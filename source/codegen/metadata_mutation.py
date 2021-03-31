import common_helpers

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
            parameter['cppName'] += 'Parameter'

def mark_size_params(parameters):
  """Marks the size parameters in the metadata. Also, as appropriate it will 
     mark the parameters whose value shouldn't be derived from a gRPC request message and
     adds information on how to get their value instead for the API call."""
  named_params = { p['name'] : p for p in parameters }
  for param in parameters:
    mechanism = common_helpers.get_size_mechanism(param)
    if mechanism in {'len', 'ivi-dance', 'passed-in'}:
      size_param = named_params.get(param['size']['value'], None)
      size_param['is_size_param'] = True
      if mechanism == 'len' or mechanism == 'ivi-dance':
        size_param['include_in_proto'] = False
        if mechanism == 'len':
          size_param['determine_size_from'] = param['name']