"""Helpers for creating service .h/.cpp files."""

from typing import Any, Dict, List, NamedTuple, Optional

import common_helpers


def get_include_guard_name(config, suffix):
    """Get an appropriate #include guard name."""
    include_guard_name = config["namespace_component"] + "_grpc" + suffix
    return include_guard_name.upper()


def get_c_element_type_for_array_that_needs_coercion(parameter):
    """Get the C element type for the given parameter, if it's an array that needs coercion."""
    if not parameter.get("coerced", False):
        return None
    if not common_helpers.is_array(parameter["type"]):
        return None
    return get_c_element_type(parameter)


def get_c_element_type(parameter):
    """Get the C element type for the given parameter."""
    stripped_type = parameter["type"]
    stripped_type = common_helpers.strip_prefix(stripped_type, "const ")
    stripped_type = common_helpers.strip_suffix(stripped_type, "*")
    stripped_type = common_helpers.strip_suffix(stripped_type, "[]")
    return stripped_type


def is_scalar_input_that_needs_coercion(parameter: dict) -> bool:
    """Whether the parameter is a scalar input that needs coercion."""
    return (
        common_helpers.is_input_parameter(parameter)
        and parameter.get("coerced", False)
        and not common_helpers.is_array(parameter["type"])
    )


def is_input_array_that_needs_coercion(parameter):
    """Whether the parameter is an input array that needs coercion."""
    return (
        common_helpers.is_input_parameter(parameter)
        and get_c_element_type_for_array_that_needs_coercion(parameter) is not None
    )


def _is_input_that_needs_coercion(parameter, custom_types: list):
    if not common_helpers.is_input_parameter(parameter):
        return False
    if parameter.get("coerced", False):
        return True
    if not common_helpers.is_struct(parameter):
        return False
    underlying_struct_name = common_helpers.get_underlying_type_name(parameter["type"])
    underlying_structs = [
        custom_type for custom_type in custom_types if custom_type["name"] == underlying_struct_name
    ]
    if not any([underlying_structs]):
        return False
    custom_type = underlying_structs[0]
    return any([field.get("coerced", False) for field in custom_type["fields"]])


def is_output_array_that_needs_coercion(parameter):
    """Whether the parameter is an output array that needs coercion."""
    return (
        common_helpers.is_output_parameter(parameter)
        and get_c_element_type_for_array_that_needs_coercion(parameter) is not None
    )


def create_args_for_callback(parameters):
    """Get the args needed for a CallbackRouter handler."""
    return ", ".join([f'{p["type"]} {common_helpers.get_grpc_field_name(p)}' for p in parameters])


def _is_array_that_requires_conversion(parameter):
    """Return whether the protobuf representation is not the same as the C API representation."""
    is_array = common_helpers.is_array(parameter["type"])

    if is_array:
        return (
            common_helpers.supports_standard_copy_conversion_routines(parameter)
            or get_c_element_type_for_array_that_needs_coercion(parameter) is not None
            # Sessions are "converted" by accessing the session repository.
            or parameter["grpc_type"] == "repeated nidevice_grpc.Session"
            # ViInt16s have a hardcoded copy convert routine that predates the coerced flag.
            or parameter["type"] == "ViInt16[]"
        )

    return False


def _create_standard_arg(parameter):
    parameter_name = common_helpers.get_cpp_local_name(parameter)
    is_array = common_helpers.is_array(parameter["type"])
    is_output = common_helpers.is_output_parameter(parameter)
    is_hardcoded = "hardcoded_value" in parameter
    if is_output and common_helpers.is_string_arg(parameter):
        type_without_brackets = common_helpers.get_underlying_type_name(parameter["type"])
        return f"({type_without_brackets}*){parameter_name}.data(), "
    elif _is_array_that_requires_conversion(parameter):
        # Converted arrays are allocated into a std::vector. Access the C array via data().
        return f"{parameter_name}.data(), "
    elif "callback_params" in parameter and not is_hardcoded:
        return f"CallbackRouter::handle_callback, "
    elif "callback_token" in parameter and not is_hardcoded:
        return f"handler->token(), "
    elif is_size_param_passed_by_ptr(parameter):
        return f"&{parameter_name}_copy, "
    elif not is_array and is_output:
        return f"&{parameter_name}, "
    elif (
        not is_array
        and not is_output
        and "pointer" in parameter
        and "input_passed_by_ptr" in parameter
    ):
        return f"&{parameter_name}, "
    return f"{parameter_name}, "


