import re
from collections import defaultdict, namedtuple
from typing import List, Optional


def is_output_parameter(parameter):
    return "out" in parameter["direction"]


def is_input_parameter(parameter):
    return "in" in parameter["direction"]


def is_callback_token_parameter(parameter):
    return parameter.get('callback_token', False)


def is_pointer_parameter(parameter):
    return is_output_parameter(parameter) or parameter.get('pointer', False)

# This means the parameter follows a specific varargs convention where
# the user can pass in an arbitrary repetition of fixed arguments.


def is_repeated_varargs_parameter(parameter: dict):
    return parameter.get('repeated_var_args', False)

# This means the parameter can be repeated as many times as desired.
# See also is_repeatied_varargs_parameter()


def is_repeating_parameter(parameter: dict):
    return parameter.get('repeating_argument', False)


def is_array(dataType: str):
    return dataType.endswith("[]") or dataType.endswith("*")


def is_enum(parameter: dict):
    return (
        "enum" in parameter
        or "mapped-enum" in parameter
        or "bitfield_as_enum_array" in parameter
    )


def is_custom_struct(parameter: dict) -> bool:
    return parameter["type"].startswith("struct")


def uses_nidevice_common_message_types(functions: dict) -> bool:
    return any(
        p
        for f in functions.values()
        for p in f["parameters"]
        if is_nidevice_common_message_type(p)
    )


_NIDEVICE_COMMON_MESSAGE_TYPES = (
    "nidevice_grpc.NIComplexNumber",
    "nidevice_grpc.NIComplexNumberF32",
    "nidevice_grpc.NIComplexI16",
    "nidevice_grpc.SmtSpectrumInfo",
)

_WELL_KNOWN_MESSAGE_TYPES = (
    "google.protobuf.Timestamp",
)


def is_nidevice_common_message_type(parameter: dict) -> bool:
    grpc_type = get_underlying_grpc_type(parameter)
    return grpc_type in _NIDEVICE_COMMON_MESSAGE_TYPES


def is_supported_well_known_type(parameter: dict) -> bool:
    grpc_type = get_underlying_grpc_type(parameter)
    return grpc_type in _WELL_KNOWN_MESSAGE_TYPES


def is_struct(parameter: dict) -> bool:
    return (
        is_nidevice_common_message_type(parameter)
        or is_supported_well_known_type(parameter)
        or is_custom_struct(parameter)
    )


def supports_standard_copy_conversion_routines(parameter: dict) -> bool:
    """
    Returns true if the parameter data can be converted with convert_from_grpc and convert_to_grpc.
    """
    return is_struct(parameter) or parameter["grpc_type"] == "repeated bool"


def any_function_uses_timestamp(functions):
    for function in functions:
        if any(p['grpc_type'] == 'google.protobuf.Timestamp' for p in functions[function]['parameters']):
            return True
    return False


def get_custom_types(config: dict) -> dict:
    return config.get("custom_types", {})


def get_input_and_output_custom_types(functions):
    '''Returns a set of custom types used by input and output parameters separately.'''
    input_custom_types = set()
    output_custom_types = set()
    for function in functions:
        struct_params = [
            p
            for p in functions[function]["parameters"]
            if is_custom_struct(p)
        ]
        for parameter in struct_params:
            if is_input_parameter(parameter):
                input_custom_types.add(
                    get_underlying_type_name(parameter["type"]))
            elif is_output_parameter(parameter):
                output_custom_types.add(
                    get_underlying_type_name(parameter["type"]))
    return (input_custom_types, output_custom_types)


def is_null_terminated_in_c(parameter):
    return parameter['grpc_type'] == 'string'


def is_string_arg(parameter):
    return parameter['grpc_type'] in ['string', 'bytes']


def strip_repeated_from_grpc_type(grpc_type):
    if not grpc_type.startswith('repeated '):
        raise Exception("varargs grpc_type " + grpc_type + " must be repeated")
    return grpc_type[len('repeated '):]


def get_underlying_type_name(parameter_type: str) -> str:
    '''Strip away information from type name like brackets for arrays, leading "struct ", etc. leaving just the underlying type name.'''
    return parameter_type.replace("struct ", "").replace('[]', '')


