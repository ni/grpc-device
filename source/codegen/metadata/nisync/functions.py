# -*- coding: utf-8 -*-
functions = {
    "init": {
        "parameters": [
            {"direction": "in", "name": "resourceName", "type": "ViRsrc"},
            {"direction": "in", "name": "IDQuery", "type": "ViBoolean"},
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
}
