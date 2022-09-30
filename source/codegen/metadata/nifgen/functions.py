# -*- coding: utf-8 -*-
# This file is generated from NI-FGEN API metadata version 20.0.0d5
functions = {
    'AbortGeneration': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'AdjustSampleClockRelativeDelay': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'adjustmentTime',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'adjustmentTime',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'AllocateNamedWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'AllocateWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViBoolean': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViInt32': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'enum': 'NiFgenInt32AttributeValues',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViInt64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'attributeValue_raw',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViReal64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'enum': 'NiFgenReal64AttributeValues',
                'grpc_type': 'double',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViSession': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'attributeValue',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViString': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'attributeValue_raw',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearArbMemory': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearArbSequence': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sequenceHandle',
                'direction': 'in',
                'enum': 'SequenceHandle',
                'grpc_type': 'sint32',
                'name': 'sequenceHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearArbWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'in',
                'enum': 'WaveformHandle',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearError': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearFreqList': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'frequencyListHandle',
                'direction': 'in',
                'enum': 'FrequencyListOptions',
                'grpc_type': 'sint32',
                'name': 'frequencyListHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearInterchangeWarnings': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearUserStandardWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Close': {
        'cname': 'niFgen_close',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Commit': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureAmplitude': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'amplitude',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'amplitude',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureArbSequence': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'sequenceHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'sequenceHandle',
                'type': 'ViInt32'
            },
            {
                'cppName': 'gain',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'gain',
                'type': 'ViReal64'
            },
            {
                'cppName': 'offset',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'offset',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureArbWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            },
            {
                'cppName': 'gain',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'gain',
                'type': 'ViReal64'
            },
            {
                'cppName': 'offset',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'offset',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureChannels': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channels',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channels',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureClockMode': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'clockMode',
                'direction': 'in',
                'enum': 'ClockMode',
                'grpc_type': 'sint32',
                'name': 'clockMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureCustomFIRFilterCoefficients': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numberOfCoefficients',
                'determine_size_from': [
                    'coefficientsArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfCoefficients',
                'type': 'ViInt32'
            },
            {
                'cppName': 'coefficientsArray',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'coefficientsArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfCoefficients'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeScriptTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerId',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerId',
                'type': 'ViConstString'
            },
            {
                'cppName': 'source',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edge',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeStartTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'source',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edge',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalLevelScriptTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerId',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerId',
                'type': 'ViConstString'
            },
            {
                'cppName': 'source',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'cppName': 'triggerWhen',
                'direction': 'in',
                'enum': 'TriggerWhen',
                'grpc_type': 'sint32',
                'name': 'triggerWhen',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureFreqList': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'frequencyListHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'frequencyListHandle',
                'type': 'ViInt32'
            },
            {
                'cppName': 'amplitude',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'amplitude',
                'type': 'ViReal64'
            },
            {
                'cppName': 'dcOffset',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'dcOffset',
                'type': 'ViReal64'
            },
            {
                'cppName': 'startPhase',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'startPhase',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureFrequency': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'frequency',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'frequency',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureOperationMode': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'operationMode',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'operationMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureOutputEnabled': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'enabled',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'enabled',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureOutputImpedance': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'impedance',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'impedance',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureOutputMode': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'outputMode',
                'direction': 'in',
                'enum': 'OutputMode',
                'grpc_type': 'sint32',
                'name': 'outputMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureP2PEndpointFullnessStartTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'p2pEndpointFullnessLevel',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'p2pEndpointFullnessLevel',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureReferenceClock': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'referenceClockSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'referenceClockSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'referenceClockFrequency',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'referenceClockFrequency',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSampleClockSource': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sampleClockSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'sampleClockSource',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSampleRate': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sampleRate',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'sampleRate',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeScriptTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerId',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerId',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeStartTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureStandardWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveform',
                'direction': 'in',
                'enum': 'Waveform',
                'grpc_type': 'sint32',
                'name': 'waveform',
                'type': 'ViInt32'
            },
            {
                'cppName': 'amplitude',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'amplitude',
                'type': 'ViReal64'
            },
            {
                'cppName': 'dcOffset',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'dcOffset',
                'type': 'ViReal64'
            },
            {
                'cppName': 'frequency',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'frequency',
                'type': 'ViReal64'
            },
            {
                'cppName': 'startPhase',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'startPhase',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSynchronization': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'synchronizationSource',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'synchronizationSource',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerMode': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'triggerMode',
                'direction': 'in',
                'enum': 'TriggerMode',
                'grpc_type': 'sint32',
                'name': 'triggerMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateAdvancedArbSequence': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sequenceLength',
                'determine_size_from': [
                    'waveformHandlesArray',
                    'loopCountsArray',
                    'sampleCountsArray',
                    'markerLocationArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sequenceLength',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformHandlesArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'waveformHandlesArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'sequenceLength'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'loopCountsArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'loopCountsArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'sequenceLength'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'sampleCountsArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'sampleCountsArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'sequenceLength'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'markerLocationArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'markerLocationArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'sequenceLength'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'coercedMarkersArray',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'coercedMarkersArray',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'sequenceLength'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'sequenceHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'sequenceHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateArbSequence': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sequenceLength',
                'determine_size_from': [
                    'waveformHandlesArray',
                    'loopCountsArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sequenceLength',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformHandlesArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'waveformHandlesArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'sequenceLength'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'loopCountsArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'loopCountsArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'sequenceLength'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'sequenceHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'sequenceHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateFreqList': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'waveform',
                'direction': 'in',
                'enum': 'Waveform',
                'grpc_type': 'sint32',
                'name': 'waveform',
                'type': 'ViInt32'
            },
            {
                'cppName': 'frequencyListLength',
                'determine_size_from': [
                    'frequencyArray',
                    'durationArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'frequencyListLength',
                'type': 'ViInt32'
            },
            {
                'cppName': 'frequencyArray',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'frequencyArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'frequencyListLength'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'durationArray',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'durationArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'frequencyListLength'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'frequencyListHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'frequencyListHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateWaveformComplexF64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numberOfSamples',
                'determine_size_from': [
                    'waveformDataArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformDataArray',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'waveformDataArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateWaveformF64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformSize',
                'determine_size_from': [
                    'waveformDataArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'waveformSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformDataArray',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'waveformDataArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'waveformSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateWaveformFromFileF64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'fileName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'fileName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'byteOrder',
                'direction': 'in',
                'enum': 'ByteOrder',
                'grpc_type': 'sint32',
                'name': 'byteOrder',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateWaveformFromFileHWS': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'fileName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'fileName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'useRateFromWaveform',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'useRateFromWaveform',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'useGainAndOffsetFromWaveform',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'useGainAndOffsetFromWaveform',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateWaveformFromFileI16': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'fileName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'fileName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'byteOrder',
                'direction': 'in',
                'enum': 'ByteOrder',
                'grpc_type': 'sint32',
                'name': 'byteOrder',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateWaveformI16': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformSize',
                'determine_size_from': [
                    'waveformDataArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'waveformSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformDataArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'waveformDataArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'waveformSize'
                },
                'type': 'ViInt16[]',
                'use_array': True
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'DefineUserStandardWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformSize',
                'determine_size_from': [
                    'waveformDataArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'waveformSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformDataArray',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'waveformDataArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'waveformSize'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteNamedWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteScript': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'scriptName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'scriptName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Disable': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableAnalogFilter': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableDigitalFilter': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableDigitalPatterning': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableScriptTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerId',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerId',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableStartTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableAnalogFilter': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'filterCorrectionFrequency',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'filterCorrectionFrequency',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableDigitalFilter': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableDigitalPatterning': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorHandler': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorMessage': {
        'cname': 'niFgen_error_message',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorQuery': {
        'cname': 'niFgen_error_query',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViInt32'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationBuffer': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sizeInBytes',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'cppName': 'configuration',
                'direction': 'out',
                'grpc_type': 'repeated fixed64',
                'name': 'configuration',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'sizeInBytes'
                },
                'type': 'ViAddr[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationFile': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportSignal': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'signal',
                'direction': 'in',
                'enum': 'Signal',
                'grpc_type': 'sint32',
                'name': 'signal',
                'type': 'ViInt32'
            },
            {
                'cppName': 'signalIdentifier',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'signalIdentifier',
                'type': 'ViConstString'
            },
            {
                'cppName': 'outputTerminal',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'outputTerminal',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViBoolean': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt32': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'attributeValue',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViSession': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'attributeValue',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViString': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'arraySize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'attributeValue',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetChannelName': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'index',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'index',
                'type': 'ViInt32'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'channelString',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'channelString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetError': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'errorDescriptionBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'errorDescriptionBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'errorDescription',
                'direction': 'out',
                'grpc_type': 'string',
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
    'GetExtCalLastDateAndTime': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'year',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'year',
                'type': 'ViInt32'
            },
            {
                'cppName': 'month',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'month',
                'type': 'ViInt32'
            },
            {
                'cppName': 'day',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'day',
                'type': 'ViInt32'
            },
            {
                'cppName': 'hour',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'hour',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minute',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'minute',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetExtCalLastTemp': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'temperature',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'temperature',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetExtCalRecommendedInterval': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'months',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'months',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetFIRFilterCoefficients': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'arraySize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'coefficientsArray',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'coefficientsArray',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'numberOfCoefficientsRead'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'numberOfCoefficientsRead',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'numberOfCoefficientsRead',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetHardwareState': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'state',
                'direction': 'out',
                'enum': 'HardwareState',
                'grpc_type': 'sint32',
                'name': 'state',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetNextCoercionRecord': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'coercionRecord',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'coercionRecord',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetNextInterchangeWarning': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'interchangeWarning',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'interchangeWarning',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSelfCalLastDateAndTime': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'year',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'year',
                'type': 'ViInt32'
            },
            {
                'cppName': 'month',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'month',
                'type': 'ViInt32'
            },
            {
                'cppName': 'day',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'day',
                'type': 'ViInt32'
            },
            {
                'cppName': 'hour',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'hour',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minute',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'minute',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSelfCalLastTemp': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'temperature',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'temperature',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSelfCalSupported': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'selfCalSupported',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'selfCalSupported',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetStreamEndpointHandle': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'streamEndpoint',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'streamEndpoint',
                'type': 'ViConstString'
            },
            {
                'cppName': 'readerHandle',
                'direction': 'out',
                'grpc_type': 'uint32',
                'name': 'readerHandle',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationBuffer': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sizeInBytes',
                'determine_size_from': [
                    'configuration'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'cppName': 'configuration',
                'direction': 'in',
                'grpc_type': 'repeated fixed64',
                'name': 'configuration',
                'size': {
                    'mechanism': 'len',
                    'value': 'sizeInBytes'
                },
                'type': 'ViAddr[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationFile': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Init': {
        'cname': 'niFgen_init ',
        'init_method': True,
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'cppName': 'idQuery',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'idQuery',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'resetDevice',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitWithOptions': {
        'init_method': True,
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'cppName': 'idQuery',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'idQuery',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'resetDevice',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'optionString',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'optionString',
                'type': 'ViConstString'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitializeWithChannels': {
        'init_method': True,
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'resetDevice',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'optionString',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'optionString',
                'type': 'ViConstString'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitiateGeneration': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'InvalidateAllAttributes': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'IsDone': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'done',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'done',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'LockSession': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'callerHasLock',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ManualEnableP2PStream': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'endpointName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'endpointName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'QueryArbSeqCapabilities': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'maximumNumberOfSequences',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'maximumNumberOfSequences',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minimumSequenceLength',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'minimumSequenceLength',
                'type': 'ViInt32'
            },
            {
                'cppName': 'maximumSequenceLength',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'maximumSequenceLength',
                'type': 'ViInt32'
            },
            {
                'cppName': 'maximumLoopCount',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'maximumLoopCount',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'QueryArbWfmCapabilities': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'maximumNumberOfWaveforms',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'maximumNumberOfWaveforms',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformQuantum',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'waveformQuantum',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minimumWaveformSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'minimumWaveformSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'maximumWaveformSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'maximumWaveformSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'QueryFreqListCapabilities': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'maximumNumberOfFreqLists',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'maximumNumberOfFreqLists',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minimumFrequencyListLength',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'minimumFrequencyListLength',
                'type': 'ViInt32'
            },
            {
                'cppName': 'maximumFrequencyListLength',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'maximumFrequencyListLength',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minimumFrequencyListDuration',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'minimumFrequencyListDuration',
                'type': 'ViReal64'
            },
            {
                'cppName': 'maximumFrequencyListDuration',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'maximumFrequencyListDuration',
                'type': 'ViReal64'
            },
            {
                'cppName': 'frequencyListDurationQuantum',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'frequencyListDurationQuantum',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadCurrentTemperature': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'temperature',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'temperature',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset': {
        'cname': 'niFgen_reset',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetAttribute': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetDevice': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetInterchangeCheck': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetWithDefaults': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'RevisionQuery': {
        'cname': 'niFgen_revision_query',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'instrumentDriverRevision',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'instrumentDriverRevision',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            },
            {
                'cppName': 'firmwareRevision',
                'direction': 'out',
                'grpc_type': 'string',
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
    'RouteSignalOut': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'routeSignalFrom',
                'direction': 'in',
                'enum': 'RouteSignalFrom',
                'grpc_type': 'sint32',
                'name': 'routeSignalFrom',
                'type': 'ViInt32'
            },
            {
                'cppName': 'routeSignalTo',
                'direction': 'in',
                'enum': 'RouteSignalTo',
                'grpc_type': 'sint32',
                'name': 'routeSignalTo',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfCal': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfTest': {
        'cname': 'niFgen_self_test',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'selfTestResult',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'selfTestResult',
                'type': 'ViInt16'
            },
            {
                'cppName': 'selfTestMessage',
                'direction': 'out',
                'grpc_type': 'string',
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
    'SendSoftwareEdgeTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'trigger',
                'direction': 'in',
                'enum': 'Trigger',
                'grpc_type': 'sint32',
                'name': 'trigger',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerId',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerId',
                'type': 'ViString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViBoolean': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt32': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'enum': 'NiFgenInt32AttributeValues',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'attributeValue_raw',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'enum': 'NiFgenReal64AttributeValues',
                'grpc_type': 'double',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViSession': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'attributeValue',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViString': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFgenAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'attributeValue_raw',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetNamedWaveformNextWritePosition': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'relativeTo',
                'direction': 'in',
                'enum': 'RelativeTo',
                'grpc_type': 'sint32',
                'name': 'relativeTo',
                'type': 'ViInt32'
            },
            {
                'cppName': 'offset',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'offset',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetWaveformNextWritePosition': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            },
            {
                'cppName': 'relativeTo',
                'direction': 'in',
                'enum': 'RelativeTo',
                'grpc_type': 'sint32',
                'name': 'relativeTo',
                'type': 'ViInt32'
            },
            {
                'cppName': 'offset',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'offset',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnlockSession': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'callerHasLock',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WaitUntilDone': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'maxTime',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'maxTime',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteBinary16Waveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViInt16[]',
                'use_array': True
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteComplexBinary16Waveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexI16',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'NIComplexI16_struct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteNamedWaveformComplexF64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'NIComplexNumber_struct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteNamedWaveformComplexI16': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexI16',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'NIComplexI16_struct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteNamedWaveformF64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteNamedWaveformI16': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViInt16[]',
                'use_array': True
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteP2PEndpointI16': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'endpointName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'endpointName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numberOfSamples',
                'determine_size_from': [
                    'endpointData'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'endpointData',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'endpointData',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViInt16[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteScript': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'script',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'script',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteWaveform': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteWaveformComplexF64': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numberOfSamples',
                'determine_size_from': [
                    'data'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'cppName': 'waveformHandle',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'waveformHandle',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    }
}
