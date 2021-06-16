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

def determine_function_parameter_type(parameter, driver_name_pascal):
  is_array = common_helpers.is_array(parameter["type"])
  if common_helpers.is_enum(parameter) :
    parameter_type = parameter["enum"]
    if is_array :
      parameter_type = "repeated " + parameter_type
  else:
    parameter_type = get_grpc_type_from_ivi(parameter["type"], is_array, driver_name_pascal)
  return parameter_type

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