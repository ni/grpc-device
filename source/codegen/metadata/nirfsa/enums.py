# -*- coding: utf-8 -*-
# This file is generated from NI-RFSA API metadata version 27.0.0d9999
enums = {
    'AcquisitionType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'IQ',
                'value': 100
            },
            {
                'name': 'SPECTRUM',
                'value': 101
            }
        ]
    },
    'AnalogSlope': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RISING_SLOPE',
                'value': 1000
            },
            {
                'name': 'FALLING_SLOPE',
                'value': 1001
            }
        ]
    },
    'AveragingMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NO_AVERAGING',
                'value': 400
            },
            {
                'name': 'RMS_AVERAGING',
                'value': 401
            },
            {
                'name': 'VECTOR_AVERAGING',
                'value': 402
            },
            {
                'name': 'PEAK_HOLD_AVERAGING',
                'value': 403
            },
            {
                'name': 'MIN_HOLD_AVERAGING',
                'value': 404
            },
            {
                'name': 'SCALAR_AVERAGING',
                'value': 405
            },
            {
                'name': 'LOG_AVERAGING',
                'value': 406
            }
        ]
    },
    'BandwidthType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RBW_3_DB',
                'value': 300
            },
            {
                'name': 'RBW_6_DB',
                'value': 301
            },
            {
                'name': 'RBW_BIN_WIDTH',
                'value': 302
            },
            {
                'name': 'RBW_ENBW',
                'value': 303
            }
        ]
    },
    'CalIfAttenTableSelection': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'EXT_CAL_IF_ATTENUATION_TABLE_STANDARD',
                'value': 2900
            },
            {
                'name': 'EXT_CAL_IF_ATTENUATION_TABLE_ACPR',
                'value': 2901
            }
        ]
    },
    'CalIfFilterSelection': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_1',
                'value': 2100
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_2',
                'value': 2101
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_3',
                'value': 2102
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_4',
                'value': 2103
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_5',
                'value': 2104
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_6',
                'value': 2105
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_7',
                'value': 2106
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_8',
                'value': 2107
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_9',
                'value': 2108
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_10',
                'value': 2109
            },
            {
                'name': 'EXT_CAL_IF_FILTER_PATH_11',
                'value': 2110
            }
        ]
    },
    'CalToneMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLED',
                'value': 2700
            },
            {
                'name': 'LOWBAND_RF',
                'value': 2701
            },
            {
                'name': 'HIGHBAND_RF',
                'value': 2702
            },
            {
                'name': 'HIGHBAND_IF',
                'value': 2703
            },
            {
                'name': 'LOWBAND_RF_WITHOUT_ALC',
                'value': 2704
            },
            {
                'name': 'COMB_GENERATOR',
                'value': 2705
            }
        ]
    },
    'ChannelCoupling': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'AC',
                'value': 3001
            },
            {
                'name': 'DC',
                'value': 3002
            }
        ]
    },
    'ConditioningCalToneMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLED',
                'value': 2700
            },
            {
                'name': 'LOWBAND_RF',
                'value': 2701
            },
            {
                'name': 'HIGHBAND_RF',
                'value': 2702
            }
        ]
    },
    'DeembeddingType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 3900
            },
            {
                'name': 'SCALAR',
                'value': 3901
            },
            {
                'name': 'VECTOR',
                'value': 3902
            },
            {
                'name': 'AMPLITUDE_FLATNESS',
                'value': 3903
            }
        ]
    },
    'DeviceResponse': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DOWNCONVERTER_IF_RESPONSE',
                'value': 2800
            },
            {
                'name': 'DOWNCONVERTER_RF_RESPONSE',
                'value': 2801
            },
            {
                'name': 'DOWNCONVERTER_COMBINED_RESPONSE',
                'value': 2802
            },
            {
                'name': 'VSA_IF_RESPONSE',
                'value': 2803
            },
            {
                'name': 'VSA_COMBINED_RESPONSE',
                'value': 2804
            }
        ]
    },
    'DigitalEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RISING_EDGE',
                'value': 900
            },
            {
                'name': 'FALLING_EDGE',
                'value': 901
            }
        ]
    },
    'DigitalEdgeTriggerSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'RTSI0',
                'value': 'NIRFSA_VAL_PXI_TRIG0_STR'
            },
            {
                'name': 'RTSI1',
                'value': 'NIRFSA_VAL_PXI_TRIG1_STR'
            },
            {
                'name': 'RTSI2',
                'value': 'NIRFSA_VAL_PXI_TRIG2_STR'
            },
            {
                'name': 'RTSI3',
                'value': 'NIRFSA_VAL_PXI_TRIG3_STR'
            },
            {
                'name': 'RTSI4',
                'value': 'NIRFSA_VAL_PXI_TRIG4_STR'
            },
            {
                'name': 'RTSI5',
                'value': 'NIRFSA_VAL_PXI_TRIG5_STR'
            },
            {
                'name': 'RTSI6',
                'value': 'NIRFSA_VAL_PXI_TRIG6_STR'
            },
            {
                'name': 'RTSI7',
                'value': 'NIRFSA_VAL_PXI_TRIG7_STR'
            },
            {
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            }
        ]
    },
    'DigitizerSampleClockOutTerminal': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NONE',
                'value': 'None'
            },
            {
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            }
        ]
    },
    'DigitizerSampleClockTimebaseSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'CLK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'LO_REF_CLK',
                'value': 'LORefClk'
            },
            {
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            }
        ]
    },
    'DownconverterFrequencyOffsetMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'AUTOMATIC',
                'value': 1903
            },
            {
                'name': 'ENABLED',
                'value': 1901
            },
            {
                'name': 'USER_DEFINED',
                'value': 1904
            }
        ]
    },
    'DownconverterPreselectorEnabled': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ATTR_DISABLED',
                'value': 2600
            },
            {
                'name': 'ATTR_ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 2601
            },
            {
                'name': 'ATTR_ENABLED',
                'value': 2602
            }
        ]
    },
    'Enabled': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ATTR_DISABLED',
                'value': 1900
            },
            {
                'name': 'ATTR_ENABLED',
                'value': 1901
            }
        ]
    },
    'ExportTerminal': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'DO_NOT_EXPORT',
                'value': ''
            },
            {
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            }
        ]
    },
    'FetchRelativeTo': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'MOST_RECENT_SAMPLE',
                'value': 700
            },
            {
                'name': 'FIRST_SAMPLE',
                'value': 701
            },
            {
                'name': 'REF_TRIGGER',
                'value': 702
            },
            {
                'name': 'FIRST_PRETRIGGER_SAMPLE',
                'value': 703
            },
            {
                'name': 'CURRENT_READ_POSITION',
                'value': 704
            }
        ]
    },
    'FftWindowType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'UNIFORM',
                'value': 500
            },
            {
                'name': 'HANNING',
                'value': 501
            },
            {
                'name': 'HAMMING',
                'value': 502
            },
            {
                'name': 'BLACKMAN_HARRIS',
                'value': 503
            },
            {
                'name': 'EXACT_BLACKMAN',
                'value': 504
            },
            {
                'name': 'BLACKMAN',
                'value': 505
            },
            {
                'name': 'FLAT_TOP',
                'value': 506
            },
            {
                'name': '4_TERM_BLACKMAN_HARRIS',
                'value': 507
            },
            {
                'name': '7_TERM_BLACKMAN_HARRIS',
                'value': 508
            },
            {
                'name': 'LOW_SIDE_LOBE',
                'value': 509
            },
            {
                'name': 'GAUSSIAN',
                'value': 510
            },
            {
                'name': 'KAISER_BESSEL',
                'value': 511
            }
        ]
    },
    'FrequencySettlingUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PPM',
                'value': 2000
            },
            {
                'name': 'SECONDS_AFTER_LOCK',
                'value': 2001
            },
            {
                'name': 'SECONDS_AFTER_IO',
                'value': 2002
            }
        ]
    },
    'GeneralTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 600
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 601
            },
            {
                'name': 'SOFTWARE_EDGE',
                'value': 604
            }
        ]
    },
    'IfFilter': {
        'codegen_method': 'public',
        'values': [
            {
                'name': '187_5_MHZ_WIDE',
                'value': 1400
            },
            {
                'name': '187_5_MHZ_NARROW',
                'value': 1401
            },
            {
                'name': '53_MHZ',
                'value': 1402
            },
            {
                'name': 'BYPASS',
                'value': 1403
            }
        ]
    },
    'InputPort': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RF_IN',
                'value': 2000
            },
            {
                'name': 'IQ_IN',
                'value': 2001
            },
            {
                'name': 'CAL_IN',
                'value': 2002
            },
            {
                'name': 'I_ONLY',
                'value': 2003
            }
        ]
    },
    'IqInPortTermConfig': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DIFFERENTIAL',
                'value': 2100
            },
            {
                'name': 'SINGLE_ENDED',
                'value': 2101
            }
        ]
    },
    'LinearInterpolationFormat': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'MAGNITUDE_AND_PHASE',
                'value': 4001
            },
            {
                'name': 'MAGNITUDE_DB_AND_PHASE',
                'value': 4002
            },
            {
                'name': 'REAL_AND_IMAGINARY',
                'value': 4000
            }
        ]
    },
    'LoInjectionSideValues': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HIGH_SIDE',
                'value': 1300
            },
            {
                'name': 'LOW_SIDE',
                'value': 1301
            }
        ]
    },
    'LoPathSelection': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'EXT_CAL_LO_PATH_1',
                'value': 2300
            },
            {
                'name': 'EXT_CAL_LO_PATH_2',
                'value': 2301
            },
            {
                'name': 'EXT_CAL_LO_PATH_3',
                'value': 2302
            },
            {
                'name': 'EXT_CAL_LO_PATH_4',
                'value': 2303
            },
            {
                'name': 'EXT_CAL_LO_PATH_5',
                'value': 2304
            }
        ]
    },
    'LoSourceSelection': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'ONBOARD',
                'value': 'Onboard'
            },
            {
                'name': 'LO_IN',
                'value': 'LO_In'
            },
            {
                'name': 'LO_SOURCE_SECONDARY',
                'value': 'Secondary'
            },
            {
                'name': 'LO_SOURCE_SG_SA_SHARED',
                'value': 'SG_SA_Shared'
            }
        ]
    },
    'LoYigMainCoilDrive': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NORMAL',
                'value': 2400
            },
            {
                'name': 'FAST',
                'value': 2401
            }
        ]
    },
    'LoadConfigurationResetOptions': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIRFSA_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_NONE',
                'value': 0
            },
            {
                'name': 'NIRFSA_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_DEEMBEDDING_TABLES',
                'value': 2
            }
        ]
    },
    'LoopBandwidth': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NARROW',
                'value': 800
            },
            {
                'name': 'MEDIUM',
                'value': 801
            },
            {
                'name': 'WIDE',
                'value': 802
            }
        ]
    },
    'NiRFSAInt32AttributeValues': {
        'enum-value-prefix': 'NIRFSA_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'ACQUISITION_TYPE_IQ',
                'value': 100
            },
            {
                'name': 'ACQUISITION_TYPE_SPECTRUM',
                'value': 101
            },
            {
                'name': 'ANALOG_SLOPE_RISING_SLOPE',
                'value': 1000
            },
            {
                'name': 'ANALOG_SLOPE_FALLING_SLOPE',
                'value': 1001
            },
            {
                'name': 'AVERAGING_MODE_NO_AVERAGING',
                'value': 400
            },
            {
                'name': 'AVERAGING_MODE_RMS_AVERAGING',
                'value': 401
            },
            {
                'name': 'AVERAGING_MODE_VECTOR_AVERAGING',
                'value': 402
            },
            {
                'name': 'AVERAGING_MODE_PEAK_HOLD_AVERAGING',
                'value': 403
            },
            {
                'name': 'AVERAGING_MODE_MIN_HOLD_AVERAGING',
                'value': 404
            },
            {
                'name': 'AVERAGING_MODE_SCALAR_AVERAGING',
                'value': 405
            },
            {
                'name': 'AVERAGING_MODE_LOG_AVERAGING',
                'value': 406
            },
            {
                'name': 'BANDWIDTH_TYPE_RBW_3_DB',
                'value': 300
            },
            {
                'name': 'BANDWIDTH_TYPE_RBW_6_DB',
                'value': 301
            },
            {
                'name': 'BANDWIDTH_TYPE_RBW_BIN_WIDTH',
                'value': 302
            },
            {
                'name': 'BANDWIDTH_TYPE_RBW_ENBW',
                'value': 303
            },
            {
                'name': 'CAL_IF_ATTEN_TABLE_SELECTION_EXT_CAL_IF_ATTENUATION_TABLE_STANDARD',
                'value': 2900
            },
            {
                'name': 'CAL_IF_ATTEN_TABLE_SELECTION_EXT_CAL_IF_ATTENUATION_TABLE_ACPR',
                'value': 2901
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_1',
                'value': 2100
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_2',
                'value': 2101
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_3',
                'value': 2102
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_4',
                'value': 2103
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_5',
                'value': 2104
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_6',
                'value': 2105
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_7',
                'value': 2106
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_8',
                'value': 2107
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_9',
                'value': 2108
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_10',
                'value': 2109
            },
            {
                'name': 'CAL_IF_FILTER_SELECTION_EXT_CAL_IF_FILTER_PATH_11',
                'value': 2110
            },
            {
                'name': 'CAL_TONE_MODE_DISABLED',
                'value': 2700
            },
            {
                'name': 'CAL_TONE_MODE_LOWBAND_RF',
                'value': 2701
            },
            {
                'name': 'CAL_TONE_MODE_HIGHBAND_RF',
                'value': 2702
            },
            {
                'name': 'CAL_TONE_MODE_HIGHBAND_IF',
                'value': 2703
            },
            {
                'name': 'CAL_TONE_MODE_LOWBAND_RF_WITHOUT_ALC',
                'value': 2704
            },
            {
                'name': 'CAL_TONE_MODE_COMB_GENERATOR',
                'value': 2705
            },
            {
                'name': 'CHANNEL_COUPLING_AC',
                'value': 3001
            },
            {
                'name': 'CHANNEL_COUPLING_DC',
                'value': 3002
            },
            {
                'name': 'CONDITIONING_CAL_TONE_MODE_DISABLED',
                'value': 2700
            },
            {
                'name': 'CONDITIONING_CAL_TONE_MODE_LOWBAND_RF',
                'value': 2701
            },
            {
                'name': 'CONDITIONING_CAL_TONE_MODE_HIGHBAND_RF',
                'value': 2702
            },
            {
                'name': 'DEEMBEDDING_TYPE_NONE',
                'value': 3900
            },
            {
                'name': 'DEEMBEDDING_TYPE_SCALAR',
                'value': 3901
            },
            {
                'name': 'DEEMBEDDING_TYPE_VECTOR',
                'value': 3902
            },
            {
                'name': 'DEEMBEDDING_TYPE_AMPLITUDE_FLATNESS',
                'value': 3903
            },
            {
                'name': 'DIGITAL_EDGE_RISING_EDGE',
                'value': 900
            },
            {
                'name': 'DIGITAL_EDGE_FALLING_EDGE',
                'value': 901
            },
            {
                'name': 'DOWNCONVERTER_FREQUENCY_OFFSET_MODE_AUTOMATIC',
                'value': 1903
            },
            {
                'name': 'DOWNCONVERTER_FREQUENCY_OFFSET_MODE_ENABLED',
                'value': 1901
            },
            {
                'name': 'DOWNCONVERTER_FREQUENCY_OFFSET_MODE_USER_DEFINED',
                'value': 1904
            },
            {
                'name': 'DOWNCONVERTER_PRESELECTOR_ENABLED_ATTR_DISABLED',
                'value': 2600
            },
            {
                'name': 'DOWNCONVERTER_PRESELECTOR_ENABLED_ATTR_ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 2601
            },
            {
                'name': 'DOWNCONVERTER_PRESELECTOR_ENABLED_ATTR_ENABLED',
                'value': 2602
            },
            {
                'name': 'ENABLED_ATTR_DISABLED',
                'value': 1900
            },
            {
                'name': 'ENABLED_ATTR_ENABLED',
                'value': 1901
            },
            {
                'name': 'FETCH_RELATIVE_TO_MOST_RECENT_SAMPLE',
                'value': 700
            },
            {
                'name': 'FETCH_RELATIVE_TO_FIRST_SAMPLE',
                'value': 701
            },
            {
                'name': 'FETCH_RELATIVE_TO_REF_TRIGGER',
                'value': 702
            },
            {
                'name': 'FETCH_RELATIVE_TO_FIRST_PRETRIGGER_SAMPLE',
                'value': 703
            },
            {
                'name': 'FETCH_RELATIVE_TO_CURRENT_READ_POSITION',
                'value': 704
            },
            {
                'name': 'FFT_WINDOW_TYPE_UNIFORM',
                'value': 500
            },
            {
                'name': 'FFT_WINDOW_TYPE_HANNING',
                'value': 501
            },
            {
                'name': 'FFT_WINDOW_TYPE_HAMMING',
                'value': 502
            },
            {
                'name': 'FFT_WINDOW_TYPE_BLACKMAN_HARRIS',
                'value': 503
            },
            {
                'name': 'FFT_WINDOW_TYPE_EXACT_BLACKMAN',
                'value': 504
            },
            {
                'name': 'FFT_WINDOW_TYPE_BLACKMAN',
                'value': 505
            },
            {
                'name': 'FFT_WINDOW_TYPE_FLAT_TOP',
                'value': 506
            },
            {
                'name': 'FFT_WINDOW_TYPE_4_TERM_BLACKMAN_HARRIS',
                'value': 507
            },
            {
                'name': 'FFT_WINDOW_TYPE_7_TERM_BLACKMAN_HARRIS',
                'value': 508
            },
            {
                'name': 'FFT_WINDOW_TYPE_LOW_SIDE_LOBE',
                'value': 509
            },
            {
                'name': 'FFT_WINDOW_TYPE_GAUSSIAN',
                'value': 510
            },
            {
                'name': 'FFT_WINDOW_TYPE_KAISER_BESSEL',
                'value': 511
            },
            {
                'name': 'FREQUENCY_SETTLING_UNITS_PPM',
                'value': 2000
            },
            {
                'name': 'FREQUENCY_SETTLING_UNITS_SECONDS_AFTER_LOCK',
                'value': 2001
            },
            {
                'name': 'FREQUENCY_SETTLING_UNITS_SECONDS_AFTER_IO',
                'value': 2002
            },
            {
                'name': 'GENERAL_TRIGGER_TYPE_NONE',
                'value': 600
            },
            {
                'name': 'GENERAL_TRIGGER_TYPE_DIGITAL_EDGE',
                'value': 601
            },
            {
                'name': 'GENERAL_TRIGGER_TYPE_SOFTWARE_EDGE',
                'value': 604
            },
            {
                'name': 'IF_FILTER_187_5_MHZ_WIDE',
                'value': 1400
            },
            {
                'name': 'IF_FILTER_187_5_MHZ_NARROW',
                'value': 1401
            },
            {
                'name': 'IF_FILTER_53_MHZ',
                'value': 1402
            },
            {
                'name': 'IF_FILTER_BYPASS',
                'value': 1403
            },
            {
                'name': 'INPUT_PORT_RF_IN',
                'value': 2000
            },
            {
                'name': 'INPUT_PORT_IQ_IN',
                'value': 2001
            },
            {
                'name': 'INPUT_PORT_CAL_IN',
                'value': 2002
            },
            {
                'name': 'INPUT_PORT_I_ONLY',
                'value': 2003
            },
            {
                'name': 'IQ_IN_PORT_TERM_CONFIG_DIFFERENTIAL',
                'value': 2100
            },
            {
                'name': 'IQ_IN_PORT_TERM_CONFIG_SINGLE_ENDED',
                'value': 2101
            },
            {
                'name': 'LO_INJECTION_SIDE_VALUES_HIGH_SIDE',
                'value': 1300
            },
            {
                'name': 'LO_INJECTION_SIDE_VALUES_LOW_SIDE',
                'value': 1301
            },
            {
                'name': 'LO_PATH_SELECTION_EXT_CAL_LO_PATH_1',
                'value': 2300
            },
            {
                'name': 'LO_PATH_SELECTION_EXT_CAL_LO_PATH_2',
                'value': 2301
            },
            {
                'name': 'LO_PATH_SELECTION_EXT_CAL_LO_PATH_3',
                'value': 2302
            },
            {
                'name': 'LO_PATH_SELECTION_EXT_CAL_LO_PATH_4',
                'value': 2303
            },
            {
                'name': 'LO_PATH_SELECTION_EXT_CAL_LO_PATH_5',
                'value': 2304
            },
            {
                'name': 'LO_YIG_MAIN_COIL_DRIVE_NORMAL',
                'value': 2400
            },
            {
                'name': 'LO_YIG_MAIN_COIL_DRIVE_FAST',
                'value': 2401
            },
            {
                'name': 'LOAD_CONFIGURATION_RESET_OPTIONS_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_NONE',
                'value': 0
            },
            {
                'name': 'LOAD_CONFIGURATION_RESET_OPTIONS_VAL_LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS_SKIP_DEEMBEDDING_TABLES',
                'value': 2
            },
            {
                'name': 'LOOP_BANDWIDTH_NARROW',
                'value': 800
            },
            {
                'name': 'LOOP_BANDWIDTH_MEDIUM',
                'value': 801
            },
            {
                'name': 'LOOP_BANDWIDTH_WIDE',
                'value': 802
            },
            {
                'name': 'NOTCH_FILTER_ENABLED_DISABLED',
                'value': 3400
            },
            {
                'name': 'NOTCH_FILTER_ENABLED_ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 3401
            },
            {
                'name': 'NOTCH_FILTER_ENABLED_ENABLED',
                'value': 3402
            },
            {
                'name': 'OVERFLOW_ERROR_REPORTING_WARNING',
                'value': 1301
            },
            {
                'name': 'OVERFLOW_ERROR_REPORTING_DISABLED',
                'value': 1302
            },
            {
                'name': 'POWER_SPECTRUM_UNITS_DBM',
                'value': 200
            },
            {
                'name': 'POWER_SPECTRUM_UNITS_VOLTS_SQUARED',
                'value': 201
            },
            {
                'name': 'POWER_SPECTRUM_UNITS_DBMV',
                'value': 202
            },
            {
                'name': 'POWER_SPECTRUM_UNITS_DBUV',
                'value': 203
            },
            {
                'name': 'POWER_SPECTRUM_UNITS_VOLTS',
                'value': 204
            },
            {
                'name': 'POWER_SPECTRUM_UNITS_WATTS',
                'value': 205
            },
            {
                'name': 'PULSE_WIDTH_UNIT_TYPE_SECONDS',
                'value': 6200
            },
            {
                'name': 'PULSE_WIDTH_UNIT_TYPE_CLOCK_PERIODS',
                'value': 6201
            },
            {
                'name': 'REF_TRIGGER_TYPE_NONE',
                'value': 600
            },
            {
                'name': 'REF_TRIGGER_TYPE_DIGITAL_EDGE',
                'value': 601
            },
            {
                'name': 'REF_TRIGGER_TYPE_IQ_POWER_EDGE',
                'value': 603
            },
            {
                'name': 'REF_TRIGGER_TYPE_SOFTWARE_EDGE',
                'value': 604
            },
            {
                'name': 'REF_TRIGGER_TYPE_IQ_ANALOG_EDGE',
                'value': 605
            },
            {
                'name': 'RF_LB_SIG_COND_PATH_SEL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_1',
                'value': 3700
            },
            {
                'name': 'RF_LB_SIG_COND_PATH_SEL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_2',
                'value': 3701
            },
            {
                'name': 'RF_LB_SIG_COND_PATH_SEL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_3',
                'value': 3702
            },
            {
                'name': 'RF_LB_SIG_COND_PATH_SEL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_4',
                'value': 3703
            },
            {
                'name': 'RF_LB_SIG_COND_PATH_SEL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_5',
                'value': 3704
            },
            {
                'name': 'RF_PATH_SELECTION_EXT_CAL_RF_BAND_1',
                'value': 1700
            },
            {
                'name': 'RF_PATH_SELECTION_EXT_CAL_RF_BAND_2',
                'value': 1701
            },
            {
                'name': 'RF_PATH_SELECTION_EXT_CAL_RF_BAND_3',
                'value': 1702
            },
            {
                'name': 'RF_PATH_SELECTION_EXT_CAL_RF_BAND_4',
                'value': 1703
            },
            {
                'name': 'RF_PREAMP_ENABLED_DISABLED',
                'value': 2500
            },
            {
                'name': 'RF_PREAMP_ENABLED_ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 2501
            },
            {
                'name': 'RF_PREAMP_ENABLED_ENABLED',
                'value': 2502
            },
            {
                'name': 'RF_PREAMP_ENABLED_AUTOMATIC',
                'value': 2503
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_NONE',
                'value': 3300
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_1',
                'value': 3301
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_2',
                'value': 3302
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_3',
                'value': 3303
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_4',
                'value': 3304
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_5',
                'value': 3305
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_6',
                'value': 3306
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_7',
                'value': 3307
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_8',
                'value': 3308
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_9',
                'value': 3309
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_10',
                'value': 3310
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_11',
                'value': 3311
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_12',
                'value': 3312
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_13',
                'value': 3313
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_14',
                'value': 3314
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_15',
                'value': 3315
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_16',
                'value': 3316
            },
            {
                'name': 'RF_PRESELECTOR_FILTER_FILTER_PATH_EXTERNAL_FILTER',
                'value': 3317
            },
            {
                'name': 'SIGNAL_CONDITIONING_ENABLED_ENABLED',
                'value': 3600
            },
            {
                'name': 'SIGNAL_CONDITIONING_ENABLED_BYPASSED',
                'value': 3601
            },
            {
                'name': 'STEP_GAIN_ENABLED_DISABLED',
                'value': 3200
            },
            {
                'name': 'STEP_GAIN_ENABLED_ENABLED',
                'value': 3201
            },
            {
                'name': 'UNSPECIFIED_ATTR_DISABLED',
                'value': 1900
            },
            {
                'name': 'UNSPECIFIED_ATTR_ENABLED',
                'value': 1901
            },
            {
                'name': 'UNSPECIFIED_ATTR_UNSPECIFIED',
                'value': 1902
            }
        ]
    },
    'NiRFSAStringAttributeValuesMapped': {
        'enum-value-prefix': 'NIRFSA_STRING',
        'generate-mappings': True,
        'values': [
            {
                'name': 'DIGITIZER_SAMPLE_CLOCK_OUT_TERMINAL_NONE',
                'value': 'None'
            },
            {
                'name': 'DIGITIZER_SAMPLE_CLOCK_OUT_TERMINAL_CLK_OUT',
                'value': 'ClkOut'
            },
            {
                'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE_CLK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE_LO_REF_CLK',
                'value': 'LORefClk'
            },
            {
                'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE_PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'EXPORT_TERMINAL_DO_NOT_EXPORT',
                'value': ''
            },
            {
                'name': 'EXPORT_TERMINAL_PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'EXPORT_TERMINAL_PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'EXPORT_TERMINAL_PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'EXPORT_TERMINAL_PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'EXPORT_TERMINAL_REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'EXPORT_TERMINAL_REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'EXPORT_TERMINAL_CLK_OUT',
                'value': 'ClkOut'
            },
            {
                'name': 'LO_SOURCE_SELECTION_ONBOARD',
                'value': 'Onboard'
            },
            {
                'name': 'LO_SOURCE_SELECTION_LO_IN',
                'value': 'LO_In'
            },
            {
                'name': 'LO_SOURCE_SELECTION_LO_SOURCE_SECONDARY',
                'value': 'Secondary'
            },
            {
                'name': 'LO_SOURCE_SELECTION_LO_SOURCE_SG_SA_SHARED',
                'value': 'SG_SA_Shared'
            },
            {
                'name': 'PXI_CHASSIS_CLK10_SOURCE_NONE',
                'value': 'None'
            },
            {
                'name': 'PXI_CHASSIS_CLK10_SOURCE_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'PXI_CHASSIS_CLK10_SOURCE_REF_IN',
                'value': 'RefIn'
            },
            {
                'name': 'REF_CLOCK_OUT_TERMINAL_NONE',
                'value': 'None'
            },
            {
                'name': 'REF_CLOCK_OUT_TERMINAL_REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'REF_CLOCK_OUT_TERMINAL_REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'REF_CLOCK_OUT_TERMINAL_CLK_OUT',
                'value': 'ClkOut'
            },
            {
                'name': 'REF_CLOCK_OUT_TERMINAL_IF_COND_REF_OUT',
                'value': 'IFCondRefOut'
            },
            {
                'name': 'REF_CLOCK_SOURCE_NONE',
                'value': 'None'
            },
            {
                'name': 'REF_CLOCK_SOURCE_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'REF_CLOCK_SOURCE_REF_IN',
                'value': 'RefIn'
            },
            {
                'name': 'REF_CLOCK_SOURCE_PXI_CLK',
                'value': 'PXI_Clk'
            },
            {
                'name': 'REF_CLOCK_SOURCE_CLK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'REF_CLOCK_SOURCE_REF_IN_2',
                'value': 'RefIn2'
            },
            {
                'name': 'REF_CLOCK_SOURCE_PXI_CLK_MASTER',
                'value': 'PXI_ClkMaster'
            },
            {
                'name': 'TRIGGER_SOURCE_PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'TRIGGER_SOURCE_PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'TRIGGER_SOURCE_PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'name': 'TRIGGER_SOURCE_TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'name': 'TRIGGER_SOURCE_END_OF_RECORD_EVENT',
                'value': 'EndOfRecordEvent'
            },
            {
                'name': 'TRIGGER_SOURCE_START_TRIGGER',
                'value': 'StartTrigger'
            },
            {
                'name': 'TRIGGER_SOURCE_REFERENCE_TRIGGER',
                'value': 'ReferenceTrigger'
            },
            {
                'name': 'TRIGGER_SOURCE_SYNC_START_TRIGGER',
                'value': 'Sync_Start'
            },
            {
                'name': 'TRIGGER_SOURCE_SYNC_REF_TRIGGER',
                'value': 'Sync_Ref'
            },
            {
                'name': 'TRIGGER_SOURCE_SYNC_ADVANCE_TRIGGER',
                'value': 'Sync_Advance'
            }
        ]
    },
    'NotchFilterEnabled': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLED',
                'value': 3400
            },
            {
                'name': 'ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 3401
            },
            {
                'name': 'ENABLED',
                'value': 3402
            }
        ]
    },
    'OverflowErrorReporting': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'WARNING',
                'value': 1301
            },
            {
                'name': 'DISABLED',
                'value': 1302
            }
        ]
    },
    'PowerSpectrumUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DBM',
                'value': 200
            },
            {
                'name': 'VOLTS_SQUARED',
                'value': 201
            },
            {
                'name': 'DBMV',
                'value': 202
            },
            {
                'name': 'DBUV',
                'value': 203
            },
            {
                'name': 'VOLTS',
                'value': 204
            },
            {
                'name': 'WATTS',
                'value': 205
            }
        ]
    },
    'PulseWidthUnitType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SECONDS',
                'value': 6200
            },
            {
                'name': 'CLOCK_PERIODS',
                'value': 6201
            }
        ]
    },
    'PxiChassisClk10Source': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NONE',
                'value': 'None'
            },
            {
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'REF_IN',
                'value': 'RefIn'
            }
        ]
    },
    'RefClockOutTerminal': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NONE',
                'value': 'None'
            },
            {
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            },
            {
                'name': 'IF_COND_REF_OUT',
                'value': 'IFCondRefOut'
            }
        ]
    },
    'RefClockSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NONE',
                'value': 'None'
            },
            {
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'REF_IN',
                'value': 'RefIn'
            },
            {
                'name': 'PXI_CLK',
                'value': 'PXI_Clk'
            },
            {
                'name': 'CLK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'REF_IN_2',
                'value': 'RefIn2'
            },
            {
                'name': 'PXI_CLK_MASTER',
                'value': 'PXI_ClkMaster'
            }
        ]
    },
    'RefTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 600
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 601
            },
            {
                'name': 'IQ_POWER_EDGE',
                'value': 603
            },
            {
                'name': 'SOFTWARE_EDGE',
                'value': 604
            },
            {
                'name': 'IQ_ANALOG_EDGE',
                'value': 605
            }
        ]
    },
    'ResetWithOptionsStepsToOmit': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'DEEMBEDDING_TABLES',
                'value': 2
            },
            {
                'name': 'ROUTES',
                'value': 1
            }
        ]
    },
    'RfLbSigCondPathSel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_1',
                'value': 3700
            },
            {
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_2',
                'value': 3701
            },
            {
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_3',
                'value': 3702
            },
            {
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_4',
                'value': 3703
            },
            {
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_5',
                'value': 3704
            }
        ]
    },
    'RfPathSelection': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'EXT_CAL_RF_BAND_1',
                'value': 1700
            },
            {
                'name': 'EXT_CAL_RF_BAND_2',
                'value': 1701
            },
            {
                'name': 'EXT_CAL_RF_BAND_3',
                'value': 1702
            },
            {
                'name': 'EXT_CAL_RF_BAND_4',
                'value': 1703
            }
        ]
    },
    'RfPreampEnabled': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLED',
                'value': 2500
            },
            {
                'name': 'ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 2501
            },
            {
                'name': 'ENABLED',
                'value': 2502
            },
            {
                'name': 'AUTOMATIC',
                'value': 2503
            }
        ]
    },
    'RfPreselectorFilter': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'FILTER_PATH_NONE',
                'value': 3300
            },
            {
                'name': 'FILTER_PATH_1',
                'value': 3301
            },
            {
                'name': 'FILTER_PATH_2',
                'value': 3302
            },
            {
                'name': 'FILTER_PATH_3',
                'value': 3303
            },
            {
                'name': 'FILTER_PATH_4',
                'value': 3304
            },
            {
                'name': 'FILTER_PATH_5',
                'value': 3305
            },
            {
                'name': 'FILTER_PATH_6',
                'value': 3306
            },
            {
                'name': 'FILTER_PATH_7',
                'value': 3307
            },
            {
                'name': 'FILTER_PATH_8',
                'value': 3308
            },
            {
                'name': 'FILTER_PATH_9',
                'value': 3309
            },
            {
                'name': 'FILTER_PATH_10',
                'value': 3310
            },
            {
                'name': 'FILTER_PATH_11',
                'value': 3311
            },
            {
                'name': 'FILTER_PATH_12',
                'value': 3312
            },
            {
                'name': 'FILTER_PATH_13',
                'value': 3313
            },
            {
                'name': 'FILTER_PATH_14',
                'value': 3314
            },
            {
                'name': 'FILTER_PATH_15',
                'value': 3315
            },
            {
                'name': 'FILTER_PATH_16',
                'value': 3316
            },
            {
                'name': 'FILTER_PATH_EXTERNAL_FILTER',
                'value': 3317
            }
        ]
    },
    'SelfCalibrateSteps': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'ALIGNMENT',
                'value': 1
            },
            {
                'name': 'GAIN_REFERENCE',
                'value': 2
            },
            {
                'name': 'IF_FLATNESS',
                'value': 4
            },
            {
                'name': 'DIGITIZER_SELF_CAL',
                'value': 8
            },
            {
                'name': 'LO_SELF_CAL',
                'value': 16
            },
            {
                'name': 'AMPLITUDE_ACCURACY',
                'value': 32
            },
            {
                'name': 'RESIDUAL_LO_POWER',
                'value': 64
            },
            {
                'name': 'IMAGE_SUPPRESSION',
                'value': 128
            },
            {
                'name': 'SYNTHESIZER_ALIGNMENT',
                'value': 256
            },
            {
                'name': 'DC_OFFSET',
                'value': 512
            }
        ]
    },
    'Signal': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'START_TRIGGER',
                'value': 1100
            },
            {
                'name': 'REF_TRIGGER',
                'value': 702
            },
            {
                'name': 'ADVANCE_TRIGGER',
                'value': 1102
            },
            {
                'name': 'READY_FOR_START_EVENT',
                'value': 1200
            },
            {
                'name': 'READY_FOR_REF_EVENT',
                'value': 1201
            },
            {
                'name': 'END_OF_RECORD_EVENT',
                'value': 1203
            },
            {
                'name': 'DONE_EVENT',
                'value': 1204
            },
            {
                'name': 'REF_CLOCK',
                'value': 1205
            },
            {
                'name': 'USER',
                'value': 1206
            },
            {
                'name': 'ARM_REF_TRIGGER',
                'value': 1103
            },
            {
                'name': 'READY_FOR_ADVANCE_EVENT',
                'value': 1202
            }
        ]
    },
    'SignalConditioningEnabled': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ENABLED',
                'value': 3600
            },
            {
                'name': 'BYPASSED',
                'value': 3601
            }
        ]
    },
    'SparameterOrientation': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PORT1_TOWARDS_DUT',
                'value': 3800
            },
            {
                'name': 'PORT2_TOWARDS_DUT',
                'value': 3801
            }
        ]
    },
    'StepGainEnabled': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLED',
                'value': 3200
            },
            {
                'name': 'ENABLED',
                'value': 3201
            }
        ]
    },
    'TriggerSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'name': 'END_OF_RECORD_EVENT',
                'value': 'EndOfRecordEvent'
            },
            {
                'name': 'START_TRIGGER',
                'value': 'StartTrigger'
            },
            {
                'name': 'REFERENCE_TRIGGER',
                'value': 'ReferenceTrigger'
            },
            {
                'name': 'SYNC_START_TRIGGER',
                'value': 'Sync_Start'
            },
            {
                'name': 'SYNC_REF_TRIGGER',
                'value': 'Sync_Ref'
            },
            {
                'name': 'SYNC_ADVANCE_TRIGGER',
                'value': 'Sync_Advance'
            }
        ]
    },
    'Unspecified': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ATTR_DISABLED',
                'value': 1900
            },
            {
                'name': 'ATTR_ENABLED',
                'value': 1901
            },
            {
                'name': 'ATTR_UNSPECIFIED',
                'value': 1902
            }
        ]
    }
}
