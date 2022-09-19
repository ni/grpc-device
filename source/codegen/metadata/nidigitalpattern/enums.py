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
    'HistoryRAMCyclesToAcquire': {
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
                'name': 'HISTORY_RAM_CYCLES_TO_ACQUIRE_VAL_FAILED_CYCLES',
                'value': 2303
            },
            {
                'name': 'HISTORY_RAM_CYCLES_TO_ACQUIRE_VAL_ALL_CYCLES',
                'value': 2304
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
    'PPMUApertureTimeUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_SECONDS',
                'value': 2100
            }
        ]
    },
    'PPMUCurrentLimitBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDIGITAL_VAL_CURRENT_REGULATE',
                'value': 3100
            }
        ]
    },
    'PPMUMeasurementType': {
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
    'PPMUOutputFunction': {
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
    'SequencerFlag': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_FLAG0',
                'value': 'seqflag0'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_FLAG1',
                'value': 'seqflag1'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_FLAG2',
                'value': 'seqflag2'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_FLAG3',
                'value': 'seqflag3'
            }
        ]
    },
    'SequencerRegister': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER0',
                'value': 'reg0'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER1',
                'value': 'reg1'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER2',
                'value': 'reg2'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER3',
                'value': 'reg3'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER4',
                'value': 'reg4'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER5',
                'value': 'reg5'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER6',
                'value': 'reg6'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER7',
                'value': 'reg7'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER8',
                'value': 'reg8'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER9',
                'value': 'reg9'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER10',
                'value': 'reg10'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER11',
                'value': 'reg11'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER12',
                'value': 'reg12'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER13',
                'value': 'reg13'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER14',
                'value': 'reg14'
            },
            {
                'name': 'NIDIGITAL_VAL_SEQUENCER_REGISTER15',
                'value': 'reg15'
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
    'TriggerTerminal': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDIGITAL_VAL_DO_NOT_EXPORT_STR',
                'value': ''
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'NIDIGITAL_VAL_PXI_TRIG7_STR',
                'value': 'PXI_Trig7'
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
