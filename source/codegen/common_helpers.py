def driver_name_to_pascal(driver_name):
  driver_name = list(driver_name.lower())
  index = 0
  driver_name[index] = driver_name[index].upper()
  for x in driver_name :
      if x == '-' :
          driver_name[index + 1] = driver_name[index + 1].upper()
          del driver_name[index]

      index = index + 1
  return ("".join(driver_name))

def driver_name_add_underscore(driver_name):
  driver_name = list(driver_name)
  index = 0
  for x in driver_name :
      if x == '-' :
          driver_name[index] = "_"

      index = index + 1
  return ("".join(driver_name))


def is_output_parameter(parameter):
    if "out" in parameter["direction"]:
      return True
    return False

def is_input_parameter(parameter):
    if "in" in parameter["direction"]:
        return True
    return False

def is_array(dataType):
  return dataType.endswith("[]")

def is_enum(parameter):
  if "enum" in parameter:
    return True
  return False

def is_struct(parameter):
  return parameter["type"].startswith("struct")

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
  return not get_size_mechanism(parameter) in {'fixed', 'len', 'ivi-dance', 'passed-in', None}

def is_unsupported_struct(parameter):
  return is_struct(parameter) and is_input_parameter(parameter)

def is_unsupported_scalar_array(parameter):
  if not is_array(parameter['type']):
    return False
  return is_enum(parameter) or get_underlying_type_name(parameter['type']) in {'ViInt16', 'ViBoolean'}

def camel_to_snake(camelString):
  camelString = list(camelString)
  index = 0
  for x in camelString :
      if x.isupper():
          camelString[index] = camelString[index].lower()
          camelString.insert(index, "_")

      index = index + 1
  return ("".join(camelString))

def snake_to_camel(snake_string):
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
  pascal_string = list(pascal_string)
  pascal_string[0] = pascal_string[0].lower()
  return ("".join(pascal_string))

def pascal_to_snake(pascal_string):
  camel_string = pascal_to_camel(pascal_string)
  snake_string = camel_to_snake(camel_string)
  return ("".join(snake_string))

def filter_proto_rpc_functions(functions):
  '''Returns function metadata only for those functions to include for generating proto rpc methods'''
  functions_for_proto = {'public', 'CustomCode'}
  return [name for name, function in functions.items() if function.get('codegen_method', 'public') in functions_for_proto]

def get_service_namespace(driver_name_caps_underscore):
  driver_full_namespace = driver_name_caps_underscore + "_" + "grpc"
  driver_full_namespace = driver_full_namespace.lower().replace("_", ".")
  return driver_full_namespace

def get_used_enums(functions, attributes):
  used_enums = set()
  for function in functions:
    for parameter in functions[function]["parameters"]:
      if "enum" in parameter:
        used_enums.add(parameter["enum"])
  for attribute in attributes:
    if "enum" in attributes[attribute]:
      used_enums.add(attributes[attribute]["enum"])
  return used_enums

def mark_non_grpc_params(parameters):
  named_params = { p['name'] : p for p in parameters }
  for param in parameters:
    mechanism = get_size_mechanism(param)
    if mechanism in {'len', 'ivi-dance', 'passed-in'}:
      size_param = named_params.get(param['size']['value'], None)
      size_param['is_size_param'] = True
      if mechanism == 'len' or mechanism == 'ivi-dance':
        size_param['gen_proto_field'] = False
        if mechanism == 'len':
          size_param['determine_size_from'] = param['name']

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
