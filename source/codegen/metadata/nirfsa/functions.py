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
    'CheckAcquisitionStatus': {
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
        'cname': 'niRFSA_close',
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
    'ConfigureAcquisitionType': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AcquisitionType',
                'name': 'acquisitionType',
                'type': 'ViInt32'
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
    'ConfigureDigitalEdgeAdvanceTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeTriggerSource',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdge',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeRefTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeTriggerSource',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdge',
                'name': 'edge',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'ViInt64'
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
                'enum': 'DigitalEdgeTriggerSource',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdge',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureIQCarrierFrequency': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'carrierFrequency',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureIQPowerEdgeRefTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'hardcoded_value': '"0"',
                'include_in_proto': False,
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'AnalogSlope',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureIQRate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'iqRate',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureNumberOfRecords': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfRecordsIsFinite',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'numberOfRecords',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureNumberOfSamples': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamplesIsFinite',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'samplesPerRecord',
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
                'enum': 'PxiChassisClk10Source',
                'name': 'pxiClk10Source',
                'type': 'ViConstString'
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
                'name': 'clockSource',
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
    'ConfigureReferenceLevel': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'referenceLevel',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureResolutionBandwidth': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'resolutionBandwidth',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeAdvanceTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeRefTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeStartTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSpectrumFrequencyCenterSpan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'centerFrequency',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'span',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSpectrumFrequencyStartStop': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'startFrequency',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'stopFrequency',
                'type': 'ViReal64'
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
                'name': 'numberOfListAttributes',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'listAttributeIds',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfListAttributes'
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
                'enum': 'SparameterOrientation',
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
                'enum': 'SparameterOrientation',
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
    'DisableAdvanceTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableRefTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
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
    'EnableSessionAccess': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'enable',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorMessage': {
        'cname': 'niRFSA_error_message',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'statusCode',
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
        'cname': 'niRFSA_error_query',
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
                'enum': 'Signal',
                'name': 'signal',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'signalIdentifier',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'ExportTerminal',
                'name': 'outputTerminal',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchIQMultiRecordComplexF32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'startingRecord',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfRecords',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumberF32',
                'name': 'data',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'numberOfSamples * numberOfRecords'
                },
                'type': 'NIComplexNumberF32_struct[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfRecords'
                },
                'type': 'struct niRFSA_wfmInfo_struct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchIQMultiRecordComplexF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'startingRecord',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfRecords',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'data',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'numberOfSamples * numberOfRecords'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfRecords'
                },
                'type': 'struct niRFSA_wfmInfo_struct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchIQMultiRecordComplexI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'startingRecord',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfRecords',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexI16',
                'name': 'data',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'numberOfSamples * numberOfRecords'
                },
                'type': 'NIComplexI16_struct[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfRecords'
                },
                'type': 'struct niRFSA_wfmInfo_struct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchIQSingleRecordComplexF32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'recordNumber',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumberF32',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexNumberF32_struct[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'WaveformInfo',
                'name': 'wfmInfo',
                'type': 'struct niRFSA_wfmInfo_struct'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchIQSingleRecordComplexF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'recordNumber',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'WaveformInfo',
                'name': 'wfmInfo',
                'type': 'struct niRFSA_wfmInfo_struct'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchIQSingleRecordComplexI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'recordNumber',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'numberOfSamples',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexI16',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSamples'
                },
                'type': 'NIComplexI16_struct[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'WaveformInfo',
                'name': 'wfmInfo',
                'type': 'struct niRFSA_wfmInfo_struct'
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
    'GetCalUserDefinedInfo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'info',
                'size': {
                    'mechanism': 'fixed',
                    'value': 2048
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCalUserDefinedInfoMaxSize': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'infoSize',
                'type': 'ViInt32'
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
    'GetDeviceResponse': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DeviceResponse',
                'name': 'responseType',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'frequencies',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'magnitudeResponse',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'phaseResponse',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'numberOfFrequencies',
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
    'GetExtCalLastDateAndTime': {
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
            }
        ],
        'returns': 'ViStatus'
    },
    'GetExtCalLastTemp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'temperature',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
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
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetFetchBacklog': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'recordNumber',
                'type': 'ViInt64'
            },
            {
                'direction': 'out',
                'name': 'backlog',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetFrequencyResponse': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'frequencies',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'magnitudeResponse',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'phaseResponse',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'numberOfFrequencies',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetNormalizationCoefficients': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated CoefficientInfo',
                'name': 'coefficientInfo',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'numberOfCoefficientSets'
                },
                'type': 'struct niRFSA_coefficientInfo_struct[]'
            },
            {
                'direction': 'out',
                'name': 'numberOfCoefficientSets',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetNumberOfSpectralLines': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'numberOfSpectralLines',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetRelayName': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'index',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'name',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'tags': [
                        'strlen-bug'
                    ],
                    'value': 'bufferSize',
                    'value_twist': 'bufferSize'
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'out',
                'name': 'bufferSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetRelayOperationsCount': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'operationsCount',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'bufferSize'
                },
                'type': 'ViInt32[]'
            },
            {
                'direction': 'out',
                'name': 'bufferSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetScalingCoefficients': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated CoefficientInfo',
                'name': 'coefficientInfo',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'numberOfCoefficientSets'
                },
                'type': 'struct niRFSA_coefficientInfo_struct[]'
            },
            {
                'direction': 'out',
                'name': 'numberOfCoefficientSets',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSelfCalLastDateAndTime': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'selfCalibrationStep',
                'type': 'ViInt64'
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
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSelfCalLastTemp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'selfCalibrationStep',
                'type': 'ViInt64'
            },
            {
                'direction': 'out',
                'name': 'temp',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSpectralInfoForSMT': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.SmtSpectrumInfo',
                'name': 'spectrumInfo',
                'type': 'SmtSpectrumInfo_struct'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetStreamEndpointHandle': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'streamEndpoint',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'writerHandle',
                'type': 'ViUInt32'
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
                'enum': 'Signal',
                'name': 'signal',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
                    'mechanism': 'passed-in',
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
    'Init': {
        'cname': 'niRFSA_init',
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
                'name': 'reset',
                'type': 'ViBoolean'
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
                'name': 'reset',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'optionString',
                'type': 'ViConstString'
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
    'IsSelfCalValid': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'selfCalValid',
                'type': 'ViBoolean'
            },
            {
                'bitfield_as_enum_array': 'SelfCalibrateSteps',
                'direction': 'out',
                'name': 'validSteps',
                'type': 'ViInt64'
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
    'ReadIQSingleRecordComplexF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'dataArraySize'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'ViInt64'
            },
            {
                'direction': 'out',
                'grpc_type': 'WaveformInfo',
                'name': 'wfmInfo',
                'type': 'struct niRFSA_wfmInfo_struct'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadPowerSpectrumF32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'name': 'powerSpectrumData',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'dataArraySize'
                },
                'type': 'ViReal32[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'SpectrumInfo',
                'name': 'spectrumInfo',
                'type': 'struct niRFSA_spectrumInfo_struct'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadPowerSpectrumF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'out',
                'name': 'powerSpectrumData',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'dataArraySize'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'in',
                'name': 'dataArraySize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'SpectrumInfo',
                'name': 'spectrumInfo',
                'type': 'struct niRFSA_spectrumInfo_struct'
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset': {
        'cname': 'niRFSA_reset',
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
        'cname': 'niRFSA_revision_query',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'driverRev',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'out',
                'name': 'instrRev',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
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
    'SelfCalibrate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'SelfCalibrateSteps',
                'name': 'stepsToOmit',
                'type': 'ViInt64'
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
                'enum': 'SelfCalibrateSteps',
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
                'name': 'minReferenceLevel',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'maxReferenceLevel',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfTest': {
        'cname': 'niRFSA_self_test',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'testResult',
                'type': 'ViInt16'
            },
            {
                'direction': 'out',
                'name': 'testMessage',
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
                'enum': 'Signal',
                'name': 'trigger',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
                'name': 'attributeId',
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
    'SetCalUserDefinedInfo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'info',
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
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'bufferSize'
                },
                'type': 'ViInt8[]'
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
    }
}
