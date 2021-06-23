enums = {
    'AnalogPath': {
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
    'FrequencyListOptions': {
        'values': [
            {
                'name': 'NIFGEN_VAL_ALL_FLISTS',
                'value': -1
            }
        ]
    },
    'SequenceHandle': {
        'values': [
            {
                'name': 'NIFGEN_VAL_ALL_SEQUENCES',
                'value': -1
            }
        ]
    },
    'WaveformHandle': {
        'values': [
            {
                'name': 'NIFGEN_VAL_ALL_WAVEFORMS',
                'value': -1
            }
        ]
    },
    'ArbitraryWaveformHandle': {
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
    'ArbitrarySequenceHandle': {
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
    'BurstCount': {
        'values': [
            {
                'name': 'NIFGEN_VAL_GENERATE_CONTINUOUS',
                'value': -1
            }
        ]
    },
    'BusType': {
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
    'HardwareState': {
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
        'values': [
            {
                'name': 'NIFGEN_VAL_MATCHED_LOAD_IMPEDANCE',
                'value': -1
            }
        ]
    },
    'MarkerEventDelayUnits': {
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
    'OspMode': {
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
    'AddressType': {
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
    'ReadyForStartEventActiveLevel': {
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
    'RelativeTo': {
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
    'SampleRate': {
        'values': [
            {
                'name': 'NIFGEN_VAL_EXTERNAL_SAMPLE_RATE',
                'value': -1
            }
        ]
    },
    'ScriptTriggerDigitalEdgeEdge': {
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
    'Signal': {
        'values': [
            {
                'name': 'NIFGEN_VAL_MARKER_EVENT',
                'value': 1001
            },
            {
                'name': 'NIFGEN_VAL_SYNC_OUT',
                'value': 1002
            },
            {
                'name': 'NIFGEN_VAL_ONBOARD_REFERENCE_CLOCK',
                'value': 1019
            },
            {
                'name': 'NIFGEN_VAL_START_TRIGGER',
                'value': 1004
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
    'RouteSignalFrom': {
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
    'StartTriggerDigitalEdgeEdge': {
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
    }
}
