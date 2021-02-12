import common_helpers
import proto_helpers

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
    """Sanitizes name fields on a list of parameter objects and populates the cppname field with the sanitized value."""
    for parameter in parameters:
        parameter['cppName'] = parameter['name']
        if parameter['cppName'] in RESERVED_WORDS:
            parameter['cppName'] = parameter['cppName'] + 'Parameter'

def create_args(parameters):
    result = ''
    for parameter in parameters:
        if common_helpers.is_input_parameter(parameter) == False:
            result = result + '&'
        result = result + common_helpers.camel_to_snake(parameter['cppName']) + ', '
    return result[:-2]

def create_params(parameters, driver_name_pascal):
    result = ''
    for parameter in parameters:
        result = result + get_c_type(parameter, driver_name_pascal)
        if '[]' in parameter['type']:
          result = result + '['
          if parameter['size']['mechanism'] == 'fixed':
            result = result + str(parameter['size']['value'])
          result = result + ']'
        if common_helpers.is_output_parameter(parameter):
          result = result + '*'
        result = result + ', '
    return result[:-2]

def get_request_value(parameter, driver_name_pascal):
    result = ''
    if parameter['type'] == 'ViChar':
        result = '%(result)s(char*)'
    result = f'{result}request->'
    param_name = common_helpers.camel_to_snake(parameter['cppName'])
    is_array = common_helpers.is_array(parameter["type"])
    request_name = proto_helpers.get_grpc_type_from_ivi(param_name, is_array, driver_name_pascal)
    result = f'{result}{request_name}()'
    is_enum = common_helpers.is_enum(parameter)
    if  common_helpers.is_enum(parameter) == True:
        return result
    if parameter['type'] == 'ViConstString':
        result = f'{result}.c_str()'
    if parameter['type'] == 'ViRsrc':
        result = f'{result}.c_str()'
    if parameter['type'] == 'ViChar':
        if is_array:
            result = f'{result}.c_str()'
        else:
            result = f'{result}[0]'
    result = f'{result};'
    return result

def get_c_type(parameter, driver_name_pascal):
  is_array = common_helpers.is_array(parameter["type"])
  grpc_type = proto_helpers.get_grpc_type_from_ivi(parameter['type'], is_array, driver_name_pascal)
  grpc_to_c = {
    "double": "double",
    "float": "float",
    "int32": "std::int32_t",
    "int64": "std::int64_t",
    "uint32": "std::uint32_t",
    "uint64": "std::uint64_t",
    "sint32": "std::int32_t",
    "sint64": "std::int64_t",
    "fixed32": "std::uint32_t",
    "fixed64": "std::uint64_t",
    "sfixed32": "std::int32_t",
    "sfixed64": "std::int64_t",
    "bool": "bool",
    "string": "std::string",
    "bytes": "std::string",
    "google.protobuf.Timestamp": "google::protobuf::Timestamp"
  }
  # This is equivalent to a switch statement with the default case returning the grpc_type
  return grpc_to_c.get(grpc_type, grpc_type)

def filter_api_functions(functions):
  '''Returns function metadata only for those functions to include for generating the function types to the API library'''
  return {k: function for k, function in functions.items() if 'codegen_method' not in function.keys() or function['codegen_method'] != 'no'}