functions = {
    'createSession': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'hostname',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'status',
                'grpc_name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'nimxlc_Session'
    },
    'destroySession': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            }
        ],
        'returns': 'void'
    },
    'refreshTerminalCache': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'void'
    },
    'hasTerminalInformationChanged': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            },
            {
                'direction': 'in',
                'name': 'systemChangeNumber',
                'type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'bool'
    },
    'getSystemChangeNumber': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'uint32'
    },
    'getDeviceContainer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nimxlc_Session'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'DeviceContainer'
    },
    'DeviceContainer_begin': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'DeviceContainer'
            }
        ],
        'returns': 'DeviceIterator'
    },
    'DeviceIterator_next': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'iterator',
                'type': 'DeviceIterator'
            }
        ],
        'returns': 'void'
    },
    'DeviceIterator_getTerminalContainer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'DeviceIterator'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'TerminalContainer'
    },
    'DeviceIterator_getDeviceName': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'DeviceIterator'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'TerminalContainer'
    },
    'DeviceIterator_supportsOnBoardClock': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'DeviceIterator'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'bool'
    },
    'DeviceIterator_isEnd': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'DeviceContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'DeviceIterator'
            }
        ],
        'returns': 'bool'
    },
    'DeviceContainer_destroy': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'DeviceContainer'
            }
        ],
        'returns': 'void'
    },
    'TerminalContainer_begin': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'DeviceContainer'
            }
        ],
        'returns': 'TerminalIterator'
    },
    'TerminalIterator_next': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'iterator',
                'type': 'TerminalIterator'
            }
        ],
        'returns': 'void'
    },
    'TerminalIterator_isEnd': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'TerminalContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'TerminalIterator'
            }
        ],
        'returns': 'bool'
    },
    'TerminalContainer_destroy': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'TerminalContainer'
            }
        ],
        'returns': 'void'
    },
    'TerminalIterator_getTerminalName': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'TerminalContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'TerminalIterator'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'const char*'
    },
    'TerminalIterator_getVisibility': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'container',
                'type': 'TerminalContainer'
            },
            {
                'direction': 'in',
                'name': 'iterator',
                'type': 'TerminalIterator'
            },
            {
                'direction': 'out',
                'name': 'cStatus',
                'type': 'nierrStatus'
            }
        ],
        'returns': 'const char*'
    }
}
