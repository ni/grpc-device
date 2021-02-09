import common_helpers
def get_grpc_type_from_ivi(type, is_array, driver_name_pascal):
  add_repeated = is_array;
  if 'ViSession' in type:
    type = 'fixed64'
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
    type = 'uint32'
  if 'ViInt64' in type:
    type = 'int64'
  if 'ViUInt32' in type:
    type = 'uint32'
  if 'ViUInt64' in type:
    type = 'uint64'
  if 'ViStatus' in type:
    type = 'sint32'
  if 'ViAddr' in type:
    type = 'fixed64'
  if 'hightime.datetime' in type:
    type = 'google.protobuf.Timestamp'
  if 'CustomStruct' in type:
    type = 'fixed64'
  if 'int' == type:
    type = 'sint32'
  if add_repeated == True:
    return "repeated " + type
  return type
  
def determine_function_parameter_type(parameter, driver_name_pascal):
  is_array = common_helpers.is_array(parameter["type"])
  if "enum" in parameter :
    parameter_type = parameter["enum"]
    if is_array == True : 
      parameter_type = "repeated " + parameter_type
  else:
    parameter_type = get_grpc_type_from_ivi(parameter["type"], is_array, driver_name_pascal)
  return parameter_type
