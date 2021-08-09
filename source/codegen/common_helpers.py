import re

def is_output_parameter(parameter):
  return "out" in parameter["direction"]

def is_input_parameter(parameter):
  return "in" in parameter["direction"]

def is_pass_null_parameter(parameter):
  return parameter.get('pass_null', False)

def is_callback_token_parameter(parameter):
  return parameter.get('callback_token', False)

def is_pointer_parameter(parameter):
  return is_output_parameter(parameter) or is_pass_null_parameter(parameter) or is_callback_token_parameter(parameter)


def is_varargs_parameter(parameter):
  return parameter.get('var_args', False)

def is_array(dataType):
  return dataType.endswith("[]")

def is_enum(parameter):
  return "enum" in parameter or "mapped-enum" in parameter

def is_struct(parameter):
  return parameter["type"].startswith("struct")


def any_function_uses_timestamp(functions):
  for function in functions:
    if any(p['grpc_type'] == 'google.protobuf.Timestamp' for p in functions[function]['parameters']):
      return True
  return False

def get_input_and_output_custom_types(functions):
  '''Returns a set of custom types used by input and output parameters separately.'''
  input_custom_types = set()
  output_custom_types = set()
  for function in functions:
    struct_array_params = [p for p in functions[function]["parameters"] if is_struct(p) and is_array(p["type"])]
    for parameter in struct_array_params:
        if is_input_parameter(parameter):
            input_custom_types.add(get_underlying_type_name(parameter["type"]))
        elif is_output_parameter(parameter):
            output_custom_types.add(get_underlying_type_name(parameter["type"]))
  return (input_custom_types, output_custom_types)

def is_string_arg(parameter):
  return parameter['grpc_type'] in ['string', 'bytes']


def strip_repeated_from_grpc_type(grpc_type):
  if not grpc_type.startswith('repeated '):
      raise Exception("varargs grpc_type " + grpc_type + " must be repeated")
  return grpc_type[len('repeated '):]

def get_underlying_type_name(parameter_type):
  '''Strip away information from type name like brackets for arrays, leading "struct ", etc. leaving just the underlying type name.'''
  return parameter_type.replace("struct ","").replace('[]', '')

def has_unsupported_parameter(function):
  return any(is_unsupported_parameter(p) for p in function['parameters'])

def is_unsupported_parameter(parameter):
  return is_unsupported_size_mechanism(parameter) \
      or is_unsupported_scalar_array(parameter)

def is_unsupported_size_mechanism(parameter):
  return not get_size_mechanism(parameter) in {'fixed', 'len', 'ivi-dance', 'passed-in', 'ivi-dance-with-a-twist', 'custom-code', None}

def is_unsupported_scalar_array(parameter):
  return is_array(parameter['type']) and is_unsupported_enum_array(parameter)

def is_unsupported_enum_array(parameter):
  if is_enum(parameter):
    return not (is_output_parameter(parameter) and is_string_arg(parameter))
  return False

def camel_to_snake(camel_string):
  '''Returns a snake_string for a given camelString.'''
  # Add _ before Words: 
  # someDeviceIPAddress -> some_DeviceIP_Address
  s1 = re.sub(r"([^_])([A-Z][a-z]+[0-9]*)", r"\1_\2", camel_string)
  # Add _ before any capital letters not already preceded by _ and convert to lower:
  # some_DeviceIP_Address -> some_Device_IP_Address
  # some_Device_IP_Address -> some_device_ip_address
  return re.sub(r"([^_])([A-Z]+[0-9]*)", r"\1_\2", s1).lower()

def snake_to_pascal(snake_string):
  '''Returns a PascalString for a given snake_string.'''
  snake_string = list(snake_string)
  index = 0
  snake_string[index] = snake_string[index].upper()
  for x in snake_string :
      if x == '_':
          snake_string[index + 1] = snake_string[index + 1].upper()
          del snake_string[index]
      index = index + 1
  return ("".join(snake_string))

def pascal_to_camel(pascal_string):
  '''Returns a camelString for a given PascalString.'''
  # Full string all-caps: IEPE -> iepe. HTTP2 -> http2.
  match = re.fullmatch(r"([A-Z]+[0-9]*)", pascal_string)
  if match:
    return match[1].lower()
  
  # Leading all-caps: IPAddress -> ipAddress. HTTP2Stream -> http2Stream.
  match = re.fullmatch(r"([A-Z]+[0-9]*)([A-Z].*)", pascal_string)
  if match:
    return match[1].lower() + match[2]

  # Normal case: NormalCase -> normalCase
  match = re.fullmatch(r"([A-Z])(.*)", pascal_string)
  return match[1].lower() + match[2]

def pascal_to_snake(pascal_string):
  '''Returns a snake_string for a given PascalString.'''
  camel_string = pascal_to_camel(pascal_string)
  snake_string = camel_to_snake(camel_string)
  return ("".join(snake_string))

def filter_proto_rpc_functions(functions):
  '''Returns function metadata only for those functions to include for generating proto rpc methods'''
  functions_for_proto = {'public', 'CustomCode'}
  return [name for name, function in functions.items() if function.get('codegen_method', 'public') in functions_for_proto]

