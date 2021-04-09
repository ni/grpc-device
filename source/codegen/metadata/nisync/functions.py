# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 20.5.0d7
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
}
