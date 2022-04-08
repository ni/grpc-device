# -*- coding: utf-8 -*-
functions = {
    "Init": {
        "cname": "niSync_init",
        "init_method": True,
        "parameters": [
            {
                "direction": "in",
                "name": "resourceName",
                "type": "ViRsrc",
            },
            {
                "direction": "in",
                "name": "idQuery",
                "type": "ViBoolean",
            },
            {
                "direction": "in",
                "name": "resetDevice",
                "type": "ViBoolean",
            },
            {
                "direction": "out",
                "name": "vi",
                "type": "ViSession",
            }
        ],
        "returns": "ViStatus",
    },
    "Close": {
        "cname": "niSync_close",
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "ErrorMessage": {
        "cname": "niSync_error_message",
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "errorCode",
                "type": "ViStatus",
            },
            {
                "direction": "out",
                "name": "errorMessage",
                "type": "ViChar[]",
                "size": {
                    "mechanism": "fixed",
                    "value": 256,
                },
            },
        ],
        "returns": "ViStatus",
    },
    "Reset": {
        "cname": "niSync_reset",
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "PersistConfig": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "SelfTest": {
        "cname": "niSync_self_test",
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "selfTestResult",
                "type": "ViInt16",
            },
            {
                "direction": "out",
                "name": "selfTestMessage",
                "type": "ViChar[]",
                "size": {
                    "mechanism": "fixed",
                    "value": 256,
                },
            },
        ],
        "returns": "ViStatus",
    },
    "RevisionQuery": {
        "cname": "niSync_revision_query",
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "driverRevision",
                "type": "ViChar[]",
                "size": {
                    "mechanism": "fixed",
                    "value": 256,
                },
            },
            {
                "direction": "out",
                "name": "firmwareRevision",
                "type": "ViChar[]",
                "size": {
                    "mechanism": "fixed",
                    "value": 256,
                },
            },
        ],
        "returns": "ViStatus",
    },
    "ConnectTrigTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "syncClock",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "invert",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "updateEdge",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "DisconnectTrigTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "ConnectSWTrigToTerminal": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "syncClock",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "invert",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "updateEdge",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "delay",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "DisconnectSWTrigFromTerminal": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "SendSoftwareTrigger": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "ConnectClkTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "DisconnectClkTerminals": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "destTerminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "MeasureFrequency": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "duration",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "actualDuration",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "frequency",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "error",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "MeasureFrequencyEx": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "srcTerminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "duration",
                "type": "ViReal64",
            },
            {
                "direction": "in",
                "name": "decimationCount",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "actualDuration",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "frequency",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "frequencyError",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "Start1588": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "Stop1588": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "Start8021AS": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "Stop8021AS": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "SetTime": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "timeSource",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "timeSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "timeNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "timeFractionalNanoseconds",
                "type": "ViUInt16",
            },
        ],
        "returns": "ViStatus",
    },
    "GetTime": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "timeSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timeNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timeFractionalNanoseconds",
                "type": "ViUInt16",
            },
        ],
        "returns": "ViStatus",
    },
    "ResetFrequency": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "CreateFutureTimeEvent": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "outputLevel",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "timeSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "timeNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "timeFractionalNanoseconds",
                "type": "ViUInt16",
            },
        ],
        "returns": "ViStatus",
    },
    "ClearFutureTimeEvents": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "EnableTimeStampTrigger": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "activeEdge",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "EnableTimeStampTriggerWithDecimation": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "activeEdge",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "decimationCount",
                "type": "ViUInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "ReadTriggerTimeStamp": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "timeout",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "timeSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timeNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timeFractionalNanoseconds",
                "type": "ViUInt16",
            },
            {
                "direction": "out",
                "name": "detectedEdge",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "ReadMultipleTriggerTimeStamp": {
        "codegen_method": "CustomCode",
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "timestampsToRead",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "timeout",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "timeSecondsBuffer",
                "type": "ViUInt32[]",
                "size": {
                    "mechanism": "passed-in",
                    "value": "timestampsToRead",
                },
            },
            {
                "direction": "out",
                "name": "timeNanosecondsBuffer",
                "type": "ViUInt32[]",
                "size": {
                    "mechanism": "passed-in",
                    "value": "timestampsToRead",
                },
            },
            {
                "direction": "out",
                "name": "timeFractionalNanosecondsBuffer",
                "type": "ViUInt16[]",
                "size": {
                    "mechanism": "passed-in",
                    "value": "timestampsToRead",
                },
            },
            {
                "direction": "out",
                "name": "detectedEdgeBuffer",
                "type": "ViInt32[]",
                "size": {
                    "mechanism": "passed-in",
                    "value": "timestampsToRead",
                },
            },
            {
                "direction": "out",
                "name": "timestampsRead",
                "type": "ViUInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "DisableTimeStampTrigger": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "CreateClock": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "highTicks",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "lowTicks",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "startTimeSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "startTimeNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "startTimeFractionalNanoseconds",
                "type": "ViUInt16",
            },
            {
                "direction": "in",
                "name": "stopTimeSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "stopTimeNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "stopTimeFractionalNanoseconds",
                "type": "ViUInt16",
            },
        ],
        "returns": "ViStatus",
    },
    "ClearClock": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "SetTimeReferenceFreeRunning": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "SetTimeReferenceGPS": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "SetTimeReferenceIRIG": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "irigType",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "terminalName",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "SetTimeReferencePPS": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminalName",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "useManualTime",
                "type": "ViBoolean",
            },
            {
                "direction": "in",
                "name": "initialTimeSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "initialTimeNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "in",
                "name": "initialTimeFractionalNanoseconds",
                "type": "ViUInt16",
            },
        ],
        "returns": "ViStatus",
    },
    "SetTimeReference1588OrdinaryClock": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "SetTimeReference8021AS": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "EnableGPSTimestamping": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "EnableIRIGTimestamping": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "irigType",
                "type": "ViInt32",
            },
            {
                "direction": "in",
                "name": "terminalName",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "ReadLastGPSTimestamp": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "timestampSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timestampNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timestampFractionalNanoseconds",
                "type": "ViUInt16",
            },
            {
                "direction": "out",
                "name": "gpsSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "gpsNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "gpsFractionalNanoseconds",
                "type": "ViUInt16",
            },
        ],
        "returns": "ViStatus",
    },
    "ReadLastIRIGTimestamp": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminal",
                "type": "ViConstString",
            },
            {
                "direction": "out",
                "name": "timestampSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timestampNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timestampFractionalNanoseconds",
                "type": "ViUInt16",
            },
            {
                "direction": "out",
                "name": "irigbSeconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "irigbNanoseconds",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "irigbFractionalNanoseconds",
                "type": "ViUInt16",
            },
        ],
        "returns": "ViStatus",
    },
    "DisableGPSTimestamping": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
        ],
        "returns": "ViStatus",
    },
    "DisableIRIGTimestamping": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "terminalName",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "GetVelocity": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "eastVelocity",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "northVelocity",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "upVelocity",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "GetLocation": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "latitude",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "longitude",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "altitude",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "GetTimeReferenceNames": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "bufferSize",
                "type": "ViUInt32",
            },
            {
                "direction": "out",
                "name": "timeReferenceNames",
                "type": "ViChar[]",
                "size": {
                    "mechanism": "ivi-dance",
                    "value": "bufferSize",
                },
            },
        ],
        "returns": "ViStatus",
    },
    "GetAttributeViInt32": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "out",
                "name": "value",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "GetAttributeViReal64": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "out",
                "name": "value",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "GetAttributeViBoolean": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "out",
                "name": "value",
                "type": "ViBoolean",
            },
        ],
        "returns": "ViStatus",
    },
    "GetAttributeViString": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "in",
                "name": "bufferSize",
                "type": "ViInt32",
            },
            {
                "direction": "out",
                "name": "value",
                "type": "ViChar[]",
                "size": {
                    "mechanism": "ivi-dance",
                    "value": "bufferSize",
                },
            },
        ],
        "returns": "ViStatus",
    },
    "SetAttributeViInt32": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "SetAttributeViReal64": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "SetAttributeViBoolean": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViBoolean",
            },
        ],
        "returns": "ViStatus",
    },
    "SetAttributeViString": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "activeItem",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "attribute",
                "type": "ViAttr",
            },
            {
                "direction": "in",
                "name": "value",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "GetExtCalLastDateAndTime": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "year",
                "type": "ViInt32",
            },
            {
                "direction": "out",
                "name": "month",
                "type": "ViInt32",
            },
            {
                "direction": "out",
                "name": "day",
                "type": "ViInt32",
            },
            {
                "direction": "out",
                "name": "hour",
                "type": "ViInt32",
            },
            {
                "direction": "out",
                "name": "minute",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "GetExtCalLastTemp": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "temp",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "GetExtCalRecommendedInterval": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "months",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "ChangeExtCalPassword": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "oldPassword",
                "type": "ViConstString",
            },
            {
                "direction": "in",
                "name": "newPassword",
                "type": "ViConstString",
            },
        ],
        "returns": "ViStatus",
    },
    "ReadCurrentTemperature": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "temperature",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "CalGetOscillatorVoltage": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "voltage",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "CalGetClk10PhaseVoltage": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "voltage",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "CalGetDDSStartPulsePhaseVoltage": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "voltage",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "CalGetDDSInitialPhase": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "out",
                "name": "phase",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "InitExtCal": {
        "init_method": True,
        "parameters": [
            {
                "direction": "in",
                "name": "resourceName",
                "type": "ViRsrc",
            },
            {
                "direction": "in",
                "name": "password",
                "type": "ViConstString",
            },
            {
                "direction": "out",
                "name": "vi",
                "type": "ViSession",
            }
        ],
        "returns": "ViStatus",
    },
    "CloseExtCal": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "action",
                "type": "ViInt32",
            },
        ],
        "returns": "ViStatus",
    },
    "CalAdjustOscillatorVoltage": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "measuredVoltage",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "oldVoltage",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "CalAdjustClk10PhaseVoltage": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "measuredVoltage",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "oldVoltage",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "CalAdjustDDSStartPulsePhaseVoltage": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "measuredVoltage",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "oldVoltage",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
    "CalAdjustDDSInitialPhase": {
        "parameters": [
            {
                "direction": "in",
                "name": "vi",
                "type": "ViSession",
            },
            {
                "direction": "in",
                "name": "measuredPhase",
                "type": "ViReal64",
            },
            {
                "direction": "out",
                "name": "oldPhase",
                "type": "ViReal64",
            },
        ],
        "returns": "ViStatus",
    },
}
