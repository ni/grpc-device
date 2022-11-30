# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 23.0.0d87
functions = {
    'Abort': {
        'codegen_method': 'public',
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
    'AcquisitionStatus': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'acquisitionStatus',
                'direction': 'out',
                'enum': 'AcquisitionStatus',
                'grpc_type': 'sint32',
                'name': 'acquisitionStatus',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ActualMeasWfmSize': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'arrayMeasFunction',
                'direction': 'in',
                'enum': 'ArrayMeasurement',
                'grpc_type': 'sint32',
                'name': 'arrayMeasFunction',
                'type': 'ViInt32'
            },
            {
                'cppName': 'measWaveformSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'measWaveformSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ActualNumWfms': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numWfms',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'numWfms',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ActualRecordLength': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'recordLength',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'recordLength',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'AddWaveformProcessing': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'measFunction',
                'direction': 'in',
                'enum': 'ArrayMeasurement',
                'grpc_type': 'sint32',
                'name': 'measFunction',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'AdjustSampleClockRelativeDelay': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'AutoSetup': {
        'codegen_method': 'public',
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
    'CableSenseSignalStart': {
        'codegen_method': 'public',
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
    'CableSenseSignalStop': {
        'codegen_method': 'public',
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
    'CalFetchDate': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'whichOne',
                'direction': 'in',
                'enum': 'CalibrationTypes',
                'grpc_type': 'sint32',
                'name': 'whichOne',
                'type': 'ViInt32'
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
            }
        ],
        'returns': 'ViStatus'
    },
    'CalFetchTemperature': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'whichOne',
                'direction': 'in',
                'enum': 'CalibrationTypes',
                'grpc_type': 'sint32',
                'name': 'whichOne',
                'type': 'ViInt32'
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
    'CalSelfCalibrate': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'option',
                'direction': 'in',
                'enum': 'Option',
                'grpc_type': 'sint32',
                'name': 'option',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViBoolean': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViInt32': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'enum': 'NiScopeInt32AttributeValues',
                'grpc_field_number': '5',
                'grpc_raw_field_number': '4',
                'grpc_type': 'sint32',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViInt64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'value_raw',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViReal64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'enum': 'NiScopeReal64AttributeValues',
                'grpc_field_number': '5',
                'grpc_mapped_field_number': '6',
                'grpc_raw_field_number': '4',
                'grpc_type': 'double',
                'mapped-enum': 'NiScopeReal64AttributeValuesMapped',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViSession': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'string',
                'mapped-enum': 'NiScopeStringAttributeValuesMapped',
                'name': 'value',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearWaveformMeasurementStats': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'clearableMeasurementFunction',
                'direction': 'in',
                'enum': 'ClearableMeasurement',
                'grpc_type': 'sint32',
                'name': 'clearableMeasurementFunction',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearWaveformProcessing': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Close': {
        'cname': 'niScope_close',
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
    'ConfigureAcquisition': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'acquisitionType',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'acquisitionType',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureChanCharacteristics': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'inputImpedance',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'inputImpedance',
                'type': 'ViReal64'
            },
            {
                'cppName': 'maxInputFrequency',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'maxInputFrequency',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureClock': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'inputClockSource',
                'direction': 'in',
                'grpc_mapped_field_number': '6',
                'grpc_raw_field_number': '2',
                'grpc_type': 'string',
                'mapped-enum': 'ClockingTerminalValues',
                'name': 'inputClockSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'outputClockSource',
                'direction': 'in',
                'grpc_mapped_field_number': '7',
                'grpc_raw_field_number': '3',
                'grpc_type': 'string',
                'mapped-enum': 'ClockingTerminalValues',
                'name': 'outputClockSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'clockSyncPulseSource',
                'direction': 'in',
                'grpc_mapped_field_number': '8',
                'grpc_raw_field_number': '4',
                'grpc_type': 'string',
                'mapped-enum': 'ClockingTerminalValues',
                'name': 'clockSyncPulseSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'masterEnabled',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'masterEnabled',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureEqualizationFilterCoefficients': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numberOfCoefficients',
                'determine_size_from': [
                    'coefficients'
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
                'cppName': 'coefficients',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'coefficients',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfCoefficients'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureHorizontalTiming': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'minSampleRate',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'minSampleRate',
                'type': 'ViReal64'
            },
            {
                'cppName': 'minNumPts',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'minNumPts',
                'type': 'ViInt32'
            },
            {
                'cppName': 'refPosition',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'refPosition',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numRecords',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numRecords',
                'type': 'ViInt32'
            },
            {
                'cppName': 'enforceRealtime',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'enforceRealtime',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerDigital': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'slope',
                'direction': 'in',
                'enum': 'TriggerSlope',
                'grpc_type': 'sint32',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerEdge': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'level',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'cppName': 'slope',
                'direction': 'in',
                'enum': 'TriggerSlope',
                'grpc_type': 'sint32',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerCoupling',
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'grpc_type': 'sint32',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerGlitch': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'level',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'cppName': 'width',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'width',
                'type': 'ViReal64'
            },
            {
                'cppName': 'polarity',
                'direction': 'in',
                'enum': 'GlitchPolarity',
                'grpc_type': 'sint32',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'cppName': 'glitchCondition',
                'direction': 'in',
                'enum': 'GlitchCondition',
                'grpc_type': 'sint32',
                'name': 'glitchCondition',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerCoupling',
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'grpc_type': 'sint32',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerHysteresis': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'level',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'cppName': 'hysteresis',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'hysteresis',
                'type': 'ViReal64'
            },
            {
                'cppName': 'slope',
                'direction': 'in',
                'enum': 'TriggerSlope',
                'grpc_type': 'sint32',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerCoupling',
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'grpc_type': 'sint32',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerImmediate': {
        'codegen_method': 'public',
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
    'ConfigureTriggerRunt': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'lowThreshold',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'lowThreshold',
                'type': 'ViReal64'
            },
            {
                'cppName': 'highThreshold',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'highThreshold',
                'type': 'ViReal64'
            },
            {
                'cppName': 'polarity',
                'direction': 'in',
                'enum': 'RuntPolarity',
                'grpc_type': 'sint32',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerCoupling',
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'grpc_type': 'sint32',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerSoftware': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerVideo': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'enableDcRestore',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'enableDcRestore',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'signalFormat',
                'direction': 'in',
                'enum': 'VideoSignalFormat',
                'grpc_type': 'sint32',
                'name': 'signalFormat',
                'type': 'ViInt32'
            },
            {
                'cppName': 'eventParameter',
                'direction': 'in',
                'enum': 'VideoTriggerEvent',
                'grpc_type': 'sint32',
                'name': 'event',
                'type': 'ViInt32'
            },
            {
                'cppName': 'lineNumber',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'lineNumber',
                'type': 'ViInt32'
            },
            {
                'cppName': 'polarity',
                'direction': 'in',
                'enum': 'VideoPolarity',
                'grpc_type': 'sint32',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerCoupling',
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'grpc_type': 'sint32',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerWidth': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'level',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'cppName': 'lowThreshold',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'lowThreshold',
                'type': 'ViReal64'
            },
            {
                'cppName': 'highThreshold',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'highThreshold',
                'type': 'ViReal64'
            },
            {
                'cppName': 'polarity',
                'direction': 'in',
                'enum': 'WidthPolarity',
                'grpc_type': 'sint32',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'cppName': 'condition',
                'direction': 'in',
                'enum': 'WidthCondition',
                'grpc_type': 'sint32',
                'name': 'condition',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerCoupling',
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'grpc_type': 'sint32',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerWindow': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'cppName': 'lowLevel',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'lowLevel',
                'type': 'ViReal64'
            },
            {
                'cppName': 'highLevel',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'highLevel',
                'type': 'ViReal64'
            },
            {
                'cppName': 'windowMode',
                'direction': 'in',
                'enum': 'TriggerWindowMode',
                'grpc_type': 'sint32',
                'name': 'windowMode',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerCoupling',
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'grpc_type': 'sint32',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'holdoff',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'cppName': 'delay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureVertical': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'range',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'range',
                'type': 'ViReal64'
            },
            {
                'cppName': 'offset',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'offset',
                'type': 'ViReal64'
            },
            {
                'cppName': 'coupling',
                'direction': 'in',
                'enum': 'VerticalCoupling',
                'grpc_type': 'sint32',
                'name': 'coupling',
                'type': 'ViInt32'
            },
            {
                'cppName': 'probeAttenuation',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'probeAttenuation',
                'type': 'ViReal64'
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
    'Disable': {
        'codegen_method': 'public',
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
    'ErrorHandler': {
        'cname': 'niScope_errorHandler',
        'codegen_method': 'public',
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
                'cppName': 'errorSource',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'errorSource',
                'size': {
                    'mechanism': 'fixed',
                    'value': 55
                },
                'type': 'ViChar[]'
            },
            {
                'cppName': 'errorDescription',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'fixed',
                    'value': 642
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationBuffer': {
        'codegen_method': 'public',
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
                'grpc_type': 'bytes',
                'name': 'configuration',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationFile': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
                'enum': 'ExportableSignals',
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
                'mapped-enum': 'ClockingTerminalValues',
                'name': 'outputTerminal',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Fetch': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveform',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'waveform',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchArrayMeasurement': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'arrayMeasFunction',
                'direction': 'in',
                'enum': 'ArrayMeasurement',
                'grpc_type': 'sint32',
                'name': 'arrayMeasFunction',
                'type': 'ViInt32'
            },
            {
                'cppName': 'measWfmSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'name': 'measWfmSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'measWfm',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'measWfm',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(measurement_waveform_size * actual_num_wfms)'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary16': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveform',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'waveform',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViInt16[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary32': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveform',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'waveform',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary8': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveform',
                'direction': 'out',
                'grpc_type': 'bytes',
                'name': 'waveform',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViInt8[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchComplex': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'wfm',
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'wfm',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'struct NIComplexNumber_struct[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchComplexBinary16': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'wfm',
                'direction': 'out',
                'grpc_type': 'repeated nidevice_grpc.NIComplexI16',
                'name': 'wfm',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'struct NIComplexI16_struct[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchMeasurement': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'scalarMeasFunction',
                'direction': 'in',
                'enum': 'ScalarMeasurement',
                'grpc_type': 'sint32',
                'name': 'scalarMeasFunction',
                'type': 'ViInt32'
            },
            {
                'cppName': 'result',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'result',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchMeasurementStats': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'scalarMeasFunction',
                'direction': 'in',
                'enum': 'ScalarMeasurement',
                'grpc_type': 'sint32',
                'name': 'scalarMeasFunction',
                'type': 'ViInt32'
            },
            {
                'cppName': 'result',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'result',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'mean',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'mean',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'stdev',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'stdev',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'min',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'min',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'max',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'max',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'numInStats',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'numInStats',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViBoolean': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt32': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'value',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViSession': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'bufSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'string',
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
        'codegen_method': 'public',
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
    'GetChannelNameFromString': {
        'codegen_method': 'public',
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
                'grpc_type': 'string',
                'name': 'index',
                'type': 'ViConstString'
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
                'cppName': 'name',
                'direction': 'out',
                'grpc_type': 'string',
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
    'GetEqualizationFilterCoefficients': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channel',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numberOfCoefficients',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfCoefficients',
                'type': 'ViInt32'
            },
            {
                'cppName': 'coefficients',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'coefficients',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfCoefficients'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetError': {
        'codegen_method': 'public',
        'is_error_handling': True,
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
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'description',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'description',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetErrorMessage': {
        'codegen_method': 'public',
        'is_error_handling': True,
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
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetFrequencyResponse': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channel',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel',
                'type': 'ViConstString'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'frequencies',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'frequencies',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'bufferSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'amplitudes',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'amplitudes',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'bufferSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'phases',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'phases',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'bufferSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'numberOfFrequencies',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'numberOfFrequencies',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetNormalizationCoefficients': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
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
                'cppName': 'coefficientInfo',
                'direction': 'out',
                'grpc_type': 'repeated CoefficientInfo',
                'name': 'coefficientInfo',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfCoefficientSets'
                },
                'type': 'struct niScope_coefficientInfo[]'
            },
            {
                'cppName': 'numberOfCoefficientSets',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'numberOfCoefficientSets',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetScalingCoefficients': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
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
                'cppName': 'coefficientInfo',
                'direction': 'out',
                'grpc_type': 'repeated CoefficientInfo',
                'name': 'coefficientInfo',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfCoefficientSets'
                },
                'type': 'struct niScope_coefficientInfo[]'
            },
            {
                'cppName': 'numberOfCoefficientSets',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'numberOfCoefficientSets',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetStreamEndpointHandle': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'streamName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'streamName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'writerHandle',
                'direction': 'out',
                'grpc_type': 'uint32',
                'name': 'writerHandle',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationBuffer': {
        'codegen_method': 'public',
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
                'grpc_type': 'bytes',
                'name': 'configuration',
                'size': {
                    'mechanism': 'len',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationFile': {
        'codegen_method': 'public',
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
        'cname': 'niScope_init',
        'codegen_method': 'public',
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
                'get_last_error': 'deprecated',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            },
            {
                'cppName': 'initializationBehavior',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.SessionInitializationBehavior',
                'name': 'initializationBehavior',
                'proto_only': True,
                'type': 'ViInt32'
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
        'codegen_method': 'public',
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
                'get_last_error': 'deprecated',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            },
            {
                'cppName': 'initializationBehavior',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.SessionInitializationBehavior',
                'name': 'initializationBehavior',
                'proto_only': True,
                'type': 'ViInt32'
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
    'InitiateAcquisition': {
        'codegen_method': 'public',
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
    'ProbeCompensationSignalStart': {
        'codegen_method': 'public',
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
    'ProbeCompensationSignalStop': {
        'codegen_method': 'public',
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
    'Read': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'numSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveform',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'waveform',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'wfmInfo',
                'direction': 'out',
                'grpc_type': 'repeated WaveformInfo',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadMeasurement': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'scalarMeasFunction',
                'direction': 'in',
                'enum': 'ScalarMeasurement',
                'grpc_type': 'sint32',
                'name': 'scalarMeasFunction',
                'type': 'ViInt32'
            },
            {
                'cppName': 'result',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'result',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset': {
        'cname': 'niScope_reset',
        'codegen_method': 'public',
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
    'ResetDevice': {
        'codegen_method': 'public',
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
        'cname': 'niScope_revision_query',
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'driverRevision',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'driverRevision',
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
    'SampleMode': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sampleMode',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'sampleMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SampleRate': {
        'codegen_method': 'public',
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
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'sampleRate',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfTest': {
        'cname': 'niScope_self_test',
        'codegen_method': 'public',
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
    'SendSoftwareTriggerEdge': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'whichTrigger',
                'direction': 'in',
                'enum': 'WhichTrigger',
                'grpc_type': 'sint32',
                'name': 'whichTrigger',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViBoolean': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt32': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'enum': 'NiScopeInt32AttributeValues',
                'grpc_field_number': '5',
                'grpc_raw_field_number': '4',
                'grpc_type': 'sint32',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'value_raw',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'enum': 'NiScopeReal64AttributeValues',
                'grpc_field_number': '5',
                'grpc_mapped_field_number': '6',
                'grpc_raw_field_number': '4',
                'grpc_type': 'double',
                'mapped-enum': 'NiScopeReal64AttributeValuesMapped',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViSession': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiScopeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'string',
                'mapped-enum': 'NiScopeStringAttributeValuesMapped',
                'name': 'value',
                'type': 'ViConstString'
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
    }
}
