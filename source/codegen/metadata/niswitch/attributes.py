# -*- coding: utf-8 -*-
# This file is generated from NI-SWITCH API metadata version 23.0.0d58
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
    1150001: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SERIAL_NUMBER_I32',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150004: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IS_WAITING_FOR_TRIG',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150005: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150006: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MASTER_SLAVE_TRIGGER_BUS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150007: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MASTER_SLAVE_SCAN_ADVANCED_BUS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150008: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CABLED_MODULE_TRIGGER_BUS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150009: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CABLED_MODULE_SCAN_ADVANCED_BUS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150010: {
        'codegen_method': 'public',
        'enum': 'TriggerInputPolarity',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_INPUT_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150011: {
        'codegen_method': 'public',
        'enum': 'ScanAdvancedPolarity',
        'grpc_type': 'sint32',
        'name': 'SCAN_ADVANCED_POLARITY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150012: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'PARSED_SCAN_LIST',
        'resettable': False,
        'type': 'ViString'
    },
    1150013: {
        'codegen_method': 'public',
        'enum': 'HandshakingInitiation',
        'grpc_type': 'sint32',
        'name': 'HANDSHAKING_INITIATION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150014: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'NUMBER_OF_RELAYS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150015: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150016: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DIGITAL_FILTER_ENABLE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150017: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'POWER_DOWN_LATCHING_RELAYS_AFTER_DEBOUNCE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150018: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ANALOG_BUS_SHARING_ENABLE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150019: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250001: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IS_SOURCE_CHANNEL',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1250002: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IS_DEBOUNCED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1250003: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IS_CONFIGURATION_CHANNEL',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1250004: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SETTLING_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250005: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'BANDWIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250006: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_DC_VOLTAGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250007: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_AC_VOLTAGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250008: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_SWITCHING_DC_CURRENT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250009: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_SWITCHING_AC_CURRENT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250010: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_CARRY_DC_CURRENT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250011: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_CARRY_AC_CURRENT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250012: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_SWITCHING_DC_POWER',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250013: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_SWITCHING_AC_POWER',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250014: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_CARRY_DC_POWER',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250015: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_CARRY_AC_POWER',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250016: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CHARACTERISTIC_IMPEDANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250017: {
        'codegen_method': 'public',
        'enum': 'WireMode',
        'grpc_type': 'sint32',
        'name': 'WIRE_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250018: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'NUM_OF_ROWS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250019: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'NUM_OF_COLUMNS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250020: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SCAN_LIST',
        'resettable': False,
        'type': 'ViString'
    },
    1250021: {
        'codegen_method': 'public',
        'enum': 'ScanMode',
        'grpc_type': 'sint32',
        'name': 'SCAN_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250022: {
        'codegen_method': 'public',
        'enum': 'TriggerInput',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_INPUT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250023: {
        'codegen_method': 'public',
        'enum': 'ScanAdvancedOutput',
        'grpc_type': 'sint32',
        'name': 'SCAN_ADVANCED_OUTPUT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250024: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IS_SCANNING',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1250025: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SCAN_DELAY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250026: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'CONTINUOUS_SCAN',
        'resettable': False,
        'type': 'ViBoolean'
    }
}
