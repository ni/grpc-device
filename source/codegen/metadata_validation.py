from collections import namedtuple
from typing import Any, Dict, Iterable, Set
from schema import Schema, And, Use, Optional
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
        'parameters': list,
        'returns': str,
        Optional('cname'): str
    }
)

def validate_function(function_name: str, metadata: dict):
    try:
        function: Dict[str, Any] = metadata['functions'][function_name]
        function_keys = set(function.keys())
        FUNCTION_SCHEMA.validate(function)
        #validate_keys(function_keys, ["parameters", "returns"], [
        #              "cname", "codegen_method", "init_method", "stream_response", "is_error_handling", "render_in_session_base", "method_name_for_documentation"])
    except Exception as e:
        raise Exception(f"Failed to validate {function_name}") from e


def validate_keys(keys: Iterable[str], required_keys: Iterable[str], optional_keys: Iterable[str]):
    keys = set(keys)
    for required_key in required_keys:
        if required_key not in keys:
            raise Exception(f"missing required key {required_key}")
        keys.remove(required_key)
    for optional_key in optional_keys:
        if optional_key in keys:
            keys.remove(optional_key)
    if any(keys):
        raise Exception(f"Unrecognized keys: {keys}")
