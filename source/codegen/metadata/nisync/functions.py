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
}
