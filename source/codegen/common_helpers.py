"""Common helpers."""

import os
import re
from collections import defaultdict, namedtuple
from typing import Any, Dict, List, NamedTuple, Optional

_NIDEVICE_COMMON_MESSAGE_TYPES = (
    "nidevice_grpc.NIComplexNumber",
    "nidevice_grpc.NIComplexNumberF32",
    "nidevice_grpc.NIComplexI16",
    "nidevice_grpc.SmtSpectrumInfo",
)

_WELL_KNOWN_MESSAGE_TYPES = ("google.protobuf.Timestamp",)

PascalTokenSubstitution = namedtuple(
    "PascalTokenSubstitution", ["pascal_representation", "preferred_representation"]
)
SPECIAL_CASE_PASCAL_TOKENS = [
    # NI uses UInt, not Uint, and never U_INT when converting to snake.
    PascalTokenSubstitution("Uint", "UInt")
]


def is_output_parameter(parameter):
    """Whether the parameter is an output parameter."""
    return "out" in parameter["direction"]


def is_input_parameter(parameter):
    """Whether the parameter is an input parameter."""
    return "in" in parameter["direction"]


def levels_of_pointer_indirection(parameter: dict) -> int:
    """Levels of pointer indirection for pointer. I.e. number of '*'s."""
    return [is_output_parameter(parameter), parameter.get("pointer", False)].count(True)


def is_repeated_varargs_parameter(parameter: dict):
    """Whether the parameter is a repeated varargs parameter.

    This means the parameter follows a specific varargs convention where the user can pass in an
    arbitrary repetition of fixed arguments.
    """
    return parameter.get("repeated_var_args", False)


def is_proto_only_paramater(parameter: dict):
    """Whether the parameter is only included in the proto file and not the driver API."""
    return parameter.get("proto_only", False)


def is_repeating_parameter(parameter: dict):
    """Whether the parameter is a repeating parameter.

    This means the parameter can be repeated as many times as desired. See also
    is_repeated_varargs_parameter().
    """
    return parameter.get("repeating_argument", False)


def is_array(data_type: str):
    """Whether the parameter is an array parameter."""
    return data_type.endswith("[]") or data_type.endswith("*")


def get_bitfield_enum_type(parameter: dict) -> str:
    """Get the enum type for a bitfield represented as an enum array."""
    return parameter["bitfield_as_enum_array"]


def is_bitfield_as_enum_array(parameter: dict) -> bool:
    """Whether the parameter is a bitfield represented as an enum array."""
    return "bitfield_as_enum_array" in parameter


def is_enum(parameter: dict):
    """Whether the parameter's type is an enum."""
    return "enum" in parameter or "mapped-enum" in parameter or is_bitfield_as_enum_array(parameter)


def _is_custom_struct(parameter: dict) -> bool:
    return parameter["type"].startswith("struct")


def uses_nidevice_common_message_types(config: dict, functions: dict) -> bool:
    """Whether a custom_type or function has any parameters whose type is a common nidevice type."""
    any_funcs = any(
        p
        for f in functions.values()
        for p in f["parameters"]
        if _is_nidevice_common_message_type(p)
    )
    any_custom_types = any(
        field
        for ct in config.get("custom_types", {})
        for field in ct["fields"]
        if _is_nidevice_common_message_type(field)
    )
    return any_funcs or any_custom_types


def _is_nidevice_common_message_type(parameter: dict) -> bool:
    if "grpc_type" not in parameter:
        return False
    grpc_type = _get_underlying_grpc_type(parameter)
    return grpc_type in _NIDEVICE_COMMON_MESSAGE_TYPES


def _is_supported_well_known_type(parameter: dict) -> bool:
    grpc_type = _get_underlying_grpc_type(parameter)
    return grpc_type in _WELL_KNOWN_MESSAGE_TYPES


def is_struct(parameter: dict) -> bool:
    """Whether the parameter's type is a struct."""
    return (
        _is_nidevice_common_message_type(parameter)
        or _is_supported_well_known_type(parameter)
        or _is_custom_struct(parameter)
    )


def is_driver_typedef_with_same_size_but_different_qualifiers(type: str) -> bool:
    """Whether the type has different per-platform qualifiers.

    Some of the drivers use different qualifiers for integers of same size on windows vs linux. We
    need to reinterpret_cast in the generated code to get the correct value.
    """
    return type in (
        "ViAddr",
        "ViInt32",
        "ViUInt32",
        "ViUInt16",
        "uInt32",
        "int32",
        "uInt64",
        "int64",
        "nxTimestamp1ns_t",
        "nxTimestamp100ns_t",
        "ViAttr",
    )


def _has_copy_convert_tag(parameter):
    return parameter.get("supports_standard_copy_convert", False)


