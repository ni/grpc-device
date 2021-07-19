functions = {
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
                'type': 'int32[]'
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
                    'mechanism': 'passed-in',
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
                    'mechanism': 'passed-in',
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
                    'mechanism': 'passed-in',
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
                    'mechanism': 'passed-in',
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
                'type': 'bool32'
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'type': 'int32[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
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
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
                'type': 'bool32'
            }
        ],
        'returns': 'int32'
    }
}
