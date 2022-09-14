# -*- coding: utf-8 -*-
# This file is generated from NI-DMM API metadata version 22.8.0d9999
enums = {
    'ADCCalibration': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_ADC_CALIBRATION_OFF',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_ADC_CALIBRATION_AUTO',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_ADC_CALIBRATION_ON',
                'value': 1
            }
        ]
    },
    'AcquisitionStatus': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_ACQUISITION_STATUS_RUNNING',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_ACQUISITION_STATUS_FINISHED_WITH_BACKLOG',
                'value': 1
            },
            {
                'name': 'NIDMM_VAL_ACQUISITION_STATUS_FINISHED_WITH_NO_BACKLOG',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_ACQUISITION_STATUS_PAUSED',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_ACQUISITION_STATUS_NO_ACQUISITION_IN_PROGRESS',
                'value': 4
            }
        ]
    },
    'ApertureTime': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_APERTURE_TIME_AUTO',
                'value': -1.0
            },
            {
                'name': 'NIDMM_VAL_1_PLC',
                'value': 1.0
            },
            {
                'name': 'NIDMM_VAL_5_PLC',
                'value': 5.0
            },
            {
                'name': 'NIDMM_VAL_6_PLC',
                'value': 6.0
            },
            {
                'name': 'NIDMM_VAL_10_PLC',
                'value': 10.0
            },
            {
                'name': 'NIDMM_VAL_12_PLC',
                'value': 12.0
            },
            {
                'name': 'NIDMM_VAL_100_PLC',
                'value': 100.0
            },
            {
                'name': 'NIDMM_VAL_120_PLC',
                'value': 120.0
            }
        ]
    },
    'ApertureTimeUnits': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_ZERO_OFF',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_AUTO_ZERO_AUTO',
                'value': -1
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
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_BUFFER_SIZE_AUTO',
                'value': -1
            }
        ]
    },
    'CableCompensationType': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
    'Configuration4022': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_4022_CONFIG_GUARD',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_4022_CONFIG_CURRENT_100_NANOAMP',
                'value': 2
            },
            {
                'name': 'NIDMM_VAL_4022_CONFIG_CURRENT_10_MICROAMP',
                'value': 3
            },
            {
                'name': 'NIDMM_VAL_4022_CONFIG_CURRENT_1_MILLIAMP',
                'value': 7
            },
            {
                'name': 'NIDMM_VAL_4022_CONFIG_CURRENT_DISCONNECT_AGND',
                'value': 8
            }
        ]
    },
    'ControlCommit': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_CONTROL_COMMIT',
                'value': 0
            }
        ]
    },
    'CurrentSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_1_MICROAMP',
                'value': 1e-06
            },
            {
                'name': 'NIDMM_VAL_10_MICROAMP',
                'value': 1e-05
            },
            {
                'name': 'NIDMM_VAL_100_MICROAMP',
                'value': 0.0001
            },
            {
                'name': 'NIDMM_VAL_1_MILLIAMP',
                'value': 0.001
            }
        ]
    },
    'DCBias': {
        'codegen_method': 'public',
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
    'DCNoiseRejection': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_DCNR_NORMAL',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_DCNR_AUTO',
                'value': -1
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
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_ON',
                'value': -1.0
            },
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_OFF',
                'value': -2.0
            }
        ]
    },
    'Function': {
        'codegen_method': 'public',
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
    'InputResistance': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_1_MEGAOHM',
                'value': 1000000.0
            },
            {
                'name': 'NIDMM_VAL_10_MEGAOHM',
                'value': 10000000.0
            },
            {
                'name': 'NIDMM_VAL_GREATER_THAN_10_GIGAOHM',
                'value': 10000000000.0
            }
        ]
    },
    'LCCalculationModel': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_CALC_MODEL_SERIES',
                'value': 0
            },
            {
                'name': 'NIDMM_VAL_CALC_MODEL_AUTO',
                'value': -1
            },
            {
                'name': 'NIDMM_VAL_CALC_MODEL_PARALLEL',
                'value': 1
            }
        ]
    },
    'Latency': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_LATENCY_AUTO',
                'value': -1
            }
        ]
    },
    'MeasurementCompleteDest': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
    'NiDmmInt32AttributeValues': {
        'enum-value-prefix': 'NIDMM_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'ADC_CALIBRATION_VAL_ADC_CALIBRATION_OFF',
                'value': 0
            },
            {
                'name': 'ADC_CALIBRATION_VAL_ADC_CALIBRATION_AUTO',
                'value': -1
            },
            {
                'name': 'ADC_CALIBRATION_VAL_ADC_CALIBRATION_ON',
                'value': 1
            },
            {
                'name': 'APERTURE_TIME_UNITS_VAL_SECONDS',
                'value': 0
            },
            {
                'name': 'APERTURE_TIME_UNITS_VAL_POWER_LINE_CYCLES',
                'value': 1
            },
            {
                'name': 'AUTO_ZERO_VAL_AUTO_ZERO_OFF',
                'value': 0
            },
            {
                'name': 'AUTO_ZERO_VAL_AUTO_ZERO_AUTO',
                'value': -1
            },
            {
                'name': 'AUTO_ZERO_VAL_AUTO_ZERO_ON',
                'value': 1
            },
            {
                'name': 'AUTO_ZERO_VAL_AUTO_ZERO_ONCE',
                'value': 2
            },
            {
                'name': 'BUFFER_SIZE_VAL_BUFFER_SIZE_AUTO',
                'value': -1
            },
            {
                'name': 'CABLE_COMPENSATION_TYPE_VAL_CABLE_COMP_NONE',
                'value': 0
            },
            {
                'name': 'CABLE_COMPENSATION_TYPE_VAL_CABLE_COMP_OPEN',
                'value': 1
            },
            {
                'name': 'CABLE_COMPENSATION_TYPE_VAL_CABLE_COMP_SHORT',
                'value': 2
            },
            {
                'name': 'CABLE_COMPENSATION_TYPE_VAL_CABLE_COMP_OPEN_AND_SHORT',
                'value': 3
            },
            {
                'name': 'DC_BIAS_VAL_DC_BIAS_OFF',
                'value': 0
            },
            {
                'name': 'DC_BIAS_VAL_DC_BIAS_ON',
                'value': 1
            },
            {
                'name': 'DC_NOISE_REJECTION_VAL_DCNR_NORMAL',
                'value': 0
            },
            {
                'name': 'DC_NOISE_REJECTION_VAL_DCNR_AUTO',
                'value': -1
            },
            {
                'name': 'DC_NOISE_REJECTION_VAL_DCNR_SECOND_ORDER',
                'value': 1
            },
            {
                'name': 'DC_NOISE_REJECTION_VAL_DCNR_HIGH_ORDER',
                'value': 2
            },
            {
                'name': 'FUNCTION_VAL_DC_VOLTS',
                'value': 1
            },
            {
                'name': 'FUNCTION_VAL_AC_VOLTS',
                'value': 2
            },
            {
                'name': 'FUNCTION_VAL_DC_CURRENT',
                'value': 3
            },
            {
                'name': 'FUNCTION_VAL_AC_CURRENT',
                'value': 4
            },
            {
                'name': 'FUNCTION_VAL_2_WIRE_RES',
                'value': 5
            },
            {
                'name': 'FUNCTION_VAL_4_WIRE_RES',
                'value': 101
            },
            {
                'name': 'FUNCTION_VAL_FREQ',
                'value': 104
            },
            {
                'name': 'FUNCTION_VAL_PERIOD',
                'value': 105
            },
            {
                'name': 'FUNCTION_VAL_TEMPERATURE',
                'value': 108
            },
            {
                'name': 'FUNCTION_VAL_AC_VOLTS_DC_COUPLED',
                'value': 1001
            },
            {
                'name': 'FUNCTION_VAL_DIODE',
                'value': 1002
            },
            {
                'name': 'FUNCTION_VAL_WAVEFORM_VOLTAGE',
                'value': 1003
            },
            {
                'name': 'FUNCTION_VAL_WAVEFORM_CURRENT',
                'value': 1004
            },
            {
                'name': 'FUNCTION_VAL_CAPACITANCE',
                'value': 1005
            },
            {
                'name': 'FUNCTION_VAL_INDUCTANCE',
                'value': 1006
            },
            {
                'name': 'LC_CALCULATION_MODEL_VAL_CALC_MODEL_SERIES',
                'value': 0
            },
            {
                'name': 'LC_CALCULATION_MODEL_VAL_CALC_MODEL_AUTO',
                'value': -1
            },
            {
                'name': 'LC_CALCULATION_MODEL_VAL_CALC_MODEL_PARALLEL',
                'value': 1
            },
            {
                'name': 'LATENCY_VAL_LATENCY_AUTO',
                'value': -1
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_NONE',
                'value': -1
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_EXTERNAL',
                'value': 2
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG0',
                'value': 111
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG1',
                'value': 112
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG2',
                'value': 113
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG3',
                'value': 114
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG4',
                'value': 115
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG5',
                'value': 116
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG6',
                'value': 117
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_PXI_TRIG7',
                'value': 118
            },
            {
                'name': 'MEASUREMENT_COMPLETE_DEST_VAL_LBR_TRIG0',
                'value': 1003
            },
            {
                'name': 'MEASUREMENT_DESTINATION_SLOPE_VAL_POSITIVE',
                'value': 0
            },
            {
                'name': 'MEASUREMENT_DESTINATION_SLOPE_VAL_NEGATIVE',
                'value': 1
            },
            {
                'name': 'OFFSET_COMPENSATED_OHMS_VAL_OFFSET_COMP_OHMS_OFF',
                'value': 0
            },
            {
                'name': 'OFFSET_COMPENSATED_OHMS_VAL_OFFSET_COMP_OHMS_ON',
                'value': 1
            },
            {
                'name': 'OPERATION_MODE_VAL_IVIDMM_MODE',
                'value': 0
            },
            {
                'name': 'OPERATION_MODE_VAL_WAVEFORM_MODE',
                'value': 1
            },
            {
                'name': 'RTD_TYPE_VAL_TEMP_RTD_CUSTOM',
                'value': 0
            },
            {
                'name': 'RTD_TYPE_VAL_TEMP_RTD_PT3750',
                'value': 1
            },
            {
                'name': 'RTD_TYPE_VAL_TEMP_RTD_PT3851',
                'value': 2
            },
            {
                'name': 'RTD_TYPE_VAL_TEMP_RTD_PT3911',
                'value': 3
            },
            {
                'name': 'RTD_TYPE_VAL_TEMP_RTD_PT3916',
                'value': 4
            },
            {
                'name': 'RTD_TYPE_VAL_TEMP_RTD_PT3920',
                'value': 5
            },
            {
                'name': 'RTD_TYPE_VAL_TEMP_RTD_PT3928',
                'value': 6
            },
            {
                'name': 'SAMPLE_COUNT_VAL_SAMPLE_COUNT_INFINITE',
                'value': 0
            },
            {
                'name': 'SAMPLE_TRIG_SLOPE_VAL_POSITIVE',
                'value': 0
            },
            {
                'name': 'SAMPLE_TRIG_SLOPE_VAL_NEGATIVE',
                'value': 1
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_IMMEDIATE',
                'value': 1
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_EXTERNAL',
                'value': 2
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_SOFTWARE_TRIG',
                'value': 3
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_INTERVAL',
                'value': 10
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG0',
                'value': 111
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG1',
                'value': 112
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG2',
                'value': 113
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG3',
                'value': 114
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG4',
                'value': 115
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG5',
                'value': 116
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG6',
                'value': 117
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_TRIG7',
                'value': 118
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_AUX_TRIG1',
                'value': 1001
            },
            {
                'name': 'SAMPLE_TRIGGER_VAL_LBR_TRIG1',
                'value': 1004
            },
            {
                'name': 'THERMISTOR_TYPE_VAL_TEMP_THERMISTOR_CUSTOM',
                'value': 0
            },
            {
                'name': 'THERMISTOR_TYPE_VAL_TEMP_THERMISTOR_44004',
                'value': 1
            },
            {
                'name': 'THERMISTOR_TYPE_VAL_TEMP_THERMISTOR_44006',
                'value': 2
            },
            {
                'name': 'THERMISTOR_TYPE_VAL_TEMP_THERMISTOR_44007',
                'value': 3
            },
            {
                'name': 'THERMOCOUPLE_REFERENCE_JUNCTION_TYPE_VAL_FIXED',
                'value': 2
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_B',
                'value': 1
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_E',
                'value': 4
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_J',
                'value': 6
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_K',
                'value': 7
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_N',
                'value': 8
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_R',
                'value': 9
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_S',
                'value': 10
            },
            {
                'name': 'THERMOCOUPLE_TYPE_VAL_TEMP_TC_T',
                'value': 11
            },
            {
                'name': 'TRANSDUCER_TYPE_VAL_THERMOCOUPLE',
                'value': 1
            },
            {
                'name': 'TRANSDUCER_TYPE_VAL_THERMISTOR',
                'value': 2
            },
            {
                'name': 'TRANSDUCER_TYPE_VAL_2_WIRE_RTD',
                'value': 3
            },
            {
                'name': 'TRANSDUCER_TYPE_VAL_4_WIRE_RTD',
                'value': 4
            },
            {
                'name': 'TRIGGER_COUNT_VAL_TRIG_COUNT_INFINITE',
                'value': 0
            },
            {
                'name': 'TRIGGER_SLOPE_VAL_POSITIVE',
                'value': 0
            },
            {
                'name': 'TRIGGER_SLOPE_VAL_NEGATIVE',
                'value': 1
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_IMMEDIATE',
                'value': 1
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_EXTERNAL',
                'value': 2
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_SOFTWARE_TRIG',
                'value': 3
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG0',
                'value': 111
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG1',
                'value': 112
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG2',
                'value': 113
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG3',
                'value': 114
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG4',
                'value': 115
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG5',
                'value': 116
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG6',
                'value': 117
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_TRIG7',
                'value': 118
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_STAR',
                'value': 131
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_TRIG1',
                'value': 1001
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_LBR_TRIG1',
                'value': 1004
            },
            {
                'name': 'WAVEFORM_COUPLING_VAL_WAVEFORM_COUPLING_AC',
                'value': 0
            },
            {
                'name': 'WAVEFORM_COUPLING_VAL_WAVEFORM_COUPLING_DC',
                'value': 1
            }
        ]
    },
    'NiDmmReal64AttributeValuesMapped': {
        'enum-value-prefix': 'NIDMM_REAL64',
        'generate-mappings': True,
        'values': [
            {
                'name': 'APERTURE_TIME_VAL_APERTURE_TIME_AUTO',
                'value': -1.0
            },
            {
                'name': 'APERTURE_TIME_VAL_1_PLC',
                'value': 1.0
            },
            {
                'name': 'APERTURE_TIME_VAL_5_PLC',
                'value': 5.0
            },
            {
                'name': 'APERTURE_TIME_VAL_6_PLC',
                'value': 6.0
            },
            {
                'name': 'APERTURE_TIME_VAL_10_PLC',
                'value': 10.0
            },
            {
                'name': 'APERTURE_TIME_VAL_12_PLC',
                'value': 12.0
            },
            {
                'name': 'APERTURE_TIME_VAL_100_PLC',
                'value': 100.0
            },
            {
                'name': 'APERTURE_TIME_VAL_120_PLC',
                'value': 120.0
            },
            {
                'name': 'CURRENT_SOURCE_VAL_1_MICROAMP',
                'value': 1e-06
            },
            {
                'name': 'CURRENT_SOURCE_VAL_10_MICROAMP',
                'value': 1e-05
            },
            {
                'name': 'CURRENT_SOURCE_VAL_100_MICROAMP',
                'value': 0.0001
            },
            {
                'name': 'CURRENT_SOURCE_VAL_1_MILLIAMP',
                'value': 0.001
            },
            {
                'name': 'FREQUENCY_VOLTAGE_RANGE_VAL_AUTO_RANGE_ON',
                'value': -1.0
            },
            {
                'name': 'FREQUENCY_VOLTAGE_RANGE_VAL_AUTO_RANGE_OFF',
                'value': -2.0
            },
            {
                'name': 'INPUT_RESISTANCE_VAL_1_MEGAOHM',
                'value': 1000000.0
            },
            {
                'name': 'INPUT_RESISTANCE_VAL_10_MEGAOHM',
                'value': 10000000.0
            },
            {
                'name': 'INPUT_RESISTANCE_VAL_GREATER_THAN_10_GIGAOHM',
                'value': 10000000000.0
            },
            {
                'name': 'POWERLINE_FREQUENCY_VAL_50_HERTZ',
                'value': 50.0
            },
            {
                'name': 'POWERLINE_FREQUENCY_VAL_60_HERTZ',
                'value': 60.0
            },
            {
                'name': 'RANGE_VAL_AUTO_RANGE_ON',
                'value': -1.0
            },
            {
                'name': 'RANGE_VAL_AUTO_RANGE_OFF',
                'value': -2.0
            },
            {
                'name': 'RANGE_VAL_AUTO_RANGE_ONCE',
                'value': -3.0
            },
            {
                'name': 'SAMPLE_INTERVAL_VAL_AUTO_DELAY',
                'value': -1.0
            },
            {
                'name': 'SETTLE_TIME_VAL_SETTLE_TIME_AUTO',
                'value': -1.0
            },
            {
                'name': 'TRIGGER_DELAYS_VAL_AUTO_DELAY_ON',
                'value': -1.0
            },
            {
                'name': 'TRIGGER_DELAYS_VAL_AUTO_DELAY_OFF',
                'value': -2.0
            }
        ]
    },
    'OffsetCompensatedOhms': {
        'codegen_method': 'public',
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
    'OperationMode': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_50_HERTZ',
                'value': 50.0
            },
            {
                'name': 'NIDMM_VAL_60_HERTZ',
                'value': 60.0
            }
        ]
    },
    'PowerlineFrequency': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_50_HERTZ',
                'value': 50.0
            },
            {
                'name': 'NIDMM_VAL_60_HERTZ',
                'value': 60.0
            }
        ]
    },
    'RTDType': {
        'codegen_method': 'public',
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
    'Range': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_ON',
                'value': -1.0
            },
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_OFF',
                'value': -2.0
            },
            {
                'name': 'NIDMM_VAL_AUTO_RANGE_ONCE',
                'value': -3.0
            }
        ]
    },
    'SampleCount': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_SAMPLE_COUNT_INFINITE',
                'value': 0
            }
        ]
    },
    'SampleInterval': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_DELAY',
                'value': -1.0
            }
        ]
    },
    'SampleTrigSlope': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_SETTLE_TIME_AUTO',
                'value': -1.0
            }
        ]
    },
    'ThermistorType': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_FIXED',
                'value': 2
            }
        ]
    },
    'ThermocoupleType': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_TIME_LIMIT_AUTO',
                'value': -1
            }
        ]
    },
    'TransducerType': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDMM_VAL_TRIG_COUNT_INFINITE',
                'value': 0
            }
        ]
    },
    'TriggerDelays': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NIDMM_VAL_AUTO_DELAY_ON',
                'value': -1.0
            },
            {
                'name': 'NIDMM_VAL_AUTO_DELAY_OFF',
                'value': -2.0
            }
        ]
    },
    'TriggerSlope': {
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
        'codegen_method': 'public',
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