def create_args(parameters):
    """Get the args needed to call the library function."""
    parameters = common_helpers.get_driver_api_params(parameters)
    result = ""
    have_expanded_varargs = False
    for parameter in parameters:
        if parameter.get("proto_only", False):
            continue
        if parameter.get("repeating_argument", False):
            continue
        parameter_name = common_helpers.get_cpp_local_name(parameter)
        if common_helpers.is_repeated_varargs_parameter(parameter):
            # Some methods have both input and output repeated varargs parameters,
            # so only expand them once.
            if have_expanded_varargs:
                continue
            have_expanded_varargs = True
            repeated_parameters = [
                p for p in parameters if common_helpers.is_repeating_parameter(p)
            ]
            # We need to pass one extra set of arguments because the last parameters have to be
            # nullptr's so the callee knows we're done passing arguments.
            max_length = parameter["max_length"] + 1
            for i in range(max_length):
                for parameter in repeated_parameters:
                    if common_helpers.is_input_parameter(parameter):
                        result += f'get_{parameter["name"]}_if({parameter_name}, {i}), '
                    else:
                        result += f'get_{parameter["name"]}_if({parameter["name"]}Vector, {i}), '
        else:
            result = f"{result}{_create_standard_arg(parameter)}"
    return result[:-2]


def create_args_for_ivi_dance(parameters):
    """Get the args needed to call the ivi-dance library function."""
    result = ""
    for parameter in parameters:
        if parameter.get("is_size_param", False):
            result = f"{result}0, "
        elif common_helpers.is_output_parameter(parameter):
            result = f"{result}nullptr, "
        else:
            result = result + _create_standard_arg(parameter)
    return result[:-2]


def create_args_for_ivi_dance_with_a_twist(parameters):
    """Get the args needed to call the ivi-dance-with-a-twist library function."""
    result = ""
    ivi_twist_array_params = [
        p for p in parameters if common_helpers.get_size_mechanism(p) == "ivi-dance-with-a-twist"
    ]
    arrays = {p["name"] for p in ivi_twist_array_params}
    twists = {p["size"]["value_twist"] for p in ivi_twist_array_params}
    sizes = {p["size"]["value"] for p in ivi_twist_array_params}

    for parameter in parameters:
        c_name = common_helpers.get_cpp_local_name(parameter)
        name = parameter["name"]
        if name in arrays:
            result = f"{result}nullptr, "
        elif name in twists:
            # Pass the twist output param by pointer.
            result = result + f"&{c_name}" + ", "
        elif name in sizes:
            result = f"{result}0, "
        else:
            result = result + _create_standard_arg(parameter)
    return result[:-2]


def create_params(parameters, expand_varargs=True):
    """Get the params needed for defining the library function."""
    parameters = common_helpers.get_driver_api_params(parameters)
    if not len(parameters):
        return ""
    repeated_parameters = [p for p in parameters if common_helpers.is_repeating_parameter(p)]
    # Some methods have both input and output repeated varargs parameters,
    # so only expand them once.
    if common_helpers.is_repeated_varargs_parameter(
        parameters[-1]
    ) and common_helpers.is_repeated_varargs_parameter(parameters[-2]):
        parameters = parameters[:-1]
    return ", ".join(
        _create_param(p, expand_varargs, repeated_parameters)
        for p in parameters
        if not p.get("proto_only", False)
    )


def _get_array_param_size(parameter) -> str:
    if "size" in parameter and parameter["size"]["mechanism"] == "fixed":
        return parameter["size"]["value"]

    return ""


def expand_varargs_parameters(parameters):
    """Get a modified list of parameters, with repeating_parameters repeated max_length times.

    The max_length value comes from the first repeated_var_args parameter. Each repeated parameter
    gets a number (starting at zero) appended to the parameter name.
    """
    parameters = common_helpers.get_driver_api_params(parameters)
    if not common_helpers.has_repeated_varargs_parameter(parameters):
        return parameters
    # omit the varargs parameters that we're going to expand
    new_parameters = [p for p in parameters if not common_helpers.is_repeated_varargs_parameter(p)]
    varargs_parameters = [p for p in parameters if common_helpers.is_repeated_varargs_parameter(p)]
    max_length = varargs_parameters[0]["max_length"]
    repeated_parameters = [p for p in parameters if common_helpers.is_repeating_parameter(p)]
    for i in range(max_length):
        for p in repeated_parameters:
            new_parameters.append({"cppName": f'{p["name"]}{i}'})
    return new_parameters


