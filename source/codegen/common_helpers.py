def is_output_parameter(parameter):
    return "out" in parameter["direction"]

def is_input_parameter(parameter):
    return "in" in parameter["direction"]

def is_array(dataType):
  return dataType.endswith("[]")

def is_enum(parameter):
  return "enum" in parameter

def is_struct(parameter):
  return parameter["type"].startswith("struct")

def is_string_arg(parameter):
  return parameter['type'] in ['ViChar[]', 'ViInt8[]', 'ViUInt8[]']

def get_underlying_type_name(parameter_type):
  '''Strip away information from type name like brackets for arrays, leading "struct ", etc. leaving just the underlying type name.'''
  return parameter_type.replace("struct ","").replace('[]', '')

def has_unsupported_parameter(function):
  return any(is_unsupported_parameter(p) for p in function['parameters'])

def is_unsupported_parameter(parameter):
  return is_unsupported_size_mechanism(parameter) \
      or is_unsupported_struct(parameter) \
      or is_unsupported_scalar_array(parameter)

def is_unsupported_size_mechanism(parameter):
  return not get_size_mechanism(parameter) in {'fixed', 'len', 'ivi-dance', 'passed-in', 'ivi-dance-with-a-twist', None}

def is_unsupported_struct(parameter):
  return is_struct(parameter) and is_input_parameter(parameter)

def is_unsupported_scalar_array(parameter):
  if not is_array(parameter['type']):
    return False
  return is_unsupported_enum_array(parameter) or get_underlying_type_name(parameter['type']) == 'ViInt16'

def is_unsupported_enum_array(parameter):
  if is_enum(parameter):
    return not (is_output_parameter(parameter) and is_string_arg(parameter))
  return False

def camel_to_snake(camelString):
  '''Returns a snake_string for a given camelString.'''
  camelString = list(camelString)
  index = 0
  for x in camelString :
      if x.isupper():
          camelString[index] = camelString[index].lower()
          camelString.insert(index, "_")

      index = index + 1
  return ("".join(camelString))

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
  pascal_string = list(pascal_string)
  pascal_string[0] = pascal_string[0].lower()
  return ("".join(pascal_string))

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
  return function_enums

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

def is_ivi_dance_array_param(parameter):
  return get_size_mechanism(parameter) == 'ivi-dance'

def has_ivi_dance_param(parameters):
  return any(is_ivi_dance_array_param(p) for p in parameters)

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
