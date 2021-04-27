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
    "GetAttributeViInt32": {
        "parameters": [
        {
            "direction": "in",
            "name": "vi",
            "type": "ViSession"
        },
        {
            "direction": "in",
            "name": "terminalName",
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
            "name": "terminalName",
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
            "name": "terminalName",
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
            "type": "ViChar"
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
            "name": "terminalName",
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
}
