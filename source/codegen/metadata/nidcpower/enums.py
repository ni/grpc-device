# -*- coding: utf-8 -*-
# This file is generated from NI-DCPower API metadata version 23.0.0d288
enums = {
    'ApertureTimeAutoMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_OFF',
                'value': 1135
            },
            {
                'name': 'NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_SHORT',
                'value': 1136
            },
            {
                'name': 'NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_NORMAL',
                'value': 1137
            },
            {
                'name': 'NIDCPOWER_VAL_APERTURE_TIME_AUTO_MODE_LONG',
                'value': 1138
            }
        ]
    },
    'ApertureTimeUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_SECONDS',
                'value': 1028
            },
            {
                'name': 'NIDCPOWER_VAL_POWER_LINE_CYCLES',
                'value': 1029
            }
        ]
    },
    'AutoZero': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_OFF',
                'value': 0
            },
            {
                'name': 'NIDCPOWER_VAL_ON',
                'value': 1
            },
            {
                'name': 'NIDCPOWER_VAL_ONCE',
                'value': 1024
            }
        ]
    },
    'AutorangeApertureTimeMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_APERTURE_TIME_AUTO',
                'value': 1110
            },
            {
                'name': 'NIDCPOWER_VAL_APERTURE_TIME_CUSTOM',
                'value': 1111
            }
        ]
    },
    'AutorangeBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_RANGE_UP_TO_LIMIT_THEN_DOWN',
                'value': 1107
            },
            {
                'name': 'NIDCPOWER_VAL_RANGE_UP',
                'value': 1108
            },
            {
                'name': 'NIDCPOWER_VAL_RANGE_UP_AND_DOWN',
                'value': 1109
            }
        ]
    },
    'AutorangeThresholdMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_THRESHOLD_MODE_NORMAL',
                'value': 1112
            },
            {
                'name': 'NIDCPOWER_VAL_THRESHOLD_MODE_FAST_STEP',
                'value': 1113
            },
            {
                'name': 'NIDCPOWER_VAL_THRESHOLD_MODE_HIGH_HYSTERESIS',
                'value': 1114
            },
            {
                'name': 'NIDCPOWER_VAL_THRESHOLD_MODE_MEDIUM_HYSTERESIS',
                'value': 1115
            },
            {
                'name': 'NIDCPOWER_VAL_THRESHOLD_MODE_HOLD',
                'value': 1116
            }
        ]
    },
    'CableLength': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_ZERO_M',
                'value': 1121
            },
            {
                'name': 'NIDCPOWER_VAL_NI_STANDARD_1M',
                'value': 1122
            },
            {
                'name': 'NIDCPOWER_VAL_NI_STANDARD_2M',
                'value': 1123
            },
            {
                'name': 'NIDCPOWER_VAL_NI_STANDARD_4M',
                'value': 1124
            },
            {
                'name': 'NIDCPOWER_VAL_CUSTOM_ONBOARD_STORAGE',
                'value': 1125
            },
            {
                'name': 'NIDCPOWER_VAL_CUSTOM_AS_CONFIGURED',
                'value': 1126
            },
            {
                'name': 'NIDCPOWER_VAL_NI_STANDARD_TRIAXIAL_1M',
                'value': 1139
            },
            {
                'name': 'NIDCPOWER_VAL_NI_STANDARD_TRIAXIAL_2M',
                'value': 1140
            },
            {
                'name': 'NIDCPOWER_VAL_NI_STANDARD_TRIAXIAL_4M',
                'value': 1141
            }
        ]
    },
    'ComplianceLimitSymmetry': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_SYMMETRIC',
                'value': 0
            },
            {
                'name': 'NIDCPOWER_VAL_ASYMMETRIC',
                'value': 1
            }
        ]
    },
    'CurrentLimitBehavior': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_CURRENT_REGULATE',
                'value': 0
            },
            {
                'name': 'NIDCPOWER_VAL_CURRENT_TRIP',
                'value': 1
            }
        ]
    },
    'DCNoiseRejection': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_DC_NOISE_REJECTION_SECOND_ORDER',
                'value': 1043
            },
            {
                'name': 'NIDCPOWER_VAL_DC_NOISE_REJECTION_NORMAL',
                'value': 1044
            }
        ]
    },
    'DigitalEdge': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_RISING',
                'value': 1016
            },
            {
                'name': 'NIDCPOWER_VAL_FALLING',
                'value': 1017
            }
        ]
    },
    'Event': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_SOURCE_COMPLETE',
                'value': 1030
            },
            {
                'name': 'NIDCPOWER_VAL_MEASURE_COMPLETE',
                'value': 1031
            },
            {
                'name': 'NIDCPOWER_VAL_SEQUENCE_ITERATION_COMPLETE',
                'value': 1032
            },
            {
                'name': 'NIDCPOWER_VAL_SEQUENCE_ENGINE_DONE',
                'value': 1033
            },
            {
                'name': 'NIDCPOWER_VAL_PULSE_COMPLETE',
                'value': 1051
            },
            {
                'name': 'NIDCPOWER_VAL_READY_FOR_PULSE_TRIGGER',
                'value': 1052
            }
        ]
    },
    'ExportSignal': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_SOURCE_COMPLETE_EVENT',
                'value': 1030
            },
            {
                'name': 'NIDCPOWER_VAL_MEASURE_COMPLETE_EVENT',
                'value': 1031
            },
            {
                'name': 'NIDCPOWER_VAL_SEQUENCE_ITERATION_COMPLETE_EVENT',
                'value': 1032
            },
            {
                'name': 'NIDCPOWER_VAL_SEQUENCE_ENGINE_DONE_EVENT',
                'value': 1033
            },
            {
                'name': 'NIDCPOWER_VAL_PULSE_COMPLETE_EVENT',
                'value': 1051
            },
            {
                'name': 'NIDCPOWER_VAL_READY_FOR_PULSE_TRIGGER_EVENT',
                'value': 1052
            },
            {
                'name': 'NIDCPOWER_VAL_START_TRIGGER',
                'value': 1034
            },
            {
                'name': 'NIDCPOWER_VAL_SOURCE_TRIGGER',
                'value': 1035
            },
            {
                'name': 'NIDCPOWER_VAL_MEASURE_TRIGGER',
                'value': 1036
            },
            {
                'name': 'NIDCPOWER_VAL_SEQUENCE_ADVANCE_TRIGGER',
                'value': 1037
            },
            {
                'name': 'NIDCPOWER_VAL_PULSE_TRIGGER',
                'value': 1053
            },
            {
                'name': 'NIDCPOWER_VAL_SHUTDOWN_TRIGGER',
                'value': 1118
            }
        ]
    },
    'InstrumentMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_SMU_PS',
                'value': 1061
            },
            {
                'name': 'NIDCPOWER_VAL_LCR',
                'value': 1062
            }
        ]
    },
    'IsolationState': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_ISOLATED',
                'value': 1128
            },
            {
                'name': 'NIDCPOWER_VAL_NON_ISOLATED',
                'value': 1129
            }
        ]
    },
    'LCRAutomaticLevelControl': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_OFF',
                'value': 0
            },
            {
                'name': 'NIDCPOWER_VAL_ON',
                'value': 1
            }
        ]
    },
    'LCRCompensationType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_OPEN_COMPENSATION',
                'value': 1130
            },
            {
                'name': 'NIDCPOWER_VAL_SHORT_COMPENSATION',
                'value': 1131
            },
            {
                'name': 'NIDCPOWER_VAL_LOAD_COMPENSATION',
                'value': 1132
            },
            {
                'name': 'NIDCPOWER_VAL_OPEN_CUSTOM_CABLE_COMPENSATION',
                'value': 1133
            },
            {
                'name': 'NIDCPOWER_VAL_SHORT_CUSTOM_CABLE_COMPENSATION',
                'value': 1134
            }
        ]
    },
    'LCRDCBiasSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_DC_BIAS_OFF',
                'value': 1065
            },
            {
                'name': 'NIDCPOWER_VAL_DC_BIAS_VOLTAGE',
                'value': 1066
            },
            {
                'name': 'NIDCPOWER_VAL_DC_BIAS_CURRENT',
                'value': 1067
            }
        ]
    },
    'LCRImpedanceAutoRange': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_AUTO_RANGE_OFF',
                'value': 1068
            },
            {
                'name': 'NIDCPOWER_VAL_AUTO_RANGE_ON',
                'value': 1070
            }
        ]
    },
    'LCRImpedanceRangeSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_LCR_IMPEDANCE_RANGE',
                'value': 1142
            },
            {
                'name': 'NIDCPOWER_VAL_LCR_LOAD_CONFIGURATION',
                'value': 1143
            }
        ]
    },
    'LCRMeasurementTime': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_MEASUREMENT_TIME_SHORT',
                'value': 1071
            },
            {
                'name': 'NIDCPOWER_VAL_MEASUREMENT_TIME_MEDIUM',
                'value': 1072
            },
            {
                'name': 'NIDCPOWER_VAL_MEASUREMENT_TIME_LONG',
                'value': 1073
            },
            {
                'name': 'NIDCPOWER_VAL_MEASUREMENT_TIME_CUSTOM',
                'value': 1117
            }
        ]
    },
    'LCROpenShortLoadCompensationDataSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_ONBOARD_STORAGE',
                'value': 1074
            },
            {
                'name': 'NIDCPOWER_VAL_AS_DEFINED',
                'value': 1075
            },
            {
                'name': 'NIDCPOWER_VAL_AS_CONFIGURED',
                'value': 1146
            }
        ]
    },
    'LCRSourceDelayMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_LCR_SOURCE_DELAY_MODE_AUTOMATIC',
                'value': 1144
            },
            {
                'name': 'NIDCPOWER_VAL_LCR_SOURCE_DELAY_MODE_MANUAL',
                'value': 1145
            }
        ]
    },
    'LCRStimulusFunction': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_AC_VOLTAGE',
                'value': 1063
            },
            {
                'name': 'NIDCPOWER_VAL_AC_CURRENT',
                'value': 1064
            }
        ]
    },
    'MeasureWhen': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE',
                'value': 1025
            },
            {
                'name': 'NIDCPOWER_VAL_ON_DEMAND',
                'value': 1026
            },
            {
                'name': 'NIDCPOWER_VAL_ON_MEASURE_TRIGGER',
                'value': 1027
            }
        ]
    },
    'MeasurementTypes': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_MEASURE_CURRENT',
                'value': 0
            },
            {
                'name': 'NIDCPOWER_VAL_MEASURE_VOLTAGE',
                'value': 1
            }
        ]
    },
    'NiDCPowerInt32AttributeValues': {
        'enum-value-prefix': 'NIDCPOWER_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'APERTURE_TIME_AUTO_MODE_VAL_APERTURE_TIME_AUTO_MODE_OFF',
                'value': 1135
            },
            {
                'name': 'APERTURE_TIME_AUTO_MODE_VAL_APERTURE_TIME_AUTO_MODE_SHORT',
                'value': 1136
            },
            {
                'name': 'APERTURE_TIME_AUTO_MODE_VAL_APERTURE_TIME_AUTO_MODE_NORMAL',
                'value': 1137
            },
            {
                'name': 'APERTURE_TIME_AUTO_MODE_VAL_APERTURE_TIME_AUTO_MODE_LONG',
                'value': 1138
            },
            {
                'name': 'APERTURE_TIME_UNITS_VAL_SECONDS',
                'value': 1028
            },
            {
                'name': 'APERTURE_TIME_UNITS_VAL_POWER_LINE_CYCLES',
                'value': 1029
            },
            {
                'name': 'AUTO_ZERO_VAL_OFF',
                'value': 0
            },
            {
                'name': 'AUTO_ZERO_VAL_ON',
                'value': 1
            },
            {
                'name': 'AUTO_ZERO_VAL_ONCE',
                'value': 1024
            },
            {
                'name': 'AUTORANGE_APERTURE_TIME_MODE_VAL_APERTURE_TIME_AUTO',
                'value': 1110
            },
            {
                'name': 'AUTORANGE_APERTURE_TIME_MODE_VAL_APERTURE_TIME_CUSTOM',
                'value': 1111
            },
            {
                'name': 'AUTORANGE_BEHAVIOR_VAL_RANGE_UP_TO_LIMIT_THEN_DOWN',
                'value': 1107
            },
            {
                'name': 'AUTORANGE_BEHAVIOR_VAL_RANGE_UP',
                'value': 1108
            },
            {
                'name': 'AUTORANGE_BEHAVIOR_VAL_RANGE_UP_AND_DOWN',
                'value': 1109
            },
            {
                'name': 'AUTORANGE_THRESHOLD_MODE_VAL_THRESHOLD_MODE_NORMAL',
                'value': 1112
            },
            {
                'name': 'AUTORANGE_THRESHOLD_MODE_VAL_THRESHOLD_MODE_FAST_STEP',
                'value': 1113
            },
            {
                'name': 'AUTORANGE_THRESHOLD_MODE_VAL_THRESHOLD_MODE_HIGH_HYSTERESIS',
                'value': 1114
            },
            {
                'name': 'AUTORANGE_THRESHOLD_MODE_VAL_THRESHOLD_MODE_MEDIUM_HYSTERESIS',
                'value': 1115
            },
            {
                'name': 'AUTORANGE_THRESHOLD_MODE_VAL_THRESHOLD_MODE_HOLD',
                'value': 1116
            },
            {
                'name': 'CABLE_LENGTH_VAL_ZERO_M',
                'value': 1121
            },
            {
                'name': 'CABLE_LENGTH_VAL_NI_STANDARD_1M',
                'value': 1122
            },
            {
                'name': 'CABLE_LENGTH_VAL_NI_STANDARD_2M',
                'value': 1123
            },
            {
                'name': 'CABLE_LENGTH_VAL_NI_STANDARD_4M',
                'value': 1124
            },
            {
                'name': 'CABLE_LENGTH_VAL_CUSTOM_ONBOARD_STORAGE',
                'value': 1125
            },
            {
                'name': 'CABLE_LENGTH_VAL_CUSTOM_AS_CONFIGURED',
                'value': 1126
            },
            {
                'name': 'CABLE_LENGTH_VAL_NI_STANDARD_TRIAXIAL_1M',
                'value': 1139
            },
            {
                'name': 'CABLE_LENGTH_VAL_NI_STANDARD_TRIAXIAL_2M',
                'value': 1140
            },
            {
                'name': 'CABLE_LENGTH_VAL_NI_STANDARD_TRIAXIAL_4M',
                'value': 1141
            },
            {
                'name': 'COMPLIANCE_LIMIT_SYMMETRY_VAL_SYMMETRIC',
                'value': 0
            },
            {
                'name': 'COMPLIANCE_LIMIT_SYMMETRY_VAL_ASYMMETRIC',
                'value': 1
            },
            {
                'name': 'CURRENT_LIMIT_BEHAVIOR_VAL_CURRENT_REGULATE',
                'value': 0
            },
            {
                'name': 'CURRENT_LIMIT_BEHAVIOR_VAL_CURRENT_TRIP',
                'value': 1
            },
            {
                'name': 'DC_NOISE_REJECTION_VAL_DC_NOISE_REJECTION_SECOND_ORDER',
                'value': 1043
            },
            {
                'name': 'DC_NOISE_REJECTION_VAL_DC_NOISE_REJECTION_NORMAL',
                'value': 1044
            },
            {
                'name': 'DIGITAL_EDGE_VAL_RISING',
                'value': 1016
            },
            {
                'name': 'DIGITAL_EDGE_VAL_FALLING',
                'value': 1017
            },
            {
                'name': 'INSTRUMENT_MODE_VAL_SMU_PS',
                'value': 1061
            },
            {
                'name': 'INSTRUMENT_MODE_VAL_LCR',
                'value': 1062
            },
            {
                'name': 'ISOLATION_STATE_VAL_ISOLATED',
                'value': 1128
            },
            {
                'name': 'ISOLATION_STATE_VAL_NON_ISOLATED',
                'value': 1129
            },
            {
                'name': 'LCR_AUTOMATIC_LEVEL_CONTROL_VAL_OFF',
                'value': 0
            },
            {
                'name': 'LCR_AUTOMATIC_LEVEL_CONTROL_VAL_ON',
                'value': 1
            },
            {
                'name': 'LCRDC_BIAS_SOURCE_VAL_DC_BIAS_OFF',
                'value': 1065
            },
            {
                'name': 'LCRDC_BIAS_SOURCE_VAL_DC_BIAS_VOLTAGE',
                'value': 1066
            },
            {
                'name': 'LCRDC_BIAS_SOURCE_VAL_DC_BIAS_CURRENT',
                'value': 1067
            },
            {
                'name': 'LCR_IMPEDANCE_AUTO_RANGE_VAL_AUTO_RANGE_OFF',
                'value': 1068
            },
            {
                'name': 'LCR_IMPEDANCE_AUTO_RANGE_VAL_AUTO_RANGE_ON',
                'value': 1070
            },
            {
                'name': 'LCR_IMPEDANCE_RANGE_SOURCE_VAL_LCR_IMPEDANCE_RANGE',
                'value': 1142
            },
            {
                'name': 'LCR_IMPEDANCE_RANGE_SOURCE_VAL_LCR_LOAD_CONFIGURATION',
                'value': 1143
            },
            {
                'name': 'LCR_MEASUREMENT_TIME_VAL_MEASUREMENT_TIME_SHORT',
                'value': 1071
            },
            {
                'name': 'LCR_MEASUREMENT_TIME_VAL_MEASUREMENT_TIME_MEDIUM',
                'value': 1072
            },
            {
                'name': 'LCR_MEASUREMENT_TIME_VAL_MEASUREMENT_TIME_LONG',
                'value': 1073
            },
            {
                'name': 'LCR_MEASUREMENT_TIME_VAL_MEASUREMENT_TIME_CUSTOM',
                'value': 1117
            },
            {
                'name': 'LCR_OPEN_SHORT_LOAD_COMPENSATION_DATA_SOURCE_VAL_ONBOARD_STORAGE',
                'value': 1074
            },
            {
                'name': 'LCR_OPEN_SHORT_LOAD_COMPENSATION_DATA_SOURCE_VAL_AS_DEFINED',
                'value': 1075
            },
            {
                'name': 'LCR_OPEN_SHORT_LOAD_COMPENSATION_DATA_SOURCE_VAL_AS_CONFIGURED',
                'value': 1146
            },
            {
                'name': 'LCR_SOURCE_DELAY_MODE_VAL_LCR_SOURCE_DELAY_MODE_AUTOMATIC',
                'value': 1144
            },
            {
                'name': 'LCR_SOURCE_DELAY_MODE_VAL_LCR_SOURCE_DELAY_MODE_MANUAL',
                'value': 1145
            },
            {
                'name': 'LCR_STIMULUS_FUNCTION_VAL_AC_VOLTAGE',
                'value': 1063
            },
            {
                'name': 'LCR_STIMULUS_FUNCTION_VAL_AC_CURRENT',
                'value': 1064
            },
            {
                'name': 'MEASURE_WHEN_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE',
                'value': 1025
            },
            {
                'name': 'MEASURE_WHEN_VAL_ON_DEMAND',
                'value': 1026
            },
            {
                'name': 'MEASURE_WHEN_VAL_ON_MEASURE_TRIGGER',
                'value': 1027
            },
            {
                'name': 'OUTPUT_CAPACITANCE_VAL_LOW',
                'value': 1010
            },
            {
                'name': 'OUTPUT_CAPACITANCE_VAL_HIGH',
                'value': 1011
            },
            {
                'name': 'OUTPUT_FUNCTION_VAL_DC_VOLTAGE',
                'value': 1006
            },
            {
                'name': 'OUTPUT_FUNCTION_VAL_DC_CURRENT',
                'value': 1007
            },
            {
                'name': 'OUTPUT_FUNCTION_VAL_PULSE_VOLTAGE',
                'value': 1049
            },
            {
                'name': 'OUTPUT_FUNCTION_VAL_PULSE_CURRENT',
                'value': 1050
            },
            {
                'name': 'POLARITY_VAL_ACTIVE_HIGH',
                'value': 1018
            },
            {
                'name': 'POLARITY_VAL_ACTIVE_LOW',
                'value': 1019
            },
            {
                'name': 'POWER_ALLOCATION_MODE_VAL_DISABLED',
                'value': 1058
            },
            {
                'name': 'POWER_ALLOCATION_MODE_VAL_AUTOMATIC',
                'value': 1059
            },
            {
                'name': 'POWER_ALLOCATION_MODE_VAL_MANUAL',
                'value': 1060
            },
            {
                'name': 'POWER_SOURCE_VAL_INTERNAL',
                'value': 1003
            },
            {
                'name': 'POWER_SOURCE_VAL_AUXILIARY',
                'value': 1004
            },
            {
                'name': 'POWER_SOURCE_VAL_AUTOMATIC',
                'value': 1005
            },
            {
                'name': 'POWER_SOURCE_IN_USE_VAL_INTERNAL',
                'value': 1003
            },
            {
                'name': 'POWER_SOURCE_IN_USE_VAL_AUXILIARY',
                'value': 1004
            },
            {
                'name': 'SELF_CALIBRATION_PERSISTENCE_VAL_KEEP_IN_MEMORY',
                'value': 1045
            },
            {
                'name': 'SELF_CALIBRATION_PERSISTENCE_VAL_WRITE_TO_EEPROM',
                'value': 1046
            },
            {
                'name': 'SENSE_VAL_LOCAL',
                'value': 1008
            },
            {
                'name': 'SENSE_VAL_REMOTE',
                'value': 1009
            },
            {
                'name': 'SOURCE_MODE_VAL_SINGLE_POINT',
                'value': 1020
            },
            {
                'name': 'SOURCE_MODE_VAL_SEQUENCE',
                'value': 1021
            },
            {
                'name': 'TRANSIENT_RESPONSE_VAL_NORMAL',
                'value': 1038
            },
            {
                'name': 'TRANSIENT_RESPONSE_VAL_FAST',
                'value': 1039
            },
            {
                'name': 'TRANSIENT_RESPONSE_VAL_SLOW',
                'value': 1041
            },
            {
                'name': 'TRANSIENT_RESPONSE_VAL_CUSTOM',
                'value': 1042
            },
            {
                'name': 'TRIGGER_TYPE_VAL_NONE',
                'value': 1012
            },
            {
                'name': 'TRIGGER_TYPE_VAL_DIGITAL_EDGE',
                'value': 1014
            },
            {
                'name': 'TRIGGER_TYPE_VAL_SOFTWARE_EDGE',
                'value': 1015
            }
        ]
    },
    'NiDCPowerReal64AttributeValues': {
        'enum-value-prefix': 'NIDCPOWER_REAL64',
        'generate-mappings': False,
        'values': [
            {
                'name': 'POWER_LINE_FREQUENCIES_VAL_50_HERTZ',
                'value': 50
            },
            {
                'name': 'POWER_LINE_FREQUENCIES_VAL_60_HERTZ',
                'value': 60
            }
        ]
    },
    'OutputCapacitance': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_LOW',
                'value': 1010
            },
            {
                'name': 'NIDCPOWER_VAL_HIGH',
                'value': 1011
            }
        ]
    },
    'OutputCutoffReason': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_ALL',
                'value': -1
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_OUTPUT_HIGH',
                'value': 1
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_OUTPUT_LOW',
                'value': 2
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_MEASURE_HIGH',
                'value': 4
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_MEASURE_LOW',
                'value': 8
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_CHANGE_HIGH',
                'value': 16
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_VOLTAGE_CHANGE_LOW',
                'value': 32
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_CHANGE_HIGH',
                'value': 64
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CUTOFF_REASON_CURRENT_CHANGE_LOW',
                'value': 128
            }
        ]
    },
    'OutputFunction': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_DC_VOLTAGE',
                'value': 1006
            },
            {
                'name': 'NIDCPOWER_VAL_DC_CURRENT',
                'value': 1007
            },
            {
                'name': 'NIDCPOWER_VAL_PULSE_VOLTAGE',
                'value': 1049
            },
            {
                'name': 'NIDCPOWER_VAL_PULSE_CURRENT',
                'value': 1050
            }
        ]
    },
    'OutputStates': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CONSTANT_VOLTAGE',
                'value': 0
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_CONSTANT_CURRENT',
                'value': 1
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_OVER_VOLTAGE',
                'value': 2
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_OVER_CURRENT',
                'value': 3
            },
            {
                'name': 'NIDCPOWER_VAL_OUTPUT_UNREGULATED',
                'value': 4
            }
        ]
    },
    'Polarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_ACTIVE_HIGH',
                'value': 1018
            },
            {
                'name': 'NIDCPOWER_VAL_ACTIVE_LOW',
                'value': 1019
            }
        ]
    },
    'PowerAllocationMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_DISABLED',
                'value': 1058
            },
            {
                'name': 'NIDCPOWER_VAL_AUTOMATIC',
                'value': 1059
            },
            {
                'name': 'NIDCPOWER_VAL_MANUAL',
                'value': 1060
            }
        ]
    },
    'PowerLineFrequencies': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_50_HERTZ',
                'value': 50
            },
            {
                'name': 'NIDCPOWER_VAL_60_HERTZ',
                'value': 60
            }
        ]
    },
    'PowerSource': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_INTERNAL',
                'value': 1003
            },
            {
                'name': 'NIDCPOWER_VAL_AUXILIARY',
                'value': 1004
            },
            {
                'name': 'NIDCPOWER_VAL_AUTOMATIC',
                'value': 1005
            }
        ]
    },
    'PowerSourceInUse': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_INTERNAL',
                'value': 1003
            },
            {
                'name': 'NIDCPOWER_VAL_AUXILIARY',
                'value': 1004
            }
        ]
    },
    'SelfCalibrationPersistence': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_KEEP_IN_MEMORY',
                'value': 1045
            },
            {
                'name': 'NIDCPOWER_VAL_WRITE_TO_EEPROM',
                'value': 1046
            }
        ]
    },
    'SendSoftwareEdgeTriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_START',
                'value': 1034
            },
            {
                'name': 'NIDCPOWER_VAL_SOURCE',
                'value': 1035
            },
            {
                'name': 'NIDCPOWER_VAL_MEASURE',
                'value': 1036
            },
            {
                'name': 'NIDCPOWER_VAL_SEQUENCE_ADVANCE',
                'value': 1037
            },
            {
                'name': 'NIDCPOWER_VAL_PULSE',
                'value': 1053
            },
            {
                'name': 'NIDCPOWER_VAL_SHUTDOWN',
                'value': 1118
            }
        ]
    },
    'Sense': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_LOCAL',
                'value': 1008
            },
            {
                'name': 'NIDCPOWER_VAL_REMOTE',
                'value': 1009
            }
        ]
    },
    'SourceMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_SINGLE_POINT',
                'value': 1020
            },
            {
                'name': 'NIDCPOWER_VAL_SEQUENCE',
                'value': 1021
            }
        ]
    },
    'TransientResponse': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_NORMAL',
                'value': 1038
            },
            {
                'name': 'NIDCPOWER_VAL_FAST',
                'value': 1039
            },
            {
                'name': 'NIDCPOWER_VAL_SLOW',
                'value': 1041
            },
            {
                'name': 'NIDCPOWER_VAL_CUSTOM',
                'value': 1042
            }
        ]
    },
    'TriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NIDCPOWER_VAL_NONE',
                'value': 1012
            },
            {
                'name': 'NIDCPOWER_VAL_DIGITAL_EDGE',
                'value': 1014
            },
            {
                'name': 'NIDCPOWER_VAL_SOFTWARE_EDGE',
                'value': 1015
            }
        ]
    }
}
