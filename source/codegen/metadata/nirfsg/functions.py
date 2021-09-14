functions = {
    "Init": {
        "init_method": True,
        "codegen_method": "public",
        "cname": "niRFSG_init",
        "parameters": [
            {
                "name": "resourceName",
                "direction": "in",
                "type": "ViRsrc"
            },
            {
                "name": "idQuery",
                "direction": "in",
                "type": "ViBoolean"
            },
            {
                "name": "reset",
                "direction": "in",
                "type": "ViBoolean"
            },
            {
                "name": "vi",
                "direction": "out",
                "type": "ViSession",
                "xxgrpc_type": "nidevice_grpc.Session"
            }
        ],
        "returns": "ViStatus"
    },
    "Close": {
        "cname": "niRFSG_close",
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            }
        ],
        "returns": "ViStatus",
    },
    "InitWithOptions": {
        "init_method": True,
        "parameters": [
            {
                "direction": "in",
                "name": "resourceName",
                "type": "ViRsrc"
            },
            {
                "direction": "in",
                "name": "idQuery",
                "type": "ViBoolean",
            },
            {
                "direction": "in",
                "name": "resetDevice",
                "type": "ViBoolean"
            },
            {
                "direction": "in",
                "name": "optionString",
                "type": "ViConstString",
            },
            {
                "direction": "out",
                "name": "vi",
                "type": "ViSession"
            }
        ],
        "returns": "ViStatus",
    },
    'ErrorMessage': {
        'cname': 'niRFSG_error_message',
        'parameters': [
            {
                'name': 'vi',
                'direction': 'in',
                'type': 'ViSession'
            },
            {
                'name': 'errorCode',
                'direction': 'in',
                'type': 'ViStatus'
            },
            {
                'name': 'errorMessage',
                'direction': 'out',
                'type': 'ViChar[]',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                }
            }
        ],
        'returns': 'ViStatus'
    },
}