def get_underlying_grpc_type_name(grpc_type: str) -> str:
    return strip_prefix(grpc_type, "repeated ")


def get_underlying_type(parameter_or_attribute: dict) -> str:
    return get_underlying_type_name(parameter_or_attribute["type"])


def get_underlying_grpc_type(parameter: dict) -> str:
    return get_underlying_grpc_type_name(parameter["grpc_type"])


def has_unsupported_parameter(function):
    return any(is_unsupported_parameter(p) for p in function['parameters'])


def is_unsupported_parameter(parameter):
    return is_unsupported_size_mechanism(parameter) \
        or is_unsupported_scalar_array(parameter)


def is_unsupported_size_mechanism(parameter: dict) -> bool:
    size_mechanism = get_size_mechanism(parameter)
    if size_mechanism is None:
        return False
    return is_unsupported_size_mechanism_type(size_mechanism)

# These are the mechanisms that are used to specify the size of arrays/strings. Here's what they mean:
# - fixed: the array is of a constant size. The size is specified in the 'value' member.
# - len: the array's length needs to be passed into the function. The parameter to pass it in is specified
#        in the 'value' member. Should only be used for input arrays. Multiple input arrays can use this
#        mechanism with the same 'value' member - in that case, the service will enforce that those arrays
#        are all the same length.
# - ivi-dance: This is a two-step process. On the first call, pass in NULL, and the function will return
#              how big the array should be (instead of an error as usual). Then, the service creates an array
#              of that size and passes it in. Should only be used for output arrays. The size of the array
#              (which is still passed in) is specified in the 'value' member. Note that it is possible that the
#              second call will return a "buffer too small" error (if the underlying value in the driver has changed
#              size between calls), in which case the "dance" will start again by passing NULL.
# - ivi-dance-with-a-twist: This is similar to ivi-dance, but the size is returned in an output parameter that
#                           is specified in the 'value_twist' member. Should only be used for output arrays. The size
#                           of the array is specified in the 'value' member. This mechanism is necessary if there
#                           are multiple output arrays (so ivi-dance won't work). Similar to ivi-dance, this will loop
#                           around if a "buffer too small" error is returned on the second call.
# - passed-in: The array's size is passed in in a separate parameter, which is specified in the 'value' member.
#              Should only be used for output arrays (otherwise you can just use 'len').
# - passed-in-by-ptr: The array's size is passed in in a separate parameter, which is specified in the 'value' member.
#                     It is passed in by pointer, and on return the underlying call will set the actual number of
#                     elements filled in to the array as long as that is smaller than the passed-in value. (if it is
#                     larger, the underlying call will return an error)
#                     Should only be used for output arrays.
# - custom-code: The array's size is determined by the C++ code in the 'value' member.


def is_unsupported_size_mechanism_type(size_mechanism: str) -> bool:
    return not size_mechanism in {'fixed', 'len', 'ivi-dance', 'passed-in', 'passed-in-by-ptr', 'ivi-dance-with-a-twist', 'custom-code'}


def is_unsupported_scalar_array(parameter):
    return is_array(parameter['type']) and is_unsupported_enum_array(parameter)


def is_unsupported_enum_array(parameter):
    if is_enum(parameter):
        if is_input_parameter(parameter):
            return False

        return not is_supported_enum_array_output_type(parameter)
    return False


def is_supported_enum_array_output_type(parameter):
    return is_string_arg(parameter) or is_static_castable_enum_type(parameter)


def is_static_castable_enum_type(parameter):
    grpc_type = get_underlying_grpc_type(parameter)
    # Note: sint32 could work here but causes issue with existing attribute output accessors
    # because it's not wire-compatible with enum. If it's added here, we need to make sure that
    # we're handling compatibility issues on those methods.
    return grpc_type in ['int32', 'uint32']


PascalTokenSubstitution = namedtuple('PascalTokenSubstitution', [
                                     'pascal_representation', 'preferred_representation'])
SPECIAL_CASE_PASCAL_TOKENS = [
    # NI uses UInt, not Uint, and never U_INT when converting to snake.
    PascalTokenSubstitution('Uint', 'UInt')
]


