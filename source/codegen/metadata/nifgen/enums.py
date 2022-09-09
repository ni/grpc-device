# -*- coding: utf-8 -*-
# This file is generated from NI-FGEN API metadata version 22.8.0d9999
enums = {
    'AnalogPath': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'MAIN_ANALOG_PATH',
                'value': 0
            },
            {
                'name': 'DIRECT_ANALOG_PATH',
                'value': 1
            },
            {
                'name': 'FIXED_LOW_GAIN_ANALOG_PATH',
                'value': 2
            },
            {
                'name': 'FIXED_HIGH_GAIN_ANALOG_PATH',
                'value': 3
            }
        ]
    },
    'BusType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'BUS_INVALID',
                'value': 0
            },
            {
                'name': 'BUS_AT',
                'value': 1
            },
            {
                'name': 'BUS_PCI',
                'value': 2
            },
            {
                'name': 'BUS_PXI',
                'value': 3
            },
            {
                'name': 'BUS_VXI',
                'value': 4
            },
            {
                'name': 'BUS_PCMCIA',
                'value': 5
            },
            {
                'name': 'BUS_PXIE',
                'value': 6
            }
        ]
    },
    'ByteOrder': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'LITTLE_ENDIAN',
                'value': 0
            },
            {
                'name': 'BIG_ENDIAN',
                'value': 1
            }
        ]
    },
    'ClockMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HIGH_RESOLUTION',
                'value': 0
            },
            {
                'name': 'DIVIDE_DOWN',
                'value': 1
            },
            {
                'name': 'AUTOMATIC',
                'value': 2
            }
        ]
    },
    'DataMarkerEventLevelPolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'DataProcessingMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'OSP_REAL',
                'value': 0
            },
            {
                'name': 'OSP_COMPLEX',
                'value': 1
            }
        ]
    },
    'DoneEventActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'DoneEventDelayUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'SECONDS',
                'value': 102
            }
        ]
    },
    'DoneEventOutputBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PULSE',
                'value': 101
            },
            {
                'name': 'LEVEL',
                'value': 102
            }
        ]
    },
    'DoneEventPulsePolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'DoneEventPulseWidthUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'SECONDS',
                'value': 102
            }
        ]
    },
    'FilterType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'OSP_FLAT',
                'value': 0
            },
            {
                'name': 'OSP_RAISED_COSINE',
                'value': 1
            },
            {
                'name': 'OSP_ROOT_RAISED_COSINE',
                'value': 2
            },
            {
                'name': 'OSP_GAUSSIAN',
                'value': 3
            },
            {
                'name': 'OSP_CUSTOM',
                'value': 4
            }
        ]
    },
    'HardwareState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'IDLE',
                'value': 0
            },
            {
                'name': 'WAITING_FOR_START_TRIGGER',
                'value': 100
            },
            {
                'name': 'RUNNING',
                'value': 200
            },
            {
                'name': 'DONE',
                'value': 600
            },
            {
                'name': 'HARDWARE_ERROR',
                'value': 1000
            }
        ]
    },
    'IdleBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'JUMP_TO_VALUE',
                'value': 401
            }
        ]
    },
    'MarkerEventDelayUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'SECONDS',
                'value': 102
            }
        ]
    },
    'MarkerEventOutputBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PULSE',
                'value': 101
            },
            {
                'name': 'LEVEL',
                'value': 102
            },
            {
                'name': 'TOGGLE',
                'value': 103
            }
        ]
    },
    'MarkerEventPulsePolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'MarkerEventPulseWidthUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'SECONDS',
                'value': 102
            }
        ]
    },
    'MarkerEventToggleInitialState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HIGH',
                'value': 101
            },
            {
                'name': 'LOW',
                'value': 102
            }
        ]
    },
    'NiFgenInt32AttributeValues': {
        'enum-value-prefix': 'NIFGEN_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'ANALOG_PATH_MAIN_ANALOG_PATH',
                'value': 0
            },
            {
                'name': 'ANALOG_PATH_DIRECT_ANALOG_PATH',
                'value': 1
            },
            {
                'name': 'ANALOG_PATH_FIXED_LOW_GAIN_ANALOG_PATH',
                'value': 2
            },
            {
                'name': 'ANALOG_PATH_FIXED_HIGH_GAIN_ANALOG_PATH',
                'value': 3
            },
            {
                'name': 'BUS_TYPE_BUS_INVALID',
                'value': 0
            },
            {
                'name': 'BUS_TYPE_BUS_AT',
                'value': 1
            },
            {
                'name': 'BUS_TYPE_BUS_PCI',
                'value': 2
            },
            {
                'name': 'BUS_TYPE_BUS_PXI',
                'value': 3
            },
            {
                'name': 'BUS_TYPE_BUS_VXI',
                'value': 4
            },
            {
                'name': 'BUS_TYPE_BUS_PCMCIA',
                'value': 5
            },
            {
                'name': 'BUS_TYPE_BUS_PXIE',
                'value': 6
            },
            {
                'name': 'CLOCK_MODE_HIGH_RESOLUTION',
                'value': 0
            },
            {
                'name': 'CLOCK_MODE_DIVIDE_DOWN',
                'value': 1
            },
            {
                'name': 'CLOCK_MODE_AUTOMATIC',
                'value': 2
            },
            {
                'name': 'DATA_MARKER_EVENT_LEVEL_POLARITY_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'DATA_MARKER_EVENT_LEVEL_POLARITY_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'DATA_PROCESSING_MODE_OSP_REAL',
                'value': 0
            },
            {
                'name': 'DATA_PROCESSING_MODE_OSP_COMPLEX',
                'value': 1
            },
            {
                'name': 'DONE_EVENT_ACTIVE_LEVEL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_ACTIVE_LEVEL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_DELAY_UNITS_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_DELAY_UNITS_SECONDS',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_OUTPUT_BEHAVIOR_PULSE',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_OUTPUT_BEHAVIOR_LEVEL',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_PULSE_POLARITY_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_PULSE_POLARITY_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'DONE_EVENT_PULSE_WIDTH_UNITS_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'DONE_EVENT_PULSE_WIDTH_UNITS_SECONDS',
                'value': 102
            },
            {
                'name': 'FILTER_TYPE_OSP_FLAT',
                'value': 0
            },
            {
                'name': 'FILTER_TYPE_OSP_RAISED_COSINE',
                'value': 1
            },
            {
                'name': 'FILTER_TYPE_OSP_ROOT_RAISED_COSINE',
                'value': 2
            },
            {
                'name': 'FILTER_TYPE_OSP_GAUSSIAN',
                'value': 3
            },
            {
                'name': 'FILTER_TYPE_OSP_CUSTOM',
                'value': 4
            },
            {
                'name': 'IDLE_BEHAVIOR_HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'IDLE_BEHAVIOR_JUMP_TO_VALUE',
                'value': 401
            },
            {
                'name': 'MARKER_EVENT_DELAY_UNITS_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_DELAY_UNITS_SECONDS',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_PULSE',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_LEVEL',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR_TOGGLE',
                'value': 103
            },
            {
                'name': 'MARKER_EVENT_PULSE_POLARITY_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_PULSE_POLARITY_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS_SECONDS',
                'value': 102
            },
            {
                'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE_HIGH',
                'value': 101
            },
            {
                'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE_LOW',
                'value': 102
            },
            {
                'name': 'OPERATION_MODE_OPERATE_CONTINUOUS',
                'value': 0
            },
            {
                'name': 'OSP_MODE_OSP_IF',
                'value': 0
            },
            {
                'name': 'OSP_MODE_OSP_BASEBAND',
                'value': 1
            },
            {
                'name': 'OSP_OVERFLOW_ERROR_REPORTING_ERROR_REPORTING_ERROR',
                'value': 0
            },
            {
                'name': 'OSP_OVERFLOW_ERROR_REPORTING_ERROR_REPORTING_DISABLED',
                'value': 2
            },
            {
                'name': 'OUTPUT_MODE_OUTPUT_FUNC',
                'value': 0
            },
            {
                'name': 'OUTPUT_MODE_OUTPUT_ARB',
                'value': 1
            },
            {
                'name': 'OUTPUT_MODE_OUTPUT_SEQ',
                'value': 2
            },
            {
                'name': 'OUTPUT_MODE_OUTPUT_FREQ_LIST',
                'value': 101
            },
            {
                'name': 'OUTPUT_MODE_OUTPUT_SCRIPT',
                'value': 102
            },
            {
                'name': 'P2_P_ADDRESS_TYPE_ADDR_PHYSICAL',
                'value': 0
            },
            {
                'name': 'P2_P_ADDRESS_TYPE_ADDR_VIRTUAL',
                'value': 1
            },
            {
                'name': 'READY_FOR_START_EVENT_ACTIVE_LEVEL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'READY_FOR_START_EVENT_ACTIVE_LEVEL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_EDGE_EDGE_RISING_EDGE',
                'value': 101
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_EDGE_EDGE_FALLING_EDGE',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_LEVEL_ACTIVE_LEVEL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'SCRIPT_TRIGGER_DIGITAL_LEVEL_ACTIVE_LEVEL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_TRIG_NONE',
                'value': 101
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_DIGITAL_LEVEL',
                'value': 103
            },
            {
                'name': 'SCRIPT_TRIGGER_TYPE_SOFTWARE_EDGE',
                'value': 104
            },
            {
                'name': 'START_TRIGGER_DIGITAL_EDGE_EDGE_RISING_EDGE',
                'value': 101
            },
            {
                'name': 'START_TRIGGER_DIGITAL_EDGE_EDGE_FALLING_EDGE',
                'value': 102
            },
            {
                'name': 'START_TRIGGER_TYPE_TRIG_NONE',
                'value': 101
            },
            {
                'name': 'START_TRIGGER_TYPE_DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'START_TRIGGER_TYPE_SOFTWARE_EDGE',
                'value': 104
            },
            {
                'name': 'START_TRIGGER_TYPE_P2P_ENDPOINT_FULLNESS',
                'value': 106
            },
            {
                'name': 'STARTED_EVENT_ACTIVE_LEVEL_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_ACTIVE_LEVEL_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_DELAY_UNITS_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_DELAY_UNITS_SECONDS',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_OUTPUT_BEHAVIOR_PULSE',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_OUTPUT_BEHAVIOR_LEVEL',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_PULSE_POLARITY_ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_PULSE_POLARITY_ACTIVE_LOW',
                'value': 102
            },
            {
                'name': 'STARTED_EVENT_PULSE_WIDTH_UNITS_SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'STARTED_EVENT_PULSE_WIDTH_UNITS_SECONDS',
                'value': 102
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_TTL0',
                'value': 111
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_TTL1',
                'value': 112
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_TTL2',
                'value': 113
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_TTL3',
                'value': 114
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_TTL4',
                'value': 115
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_TTL5',
                'value': 116
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_TTL6',
                'value': 117
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_RTSI_0',
                'value': 141
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_RTSI_1',
                'value': 142
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_RTSI_2',
                'value': 143
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_RTSI_3',
                'value': 144
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_RTSI_4',
                'value': 145
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_RTSI_5',
                'value': 146
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_RTSI_6',
                'value': 147
            },
            {
                'name': 'SYNCHRONIZATION_SOURCE_NONE',
                'value': 1000
            },
            {
                'name': 'TERMINAL_CONFIGURATION_SINGLE_ENDED',
                'value': 300
            },
            {
                'name': 'TERMINAL_CONFIGURATION_DIFFERENTIAL',
                'value': 301
            },
            {
                'name': 'TRIGGER_MODE_SINGLE',
                'value': 1
            },
            {
                'name': 'TRIGGER_MODE_CONTINUOUS',
                'value': 2
            },
            {
                'name': 'TRIGGER_MODE_STEPPED',
                'value': 3
            },
            {
                'name': 'TRIGGER_MODE_BURST',
                'value': 4
            },
            {
                'name': 'TRIGGER_SOURCE_IMMEDIATE',
                'value': 0
            },
            {
                'name': 'TRIGGER_SOURCE_EXTERNAL',
                'value': 1
            },
            {
                'name': 'TRIGGER_SOURCE_SOFTWARE_TRIG',
                'value': 2
            },
            {
                'name': 'TRIGGER_SOURCE_TTL0',
                'value': 111
            },
            {
                'name': 'TRIGGER_SOURCE_TTL1',
                'value': 112
            },
            {
                'name': 'TRIGGER_SOURCE_TTL2',
                'value': 113
            },
            {
                'name': 'TRIGGER_SOURCE_TTL3',
                'value': 114
            },
            {
                'name': 'TRIGGER_SOURCE_TTL4',
                'value': 115
            },
            {
                'name': 'TRIGGER_SOURCE_TTL5',
                'value': 116
            },
            {
                'name': 'TRIGGER_SOURCE_TTL6',
                'value': 117
            },
            {
                'name': 'TRIGGER_SOURCE_PXI_STAR',
                'value': 131
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_0',
                'value': 141
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_1',
                'value': 142
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_2',
                'value': 143
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_3',
                'value': 144
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_4',
                'value': 145
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_5',
                'value': 146
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_6',
                'value': 147
            },
            {
                'name': 'TRIGGER_SOURCE_RTSI_7',
                'value': 1010
            },
            {
                'name': 'TRIGGER_SOURCE_PFI_0',
                'value': 1011
            },
            {
                'name': 'TRIGGER_SOURCE_PFI_1',
                'value': 1012
            },
            {
                'name': 'TRIGGER_SOURCE_PFI_2',
                'value': 1013
            },
            {
                'name': 'TRIGGER_SOURCE_PFI_3',
                'value': 1014
            },
            {
                'name': 'TRIGGER_SOURCE_OTHER_TERMINAL',
                'value': 1018
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_INTERNAL',
                'value': 0
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_EXTERNAL',
                'value': 1
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_TTL1',
                'value': 112
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_TTL2',
                'value': 113
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_TTL3',
                'value': 114
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_TTL4',
                'value': 115
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_TTL5',
                'value': 116
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_TTL6',
                'value': 117
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_PXI_STAR',
                'value': 131
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_0',
                'value': 141
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_1',
                'value': 142
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_2',
                'value': 143
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_3',
                'value': 144
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_4',
                'value': 145
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_5',
                'value': 146
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_6',
                'value': 147
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_RTSI_7',
                'value': 1010
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_OTHER_TERMINAL',
                'value': 1018
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_CLK_IN',
                'value': 1202
            },
            {
                'name': 'UPDATE_CLOCK_SOURCE_DDC_CLK_IN',
                'value': 1203
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_PAL_B',
                'value': 0
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_PAL_D',
                'value': 1
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_PAL_G',
                'value': 2
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_PAL_H',
                'value': 3
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_PAL_I',
                'value': 4
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_PAL_M',
                'value': 5
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_PAL_N',
                'value': 6
            },
            {
                'name': 'VIDEO_WAVEFORM_TYPE_NTSC_M',
                'value': 7
            },
            {
                'name': 'WAIT_BEHAVIOR_HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'WAIT_BEHAVIOR_JUMP_TO_VALUE',
                'value': 401
            },
            {
                'name': 'WAVEFORM_WFM_SINE',
                'value': 1
            },
            {
                'name': 'WAVEFORM_WFM_SQUARE',
                'value': 2
            },
            {
                'name': 'WAVEFORM_WFM_TRIANGLE',
                'value': 3
            },
            {
                'name': 'WAVEFORM_WFM_RAMP_UP',
                'value': 4
            },
            {
                'name': 'WAVEFORM_WFM_RAMP_DOWN',
                'value': 5
            },
            {
                'name': 'WAVEFORM_WFM_DC',
                'value': 6
            },
            {
                'name': 'WAVEFORM_WFM_NOISE',
                'value': 101
            },
            {
                'name': 'WAVEFORM_WFM_USER',
                'value': 102
            }
        ]
    },
    'NiFgenStringAttributeValuesMapped': {
        'enum-value-prefix': 'NIFGEN_STRING',
        'generate-mappings': True,
        'values': [
            {
                'name': 'REFERENCE_CLOCK_SOURCE_CLOCK_IN_COLLISION_AVOIDANCE',
                'value': 'ClkIn'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_NONE_COLLISION_AVOIDANCE',
                'value': 'None'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_ONBOARD_REFERENCE_CLOCK_COLLISION_AVOIDANCE',
                'value': 'OnboardRefClk'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_PXI_CLOCK_COLLISION_AVOIDANCE',
                'value': 'PXI_Clk'
            },
            {
                'name': 'REFERENCE_CLOCK_SOURCE_RTSI_7_COLLISION_AVOIDANCE',
                'value': 'RTSI7'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_DDC_CLOCK_IN',
                'value': 'DDC_ClkIn'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_STAR_LINE',
                'value': 'PXI_Star'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_0_RTSI_0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_1_RTSI_1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_2_RTSI_2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_3_RTSI_3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_4_RTSI_4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_5_RTSI_5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_6_RTSI_6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'SAMPLE_CLOCK_SOURCE_PXI_TRIGGER_LINE_7_RTSI_7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'SAMPLE_CLOCK_TIMEBASE_SOURCE_CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'SAMPLE_CLOCK_TIMEBASE_SOURCE_ONBOARD_CLOCK',
                'value': 'OnboardClock'
            }
        ]
    },
    'OperationMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'OPERATE_CONTINUOUS',
                'value': 0
            }
        ]
    },
    'OspMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'OSP_IF',
                'value': 0
            },
            {
                'name': 'OSP_BASEBAND',
                'value': 1
            }
        ]
    },
    'OspOverflowErrorReporting': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ERROR_REPORTING_ERROR',
                'value': 0
            },
            {
                'name': 'ERROR_REPORTING_DISABLED',
                'value': 2
            }
        ]
    },
    'OutputMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'OUTPUT_FUNC',
                'value': 0
            },
            {
                'name': 'OUTPUT_ARB',
                'value': 1
            },
            {
                'name': 'OUTPUT_SEQ',
                'value': 2
            },
            {
                'name': 'OUTPUT_FREQ_LIST',
                'value': 101
            },
            {
                'name': 'OUTPUT_SCRIPT',
                'value': 102
            }
        ]
    },
    'P2PAddressType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ADDR_PHYSICAL',
                'value': 0
            },
            {
                'name': 'ADDR_VIRTUAL',
                'value': 1
            }
        ]
    },
    'ReadyForStartEventActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'ReferenceClockSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'grpc_name': 'CLOCK_IN',
                'name': 'CLOCK_IN_COLLISION_AVOIDANCE',
                'value': 'ClkIn'
            },
            {
                'grpc_name': 'NONE',
                'name': 'NONE_COLLISION_AVOIDANCE',
                'value': 'None'
            },
            {
                'grpc_name': 'ONBOARD_REFERENCE_CLOCK',
                'name': 'ONBOARD_REFERENCE_CLOCK_COLLISION_AVOIDANCE',
                'value': 'OnboardRefClk'
            },
            {
                'grpc_name': 'PXI_CLOCK',
                'name': 'PXI_CLOCK_COLLISION_AVOIDANCE',
                'value': 'PXI_Clk'
            },
            {
                'grpc_name': 'RTSI_7',
                'name': 'RTSI_7_COLLISION_AVOIDANCE',
                'value': 'RTSI7'
            }
        ]
    },
    'RelativeTo': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'WAVEFORM_POSITION_START',
                'value': 0
            },
            {
                'name': 'WAVEFORM_POSITION_CURRENT',
                'value': 1
            }
        ]
    },
    'SampleClockSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'DDC_CLOCK_IN',
                'value': 'DDC_ClkIn'
            },
            {
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'PXI_STAR_LINE',
                'value': 'PXI_Star'
            },
            {
                'name': 'PXI_TRIGGER_LINE_0_RTSI_0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'PXI_TRIGGER_LINE_1_RTSI_1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'PXI_TRIGGER_LINE_2_RTSI_2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'PXI_TRIGGER_LINE_3_RTSI_3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'PXI_TRIGGER_LINE_4_RTSI_4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'PXI_TRIGGER_LINE_5_RTSI_5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'PXI_TRIGGER_LINE_6_RTSI_6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'PXI_TRIGGER_LINE_7_RTSI_7',
                'value': 'PXI_Trig7'
            }
        ]
    },
    'SampleClockTimebaseSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'CLOCK_IN',
                'value': 'ClkIn'
            },
            {
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            }
        ]
    },
    'ScriptTriggerDigitalEdgeEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RISING_EDGE',
                'value': 101
            },
            {
                'name': 'FALLING_EDGE',
                'value': 102
            }
        ]
    },
    'ScriptTriggerDigitalLevelActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'ScriptTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'TRIG_NONE',
                'value': 101
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'DIGITAL_LEVEL',
                'value': 103
            },
            {
                'name': 'SOFTWARE_EDGE',
                'value': 104
            }
        ]
    },
    'Signal': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ONBOARD_REFERENCE_CLOCK',
                'value': 1019
            },
            {
                'name': 'SYNC_OUT',
                'value': 1002
            },
            {
                'name': 'START_TRIGGER',
                'value': 1004
            },
            {
                'name': 'MARKER_EVENT',
                'value': 1001
            },
            {
                'name': 'SAMPLE_CLOCK_TIMEBASE',
                'value': 1006
            },
            {
                'name': 'SYNCHRONIZATION',
                'value': 1007
            },
            {
                'name': 'SAMPLE_CLOCK',
                'value': 101
            },
            {
                'name': 'REFERENCE_CLOCK',
                'value': 102
            },
            {
                'name': 'SCRIPT_TRIGGER',
                'value': 103
            },
            {
                'name': 'READY_FOR_START_EVENT',
                'value': 105
            },
            {
                'name': 'STARTED_EVENT',
                'value': 106
            },
            {
                'name': 'DONE_EVENT',
                'value': 107
            },
            {
                'name': 'DATA_MARKER_EVENT',
                'value': 108
            }
        ]
    },
    'StartTriggerDigitalEdgeEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RISING_EDGE',
                'value': 101
            },
            {
                'name': 'FALLING_EDGE',
                'value': 102
            }
        ]
    },
    'StartTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'TRIG_NONE',
                'value': 101
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 102
            },
            {
                'name': 'SOFTWARE_EDGE',
                'value': 104
            },
            {
                'name': 'P2P_ENDPOINT_FULLNESS',
                'value': 106
            }
        ]
    },
    'StartedEventActiveLevel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'StartedEventDelayUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'SECONDS',
                'value': 102
            }
        ]
    },
    'StartedEventOutputBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PULSE',
                'value': 101
            },
            {
                'name': 'LEVEL',
                'value': 102
            }
        ]
    },
    'StartedEventPulsePolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'StartedEventPulseWidthUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 101
            },
            {
                'name': 'SECONDS',
                'value': 102
            }
        ]
    },
    'SynchronizationSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'TTL0',
                'value': 111
            },
            {
                'name': 'TTL1',
                'value': 112
            },
            {
                'name': 'TTL2',
                'value': 113
            },
            {
                'name': 'TTL3',
                'value': 114
            },
            {
                'name': 'TTL4',
                'value': 115
            },
            {
                'name': 'TTL5',
                'value': 116
            },
            {
                'name': 'TTL6',
                'value': 117
            },
            {
                'name': 'RTSI_0',
                'value': 141
            },
            {
                'name': 'RTSI_1',
                'value': 142
            },
            {
                'name': 'RTSI_2',
                'value': 143
            },
            {
                'name': 'RTSI_3',
                'value': 144
            },
            {
                'name': 'RTSI_4',
                'value': 145
            },
            {
                'name': 'RTSI_5',
                'value': 146
            },
            {
                'name': 'RTSI_6',
                'value': 147
            },
            {
                'name': 'NONE',
                'value': 1000
            }
        ]
    },
    'TerminalConfiguration': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SINGLE_ENDED',
                'value': 300
            },
            {
                'name': 'DIFFERENTIAL',
                'value': 301
            }
        ]
    },
    'Trigger': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'START_TRIGGER',
                'value': 1004
            },
            {
                'name': 'SCRIPT_TRIGGER',
                'value': 103
            }
        ]
    },
    'TriggerMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'SINGLE',
                'value': 1
            },
            {
                'name': 'CONTINUOUS',
                'value': 2
            },
            {
                'name': 'STEPPED',
                'value': 3
            },
            {
                'name': 'BURST',
                'value': 4
            }
        ]
    },
    'TriggerSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'IMMEDIATE',
                'value': 0
            },
            {
                'name': 'EXTERNAL',
                'value': 1
            },
            {
                'name': 'SOFTWARE_TRIG',
                'value': 2
            },
            {
                'name': 'TTL0',
                'value': 111
            },
            {
                'name': 'TTL1',
                'value': 112
            },
            {
                'name': 'TTL2',
                'value': 113
            },
            {
                'name': 'TTL3',
                'value': 114
            },
            {
                'name': 'TTL4',
                'value': 115
            },
            {
                'name': 'TTL5',
                'value': 116
            },
            {
                'name': 'TTL6',
                'value': 117
            },
            {
                'name': 'PXI_STAR',
                'value': 131
            },
            {
                'name': 'RTSI_0',
                'value': 141
            },
            {
                'name': 'RTSI_1',
                'value': 142
            },
            {
                'name': 'RTSI_2',
                'value': 143
            },
            {
                'name': 'RTSI_3',
                'value': 144
            },
            {
                'name': 'RTSI_4',
                'value': 145
            },
            {
                'name': 'RTSI_5',
                'value': 146
            },
            {
                'name': 'RTSI_6',
                'value': 147
            },
            {
                'name': 'RTSI_7',
                'value': 1010
            },
            {
                'name': 'PFI_0',
                'value': 1011
            },
            {
                'name': 'PFI_1',
                'value': 1012
            },
            {
                'name': 'PFI_2',
                'value': 1013
            },
            {
                'name': 'PFI_3',
                'value': 1014
            },
            {
                'name': 'OTHER_TERMINAL',
                'value': 1018
            }
        ]
    },
    'TriggerWhen': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ACTIVE_HIGH',
                'value': 101
            },
            {
                'name': 'ACTIVE_LOW',
                'value': 102
            }
        ]
    },
    'UpdateClockSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'INTERNAL',
                'value': 0
            },
            {
                'name': 'EXTERNAL',
                'value': 1
            },
            {
                'name': 'TTL1',
                'value': 112
            },
            {
                'name': 'TTL2',
                'value': 113
            },
            {
                'name': 'TTL3',
                'value': 114
            },
            {
                'name': 'TTL4',
                'value': 115
            },
            {
                'name': 'TTL5',
                'value': 116
            },
            {
                'name': 'TTL6',
                'value': 117
            },
            {
                'name': 'PXI_STAR',
                'value': 131
            },
            {
                'name': 'RTSI_0',
                'value': 141
            },
            {
                'name': 'RTSI_1',
                'value': 142
            },
            {
                'name': 'RTSI_2',
                'value': 143
            },
            {
                'name': 'RTSI_3',
                'value': 144
            },
            {
                'name': 'RTSI_4',
                'value': 145
            },
            {
                'name': 'RTSI_5',
                'value': 146
            },
            {
                'name': 'RTSI_6',
                'value': 147
            },
            {
                'name': 'RTSI_7',
                'value': 1010
            },
            {
                'name': 'OTHER_TERMINAL',
                'value': 1018
            },
            {
                'name': 'CLK_IN',
                'value': 1202
            },
            {
                'name': 'DDC_CLK_IN',
                'value': 1203
            }
        ]
    },
    'VideoWaveformType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'PAL_B',
                'value': 0
            },
            {
                'name': 'PAL_D',
                'value': 1
            },
            {
                'name': 'PAL_G',
                'value': 2
            },
            {
                'name': 'PAL_H',
                'value': 3
            },
            {
                'name': 'PAL_I',
                'value': 4
            },
            {
                'name': 'PAL_M',
                'value': 5
            },
            {
                'name': 'PAL_N',
                'value': 6
            },
            {
                'name': 'NTSC_M',
                'value': 7
            }
        ]
    },
    'WaitBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'HOLD_LAST_VALUE',
                'value': 400
            },
            {
                'name': 'JUMP_TO_VALUE',
                'value': 401
            }
        ]
    },
    'Waveform': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'WFM_SINE',
                'value': 1
            },
            {
                'name': 'WFM_SQUARE',
                'value': 2
            },
            {
                'name': 'WFM_TRIANGLE',
                'value': 3
            },
            {
                'name': 'WFM_RAMP_UP',
                'value': 4
            },
            {
                'name': 'WFM_RAMP_DOWN',
                'value': 5
            },
            {
                'name': 'WFM_DC',
                'value': 6
            },
            {
                'name': 'WFM_NOISE',
                'value': 101
            },
            {
                'name': 'WFM_USER',
                'value': 102
            }
        ]
    }
}
