functions = {
    'AddCDAQSyncConnection': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'portList',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'AddGlobalChansToTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelNames',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'AddNetworkDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'ipAddress',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'attemptReservation',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'deviceNameOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'deviceNameOutBufferSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'deviceNameOutBufferSize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'AreConfiguredCDAQSyncPortsDisconnected': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'chassisDevicesPorts',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'disconnectedPortsExist',
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'AutoConfigureCDAQSyncConnections': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'chassisDevicesPorts',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CalculateReversePolyCoeff': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'forwardCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numForwardCoeffsIn'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numForwardCoeffsIn',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'minValX',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxValX',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'numPointsToCompute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reversePolyOrder',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'reverseCoeffs',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(reversePolyOrder < 0) ? numForwardCoeffsIn : reversePolyOrder + 1'
                },
                'type': 'float64[]'
            }
        ],
        'returns': 'int32'
    },
    'CfgAnlgEdgeRefTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Slope1',
                'name': 'triggerSlope',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'triggerLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgAnlgEdgeStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Slope1',
                'name': 'triggerSlope',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'triggerLevel',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgAnlgMultiEdgeRefTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSources',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'triggerSlopeArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'triggerLevelArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgAnlgMultiEdgeStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSources',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'triggerSlopeArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'triggerLevelArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgAnlgWindowRefTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'WindowTriggerCondition1',
                'name': 'triggerWhen',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'windowTop',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'windowBottom',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgAnlgWindowStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'WindowTriggerCondition1',
                'name': 'triggerWhen',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'windowTop',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'windowBottom',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgBurstHandshakingTimingExportClock': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'sampleMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampsPerChan',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'name': 'sampleClkRate',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'sampleClkOutpTerm',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Polarity2',
                'name': 'sampleClkPulsePolarity',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Level1',
                'name': 'pauseWhen',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Polarity2',
                'name': 'readyEventActiveLevel',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgBurstHandshakingTimingImportClock': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'sampleMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampsPerChan',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'name': 'sampleClkRate',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'sampleClkSrc',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'sampleClkActiveEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Level1',
                'name': 'pauseWhen',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Polarity2',
                'name': 'readyEventActiveLevel',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgChangeDetectionTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'risingEdgeChan',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'fallingEdgeChan',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'sampleMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampsPerChan',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'CfgDigEdgeRefTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'triggerEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgDigEdgeStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'triggerEdge',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgDigPatternRefTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'triggerPattern',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'DigitalPatternCondition1',
                'name': 'triggerWhen',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgDigPatternStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'triggerPattern',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'DigitalPatternCondition1',
                'name': 'triggerWhen',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgHandshakingTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'sampleMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampsPerChan',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'CfgImplicitTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'sampleMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampsPerChan',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'CfgInputBuffer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgOutputBuffer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgPipelinedSampClkTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'source',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'rate',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'activeEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'sampleMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampsPerChan',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'CfgSampClkTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'source',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'rate',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'activeEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'sampleMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampsPerChan',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'CfgTimeStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'when',
                'type': 'CVIAbsoluteTime'
            },
            {
                'direction': 'in',
                'enum': 'Timescale2',
                'name': 'timescale',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgWatchdogAOExpirStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'expirStateArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'enum': 'WatchdogAOOutputType',
                'name': 'outputTypeArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgWatchdogCOExpirStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'WatchdogCOExpirState',
                'name': 'expirStateArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'CfgWatchdogDOExpirStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'DigitalLineState',
                'name': 'expirStateArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'ClearTEDS': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'ClearTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'ConfigureLogging': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'LoggingMode',
                'name': 'loggingMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'groupName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'LoggingOperation',
                'name': 'operation',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ConfigureTEDS': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'ConnectTerms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'sourceTerminal',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'destinationTerminal',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InvertPolarity',
                'name': 'signalModifiers',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ControlWatchdogTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'WatchdogControlAction',
                'name': 'action',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIAccel4WireDCVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AccelUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AccelSensitivityUnits1',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'useExcitForScaling',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIAccelChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AccelUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AccelSensitivityUnits1',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIAccelChargeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AccelUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AccelChargeSensitivityUnits',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIBridgeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'BridgeUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIChargeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ChargeUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAICurrentChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'CurrentUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'CurrentShuntResistorLocationWithDefault',
                'name': 'shuntResistorLoc',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'extShuntResistorVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAICurrentRMSChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'CurrentUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'CurrentShuntResistorLocationWithDefault',
                'name': 'shuntResistorLoc',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'extShuntResistorVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIForceBridgePolynomialChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ForceUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'forwardCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numForwardCoeffs'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numForwardCoeffs',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'reverseCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numReverseCoeffs'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numReverseCoeffs',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIForceBridgeTableChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ForceUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'electricalVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numElectricalVals'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numElectricalVals',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'physicalVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numPhysicalVals'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numPhysicalVals',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIForceBridgeTwoPointLinChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ForceUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'firstElectricalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'secondElectricalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'firstPhysicalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'secondPhysicalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIForceIEPEChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ForceIEPEUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ForceIEPESensorSensitivityUnits',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIFreqVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'FrequencyUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'thresholdLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'hysteresis',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIMicrophoneChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'SoundPressureUnits1',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'micSensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxSndPressLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIPosEddyCurrProxProbeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'LengthUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'EddyCurrentProxProbeSensitivityUnits',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIPosLVDTChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'LengthUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'LVDTSensitivityUnits1',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitFreq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ACExcitWireMode',
                'name': 'acExcitWireMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIPosRVDTChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AngleUnits1',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'RVDTSensitivityUnits1',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitFreq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ACExcitWireMode',
                'name': 'acExcitWireMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIPowerChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'voltageSetpoint',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'currentSetpoint',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'outputEnable',
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIPressureBridgePolynomialChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'PressureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'forwardCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numForwardCoeffs'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numForwardCoeffs',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'reverseCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numReverseCoeffs'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numReverseCoeffs',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIPressureBridgeTableChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'PressureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'electricalVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numElectricalVals'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numElectricalVals',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'physicalVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numPhysicalVals'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numPhysicalVals',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIPressureBridgeTwoPointLinChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'PressureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'firstElectricalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'secondElectricalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'firstPhysicalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'secondPhysicalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIRTDChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'RTDType1',
                'name': 'rtdType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'r0',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIResistanceChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIRosetteStrainGageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'StrainGageRosetteType',
                'name': 'rosetteType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'gageOrientation',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'rosetteMeasTypes',
                'size': {
                    'mechanism': 'len',
                    'value': 'numRosetteMeasTypes'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'numRosetteMeasTypes',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'StrainGageBridgeType1',
                'name': 'strainConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'gageFactor',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalGageResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'poissonRatio',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'leadWireResistance',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIStrainGageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'StrainUnits1',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'StrainGageBridgeType1',
                'name': 'strainConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'gageFactor',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'initialBridgeVoltage',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalGageResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'poissonRatio',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'leadWireResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAITempBuiltInSensorChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIThrmcplChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ThermocoupleType1',
                'name': 'thermocoupleType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'CJCSource1',
                'name': 'cjcSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'cjcVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'cjcChannel',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIThrmstrChanIex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'a',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'b',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'c',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIThrmstrChanVex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'a',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'b',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'c',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'r1',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateAITorqueBridgePolynomialChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TorqueUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'forwardCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numForwardCoeffs'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numForwardCoeffs',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'reverseCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numReverseCoeffs'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numReverseCoeffs',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAITorqueBridgeTableChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TorqueUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'electricalVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numElectricalVals'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numElectricalVals',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'physicalVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numPhysicalVals'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numPhysicalVals',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAITorqueBridgeTwoPointLinChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TorqueUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'nominalBridgeResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'firstElectricalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'secondElectricalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'BridgeElectricalUnits',
                'name': 'electricalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'firstPhysicalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'secondPhysicalVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'BridgePhysicalUnits',
                'name': 'physicalUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIVelocityIEPEChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'VelocityUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sensitivity',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'VelocityIEPESensorSensitivityUnits',
                'name': 'sensitivityUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'VoltageUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIVoltageChanWithExcit': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'VoltageUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'BridgeConfiguration1',
                'name': 'bridgeConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'useExcitForScaling',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIVoltageRMSChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'VoltageUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAOCurrentChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'CurrentUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAOFuncGenChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'FuncGenType',
                'name': 'type',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'freq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'amplitude',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'offset',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateAOVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'VoltageUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIAngEncoderChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'EncoderType2',
                'name': 'decodingType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'zidxEnable',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'zidxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'EncoderZIndexPhase1',
                'name': 'zidxPhase',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AngleUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'pulsesPerRev',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'initialAngle',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIAngVelocityChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'EncoderType2',
                'name': 'decodingType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AngularVelocityUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'pulsesPerRev',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCICountEdgesChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'edge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'initialCount',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'CountDirection1',
                'name': 'countDirection',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIDutyCycleChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minFreq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxFreq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'edge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIFreqChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'FrequencyUnits3',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'edge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'CounterFrequencyMethod',
                'name': 'measMethod',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'measTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'divisor',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIGPSTimestampChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'TimeUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'GpsSignalType1',
                'name': 'syncMethod',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCILinEncoderChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'EncoderType2',
                'name': 'decodingType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'zidxEnable',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'zidxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'EncoderZIndexPhase1',
                'name': 'zidxPhase',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'LengthUnits3',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'distPerPulse',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'initialPos',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCILinVelocityChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'EncoderType2',
                'name': 'decodingType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'VelocityUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'distPerPulse',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIPeriodChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TimeUnits3',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'edge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'CounterFrequencyMethod',
                'name': 'measMethod',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'measTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'divisor',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIPulseChanFreq': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'FrequencyUnits2',
                'name': 'units',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIPulseChanTicks': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'sourceTerminal',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIPulseChanTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'DigitalWidthUnits3',
                'name': 'units',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateCIPulseWidthChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TimeUnits3',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'startingEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCISemiPeriodChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TimeUnits3',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCITwoEdgeSepChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TimeUnits3',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'firstEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Edge1',
                'name': 'secondEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateCOPulseChanFreq': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'FrequencyUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Level1',
                'name': 'idleState',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'initialDelay',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'freq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dutyCycle',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateCOPulseChanTicks': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'sourceTerminal',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'Level1',
                'name': 'idleState',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'initialDelay',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'lowTicks',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'highTicks',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateCOPulseChanTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'DigitalWidthUnits3',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'Level1',
                'name': 'idleState',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'initialDelay',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'lowTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'highTime',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateDIChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToLines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'LineGrouping',
                'name': 'lineGrouping',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateDOChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToLines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'LineGrouping',
                'name': 'lineGrouping',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateLinScale': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'name',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'slope',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'yIntercept',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'UnitsPreScaled',
                'name': 'preScaledUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'scaledUnits',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateMapScale': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'name',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'prescaledMin',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'prescaledMax',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'scaledMin',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'scaledMax',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'UnitsPreScaled',
                'name': 'preScaledUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'scaledUnits',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreatePolynomialScale': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'name',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'forwardCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numForwardCoeffsIn'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numForwardCoeffsIn',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'reverseCoeffs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numReverseCoeffsIn'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numReverseCoeffsIn',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'UnitsPreScaled',
                'name': 'preScaledUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'scaledUnits',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIAccelChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AccelUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIBridgeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TEDSUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAICurrentChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TEDSUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'CurrentShuntResistorLocationWithDefault',
                'name': 'shuntResistorLoc',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'extShuntResistorVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIForceBridgeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ForceUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIForceIEPEChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ForceIEPEUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIMicrophoneChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'SoundPressureUnits1',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'maxSndPressLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIPosLVDTChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'LengthUnits2',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitFreq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ACExcitWireMode',
                'name': 'acExcitWireMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIPosRVDTChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AngleUnits1',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitFreq',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ACExcitWireMode',
                'name': 'acExcitWireMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIPressureBridgeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'PressureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIRTDChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIResistanceChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TEDSUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIStrainGageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'StrainUnits1',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'initialBridgeVoltage',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'leadWireResistance',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIThrmcplChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'CJCSource1',
                'name': 'cjcSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'cjcVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'cjcChannel',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIThrmstrChanIex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'currentExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'currentExcitVal',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIThrmstrChanVex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TemperatureUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ResistanceConfiguration',
                'name': 'resistanceConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'r1',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAITorqueBridgeChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TorqueUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TEDSUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTEDSAIVoltageChanWithExcit': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TEDSUnits',
                'name': 'units',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ExcitationSource',
                'name': 'voltageExcitSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'voltageExcitVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTableScale': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'name',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'prescaledVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numPrescaledValsIn'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numPrescaledValsIn',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'scaledVals',
                'size': {
                    'mechanism': 'len',
                    'value': 'numScaledValsIn'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'numScaledValsIn',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'UnitsPreScaled',
                'name': 'preScaledUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'scaledUnits',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateTask': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'is_session_name': True,
                'name': 'sessionName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'task',
                'type': 'TaskHandle'
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
        'returns': 'int32'
    },
    'CreateWatchdogTimerTask': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'is_session_name': True,
                'name': 'sessionName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'lines',
                'repeating_argument': True,
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'DigitalLineState',
                'include_in_proto': False,
                'name': 'expState',
                'repeating_argument': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated WatchdogExpChannelsAndState',
                'is_compound_type': True,
                'max_length': 96,
                'name': 'expStates',
                'repeated_var_args': True
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
        'returns': 'int32'
    },
    'CreateWatchdogTimerTaskEx': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'is_session_name': True,
                'name': 'sessionName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
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
        'returns': 'int32'
    },
    'DeleteNetworkDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'DeleteSavedGlobalChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'DeleteSavedScale': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'DeleteSavedTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'taskName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'DeviceSupportsCal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'calSupported',
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'DisableRefTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'DisableStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'DisconnectTerms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'sourceTerminal',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'destinationTerminal',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'ExportSignal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'Signal',
                'name': 'signalID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'outputTerminal',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetAIChanCalCalDate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'year',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'month',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'day',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'hour',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'minute',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetAIChanCalExpDate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'year',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'month',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'day',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'hour',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'minute',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetAnalogPowerUpStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'channelName',
                'repeating_argument': True,
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'state',
                'repeating_argument': True,
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'PowerUpChannelType',
                'include_in_proto': False,
                'name': 'channelType',
                'repeating_argument': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated AnalogPowerUpChannelAndType',
                'is_compound_type': True,
                'max_length': 96,
                'name': 'channels',
                'repeated_var_args': True
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated double',
                'max_length': 96,
                'name': 'powerUpStates',
                'repeated_var_args': True
            }
        ],
        'returns': 'int32'
    },
    'GetAnalogPowerUpStatesWithOutputType': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelNames',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'stateArray',
                'size': {
                    'mechanism': 'passed-in-by-ptr',
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'enum': 'PowerUpChannelType',
                'name': 'channelTypeArray',
                'size': {
                    'mechanism': 'passed-in-by-ptr',
                    'value': 'arraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetArmStartTrigTimestampVal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetArmStartTrigTrigWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetAutoConfiguredCDAQSyncConnections': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'portList',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'portListSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'portListSize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetBufferAttributeUInt32': {
        'cname': 'DAQmxGetBufferAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'BufferAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetCalInfoAttributeBool': {
        'cname': 'DAQmxGetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetCalInfoAttributeDouble': {
        'cname': 'DAQmxGetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetCalInfoAttributeString': {
        'cname': 'DAQmxGetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetCalInfoAttributeUInt32': {
        'cname': 'DAQmxGetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetChanAttributeBool': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetChanAttributeDouble': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetChanAttributeDoubleArray': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetChanAttributeInt32': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetChanAttributeString': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetChanAttributeUInt32': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeBool': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeDouble': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeDoubleArray': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeInt32': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeInt32Array': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeString': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeUInt32': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDeviceAttributeUInt32Array': {
        'cname': 'DAQmxGetDeviceAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'DeviceAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetDigitalLogicFamilyPowerUpState': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'logicFamily',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetDigitalPowerUpStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'channelName',
                'repeating_argument': True,
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'enum': 'PowerUpStates',
                'include_in_proto': False,
                'name': 'state',
                'repeating_argument': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated string',
                'max_length': 96,
                'name': 'channelName',
                'repeated_var_args': True
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated PowerUpStates',
                'max_length': 96,
                'name': 'powerUpStates',
                'repeated_var_args': True
            }
        ],
        'returns': 'int32'
    },
    'GetDigitalPullUpPullDownStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'channelName',
                'repeating_argument': True,
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'enum': 'ResistorState',
                'include_in_proto': False,
                'name': 'state',
                'repeating_argument': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated string',
                'max_length': 96,
                'name': 'channelName',
                'repeated_var_args': True
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated ResistorState',
                'max_length': 96,
                'name': 'pullUpPullDownStates',
                'repeated_var_args': True
            }
        ],
        'returns': 'int32'
    },
    'GetDisconnectedCDAQSyncPorts': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'portList',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'portListSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'portListSize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetErrorString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'errorString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetExportedSignalAttributeBool': {
        'cname': 'DAQmxGetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetExportedSignalAttributeDouble': {
        'cname': 'DAQmxGetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetExportedSignalAttributeInt32': {
        'cname': 'DAQmxGetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetExportedSignalAttributeString': {
        'cname': 'DAQmxGetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetExportedSignalAttributeUInt32': {
        'cname': 'DAQmxGetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetExtendedErrorInfo': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'out',
                'name': 'errorString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetFirstSampClkWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetFirstSampTimestampVal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetNthTaskChannel': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'index',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetNthTaskDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'index',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetNthTaskReadChannel': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'index',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetPersistedChanAttributeBool': {
        'cname': 'DAQmxGetPersistedChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PersistedChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPersistedChanAttributeString': {
        'cname': 'DAQmxGetPersistedChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PersistedChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPersistedScaleAttributeBool': {
        'cname': 'DAQmxGetPersistedScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PersistedScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPersistedScaleAttributeString': {
        'cname': 'DAQmxGetPersistedScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PersistedScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPersistedTaskAttributeBool': {
        'cname': 'DAQmxGetPersistedTaskAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'taskName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PersistedTaskAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPersistedTaskAttributeString': {
        'cname': 'DAQmxGetPersistedTaskAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'taskName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PersistedTaskAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeBool': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeBytes': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'uInt8[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeDouble': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeDoubleArray': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeInt32': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeInt32Array': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeString': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeUInt32': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetPhysicalChanAttributeUInt32Array': {
        'cname': 'DAQmxGetPhysicalChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'PhysicalChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetReadAttributeBool': {
        'cname': 'DAQmxGetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetReadAttributeDouble': {
        'cname': 'DAQmxGetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetReadAttributeInt32': {
        'cname': 'DAQmxGetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetReadAttributeString': {
        'cname': 'DAQmxGetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetReadAttributeUInt32': {
        'cname': 'DAQmxGetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetReadAttributeUInt64': {
        'cname': 'DAQmxGetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetRealTimeAttributeBool': {
        'cname': 'DAQmxGetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'RealTimeAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetRealTimeAttributeInt32': {
        'cname': 'DAQmxGetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'RealTimeAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetRealTimeAttributeUInt32': {
        'cname': 'DAQmxGetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'RealTimeAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetRefTrigTimestampVal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetScaleAttributeDouble': {
        'cname': 'DAQmxGetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetScaleAttributeDoubleArray': {
        'cname': 'DAQmxGetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetScaleAttributeInt32': {
        'cname': 'DAQmxGetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetScaleAttributeString': {
        'cname': 'DAQmxGetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetSelfCalLastDateAndTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'year',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'month',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'day',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'hour',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'minute',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetStartTrigTimestampVal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetStartTrigTrigWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetSyncPulseTimeWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'GetSystemInfoAttributeString': {
        'cname': 'DAQmxGetSystemInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'SystemAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetSystemInfoAttributeUInt32': {
        'cname': 'DAQmxGetSystemInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'SystemAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTaskAttributeBool': {
        'cname': 'DAQmxGetTaskAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TaskAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTaskAttributeString': {
        'cname': 'DAQmxGetTaskAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TaskAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTaskAttributeUInt32': {
        'cname': 'DAQmxGetTaskAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TaskAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeBool': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeDouble': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeExBool': {
        'cname': 'DAQmxGetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeExDouble': {
        'cname': 'DAQmxGetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeExInt32': {
        'cname': 'DAQmxGetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeExString': {
        'cname': 'DAQmxGetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeExTimestamp': {
        'cname': 'DAQmxGetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'CVIAbsoluteTime'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeExUInt32': {
        'cname': 'DAQmxGetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeExUInt64': {
        'cname': 'DAQmxGetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeInt32': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeString': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeTimestamp': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'CVIAbsoluteTime'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeUInt32': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeUInt64': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeBool': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeDouble': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeDoubleArray': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeInt32': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeInt32Array': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeString': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeTimestamp': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'CVIAbsoluteTime'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetTrigAttributeUInt32': {
        'cname': 'DAQmxGetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWatchdogAttributeBool': {
        'cname': 'DAQmxGetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWatchdogAttributeDouble': {
        'cname': 'DAQmxGetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWatchdogAttributeInt32': {
        'cname': 'DAQmxGetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWatchdogAttributeString': {
        'cname': 'DAQmxGetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWriteAttributeBool': {
        'cname': 'DAQmxGetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWriteAttributeDouble': {
        'cname': 'DAQmxGetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWriteAttributeInt32': {
        'cname': 'DAQmxGetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWriteAttributeString': {
        'cname': 'DAQmxGetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWriteAttributeUInt32': {
        'cname': 'DAQmxGetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetWriteAttributeUInt64': {
        'cname': 'DAQmxGetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'IsTaskDone': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'out',
                'name': 'isTaskDone',
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'LoadTask': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'is_session_name': True,
                'name': 'sessionName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'task',
                'type': 'TaskHandle'
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
        'returns': 'int32'
    },
    'ReadAnalogF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadAnalogScalarF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadBinaryI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'int16[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadBinaryI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadBinaryU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt16[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadBinaryU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCounterF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCounterF64Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCounterScalarF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCounterScalarU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCounterU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCounterU32Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCtrFreq': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'interleaved',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArrayFrequency',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'readArrayDutyCycle',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCtrFreqScalar': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dutyCycle',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCtrTicks': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'interleaved',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArrayHighTicks',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'out',
                'name': 'readArrayLowTicks',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCtrTicksScalar': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'highTicks',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'lowTicks',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCtrTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'interleaved',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArrayHighTime',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'readArrayLowTime',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadCtrTimeScalar': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'highTime',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'lowTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadDigitalLines': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInBytes'
                },
                'type': 'uInt8[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInBytes',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'numBytesPerSamp',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadDigitalScalarU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadDigitalU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt16[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadDigitalU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadDigitalU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'uInt8[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadPowerBinaryI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'readArrayVoltage',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'int16[]'
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'readArrayCurrent',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'int16[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadPowerF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArrayVoltage',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'readArrayCurrent',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadPowerScalarF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'voltage',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'current',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ReadRaw': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInBytes'
                },
                'type': 'uInt8[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInBytes',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsRead',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'numBytesPerSamp',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'RegisterDoneEvent': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'options',
                'type': 'uInt32'
            },
            {
                'callback_params': [
                    {
                        'direction': 'out',
                        'include_in_proto': False,
                        'name': 'task',
                        'type': 'TaskHandle'
                    },
                    {
                        'direction': 'out',
                        'name': 'status',
                        'type': 'int32'
                    }
                ],
                'direction': 'in',
                'include_in_proto': False,
                'name': 'callbackFunction',
                'type': 'DAQmxDoneEventCallbackPtr'
            },
            {
                'callback_token': True,
                'direction': 'in',
                'include_in_proto': False,
                'name': 'callbackData',
                'pointer': True,
                'type': 'void'
            }
        ],
        'returns': 'int32',
        'stream_response': True
    },
    'RegisterEveryNSamplesEvent': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'EveryNSamplesEventType',
                'name': 'everyNSamplesEventType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'nSamples',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'options',
                'type': 'uInt32'
            },
            {
                'callback_params': [
                    {
                        'direction': 'out',
                        'include_in_proto': False,
                        'name': 'task',
                        'type': 'TaskHandle'
                    },
                    {
                        'direction': 'out',
                        'enum': 'EveryNSamplesEventType',
                        'name': 'everyNSamplesEventType',
                        'type': 'int32'
                    },
                    {
                        'direction': 'out',
                        'name': 'nSamples',
                        'type': 'uInt32'
                    }
                ],
                'direction': 'in',
                'include_in_proto': False,
                'name': 'callbackFunction',
                'type': 'DAQmxEveryNSamplesEventCallbackPtr'
            },
            {
                'callback_token': True,
                'direction': 'in',
                'include_in_proto': False,
                'name': 'callbackData',
                'pointer': True,
                'type': 'void'
            }
        ],
        'returns': 'int32',
        'stream_response': True
    },
    'RegisterSignalEvent': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'Signal2',
                'name': 'signalID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'options',
                'type': 'uInt32'
            },
            {
                'callback_params': [
                    {
                        'direction': 'out',
                        'include_in_proto': False,
                        'name': 'task',
                        'type': 'TaskHandle'
                    },
                    {
                        'direction': 'out',
                        'name': 'signalID',
                        'type': 'int32'
                    }
                ],
                'direction': 'in',
                'include_in_proto': False,
                'name': 'callbackFunction',
                'type': 'DAQmxSignalEventCallbackPtr'
            },
            {
                'callback_token': True,
                'direction': 'in',
                'include_in_proto': False,
                'name': 'callbackData',
                'pointer': True,
                'type': 'void'
            }
        ],
        'returns': 'int32',
        'stream_response': True
    },
    'RemoveCDAQSyncConnection': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'portList',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'ReserveNetworkDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'overrideReservation',
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'ResetBufferAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'BufferAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetChanAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'ResetExportedSignalAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetReadAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetRealTimeAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'RealTimeAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetTimingAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetTimingAttributeEx': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetTrigAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetWatchdogAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetWriteAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SaveGlobalChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'saveAs',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'author',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'SaveOptions',
                'name': 'options',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SaveScale': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'saveAs',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'author',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'SaveOptions',
                'name': 'options',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SaveTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'saveAs',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'author',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'SaveOptions',
                'name': 'options',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SelfCal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'SelfTestDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'SetAIChanCalCalDate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'year',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'month',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'day',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'hour',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'minute',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetAIChanCalExpDate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'year',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'month',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'day',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'hour',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'minute',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetAnalogPowerUpStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'channelNames',
                'repeating_argument': True,
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'state',
                'repeating_argument': True,
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'PowerUpChannelType',
                'include_in_proto': False,
                'name': 'channelType',
                'repeating_argument': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated AnalogPowerUpChannelsAndState',
                'is_compound_type': True,
                'max_length': 96,
                'name': 'powerUpStates',
                'repeated_var_args': True
            }
        ],
        'returns': 'int32'
    },
    'SetAnalogPowerUpStatesWithOutputType': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'stateArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'enum': 'PowerUpChannelType',
                'name': 'channelTypeArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetArmStartTrigTrigWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'SetBufferAttributeUInt32': {
        'cname': 'DAQmxSetBufferAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'BufferAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetCalInfoAttributeBool': {
        'cname': 'DAQmxSetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetCalInfoAttributeDouble': {
        'cname': 'DAQmxSetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetCalInfoAttributeString': {
        'cname': 'DAQmxSetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetCalInfoAttributeUInt32': {
        'cname': 'DAQmxSetCalInfoAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'CalibrationInfoAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetChanAttributeBool': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetChanAttributeDouble': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetChanAttributeDoubleArray': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetChanAttributeInt32': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetChanAttributeString': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetChanAttributeUInt32': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ChannelAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetDigitalLogicFamilyPowerUpState': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'LogicFamily',
                'name': 'logicFamily',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetDigitalPowerUpStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'channelNames',
                'repeating_argument': True,
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'PowerUpStates',
                'include_in_proto': False,
                'name': 'state',
                'repeating_argument': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated DigitalPowerUpChannelsAndState',
                'is_compound_type': True,
                'max_length': 96,
                'name': 'powerUpStates',
                'repeated_var_args': True
            }
        ],
        'returns': 'int32'
    },
    'SetDigitalPullUpPullDownStates': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'channelNames',
                'repeating_argument': True,
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'ResistorState',
                'include_in_proto': False,
                'name': 'state',
                'repeating_argument': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated DigitalPullUpPullDownChannelsAndState',
                'is_compound_type': True,
                'max_length': 96,
                'name': 'pullUpPullDownStates',
                'repeated_var_args': True
            }
        ],
        'returns': 'int32'
    },
    'SetExportedSignalAttributeBool': {
        'cname': 'DAQmxSetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetExportedSignalAttributeDouble': {
        'cname': 'DAQmxSetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetExportedSignalAttributeInt32': {
        'cname': 'DAQmxSetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetExportedSignalAttributeString': {
        'cname': 'DAQmxSetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetExportedSignalAttributeUInt32': {
        'cname': 'DAQmxSetExportedSignalAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ExportSignalAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetFirstSampClkWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'SetReadAttributeBool': {
        'cname': 'DAQmxSetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetReadAttributeDouble': {
        'cname': 'DAQmxSetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetReadAttributeInt32': {
        'cname': 'DAQmxSetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetReadAttributeString': {
        'cname': 'DAQmxSetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetReadAttributeUInt32': {
        'cname': 'DAQmxSetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetReadAttributeUInt64': {
        'cname': 'DAQmxSetReadAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'ReadAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetRealTimeAttributeBool': {
        'cname': 'DAQmxSetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'RealTimeAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetRealTimeAttributeInt32': {
        'cname': 'DAQmxSetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'RealTimeAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetRealTimeAttributeUInt32': {
        'cname': 'DAQmxSetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'RealTimeAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetScaleAttributeDouble': {
        'cname': 'DAQmxSetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetScaleAttributeDoubleArray': {
        'cname': 'DAQmxSetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetScaleAttributeInt32': {
        'cname': 'DAQmxSetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetScaleAttributeString': {
        'cname': 'DAQmxSetScaleAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'scaleName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'ScaleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetStartTrigTrigWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'SetSyncPulseTimeWhen': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'data',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeBool': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeDouble': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeExBool': {
        'cname': 'DAQmxSetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeExDouble': {
        'cname': 'DAQmxSetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeExInt32': {
        'cname': 'DAQmxSetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeExString': {
        'cname': 'DAQmxSetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeExTimestamp': {
        'cname': 'DAQmxSetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'CVIAbsoluteTime'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeExUInt32': {
        'cname': 'DAQmxSetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeExUInt64': {
        'cname': 'DAQmxSetTimingAttributeEx',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'deviceNames',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeInt32': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeString': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeTimestamp': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'CVIAbsoluteTime'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeUInt32': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeUInt64': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TimingAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeBool': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeDouble': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeDoubleArray': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeInt32': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeInt32Array': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'const int32[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeString': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeTimestamp': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'CVIAbsoluteTime'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetTrigAttributeUInt32': {
        'cname': 'DAQmxSetTrigAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'TriggerAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWatchdogAttributeBool': {
        'cname': 'DAQmxSetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWatchdogAttributeDouble': {
        'cname': 'DAQmxSetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWatchdogAttributeInt32': {
        'cname': 'DAQmxSetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWatchdogAttributeString': {
        'cname': 'DAQmxSetWatchdogAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'WatchdogAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWriteAttributeBool': {
        'cname': 'DAQmxSetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWriteAttributeDouble': {
        'cname': 'DAQmxSetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWriteAttributeInt32': {
        'cname': 'DAQmxSetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWriteAttributeString': {
        'cname': 'DAQmxSetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWriteAttributeUInt32': {
        'cname': 'DAQmxSetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetWriteAttributeUInt64': {
        'cname': 'DAQmxSetWriteAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'WriteAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt64'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0U',
                'include_in_proto': False,
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'StartNewFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'StartTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'StopTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'TaskControl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'TaskControlAction',
                'name': 'action',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'TristateOutputTerm': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'outputTerminal',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'UnreserveNetworkDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'deviceName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'WaitForNextSampleClock': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'isLate',
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WaitForValidTimestamp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'enum': 'TimestampEvent',
                'name': 'timestampEvent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'timestamp',
                'type': 'CVIAbsoluteTime'
            }
        ],
        'returns': 'int32'
    },
    'WaitUntilTaskDone': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'timeToWait',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'WriteAnalogF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const float64[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteAnalogScalarF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteBinaryI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'coerced': True,
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const int16[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteBinaryI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const int32[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteBinaryU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'coerced': True,
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt16[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteBinaryU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt32[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteCtrFreq': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'frequency',
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'dutyCycle',
                'type': 'const float64[]'
            },
            {
                'direction': 'out',
                'name': 'numSampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteCtrFreqScalar': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'frequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dutyCycle',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteCtrTicks': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'highTicks',
                'type': 'const uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'lowTicks',
                'type': 'const uInt32[]'
            },
            {
                'direction': 'out',
                'name': 'numSampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteCtrTicksScalar': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'highTicks',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'lowTicks',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteCtrTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'highTime',
                'type': 'const float64[]'
            },
            {
                'direction': 'in',
                'name': 'lowTime',
                'type': 'const float64[]'
            },
            {
                'direction': 'out',
                'name': 'numSampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteCtrTimeScalar': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'highTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'lowTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteDigitalLines': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt8[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteDigitalScalarU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteDigitalU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'coerced': True,
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt16[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteDigitalU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt32[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteDigitalU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt8[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteRaw': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSamps',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt8[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    },
    'WriteToTEDSFromArray': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'bitStream',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'const uInt8[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'enum': 'WriteBasicTEDSOptions',
                'name': 'basicTEDSOptions',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'WriteToTEDSFromFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'WriteBasicTEDSOptions',
                'name': 'basicTEDSOptions',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    }
}