def normalize_special_pascal_tokens(pascal_or_camel_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        pascal_or_camel_string = pascal_or_camel_string.replace(
            special_case_override, pascal_token)
    return pascal_or_camel_string


def insert_special_case_pascal_tokens(normal_pascal_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        normal_pascal_string = normal_pascal_string.replace(
            pascal_token, special_case_override)
    return normal_pascal_string


def insert_leading_special_case_pascal_tokens(camel_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        camel_string = replace_prefix(
            camel_string, pascal_token.lower(), special_case_override)
    return camel_string


def normalize_leading_special_case_pascal_tokens(pascal_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        pascal_string = replace_prefix(
            pascal_string, special_case_override, pascal_token)
    return pascal_string


def is_actually_pascal(camel_or_pascal_string: str) -> bool:
    return 'A' <= camel_or_pascal_string[0] <= 'Z'


def _camel_to_snake(camel_string: str) -> str:
    '''
    Returns a snake_string for a given camelString.

    External callers should use/create a wrapper instead (i.e. get_grpc_field_name).
    '''
    if is_actually_pascal(camel_string):
        camel_string = pascal_to_camel(camel_string)

    camel_string = normalize_special_pascal_tokens(camel_string)
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
    for x in snake_string:
        if x == '_':
            snake_string[index + 1] = snake_string[index + 1].upper()
            del snake_string[index]
        index = index + 1
    result = ("".join(snake_string))
    return insert_special_case_pascal_tokens(result)


def pascal_to_camel(pascal_string):
    '''Returns a camelString for a given PascalString.'''
    pascal_string = normalize_leading_special_case_pascal_tokens(pascal_string)
    if not is_actually_pascal(pascal_string):
        return pascal_string

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


def ensure_pascal_case(pascal_or_camel_string):
    '''Ensures that a camel/pascal case string is pascal case
    NOTE: does not distinguish leading all-caps acronyms.'''
    pascal_or_camel_string = insert_leading_special_case_pascal_tokens(
        pascal_or_camel_string)

    match = re.fullmatch(r'^([a-z])(.*)$', pascal_or_camel_string)
    if match:
        return match[1].upper() + match[2]

    return pascal_or_camel_string


def pascal_to_snake(pascal_string):
    '''Returns a snake_string for a given PascalString.'''
    camel_string = pascal_to_camel(pascal_string)
    snake_string = _camel_to_snake(camel_string)
    return ("".join(snake_string))


def filter_proto_rpc_functions(functions):
    '''Returns function metadata only for those functions to include for generating proto rpc methods'''
    functions_for_proto = {'public', 'CustomCode'}
    return [name for name, function in functions.items() if function.get('codegen_method', 'public') in functions_for_proto]


def get_attribute_enums_by_type(attributes):
    '''Returns a dictionary of different attribute data types that use enum alongwith set of enums used'''
    attribute_enums_by_type = defaultdict(set)
    # For Compatibility: Pre-adding the following types to the map causes them to use value_raw
    # params even if they have no enum values. This is part of the shipping API for MI drivers.
    for enum_type in ['ViInt32', 'ViInt64', 'ViReal64', 'ViString']:
        attribute_enums_by_type[enum_type] = set()

    for attribute_name in attributes:
        attribute = attributes[attribute_name]
        if 'enum' in attribute:
            attribute_type = get_underlying_type(attribute)
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
            if 'bitfield_as_enum_array' in parameter:
                function_enums.add(parameter['bitfield_as_enum_array'])
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


def get_size_mechanism(parameter: dict) -> Optional[str]:
    size = parameter.get('size', {})
    return size.get('mechanism', None)


def has_size_mechanism_tag(parameter: dict, tag: str) -> bool:
    size_request = parameter.get('size', {})
    tags = size_request.get('tags', {})
    return tag in tags


def has_strlen_bug(parameter: dict) -> bool:
    """True if the parameter is a string output where the size
    mechanism implementation has the 'strlen bug':
        Reports strlen instead of strlen + 1 for the required
        buffersize
    We assume that this bug may some day be fixed, so the 
    implementation needs to allocate the extra character but also
    trim it off if it's an extra null.
    """
    return has_size_mechanism_tag(parameter, "strlen-bug")


def is_optional(parameter: dict) -> bool:
    return has_size_mechanism_tag(parameter, "optional")


def get_buffer_size_expression(parameter: dict) -> str:
    """Returns the C++ size expression for the size of the underlying
    C API bugger for a string/array parameter.
    Unlike get_size_expression, this will include the trailing null terminator
    for strings (which is in the size reported by driver APIs).
    """
    size_mechanism = get_size_mechanism(parameter)
    if 'size' not in parameter:
        raise Exception("No size for parameter " + parameter["name"])
    if size_mechanism == 'fixed':
        return parameter['size']['value']
    elif size_mechanism == 'ivi-dance-with-a-twist':
        return get_grpc_field_name_from_str(parameter['size']['value_twist'])
    elif size_mechanism == 'passed-in-by-ptr':
        return get_grpc_field_name_from_str(parameter['size']['value']) + '_copy'
    else:
        return get_grpc_field_name_from_str(parameter['size']['value'])


def get_size_expression(parameter: dict) -> str:
    """"Returns the C++ size expression for sizing the C++ container type
    for a given parameter."""
    expression = get_buffer_size_expression(parameter)
    if is_null_terminated_in_c(parameter):
        # if the C API reports strlen instead of size:
        # Don't subtract one for the null terminator, the API already did!
        if has_strlen_bug(parameter):
            return f"{expression} /* Workaround: strlen-bug */"
        return f"{expression} - 1"
    return expression


def is_ivi_dance_array_param(parameter):
    return get_size_mechanism(parameter) == 'ivi-dance'


def has_ivi_dance_param(parameters):
    return any(is_ivi_dance_array_param(p) for p in parameters)


def has_repeated_varargs_parameter(parameters):
    return any(is_repeated_varargs_parameter(p) for p in parameters)

# Google Mock can't handle the case where a function has a variable number of arguments
# and there's also a limit on the max number of arguments.


def can_mock_function(parameters):
    # I'm not sure this is exactly right, but it does enough to distinguish between
    # non-varargs functions and varargs functions that take > 100 parameters.
    MAX_MOCK_PARAM_LEN = 20
    repeated_varargs_parameters = [
        p for p in parameters if is_repeated_varargs_parameter(p)]
    first_repeating_parameters = len(
        [p for p in parameters if is_repeating_parameter(p)])
    if not any(repeated_varargs_parameters):
        return len(parameters) - first_repeating_parameters <= MAX_MOCK_PARAM_LEN
    varargs_parameter = repeated_varargs_parameters[0]
    return len(parameters) - first_repeating_parameters - len(repeated_varargs_parameters) + (first_repeating_parameters * varargs_parameter['max_length']) <= MAX_MOCK_PARAM_LEN


def get_ivi_dance_params(parameters):
    array_param = next(
        (p for p in parameters if is_ivi_dance_array_param(p)), None)
    size_param = next(
        p for p in parameters if p['name'] == array_param['size']['value']) if array_param else None
    other_params = (p for p in parameters if p !=
                    array_param and p != size_param)
    return (size_param, array_param, other_params)


def get_twist_value(parameters):
    for p in parameters:
        if is_array(p['type']):
            size = p.get('size', {})
            value_twist = size.get('value_twist', None)
            if value_twist is not None:
                return value_twist
    return None


def is_ivi_dance_array_with_a_twist_param(parameter):
    return get_size_mechanism(parameter) == 'ivi-dance-with-a-twist'


def has_ivi_dance_with_a_twist_param(parameters):
    return any(is_ivi_dance_array_with_a_twist_param(p) for p in parameters)


def get_param_with_name(parameters: List[dict], name: str) -> dict:
    matched_params = (
        p
        for p in parameters
        if p['name'] == name
    )
    return next(matched_params)


def get_ivi_dance_with_a_twist_params(parameters):
    array_param = next(
        (p for p in parameters if is_ivi_dance_array_with_a_twist_param(p)))

    size_param = get_param_with_name(parameters, array_param['size']['value'])
    twist_param = get_param_with_name(
        parameters, array_param['size']['value_twist'])

    other_params = (
        p
        for p in parameters
        if p not in [array_param, size_param, twist_param]
    )
    return (size_param, twist_param, array_param, other_params)


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


def trim_trailing_comma():
    """For use as a mako filter.
        Returns a function that removes the last comma from a block of text (preserves newlines).
        Consider this as an alternative to str.join when it allows preserving context in the mako file."""
    def trim_trailing_comma_impl(text: str) -> str:
        i = text.rfind(",")
        return text[:i] + text[i+1:]

    return lambda text: trim_trailing_comma_impl(text)


def filter_parameters_for_grpc_fields(parameters_or_fields: List[dict]):
    """Filter out the parameters that shouldn't be represented by a field on a grpc message.
        For example, get rid of any parameters whose values should be determined from another parameter."""
    return [p for p in parameters_or_fields if p.get('include_in_proto', True)]


class AttributeGroup:
    def __init__(self, name, attributes, config):
        self.name = name
        self.attributes = attributes
        self._config = config

    def get_attributes_split_by_sub_group(self):
        """
        Splits attributes by type, with an additional "Reset" sub-group
        for resettable attributes.
        """
        if not get_split_attributes_by_type(self._config):
            return {'': self.attributes}

        categorized_attributes = defaultdict(dict)
        for id, data in self.attributes.items():
            data_type = get_grpc_type_name_for_identifier(
                data['type'], self._config)
            categorized_attributes[data_type][id] = data
            if data.get('resettable', False):
                categorized_attributes['Reset'][id] = data
        return categorized_attributes


def get_attribute_enum_suffix(config: dict) -> str:
    use_legacy_prefix = use_legacy_attribute_prefix(config)
    return "Attributes" if use_legacy_prefix else "Attribute"


def get_attribute_enum_name(group_name: str, data_type: str, config: dict) -> str:
    attribute_suffix = get_attribute_enum_suffix(config)
    return f'{group_name}{data_type}{attribute_suffix}'


def get_attribute_groups(data):
    attributes = data['attributes']
    config = data['config']

    # If the attributes are already in string categories: those are the groups. Return as-is.
    first_key = next(iter(attributes), None)
    if isinstance(first_key, str):
        return [AttributeGroup(name, attributes, config) for name, attributes in attributes.items()]

    # If there's just one level of attributes: use the service_class_prefix as the group.
    service_class_prefix = config['service_class_prefix']
    return [AttributeGroup(service_class_prefix, attributes, config)]


def strip_prefix(s: str, prefix: str) -> str:
    return s[len(prefix):] if s.startswith(prefix) else s


def strip_suffix(s: str, suffix: str) -> str:
    return s[: -len(suffix)] if s.endswith(suffix) else s


def replace_prefix(s: str, prefix: str, sub: str) -> str:
    return sub + s[len(prefix):] if s.startswith(prefix) else s


def get_grpc_type_name_for_identifier(data_type, config):
    """
    Used to create an identifier string based on the grpc_type
    i.e., double -> Double. repeated double -> DoubleArray.
    """
    grpc_type = get_grpc_type(data_type, config)
    grpc_type = re.sub(r'^(repeated )(\w+)$', r'\2Array', grpc_type)
    # take the last identifier if the type is namespaced (i.e., Timestamp)
    grpc_type = grpc_type.split(".")[-1]
    return ensure_pascal_case(grpc_type)


def get_grpc_type_from_ivi(
        type: str,
        is_array: bool,
        driver_name_pascal: str,
        config: dict) -> str:
    add_repeated = is_array
    if 'ViSession' in type:
        type = 'nidevice_grpc.Session'
    if 'ViBoolean' in type:
        type = 'bool'
    if 'ViReal64' in type:
        type = 'double'
    if 'ViInt32' in type:
        type = 'sint32'
    if 'ViConstString' in type:
        type = 'string'
    if 'ViString' in type:
        type = 'string'
    if 'ViRsrc' in type:
        type = 'string'
    if 'ViChar' in type:
        if is_array:
            add_repeated = False
            type = 'string'
        else:
            type = 'uint32'
    if 'ViReal32' in type:
        type = 'float'
    if 'ViAttr' in type:
        type = get_attribute_enum_name(driver_name_pascal, "", config)
    if 'ViInt8' in type:
        if is_array:
            type = "bytes"
            add_repeated = False
        else:
            type = 'uint32'
    if 'void*' in type:
        type = 'fixed64'
    if 'ViInt16' in type:
        type = 'sint32'
    if 'ViInt64' in type:
        type = 'int64'
    if 'ViUInt16' in type:
        type = 'uint32'
    if 'ViUInt32' in type:
        type = 'uint32'
    if 'ViUInt64' in type:
        type = 'uint64'
    if 'ViUInt8' in type:
        if is_array:
            type = "bytes"
            add_repeated = False
        else:
            type = 'uint32'
    if 'ViStatus' in type:
        type = 'sint32'
    if 'ViAddr' in type:
        type = 'fixed64'
    if 'int' == type:
        type = 'sint32'
    if "[]" in type:
        type = type.replace("[]", "")

    return "repeated " + type if add_repeated else type


def get_grpc_type(data_type, config):
    service_class_prefix = config['service_class_prefix']
    if 'type_to_grpc_type' in config:
        type_map = config['type_to_grpc_type']
        stripped_type = strip_prefix(data_type, 'const ')
        if stripped_type in type_map:
            return type_map[stripped_type]

        repeated = is_array(data_type)

        stripped_type = strip_suffix(stripped_type, '*')
        stripped_type = strip_suffix(stripped_type, '[]')

        # Note: if we never resolve or strip anything, this will fallback
        # to the original datatype.
        resolved_type = type_map.get(stripped_type, stripped_type)

        return f'repeated {resolved_type}' if repeated else resolved_type

    return get_grpc_type_from_ivi(
        data_type,
        is_array(data_type),
        service_class_prefix,
        config)


def use_legacy_attribute_prefix(config: dict) -> bool:
    return config.get('use_legacy_attribute_prefix', False)


def get_split_attributes_by_type(config):
    return config.get('split_attributes_by_type', False)


def supports_raw_attributes(config: dict) -> bool:
    return config.get('supports_raw_attributes', False)


def get_enum_value_cpp_type(enum: dict) -> str:
    """Uses the python datatype of the first value in the enum to
    infer the C++ type.

    Used for mapped enums."""
    enum_value = enum["values"][0]["value"]
    if isinstance(enum_value, float):
        return "double"
    if isinstance(enum_value, int):
        return "std::int32_t"
    if isinstance(enum_value, str):
        return "std::string"
    return "std::int32_t"


def is_regular_string_arg(parameter: dict) -> bool:
    """Excludes: byte arrays"""
    return is_string_arg(parameter) and not parameter["grpc_type"] == "bytes"


def is_regular_byte_array_arg(parameter: dict) -> bool:
    """Excludes: strings and byte arrays that are mapped to enums"""
    return parameter["grpc_type"] == "bytes" and not is_enum(parameter)


def get_additional_headers(config: dict, including_from_file: str) -> List[str]:
    additional_header_requirements = config.get("additional_headers", {})
    return (
        header
        for header, required_by in additional_header_requirements.items()
        if including_from_file in required_by
    )


def get_enum_value_prefix(enum_name: str, enum: dict) -> str:
    return enum.get("enum-value-prefix", pascal_to_snake(enum_name).upper())


def get_driver_readiness(config: dict) -> str:
    return config.get('code_readiness', 'Release')


def get_grpc_field_name(param: dict) -> str:
    """"
    Returns the name of the protobuf field for the given param.

    This will be a snake_case_string, that can be used in the proto
    definition itself, as well as in C++ code that accesses the field
    from a Request/Response message.
    """
    return param.get("grpc_name", _camel_to_snake(param["name"]))


def get_grpc_field_name_from_str(field_name: str) -> str:
    """
    NOTE: Does not account for "grpc_name" overrides, but can be used to
    get a proto name from a camelCase field name when no overrides are present.
    """
    return _camel_to_snake(field_name)


def get_cpp_local_name(param: dict) -> str:
    """"
    Returns a similar to token get_grpc_field_name, but will ensure
    that the name is valid as a C++ variable name.

    NOTE: this is not used consistently to differentiate from get_grpc_field_name.
    For that reason, the field respects the "grpc_name" override so that the two
    will match in the vast majority of cases where "name" is not a reserved keyword.
    If "grpc_name" is a reserved keyword, this may be an issue (but don't use 
    reserved grpc_name!).
    """
    return param.get("grpc_name", _camel_to_snake(param["cppName"]))