def _create_param(parameter, expand_varargs=True, repeated_parameters=None):
    type = parameter["type"]
    name = parameter["cppName"]
    if common_helpers.is_struct(parameter):
        type = type.replace("struct ", "")
    if common_helpers.is_repeated_varargs_parameter(parameter):
        if expand_varargs:
            max_length = parameter["max_length"]
            s = ""
            for i in range(max_length):
                for parameter in repeated_parameters:
                    real_field_name = parameter["cppName"]
                    parameter["cppName"] = f"{real_field_name}{i}"
                    s += _create_param(parameter, expand_varargs=False) + ", "
                    parameter["cppName"] = real_field_name
            return s[:-2]
        else:
            return "..."
    elif common_helpers.is_array(type):
        if type == "void *":
            return f"void* {name}"
        array_size = _get_array_param_size(parameter)
        if type[:-2] == "void":  # Having void[] in C++ is not allowed, hence using it as void*
            return f"{type[:-2]}* {name}"
        else:
            return f"{type[:-2]} {name}[{array_size}]"
    else:
        pointer_qualifier = "*" * common_helpers.levels_of_pointer_indirection(parameter)
        return f"{type}{pointer_qualifier} {name}"


def _format_value(value):
    if isinstance(value, str):
        value = f'"{value}"'
    if isinstance(value, float):
        value = f"{value}f"
    return value


def get_input_lookup_values(enum_data):
    """Get an initializer list for a std::map that maps enum value index to enum value value."""
    out_value_format = ""
    is_int = isinstance(enum_data["values"][0]["value"], int)
    if is_int:
        out_value_format = "{0, 0},"
    for i, value in enumerate(enum_data["values"]):
        formated_value = str(_format_value(value["value"]))
        out_value_format += f"{{{i + 1}, {formated_value}}},"
    return out_value_format


def get_output_lookup_values(enum_data):
    """Get an initializer list for a std::map that maps enum value value to enum value index."""
    out_value_format = ""
    is_int = isinstance(enum_data["values"][0]["value"], int)
    if is_int:
        out_value_format = "{0, 0},"
    for i, value in enumerate(enum_data["values"]):
        formated_value = _format_value(value["value"])
        out_value_format += f"{{{formated_value}, {i + 1}}},"
    return out_value_format


def generate_enum_oneof_selector_map(enum_data):
    """ "Get an initializer list for a std::map that maps enum value value to enum value type."""
    id_type_content = ""
    for i, value in enumerate(enum_data["values"]):
        formated_value = _format_value(value["value"])
        type = value["type"]
        id_type_content += f"{{{formated_value}, {type}_}},"
    return id_type_content


def filter_api_functions(functions, only_mockable_functions=True):
    """Filter function metadata to only include those to be generated into the API library."""

    def filter_function(function):
        if function.get("codegen_method", "") == "no":
            return False
        if only_mockable_functions and not common_helpers.can_mock_function(function["parameters"]):
            return False
        return True

    return [name for name, function in functions.items() if filter_function(function)]


def filter_proto_rpc_functions_to_generate(functions):
    """Return function metadata only for functions to include for generating proto rpc methods."""
    functions_for_code_gen = {"public"}
    return [
        name
        for name, function in functions.items()
        if function.get("codegen_method", "public") in functions_for_code_gen
    ]


def get_cname(functions, method_name, c_function_prefix):
    """Get the C name of the function."""
    if "cname" in functions[method_name]:
        return functions[method_name]["cname"]
    return c_function_prefix + method_name


def is_private_method(function_data):
    """Whether the function is private."""
    return function_data.get("codegen_method", "") == "private"


def is_custom_close_method(function_data):
    """Whether the function is a custom_close_method."""
    return function_data.get("custom_close_method", False)


