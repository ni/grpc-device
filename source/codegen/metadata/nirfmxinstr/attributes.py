attributes = {
    2: {
        'access': 'read-write',
        'enum': 'FrequencyReferenceSource',
        'name': 'FREQUENCY_REFERENCE_SOURCE',
        'type': 'char[]'
    },
    3: {
        'access': 'read-write',
        'name': 'FREQUENCY_REFERENCE_FREQUENCY',
        'type': 'float64'
    },
    4: {
        'access': 'read-write',
        'enum': 'RFAttenuationAuto',
        'name': 'RF_ATTENUATION_AUTO',
        'type': 'int32'
    },
    5: {
        'access': 'read-write',
        'name': 'RF_ATTENUATION_VALUE',
        'type': 'float64'
    },
    6: {
        'access': 'read-write',
        'enum': 'MechanicalAttenuationAuto',
        'name': 'MECHANICAL_ATTENUATION_AUTO',
        'type': 'int32'
    },
    7: {
        'access': 'read-write',
        'name': 'MECHANICAL_ATTENUATION_VALUE',
        'type': 'float64'
    },
    8: {
        'access': 'read-write',
        'enum': 'TuningSpeed',
        'name': 'TUNING_SPEED',
        'type': 'int32'
    },
    9: {
        'access': 'read-write',
        'enum': 'FrequencySettlingUnits',
        'name': 'FREQUENCY_SETTLING_UNITS',
        'type': 'int32'
    },
    10: {
        'access': 'read-write',
        'name': 'FREQUENCY_SETTLING',
        'type': 'float64'
    },
    11: {
        'access': 'read-write',
        'enum': 'ChannelCoupling',
        'name': 'CHANNEL_COUPLING',
        'type': 'int32'
    },
    12: {
        'access': 'read-write',
        'enum': 'DownconverterPreselectorEnabled',
        'name': 'DOWNCONVERTER_PRESELECTOR_ENABLED',
        'type': 'int32'
    },
    13: {
        'access': 'read-write',
        'name': 'DOWNCONVERTER_CENTER_FREQUENCY',
        'type': 'float64'
    },
    14: {
        'access': 'read-write',
        'name': 'PREAMP_ENABLED',
        'type': 'int32'
    },
    15: {
        'access': 'read-write',
        'name': 'MIXER_LEVEL_OFFSET',
        'type': 'float64'
    },
    16: {
        'access': 'read-write',
        'name': 'MIXER_LEVEL',
        'type': 'float64'
    },
    17: {
        'access': 'read-write',
        'name': 'IF_OUTPUT_POWER_LEVEL_OFFSET',
        'type': 'float64'
    },
    18: {
        'access': 'read-write',
        'enum': 'LOInjectionSide',
        'name': 'LO_INJECTION_SIDE',
        'type': 'int32'
    },
    19: {
        'access': 'read-write',
        'name': 'PHASE_OFFSET',
        'type': 'float64'
    },
    21: {
        'access': 'read-write',
        'enum': 'DigitizerDitherEnabled',
        'name': 'DIGITIZER_DITHER_ENABLED',
        'type': 'int32'
    },
    22: {
        'access': 'read-write',
        'name': 'FFT_WIDTH',
        'type': 'float64'
    },
    23: {
        'access': 'read-write',
        'enum': 'OspDelayEnabled',
        'name': 'OSP_DELAY_ENABLED',
        'type': 'int32'
    },
    24: {
        'access': 'read-write',
        'name': 'DEVICE_TEMPERATURE',
        'type': 'float64'
    },
    25: {
        'access': 'read-write',
        'name': 'DIGITIZER_TEMPERATURE',
        'type': 'float64'
    },
    26: {
        'access': 'read-write',
        'name': 'LO_TEMPERATURE',
        'type': 'float64'
    },
    27: {
        'access': 'read-write',
        'name': 'INSTRUMENT_FIRMWARE_REVISION',
        'type': 'char[]'
    },
    28: {
        'access': 'read-write',
        'name': 'INSTRUMENT_MODEL',
        'type': 'char[]'
    },
    29: {
        'access': 'read-write',
        'name': 'MODULE_REVISION',
        'type': 'char[]'
    },
    30: {
        'access': 'read-write',
        'name': 'SERIAL_NUMBER',
        'type': 'char[]'
    },
    31: {
        'access': 'read-write',
        'name': 'PRESELECTOR_PRESENT',
        'type': 'int32'
    },
    32: {
        'access': 'read-write',
        'name': 'RF_PREAMP_PRESENT',
        'type': 'int32'
    },
    33: {
        'access': 'read-write',
        'enum': 'LOExportEnabled',
        'name': 'LO_EXPORT_ENABLED',
        'type': 'int32'
    },
    34: {
        'access': 'read-write',
        'enum': 'FrequencyReferenceExportedTerminal',
        'name': 'FREQUENCY_REFERENCE_EXPORTED_TERMINAL',
        'type': 'char[]'
    },
    35: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'TRIGGER_EXPORT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    36: {
        'access': 'read-write',
        'name': 'TRIGGER_TERMINAL_NAME',
        'type': 'char[]'
    },
    37: {
        'access': 'read-write',
        'enum': 'CleanerSpectrumEnabled',
        'name': 'CLEANER_SPECTRUM_ENABLED',
        'type': 'int32'
    },
    39: {
        'access': 'read-write',
        'enum': 'RecommendedAcquisitionType',
        'name': 'RECOMMENDED_ACQUISITION_TYPE',
        'type': 'int32'
    },
    40: {
        'access': 'read-write',
        'name': 'RECOMMENDED_NUMBER_OF_RECORDS',
        'type': 'int32'
    },
    41: {
        'access': 'read-write',
        'name': 'RECOMMENDED_TRIGGER_MINIMUM_QUIET_TIME',
        'type': 'float64'
    },
    42: {
        'access': 'read-write',
        'name': 'RECOMMENDED_IQ_ACQUISITION_TIME',
        'type': 'float64'
    },
    43: {
        'access': 'read-write',
        'name': 'RECOMMENDED_IQ_MINIMUM_SAMPLE_RATE',
        'type': 'float64'
    },
    44: {
        'access': 'read-write',
        'name': 'RECOMMENDED_IQ_PRE_TRIGGER_TIME',
        'type': 'float64'
    },
    45: {
        'access': 'read-write',
        'name': 'RECOMMENDED_SPECTRAL_ACQUISITION_SPAN',
        'type': 'float64'
    },
    46: {
        'access': 'read-write',
        'enum': 'RecommendedSpectralFftWindow',
        'name': 'RECOMMENDED_SPECTRAL_FFT_WINDOW',
        'type': 'int32'
    },
    47: {
        'access': 'read-write',
        'name': 'RECOMMENDED_SPECTRAL_RESOLUTION_BANDWIDTH',
        'type': 'float64'
    },
    48: {
        'access': 'read-write',
        'name': 'IF_FILTER_BANDWIDTH',
        'type': 'float64'
    },
    49: {
        'access': 'read-write',
        'name': 'RF_HIGHPASS_FILTER_FREQUENCY',
        'type': 'float64'
    },
    50: {
        'access': 'read-write',
        'name': 'SUBSPAN_OVERLAP',
        'type': 'float64'
    },
    51: {
        'access': 'read-write',
        'name': 'RECOMMENDED_IQ_MEASUREMENT_BANDWIDTH',
        'type': 'float64'
    },
    52: {
        'access': 'read-write',
        'name': 'DOWNCONVERTER_GAIN',
        'type': 'float64'
    },
    53: {
        'access': 'read-write',
        'name': 'DOWNCONVERTER_FREQUENCY_OFFSET',
        'type': 'float64'
    },
    54: {
        'access': 'read-write',
        'name': 'RF_ATTENUATION_STEP_SIZE',
        'type': 'float64'
    },
    55: {
        'access': 'read-write',
        'enum': 'LOLeakageAvoidanceEnabled',
        'name': 'LO_LEAKAGE_AVOIDANCE_ENABLED',
        'type': 'int32'
    },
    56: {
        'access': 'read-write',
        'name': 'AMPLITUDE_SETTLING',
        'type': 'float64'
    },
    57: {
        'access': 'read-write',
        'name': 'RECOMMENDED_CENTER_FREQUENCY',
        'type': 'float64'
    },
    58: {
        'access': 'read-write',
        'enum': 'LO2ExportEnabled',
        'name': 'LO2_EXPORT_ENABLED',
        'type': 'int32'
    },
    59: {
        'access': 'read-write',
        'enum': 'LOSource',
        'name': 'LO_SOURCE',
        'type': 'char[]'
    },
    60: {
        'access': 'read-write',
        'name': 'LO_FREQUENCY',
        'type': 'float64'
    },
    68: {
        'access': 'read-write',
        'enum': 'LOSharingMode',
        'name': 'LO_SHARING_MODE',
        'type': 'int32'
    },
    70: {
        'access': 'read-write',
        'name': 'COMMON_MODE_LEVEL',
        'type': 'float64'
    },
    71: {
        'access': 'read-write',
        'name': 'SMU_RESOURCE_NAME',
        'type': 'char[]'
    },
    72: {
        'access': 'read-write',
        'name': 'SMU_CHANNEL',
        'type': 'char[]'
    },
    74: {
        'access': 'read-write',
        'enum': 'AutomaticSGSASharedLOEnabled',
        'name': 'AUTOMATIC_SG_SA_SHARED_LO_ENABLED',
        'type': 'int32'
    },
    77: {
        'access': 'read-write',
        'enum': 'OverflowErrorReporting',
        'name': 'OVERFLOW_ERROR_REPORTING',
        'type': 'int32'
    },
    78: {
        'access': 'read-write',
        'name': 'LO_IN_POWER',
        'type': 'float64'
    },
    79: {
        'access': 'read-write',
        'name': 'LO_OUT_POWER',
        'type': 'float64'
    },
    80: {
        'access': 'read-write',
        'name': 'LO_VCO_FREQUENCY_STEP_SIZE',
        'type': 'float64'
    },
    84: {
        'access': 'read-write',
        'name': 'DIGITAL_GAIN',
        'type': 'float64'
    },
    90: {
        'access': 'read-write',
        'enum': 'LOPllFractionalModeEnabled',
        'name': 'LO_PLL_FRACTIONAL_MODE_ENABLED',
        'type': 'int32'
    },
    91: {
        'access': 'read-write',
        'enum': 'OptimizePathForSignalBandwidth',
        'name': 'OPTIMIZE_PATH_FOR_SIGNAL_BANDWIDTH',
        'type': 'int32'
    },
    92: {
        'access': 'read-write',
        'enum': 'InputIsolationEnabled',
        'name': 'INPUT_ISOLATION_ENABLED',
        'type': 'int32'
    },
    94: {
        'access': 'read-write',
        'name': 'THERMAL_CORRECTION_HEADROOM_RANGE',
        'type': 'float64'
    },
    95: {
        'access': 'read-write',
        'name': 'LO_FREQUENCY_STEP_SIZE',
        'type': 'float64'
    },
    97: {
        'access': 'read-write',
        'name': 'NUMBER_OF_LO_SHARING_GROUPS',
        'type': 'int32'
    },
    98: {
        'access': 'read-write',
        'enum': 'StartTriggerType',
        'name': 'START_TRIGGER_TYPE',
        'type': 'int32'
    },
    99: {
        'access': 'read-write',
        'enum': 'DigitalEdgeTriggerSource',
        'name': 'START_TRIGGER_DIGITAL_EDGE_SOURCE',
        'type': 'char[]'
    },
    100: {
        'access': 'read-write',
        'enum': 'StartTriggerDigitalEdge',
        'name': 'START_TRIGGER_DIGITAL_EDGE',
        'type': 'int32'
    },
    101: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'START_TRIGGER_EXPORT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    102: {
        'access': 'read-write',
        'name': 'START_TRIGGER_TERMINAL_NAME',
        'type': 'char[]'
    },
    103: {
        'access': 'read-write',
        'enum': 'AdvanceTriggerType',
        'name': 'ADVANCE_TRIGGER_TYPE',
        'type': 'int32'
    },
    104: {
        'access': 'read-write',
        'enum': 'DigitalEdgeTriggerSource',
        'name': 'ADVANCE_TRIGGER_DIGITAL_EDGE_SOURCE',
        'type': 'char[]'
    },
    105: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'ADVANCE_TRIGGER_EXPORT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    106: {
        'access': 'read-write',
        'name': 'ADVANCE_TRIGGER_TERMINAL_NAME',
        'type': 'char[]'
    },
    107: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'READY_FOR_START_EVENT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    108: {
        'access': 'read-write',
        'name': 'READY_FOR_START_EVENT_TERMINAL_NAME',
        'type': 'char[]'
    },
    109: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    110: {
        'access': 'read-write',
        'name': 'READY_FOR_ADVANCE_EVENT_TERMINAL_NAME',
        'type': 'char[]'
    },
    111: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'READY_FOR_REFERENCE_EVENT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    112: {
        'access': 'read-write',
        'name': 'READY_FOR_REFERENCE_EVENT_TERMINAL_NAME',
        'type': 'char[]'
    },
    113: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'END_OF_RECORD_EVENT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    114: {
        'access': 'read-write',
        'name': 'END_OF_RECORD_EVENT_TERMINAL_NAME',
        'type': 'char[]'
    },
    115: {
        'access': 'read-write',
        'enum': 'OutputTerminal',
        'name': 'DONE_EVENT_OUTPUT_TERMINAL',
        'type': 'char[]'
    },
    116: {
        'access': 'read-write',
        'name': 'DONE_EVENT_TERMINAL_NAME',
        'type': 'char[]'
    },
    117: {
        'access': 'read-write',
        'enum': 'SelfCalibrationValidityCheck',
        'name': 'SELF_CALIBRATION_VALIDITY_CHECK',
        'type': 'int32'
    },
    118: {
        'access': 'read-write',
        'name': 'SELF_CALIBRATION_VALIDITY_CHECK_TIME_INTERVAL',
        'type': 'float64'
    },
    119: {
        'access': 'read-write',
        'name': 'TEMPERATURE_READ_INTERVAL',
        'type': 'float64'
    },
    120: {
        'access': 'read-write',
        'name': 'THERMAL_CORRECTION_TEMPERATURE_RESOLUTION',
        'type': 'float64'
    },
    128: {
        'access': 'read-write',
        'name': 'NUMBER_OF_RAW_IQ_RECORDS',
        'type': 'int32'
    },
    163: {
        'access': 'read-write',
        'enum': 'LoadOptions',
        'name': 'LOAD_OPTIONS',
        'type': 'int32[]'
    }
}
