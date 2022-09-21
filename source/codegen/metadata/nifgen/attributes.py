# -*- coding: utf-8 -*-
# This file is generated from NI-FGEN API metadata version 22.8.0d9999
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
        'resettable': True,
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
        'name': 'NUM_CHANNELS',
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
    1050503: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SPECIFIC_DRIVER_MAJOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050504: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SPECIFIC_DRIVER_MINOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'
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
        'name': 'ID_QUERY_RESPONSE',
        'resettable': True,
        'type': 'ViString'
    },
    1150101: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DIGITAL_PATTERN_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150102: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DIGITAL_FILTER_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150103: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'ANALOG_FILTER_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150104: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FILTER_CORRECTION_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150105: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SYNC_DUTY_CYCLE_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150106: {
        'codegen_method': 'public',
        'enum': 'UpdateClockSource',
        'grpc_type': 'sint32',
        'name': 'UPDATE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150107: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'REF_CLOCK_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150108: {
        'codegen_method': 'public',
        'enum': 'TriggerMode',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150110: {
        'codegen_method': 'public',
        'enum': 'ClockMode',
        'grpc_type': 'sint32',
        'name': 'CLOCK_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150111: {
        'codegen_method': 'public',
        'enum': 'SynchronizationSource',
        'grpc_type': 'sint32',
        'name': 'SYNCHRONIZATION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150112: {
        'codegen_method': 'public',
        'enum': 'SampleClockSource',
        'grpc_type': 'string',
        'name': 'SAMPLE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150113: {
        'codegen_method': 'public',
        'enum': 'ReferenceClockSource',
        'grpc_type': 'string',
        'name': 'REFERENCE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150208: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FREQ_LIST_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150209: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MAX_NUM_FREQ_LISTS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150210: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MIN_FREQ_LIST_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150211: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MAX_FREQ_LIST_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150212: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MIN_FREQ_LIST_DURATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150213: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MAX_FREQ_LIST_DURATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150214: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FREQ_LIST_DURATION_QUANTUM',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150215: {
        'codegen_method': 'public',
        'enum': 'BusType',
        'grpc_type': 'sint32',
        'name': 'BUS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150216: {
        'codegen_method': 'public',
        'enum': 'VideoWaveformType',
        'grpc_type': 'sint32',
        'name': 'VIDEO_WAVEFORM_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150218: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITAL_FILTER_INTERPOLATION_FACTOR',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150219: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'EXPORTED_SAMPLE_CLOCK_DIVISOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150220: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'LOAD_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150222: {
        'codegen_method': 'public',
        'enum': 'AnalogPath',
        'grpc_type': 'sint32',
        'name': 'ANALOG_PATH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150223: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'GAIN_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150224: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'OFFSET_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150225: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'OSCILLATOR_FREQ_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150227: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'CAL_ADC_INPUT',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150228: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'PRE_AMPLIFIER_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150229: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'POST_AMPLIFIER_ATTENUATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150230: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'EXPORTED_SAMPLE_CLOCK_TIMEBASE_DIVISOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150231: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SAMPLE_CLOCK_ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150232: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'OSCILLATOR_PHASE_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150233: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'EXTERNAL_CLOCK_DELAY_BINARY_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150234: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ANALOG_DATA_MASK',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150235: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ANALOG_STATIC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150236: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_DATA_MASK',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150237: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_STATIC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150238: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FUNC_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150239: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FUNC_MAX_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150240: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'FILE_TRANSFER_BLOCK_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150241: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150242: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MEMORY_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150243: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150244: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DIRECT_DMA_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150245: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DIRECT_DMA_WINDOW_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150246: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OSP_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150247: {
        'codegen_method': 'public',
        'enum': 'DataProcessingMode',
        'grpc_type': 'sint32',
        'name': 'OSP_DATA_PROCESSING_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150248: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_IQ_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150249: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OSP_CARRIER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150250: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_CARRIER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150251: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_CARRIER_PHASE_I',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150252: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_CARRIER_PHASE_Q',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150253: {
        'codegen_method': 'public',
        'enum': 'FilterType',
        'grpc_type': 'sint32',
        'name': 'OSP_FIR_FILTER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150254: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DIGITAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150255: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OSP_FIR_FILTER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150256: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_FIR_FILTER_INTERPOLATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150257: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OSP_CIC_FILTER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150258: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_CIC_FILTER_INTERPOLATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150259: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_FIR_FILTER_ROOT_RAISED_COSINE_ALPHA',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150260: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_FIR_FILTER_RAISED_COSINE_ALPHA',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150261: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_FIR_FILTER_FLAT_PASSBAND',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150262: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_FIR_FILTER_GAUSSIAN_BT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150263: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_CIC_FILTER_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150264: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_PRE_FILTER_GAIN_I',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150265: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_PRE_FILTER_GAIN_Q',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150266: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_PRE_FILTER_OFFSET_I',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150267: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_PRE_FILTER_OFFSET_Q',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150268: {
        'codegen_method': 'public',
        'enum': 'OspOverflowErrorReporting',
        'grpc_type': 'sint32',
        'name': 'OSP_OVERFLOW_ERROR_REPORTING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150269: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'OSP_OVERFLOW_STATUS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150270: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SCRIPT_TO_GENERATE',
        'resettable': False,
        'type': 'ViString'
    },
    1150271: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENTS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150272: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'SCRIPT_TRIGGERS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150273: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_MARKER_EVENTS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150274: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DIRECT_DMA_WINDOW_ADDRESS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150280: {
        'codegen_method': 'public',
        'enum': 'StartTriggerType',
        'grpc_type': 'sint32',
        'name': 'START_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150281: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150282: {
        'codegen_method': 'public',
        'enum': 'StartTriggerDigitalEdgeEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150283: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150290: {
        'codegen_method': 'public',
        'enum': 'ScriptTriggerType',
        'grpc_type': 'sint32',
        'name': 'SCRIPT_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150291: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150292: {
        'codegen_method': 'public',
        'enum': 'ScriptTriggerDigitalEdgeEdge',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150293: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150294: {
        'codegen_method': 'public',
        'enum': 'ScriptTriggerDigitalLevelActiveLevel',
        'grpc_type': 'sint32',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150295: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150310: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'READY_FOR_START_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150311: {
        'codegen_method': 'public',
        'enum': 'ReadyForStartEventActiveLevel',
        'grpc_type': 'sint32',
        'name': 'READY_FOR_START_EVENT_LEVEL_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150312: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MARKER_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150313: {
        'codegen_method': 'public',
        'enum': 'MarkerEventPulsePolarity',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_PULSE_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150314: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'STARTED_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150315: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DONE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150316: {
        'codegen_method': 'public',
        'enum': 'StartedEventActiveLevel',
        'grpc_type': 'sint32',
        'name': 'STARTED_EVENT_LEVEL_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150317: {
        'codegen_method': 'public',
        'enum': 'DoneEventActiveLevel',
        'grpc_type': 'sint32',
        'name': 'DONE_EVENT_LEVEL_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150318: {
        'codegen_method': 'public',
        'enum': 'StartedEventPulsePolarity',
        'grpc_type': 'sint32',
        'name': 'STARTED_EVENT_PULSE_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150319: {
        'codegen_method': 'public',
        'enum': 'DoneEventPulsePolarity',
        'grpc_type': 'sint32',
        'name': 'DONE_EVENT_PULSE_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150320: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150321: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_REFERENCE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150322: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_ONBOARD_REFERENCE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150323: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'FLATNESS_CORRECTION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150324: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'STREAMING_WAVEFORM_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150325: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'STREAMING_SPACE_AVAILABLE_IN_WAVEFORM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150326: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'STREAMING_WAVEFORM_NAME',
        'resettable': True,
        'type': 'ViString'
    },
    1150327: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_MARKER_POSITION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150328: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_REPEAT_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150329: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'EXPORTED_SAMPLE_CLOCK_TIMEBASE_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150330: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SYNC_OUT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150331: {
        'codegen_method': 'public',
        'enum': 'StartedEventOutputBehavior',
        'grpc_type': 'sint32',
        'name': 'STARTED_EVENT_OUTPUT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150332: {
        'codegen_method': 'public',
        'enum': 'DoneEventOutputBehavior',
        'grpc_type': 'sint32',
        'name': 'DONE_EVENT_OUTPUT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150333: {
        'codegen_method': 'public',
        'enum': 'StartedEventPulseWidthUnits',
        'grpc_type': 'sint32',
        'name': 'STARTED_EVENT_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150334: {
        'codegen_method': 'public',
        'enum': 'DoneEventPulseWidthUnits',
        'grpc_type': 'sint32',
        'name': 'DONE_EVENT_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150335: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'STARTED_EVENT_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150336: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DONE_EVENT_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150337: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_MARKER_EVENT_DATA_BIT_NUMBER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150338: {
        'codegen_method': 'public',
        'enum': 'DataMarkerEventLevelPolarity',
        'grpc_type': 'sint32',
        'name': 'DATA_MARKER_EVENT_LEVEL_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150339: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'DATA_MARKER_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150340: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MARKER_EVENT_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150341: {
        'codegen_method': 'public',
        'enum': 'MarkerEventPulseWidthUnits',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150342: {
        'codegen_method': 'public',
        'enum': 'MarkerEventOutputBehavior',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150343: {
        'codegen_method': 'public',
        'enum': 'MarkerEventToggleInitialState',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150344: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ALL_MARKER_EVENTS_LIVE_STATUS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150345: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'MARKER_EVENT_LIVE_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150348: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'READY_FOR_START_EVENT_LIVE_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150349: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ALL_MARKER_EVENTS_LATCHED_STATUS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150350: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'MARKER_EVENT_LATCHED_STATUS',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150351: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'DONE_EVENT_LATCHED_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150352: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'STARTED_EVENT_LATCHED_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150354: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'MARKER_EVENT_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150355: {
        'codegen_method': 'public',
        'enum': 'MarkerEventDelayUnits',
        'grpc_type': 'sint32',
        'name': 'MARKER_EVENT_DELAY_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150356: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'STARTED_EVENT_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150357: {
        'codegen_method': 'public',
        'enum': 'StartedEventDelayUnits',
        'grpc_type': 'sint32',
        'name': 'STARTED_EVENT_DELAY_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150358: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DONE_EVENT_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150359: {
        'codegen_method': 'public',
        'enum': 'DoneEventDelayUnits',
        'grpc_type': 'sint32',
        'name': 'DONE_EVENT_DELAY_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150362: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'PCI_DMA_OPTIMIZATIONS_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150365: {
        'codegen_method': 'public',
        'enum': 'TerminalConfiguration',
        'grpc_type': 'sint32',
        'name': 'TERMINAL_CONFIGURATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150366: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'COMMON_MODE_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150367: {
        'codegen_method': 'public',
        'enum': 'SampleClockTimebaseSource',
        'grpc_type': 'string',
        'name': 'SAMPLE_CLOCK_TIMEBASE_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150368: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SAMPLE_CLOCK_TIMEBASE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150369: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'CHANNEL_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150370: {
        'codegen_method': 'public',
        'enum': 'OspMode',
        'grpc_type': 'sint32',
        'name': 'OSP_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150371: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OSP_FREQUENCY_SHIFT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150373: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150374: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_PREFERRED_PACKET_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150375: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150376: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'EXTERNAL_SAMPLE_CLOCK_MULTIPLIER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150377: {
        'codegen_method': 'public',
        'enum': 'IdleBehavior',
        'grpc_type': 'sint32',
        'name': 'IDLE_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150378: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'IDLE_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150379: {
        'codegen_method': 'public',
        'enum': 'WaitBehavior',
        'grpc_type': 'sint32',
        'name': 'WAIT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150380: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'WAIT_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150389: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OSP_COMPENSATE_FOR_FILTER_GROUP_DELAY',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150390: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'MODULE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150391: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150392: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'P2P_DESTINATION_CHANNELS',
        'resettable': False,
        'type': 'ViString'
    },
    1150393: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_ENDPOINT_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150394: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_SPACE_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150395: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_MOST_SPACE_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150396: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_ENDPOINT_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150397: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'P2P_MANUAL_CONFIGURATION_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150398: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_ADDRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150399: {
        'codegen_method': 'public',
        'enum': 'P2PAddressType',
        'grpc_type': 'sint32',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_ADDRESS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150400: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INTERVAL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150401: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_ENDPOINT_WINDOW_ADDRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150402: {
        'codegen_method': 'public',
        'enum': 'P2PAddressType',
        'grpc_type': 'sint32',
        'name': 'P2P_ENDPOINT_WINDOW_ADDRESS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150403: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_ENDPOINT_WINDOW_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150405: {
        'codegen_method': 'public',
        'grpc_type': 'int64',
        'name': 'P2P_DONE_NOTIFICATION_ADDRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150406: {
        'codegen_method': 'public',
        'enum': 'P2PAddressType',
        'grpc_type': 'sint32',
        'name': 'P2P_DONE_NOTIFICATION_ADDRESS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150407: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_DONE_NOTIFICATION_VALUE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150408: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INITIAL_CREDITS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150409: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'STREAMING_WRITE_TIMEOUT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150410: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'P2P_ENDPOINT_FULLNESS_START_TRIGGER_LEVEL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150411: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'AUX_POWER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150412: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'FPGA_BITFILE_PATH',
        'resettable': False,
        'type': 'ViString'
    },
    1150413: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250001: {
        'codegen_method': 'public',
        'enum': 'OutputMode',
        'grpc_type': 'sint32',
        'name': 'OUTPUT_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250003: {
        'codegen_method': 'public',
        'grpc_type': 'bool',
        'name': 'OUTPUT_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250004: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OUTPUT_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250101: {
        'codegen_method': 'public',
        'enum': 'Waveform',
        'grpc_type': 'sint32',
        'name': 'FUNC_WAVEFORM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250102: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FUNC_AMPLITUDE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250103: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FUNC_DC_OFFSET',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250104: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FUNC_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250105: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FUNC_START_PHASE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250106: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FUNC_DUTY_CYCLE_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250201: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_WAVEFORM_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250202: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250203: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250204: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'ARB_SAMPLE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250205: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MAX_NUM_WAVEFORMS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250206: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'WAVEFORM_QUANTUM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250207: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MIN_WAVEFORM_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250208: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MAX_WAVEFORM_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250211: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'ARB_SEQUENCE_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250212: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MAX_NUM_SEQUENCES',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250213: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MIN_SEQUENCE_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250214: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MAX_SEQUENCE_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250215: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'MAX_LOOP_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250302: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250350: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'BURST_COUNT',
        'resettable': True,
        'type': 'ViInt32'
    }
}
