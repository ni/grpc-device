# -*- coding: utf-8 -*-
# This file is generated from NI-FGEN API metadata version 23.0.0f157
enums = {
    'AddressType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ADDR_PHYSICAL',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_ADDR_VIRTUAL',
                'value': 1
            }
        ]
    },
    'AnalogPath': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_MAIN_ANALOG_PATH',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_DIRECT_ANALOG_PATH',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_FIXED_LOW_GAIN_ANALOG_PATH',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_FIXED_HIGH_GAIN_ANALOG_PATH',
                'value': 3
            }
        ]
    },
    'ArbitrarySequenceHandle': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_FIRST_SEQUENCE_HANDLE',
                'value': 100000
            },
            {
                'name': 'NIFGEN_VAL_LAST_SEQUENCE_HANDLE',
                'value': 109999
            },
            {
                'name': 'NIFGEN_VAL_NO_SEQUENCE',
                'value': -1
            }
        ]
    },
    'ArbitraryWaveformHandle': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_FIRST_WAVEFORM_HANDLE',
                'value': 10000
            },
            {
                'name': 'NIFGEN_VAL_LAST_WAVEFORM_HANDLE',
                'value': 10999
            },
            {
                'name': 'NIFGEN_VAL_NO_WAVEFORM',
                'value': -1
            }
        ]
    },
    'BurstCount': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_GENERATE_CONTINUOUS',
                'value': -1
            }
        ]
    },
    'BusType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_BUS_INVALID',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_BUS_AT',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_BUS_PCI',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_BUS_PXI',
                'value': 3
            },
            {
                'name': 'NIFGEN_VAL_BUS_VXI',
                'value': 4
            },
            {
                'name': 'NIFGEN_VAL_BUS_PCMCIA',
                'value': 5
            },
            {
                'name': 'NIFGEN_VAL_BUS_PXIE',
                'value': 6
            }
        ]
    },
    'ByteOrder': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_LITTLE_ENDIAN',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_BIG_ENDIAN',
                'value': 1
            }
        ]
    },
    'ClockMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_HIGH_RESOLUTION',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_DIVIDE_DOWN',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_AUTOMATIC',
                'value': 2
            }
        ]
    },
    'DataMarkerEventLevelPolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'DataProcessingMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_OSP_REAL',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_OSP_COMPLEX',
                'value': 1
            }
        ]
    },
    'DoneEventActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'DoneEventDelayUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_SECONDS',
                'value': 102
            }
        ]
    },
    'DoneEventOutputBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_PULSE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_LEVEL',
                'value': 102
            }
        ]
    },
    'DoneEventPulsePolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'DoneEventPulseWidthUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_SECONDS',
                'value': 102
            }
        ]
    },
    'FilterType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_OSP_FLAT',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_OSP_RAISED_COSINE',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_OSP_ROOT_RAISED_COSINE',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_OSP_GAUSSIAN',
                'value': 3
            },
            {
                'name': 'NIFGEN_VAL_OSP_CUSTOM',
                'value': 4
            }
        ]
    },
    'FrequencyListHandle': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_FIRST_FREQ_LIST_HANDLE',
                'value': 200000
            },
            {
                'name': 'NIFGEN_VAL_LAST_FREQ_LIST_HANDLE',
                'value': 209999
            },
            {
                'name': 'NIFGEN_VAL_NO_FREQ_LIST',
                'value': -1
            }
        ]
    },
    'FrequencyListOptions': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ALL_FLISTS',
                'value': -1
            }
        ]
    },
    'HardwareState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_IDLE',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_WAITING_FOR_START_TRIGGER',
                'value': 100
            },
            {
                'name': 'NIFGEN_VAL_RUNNING',
                'value': 200
            },
            {
                'name': 'NIFGEN_VAL_DONE',
                'value': 600
            },
            {
                'name': 'NIFGEN_VAL_HARDWARE_ERROR',
                'value': 1000
            }
        ]
    },
    'IdleBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'NIFGEN_VAL_JUMP_TO_VALUE',
                'value': 401
            }
        ]
    },
    'LoadImpedance': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_MATCHED_LOAD_IMPEDANCE',
                'value': -1
            }
        ]
    },
    'MarkerEventDelayUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_SECONDS',
                'value': 102
            }
        ]
    },
    'MarkerEventOutputBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_PULSE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_LEVEL',
                'value': 102
            },
            {
                'name': 'NIFGEN_VAL_TOGGLE',
                'value': 103
            }
        ]
    },
    'MarkerEventPulsePolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'MarkerEventPulseWidthUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_SECONDS',
                'value': 102
            }
        ]
    },
    'MarkerEventToggleInitialState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_LOW',
                'value': 102
            }
        ]
    },
    'NiFgenInt32AttributeValues': {
        'enum-value-prefix': 'NIFGEN_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'ADDRESS_TYPE_VAL_ADDR_PHYSICAL',
                'value': 0
            },
            {
                'name': 'ADDRESS_TYPE_VAL_ADDR_VIRTUAL',
                'value': 1
            },
            {
                'name': 'ANALOG_PATH_VAL_MAIN_ANALOG_PATH',
                'value': 0
            },
            {
                'name': 'ANALOG_PATH_VAL_DIRECT_ANALOG_PATH',
                'value': 1
            },
            {
                'name': 'ANALOG_PATH_VAL_FIXED_LOW_GAIN_ANALOG_PATH',
                'value': 2
            },
            {
                'name': 'ANALOG_PATH_VAL_FIXED_HIGH_GAIN_ANALOG_PATH',
                'value': 3
            },
            {
                'name': 'ARBITRARY_SEQUENCE_HANDLE_VAL_FIRST_SEQUENCE_HANDLE',
                'value': 100000
            },
            {
                'name': 'ARBITRARY_SEQUENCE_HANDLE_VAL_LAST_SEQUENCE_HANDLE',
                'value': 109999
            },
            {
                'name': 'ARBITRARY_SEQUENCE_HANDLE_VAL_NO_SEQUENCE',
                'value': -1
            },
            {
                'name': 'ARBITRARY_WAVEFORM_HANDLE_VAL_FIRST_WAVEFORM_HANDLE',
                'value': 10000
            },
            {
                'name': 'ARBITRARY_WAVEFORM_HANDLE_VAL_LAST_WAVEFORM_HANDLE',
                'value': 10999
            },
            {
                'name': 'ARBITRARY_WAVEFORM_HANDLE_VAL_NO_WAVEFORM',
                'value': -1
            },
            {
                'name': 'BURST_COUNT_VAL_GENERATE_CONTINUOUS',
                'value': -1
            },
            {
                'name': 'BUS_TYPE_VAL_BUS_INVALID',
                'value': 0
            },
            {
                'name': 'BUS_TYPE_VAL_BUS_AT',
                'value': 1
            },
            {
                'name': 'BUS_TYPE_VAL_BUS_PCI',
                'value': 2
            },
            {
                'name': 'BUS_TYPE_VAL_BUS_PXI',
                'value': 3
            },
            {
                'name': 'BUS_TYPE_VAL_BUS_VXI',
                'value': 4
            },
            {
                'name': 'BUS_TYPE_VAL_BUS_PCMCIA',
                'value': 5
            },
            {
                'name': 'BUS_TYPE_VAL_BUS_PXIE',
                'value': 6
            },
            {
                'name': 'CLOCK_MODE_VAL_HIGH_RESOLUTION',
                'value': 0
            },
            {
                'name': 'CLOCK_MODE_VAL_DIVIDE_DOWN',
                'value': 1
            },
            {
                'name': 'CLOCK_MODE_VAL_AUTOMATIC',
                'value': 2
            },
            {
                'name': 'DATA_MARKER_EVENT_LEVEL_POLARITY_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'DATA_MARKER_EVENT_LEVEL_POLARITY_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'DATA_PROCESSING_MODE_VAL_OSP_REAL',
                'value': 0
            },
            {
                'name': 'DATA_PROCESSING_MODE_VAL_OSP_COMPLEX',
                'value': 1
            },
            {
                'name': 'DONE_EVENT_ACTIVE_LEVEL_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_ACTIVE_LEVEL_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_DELAY_UNITS_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_DELAY_UNITS_VAL_SECONDS',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_OUTPUT_BEHAVIOR_VAL_PULSE',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_OUTPUT_BEHAVIOR_VAL_LEVEL',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_PULSE_POLARITY_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_PULSE_POLARITY_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_PULSE_WIDTH_UNITS_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_PULSE_WIDTH_UNITS_VAL_SECONDS',
                'value': 102
            },
            {
                'name': 'FILTER_TYPE_VAL_OSP_FLAT',
                'value': 0
            },
            {
                'name': 'FILTER_TYPE_VAL_OSP_RAISED_COSINE',
                'value': 1
            },
            {
                'name': 'FILTER_TYPE_VAL_OSP_ROOT_RAISED_COSINE',
                'value': 2
            },
            {
                'name': 'FILTER_TYPE_VAL_OSP_GAUSSIAN',
                'value': 3
            },
            {
                'name': 'FILTER_TYPE_VAL_OSP_CUSTOM',
                'value': 4
            },
            {
                'name': 'FREQUENCY_LIST_HANDLE_VAL_FIRST_FREQ_LIST_HANDLE',
                'value': 200000
            },
            {
                'name': 'FREQUENCY_LIST_HANDLE_VAL_LAST_FREQ_LIST_HANDLE',
                'value': 209999
            },
            {
                'name': 'FREQUENCY_LIST_HANDLE_VAL_NO_FREQ_LIST',
                'value': -1
            },
            {
                'name': 'IDLE_BEHAVIOR_VAL_HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'IDLE_BEHAVIOR_VAL_JUMP_TO_VALUE',
                'value': 401
            },
            {
                'name': 'MARKER_EVENT_DELAY_UNITS_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_DELAY_UNITS_VAL_SECONDS',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_VAL_PULSE',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_VAL_LEVEL',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_VAL_TOGGLE',
                'value': 103
            },
            {
                'name': 'MARKER_EVENT_PULSE_POLARITY_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_PULSE_POLARITY_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS_VAL_SECONDS',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE_VAL_HIGH',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE_VAL_LOW',
                'value': 102
            },
            {
                'name': 'OSP_MODE_VAL_OSP_IF',
                'value': 0
            },
            {
                'name': 'OSP_MODE_VAL_OSP_BASEBAND',
                'value': 1
            },
            {
                'name': 'OSP_OVERFLOW_ERROR_REPORTING_VAL_ERROR_REPORTING_ERROR',
                'value': 0
            },
            {
                'name': 'OSP_OVERFLOW_ERROR_REPORTING_VAL_ERROR_REPORTING_DISABLED',
                'value': 2
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_NONE',
                'value': 0
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_I',
                'value': 1
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_Q',
                'value': 2
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_I',
                'value': 4
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_Q',
                'value': 8
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_FIR_FILTER_I',
                'value': 16
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_PFIR_FILTER_I',
                'value': 16
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_FIR_FILTER_Q',
                'value': 32
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_PFIR_FILTER_Q',
                'value': 32
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_CIC_FILTER_I',
                'value': 64
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_CIC_FILTER_Q',
                'value': 128
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_COMPLEX_DATA',
                'value': 256
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_CFIR_FILTER_I',
                'value': 512
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_CFIR_FILTER_Q',
                'value': 1024
            },
            {
                'name': 'OSP_OVERFLOW_STATUS_VAL_OSP_OVERFLOW_EQUALIZER',
                'value': 2048
            },
            {
                'name': 'OUTPUT_MODE_VAL_OUTPUT_FUNC',
                'value': 0
            },
            {
                'name': 'OUTPUT_MODE_VAL_OUTPUT_ARB',
                'value': 1
            },
            {
                'name': 'OUTPUT_MODE_VAL_OUTPUT_SEQ',
                'value': 2
            },
            {
                'name': 'OUTPUT_MODE_VAL_OUTPUT_FREQ_LIST',
                'value': 101
            },
            {
                'name': 'OUTPUT_MODE_VAL_OUTPUT_SCRIPT',
                'value': 102
            },
            {
                'name': 'READY_FOR_START_EVENT_ACTIVE_LEVEL_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'READY_FOR_START_EVENT_ACTIVE_LEVEL_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_EDGE_EDGE_VAL_RISING_EDGE',
                'value': 101
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_EDGE_EDGE_VAL_FALLING_EDGE',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_LEVEL_ACTIVE_LEVEL_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_LEVEL_ACTIVE_LEVEL_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_VAL_TRIG_NONE',
                'value': 101
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_VAL_DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_VAL_DIGITAL_LEVEL',
                'value': 103
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_VAL_SOFTWARE_EDGE',
                'value': 104
            },
            {
                'name': 'START_TRIGGER_DIGITAL_EDGE_EDGE_VAL_RISING_EDGE',
                'value': 101
            },
            {
                'name': 'START_TRIGGER_DIGITAL_EDGE_EDGE_VAL_FALLING_EDGE',
                'value': 102
            },
            {
                'name': 'START_TRIGGER_TYPE_VAL_TRIG_NONE',
                'value': 101
            },
            {
                'name': 'START_TRIGGER_TYPE_VAL_DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'START_TRIGGER_TYPE_VAL_SOFTWARE_EDGE',
                'value': 104
            },
            {
                'name': 'START_TRIGGER_TYPE_VAL_P2P_ENDPOINT_FULLNESS',
                'value': 106
            },
            {
                'name': 'STARTED_EVENT_ACTIVE_LEVEL_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_ACTIVE_LEVEL_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_DELAY_UNITS_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_DELAY_UNITS_VAL_SECONDS',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_OUTPUT_BEHAVIOR_VAL_PULSE',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_OUTPUT_BEHAVIOR_VAL_LEVEL',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_PULSE_POLARITY_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_PULSE_POLARITY_VAL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_PULSE_WIDTH_UNITS_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_PULSE_WIDTH_UNITS_VAL_SECONDS',
                'value': 102
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_TTL0',
                'value': 111
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_TTL1',
                'value': 112
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_TTL2',
                'value': 113
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_TTL3',
                'value': 114
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_TTL4',
                'value': 115
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_TTL5',
                'value': 116
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_TTL6',
                'value': 117
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_VAL_NONE',
                'value': 1000
            },
            {
                'name': 'TERMINAL_CONFIGURATION_VAL_SINGLE_ENDED',
                'value': 300
            },
            {
                'name': 'TERMINAL_CONFIGURATION_VAL_DIFFERENTIAL',
                'value': 301
            },
            {
                'name': 'TRIGGER_MODE_VAL_SINGLE',
                'value': 1
            },
            {
                'name': 'TRIGGER_MODE_VAL_CONTINUOUS',
                'value': 2
            },
            {
                'name': 'TRIGGER_MODE_VAL_STEPPED',
                'value': 3
            },
            {
                'name': 'TRIGGER_MODE_VAL_BURST',
                'value': 4
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_IMMEDIATE',
                'value': 0
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_EXTERNAL',
                'value': 1
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_SOFTWARE_TRIG',
                'value': 2
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL0',
                'value': 111
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL1',
                'value': 112
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL2',
                'value': 113
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL3',
                'value': 114
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL4',
                'value': 115
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL5',
                'value': 116
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL6',
                'value': 117
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_7',
                'value': 1010
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_0',
                'value': 1011
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_1',
                'value': 1012
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_2',
                'value': 1013
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_3',
                'value': 1014
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_OTHER_TERMINAL',
                'value': 1018
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_INTERNAL',
                'value': 0
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_EXTERNAL',
                'value': 1
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_TTL1',
                'value': 112
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_TTL2',
                'value': 113
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_TTL3',
                'value': 114
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_TTL4',
                'value': 115
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_TTL5',
                'value': 116
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_TTL6',
                'value': 117
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_RTSI_7',
                'value': 1010
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_OTHER_TERMINAL',
                'value': 1018
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_CLK_IN',
                'value': 1202
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_VAL_DDC_CLK_IN',
                'value': 1203
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_PAL_B',
                'value': 0
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_PAL_D',
                'value': 1
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_PAL_G',
                'value': 2
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_PAL_H',
                'value': 3
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_PAL_I',
                'value': 4
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_PAL_M',
                'value': 5
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_PAL_N',
                'value': 6
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_VAL_NTSC_M',
                'value': 7
            },
            {
                'name': 'WAIT_BEHAVIOR_VAL_HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'WAIT_BEHAVIOR_VAL_JUMP_TO_VALUE',
                'value': 401
            },
            {
                'name': 'WAVEFORM_VAL_WFM_SINE',
                'value': 1
            },
            {
                'name': 'WAVEFORM_VAL_WFM_SQUARE',
                'value': 2
            },
            {
                'name': 'WAVEFORM_VAL_WFM_TRIANGLE',
                'value': 3
            },
            {
                'name': 'WAVEFORM_VAL_WFM_RAMP_UP',
                'value': 4
            },
            {
                'name': 'WAVEFORM_VAL_WFM_RAMP_DOWN',
                'value': 5
            },
            {
                'name': 'WAVEFORM_VAL_WFM_DC',
                'value': 6
            },
            {
                'name': 'WAVEFORM_VAL_WFM_NOISE',
                'value': 101
            },
            {
                'name': 'WAVEFORM_VAL_WFM_USER',
                'value': 102
            }
        ]
    },
    'NiFgenReal64AttributeValues': {
        'enum-value-prefix': 'NIFGEN_REAL64',
        'generate-mappings': False,
        'values': [
            {
                'name': 'LOAD_IMPEDANCE_VAL_MATCHED_LOAD_IMPEDANCE',
                'value': -1
            },
            {
                'name': 'OUTPUT_IMPEDANCE_VAL_50_OHMS',
                'value': 50
            },
            {
                'name': 'OUTPUT_IMPEDANCE_VAL_75_OHMS',
                'value': 75
            },
            {
                'name': 'SAMPLE_RATE_VAL_EXTERNAL_SAMPLE_RATE',
                'value': -1
            }
        ]
    },
    'NiFgenStringAttributeValuesMapped': {
        'enum-value-prefix': 'NIFGEN_STRING',
        'generate-mappings': True,
        'values': [
            {
                'name': 'REFERENCE_CLOCK_SOURCE_VAL_CLOCK_IN_COLLISION_AVOIDANCE',
                'value': 'ClkIn'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_VAL_NONE_COLLISION_AVOIDANCE',
                'value': 'None'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_VAL_ONBOARD_REFERENCE_CLOCK_COLLISION_AVOIDANCE',
                'value': 'OnboardRefClk'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_VAL_PXI_CLOCK_COLLISION_AVOIDANCE',
                'value': 'PXI_Clk'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_VAL_RTSI_7_COLLISION_AVOIDANCE',
                'value': 'RTSI7'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_DDC_CLOCK_IN',
                'value': 'DDC_ClkIn'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_STAR_LINE',
                'value': 'PXI_Star'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_0_RTSI_0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_1_RTSI_1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_2_RTSI_2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_3_RTSI_3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_4_RTSI_4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_5_RTSI_5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_6_RTSI_6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_VAL_PXI_TRIGGER_LINE_7_RTSI_7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'SAMPLE_CLOCK_TIMEBASE_SOURCE_VAL_CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'SAMPLE_CLOCK_TIMEBASE_SOURCE_VAL_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            }
        ]
    },
    'OspMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_OSP_IF',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_OSP_BASEBAND',
                'value': 1
            }
        ]
    },
    'OspOverflowErrorReporting': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ERROR_REPORTING_ERROR',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_ERROR_REPORTING_DISABLED',
                'value': 2
            }
        ]
    },
    'OspOverflowStatus': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_NONE',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_I',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_Q',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_I',
                'value': 4
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_Q',
                'value': 8
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_FIR_FILTER_I',
                'value': 16
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_PFIR_FILTER_I',
                'value': 16
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_FIR_FILTER_Q',
                'value': 32
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_PFIR_FILTER_Q',
                'value': 32
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_CIC_FILTER_I',
                'value': 64
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_CIC_FILTER_Q',
                'value': 128
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_COMPLEX_DATA',
                'value': 256
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_CFIR_FILTER_I',
                'value': 512
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_CFIR_FILTER_Q',
                'value': 1024
            },
            {
                'name': 'NIFGEN_VAL_OSP_OVERFLOW_EQUALIZER',
                'value': 2048
            }
        ]
    },
    'OutputImpedance': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_50_OHMS',
                'value': 50
            },
            {
                'name': 'NIFGEN_VAL_75_OHMS',
                'value': 75
            }
        ]
    },
    'OutputMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_OUTPUT_FUNC',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_OUTPUT_ARB',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_OUTPUT_SEQ',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_OUTPUT_FREQ_LIST',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_OUTPUT_SCRIPT',
                'value': 102
            }
        ]
    },
    'ReadyForStartEventActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'ReferenceClockSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIFGEN_VAL_CLOCK_IN_COLLISION_AVOIDANCE',
                'value': 'ClkIn'
            },
            {
                'name': 'NIFGEN_VAL_NONE_COLLISION_AVOIDANCE',
                'value': 'None'
            },
            {
                'name': 'NIFGEN_VAL_ONBOARD_REFERENCE_CLOCK_COLLISION_AVOIDANCE',
                'value': 'OnboardRefClk'
            },
            {
                'name': 'NIFGEN_VAL_PXI_CLOCK_COLLISION_AVOIDANCE',
                'value': 'PXI_Clk'
            },
            {
                'name': 'NIFGEN_VAL_RTSI_7_COLLISION_AVOIDANCE',
                'value': 'RTSI7'
            }
        ]
    },
    'RelativeTo': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_WAVEFORM_POSITION_START',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_WAVEFORM_POSITION_CURRENT',
                'value': 1
            }
        ]
    },
    'RouteSignalFrom': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_MARKER',
                'value': 1001
            },
            {
                'name': 'NIFGEN_VAL_SYNC_OUT',
                'value': 1002
            },
            {
                'name': 'NIFGEN_VAL_OUT_START_TRIGGER',
                'value': 1004
            },
            {
                'name': 'NIFGEN_VAL_BOARD_CLOCK',
                'value': 1006
            },
            {
                'name': 'NIFGEN_VAL_SYNCHRONIZATION',
                'value': 1007
            },
            {
                'name': 'NIFGEN_VAL_SOFTWARE_TRIG',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_REF_OUT',
                'value': 1008
            },
            {
                'name': 'NIFGEN_VAL_CLOCK_OUT',
                'value': 1009
            },
            {
                'name': 'NIFGEN_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'NIFGEN_VAL_PFI_0',
                'value': 1011
            },
            {
                'name': 'NIFGEN_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'NIFGEN_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'NIFGEN_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'NIFGEN_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'NIFGEN_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'NIFGEN_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'NIFGEN_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'NIFGEN_VAL_RTSI_7',
                'value': 1010
            },
            {
                'name': 'NIFGEN_VAL_ONBOARD_REFERENCE_CLOCK',
                'value': 1019
            }
        ]
    },
    'RouteSignalTo': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'NIFGEN_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'NIFGEN_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'NIFGEN_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'NIFGEN_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'NIFGEN_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'NIFGEN_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'NIFGEN_VAL_RTSI_7',
                'value': 1010
            },
            {
                'name': 'NIFGEN_VAL_REF_OUT',
                'value': 1008
            },
            {
                'name': 'NIFGEN_VAL_PFI_0',
                'value': 1011
            },
            {
                'name': 'NIFGEN_VAL_PFI_1',
                'value': 1012
            },
            {
                'name': 'NIFGEN_VAL_PXI_STAR',
                'value': 131
            }
        ]
    },
    'SampleClockSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIFGEN_VAL_CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'NIFGEN_VAL_DDC_CLOCK_IN',
                'value': 'DDC_ClkIn'
            },
            {
                'name': 'NIFGEN_VAL_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'NIFGEN_VAL_PXI_STAR_LINE',
                'value': 'PXI_Star'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_0_RTSI_0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_1_RTSI_1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_2_RTSI_2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_3_RTSI_3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_4_RTSI_4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_5_RTSI_5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_6_RTSI_6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'NIFGEN_VAL_PXI_TRIGGER_LINE_7_RTSI_7',
                'value': 'PXI_Trig7'
            }
        ]
    },
    'SampleClockTimebaseSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIFGEN_VAL_CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'NIFGEN_VAL_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            }
        ]
    },
    'SampleRate': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_EXTERNAL_SAMPLE_RATE',
                'value': -1
            }
        ]
    },
    'ScriptTriggerDigitalEdgeEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_RISING_EDGE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_FALLING_EDGE',
                'value': 102
            }
        ]
    },
    'ScriptTriggerDigitalLevelActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'ScriptTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_TRIG_NONE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'NIFGEN_VAL_DIGITAL_LEVEL',
                'value': 103
            },
            {
                'name': 'NIFGEN_VAL_SOFTWARE_EDGE',
                'value': 104
            }
        ]
    },
    'SequenceHandle': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ALL_SEQUENCES',
                'value': -1
            }
        ]
    },
    'Signal': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ONBOARD_REFERENCE_CLOCK',
                'value': 1019
            },
            {
                'name': 'NIFGEN_VAL_SYNC_OUT',
                'value': 1002
            },
            {
                'name': 'NIFGEN_VAL_START_TRIGGER',
                'value': 1004
            },
            {
                'name': 'NIFGEN_VAL_MARKER_EVENT',
                'value': 1001
            },
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK_TIMEBASE',
                'value': 1006
            },
            {
                'name': 'NIFGEN_VAL_SYNCHRONIZATION',
                'value': 1007
            },
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_REFERENCE_CLOCK',
                'value': 102
            },
            {
                'name': 'NIFGEN_VAL_SCRIPT_TRIGGER',
                'value': 103
            },
            {
                'name': 'NIFGEN_VAL_READY_FOR_START_EVENT',
                'value': 105
            },
            {
                'name': 'NIFGEN_VAL_STARTED_EVENT',
                'value': 106
            },
            {
                'name': 'NIFGEN_VAL_DONE_EVENT',
                'value': 107
            },
            {
                'name': 'NIFGEN_VAL_DATA_MARKER_EVENT',
                'value': 108
            }
        ]
    },
    'StartTriggerDigitalEdgeEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_RISING_EDGE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_FALLING_EDGE',
                'value': 102
            }
        ]
    },
    'StartTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_TRIG_NONE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'NIFGEN_VAL_SOFTWARE_EDGE',
                'value': 104
            },
            {
                'name': 'NIFGEN_VAL_P2P_ENDPOINT_FULLNESS',
                'value': 106
            }
        ]
    },
    'StartedEventActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'StartedEventDelayUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_SECONDS',
                'value': 102
            }
        ]
    },
    'StartedEventOutputBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_PULSE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_LEVEL',
                'value': 102
            }
        ]
    },
    'StartedEventPulsePolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'StartedEventPulseWidthUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_SECONDS',
                'value': 102
            }
        ]
    },
    'SynchronizationSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_TTL0',
                'value': 111
            },
            {
                'name': 'NIFGEN_VAL_TTL1',
                'value': 112
            },
            {
                'name': 'NIFGEN_VAL_TTL2',
                'value': 113
            },
            {
                'name': 'NIFGEN_VAL_TTL3',
                'value': 114
            },
            {
                'name': 'NIFGEN_VAL_TTL4',
                'value': 115
            },
            {
                'name': 'NIFGEN_VAL_TTL5',
                'value': 116
            },
            {
                'name': 'NIFGEN_VAL_TTL6',
                'value': 117
            },
            {
                'name': 'NIFGEN_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'NIFGEN_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'NIFGEN_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'NIFGEN_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'NIFGEN_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'NIFGEN_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'NIFGEN_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'NIFGEN_VAL_NONE',
                'value': 1000
            }
        ]
    },
    'TerminalConfiguration': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SINGLE_ENDED',
                'value': 300
            },
            {
                'name': 'NIFGEN_VAL_DIFFERENTIAL',
                'value': 301
            }
        ]
    },
    'Trigger': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_START_TRIGGER',
                'value': 1004
            },
            {
                'name': 'NIFGEN_VAL_SCRIPT_TRIGGER',
                'value': 103
            }
        ]
    },
    'TriggerMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_SINGLE',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_CONTINUOUS',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_STEPPED',
                'value': 3
            },
            {
                'name': 'NIFGEN_VAL_BURST',
                'value': 4
            }
        ]
    },
    'TriggerSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_IMMEDIATE',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_EXTERNAL',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_SOFTWARE_TRIG',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_TTL0',
                'value': 111
            },
            {
                'name': 'NIFGEN_VAL_TTL1',
                'value': 112
            },
            {
                'name': 'NIFGEN_VAL_TTL2',
                'value': 113
            },
            {
                'name': 'NIFGEN_VAL_TTL3',
                'value': 114
            },
            {
                'name': 'NIFGEN_VAL_TTL4',
                'value': 115
            },
            {
                'name': 'NIFGEN_VAL_TTL5',
                'value': 116
            },
            {
                'name': 'NIFGEN_VAL_TTL6',
                'value': 117
            },
            {
                'name': 'NIFGEN_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'NIFGEN_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'NIFGEN_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'NIFGEN_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'NIFGEN_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'NIFGEN_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'NIFGEN_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'NIFGEN_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'NIFGEN_VAL_RTSI_7',
                'value': 1010
            },
            {
                'name': 'NIFGEN_VAL_PFI_0',
                'value': 1011
            },
            {
                'name': 'NIFGEN_VAL_PFI_1',
                'value': 1012
            },
            {
                'name': 'NIFGEN_VAL_PFI_2',
                'value': 1013
            },
            {
                'name': 'NIFGEN_VAL_PFI_3',
                'value': 1014
            },
            {
                'name': 'NIFGEN_VAL_OTHER_TERMINAL',
                'value': 1018
            }
        ]
    },
    'TriggerWhen': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'UpdateClockSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_INTERNAL',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_EXTERNAL',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_TTL1',
                'value': 112
            },
            {
                'name': 'NIFGEN_VAL_TTL2',
                'value': 113
            },
            {
                'name': 'NIFGEN_VAL_TTL3',
                'value': 114
            },
            {
                'name': 'NIFGEN_VAL_TTL4',
                'value': 115
            },
            {
                'name': 'NIFGEN_VAL_TTL5',
                'value': 116
            },
            {
                'name': 'NIFGEN_VAL_TTL6',
                'value': 117
            },
            {
                'name': 'NIFGEN_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'NIFGEN_VAL_RTSI_0',
                'value': 141
            },
            {
                'name': 'NIFGEN_VAL_RTSI_1',
                'value': 142
            },
            {
                'name': 'NIFGEN_VAL_RTSI_2',
                'value': 143
            },
            {
                'name': 'NIFGEN_VAL_RTSI_3',
                'value': 144
            },
            {
                'name': 'NIFGEN_VAL_RTSI_4',
                'value': 145
            },
            {
                'name': 'NIFGEN_VAL_RTSI_5',
                'value': 146
            },
            {
                'name': 'NIFGEN_VAL_RTSI_6',
                'value': 147
            },
            {
                'name': 'NIFGEN_VAL_RTSI_7',
                'value': 1010
            },
            {
                'name': 'NIFGEN_VAL_OTHER_TERMINAL',
                'value': 1018
            },
            {
                'name': 'NIFGEN_VAL_CLK_IN',
                'value': 1202
            },
            {
                'name': 'NIFGEN_VAL_DDC_CLK_IN',
                'value': 1203
            }
        ]
    },
    'VideoWaveformType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_PAL_B',
                'value': 0
            },
            {
                'name': 'NIFGEN_VAL_PAL_D',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_PAL_G',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_PAL_H',
                'value': 3
            },
            {
                'name': 'NIFGEN_VAL_PAL_I',
                'value': 4
            },
            {
                'name': 'NIFGEN_VAL_PAL_M',
                'value': 5
            },
            {
                'name': 'NIFGEN_VAL_PAL_N',
                'value': 6
            },
            {
                'name': 'NIFGEN_VAL_NTSC_M',
                'value': 7
            }
        ]
    },
    'WaitBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'NIFGEN_VAL_JUMP_TO_VALUE',
                'value': 401
            }
        ]
    },
    'Waveform': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_WFM_SINE',
                'value': 1
            },
            {
                'name': 'NIFGEN_VAL_WFM_SQUARE',
                'value': 2
            },
            {
                'name': 'NIFGEN_VAL_WFM_TRIANGLE',
                'value': 3
            },
            {
                'name': 'NIFGEN_VAL_WFM_RAMP_UP',
                'value': 4
            },
            {
                'name': 'NIFGEN_VAL_WFM_RAMP_DOWN',
                'value': 5
            },
            {
                'name': 'NIFGEN_VAL_WFM_DC',
                'value': 6
            },
            {
                'name': 'NIFGEN_VAL_WFM_NOISE',
                'value': 101
            },
            {
                'name': 'NIFGEN_VAL_WFM_USER',
                'value': 102
            }
        ]
    },
    'WaveformHandle': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIFGEN_VAL_ALL_WAVEFORMS',
                'value': -1
            }
        ]
    }
}
