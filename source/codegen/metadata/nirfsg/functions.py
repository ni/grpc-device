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
    'GetError': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'direction': 'in',
                'name': 'errorDescriptionBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorDescriptionBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
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
}
