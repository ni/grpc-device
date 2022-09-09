functions = {
    'createSession': {
        'init_method': True,
        'status_expression': '(&c_status)->code',
        'parameters': [
            {
                'direction': 'in',
                'name': 'hostname',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'c_status',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'handle',
                'return_value': True,
                'type': 'nimxlc_Session'
            },
        ],
        'returns': 'nimxlc_Session'
    },
    'destroySession': {
        'status_expression' : '0',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session',
            },
        ],
        'returns': 'void',
    },
    'refreshTerminalCache': {
        'status_expression': '(&c_status)->code',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session',
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'c_status',
                'type': 'nierr_Status',
            },
        ],
        'returns': 'void',
    },
    'hasTerminalInformationChanged': {
        'status_expression': '(&c_status)->code',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            },
            {
                'direction': 'in',
                'name': 'systemChangeNumber',
                'type': 'uint32_t'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'c_status',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'name': 'terminal_information_changed',
                'return_value': True,
                'type': 'bool'
            }
        ],
        'returns': 'bool'
    },
    'getSystemChangeNumber': {
        'status_expression': '(&c_status)->code',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'c_status',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'name': 'system_change_number',
                'return_value': True,
                'type': 'uint32_t'
            }
        ],
        'returns': 'uint32_t'
    },
    'getDeviceContainer': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'c_status',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'pointer': True,
                'grpc_type': 'repeated NIMXLCDevice',
                'name': 'container_out',
                'return_value': True,
                'type': 'nimxlc_DeviceContainer'
            }
        ],
        'returns': 'nimxlc_DeviceContainer'
    },
    'DeviceContainer_begin': {
        'status_expression': '(&c_status)->code',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_DeviceContainer'
            },
            {
                'direction': 'out',
                'name': 'iterator_out',
                'return_value': True,
                'type': 'nimxlc_DeviceIterator'
            }
        ],
        'returns': 'nimxlc_DeviceIterator'
    },
    'DeviceIterator_next': {
        'status_expression': 'iterator ? 0 : 1',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'out',
                'name': 'iterator',
                'type': 'nimxlc_DeviceIterator'
            }
        ],
        'returns': 'void'
    },
    'DeviceIterator_getTerminalContainer': {
        'status_expression': '(&c_status)->code',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'nimxlc_DeviceIterator'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'cStatus',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'name': 'container_out',
                'return_value': True,
                'type': 'nimxlc_TerminalContainer'
            }
        ],
        'returns': 'nimxlc_TerminalContainer'
    },
    'DeviceIterator_getDeviceName': {
        'status_expression': '(&c_status)->code',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'nimxlc_DeviceIterator'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'cStatus',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'name': 'string_out',
                'return_value': True,
                'type': 'const char[]'
            }
        ],
        'returns': 'const char*'
    },
    'DeviceIterator_supportsOnBoardClock': {
        'status_expression': '(&c_status)->code',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'nimxlc_DeviceIterator'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'cStatus',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'name': 'bool_out',
                'return_value': True,
                'type': 'bool'
            }
        ],
        'returns': 'bool'
    },
    'DeviceIterator_isEnd': {
        'status_expression': '0',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'nimxlc_DeviceIterator'
            },
            {
                'direction': 'out',
                'name': 'bool_out',
                'return_value': True,
                'type': 'bool'
            }
        ],
        'returns': 'bool'
    },
    'DeviceContainer_destroy': {
        'status_expression': '0',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_DeviceContainer'
            }
        ],
        'returns': 'void'
    },
    'TerminalContainer_begin': {
        'status_expression': '0',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_TerminalContainer'
            },
            {
                'direction': 'out',
                'name': 'iterator_out',
                'return_value': True,
                'type': 'nimxlc_TerminalIterator'
            }
        ],
        'returns': 'nimxlc_TerminalIterator'
    },
    'TerminalIterator_next': {
        'status_expression': '0',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'out',
                'name': 'iterator',
                'type': 'nimxlc_TerminalIterator'
            }
        ],
        'returns': 'void'
    },
    'TerminalIterator_isEnd': {
        'status_expression': '0',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_TerminalContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'nimxlc_TerminalIterator'
            },
            {
                'direction': 'out',
                'name': 'bool_out',
                'return_value': True,
                'type': 'bool'
            }
        ],
        'returns': 'bool'
    },
    'TerminalContainer_destroy': {
        'status_expression': '0',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_TerminalContainer'
            }
        ],
        'returns': 'void'
    },
    'TerminalIterator_getTerminalName': {
        'status_expression': '(&c_status)->code',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_TerminalContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'nimxlc_TerminalIterator'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'cStatus',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'name': 'string_out',
                'return_value': True,
                'type': 'const char[]'
            }
        ],
        'returns': 'const char*'
    },
    'TerminalIterator_getVisibility': {
        'status_expression': '(&c_status)->code',
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'nimxlc_TerminalContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'nimxlc_TerminalIterator'
            },
            {
                'direction': 'out',
                'grpc_type': 'NIErrStatus',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'name': 'cStatus',
                'type': 'nierr_Status'
            },
            {
                'direction': 'out',
                'name': 'string_out',
                'return_value': True,
                'type': 'const char[]'
            }
        ],
        'returns': 'const char*'
    }
}