def supports_standard_copy_conversion_routines(parameter: dict) -> bool:
    """Whether the parameter can be converted with convert_from_grpc and convert_to_grpc."""
    return (
        _has_copy_convert_tag(parameter)
        or is_struct(parameter)
        or parameter.get("grpc_type", "") == "repeated bool"
    )


def supports_standard_output_allocation_routines(parameter: dict) -> bool:
    """Whether the parameter can be allocated as an output param with allocate_output_storage."""
    return parameter.get("supports_standard_output_allocation", False)


def _any_function_uses_grpc_type(functions, type_name):
    return any(p["grpc_type"] == type_name for f in functions for p in functions[f]["parameters"])


def list_external_proto_dependencies(functions: dict) -> List[str]:
    """Return a list of external proto files required by the functions dictionary."""
    mappings = {
        "google.protobuf.Timestamp": "google/protobuf/timestamp.proto",
        "google.protobuf.Duration": "google/protobuf/duration.proto",
    }
    return [
        proto_name
        for type_name, proto_name in mappings.items()
        if _any_function_uses_grpc_type(functions, type_name)
    ]


def get_custom_types(config: dict) -> List[Dict[str, Any]]:
    """Get the custom_types config setting."""
    return config.get("custom_types", [])


def get_input_and_output_custom_types(config, functions):
    """Return a set of custom types used by input and output parameters separately."""
    input_custom_types = set()
    output_custom_types = set()
    for function in functions:
        struct_params = [p for p in functions[function]["parameters"] if _is_custom_struct(p)]
        for parameter in struct_params:
            underlying_type_name = get_underlying_type_name(parameter["type"])
            nested_types = _get_nested_types(config, underlying_type_name)
            if is_input_parameter(parameter):
                input_custom_types.add(underlying_type_name)
                input_custom_types = input_custom_types.union(nested_types)
            elif is_output_parameter(parameter):
                output_custom_types.add(underlying_type_name)
                output_custom_types = output_custom_types.union(nested_types)
    return (input_custom_types, output_custom_types)


def _get_nested_types(config, type_name):
    custom_types = set()
    matching_custom_type = [
        custom_type
        for custom_type in config.get("custom_types", [])
        if custom_type["name"] == type_name
    ][0]
    for field in matching_custom_type["fields"]:
        if field["type"].startswith("struct "):
            nested_type_name = get_underlying_type_name(field["type"])
            custom_types.add(nested_type_name)
            custom_types = custom_types.union(_get_nested_types(config, nested_type_name))
    return custom_types


def _is_null_terminated_in_c(parameter):
    return parameter["grpc_type"] == "string"


def is_string_arg(parameter):
    """Whether the parameter's type is string or bytes."""
    return parameter["grpc_type"] in ["string", "bytes"]


def strip_repeated_from_grpc_type(grpc_type):
    """Strip "repeated" from the grpc_type."""
    if not grpc_type.startswith("repeated "):
        raise Exception("varargs grpc_type " + grpc_type + " must be repeated")
    return grpc_type[len("repeated ") :]


def get_underlying_type_name(parameter_type: str) -> str:
    """Get the underlying type name of the given type.

    Strip away information from type name like brackets for arrays, leading "struct ", etc. leaving
    just the underlying type name.
    """
    return parameter_type.replace("struct ", "").replace("[]", "")


def _get_underlying_grpc_type_name(grpc_type: str) -> str:
    return strip_prefix(grpc_type, "repeated ")


def get_underlying_type(parameter_or_attribute: dict) -> str:
    """Get the underlying type name of the given parameter or attribute."""
    return get_underlying_type_name(parameter_or_attribute["type"])


def _get_underlying_grpc_type(parameter: dict) -> str:
    return _get_underlying_grpc_type_name(parameter.get("grpc_type", ""))


def has_unsupported_parameter(function):
    """Whether the given function has a parameter that's not supported.

    Examples of unsupported parameters:
        * Parameters with an unsupported size mechanism
        * Output array parameters whose type is an enum whose underlying type is not a string or
          32-bit int
    """
    return any(_is_unsupported_parameter(p) for p in function["parameters"])


def _is_unsupported_parameter(parameter):
    return is_unsupported_size_mechanism(parameter) or _is_unsupported_scalar_array(parameter)


def is_unsupported_size_mechanism(parameter: dict) -> bool:
    """Whether the parameter has a size that uses an unsupported mechanism."""
    size_mechanism = get_size_mechanism(parameter)
    if size_mechanism is None:
        return False
    return is_unsupported_size_mechanism_type(size_mechanism)


