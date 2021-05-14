# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 19.5.0d7
enums = {
    'BitOrder': {
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
            }
        ]
    },
    'HistoryRamCyclesToAcquire': {
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
    'HistoryRamMaxSamplesToAcquirePerSite': {
        'values': [
            {
                'name': 'NIDIGITAL_VAL_ACQUIRE_ALL_SAMPLES',
                'value': -1
            }
        ]
    },
    'HistoryRamTriggerType': {
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
    'FrequencyMeasurementMode': {
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
    'PpmuApertureTimeUnits': {
        'values': [
            {
                'name': 'NIDIGITAL_VAL_SECONDS',
                'value': 2100
            }
        ]
    },
    'PpmuCurrentLimitBehavior': {
        'values': [
            {
                'name': 'NIDIGITAL_VAL_CURRENT_REGULATE',
                'value': 3100
            }
        ]
    },
    'PpmuMeasurementType': {
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
    'PinState': {
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
    'SelectedFunction': {
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
            }
        ]
    },
    'SiteResultType': {
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
    'TdrEndpointTermination': {
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
