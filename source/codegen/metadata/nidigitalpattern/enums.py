# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 22.8.0d9999
enums = {
    'BitOrder': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_MSB_FIRST',
                'value': 2500
            },
            {
                'name': 'NIDIGITAL_VAL_LSB_FIRST',
                'value': 2501
            }
        ]
    },
    'DigitalEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_RISING_EDGE',
                'value': 1800
            },
            {
                'name': 'NIDIGITAL_VAL_FALLING_EDGE',
                'value': 1801
            }
        ]
    },
    'DriveFormat': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_NR',
                'value': 1500
            },
            {
                'name': 'NIDIGITAL_VAL_RL',
                'value': 1501
            },
            {
                'name': 'NIDIGITAL_VAL_RH',
                'value': 1502
            },
            {
                'name': 'NIDIGITAL_VAL_SBC',
                'value': 1503
            }
        ]
    },
    'ExportSignal': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_START_TRIGGER',
                'value': 2000
            },
            {
                'name': 'NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER',
                'value': 2001
            },
            {
                'name': 'NIDIGITAL_VAL_PATTERN_OPCODE_EVENT',
                'value': 2002
            },
            {
                'name': 'NIDIGITAL_VAL_REF_CLOCK',
                'value': 2003
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_EVENT',
                'value': 2004
            }
        ]
    },
    'FrequencyMeasurementMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_BANKED',
                'value': 3700
            },
            {
                'name': 'NIDIGITAL_VAL_PARALLEL',
                'value': 3701
            }
        ]
    },
    'HistoryRAMMaxSamplesToAcquirePerSite': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_ACQUIRE_ALL_SAMPLES',
                'value': -1
            }
        ]
    },
    'HistoryRAMTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_FIRST_FAILURE',
                'value': 2200
            },
            {
                'name': 'NIDIGITAL_VAL_CYCLE_NUMBER',
                'value': 2201
            },
            {
                'name': 'NIDIGITAL_VAL_PATTERN_LABEL',
                'value': 2202
            }
        ]
    },
    'HistoryRamCyclesToAcquire': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_FAILED_CYCLES',
                'value': 2303
            },
            {
                'name': 'NIDIGITAL_VAL_ALL_CYCLES',
                'value': 2304
            }
        ]
    },
    'NiDigitalInt32AttributeValues': {
        'enum-value-prefix': 'NIDIGITAL_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'DIGITAL_EDGE_VAL_RISING_EDGE',
                'value': 1800
            },
            {
                'name': 'DIGITAL_EDGE_VAL_FALLING_EDGE',
                'value': 1801
            },
            {
                'name': 'FREQUENCY_MEASUREMENT_MODE_VAL_BANKED',
                'value': 3700
            },
            {
                'name': 'FREQUENCY_MEASUREMENT_MODE_VAL_PARALLEL',
                'value': 3701
            },
            {
                'name': 'HISTORY_RAM_MAX_SAMPLES_TO_ACQUIRE_PER_SITE_VAL_ACQUIRE_ALL_SAMPLES',
                'value': -1
            },
            {
                'name': 'HISTORY_RAM_TRIGGER_TYPE_VAL_FIRST_FAILURE',
                'value': 2200
            },
            {
                'name': 'HISTORY_RAM_TRIGGER_TYPE_VAL_CYCLE_NUMBER',
                'value': 2201
            },
            {
                'name': 'HISTORY_RAM_TRIGGER_TYPE_VAL_PATTERN_LABEL',
                'value': 2202
            },
            {
                'name': 'HISTORY_RAM_CYCLES_TO_ACQUIRE_VAL_FAILED_CYCLES',
                'value': 2303
            },
            {
                'name': 'HISTORY_RAM_CYCLES_TO_ACQUIRE_VAL_ALL_CYCLES',
                'value': 2304
            },
            {
                'name': 'PPMU_APERTURE_TIME_UNITS_VAL_SECONDS',
                'value': 2100
            },
            {
                'name': 'PPMU_CURRENT_LIMIT_BEHAVIOR_VAL_CURRENT_REGULATE',
                'value': 3100
            },
            {
                'name': 'PPMU_OUTPUT_FUNCTION_VAL_DC_VOLTAGE',
                'value': 1300
            },
            {
                'name': 'PPMU_OUTPUT_FUNCTION_VAL_DC_CURRENT',
                'value': 1301
            },
            {
                'name': 'SELECTED_FUNCTION_VAL_DIGITAL',
                'value': 1100
            },
            {
                'name': 'SELECTED_FUNCTION_VAL_PPMU',
                'value': 1101
            },
            {
                'name': 'SELECTED_FUNCTION_VAL_OFF',
                'value': 1102
            },
            {
                'name': 'SELECTED_FUNCTION_VAL_DISCONNECT',
                'value': 1103
            },
            {
                'name': 'SELECTED_FUNCTION_VAL_RIO',
                'value': 1104
            },
            {
                'name': 'TDR_ENDPOINT_TERMINATION_VAL_TDR_TO_OPEN',
                'value': 3600
            },
            {
                'name': 'TDR_ENDPOINT_TERMINATION_VAL_TDR_TO_SHORT_TO_GROUND',
                'value': 3601
            },
            {
                'name': 'TERMINATION_MODE_VAL_ACTIVE_LOAD',
                'value': 1200
            },
            {
                'name': 'TERMINATION_MODE_VAL_VTERM',
                'value': 1201
            },
            {
                'name': 'TERMINATION_MODE_VAL_HIGH_Z',
                'value': 1202
            },
            {
                'name': 'TRIGGER_TYPE_VAL_NONE',
                'value': 1700
            },
            {
                'name': 'TRIGGER_TYPE_VAL_DIGITAL_EDGE',
                'value': 1701
            },
            {
                'name': 'TRIGGER_TYPE_VAL_SOFTWARE',
                'value': 1702
            }
        ]
    },
    'PinState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_0',
                'value': 0
            },
            {
                'name': 'NIDIGITAL_VAL_1',
                'value': 1
            },
            {
                'name': 'NIDIGITAL_VAL_L',
                'value': 3
            },
            {
                'name': 'NIDIGITAL_VAL_H',
                'value': 4
            },
            {
                'name': 'NIDIGITAL_VAL_X',
                'value': 5
            },
            {
                'name': 'NIDIGITAL_VAL_M',
                'value': 6
            },
            {
                'name': 'NIDIGITAL_VAL_V',
                'value': 7
            },
            {
                'name': 'NIDIGITAL_VAL_D',
                'value': 8
            },
            {
                'name': 'NIDIGITAL_VAL_E',
                'value': 9
            },
            {
                'name': 'NIDIGITAL_VAL_NOT_A_PIN_STATE',
                'value': 254
            },
            {
                'name': 'NIDIGITAL_VAL_PIN_STATE_NOT_ACQUIRED',
                'value': 255
            }
        ]
    },
    'PpmuApertureTimeUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_SECONDS',
                'value': 2100
            }
        ]
    },
    'PpmuCurrentLimitBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_CURRENT_REGULATE',
                'value': 3100
            }
        ]
    },
    'PpmuMeasurementType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_MEASURE_CURRENT',
                'value': 2400
            },
            {
                'name': 'NIDIGITAL_VAL_MEASURE_VOLTAGE',
                'value': 2401
            }
        ]
    },
    'PpmuOutputFunction': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_DC_VOLTAGE',
                'value': 1300
            },
            {
                'name': 'NIDIGITAL_VAL_DC_CURRENT',
                'value': 1301
            }
        ]
    },
    'RIOTriggerId': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER0',
                'value': 'RIOTrigger0'
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER1',
                'value': 'RIOTrigger1'
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER2',
                'value': 'RIOTrigger2'
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER3',
                'value': 'RIOTrigger3'
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER4',
                'value': 'RIOTrigger4'
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER5',
                'value': 'RIOTrigger5'
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER6',
                'value': 'RIOTrigger6'
            },
            {
                'name': 'NIDIGITAL_VAL_RIO_TRIGGER7',
                'value': 'RIOTrigger7'
            }
        ]
    },
    'SelectedFunction': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_DIGITAL',
                'value': 1100
            },
            {
                'name': 'NIDIGITAL_VAL_PPMU',
                'value': 1101
            },
            {
                'name': 'NIDIGITAL_VAL_OFF',
                'value': 1102
            },
            {
                'name': 'NIDIGITAL_VAL_DISCONNECT',
                'value': 1103
            },
            {
                'name': 'NIDIGITAL_VAL_RIO',
                'value': 1104
            }
        ]
    },
    'SiteResultType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_PASS_FAIL',
                'value': 3300
            },
            {
                'name': 'NIDIGITAL_VAL_CAPTURE_WAVEFORM',
                'value': 3301
            }
        ]
    },
    'SoftwareTrigger': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_START_TRIGGER',
                'value': 2000
            },
            {
                'name': 'NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER',
                'value': 2001
            }
        ]
    },
    'SourceDataMapping': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_BROADCAST',
                'value': 2600
            },
            {
                'name': 'NIDIGITAL_VAL_SITE_UNIQUE',
                'value': 2601
            }
        ]
    },
    'TDREndpointTermination': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_TDR_TO_OPEN',
                'value': 3600
            },
            {
                'name': 'NIDIGITAL_VAL_TDR_TO_SHORT_TO_GROUND',
                'value': 3601
            }
        ]
    },
    'TerminationMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_ACTIVE_LOAD',
                'value': 1200
            },
            {
                'name': 'NIDIGITAL_VAL_VTERM',
                'value': 1201
            },
            {
                'name': 'NIDIGITAL_VAL_HIGH_Z',
                'value': 1202
            }
        ]
    },
    'TimeSetEdgeType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_DRIVE_ON',
                'value': 2800
            },
            {
                'name': 'NIDIGITAL_VAL_DRIVE_DATA',
                'value': 2801
            },
            {
                'name': 'NIDIGITAL_VAL_DRIVE_RETURN',
                'value': 2802
            },
            {
                'name': 'NIDIGITAL_VAL_DRIVE_OFF',
                'value': 2803
            },
            {
                'name': 'NIDIGITAL_VAL_COMPARE_STROBE',
                'value': 2804
            },
            {
                'name': 'NIDIGITAL_VAL_DRIVE_DATA2',
                'value': 2805
            },
            {
                'name': 'NIDIGITAL_VAL_DRIVE_RETURN2',
                'value': 2806
            },
            {
                'name': 'NIDIGITAL_VAL_COMPARE_STROBE2',
                'value': 2807
            }
        ]
    },
    'TriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_NONE',
                'value': 1700
            },
            {
                'name': 'NIDIGITAL_VAL_DIGITAL_EDGE',
                'value': 1701
            },
            {
                'name': 'NIDIGITAL_VAL_SOFTWARE',
                'value': 1702
            }
        ]
    },
    'WriteStaticPinState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_0',
                'value': 0
            },
            {
                'name': 'NIDIGITAL_VAL_1',
                'value': 1
            },
            {
                'name': 'NIDIGITAL_VAL_X',
                'value': 5
            }
        ]
    }
}
