# -*- coding: utf-8 -*-
# This file is generated from NI-RFSG API metadata version 27.0.0d9999
enums = {
    'AmpPath': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HIGH_POWER',
                'value': 16000
            },
            {
                'name': 'LOW_HARMONIC',
                'value': 16001
            }
        ]
    },
    'AnalogModulationFmBand': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NARROWBAND',
                'value': 17000
            },
            {
                'name': 'WIDEBAND',
                'value': 17001
            }
        ]
    },
    'AnalogModulationFmNarrowbandIntegrator': {
        'codegen_method': 'public',
        'values': [
            {
                'name': '100_HZ_TO_1_KHZ',
                'value': 18000
            },
            {
                'name': '1_KHZ_TO_10_KHZ',
                'value': 18001
            },
            {
                'name': '10_KHZ_TO_100_KHZ',
                'value': 18002
            }
        ]
    },
    'AnalogModulationPmMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HIGH_DEVIATION',
                'value': 19000
            },
            {
                'name': 'LOW_PHASE_NOISE',
                'value': 19001
            }
        ]
    },
    'AnalogModulationType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'FM',
                'value': 2000
            },
            {
                'name': 'PM',
                'value': 2001
            },
            {
                'name': 'AM',
                'value': 2002
            }
        ]
    },
    'AnalogModulationWaveformType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SINE',
                'value': 3000
            },
            {
                'name': 'SQUARE',
                'value': 3001
            },
            {
                'name': 'TRIANGLE',
                'value': 3002
            }
        ]
    },
    'AnySignalOutputTerm': {
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
                'name': 'PFI4',
                'value': 'PFI4'
            },
            {
                'name': 'PFI5',
                'value': 'PFI5'
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
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
            },
            {
                'mapped_enum_append_index': 1,
                'name': 'DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'mapped_enum_append_index': 2,
                'name': 'DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'mapped_enum_append_index': 3,
                'name': 'DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'mapped_enum_append_index': 4,
                'name': 'DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'mapped_enum_append_index': 5,
                'name': 'DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'mapped_enum_append_index': 6,
                'name': 'DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'mapped_enum_append_index': 7,
                'name': 'DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'mapped_enum_append_index': 8,
                'name': 'DIO7',
                'value': 'DIO/PFI7'
            }
        ]
    },
    'ArbFilterType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 10000
            },
            {
                'name': 'ROOT_RAISED_COSINE',
                'value': 10001
            },
            {
                'name': 'RAISED_COSINE',
                'value': 10002
            }
        ]
    },
    'ArbOnboardSampleClockMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HIGH_RESOLUTION',
                'value': 6000
            },
            {
                'name': 'DIVIDE_DOWN',
                'value': 6001
            }
        ]
    },
    'ArbSampleClockSource': {
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
            }
        ]
    },
    'ConfigListTrigOutputTerm': {
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
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
            },
            {
                'mapped_enum_append_index': 9,
                'name': 'DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'mapped_enum_append_index': 10,
                'name': 'DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'mapped_enum_append_index': 11,
                'name': 'DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'mapped_enum_append_index': 12,
                'name': 'DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'mapped_enum_append_index': 13,
                'name': 'DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'mapped_enum_append_index': 14,
                'name': 'DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'mapped_enum_append_index': 15,
                'name': 'DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'mapped_enum_append_index': 16,
                'name': 'DIO7',
                'value': 'DIO/PFI7'
            }
        ]
    },
    'ConfigListTrigSource': {
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
                'name': 'PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'name': 'MARKER0_EVENT',
                'value': 'Marker0Event'
            },
            {
                'name': 'MARKER1_EVENT',
                'value': 'Marker1Event'
            },
            {
                'name': 'MARKER2_EVENT',
                'value': 'Marker2Event'
            },
            {
                'name': 'MARKER3_EVENT',
                'value': 'Marker3Event'
            },
            {
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'name': 'TRIG_IN',
                'value': 'TrigIn'
            },
            {
                'mapped_enum_append_index': 17,
                'name': 'DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'mapped_enum_append_index': 18,
                'name': 'DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'mapped_enum_append_index': 19,
                'name': 'DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'mapped_enum_append_index': 20,
                'name': 'DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'mapped_enum_append_index': 21,
                'name': 'DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'mapped_enum_append_index': 22,
                'name': 'DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'mapped_enum_append_index': 23,
                'name': 'DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'mapped_enum_append_index': 24,
                'name': 'DIO7',
                'value': 'DIO/PFI7'
            }
        ]
    },
    'ConfigListTriggerDigEdgeEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RISING_EDGE',
                'value': 0
            }
        ]
    },
    'ConfigSettledEventOutputTerm': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'DO_NOT_EXPORT',
                'value': ''
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
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
            }
        ]
    },
    'ConfigurationListRepeat': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'CONFIGURATION_LIST_REPEAT_CONTINUOUS',
                'value': 0
            },
            {
                'name': 'CONFIGURATION_LIST_REPEAT_SINGLE',
                'value': 1
            }
        ]
    },
    'DeembeddingType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 25000
            },
            {
                'name': 'SCALAR',
                'value': 25001
            },
            {
                'name': 'VECTOR',
                'value': 25002
            },
            {
                'name': 'AMPLITUDE_FLATNESS',
                'value': 25003
            }
        ]
    },
    'DigitalEdgeConfigurationListStepTriggerSource': {
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
                'name': 'PFI2',
                'value': 'PFI2'
            },
            {
                'name': 'PFI3',
                'value': 'PFI3'
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
                'name': 'MARKER0_EVENT',
                'value': 'Marker0Event'
            },
            {
                'name': 'MARKER1_EVENT',
                'value': 'Marker1Event'
            },
            {
                'name': 'MARKER2_EVENT',
                'value': 'Marker2Event'
            },
            {
                'name': 'MARKER3_EVENT',
                'value': 'Marker3Event'
            },
            {
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'name': 'TRIG_IN',
                'value': 'TrigIn'
            }
        ]
    },
    'DigitalEdgeEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RISING_EDGE',
                'value': 0
            },
            {
                'name': 'FALLING_EDGE',
                'value': 1
            }
        ]
    },
    'DigitalEdgeScriptTriggerIdentifier': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'SCRIPT_TRIGGER0',
                'value': 'scriptTrigger0'
            },
            {
                'name': 'SCRIPT_TRIGGER1',
                'value': 'scriptTrigger1'
            },
            {
                'name': 'SCRIPT_TRIGGER2',
                'value': 'scriptTrigger2'
            },
            {
                'name': 'SCRIPT_TRIGGER3',
                'value': 'scriptTrigger3'
            }
        ]
    },
    'DigitalLevelActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 9000
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 9001
            }
        ]
    },
    'DigitalModulationType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'FSK',
                'value': 4000
            },
            {
                'name': 'OOK',
                'value': 4001
            },
            {
                'name': 'PSK',
                'value': 4002
            }
        ]
    },
    'DigitalModulationWaveformType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PRBS',
                'value': 5000
            },
            {
                'name': 'USER_DEFINED',
                'value': 5001
            }
        ]
    },
    'EnableValues': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLE',
                'value': 0
            },
            {
                'name': 'ENABLE',
                'value': 1
            }
        ]
    },
    'FrequencySettlingUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'TIME_AFTER_LOCK',
                'value': 12000
            },
            {
                'name': 'TIME_AFTER_IO',
                'value': 12001
            },
            {
                'name': 'PPM',
                'value': 12002
            }
        ]
    },
    'GenerationMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'CW',
                'value': 1000
            },
            {
                'name': 'ARB_WAVEFORM',
                'value': 1001
            },
            {
                'name': 'SCRIPT',
                'value': 1002
            }
        ]
    },
    'IQOffsetUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PERCENT',
                'value': 11000
            },
            {
                'name': 'VOLTS',
                'value': 11001
            }
        ]
    },
    'IQOutPortTermConfig': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DIFFERENTIAL',
                'value': 15000
            },
            {
                'name': 'SINGLE_ENDED',
                'value': 15001
            }
        ]
    },
    'LinearInterpolationFormat': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'MAGNITUDE_AND_PHASE',
                'value': 26001
            },
            {
                'name': 'MAGNITUDE_DB_AND_PHASE',
                'value': 26002
            },
            {
                'name': 'REAL_AND_IMAGINARY',
                'value': 26000
            }
        ]
    },
    'ListStepTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 1
            }
        ]
    },
    'LoSource': {
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
                'name': 'SECONDARY',
                'value': 'Secondary'
            },
            {
                'name': 'SG_SA_SHARED',
                'value': 'SG_SA_Shared'
            },
            {
                'name': 'AUTOMATIC_SG_SA_SHARED',
                'value': 'Automatic_SG_SA_Shared'
            }
        ]
    },
    'LoadOptions': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SKIP_NONE',
                'value': 0
            },
            {
                'name': 'SKIP_WAVEFORMS',
                'value': 1
            },
            {
                'name': 'SKIP_SCRIPTS',
                'value': 2
            }
        ]
    },
    'LoopBandwidth': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NARROW',
                'value': 0
            },
            {
                'name': 'MEDIUM',
                'value': 1
            },
            {
                'name': 'WIDE',
                'value': 2
            }
        ]
    },
    'MarkerEventOutputBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PULSE',
                'value': 23000
            },
            {
                'name': 'TOGGLE',
                'value': 23001
            }
        ]
    },
    'MarkerEventPulseWidthUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SECONDS',
                'value': 22000
            },
            {
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 22001
            }
        ]
    },
    'MarkerEventToggleInitialState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DIGITAL_LOW',
                'value': 21000
            },
            {
                'name': 'DIGITAL_HIGH',
                'value': 21001
            }
        ]
    },
    'Module': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PRIMARY_MODULE',
                'value': 13000
            },
            {
                'name': 'AWG',
                'value': 13001
            },
            {
                'name': 'LO',
                'value': 13002
            }
        ]
    },
    'NiRFSGInt32AttributeValues': {
        'enum-value-prefix': 'NIRFSG_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'AMP_PATH_HIGH_POWER',
                'value': 16000
            },
            {
                'name': 'AMP_PATH_LOW_HARMONIC',
                'value': 16001
            },
            {
                'name': 'ANALOG_MODULATION_FM_BAND_NARROWBAND',
                'value': 17000
            },
            {
                'name': 'ANALOG_MODULATION_FM_BAND_WIDEBAND',
                'value': 17001
            },
            {
                'name': 'ANALOG_MODULATION_FM_NARROWBAND_INTEGRATOR_100_HZ_TO_1_KHZ',
                'value': 18000
            },
            {
                'name': 'ANALOG_MODULATION_FM_NARROWBAND_INTEGRATOR_1_KHZ_TO_10_KHZ',
                'value': 18001
            },
            {
                'name': 'ANALOG_MODULATION_FM_NARROWBAND_INTEGRATOR_10_KHZ_TO_100_KHZ',
                'value': 18002
            },
            {
                'name': 'ANALOG_MODULATION_PM_MODE_HIGH_DEVIATION',
                'value': 19000
            },
            {
                'name': 'ANALOG_MODULATION_PM_MODE_LOW_PHASE_NOISE',
                'value': 19001
            },
            {
                'name': 'ANALOG_MODULATION_TYPE_NONE',
                'value': 0
            },
            {
                'name': 'ANALOG_MODULATION_TYPE_FM',
                'value': 2000
            },
            {
                'name': 'ANALOG_MODULATION_TYPE_PM',
                'value': 2001
            },
            {
                'name': 'ANALOG_MODULATION_TYPE_AM',
                'value': 2002
            },
            {
                'name': 'ANALOG_MODULATION_WAVEFORM_TYPE_SINE',
                'value': 3000
            },
            {
                'name': 'ANALOG_MODULATION_WAVEFORM_TYPE_SQUARE',
                'value': 3001
            },
            {
                'name': 'ANALOG_MODULATION_WAVEFORM_TYPE_TRIANGLE',
                'value': 3002
            },
            {
                'name': 'ARB_FILTER_TYPE_NONE',
                'value': 10000
            },
            {
                'name': 'ARB_FILTER_TYPE_ROOT_RAISED_COSINE',
                'value': 10001
            },
            {
                'name': 'ARB_FILTER_TYPE_RAISED_COSINE',
                'value': 10002
            },
            {
                'name': 'ARB_ONBOARD_SAMPLE_CLOCK_MODE_HIGH_RESOLUTION',
                'value': 6000
            },
            {
                'name': 'ARB_ONBOARD_SAMPLE_CLOCK_MODE_DIVIDE_DOWN',
                'value': 6001
            },
            {
                'name': 'CONFIG_LIST_TRIGGER_DIG_EDGE_EDGE_RISING_EDGE',
                'value': 0
            },
            {
                'name': 'CONFIGURATION_LIST_REPEAT_CONFIGURATION_LIST_REPEAT_CONTINUOUS',
                'value': 0
            },
            {
                'name': 'CONFIGURATION_LIST_REPEAT_CONFIGURATION_LIST_REPEAT_SINGLE',
                'value': 1
            },
            {
                'name': 'DEEMBEDDING_TYPE_NONE',
                'value': 25000
            },
            {
                'name': 'DEEMBEDDING_TYPE_SCALAR',
                'value': 25001
            },
            {
                'name': 'DEEMBEDDING_TYPE_VECTOR',
                'value': 25002
            },
            {
                'name': 'DEEMBEDDING_TYPE_AMPLITUDE_FLATNESS',
                'value': 25003
            },
            {
                'name': 'DIGITAL_EDGE_EDGE_RISING_EDGE',
                'value': 0
            },
            {
                'name': 'DIGITAL_EDGE_EDGE_FALLING_EDGE',
                'value': 1
            },
            {
                'name': 'DIGITAL_LEVEL_ACTIVE_LEVEL_ACTIVE_HIGH',
                'value': 9000
            },
            {
                'name': 'DIGITAL_LEVEL_ACTIVE_LEVEL_ACTIVE_LOW',
                'value': 9001
            },
            {
                'name': 'DIGITAL_MODULATION_TYPE_NONE',
                'value': 0
            },
            {
                'name': 'DIGITAL_MODULATION_TYPE_FSK',
                'value': 4000
            },
            {
                'name': 'DIGITAL_MODULATION_TYPE_OOK',
                'value': 4001
            },
            {
                'name': 'DIGITAL_MODULATION_TYPE_PSK',
                'value': 4002
            },
            {
                'name': 'DIGITAL_MODULATION_WAVEFORM_TYPE_PRBS',
                'value': 5000
            },
            {
                'name': 'DIGITAL_MODULATION_WAVEFORM_TYPE_USER_DEFINED',
                'value': 5001
            },
            {
                'name': 'ENABLE_VALUES_DISABLE',
                'value': 0
            },
            {
                'name': 'ENABLE_VALUES_ENABLE',
                'value': 1
            },
            {
                'name': 'FREQUENCY_SETTLING_UNITS_TIME_AFTER_LOCK',
                'value': 12000
            },
            {
                'name': 'FREQUENCY_SETTLING_UNITS_TIME_AFTER_IO',
                'value': 12001
            },
            {
                'name': 'FREQUENCY_SETTLING_UNITS_PPM',
                'value': 12002
            },
            {
                'name': 'GENERATION_MODE_CW',
                'value': 1000
            },
            {
                'name': 'GENERATION_MODE_ARB_WAVEFORM',
                'value': 1001
            },
            {
                'name': 'GENERATION_MODE_SCRIPT',
                'value': 1002
            },
            {
                'name': 'IQ_OFFSET_UNITS_PERCENT',
                'value': 11000
            },
            {
                'name': 'IQ_OFFSET_UNITS_VOLTS',
                'value': 11001
            },
            {
                'name': 'IQ_OUT_PORT_TERM_CONFIG_DIFFERENTIAL',
                'value': 15000
            },
            {
                'name': 'IQ_OUT_PORT_TERM_CONFIG_SINGLE_ENDED',
                'value': 15001
            },
            {
                'name': 'LIST_STEP_TRIGGER_TYPE_NONE',
                'value': 0
            },
            {
                'name': 'LIST_STEP_TRIGGER_TYPE_DIGITAL_EDGE',
                'value': 1
            },
            {
                'name': 'LOAD_OPTIONS_SKIP_NONE',
                'value': 0
            },
            {
                'name': 'LOAD_OPTIONS_SKIP_WAVEFORMS',
                'value': 1
            },
            {
                'name': 'LOAD_OPTIONS_SKIP_SCRIPTS',
                'value': 2
            },
            {
                'name': 'LOOP_BANDWIDTH_NARROW',
                'value': 0
            },
            {
                'name': 'LOOP_BANDWIDTH_MEDIUM',
                'value': 1
            },
            {
                'name': 'LOOP_BANDWIDTH_WIDE',
                'value': 2
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_PULSE',
                'value': 23000
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_TOGGLE',
                'value': 23001
            },
            {
                'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS_SECONDS',
                'value': 22000
            },
            {
                'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS_SAMPLE_CLOCK_PERIODS',
                'value': 22001
            },
            {
                'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE_DIGITAL_LOW',
                'value': 21000
            },
            {
                'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE_DIGITAL_HIGH',
                'value': 21001
            },
            {
                'name': 'OUTPUT_PORT_RF_OUT',
                'value': 14000
            },
            {
                'name': 'OUTPUT_PORT_IQ_OUT',
                'value': 14001
            },
            {
                'name': 'OUTPUT_PORT_CAL_OUT',
                'value': 14002
            },
            {
                'name': 'OUTPUT_PORT_I_ONLY',
                'value': 14003
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
                'name': 'PPA_SCRIPT_INHERITANCE_EXACT_MATCH',
                'value': 0
            },
            {
                'name': 'PPA_SCRIPT_INHERITANCE_MINIMUM',
                'value': 1
            },
            {
                'name': 'PPA_SCRIPT_INHERITANCE_MAXIMUM',
                'value': 2
            },
            {
                'name': 'PHASE_CONTINUITY_DISABLE',
                'value': 0
            },
            {
                'name': 'PHASE_CONTINUITY_AUTO',
                'value': -1
            },
            {
                'name': 'PHASE_CONTINUITY_ENABLE',
                'value': 1
            },
            {
                'name': 'POWER_LEVEL_TYPE_AVERAGE_POWER',
                'value': 7000
            },
            {
                'name': 'POWER_LEVEL_TYPE_PEAK_POWER',
                'value': 7001
            },
            {
                'name': 'PULSE_MODULATION_MODE_OPTIMAL_MATCH',
                'value': 20000
            },
            {
                'name': 'PULSE_MODULATION_MODE_HIGH_ISOLATION',
                'value': 20001
            },
            {
                'name': 'PULSE_MODULATION_MODE_ANALOG',
                'value': 20002
            },
            {
                'name': 'PULSE_MODULATION_MODE_DIGITAL',
                'value': 20003
            },
            {
                'name': 'RF_IN_LO_EXPORT_ENABLED_DISABLE',
                'value': 0
            },
            {
                'name': 'RF_IN_LO_EXPORT_ENABLED_UNSPECIFIED',
                'value': -2
            },
            {
                'name': 'RF_IN_LO_EXPORT_ENABLED_ENABLE',
                'value': 1
            },
            {
                'name': 'RESET_OPTIONS_SKIP_NONE',
                'value': 0
            },
            {
                'name': 'RESET_OPTIONS_SKIP_WAVEFORMS',
                'value': 1
            },
            {
                'name': 'RESET_OPTIONS_SKIP_DEEMBEDING_TABLES',
                'value': 8
            },
            {
                'name': 'RESET_OPTIONS_SKIP_SCRIPTS',
                'value': 2
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_NONE',
                'value': 0
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_DIGITAL_EDGE',
                'value': 1
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_DIGITAL_LEVEL',
                'value': 8000
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_SOFTWARE',
                'value': 2
            },
            {
                'name': 'START_TRIGGER_TYPE_NONE',
                'value': 0
            },
            {
                'name': 'START_TRIGGER_TYPE_DIGITAL_EDGE',
                'value': 1
            },
            {
                'name': 'START_TRIGGER_TYPE_SOFTWARE',
                'value': 2
            },
            {
                'name': 'START_TRIGGER_TYPE_P2_P_ENDPOINT_FULLNESS',
                'value': 3
            },
            {
                'name': 'UPCONVERTER_FREQUENCY_OFFSET_MODE_AUTO',
                'value': -1
            },
            {
                'name': 'UPCONVERTER_FREQUENCY_OFFSET_MODE_ENABLE',
                'value': 1
            },
            {
                'name': 'UPCONVERTER_FREQUENCY_OFFSET_MODE_USER_DEFINED',
                'value': 5001
            },
            {
                'name': 'WRITE_WAVEFORM_BURST_DETECTION_MODE_MANUAL',
                'value': 0
            },
            {
                'name': 'WRITE_WAVEFORM_BURST_DETECTION_MODE_AUTO',
                'value': -1
            },
            {
                'name': 'YIG_MAIN_COIL_SLOW',
                'value': 0
            },
            {
                'name': 'YIG_MAIN_COIL_FAST',
                'value': 1
            }
        ]
    },
    'NiRFSGReal64AttributeValues': {
        'enum-value-prefix': 'NIRFSG_REAL64',
        'generate-mappings': False,
        'values': [
            {
                'name': 'REF_CLOCK_RATE_AUTO',
                'value': -1
            },
            {
                'name': 'REF_CLOCK_RATE_10_MHZ',
                'value': 10000000
            }
        ]
    },
    'NiRFSGStringAttributeValuesMapped': {
        'enum-value-prefix': 'NIRFSG_STRING',
        'generate-mappings': True,
        'values': [
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DO_NOT_EXPORT',
                'value': ''
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PFI4',
                'value': 'PFI4'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PFI5',
                'value': 'PFI5'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_TRIG_OUT',
                'value': 'TrigOut'
            },
            {
                'name': 'ARB_SAMPLE_CLOCK_SOURCE_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'ARB_SAMPLE_CLOCK_SOURCE_CLK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DO_NOT_EXPORT',
                'value': ''
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_TRIG_OUT',
                'value': 'TrigOut'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_MARKER0_EVENT',
                'value': 'Marker0Event'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_MARKER1_EVENT',
                'value': 'Marker1Event'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_MARKER2_EVENT',
                'value': 'Marker2Event'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_MARKER3_EVENT',
                'value': 'Marker3Event'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_TRIG_IN',
                'value': 'TrigIn'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_DO_NOT_EXPORT',
                'value': ''
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'name': 'CONFIG_SETTLED_EVENT_OUTPUT_TERM_TRIG_OUT',
                'value': 'TrigOut'
            },
            {
                'name': 'LO_SOURCE_ONBOARD',
                'value': 'Onboard'
            },
            {
                'name': 'LO_SOURCE_LO_IN',
                'value': 'LO_In'
            },
            {
                'name': 'LO_SOURCE_SECONDARY',
                'value': 'Secondary'
            },
            {
                'name': 'LO_SOURCE_SG_SA_SHARED',
                'value': 'SG_SA_Shared'
            },
            {
                'name': 'LO_SOURCE_AUTOMATIC_SG_SA_SHARED',
                'value': 'Automatic_SG_SA_Shared'
            },
            {
                'name': 'PXI_CHASSIS_CLK10_NONE',
                'value': 'None'
            },
            {
                'name': 'PXI_CHASSIS_CLK10_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'PXI_CHASSIS_CLK10_REF_IN',
                'value': 'RefIn'
            },
            {
                'name': 'REF_CLOCK_OUTPUT_TERM_DO_NOT_EXPORT',
                'value': ''
            },
            {
                'name': 'REF_CLOCK_OUTPUT_TERM_REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'REF_CLOCK_OUTPUT_TERM_REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'REF_CLOCK_OUTPUT_TERM_CLK_OUT',
                'value': 'ClkOut'
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
                'value': 'PXI_CLK'
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
                'name': 'TRIGGER_SOURCE_PFI2',
                'value': 'PFI2'
            },
            {
                'name': 'TRIGGER_SOURCE_PFI3',
                'value': 'PFI3'
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
                'name': 'TRIGGER_SOURCE_SYNC_START_TRIGGER',
                'value': 'Sync_Start'
            },
            {
                'name': 'TRIGGER_SOURCE_SYNC_SCRIPT_TRIGGER',
                'value': 'Sync_Script'
            },
            {
                'name': 'TRIGGER_SOURCE_TRIG_IN',
                'value': 'TrigIn'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'name': 'ANY_SIGNAL_OUTPUT_TERM_DIO7',
                'value': 'DIO/PFI7'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'name': 'CONFIG_LIST_TRIG_OUTPUT_TERM_DIO7',
                'value': 'DIO/PFI7'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'name': 'CONFIG_LIST_TRIG_SOURCE_DIO7',
                'value': 'DIO/PFI7'
            },
            {
                'name': 'TRIGGER_SOURCE_PULSE_IN',
                'value': 'PulseIn'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'name': 'TRIGGER_SOURCE_DIO7',
                'value': 'DIO/PFI7'
            }
        ]
    },
    'OutputPort': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RF_OUT',
                'value': 14000
            },
            {
                'name': 'IQ_OUT',
                'value': 14001
            },
            {
                'name': 'CAL_OUT',
                'value': 14002
            },
            {
                'name': 'I_ONLY',
                'value': 14003
            }
        ]
    },
    'OutputSignal': {
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
                'name': 'PFI4',
                'value': 'PFI4'
            },
            {
                'name': 'PFI5',
                'value': 'PFI5'
            },
            {
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
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
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
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
    'PPAScriptInheritance': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'EXACT_MATCH',
                'value': 0
            },
            {
                'name': 'MINIMUM',
                'value': 1
            },
            {
                'name': 'MAXIMUM',
                'value': 2
            }
        ]
    },
    'PXIChassisClk10': {
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
    'PhaseContinuity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLE',
                'value': 0
            },
            {
                'name': 'AUTO',
                'value': -1
            },
            {
                'name': 'ENABLE',
                'value': 1
            }
        ]
    },
    'PowerLevelType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'AVERAGE_POWER',
                'value': 7000
            },
            {
                'name': 'PEAK_POWER',
                'value': 7001
            }
        ]
    },
    'PulseModulationMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'OPTIMAL_MATCH',
                'value': 20000
            },
            {
                'name': 'HIGH_ISOLATION',
                'value': 20001
            },
            {
                'name': 'ANALOG',
                'value': 20002
            },
            {
                'name': 'DIGITAL',
                'value': 20003
            }
        ]
    },
    'RFInLoExportEnabled': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'DISABLE',
                'value': 0
            },
            {
                'name': 'UNSPECIFIED',
                'value': -2
            },
            {
                'name': 'ENABLE',
                'value': 1
            }
        ]
    },
    'RefClockOutputTerm': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'DO_NOT_EXPORT',
                'value': ''
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
    'RefClockRate': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'AUTO',
                'value': -1
            },
            {
                'name': '10_MHZ',
                'value': 10000000
            }
        ]
    },
    'RefClockSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
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
                'value': 'PXI_CLK'
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
    'RelativeTo': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'CURRENT_POSITION',
                'value': 8001
            },
            {
                'name': 'START_OF_WAVEFORM',
                'value': 8000
            }
        ]
    },
    'ResetOptions': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SKIP_NONE',
                'value': 0
            },
            {
                'name': 'SKIP_WAVEFORMS',
                'value': 1
            },
            {
                'name': 'SKIP_DEEMBEDING_TABLES',
                'value': 8
            },
            {
                'name': 'SKIP_SCRIPTS',
                'value': 2
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
                'value': 8
            },
            {
                'name': 'ROUTES',
                'value': 4
            },
            {
                'name': 'SCRIPTS',
                'value': 2
            },
            {
                'name': 'WAVEFORMS',
                'value': 1
            }
        ]
    },
    'RoutedSignal': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'START_TRIGGER',
                'value': 0
            },
            {
                'name': 'SCRIPT_TRIGGER',
                'value': 1
            },
            {
                'name': 'MARKER_EVENT',
                'value': 2
            },
            {
                'name': 'REF_CLOCK',
                'value': 3
            },
            {
                'name': 'STARTED_EVENT',
                'value': 4
            },
            {
                'name': 'DONE_EVENT',
                'value': 5
            },
            {
                'name': 'CONFIGURATION_LIST_STEP_TRIGGER',
                'value': 6
            },
            {
                'name': 'CONFIGURATION_SETTLED_EVENT',
                'value': 7
            }
        ]
    },
    'SParameterOrientation': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PORT1_TOWARDS_DUT',
                'value': 24000
            },
            {
                'name': 'PORT2_TOWARDS_DUT',
                'value': 24001
            }
        ]
    },
    'ScriptTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 1
            },
            {
                'name': 'DIGITAL_LEVEL',
                'value': 8000
            },
            {
                'name': 'SOFTWARE',
                'value': 2
            }
        ]
    },
    'SelfCalibrateRangeStepsToOmit': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'OMIT_NONE',
                'value': 0
            },
            {
                'name': 'IMAGE_SUPPRESSION',
                'value': 8
            },
            {
                'name': 'LO_SELF_CAL',
                'value': 1
            },
            {
                'name': 'POWER_LEVEL_ACCURACY',
                'value': 2
            },
            {
                'name': 'RESIDUAL_LO_POWER',
                'value': 4
            },
            {
                'name': 'SYNTHESIZER_ALIGNMENT',
                'value': 16
            }
        ]
    },
    'SignalIdentifier': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NONE',
                'value': ''
            },
            {
                'name': 'SCRIPT_TRIGGER0',
                'value': 'scriptTrigger0'
            },
            {
                'name': 'SCRIPT_TRIGGER1',
                'value': 'scriptTrigger1'
            },
            {
                'name': 'SCRIPT_TRIGGER2',
                'value': 'scriptTrigger2'
            },
            {
                'name': 'SCRIPT_TRIGGER3',
                'value': 'scriptTrigger3'
            },
            {
                'name': 'MARKER0',
                'value': 'marker0'
            },
            {
                'name': 'MARKER1',
                'value': 'marker1'
            },
            {
                'name': 'MARKER2',
                'value': 'marker2'
            },
            {
                'name': 'MARKER3',
                'value': 'marker3'
            }
        ]
    },
    'StartTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 1
            },
            {
                'name': 'SOFTWARE',
                'value': 2
            },
            {
                'name': 'P2_P_ENDPOINT_FULLNESS',
                'value': 3
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
                'name': 'PFI2',
                'value': 'PFI2'
            },
            {
                'name': 'PFI3',
                'value': 'PFI3'
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
                'name': 'SYNC_START_TRIGGER',
                'value': 'Sync_Start'
            },
            {
                'name': 'SYNC_SCRIPT_TRIGGER',
                'value': 'Sync_Script'
            },
            {
                'name': 'TRIG_IN',
                'value': 'TrigIn'
            },
            {
                'mapped_enum_append_index': 25,
                'name': 'PULSE_IN',
                'value': 'PulseIn'
            },
            {
                'mapped_enum_append_index': 26,
                'name': 'DIO0',
                'value': 'DIO/PFI0'
            },
            {
                'mapped_enum_append_index': 27,
                'name': 'DIO1',
                'value': 'DIO/PFI1'
            },
            {
                'mapped_enum_append_index': 28,
                'name': 'DIO2',
                'value': 'DIO/PFI2'
            },
            {
                'mapped_enum_append_index': 29,
                'name': 'DIO3',
                'value': 'DIO/PFI3'
            },
            {
                'mapped_enum_append_index': 30,
                'name': 'DIO4',
                'value': 'DIO/PFI4'
            },
            {
                'mapped_enum_append_index': 31,
                'name': 'DIO5',
                'value': 'DIO/PFI5'
            },
            {
                'mapped_enum_append_index': 32,
                'name': 'DIO6',
                'value': 'DIO/PFI6'
            },
            {
                'mapped_enum_append_index': 33,
                'name': 'DIO7',
                'value': 'DIO/PFI7'
            }
        ]
    },
    'UpconverterFrequencyOffsetMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'AUTO',
                'value': -1
            },
            {
                'name': 'ENABLE',
                'value': 1
            },
            {
                'name': 'USER_DEFINED',
                'value': 5001
            }
        ]
    },
    'WriteWaveformBurstDetectionMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'MANUAL',
                'value': 0
            },
            {
                'name': 'AUTO',
                'value': -1
            }
        ]
    },
    'YIGMainCoil': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SLOW',
                'value': 0
            },
            {
                'name': 'FAST',
                'value': 1
            }
        ]
    }
}
