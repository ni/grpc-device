import common_helpers


def get_include_guard_name(config, suffix):
    include_guard_name = config['namespace_component'] + "_grpc" + suffix
    return include_guard_name.upper()


def get_c_element_type_for_array_that_needs_coercion(parameter):
    if not parameter.get('coerced', False):
        return None
    stripped_type = parameter['type']
    if stripped_type.startswith('const '):
        stripped_type = stripped_type[len('const '):]
    if stripped_type.endswith('*'):
        stripped_type = stripped_type[:-1]
    elif stripped_type.endswith('[]'):
        stripped_type = stripped_type[:-2]
    else:
        return None
    return stripped_type


def is_input_array_that_needs_coercion(parameter):
    return common_helpers.is_input_parameter(parameter) and get_c_element_type_for_array_that_needs_coercion(parameter) is not None


def is_output_array_that_needs_coercion(parameter):
    return common_helpers.is_output_parameter(parameter) and get_c_element_type_for_array_that_needs_coercion(parameter) is not None


def create_args_for_callback(parameters):
    return ", ".join([
        f'{p["type"]} {common_helpers.camel_to_snake(p["name"])}'
        for p in parameters
    ])

def create_args(parameters):
    result = ''
    is_twist_mechanism = common_helpers.has_ivi_dance_with_a_twist_param(
        parameters)
    if is_twist_mechanism:
        twist_value = common_helpers.get_twist_value(parameters)
        twist_value_name = common_helpers.camel_to_snake(twist_value)
    for parameter in parameters:
        parameter_name = common_helpers.camel_to_snake(parameter['cppName'])
        is_array = common_helpers.is_array(parameter['type'])
        is_output = common_helpers.is_output_parameter(parameter)
        if is_output and common_helpers.is_string_arg(parameter):
            type_without_brackets = common_helpers.get_underlying_type_name(
                parameter['type'])
            result = f'{result}({type_without_brackets}*){parameter_name}.data(), '
        elif parameter['type'] in {"ViBoolean[]", "ViSession[]", "ViInt16[]"}:
            result = f'{result}{parameter_name}.data(), '
        elif parameter.get('is_size_param', False) and is_twist_mechanism:
            result = f'{result}{twist_value_name}, '
        elif 'callback_params' in parameter:
            result = f'{result}CallbackRouter::handle_callback, '
        elif 'callback_token' in parameter:
            result =  f'{result}handler->token(), '
        else:
            if is_array and common_helpers.is_struct(parameter):
                parameter_name = parameter_name + ".data()"
            elif not is_array and is_output:
                result = f'{result}&'
            elif get_c_element_type_for_array_that_needs_coercion(parameter) is not None:
                parameter_name = parameter_name + ".data()"
            result = f'{result}{parameter_name}, '
    return result[:-2]


def create_args_for_ivi_dance(parameters):
    result = ''
    for parameter in parameters:
        if parameter.get('is_size_param', False):
            result = f'{result}0, '
        elif common_helpers.is_output_parameter(parameter):
            result = f'{result}nullptr, '
        else:
            result = result + \
                common_helpers.camel_to_snake(parameter['cppName']) + ', '
    return result[:-2]


def create_args_for_ivi_dance_with_a_twist(parameters):
    result = ''
    for parameter in parameters:
        name = common_helpers.camel_to_snake(parameter['cppName'])
        is_array = common_helpers.is_array(parameter['type'])
        if parameter.get('is_size_param', False):
            result = f'{result}0, '
        elif common_helpers.is_output_parameter(parameter):
            if is_array:
                result = f'{result}nullptr, '
            else:
                result = result + f'&{name}' + ', '
        else:
            result = result + common_helpers.camel_to_snake(name) + ', '
    return result[:-2]


def create_params(parameters):
    return ', '.join(create_param(p) for p in parameters)


def get_array_param_size(parameter) -> str:
    if 'size' in parameter and parameter['size']['mechanism'] == 'fixed':
        return parameter['size']['value']

    return ''


def create_param(parameter):
    type = parameter['type']
    name = parameter['cppName']
    if common_helpers.is_struct(parameter):
        type = type.replace("struct ", "")
    if common_helpers.is_array(type):
        array_size = get_array_param_size(parameter)
        return f'{type[:-2]} {name}[{array_size}]'
    elif common_helpers.is_pointer_parameter(parameter):
        return f'{type}* {name}'
    else:
        return f'{type} {name}'


def python_to_c(enum):
    enum_value = enum["values"][0]["value"]
    if isinstance(enum_value, float):
        return "float"
    if isinstance(enum_value, int):
        return "std::int32_t"
    if isinstance(enum_value, str):
        return "std::string"
    return "std::int32_t"


def format_value(value):
    if isinstance(value, str):
        value = f"\"{value}\""
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
        out_value_format = out_value_format + \
            "{" + str(index) + ", " + formated_value + "},"
        index = index+1
    return out_value_format


def get_output_lookup_values(enum_data):
    out_value_format = ""
    index = 1
    is_int = isinstance(enum_data["values"][0]["value"], int)
    if is_int:
        out_value_format = "{0, 0},"
    for value in enum_data["values"]:
        formated_value = format_value(value["value"])
        out_value_format = out_value_format + \
            "{" + str(formated_value) + ", " + str(index) + "},"
        index = index+1
    return out_value_format


def filter_api_functions(functions):
    '''Returns function metadata only for those functions to include for generating the function types to the API library'''
    return [name for name, function in functions.items() if function.get('codegen_method', '') != 'no']


def filter_proto_rpc_functions_to_generate(functions):
    '''Returns function metadata only for those functions to include for generating proto rpc methods'''
    functions_for_code_gen = {'public'}
    return [name for name, function in functions.items() if function.get('codegen_method', 'public') in functions_for_code_gen]


def get_cname(functions, method_name, c_function_prefix):
    if 'cname' in functions[method_name]:
        return functions[method_name]['cname']
    return c_function_prefix + method_name


def is_private_method(function_data):
    return function_data.get('codegen_method', '') == 'private'


def is_custom_close_method(function_data):
    return function_data.get('custom_close_method', False)


def requires_checked_conversion(parameters):
    return any([is_input_array_that_needs_coercion(p) for p in parameters])


def get_request_param(method_name):
    return f'const {get_request_type(method_name)}* request'


def get_request_type(method_name):
    return f"{method_name}Request"


def get_response_param(method_name):
    return f'{get_response_type(method_name)}* response'


def get_response_type(method_name):
    return f'{method_name}Response'


def get_async_functions(functions):
    return {
        name: data 
        for name, data in functions.items() 
        if common_helpers.has_streaming_response(data)
    }


def get_callback_method_parameters(function_data):
    parameters = function_data['parameters']
    input_parameters = [
        p
        for p in parameters
        if common_helpers.is_input_parameter(p)
    ]
    callback_ptr_parameter = next((p for p in parameters if 'callback_params' in p))
    output_parameters = callback_ptr_parameter['callback_params']

    return input_parameters, output_parameters


def create_param_type_list(parameters):
    return ', '.join([p['type'] for p in parameters])