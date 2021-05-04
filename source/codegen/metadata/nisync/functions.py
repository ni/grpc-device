# -*- coding: utf-8 -*-
functions = {
    "init": {
        'init_method': True,
        "parameters": [
            {"direction": "in", "name": "resourceName", "type": "ViRsrc"},
            {"direction": "in", "name": "idQuery", "type": "ViBoolean"},
            {"direction": "in", "name": "resetDevice", "type": "ViBoolean"},
            {"direction": "out", "name": "vi", "type": "ViSession"},
        ],
        "returns": "ViStatus",
    },
    "close": {
        "parameters": [
            {"direction": "in", "name": "vi", "type": "ViSession"},
        ],
        "returns": "ViStatus",
    },
    "SendSoftwareTrigger": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            }
        ],
        "returns": "ViStatus"
    },
    "ConnectClkTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString"
            }
        ],
        "returns": "ViStatus"
    },
    "DisconnectClkTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString"
            }
        ],
        "returns": "ViStatus"
    },
    "ConnectSWTrigToTerminal": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "syncClock",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "invert",
                "type": "ViInt32"
            },
            {
                "direction": "in",
                "name": "updateEdge",
                "type": "ViInt32"
            },
            {
                "direction": "in",
                "name": "delay",
                "type": "ViReal64"
            }
        ],
        "returns": "ViStatus"
    },
    "DisconnectSWTrigFromTerminal": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString"
            }
        ],
        "returns": "ViStatus"
    },
    "ConnectTrigTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "syncClock",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "invert",
                "type": "ViInt32"
            },
            {
                "direction": "in",
                "name": "updateEdge",
                "type": "ViInt32"
            }
        ],
        "returns": "ViStatus"
    },
    "DisconnectTrigTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString"
            }
        ],
        "returns": "ViStatus"
    },
    "MeasureFrequencyEx": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "duration",
                "type": "ViReal64"
            },
            {
                "direction": "in",
                "name": "decimationCount",
                "type": "ViUInt32"
            },
            {
                "direction": "out",
                "name": "actualDuration",
                "type": "ViReal64"
            },
            {
                "direction": "out",
                "name": "frequency",
                "type": "ViReal64"
            },
            {
                "direction": "out",
                "name": "frequencyError",
                "type": "ViReal64"
            }
        ],
        "returns": "ViStatus"
    },    
    "GetAttributeViInt32": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "out",
                "name": "value",
                "type": "ViInt32"
            }
        ],
        "returns": "ViStatus"
    },
    "SetAttributeViInt32": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViInt32"
            }
        ],
        "returns": "ViStatus"
    },
    "GetAttributeViString": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "in",
                "name": "bufferSize",
                "type": "ViInt32"
            },
            {
                "direction": "out",
                "name": "value",
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        "returns": "ViStatus"
    },
    "SetAttributeViString": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViConstString"
            }
        ],
        "returns": "ViStatus"
    },
    "GetAttributeViBoolean": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "out",
                "name": "value",
                "type": "ViBoolean"
            }
        ],
        "returns": "ViStatus"
    },
    "SetAttributeViBoolean": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViBoolean"
            }
        ],
        "returns": "ViStatus"
    },
    "GetAttributeViReal64": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "out",
                "name": "value",
                "type": "ViReal64"
            }
        ],
        "returns": "ViStatus"
    },
    "SetAttributeViReal64": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString"
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr"
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViReal64"
            }
        ],
        "returns": "ViStatus"
    },
}
