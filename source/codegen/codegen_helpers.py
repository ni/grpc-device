RESERVED_WORDS = [
    'abstract', 'as',
    'base', 'bool', 'break','byte',
    'case', 'catch', 'char', 'checked', 'class', 'const', 'continue',
    'decimal', 'default', 'delegate', 'do', 'double',
    'else', 'enum', 'event', 'explicit', 'extern',
    'false', 'finally', 'fixed', 'float', 'for', 'foreach',
    'goto',
    'if', 'implicit', 'in', 'int', 'interface', 'internal', 'is',
    'lock', 'long',
    'namespace', 'new', 'null',
    'object', 'operator', 'out', 'override',
    'params', 'private', 'protected', 'public',
    'readonly', 'ref', 'return',
    'sbyte', 'sealed', 'short', 'sizeof', 'stackalloc', 'static', 'status', 'string', 'struct', 'switch',
    'this', 'throw', 'true', 'try', 'typeof',
    'uint', 'ulong', 'unchecked', 'unsafe', 'ushort', 'using',
    'virtual', 'void', 'volatile',
    'while'
]

def sanitize_names(parameters):
    """Sanitizes name fields on a list of parameter objects and populates the dotNetName field with the sanitized value."""
    for parameter in parameters:
        if parameter['name'] in RESERVED_WORDS:
            parameter['dotNetName'] = parameter['name'] + 'Parameter'

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
    if parameter['direction'] == 'out':
        return True
    return False

def is_input_parameter(parameter):
    if parameter['direction'] == 'in':
        return True
    return False

def get_repeated_prefix(parameter):
    if '[]' in parameter['nettype']:
        return 'repeated '
    return ''

def create_args(parameters):
    result = ''
    for parameter in parameters:
        if is_input_parameter(parameter) == False:
            result = result + '&'
        result = result + camel_to_snake_name(parameter) + ', '
    return result[:-2]
def create_params(parameters):
    result = ''
    for parameter in parameters:
        result = result + get_proto_type(parameter['type'])
        if '[]' in parameter['type']:
          result = result + '['
          if parameter['size']['mechanism'] == 'fixed':
            result = result + str(parameter['size']['value'])
          result = result + ']'
        if is_output_parameter(parameter):
          result = result + '*'
        result = result + ', '
    return result[:-2]

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