def requires_checked_conversion(parameters, custom_types):
    """Whether any parameter needs coercion."""
    return any([_is_input_that_needs_coercion(p, custom_types) for p in parameters])


def get_request_param(method_name):
    """Get a parameter for taking in a Request object for the function with the given name."""
    return f"const {get_request_type(method_name)}* request"


def get_request_type(method_name):
    """Get the name of the Request class for the function with the given name."""
    return f"{method_name}Request"


def get_response_param(method_name):
    """Get a parameter for taking in a Response object for the function with the given name."""
    return f"{get_response_type(method_name)}* response"


def get_response_type(method_name):
    """Get the name of the Response class for the function with the given name."""
    return f"{method_name}Response"


def get_async_functions(functions):
    """Filter the functions to include only async functions (those with a streaming response)."""
    return {
        name: data
        for name, data in functions.items()
        if common_helpers.has_streaming_response(data)
    }


def get_functions_with_two_dimension_param(functions):
    """Filter the functions to include only those with a two-dimension array parameter."""
    return {
        name: data
        for name, data in functions.items()
        if common_helpers.has_two_dimension_array_param(data["parameters"])
    }


def get_callback_method_parameters(function_data):
    """Get the parameters of the given function's callback function parameter."""
    parameters = function_data["parameters"]
    callback_ptr_parameter = next((p for p in parameters if "callback_params" in p))
    output_parameters = callback_ptr_parameter["callback_params"]

    return output_parameters


def create_param_type_list(parameters):
    """Get a comma-separated list of parameter types."""
    return ", ".join([p["type"] for p in parameters])


def get_feature_toggles(config: dict) -> Dict[str, str]:
    """Get the feature_toggles config setting."""
    return config.get("feature_toggles", {})


def get_toggle_member_name(fully_qualified_toggle_name: str) -> str:
    """Get the member name to use for the given toggle, in the FeatureToggles class."""
    toggle_name = fully_qualified_toggle_name.split(".")[-1]
    return f"is_{toggle_name}_enabled"


def get_driver_service_readiness(config: dict) -> str:
    """Get the C++ constant representing the driver's code_readiness."""
    readiness = common_helpers.get_driver_readiness(config)
    return to_cpp_readiness(readiness)


def is_restricted_driver_service(config):
    """Whether the driver service is restricted."""
    return common_helpers.is_driver_restricted(config)


def to_cpp_readiness(user_readiness: str) -> str:
    """Get the C++ constant representing the given code_readiness."""
    return f"CodeReadiness::k{user_readiness}"


def get_enums_to_map(functions: dict, enums: dict) -> List[str]:
    """Get a list of the enums used by functions, for which mappings should be generated."""

    def get_enum_or_default(enum_name: str) -> dict:
        # Enums that are added during metadata mutation (like attributes)
        # may not be in the enum dictionary. Assume they don't generate-mappings.
        return enums.get(enum_name, {})

    def should_generate_mappings(enum_name: str) -> bool:
        enum = get_enum_or_default(enum_name)
        return enum.get("generate-mappings", False)

    function_enums = common_helpers.get_function_enums(functions, enums)
    return [e for e in function_enums if should_generate_mappings(e)]


def generate_mapping_enums_to_type(enums: dict) -> List[str]:
    """Get a list of the enums used by functions, for which mappings should be generated."""
    list_of_enums: List[str] = []
    for enum_name in enums.keys():
        if "generate-mapping-type" in enums[enum_name]:
            list_of_enums.append(enum_name)
    return list_of_enums


def get_distinct_types_from_enums(enums: dict) -> str:
    """Return a comma seperated string of different data types used in enums value type field."""
    distinct_type = set()
    for enum_name in enums.keys():
        if "generate-mapping-type" in enums[enum_name]:
            for i, value in enumerate(enums[enum_name]["values"]):
                type = value["type"]
                distinct_type.add(f"{type}_")
    return str.join(", ", sorted(distinct_type))


def get_bitfield_value_to_name_mapping(parameter: dict, enums: dict) -> Dict[int, str]:
    """Get a mapping from bitfield values to the corresponding C++ enum value constants."""
    enum_name = parameter["bitfield_as_enum_array"]
    enum = enums[enum_name]
    enum_value_prefix = common_helpers.get_enum_value_prefix(enum_name, enum)
    enum_qualified_name_prefix = f"{enum_name}::{enum_value_prefix}"

    return {
        v["value"]: f"{enum_qualified_name_prefix}_{v['name']}"
        for v in enum["values"]
        if v["value"] != 0  # zero values can't be flags!
    }


