# -*- coding: utf-8 -*-
# This file is generated from NI-DCPower API metadata version 20.7.0d8
attributes = {
    1050002: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'RANGE_CHECK',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050003: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'QUERY_INSTRUMENT_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050004: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'CACHE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050005: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'SIMULATE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050006: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'RECORD_COERCIONS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050007: {
        'access': 'read only',
        'channel_based': False,
        'name': 'DRIVER_SETUP',
        'resettable': False,
        'type': 'ViString'
    },
    1050021: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'INTERCHANGE_CHECK',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050203: {
        'access': 'read only',
        'channel_based': False,
        'name': 'CHANNEL_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050302: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_PREFIX',
        'resettable': False,
        'type': 'ViString'
    },
    1050304: {
        'access': 'read only',
        'channel_based': False,
        'name': 'IO_RESOURCE_DESCRIPTOR',
        'resettable': False,
        'type': 'ViString'
    },
    1050305: {
        'access': 'read only',
        'channel_based': False,
        'name': 'LOGICAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1050327: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SUPPORTED_INSTRUMENT_MODELS',
        'resettable': False,
        'type': 'ViString'
    },
    1050401: {
        'access': 'read only',
        'channel_based': False,
        'name': 'GROUP_CAPABILITIES',
        'resettable': False,
        'type': 'ViString'
    },
    1050510: {
        'access': 'read only',
        'channel_based': True,
        'name': 'INSTRUMENT_FIRMWARE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1050511: {
        'access': 'read only',
        'channel_based': False,
        'name': 'INSTRUMENT_MANUFACTURER',
        'resettable': False,
        'type': 'ViString'
    },
    1050512: {
        'access': 'read only',
        'name': 'INSTRUMENT_MODEL',
        'resettable': False,
        'type': 'ViString'
    },
    1050513: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_VENDOR',
        'resettable': False,
        'type': 'ViString'
    },
    1050514: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_DESCRIPTION',
        'resettable': False,
        'type': 'ViString'
    },
    1050515: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050516: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'        
    },
    1050551: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150000: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'PowerSource',
        'name': 'POWER_SOURCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150001: {
        'access': 'read only',
        'channel_based': True,
        'enum': 'PowerSourceInUse',
        'name': 'POWER_SOURCE_IN_USE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150002: {
        'access': 'read only',
        'channel_based': True,
        'name': 'AUXILIARY_POWER_SOURCE_AVAILABLE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150003: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SAMPLES_TO_AVERAGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150004: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150005: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150006: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'RESET_AVERAGE_BEFORE_MEASUREMENT',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150007: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'OVERRANGING_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150008: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'OutputFunction',
        'name': 'OUTPUT_FUNCTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150009: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150010: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150011: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150012: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150013: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'Sense',
        'name': 'SENSE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150014: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'OutputCapacitance',
        'name': 'OUTPUT_CAPACITANCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150015: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutoZero',
        'name': 'VOLTAGE_LEVEL_AUTORANGE',
        'python_type': 'bool',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150016: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutoZero',
        'name': 'CURRENT_LIMIT_AUTORANGE',
        'python_type': 'bool',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150017: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutoZero',
        'name': 'CURRENT_LEVEL_AUTORANGE',
        'python_type': 'bool',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150018: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutoZero',
        'name': 'VOLTAGE_LIMIT_AUTORANGE',
        'python_type': 'bool',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150020: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'POWER_LINE_FREQUENCY',
        'enum': 'PowerLineFrequencies',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150021: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'TriggerType',
        'name': 'START_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150022: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150023: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'DIGITAL_EDGE_START_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150024: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150025: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_LOOP_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150026: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'TriggerType',
        'name': 'SEQUENCE_ADVANCE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150027: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150028: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150029: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'EXPORTED_SEQUENCE_ADVANCE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150030: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'TriggerType',
        'name': 'SOURCE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150031: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_SOURCE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150032: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'DIGITAL_EDGE_SOURCE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150033: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'EXPORTED_SOURCE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150034: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'TriggerType',
        'name': 'MEASURE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150035: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_MEASURE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150036: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'DIGITAL_EDGE_MEASURE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150037: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'EXPORTED_MEASURE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150038: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'Polarity',
        'name': 'SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150039: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150040: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_ITERATION_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150041: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'Polarity',
        'name': 'SOURCE_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150042: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SOURCE_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150043: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SOURCE_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150044: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'Polarity',
        'name': 'MEASURE_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150045: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'MEASURE_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150046: {
        'access': 'read-write',
        'attribute_class': 'AttributeViReal64TimeDeltaSeconds',
        'channel_based': True,
        'name': 'MEASURE_COMPLETE_EVENT_DELAY',
        'resettable': False,
        'type': 'ViReal64',
        'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds'
    },
    1150047: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'MEASURE_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150048: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'Polarity',
        'name': 'SEQUENCE_ENGINE_DONE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150049: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_ENGINE_DONE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150050: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_ENGINE_DONE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150051: {
        'access': 'read-write',
        'attribute_class': 'AttributeViReal64TimeDeltaSeconds',
        'channel_based': True,
        'name': 'SOURCE_DELAY',
        'resettable': False,
        'type': 'ViReal64',
        'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds'
    },
    1150054: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'SourceMode',
        'name': 'SOURCE_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150055: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutoZero',
        'name': 'AUTO_ZERO',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150056: {
        'access': 'read only',
        'channel_based': True,
        'name': 'FETCH_BACKLOG',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150057: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'MeasureWhen',
        'name': 'MEASURE_WHEN',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150058: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'APERTURE_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150059: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'ApertureTimeUnits',
        'name': 'APERTURE_TIME_UNITS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150060: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'OUTPUT_CONNECTED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150061: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'OUTPUT_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150062: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'TransientResponse',
        'name': 'TRANSIENT_RESPONSE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150063: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'MEASURE_RECORD_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150064: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'MEASURE_RECORD_LENGTH_IS_FINITE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150065: {
        'access': 'read only',
        'attribute_class': 'AttributeViReal64TimeDeltaSeconds',
        'channel_based': True,
        'name': 'MEASURE_RECORD_DELTA_TIME',
        'resettable': False,
        'type': 'ViReal64',
        'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds'
    },
    1150066: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'DCNoiseRejection',
        'name': 'DC_NOISE_REJECTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150067: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_GAIN_BANDWIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150068: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_COMPENSATION_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150069: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_POLE_ZERO_RATIO',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150070: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_GAIN_BANDWIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150071: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_COMPENSATION_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150072: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_POLE_ZERO_RATIO',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150073: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'SelfCalibrationPersistence',
        'name': 'SELF_CALIBRATION_PERSISTENCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150074: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'ACTIVE_ADVANCED_SEQUENCE',
        'resettable': False,
        'type': 'ViString'
    },
    1150075: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'ACTIVE_ADVANCED_SEQUENCE_STEP',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150077: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'MEASURE_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150078: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_LOOP_COUNT_IS_FINITE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150080: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_VOLTAGE_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150081: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_CURRENT_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150082: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_VOLTAGE_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150083: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_CURRENT_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150084: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_VOLTAGE_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150085: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_CURRENT_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150086: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_CURRENT_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150087: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_VOLTAGE_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150088: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_CURRENT_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150089: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_VOLTAGE_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150090: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_CURRENT_LEVEL_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150091: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_VOLTAGE_LIMIT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150092: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_DELAY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150093: {
        'access': 'read-write',
        'attribute_class': 'AttributeViReal64TimeDeltaSeconds',
        'channel_based': True,
        'name': 'PULSE_ON_TIME',
        'resettable': False,
        'type': 'ViReal64',
        'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds'
    },
    1150094: {
        'access': 'read-write',
        'attribute_class': 'AttributeViReal64TimeDeltaSeconds',
        'channel_based': True,
        'name': 'PULSE_OFF_TIME',
        'resettable': False,
        'type': 'ViReal64',
        'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds'
    },
    1150095: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'TriggerType',
        'name': 'PULSE_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150096: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_PULSE_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150097: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'DIGITAL_EDGE_PULSE_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150098: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'EXPORTED_PULSE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150099: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_COMPLETE_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150100: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'Polarity',
        'name': 'PULSE_COMPLETE_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150101: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_COMPLETE_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150102: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'READY_FOR_PULSE_TRIGGER_EVENT_OUTPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1150103: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'Polarity',
        'name': 'READY_FOR_PULSE_TRIGGER_EVENT_PULSE_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150104: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'READY_FOR_PULSE_TRIGGER_EVENT_PULSE_WIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150105: {
        'access': 'read only',
        'channel_based': True,
        'name': 'INTERLOCK_INPUT_OPEN',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150152: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150184: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'ComplianceLimitSymmetry',
        'name': 'COMPLIANCE_LIMIT_SYMMETRY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150185: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150186: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150187: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150188: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150189: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_VOLTAGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150190: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_VOLTAGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150191: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_VOLTAGE_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150192: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_VOLTAGE_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150193: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_CURRENT_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150194: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_CURRENT_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150195: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_CURRENT_LIMIT_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150196: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'PULSE_BIAS_CURRENT_LIMIT_LOW',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150198: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_STEP_DELTA_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150199: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'SEQUENCE_STEP_DELTA_TIME_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150205: {
        'access': 'read only',
        'channel_based': True,
        'name': 'ACTUAL_POWER_ALLOCATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150206: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'REQUESTED_POWER_ALLOCATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150207: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'PowerAllocationMode',
        'name': 'POWER_ALLOCATION_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150244: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutoZero',
        'name': 'AUTORANGE',
        'python_type': 'bool',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150245: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutorangeBehavior',
        'name': 'AUTORANGE_BEHAVIOR',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150246: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutorangeApertureTimeMode',
        'name': 'AUTORANGE_APERTURE_TIME_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150247: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'AUTORANGE_MINIMUM_APERTURE_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150248: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'ApertureTimeUnits',
        'name': 'AUTORANGE_MINIMUM_APERTURE_TIME_UNITS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150249: {
        'access': 'read-write',
        'attribute_class': 'AttributeViStringRepeatedCapability',
        'channel_based': True,
        'name': 'MERGED_CHANNELS',
        'resettable': False,
        'type': 'ViString'
    },
    1150255: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'AUTORANGE_MINIMUM_CURRENT_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150256: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'AUTORANGE_MINIMUM_VOLTAGE_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150257: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'AutorangeThresholdMode',
        'name': 'AUTORANGE_THRESHOLD_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150275: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'TriggerType',
        'name': 'SHUTDOWN_TRIGGER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150276: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'DigitalEdge',
        'name': 'DIGITAL_EDGE_SHUTDOWN_TRIGGER_EDGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150277: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'DIGITAL_EDGE_SHUTDOWN_TRIGGER_INPUT_TERMINAL',
        'resettable': False,
        'type': 'ViString'
    },
    1250001: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'VOLTAGE_LEVEL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250002: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'OVP_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1250003: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'OVP_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250004: {
        'access': 'read-write',
        'channel_based': True,
        'enum': 'CurrentLimitBehavior',
        'name': 'CURRENT_LIMIT_BEHAVIOR',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250005: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'CURRENT_LIMIT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250006: {
        'access': 'read-write',
        'channel_based': True,
        'name': 'OUTPUT_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    }
}
