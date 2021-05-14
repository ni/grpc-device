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
    'RevisionQuery':{
        'cname' : 'niSync_revision_query',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'driverRevision',
                'direction':'out',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'fixed',
                    'value':256
                }
            },
            {
                'name':'firmwareRevision',
                'direction':'out',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'fixed',
                    'value':256
                }
            }
        ],
        'returns':'ViStatus'
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
    "SetTime": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "timeSource",
                "type": "ViInt32"
            },
            {
                "direction": "in",
                "name": "timeSeconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "timeNanoseconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "timeFractionalNanoseconds",
                "type": "ViUInt16"
            }
        ],
        "returns": "ViStatus"
    },
    "GetTime": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "out",
                "name": "timeSeconds",
                "type": "ViUInt32"
            },
            {
                "direction": "out",
                "name": "timeNanoseconds",
                "type": "ViUInt32"
            },
            {
                "direction": "out",
                "name": "timeFractionalNanoseconds",
                "type": "ViUInt16"
            }
        ],
        "returns": "ViStatus"
    },
    "SetTimeReferenceFreeRunning": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            }
        ],
        "returns": "ViStatus"
    },
    "SetTimeReferenceGPS": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            }
        ],
        "returns": "ViStatus"
    },
    "SetTimeReferenceIRIG": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "irigType",
                "type": "ViInt32"
            },
            {
                "direction": "in",
                "name": "terminalName",
                "type": "ViConstString"
            }
        ],
        "returns": "ViStatus"
    },
    "SetTimeReferencePPS": {
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
                "name": "useManualTime",
                "type": "ViBoolean"
            },
            {
                "direction": "in",
                "name": "initialTimeSeconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "initialTimeNanoseconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "initialTimeFractionalNanoseconds",
                "type": "ViUInt16"
            }
        ],
        "returns": "ViStatus"
    },
    "SetTimeReference1588OrdinaryClock": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            }
        ],
        "returns": "ViStatus"
    },
    "SetTimeReference8021AS": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            }
        ],
        "returns": "ViStatus"
    },
    "CreateFutureTimeEvent": {
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
                "name": "outputLevel",
                "type": "ViInt32"
            },
            {
                "direction": "in",
                "name": "timeSeconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "timeNanoseconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "timeFractionalNanoseconds",
                "type": "ViUInt16"
            }
        ],
        "returns": "ViStatus"
    },
    "ClearFutureTimeEvents": {
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
            }
        ],
        "returns": "ViStatus"
    },
    "CreateClock": {
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
                "name": "highTicks",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "lowTicks",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "startTimeSeconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "startTimeNanoseconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "startTimeFractionalNanoseconds",
                "type": "ViUInt16"
            },
            {
                "direction": "in",
                "name": "stopTimeSeconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "stopTimeNanoseconds",
                "type": "ViUInt32"
            },
            {
                "direction": "in",
                "name": "stopTimeFractionalNanoseconds",
                "type": "ViUInt16"
            }
        ],
        "returns": "ViStatus"
    },
    "ClearClock": {
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
            }
        ],
        "returns": "ViStatus"
    },
    "GetTimeReferenceNames": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession"
            },
            {
                "direction": "in",
                "name": "bufferSize",
                "type": "ViUInt32"
            },
            {
                "direction": "out",
                "name": "timeReferenceNames",
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
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
