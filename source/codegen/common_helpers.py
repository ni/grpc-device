def driver_name_to_pascal(driver_name):
  driver_name = list(driver_name.lower())
  index = 0
  driver_name[index] = driver_name[index].upper();
  for x in driver_name :
      if x == '-' :
          driver_name[index + 1] = driver_name[index + 1].upper();
          del driver_name[index]
         
      index = index + 1
  return ("".join(driver_name))
  
def driver_name_add_underscore(driver_name):
  driver_name = list(driver_name)
  index = 0
  for x in driver_name :
      if x == '-' :
          driver_name[index] = "_";
         
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
  if dataType.find("[]") != -1:
    return True
  return False
  
def is_enum(parameter):
  if "enum" in parameter:
    return True
  return False

def has_array_parameter(function):
  for parameter in function['parameters']:
    if is_array(parameter['type']):
      return True
  return False
  
def camel_to_snake(camelString):
  camelString = list(camelString)
  index = 0
  for x in camelString :
      if x.isupper():
          camelString[index] = camelString[index].lower();
          camelString.insert(index, "_")
          
      index = index + 1
  return ("".join(camelString))

def snake_to_camel(snake_string):
  snake_string = list(snake_string)
  index = 0
  snake_string[index] = snake_string[index].upper();
  for x in snake_string :
      if x == '_':
          snake_string[index + 1] = snake_string[index + 1].upper();
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

def should_gen_service_handler(function):
  '''Returns function metadata only for those functions to include for generating function pointers to driver library'''
  return 'codegen_method' not in function.keys() or function['codegen_method'] == 'public'

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
