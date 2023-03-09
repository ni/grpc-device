attributes = {
    'Buffer': {
        6252: {
            'access': 'read-write',
            'name': 'INPUT_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        6253: {
            'access': 'read-write',
            'name': 'OUTPUT_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        8970: {
            'access': 'read',
            'name': 'INPUT_ONBRD_BUF_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        8971: {
            'access': 'read-write',
            'name': 'OUTPUT_ONBRD_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        }
    },
    'CalibrationInfo': {
        6240: {
            'access': 'read',
            'name': 'SELF_CAL_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        6241: {
            'access': 'read-write',
            'name': 'CAL_USER_DEFINED_INFO',
            'resettable': False,
            'type': 'char[]'
        },
        6244: {
            'access': 'read',
            'name': 'SELF_CAL_LAST_TEMP',
            'resettable': False,
            'type': 'float64'
        },
        6247: {
            'access': 'read',
            'name': 'EXT_CAL_LAST_TEMP',
            'resettable': False,
            'type': 'float64'
        },
        6248: {
            'access': 'read',
            'name': 'EXT_CAL_RECOMMENDED_INTERVAL',
            'resettable': False,
            'type': 'uInt32'
        },
        6428: {
            'access': 'read',
            'name': 'CAL_USER_DEFINED_INFO_MAX_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        8763: {
            'access': 'read',
            'name': 'CAL_DEV_TEMP',
            'resettable': False,
            'type': 'float64'
        },
        12267: {
            'access': 'read-write',
            'name': 'CAL_ACC_CONNECTION_COUNT',
            'resettable': False,
            'type': 'uInt32'
        },
        12268: {
            'access': 'read',
            'name': 'CAL_RECOMMENDED_ACC_CONNECTION_COUNT_LIMIT',
            'resettable': False,
            'type': 'uInt32'
        }
    },
    'Channel': {
        80: {
            'access': 'read',
            'enum': 'DataJustification1',
            'name': 'AI_RAW_SAMP_JUSTIFICATION',
            'resettable': False,
            'type': 'int32'
        },
        98: {
            'access': 'read-write',
            'name': 'AI_IMPEDANCE',
            'resettable': True,
            'type': 'float64'
        },
        100: {
            'access': 'read-write',
            'enum': 'Coupling1',
            'name': 'AI_COUPLING',
            'resettable': True,
            'type': 'int32'
        },
        104: {
            'access': 'read-write',
            'name': 'AI_DITHER_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        135: {
            'access': 'read-write',
            'enum': 'BridgeConfiguration1',
            'name': 'AI_BRIDGE_CFG',
            'resettable': True,
            'type': 'int32'
        },
        148: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_SHUNT_CAL_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        257: {
            'access': 'read-write',
            'name': 'AI_AC_EXCIT_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        258: {
            'access': 'read-write',
            'name': 'AI_AC_EXCIT_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        280: {
            'access': 'read-write',
            'name': 'AO_GAIN',
            'resettable': True,
            'type': 'float64'
        },
        289: {
            'access': 'read-write',
            'name': 'AO_LOAD_IMPEDANCE',
            'resettable': True,
            'type': 'float64'
        },
        304: {
            'access': 'read-write',
            'name': 'AO_DAC_REF_CONN_TO_GND',
            'resettable': True,
            'type': 'bool32'
        },
        306: {
            'access': 'read-write',
            'enum': 'SourceSelection',
            'name': 'AO_DAC_REF_SRC',
            'resettable': True,
            'type': 'int32'
        },
        307: {
            'access': 'read-write',
            'name': 'AO_REGLITCH_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        308: {
            'access': 'read-write',
            'enum': 'DataTransferMechanism',
            'name': 'AO_DATA_XFER_MECH',
            'resettable': True,
            'type': 'int32'
        },
        322: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_CTR_TIMEBASE_ACTIVE_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        323: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        324: {
            'access': 'read-write',
            'enum': 'CounterFrequencyMethod',
            'name': 'CI_FREQ_MEAS_METH',
            'resettable': True,
            'type': 'int32'
        },
        325: {
            'access': 'read-write',
            'name': 'CI_FREQ_MEAS_TIME',
            'resettable': True,
            'type': 'float64'
        },
        327: {
            'access': 'read-write',
            'name': 'CI_FREQ_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        328: {
            'access': 'read',
            'name': 'CI_COUNT',
            'resettable': False,
            'type': 'uInt32'
        },
        329: {
            'access': 'read',
            'enum': 'Level1',
            'name': 'CI_OUTPUT_STATE',
            'resettable': False,
            'type': 'int32'
        },
        336: {
            'access': 'read',
            'name': 'CI_TC_REACHED',
            'resettable': False,
            'type': 'bool32'
        },
        512: {
            'access': 'read-write',
            'enum': 'DataTransferMechanism',
            'name': 'CI_DATA_XFER_MECH',
            'resettable': True,
            'type': 'int32'
        },
        659: {
            'access': 'read',
            'name': 'CO_COUNT',
            'resettable': False,
            'type': 'uInt32'
        },
        660: {
            'access': 'read',
            'enum': 'Level1',
            'name': 'CO_OUTPUT_STATE',
            'resettable': False,
            'type': 'int32'
        },
        661: {
            'access': 'read-write',
            'name': 'CO_AUTO_INCR_CNT',
            'resettable': True,
            'type': 'uInt32'
        },
        664: {
            'access': 'read-write',
            'name': 'CO_PULSE_TICKS_INITIAL_DELAY',
            'resettable': True,
            'type': 'uInt32'
        },
        665: {
            'access': 'read-write',
            'name': 'CO_PULSE_FREQ_INITIAL_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        825: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        833: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CO_CTR_TIMEBASE_ACTIVE_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        1651: {
            'access': 'read-write',
            'enum': 'AccelUnits2',
            'name': 'AI_ACCEL_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        1682: {
            'access': 'read-write',
            'name': 'AI_ACCEL_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        1685: {
            'access': 'read',
            'enum': 'AIMeasurementType',
            'name': 'AI_MEAS_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        1686: {
            'access': 'read-write',
            'enum': 'CountDirection1',
            'name': 'CI_COUNT_EDGES_DIR',
            'resettable': True,
            'type': 'int32'
        },
        1687: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_COUNT_EDGES_ACTIVE_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        1688: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_INITIAL_CNT',
            'resettable': True,
            'type': 'uInt32'
        },
        1793: {
            'access': 'read-write',
            'enum': 'CurrentUnits1',
            'name': 'AI_CURRENT_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        1939: {
            'access': 'read-write',
            'name': 'DI_INVERT_LINES',
            'resettable': True,
            'type': 'bool32'
        },
        1945: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_FREQ_STARTING_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        2054: {
            'access': 'read-write',
            'enum': 'FrequencyUnits',
            'name': 'AI_FREQ_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        2068: {
            'access': 'read-write',
            'name': 'AI_FREQ_HYST',
            'resettable': True,
            'type': 'float64'
        },
        2069: {
            'access': 'read-write',
            'name': 'AI_FREQ_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        2083: {
            'access': 'read-write',
            'enum': 'TimeUnits3',
            'name': 'CI_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        2085: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_PULSE_WIDTH_STARTING_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        2099: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_TWO_EDGE_SEP_FIRST_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        2100: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_TWO_EDGE_SEP_SECOND_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        2130: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_PERIOD_STARTING_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        2165: {
            'access': 'read-write',
            'name': 'CI_ANG_ENCODER_PULSES_PER_REV',
            'resettable': True,
            'type': 'uInt32'
        },
        2167: {
            'access': 'read-write',
            'enum': 'AngleUnits1',
            'name': 'AI_RVDT_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        2177: {
            'access': 'read-write',
            'name': 'CI_ANG_ENCODER_INITIAL_ANGLE',
            'resettable': True,
            'type': 'float64'
        },
        2184: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INDEX_VAL',
            'resettable': True,
            'type': 'float64'
        },
        2185: {
            'access': 'read-write',
            'enum': 'EncoderZIndexPhase1',
            'name': 'CI_ENCODER_Z_INDEX_PHASE',
            'resettable': True,
            'type': 'int32'
        },
        2192: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INDEX_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        2307: {
            'access': 'read-write',
            'name': 'AI_RVDT_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        2320: {
            'access': 'read-write',
            'enum': 'LengthUnits2',
            'name': 'AI_LVDT_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        2321: {
            'access': 'read-write',
            'name': 'CI_LIN_ENCODER_DIST_PER_PULSE',
            'resettable': True,
            'type': 'float64'
        },
        2325: {
            'access': 'read-write',
            'name': 'CI_LIN_ENCODER_INITIAL_POS',
            'resettable': True,
            'type': 'float64'
        },
        2361: {
            'access': 'read-write',
            'name': 'AI_LVDT_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        2389: {
            'access': 'read-write',
            'enum': 'ResistanceUnits1',
            'name': 'AI_RESISTANCE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        2433: {
            'access': 'read-write',
            'enum': 'StrainUnits1',
            'name': 'AI_STRAIN_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        2434: {
            'access': 'read-write',
            'enum': 'StrainGageBridgeType1',
            'name': 'AI_STRAIN_GAGE_CFG',
            'resettable': True,
            'type': 'int32'
        },
        2452: {
            'access': 'read-write',
            'name': 'AI_STRAIN_GAGE_GAGE_FACTOR',
            'resettable': True,
            'type': 'float64'
        },
        2456: {
            'access': 'read-write',
            'name': 'AI_STRAIN_GAGE_POISSON_RATIO',
            'resettable': True,
            'type': 'float64'
        },
        4112: {
            'access': 'read-write',
            'name': 'AI_RTD_A',
            'resettable': True,
            'type': 'float64'
        },
        4113: {
            'access': 'read-write',
            'name': 'AI_RTD_B',
            'resettable': True,
            'type': 'float64'
        },
        4115: {
            'access': 'read-write',
            'name': 'AI_RTD_C',
            'resettable': True,
            'type': 'float64'
        },
        4144: {
            'access': 'read-write',
            'name': 'AI_RTD_R0',
            'resettable': True,
            'type': 'float64'
        },
        4146: {
            'access': 'read-write',
            'enum': 'RTDType1',
            'name': 'AI_RTD_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        4147: {
            'access': 'read-write',
            'enum': 'TemperatureUnits1',
            'name': 'AI_TEMP_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        4148: {
            'access': 'read',
            'name': 'AI_THRMCPL_CJC_CHAN',
            'resettable': False,
            'type': 'char[]'
        },
        4149: {
            'access': 'read',
            'enum': 'CJCSource1',
            'name': 'AI_THRMCPL_CJC_SRC',
            'resettable': False,
            'type': 'int32'
        },
        4150: {
            'access': 'read-write',
            'name': 'AI_THRMCPL_CJC_VAL',
            'resettable': True,
            'type': 'float64'
        },
        4176: {
            'access': 'read-write',
            'enum': 'ThermocoupleType1',
            'name': 'AI_THRMCPL_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        4193: {
            'access': 'read-write',
            'name': 'AI_THRMSTR_R1',
            'resettable': True,
            'type': 'float64'
        },
        4242: {
            'access': 'read-write',
            'enum': 'GpsSignalType1',
            'name': 'CI_GPS_SYNC_METHOD',
            'resettable': True,
            'type': 'int32'
        },
        4243: {
            'access': 'read-write',
            'name': 'CI_GPS_SYNC_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4244: {
            'access': 'read-write',
            'enum': 'VoltageUnits1',
            'name': 'AI_VOLTAGE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        4247: {
            'access': 'read-write',
            'enum': 'InputTermCfg',
            'name': 'AI_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        4360: {
            'access': 'read',
            'enum': 'AOOutputChannelType',
            'name': 'AO_OUTPUT_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        4361: {
            'access': 'read-write',
            'enum': 'CurrentUnits1',
            'name': 'AO_CURRENT_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        4403: {
            'access': 'read-write',
            'name': 'DO_INVERT_LINES',
            'resettable': True,
            'type': 'bool32'
        },
        4407: {
            'access': 'read-write',
            'enum': 'DigitalDriveType',
            'name': 'DO_OUTPUT_DRIVE_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        4457: {
            'access': 'read-write',
            'name': 'CO_PULSE_HIGH_TICKS',
            'resettable': True,
            'type': 'uInt32'
        },
        4464: {
            'access': 'read-write',
            'enum': 'Level1',
            'name': 'CO_PULSE_IDLE_STATE',
            'resettable': True,
            'type': 'int32'
        },
        4465: {
            'access': 'read-write',
            'name': 'CO_PULSE_LOW_TICKS',
            'resettable': True,
            'type': 'uInt32'
        },
        4470: {
            'access': 'read-write',
            'name': 'CO_PULSE_DUTY_CYC',
            'resettable': True,
            'type': 'float64'
        },
        4472: {
            'access': 'read-write',
            'name': 'CO_PULSE_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        4484: {
            'access': 'read-write',
            'enum': 'VoltageUnits2',
            'name': 'AO_VOLTAGE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        4486: {
            'access': 'read-write',
            'name': 'AO_MAX',
            'resettable': True,
            'type': 'float64'
        },
        4487: {
            'access': 'read-write',
            'name': 'AO_MIN',
            'resettable': True,
            'type': 'float64'
        },
        4488: {
            'access': 'read-write',
            'name': 'AO_CUSTOM_SCALE_NAME',
            'resettable': True,
            'type': 'char[]'
        },
        5264: {
            'access': 'read-write',
            'name': 'AO_OUTPUT_IMPEDANCE',
            'resettable': True,
            'type': 'float64'
        },
        5416: {
            'access': 'read-write',
            'enum': 'SoundPressureUnits1',
            'name': 'AI_SOUND_PRESSURE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5430: {
            'access': 'read-write',
            'name': 'AI_MICROPHONE_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        5984: {
            'access': 'read-write',
            'enum': 'AutoZeroType1',
            'name': 'AI_AUTO_ZERO_MODE',
            'resettable': True,
            'type': 'int32'
        },
        5988: {
            'access': 'read',
            'enum': 'ResolutionType1',
            'name': 'AI_RESOLUTION_UNITS',
            'resettable': False,
            'type': 'int32'
        },
        5989: {
            'access': 'read',
            'name': 'AI_RESOLUTION',
            'resettable': False,
            'type': 'float64'
        },
        6109: {
            'access': 'read-write',
            'name': 'AI_MAX',
            'resettable': True,
            'type': 'float64'
        },
        6110: {
            'access': 'read-write',
            'name': 'AI_MIN',
            'resettable': True,
            'type': 'float64'
        },
        6112: {
            'access': 'read-write',
            'name': 'AI_CUSTOM_SCALE_NAME',
            'resettable': True,
            'type': 'char[]'
        },
        6114: {
            'access': 'read-write',
            'enum': 'VoltageUnits1',
            'name': 'AI_VOLTAGE_ACRMS_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6115: {
            'access': 'read-write',
            'enum': 'CurrentUnits1',
            'name': 'AI_CURRENT_ACRMS_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6124: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_NOM_RESISTANCE',
            'resettable': True,
            'type': 'float64'
        },
        6125: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_INITIAL_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        6126: {
            'access': 'read-write',
            'name': 'AI_LEAD_WIRE_RESISTANCE',
            'resettable': True,
            'type': 'float64'
        },
        6129: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_BALANCE_COARSE_POT',
            'resettable': True,
            'type': 'int32'
        },
        6130: {
            'access': 'read-write',
            'enum': 'CurrentShuntResistorLocation1',
            'name': 'AI_CURRENT_SHUNT_LOC',
            'resettable': True,
            'type': 'int32'
        },
        6131: {
            'access': 'read-write',
            'name': 'AI_CURRENT_SHUNT_RESISTANCE',
            'resettable': True,
            'type': 'float64'
        },
        6132: {
            'access': 'read-write',
            'enum': 'ExcitationSource',
            'name': 'AI_EXCIT_SRC',
            'resettable': True,
            'type': 'int32'
        },
        6133: {
            'access': 'read-write',
            'name': 'AI_EXCIT_VAL',
            'resettable': True,
            'type': 'float64'
        },
        6134: {
            'access': 'read-write',
            'enum': 'ExcitationVoltageOrCurrent',
            'name': 'AI_EXCIT_VOLTAGE_OR_CURRENT',
            'resettable': True,
            'type': 'int32'
        },
        6139: {
            'access': 'read-write',
            'enum': 'ExcitationDCorAC',
            'name': 'AI_EXCIT_D_COR_AC',
            'resettable': True,
            'type': 'int32'
        },
        6140: {
            'access': 'read-write',
            'name': 'AI_EXCIT_USE_FOR_SCALING',
            'resettable': True,
            'type': 'bool32'
        },
        6145: {
            'access': 'read-write',
            'name': 'AI_ATTEN',
            'resettable': True,
            'type': 'float64'
        },
        6146: {
            'access': 'read-write',
            'name': 'AI_LOWPASS_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        6147: {
            'access': 'read-write',
            'name': 'AI_LOWPASS_CUTOFF_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        6150: {
            'access': 'read-write',
            'name': 'AI_HIGHPASS_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        6151: {
            'access': 'read-write',
            'name': 'AI_HIGHPASS_CUTOFF_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        6152: {
            'access': 'read-write',
            'enum': 'FilterType1',
            'name': 'AI_HIGHPASS_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        6153: {
            'access': 'read-write',
            'name': 'AI_HIGHPASS_ORDER',
            'resettable': True,
            'type': 'uInt32'
        },
        6155: {
            'access': 'read-write',
            'name': 'AI_BANDPASS_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        6156: {
            'access': 'read-write',
            'name': 'AI_BANDPASS_CENTER_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        6157: {
            'access': 'read-write',
            'enum': 'FilterType1',
            'name': 'AI_BANDPASS_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        6158: {
            'access': 'read-write',
            'name': 'AI_BANDPASS_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        6160: {
            'access': 'read-write',
            'name': 'AI_NOTCH_CENTER_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        6161: {
            'access': 'read-write',
            'enum': 'FilterType1',
            'name': 'AI_NOTCH_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        6162: {
            'access': 'read-write',
            'name': 'AI_NOTCH_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        6165: {
            'access': 'read-write',
            'name': 'AI_RNG_HIGH',
            'resettable': True,
            'type': 'float64'
        },
        6166: {
            'access': 'read-write',
            'name': 'AI_RNG_LOW',
            'resettable': True,
            'type': 'float64'
        },
        6168: {
            'access': 'read-write',
            'name': 'AI_GAIN',
            'resettable': True,
            'type': 'float64'
        },
        6170: {
            'access': 'read-write',
            'name': 'AI_SAMP_AND_HOLD_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        6177: {
            'access': 'read-write',
            'enum': 'DataTransferMechanism',
            'name': 'AI_DATA_XFER_MECH',
            'resettable': True,
            'type': 'int32'
        },
        6187: {
            'access': 'read-write',
            'enum': 'ResolutionType1',
            'name': 'AO_RESOLUTION_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6188: {
            'access': 'read',
            'name': 'AO_RESOLUTION',
            'resettable': False,
            'type': 'float64'
        },
        6189: {
            'access': 'read-write',
            'name': 'AO_DAC_RNG_LOW',
            'resettable': True,
            'type': 'float64'
        },
        6190: {
            'access': 'read-write',
            'name': 'AO_DAC_RNG_HIGH',
            'resettable': True,
            'type': 'float64'
        },
        6192: {
            'access': 'read-write',
            'name': 'AO_DAC_REF_ALLOW_CONN_TO_GND',
            'resettable': True,
            'type': 'bool32'
        },
        6194: {
            'access': 'read-write',
            'name': 'AO_DAC_REF_VAL',
            'resettable': True,
            'type': 'float64'
        },
        6202: {
            'access': 'read-write',
            'name': 'AO_USE_ONLY_ON_BRD_MEM',
            'resettable': True,
            'type': 'bool32'
        },
        6204: {
            'access': 'read-write',
            'enum': 'OutputDataTransferCondition',
            'name': 'AO_DATA_XFER_REQ_COND',
            'resettable': True,
            'type': 'int32'
        },
        6271: {
            'access': 'read',
            'enum': 'ChannelType',
            'name': 'CHAN_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        6273: {
            'access': 'read-write',
            'enum': 'ResistanceConfiguration',
            'name': 'AI_RESISTANCE_CFG',
            'resettable': True,
            'type': 'int32'
        },
        6275: {
            'access': 'read-write',
            'name': 'AI_EXCIT_ACTUAL_VAL',
            'resettable': True,
            'type': 'float64'
        },
        6276: {
            'access': 'read-write',
            'enum': 'SourceSelection',
            'name': 'AI_LOWPASS_SWITCH_CAP_CLK_SRC',
            'resettable': True,
            'type': 'int32'
        },
        6277: {
            'access': 'read-write',
            'name': 'AI_LOWPASS_SWITCH_CAP_EXT_CLK_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        6278: {
            'access': 'read-write',
            'name': 'AI_LOWPASS_SWITCH_CAP_EXT_CLK_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        6279: {
            'access': 'read-write',
            'name': 'AI_LOWPASS_SWITCH_CAP_OUT_CLK_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        6283: {
            'access': 'read-write',
            'enum': 'InputDataTransferCondition',
            'name': 'AI_DATA_XFER_REQ_COND',
            'resettable': True,
            'type': 'int32'
        },
        6284: {
            'access': 'read-write',
            'name': 'AI_MEM_MAP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        6286: {
            'access': 'read-write',
            'enum': 'OutputTermCfg',
            'name': 'AO_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        6287: {
            'access': 'read-write',
            'name': 'AO_MEM_MAP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        6288: {
            'access': 'read-write',
            'name': 'DI_TRISTATE',
            'resettable': True,
            'type': 'bool32'
        },
        6300: {
            'access': 'read-write',
            'name': 'CI_MAX',
            'resettable': True,
            'type': 'float64'
        },
        6301: {
            'access': 'read-write',
            'name': 'CI_MIN',
            'resettable': True,
            'type': 'float64'
        },
        6302: {
            'access': 'read-write',
            'name': 'CI_CUSTOM_SCALE_NAME',
            'resettable': True,
            'type': 'char[]'
        },
        6304: {
            'access': 'read',
            'enum': 'CIMeasurementType',
            'name': 'CI_MEAS_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        6305: {
            'access': 'read-write',
            'enum': 'FrequencyUnits3',
            'name': 'CI_FREQ_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6306: {
            'access': 'read-write',
            'name': 'CI_FREQ_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6307: {
            'access': 'read-write',
            'enum': 'TimeUnits3',
            'name': 'CI_PERIOD_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6308: {
            'access': 'read-write',
            'name': 'CI_PERIOD_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6310: {
            'access': 'read-write',
            'enum': 'AngleUnits2',
            'name': 'CI_ANG_ENCODER_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6313: {
            'access': 'read-write',
            'enum': 'LengthUnits3',
            'name': 'CI_LIN_ENCODER_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6314: {
            'access': 'read-write',
            'name': 'CI_PULSE_WIDTH_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6316: {
            'access': 'read-write',
            'enum': 'TimeUnits3',
            'name': 'CI_TWO_EDGE_SEP_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6317: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_FIRST_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6318: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_SECOND_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6319: {
            'access': 'read-write',
            'enum': 'TimeUnits3',
            'name': 'CI_SEMI_PERIOD_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6320: {
            'access': 'read-write',
            'name': 'CI_SEMI_PERIOD_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6322: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        6323: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_MASTER_TIMEBASE_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        6325: {
            'access': 'read',
            'enum': 'COOutputType',
            'name': 'CO_OUTPUT_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        6330: {
            'access': 'read-write',
            'name': 'CO_PULSE_HIGH_TIME',
            'resettable': True,
            'type': 'float64'
        },
        6331: {
            'access': 'read-write',
            'name': 'CO_PULSE_LOW_TIME',
            'resettable': True,
            'type': 'float64'
        },
        6332: {
            'access': 'read-write',
            'name': 'CO_PULSE_TIME_INITIAL_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        6338: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        6339: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_MASTER_TIMEBASE_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        6343: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6345: {
            'access': 'read-write',
            'name': 'AI_THRMSTR_A',
            'resettable': True,
            'type': 'float64'
        },
        6346: {
            'access': 'read-write',
            'name': 'AI_THRMSTR_C',
            'resettable': True,
            'type': 'float64'
        },
        6347: {
            'access': 'read-write',
            'name': 'AI_THRMSTR_B',
            'resettable': True,
            'type': 'float64'
        },
        6349: {
            'access': 'read-write',
            'enum': 'ACExcitWireMode',
            'name': 'AI_AC_EXCIT_WIRE_MODE',
            'resettable': True,
            'type': 'int32'
        },
        6357: {
            'access': 'read-write',
            'enum': 'FrequencyUnits2',
            'name': 'CO_PULSE_FREQ_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6358: {
            'access': 'read-write',
            'enum': 'TimeUnits2',
            'name': 'CO_PULSE_TIME_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6369: {
            'access': 'read-write',
            'name': 'CO_PULSE_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6387: {
            'access': 'read-write',
            'name': 'DO_TRISTATE',
            'resettable': True,
            'type': 'bool32'
        },
        6388: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_BALANCE_FINE_POT',
            'resettable': True,
            'type': 'int32'
        },
        6389: {
            'access': 'read-write',
            'name': 'PHYSICAL_CHAN_NAME',
            'resettable': False,
            'type': 'char[]'
        },
        6392: {
            'access': 'read-write',
            'name': 'AI_FORCE_READ_FROM_CHAN',
            'resettable': True,
            'type': 'bool32'
        },
        6414: {
            'access': 'read',
            'name': 'CO_PULSE_DONE',
            'resettable': False,
            'type': 'bool32'
        },
        6438: {
            'access': 'read-write',
            'name': 'CHAN_DESCR',
            'resettable': True,
            'type': 'char[]'
        },
        6444: {
            'access': 'read-write',
            'enum': 'CounterFrequencyMethod',
            'name': 'CI_PERIOD_MEAS_METH',
            'resettable': True,
            'type': 'int32'
        },
        6445: {
            'access': 'read-write',
            'name': 'CI_PERIOD_MEAS_TIME',
            'resettable': True,
            'type': 'float64'
        },
        6446: {
            'access': 'read-write',
            'name': 'CI_PERIOD_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        6448: {
            'access': 'read',
            'name': 'AI_DEV_SCALING_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        6449: {
            'access': 'read',
            'name': 'AO_DEV_SCALING_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        6460: {
            'access': 'read',
            'name': 'CI_NUM_POSSIBLY_INVALID_SAMPS',
            'resettable': False,
            'type': 'uInt32'
        },
        6463: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_SHUNT_CAL_GAIN_ADJUST',
            'resettable': True,
            'type': 'float64'
        },
        8568: {
            'access': 'read',
            'name': 'DI_NUM_LINES',
            'resettable': False,
            'type': 'uInt32'
        },
        8569: {
            'access': 'read',
            'name': 'DO_NUM_LINES',
            'resettable': False,
            'type': 'uInt32'
        },
        8576: {
            'access': 'read-write',
            'name': 'AI_EXCIT_USE_MULTIPLEXED',
            'resettable': True,
            'type': 'bool32'
        },
        8600: {
            'access': 'read-write',
            'name': 'AI_INPUT_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8602: {
            'access': 'read-write',
            'enum': 'LVDTSensitivityUnits1',
            'name': 'AI_LVDT_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        8603: {
            'access': 'read-write',
            'enum': 'RVDTSensitivityUnits1',
            'name': 'AI_RVDT_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        8604: {
            'access': 'read-write',
            'enum': 'AccelSensitivityUnits1',
            'name': 'AI_ACCEL_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        8605: {
            'access': 'read-write',
            'name': 'CI_ENCODER_A_INPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8606: {
            'access': 'read-write',
            'name': 'CI_ENCODER_B_INPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8607: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8620: {
            'access': 'read-write',
            'name': 'CI_DUP_COUNT_PREVENT',
            'resettable': True,
            'type': 'bool32'
        },
        8661: {
            'access': 'read-write',
            'enum': 'ShuntCalSelect',
            'name': 'AI_BRIDGE_SHUNT_CAL_SELECT',
            'resettable': True,
            'type': 'int32'
        },
        8662: {
            'access': 'read-write',
            'name': 'DI_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8663: {
            'access': 'read-write',
            'name': 'DI_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8672: {
            'access': 'read',
            'name': 'AI_TEDS_UNITS',
            'resettable': False,
            'type': 'char[]'
        },
        8673: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_DIR_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8678: {
            'access': 'read-write',
            'enum': 'EncoderType2',
            'name': 'CI_ENCODER_DECODING_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        8679: {
            'access': 'read-write',
            'name': 'CI_FREQ_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8680: {
            'access': 'read-write',
            'name': 'CI_FREQ_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8681: {
            'access': 'read-write',
            'name': 'CI_FREQ_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8682: {
            'access': 'read-write',
            'name': 'CI_FREQ_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8683: {
            'access': 'read-write',
            'name': 'CI_FREQ_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8684: {
            'access': 'read-write',
            'name': 'CI_PERIOD_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8685: {
            'access': 'read-write',
            'name': 'CI_PERIOD_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8686: {
            'access': 'read-write',
            'name': 'CI_PERIOD_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8687: {
            'access': 'read-write',
            'name': 'CI_PERIOD_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8688: {
            'access': 'read-write',
            'name': 'CI_PERIOD_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8689: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8690: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8691: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8692: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8693: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8694: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8695: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8696: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8697: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8698: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8699: {
            'access': 'read-write',
            'name': 'CI_ENCODER_A_INPUT_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8700: {
            'access': 'read-write',
            'name': 'CI_ENCODER_A_INPUT_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8701: {
            'access': 'read-write',
            'name': 'CI_ENCODER_A_INPUT_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8702: {
            'access': 'read-write',
            'name': 'CI_ENCODER_A_INPUT_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8703: {
            'access': 'read-write',
            'name': 'CI_ENCODER_A_INPUT_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8704: {
            'access': 'read-write',
            'name': 'CI_ENCODER_B_INPUT_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8705: {
            'access': 'read-write',
            'name': 'CI_ENCODER_B_INPUT_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8706: {
            'access': 'read-write',
            'name': 'CI_ENCODER_B_INPUT_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8707: {
            'access': 'read-write',
            'name': 'CI_ENCODER_B_INPUT_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8708: {
            'access': 'read-write',
            'name': 'CI_ENCODER_B_INPUT_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8709: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INPUT_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8710: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INPUT_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8711: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INPUT_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8712: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INPUT_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8713: {
            'access': 'read-write',
            'name': 'CI_ENCODER_Z_INPUT_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8714: {
            'access': 'read-write',
            'name': 'CI_PULSE_WIDTH_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8715: {
            'access': 'read-write',
            'name': 'CI_PULSE_WIDTH_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8716: {
            'access': 'read-write',
            'name': 'CI_PULSE_WIDTH_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8717: {
            'access': 'read-write',
            'name': 'CI_PULSE_WIDTH_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8718: {
            'access': 'read-write',
            'name': 'CI_PULSE_WIDTH_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8719: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_FIRST_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8720: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_FIRST_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8721: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_FIRST_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8722: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_FIRST_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8723: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_FIRST_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8724: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_SECOND_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8725: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_SECOND_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8726: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_SECOND_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8727: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_SECOND_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8728: {
            'access': 'read-write',
            'name': 'CI_TWO_EDGE_SEP_SECOND_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8729: {
            'access': 'read-write',
            'name': 'CI_SEMI_PERIOD_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8730: {
            'access': 'read-write',
            'name': 'CI_SEMI_PERIOD_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8731: {
            'access': 'read-write',
            'name': 'CI_SEMI_PERIOD_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8732: {
            'access': 'read-write',
            'name': 'CI_SEMI_PERIOD_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8733: {
            'access': 'read-write',
            'name': 'CI_SEMI_PERIOD_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8761: {
            'access': 'read-write',
            'name': 'CI_PRESCALER',
            'resettable': True,
            'type': 'uInt32'
        },
        8762: {
            'access': 'read-write',
            'name': 'AI_SOUND_PRESSURE_MAX_SOUND_PRESSURE_LVL',
            'resettable': True,
            'type': 'float64'
        },
        8768: {
            'access': 'read-write',
            'enum': 'AOIdleOutputBehavior',
            'name': 'AO_IDLE_OUTPUT_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        8769: {
            'access': 'read-write',
            'name': 'AO_ENHANCED_IMAGE_REJECTION_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8786: {
            'access': 'read-write',
            'name': 'AO_DAC_REF_EXT_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8787: {
            'access': 'read-write',
            'enum': 'SourceSelection',
            'name': 'AO_DAC_OFFSET_SRC',
            'resettable': True,
            'type': 'int32'
        },
        8788: {
            'access': 'read-write',
            'name': 'AO_DAC_OFFSET_EXT_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8789: {
            'access': 'read-write',
            'name': 'AO_DAC_OFFSET_VAL',
            'resettable': True,
            'type': 'float64'
        },
        8803: {
            'access': 'read-write',
            'enum': 'DataTransferMechanism',
            'name': 'DI_DATA_XFER_MECH',
            'resettable': True,
            'type': 'int32'
        },
        8804: {
            'access': 'read-write',
            'enum': 'InputDataTransferCondition',
            'name': 'DI_DATA_XFER_REQ_COND',
            'resettable': True,
            'type': 'int32'
        },
        8805: {
            'access': 'read-write',
            'name': 'DO_USE_ONLY_ON_BRD_MEM',
            'resettable': True,
            'type': 'bool32'
        },
        8806: {
            'access': 'read-write',
            'enum': 'DataTransferMechanism',
            'name': 'DO_DATA_XFER_MECH',
            'resettable': True,
            'type': 'int32'
        },
        8807: {
            'access': 'read-write',
            'enum': 'OutputDataTransferCondition',
            'name': 'DO_DATA_XFER_REQ_COND',
            'resettable': True,
            'type': 'int32'
        },
        8813: {
            'access': 'read-write',
            'name': 'CO_PRESCALER',
            'resettable': True,
            'type': 'uInt32'
        },
        8817: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8818: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8819: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8820: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8821: {
            'access': 'read-write',
            'name': 'CI_CTR_TIMEBASE_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8822: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8823: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8824: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8825: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8826: {
            'access': 'read-write',
            'name': 'CO_CTR_TIMEBASE_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8852: {
            'access': 'read-write',
            'name': 'AI_ENHANCED_ALIAS_REJECTION_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8855: {
            'access': 'read',
            'name': 'AI_CHAN_CAL_HAS_VALID_CAL_INFO',
            'resettable': False,
            'type': 'bool32'
        },
        8856: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_ENABLE_CAL',
            'resettable': True,
            'type': 'bool32'
        },
        8857: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_APPLY_CAL_IF_EXP',
            'resettable': True,
            'type': 'bool32'
        },
        8860: {
            'access': 'read-write',
            'enum': 'ScaleType3',
            'name': 'AI_CHAN_CAL_SCALE_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        8861: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_TABLE_PRE_SCALED_VALS',
            'resettable': True,
            'type': 'float64[]'
        },
        8862: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_TABLE_SCALED_VALS',
            'resettable': True,
            'type': 'float64[]'
        },
        8863: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_POLY_FORWARD_COEFF',
            'resettable': True,
            'type': 'float64[]'
        },
        8864: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_POLY_REVERSE_COEFF',
            'resettable': True,
            'type': 'float64[]'
        },
        8865: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_VERIF_REF_VALS',
            'resettable': True,
            'type': 'float64[]'
        },
        8866: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_VERIF_ACQ_VALS',
            'resettable': True,
            'type': 'float64[]'
        },
        8867: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_OPERATOR_NAME',
            'resettable': True,
            'type': 'char[]'
        },
        8868: {
            'access': 'read-write',
            'name': 'AI_CHAN_CAL_DESC',
            'resettable': True,
            'type': 'char[]'
        },
        8883: {
            'access': 'read-write',
            'enum': 'TimeUnits',
            'name': 'CI_TIMESTAMP_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        8884: {
            'access': 'read-write',
            'name': 'CI_TIMESTAMP_INITIAL_SECONDS',
            'resettable': True,
            'type': 'uInt32'
        },
        8920: {
            'access': 'read-write',
            'enum': 'RawDataCompressionType',
            'name': 'AI_RAW_DATA_COMPRESSION_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        8921: {
            'access': 'read-write',
            'name': 'AI_LOSSY_LSB_REMOVAL_COMPRESSED_SAMP_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        8922: {
            'access': 'read',
            'name': 'AI_RAW_SAMP_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        8958: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_SEMI_PERIOD_STARTING_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        8959: {
            'access': 'read',
            'name': 'CO_RDY_FOR_NEW_VAL',
            'resettable': False,
            'type': 'bool32'
        },
        8964: {
            'access': 'read',
            'name': 'CHAN_IS_GLOBAL',
            'resettable': False,
            'type': 'bool32'
        },
        8972: {
            'access': 'read-write',
            'name': 'AI_DATA_XFER_CUSTOM_THRESHOLD',
            'resettable': True,
            'type': 'uInt32'
        },
        10598: {
            'access': 'read-write',
            'enum': 'SampleClockActiveOrInactiveEdgeSelection',
            'name': 'DI_ACQUIRE_ON',
            'resettable': True,
            'type': 'int32'
        },
        10599: {
            'access': 'read-write',
            'enum': 'DigitalLineState',
            'name': 'DO_LINE_STATES_PAUSED_STATE',
            'resettable': True,
            'type': 'int32'
        },
        10600: {
            'access': 'read-write',
            'enum': 'DigitalLineState',
            'name': 'DO_LINE_STATES_DONE_STATE',
            'resettable': True,
            'type': 'int32'
        },
        10601: {
            'access': 'read-write',
            'enum': 'SampleClockActiveOrInactiveEdgeSelection',
            'name': 'DO_GENERATE_ON',
            'resettable': True,
            'type': 'int32'
        },
        10602: {
            'access': 'read-write',
            'name': 'DI_MEM_MAP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        10603: {
            'access': 'read-write',
            'name': 'DO_MEM_MAP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        10605: {
            'access': 'read-write',
            'enum': 'LogicFamily',
            'name': 'DI_LOGIC_FAMILY',
            'resettable': True,
            'type': 'int32'
        },
        10606: {
            'access': 'read-write',
            'enum': 'LogicFamily',
            'name': 'DO_LOGIC_FAMILY',
            'resettable': True,
            'type': 'int32'
        },
        10610: {
            'access': 'read-write',
            'enum': 'DigitalLineState',
            'name': 'DO_LINE_STATES_START_STATE',
            'resettable': True,
            'type': 'int32'
        },
        10627: {
            'access': 'read',
            'name': 'AI_IS_TEDS',
            'resettable': False,
            'type': 'bool32'
        },
        10672: {
            'access': 'read-write',
            'name': 'AI_VOLTAGE_DB_REF',
            'resettable': True,
            'type': 'float64'
        },
        10673: {
            'access': 'read-write',
            'name': 'AI_SOUND_PRESSURE_DB_REF',
            'resettable': True,
            'type': 'float64'
        },
        10674: {
            'access': 'read-write',
            'name': 'AI_ACCEL_DB_REF',
            'resettable': True,
            'type': 'float64'
        },
        10704: {
            'access': 'read-write',
            'enum': 'ScaleType2',
            'name': 'AI_THRMCPL_SCALE_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        10738: {
            'access': 'read-write',
            'enum': 'ConstrainedGenMode',
            'name': 'CO_CONSTRAINED_GEN_MODE',
            'resettable': True,
            'type': 'int32'
        },
        10745: {
            'access': 'read-write',
            'enum': 'ADCTimingMode',
            'name': 'AI_ADC_TIMING_MODE',
            'resettable': True,
            'type': 'int32'
        },
        10776: {
            'access': 'read-write',
            'enum': 'FuncGenType',
            'name': 'AO_FUNC_GEN_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        10777: {
            'access': 'read-write',
            'name': 'AO_FUNC_GEN_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        10778: {
            'access': 'read-write',
            'name': 'AO_FUNC_GEN_AMPLITUDE',
            'resettable': True,
            'type': 'float64'
        },
        10779: {
            'access': 'read-write',
            'name': 'AO_FUNC_GEN_OFFSET',
            'resettable': True,
            'type': 'float64'
        },
        10780: {
            'access': 'read-write',
            'name': 'AO_FUNC_GEN_SQUARE_DUTY_CYCLE',
            'resettable': True,
            'type': 'float64'
        },
        10781: {
            'access': 'read-write',
            'name': 'AO_VOLTAGE_CURRENT_LIMIT',
            'resettable': True,
            'type': 'float64'
        },
        10786: {
            'access': 'read-write',
            'enum': 'ModulationType',
            'name': 'AO_FUNC_GEN_MODULATION_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        10787: {
            'access': 'read-write',
            'name': 'AO_FUNC_GEN_FM_DEVIATION',
            'resettable': True,
            'type': 'float64'
        },
        10885: {
            'access': 'read-write',
            'name': 'DO_OVERCURRENT_LIMIT',
            'resettable': True,
            'type': 'float64'
        },
        10886: {
            'access': 'read-write',
            'name': 'DO_OVERCURRENT_AUTO_REENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        10887: {
            'access': 'read-write',
            'name': 'DO_OVERCURRENT_REENABLE_PERIOD',
            'resettable': True,
            'type': 'float64'
        },
        10888: {
            'access': 'read-write',
            'name': 'AI_PROBE_ATTEN',
            'resettable': True,
            'type': 'float64'
        },
        10889: {
            'access': 'read-write',
            'name': 'AI_DC_OFFSET',
            'resettable': True,
            'type': 'float64'
        },
        10894: {
            'access': 'read-write',
            'name': 'AI_USB_XFER_REQ_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        10895: {
            'access': 'read-write',
            'name': 'AO_USB_XFER_REQ_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        10896: {
            'access': 'read-write',
            'name': 'DI_USB_XFER_REQ_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        10897: {
            'access': 'read-write',
            'name': 'DO_USB_XFER_REQ_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        10898: {
            'access': 'read-write',
            'name': 'CI_USB_XFER_REQ_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        10899: {
            'access': 'read-write',
            'name': 'CO_USB_XFER_REQ_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        10942: {
            'access': 'read-write',
            'name': 'AI_EDDY_CURRENT_PROX_PROBE_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        10943: {
            'access': 'read-write',
            'enum': 'EddyCurrentProxProbeSensitivityUnits',
            'name': 'AI_EDDY_CURRENT_PROX_PROBE_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        10944: {
            'access': 'read-write',
            'enum': 'LengthUnits2',
            'name': 'AI_EDDY_CURRENT_PROX_PROBE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        11977: {
            'access': 'read-write',
            'name': 'CO_ENABLE_INITIAL_DELAY_ON_RETRIGGER',
            'resettable': True,
            'type': 'bool32'
        },
        11979: {
            'access': 'read-write',
            'name': 'CO_USE_ONLY_ON_BRD_MEM',
            'resettable': True,
            'type': 'bool32'
        },
        11980: {
            'access': 'read-write',
            'enum': 'DataTransferMechanism',
            'name': 'CO_DATA_XFER_MECH',
            'resettable': True,
            'type': 'int32'
        },
        11981: {
            'access': 'read-write',
            'enum': 'OutputDataTransferCondition',
            'name': 'CO_DATA_XFER_REQ_COND',
            'resettable': True,
            'type': 'int32'
        },
        11984: {
            'access': 'read-write',
            'name': 'CI_FREQ_ENABLE_AVERAGING',
            'resettable': True,
            'type': 'bool32'
        },
        11985: {
            'access': 'read-write',
            'name': 'CI_PERIOD_ENABLE_AVERAGING',
            'resettable': True,
            'type': 'bool32'
        },
        11986: {
            'access': 'read-write',
            'name': 'CI_MEM_MAP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        11987: {
            'access': 'read-write',
            'name': 'CO_MEM_MAP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        11988: {
            'access': 'read-write',
            'name': 'DI_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        11989: {
            'access': 'read-write',
            'name': 'DI_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        11990: {
            'access': 'read-write',
            'name': 'DI_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12027: {
            'access': 'read-write',
            'enum': 'InputDataTransferCondition',
            'name': 'CI_DATA_XFER_REQ_COND',
            'resettable': True,
            'type': 'int32'
        },
        12030: {
            'access': 'read-write',
            'name': 'DI_DIG_FLTR_ENABLE_BUS_MODE',
            'resettable': True,
            'type': 'bool32'
        },
        12036: {
            'access': 'read-write',
            'name': 'CI_PULSE_FREQ_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12037: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_PULSE_FREQ_START_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        12038: {
            'access': 'read-write',
            'name': 'CI_PULSE_FREQ_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12039: {
            'access': 'read-write',
            'name': 'CI_PULSE_FREQ_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12040: {
            'access': 'read-write',
            'name': 'CI_PULSE_FREQ_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12041: {
            'access': 'read-write',
            'name': 'CI_PULSE_FREQ_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12042: {
            'access': 'read-write',
            'name': 'CI_PULSE_FREQ_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12043: {
            'access': 'read-write',
            'enum': 'FrequencyUnits2',
            'name': 'CI_PULSE_FREQ_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12044: {
            'access': 'read-write',
            'name': 'CI_PULSE_TIME_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12045: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_PULSE_TIME_START_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        12046: {
            'access': 'read-write',
            'name': 'CI_PULSE_TIME_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12047: {
            'access': 'read-write',
            'name': 'CI_PULSE_TIME_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12048: {
            'access': 'read-write',
            'name': 'CI_PULSE_TIME_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12049: {
            'access': 'read-write',
            'name': 'CI_PULSE_TIME_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12050: {
            'access': 'read-write',
            'name': 'CI_PULSE_TIME_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12051: {
            'access': 'read-write',
            'enum': 'TimeUnits2',
            'name': 'CI_PULSE_TIME_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12052: {
            'access': 'read-write',
            'name': 'CI_PULSE_TICKS_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12053: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_PULSE_TICKS_START_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        12054: {
            'access': 'read-write',
            'name': 'CI_PULSE_TICKS_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12055: {
            'access': 'read-write',
            'name': 'CI_PULSE_TICKS_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12056: {
            'access': 'read-write',
            'name': 'CI_PULSE_TICKS_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12057: {
            'access': 'read-write',
            'name': 'CI_PULSE_TICKS_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12058: {
            'access': 'read-write',
            'name': 'CI_PULSE_TICKS_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12139: {
            'access': 'read-write',
            'name': 'AI_ADC_CUSTOM_TIMING_MODE',
            'resettable': True,
            'type': 'uInt32'
        },
        12146: {
            'access': 'read-write',
            'name': 'AI_OPEN_THRMCPL_DETECT_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12149: {
            'access': 'read-write',
            'enum': 'ForceUnits',
            'name': 'AI_FORCE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12150: {
            'access': 'read-write',
            'enum': 'PressureUnits',
            'name': 'AI_PRESSURE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12151: {
            'access': 'read-write',
            'enum': 'TorqueUnits',
            'name': 'AI_TORQUE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12152: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_SHUNT_CAL_SHUNT_CAL_A_RESISTANCE',
            'resettable': True,
            'type': 'float64'
        },
        12153: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_SHUNT_CAL_SHUNT_CAL_A_ACTUAL_RESISTANCE',
            'resettable': True,
            'type': 'float64'
        },
        12154: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_SHUNT_CAL_SHUNT_CAL_B_RESISTANCE',
            'resettable': True,
            'type': 'float64'
        },
        12155: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_SHUNT_CAL_SHUNT_CAL_B_ACTUAL_RESISTANCE',
            'resettable': True,
            'type': 'float64'
        },
        12161: {
            'access': 'read-write',
            'name': 'AI_FORCE_IEPE_SENSOR_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        12162: {
            'access': 'read-write',
            'enum': 'ForceIEPESensorSensitivityUnits',
            'name': 'AI_FORCE_IEPE_SENSOR_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12166: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_INITIAL_RATIO',
            'resettable': True,
            'type': 'float64'
        },
        12167: {
            'access': 'read-write',
            'enum': 'BridgeElectricalUnits',
            'name': 'AI_BRIDGE_ELECTRICAL_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12168: {
            'access': 'read-write',
            'enum': 'BridgePhysicalUnits',
            'name': 'AI_BRIDGE_PHYSICAL_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12169: {
            'access': 'read-write',
            'enum': 'ScaleType4',
            'name': 'AI_BRIDGE_SCALE_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12170: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_TWO_POINT_LIN_FIRST_ELECTRICAL_VAL',
            'resettable': True,
            'type': 'float64'
        },
        12171: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_TWO_POINT_LIN_FIRST_PHYSICAL_VAL',
            'resettable': True,
            'type': 'float64'
        },
        12172: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_TWO_POINT_LIN_SECOND_ELECTRICAL_VAL',
            'resettable': True,
            'type': 'float64'
        },
        12173: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_TWO_POINT_LIN_SECOND_PHYSICAL_VAL',
            'resettable': True,
            'type': 'float64'
        },
        12174: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_TABLE_ELECTRICAL_VALS',
            'resettable': True,
            'type': 'float64[]'
        },
        12175: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_TABLE_PHYSICAL_VALS',
            'resettable': True,
            'type': 'float64[]'
        },
        12176: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_POLY_FORWARD_COEFF',
            'resettable': True,
            'type': 'float64[]'
        },
        12177: {
            'access': 'read-write',
            'name': 'AI_BRIDGE_POLY_REVERSE_COEFF',
            'resettable': True,
            'type': 'float64[]'
        },
        12178: {
            'access': 'read-write',
            'enum': 'BridgeUnits',
            'name': 'AI_BRIDGE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12207: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12208: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_RESET_COUNT',
            'resettable': True,
            'type': 'uInt32'
        },
        12209: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12210: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_ACTIVE_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        12211: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12212: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12213: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12214: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12215: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12216: {
            'access': 'read-write',
            'name': 'AI_THRMCPL_LEAD_OFFSET_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12221: {
            'access': 'read-write',
            'name': 'AI_REMOVE_FILTER_DELAY',
            'resettable': True,
            'type': 'bool32'
        },
        12269: {
            'access': 'read',
            'name': 'AI_FILTER_DELAY',
            'resettable': False,
            'type': 'float64'
        },
        12270: {
            'access': 'read-write',
            'name': 'AI_AVERAGING_WIN_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        12276: {
            'access': 'read-write',
            'enum': 'VelocityUnits',
            'name': 'AI_VELOCITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12277: {
            'access': 'read-write',
            'name': 'AI_VELOCITY_IEPE_SENSOR_DB_REF',
            'resettable': True,
            'type': 'float64'
        },
        12278: {
            'access': 'read-write',
            'name': 'AI_VELOCITY_IEPE_SENSOR_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        12279: {
            'access': 'read-write',
            'enum': 'VelocityIEPESensorSensitivityUnits',
            'name': 'AI_VELOCITY_IEPE_SENSOR_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12282: {
            'access': 'read-write',
            'name': 'AI_STRAIN_GAGE_FORCE_READ_FROM_CHAN',
            'resettable': True,
            'type': 'bool32'
        },
        12283: {
            'access': 'read',
            'name': 'AI_ROSETTE_STRAIN_GAGE_STRAIN_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12284: {
            'access': 'read-write',
            'name': 'AI_ROSETTE_STRAIN_GAGE_ORIENTATION',
            'resettable': True,
            'type': 'float64'
        },
        12285: {
            'access': 'read-write',
            'enum': 'StrainGageRosetteMeasurementType',
            'name': 'AI_ROSETTE_STRAIN_GAGE_ROSETTE_MEAS_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12286: {
            'access': 'read',
            'enum': 'StrainGageRosetteType',
            'name': 'AI_ROSETTE_STRAIN_GAGE_ROSETTE_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        12288: {
            'access': 'read-write',
            'name': 'AI_USB_XFER_REQ_COUNT',
            'resettable': True,
            'type': 'uInt32'
        },
        12289: {
            'access': 'read-write',
            'name': 'AO_USB_XFER_REQ_COUNT',
            'resettable': True,
            'type': 'uInt32'
        },
        12290: {
            'access': 'read-write',
            'name': 'DI_USB_XFER_REQ_COUNT',
            'resettable': True,
            'type': 'uInt32'
        },
        12291: {
            'access': 'read-write',
            'name': 'DO_USB_XFER_REQ_COUNT',
            'resettable': True,
            'type': 'uInt32'
        },
        12292: {
            'access': 'read-write',
            'name': 'CI_USB_XFER_REQ_COUNT',
            'resettable': True,
            'type': 'uInt32'
        },
        12293: {
            'access': 'read-write',
            'name': 'CO_USB_XFER_REQ_COUNT',
            'resettable': True,
            'type': 'uInt32'
        },
        12345: {
            'access': 'read-write',
            'name': 'CI_TIMESTAMP_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12346: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_TIMESTAMP_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        12347: {
            'access': 'read-write',
            'enum': 'Timescale',
            'name': 'CI_TIMESTAMP_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12348: {
            'access': 'read-write',
            'name': 'NAV_CUSTOM_SCALE_NAME',
            'resettable': True,
            'type': 'char[]'
        },
        12349: {
            'access': 'read',
            'enum': 'NavMeasurementType',
            'name': 'NAV_MEAS_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        12350: {
            'access': 'read-write',
            'enum': 'LengthUnits4',
            'name': 'NAV_ALT_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12351: {
            'access': 'read-write',
            'enum': 'AngleUnits3',
            'name': 'NAV_LAT_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12352: {
            'access': 'read-write',
            'enum': 'AngleUnits3',
            'name': 'NAV_LONG_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12353: {
            'access': 'read-write',
            'enum': 'VelocityUnits2',
            'name': 'NAV_SPEED_OVER_GROUND_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12354: {
            'access': 'read-write',
            'enum': 'AngleUnits1',
            'name': 'NAV_TRACK_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12355: {
            'access': 'read-write',
            'enum': 'VelocityUnits2',
            'name': 'NAV_VERT_VELOCITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12356: {
            'access': 'read-write',
            'enum': 'TimeUnits',
            'name': 'NAV_TIMESTAMP_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12357: {
            'access': 'read-write',
            'enum': 'Timescale',
            'name': 'NAV_TIMESTAMP_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12401: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits4',
            'name': 'AI_FILTER_DELAY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12402: {
            'access': 'read-write',
            'name': 'AO_FILTER_DELAY_ADJUSTMENT',
            'resettable': True,
            'type': 'float64'
        },
        12404: {
            'access': 'read-write',
            'name': 'AI_FILTER_DELAY_ADJUSTMENT',
            'resettable': True,
            'type': 'float64'
        },
        12405: {
            'access': 'read-write',
            'name': 'AO_FILTER_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        12406: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits4',
            'name': 'AO_FILTER_DELAY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12429: {
            'access': 'read-write',
            'name': 'CI_DUTY_CYCLE_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12430: {
            'access': 'read-write',
            'name': 'CI_DUTY_CYCLE_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12431: {
            'access': 'read-write',
            'name': 'CI_DUTY_CYCLE_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12432: {
            'access': 'read-write',
            'name': 'CI_DUTY_CYCLE_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12433: {
            'access': 'read-write',
            'name': 'CI_DUTY_CYCLE_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12434: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'CI_DUTY_CYCLE_STARTING_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        12435: {
            'access': 'read-write',
            'enum': 'SampClkOverrunBehavior',
            'name': 'CI_SAMP_CLK_OVERRUN_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12436: {
            'access': 'read-write',
            'name': 'CI_SAMP_CLK_OVERRUN_SENTINEL_VAL',
            'resettable': True,
            'type': 'int32'
        },
        12437: {
            'access': 'read-write',
            'name': 'CI_MAX_MEAS_PERIOD',
            'resettable': True,
            'type': 'float64'
        },
        12439: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_FREQ_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12440: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_FREQ_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12441: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_PERIOD_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12442: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_PERIOD_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12443: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_COUNT_EDGES_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12444: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_COUNT_EDGES_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12445: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12446: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12447: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12448: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12449: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_DUTY_CYCLE_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12450: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_DUTY_CYCLE_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12451: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_ENCODER_A_INPUT_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12452: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_ENCODER_A_INPUT_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12453: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_ENCODER_B_INPUT_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12454: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_ENCODER_B_INPUT_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12455: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_ENCODER_Z_INPUT_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12456: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_ENCODER_Z_INPUT_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12457: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_PULSE_WIDTH_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12458: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_PULSE_WIDTH_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12459: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_TWO_EDGE_SEP_FIRST_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12460: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_TWO_EDGE_SEP_FIRST_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12461: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_TWO_EDGE_SEP_SECOND_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12462: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_TWO_EDGE_SEP_SECOND_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12463: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_SEMI_PERIOD_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12464: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_SEMI_PERIOD_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12465: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_PULSE_FREQ_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12466: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_PULSE_FREQ_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12467: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_PULSE_TIME_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12468: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_PULSE_TIME_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12469: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_PULSE_TICKS_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12470: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_PULSE_TICKS_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12471: {
            'access': 'read-write',
            'name': 'CI_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12472: {
            'access': 'read-write',
            'enum': 'ExcitationIdleOutputBehavior',
            'name': 'AI_EXCIT_IDLE_OUTPUT_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12477: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12478: {
            'access': 'read-write',
            'enum': 'FilterType2',
            'name': 'AI_DIG_FLTR_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12479: {
            'access': 'read-write',
            'enum': 'FilterResponse',
            'name': 'AI_DIG_FLTR_RESPONSE',
            'resettable': True,
            'type': 'int32'
        },
        12480: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_ORDER',
            'resettable': True,
            'type': 'uInt32'
        },
        12481: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_LOWPASS_CUTOFF_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        12482: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_HIGHPASS_CUTOFF_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        12483: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_BANDPASS_CENTER_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        12484: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_BANDPASS_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12485: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_NOTCH_CENTER_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        12486: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_NOTCH_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12487: {
            'access': 'read-write',
            'name': 'AI_DIG_FLTR_COEFF',
            'resettable': True,
            'type': 'float64[]'
        },
        12490: {
            'access': 'read-write',
            'enum': 'BridgeShuntCalSource',
            'name': 'AI_BRIDGE_SHUNT_CAL_SHUNT_CAL_A_SRC',
            'resettable': True,
            'type': 'int32'
        },
        12504: {
            'access': 'read-write',
            'enum': 'AngularVelocityUnits',
            'name': 'CI_VELOCITY_ANG_ENCODER_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12505: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ANG_ENCODER_PULSES_PER_REV',
            'resettable': True,
            'type': 'uInt32'
        },
        12506: {
            'access': 'read-write',
            'enum': 'VelocityUnits',
            'name': 'CI_VELOCITY_LIN_ENCODER_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12507: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_LIN_ENCODER_DIST_PER_PULSE',
            'resettable': True,
            'type': 'float64'
        },
        12508: {
            'access': 'read-write',
            'enum': 'EncoderType2',
            'name': 'CI_VELOCITY_ENCODER_DECODING_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12509: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_A_INPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12510: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_VELOCITY_ENCODER_A_INPUT_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12511: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_VELOCITY_ENCODER_A_INPUT_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12512: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_A_INPUT_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12513: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_A_INPUT_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12514: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_A_INPUT_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12515: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_A_INPUT_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12516: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_B_INPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12517: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_VELOCITY_ENCODER_B_INPUT_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12518: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_VELOCITY_ENCODER_B_INPUT_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12519: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_B_INPUT_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12520: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_B_INPUT_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12521: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_B_INPUT_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12522: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_ENCODER_B_INPUT_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12523: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_MEAS_TIME',
            'resettable': True,
            'type': 'float64'
        },
        12524: {
            'access': 'read-write',
            'name': 'CI_VELOCITY_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        12525: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12526: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        12527: {
            'access': 'read-write',
            'enum': 'InputTermCfg2',
            'name': 'CI_COUNT_EDGES_GATE_TERM_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12528: {
            'access': 'read-write',
            'enum': 'LogicLvlBehavior',
            'name': 'CI_COUNT_EDGES_GATE_LOGIC_LVL_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12529: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12530: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12531: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12532: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12533: {
            'access': 'read-write',
            'enum': 'Level1',
            'name': 'CI_COUNT_EDGES_GATE_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        12535: {
            'access': 'read-write',
            'enum': 'BridgeShuntCalSource',
            'name': 'AI_BRIDGE_SHUNT_CAL_SHUNT_CAL_B_SRC',
            'resettable': True,
            'type': 'int32'
        },
        12541: {
            'access': 'read-write',
            'enum': 'Sense',
            'name': 'AI_EXCIT_SENSE',
            'resettable': True,
            'type': 'int32'
        },
        12543: {
            'access': 'read-write',
            'name': 'AI_OPEN_CHAN_DETECT_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12562: {
            'access': 'read-write',
            'enum': 'ChargeUnits',
            'name': 'AI_CHARGE_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12563: {
            'access': 'read-write',
            'name': 'AI_ACCEL_CHARGE_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        12564: {
            'access': 'read-write',
            'enum': 'AccelChargeSensitivityUnits',
            'name': 'AI_ACCEL_CHARGE_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12565: {
            'access': 'read-write',
            'name': 'AI_ACCEL_4_WIRE_DC_VOLTAGE_SENSITIVITY',
            'resettable': True,
            'type': 'float64'
        },
        12566: {
            'access': 'read-write',
            'enum': 'AccelSensitivityUnits1',
            'name': 'AI_ACCEL_4_WIRE_DC_VOLTAGE_SENSITIVITY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12567: {
            'access': 'read-write',
            'name': 'AI_DATA_XFER_MAX_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12604: {
            'access': 'read-write',
            'enum': 'SyncUnlockBehavior',
            'name': 'CHAN_SYNC_UNLOCK_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12611: {
            'access': 'read-write',
            'name': 'AI_CHOP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12649: {
            'access': 'read-write',
            'name': 'AI_SENSOR_POWER_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12650: {
            'access': 'read-write',
            'enum': 'SensorPowerCfg',
            'name': 'AI_SENSOR_POWER_CFG',
            'resettable': True,
            'type': 'int32'
        },
        12651: {
            'access': 'read-write',
            'enum': 'SensorPowerType',
            'name': 'AI_SENSOR_POWER_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12659: {
            'access': 'read-write',
            'name': 'AI_FILTER_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12660: {
            'access': 'read-write',
            'name': 'AI_FILTER_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        12661: {
            'access': 'read-write',
            'enum': 'FilterResponse1',
            'name': 'AI_FILTER_RESPONSE',
            'resettable': True,
            'type': 'int32'
        },
        12662: {
            'access': 'read-write',
            'name': 'AI_FILTER_ORDER',
            'resettable': True,
            'type': 'uInt32'
        },
        12684: {
            'access': 'read-write',
            'name': 'AI_INPUT_LIMITS_FAULT_DETECT_UPPER_LIMIT',
            'resettable': True,
            'type': 'float64'
        },
        12685: {
            'access': 'read-write',
            'name': 'AI_INPUT_LIMITS_FAULT_DETECT_LOWER_LIMIT',
            'resettable': True,
            'type': 'float64'
        },
        12686: {
            'access': 'read-write',
            'name': 'AI_INPUT_LIMITS_FAULT_DETECT_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12689: {
            'access': 'read-write',
            'name': 'AI_POWER_SUPPLY_FAULT_DETECT_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12692: {
            'access': 'read-write',
            'name': 'AI_OVERCURRENT_DETECT_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12715: {
            'access': 'read-write',
            'name': 'CI_FREQ_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12716: {
            'access': 'read-write',
            'name': 'CI_FREQ_HYST',
            'resettable': True,
            'type': 'float64'
        },
        12717: {
            'access': 'read-write',
            'name': 'CI_PERIOD_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12718: {
            'access': 'read-write',
            'name': 'CI_PERIOD_HYST',
            'resettable': True,
            'type': 'float64'
        },
        12719: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12720: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_HYST',
            'resettable': True,
            'type': 'float64'
        },
        12721: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12722: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_DIR_HYST',
            'resettable': True,
            'type': 'float64'
        },
        12723: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12724: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_COUNT_RESET_HYST',
            'resettable': True,
            'type': 'float64'
        },
        12725: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_THRESH_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12726: {
            'access': 'read-write',
            'name': 'CI_COUNT_EDGES_GATE_HYST',
            'resettable': True,
            'type': 'float64'
        },
        12727: {
            'access': 'read-write',
            'name': 'CI_FILTER_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12728: {
            'access': 'read-write',
            'name': 'CI_FILTER_FREQ',
            'resettable': True,
            'type': 'float64'
        },
        12729: {
            'access': 'read-write',
            'enum': 'FilterResponse1',
            'name': 'CI_FILTER_RESPONSE',
            'resettable': True,
            'type': 'int32'
        },
        12730: {
            'access': 'read-write',
            'name': 'CI_FILTER_ORDER',
            'resettable': True,
            'type': 'uInt32'
        },
        12731: {
            'access': 'read',
            'name': 'CI_FILTER_DELAY',
            'resettable': False,
            'type': 'float64'
        },
        12732: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits4',
            'name': 'CI_FILTER_DELAY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        12740: {
            'access': 'read-write',
            'name': 'AO_FUNC_GEN_START_PHASE',
            'resettable': True,
            'type': 'float64'
        },
        12748: {
            'access': 'read-write',
            'name': 'AO_COMMON_MODE_OFFSET',
            'resettable': True,
            'type': 'float64'
        },
        12756: {
            'access': 'read-write',
            'name': 'PWR_VOLTAGE_SETPOINT',
            'resettable': True,
            'type': 'float64'
        },
        12757: {
            'access': 'read-write',
            'name': 'PWR_CURRENT_SETPOINT',
            'resettable': True,
            'type': 'float64'
        },
        12758: {
            'access': 'read-write',
            'name': 'PWR_OUTPUT_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12759: {
            'access': 'read',
            'enum': 'PowerOutputState',
            'name': 'PWR_OUTPUT_STATE',
            'resettable': False,
            'type': 'int32'
        },
        12760: {
            'access': 'read-write',
            'enum': 'PowerIdleOutputBehavior',
            'name': 'PWR_IDLE_OUTPUT_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12761: {
            'access': 'read',
            'name': 'PWR_VOLTAGE_DEV_SCALING_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        12762: {
            'access': 'read',
            'name': 'PWR_CURRENT_DEV_SCALING_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        12763: {
            'access': 'read-write',
            'enum': 'Sense',
            'name': 'PWR_REMOTE_SENSE',
            'resettable': True,
            'type': 'int32'
        }
    },
    'Device': {
        1585: {
            'access': 'read',
            'name': 'PRODUCT_TYPE',
            'resettable': False,
            'type': 'char[]'
        },
        1586: {
            'access': 'read',
            'name': 'SERIAL_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        8906: {
            'access': 'read',
            'name': 'IS_SIMULATED',
            'resettable': False,
            'type': 'bool32'
        },
        8989: {
            'access': 'read',
            'name': 'PRODUCT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        8990: {
            'access': 'read',
            'name': 'AI_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8991: {
            'access': 'read',
            'name': 'AO_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8992: {
            'access': 'read',
            'name': 'DI_LINES',
            'resettable': False,
            'type': 'char[]'
        },
        8993: {
            'access': 'read',
            'name': 'DI_PORTS',
            'resettable': False,
            'type': 'char[]'
        },
        8994: {
            'access': 'read',
            'name': 'DO_LINES',
            'resettable': False,
            'type': 'char[]'
        },
        8995: {
            'access': 'read',
            'name': 'DO_PORTS',
            'resettable': False,
            'type': 'char[]'
        },
        8996: {
            'access': 'read',
            'name': 'CI_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8997: {
            'access': 'read',
            'name': 'CO_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8998: {
            'access': 'read',
            'enum': 'BusType',
            'name': 'BUS_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        8999: {
            'access': 'read',
            'name': 'PCI_BUS_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9000: {
            'access': 'read',
            'name': 'PCI_DEV_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9001: {
            'access': 'read',
            'name': 'PXI_CHASSIS_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9002: {
            'access': 'read',
            'name': 'PXI_SLOT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9020: {
            'access': 'read',
            'name': 'NUM_DMA_CHANS',
            'resettable': False,
            'type': 'uInt32'
        },
        10628: {
            'access': 'read',
            'name': 'ANLG_TRIG_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10629: {
            'access': 'read',
            'name': 'DIG_TRIG_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10630: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'AI_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10631: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'AO_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10632: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'DI_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10633: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'DO_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10634: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'CI_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10635: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'CO_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10636: {
            'access': 'read',
            'name': 'AI_MAX_SINGLE_CHAN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10637: {
            'access': 'read',
            'name': 'AI_MAX_MULTI_CHAN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10638: {
            'access': 'read',
            'name': 'AI_MIN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10639: {
            'access': 'read',
            'name': 'AI_SIMULTANEOUS_SAMPLING_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10640: {
            'access': 'read',
            'name': 'AI_VOLTAGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10641: {
            'access': 'read',
            'name': 'AI_CURRENT_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10642: {
            'access': 'read',
            'name': 'AI_FREQ_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10643: {
            'access': 'read',
            'name': 'AI_GAINS',
            'resettable': False,
            'type': 'float64[]'
        },
        10644: {
            'access': 'read',
            'enum': 'Coupling1',
            'name': 'AI_COUPLINGS',
            'resettable': False,
            'type': 'int32[]'
        },
        10645: {
            'access': 'read',
            'name': 'AI_LOWPASS_CUTOFF_FREQ_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10646: {
            'access': 'read',
            'name': 'AO_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10647: {
            'access': 'read',
            'name': 'AO_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10648: {
            'access': 'read',
            'name': 'AO_MIN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10649: {
            'access': 'read',
            'name': 'DI_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10650: {
            'access': 'read',
            'name': 'DO_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10651: {
            'access': 'read',
            'name': 'AO_VOLTAGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10652: {
            'access': 'read',
            'name': 'AO_CURRENT_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10653: {
            'access': 'read',
            'name': 'AO_GAINS',
            'resettable': False,
            'type': 'float64[]'
        },
        10654: {
            'access': 'read',
            'name': 'CI_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10655: {
            'access': 'read',
            'name': 'CI_MAX_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        10656: {
            'access': 'read',
            'name': 'CI_MAX_TIMEBASE',
            'resettable': False,
            'type': 'float64'
        },
        10657: {
            'access': 'read',
            'name': 'CO_MAX_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        10658: {
            'access': 'read',
            'name': 'CO_MAX_TIMEBASE',
            'resettable': False,
            'type': 'float64'
        },
        10665: {
            'access': 'read',
            'enum': 'ProductCategory',
            'name': 'PRODUCT_CATEGORY',
            'resettable': False,
            'type': 'int32'
        },
        10678: {
            'access': 'read',
            'name': 'CHASSIS_MODULE_DEV_NAMES',
            'resettable': False,
            'type': 'char[]'
        },
        10679: {
            'access': 'read',
            'name': 'COMPACT_DAQ_CHASSIS_DEV_NAME',
            'resettable': False,
            'type': 'char[]'
        },
        10680: {
            'access': 'read',
            'name': 'COMPACT_DAQ_SLOT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        10697: {
            'access': 'read',
            'name': 'AI_VOLTAGE_INT_EXCIT_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10698: {
            'access': 'read',
            'name': 'AI_VOLTAGE_INT_EXCIT_RANGE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10699: {
            'access': 'read',
            'name': 'AI_CURRENT_INT_EXCIT_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10703: {
            'access': 'read',
            'name': 'AI_LOWPASS_CUTOFF_FREQ_RANGE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10773: {
            'access': 'read',
            'name': 'AI_RESISTANCE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10816: {
            'access': 'read',
            'name': 'TERMINALS',
            'resettable': False,
            'type': 'char[]'
        },
        10890: {
            'access': 'read',
            'name': 'CARRIER_SERIAL_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        10891: {
            'access': 'read',
            'name': 'TCPIP_HOSTNAME',
            'resettable': False,
            'type': 'char[]'
        },
        10892: {
            'access': 'read',
            'name': 'TCPIP_ETHERNET_IP',
            'resettable': False,
            'type': 'char[]'
        },
        10893: {
            'access': 'read',
            'name': 'TCPIP_WIRELESS_IP',
            'resettable': False,
            'type': 'char[]'
        },
        12123: {
            'access': 'read',
            'name': 'CO_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        12141: {
            'access': 'read',
            'name': 'ACCESSORY_PRODUCT_TYPES',
            'resettable': False,
            'type': 'char[]'
        },
        12142: {
            'access': 'read',
            'name': 'ACCESSORY_PRODUCT_NUMS',
            'resettable': False,
            'type': 'uInt32[]'
        },
        12143: {
            'access': 'read',
            'name': 'ACCESSORY_SERIAL_NUMS',
            'resettable': False,
            'type': 'uInt32[]'
        },
        12240: {
            'access': 'read',
            'name': 'AI_BRIDGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        12242: {
            'access': 'read',
            'enum': 'AIMeasurementType',
            'name': 'AI_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12243: {
            'access': 'read',
            'enum': 'AOOutputChannelType',
            'name': 'AO_SUPPORTED_OUTPUT_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12244: {
            'access': 'read',
            'enum': 'CIMeasurementType',
            'name': 'CI_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12245: {
            'access': 'read',
            'enum': 'COOutputType',
            'name': 'CO_SUPPORTED_OUTPUT_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12246: {
            'access': 'read',
            'name': 'TEDS_HWTEDS_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        12252: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'AI_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12253: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'AO_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12254: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'CI_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12255: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'CO_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12319: {
            'access': 'read',
            'name': 'TIME_TRIG_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        12320: {
            'access': 'read',
            'name': 'CI_CURRENT_UTC_OFFSET',
            'resettable': False,
            'type': 'int32'
        },
        12321: {
            'access': 'read',
            'name': 'CI_UTC_OFFSET_READY',
            'resettable': False,
            'type': 'bool32'
        },
        12322: {
            'access': 'read',
            'name': 'NAV_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12323: {
            'access': 'read',
            'enum': 'NavMeasurementType',
            'name': 'NAV_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12324: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'NAV_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        12325: {
            'access': 'read-write',
            'enum': 'NavMode',
            'name': 'NAV_MODE',
            'resettable': False,
            'type': 'int32'
        },
        12326: {
            'access': 'read-write',
            'name': 'NAV_PRESET_LAT',
            'resettable': False,
            'type': 'float64'
        },
        12327: {
            'access': 'read-write',
            'name': 'NAV_PRESET_LONG',
            'resettable': False,
            'type': 'float64'
        },
        12328: {
            'access': 'read-write',
            'name': 'NAV_PRESET_ALT',
            'resettable': False,
            'type': 'float64'
        },
        12329: {
            'access': 'read-write',
            'enum': 'AltRef',
            'name': 'NAV_ALT_REF',
            'resettable': False,
            'type': 'int32'
        },
        12330: {
            'access': 'read-write',
            'name': 'NAV_PPS_COMPEN',
            'resettable': False,
            'type': 'float64'
        },
        12331: {
            'access': 'read-write',
            'name': 'NAV_NUM_SURVEY_FIXES',
            'resettable': False,
            'type': 'uInt32'
        },
        12332: {
            'access': 'read',
            'name': 'NAV_REMAINING_SURVEY_FIXES',
            'resettable': False,
            'type': 'uInt32'
        },
        12333: {
            'access': 'read',
            'name': 'NAV_HAS_FIX',
            'resettable': False,
            'type': 'bool32'
        },
        12334: {
            'access': 'read',
            'enum': 'AntStatus',
            'name': 'NAV_ANT_STATUS',
            'resettable': False,
            'type': 'int32'
        },
        12335: {
            'access': 'read',
            'name': 'NAV_UTC_OFFSET_READY',
            'resettable': False,
            'type': 'bool32'
        },
        12336: {
            'access': 'read',
            'name': 'NAV_CURRENT_UTC_OFFSET',
            'resettable': False,
            'type': 'int32'
        },
        12337: {
            'access': 'read',
            'name': 'NAV_NUM_SATS',
            'resettable': False,
            'type': 'uInt32'
        },
        12338: {
            'access': 'read',
            'name': 'NAV_PDOP',
            'resettable': False,
            'type': 'float64'
        },
        12339: {
            'access': 'read',
            'name': 'NAV_HDOP',
            'resettable': False,
            'type': 'float64'
        },
        12340: {
            'access': 'read',
            'name': 'NAV_VDOP',
            'resettable': False,
            'type': 'float64'
        },
        12488: {
            'access': 'read',
            'name': 'AI_DIG_FLTR_LOWPASS_CUTOFF_FREQ_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        12489: {
            'access': 'read',
            'name': 'AI_DIG_FLTR_LOWPASS_CUTOFF_FREQ_RANGE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        12551: {
            'access': 'read',
            'enum': 'FilterType2',
            'name': 'AI_DIG_FLTR_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12561: {
            'access': 'read',
            'name': 'AI_CHARGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        12609: {
            'access': 'read',
            'name': 'NUM_TIME_TRIGS',
            'resettable': False,
            'type': 'uInt32'
        },
        12610: {
            'access': 'read',
            'name': 'NUM_TIMESTAMP_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12641: {
            'access': 'read',
            'name': 'COMPACT_RIO_CHASSIS_DEV_NAME',
            'resettable': False,
            'type': 'char[]'
        },
        12642: {
            'access': 'read',
            'name': 'COMPACT_RIO_SLOT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        12643: {
            'access': 'read',
            'name': 'AI_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12644: {
            'access': 'read',
            'name': 'AI_NUM_SYNC_PULSE_SRCS',
            'resettable': False,
            'type': 'uInt32'
        },
        12645: {
            'access': 'read',
            'name': 'AO_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12646: {
            'access': 'read',
            'name': 'AO_NUM_SYNC_PULSE_SRCS',
            'resettable': False,
            'type': 'uInt32'
        },
        12647: {
            'access': 'read',
            'name': 'DI_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12648: {
            'access': 'read',
            'name': 'DO_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12657: {
            'access': 'read',
            'name': 'FIELD_DAQ_DEV_NAME',
            'resettable': False,
            'type': 'char[]'
        },
        12664: {
            'access': 'read',
            'name': 'FIELD_DAQ_BANK_DEV_NAMES',
            'resettable': False,
            'type': 'char[]'
        }
    },
    'ExportSignal': {
        1409: {
            'access': 'read',
            'name': 'START_TRIG_DELAY',
            'resettable': False,
            'type': 'float64'
        },
        1412: {
            'access': 'read-write',
            'name': 'START_TRIG_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        1413: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'START_TRIG_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        1414: {
            'access': 'read',
            'name': 'START_TRIG_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        1424: {
            'access': 'read-write',
            'name': 'REF_TRIG_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        1425: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'REF_TRIG_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        5634: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'START_TRIG_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5641: {
            'access': 'read-write',
            'name': 'RDY_FOR_START_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5653: {
            'access': 'read-write',
            'name': 'PAUSE_TRIG_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5654: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'PAUSE_TRIG_LVL_ACTIVE_LVL',
            'resettable': True,
            'type': 'int32'
        },
        5666: {
            'access': 'read',
            'enum': 'Polarity2',
            'name': 'RDY_FOR_REF_EVENT_PULSE_POLARITY',
            'resettable': False,
            'type': 'int32'
        },
        5667: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'RDY_FOR_REF_EVENT_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5668: {
            'access': 'read',
            'name': 'RDY_FOR_REF_EVENT_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        5683: {
            'access': 'read-write',
            'name': 'DATA_ACTIVE_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5684: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'DATA_ACTIVE_EVENT_LVL_ACTIVE_LVL',
            'resettable': True,
            'type': 'int32'
        },
        5701: {
            'access': 'read-write',
            'name': 'ADV_TRIG_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5702: {
            'access': 'read',
            'enum': 'Polarity2',
            'name': 'ADV_TRIG_PULSE_POLARITY',
            'resettable': False,
            'type': 'int32'
        },
        5703: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits3',
            'name': 'ADV_TRIG_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5704: {
            'access': 'read-write',
            'name': 'ADV_TRIG_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        5706: {
            'access': 'read-write',
            'name': 'ADV_CMPLT_EVENT_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        5713: {
            'access': 'read-write',
            'name': 'ADV_CMPLT_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5714: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'ADV_CMPLT_EVENT_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        5715: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'ADV_CMPLT_EVENT_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5716: {
            'access': 'read-write',
            'name': 'ADV_CMPLT_EVENT_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        5718: {
            'access': 'read-write',
            'name': '20_MHZ_TIMEBASE_DIVIDE_DOWN_BY_N',
            'resettable': True,
            'type': 'uInt32'
        },
        5719: {
            'access': 'read-write',
            'name': '20_MHZ_TIMEBASE_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5720: {
            'access': 'read',
            'enum': 'Polarity2',
            'name': '20_MHZ_TIMEBASE_PULSE_POLARITY',
            'resettable': False,
            'type': 'int32'
        },
        5721: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': '20_MHZ_TIMEBASE_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5728: {
            'access': 'read',
            'name': '20_MHZ_TIMEBASE_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        5731: {
            'access': 'read-write',
            'name': 'SAMP_CLK_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5732: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'SAMP_CLK_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        5733: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'SAMP_CLK_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5734: {
            'access': 'read',
            'name': 'SAMP_CLK_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        5767: {
            'access': 'read-write',
            'name': 'AI_CONV_CLK_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5768: {
            'access': 'read',
            'enum': 'Polarity2',
            'name': 'AI_CONV_CLK_PULSE_POLARITY',
            'resettable': False,
            'type': 'int32'
        },
        5769: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'AI_CONV_CLK_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5776: {
            'access': 'read',
            'name': 'AI_CONV_CLK_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        5906: {
            'access': 'read',
            'enum': 'Polarity2',
            'name': 'FREQ_OUT_CLK_PULSE_POLARITY',
            'resettable': False,
            'type': 'int32'
        },
        5907: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'FREQ_OUT_CLK_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5908: {
            'access': 'read',
            'name': 'FREQ_OUT_CLK_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        5911: {
            'access': 'read-write',
            'name': 'CTR_OUT_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        5912: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'CTR_OUT_EVENT_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        5913: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'CTR_OUT_EVENT_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5920: {
            'access': 'read',
            'name': 'CTR_OUT_EVENT_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        5942: {
            'access': 'read',
            'enum': 'Polarity2',
            'name': 'REF_CLK_PULSE_POLARITY',
            'resettable': False,
            'type': 'int32'
        },
        5943: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'REF_CLK_PULSE_WIDTH_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5944: {
            'access': 'read',
            'name': 'REF_CLK_PULSE_WIDTH',
            'resettable': False,
            'type': 'float64'
        },
        5955: {
            'access': 'read-write',
            'enum': 'ExportActions',
            'name': 'START_TRIG_OUTPUT_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        5956: {
            'access': 'read-write',
            'enum': 'Level1',
            'name': 'START_TRIG_TOGGLE_INITIAL_STATE',
            'resettable': True,
            'type': 'int32'
        },
        5965: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'START_TRIG_DELAY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        5967: {
            'access': 'read-write',
            'enum': 'ExportActions2',
            'name': 'CTR_OUT_EVENT_OUTPUT_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        5968: {
            'access': 'read',
            'enum': 'Polarity2',
            'name': 'CTR_OUT_EVENT_LVL_POLARITY',
            'resettable': False,
            'type': 'int32'
        },
        5969: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'RDY_FOR_START_EVENT_LVL_ACTIVE_LVL',
            'resettable': True,
            'type': 'int32'
        },
        5975: {
            'access': 'read-write',
            'name': 'ADV_CMPLT_EVENT_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        6250: {
            'access': 'read-write',
            'enum': 'Level1',
            'name': 'CTR_OUT_EVENT_TOGGLE_IDLE_STATE',
            'resettable': True,
            'type': 'int32'
        },
        6251: {
            'access': 'read-write',
            'enum': 'ExportActions3',
            'name': 'SAMP_CLK_OUTPUT_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        6381: {
            'access': 'read-write',
            'name': 'AI_HOLD_CMPLT_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        6382: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'AI_HOLD_CMPLT_EVENT_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        6393: {
            'access': 'read-write',
            'name': 'SAMP_CLK_TIMEBASE_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8599: {
            'access': 'read-write',
            'name': 'CHANGE_DETECT_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8609: {
            'access': 'read-write',
            'name': 'DIVIDED_SAMP_CLK_TIMEBASE_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8618: {
            'access': 'read-write',
            'name': 'WATCHDOG_EXPIRED_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8644: {
            'access': 'read-write',
            'name': 'SAMP_CLK_DELAY_OFFSET',
            'resettable': True,
            'type': 'float64'
        },
        8764: {
            'access': 'read-write',
            'name': 'SYNC_PULSE_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8814: {
            'access': 'read-write',
            'name': '10_MHZ_REF_CLK_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8885: {
            'access': 'read-write',
            'name': 'RDY_FOR_XFER_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8886: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'RDY_FOR_XFER_EVENT_LVL_ACTIVE_LVL',
            'resettable': True,
            'type': 'int32'
        },
        8890: {
            'access': 'read-write',
            'name': 'HSHK_EVENT_OUTPUT_TERM',
            'resettable': True,
            'type': 'char[]'
        },
        8891: {
            'access': 'read-write',
            'enum': 'ExportActions5',
            'name': 'HSHK_EVENT_OUTPUT_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        8892: {
            'access': 'read-write',
            'name': 'HSHK_EVENT_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        8893: {
            'access': 'read-write',
            'enum': 'Level1',
            'name': 'HSHK_EVENT_INTERLOCKED_ASSERTED_LVL',
            'resettable': True,
            'type': 'int32'
        },
        8894: {
            'access': 'read-write',
            'name': 'HSHK_EVENT_INTERLOCKED_ASSERT_ON_START',
            'resettable': True,
            'type': 'bool32'
        },
        8895: {
            'access': 'read-write',
            'name': 'HSHK_EVENT_INTERLOCKED_DEASSERT_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        8896: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'HSHK_EVENT_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        8897: {
            'access': 'read-write',
            'name': 'HSHK_EVENT_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8963: {
            'access': 'read-write',
            'enum': 'Polarity2',
            'name': 'CHANGE_DETECT_EVENT_PULSE_POLARITY',
            'resettable': True,
            'type': 'int32'
        },
        10595: {
            'access': 'read-write',
            'enum': 'DeassertCondition',
            'name': 'RDY_FOR_XFER_EVENT_DEASSERT_COND',
            'resettable': True,
            'type': 'int32'
        },
        10596: {
            'access': 'read-write',
            'name': 'RDY_FOR_XFER_EVENT_DEASSERT_COND_CUSTOM_THRESHOLD',
            'resettable': True,
            'type': 'uInt32'
        }
    },
    'PersistedChannel': {
        8911: {
            'access': 'write',
            'name': 'ACTIVE_CHAN',
            'resettable': False,
            'type': 'char[]'
        },
        8912: {
            'access': 'read',
            'name': 'AUTHOR',
            'resettable': False,
            'type': 'char[]'
        },
        8913: {
            'access': 'read',
            'name': 'ALLOW_INTERACTIVE_EDITING',
            'resettable': False,
            'type': 'bool32'
        },
        8914: {
            'access': 'read',
            'name': 'ALLOW_INTERACTIVE_DELETION',
            'resettable': False,
            'type': 'bool32'
        }
    },
    'PersistedScale': {
        8915: {
            'access': 'write',
            'name': 'ACTIVE_SCALE',
            'resettable': False,
            'type': 'char[]'
        },
        8916: {
            'access': 'read',
            'name': 'AUTHOR',
            'resettable': False,
            'type': 'char[]'
        },
        8917: {
            'access': 'read',
            'name': 'ALLOW_INTERACTIVE_EDITING',
            'resettable': False,
            'type': 'bool32'
        },
        8918: {
            'access': 'read',
            'name': 'ALLOW_INTERACTIVE_DELETION',
            'resettable': False,
            'type': 'bool32'
        }
    },
    'PersistedTask': {
        8907: {
            'access': 'write',
            'name': 'ACTIVE_TASK',
            'resettable': False,
            'type': 'char[]'
        },
        8908: {
            'access': 'read',
            'name': 'AUTHOR',
            'resettable': False,
            'type': 'char[]'
        },
        8909: {
            'access': 'read',
            'name': 'ALLOW_INTERACTIVE_EDITING',
            'resettable': False,
            'type': 'bool32'
        },
        8910: {
            'access': 'read',
            'name': 'ALLOW_INTERACTIVE_DELETION',
            'resettable': False,
            'type': 'bool32'
        }
    },
    'PhysicalChannel': {
        8666: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_TEDS_MFG_ID',
            'resettable': False,
            'type': 'uInt32'
        },
        8667: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_TEDS_MODEL_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        8668: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_TEDS_SERIAL_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        8669: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_TEDS_VERSION_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        8670: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_TEDS_VERSION_LETTER',
            'resettable': False,
            'type': 'char[]'
        },
        8671: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_TEDS_BIT_STREAM',
            'resettable': False,
            'type': 'uInt8[]'
        },
        8847: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_TEDS_TEMPLATE_I_DS',
            'resettable': False,
            'type': 'uInt32[]'
        },
        9026: {
            'access': 'read',
            'enum': 'InputTermCfg',
            'name': 'PHYSICAL_CHAN_AI_TERM_CFGS',
            'resettable': False,
            'type': 'int32[]'
        },
        10659: {
            'access': 'read',
            'enum': 'OutputTermCfg',
            'name': 'PHYSICAL_CHAN_AO_TERM_CFGS',
            'resettable': False,
            'type': 'int32[]'
        },
        10660: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_DI_PORT_WIDTH',
            'resettable': False,
            'type': 'uInt32'
        },
        10661: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_DI_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10662: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_DI_CHANGE_DETECT_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10663: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_DO_PORT_WIDTH',
            'resettable': False,
            'type': 'uInt32'
        },
        10664: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_DO_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10782: {
            'access': 'read-write',
            'name': 'PHYSICAL_CHAN_AO_MANUAL_CONTROL_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        10783: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_AO_MANUAL_CONTROL_AMPLITUDE',
            'resettable': False,
            'type': 'float64'
        },
        10784: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_AO_MANUAL_CONTROL_FREQ',
            'resettable': False,
            'type': 'float64'
        },
        11971: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_AO_MANUAL_CONTROL_SHORT_DETECTED',
            'resettable': False,
            'type': 'bool32'
        },
        12247: {
            'access': 'read',
            'enum': 'AIMeasurementType',
            'name': 'PHYSICAL_CHAN_AI_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12248: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_AI_INPUT_SRCS',
            'resettable': False,
            'type': 'char[]'
        },
        12249: {
            'access': 'read',
            'enum': 'AOOutputChannelType',
            'name': 'PHYSICAL_CHAN_AO_SUPPORTED_OUTPUT_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12250: {
            'access': 'read',
            'enum': 'CIMeasurementType',
            'name': 'PHYSICAL_CHAN_CI_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12251: {
            'access': 'read',
            'enum': 'COOutputType',
            'name': 'PHYSICAL_CHAN_CO_SUPPORTED_OUTPUT_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12256: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'PHYSICAL_CHAN_DI_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12257: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'PHYSICAL_CHAN_DO_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12343: {
            'access': 'read',
            'enum': 'NavMeasurementType',
            'name': 'PHYSICAL_CHAN_NAV_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12366: {
            'access': 'read',
            'enum': 'AOPowerUpOutputBehavior',
            'name': 'PHYSICAL_CHAN_AO_SUPPORTED_POWER_UP_OUTPUT_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12386: {
            'access': 'read-write',
            'name': 'AO_POWER_AMP_CHANNEL_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12387: {
            'access': 'read',
            'name': 'AO_POWER_AMP_SCALING_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        12388: {
            'access': 'read',
            'name': 'AO_POWER_AMP_OVERCURRENT',
            'resettable': False,
            'type': 'bool32'
        },
        12389: {
            'access': 'read',
            'name': 'AO_POWER_AMP_GAIN',
            'resettable': False,
            'type': 'float64'
        },
        12390: {
            'access': 'read',
            'name': 'AO_POWER_AMP_OFFSET',
            'resettable': False,
            'type': 'float64'
        },
        12652: {
            'access': 'read-write',
            'name': 'PHYSICAL_CHAN_AI_POWER_CONTROL_VOLTAGE',
            'resettable': True,
            'type': 'float64'
        },
        12653: {
            'access': 'read-write',
            'name': 'PHYSICAL_CHAN_AI_POWER_CONTROL_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12654: {
            'access': 'read-write',
            'enum': 'SensorPowerType',
            'name': 'PHYSICAL_CHAN_AI_POWER_CONTROL_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12665: {
            'access': 'read',
            'enum': 'SensorPowerType',
            'name': 'PHYSICAL_CHAN_AI_SENSOR_POWER_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12666: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_AI_SENSOR_POWER_VOLTAGE_RANGE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        12668: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_AI_SENSOR_POWER_OPEN_CHAN',
            'resettable': False,
            'type': 'bool32'
        },
        12669: {
            'access': 'read',
            'name': 'PHYSICAL_CHAN_AI_SENSOR_POWER_OVERCURRENT',
            'resettable': False,
            'type': 'bool32'
        }
    },
    'Read': {
        4625: {
            'access': 'read-write',
            'enum': 'OverwriteMode1',
            'name': 'OVERWRITE',
            'resettable': True,
            'type': 'int32'
        },
        4629: {
            'access': 'read-write',
            'name': 'READ_ALL_AVAIL_SAMP',
            'resettable': True,
            'type': 'bool32'
        },
        4641: {
            'access': 'read',
            'name': 'CURR_READ_POS',
            'resettable': False,
            'type': 'uInt64'
        },
        4643: {
            'access': 'read',
            'name': 'AVAIL_SAMP_PER_CHAN',
            'resettable': False,
            'type': 'uInt32'
        },
        6179: {
            'access': 'read-write',
            'name': 'CHANNELS_TO_READ',
            'resettable': True,
            'type': 'char[]'
        },
        6182: {
            'access': 'read-write',
            'name': 'AUTO_START',
            'resettable': True,
            'type': 'bool32'
        },
        6410: {
            'access': 'read-write',
            'enum': 'ReadRelativeTo',
            'name': 'RELATIVE_TO',
            'resettable': True,
            'type': 'int32'
        },
        6411: {
            'access': 'read-write',
            'name': 'OFFSET',
            'resettable': True,
            'type': 'int32'
        },
        6442: {
            'access': 'read',
            'name': 'TOTAL_SAMP_PER_CHAN_ACQUIRED',
            'resettable': False,
            'type': 'uInt64'
        },
        8564: {
            'access': 'read',
            'name': 'OVERLOADED_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        8565: {
            'access': 'read',
            'name': 'OVERLOADED_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8570: {
            'access': 'read',
            'name': 'RAW_DATA_WIDTH',
            'resettable': False,
            'type': 'uInt32'
        },
        8571: {
            'access': 'read',
            'name': 'NUM_CHANS',
            'resettable': False,
            'type': 'uInt32'
        },
        8572: {
            'access': 'read',
            'name': 'DIGITAL_LINES_BYTES_PER_CHAN',
            'resettable': False,
            'type': 'uInt32'
        },
        8596: {
            'access': 'read',
            'name': 'CHANGE_DETECT_HAS_OVERFLOWED',
            'resettable': False,
            'type': 'bool32'
        },
        8754: {
            'access': 'read-write',
            'enum': 'WaitMode',
            'name': 'WAIT_MODE',
            'resettable': True,
            'type': 'int32'
        },
        8880: {
            'access': 'read-write',
            'name': 'SLEEP_TIME',
            'resettable': True,
            'type': 'float64'
        },
        10726: {
            'access': 'read',
            'name': 'OVERCURRENT_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        10727: {
            'access': 'read',
            'name': 'OVERCURRENT_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        10761: {
            'access': 'read',
            'name': 'OPEN_CURRENT_LOOP_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        10762: {
            'access': 'read',
            'name': 'OPEN_CURRENT_LOOP_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        10902: {
            'access': 'read',
            'name': 'OPEN_THRMCPL_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        10903: {
            'access': 'read',
            'name': 'OPEN_THRMCPL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        10904: {
            'access': 'read',
            'name': 'COMMON_MODE_RANGE_ERROR_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        10905: {
            'access': 'read',
            'name': 'COMMON_MODE_RANGE_ERROR_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        11972: {
            'access': 'read-write',
            'name': 'LOGGING_FILE_PATH',
            'resettable': True,
            'type': 'char[]'
        },
        11973: {
            'access': 'read-write',
            'enum': 'LoggingMode',
            'name': 'LOGGING_MODE',
            'resettable': True,
            'type': 'int32'
        },
        11974: {
            'access': 'read-write',
            'name': 'LOGGING_TDMS_GROUP_NAME',
            'resettable': True,
            'type': 'char[]'
        },
        11975: {
            'access': 'read-write',
            'enum': 'LoggingOperation',
            'name': 'LOGGING_TDMS_OPERATION',
            'resettable': True,
            'type': 'int32'
        },
        12144: {
            'access': 'read',
            'name': 'ACCESSORY_INSERTION_OR_REMOVAL_DETECTED',
            'resettable': False,
            'type': 'bool32'
        },
        12145: {
            'access': 'read',
            'name': 'DEVS_WITH_INSERTED_OR_REMOVED_ACCESSORIES',
            'resettable': False,
            'type': 'char[]'
        },
        12227: {
            'access': 'read-write',
            'name': 'LOGGING_FILE_WRITE_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        12230: {
            'access': 'read-write',
            'name': 'LOGGING_FILE_PREALLOCATION_SIZE',
            'resettable': True,
            'type': 'uInt64'
        },
        12259: {
            'access': 'read-write',
            'name': 'LOGGING_PAUSE',
            'resettable': True,
            'type': 'bool32'
        },
        12260: {
            'access': 'read-write',
            'name': 'LOGGING_SAMPS_PER_FILE',
            'resettable': True,
            'type': 'uInt64'
        },
        12341: {
            'access': 'read',
            'name': 'NAV_FIX_LOST',
            'resettable': False,
            'type': 'bool32'
        },
        12417: {
            'access': 'read',
            'name': 'OVERTEMPERATURE_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12418: {
            'access': 'read',
            'name': 'OVERTEMPERATURE_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12424: {
            'access': 'read',
            'name': 'EXCIT_FAULT_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12425: {
            'access': 'read',
            'name': 'EXCIT_FAULT_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12544: {
            'access': 'read',
            'name': 'OPEN_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12545: {
            'access': 'read',
            'name': 'OPEN_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12546: {
            'access': 'read',
            'name': 'OPEN_CHANS_DETAILS',
            'resettable': False,
            'type': 'char[]'
        },
        12568: {
            'access': 'read',
            'name': 'PLL_UNLOCKED_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12569: {
            'access': 'read',
            'name': 'PLL_UNLOCKED_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12605: {
            'access': 'read',
            'name': 'SYNC_UNLOCKED_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12606: {
            'access': 'read',
            'name': 'SYNC_UNLOCKED_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12687: {
            'access': 'read',
            'name': 'INPUT_LIMITS_FAULT_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12688: {
            'access': 'read',
            'name': 'INPUT_LIMITS_FAULT_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12690: {
            'access': 'read',
            'name': 'POWER_SUPPLY_FAULT_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12691: {
            'access': 'read',
            'name': 'POWER_SUPPLY_FAULT_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12765: {
            'access': 'read',
            'name': 'REMOTE_SENSE_ERROR_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12766: {
            'access': 'read',
            'name': 'REMOTE_SENSE_ERROR_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12767: {
            'access': 'read',
            'name': 'AUX_POWER_ERROR_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12768: {
            'access': 'read',
            'name': 'AUX_POWER_ERROR_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12774: {
            'access': 'read',
            'name': 'REVERSE_VOLTAGE_ERROR_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12775: {
            'access': 'read',
            'name': 'REVERSE_VOLTAGE_ERROR_CHANS',
            'resettable': False,
            'type': 'char[]'
        }
    },
    'RealTime': {
        8941: {
            'access': 'read-write',
            'name': 'NUM_OF_WARMUP_ITERS',
            'resettable': True,
            'type': 'uInt32'
        },
        8942: {
            'access': 'read-write',
            'name': 'CONV_LATE_ERRORS_TO_WARNINGS',
            'resettable': True,
            'type': 'bool32'
        },
        8943: {
            'access': 'read-write',
            'enum': 'WaitMode3',
            'name': 'WAIT_FOR_NEXT_SAMP_CLK_WAIT_MODE',
            'resettable': True,
            'type': 'int32'
        },
        8985: {
            'access': 'read-write',
            'name': 'REPORT_MISSED_SAMP',
            'resettable': True,
            'type': 'bool32'
        },
        8986: {
            'access': 'read-write',
            'enum': 'WaitMode4',
            'name': 'WRITE_RECOVERY_MODE',
            'resettable': True,
            'type': 'int32'
        }
    },
    'Scale': {
        4646: {
            'access': 'read-write',
            'name': 'DESCR',
            'resettable': False,
            'type': 'char[]'
        },
        4647: {
            'access': 'read-write',
            'name': 'LIN_SLOPE',
            'resettable': False,
            'type': 'float64'
        },
        4648: {
            'access': 'read-write',
            'name': 'LIN_Y_INTERCEPT',
            'resettable': False,
            'type': 'float64'
        },
        4649: {
            'access': 'read-write',
            'name': 'MAP_SCALED_MAX',
            'resettable': False,
            'type': 'float64'
        },
        4656: {
            'access': 'read-write',
            'name': 'MAP_SCALED_MIN',
            'resettable': False,
            'type': 'float64'
        },
        4657: {
            'access': 'read-write',
            'name': 'MAP_PRE_SCALED_MAX',
            'resettable': False,
            'type': 'float64'
        },
        4658: {
            'access': 'read-write',
            'name': 'MAP_PRE_SCALED_MIN',
            'resettable': False,
            'type': 'float64'
        },
        4660: {
            'access': 'read-write',
            'name': 'POLY_FORWARD_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        4661: {
            'access': 'read-write',
            'name': 'POLY_REVERSE_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        4662: {
            'access': 'read-write',
            'name': 'TABLE_SCALED_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        4663: {
            'access': 'read-write',
            'name': 'TABLE_PRE_SCALED_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        6391: {
            'access': 'read-write',
            'enum': 'UnitsPreScaled',
            'name': 'PRE_SCALED_UNITS',
            'resettable': False,
            'type': 'int32'
        },
        6427: {
            'access': 'read-write',
            'name': 'SCALED_UNITS',
            'resettable': False,
            'type': 'char[]'
        },
        6441: {
            'access': 'read',
            'enum': 'ScaleType',
            'name': 'TYPE',
            'resettable': False,
            'type': 'int32'
        }
    },
    'System': {
        4709: {
            'access': 'read',
            'name': 'GLOBAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        4710: {
            'access': 'read',
            'name': 'SCALES',
            'resettable': False,
            'type': 'char[]'
        },
        4711: {
            'access': 'read',
            'name': 'TASKS',
            'resettable': False,
            'type': 'char[]'
        },
        4722: {
            'access': 'read',
            'name': 'NIDAQ_MAJOR_VERSION',
            'resettable': False,
            'type': 'uInt32'
        },
        6435: {
            'access': 'read',
            'name': 'NIDAQ_MINOR_VERSION',
            'resettable': False,
            'type': 'uInt32'
        },
        6459: {
            'access': 'read',
            'name': 'DEV_NAMES',
            'resettable': False,
            'type': 'char[]'
        },
        12066: {
            'access': 'read',
            'name': 'NIDAQ_UPDATE_VERSION',
            'resettable': False,
            'type': 'uInt32'
        }
    },
    'Task': {
        4723: {
            'access': 'read',
            'name': 'CHANNELS',
            'resettable': False,
            'type': 'char[]'
        },
        4724: {
            'access': 'read',
            'name': 'COMPLETE',
            'resettable': False,
            'type': 'bool32'
        },
        4726: {
            'access': 'read',
            'name': 'NAME',
            'resettable': False,
            'type': 'char[]'
        },
        8577: {
            'access': 'read',
            'name': 'NUM_CHANS',
            'resettable': False,
            'type': 'uInt32'
        },
        8974: {
            'access': 'read',
            'name': 'DEVICES',
            'resettable': False,
            'type': 'char[]'
        },
        10682: {
            'access': 'read',
            'name': 'NUM_DEVICES',
            'resettable': False,
            'type': 'uInt32'
        }
    },
    'Timing': {
        4864: {
            'access': 'read-write',
            'enum': 'AcquisitionType',
            'name': 'SAMP_QUANT_SAMP_MODE',
            'resettable': True,
            'type': 'int32'
        },
        4865: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'SAMP_CLK_ACTIVE_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        4867: {
            'access': 'read-write',
            'name': 'SAMP_CLK_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        4868: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits2',
            'name': 'DELAY_FROM_SAMP_CLK_DELAY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        4869: {
            'access': 'read-write',
            'name': 'SAMP_CLK_TIMEBASE_MASTER_TIMEBASE_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        4872: {
            'access': 'read-write',
            'name': 'SAMP_CLK_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4880: {
            'access': 'read-write',
            'name': 'SAMP_QUANT_SAMP_PER_CHAN',
            'resettable': True,
            'type': 'uInt64'
        },
        4885: {
            'access': 'read-write',
            'name': 'REF_CLK_RATE',
            'resettable': True,
            'type': 'float64'
        },
        4886: {
            'access': 'read-write',
            'name': 'REF_CLK_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4887: {
            'access': 'read-write',
            'name': 'DELAY_FROM_SAMP_CLK_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        4917: {
            'access': 'read-write',
            'name': 'AI_CONV_TIMEBASE_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        4921: {
            'access': 'read-write',
            'enum': 'MIOAIConvertTbSrc',
            'name': 'AI_CONV_TIMEBASE_SRC',
            'resettable': True,
            'type': 'int32'
        },
        4931: {
            'access': 'read-write',
            'name': 'MASTER_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4932: {
            'access': 'read-write',
            'name': 'SAMP_CLK_RATE',
            'resettable': True,
            'type': 'float64'
        },
        4935: {
            'access': 'read-write',
            'enum': 'SampleTimingType',
            'name': 'SAMP_TIMING_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        5269: {
            'access': 'read-write',
            'name': 'MASTER_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        5378: {
            'access': 'read-write',
            'name': 'AI_CONV_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        6216: {
            'access': 'read-write',
            'name': 'AI_CONV_RATE',
            'resettable': True,
            'type': 'float64'
        },
        6226: {
            'access': 'read-write',
            'name': 'SAMP_CLK_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        6227: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'AI_CONV_ACTIVE_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        6379: {
            'access': 'read-write',
            'name': 'SAMP_CLK_TIMEBASE_DIV',
            'resettable': True,
            'type': 'uInt32'
        },
        6380: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'SAMP_CLK_TIMEBASE_ACTIVE_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        8597: {
            'access': 'read-write',
            'name': 'CHANGE_DETECT_DI_RISING_EDGE_PHYSICAL_CHANS',
            'resettable': True,
            'type': 'char[]'
        },
        8598: {
            'access': 'read-write',
            'name': 'CHANGE_DETECT_DI_FALLING_EDGE_PHYSICAL_CHANS',
            'resettable': True,
            'type': 'char[]'
        },
        8608: {
            'access': 'read-write',
            'name': 'ON_DEMAND_SIMULTANEOUS_AO_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8734: {
            'access': 'read-write',
            'name': 'SAMP_CLK_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8735: {
            'access': 'read-write',
            'name': 'SAMP_CLK_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8736: {
            'access': 'read-write',
            'name': 'SAMP_CLK_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8737: {
            'access': 'read-write',
            'name': 'SAMP_CLK_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8738: {
            'access': 'read-write',
            'name': 'SAMP_CLK_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8765: {
            'access': 'read-write',
            'name': 'SYNC_PULSE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8766: {
            'access': 'read',
            'name': 'SYNC_PULSE_SYNC_TIME',
            'resettable': False,
            'type': 'float64'
        },
        8767: {
            'access': 'read-write',
            'name': 'SYNC_PULSE_MIN_DELAY_TO_START',
            'resettable': True,
            'type': 'float64'
        },
        8898: {
            'access': 'read-write',
            'name': 'HSHK_DELAY_AFTER_XFER',
            'resettable': True,
            'type': 'float64'
        },
        8899: {
            'access': 'read-write',
            'enum': 'HandshakeStartCondition',
            'name': 'HSHK_START_COND',
            'resettable': True,
            'type': 'int32'
        },
        8900: {
            'access': 'read-write',
            'enum': 'SampleInputDataWhen',
            'name': 'HSHK_SAMPLE_INPUT_DATA_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        8904: {
            'access': 'read',
            'name': 'SAMP_CLK_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        8905: {
            'access': 'read',
            'name': 'AI_CONV_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10593: {
            'access': 'read-write',
            'enum': 'UnderflowBehavior',
            'name': 'SAMP_CLK_UNDERFLOW_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        10790: {
            'access': 'read-write',
            'name': 'SAMP_TIMING_ENGINE',
            'resettable': True,
            'type': 'uInt32'
        },
        11996: {
            'access': 'read-write',
            'name': 'AI_CONV_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        11997: {
            'access': 'read-write',
            'name': 'AI_CONV_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        11998: {
            'access': 'read-write',
            'name': 'AI_CONV_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        11999: {
            'access': 'read-write',
            'name': 'AI_CONV_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12000: {
            'access': 'read-write',
            'name': 'AI_CONV_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12026: {
            'access': 'read-write',
            'name': 'CHANGE_DETECT_DI_TRISTATE',
            'resettable': True,
            'type': 'bool32'
        },
        12028: {
            'access': 'read-write',
            'enum': 'OverflowBehavior',
            'name': 'SAMP_CLK_OVERRUN_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12029: {
            'access': 'read-write',
            'enum': 'UnderflowBehavior',
            'name': 'IMPLICIT_UNDERFLOW_BEHAVIOR',
            'resettable': True,
            'type': 'int32'
        },
        12059: {
            'access': 'read',
            'name': 'SAMP_CLK_TERM',
            'resettable': False,
            'type': 'char[]'
        },
        12060: {
            'access': 'read',
            'name': 'SAMP_CLK_TIMEBASE_TERM',
            'resettable': False,
            'type': 'char[]'
        },
        12156: {
            'access': 'read',
            'name': 'SYNC_PULSE_RESET_TIME',
            'resettable': False,
            'type': 'float64'
        },
        12157: {
            'access': 'read-write',
            'name': 'SYNC_PULSE_RESET_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        12158: {
            'access': 'read-write',
            'name': 'SYNC_CLK_INTERVAL',
            'resettable': True,
            'type': 'uInt32'
        },
        12165: {
            'access': 'read',
            'name': 'SYNC_PULSE_TERM',
            'resettable': False,
            'type': 'char[]'
        },
        12474: {
            'access': 'read-write',
            'name': 'TIMING_SYNC_PULSE_FORCE',
            'resettable': True,
            'type': 'bool32'
        },
        12540: {
            'access': 'read-write',
            'name': 'SAMP_CLK_WRITE_WFM_USE_INITIAL_WFM_DT',
            'resettable': True,
            'type': 'bool32'
        },
        12598: {
            'access': 'read-write',
            'enum': 'SyncPulseType',
            'name': 'SYNC_PULSE_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12599: {
            'access': 'read-write',
            'name': 'SYNC_PULSE_TIME_WHEN',
            'resettable': True,
            'type': 'CVIAbsoluteTime'
        },
        12600: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'SYNC_PULSE_TIME_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12601: {
            'access': 'read-write',
            'name': 'FIRST_SAMP_TIMESTAMP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12602: {
            'access': 'read',
            'name': 'FIRST_SAMP_TIMESTAMP_VAL',
            'resettable': False,
            'type': 'CVIAbsoluteTime'
        },
        12603: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'FIRST_SAMP_TIMESTAMP_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12674: {
            'access': 'read-write',
            'name': 'FIRST_SAMP_CLK_WHEN',
            'resettable': True,
            'type': 'CVIAbsoluteTime'
        },
        12675: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'FIRST_SAMP_CLK_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12714: {
            'access': 'read-write',
            'name': 'FIRST_SAMP_CLK_OFFSET',
            'resettable': True,
            'type': 'float64'
        }
    },
    'Trigger': {
        4960: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'DIG_EDGE_ADV_TRIG_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        4962: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ADV_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4965: {
            'access': 'read-write',
            'enum': 'TriggerType5',
            'name': 'ADV_TRIG_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        4966: {
            'access': 'read-write',
            'enum': 'TriggerType6',
            'name': 'PAUSE_TRIG_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        4968: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_HYST',
            'resettable': True,
            'type': 'float64'
        },
        4969: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_LVL',
            'resettable': True,
            'type': 'float64'
        },
        4976: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4977: {
            'access': 'read-write',
            'enum': 'ActiveLevel',
            'name': 'ANLG_LVL_PAUSE_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        4979: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4980: {
            'access': 'read-write',
            'enum': 'WindowTriggerCondition2',
            'name': 'ANLG_WIN_PAUSE_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        4981: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_BTM',
            'resettable': True,
            'type': 'float64'
        },
        4982: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_TOP',
            'resettable': True,
            'type': 'float64'
        },
        4985: {
            'access': 'read-write',
            'name': 'DIG_LVL_PAUSE_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        4992: {
            'access': 'read-write',
            'enum': 'Level1',
            'name': 'DIG_LVL_PAUSE_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        5011: {
            'access': 'read-write',
            'enum': 'TriggerType10',
            'name': 'START_TRIG_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        5013: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_HYST',
            'resettable': True,
            'type': 'float64'
        },
        5014: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_LVL',
            'resettable': True,
            'type': 'float64'
        },
        5015: {
            'access': 'read-write',
            'enum': 'Slope1',
            'name': 'ANLG_EDGE_START_TRIG_SLOPE',
            'resettable': True,
            'type': 'int32'
        },
        5016: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5120: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5121: {
            'access': 'read-write',
            'enum': 'WindowTriggerCondition1',
            'name': 'ANLG_WIN_START_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        5122: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_BTM',
            'resettable': True,
            'type': 'float64'
        },
        5123: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_TOP',
            'resettable': True,
            'type': 'float64'
        },
        5124: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'DIG_EDGE_START_TRIG_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        5127: {
            'access': 'read-write',
            'name': 'DIG_EDGE_START_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5136: {
            'access': 'read-write',
            'name': 'DIG_PATTERN_START_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5137: {
            'access': 'read-write',
            'enum': 'DigitalPatternCondition1',
            'name': 'DIG_PATTERN_START_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        5140: {
            'access': 'read-write',
            'enum': 'TriggerType4',
            'name': 'ARM_START_TRIG_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        5141: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'DIG_EDGE_ARM_START_TRIG_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        5143: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ARM_START_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5145: {
            'access': 'read-write',
            'enum': 'TriggerType8',
            'name': 'REF_TRIG_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        5153: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_HYST',
            'resettable': True,
            'type': 'float64'
        },
        5154: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_LVL',
            'resettable': True,
            'type': 'float64'
        },
        5155: {
            'access': 'read-write',
            'enum': 'Slope1',
            'name': 'ANLG_EDGE_REF_TRIG_SLOPE',
            'resettable': True,
            'type': 'int32'
        },
        5156: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5158: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5159: {
            'access': 'read-write',
            'enum': 'WindowTriggerCondition1',
            'name': 'ANLG_WIN_REF_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        5160: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_BTM',
            'resettable': True,
            'type': 'float64'
        },
        5161: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_TOP',
            'resettable': True,
            'type': 'float64'
        },
        5168: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'DIG_EDGE_REF_TRIG_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        5172: {
            'access': 'read-write',
            'name': 'DIG_EDGE_REF_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5175: {
            'access': 'read-write',
            'name': 'DIG_PATTERN_REF_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        5176: {
            'access': 'read-write',
            'enum': 'DigitalPatternCondition1',
            'name': 'DIG_PATTERN_REF_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        5189: {
            'access': 'read-write',
            'name': 'REF_TRIG_PRETRIG_SAMPLES',
            'resettable': True,
            'type': 'uInt32'
        },
        5251: {
            'access': 'read-write',
            'name': 'REF_TRIG_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        6230: {
            'access': 'read-write',
            'name': 'START_TRIG_DELAY',
            'resettable': True,
            'type': 'float64'
        },
        6231: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_WIN_REF_TRIG_COUPLING',
            'resettable': True,
            'type': 'int32'
        },
        6344: {
            'access': 'read-write',
            'enum': 'DigitalWidthUnits1',
            'name': 'START_TRIG_DELAY_UNITS',
            'resettable': True,
            'type': 'int32'
        },
        6415: {
            'access': 'read-write',
            'name': 'START_TRIG_RETRIGGERABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8559: {
            'access': 'read-write',
            'name': 'DIG_PATTERN_PAUSE_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8560: {
            'access': 'read-write',
            'enum': 'DigitalPatternCondition1',
            'name': 'DIG_PATTERN_PAUSE_TRIG_WHEN',
            'resettable': True,
            'type': 'int32'
        },
        8582: {
            'access': 'read-write',
            'name': 'DIG_PATTERN_START_TRIG_PATTERN',
            'resettable': True,
            'type': 'char[]'
        },
        8583: {
            'access': 'read-write',
            'name': 'DIG_PATTERN_REF_TRIG_PATTERN',
            'resettable': True,
            'type': 'char[]'
        },
        8584: {
            'access': 'read-write',
            'name': 'DIG_PATTERN_PAUSE_TRIG_PATTERN',
            'resettable': True,
            'type': 'char[]'
        },
        8739: {
            'access': 'read-write',
            'name': 'DIG_EDGE_START_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8740: {
            'access': 'read-write',
            'name': 'DIG_EDGE_START_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8741: {
            'access': 'read-write',
            'name': 'DIG_EDGE_START_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8742: {
            'access': 'read-write',
            'name': 'DIG_EDGE_START_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8743: {
            'access': 'read-write',
            'name': 'DIG_EDGE_START_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8744: {
            'access': 'read-write',
            'name': 'DIG_LVL_PAUSE_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8745: {
            'access': 'read-write',
            'name': 'DIG_LVL_PAUSE_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8746: {
            'access': 'read-write',
            'name': 'DIG_LVL_PAUSE_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8747: {
            'access': 'read-write',
            'name': 'DIG_LVL_PAUSE_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8748: {
            'access': 'read-write',
            'name': 'DIG_LVL_PAUSE_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8749: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ARM_START_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8750: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ARM_START_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        8751: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ARM_START_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8752: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ARM_START_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        8753: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ARM_START_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8755: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_EDGE_START_TRIG_COUPLING',
            'resettable': True,
            'type': 'int32'
        },
        8756: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_WIN_START_TRIG_COUPLING',
            'resettable': True,
            'type': 'int32'
        },
        8757: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_EDGE_REF_TRIG_COUPLING',
            'resettable': True,
            'type': 'int32'
        },
        8758: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_LVL_PAUSE_TRIG_COUPLING',
            'resettable': True,
            'type': 'int32'
        },
        8759: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_WIN_PAUSE_TRIG_COUPLING',
            'resettable': True,
            'type': 'int32'
        },
        8760: {
            'access': 'read-write',
            'name': 'DIG_EDGE_ADV_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        8887: {
            'access': 'read-write',
            'enum': 'TriggerType9',
            'name': 'HSHK_TRIG_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        8888: {
            'access': 'read-write',
            'name': 'INTERLOCKED_HSHK_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8889: {
            'access': 'read-write',
            'enum': 'Level1',
            'name': 'INTERLOCKED_HSHK_TRIG_ASSERTED_LVL',
            'resettable': True,
            'type': 'int32'
        },
        11969: {
            'access': 'read-write',
            'name': 'REF_TRIG_AUTO_TRIG_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        11970: {
            'access': 'read',
            'name': 'REF_TRIG_AUTO_TRIGGERED',
            'resettable': False,
            'type': 'bool32'
        },
        11991: {
            'access': 'read-write',
            'name': 'DIG_EDGE_REF_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        11992: {
            'access': 'read-write',
            'name': 'DIG_EDGE_REF_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        11993: {
            'access': 'read-write',
            'name': 'DIG_EDGE_REF_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        11994: {
            'access': 'read-write',
            'name': 'DIG_EDGE_REF_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        11995: {
            'access': 'read-write',
            'name': 'DIG_EDGE_REF_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12001: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12002: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12003: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12004: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12005: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_START_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12006: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12007: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12008: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12009: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12010: {
            'access': 'read-write',
            'name': 'ANLG_EDGE_REF_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12011: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12012: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12013: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12014: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12015: {
            'access': 'read-write',
            'name': 'ANLG_WIN_REF_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12016: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12017: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12018: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12019: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12020: {
            'access': 'read-write',
            'name': 'ANLG_LVL_PAUSE_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12021: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12022: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12023: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12024: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12025: {
            'access': 'read-write',
            'name': 'ANLG_WIN_PAUSE_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12031: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_DIG_FLTR_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12032: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_DIG_FLTR_MIN_PULSE_WIDTH',
            'resettable': True,
            'type': 'float64'
        },
        12033: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_DIG_FLTR_TIMEBASE_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12034: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_DIG_FLTR_TIMEBASE_RATE',
            'resettable': True,
            'type': 'float64'
        },
        12035: {
            'access': 'read-write',
            'name': 'ANLG_WIN_START_TRIG_DIG_SYNC_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12062: {
            'access': 'read',
            'name': 'START_TRIG_TERM',
            'resettable': False,
            'type': 'char[]'
        },
        12063: {
            'access': 'read',
            'name': 'REF_TRIG_TERM',
            'resettable': False,
            'type': 'char[]'
        },
        12064: {
            'access': 'read',
            'name': 'PAUSE_TRIG_TERM',
            'resettable': False,
            'type': 'char[]'
        },
        12159: {
            'access': 'read',
            'name': 'ARM_START_TERM',
            'resettable': False,
            'type': 'char[]'
        },
        12160: {
            'access': 'read-write',
            'enum': 'SyncType',
            'name': 'TRIGGER_SYNC_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12317: {
            'access': 'read-write',
            'name': 'TIME_START_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        12342: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'START_TRIG_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12365: {
            'access': 'read-write',
            'name': 'START_TRIG_TRIG_WHEN',
            'resettable': True,
            'type': 'CVIAbsoluteTime'
        },
        12570: {
            'access': 'read-write',
            'name': 'START_TRIG_TRIG_WIN',
            'resettable': True,
            'type': 'float64'
        },
        12571: {
            'access': 'read-write',
            'name': 'START_TRIG_RETRIGGER_WIN',
            'resettable': True,
            'type': 'float64'
        },
        12572: {
            'access': 'read-write',
            'name': 'START_TRIG_MAX_NUM_TRIGS_TO_DETECT',
            'resettable': True,
            'type': 'uInt32'
        },
        12573: {
            'access': 'read-write',
            'name': 'REF_TRIG_RETRIGGERABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12574: {
            'access': 'read-write',
            'name': 'REF_TRIG_TRIG_WIN',
            'resettable': True,
            'type': 'float64'
        },
        12575: {
            'access': 'read-write',
            'name': 'REF_TRIG_RETRIGGER_WIN',
            'resettable': True,
            'type': 'float64'
        },
        12576: {
            'access': 'read-write',
            'name': 'REF_TRIG_MAX_NUM_TRIGS_TO_DETECT',
            'resettable': True,
            'type': 'uInt32'
        },
        12577: {
            'access': 'read-write',
            'name': 'ANLG_MULTI_EDGE_START_TRIG_SRCS',
            'resettable': True,
            'type': 'char[]'
        },
        12578: {
            'access': 'read-write',
            'enum': 'Slope1',
            'name': 'ANLG_MULTI_EDGE_START_TRIG_SLOPES',
            'resettable': True,
            'type': 'int32[]'
        },
        12579: {
            'access': 'read-write',
            'name': 'ANLG_MULTI_EDGE_START_TRIG_LVLS',
            'resettable': True,
            'type': 'float64[]'
        },
        12580: {
            'access': 'read-write',
            'name': 'ANLG_MULTI_EDGE_START_TRIG_HYSTS',
            'resettable': True,
            'type': 'float64[]'
        },
        12581: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_MULTI_EDGE_START_TRIG_COUPLINGS',
            'resettable': True,
            'type': 'int32[]'
        },
        12582: {
            'access': 'read-write',
            'name': 'ANLG_MULTI_EDGE_REF_TRIG_SRCS',
            'resettable': True,
            'type': 'char[]'
        },
        12583: {
            'access': 'read-write',
            'enum': 'Slope1',
            'name': 'ANLG_MULTI_EDGE_REF_TRIG_SLOPES',
            'resettable': True,
            'type': 'int32[]'
        },
        12584: {
            'access': 'read-write',
            'name': 'ANLG_MULTI_EDGE_REF_TRIG_LVLS',
            'resettable': True,
            'type': 'float64[]'
        },
        12585: {
            'access': 'read-write',
            'name': 'ANLG_MULTI_EDGE_REF_TRIG_HYSTS',
            'resettable': True,
            'type': 'float64[]'
        },
        12586: {
            'access': 'read-write',
            'enum': 'Coupling2',
            'name': 'ANLG_MULTI_EDGE_REF_TRIG_COUPLINGS',
            'resettable': True,
            'type': 'int32[]'
        },
        12589: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'START_TRIG_TIMESTAMP_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12590: {
            'access': 'read-write',
            'name': 'REF_TRIG_TIMESTAMP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12591: {
            'access': 'read',
            'name': 'REF_TRIG_TIMESTAMP_VAL',
            'resettable': False,
            'type': 'CVIAbsoluteTime'
        },
        12592: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'REF_TRIG_TIMESTAMP_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12593: {
            'access': 'read-write',
            'name': 'ARM_START_TRIG_TRIG_WHEN',
            'resettable': True,
            'type': 'CVIAbsoluteTime'
        },
        12594: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'ARM_START_TRIG_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12595: {
            'access': 'read-write',
            'name': 'ARM_START_TRIG_TIMESTAMP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12596: {
            'access': 'read',
            'name': 'ARM_START_TRIG_TIMESTAMP_VAL',
            'resettable': False,
            'type': 'CVIAbsoluteTime'
        },
        12597: {
            'access': 'read-write',
            'enum': 'Timescale2',
            'name': 'ARM_START_TRIG_TIMESTAMP_TIMESCALE',
            'resettable': True,
            'type': 'int32'
        },
        12618: {
            'access': 'read-write',
            'name': 'START_TRIG_TIMESTAMP_ENABLE',
            'resettable': True,
            'type': 'bool32'
        },
        12619: {
            'access': 'read',
            'name': 'START_TRIG_TIMESTAMP_VAL',
            'resettable': False,
            'type': 'CVIAbsoluteTime'
        }
    },
    'Watchdog': {
        8611: {
            'access': 'read-write',
            'enum': 'TriggerType4',
            'name': 'EXPIR_TRIG_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        8612: {
            'access': 'read-write',
            'name': 'DIG_EDGE_WATCHDOG_EXPIR_TRIG_SRC',
            'resettable': True,
            'type': 'char[]'
        },
        8613: {
            'access': 'read-write',
            'enum': 'Edge1',
            'name': 'DIG_EDGE_WATCHDOG_EXPIR_TRIG_EDGE',
            'resettable': True,
            'type': 'int32'
        },
        8615: {
            'access': 'read-write',
            'enum': 'DigitalLineState',
            'name': 'DO_EXPIR_STATE',
            'resettable': True,
            'type': 'int32'
        },
        8616: {
            'access': 'read',
            'name': 'HAS_EXPIRED',
            'resettable': False,
            'type': 'bool32'
        },
        8617: {
            'access': 'read-write',
            'name': 'TIMEOUT',
            'resettable': True,
            'type': 'float64'
        },
        12381: {
            'access': 'read-write',
            'name': 'EXPIR_TRIG_TRIG_ON_NETWORK_CONN_LOSS',
            'resettable': True,
            'type': 'bool32'
        },
        12382: {
            'access': 'read-write',
            'enum': 'WatchdogAOExpirState',
            'name': 'AO_OUTPUT_TYPE',
            'resettable': True,
            'type': 'int32'
        },
        12383: {
            'access': 'read-write',
            'name': 'AO_EXPIR_STATE',
            'resettable': True,
            'type': 'float64'
        },
        12384: {
            'access': 'read-write',
            'enum': 'WatchdogCOExpirState',
            'name': 'CO_EXPIR_STATE',
            'resettable': True,
            'type': 'int32'
        }
    },
    'Write': {
        5203: {
            'access': 'read-write',
            'enum': 'RegenerationMode1',
            'name': 'REGEN_MODE',
            'resettable': True,
            'type': 'int32'
        },
        5208: {
            'access': 'read',
            'name': 'CURR_WRITE_POS',
            'resettable': False,
            'type': 'uInt64'
        },
        5216: {
            'access': 'read',
            'name': 'SPACE_AVAIL',
            'resettable': False,
            'type': 'uInt32'
        },
        6412: {
            'access': 'read-write',
            'enum': 'WriteRelativeTo',
            'name': 'RELATIVE_TO',
            'resettable': True,
            'type': 'int32'
        },
        6413: {
            'access': 'read-write',
            'name': 'OFFSET',
            'resettable': True,
            'type': 'int32'
        },
        6443: {
            'access': 'read',
            'name': 'TOTAL_SAMP_PER_CHAN_GENERATED',
            'resettable': False,
            'type': 'uInt64'
        },
        8573: {
            'access': 'read',
            'name': 'RAW_DATA_WIDTH',
            'resettable': False,
            'type': 'uInt32'
        },
        8574: {
            'access': 'read',
            'name': 'NUM_CHANS',
            'resettable': False,
            'type': 'uInt32'
        },
        8575: {
            'access': 'read',
            'name': 'DIGITAL_LINES_BYTES_PER_CHAN',
            'resettable': False,
            'type': 'uInt32'
        },
        8881: {
            'access': 'read-write',
            'enum': 'WaitMode2',
            'name': 'WAIT_MODE',
            'resettable': True,
            'type': 'int32'
        },
        8882: {
            'access': 'read-write',
            'name': 'SLEEP_TIME',
            'resettable': True,
            'type': 'float64'
        },
        10604: {
            'access': 'read-write',
            'name': 'NEXT_WRITE_IS_LAST',
            'resettable': True,
            'type': 'bool32'
        },
        10728: {
            'access': 'read',
            'name': 'OVERCURRENT_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        10729: {
            'access': 'read',
            'name': 'OVERCURRENT_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        10730: {
            'access': 'read',
            'name': 'OPEN_CURRENT_LOOP_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        10731: {
            'access': 'read',
            'name': 'OPEN_CURRENT_LOOP_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        10732: {
            'access': 'read',
            'name': 'POWER_SUPPLY_FAULT_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        10733: {
            'access': 'read',
            'name': 'POWER_SUPPLY_FAULT_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        10884: {
            'access': 'read',
            'name': 'OVERTEMPERATURE_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12371: {
            'access': 'read',
            'name': 'ACCESSORY_INSERTION_OR_REMOVAL_DETECTED',
            'resettable': False,
            'type': 'bool32'
        },
        12372: {
            'access': 'read',
            'name': 'DEVS_WITH_INSERTED_OR_REMOVED_ACCESSORIES',
            'resettable': False,
            'type': 'char[]'
        },
        12419: {
            'access': 'read',
            'name': 'OVERTEMPERATURE_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12420: {
            'access': 'read',
            'name': 'OVERLOADED_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12421: {
            'access': 'read',
            'name': 'OVERLOADED_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12475: {
            'access': 'read',
            'name': 'EXTERNAL_OVERVOLTAGE_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12476: {
            'access': 'read',
            'name': 'EXTERNAL_OVERVOLTAGE_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12607: {
            'access': 'read',
            'name': 'SYNC_UNLOCKED_CHANS_EXIST',
            'resettable': False,
            'type': 'bool32'
        },
        12608: {
            'access': 'read',
            'name': 'SYNC_UNLOCKED_CHANS',
            'resettable': False,
            'type': 'char[]'
        }
    }
}