# These are the mechanisms that are used to specify the size of arrays/strings. Here's what they
# mean:
# - fixed:
#     the array is of a constant size. The size is specified in the 'value' member.
# - len:
#     the array's length needs to be passed into the function. The parameter to pass it in is
#     specified in the 'value' member. Should only be used for input arrays. Multiple input arrays
#     can use this mechanism with the same 'value' member - in that case, the service will enforce
#     that those arrays are all the same length.
# - ivi-dance:
#     This is a two-step process. On the first call, pass in NULL, and the function will return how
#     big the array should be (instead of an error as usual). Then, the service creates an array of
#     that size and passes it in. Should only be used for output arrays. The size of the array
#     (which is still passed in) is specified in the 'value' member. Note that it is possible that
#     the second call will return a "buffer too small" error (if the underlying value in the driver
#     has changed size between calls), in which case the "dance" will start again by passing NULL.
# - ivi-dance-with-a-twist:
#     This is similar to ivi-dance, but the size is returned in an output parameter that is
#     specified in the 'value_twist' member. Should only be used for output arrays. The size of the
#     array is specified in the 'value' member. This mechanism is necessary if there are multiple
#     output arrays (so ivi-dance won't work). Similar to ivi-dance, this will loop around if a
#     "buffer too small" error is returned on the second call.
# - passed-in:
#     The array's size is passed in in a separate parameter, which is specified in the 'value'
#     member. Should only be used for output arrays (otherwise you can just use 'len').
# - passed-in-by-ptr:
#     The array's size is passed in in a separate parameter, which is specified in the 'value'
#     member. It is passed in by pointer, and on return the underlying call will set the actual
#     number of elements filled in to the array as long as that is smaller than the passed-in value.
#     (If it is larger, the underlying call will return an error.)
#     Should only be used for output arrays.
# - two-dimension:
#     The array being operated on is two dimensional in nature and the size specified in the 'value'
#     member is an array that specifies the size of each array in the two dimensional array. The
#     user will still need to pass in the array of sizes and some validation is done to ensure the
#     sum of the size array matches the size of the two dimensional array.
# - custom-code:
#     The array's size is determined by the C++ code in the 'value' member.


def is_unsupported_size_mechanism_type(size_mechanism: str) -> bool:
    """Whether the given size mechanism is unknown/unsupported."""
    return size_mechanism not in {
        "fixed",
        "len",
        "len-in-bytes",
        "ivi-dance",
        "passed-in",
        "passed-in-by-ptr",
        "ivi-dance-with-a-twist",
        "two-dimension",
        "custom-code",
    }


def _is_unsupported_scalar_array(parameter):
    return is_array(parameter["type"]) and _is_unsupported_enum_array(parameter)


def _is_unsupported_enum_array(parameter):
    if is_enum(parameter):
        if is_input_parameter(parameter):
            return False

        return not _is_supported_enum_array_output_type(parameter)
    return False


def _is_supported_enum_array_output_type(parameter):
    return is_string_arg(parameter) or is_static_castable_enum_type(parameter)


def is_static_castable_enum_type(parameter):
    """Whether the underlying type of the parameter's enum is static_castable."""
    grpc_type = _get_underlying_grpc_type(parameter)
    # Note: sint32 could work here but causes issue with existing attribute output accessors
    # because it's not wire-compatible with enum. If it's added here, we need to make sure that
    # we're handling compatibility issues on those methods.
    return grpc_type in ["int32", "uint32"]


