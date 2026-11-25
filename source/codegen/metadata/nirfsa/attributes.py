# -*- coding: utf-8 -*-
# This file is generated from NI-RFSA API metadata version 27.0.0d9999
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
        'type': 'ViInt32'
    },
    1050302: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_PREFIX',
        'type': 'ViString'
    },
    1050304: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'IO_RESOURCE_DESCRIPTOR',
        'type': 'ViString'
    },
    1050305: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'LOGICAL_NAME',
        'type': 'ViString'
    },
    1050327: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SUPPORTED_INSTRUMENT_MODELS',
        'type': 'ViString'
    },
    1050401: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'GROUP_CAPABILITIES',
        'type': 'ViString'
    },
    1050510: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'INSTRUMENT_FIRMWARE_REVISION',
        'type': 'ViString'
    },
    1050511: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'INSTRUMENT_MANUFACTURER',
        'type': 'ViString'
    },
    1050512: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'INSTRUMENT_MODEL',
        'type': 'ViString'
    },
    1050513: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_VENDOR',
        'type': 'ViString'
    },
    1050514: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_DESCRIPTION',
        'type': 'ViString'
    },
    1050515: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION',
        'type': 'ViInt32'
    },
    1050516: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION',
        'type': 'ViInt32'
    },
    1050551: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SPECIFIC_DRIVER_REVISION',
        'type': 'ViString'
    },
    1150001: {
        'codegen_method': 'public',
        'enum': 'AcquisitionType',
        'grpc_type': 'sint32',
        'name': 'ACQUISITION_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150002: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CENTER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150003: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SPECTRUM_SPAN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150004: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REFERENCE_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150005: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150006: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MIXER_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150007: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150008: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'NUMBER_OF_SAMPLES_IS_FINITE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150009: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'NUMBER_OF_SAMPLES',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150010: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'NUMBER_OF_RECORDS_IS_FINITE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150011: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'NUMBER_OF_RECORDS',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150012: {
        'codegen_method': 'public',
        'enum': 'PowerSpectrumUnits',
        'grpc_type': 'sint32',
        'name': 'POWER_SPECTRUM_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150013: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RESOLUTION_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150014: {
        'codegen_method': 'public',
        'enum': 'BandwidthType',
        'grpc_type': 'sint32',
        'name': 'RESOLUTION_BANDWIDTH_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150015: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SPECTRUM_NUMBER_OF_AVERAGES',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150016: {
        'codegen_method': 'public',
        'enum': 'AveragingMode',
        'grpc_type': 'sint32',
        'name': 'SPECTRUM_AVERAGING_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150017: {
        'codegen_method': 'public',
        'enum': 'FftWindowType',
        'grpc_type': 'sint32',
        'name': 'FFT_WINDOW_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150018: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'NUMBER_OF_SPECTRAL_LINES',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150019: {
        'codegen_method': 'public',
        'enum': 'RefClockSource',
        'grpc_type': 'string',
        'name': 'REF_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150020: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REF_CLOCK_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150021: {
        'codegen_method': 'public',
        'enum': 'DigitizerSampleClockTimebaseSource',
        'grpc_type': 'string',
        'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150022: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITIZER_SAMPLE_CLOCK_TIMEBASE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150023: {
        'codegen_method': 'public',
        'enum': 'PxiChassisClk10Source',
        'grpc_type': 'string',
        'name': 'PXI_CHASSIS_CLK10_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150024: {
        'codegen_method': 'public',
        'enum': 'GeneralTriggerType',
        'grpc_type': 'sint32',
        'name': 'START_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150025: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150026: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150027: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150028: {
        'codegen_method': 'public',
        'enum': 'RefTriggerType',
        'grpc_type': 'sint32',
        'name': 'REF_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150029: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_REF_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150030: {
        'codegen_method': 'public',
        'enum': 'DigitalEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_REF_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150032: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150033: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'START_TO_REF_TRIGGER_HOLDOFF',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150034: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REF_TO_REF_TRIGGER_HOLDOFF',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150035: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'REF_TRIGGER_PRETRIGGER_SAMPLES',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150036: {
        'codegen_method': 'public',
        'enum': 'GeneralTriggerType',
        'grpc_type': 'sint32',
        'name': 'ADVANCE_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150037: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150038: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150039: {
        'codegen_method': 'public',
        'enum': 'GeneralTriggerType',
        'grpc_type': 'sint32',
        'name': 'ARM_REF_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150040: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_ARM_REF_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150041: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_READY_FOR_START_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150042: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150043: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_READY_FOR_REF_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150044: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_END_OF_RECORD_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150045: {
        'codegen_method': 'public',
        'enum': 'FetchRelativeTo',
        'grpc_type': 'sint32',
        'name': 'FETCH_RELATIVE_TO',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150046: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'FETCH_OFFSET',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150047: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'RECORDS_DONE',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150048: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DIGITAL_IF_EQUALIZATION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150049: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FFT_WINDOW_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150050: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FFT_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150051: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEVICE_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150053: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150054: {
        'codegen_method': 'public',
        'enum': 'ExportTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_DONE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150055: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'IQ_POWER_EDGE_REF_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150056: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_POWER_EDGE_REF_TRIGGER_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150057: {
        'codegen_method': 'public',
        'enum': 'AnalogSlope',
        'grpc_type': 'sint32',
        'name': 'IQ_POWER_EDGE_REF_TRIGGER_SLOPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150058: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REF_TRIGGER_MINIMUM_QUIET_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150059: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_CARRIER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150060: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REF_TRIGGER_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150061: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMPERATURE_READ_INTERVAL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150065: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DOWNCONVERTER_GAIN',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150067: {
        'codegen_method': 'public',
        'enum': 'LoopBandwidth',
        'grpc_type': 'sint32',
        'name': 'DOWNCONVERTER_LOOP_BANDWIDTH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150068: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150069: {
        'codegen_method': 'public',
        'enum': 'LoInjectionSideValues',
        'grpc_type': 'sint32',
        'name': 'LO_INJECTION_SIDE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150070: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITIZER_VERTICAL_RANGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150071: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ENABLE_FRACTIONAL_RESAMPLING',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150072: {
        'codegen_method': 'public',
        'enum': 'RefClockOutTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_REF_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150074: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150075: {
        'codegen_method': 'public',
        'enum': 'IfFilter',
        'grpc_type': 'sint32',
        'name': 'IF_FILTER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150076: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'RF_ATTENUATION_INDEX',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150077: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'RF_ATTENUATION_TABLE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150078: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF1_ATTEN_VALUE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150079: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF2_ATTEN_VALUE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150080: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DIGITIZER_DITHER_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150081: {
        'codegen_method': 'public',
        'enum': 'Enabled',
        'grpc_type': 'sint32',
        'name': 'MECHANICAL_ATTENUATOR_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150082: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DOWNCONVERTER_CENTER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150083: {
        'codegen_method': 'public',
        'enum': 'RfPathSelection',
        'grpc_type': 'sint32',
        'name': 'CAL_RF_PATH_SELECTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150085: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'MEMORY_SIZE',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150086: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF_OUTPUT_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150087: {
        'codegen_method': 'public',
        'enum': 'FrequencySettlingUnits',
        'grpc_type': 'sint32',
        'name': 'FREQUENCY_SETTLING_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150088: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FREQUENCY_SETTLING',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150089: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150090: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITIZER_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150091: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MODULE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150092: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ACTIVE_CONFIGURATION_LIST',
        'resettable': True,
        'type': 'ViString'
    },
    1150093: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'ACTIVE_CONFIGURATION_LIST_STEP',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150094: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'EXTERNAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150095: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'CONFIGURATION_LIST_STEP_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150096: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TIMER_EVENT_INTERVAL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150097: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150098: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_FIFO_ENDPOINT_COUNT',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150099: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_SAMPLES_TRANSFERRED',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150100: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_SAMPLES_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150101: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_MOST_SAMPLES_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150102: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_ENDPOINT_SIZE',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150103: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ENDPOINT_OVERFLOW',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150104: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150105: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150106: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PHASE_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150107: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ONBOARD_MEMORY_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150109: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CAL_IF_ATTENUATION_INDEX',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150110: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CAL_RF_ELECTRONIC_ATTENUATION_INDEX',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150111: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CAL_RF_MECHANICAL_ATTENUATION_INDEX',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150112: {
        'codegen_method': 'public',
        'enum': 'CalIfFilterSelection',
        'grpc_type': 'sint32',
        'name': 'CAL_IF_FILTER_SELECTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150113: {
        'codegen_method': 'public',
        'enum': 'LoPathSelection',
        'grpc_type': 'sint32',
        'name': 'CAL_LO_PATH_SELECTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150114: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CAL_LO1_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150115: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CAL_LO2_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150116: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CAL_LO3_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150117: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_START_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150118: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_ADVANCE_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150119: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_REF_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150120: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'END_OF_RECORD_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150121: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DONE_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150122: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'START_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150123: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'REF_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150124: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ADVANCE_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150125: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEVICE_INSTANTANEOUS_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150126: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'CONFIGURATION_LIST_STEP_IN_PROGRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150127: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MIXER_LEVEL_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150128: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MECHANICAL_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150129: {
        'codegen_method': 'public',
        'enum': 'RfPreampEnabled',
        'grpc_type': 'sint32',
        'name': 'RF_PREAMP_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150130: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF_OUTPUT_POWER_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150131: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF_OUTPUT_POWER_LEVEL_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150132: {
        'codegen_method': 'public',
        'enum': 'DownconverterPreselectorEnabled',
        'grpc_type': 'sint32',
        'name': 'DOWNCONVERTER_PRESELECTOR_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150134: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'LO_EXPORT_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150135: {
        'codegen_method': 'public',
        'enum': 'LoYigMainCoilDrive',
        'grpc_type': 'sint32',
        'name': 'LO_YIG_MAIN_COIL_DRIVE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150136: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'PRESELECTOR_PRESENT',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150137: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'RF_PREAMP_PRESENT',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150139: {
        'codegen_method': 'public',
        'enum': 'CalToneMode',
        'grpc_type': 'sint32',
        'name': 'DOWNCONVERTER_CAL_TONE_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150140: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DOWNCONVERTER_CAL_TONE_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150141: {
        'codegen_method': 'public',
        'enum': 'CalIfAttenTableSelection',
        'grpc_type': 'sint32',
        'name': 'CAL_IF_ATTENUATION_TABLE_SELECTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150142: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MINIMUM_ACPR',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150144: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SPECTRUM_OSP_SAMPLING_RATIO',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150146: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CALIBRATION_CORRECTION_THROUGH_FILTER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150147: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CALIBRATION_CORRECTION_300_KHZ_FILTER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150148: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CALIBRATION_CORRECTION_5_MHZ_FILTER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150149: {
        'codegen_method': 'public',
        'enum': 'ChannelCoupling',
        'grpc_type': 'sint32',
        'name': 'CHANNEL_COUPLING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150151: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_DATA_SCALING_FACTOR',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150154: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ALLOW_MORE_RECORDS_THAN_MEMORY',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150155: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RF_ATTENUATION_STEP_SIZE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150157: {
        'codegen_method': 'public',
        'enum': 'StepGainEnabled',
        'grpc_type': 'sint32',
        'name': 'STEP_GAIN_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150158: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': '5665_PRESELECTOR_TUNING_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150159: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEVICE_CONFIGURATION_TEMPERATURE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150160: {
        'codegen_method': 'public',
        'enum': 'SignalConditioningEnabled',
        'grpc_type': 'sint32',
        'name': 'SIGNAL_CONDITIONING_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150161: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'IF_CONDITIONING_DOWN_CONVERSION_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150162: {
        'codegen_method': 'public',
        'enum': 'LoSourceSelection',
        'grpc_type': 'string',
        'name': 'LO_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150163: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AMPLITUDE_SETTLING',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150164: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DDC_REF_TRIGGER_OVERRIDE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150165: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MINIMUM_RECONFIG_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150166: {
        'codegen_method': 'public',
        'enum': 'RfPreselectorFilter',
        'grpc_type': 'sint32',
        'name': 'RF_PRESELECTOR_FILTER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150167: {
        'codegen_method': 'public',
        'enum': 'NotchFilterEnabled',
        'grpc_type': 'sint32',
        'name': 'NOTCH_FILTER_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150168: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CAL_TONE_STEP_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150169: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FFT_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150170: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'INPUT_ISOLATION_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150172: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CONTIGUOUS_MULTIRECORD',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150173: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'TIMER_START_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150174: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CAL_TONE_POWER_REFERRED_TO_RF_IN',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150175: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'START_TRIGGER_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150176: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SYNC_START_TRIGGER_MASTER',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150177: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_START_TRIGGER_DIST_LINE',
        'resettable': True,
        'type': 'ViString'
    },
    1150178: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SYNC_REF_TRIGGER_MASTER',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150179: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_REF_TRIGGER_DIST_LINE',
        'resettable': True,
        'type': 'ViString'
    },
    1150180: {
        'codegen_method': 'public',
        'enum': 'InputPort',
        'grpc_type': 'sint32',
        'name': 'INPUT_PORT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150181: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_IN_PORT_CARRIER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150182: {
        'codegen_method': 'public',
        'enum': 'IqInPortTermConfig',
        'grpc_type': 'sint32',
        'name': 'IQ_IN_PORT_TERMINAL_CONFIGURATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150183: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_IN_PORT_VERTICAL_RANGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150184: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SYNC_ADVANCE_TRIGGER_MASTER',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150185: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_ADVANCE_TRIGGER_DIST_LINE',
        'resettable': True,
        'type': 'ViString'
    },
    1150186: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_IN_POWER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150187: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'LO_PLL_FRACTIONAL_MODE_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150188: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_FREQUENCY_STEP_SIZE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150189: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SYNC_REF_TRIGGER_DELAY_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150191: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DECIMATION_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150192: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150193: {
        'codegen_method': 'public',
        'enum': 'AnalogSlope',
        'grpc_type': 'sint32',
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_SLOPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150194: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150195: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_ANALOG_EDGE_REF_TRIGGER_HYSTERESIS',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150196: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'REF_TRIGGER_OSP_DELAY_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150203: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DOWNCONVERTER_FREQUENCY_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150204: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_IN_PORT_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150205: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF_FILTER_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150206: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FFT_WINDOW_SHAPE_FACTOR',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150207: {
        'codegen_method': 'public',
        'enum': 'Enabled',
        'grpc_type': 'sint32',
        'name': 'LOW_FREQUENCY_BYPASS_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150208: {
        'codegen_method': 'public',
        'enum': 'ConditioningCalToneMode',
        'grpc_type': 'sint32',
        'name': 'RF_CONDITIONING_CAL_TONE_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150209: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RF_CONDITIONING_CAL_TONE_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150210: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IF_CONDITIONING_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150211: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RF_CONDITIONING_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150215: {
        'codegen_method': 'public',
        'enum': 'RfLbSigCondPathSel',
        'grpc_type': 'sint32',
        'name': 'CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_SELECTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150216: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CAL_IF_ATTENUATION_TABLE_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150217: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SYNC_SAMPLE_CLOCK_MASTER',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150218: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_SAMPLE_CLOCK_DIST_LINE',
        'resettable': True,
        'type': 'ViString'
    },
    1150219: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SMOOTH_SPECTRUM_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150220: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RF_HIGH_PASS_FILTERING',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150221: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FPGA_BITFILE_PATH',
        'resettable': False,
        'type': 'ViString'
    },
    1150222: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'NOISE_SOURCE_POWER_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150223: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CALIBRATION_CORRECTION_100_MHZ_FILTER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150224: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CALIBRATION_CORRECTION_320_MHZ_FILTER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150225: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CALIBRATION_CORRECTION_765_MHZ_FILTER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150226: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'CAL_DIGITIZER_ID',
        'resettable': True,
        'type': 'ViString'
    },
    1150228: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITIZER_SAMPLE_CLOCK_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150229: {
        'codegen_method': 'public',
        'enum': 'DigitizerSampleClockOutTerminal',
        'grpc_type': 'string',
        'name': 'EXPORTED_DIGITIZER_SAMPLE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150233: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FPGA_TARGET_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150234: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SUBSPAN_OVERLAP',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150235: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'LO2_EXPORT_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150236: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_DEVICE_INSTANTANEOUS_BANDWIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150237: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_IQ_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150246: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_OUT_POWER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150254: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FPGA_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150255: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MODULE_POWER_CONSUMPTION',
        'type': 'ViReal64'
    },
    1150256: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ALLOW_OUT_OF_SPECIFICATION_USER_SETTINGS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150266: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150267: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SIGNAL_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150269: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'COMMON_MODE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150271: {
        'codegen_method': 'public',
        'enum': 'OverflowErrorReporting',
        'grpc_type': 'sint32',
        'name': 'OVERFLOW_ERROR_REPORTING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150285: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'HOST_DMA_BUFFER_SIZE',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150297: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SELECTED_PORTS',
        'resettable': True,
        'type': 'ViString'
    },
    1150298: {
        'codegen_method': 'public',
        'enum': 'Unspecified',
        'grpc_type': 'sint32',
        'name': 'RF_OUT_LO_EXPORT_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150299: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'LO_OUT_EXPORT_CONFIGURE_FROM_RFSG',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150300: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'THERMAL_CORRECTION_TEMPERATURE_RESOLUTION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150301: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150305: {
        'codegen_method': 'public',
        'enum': 'DownconverterFrequencyOffsetMode',
        'grpc_type': 'sint32',
        'name': 'DOWNCONVERTER_FREQUENCY_OFFSET_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150306: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'AVAILABLE_PORTS',
        'resettable': False,
        'type': 'ViString'
    },
    1150307: {
        'codegen_method': 'public',
        'enum': 'DeembeddingType',
        'grpc_type': 'sint32',
        'name': 'DEEMBEDDING_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150308: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DEEMBEDDING_SELECTED_TABLE',
        'resettable': True,
        'type': 'ViString'
    },
    1150309: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REFERENCE_LEVEL_HEADROOM',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150312: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_VCO_FREQUENCY_STEP_SIZE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150316: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'THERMAL_CORRECTION_HEADROOM_RANGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150321: {
        'codegen_method': 'public',
        'enum': 'PulseWidthUnitType',
        'grpc_type': 'sint32',
        'name': 'USER_SOURCE_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150322: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'USER_SOURCE_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150324: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FIXED_GROUP_DELAY_ACROSS_PORTS',
        'resettable': True,
        'type': 'ViString'
    },
    1150325: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEEMBEDDING_COMPENSATION_GAIN',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150326: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'EXPORTED_REF_CLOCK_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150331: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SELECTED_PATH',
        'resettable': True,
        'type': 'ViString'
    },
    1150332: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'AVAILABLE_PATHS',
        'resettable': True,
        'type': 'ViString'
    },
    1150333: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CREATED_SESSION_CHANNEL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150334: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MIN_FUNDAMENTAL_SILO_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150335: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_FUNDAMENTAL_SILO_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150337: {
        'codegen_method': 'public',
        'enum': 'LoadConfigurationResetOptions',
        'grpc_type': 'sint32',
        'name': 'LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150356: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ASSOC_AUX_SWITCH_GAIN_UID',
        'resettable': False,
        'type': 'ViInt32'
    }
}
