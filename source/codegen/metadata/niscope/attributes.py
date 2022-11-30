# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 23.0.0d87
attributes = {
    1050002: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'RANGE_CHECK',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1050003: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'QUERY_INSTRUMENT_STATUS',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1050004: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'CACHE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1050005: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SIMULATE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1050006: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'RECORD_COERCIONS',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1050007: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DRIVER_SETUP',
        'resettable': False,
        'type': 'ViString'
    },
    1050021: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'INTERCHANGE_CHECK',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1050203: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CHANNEL_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050302: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_PREFIX',
        'resettable': False,
        'type': 'ViString'
    },
    1050304: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'IO_RESOURCE_DESCRIPTOR',
        'resettable': False,
        'type': 'ViString'
    },
    1050305: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'LOGICAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1050327: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SUPPORTED_INSTRUMENT_MODELS',
        'resettable': False,
        'type': 'ViString'
    },
    1050401: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'GROUP_CAPABILITIES',
        'resettable': False,
        'type': 'ViString'
    },
    1050510: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'INSTRUMENT_FIRMWARE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1050511: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'INSTRUMENT_MANUFACTURER',
        'resettable': False,
        'type': 'ViString'
    },
    1050512: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'INSTRUMENT_MODEL',
        'resettable': False,
        'type': 'ViString'
    },
    1050513: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_VENDOR',
        'resettable': False,
        'type': 'ViString'
    },
    1050514: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_DESCRIPTION',
        'resettable': False,
        'type': 'ViString'
    },
    1050515: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050516: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050551: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150001: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'HORZ_NUM_RECORDS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150002: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'INPUT_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150003: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'OUTPUT_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150004: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'HORZ_ENFORCE_REALTIME',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150005: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'BINARY_SAMPLE_WIDTH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150006: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TRIGGER_HYSTERESIS',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150007: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'CLOCK_SYNC_PULSE_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150008: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'MASTER_ENABLE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150009: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MIN_SAMPLE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150012: {
        'codegen_method': 'public',
        'enum': 'TriggerWindowMode',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_WINDOW_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150013: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TRIGGER_WINDOW_LOW_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150014: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TRIGGER_WINDOW_HIGH_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150016: {
        'codegen_method': 'public',
        'enum': 'MeasRefLevelUnits',
        'grpc_type': 'sint32',
        'name': 'MEAS_REF_LEVEL_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150018: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MEAS_OTHER_CHANNEL',
        'resettable': True,
        'type': 'ViString'
    },
    1150019: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_HYSTERESIS_PERCENT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150020: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEAS_LAST_ACQ_HISTOGRAM_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150021: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEAS_VOLTAGE_HISTOGRAM_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150022: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_VOLTAGE_HISTOGRAM_LOW_VOLTS',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150023: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_VOLTAGE_HISTOGRAM_HIGH_VOLTS',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150024: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEAS_TIME_HISTOGRAM_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150025: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_TIME_HISTOGRAM_LOW_VOLTS',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150026: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_TIME_HISTOGRAM_HIGH_VOLTS',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150027: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_TIME_HISTOGRAM_LOW_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150028: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_TIME_HISTOGRAM_HIGH_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150029: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEAS_POLYNOMIAL_INTERPOLATION_ORDER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150030: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_INTERPOLATION_SAMPLING_FACTOR',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150031: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_FILTER_CUTOFF_FREQ',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150032: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_FILTER_CENTER_FREQ',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150033: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_FILTER_RIPPLE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150034: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_FILTER_TRANSIENT_WAVEFORM_PERCENT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150035: {
        'codegen_method': 'public',
        'enum': 'MeasFilterType',
        'grpc_type': 'sint32',
        'name': 'MEAS_FILTER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150036: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEAS_FILTER_ORDER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150037: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEAS_FILTER_TAPS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150038: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_CHAN_LOW_REF_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150039: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_CHAN_MID_REF_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150040: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_CHAN_HIGH_REF_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150041: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_FILTER_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150042: {
        'codegen_method': 'public',
        'enum': 'FIRFilterWindow',
        'grpc_type': 'sint32',
        'name': 'MEAS_FIR_FILTER_WINDOW',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150043: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_ARRAY_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150044: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_ARRAY_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150045: {
        'codegen_method': 'public',
        'enum': 'MeasPercentageMethod',
        'grpc_type': 'sint32',
        'name': 'MEAS_PERCENTAGE_METHOD',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150053: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ACQ_ARM_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150066: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IS_PROBE_COMP_ON',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150067: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'USE_SPEC_INITIAL_X',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150068: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ALLOW_MORE_RECORDS_THAN_MEMORY',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150069: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ONBOARD_MEMORY_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150070: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'RIS_NUM_AVERAGES',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150071: {
        'codegen_method': 'public',
        'enum': 'RISMethod',
        'grpc_type': 'sint32',
        'name': 'RIS_METHOD',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150072: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'FETCH_INTERLEAVED_DATA',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150073: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_REAL_TIME_SAMPLING_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150074: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_RIS_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150075: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TRIGGER_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150076: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DEVICE_NUMBER',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150077: {
        'codegen_method': 'public',
        'enum': 'FetchRelativeTo',
        'grpc_type': 'sint32',
        'name': 'FETCH_RELATIVE_TO',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150078: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FETCH_OFFSET',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150079: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FETCH_RECORD_NUMBER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150080: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FETCH_NUM_RECORDS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150081: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FETCH_MEAS_NUM_SAMPLES',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150082: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'POINTS_DONE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150083: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'RECORDS_DONE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150084: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'BACKLOG',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150086: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEVICE_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150087: {
        'codegen_method': 'public',
        'enum': 'SampClkTimepaceSrc',
        'grpc_type': 'string',
        'name': 'SAMP_CLK_TIMEBASE_SRC',
        'resettable': True,
        'type': 'ViString'
    },
    1150088: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SAMP_CLK_TIMEBASE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150089: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SAMP_CLK_TIMEBASE_DIV',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150090: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REF_CLK_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150091: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150093: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ENABLE_DC_RESTORE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150094: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ADV_TRIG_SRC',
        'resettable': True,
        'type': 'ViString'
    },
    1150095: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ARM_REF_TRIG_SRC',
        'resettable': True,
        'type': 'ViString'
    },
    1150096: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'REF_TRIG_TDC_ENABLE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150097: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150098: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150099: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'END_OF_RECORD_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150100: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'POLL_INTERVAL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150101: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'END_OF_ACQUISITION_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150102: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'RESOLUTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150103: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'START_TO_REF_TRIGGER_HOLDOFF',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150104: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150105: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'OSCILLATOR_PHASE_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150106: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'RIS_IN_AUTO_SETUP_ENABLE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150107: {
        'codegen_method': 'public',
        'enum': 'TerminalConfiguration',
        'grpc_type': 'sint32',
        'name': 'CHANNEL_TERMINAL_CONFIGURATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150109: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150110: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_START_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150111: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_REF_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150112: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150128: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ENABLE_TIME_INTERLEAVED_SAMPLING',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150129: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': '5V_OUT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150132: {
        'codegen_method': 'public',
        'enum': 'RuntTimeCondition',
        'grpc_type': 'sint32',
        'name': 'RUNT_TIME_CONDITION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150133: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RUNT_TIME_LOW_LIMIT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150134: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RUNT_TIME_HIGH_LIMIT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150137: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CABLE_SENSE_VOLTAGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150138: {
        'codegen_method': 'public',
        'enum': 'CableSenseMode',
        'grpc_type': 'double',
        'name': 'CABLE_SENSE_MODE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150139: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'CABLE_SENSE_SIGNAL_ENABLE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150140: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ENABLED_CHANNELS',
        'resettable': False,
        'type': 'ViString'
    },
    1150141: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'END_OF_ACQUISITION_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150142: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'END_OF_RECORD_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150143: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ADVANCE_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150144: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'REF_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150145: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'START_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150146: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_ADVANCE_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150147: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_REF_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150148: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_START_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150271: {
        'codegen_method': 'public',
        'enum': 'FlexFIRAntialiasFilterType',
        'grpc_type': 'sint32',
        'name': 'FLEX_FIR_ANTIALIAS_FILTER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150278: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'TRIGGER_AUTO_TRIGGERED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150279: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SIGNAL_COND_GAIN',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150280: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SIGNAL_COND_OFFSET',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150300: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DDC_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150302: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DDC_FREQUENCY_TRANSLATION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150303: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DDC_CENTER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150304: {
        'codegen_method': 'public',
        'enum': 'DataProcessingMode',
        'grpc_type': 'sint32',
        'name': 'DDC_DATA_PROCESSING_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150305: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DDC_FREQUENCY_TRANSLATION_PHASE_I',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150306: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DDC_FREQUENCY_TRANSLATION_PHASE_Q',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150307: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150308: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITAL_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150309: {
        'codegen_method': 'public',
        'enum': 'OverflowErrorReporting',
        'grpc_type': 'sint32',
        'name': 'OVERFLOW_ERROR_REPORTING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150310: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DDC_Q_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150311: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'FETCH_INTERLEAVED_IQ_DATA',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150312: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'EQUALIZATION_NUM_COEFFICIENTS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150313: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'EQUALIZATION_FILTER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150314: {
        'codegen_method': 'public',
        'enum': 'RefTriggerDetectorLocation',
        'grpc_type': 'sint32',
        'name': 'REF_TRIGGER_DETECTOR_LOCATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150315: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REF_TRIGGER_MINIMUM_QUIET_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150316: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150318: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'BANDPASS_FILTER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150319: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DITHER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150320: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'FRACTIONAL_RESAMPLE_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150321: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150322: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_PREFERRED_PACKET_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150328: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_SAMPLES_AVAIL_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150329: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_DATA_TRANS_PERMISSION_ADDR',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150330: {
        'codegen_method': 'public',
        'enum': 'AddressType',
        'grpc_type': 'sint32',
        'name': 'P2P_DATA_TRANS_PERMISSION_ADDR_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150331: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_DESTINATION_WINDOW_ADDR',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150332: {
        'codegen_method': 'public',
        'enum': 'AddressType',
        'grpc_type': 'sint32',
        'name': 'P2P_DESTINATION_WINDOW_ADDR_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150333: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_DESTINATION_WINDOW_SIZE',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150334: {
        'codegen_method': 'public',
        'enum': 'NotificationType',
        'grpc_type': 'sint32',
        'name': 'P2P_NOTIFY_PUSH_MESSAGE_ON',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150335: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_NOTIFY_MESSAGE_PUSH_ADDR',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150336: {
        'codegen_method': 'public',
        'enum': 'AddressType',
        'grpc_type': 'sint32',
        'name': 'P2P_NOTIFY_MESSAGE_PUSH_ADDR_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150337: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_NOTIFY_MESSAGE_PUSH_VALUE',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150338: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150339: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'P2P_CHANNELS_TO_STREAM',
        'resettable': True,
        'type': 'ViString'
    },
    1150340: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_SAMPLES_TRANSFERRED',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150341: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_MOST_SAMPLES_AVAIL_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150342: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_ENDPOINT_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150343: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_MANUAL_CONFIGURATION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150344: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ENDPOINT_OVERFLOW',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150345: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_FIFO_ENDPOINT_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150354: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ONBOARD_MEMORY_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150366: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'END_OF_RECORD_TO_ADVANCE_TRIGGER_HOLDOFF',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150367: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SAMP_CLK_TIMEBASE_MULT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150373: {
        'codegen_method': 'public',
        'enum': 'P2PStreamRelativeTo',
        'grpc_type': 'sint32',
        'name': 'P2P_STREAM_RELATIVE_TO',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150374: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ABSOLUTE_SAMPLE_CLOCK_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150375: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FPGA_BITFILE_PATH',
        'resettable': False,
        'type': 'ViString'
    },
    1150376: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'INTERLEAVING_OFFSET_CORRECTION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150377: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'HIGH_PASS_FILTER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150380: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_SAMPLES_TRANSFERRED_PER_RECORD',
        'resettable': False,
        'type': 'ViInt32'
    },
    1151303: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'PLL_LOCK_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1250001: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VERTICAL_RANGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250002: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VERTICAL_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250003: {
        'codegen_method': 'public',
        'enum': 'VerticalCoupling',
        'grpc_type': 'sint32',
        'name': 'VERTICAL_COUPLING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250004: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PROBE_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250005: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'CHANNEL_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250006: {
        'codegen_method': 'public',
        'enum': 'MaxInputFrequency',
        'grpc_type': 'double',
        'name': 'MAX_INPUT_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250007: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'HORZ_TIME_PER_RECORD',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250008: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'HORZ_RECORD_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250009: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'HORZ_MIN_NUM_PTS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250010: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'HORZ_SAMPLE_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250011: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'HORZ_RECORD_REF_POSITION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250012: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250013: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'string',
        'name': 'TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1250014: {
        'codegen_method': 'public',
        'enum': 'TriggerCoupling',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_COUPLING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250015: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TRIGGER_DELAY_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250016: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TRIGGER_HOLDOFF',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250017: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TRIGGER_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250018: {
        'codegen_method': 'public',
        'enum': 'TriggerSlope',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_SLOPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250101: {
        'codegen_method': 'public',
        'enum': 'AcquisitionType',
        'grpc_type': 'sint32',
        'name': 'ACQUISITION_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250102: {
        'codegen_method': 'public',
        'enum': 'TriggerModifier',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_MODIFIER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250103: {
        'codegen_method': 'public',
        'enum': 'InputImpedance',
        'grpc_type': 'double',
        'name': 'INPUT_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250106: {
        'codegen_method': 'public',
        'enum': 'SampleMode',
        'grpc_type': 'sint32',
        'name': 'SAMPLE_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250109: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ACQUISITION_START_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250201: {
        'codegen_method': 'public',
        'enum': 'VideoSignalFormat',
        'grpc_type': 'sint32',
        'name': 'TV_TRIGGER_SIGNAL_FORMAT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250204: {
        'codegen_method': 'public',
        'enum': 'VideoPolarity',
        'grpc_type': 'sint32',
        'name': 'TV_TRIGGER_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250205: {
        'codegen_method': 'public',
        'enum': 'VideoTriggerEvent',
        'grpc_type': 'sint32',
        'name': 'TV_TRIGGER_EVENT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250206: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'TV_TRIGGER_LINE_NUMBER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250301: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RUNT_HIGH_THRESHOLD',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250302: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RUNT_LOW_THRESHOLD',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250303: {
        'codegen_method': 'public',
        'enum': 'RuntPolarity',
        'grpc_type': 'sint32',
        'name': 'RUNT_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250401: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'GLITCH_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250402: {
        'codegen_method': 'public',
        'enum': 'GlitchPolarity',
        'grpc_type': 'sint32',
        'name': 'GLITCH_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250403: {
        'codegen_method': 'public',
        'enum': 'GlitchCondition',
        'grpc_type': 'sint32',
        'name': 'GLITCH_CONDITION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250501: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WIDTH_LOW_THRESHOLD',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250502: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WIDTH_HIGH_THRESHOLD',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250503: {
        'codegen_method': 'public',
        'enum': 'WidthPolarity',
        'grpc_type': 'sint32',
        'name': 'WIDTH_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250504: {
        'codegen_method': 'public',
        'enum': 'WidthCondition',
        'grpc_type': 'sint32',
        'name': 'WIDTH_CONDITION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250607: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_HIGH_REF',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250608: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_LOW_REF',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250609: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEAS_MID_REF',
        'resettable': True,
        'type': 'ViReal64'
    }
}
