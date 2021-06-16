attributes = {
    1050002: {
        'access': 'read-write',
        'name': 'RANGE_CHECK',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050003: {
        'access': 'read-write',
        'name': 'QUERY_INSTRUMENT_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050004: {
        'access': 'read-write',
        'name': 'CACHE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050005: {
        'access': 'read-write',
        'name': 'SIMULATE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050006: {
        'access': 'read-write',
        'name': 'RECORD_COERCIONS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050007: {
        'access': 'read only',
        'name': 'DRIVER_SETUP',
        'resettable': True,
        'type': 'ViString'
    },
    1050021: {
        'access': 'read-write',
        'name': 'INTERCHANGE_CHECK',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050203: {
        'access': 'read only',
        'name': 'CHANNEL_COUNT',
        'type': 'ViInt32'
    },
    1050302: {
        'access': 'read only',
        'name': 'SPECIFIC_DRIVER_PREFIX',
        'resettable': False,
        'type': 'ViString'
    },
    1050304: {
        'access': 'read only',
        'name': 'IO_RESOURCE_DESCRIPTOR',
        'resettable': False,
        'type': 'ViString'
    },
    1050305: {
        'access': 'read only',
        'name': 'LOGICAL_NAME',
        'resettable': False,
        'type': 'ViString'
    },
    1050327: {
        'access': 'read only',
        'name': 'SUPPORTED_INSTRUMENT_MODELS',
        'resettable': False,
        'type': 'ViString'
    },
    1050401: {
        'access': 'read only',
        'name': 'GROUP_CAPABILITIES',
        'resettable': False,
        'type': 'ViString'
    },
    1050510: {
        'access': 'read only',
        'name': 'INSTRUMENT_FIRMWARE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1050511: {
        'access': 'read only',
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
        'name': 'SPECIFIC_DRIVER_VENDOR',
        'resettable': False,
        'type': 'ViString'
    },
    1050514: {
        'access': 'read only',
        'name': 'SPECIFIC_DRIVER_DESCRIPTION',
        'resettable': False,
        'type': 'ViString'
    },
    1050515: {
        'access': 'read only',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050516: {
        'access': 'read only',
        'name': 'SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050551: {
        'access': 'read only',
        'name': 'SPECIFIC_DRIVER_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150001: {
        'access': 'read only',
        'name': 'ID_QUERY_RESPONSE',
        'resettable': True,
        'type': 'ViString'
    },
    1150101: {
        'access': 'read-write',
        'name': 'DIGITAL_PATTERN_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150102: {
        'access': 'read-write',
        'name': 'DIGITAL_FILTER_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150103: {
        'access': 'read-write',
        'name': 'ANALOG_FILTER_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150104: {
        'access': 'read-write',
        'name': 'FILTER_CORRECTION_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150105: {
        'access': 'read-write',
        'name': 'SYNC_DUTY_CYCLE_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150107: {
        'access': 'read-write',
        'name': 'REF_CLOCK_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150108: {
        'access': 'read-write',
        'enum': 'TriggerMode',
        'name': 'TRIGGER_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150110: {
        'access': 'read-write',
        'enum': 'ClockMode',
        'name': 'CLOCK_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150111: {
        'access': 'read-write',
        'enum': 'SynchronizationSource',
        'name': 'SYNCHRONIZATION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150112: {
        'access': 'read-write',
        'name': 'SAMPLE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150113: {
        'access': 'read-write',
        'name': 'REFERENCE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150208: {
        'access': 'read-write',
        'name': 'FREQ_LIST_HANDLE',
        'enum': 'FrequencyListHandle',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150209: {
        'access': 'read only',
        'name': 'MAX_NUM_FREQ_LISTS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150210: {
        'access': 'read only',
        'name': 'MIN_FREQ_LIST_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150211: {
        'access': 'read only',
        'name': 'MAX_FREQ_LIST_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150212: {
        'access': 'read only',
        'name': 'MIN_FREQ_LIST_DURATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150213: {
        'access': 'read only',
        'name': 'MAX_FREQ_LIST_DURATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150214: {
        'access': 'read-write',
        'name': 'FREQ_LIST_DURATION_QUANTUM',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150215: {
        'access': 'read only',
        'enum': 'BusType',
        'name': 'BUS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150216: {
        'access': 'read-write',
        'enum': 'VideoWaveformType',
        'name': 'VIDEO_WAVEFORM_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150218: {
        'access': 'read-write',
        'name': 'DIGITAL_FILTER_INTERPOLATION_FACTOR',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150219: {
        'access': 'read-write',
        'name': 'EXPORTED_SAMPLE_CLOCK_DIVISOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150220: {
        'access': 'read-write',
        'enum': 'LoadImpedance',
        'name': 'LOAD_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150222: {
        'access': 'read-write',
        'enum': 'AnalogPath',
        'name': 'ANALOG_PATH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150230: {
        'access': 'read-write',
        'name': 'EXPORTED_SAMPLE_CLOCK_TIMEBASE_DIVISOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150231: {
        'access': 'read-write',
        'name': 'SAMPLE_CLOCK_ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150232: {
        'access': 'read-write',
        'name': 'OSCILLATOR_PHASE_DAC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150233: {
        'access': 'read-write',
        'name': 'EXTERNAL_CLOCK_DELAY_BINARY_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150234: {
        'access': 'read-write',
        'name': 'ANALOG_DATA_MASK',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150235: {
        'access': 'read-write',
        'name': 'ANALOG_STATIC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150236: {
        'access': 'read-write',
        'name': 'DIGITAL_DATA_MASK',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150237: {
        'access': 'read-write',
        'name': 'DIGITAL_STATIC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150238: {
        'access': 'read only',
        'name': 'FUNC_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150239: {
        'access': 'read-write',
        'name': 'FUNC_MAX_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150240: {
        'access': 'read-write',
        'name': 'FILE_TRANSFER_BLOCK_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150241: {
        'access': 'read-write',
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150242: {
        'access': 'read only',
        'name': 'MEMORY_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150243: {
        'access': 'read only',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150244: {
        'access': 'read-write',
        'name': 'DIRECT_DMA_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150245: {
        'access': 'read-write',
        'name': 'DIRECT_DMA_WINDOW_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150246: {
        'access': 'read-write',
        'name': 'OSP_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150247: {
        'access': 'read-write',
        'enum': 'DataProcessingMode',
        'name': 'OSP_DATA_PROCESSING_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150248: {
        'access': 'read-write',
        'name': 'OSP_IQ_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150249: {
        'access': 'read-write',
        'name': 'OSP_CARRIER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150250: {
        'access': 'read-write',
        'name': 'OSP_CARRIER_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150251: {
        'access': 'read-write',
        'name': 'OSP_CARRIER_PHASE_I',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150252: {
        'access': 'read-write',
        'name': 'OSP_CARRIER_PHASE_Q',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150253: {
        'access': 'read-write',
        'enum': 'FilterType',
        'name': 'OSP_FIR_FILTER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150254: {
        'access': 'read-write',
        'name': 'DIGITAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150255: {
        'access': 'read-write',
        'name': 'OSP_FIR_FILTER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150256: {
        'access': 'read-write',
        'name': 'OSP_FIR_FILTER_INTERPOLATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150257: {
        'access': 'read-write',
        'name': 'OSP_CIC_FILTER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150258: {
        'access': 'read-write',
        'name': 'OSP_CIC_FILTER_INTERPOLATION',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150259: {
        'access': 'read-write',
        'name': 'OSP_FIR_FILTER_ROOT_RAISED_COSINE_ALPHA',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150260: {
        'access': 'read-write',
        'name': 'OSP_FIR_FILTER_RAISED_COSINE_ALPHA',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150261: {
        'access': 'read-write',
        'name': 'OSP_FIR_FILTER_FLAT_PASSBAND',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150262: {
        'access': 'read-write',
        'name': 'OSP_FIR_FILTER_GAUSSIAN_BT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150263: {
        'access': 'read-write',
        'name': 'OSP_CIC_FILTER_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150264: {
        'access': 'read-write',
        'name': 'OSP_PRE_FILTER_GAIN_I',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150265: {
        'access': 'read-write',
        'name': 'OSP_PRE_FILTER_GAIN_Q',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150266: {
        'access': 'read-write',
        'name': 'OSP_PRE_FILTER_OFFSET_I',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150267: {
        'access': 'read-write',
        'name': 'OSP_PRE_FILTER_OFFSET_Q',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150268: {
        'access': 'read-write',
        'enum': 'OspOverflowErrorReporting',
        'name': 'OSP_OVERFLOW_ERROR_REPORTING',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150269: {
        'access': 'read-write',
        'name': 'OSP_OVERFLOW_STATUS',
        'resettable': True,
        'type': 'ViInt32',
        'enum': 'OspOverflowStatus'
    },
    1150270: {
        'access': 'read-write',
        'name': 'SCRIPT_TO_GENERATE',
        'resettable': False,
        'type': 'ViString'
    },
    1150271: {
        'access': 'read only',
        'name': 'MARKER_EVENTS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150272: {
        'access': 'read only',
        'name': 'SCRIPT_TRIGGERS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150273: {
        'access': 'read only',
        'name': 'DATA_MARKER_EVENTS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150274: {
        'access': 'read-write',
        'name': 'DIRECT_DMA_WINDOW_ADDRESS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150280: {
        'access': 'read-write',
        'enum': 'StartTriggerType',
        'name': 'START_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150281: {
        'access': 'read-write',
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150282: {
        'access': 'read-write',
        'enum': 'StartTriggerDigitalEdgeEdge',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150283: {
        'access': 'read-write',
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150290: {
        'access': 'read-write',
        'enum': 'ScriptTriggerType',
        'name': 'SCRIPT_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150291: {
        'access': 'read-write',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150292: {
        'access': 'read-write',
        'enum': 'ScriptTriggerDigitalEdgeEdge',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150293: {
        'access': 'read-write',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150294: {
        'access': 'read-write',
        'enum': 'ScriptTriggerDigitalLevelActiveLevel',
        'name': 'DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150295: {
        'access': 'read-write',
        'name': 'EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150310: {
        'access': 'read-write',
        'name': 'READY_FOR_START_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150311: {
        'access': 'read-write',
        'enum': 'ReadyForStartEventActiveLevel',
        'name': 'READY_FOR_START_EVENT_LEVEL_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150312: {
        'access': 'read-write',
        'name': 'MARKER_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150313: {
        'access': 'read-write',
        'enum': 'MarkerEventPulsePolarity',
        'name': 'MARKER_EVENT_PULSE_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150314: {
        'access': 'read-write',
        'name': 'STARTED_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150315: {
        'access': 'read-write',
        'name': 'DONE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150316: {
        'access': 'read-write',
        'enum': 'StartedEventActiveLevel',
        'name': 'STARTED_EVENT_LEVEL_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150317: {
        'access': 'read-write',
        'enum': 'DoneEventActiveLevel',
        'name': 'DONE_EVENT_LEVEL_ACTIVE_LEVEL',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150318: {
        'access': 'read-write',
        'enum': 'StartedEventPulsePolarity',
        'name': 'STARTED_EVENT_PULSE_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150319: {
        'access': 'read-write',
        'enum': 'DoneEventPulsePolarity',
        'name': 'DONE_EVENT_PULSE_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150320: {
        'access': 'read-write',
        'name': 'EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150321: {
        'access': 'read-write',
        'name': 'EXPORTED_REFERENCE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150322: {
        'access': 'read-write',
        'name': 'EXPORTED_ONBOARD_REFERENCE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150323: {
        'access': 'read-write',
        'name': 'FLATNESS_CORRECTION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150324: {
        'access': 'read-write',
        'name': 'STREAMING_WAVEFORM_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150325: {
        'access': 'read only',
        'name': 'STREAMING_SPACE_AVAILABLE_IN_WAVEFORM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150326: {
        'access': 'read-write',
        'name': 'STREAMING_WAVEFORM_NAME',
        'resettable': True,
        'type': 'ViString'
    },
    1150327: {
        'access': 'read-write',
        'name': 'ARB_MARKER_POSITION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150328: {
        'access': 'read-write',
        'name': 'ARB_REPEAT_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150329: {
        'access': 'read-write',
        'name': 'EXPORTED_SAMPLE_CLOCK_TIMEBASE_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150330: {
        'access': 'read-write',
        'name': 'SYNC_OUT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150331: {
        'access': 'read-write',
        'enum': 'StartedEventOutputBehavior',
        'name': 'STARTED_EVENT_OUTPUT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150332: {
        'access': 'read-write',
        'enum': 'DoneEventOutputBehavior',
        'name': 'DONE_EVENT_OUTPUT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150333: {
        'access': 'read-write',
        'enum': 'StartedEventPulseWidthUnits',
        'name': 'STARTED_EVENT_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150334: {
        'access': 'read-write',
        'enum': 'DoneEventPulseWidthUnits',
        'name': 'DONE_EVENT_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150335: {
        'access': 'read-write',
        'name': 'STARTED_EVENT_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150336: {
        'access': 'read-write',
        'name': 'DONE_EVENT_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150337: {
        'access': 'read-write',
        'name': 'DATA_MARKER_EVENT_DATA_BIT_NUMBER',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150338: {
        'access': 'read-write',
        'enum': 'DataMarkerEventLevelPolarity',
        'name': 'DATA_MARKER_EVENT_LEVEL_POLARITY',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150339: {
        'access': 'read-write',
        'name': 'DATA_MARKER_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150340: {
        'access': 'read-write',
        'name': 'MARKER_EVENT_PULSE_WIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150341: {
        'access': 'read-write',
        'enum': 'MarkerEventPulseWidthUnits',
        'name': 'MARKER_EVENT_PULSE_WIDTH_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150342: {
        'access': 'read-write',
        'enum': 'MarkerEventOutputBehavior',
        'name': 'MARKER_EVENT_OUTPUT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150343: {
        'access': 'read-write',
        'enum': 'MarkerEventToggleInitialState',
        'name': 'MARKER_EVENT_TOGGLE_INITIAL_STATE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150344: {
        'access': 'read only',
        'name': 'ALL_MARKER_EVENTS_LIVE_STATUS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150345: {
        'access': 'read only',
        'name': 'MARKER_EVENT_LIVE_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150348: {
        'access': 'read only',
        'name': 'READY_FOR_START_EVENT_LIVE_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150349: {
        'access': 'read-write',
        'name': 'ALL_MARKER_EVENTS_LATCHED_STATUS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150350: {
        'access': 'read-write',
        'name': 'MARKER_EVENT_LATCHED_STATUS',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150351: {
        'access': 'read only',
        'name': 'DONE_EVENT_LATCHED_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150352: {
        'access': 'read only',
        'name': 'STARTED_EVENT_LATCHED_STATUS',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150354: {
        'access': 'read-write',
        'name': 'MARKER_EVENT_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150355: {
        'access': 'read-write',
        'enum': 'MarkerEventDelayUnits',
        'name': 'MARKER_EVENT_DELAY_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150356: {
        'access': 'read-write',
        'name': 'STARTED_EVENT_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150357: {
        'access': 'read-write',
        'enum': 'StartedEventDelayUnits',
        'name': 'STARTED_EVENT_DELAY_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150358: {
        'access': 'read-write',
        'name': 'DONE_EVENT_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150359: {
        'access': 'read-write',
        'enum': 'DoneEventDelayUnits',
        'name': 'DONE_EVENT_DELAY_UNITS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150362: {
        'access': 'read-write',
        'name': 'PCI_DMA_OPTIMIZATIONS_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150365: {
        'access': 'read-write',
        'enum': 'TerminalConfiguration',
        'name': 'TERMINAL_CONFIGURATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150366: {
        'access': 'read-write',
        'name': 'COMMON_MODE_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150367: {
        'access': 'read-write',
        'name': 'SAMPLE_CLOCK_TIMEBASE_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150368: {
        'access': 'read-write',
        'name': 'SAMPLE_CLOCK_TIMEBASE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150369: {
        'access': 'read-write',
        'name': 'CHANNEL_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150370: {
        'access': 'read-write',
        'enum': 'OspMode',
        'name': 'OSP_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150371: {
        'access': 'read-write',
        'name': 'OSP_FREQUENCY_SHIFT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150373: {
        'access': 'read-write',
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150374: {
        'access': 'read-write',
        'name': 'DATA_TRANSFER_PREFERRED_PACKET_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150375: {
        'access': 'read-write',
        'name': 'DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150376: {
        'access': 'read-write',
        'name': 'EXTERNAL_SAMPLE_CLOCK_MULTIPLIER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150377: {
        'access': 'read-write',
        'enum': 'IdleBehavior',
        'name': 'IDLE_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150378: {
        'access': 'read-write',
        'name': 'IDLE_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150379: {
        'access': 'read-write',
        'enum': 'WaitBehavior',
        'name': 'WAIT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150380: {
        'access': 'read-write',
        'name': 'WAIT_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150389: {
        'access': 'read-write',
        'name': 'OSP_COMPENSATE_FOR_FILTER_GROUP_DELAY',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150390: {
        'access': 'read only',
        'name': 'MODULE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150391: {
        'access': 'read-write',
        'name': 'P2P_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150392: {
        'access': 'read-write',
        'name': 'P2P_DESTINATION_CHANNELS',
        'resettable': False,
        'type': 'ViString'
    },
    1150393: {
        'access': 'read only',
        'name': 'P2P_ENDPOINT_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150394: {
        'access': 'read only',
        'name': 'P2P_SPACE_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150395: {
        'access': 'read only',
        'name': 'P2P_MOST_SPACE_AVAILABLE_IN_ENDPOINT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150396: {
        'access': 'read only',
        'name': 'P2P_ENDPOINT_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150397: {
        'access': 'read-write',
        'name': 'P2P_MANUAL_CONFIGURATION_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150398: {
        'access': 'write only',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_ADDRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150399: {
        'access': 'read-write',
        'enum': 'AddressType',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_ADDRESS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150400: {
        'access': 'read-write',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INTERVAL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150401: {
        'access': 'read only',
        'name': 'P2P_ENDPOINT_WINDOW_ADDRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150402: {
        'access': 'read-write',
        'enum': 'AddressType',
        'name': 'P2P_ENDPOINT_WINDOW_ADDRESS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150403: {
        'access': 'read only',
        'name': 'P2P_ENDPOINT_WINDOW_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150405: {
        'access': 'read only',
        'name': 'P2P_DONE_NOTIFICATION_ADDRESS',
        'resettable': False,
        'type': 'ViInt64'
    },
    1150406: {
        'access': 'read-write',
        'enum': 'AddressType',
        'name': 'P2P_DONE_NOTIFICATION_ADDRESS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150407: {
        'access': 'read only',
        'name': 'P2P_DONE_NOTIFICATION_VALUE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150408: {
        'access': 'read-write',
        'name': 'P2P_DATA_TRANSFER_PERMISSION_INITIAL_CREDITS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150409: {
        'access': 'read-write',
        'name': 'STREAMING_WRITE_TIMEOUT',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150410: {
        'access': 'read-write',
        'name': 'P2P_ENDPOINT_FULLNESS_START_TRIGGER_LEVEL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150411: {
        'access': 'read-write',
        'name': 'AUX_POWER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150412: {
        'access': 'read only',
        'name': 'FPGA_BITFILE_PATH',
        'resettable': False,
        'type': 'ViString'
    },
    1150413: {
        'access': 'read-write',
        'name': 'ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250001: {
        'access': 'read-write',
        'enum': 'OutputMode',
        'name': 'OUTPUT_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250003: {
        'access': 'read-write',
        'name': 'OUTPUT_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250004: {
        'access': 'read-write',
        'enum': 'OutputImpedance',
        'name': 'OUTPUT_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250101: {
        'access': 'read-write',
        'enum': 'Waveform',
        'name': 'FUNC_WAVEFORM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250102: {
        'access': 'read-write',
        'name': 'FUNC_AMPLITUDE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250103: {
        'access': 'read-write',
        'name': 'FUNC_DC_OFFSET',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250104: {
        'access': 'read-write',
        'name': 'FUNC_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250105: {
        'access': 'read-write',
        'name': 'FUNC_START_PHASE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250106: {
        'access': 'read-write',
        'name': 'FUNC_DUTY_CYCLE_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250201: {
        'access': 'read-write',
        'name': 'ARB_WAVEFORM_HANDLE',
        'enum': 'ArbitraryWaveformHandle',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250202: {
        'access': 'read-write',
        'name': 'ARB_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250203: {
        'access': 'read-write',
        'name': 'ARB_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250204: {
        'access': 'read-write',
        'enum': 'SampleRate',
        'name': 'ARB_SAMPLE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250205: {
        'access': 'read only',
        'name': 'MAX_NUM_WAVEFORMS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250206: {
        'access': 'read only',
        'name': 'WAVEFORM_QUANTUM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250207: {
        'access': 'read only',
        'name': 'MIN_WAVEFORM_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250208: {
        'access': 'read only',
        'name': 'MAX_WAVEFORM_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250211: {
        'access': 'read-write',
        'name': 'ARB_SEQUENCE_HANDLE',
        'enum': 'ArbitrarySequenceHandle',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250212: {
        'access': 'read only',
        'name': 'MAX_NUM_SEQUENCES',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250213: {
        'access': 'read only',
        'name': 'MIN_SEQUENCE_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250214: {
        'access': 'read only',
        'name': 'MAX_SEQUENCE_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250215: {
        'access': 'read only',
        'name': 'MAX_LOOP_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250302: {
        'access': 'read-write',
        'enum': 'TriggerSource',
        'name': 'TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1250350: {
        'name': 'BURST_COUNT',
        'type': 'ViInt32',
        'enum': 'BurstCount'
    }
}
