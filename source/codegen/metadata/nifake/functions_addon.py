# These dictionaries are merged with the extracted function metadata at build time.
# Changes to the metadata should be made here, because functions.py is generated thus any changes get overwritten.

functions_override_metadata = {
    'SetRuntimeEnvironment': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'environment',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'environment',
                'type': 'ViConstString'
            },
            {
                'cppName': 'environmentVersion',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'environmentVersion',
                'type': 'ViConstString'
            },
            {
                'cppName': 'reserved1',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'reserved1',
                'type': 'ViConstString'
            },
            {
                'cppName': 'reserved2',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'reserved2',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
}

functions_validation_suppressions = {
    "AcceptViSessionArray": {
        "parameters": {
            "sessionArray": ["INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"]
        }
    },
    "BoolArrayInputFunction": {
        "parameters": {
            "anArray": ["INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"]
        }
    },
    "ViUInt8ArrayInputFunction": {
        "parameters": {
            "anArray": ["INPUT_ARRAY_SHOULD_NOT_HAVE_PASSED_IN_SIZE"]
        }
    },
}