def get_attribute_enums_by_type(attributes):
  '''Returns a dictionary of different attribute data types that use enum alongwith set of enums used'''
  attribute_enums_by_type = {
    'ViInt32': set(),
    'ViInt64': set(),
    'ViReal64': set(),
    'ViString': set()
  }
  for attribute_name in attributes:
    attribute = attributes[attribute_name]
    if 'enum' in attribute:
      attribute_type = attribute['type']
      enum_name = attribute['enum']
      attribute_enums_by_type[attribute_type].add(enum_name)
  return attribute_enums_by_type

def get_function_enums(functions):
  '''Returns a set of enums used with functions.'''
  function_enums = set()
  for function in functions:
    for parameter in functions[function]['parameters']:
      if 'enum' in parameter:
        function_enums.add(parameter['enum'])
      if 'mapped-enum' in parameter:
        function_enums.add(parameter['mapped-enum'])
  return sorted(function_enums)

def has_viboolean_array_param(functions):
  '''Returns True if atleast one function has parameter of type ViBoolean[]'''
  for function in functions:
    for parameter in functions[function]["parameters"]:
      if parameter['type'] == 'ViBoolean[]':
        return True
  return False

def has_enum_array_string_out_param(functions):
  '''Returns True if atleast one function has output parameter of type ViChar[], ViInt8[] or ViUInt8[] that uses enum'''
  for function in functions:
    for parameter in functions[function]["parameters"]:
      if is_output_parameter(parameter) and is_string_arg(parameter) and is_enum(parameter):
        return True
  return False

def get_size_mechanism(parameter):
  size = parameter.get('size', {})
  return size.get('mechanism', None)

def get_size_expression(parameter):
  size_mechanism = get_size_mechanism(parameter)
  if size_mechanism == 'fixed':
    return parameter['size']['value']
  elif size_mechanism == 'ivi-dance-with-a-twist':
    return camel_to_snake(parameter['size']['value_twist'])
  else:
    return camel_to_snake(parameter['size']['value'])


def is_ivi_dance_array_param(parameter):
  return get_size_mechanism(parameter) == 'ivi-dance'

def has_ivi_dance_param(parameters):
  return any(is_ivi_dance_array_param(p) for p in parameters)


def has_varargs_parameter(parameters):
  return any(is_varargs_parameter(p) for p in parameters)

# Google Mock can't handle the case where a function has a variable number of arguments
# and there's also a limit on the max number of arguments.
def can_mock_function(parameters):
  # I'm not sure this is exactly right, but it does enough to distinguish between
  # non-varargs functions and varargs functions that take > 100 parameters.
  MAX_PARAM_LEN = 20
  varargs_parameters = [p for p in parameters if is_varargs_parameter(p)]
  parameters_not_in_proto = len(
      [p for p in parameters if not p.get('include_in_proto', True)])
  if not any(varargs_parameters):
    return len(parameters) - parameters_not_in_proto <= MAX_PARAM_LEN
  # This assumes that parmaeters_not_in_proto matches the members of the varargs struct
  varargs_parameter = varargs_parameters[0]
  return len(parameters) - parameters_not_in_proto - len(varargs_parameters) + (parameters_not_in_proto * varargs_parameter['max_length']) <= MAX_PARAM_LEN

def get_ivi_dance_params(parameters):
  array_param = next((p for p in parameters if is_ivi_dance_array_param(p)), None)
  size_param = next(p for p in parameters if p['name'] == array_param['size']['value']) if array_param else None
  other_params = (p for p in parameters if p != array_param and p != size_param)
  return (size_param, array_param, other_params)

def get_twist_value(parameters):
  for p in parameters:
      if is_array(p['type']):
        size = p.get('size', {})
        return size.get('value_twist', None)

def is_ivi_dance_array_with_a_twist_param(parameter):
  return get_size_mechanism(parameter) == 'ivi-dance-with-a-twist'

def has_ivi_dance_with_a_twist_param(parameters):
  return any(is_ivi_dance_array_with_a_twist_param(p) for p in parameters)

def get_ivi_dance_with_a_twist_params(parameters):
  array_param = next((p for p in parameters if is_ivi_dance_array_with_a_twist_param(p)), None)
  size_param = next(p for p in parameters if p['name'] == array_param['size']['value']) if array_param else None
  other_params = (p for p in parameters if p != array_param and p != size_param)
  return (size_param, array_param, other_params)

def is_init_method(function_data):
  return function_data.get('init_method', False)

def has_streaming_response(function_data):
  return function_data.get('stream_response', False)


def has_callback_param(function_data):
  return any((p for p in function_data['parameters'] if 'callback_params' in p))


def has_async_streaming_response(function_data):
  return has_streaming_response(function_data) and has_callback_param(function_data)


def get_library_interface_type_name(config):
  service_class_prefix = config["service_class_prefix"]
  return f'{service_class_prefix}LibraryInterface'


def indent(level):
  """For use as a mako filter.
     Returns a function that indents a block of text to the provided level."""
  def indent_text_to_level(text, level):
    result = ""
    indentation = level * "  "
    for line in text.splitlines(True):
      result = result + indentation + line
    return result

  return lambda text: indent_text_to_level(text, level)
      

def filter_parameters_for_grpc_fields(parameters):
  """Filter out the parameters that shouldn't be represented by a field on a grpc message.
     For example, get rid of any parameters whose values should be determined from another parameter."""
  return [p for p in parameters if p.get('include_in_proto', True)]