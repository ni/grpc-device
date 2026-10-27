# -*- coding: utf-8 -*-
# This file is generated from NI-RFSG API metadata version 27.0.0d9999
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
    1050022: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SPY',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050023: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'USE_SPECIFIC_SIMULATION',
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
    1050402: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FUNCTION_CAPABILITIES',
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
        'enum': 'RefClockSource',
        'grpc_type': 'string',
        'name': 'REF_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150002: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150003: {
        'codegen_method': 'public',
        'enum': 'AnySignalOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150004: {
        'codegen_method': 'public',
        'enum': 'PXIChassisClk10',
        'grpc_type': 'string',
        'name': 'PXI_CHASSIS_CLK10_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150005: {
        'codegen_method': 'public',
        'enum': 'PhaseContinuity',
        'grpc_type': 'sint32',
        'name': 'PHASE_CONTINUITY_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150006: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FREQUENCY_TOLERANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150007: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SIGNAL_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150008: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'AUTOMATIC_THERMAL_CORRECTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150009: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ATTENUATOR_HOLD_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150010: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ATTENUATOR_HOLD_MAX_POWER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150011: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PEAK_ENVELOPE_POWER',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150012: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EQUALIZATION_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150013: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'LO_OUT_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150014: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'ALLOW_OUT_OF_SPECIFICATION_USER_SETTINGS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150015: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_CARRIER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150016: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_POWER',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150017: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEVICE_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150018: {
        'codegen_method': 'public',
        'enum': 'GenerationMode',
        'grpc_type': 'sint32',
        'name': 'GENERATION_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150019: {
        'codegen_method': 'public',
        'enum': 'ScriptTriggerType',
        'grpc_type': 'sint32',
        'name': 'SCRIPT_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150020: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150021: {
        'codegen_method': 'public',
        'enum': 'DigitalEdgeEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150022: {
        'codegen_method': 'public',
        'enum': 'AnySignalOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150023: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SELECTED_SCRIPT',
        'resettable': True,
        'type': 'ViString'
    },
    1150024: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PHASE_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150025: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_PRE_FILTER_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150026: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150027: {
        'codegen_method': 'public',
        'enum': 'LoopBandwidth',
        'grpc_type': 'sint32',
        'name': 'LOOP_BANDWIDTH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150029: {
        'codegen_method': 'public',
        'enum': 'ArbOnboardSampleClockMode',
        'grpc_type': 'sint32',
        'name': 'ARB_ONBOARD_SAMPLE_CLOCK_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150030: {
        'codegen_method': 'public',
        'enum': 'ArbSampleClockSource',
        'grpc_type': 'string',
        'name': 'ARB_SAMPLE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150031: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_SAMPLE_CLOCK_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150032: {
        'codegen_method': 'public',
        'enum': 'AnalogModulationType',
        'grpc_type': 'sint32',
        'name': 'ANALOG_MODULATION_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150033: {
        'codegen_method': 'public',
        'enum': 'AnalogModulationWaveformType',
        'grpc_type': 'sint32',
        'name': 'ANALOG_MODULATION_WAVEFORM_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150034: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ANALOG_MODULATION_WAVEFORM_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150035: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ANALOG_MODULATION_FM_DEVIATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150036: {
        'codegen_method': 'public',
        'enum': 'DigitalModulationType',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_MODULATION_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150037: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITAL_MODULATION_SYMBOL_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150038: {
        'codegen_method': 'public',
        'enum': 'DigitalModulationWaveformType',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_MODULATION_WAVEFORM_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150039: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_MODULATION_PRBS_ORDER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150040: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_MODULATION_PRBS_SEED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150041: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITAL_MODULATION_FSK_DEVIATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150042: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'DIRECT_DOWNLOAD',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150043: {
        'codegen_method': 'public',
        'enum': 'PowerLevelType',
        'grpc_type': 'sint32',
        'name': 'POWER_LEVEL_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150044: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DIGITAL_PATTERN',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150045: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'STREAMING_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150046: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'STREAMING_WAVEFORM_NAME',
        'resettable': True,
        'type': 'ViString'
    },
    1150047: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'STREAMING_SPACE_AVAILABLE_IN_WAVEFORM',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150048: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150052: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_WAVEFORM_SOFTWARE_SCALING_FACTOR',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150053: {
        'codegen_method': 'public',
        'enum': 'RefClockOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_REF_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150054: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150055: {
        'codegen_method': 'public',
        'enum': 'DigitalLevelActiveLevel',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150056: {
        'codegen_method': 'public',
        'enum': 'ArbFilterType',
        'grpc_type': 'sint32',
        'name': 'ARB_FILTER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150057: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_FILTER_ROOT_RAISED_COSINE_ALPHA',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150058: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'UPCONVERTER_CENTER_FREQUENCY_INCREMENT',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150059: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'UPCONVERTER_CENTER_FREQUENCY_INCREMENT_ANCHOR',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150060: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_FILTER_RAISED_COSINE_ALPHA',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150061: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'MEMORY_SIZE',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150062: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ANALOG_MODULATION_PM_DEVIATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150063: {
        'codegen_method': 'public',
        'enum': 'AnySignalOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_DONE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150064: {
        'codegen_method': 'public',
        'enum': 'AnySignalOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_MARKER_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150065: {
        'codegen_method': 'public',
        'enum': 'AnySignalOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_STARTED_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150066: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_OUT_POWER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150067: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_IN_POWER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150068: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150069: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IQ_IMPAIRMENT_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150070: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_I_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150071: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_Q_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150072: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_GAIN_IMBALANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150073: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_SKEW',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150075: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150076: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'EXTERNAL_CALIBRATION_RECOMMENDED_INTERVAL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150077: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'EXTERNAL_CALIBRATION_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150078: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXTERNAL_CALIBRATION_USER_DEFINED_INFO',
        'resettable': True,
        'type': 'ViString'
    },
    1150079: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'EXTERNAL_CALIBRATION_USER_DEFINED_INFO_MAX_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150081: {
        'codegen_method': 'public',
        'enum': 'IQOffsetUnits',
        'grpc_type': 'sint32',
        'name': 'IQ_OFFSET_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150082: {
        'codegen_method': 'public',
        'enum': 'FrequencySettlingUnits',
        'grpc_type': 'sint32',
        'name': 'FREQUENCY_SETTLING_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150083: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FREQUENCY_SETTLING',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150084: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MODULE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150085: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'EXTERNAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150086: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150087: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_PREFERRED_PACKET_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150088: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150089: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_OSCILLATOR_PHASE_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150096: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ACTIVE_CONFIGURATION_LIST',
        'resettable': True,
        'type': 'ViString'
    },
    1150097: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'ACTIVE_CONFIGURATION_LIST_STEP',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150098: {
        'codegen_method': 'public',
        'enum': 'ListStepTriggerType',
        'grpc_type': 'sint32',
        'name': 'CONFIGURATION_LIST_STEP_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150099: {
        'codegen_method': 'public',
        'enum': 'ConfigListTrigSource',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150100: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TIMER_EVENT_INTERVAL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150102: {
        'codegen_method': 'public',
        'enum': 'ConfigurationListRepeat',
        'grpc_type': 'sint32',
        'name': 'CONFIGURATION_LIST_REPEAT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150103: {
        'codegen_method': 'public',
        'enum': 'ConfigListTriggerDigEdgeEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150104: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CORRECTION_TEMPERATURE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150105: {
        'codegen_method': 'public',
        'enum': 'ConfigListTrigOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_CONFIGURATION_LIST_STEP_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150112: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'STARTED_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150113: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DONE_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150114: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'START_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150115: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MARKER_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150116: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SCRIPT_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150117: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'CONFIGURATION_LIST_STEP_TRIGGER_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150118: {
        'codegen_method': 'public',
        'enum': 'YIGMainCoil',
        'grpc_type': 'sint32',
        'name': 'YIG_MAIN_COIL_DRIVE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150122: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'CONFIGURATION_LIST_STEP_IN_PROGRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150123: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150124: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_ENDPOINT_SIZE',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150125: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_SPACE_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150126: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_MOST_SPACE_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150127: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_ENDPOINT_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150128: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_ENDPOINT_FULLNESS_START_TRIGGER_LEVEL',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150129: {
        'codegen_method': 'public',
        'enum': 'ConfigSettledEventOutputTerm',
        'grpc_type': 'string',
        'name': 'EXPORTED_CONFIGURATION_SETTLED_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150132: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PEAK_POWER_ADJUSTMENT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150133: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'REF_PLL_BANDWIDTH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150134: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INTERVAL',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150135: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INITIAL_CREDITS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150136: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SELF_CALIBRATION_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150137: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AMPLITUDE_SETTLING',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150140: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'STREAMING_WRITE_TIMEOUT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150141: {
        'codegen_method': 'public',
        'enum': 'PPAScriptInheritance',
        'grpc_type': 'sint32',
        'name': 'PEAK_POWER_ADJUSTMENT_INHERITANCE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150142: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SYNC_SCRIPT_TRIGGER_MASTER',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150143: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_SCRIPT_TRIGGER_DIST_LINE',
        'resettable': True,
        'type': 'ViString'
    },
    1150144: {
        'codegen_method': 'public',
        'enum': 'OutputPort',
        'grpc_type': 'sint32',
        'name': 'OUTPUT_PORT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150145: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_OUT_PORT_CARRIER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150146: {
        'codegen_method': 'public',
        'enum': 'IQOutPortTermConfig',
        'grpc_type': 'sint32',
        'name': 'IQ_OUT_PORT_TERMINAL_CONFIGURATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150147: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_OUT_PORT_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150148: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_OUT_PORT_COMMON_MODE_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150149: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_OUT_PORT_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150150: {
        'codegen_method': 'public',
        'enum': 'LoSource',
        'grpc_type': 'string',
        'name': 'LO_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150151: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_FREQUENCY_STEP_SIZE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150152: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'LO_PLL_FRACTIONAL_MODE_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150153: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'INTERPOLATION_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150154: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'EVENTS_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150155: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SYNC_START_TRIGGER_MASTER',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150156: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_START_TRIGGER_DIST_LINE',
        'resettable': True,
        'type': 'ViString'
    },
    1150157: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ARB_WAVEFORM_REPEAT_COUNT_IS_FINITE',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150158: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_WAVEFORM_REPEAT_COUNT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150160: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'UPCONVERTER_FREQUENCY_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150161: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_OUT_PORT_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150162: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'RF_BLANKING_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150163: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_OUT_PORT_LOAD_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150165: {
        'codegen_method': 'public',
        'enum': 'AnalogModulationFmNarrowbandIntegrator',
        'grpc_type': 'sint32',
        'name': 'ANALOG_MODULATION_FM_NARROWBAND_INTEGRATOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150166: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ANALOG_MODULATION_FM_SENSITIVITY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150167: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ANALOG_MODULATION_AM_SENSITIVITY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150168: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ANALOG_MODULATION_PM_SENSITIVITY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150173: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ATTENUATOR_SETTING',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150175: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'CONFIGURATION_LIST_IS_DONE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150180: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'SYNC_SAMPLE_CLOCK_MASTER',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150181: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_SAMPLE_CLOCK_DIST_LINE',
        'resettable': True,
        'type': 'ViString'
    },
    1150182: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AE_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150185: {
        'codegen_method': 'public',
        'enum': 'AmpPath',
        'grpc_type': 'sint32',
        'name': 'AMP_PATH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150186: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FPGA_BITFILE_PATH',
        'resettable': False,
        'type': 'ViString'
    },
    1150188: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'FAST_TUNING_OPTION',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150190: {
        'codegen_method': 'public',
        'enum': 'PulseModulationMode',
        'grpc_type': 'sint32',
        'name': 'PULSE_MODULATION_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150191: {
        'codegen_method': 'public',
        'enum': 'AnalogModulationFmBand',
        'grpc_type': 'sint32',
        'name': 'ANALOG_MODULATION_FM_BAND',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150192: {
        'codegen_method': 'public',
        'enum': 'AnalogModulationPmMode',
        'grpc_type': 'sint32',
        'name': 'ANALOG_MODULATION_PM_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150194: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'CONFIGURATION_SETTLED_EVENT_TERMINAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150195: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'ALC_CONTROL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150196: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'AUTO_POWER_SEARCH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150199: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150204: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_DIGITAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150206: {
        'codegen_method': 'public',
        'enum': 'MarkerEventOutputBehavior',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150207: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MARKER_EVENT_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150208: {
        'codegen_method': 'public',
        'enum': 'MarkerEventPulseWidthUnits',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150209: {
        'codegen_method': 'public',
        'enum': 'MarkerEventToggleInitialState',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150210: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MODULE_POWER_CONSUMPTION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150211: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FPGA_TEMPERATURE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150212: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMPERATURE_READ_INTERVAL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150217: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_IS_FINITE_GENERATION',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150218: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_NUMBER_OF_SAMPLES_TO_GENERATE',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150219: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_GENERATION_FIFO_SAMPLE_QUANTUM',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150220: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RELATIVE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150225: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150226: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEVICE_INSTANTANEOUS_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150228: {
        'codegen_method': 'public',
        'enum': 'OverflowErrorReporting',
        'grpc_type': 'sint32',
        'name': 'OVERFLOW_ERROR_REPORTING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150239: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'HOST_DMA_BUFFER_SIZE',
        'resettable': True,
        'type': 'ViInt64'
    },
    1150241: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SELECTED_PORTS',
        'resettable': True,
        'type': 'ViString'
    },
    1150242: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'LO_OUT_EXPORT_CONFIGURE_FROM_RFSA',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150243: {
        'codegen_method': 'public',
        'enum': 'RFInLoExportEnabled',
        'grpc_type': 'sint32',
        'name': 'RF_IN_LO_EXPORT_ENABLED',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150244: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'THERMAL_CORRECTION_TEMPERATURE_RESOLUTION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150248: {
        'codegen_method': 'public',
        'enum': 'UpconverterFrequencyOffsetMode',
        'grpc_type': 'sint32',
        'name': 'UPCONVERTER_FREQUENCY_OFFSET_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150249: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'AVAILABLE_PORTS',
        'resettable': False,
        'type': 'ViString'
    },
    1150251: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FPGA_TARGET_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1150252: {
        'codegen_method': 'public',
        'enum': 'DeembeddingType',
        'grpc_type': 'sint32',
        'name': 'DEEMBEDDING_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150253: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DEEMBEDDING_SELECTED_TABLE',
        'resettable': True,
        'type': 'ViString'
    },
    1150257: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LO_VCO_FREQUENCY_STEP_SIZE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150258: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'THERMAL_CORRECTION_HEADROOM_RANGE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150263: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WAVEFORM_IQ_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150264: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WAVEFORM_SIGNAL_BANDWIDTH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150265: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WAVEFORM_RUNTIME_SCALING',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150266: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WAVEFORM_PAPR',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150271: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FIXED_GROUP_DELAY_ACROSS_PORTS',
        'resettable': True,
        'type': 'ViString'
    },
    1150272: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'WAVEFORM_FILEPATH',
        'resettable': True,
        'type': 'ViString'
    },
    1150273: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'WRITE_WAVEFORM_BURST_DETECTION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150274: {
        'codegen_method': 'public',
        'enum': 'WriteWaveformBurstDetectionMode',
        'grpc_type': 'sint32',
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150275: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_QUIET_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150276: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_POWER_THRESHOLD',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150277: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WRITE_WAVEFORM_BURST_DETECTION_MINIMUM_BURST_TIME',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150278: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'WAVEFORM_RF_BLANKING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150289: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DEEMBEDDING_COMPENSATION_GAIN',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150290: {
        'codegen_method': 'public',
        'enum': 'LoadOptions',
        'grpc_type': 'sint32',
        'name': 'LOAD_CONFIGURATIONS_FROM_FILE_LOAD_OPTIONS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150291: {
        'codegen_method': 'public',
        'enum': 'ResetOptions',
        'grpc_type': 'sint32',
        'name': 'LOAD_CONFIGURATIONS_FROM_FILE_RESET_OPTIONS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150292: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'EXPORTED_REF_CLOCK_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150293: {
        'codegen_method': 'public',
        'enum': 'EnableValues',
        'grpc_type': 'sint32',
        'name': 'WRITE_WAVEFORM_NORMALIZATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150297: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'WAVEFORM_WAVEFORM_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150307: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'PULSE_MODULATION_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150308: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'PULSE_MODULATION_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150309: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_PULSE_MODULATION_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150310: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'EXPORTED_PULSE_MODULATION_EVENT_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150311: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SELECTED_PATH',
        'resettable': True,
        'type': 'ViString'
    },
    1150312: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'AVAILABLE_PATHS',
        'resettable': False,
        'type': 'ViString'
    },
    1152832: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'COMPENSATE_FOR_FILTER_GROUP_DELAY',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1154097: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'UPCONVERTER_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1154098: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'UPCONVERTER_CENTER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250001: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250002: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'POWER_LEVEL',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250004: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OUTPUT_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250051: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'PULSE_MODULATION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250322: {
        'codegen_method': 'public',
        'enum': 'RefClockRate',
        'grpc_type': 'double',
        'name': 'REF_CLOCK_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250401: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IQ_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250402: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_NOMINAL_VOLTAGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250404: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'IQ_SWAP_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250451: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'ARB_SELECTED_WAVEFORM',
        'resettable': True,
        'type': 'ViString'
    },
    1250452: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'IQ_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250453: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_FILTER_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250454: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_MAX_NUMBER_WAVEFORMS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250455: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_WAVEFORM_QUANTUM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250456: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_WAVEFORM_SIZE_MIN',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250457: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_WAVEFORM_SIZE_MAX',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250458: {
        'codegen_method': 'public',
        'enum': 'StartTriggerType',
        'grpc_type': 'sint32',
        'name': 'START_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250459: {
        'codegen_method': 'public',
        'enum': 'DigitalEdgeEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    }
}
