functions = {
    "Control4022":{
        "cname":"niDMM_4022Control",
        "parameters":[
            {
                "name":"resourceName",
                "direction":"in",
                "type":"ViRsrc"
            },
            {
                "name":"configuration",
                "direction":"in",
                "type":"ViInt32",
                "enum": "Configuration4022"
            }
        ],
        "returns":"ViStatus"
    },
    'Abort': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    "CheckAttributeViBoolean": {      
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "channelName",
            "direction": "in",
            "type": "ViConstString"
        },
        {
            "name": "attributeId",
            "direction": "in",
            "type": "ViAttr"
        },
        {
            "name": "attributeValue",
            "direction": "in",
            "type": "ViBoolean"
        }
        ],
        "returns": "ViStatus"
    },
    "CheckAttributeViInt32": {       
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "channelName",
            "direction": "in",
            "type": "ViConstString"
        },
        {
            "name": "attributeId",
            "direction": "in",
            "type": "ViAttr"
        },
        {
            "name": "attributeValue",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    "CheckAttributeViReal64": {        
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "channelName",
            "direction": "in",
            "type": "ViConstString"
        },
        {
            "name": "attributeId",
            "direction": "in",
            "type": "ViAttr"
        },
        {
            "name": "attributeValue",
            "direction": "in",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    "CheckAttributeViSession": {        
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "channelName",
            "direction": "in",
            "type": "ViConstString"
        },
        {
            "name": "attributeId",
            "direction": "in",
            "type": "ViAttr"
        },
        {
            "name": "attributeValue",
            "direction": "in",
            "type": "ViSession"
        }
        ],
        "returns": "ViStatus"
    },
    "CheckAttributeViString": {
         "parameters": [
         {
             "name": "vi",
             "direction": "in",
             "type": "ViSession"
         },
         {
             "name": "channelName",
             "direction": "in",
             "type": "ViConstString"
         },
         {
             "name": "attributeId",
             "direction": "in",
             "type": "ViAttr"
         },
         {
             "name": "attributeValue",
             "direction": "in",
             "type": "ViString"
         }
         ],
         "returns": "ViStatus"
     },
    "ClearError": {   
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        }
        ],
        "returns": "ViStatus"
    },
    "ClearInterchangeWarnings": {        
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        }
        ],
        "returns": "ViStatus"
    },
    'Close': {
        'cname': 'niDMM_close',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus',
    },
    "ConfigureACBandwidth": {        
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "acMinimumFrequencyHz",
            "direction": "in",
            "type": "ViReal64"
        },
        {
            "name": "acMaximumFrequencyHz",
            "direction": "in",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureADCCalibration": {       
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "adcCalibration",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureAutoZeroMode": {        
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "autoZeroMode",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureCableCompType": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "cableCompType",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureCurrentSource": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "currentSource",
            "direction": "in",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureFixedRefJunction": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "fixedReferenceJunction",
            "direction": "in",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureFrequencyVoltageRange": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "voltageRange",
            "direction": "in",
            "type": "ViReal64",
            "enum": "FrequencyVoltageRange"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureMeasCompleteDest": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "measCompleteDestination",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    'ConfigureMeasurementAbsolute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'Function',
                'name': 'measurementFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'range',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'resolutionAbsolute',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    "ConfigureMeasCompleteSlope": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "measCompleteSlope",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    'ConfigureMeasurementDigits': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'Function',
                'name': 'measurementFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'range',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'resolutionDigits',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureMultiPoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerCount',
                'type': 'ViInt32',
                'enum': 'TriggerCount'
            },
            {
                'direction': 'in',
                'name': 'sampleCount',
                'type': 'ViInt32',
                'enum': 'SampleCount'
            },
            {
                'default_value': 'SampleTrigger.IMMEDIATE',
                'direction': 'in',
                'enum': 'SampleTrigger',
                'name': 'sampleTrigger',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'sampleInterval',
                'type': 'ViReal64',
                'enum': 'SampleInterval'
            }
        ],
        'returns': 'ViStatus'
    },
    "ConfigureOffsetCompOhms": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "offsetCompOhms",
            "direction": "in",
            "type": "ViInt32",
            "enum": "CompensatedOhms"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureOpenCableCompValues": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "conductance",
            "direction": "in",
            "type": "ViReal64"
        },
        {
            "name": "susceptance",
            "direction": "in",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigurePowerLineFrequency": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "powerLineFrequencyHz",
            "direction": "in",
            "type": "ViReal64",
            "enum": "PowerLineFrequencies"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureShortCableCompValues": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "resistance",
            "direction": "in",
            "type": "ViReal64"
        },
        {
            "name": "reactance",
            "direction": "in",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    'ConfigureRTDCustom': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'rtdA',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'rtdB',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'rtdC',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureRTDType': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'RtdType',
                'name': 'rtdType',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'rtdResistance',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    "ConfigureSampleTriggerSlope": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "sampleTriggerSlope",
            "direction": "in",
            "type": "ViInt32",
            "enum": "SampleTrigSlope"
        }
        ],
        "returns": "ViStatus"
    },
    'ConfigureThermistorCustom': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'thermistorA',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'thermistorB',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'thermistorC',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureThermocouple': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'ThermocoupleType',
                'name': 'thermocoupleType',
                'type': 'ViInt32'
            },
            {
                'default_value': 'ThermocoupleReferenceJunctionType.FIXED',
                'direction': 'in',
                'enum': 'ThermocoupleReferenceJunctionType',
                'name': 'referenceJunctionType',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    "ConfigureThermistorType": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "thermistorType",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    "ConfigureTransducerType": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "transducerType",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    'ConfigureTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'TriggerSource',
                'name': 'triggerSource',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'triggerDelay',
                'enum': 'TriggerDelays',
                'type': 'ViReal64',
            }
        ],
        'returns': 'ViStatus'
    },
    "ConfigureTriggerSlope": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "triggerSlope",
            "direction": "in",
            "type": "ViInt32",
            "enum": "TriggerSlope"
        }
        ],
        "returns": "ViStatus"
    },
    'ConfigureWaveformAcquisition': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'Function',
                'name': 'measurementFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'range',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'rate',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'waveformPoints',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    "ConfigureWaveformCoupling": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "waveformCoupling",
            "direction": "in",
            "type": "ViInt32"
        }
        ],
        "returns": "ViStatus"
    },
    "Control": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "controlAction",
            "direction": "in",
            "type": "ViInt32",
            "enum": "ControlCommit"
        }
        ],
        "returns": "ViStatus"
    },
    'Disable': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationBuffer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'configuration',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'ViInt8[]',
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Fetch': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'maximumTime',
                'type': 'ViInt32',
                'enum': 'TimeLimit'
            },
            {
                'direction': 'out',
                'name': 'reading',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchMultiPoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'maximumTime',
                'type': 'ViInt32',
                'enum': 'TimeLimit'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'readingArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySize'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'actualNumberOfPoints',
                'type': 'ViInt32',
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'maximumTime',
                'type': 'ViInt32',
                'enum': 'TimeLimit'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveformArray',
                'numpy': True,
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySize'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'actualNumberOfPoints',
                'type': 'ViInt32',
            }
        ],
        'returns': 'ViStatus'
    },
    "GetApertureTimeInfo": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "apertureTime",
            "direction": "out",
            "type": "ViReal64",
            "enum": "ApertureTime"
        },
        {
            "name": "apertureTimeUnits",
            "direction": "out",
            "type": "ViInt32",
            "enum": "ApertureTimeUnits"
        }
        ],
        "returns": "ViStatus"
    },
    'GetAttributeViBoolean': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    "GetAttributeViSession": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "channelName",
            "direction": "in",
            "type": "ViConstString"
        },
        {
            "name": "attributeId",
            "direction": "in",
            "type": "ViAttr"
        },
        {
            "name": "attributeValue",
            "direction": "out",
            "type": "ViSession"
        }
        ],
        "returns": "ViStatus"
    },
    'GetAttributeViString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    "GetAutoRangeValue": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "actualRange",
            "direction": "out",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    'GetCalDateAndTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'calType',
                "enum": "CalibrationType",
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'month',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'day',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'year',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'hour',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'minute',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    "GetChannelName": {
         "codegen_method":"public",
         "parameters": [
         {
             "name": "vi",
             "direction": "in",
             "type": "ViSession"
         },
         {
             "name": "index",
             "direction": "in",
             "type": "ViInt32"
         },
         {
             "name": "bufferSize",
             "direction": "in",
             "type": "ViInt32"
         },
         {
             "name": "channelString",
             "direction": "out",
             "type": "ViChar[]",
             "size": {
                    "mechanism": "ivi-dance",
                    "value": "bufferSize"
                },
        }
        ],
        "returns": "ViStatus"
    },
    'GetDevTemp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'options',
                'type': 'ViString'
            },
            {
                'direction': 'out',
                'name': 'temperature',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetError': {
        'is_error_handling': True,
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
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'description',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus',
    },
    "GetErrorMessage": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "errorCode",
            "direction": "in",
            "type": "ViStatus"
        },
        {
            "name": "bufferSize",
            "direction": "in",
            "type": "ViInt32"
        },
        {
            "name": "errorMessage",
            "direction": "out",
            "type": "ViChar[]",
            'size':{
                'mechanism':'ivi-dance',
                'value':'bufferSize'
            }
        }
        ],
        "returns": "ViStatus"
    },
    'GetExtCalRecommendedInterval': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'months',
                'type': 'ViInt32',
            }
        ],
        'returns': 'ViStatus'
    },
    'GetLastCalTemp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'calType',
                "enum": "CalibrationType",
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'temperature',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    "GetMeasurementPeriod": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "period",
            "direction": "out",
            "type": "ViReal64"
        }
        ],
        "returns": "ViStatus"
    },
    "GetNextCoercionRecord": {
         "codegen_method":"public",
         "parameters": [
         {
             "name": "vi",
             "direction": "in",
             "type": "ViSession"
         },
         {
             "name": "bufferSize",
             "direction": "in",
             "type": "ViInt32"
         },
         {
             "name": "coercionRecord",
             "direction": "out",
             "type": "ViChar[]",
             "size": {
                    "mechanism": "ivi-dance",
                    "value": "bufferSize"
                }
         }
         ],
         "returns": "ViStatus"
     },
     "GetNextInterchangeWarning": {
         "codegen_method":"public",
         "parameters": [
         {
             "name": "vi",
             "direction": "in",
             "type": "ViSession"
         },
         {
             "name": "bufferSize",
             "direction": "in",
             "type": "ViInt32"
         },
         {
             "name": "interchangeWarning",
             "direction": "out",
             "type": "ViChar[]",
             "size": {
                    "mechanism": "ivi-dance",
                    "value": "bufferSize"
                },
         }
         ],
         "returns": "ViStatus"
     },
    'GetSelfCalSupported': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'selfCalSupported',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationBuffer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'configuration',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViInt8[]',
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Init':{
        'init_method': True,
        'cname': 'niDMM_init',
        'parameters':[
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'name':'idQuery',
                'direction':'in',
                'type':'ViBoolean'
            },
            {
                'name':'resetDevice',
                'direction':'in',
                'type':'ViBoolean'
            },
            {
                'name':'vi',
                'direction':'out',
                'type':'ViSession'
            },
            {
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns':'ViStatus'
    },
    'InitWithOptions': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViString'
            },
            {
                'default_value': False,
                'direction': 'in',
                'name': 'idQuery',
                'type': 'ViBoolean',
            },
            {
                'default_value': False,
                'direction': 'in',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'default_value': '""',
                'direction': 'in',
                'name': 'optionString',
                'type': 'ViString',
            },
            {
                'direction': 'out',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus',
    },
    'Initiate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    "InvalidateAllAttributes": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        }
        ],
        "returns": "ViStatus"
    },
    "IsOverRange": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "measurementValue",
            "direction": "in",
            "type": "ViReal64"
        },
        {
            "name": "isOverRange",
            "direction": "out",
            "type": "ViBoolean"
        }
        ],
        "returns": "ViStatus"
    },
    "IsUnderRange": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "measurementValue",
            "direction": "in",
            "type": "ViReal64"
        },
        {
            "name": "isUnderRange",
            "direction": "out",
            "type": "ViBoolean"
        }
        ],
        "returns": "ViStatus"
    },
    'LockSession': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus',
    },
    'PerformOpenCableComp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'conductance',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'name': 'susceptance',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'PerformShortCableComp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'resistance',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'name': 'reactance',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'Read': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'default_value': 'hightime.timedelta(milliseconds=-1)',
                'direction': 'in',
                'name': 'maximumTime',
                'type': 'ViInt32',
                'enum': 'TimeLimit'
            },
            {
                'direction': 'out',
                'name': 'reading',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadMultiPoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'maximumTime',
                'type': 'ViInt32',
                'enum': 'TimeLimit'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'readingArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySize'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'actualNumberOfPoints',
                'type': 'ViInt32',
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadStatus': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'acquisitionBacklog',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'enum': 'AcquisitionStatus',
                'name': 'acquisitionStatus',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'maximumTime',
                'type': 'ViInt32',
                'enum': 'TimeLimit'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveformArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySize'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'actualNumberOfPoints',
                'type': 'ViInt32',
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset': {
        'cname': 'niDMM_reset',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    "ResetInterchangeCheck": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        }
        ],
        "returns": "ViStatus"
    },
    'ResetWithDefaults': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    "RevisionQuery": {
         "cname":"niDMM_revision_query",
         "parameters": [
         {
             "name": "vi",
             "direction": "in",
             "type": "ViSession"
         },
         {
             "name": "instrumentDriverRevision",
             "direction": "out",
             "type": "ViChar[]",
             "size": {
                    "mechanism": "fixed",
                    "value": 256
                }
         },
         {
             "name": "firmwareRevision",
             "direction": "out",
             "type": "ViChar[]",
             "size": {
                    "mechanism": "fixed",
                    "value": 256
        }
         }
        ],
        "returns": "ViStatus"
    },
    'SelfCal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfTest': {
        'cname': 'niDMM_self_test',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'selfTestResult',
                'type': 'ViInt16'
            },
            {
                'direction': 'out',
                'name': 'selfTestMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SendSoftwareTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViBoolean': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    "SetAttributeViSession": {
        "parameters": [
        {
            "name": "vi",
            "direction": "in",
            "type": "ViSession"
        },
        {
            "name": "channelName",
            "direction": "in",
            "type": "ViConstString"
        },
        {
            "name": "attributeId",
            "direction": "in",
            "type": "ViAttr"
        },
        {
            "name": "attributeValue",
            "direction": "in",
            "type": "ViSession"
        }
        ],
        "returns": "ViStatus"
    },
    'SetAttributeViString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'ViString'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnlockSession': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus',
    }
}
