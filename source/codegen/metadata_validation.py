from typing import Any, Dict, Iterable, List, Set
from schema import Schema, And, Optional, Or, Use
import common_helpers


# Rules that can be suppressed
class RULES:
    ARRAY_PARAMETER_NEEDS_SIZE = "ARRAY_PARAMETER_NEEDS_SIZE"
    INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE = "INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"


def validate_metadata(metadata: dict):
    try:
        for function_name in metadata['functions']:
            validate_function(function_name, metadata)
        for attribute_group in common_helpers.get_attribute_groups(metadata):
            for attribute_id in attribute_group.attributes:
                validate_attribute(attribute_group.attributes[attribute_id], metadata)
    except Exception as e:
        raise Exception(
            f"Failed to validate {metadata['config']['namespace_component']}") from e

FUNCTION_SCHEMA = Schema(
    {
        'parameters': [
            {
                'direction': And(str, lambda s: s in ('in', 'out')),
                'name': str,
                Optional('type'): str,
                Optional('grpc_type'): str,
                Optional('documentation'): dict, # TODO
                Optional('enum'): str,
                Optional('size'): dict,
                Optional('default_value'): Or(str, bool),
                Optional('is_repeated_capability'): bool,
                Optional('repeated_capability_type'): str,
                Optional('use_array'): bool,
                Optional('numpy'): bool,
                Optional('grpc_field_number'): And(str, Use(int)), # integer in string form, make sure int(x) doesn't raise
                Optional('grpc_raw_field_number'): And(str, Use(int)), # integer in string form, make sure int(x) doesn't raise
                Optional('type_in_documentation'): str,
                Optional('include_in_proto'): bool,
                Optional('is_session_handle'): bool,
                Optional('is_session_name'): bool,
                Optional('repeating_argument'): bool,
                Optional('python_api_converter_name'): str,
                Optional('attribute'): str, # TODO?
                Optional('hardcoded_value'): str,
                Optional('is_compound_type'): bool,
                Optional('max_length'): int, # TODO - only if repeated_var_args
                Optional('repeated_var_args'): bool,
                Optional('pointer'): bool, # TODO - when is this legal?
                Optional('coerced'): bool, # TODO - figure out when this is OK?
                Optional('callback_params'): [dict], # TODO
                Optional('callback_token'): bool,
            }
        ],
        'returns': str,
        Optional('cname'): str,
        Optional('codegen_method'): And(str, lambda s: s in ('public', 'private', 'CustomCode', 'no', 'python-only')),
        Optional('init_method'): bool,
        Optional('stream_response'): bool,
        Optional('is_error_handling'): bool,
        Optional('render_in_session_base'): bool,
        Optional('method_name_for_documentation'): str,
        Optional('use_session_lock'): bool,
        Optional('documentation'): {
            'description': str
        }
    }
)

SIZE_SCHEMA = Schema(
    {
        'mechanism': And(str, lambda s: not common_helpers.is_unsupported_size_mechanism_type(s)),
        'value': Or(str, int),
        Optional('value_twist'): str,
    },
)

ATTRIBUTE_SCHEMA = Schema(
    {
        "name": str,
        # I think these should be 'read-write', 'read' or 'write', but we don't seem to use this anyhow.
        Optional("access"): str,
        "type": str,
        Optional("resettable"): bool,
        Optional("enum"): str,
        Optional("channel_based"): bool,
        Optional("attribute_class"): str,
        Optional("type_in_documentation"): str,
        Optional("documentation"): {
            'description': str,
            Optional('note'): str,
            Optional('table_body'): list
        },
        Optional("lv_property"): str,
        Optional("repeated_capability_type"): str,
        Optional("python_type"): str,
        Optional("python_name"): str,
        Optional("codegen_method"): str,
    }
)

SIMPLE_ATTRIBUTE_SCHEMA = Schema(
    {
        "name": str
    }
)

def rule_is_suppressed(metadata: dict, rule: str, path: List[str]) -> bool:
    suppression_dict_name = path[0] + "_validation_suppression"
    suppression_dict = metadata.get(suppression_dict_name, {})
    for entry in path[1:-1]:
        suppression_dict = suppression_dict.get(entry, {})
    last_entry = path[-1]
    if last_entry not in suppression_dict:
        return False
    return rule in suppression_dict[last_entry]

