from collections import namedtuple
from typing import Any, Dict, Iterable, Set
from schema import Schema, And, Optional, Or, Use
import common_helpers


def validate_metadata(metadata: dict):
    try:
        for function_name in metadata['functions']:
            validate_function(function_name, metadata)
    except Exception as e:
        raise Exception(
            f"Failed to validate {metadata['config']['namespace_component']}") from e

FUNCTION_SCHEMA = Schema(
    {
        'parameters': [
            {
                'direction': And(str, lambda s: s in ('in', 'out')),
                'name': str,
                Optional('type'): str, # TODO - if this is gone, grpc_type and repeated_var_args need to be set?
                Optional('grpc_type'): str,
                Optional('documentation'): dict, # TODO
                Optional('enum'): str, # TODO
                Optional('size'): dict, # TODO
                Optional('default_value'): Or(str, bool), # TODO?
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
                Optional('hardcoded_value'): str, # TODO - validate right type?
                Optional('is_compound_type'): bool,
                Optional('max_length'): int, # TODO - only if repeated_var_Args
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

def validate_function(function_name: str, metadata: dict):
    try:
        function: Dict[str, Any] = metadata['functions'][function_name]
        FUNCTION_SCHEMA.validate(function)
    except Exception as e:
        raise Exception(f"Failed to validate {function_name}") from e