def get_resource_handle_types(config: dict) -> List[str]:
    """Get the resource_handle_type config setting."""
    resource_handle_type = config.get("resource_handle_type", ["ViSession"])
    if isinstance(resource_handle_type, str):
        return [resource_handle_type]
    else:
        return resource_handle_type


def _get_shared_resource_repository_ptr_type(resource_handle_type: str) -> str:
    resource_repository_type = f"nidevice_grpc::SessionResourceRepository<{resource_handle_type}>"
    return f"std::shared_ptr<{resource_repository_type}>"


class CrossDriverSessionDependency(NamedTuple):  # noqa: D101
    resource_handle_type: str
    resource_repository_alias: str
    resource_repository_type: str
    field_name: str
    local_name: str


SessionRepositoryHandleTypeDependencyMap = Dict[str, CrossDriverSessionDependency]


def get_driver_shared_resource_repository_ptr_deps(
    driver_config: dict, functions: dict
) -> SessionRepositoryHandleTypeDependencyMap:
    """Get handle-type to CrossDriverSessionDependency map used by this driver.

    Combine resource_handle_type and cross_driver_session types in single map since both
    of them together decide repositories required by driver. Combining into single map also
    helps remove duplicates.
    """
    resource_repository_deps = [
        _create_cross_driver_session_dependency(resource_handle_type)
        for resource_handle_type in get_resource_handle_types(driver_config)
    ]

    resource_repository_deps[0] = CrossDriverSessionDependency(
        resource_repository_deps[0].resource_handle_type,
        "ResourceRepositorySharedPtr",
        resource_repository_deps[0].resource_repository_type,
        "session_repository_",
        "resource_repository",
    )

    resource_repository_type_dependency_map = {
        d.resource_handle_type: d for d in resource_repository_deps
    }

    for d in get_cross_driver_session_dependencies(functions):
        resource_repository_type_dependency_map.update({d.resource_handle_type: d})

    return resource_repository_type_dependency_map


def _create_cross_driver_session_dependency(
    resource_handle_type: str,
) -> CrossDriverSessionDependency:
    return CrossDriverSessionDependency(
        resource_handle_type,
        f"{resource_handle_type}ResourceRepositorySharedPtr",
        _get_shared_resource_repository_ptr_type(resource_handle_type),
        f"{common_helpers.pascal_to_snake(resource_handle_type)}_resource_repository_",
        f"{common_helpers.pascal_to_snake(resource_handle_type)}_resource_repository",
    )


def _get_cross_driver_session_type(parameter: dict) -> Optional[str]:
    return parameter.get("cross_driver_session")


def get_cross_driver_session_dependencies(functions: dict) -> List[CrossDriverSessionDependency]:
    """Get a list of cross-driver session dependencies needed by any function parameter."""
    cross_driver_session_types = (
        _get_cross_driver_session_type(p) for f in functions.values() for p in f["parameters"]
    )
    return sorted(
        set(_create_cross_driver_session_dependency(t) for t in cross_driver_session_types if t)
    )


def get_cross_driver_session_dependency(parameter: dict) -> CrossDriverSessionDependency:
    """Get the cross-driver session dependency needed by the given parameter."""
    return _create_cross_driver_session_dependency(parameter["cross_driver_session"])


def session_repository_field_name(param: dict, config: dict) -> str:
    """Get the name of the session repository field used for the given parameter."""
    cross_driver_session_type = _get_cross_driver_session_type(param)

    if cross_driver_session_type:
        return get_cross_driver_session_dependency(param).field_name
    else:
        resource_handle_deps = get_driver_shared_resource_repository_ptr_deps(
            config,
            functions={},  # This is called for retrieving session repo field name for specific parameter, functions is not needed
        )
        resource_handle_dep = next(
            resource_handle_deps[resource_handle_type]
            for resource_handle_type in resource_handle_deps
            if resource_handle_type == common_helpers.get_underlying_type(param)
        )
        return resource_handle_dep.field_name


