def get_proto_type(typestr):
    if 'ViBoolean' in typestr:
        return 'bool'
    if 'ViReal64' in typestr:
        return 'double'
    if 'ViInt32' in typestr:
        return 'int32'
    if 'ViConstString' in typestr:
        return 'string'
    if 'ViString' in typestr:
        return 'string'
    if 'ViRsrc' in typestr:
        return 'string'
    if 'ViChar' in typestr:
        return 'string'
    if 'niScope_wfmInfo' in typestr:
        return 'ScopeWaveformInfo'
    if 'niScope_coefficientInfo' in typestr:
        return 'ScopeCoefficientInfo'
    if 'ViReal32' in typestr:
        return 'float'
    if 'ViAttr' in typestr:
        return 'ScopePropertyId'
    if 'ViInt8' in typestr:
        return 'bytes'
    if 'void' in typestr:
        return 'bytes'
    if 'ViInt16' in typestr:
        return 'bytes'
    if 'ViInt64' in typestr:
        return 'int64'
    if 'ViUInt32' in typestr:
        return 'uint32'
    if 'ViUInt64' in typestr:
        return 'uint64'
    if 'ViStatus' in typestr:
        return 'int32'
    if 'ViAddr' in typestr:
        return 'bytes'
    if 'NIComplexNumber' in typestr:
        return 'ComplexNumber'
    if 'NIComplexI16' in typestr:
        return 'ComplexI16'
    if 'int' == typestr:
        return 'int32'
    return typestr

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
    result = result + get_proto_type(camel_to_snake_name(parameter).lower())
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