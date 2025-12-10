functions = {
    'AMPMLoadReferenceWaveformFromTDMSFile': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'AmpmReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmSignalType',
                'name': 'signalType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'waveformIndex',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CacheResult': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle',
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'selectorStringOutSize'
                },
                'type': 'char[]',
            },
        ],
        'returns': 'int32',
    },
    'GetError': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'name': 'errorCode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'errorDescriptionBufferSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorDescriptionBufferSize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetErrorString': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'errorDescriptionBufferSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorDescriptionBufferSize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'IQFetchDataOverrideBehavior': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'recordToFetch',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'samplesToRead',
                'type': 'int64'
            },
            {
                'direction': 'in',
                'enum': 'IQDeleteOnFetch',
                'name': 'deleteOnFetch',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 't0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dt',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyDigitalPredistortionToWaveformFromTDMSFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'DpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'measurementTimeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'waveformIndex',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'waveformOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'PAPR',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerOffset',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyPreDPDSignalConditioningToWaveformFromTDMSFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'DpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'waveformIndex',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'waveformOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'PAPR',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDLoadReferenceWaveformFromTDMSFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'DpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'waveformIndex',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IDPDLoadReferenceWaveformFromTDMSFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'IdpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'waveformIndex',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    }
}
