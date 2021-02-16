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

def get_include_guard_name(config, suffix):
    include_guard_name = 'ni_' + config['namespace_component'] + '_grpc' + suffix
    return include_guard_name.upper()

def create_args(parameters):
    result = ''
    for parameter in parameters:
        if common_helpers.is_input_parameter(parameter) == False:
            result = result + '&'
        result = result + common_helpers.camel_to_snake(parameter['cppName']) + ', '
    return result[:-2]

def create_params(parameters):
    result = ''
    for parameter in parameters:
        result = result + create_param(parameter) + ' ' + parameter['cppName'] + ', '
    return result[:-2]

def create_param(parameter):
    result = parameter['type']
    if result.endswith('[]') and parameter['size']['mechanism'] == 'fixed':
        size = parameter['size']['value'];
        result.replace('[]', f'[{size}]')
    if common_helpers.is_output_parameter(parameter):
        result = result + '*'
    return result

def get_request_value(parameter):
    field_name = common_helpers.camel_to_snake(parameter["name"])
    request_snippet = f'request->{field_name}()'
    c_type = parameter['type']
    if c_type == 'ViConstString':
        return f'{request_snippet}.c_str()';
    if c_type == 'ViString' or c_type == 'ViRsrc':
        return f'({c_type}){request_snippet}.c_str()'
    if c_type == 'ViInt8[]' or c_type == 'ViChar[]':
        return f'({c_type[:-2]}*){request_snippet}.c_str()'
    if c_type == 'ViChar' or c_type == 'ViInt16' or c_type == 'ViInt8' or 'enum' in parameter:
        return f'({c_type}){request_snippet}'
    return request_snippet

def filter_api_functions(functions):
  '''Returns function metadata only for those functions to include for generating the function types to the API library'''
  return [name for name, function in functions.items() if function.get('codegen_method', '') != 'no']
