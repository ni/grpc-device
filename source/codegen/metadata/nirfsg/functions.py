functions = {
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
    'AllocateArbWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'sizeInSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViBoolean': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViInt32': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViInt64': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViReal64': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViSession': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViString': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckGenerationStatus': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'isDone',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckIfConfigurationListExists': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'listName',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'listExists',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckIfScriptExists': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'scriptName',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'scriptExists',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckIfWaveformExists': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'waveformExists',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearAllArbWaveforms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearArbWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'name',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearError': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearSelfCalibrateRange': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Close': {
        'cname': 'niRFSG_close',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Commit': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDeembeddingTableInterpolationLinear': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'LinearInterpolationFormat',
                'name': 'format',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDeembeddingTableInterpolationNearest': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDeembeddingTableInterpolationSpline': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeConfigurationListStepTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeConfigurationListStepTriggerSource',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeEdge',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeScriptTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeScriptTriggerIdentifier',
                'name': 'triggerID',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'StartTriggerSource',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeEdge',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeStartTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'StartTriggerSource',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeEdge',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalLevelScriptTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeScriptTriggerIdentifier',
                'name': 'triggerID',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'StartTriggerSource',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalLevelActiveLevel',
                'name': 'level',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalModulationUserDefinedWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'userDefinedWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureGenerationMode': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'GenerationMode',
                'name': 'generationMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureOutputEnabled': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'outputEnabled',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureP2PEndpointFullnessStartTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'p2pEndpointFullnessLevel',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigurePXIChassisClk10': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'PXIChassisClk10',
                'name': 'pxiClk10Source',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigurePowerLevelType': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'PowerLevelType',
                'name': 'powerLevelType',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureRF': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'frequency',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'powerLevel',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureRefClock': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'RefClockSource',
                'name': 'refClockSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'refClockRate',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSignalBandwidth': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'signalBandwidth',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareScriptTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeScriptTriggerIdentifier',
                'name': 'triggerID',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareStartTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureUpconverterPLLSettlingTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'pllSettlingTime',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'ensurePLLLocked',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0',
                'include_in_proto': False,
                'name': 'reservedForFutureUse',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateConfigurationList': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'listName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfAttributes',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'configurationListAttributes',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfAttributes'
                },
                'type': 'ViAttr[]'
            },
            {
                'direction': 'in',
                'name': 'setAsActiveList',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateConfigurationListStep': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'setAsActiveStep',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateDeembeddingSparameterTableArray': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'frequencies',
                'size': {
                    'mechanism': 'len',
                    'value': 'frequenciesSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'in',
                'name': 'frequenciesSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'sparameterTable',
                'size': {
                    'mechanism': 'len',
                    'value': 'sparameterTableSize'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'sparameterTableSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'numberOfPorts',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'SParameterOrientation',
                'name': 'sparameterOrientation',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateDeembeddingSparameterTableS2PFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 's2pFilePath',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'SParameterOrientation',
                'name': 'sparameterOrientation',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteAllDeembeddingTables': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteConfigurationList': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'listName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteDeembeddingTable': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteScript': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'scriptName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
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
    'DisableAllModulation': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableConfigurationListStepTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableScriptTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeScriptTriggerIdentifier',
                'name': 'triggerID',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableStartTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorMessage': {
        'cname': 'niRFSG_error_message',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'direction': 'out',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 1024
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorQuery': {
        'cname': 'niRFSG_error_query',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'errorCode',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 1024
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportSignal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'RoutedSignal',
                'name': 'signal',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'SignalIdentifier',
                'name': 'signalIdentifier',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'OutputSignal',
                'name': 'outputTerminal',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAllNamedWaveformNames': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'waveformNames',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'actualBufferSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAllScriptNames': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'scriptNames',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'actualBufferSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetScript': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'scriptName',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'Script',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'actualBufferSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt64': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViInt64'
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViSession': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'bufSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetChannelName': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'index',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'name',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetDeembeddingSparameters': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'sparameters',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'sparametersArraySize',
                    'value_twist': 'numberOfSparameters'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'sparametersArraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'numberOfSparameters',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'numberOfPorts',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
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
    'GetExternalCalibrationLastDateAndTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'year',
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
                'name': 'hour',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'minute',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'second',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetMaxSettablePower': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSelfCalibrationDateAndTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'Module',
                'name': 'module',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'year',
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
                'name': 'hour',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'minute',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'second',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSelfCalibrationTemperature': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'Module',
                'name': 'module',
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
    'GetTerminalName': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'RoutedSignal',
                'name': 'signal',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'SignalIdentifier',
                'name': 'signalIdentifier',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'terminalName',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetUserData': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'identifier',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualDataSize'
                },
                'type': 'ViInt8[]'
            },
            {
                'direction': 'out',
                'name': 'actualDataSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetWaveformBurstStartLocations': {
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
                'name': 'numberOfLocations',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'locations',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'numberOfLocations',
                    'value_twist': 'requiredSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'requiredSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetWaveformBurstStopLocations': {
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
                'name': 'numberOfLocations',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'locations',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'numberOfLocations',
                    'value_twist': 'requiredSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'requiredSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetWaveformMarkerEventLocations': {
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
                'name': 'numberOfLocations',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'locations',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'numberOfLocations',
                    'value_twist': 'requiredSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'requiredSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Init': {
        'cname': 'niRFSG_init',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'direction': 'in',
                'name': 'idQuery',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'direction': 'out',
                'name': 'newVi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'get_last_error': 'deprecated',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            },
            {
                'cppName': 'initializationBehavior',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.SessionInitializationBehavior',
                'name': 'initializationBehavior',
                'proto_only': True,
                'type': 'int32'
            },
            {
                'cppName': 'newSessionInitialized',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'newSessionInitialized',
                'proto_only': True,
                'type': 'bool'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitWithOptions': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'direction': 'in',
                'name': 'idQuery',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'optionString',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'newVi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'get_last_error': 'deprecated',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            },
            {
                'cppName': 'initializationBehavior',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.SessionInitializationBehavior',
                'name': 'initializationBehavior',
                'proto_only': True,
                'type': 'int32'
            },
            {
                'cppName': 'newSessionInitialized',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'newSessionInitialized',
                'proto_only': True,
                'type': 'bool'
            }
        ],
        'returns': 'ViStatus'
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
    'InvalidateAllAttributes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadConfigurationsFromFile': {
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
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
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
        'returns': 'ViStatus'
    },
    'PerformPowerSearch': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'PerformThermalCorrection': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'QueryArbWaveformCapabilities': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'maxNumberWaveforms',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveformQuantum',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'minWaveformSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'maxWaveformSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadAndDownloadWaveformFromFileTDMS': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformIndex',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset': {
        'cname': 'niRFSG_reset',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetAttribute': {
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
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
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
    'ResetWithOptions': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'ResetWithOptionsStepsToOmit',
                'name': 'stepsToOmit',
                'type': 'ViUInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'RevisionQuery': {
        'cname': 'niRFSG_revision_query',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'instrumentDriverRevision',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'out',
                'name': 'firmwareRevision',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SaveConfigurationsToFile': {
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
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelectArbWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'name',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
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
    'SelfCalibrateRange': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'SelfCalibrateRangeStepsToOmit',
                'name': 'stepsToOmit',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'minFrequency',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'maxFrequency',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'minPowerLevel',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'maxPowerLevel',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfTest': {
        'cname': 'niRFSG_self_test',
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
                    'value': 2048
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SendSoftwareEdgeTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'RoutedSignal',
                'name': 'trigger',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'SignalIdentifier',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetArbWaveformNextWritePosition': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'RelativeTo',
                'name': 'relativeTo',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'offset',
                'type': 'ViInt32'
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt64': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt64'
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViSession': {
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
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
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetUserData': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'identifier',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'bufferSize'
                },
                'type': 'ViInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetWaveformBurstStartLocations': {
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
                'name': 'numberOfLocations',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'locations',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfLocations'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetWaveformBurstStopLocations': {
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
                'name': 'numberOfLocations',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'locations',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfLocations'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetWaveformMarkerEventLocations': {
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
                'name': 'numberOfLocations',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'locations',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfLocations'
                },
                'type': 'ViReal64[]'
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
        'returns': 'ViStatus'
    },
    'WaitUntilSettled': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'maxTimeMilliseconds',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteArbWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'iData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'in',
                'name': 'qData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'in',
                'name': 'moreDataPending',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteArbWaveformComplexF32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumberF32',
                'name': 'wfmData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexNumberF32_struct[]'
            },
            {
                'direction': 'in',
                'name': 'moreDataPending',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteArbWaveformComplexF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'wfmData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'moreDataPending',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteArbWaveformComplexI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexI16',
                'name': 'wfmData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexI16_struct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteArbWaveformF32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'iData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal32[]'
            },
            {
                'direction': 'in',
                'name': 'qData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal32[]'
            },
            {
                'direction': 'in',
                'name': 'moreDataPending',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteScript': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'script',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    }
}
