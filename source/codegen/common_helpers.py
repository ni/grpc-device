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

def isolate_struct_type(struct):
  return struct.replace("struct ","").replace('[]', '')

def has_unsupported_parameter(function):
  return any(is_unsupported_parameter(p) for p in function['parameters'])

def is_unsupported_parameter(parameter):
  type = parameter['type']
  supported_size_mechanisms = {'fixed', 'len'}
  supported_struct_size_mechanisms = {'passed-in'}
  is_unsupported_array = is_array(type) and parameter['size']['mechanism'] not in supported_size_mechanisms
  is_unsupported_struct_array = is_array(type) and parameter['size']['mechanism'] not in supported_struct_size_mechanisms
  if is_struct(parameter):
    return  is_unsupported_struct_array
  else:
    return is_unsupported_array

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
  return [name for name, function in functions.items() if function.get('codegen_method', 'public') == 'public']

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

def determine_size_from(parameter, parameters):
  """Returns a string representing the parameter name the given parameter should determine its value from. If none is found returns empty string."""
  expected_len_name = parameter['name']
  for possible_size_from_param in parameters:
    if possible_size_from_param.get('size', {}).get('mechanism', '') == 'len':
      if possible_size_from_param['size']['value'] == expected_len_name:
        return possible_size_from_param['name']
  return ''

def mark_len_params(parameters):
  """Adds a 'determine_size_from' field for parameters that are determined by the size of another array parameter."""
  for parameter in parameters:
      determine_size_from_name = determine_size_from(parameter, parameters)
      if (determine_size_from != ''):
        parameter['determine_size_from'] = determine_size_from_name
