from collections import namedtuple
from typing import Optional
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
    'sbyte', 'sealed', 'short', 'sizeof', 'stackalloc', 'static', 'string', 'struct', 'switch',
    'this', 'throw', 'true', 'try', 'typeof',
    'uint', 'ulong', 'unchecked', 'unsafe', 'ushort', 'using',
    'virtual', 'void', 'volatile',
    'while'
]

def sanitize_names(parameters):
    """Sanitizes name fields on a list of parameter objects and populates the cppname field with the sanitized value."""
    for parameter in parameters:
        if 'callback_params' in parameter:
            sanitize_names(parameter['callback_params'])
        parameter['cppName'] = parameter['name']
        if parameter['cppName'] in RESERVED_WORDS:
            parameter['cppName'] += 'Parameter'


def set_var_args_types(parameters, config):
    """Sets information about varargs parameters in the metadata."""
    for parameter in parameters:
        if common_helpers.is_repeated_varargs_parameter(parameter):
            parameter['type'] = '...'


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
            if size_param['direction'] == 'in':
                # Output size_params can still be included in the proto
                # as information.
                size_param['include_in_proto'] = False
            if mechanism == 'len':
                if 'determine_size_from' not in size_param:
                    size_param['determine_size_from'] = []
                size_param['determine_size_from'].append(param['name'])

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


def populate_grpc_types(parameters, config):
  for parameter in parameters:
    if 'callback_params' in parameter:
        populate_grpc_types(
            parameter['callback_params'], config)
    if 'grpc_type' in parameter:
        continue
    parameter['grpc_type'] = common_helpers.get_grpc_type(
        parameter['type'],
        config)


def get_short_enum_type_name(type):
    stripped_name = common_helpers.strip_prefix(type, "Vi")
    return common_helpers.ensure_pascal_case(stripped_name,)


def remove_leading_group_name(enum_value_name, group_name):
    return common_helpers.strip_prefix(enum_value_name, f"{group_name.upper()}_")


def add_leading_enum_name(enum_value_name, enum_name):
    return f"{common_helpers.pascal_to_snake(enum_name).upper()}_" + enum_value_name


def add_attribute_values_enums(enums, attribute_enums_by_type, group_name):
    """Update enums metadata to add new enums that will be used value parameter of SetAttribute APIs."""
    for type_name in attribute_enums_by_type:
        unmapped_values = {}
        mapped_values = {}
        for enum_name in sorted(attribute_enums_by_type[type_name]):
            enum = enums[enum_name]
            is_mapped_enum = enum.get("generate-mappings", False)
            for value in enum["values"]:
                # Remove the leading group name (if any) because it will be redundant in the aggregate enum.
                value_name = remove_leading_group_name(value["name"], group_name)
                # Add a leading enum to differentiate sub-enums within the aggregate values enum.
                value_name = add_leading_enum_name(value_name, enum_name)
                if is_mapped_enum:
                    mapped_values[value_name] = value["value"]
                else:
                    unmapped_values[value_name] = value["value"]

        shortened_type_name = get_short_enum_type_name(type_name)
        enum_value_prefix = (f"{group_name}_{shortened_type_name}").upper()
        unmapped_enum_name = get_attribute_values_enum_name(group_name, type_name)
        mapped_enum_name = get_attribute_values_enum_name(group_name, type_name, is_mapped=True)
        add_enum(unmapped_enum_name, unmapped_values, enums, enum_value_prefix)
        add_enum(mapped_enum_name, mapped_values, enums, enum_value_prefix, is_mapped=True)
    

AttributeReferencingParameter = namedtuple("AttributeReferencingParameter", ["attribute_group", "parameter"])

