def get_grpc_type_from_ivi(type):
    if 'ViSession' in type:
        return 'uint32'
    if 'ViBoolean' in type:
        return 'bool'
    if 'ViReal64' in type:
        return 'double'
    if 'ViInt32' in type:
        return 'int32'
    if 'ViConstString' in type:
        return 'string'
    if 'ViString' in type:
        return 'string'
    if 'ViRsrc' in type:
        return 'string'
    if 'ViChar' in type:
        return 'string'
    if 'ViReal32' in type:
        return 'float'
    if 'ViInt8' in type:
        return 'bytes'
    if 'void' in type:
        return 'bytes'
    if 'ViInt16' in type:
        return 'bytes'
    if 'ViInt64' in type:
        return 'int64'
    if 'ViUInt32' in type:
        return 'uint32'
    if 'ViUInt64' in type:
        return 'uint64'
    if 'ViStatus' in type:
        return 'int32'
    if 'ViAddr' in type:
        return 'bytes'
    if 'int' == type:
        return 'int32'
    return type 

def is_output_parameter(parameter):
    if "out" in parameter["direction"]:
      return True
    return False

def is_input_parameter(parameter):
    if "in" in parameter["direction"]:
        return True
    return False

def get_repeated_prefix(parameter):
    if '[]' in parameter['nettype']:
        return 'repeated '
    return ''

def get_request_value(parameter):
    result = ''
    if parameter['type'] == 'ViChar':
        result = result + '(char*)'
    if parameter['type'] == 'ViSession':
        result = result + 'session_repository_->lookup_session('        
    result = result + 'request->'
    result = result + get_grpc_type_from_ivi(camel_to_snake_name(parameter).lower())
    result = result + '()'
    if parameter['type'] == 'ViConstString':
        result = result + '.c_str()'
    if parameter['type'] == 'ViRsrc':
        result = result + '.c_str()'
    if parameter['type'] == 'ViChar':
        result = result + '.c_str()'
    if parameter['type'] == 'ViSession':
        result = result + ')'
    result = result + ';'
    return result

def camel_to_snake(camelString):
  camelString = list(camelString)
  index = 0
  snake_string = camelString
  for x in camelString :
      if x.isupper():
          camelString[index] = camelString[index].lower()
          camelString.insert(index, "_")
          
      index = index + 1
  return ("".join(camelString))

def camel_to_snake_name(parameter):
  return camel_to_snake(parameter['name'])

def has_array_parameter(function):
  for parameter in function['parameters']:
    if 'size' in parameter.keys():
      return True
  return False