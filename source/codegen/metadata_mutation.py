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
    """Marks the size parameters in the metadata."""
    for param in parameters:
        mechanism = common_helpers.get_size_mechanism(param)
        if mechanism in {'len', 'ivi-dance', 'passed-in', 'ivi-dance-with-a-twist'}:
            size_param = get_size_param(param, parameters)
            size_param['is_size_param'] = True

def mark_non_proto_params(parameters):
    """Mark the parameters that shouldn't be included in the proto request message. 
       Their values should be derived from other sources in the service handlers."""
    for param in parameters:
        mechanism = common_helpers.get_size_mechanism(param)
        if mechanism in {'len', 'ivi-dance', 'ivi-dance-with-a-twist'}:
            size_param = get_size_param(param, parameters)
            size_param['include_in_proto'] = False
            if mechanism == 'len':
                size_param['determine_size_from'] = param['name']

def get_size_param(param, parameters):
    named_params = { p['name'] : p for p in parameters }
    return named_params.get(param['size']['value'], None)

def mark_mapped_enum_params(parameters, enums):
    for param in (p for p in parameters if 'enum' in p):
        enum_name = param['enum']
        enum = enums[enum_name]
        if 'generate-mappings' in enum:
            del param['enum']
            param['mapped-enum'] = enum_name

def add_attribute_values_enums(enums, attribute_enums_by_type, service_class_prefix):
    """Update enums metadata to add new enums that will be used value parameter of SetAttribute APIs."""
    for type_name in attribute_enums_by_type:
        unmapped_values = {}
        mapped_values = {}
        for enum_name in sorted(attribute_enums_by_type[type_name]):
            enum = enums[enum_name]
            is_mapped_enum = enum.get("generate-mappings", False)
            for value in enum["values"]:
                value_name = value['name'].replace(f"{service_class_prefix.upper()}_", f"{common_helpers.pascal_to_snake(enum_name).upper()}_")
                if is_mapped_enum:
                    mapped_values[value_name] = value["value"]
                else:
                    unmapped_values[value_name] = value["value"]
        enum_value_prefix = (f"{service_class_prefix}_{type_name[2:]}").upper()
        unmapped_enum_name = get_attribute_values_enum_name(service_class_prefix, type_name)
        mapped_enum_name = get_attribute_values_enum_name(service_class_prefix, type_name, is_mapped=True)
        add_enum(unmapped_enum_name, unmapped_values, enums, enum_value_prefix)
        add_enum(mapped_enum_name, mapped_values, enums, enum_value_prefix, is_mapped=True)
    
def expand_attribute_function_value_param(function, enums, attribute_enums_by_type, service_class_prefix):
    """For SetAttribute and CheckAttribute APIs, update function metadata to mark value parameter as enum."""
    value_param = get_attribute_function_value_param(function)
    if value_param["type"] == "ViConstString":
        param_type = "ViString"
    else:
        param_type = value_param["type"]
    if value_param != None and param_type in attribute_enums_by_type:
        enum_name = get_attribute_values_enum_name(service_class_prefix, param_type)
        mapped_enum_name = get_attribute_values_enum_name(service_class_prefix, param_type, is_mapped=True)
        if enum_name in enums:
            value_param['enum'] = enum_name
        if mapped_enum_name in enums:
            value_param['mapped-enum'] = mapped_enum_name
        has_enum = enum_name in enums or mapped_enum_name in enums
        if not has_enum:
            # Ideally there must be an enum associated with this parameter for SetAttribute* API.
            # Since the enum is empty, users will be passing in raw values. Make it clear via naming.
            value_param['name'] = value_param['name'] + "_raw"

def get_attribute_function_value_param(function):
    return next((param for param in function["parameters"] if param["name"] in {"value", "attributeValue"}), None)

def get_attribute_values_enum_name(service_class_prefix, type, is_mapped=False):
    enum_name_suffix = "Mapped" if is_mapped else "" 
    return service_class_prefix + type[2:] + "AttributeValues" + enum_name_suffix

def add_enum(enum_name, enum_values, enums, enum_value_prefix, is_mapped=False):
    if not enum_values:
        return
    numeric_values = enum_values.values()
    allow_alias = (0 in numeric_values) or (len(numeric_values) != len(set(numeric_values)))
    values = [{"name": name, "value": enum_values[name]} for name in enum_values]
    new_enum = {
        'enum-value-prefix': enum_value_prefix,
        'allow-alias': allow_alias,
        'generate-mappings': is_mapped,
        'values': values
    }
    enums.update({enum_name: new_enum})
