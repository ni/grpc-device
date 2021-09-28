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