from typing import Any, Dict, List, NamedTuple, Optional
import common_helpers


def get_include_guard_name(config, suffix):
    include_guard_name = config["namespace_component"] + "_grpc" + suffix
    return include_guard_name.upper()


def get_c_element_type_for_array_that_needs_coercion(parameter):
    if not parameter.get("coerced", False):
        return None
    if not common_helpers.is_array(parameter["type"]):
        return None
    return get_c_element_type(parameter)


def get_c_element_type(parameter):
    stripped_type = parameter["type"]
    stripped_type = common_helpers.strip_prefix(stripped_type, "const ")
    stripped_type = common_helpers.strip_suffix(stripped_type, "*")
    stripped_type = common_helpers.strip_suffix(stripped_type, "[]")
    return stripped_type


def is_scalar_input_that_needs_coercion(parameter: dict) -> bool:
    return (
        common_helpers.is_input_parameter(parameter)
        and parameter.get("coerced", False)
        and not common_helpers.is_array(parameter["type"])
    )


def is_input_array_that_needs_coercion(parameter):
    return (
        common_helpers.is_input_parameter(parameter)
        and get_c_element_type_for_array_that_needs_coercion(parameter) is not None
    )


def is_input_that_needs_coercion(parameter, custom_types: list):
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
    return (
        common_helpers.is_output_parameter(parameter)
        and get_c_element_type_for_array_that_needs_coercion(parameter) is not None
    )


def create_args_for_callback(parameters):
    return ", ".join([f'{p["type"]} {common_helpers.get_grpc_field_name(p)}' for p in parameters])


def _is_array_that_requires_conversion(parameter):
    """
    Returns True for any array parameter where the protobuf representation is not the same
    as the C API representation.
    """
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


def create_standard_arg(parameter):
    parameter_name = common_helpers.get_cpp_local_name(parameter)
    is_array = common_helpers.is_array(parameter["type"])
    is_output = common_helpers.is_output_parameter(parameter)
    if is_output and common_helpers.is_string_arg(parameter):
        type_without_brackets = common_helpers.get_underlying_type_name(parameter["type"])
        return f"({type_without_brackets}*){parameter_name}.data(), "
    elif _is_array_that_requires_conversion(parameter):
        # Converted arrays are allocated into a std::vector. Access the C array via data().
        return f"{parameter_name}.data(), "
    elif "callback_params" in parameter:
        return f"CallbackRouter::handle_callback, "
    elif "callback_token" in parameter:
        return f"handler->token(), "
    elif (
        not is_output
        and common_helpers.is_pointer_parameter(parameter)
        and "hardcoded_value" not in parameter
    ):
        return f"&{parameter_name}_copy, "
    elif not is_array and is_output:
        return f"&{parameter_name}, "
    return f"{parameter_name}, "


def create_args(parameters):
    result = ""
    have_expanded_varargs = False
    for parameter in parameters:
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
            # We need to pass one extra set of arguments because the last parameters have to be nullptr's
            # so the callee knows we're done passing arguments.
            max_length = parameter["max_length"] + 1
            for i in range(max_length):
                for parameter in repeated_parameters:
                    if common_helpers.is_input_parameter(parameter):
                        result += f'get_{parameter["name"]}_if({parameter_name}, {i}), '
                    else:
                        result += f'get_{parameter["name"]}_if({parameter["name"]}Vector, {i}), '
        else:
            result = f"{result}{create_standard_arg(parameter)}"
    return result[:-2]


def create_args_for_ivi_dance(parameters):
    result = ""
    for parameter in parameters:
        if parameter.get("is_size_param", False):
            result = f"{result}0, "
        elif common_helpers.is_output_parameter(parameter):
            result = f"{result}nullptr, "
        else:
            result = result + create_standard_arg(parameter)
    return result[:-2]


def create_args_for_ivi_dance_with_a_twist(parameters):
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
            result = result + create_standard_arg(parameter)
    return result[:-2]


def create_params(parameters, expand_varargs=True):
    repeated_parameters = [p for p in parameters if common_helpers.is_repeating_parameter(p)]
    # Some methods have both input and output repeated varargs parameters,
    # so only expand them once.
    if common_helpers.is_repeated_varargs_parameter(
        parameters[-1]
    ) and common_helpers.is_repeated_varargs_parameter(parameters[-2]):
        parameters = parameters[:-1]
    return ", ".join(create_param(p, expand_varargs, repeated_parameters) for p in parameters)


