import common_helpers

def get_grpc_type_from_ivi(type, is_array, driver_name_pascal):
  add_repeated = is_array
  if 'ViSession' in type:
    type = 'nidevice_grpc.Session'
  if 'ViBoolean' in type:
    type = 'bool'
  if 'ViReal64' in type:
    type = 'double'
  if 'ViInt32' in type:
    type = 'sint32'
  if 'ViConstString' in type:
    type = 'string'
  if 'ViString' in type:
    type = 'string'
  if 'ViRsrc' in type:
    type = 'string'
  if 'ViChar' in type:
    if is_array == True:
      add_repeated = False
      type = 'string'
    else:
      type = 'uint32'
  if 'ViReal32' in type:
    type = 'float'
  if 'ViAttr' in type:
    type = driver_name_pascal + "Attributes"
  if 'ViInt8' in type:
    if is_array == True:
      type = "bytes"
      add_repeated = False
    else:
      type = 'uint32'
  if 'void*' in type:
    type = 'fixed64'
  if 'ViInt16' in type:
    type = 'sint32'
  if 'ViInt64' in type:
    type = 'int64'
  if 'ViUInt16' in type:
    type = 'uint32'
  if 'ViUInt32' in type:
    type = 'uint32'
  if 'ViUInt64' in type:
    type = 'uint64'
  if 'ViUInt8' in type:
    if is_array == True:
      type = "bytes"
      add_repeated = False
    else:
      type = 'uint32'
  if 'ViStatus' in type:
    type = 'sint32'
  if 'ViAddr' in type:
    type = 'fixed64'
  if 'int' == type:
    type = 'sint32'
  if "[]" in type:
    type = type.replace("[]","")

  return "repeated " + type if add_repeated else type

def should_allow_alias(enums):
  if enums.get("generate-mappings", False):
    return False
  for value in enums["values"]:
    if value["value"] == 0:
      return True
  return False

def filter_parameters_for_grpc_fields(parameters):
  """Filter out the parameters that shouldn't be represented by a field on a grpc message.
     For example, get rid of any parameters whose values should be determined from another parameter."""
  return [p for p in parameters if p.get('include_in_proto', True)]

def generate_parameter_field_number(parameter, used_indexes, field_name_suffix=""):
  field_name_key = f"grpc{field_name_suffix}_field_number"
  if field_name_key in parameter:
    field_number = parameter[field_name_key]
  else:
    field_number = next(i for i in range(1, 100) if i not in used_indexes)
  used_indexes.append(field_number)
  return field_number

def get_enum_definitions(enums_to_define, enums):
  enum_definitions = {}
  for enum_name in (e for e in enums if e in enums_to_define):
    enum = enums[enum_name]
    allow_alias = enum.get("allow-alias", should_allow_alias(enum))
    enum_value_prefix = enum.get("enum-value-prefix", common_helpers.pascal_to_snake(enum_name).upper())
    if enum.get("generate-mappings", False):
      values = [{"name": f"{enum_value_prefix}_{value['name']}", "value": index + 1} for index, value in enumerate(enum["values"])]
    else:
      values = [{"name": f"{enum_value_prefix}_{value['name']}", "value": value["value"]} for value in enum["values"]]
    enum_definition = {
      "allow_alias": allow_alias,
      "values": values
    }
    unspecified_name = f"{enum_value_prefix}_MAPPED_UNSPECIFIED" if enum_name.endswith("AttributeValuesMapped") else f"{enum_value_prefix}_UNSPECIFIED"
    values.insert(0, {"name": unspecified_name, "value": 0})
    enum_definitions.update({enum_name: enum_definition})
  return enum_definitions

def get_message_parameters(parameters, service_class_prefix, is_request_message):
  parameter_definitions = []
  used_indexes = []
  if not is_request_message:
    parameter_definitions.append({
      "name": "status",
      "type": "int32",
      "grpc_field_number": "1"
    })
    used_indexes = [1]
  for parameter in parameters:
    is_array = common_helpers.is_array(parameter["type"])
    parameter_name = common_helpers.camel_to_snake(parameter["name"])
    if 'grpc_type' in parameter:
      parameter_type = parameter['grpc_type']
    else:
      parameter_type = get_grpc_type_from_ivi(parameter["type"], is_array, service_class_prefix)
    if common_helpers.is_enum(parameter):
      enum_parameters = get_enum_parameters(parameter, parameter_name, parameter_type, is_array, used_indexes)
      if is_request_message:
        parameter_definitions.append({
          "name": f"{parameter_name}_enum",
          "use_oneof": True,
          "parameters": enum_parameters
        })
      else:
        parameter_definitions.extend(enum_parameters)
    else:
      grpc_field_number = generate_parameter_field_number(parameter, used_indexes)
      parameter_definitions.append({
        "name": parameter_name,
        "type": parameter_type,
        "grpc_field_number": grpc_field_number
      })
  return parameter_definitions

def get_enum_parameters(parameter, parameter_name, parameter_type, is_array, used_indexes):
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
  grpc_raw_field_number = generate_parameter_field_number(parameter, used_indexes, "_raw")
  enum_parameters.append({
    "name": f"{parameter_name}_raw",
    "type": parameter_type,
    "grpc_field_number": grpc_raw_field_number
  })
  return enum_parameters
