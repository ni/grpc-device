import common_helpers

def should_allow_alias(enum):
  if enum.get("generate-mappings", False):
    return False
  enum_values = [e["value"] for e in enum["values"]]
  return (0 in enum_values) or (len(enum_values) != len(set(enum_values)))


def generate_parameter_field_number(parameter, used_indexes, field_name_suffix=""):
  """Get unique field number for field corresponding to this parameter in proto file.
     If field number is not stored in metadata of parameter, get the next unused integer value."""
  field_name_key = f"grpc{field_name_suffix}_field_number"
  if field_name_key in parameter:
    field_number = parameter[field_name_key]
  else:
    field_number = next(i for i in range(1, 100) if i not in used_indexes)
  used_indexes.append(field_number)
  return field_number

def get_enum_definitions(enums_to_define, enums):
  """Get simplified definition for enums and values in it that can be used for defining enums in proto file."""
  enum_definitions = {}
  for enum_name in (e for e in enums if e in enums_to_define):
    enum = enums[enum_name]
    allow_alias = should_allow_alias(enum)
    enum_value_prefix = common_helpers.get_enum_value_prefix(enum_name, enum)
    if enum.get("generate-mappings", False):
      values = [{"name": f"{enum_value_prefix}_{value['name']}", "value": index + 1} for index, value in enumerate(enum["values"])]
    else:
      values = [{"name": f"{enum_value_prefix}_{value['name']}", "value": value["value"]} for value in enum["values"]]
    enum_definition = {
      "allow_alias": allow_alias,
      "values": values
    }
    unspecified_value_name = f"{enum_value_prefix}_MAPPED_UNSPECIFIED" if enum_name.endswith("AttributeValuesMapped") else f"{enum_value_prefix}_UNSPECIFIED"
    values.insert(0, {"name": unspecified_value_name, "value": 0})
    enum_definitions.update({enum_name: enum_definition})
  return enum_definitions


def is_array_input(parameter: dict):
  return common_helpers.is_array(parameter["type"]) and common_helpers.is_input_parameter(parameter)


def is_decomposable_enum(parameter: dict):
  """
  Enums are typically decomposed from a single param into an enum param and an _raw param.
  The exception is array_inputs which are left as single enum param.
  This is because protobuf does not support oneof on repeated types, so the standard
  input decomposition does not work for arrays.
  """
  return common_helpers.is_enum(parameter) and not (is_array_input(parameter) and parameter["grpc_type"] != "string")


def get_message_parameter_definitions(parameters):
  """Get simplified list of all parameters that can be used for defining request/respones messages in proto file."""
  parameter_definitions = []
  used_indexes = []
  for parameter in parameters:
    is_array = common_helpers.is_array(
        parameter["type"]) and not parameter["grpc_type"] == "string"
    parameter_name = common_helpers.camel_to_snake(parameter["name"])
    parameter_type = get_parameter_type(parameter)
    if is_decomposable_enum(parameter):
      is_request_message = common_helpers.is_input_parameter(parameter)
      enum_parameters = get_enum_parameters(parameter, parameter_name, parameter_type, is_array, used_indexes)
      if is_request_message:
        # use oneof for enums in request messages
        parameter_definitions.append({
          "name": f"{parameter_name}_enum",
          "use_oneof": True,
          "parameters": enum_parameters
        })
      else:
        # we define all enum fields in response messages
        parameter_definitions.extend(enum_parameters)
    else:
      if common_helpers.is_enum(parameter):
        # For input arrays of enums, don't generate a raw type, but do use the correct enum type.
        parameter_type = f'repeated {parameter["enum"]}'
      grpc_field_number = generate_parameter_field_number(parameter, used_indexes)
      parameter_definitions.append({
        "name": parameter_name,
        "type": parameter_type,
        "grpc_field_number": grpc_field_number
      })
  return parameter_definitions

def get_enum_parameters(parameter, parameter_name, parameter_type, is_array, used_indexes):
  """Get list of mapped/unmapped/raw parameters for enums as applicable."""
  enum_parameters = []
  if parameter.get('enum', None):
    enum_parameter_type = f"repeated {parameter['enum']}" if is_array else parameter['enum']
    grpc_enum_field_number = generate_parameter_field_number(parameter, used_indexes)
    enum_parameters.append({
      "name": parameter_name,
      "type": enum_parameter_type,
      "grpc_field_number": grpc_enum_field_number
    })
  if parameter.get('mapped-enum', None):
    mapped_type = f"repeated {parameter['mapped-enum']}" if is_array else parameter['mapped-enum']
    grpc_mapped_field_number = generate_parameter_field_number(parameter, used_indexes, "_mapped")
    enum_parameters.append({
      "name": f"{parameter_name}_mapped",
      "type": mapped_type,
      "grpc_field_number": grpc_mapped_field_number
    })
  if 'bitfield_as_enum_array' in parameter:
    enum_parameters.append({
      "name": f"{parameter_name}_array",
      "type": f"repeated {parameter['bitfield_as_enum_array']}",
      "grpc_field_number": generate_parameter_field_number(parameter, used_indexes, "_array")
    })

  grpc_raw_field_number = generate_parameter_field_number(parameter, used_indexes, "_raw")
  enum_parameters.append({
    "name": f"{parameter_name}_raw",
    "type": parameter_type,
    "grpc_field_number": grpc_raw_field_number
  })
  return enum_parameters


def get_parameter_type(parameter):
  if 'grpc_type' not in parameter:
    raise KeyError(f"grpc_type not in {parameter['name']} with {parameter['type']}")
  return parameter['grpc_type']


def is_session_name(parameter):
  return parameter.get('is_session_name', False)


def get_parameters(function):
  parameter_array = common_helpers.filter_parameters_for_grpc_fields(function['parameters'])
  input_parameters = [p for p in parameter_array if common_helpers.is_input_parameter(p)]
  if common_helpers.is_init_method(function):
    has_session_input = any(is_session_name(param) for param in input_parameters)
    if not has_session_input:
      session_name_param = {'direction': 'in','name': 'session_name','type': 'ViString', 'grpc_type': 'string'}
      input_parameters.insert(0, session_name_param)

  default_status_param = {'name': 'status', 'type': 'int32', 'grpc_type': 'int32'}
  output_parameters = [default_status_param]

  callback_parameters = get_callback_output_params(function)

  if callback_parameters:
    if any((p for p in callback_parameters if p['name'] == 'status')):
      # if the callback provides a status, it can override default_status_param.
      output_parameters = callback_parameters
    else:
      output_parameters.extend(callback_parameters)
  else:
    output_parameters.extend(
      [p for p in parameter_array if common_helpers.is_output_parameter(p)]
    )

  return (input_parameters, output_parameters)


def get_callback_output_params(function):
  """
  Looks for a parameter that specifies callback_params and returns those params
  These will be used as the outputs of a streaming response.
  """
  params = [p for p in function['parameters'] if 'callback_params' in p]
  if params:
    return common_helpers.filter_parameters_for_grpc_fields(
      params[0]['callback_params'])
  else:
    return []


def get_streaming_response_qualifier(function):
  return 'stream ' if common_helpers.has_streaming_response(function) else ''