class AttributeAccessorExpander:
    """
    Wraps an _attribute_type_map of:
    
    group -> type -> attributes

    and implements the metadata_mutations to add_attribute_values_enums, expand_attribute_function_value_param,
    and patch_attribute_enum_type.
    """
    def __init__(self, metadata):
        self._config = metadata['config']
        self._enums = metadata['enums']
        self._attribute_type_map = {}

        for group in common_helpers.get_attribute_groups(metadata):
            attribute_enums_by_type = common_helpers.get_attribute_enums_by_type(
                group.attributes)
            add_attribute_values_enums(
                self._enums,
                attribute_enums_by_type,
                group.name)
            self._attribute_type_map[group.name] = attribute_enums_by_type


    def get_attribute_reference_parameter(self, parameters) -> Optional[AttributeReferencingParameter]:
        def try_resolve_attribute_reference(parameter) -> Optional[AttributeReferencingParameter]:
            param_type = parameter['grpc_type']
            # All attribute parameters must have a grpc_type of {group_name}Attributes.
            # In MI, this is added during metadata mutation of ViAttr types.
            potential_attribute_name = common_helpers.strip_suffix(param_type, 'Attributes')
            if potential_attribute_name in self._attribute_type_map:
                return AttributeReferencingParameter(potential_attribute_name, parameter)
            return None

        # Assumption: there are 0 or 1 parameters that reference an attribute per function.
        attribute_resolve_results = (try_resolve_attribute_reference(p) for p in parameters)
        valid_references = (ref for ref in attribute_resolve_results if ref)
        return next(valid_references, None)


    def patch_attribute_enum_type(self, function_name, func):
        """
        If a driver splits attribute enums by type, 
        then the referencing functions need to be updated to match:
        ScaleAttributes -> ScaleAttributesInt32, ScaleAttributesDouble, etc.
        """
        if not common_helpers.get_split_attributes_by_type(self._config):
            return
        parameters = func['parameters']
        attribute_reference = self.get_attribute_reference_parameter(parameters)
        if attribute_reference:
            group = attribute_reference.attribute_group
            attribute_param = attribute_reference.parameter
            if function_name.startswith('Reset'):
                sub_group = 'Reset'
            else:
                value_param = get_attribute_function_value_param(func)
                sub_group = common_helpers.get_grpc_type_name_for_identifier(
                    value_param['type'],
                    self._config)
            if common_helpers.supports_raw_attributes(self._config):
                attribute_param['enum'] = common_helpers.get_attribute_enum_name(group, sub_group)
                attribute_param['grpc_type'] = 'int32'
                attribute_param['raw_attribute'] = True
            else:
                attribute_param['grpc_type'] = common_helpers.get_attribute_enum_name(group, sub_group)


    def expand_attribute_value_params(self, func):
        parameters = func["parameters"]
        attribute_reference = self.get_attribute_reference_parameter(parameters)
        if attribute_reference:
            expand_attribute_function_value_param(
                func,
                self._enums, 
                self._attribute_type_map[attribute_reference.attribute_group], 
                attribute_reference.attribute_group)


def expand_attribute_function_value_param(function, enums, attribute_enums_by_type, service_class_prefix):
    """For SetAttribute and CheckAttribute APIs, update function metadata to mark value parameter as enum."""
    value_param = get_attribute_function_value_param(function)
    if not value_param:
        return
    if value_param['direction'] == 'out':
        if common_helpers.is_static_castable_enum_type(value_param):
            value_param['use_checked_enum_conversion'] = True
        else:
            return

    if value_param["type"] == "ViConstString":
        param_type = "ViString"
    else:
        param_type = common_helpers.get_underlying_type(value_param)
    if param_type in attribute_enums_by_type:
        enum_name = get_attribute_values_enum_name(service_class_prefix, param_type)
        mapped_enum_name = get_attribute_values_enum_name(service_class_prefix, param_type, is_mapped=True)
        enum_exists = enum_name in enums
        mapped_enum_exists = mapped_enum_name in enums
        if enum_exists:
            value_param['enum'] = enum_name
        if mapped_enum_exists:
            value_param['mapped-enum'] = mapped_enum_name
        if not enum_exists and not mapped_enum_exists:
            # Ideally there must be an enum associated with this parameter for SetAttribute* API.
            # Since the enum is empty, users will be passing in raw values. Make it clear via naming.
            value_param['name'] = value_param['name'] + "_raw"

def get_attribute_function_value_param(function):
    return next((param for param in function["parameters"] if param["name"] in {"value", "attributeValue"}), None)

def get_attribute_values_enum_name(group_name, type, is_mapped=False):
    enum_name_suffix = "Mapped" if is_mapped else "" 
    shortened_type_name = get_short_enum_type_name(type)
    return group_name + shortened_type_name + "AttributeValues" + enum_name_suffix

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
