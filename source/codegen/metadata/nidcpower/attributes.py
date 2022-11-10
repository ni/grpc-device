# -*- coding: utf-8 -*-
# This file is generated from NI-DCPower API metadata version 23.0.0d288
attributes = {
    1050002: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'RANGE_CHECK',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050003: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'QUERY_INSTRUMENT_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050004: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'CACHE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050005: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SIMULATE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050006: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'RECORD_COERCIONS',
        'resettable': False,
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
        'resettable': False,
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
    1150000: {
        'codegen_method': 'public',
        'enum': 'PowerSource',
        'grpc_type': 'sint32',
        'name': 'POWER_SOURCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150001: {
        'codegen_method': 'public',
        'enum': 'PowerSourceInUse',
        'grpc_type': 'sint32',
        'name': 'POWER_SOURCE_IN_USE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150002: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'AUXILIARY_POWER_SOURCE_AVAILABLE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150003: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SAMPLES_TO_AVERAGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150004: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150005: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150006: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'RESET_AVERAGE_BEFORE_MEASUREMENT',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150007: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OVERRANGING_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150008: {
        'codegen_method': 'public',
        'enum': 'OutputFunction',
        'grpc_type': 'sint32',
        'name': 'OUTPUT_FUNCTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150009: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150010: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150011: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150012: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150013: {
        'codegen_method': 'public',
        'enum': 'Sense',
        'grpc_type': 'sint32',
        'name': 'SENSE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150014: {
        'codegen_method': 'public',
        'enum': 'OutputCapacitance',
        'grpc_type': 'sint32',
        'name': 'OUTPUT_CAPACITANCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150015: {
        'codegen_method': 'public',
        'enum': 'AutoZero',
        'grpc_type': 'sint32',
        'name': 'VOLTAGE_LEVEL_AUTORANGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150016: {
        'codegen_method': 'public',
        'enum': 'AutoZero',
        'grpc_type': 'sint32',
        'name': 'CURRENT_LIMIT_AUTORANGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150017: {
        'codegen_method': 'public',
        'enum': 'AutoZero',
        'grpc_type': 'sint32',
        'name': 'CURRENT_LEVEL_AUTORANGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150018: {
        'codegen_method': 'public',
        'enum': 'AutoZero',
        'grpc_type': 'sint32',
        'name': 'VOLTAGE_LIMIT_AUTORANGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150020: {
        'codegen_method': 'public',
        'enum': 'PowerLineFrequencies',
        'grpc_type': 'double',
        'name': 'POWER_LINE_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150021: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'START_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150022: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150023: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_START_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150024: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150025: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SEQUENCE_LOOP_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150026: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'SEQUENCE_ADVANCE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150027: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150028: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150029: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_SEQUENCE_ADVANCE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150030: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'SOURCE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150031: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_SOURCE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150032: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_SOURCE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150033: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_SOURCE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150034: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'MEASURE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150035: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_MEASURE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150036: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_MEASURE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150037: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_MEASURE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150038: {
        'codegen_method': 'public',
        'enum': 'Polarity',
        'grpc_type': 'sint32',
        'name': 'SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150039: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150040: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SEQUENCE_ITERATION_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150041: {
        'codegen_method': 'public',
        'enum': 'Polarity',
        'grpc_type': 'sint32',
        'name': 'SOURCE_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150042: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SOURCE_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150043: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SOURCE_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150044: {
        'codegen_method': 'public',
        'enum': 'Polarity',
        'grpc_type': 'sint32',
        'name': 'MEASURE_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150045: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEASURE_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150046: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEASURE_COMPLETE_EVENT_DELAY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150047: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MEASURE_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150048: {
        'codegen_method': 'public',
        'enum': 'Polarity',
        'grpc_type': 'sint32',
        'name': 'SEQUENCE_ENGINE_DONE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150049: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SEQUENCE_ENGINE_DONE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150050: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SEQUENCE_ENGINE_DONE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150051: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SOURCE_DELAY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150054: {
        'codegen_method': 'public',
        'enum': 'SourceMode',
        'grpc_type': 'sint32',
        'name': 'SOURCE_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150055: {
        'codegen_method': 'public',
        'enum': 'AutoZero',
        'grpc_type': 'sint32',
        'name': 'AUTO_ZERO',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150056: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FETCH_BACKLOG',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150057: {
        'codegen_method': 'public',
        'enum': 'MeasureWhen',
        'grpc_type': 'sint32',
        'name': 'MEASURE_WHEN',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150058: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'APERTURE_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150059: {
        'codegen_method': 'public',
        'enum': 'ApertureTimeUnits',
        'grpc_type': 'sint32',
        'name': 'APERTURE_TIME_UNITS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150060: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OUTPUT_CONNECTED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150061: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150062: {
        'codegen_method': 'public',
        'enum': 'TransientResponse',
        'grpc_type': 'sint32',
        'name': 'TRANSIENT_RESPONSE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150063: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEASURE_RECORD_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150064: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'MEASURE_RECORD_LENGTH_IS_FINITE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150065: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MEASURE_RECORD_DELTA_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150066: {
        'codegen_method': 'public',
        'enum': 'DCNoiseRejection',
        'grpc_type': 'sint32',
        'name': 'DC_NOISE_REJECTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150067: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_GAIN_BANDWIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150068: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_COMPENSATION_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150069: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_POLE_ZERO_RATIO',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150070: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_GAIN_BANDWIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150071: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_COMPENSATION_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150072: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_POLE_ZERO_RATIO',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150073: {
        'codegen_method': 'public',
        'enum': 'SelfCalibrationPersistence',
        'grpc_type': 'sint32',
        'name': 'SELF_CALIBRATION_PERSISTENCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150074: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ACTIVE_ADVANCED_SEQUENCE',
        'resettable': False,
        'type': 'ViString'
    },
    1150075: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'ACTIVE_ADVANCED_SEQUENCE_STEP',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150077: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEASURE_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150078: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SEQUENCE_LOOP_COUNT_IS_FINITE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150079: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SUPPORT_OUTPUT_DMA',
        'resettable': False,
        'type': 'bool'
    },
    1150080: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_VOLTAGE_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150081: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_CURRENT_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150082: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_VOLTAGE_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150083: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_CURRENT_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150084: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_VOLTAGE_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150085: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_CURRENT_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150086: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_CURRENT_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150087: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_VOLTAGE_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150088: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_CURRENT_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150089: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_VOLTAGE_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150090: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_CURRENT_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150091: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_VOLTAGE_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150092: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_DELAY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150093: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_ON_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150094: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_OFF_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150095: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'PULSE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150096: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_PULSE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150097: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_PULSE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150098: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_PULSE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150099: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'PULSE_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150100: {
        'codegen_method': 'public',
        'enum': 'Polarity',
        'grpc_type': 'sint32',
        'name': 'PULSE_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150101: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150102: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_PULSE_TRIGGER_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150103: {
        'codegen_method': 'public',
        'enum': 'Polarity',
        'grpc_type': 'sint32',
        'name': 'READY_FOR_PULSE_TRIGGER_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150104: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'READY_FOR_PULSE_TRIGGER_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150105: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'INTERLOCK_INPUT_OPEN',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150110: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'INSTRUMENT_API_SESSION_HANDLE',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150111: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'WAS_SESSION_OPENED_BY_INITIALIZE_WITH_INDEPENDENT_CHANNELS',
        'resettable': False,
        'type': 'bool'
    },
    1150152: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150184: {
        'codegen_method': 'public',
        'enum': 'ComplianceLimitSymmetry',
        'grpc_type': 'sint32',
        'name': 'COMPLIANCE_LIMIT_SYMMETRY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150185: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150186: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150187: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150188: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150189: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_VOLTAGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150190: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_VOLTAGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150191: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_VOLTAGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150192: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_VOLTAGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150193: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_CURRENT_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150194: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_CURRENT_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150195: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_CURRENT_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150196: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PULSE_BIAS_CURRENT_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150198: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SEQUENCE_STEP_DELTA_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150199: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SEQUENCE_STEP_DELTA_TIME_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150200: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OCP_ERROR_PERCENTAGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150205: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ACTUAL_POWER_ALLOCATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150206: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REQUESTED_POWER_ALLOCATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150207: {
        'codegen_method': 'public',
        'enum': 'PowerAllocationMode',
        'grpc_type': 'sint32',
        'name': 'POWER_ALLOCATION_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150208: {
        'codegen_method': 'public',
        'enum': 'InstrumentMode',
        'grpc_type': 'sint32',
        'name': 'INSTRUMENT_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150209: {
        'codegen_method': 'public',
        'enum': 'LCRStimulusFunction',
        'grpc_type': 'sint32',
        'name': 'LCR_STIMULUS_FUNCTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150210: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150211: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_VOLTAGE_AMPLITUDE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150212: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_CURRENT_AMPLITUDE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150213: {
        'codegen_method': 'public',
        'enum': 'LCRDCBiasSource',
        'grpc_type': 'sint32',
        'name': 'LCR_DC_BIAS_SOURCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150214: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_DC_BIAS_VOLTAGE_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150215: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_DC_BIAS_CURRENT_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150216: {
        'codegen_method': 'public',
        'enum': 'LCRImpedanceAutoRange',
        'grpc_type': 'sint32',
        'name': 'LCR_IMPEDANCE_AUTO_RANGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150217: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_IMPEDANCE_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150218: {
        'codegen_method': 'public',
        'enum': 'LCRMeasurementTime',
        'grpc_type': 'sint32',
        'name': 'LCR_MEASUREMENT_TIME',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150220: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'LCR_OPEN_COMPENSATION_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150221: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'LCR_SHORT_COMPENSATION_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150222: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'LCR_LOAD_COMPENSATION_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150223: {
        'codegen_method': 'public',
        'enum': 'LCROpenShortLoadCompensationDataSource',
        'grpc_type': 'sint32',
        'name': 'LCR_OPEN_SHORT_LOAD_COMPENSATION_DATA_SOURCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150235: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OUTPUT_CUTOFF_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150236: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_VOLTAGE_OUTPUT_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150237: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_CURRENT_MEASURE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150238: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_VOLTAGE_CHANGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150239: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_CURRENT_CHANGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150240: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OUTPUT_CUTOFF_CURRENT_OVERRANGE_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150244: {
        'codegen_method': 'public',
        'enum': 'AutoZero',
        'grpc_type': 'sint32',
        'name': 'AUTORANGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150245: {
        'codegen_method': 'public',
        'enum': 'AutorangeBehavior',
        'grpc_type': 'sint32',
        'name': 'AUTORANGE_BEHAVIOR',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150246: {
        'codegen_method': 'public',
        'enum': 'AutorangeApertureTimeMode',
        'grpc_type': 'sint32',
        'name': 'AUTORANGE_APERTURE_TIME_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150247: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AUTORANGE_MINIMUM_APERTURE_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150248: {
        'codegen_method': 'public',
        'enum': 'ApertureTimeUnits',
        'grpc_type': 'sint32',
        'name': 'AUTORANGE_MINIMUM_APERTURE_TIME_UNITS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150249: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MERGED_CHANNELS',
        'resettable': False,
        'type': 'ViString'
    },
    1150255: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AUTORANGE_MINIMUM_CURRENT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150256: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AUTORANGE_MINIMUM_VOLTAGE_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150257: {
        'codegen_method': 'public',
        'enum': 'AutorangeThresholdMode',
        'grpc_type': 'sint32',
        'name': 'AUTORANGE_THRESHOLD_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150258: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_CUSTOM_MEASUREMENT_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150259: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ACTUAL_VOLTAGE_RANGE_FOR_LAST_FETCH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150260: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ACTUAL_CURRENT_RANGE_FOR_LAST_FETCH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150261: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_OPEN_CONDUCTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150262: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_OPEN_SUSCEPTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150263: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_SHORT_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150264: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_SHORT_REACTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150265: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_VOLTAGE_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150266: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_DC_BIAS_VOLTAGE_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150267: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_CURRENT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150268: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_MEASURED_LOAD_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150269: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_MEASURED_LOAD_REACTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150270: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_ACTUAL_LOAD_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150271: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_ACTUAL_LOAD_REACTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150274: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_DC_BIAS_CURRENT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150275: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'SHUTDOWN_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150276: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_SHUTDOWN_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150277: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_SHUTDOWN_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150278: {
        'codegen_method': 'public',
        'enum': 'CableLength',
        'grpc_type': 'sint32',
        'name': 'CABLE_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150290: {
        'codegen_method': 'public',
        'enum': 'LCRAutomaticLevelControl',
        'grpc_type': 'sint32',
        'name': 'LCR_AUTOMATIC_LEVEL_CONTROL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150291: {
        'codegen_method': 'public',
        'enum': 'LCRAutomaticLevelControl',
        'grpc_type': 'sint32',
        'name': 'LCR_DC_BIAS_AUTOMATIC_LEVEL_CONTROL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150292: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_VOLTAGE_OUTPUT_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150293: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_CURRENT_MEASURE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150294: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_VOLTAGE_CHANGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150295: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_CURRENT_CHANGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150299: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'LCR_SHORT_CUSTOM_CABLE_COMPENSATION_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150300: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_CUTOFF_DELAY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150302: {
        'codegen_method': 'public',
        'enum': 'IsolationState',
        'grpc_type': 'sint32',
        'name': 'ISOLATION_STATE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150314: {
        'codegen_method': 'public',
        'enum': 'ApertureTimeAutoMode',
        'grpc_type': 'sint32',
        'name': 'APERTURE_TIME_AUTO_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150315: {
        'codegen_method': 'public',
        'enum': 'LCRSourceDelayMode',
        'grpc_type': 'sint32',
        'name': 'LCR_SOURCE_DELAY_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150318: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_LOAD_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150319: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_LOAD_INDUCTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150320: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LCR_LOAD_CAPACITANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150321: {
        'codegen_method': 'public',
        'enum': 'LCRImpedanceRangeSource',
        'grpc_type': 'sint32',
        'name': 'LCR_IMPEDANCE_RANGE_SOURCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150322: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AUTORANGE_MAXIMUM_DELAY_AFTER_RANGE_CHANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250001: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOLTAGE_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250002: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OVP_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1250003: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OVP_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250004: {
        'codegen_method': 'public',
        'enum': 'CurrentLimitBehavior',
        'grpc_type': 'sint32',
        'name': 'CURRENT_LIMIT_BEHAVIOR',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250005: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CURRENT_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250006: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OUTPUT_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    }
}