def parameter_name_exists(function: dict, name: str) -> bool:
    return any([param for param in function['parameters'] if param['name'] == name])

def validate_function(function_name: str, metadata: dict):
    try:
        function: Dict[str, Any] = metadata['functions'][function_name]
        FUNCTION_SCHEMA.validate(function)
        if function.get('codegen_method', 'public') != 'no':
            for parameter in function['parameters']:
                validate_parameter_size(parameter, function_name, metadata)
                if 'type' not in parameter:
                    if 'grpc_type' not in parameter:
                        raise Exception(f"parameter {parameter['name']} has no type or grpc_type!")
                    if not parameter.get('repeated_var_args', False):
                        raise Exception(f"parameter {parameter['name']} has no type and repeated_var_args is not set!")
                if 'enum' in parameter:
                    if parameter['enum'] not in metadata['enums']:
                        raise Exception(f"parameter {parameter['name']} has enum {parameter['enum']} that was not found!")

    except Exception as e:
        raise Exception(f"Failed to validate function {function_name}") from e

def validate_attribute(attribute: dict, metadata: dict):
    try:
        if metadata['config']['module_name'] == 'nisync':
            # The attributes for nisync only have a name
            SIMPLE_ATTRIBUTE_SCHEMA.validate(attribute)
        else:
            ATTRIBUTE_SCHEMA.validate(attribute)
        if 'enum' in attribute:
            if attribute['enum'] not in metadata['enums']:
                raise Exception(f"attribute {attribute['name']} has enum {attribute['enum']} that was not found!")

    except Exception as e:
        raise Exception(f"Failed to validate enum with name {attribute.get('name', '(none)')}") from e


def validate_parameter_size(parameter: dict, function_name: str, metadata: dict):
    function: Dict[str, Any] = metadata['functions'][function_name]
    size = parameter.get('size', None)
    if size is None:
        if common_helpers.is_array(parameter.get('type', '')) and not is_string_type(parameter, metadata):
            if not rule_is_suppressed(metadata, RULES.ARRAY_PARAMETER_NEEDS_SIZE, ["functions", function_name, 'parameters', parameter['name']]):
                raise Exception(f"parameter {parameter['name']} is an array but has no size!")
    if size is not None:
        SIZE_SCHEMA.validate(size)
        mechanism = size['mechanism']
        if mechanism in ['len', 'ivi-dance', 'ivi-dance-with-a-twist', 'passed-in']:
            if not parameter_name_exists(function, size['value']):
                raise Exception(f"parameter {parameter['name']} refers to nonexistant parameter {size['value']} in its size value!")
        if mechanism == 'ivi-dance-with-a-twist':
            if 'value_twist' not in size:
                raise Exception(f"parameter {parameter['name']} doesn't have value_twist in its size parameter!")
            if not parameter_name_exists(function, size['value_twist']):
                raise Exception(f"parameter {parameter['name']} refers to nonexistant parameter {size['value_twist']} in its size value_twist!")
        else:
            if 'value_twist' in size:
                raise Exception(f"parameter {parameter['name']} has value_twist in its size parameter but is not ivi-dance-with-a-twist!")
        if parameter['direction'] == 'in':
            if mechanism == 'passed-in':
                if not rule_is_suppressed(metadata, RULES.INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE,
                ["functions", function_name, "parameters", parameter["name"]]):
                    raise Exception(f"parameter {parameter['name']} is an input but has mechanism {mechanism}! Use mechanism len instead so the user doesn't have to explicitly pass in the size.")
            if mechanism in ['ivi-dance', 'ivi-dance-with-a-twist']:
                raise Exception(f"parameter {parameter['name']} is an input but has mechanism {mechanism}!")
        else:
            if mechanism == "len":
                raise Exception(f"parameter {parameter['name']} is an output but has mechanism {mechanism}!")

def is_string_type(parameter: dict, metadata: dict) -> bool:
    if parameter.get('is_compound_type', False):
        return False
    grpc_type = parameter.get('grpc_type', None)
    if grpc_type is None:
        grpc_type = common_helpers.get_grpc_type(parameter['type'], metadata['config'])
    return grpc_type == 'string'