def get_array_param_size(parameter) -> str:
    if "size" in parameter and parameter["size"]["mechanism"] == "fixed":
        return parameter["size"]["value"]

    return ""


def expand_varargs_parameters(parameters):
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


def create_param(parameter, expand_varargs=True, repeated_parameters=None):
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
                    s += create_param(parameter, expand_varargs=False) + ", "
                    parameter["cppName"] = real_field_name
            return s[:-2]
        else:
            return "..."
    elif common_helpers.is_array(type):
        array_size = get_array_param_size(parameter)
        return f"{type[:-2]} {name}[{array_size}]"
    elif common_helpers.is_pointer_parameter(parameter):
        return f"{type}* {name}"
    else:
        return f"{type} {name}"


def format_value(value):
    if isinstance(value, str):
        value = f'"{value}"'
    if isinstance(value, float):
        value = f"{value}f"
    return value


def get_input_lookup_values(enum_data):
    out_value_format = ""
    index = 1
    is_int = isinstance(enum_data["values"][0]["value"], int)
    if is_int:
        out_value_format = "{0, 0},"
    for value in enum_data["values"]:
        formated_value = str(format_value(value["value"]))
        out_value_format = out_value_format + "{" + str(index) + ", " + formated_value + "},"
        index = index + 1
    return out_value_format


def get_output_lookup_values(enum_data):
    out_value_format = ""
    index = 1
    is_int = isinstance(enum_data["values"][0]["value"], int)
    if is_int:
        out_value_format = "{0, 0},"
    for value in enum_data["values"]:
        formated_value = format_value(value["value"])
        out_value_format = out_value_format + "{" + str(formated_value) + ", " + str(index) + "},"
        index = index + 1
    return out_value_format


def filter_api_functions(functions, only_mockable_functions=True):
    """Returns function metadata only for those functions to include for generating the function types to the API library"""

    def filter_function(function):
        if function.get("codegen_method", "") == "no":
            return False
        if only_mockable_functions and not common_helpers.can_mock_function(function["parameters"]):
            return False
        return True

    return [name for name, function in functions.items() if filter_function(function)]


def filter_proto_rpc_functions_to_generate(functions):
    """Returns function metadata only for those functions to include for generating proto rpc methods"""
    functions_for_code_gen = {"public"}
    return [
        name
        for name, function in functions.items()
        if function.get("codegen_method", "public") in functions_for_code_gen
    ]


def get_cname(functions, method_name, c_function_prefix):
    if "cname" in functions[method_name]:
        return functions[method_name]["cname"]
    return c_function_prefix + method_name


def is_private_method(function_data):
    return function_data.get("codegen_method", "") == "private"


def is_custom_close_method(function_data):
    return function_data.get("custom_close_method", False)


def requires_checked_conversion(parameters, custom_types):
    return any([is_input_that_needs_coercion(p, custom_types) for p in parameters])


def get_request_param(method_name):
    return f"const {get_request_type(method_name)}* request"


def get_request_type(method_name):
    return f"{method_name}Request"


def get_response_param(method_name):
    return f"{get_response_type(method_name)}* response"


def get_response_type(method_name):
    return f"{method_name}Response"


def get_async_functions(functions):
    return {
        name: data
        for name, data in functions.items()
        if common_helpers.has_streaming_response(data)
    }


def get_functions_with_two_dimension_param(functions):
    return {
        name: data
        for name, data in functions.items()
        if common_helpers.has_two_dimension_array_param(data["parameters"])
    }


def get_callback_method_parameters(function_data):
    parameters = function_data["parameters"]
    input_parameters = [p for p in parameters if common_helpers.is_input_parameter(p)]
    callback_ptr_parameter = next((p for p in parameters if "callback_params" in p))
    output_parameters = callback_ptr_parameter["callback_params"]

    return input_parameters, output_parameters


def create_param_type_list(parameters):
    return ", ".join([p["type"] for p in parameters])


def get_feature_toggles(config: dict) -> Dict[str, str]:
    return config.get("feature_toggles", {})


def get_toggle_member_name(fully_qualified_toggle_name: str) -> str:
    toggle_name = fully_qualified_toggle_name.split(".")[-1]
    return f"is_{toggle_name}_enabled"


