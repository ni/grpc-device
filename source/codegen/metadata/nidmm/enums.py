# -*- coding: utf-8 -*-
# This file is generated from NI-DMM API metadata version 19.6.0d7
enums = {
    'AdcCalibration': {
        'values': [
            {
                'name': 'NIDMM_VAL_ADC_CALIBRATION_AUTO',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_ADC_CALIBRATION_OFF',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_ADC_CALIBRATION_ON',
                'value': 1
            }
        ]
    },
    'AcquisitionStatus': {
        'values': [
            {
                'name': 'NIDMM_VAL_RUNNING_ANTICOLLISION',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_FINISHED_WITH_BACKLOG',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_FINISHED_WITH_NO_BACKLOG',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_PAUSED',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_NO_ACQUISITION_IN_PROGRESS',
                'value': 4
            }
        ]
    },
    'ApertureTime': {
        'values': [
            {
                'name': 'NIDMM_VAL_APERTURE_TIME_AUTO',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_1_PLC',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_5_PLC',
                'value': 5
            },
            {
                'name': 'NIDMM_VAL_6_PLC',
                'value': 6
            },
            {
                'name': 'NIDMM_VAL_10_PLC',
                'value': 10
            },
            {
                'name': 'NIDMM_VAL_12_PLC',
                'value': 12
            },
            {
                'name': 'NIDMM_VAL_100_PLC',
                'value': 100
            },
            {
                'name': 'NIDMM_VAL_120_PLC',
                'value': 120
            }
        ]
    },
    'ApertureTimeUnits': {
        'values': [
            {
                'name': 'NIDMM_VAL_SECONDS',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_POWER_LINE_CYCLES',
                'value': 1
            }
        ]
    },
    'AutoZero': {
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_ZERO_AUTO',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_AUTO_ZERO_OFF',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_AUTO_ZERO_ON',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_AUTO_ZERO_ONCE',
                'value': 2
            }
        ]
    },
    'BufferSize': {
        'values': [
            {
                'name': 'NIDMM_VAL_BUFFER_SIZE_AUTO',
                'value': -1
            }
        ]
    },
    'CableCompensationType': {
        'values': [
            {
                'name': 'NIDMM_VAL_CABLE_COMP_NONE',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_CABLE_COMP_OPEN',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_CABLE_COMP_SHORT',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_CABLE_COMP_OPEN_AND_SHORT',
                'value': 3
            }
        ]
    },
    'CalibrationType': {
        'values': [
            {
                'name': 'NIDMM_VAL_INTERNAL_AREA',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_EXTERNAL_AREA',
                'value': 1
            }
        ]
    },
    'CompensatedOhms': {
        'values': [
            {
                'name': 'NIDMM_VAL_OFFSET_COMP_OHMS_OFF',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_OFFSET_COMP_OHMS_ON',
                'value': 1
            }
        ]
    },
    'Configuration4022': {
        'values': [
            {
                'name': 'NIDMM_4022_CONFIG_GUARD',
                'value': 0
            },
            {
                'name': 'NIDMM_4022_CONFIG_CURRENT_100_NANOAMP',
                'value': 2
            },
            {
                'name': 'NIDMM_4022_CONFIG_CURRENT_10_MICROAMP',
                'value': 3
            },
            {
                'name': 'NIDMM_4022_CONFIG_CURRENT_1_MILLIAMP',
                'value': 7
            },
            {
                'name': 'NIDMM_4022_CONFIG_DISCONNECT_AGND',
                'value': 8
            }
        ]
    },
    'ControlCommit': {
        'values': [
            {
                'name': 'NIDMM_VAL_CONTROL_COMMIT',
                'value': 0
            }
        ]
    },
    'DcBias': {
        'values': [
            {
                'name': 'NIDMM_VAL_DC_BIAS_OFF',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_DC_BIAS_ON',
                'value': 1
            }
        ]
    },
    'DcNoiseRejection': {
        'values': [
            {
                'name': 'NIDMM_VAL_DCNR_AUTO',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_DCNR_NORMAL',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_DCNR_SECOND_ORDER',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_DCNR_HIGH_ORDER',
                'value': 2
            }
        ]
    },
    'FrequencyVoltageRange': {
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_ON',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_OFF',
                'value': -2
            }
        ]
    },
    'Function': {
        'values': [
            {
                'name': 'NIDMM_VAL_DC_VOLTS',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_AC_VOLTS',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_DC_CURRENT',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_AC_CURRENT',
                'value': 4
            },
            {
                'name': 'NIDMM_VAL_2_WIRE_RES',
                'value': 5
            },
            {
                'name': 'NIDMM_VAL_4_WIRE_RES',
                'value': 101
            },
            {
                'name': 'NIDMM_VAL_FREQ',
                'value': 104
            },
            {
                'name': 'NIDMM_VAL_PERIOD',
                'value': 105
            },
            {
                'name': 'NIDMM_VAL_TEMPERATURE',
                'value': 108
            },
            {
                'name': 'NIDMM_VAL_AC_VOLTS_DC_COUPLED',
                'value': 1001
            },
            {
                'name': 'NIDMM_VAL_DIODE',
                'value': 1002
            },
            {
                'name': 'NIDMM_VAL_WAVEFORM_VOLTAGE',
                'value': 1003
            },
            {
                'name': 'NIDMM_VAL_WAVEFORM_CURRENT',
                'value': 1004
            },
            {
                'name': 'NIDMM_VAL_CAPACITANCE',
                'value': 1005
            },
            {
                'name': 'NIDMM_VAL_INDUCTANCE',
                'value': 1006
            }
        ]
    },
    'Latency': {
        'values': [
            {
                'name': 'NIDMM_VAL_LATENCY_AUTO',
                'value': -1
            }
        ]
    },
    'LcCalculationModel': {
        'values': [
            {
                'name': 'NIDMM_VAL_CALC_MODEL_AUTO',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_CALC_MODEL_SERIES',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_CALC_MODEL_PARALLEL',
                'value': 1
            }
        ]
    },
    'MeasurementCompleteDest': {
        'values': [
            {
                'name': 'NIDMM_VAL_NONE',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_EXTERNAL',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG0',
                'value': 111
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG1',
                'value': 112
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG2',
                'value': 113
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG3',
                'value': 114
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG4',
                'value': 115
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG5',
                'value': 116
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG6',
                'value': 117
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG7',
                'value': 118
            },
            {
                'name': 'NIDMM_VAL_LBR_TRIG0',
                'value': 1003
            }
        ]
    },
    'MeasurementDestinationSlope': {
        'values': [
            {
                'name': 'NIDMM_VAL_POSITIVE',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_NEGATIVE',
                'value': 1
            }
        ]
    },
    'OperationMode': {
        'values': [
            {
                'name': 'NIDMM_VAL_IVIDMM_MODE',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_WAVEFORM_MODE',
                'value': 1
            }
        ]
    },
    'PowerLineFrequencies': {
        'values': [
            {
                'name': 'NIDMM_VAL_50_HERTZ',
                'value': 50
            },
            {
                'name': 'NIDMM_VAL_60_HERTZ',
                'value': 60
            }
        ]
    },
    'Range': {
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_ON',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_OFF',
                'value': -2
            },
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_ONCE',
                'value': -3
            }
        ]
    },
    'RtdType': {
        'values': [
            {
                'name': 'NIDMM_VAL_TEMP_RTD_CUSTOM',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_TEMP_RTD_PT3750',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_TEMP_RTD_PT3851',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_TEMP_RTD_PT3911',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_TEMP_RTD_PT3916',
                'value': 4
            },
            {
                'name': 'NIDMM_VAL_TEMP_RTD_PT3920',
                'value': 5
            },
            {
                'name': 'NIDMM_VAL_TEMP_RTD_PT3928',
                'value': 6
            }
        ]
    },
    'SampleCount': {
        'values': [
            {
                'name': 'NIDMM_VAL_SAMPLE_COUNT_INFINITE',
                'value': 0
            }
        ]
    },
    'SampleInterval': {
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_DELAY',
                'value': -1
            }
        ]
    },
    'SampleTrigSlope': {
        'values': [
            {
                'name': 'NIDMM_VAL_POSITIVE',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_NEGATIVE',
                'value': 1
            }
        ]
    },
    'SampleTrigger': {
        'values': [
            {
                'name': 'NIDMM_VAL_IMMEDIATE',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_EXTERNAL',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_SOFTWARE_TRIG',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_INTERVAL',
                'value': 10
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG0',
                'value': 111
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG1',
                'value': 112
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG2',
                'value': 113
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG3',
                'value': 114
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG4',
                'value': 115
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG5',
                'value': 116
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG6',
                'value': 117
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG7',
                'value': 118
            },
            {
                'name': 'NIDMM_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'NIDMM_VAL_AUX_TRIG1',
                'value': 1001
            },
            {
                'name': 'NIDMM_VAL_LBR_TRIG1',
                'value': 1004
            }
        ]
    },
    'SettleTime': {
        'values': [
            {
                'name': 'NIDMM_VAL_SETTLE_TIME_AUTO',
                'value': -1
            }
        ]
    },
    'ThermistorType': {
        'values': [
            {
                'name': 'NIDMM_VAL_TEMP_THERMISTOR_CUSTOM',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_TEMP_THERMISTOR_44004',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_TEMP_THERMISTOR_44006',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_TEMP_THERMISTOR_44007',
                'value': 3
            }
        ]
    },
    'ThermocoupleReferenceJunctionType': {
        'values': [
            {
                'name': 'NIDMM_VAL_TEMP_REF_JUNC_FIXED',
                'value': 2
            }
        ]
    },
    'ThermocoupleType': {
        'values': [
            {
                'name': 'NIDMM_VAL_TEMP_TC_B',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_TEMP_TC_E',
                'value': 4
            },
            {
                'name': 'NIDMM_VAL_TEMP_TC_J',
                'value': 6
            },
            {
                'name': 'NIDMM_VAL_TEMP_TC_K',
                'value': 7
            },
            {
                'name': 'NIDMM_VAL_TEMP_TC_N',
                'value': 8
            },
            {
                'name': 'NIDMM_VAL_TEMP_TC_R',
                'value': 9
            },
            {
                'name': 'NIDMM_VAL_TEMP_TC_S',
                'value': 10
            },
            {
                'name': 'NIDMM_VAL_TEMP_TC_T',
                'value': 11
            }
        ]
    },
    'TimeLimit': {
        'values': [
            {
                'name': 'NIDMM_VAL_TIME_LIMIT_AUTO',
                'value': -1
            }
        ]
    },
    'TransducerType': {
        'values': [
            {
                'name': 'NIDMM_VAL_THERMOCOUPLE',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_THERMISTOR',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_2_WIRE_RTD',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_4_WIRE_RTD',
                'value': 4
            }
        ]
    },
    'TriggerCount': {
        'values': [
            {
                'name': 'NIDMM_VAL_TRIG_COUNT_INFINITE',
                'value': 0
            }
        ]
    },
    'TriggerDelays': {
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_DELAY_ON',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_AUTO_DELAY_OFF',
                'value': -2
            }
        ]
    },
    'TriggerSlope': {
        'values': [
            {
                'name': 'NIDMM_VAL_POSITIVE',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_NEGATIVE',
                'value': 1
            }
        ]
    },
    'TriggerSource': {
        'values': [
            {
                'name': 'NIDMM_VAL_IMMEDIATE',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_EXTERNAL',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_SOFTWARE_TRIG',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG0',
                'value': 111
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG1',
                'value': 112
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG2',
                'value': 113
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG3',
                'value': 114
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG4',
                'value': 115
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG5',
                'value': 116
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG6',
                'value': 117
            },
            {
                'name': 'NIDMM_VAL_PXI_TRIG7',
                'value': 118
            },
            {
                'name': 'NIDMM_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'NIDMM_VAL_AUX_TRIG1',
                'value': 1001
            },
            {
                'name': 'NIDMM_VAL_LBR_TRIG1',
                'value': 1004
            }
        ]
    },
    'WaveformCoupling': {
        'values': [
            {
                'name': 'NIDMM_VAL_WAVEFORM_COUPLING_AC',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_WAVEFORM_COUPLING_DC',
                'value': 1
            }
        ]
    }
}
