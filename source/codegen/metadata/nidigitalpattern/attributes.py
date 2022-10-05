# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 23.0.0d15
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
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150004: {
        'codegen_method': 'public',
        'enum': 'SelectedFunction',
        'grpc_type': 'sint32',
        'name': 'SELECTED_FUNCTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150006: {
        'codegen_method': 'public',
        'enum': 'TerminationMode',
        'grpc_type': 'sint32',
        'name': 'TERMINATION_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150007: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VIL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150008: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VIH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150009: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150010: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VOH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150011: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'VTERM',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150012: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ACTIVE_LOAD_IOL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150013: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ACTIVE_LOAD_IOH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150014: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ACTIVE_LOAD_VCOM',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150015: {
        'codegen_method': 'public',
        'enum': 'PpmuOutputFunction',
        'grpc_type': 'sint32',
        'name': 'PPMU_OUTPUT_FUNCTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150016: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_VOLTAGE_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150017: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_CURRENT_LIMIT_RANGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150019: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_CURRENT_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150020: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_CURRENT_LEVEL_RANGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150021: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_VOLTAGE_LIMIT_LOW',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150022: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_VOLTAGE_LIMIT_HIGH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150023: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'START_LABEL',
        'resettable': True,
        'type': 'ViString'
    },
    1150029: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'START_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150030: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150031: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150032: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150033: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'CONDITIONAL_JUMP_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150034: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_CONDITIONAL_JUMP_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150035: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_CONDITIONAL_JUMP_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150036: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_CONDITIONAL_JUMP_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150037: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_APERTURE_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150038: {
        'codegen_method': 'public',
        'enum': 'PpmuApertureTimeUnits',
        'grpc_type': 'sint32',
        'name': 'PPMU_APERTURE_TIME_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150039: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'START_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150040: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'CONDITIONAL_JUMP_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150041: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_PATTERN_OPCODE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150042: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'PATTERN_OPCODE_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150043: {
        'codegen_method': 'public',
        'enum': 'HistoryRamTriggerType',
        'grpc_type': 'sint32',
        'name': 'HISTORY_RAM_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150044: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'CYCLE_NUMBER_HISTORY_RAM_TRIGGER_CYCLE_NUMBER',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150045: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'PATTERN_LABEL_HISTORY_RAM_TRIGGER_CYCLE_OFFSET',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150046: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'PATTERN_LABEL_HISTORY_RAM_TRIGGER_LABEL',
        'resettable': True,
        'type': 'ViString'
    },
    1150047: {
        'codegen_method': 'public',
        'enum': 'HistoryRamCyclesToAcquire',
        'grpc_type': 'sint32',
        'name': 'HISTORY_RAM_CYCLES_TO_ACQUIRE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150048: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'HISTORY_RAM_PRETRIGGER_SAMPLES',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150051: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TDR_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150052: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'PATTERN_LABEL_HISTORY_RAM_TRIGGER_VECTOR_OFFSET',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150054: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PPMU_CURRENT_LIMIT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150055: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'PPMU_CURRENT_LIMIT_SUPPORTED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150059: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SEQUENCER_FLAG_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150060: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'MASK_COMPARE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150062: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'HALT_ON_KEEP_ALIVE_OPCODE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150063: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IS_KEEP_ALIVE_ACTIVE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150064: {
        'codegen_method': 'public',
        'enum': 'PpmuCurrentLimitBehavior',
        'grpc_type': 'sint32',
        'name': 'PPMU_CURRENT_LIMIT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150069: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FREQUENCY_COUNTER_MEASUREMENT_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150071: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'TIMING_ABSOLUTE_DELAY_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150072: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TIMING_ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150073: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CLOCK_GENERATOR_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150074: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'CLOCK_GENERATOR_IS_RUNNING',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150076: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'PPMU_ALLOW_EXTENDED_VOLTAGE_RANGE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150077: {
        'codegen_method': 'public',
        'enum': 'HistoryRamMaxSamplesToAcquirePerSite',
        'grpc_type': 'sint32',
        'name': 'HISTORY_RAM_MAX_SAMPLES_TO_ACQUIRE_PER_SITE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150078: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'HISTORY_RAM_NUMBER_OF_SAMPLES_IS_FINITE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150079: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'HISTORY_RAM_BUFFER_SIZE_PER_SITE',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150081: {
        'codegen_method': 'public',
        'enum': 'TdrEndpointTermination',
        'grpc_type': 'sint32',
        'name': 'TDR_ENDPOINT_TERMINATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150084: {
        'codegen_method': 'public',
        'enum': 'FrequencyMeasurementMode',
        'grpc_type': 'sint32',
        'name': 'FREQUENCY_COUNTER_MEASUREMENT_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150085: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'FREQUENCY_COUNTER_HYSTERESIS_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150086: {
        'codegen_method': 'public',
        'enum': 'TriggerType',
        'grpc_type': 'sint32',
        'name': 'RIO_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150087: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_RIO_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150088: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_RIO_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150089: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'RIO_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150090: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_RIO_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150091: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'RIO_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    }
}