def get_driver_service_readiness(config: dict) -> str:
    readiness = common_helpers.get_driver_readiness(config)
    return to_cpp_readiness(readiness)


def to_cpp_readiness(user_readiness: str) -> str:
    return f"CodeReadiness::k{user_readiness}"


def get_enums_to_map(functions: dict, enums: dict) -> List[str]:
    def get_enum_or_default(enum_name: str) -> dict:
        # Enums that are added during metadata mutation (like attributes)
        # may not be in the enum dictionary. Assume they don't generate-mappings.
        return enums.get(enum_name, {})

    def should_generate_mappings(enum_name: str) -> bool:
        enum = get_enum_or_default(enum_name)
        return enum.get("generate-mappings", False)

    function_enums = common_helpers.get_function_enums(functions)
    return [e for e in function_enums if should_generate_mappings(e)]


def get_bitfield_value_to_name_mapping(parameter: dict, enums: dict) -> Dict[int, str]:
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
    resource_handle_type = config.get("resource_handle_type", ["ViSession"])
    if isinstance(resource_handle_type, str):
        return [resource_handle_type]
    else:
        return resource_handle_type


def get_shared_resource_repository_ptr_type(resource_handle_type: str) -> str:
    resource_repository_type = f"nidevice_grpc::SessionResourceRepository<{resource_handle_type}>"
    return f"std::shared_ptr<{resource_repository_type}>"


class CrossDriverSessionDependency(NamedTuple):
    resource_handle_type: str
    resource_repository_alias: str
    resource_repository_type: str
    field_name: str
    local_name: str


def get_driver_shared_resource_repository_ptr_deps(
    driver_config: dict,
) -> List[CrossDriverSessionDependency]:
    resource_repository_deps = [
        _create_cross_driver_session_dependency(resource_handle_type)
        for resource_handle_type in get_resource_handle_types(driver_config)
    ]

    # TODO fix
    resource_repository_deps[0] = CrossDriverSessionDependency(
        resource_repository_deps[0].resource_handle_type,
        "ResourceRepositorySharedPtr",
        resource_repository_deps[0].resource_repository_type,
        "session_repository_",
        "resource_repository",
    )
    # resource_repository_deps[0].local_name = "resource_repository"
    # resource_repository_deps[0].field_name = "resource_repository_"
    # resource_repository_deps[0].resource_repository_alias = "ResourceRepositorySharedPtr"

    return resource_repository_deps


def _create_cross_driver_session_dependency(
    resource_handle_type: str,
) -> CrossDriverSessionDependency:
    return CrossDriverSessionDependency(
        resource_handle_type,
        f"{resource_handle_type}ResourceRepositorySharedPtr",
        get_shared_resource_repository_ptr_type(resource_handle_type),
        f"{common_helpers.pascal_to_snake(resource_handle_type)}_resource_repository_",
        f"{common_helpers.pascal_to_snake(resource_handle_type)}_resource_repository",
    )


def get_cross_driver_session_type(parameter: dict) -> Optional[str]:
    return parameter.get("cross_driver_session")


def get_cross_driver_session_dependencies(
    functions: List[dict],
) -> List[CrossDriverSessionDependency]:
    return sorted(
        set(
            [
                _create_cross_driver_session_dependency(get_cross_driver_session_type(p))
                for f in functions.values()
                for p in f["parameters"]
                if get_cross_driver_session_type(p)
            ]
        )
    )


def get_cross_driver_session_dependency(parameter: dict) -> CrossDriverSessionDependency:
    return _create_cross_driver_session_dependency(parameter["cross_driver_session"])


def session_repository_field_name(param: dict, config: dict) -> str:
    cross_driver_session_type = get_cross_driver_session_type(param)

    if cross_driver_session_type:
        return get_cross_driver_session_dependency(param).field_name
    else:
        resource_handle_deps = get_driver_shared_resource_repository_ptr_deps(config)
        resource_handle_dep = next(r for r in resource_handle_deps if r.resource_handle_type == common_helpers.get_underlying_type(param))
        return resource_handle_dep.field_name


SessionRepositoryHandleTypeMap = Dict[str, Dict[str, Any]]


def list_session_repository_handle_types(
    driver_configs: List[dict],
) -> SessionRepositoryHandleTypeMap:
    session_repository_handle_type_map = {}
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