def _normalize_special_pascal_tokens(pascal_or_camel_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        pascal_or_camel_string = pascal_or_camel_string.replace(special_case_override, pascal_token)
    return pascal_or_camel_string


def _insert_special_case_pascal_tokens(normal_pascal_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        normal_pascal_string = normal_pascal_string.replace(pascal_token, special_case_override)
    return normal_pascal_string


def _insert_leading_special_case_pascal_tokens(camel_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        camel_string = _replace_prefix(camel_string, pascal_token.lower(), special_case_override)
    return camel_string


def _normalize_leading_special_case_pascal_tokens(pascal_string: str) -> str:
    for pascal_token, special_case_override in SPECIAL_CASE_PASCAL_TOKENS:
        pascal_string = _replace_prefix(pascal_string, special_case_override, pascal_token)
    return pascal_string


def _is_actually_pascal(camel_or_pascal_string: str) -> bool:
    return "A" <= camel_or_pascal_string[0] <= "Z"


def _camel_to_snake(camel_string: str) -> str:
    """Return a snake_string for a given camelString.

    External callers should use/create a wrapper instead (i.e. get_grpc_field_name).
    """
    if _is_actually_pascal(camel_string):
        camel_string = _pascal_to_camel(camel_string)

    camel_string = _normalize_special_pascal_tokens(camel_string)
    # Add _ before Words:
    # someDeviceIPAddress -> some_DeviceIP_Address
    s1 = re.sub(r"([^_])([A-Z][a-z]+[0-9]*)", r"\1_\2", camel_string)
    # Add _ before any capital letters not already preceded by _ and convert to lower:
    # some_DeviceIP_Address -> some_Device_IP_Address
    # some_Device_IP_Address -> some_device_ip_address
    return re.sub(r"([^_])([A-Z]+[0-9]*)", r"\1_\2", s1).lower()


def snake_to_pascal(snake_string):
    """Return a PascalString for a given snake_string."""
    snake_string = list(snake_string)
    index = 0
    snake_string[index] = snake_string[index].upper()
    for x in snake_string:
        if x == "_":
            snake_string[index + 1] = snake_string[index + 1].upper()
            del snake_string[index]
        index = index + 1
    result = "".join(snake_string)
    return _insert_special_case_pascal_tokens(result)


def _pascal_to_camel(pascal_string):
    """Return a camelString for a given PascalString."""
    pascal_string = _normalize_leading_special_case_pascal_tokens(pascal_string)
    if not _is_actually_pascal(pascal_string):
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
    """Ensure that a camel/pascal case string is pascal case.

    NOTE: does not distinguish leading all-caps acronyms.
    """
    pascal_or_camel_string = _insert_leading_special_case_pascal_tokens(pascal_or_camel_string)

    match = re.fullmatch(r"^([a-z])(.*)$", pascal_or_camel_string)
    if match:
        return match[1].upper() + match[2]

    return pascal_or_camel_string


def pascal_to_snake(pascal_string):
    """Return a snake_string for a given PascalString."""
    camel_string = _pascal_to_camel(pascal_string)
    snake_string = _camel_to_snake(camel_string)
    return "".join(snake_string)


def filter_proto_rpc_functions(functions):
    """Return function metadata only for functions to include for generating proto rpc methods."""
    functions_for_proto = {"public", "CustomCode", "CustomCodeCustomProtoMessage"}
    return [
        name
        for name, function in functions.items()
        if function.get("codegen_method", "public") in functions_for_proto
    ]


def filter_proto_rpc_functions_for_message(functions):
    """Return function metadata only for functions to include for generating proto rpc messages."""
    functions_for_proto = {"public", "CustomCode"}
    return [
        name
        for name, function in functions.items()
        if function.get("codegen_method", "public") in functions_for_proto
    ]


def get_attribute_enums_by_type(attributes):
    """Return a dict of attribute data types that use enum, along with set of enums used."""
    attribute_enums_by_type = defaultdict(set)
    # For Compatibility: Pre-adding the following types to the map causes them to use value_raw
    # params even if they have no enum values. This is part of the shipping API for MI drivers.
    for enum_type in ["ViInt32", "ViInt64", "ViReal64", "ViString"]:
        attribute_enums_by_type[enum_type] = set()

    for attribute_name in attributes:
        attribute = attributes[attribute_name]
        if "enum" in attribute:
            attribute_type = get_underlying_type(attribute)
            enum_name = attribute["enum"]
            attribute_enums_by_type[attribute_type].add(enum_name)
    return attribute_enums_by_type


def get_function_enums(functions, enums: List[dict]):
    """Get a list of the enums used by functions."""
    function_enums = set()
    for function in functions:
        for parameter in functions[function]["parameters"]:
            if "enum" in parameter:
                function_enums.add(parameter["enum"])
            if "mapped-enum" in parameter:
                function_enums.add(parameter["mapped-enum"])
            if "bitfield_as_enum_array" in parameter:
                function_enums.add(parameter["bitfield_as_enum_array"])
    function_enums.update(_get_force_include_enums(enums))
    return sorted(function_enums)


def _get_force_include_enums(enums: List[dict]):
    force_include_enums = set()
    for enum in enums:
        if enums[enum].get("force-include", False):
            force_include_enums.add(enum)
    return force_include_enums


def has_viboolean_array_param(functions):
    """Whether at least one function has parameter of type ViBoolean[]."""
    for function in functions:
        for parameter in functions[function]["parameters"]:
            if parameter["type"] == "ViBoolean[]":
                return True
    return False


def has_enum_array_string_out_param(functions):
    """Whether at least one function has an output parameter that is a string-based enum."""
    for function in functions:
        for parameter in functions[function]["parameters"]:
            if is_output_parameter(parameter) and is_string_arg(parameter) and is_enum(parameter):
                return True
    return False


def get_size_mechanism(parameter: dict) -> Optional[str]:
    """Get the size mechanism of the given parameter."""
    size = parameter.get("size", {})
    return size.get("mechanism", None)


def get_size_param(parameter: dict) -> Optional[str]:
    """Get the size of the given parameter."""
    size = parameter.get("size", {})
    return size.get("value", None)


def _get_ivi_dance_twist_param_name(parameter: dict) -> Optional[str]:
    return parameter.get("size", {}).get("value_twist")


def has_size_mechanism_tag(parameter: dict, tag: str) -> bool:
    """Whether the given parameter specifies a size mechanism."""
    size_request = parameter.get("size", {})
    tags = size_request.get("tags", {})
    return tag in tags


def _has_strlen_bug(parameter: dict) -> bool:
    """Return whether the parameter is a string output whose size mechanism has the 'strlen bug'.

    Reports strlen instead of strlen + 1 for the required buffersize.

    We assume that this bug may some day be fixed, so the implementation needs to allocate the extra
    character but also trim it off if it's an extra null.
    """
    return has_size_mechanism_tag(parameter, "strlen-bug")


def is_optional(parameter: dict) -> bool:
    """Whether the given parameter is marked as optional."""
    return has_size_mechanism_tag(parameter, "optional")


def get_buffer_size_expression(parameter: dict) -> str:
    """Return the C++ size expression for the underlying C API buffer for a string/array parameter.

    Unlike get_size_expression, this will include the trailing null terminator for strings (which is
    in the size reported by driver APIs).
    """
    size_mechanism = get_size_mechanism(parameter)
    if "size" not in parameter:
        raise Exception("No size for parameter " + parameter["name"])
    if size_mechanism == "fixed":
        return parameter["size"]["value"]
    elif size_mechanism == "ivi-dance-with-a-twist":
        return get_grpc_field_name_from_str(parameter["size"]["value_twist"])
    elif size_mechanism == "passed-in-by-ptr":
        return get_grpc_field_name_from_str(parameter["size"]["value"]) + "_copy"
    else:
        return get_grpc_field_name_from_str(parameter["size"]["value"])


def get_size_expression(parameter: dict) -> str:
    """Return the C++ size expression for sizing the C++ container type for a given parameter."""
    expression = get_buffer_size_expression(parameter)
    if _is_null_terminated_in_c(parameter):
        # if the C API reports strlen instead of size:
        # Don't subtract one for the null terminator, the API already did!
        if _has_strlen_bug(parameter):
            return f"{expression} /* Workaround: strlen-bug */"
        return f"{expression} - 1"
    return expression


def _is_ivi_dance_array_param(parameter):
    return get_size_mechanism(parameter) == "ivi-dance"


def has_ivi_dance_param(parameters):
    """Whether any parameter uses the ivi-dance size mechanism."""
    return any(_is_ivi_dance_array_param(p) for p in parameters)


def is_two_dimension_array_param(parameter):
    """Whether the given parameter is a two-dimensional array."""
    return get_size_mechanism(parameter) == "two-dimension"


def has_two_dimension_array_param(parameters):
    """Whether any parameter is a two-dimensional array."""
    return any(is_two_dimension_array_param(p) for p in parameters)


def has_repeated_varargs_parameter(parameters):
    """Whether any parameter is a repeated varargs parameter."""
    return any(is_repeated_varargs_parameter(p) for p in parameters)


def can_mock_function(parameters):
    """Whether a function with the given parameters can be mocked by googlemock.

    Google Mock can't handle the case where a function has a variable number of arguments and
    there's also a limit on the max number of arguments.
    """
    # I'm not sure this is exactly right, but it does enough to distinguish between
    # non-varargs functions and varargs functions that take > 100 parameters.
    max_mock_param_len = 20
    repeated_varargs_parameters = [p for p in parameters if is_repeated_varargs_parameter(p)]
    first_repeating_parameters = len([p for p in parameters if is_repeating_parameter(p)])
    if not any(repeated_varargs_parameters):
        return len(parameters) - first_repeating_parameters <= max_mock_param_len
    varargs_parameter = repeated_varargs_parameters[0]
    return (
        len(parameters)
        - first_repeating_parameters
        - len(repeated_varargs_parameters)
        + (first_repeating_parameters * varargs_parameter["max_length"])
        <= max_mock_param_len
    )


def get_ivi_dance_params(parameters):
    """Get the relevant parameters for the first ivi-dance parameter, if any."""
    array_param = next((p for p in parameters if _is_ivi_dance_array_param(p)), None)
    size_param = (
        next(p for p in parameters if p["name"] == array_param["size"]["value"])
        if array_param
        else None
    )
    other_params = (p for p in parameters if p != array_param and p != size_param)
    return (size_param, array_param, other_params)


def is_ivi_dance_array_with_a_twist_param(parameter):
    """Whether the given parameter is an ivi-dance-with-a-twist parameter."""
    return get_size_mechanism(parameter) == "ivi-dance-with-a-twist"


def has_ivi_dance_with_a_twist_param(parameters):
    """Whether any parameter is an ivi-dance-with-a-twist parameter."""
    return any(is_ivi_dance_array_with_a_twist_param(p) for p in parameters)


def get_param_with_name(parameters: List[dict], name: str) -> dict:
    """Get the parameter that has the given name."""
    matched_params = (p for p in parameters if p["name"] == name)
    return next(matched_params)


def get_first_session_param(parameters: List[dict]) -> dict:
    """Get the first parameter whose type is a Session."""
    matched_params = (p for p in parameters if p.get("grpc_type", None) == "nidevice_grpc.Session")
    return next(matched_params)


class IviDanceWithATwistParamSet(NamedTuple):  # noqa: D101
    array_params: List[dict]
    size_param: dict
    twist_param: dict

    @property
    def all_params(self):
        """All parameters in the set."""
        return self.array_params + [self.size_param, self.twist_param]

    @property
    def size_param_name(self) -> str:
        """Size parameter."""
        return get_cpp_local_name(self.size_param)

    @property
    def twist_param_name(self) -> str:
        """Twist parameter."""
        return get_cpp_local_name(self.twist_param)

    @property
    def is_in_out_twist(self) -> bool:
        """Return whether this is an "in-out" twist.

        An "in-out" twist is a rare variant of ivi-dance-with-a-twist where the size and the twist
        are the same param used as an in-out param, rather than separate input and output params.
        """
        return self.size_param_name == self.twist_param_name


def _make_ivi_twist_param_set(
    twist_param_name: str, parameters: List[dict]
) -> IviDanceWithATwistParamSet:
    matched_array_params = [
        p for p in parameters if _get_ivi_dance_twist_param_name(p) == twist_param_name
    ]
    return IviDanceWithATwistParamSet(
        matched_array_params,
        get_param_with_name(parameters, matched_array_params[0]["size"]["value"]),
        get_param_with_name(parameters, twist_param_name),
    )


def _unique_twist_params(parameters) -> List[str]:
    unique_set = {_get_ivi_dance_twist_param_name(p) for p in parameters}

    # Sort and remove None
    return sorted((p for p in unique_set if p))


def get_ivi_dance_with_a_twist_params(parameters: List[dict]) -> List[IviDanceWithATwistParamSet]:
    """Get the ivi-dance-with-a-twist parameters."""
    return [
        _make_ivi_twist_param_set(twist_name, parameters)
        for twist_name in _unique_twist_params(parameters)
    ]


def get_params_not_in_ivi_twist(
    parameters: List[dict], ivi_param_sets: List[IviDanceWithATwistParamSet]
) -> List[dict]:
    """Get the parameters that are not involved with an ivi-dance-with-a-twist mechanism."""
    all_params_in_ivi_set = {p["name"] for ivi_set in ivi_param_sets for p in ivi_set.all_params}

    return [p for p in parameters if p["name"] not in all_params_in_ivi_set]


def is_init_method(function_data):
    """Whether the function is an init_method."""
    return function_data.get("init_method", False)


def _get_session_output_param(function_data):
    return next(
        p
        for p in function_data["parameters"]
        if p["direction"] == "out" and "nidevice_grpc.Session" in p["grpc_type"]
    )


def is_init_array_method(function_data):
    """Whether the function is an init_method with a repeated Session output parameter."""
    return (
        is_init_method(function_data)
        and "repeated" in _get_session_output_param(function_data)["grpc_type"]
    )


def is_cross_driver_init_method(function_data: dict) -> bool:
    """Whether the function is an init_method for a cross_driver_session."""
    return is_init_method(function_data) and any(
        p
        for p in function_data["parameters"]
        if "cross_driver_session" in p and p["direction"] == "out"
    )


def has_streaming_response(function_data):
    """Whether the function has a stream_response."""
    return function_data.get("stream_response", False)


def _has_callback_param(function_data):
    return any((p for p in function_data["parameters"] if "callback_params" in p))


def has_async_streaming_response(function_data):
    """Whether the function has an async stream_response."""
    return has_streaming_response(function_data) and _has_callback_param(function_data)


def get_library_interface_type_name(config):
    """Get the LibraryInterface type name, based on the service_class_prefix config setting."""
    service_class_prefix = config["service_class_prefix"]
    return f"{service_class_prefix}LibraryInterface"


def indent(level):
    """For use as a mako filter.

    Returns a function that indents a block of text to the provided level.
    """

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
    Consider this as an alternative to str.join when it allows preserving context in the mako file.
    """

    def trim_trailing_comma_impl(text: str) -> str:
        i = text.rfind(",")
        return text[:i] + text[i + 1 :]

    return lambda text: trim_trailing_comma_impl(text)


def os_conditional_compile_block(config):
    """For use as a mako filter.

    That wraps a block of text in #if blocks based on the config's OS support.
    """
    windows_only = config.get("windows_only", False)

    def windows_only_block_impl(text):
        # Pure python code, by default, will convert to platform-specific linesep characters on
        # save. But mako uses the platform-specific linesep characters from the template file in the
        # template string. This is balanced by the newline="" args in template_helpers, which
        # preserve newlines from the input.
        #
        # We use os.linesep here for consistency with makos template strings and to ensure that we
        # don't get a mix of CRLF and LF on windows.
        return f"#if defined(_MSC_VER){os.linesep}{text}#endif // defined(_MSC_VER){os.linesep}"

    if windows_only:
        return lambda text: windows_only_block_impl(text)

    return lambda text: text


def filter_parameters_for_grpc_fields(parameters_or_fields: List[dict]):
    """Filter out the parameters that shouldn't be represented by a field on a grpc message.

    For example, get rid of any parameters whose values should be determined from another parameter.
    """
    return [p for p in parameters_or_fields if p.get("include_in_proto", True)]


class AttributeGroup:  # noqa: D101
    def __init__(self, name, attributes, config):  # noqa: D107
        self.name = name
        self.attributes = attributes
        self._config = config

    def get_attributes_split_by_sub_group(self):
        """Split attributes by type, with an added "Reset" sub-group for resettable attributes."""
        if not get_split_attributes_by_type(self._config):
            return {"": self.attributes}

        categorized_attributes = defaultdict(dict)
        for id, data in self.attributes.items():
            data_type = get_grpc_type_name_for_identifier(data["type"], self._config)
            categorized_attributes[data_type][id] = data
            if data.get("resettable", False):
                categorized_attributes["Reset"][id] = data
        return categorized_attributes


def get_attribute_enum_suffix(config: dict) -> str:
    """Get the name suffix of the enum whose values are the attributes."""
    use_legacy_prefix = _use_legacy_attribute_prefix(config)
    return "Attributes" if use_legacy_prefix else "Attribute"


def get_attribute_enum_name(group_name: str, data_type: str, config: dict) -> str:
    """Get the name of the enum whose values are the attributes."""
    attribute_suffix = get_attribute_enum_suffix(config)
    return f"{group_name}{data_type}{attribute_suffix}"


def get_attribute_groups(data):
    """Get the attribute groups."""
    attributes = data["attributes"]
    config = data["config"]

    # If the attributes are already in string categories: those are the groups. Return as-is.
    first_key = next(iter(attributes), None)
    if isinstance(first_key, str):
        return [AttributeGroup(name, attributes, config) for name, attributes in attributes.items()]

    # If there's just one level of attributes: use the service_class_prefix as the group.
    service_class_prefix = config["service_class_prefix"]
    return [AttributeGroup(service_class_prefix, attributes, config)]


def strip_prefix(s: str, prefix: str) -> str:
    """Strip the given prefix, if present, and return the resulting string."""
    return s[len(prefix) :] if s.startswith(prefix) else s


def strip_suffix(s: str, suffix: str) -> str:
    """Strip the given suffix, if present, and return the resulting string."""
    return s[: -len(suffix)] if s.endswith(suffix) else s


def _replace_prefix(s: str, prefix: str, sub: str) -> str:
    return sub + s[len(prefix) :] if s.startswith(prefix) else s


def get_grpc_type_name_for_identifier(data_type, config):
    """Create an identifier string based on the grpc_type.

    i.e., double -> Double. repeated double -> DoubleArray.
    """
    grpc_type = get_grpc_type(data_type, config)
    grpc_type = re.sub(r"^(repeated )(\w+)$", r"\2Array", grpc_type)
    # take the last identifier if the type is namespaced (i.e., Timestamp)
    grpc_type = grpc_type.split(".")[-1]
    return ensure_pascal_case(grpc_type)


def _get_grpc_type_from_ivi(
    type: str, is_array: bool, driver_name_pascal: str, config: dict
) -> str:
    add_repeated = is_array
    if "ViSession" in type:
        type = "nidevice_grpc.Session"
    if "ViBoolean" in type:
        type = "bool"
    if "ViReal64" in type:
        type = "double"
    if "ViInt32" in type:
        type = "sint32"
    if "ViConstString" in type:
        type = "string"
    if "ViString" in type:
        type = "string"
    if "ViRsrc" in type:
        type = "string"
    if "ViChar" in type:
        if is_array:
            add_repeated = False
            type = "string"
        else:
            type = "uint32"
    if "ViReal32" in type:
        type = "float"
    if "ViAttr" in type:
        type = get_attribute_enum_name(driver_name_pascal, "", config)
    if "ViInt8" in type:
        if is_array:
            type = "bytes"
            add_repeated = False
        else:
            type = "uint32"
    if "void*" in type:
        type = "fixed64"
    if "ViInt16" in type:
        type = "sint32"
    if "ViInt64" in type:
        type = "int64"
    if "ViUInt16" in type:
        type = "uint32"
    if "ViUInt32" in type:
        type = "uint32"
    if "ViUInt64" in type:
        type = "uint64"
    if "ViUInt8" in type:
        if is_array:
            type = "bytes"
            add_repeated = False
        else:
            type = "uint32"
    if "ViStatus" in type:
        type = "sint32"
    if "ViAddr" in type:
        type = "fixed64"
    if "int" == type:
        type = "sint32"
    if "[]" in type:
        type = type.replace("[]", "")

    return "repeated " + type if add_repeated else type


def get_grpc_type(data_type, config):
    """Get the grpc_type for the given type."""
    service_class_prefix = config["service_class_prefix"]
    if "type_to_grpc_type" in config:
        type_map = config["type_to_grpc_type"]
        stripped_type = strip_prefix(data_type, "const ")
        if stripped_type in type_map:
            return type_map[stripped_type]

        repeated = is_array(data_type)

        stripped_type = strip_suffix(stripped_type, "*")
        stripped_type = strip_suffix(stripped_type, "[]")

        # Note: if we never resolve or strip anything, this will fallback
        # to the original datatype.
        resolved_type = type_map.get(stripped_type, stripped_type)

        return f"repeated {resolved_type}" if repeated else resolved_type

    return _get_grpc_type_from_ivi(data_type, is_array(data_type), service_class_prefix, config)


def _use_legacy_attribute_prefix(config: dict) -> bool:
    return config.get("use_legacy_attribute_prefix", False)


def get_split_attributes_by_type(config):
    """Get the split_attributes_by_type config setting."""
    return config.get("split_attributes_by_type", False)


def supports_raw_attributes(config: dict) -> bool:
    """Get the supports_raw_attributes config setting."""
    return config.get("supports_raw_attributes", False)


def get_enum_value_cpp_type(enum: dict) -> str:
    """Use the python datatype of the first value in the enum to infer the C++ type.

    Used for mapped enums.
    """
    enum_value = enum["values"][0]["value"]
    if isinstance(enum_value, float):
        return "double"
    if isinstance(enum_value, int):
        return "std::int32_t"
    if isinstance(enum_value, str):
        return "std::string"
    return "std::int32_t"


def is_regular_string_arg(parameter: dict) -> bool:
    """Return whether the parameter is a "regular" string.

    This excludes byte arrays.
    """
    return is_string_arg(parameter) and not parameter["grpc_type"] == "bytes"


def is_regular_byte_array_arg(parameter: dict) -> bool:
    """Return whether the parameter is a "regular" byte array.

    This excludes byte arrays that are mapped to enums.
    """
    return parameter["grpc_type"] == "bytes" and not is_enum(parameter)


def get_additional_headers(config: dict, including_from_file: str) -> List[str]:
    """Get the list of additional headers required by the given file."""
    additional_header_requirements = config.get("additional_headers", {})
    return [
        header
        for header, required_by in additional_header_requirements.items()
        if including_from_file in required_by
    ]


def get_enum_value_prefix(enum_name: str, enum: dict) -> str:
    """Get the enum value prefix for the given enum."""
    return enum.get("enum-value-prefix", pascal_to_snake(enum_name).upper())


def get_driver_readiness(config: dict) -> str:
    """Get the code_readiness config setting."""
    return config.get("code_readiness", "Release")


def get_grpc_field_name(param: dict) -> str:
    """Get the name of the protobuf field for the given param.

    This will be a snake_case_string, that can be used in the proto
    definition itself, as well as in C++ code that accesses the field
    from a Request/Response message.
    """
    return param.get("grpc_name", _camel_to_snake(param["name"]))


def get_grpc_client_field_name(param: dict) -> str:
    """Get the name of the protobuf field for the given param.

    This will be a snake_case_string, that can be used in the client generated files.
    """
    return param.get("grpc_name", _camel_to_snake(param["cppName"]))


def get_grpc_field_name_from_str(field_name: str) -> str:
    """Get the default grpc_name for the given parameter name."""
    # NOTE: Does not account for "grpc_name" overrides, but can be used to get a proto name from a
    # camelCase field name when no overrides are present.
    return _camel_to_snake(field_name)


def get_cpp_local_name(param: dict) -> str:
    """Return a similar token to get_grpc_field_name, but ensure it is valid as a C++ variable name.

    NOTE: this is not used consistently to differentiate from get_grpc_field_name.  For that reason,
    the field respects the "grpc_name" override so that the two will match in the vast majority of
    cases where "name" is not a reserved keyword.  If "grpc_name" is a reserved keyword, this may be
    an issue (but don't use reserved grpc_name!).
    """
    return param.get("cpp_local_name", param.get("grpc_name", _camel_to_snake(param["cppName"])))


def get_grpc_field_names_for_param_names(params: List[dict], names: List[str]) -> List[str]:
    """Get the grpc field name for the corresponding param in params given a list of names."""
    return [get_grpc_field_name(get_param_with_name(params, name)) for name in names]


def is_return_value(parameter: dict) -> bool:
    """Whether the parameter is marked as a return_value."""
    return parameter.get("return_value", False)


def is_get_last_error_output_param(parameter: dict) -> bool:
    """Return True if pararameter is a get_last_error parameter."""
    return "get_last_error" in parameter


def get_driver_api_params(parameters: List[dict]) -> List[dict]:
    """Return all parameters that are passed as parameters to the driver API.

    Excludes:
    * Return values.
    * Outputs that are calculated/populated after the API call.
    * Proto only params.
    """
    return [
        p
        for p in parameters
        if not (
            is_return_value(p) or is_get_last_error_output_param(p) or is_proto_only_paramater(p)
        )
    ]
