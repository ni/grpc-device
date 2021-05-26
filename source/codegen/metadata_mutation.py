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
        if mechanism in {'len', 'ivi-dance', 'passed-in'}:
            size_param = get_size_param(param, parameters)
            size_param['is_size_param'] = True

def mark_non_proto_params(parameters):
    """Mark the parameters that shouldn't be included in the proto request message. 
       Their values should be derived from other sources in the service handlers."""
    for param in parameters:
        mechanism = common_helpers.get_size_mechanism(param)
        if mechanism in {'len', 'ivi-dance'}:
            size_param = get_size_param(param, parameters)
            size_param['include_in_proto'] = False
            if mechanism == 'len':
                size_param['determine_size_from'] = param['name']

def get_size_param(param, parameters):
    named_params = { p['name'] : p for p in parameters }
    return named_params.get(param['size']['value'], None)

def add_attribute_values_enums(enums, attribute_enums, service_class_prefix):
    """Update enums metadata to add new enums that will be used by SetAttribute* APIs."""
    mapping_types = {
        'ViInt64': 'std::int64_t',
        'ViReal64': 'double',
        'ViString': 'std::string'
    }
    for type_name in attribute_enums:
        values_to_create = {}
        for enum_name in sorted(attribute_enums[type_name]):
            enum = enums[enum_name]
            for value in enum["values"]:
                value_name = value['name'].replace(f"{service_class_prefix.upper()}_", f"{common_helpers.pascal_to_snake(enum_name).upper()}_")
                value_value = value["value"]
                values_to_create[value_name] = value_value
        type_enum_name = get_attribute_values_enum_name(service_class_prefix, type_name)
        enum_value_prefix = (f"{service_class_prefix}_{type_name[2:]}").upper()
        generate_mappings = type_name in mapping_types
        allow_alias = False
        if not generate_mappings:
            enum_values = values_to_create.values()
            allow_alias = len(enum_values) != len(set(enum_values))
        values = []
        for name in values_to_create:
            values.append({"name": name, "value": values_to_create[name]})
        new_enum = {
            'enum-value-prefix': enum_value_prefix,
            'generate-mappings': generate_mappings,
            'allow_alias': allow_alias,
            'values': values
        }
        if generate_mappings:
            new_enum['value-type'] = mapping_types[type_name]
        enums.update({type_enum_name: new_enum})
    
def mark_attr_value_param_if_required(function, attribute_enums, service_class_prefix):
    """For SetAttribute* and CheckAttribute* APIs, update function metadata to mark attribute_value parameter as enum."""
    attribute_value_param = next((param for param in function["parameters"] if param["name"] in {"value", "attributeValue"}), None)
    if attribute_value_param["type"] == "ViConstString":
        enum_type = "ViString"
    else:
        enum_type = attribute_value_param["type"]
    if(attribute_value_param != None and enum_type in attribute_enums):
        attribute_value_param['enum'] = get_attribute_values_enum_name(service_class_prefix, enum_type)

def get_attribute_values_enum_name(service_class_prefix, type):
    return service_class_prefix + type[2:] + "AttributeValues"
