functions = {
    'ChannelNumberToCarrierFrequency': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'frequencyBand',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'channelBandwidth',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'secondaryFactor',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'channelStartingFactor',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ChannelNumberToCarrierFrequency80211abgjpn': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelStartingFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelBandwidth',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'secondaryFactor',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ChannelNumberToCarrierFrequency80211ac': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelStartingFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelNumber',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ChannelNumberToCarrierFrequency80211af': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelStartingFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelBandwidth',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'TvhtMode',
                'name': 'tvhtMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ChannelNumberToCarrierFrequency80211ah': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelStartingFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelNumber',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ChannelNumberToCarrierFrequency80211ax': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelStartingFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'channelNumber',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CloseSession': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            }
        ],
        'returns': 'int32'
    },
    'CreateAndWriteWaveformsToFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'FileOperationMode',
                'name': 'fileOperation',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateMIMOWaveformsComplexF64': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'reset',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 't0',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'numberOfTxChains'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'dt',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'numberOfTxChains'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'waveforms',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'individualWaveformSize',
                    'value_twist': 'actualNumSamplesInEachWfm'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfTxChains',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'individualWaveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumSamplesInEachWfm',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'done',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateMIMOWaveformsComplexF64InterleavedIQ': {
        'cname': 'niWLANG_CreateMIMOWaveformsComplexF64',
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'reset',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 't0',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'numberOfTxChains'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'dt',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'numberOfTxChains'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'waveforms',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'individualWaveformSize',
                    'value_twist': 'actualNumSamplesInEachWfm'
                },
                'type': 'float64[]',
                'value_converted_to_c_representation': 'reinterpret_cast<NIComplexNumber*>(waveforms)'
            },
            {
                'direction': 'in',
                'name': 'numberOfTxChains',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'individualWaveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumSamplesInEachWfm',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'done',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateTriggerFrameMSDU': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'generationDone',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'triggerFrameMsduBits',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualDataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualDataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateWaveformComplexF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'reset',
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
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'waveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'waveformSize',
                    'value_twist': 'actualNumWaveformSamples'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'waveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumWaveformSamples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'done',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateWaveformComplexF64InterleavedIQ': {
        'cname': 'niWLANG_CreateWaveformComplexF64',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'reset',
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
                'name': 'waveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'waveformSize',
                    'value_twist': 'actualNumWaveformSamples'
                },
                'type': 'float64[]',
                'value_converted_to_c_representation': 'reinterpret_cast<NIComplexNumber*>(waveform)'
            },
            {
                'direction': 'in',
                'name': 'waveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumWaveformSamples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'done',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetErrorString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorMessageLength'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'errorMessageLength',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetMappingMatrix': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'mappingMatrix',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'matrix_size'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixRows',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixColumns',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetMappingMatrixInterleavedIQ': {
        'cname': 'niWLANG_GetMappingMatrix',
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'mappingMatrix',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'matrix_size'
                },
                'type': 'float64[]',
                'value_converted_to_c_representation': 'reinterpret_cast<NIComplexNumber*>(mappingMatrix)'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixRows',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixColumns',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetNumberOfUsersFromRUAllocation': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'numberOfUsers',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetScalarAttributeF64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'GetScalarAttributeI32': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetScalarAttributeI64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'GetVectorAttributeF64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualNumDataArrayElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumDataArrayElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetVectorAttributeI32': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualNumDataArrayElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumDataArrayElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'LoadConfigurationFromFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resetSession',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'OpenSession': {
        'custom_close': 'CloseSession(id)',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'is_session_name': True,
                'name': 'sessionName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'CompatibilityVersion',
                'name': 'toolkitCompatibilityVersion',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'isNewSession',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGClearDatabase': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'RFSGConfigureFrequencyMultipleLO': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfRFSGSessions'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfRFSGSessions',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'LOSource',
                'name': 'loSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'externalLOHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfExternalLOHandles'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfExternalLOHandles',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'carrierFrequency',
                'size': {
                    'mechanism': 'len',
                    'value': 'dataArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'rfsgLODaisyChainEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'loExportToExternalDevicesEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGConfigureFrequencySingleLO': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfRFSGSessions'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfRFSGSessions',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'LOSource',
                'name': 'loSource',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'externalLoHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'carrierFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'rfsgLODaisyChainEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'loExportToExternalDevicesEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGConfigureMultipleDeviceSynchronization': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfRFSGSessions'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfRFSGSessions',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'masterReferenceClockSource',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'triggerLines',
                'size': {
                    'mechanism': 'len',
                    'value': 'noOfTriggerLines'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'noOfTriggerLines',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGConfigurePowerLevel': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'script',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'powerLevel',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGConfigureSampleClockDelay': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'noOfChannels'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'sampleClockDelay',
                'size': {
                    'mechanism': 'len',
                    'value': 'noOfChannels'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'noOfChannels',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGConfigureScript': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'script',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'powerLevel',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGCreateAndDownloadMIMOWaveforms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfTxChains'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfTxChains',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'RFSGCreateAndDownloadWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'RFSGForceTClkSynchronization': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfRFSGSessions'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfRFSGSessions',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'forceSync',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGInsertRFBlankingMarkerPositions': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'script',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'scriptOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'lenOfScriptOut',
                    'value_twist': 'actualLenOfScriptOut'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'lenOfScriptOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualLenOfScriptOut',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGMultipleDeviceInitiate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfRFSGSessions'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfRFSGSessions',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGReadAndDownloadWaveformsFromFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandles',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfChannels'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfChannels',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrieveBurstStartLocations': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'burstStartLocations',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualDataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualDataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrieveBurstStopLocations': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'burstStopLocations',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualDataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualDataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrieveIQRate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'iqRate',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrieveIQRateAllWaveforms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'script',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'iqRate',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrieveMinimumPAPRAllWaveforms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'script',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrievePAPR': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrieveRFBlankingMarkerPositions': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'rfBlankingMarkerPositions',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualDataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualDataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGRetrieveWaveformSize': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'waveformSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGStoreBurstStartLocations': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'burstStartLocations',
                'size': {
                    'mechanism': 'len',
                    'value': 'dataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGStoreBurstStopLocations': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'burstStopLocations',
                'size': {
                    'mechanism': 'len',
                    'value': 'dataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RFSGStoreIQRate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'iqRate',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGStorePAPR': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'papr',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGStoreRFBlankingMarkerPositions': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'rfsgHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'rfBlankingMarkerPositions',
                'size': {
                    'mechanism': 'len',
                    'value': 'dataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ReadBurstStartLocationsFromFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'burstStartLocations',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualDataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualDataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ReadBurstStopLocationsFromFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'burstStopLocations',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataArraySize',
                    'value_twist': 'actualDataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualDataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ReadWaveformFromFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'offset',
                'type': 'int64'
            },
            {
                'direction': 'in',
                'name': 'count',
                'type': 'int64'
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
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'waveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'waveformSize',
                    'value_twist': 'actualNumWaveformSamples'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'waveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumWaveformSamples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'iqRate',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'headroom',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'eof',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ReadWaveformFromFileInterleavedIQ': {
        'cname': 'niWLANG_ReadWaveformFromFile',
        'parameters': [
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'offset',
                'type': 'int64'
            },
            {
                'direction': 'in',
                'name': 'count',
                'type': 'int64'
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
                'name': 'waveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'waveformSize',
                    'value_twist': 'actualNumWaveformSamples'
                },
                'type': 'float64[]',
                'value_converted_to_c_representation': 'reinterpret_cast<NIComplexNumber*>(waveform)'
            },
            {
                'direction': 'in',
                'name': 'waveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualNumWaveformSamples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'iqRate',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'headroom',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'eof',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetSession': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            }
        ],
        'returns': 'int32'
    },
    'SaveConfigurationToFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'FileOperationMode',
                'name': 'fileOperation',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetMappingMatrix': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'mappingMatrix',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'matrix_size'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixRows',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixColumns',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetMappingMatrixInterleavedIQ': {
        'cname': 'niWLANG_SetMappingMatrix',
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'mappingMatrix',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'matrix_size'
                },
                'type': 'float64[]',
                'value_converted_to_c_representation': 'reinterpret_cast<NIComplexNumber*>(mappingMatrix)'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixRows',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'numMappingMatrixColumns',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetOFDMPacketExtensionThresholds': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'ppet16',
                'size': {
                    'mechanism': 'len',
                    'value': 'ppet16ArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'ppet8',
                'size': {
                    'mechanism': 'len',
                    'value': 'ppet8ArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfSpaceTimeStreams',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSpaceTimeStreamsArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'ruSize',
                'size': {
                    'mechanism': 'len',
                    'value': 'ruArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'ppet16ArraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'ppet8ArraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'numberOfSpaceTimeStreamsArraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'ruArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetScalarAttributeF64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SetScalarAttributeI32': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetScalarAttributeI64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'SetVectorAttributeF64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'dataArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetVectorAttributeI32': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niWLANGenerationSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxWLANGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'data',
                'size': {
                    'mechanism': 'len',
                    'value': 'dataArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    }
}
