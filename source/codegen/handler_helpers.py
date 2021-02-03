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
        result = result + codegen_helpers.get_proto_type(parameter['type'])
        if '[]' in parameter['type']:
          result = result + '['
          if parameter['size']['mechanism'] == 'fixed':
            result = result + str(parameter['size']['value'])
          result = result + ']'
        if codegen_helpers.is_output_parameter(parameter):
          result = result + '*'
        result = result + ', '
    return result[:-2]