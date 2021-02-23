# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 20.5.0d7
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
    'AcquisitionStatus': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'enum': 'AcquisitionStatus',
                'name': 'acquisitionStatus',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ActualMeasWfmSize': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'ArrayMeasurement',
                'name': 'arrayMeasFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'measWaveformSize',
                'type': 'ViInt32'
            }
        ],
        'render_in_session_base': True,
        'returns': 'ViStatus'
    },
    'ActualNumWfms': {
        'codegen_method': 'private',
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
                'name': 'numWfms',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'AddWaveformProcessing': {
        'codegen_method': 'public',
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
                'enum': 'ArrayMeasurement',
                'name': 'measFunction',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'AutoSetup': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'CalFetchDate': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'CalibrationTypes',
                'name': 'whichOne',
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
            }
        ],
        'returns': 'ViStatus'
    },
    'CalFetchTemperature': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'whichOne',
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
    'CalSelfCalibrate': {
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
                'default_value': 'Option.SELF_CALIBRATE_ALL_CHANNELS',
                'direction': 'in',
                'enum': 'Option',
                'name': 'option',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearWaveformMeasurementStats': {
        'codegen_method': 'public',
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
                'default_value': 'ClearableMeasurement.ALL_MEASUREMENTS',
                'direction': 'in',
                'enum': 'ClearableMeasurement',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
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
    'ConfigureChanCharacteristics': {
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
                'name': 'inputImpedance',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'maxInputFrequency',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureEqualizationFilterCoefficients': {
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
                'determine_size_from': 'coefficients',
                'name': 'numberOfCoefficients',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'minSampleRate',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'minNumPts',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'refPosition',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numRecords',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'enforceRealtime',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureRefLevels': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'default_value': 10.0,
                'direction': 'in',
                'name': 'low',
                'type': 'ViReal64'
            },
            {
                'default_value': 50.0,
                'direction': 'in',
                'name': 'mid',
                'type': 'ViReal64'
            },
            {
                'default_value': 90.0,
                'direction': 'in',
                'name': 'high',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerDigital': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'default_value': 'TriggerSlope.POSITIVE',
                'direction': 'in',
                'enum': 'TriggerSlope',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerEdge': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'default_value': 'TriggerSlope.POSITIVE',
                'direction': 'in',
                'enum': 'TriggerSlope',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerHysteresis': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'hysteresis',
                'type': 'ViReal64'
            },
            {
                'default_value': 'TriggerSlope.POSITIVE',
                'direction': 'in',
                'enum': 'TriggerSlope',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerImmediate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerSoftware': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerVideo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'default_value': False,
                'direction': 'in',
                'name': 'enableDcRestore',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'enum': 'VideoSignalFormat',
                'name': 'signalFormat',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'VideoTriggerEvent',
                'name': 'event',
                'type': 'ViInt32'
            },
            {
                'default_value': 1,
                'direction': 'in',
                'name': 'lineNumber',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'VideoPolarity',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerWindow': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'lowLevel',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'highLevel',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'TriggerWindowMode',
                'name': 'windowMode',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'default_value': 'hightime.timedelta(seconds=0.0)',
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureVertical': {
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
                'name': 'range',
                'type': 'ViReal64'
            },
            {
                'default_value': 0.0,
                'direction': 'in',
                'name': 'offset',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'VerticalCoupling',
                'name': 'coupling',
                'type': 'ViInt32'
            },
            {
                'default_value': 1.0,
                'direction': 'in',
                'name': 'probeAttenuation',
                'type': 'ViReal64'
            },
            {
                'default_value': True,
                'direction': 'in',
                'name': 'enabled',
                'type': 'ViBoolean'
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
    'ExportAttributeConfigurationBuffer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'configuration',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]',
                'use_array': True
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
        'codegen_method': 'public',
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
                'default_value': 'hightime.timedelta(seconds=5.0)',
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'python-code',
                    'value': '(num_samples * self._actual_num_wfms())'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchArrayMeasurement': {
        'codegen_method': 'public',
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
                'default_value': 'hightime.timedelta(seconds=5.0)',
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'ArrayMeasurement',
                'name': 'arrayMeasFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'measurementWaveformSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'measWfm',
                'size': {
                    'mechanism': 'python-code',
                    'value': '(measurement_waveform_size * self._actual_num_wfms())'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary16': {
        'codegen_method': 'public',
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
                'default_value': 'hightime.timedelta(seconds=5.0)',
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'python-code',
                    'value': '(num_samples * self._actual_num_wfms())'
                },
                'type': 'ViInt16[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary32': {
        'codegen_method': 'public',
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
                'default_value': 'hightime.timedelta(seconds=5.0)',
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'python-code',
                    'value': '(num_samples * self._actual_num_wfms())'
                },
                'type': 'ViInt32[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary8': {
        'codegen_method': 'public',
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
                'default_value': 'hightime.timedelta(seconds=5.0)',
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'python-code',
                    'value': '(num_samples * self._actual_num_wfms())'
                },
                'type': 'ViInt8[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'struct niScope_wfmInfo[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchMeasurementStats': {
        'codegen_method': 'public',
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
                'default_value': 'hightime.timedelta(seconds=5.0)',
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'ScalarMeasurement',
                'name': 'scalarMeasFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'result',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'mean',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'stdev',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'min',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'max',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'numInStats',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
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
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
    'GetAttributeViString': {
        'codegen_method': 'public',
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
    'GetEqualizationFilterCoefficients': {
        'codegen_method': 'public',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfCoefficients',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
        'codegen_method': 'private',
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
        'use_session_lock': False
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
                'determine_size_from': 'configuration',
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
    'InitWithOptions': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'default_value': False,
                'direction': 'in',
                'name': 'idQuery',
                'type': 'ViBoolean'
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
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'InitiateAcquisition': {
        'codegen_method': 'public',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'LockSession': {
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
        'render_in_session_base': True,
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'ProbeCompensationSignalStart': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ProbeCompensationSignalStop': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Read': {
        'codegen_method': 'public',
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
                'default_value': 'hightime.timedelta(seconds=5.0)',
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'size': {
                    'mechanism': 'python-code',
                    'value': '(num_samples * self._actual_num_wfms())'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'python-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'struct niScope_wfmInfo[]'
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
    'SendSoftwareTriggerEdge': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'WhichTrigger',
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
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
    'SetAttributeViString': {
        'codegen_method': 'public',
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
    'UnlockSession': {
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
        'render_in_session_base': True,
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'close': {
        'codegen_method': 'public',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'error_message': {
        'codegen_method': 'private',
        'is_error_handling': True,
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
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'reset': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'self_test': {
        'codegen_method': 'public',
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
    }
}
