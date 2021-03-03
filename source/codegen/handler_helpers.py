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

def is_string_arg(parameter):
    return parameter['type'] == 'ViChar[]' or parameter['type'] == 'ViInt8[]'

def create_args(parameters):
    result = ''
    for parameter in parameters:         
      parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
      is_array = common_helpers.is_array(parameter['type'])
      is_output = common_helpers.is_output_parameter(parameter)
      if common_helpers.is_output_parameter(parameter) and is_string_arg(parameter):
        type_without_brackets = parameter['type'].replace('[]', '')
        result = f'{result}({type_without_brackets}*){parameter_name}.data(), '
      else:
        if is_array and common_helpers.is_struct(parameter):
          parameter_name = parameter_name + ".data()"
        elif not is_array and is_output:
          result = f'{result}&'
        result = f'{result}{parameter_name}, '
    return result[:-2]

def create_args_for_ivi_dance(parameters):
    result = ''
    for parameter in parameters:
      if parameter.get('is_size_param', False):
        result = f'{result}0, '
      elif common_helpers.is_output_parameter(parameter):
        result = f'{result}nullptr, '
      else:
        result = result + common_helpers.camel_to_snake(parameter['cppName']) + ', '
    return result[:-2]

def create_params(parameters):
    return ', '.join(create_param(p) for p in parameters)

def create_param(parameter):
    type = parameter['type']
    name = parameter['cppName']
    if common_helpers.is_struct(parameter):
      type = type.replace("struct ", "")
    if common_helpers.is_array(type):
        is_fixed = parameter['size']['mechanism'] == 'fixed'
        array_size = parameter['size']['value'] if is_fixed else ''
        return f'{type[:-2]} {name}[{array_size}]'
    elif common_helpers.is_output_parameter(parameter):
        return f'{type}* {name}'
    else:
        return f'{type} {name}'

def python_to_c(enum):
  enum_value = enum["values"][0]["value"]
  if isinstance(enum_value, float):
    return "float"
  if isinstance(enum_value, int):
    return "std::int32_t"
  if isinstance(enum_value, str):
    return "std::string"
  return "std::int32_t"
 
def format_value(value):
  if isinstance(value, str):
    value = f"\"{value}\""
  if isinstance(value, float):
    value = f"{value}f"
  return value
  
def get_input_lookup_values(enum_data):
  out_value_format= ""
  index = 1
  is_int = isinstance(enum_data["values"][0]["value"], int)
  if is_int:
    out_value_format =  "{0, 0},"
  for value in enum_data["values"]:
    formated_value = str(format_value(value["value"]))
    out_value_format = out_value_format + "{" + str(index) + ", " + formated_value + "},"
    index = index+1
  return out_value_format
  
def get_output_lookup_values(enum_data):
  out_value_format= ""
  index = 1
  is_int = isinstance(enum_data["values"][0]["value"], int)
  if is_int:
    out_value_format =  "{0, 0},"
  for value in enum_data["values"]:
    formated_value = format_value(value["value"])
    out_value_format = out_value_format + "{" + str(formated_value) + ", " + str(index) + "},"
    index = index+1
  return out_value_format

def filter_api_functions(functions):
  '''Returns function metadata only for those functions to include for generating the function types to the API library'''
  return [name for name, function in functions.items() if function.get('codegen_method', '') != 'no']

