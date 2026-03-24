functions = {
    'CarrierFrequencyToChannelNumber': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'carrierFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'standard',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'channelNumber',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ChannelNumberToCarrierFrequency': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'channelNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'standard',
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
                'type': 'niBTSGSession'
            }
        ],
        'returns': 'int32'
    },
    'CreateAndWriteWaveformsToFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niBTSGSession'
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
    'CreateWaveformComplexF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
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
                    'value_twist': 'actualWaveformSize'
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
                'name': 'actualWaveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'generationDone',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateWaveformComplexF64InterleavedIQ': {
        'cname': 'niBTSG_CreateWaveformComplexF64',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
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
                    'value_twist': 'actualWaveformSize'
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
                'name': 'actualWaveformSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'generationDone',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeString': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attributeValue',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualStringSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualStringSize',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'errorMessage',
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
    'GetScalarAttributeF64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'reset',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'out',
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
    'RFSGCreateAndDownloadWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niBTSGSession'
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
    'RFSGRetrieveHeadroom': {
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
                'name': 'headroom',
                'type': 'float64'
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
    'RFSGRetrieveMinimumHeadroomAllWaveforms': {
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
                'name': 'headroom',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'RFSGStoreHeadroom': {
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
                'name': 'headroom',
                'type': 'float64'
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
                'grpc_type': 'nidevice_grpc.NIComplexNumber',
                'name': 'waveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'waveformSize',
                    'value_twist': 'actualNumWaveformSamples'
                },
                'type': 'NIComplexNumber_struct'
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
                'name': 'eof',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ReadWaveformFromFileInterleavedIQ': {
        'cname': 'niBTSG_ReadWaveformFromFile',
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
                'type': 'float64',
                'value_converted_to_c_representation': 'reinterpret_cast<NIComplexNumber>(waveform)'
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
                'name': 'eof',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
                'name': 'attributeID',
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
                'type': 'niBTSGSession'
            }
        ],
        'returns': 'int32'
    },
    'SaveConfigurationToFile': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'operation',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAntennaRelativePhaseAndAmplitude': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'relativeAmplitudeDb',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'relativePhaseDeg',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeString': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'session',
                'name': 'session',
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attributeValue',
                'type': 'char[]'
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
                'type': 'niBTSGSession'
            },
            {
                'direction': 'in',
                'name': 'channelString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'grpc_type': 'NiRFmxBluetoothGenAttribute',
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
