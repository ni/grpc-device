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
    driver_full_namespace = config["grpc_package"]
    include_guard_name = driver_full_namespace.replace(".", "_") + suffix
    return include_guard_name.upper()

def get_namespace_segments(config):
    namespace = config["grpc_package"]
    return namespace.split(".")

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
    "google.protobuf.Timestamp": "google::protobuf::Timestamp",
    driver_name_pascal + "Attributes": "std::uint32_t"
  }
  # This is equivalent to a switch statement with the default case returning the grpc_type
  return grpc_to_c.get(grpc_type, grpc_type)
  
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
  
def lookup_input_values(enum_data):
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
  
def lookup_output_values(enum_data):
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