SessionRepositoryHandleTypeMap = Dict[str, Dict[str, Any]]


def list_session_repository_handle_types(
    driver_configs: List[dict],
) -> SessionRepositoryHandleTypeMap:
    """Get per-handle type config info, for the resource handle types used by the given configs.

    The included config info keys are: local_name and windows_only.
    """
    session_repository_handle_type_map = {}  # type: SessionRepositoryHandleTypeMap
    for config in driver_configs:
        handle_types = get_resource_handle_types(config)
        for handle_type in handle_types:
            if handle_type in session_repository_handle_type_map:
                old_windows_only = session_repository_handle_type_map[handle_type]["windows_only"]
                new_windows_only = config.get("windows_only", False) and old_windows_only
                session_repository_handle_type_map[handle_type]["windows_only"] = new_windows_only
            else:
                session_repository_handle_type_map[handle_type] = {
                    "local_name": f"{common_helpers.pascal_to_snake(handle_type)}_repository",
                    "windows_only": config.get("windows_only", False),
                }
    return session_repository_handle_type_map


def get_function_return_type(function_data: dict) -> str:
    """Get the return type for function_data."""
    return function_data["returns"]


def _get_return_value_parameter(parameters: List[dict]) -> Optional[dict]:
    return next((p for p in parameters if common_helpers.is_return_value(p)), None)


def get_return_value_name(function_data: dict) -> str:
    """Get the name of the return value for function_data. The default is "status"."""
    return_param = _get_return_value_parameter(function_data["parameters"])
    return common_helpers.get_cpp_local_name(return_param) if return_param else "status"


def has_status_expression(function_data: dict) -> bool:
    """Whether function_data has a custom status_expression."""
    return "status_expression" in function_data


def get_status_expression(function_data: dict) -> str:
    """Get the custom status_expression for function_data.

    The default is to use the value of status returned from the driver function.

    Raises if "status_expression" is not present.
    """
    return function_data["status_expression"]


def get_library_ptr_for_potentially_unmockable_function(config: dict, parameters: List[dict]):
    """Get the variable or expression for the library pointer.

    Returns library_ if parameters can be mocked and called through the shared interface,
    otherwise typecasts library to the concrete type.
    """
    return (
        "library_"
        if common_helpers.can_mock_function(parameters)
        else f"std::static_pointer_cast<{config['service_class_prefix']}Library>(library_)"
    )


def is_session_returned_from_function(parameters: List[dict]) -> bool:
    """Whether parameters includes a return_value parameter with grpc_type nidevice_grpc.Session."""
    return_param = _get_return_value_parameter(parameters)
    return return_param["grpc_type"] == "nidevice_grpc.Session" if return_param else False


def should_copy_to_response(parameter: dict) -> bool:
    """Whether the value of parameter should be copied to the Response message."""
    is_included_in_response_proto = parameter.get("include_in_proto", True)
    # Repeating parameters do a special mapping in the copy logic.
    # They should execute that map/copy logic even if include_in_proto is False.
    is_mapped_as_repeating_parameter = common_helpers.is_repeating_parameter(parameter)
    return is_included_in_response_proto or is_mapped_as_repeating_parameter


def is_size_param_passed_by_ptr(parameter: dict) -> bool:
    """Return whether parameters is a size param passed-by-pointer."""
    return parameter.get("is_size_param", False) and parameter.get("pointer", False)


def get_last_error_output_params(parameters: List[dict]) -> List[dict]:
    """Return list of get_last_error parameters."""
    get_last_error_outputs = [
        p for p in parameters if common_helpers.is_get_last_error_output_param(p)
    ]
    return get_last_error_outputs


def get_protobuf_cpplib_type(grpc_type: str) -> str:
    """Return the C++ type used grpc generated code for the given protobuf type.

    Note: this implementation is incomplete. It only handles the default case
    where the grpc_type name is the same as the cpplib typename and repeated
    message types. Add other mappings as needed.
    """
    stripped_repeated = common_helpers.strip_prefix(grpc_type, "repeated ")
    if stripped_repeated != grpc_type:
        return f"google::protobuf::RepeatedPtrField<{get_protobuf_cpplib_type(stripped_repeated)}>"

    if grpc_type == "string":
        return "std::string"

    return grpc_type
