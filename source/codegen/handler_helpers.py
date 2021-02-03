import codegen_helpers

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

def create_args(parameters):
    result = ''
    for parameter in parameters:
        if codegen_helpers.is_input_parameter(parameter) == False:
            result = result + '&'
        result = result + codegen_helpers.camel_to_snake_name(parameter) + ', '
    return result[:-2]

def create_params(parameters):
    result = ''
    for parameter in parameters:
        result = result + get_c_type(parameter)
        if '[]' in parameter['type']:
          result = result + '['
          if parameter['size']['mechanism'] == 'fixed':
            result = result + str(parameter['size']['value'])
          result = result + ']'
        if codegen_helpers.is_output_parameter(parameter):
          result = result + '*'
        result = result + ', '
    return result[:-2]

def get_request_value(parameter):
    result = ''
    if parameter['type'] == 'ViChar':
        result = result + '(char*)'
    ## if parameter['type'] == 'ViSession':
        ## result = result + 'session_repository_->lookup_session('        
    result = result + 'request->'
    result = result + codegen_helpers.get_grpc_type_from_ivi(codegen_helpers.camel_to_snake_name(parameter).lower())
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

def get_c_type(parameter):
  grpc_type = codegen_helpers.get_grpc_type_from_ivi(parameter['type'])
  grpc_to_c = {
    "double": "double",
    "float": "float",
    "int32": "int32",
    "int64": "int64",
    "uint32": "uint32",
    "uint64": "uint64",
    "sint32": "int32",
    "sint64": "int64",
    "fixed32": "uint32",
    "fixed64": "uint64",
    "sfixed32": "int32",
    "sfixed64": "int64",
    "bool": "bool",
    "string": "std::string",
    "bytes": "std::string"
  }
  # This is equivalent to a switch statement with the default case returning the grpc_type
  return grpc_to_c.get(grpc_type, grpc_type)