# -*- coding: utf-8 -*-
# This file is generated from NI-FGEN API metadata version 20.0.0d5
attributes = {
    1050005: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'SIMULATE',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1050007: {
        'access': 'read only',
        'channel_based': False,
        'name': 'DRIVER_SETUP',
        'resettable': True,
        'type': 'ViString'
    },
    1050203: {
        'access': 'read only',
        'channel_based': False,
        'name': 'NUM_CHANNELS',
        'python_name': 'channel_count',
        'resettable': False,
        'type': 'ViInt32'
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
    1050503: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_MAJOR_VERSION',
        'python_name': 'major_version',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050504: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_MINOR_VERSION',
        'python_name': 'minor_version',
        'resettable': False,
        'type': 'ViInt32'
    },
    1050510: {
        'access': 'read only',
        'channel_based': False,
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
        'channel_based': False,
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
    1050551: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SPECIFIC_DRIVER_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150101: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_PATTERN_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150102: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_FILTER_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150103: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ANALOG_FILTER_ENABLED',
        'resettable': False,
        'type': 'ViBoolean'
    },
    1150104: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FILTER_CORRECTION_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150107: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'REF_CLOCK_FREQUENCY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150108: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'TriggerMode',
        'name': 'TRIGGER_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150110: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'ClockMode',
        'name': 'CLOCK_MODE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150112: {
        'access': 'read-write',
        'channel_based': False,
        #'enum': 'SampleClockSource',
        'name': 'SAMPLE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150113: {
        'access': 'read-write',
        'channel_based': False,
        # 'enum': 'ReferenceClockSource',
        'name': 'REFERENCE_CLOCK_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150208: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FREQ_LIST_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150209: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_NUM_FREQ_LISTS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150210: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MIN_FREQ_LIST_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150211: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_FREQ_LIST_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150212: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MIN_FREQ_LIST_DURATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150213: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_FREQ_LIST_DURATION',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150214: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FREQ_LIST_DURATION_QUANTUM',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150215: {
        'access': 'read only',
        'channel_based': False,
        'enum': 'BusType',
        'name': 'BUS_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150218: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_FILTER_INTERPOLATION_FACTOR',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150219: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_SAMPLE_CLOCK_DIVISOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150220: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'LOAD_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150222: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'AnalogPath',
        'name': 'ANALOG_PATH',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150230: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_SAMPLE_CLOCK_TIMEBASE_DIVISOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150233: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXTERNAL_CLOCK_DELAY_BINARY_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150234: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ANALOG_DATA_MASK',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150235: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ANALOG_STATIC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150236: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_DATA_MASK',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150237: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_STATIC_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150238: {
        'access': 'read only',
        'channel_based': False,
        'name': 'FUNC_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150239: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FUNC_MAX_BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150240: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FILE_TRANSFER_BLOCK_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150241: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DATA_TRANSFER_BLOCK_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150242: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MEMORY_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150243: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150254: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150270: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'SCRIPT_TO_GENERATE',
        'resettable': False,
        'type': 'ViString'
    },
    1150271: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MARKER_EVENTS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150272: {
        'access': 'read only',
        'channel_based': False,
        'name': 'SCRIPT_TRIGGERS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150273: {
        'access': 'read only',
        'channel_based': False,
        'name': 'DATA_MARKER_EVENTS_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150280: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'StartTriggerType',
        'name': 'START_TRIGGER_TYPE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150281: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_EDGE_START_TRIGGER_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150282: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'StartTriggerDigitalEdgeEdge',
        'name': 'DIGITAL_EDGE_START_TRIGGER_EDGE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150283: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_START_TRIGGER_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150290: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'ScriptTriggerType',
        'name': 'SCRIPT_TRIGGER_TYPE',
        'repeated_capability_type': 'script_triggers',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150291: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE',
        'repeated_capability_type': 'script_triggers',
        'resettable': True,
        'type': 'ViString'
    },
    1150292: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'ScriptTriggerDigitalEdgeEdge',
        'name': 'DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE',
        'repeated_capability_type': 'script_triggers',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150295: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL',
        'repeated_capability_type': 'script_triggers',
        'resettable': True,
        'type': 'ViString'
    },
    1150310: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'READY_FOR_START_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150312: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'MARKER_EVENT_OUTPUT_TERMINAL',
        'repeated_capability_type': 'markers',
        'resettable': True,
        'type': 'ViString'
    },
    1150314: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'STARTED_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150315: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DONE_EVENT_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150320: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150321: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_REFERENCE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150322: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_ONBOARD_REFERENCE_CLOCK_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150323: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FLATNESS_CORRECTION_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150324: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'STREAMING_WAVEFORM_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150325: {
        'access': 'read only',
        'channel_based': False,
        'name': 'STREAMING_SPACE_AVAILABLE_IN_WAVEFORM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150326: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'STREAMING_WAVEFORM_NAME',
        'resettable': True,
        'type': 'ViString'
    },
    1150327: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ARB_MARKER_POSITION',
        'repeated_capability_type': 'markers',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150328: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ARB_REPEAT_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150329: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXPORTED_SAMPLE_CLOCK_TIMEBASE_OUTPUT_TERMINAL',
        'resettable': True,
        'type': 'ViString'
    },
    1150337: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DATA_MARKER_EVENT_DATA_BIT_NUMBER',
        'repeated_capability_type': 'markers',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150338: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'DataMarkerEventLevelPolarity',
        'name': 'DATA_MARKER_EVENT_LEVEL_POLARITY',
        'repeated_capability_type': 'markers',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150339: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DATA_MARKER_EVENT_OUTPUT_TERMINAL',
        'repeated_capability_type': 'markers',
        'resettable': True,
        'type': 'ViString'
    },
    1150344: {
        'access': 'read only',
        'channel_based': False,
        'name': 'ALL_MARKER_EVENTS_LIVE_STATUS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150349: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ALL_MARKER_EVENTS_LATCHED_STATUS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150365: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'TerminalConfiguration',
        'name': 'TERMINAL_CONFIGURATION',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150366: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'COMMON_MODE_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150367: {
        'access': 'read-write',
        'channel_based': False,
        #'enum': 'SampleClockTimebaseSource',
        'name': 'SAMPLE_CLOCK_TIMEBASE_SOURCE',
        'resettable': True,
        'type': 'ViString'
    },
    1150368: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'SAMPLE_CLOCK_TIMEBASE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150369: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'CHANNEL_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150373: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DATA_TRANSFER_MAXIMUM_BANDWIDTH',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150374: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DATA_TRANSFER_PREFERRED_PACKET_SIZE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150375: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150376: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'EXTERNAL_SAMPLE_CLOCK_MULTIPLIER',
        'resettable': True,
        'type': 'ViReal64'
    },
    1150377: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'IdleBehavior',
        'name': 'IDLE_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150378: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'IDLE_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150379: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'WaitBehavior',
        'name': 'WAIT_BEHAVIOR',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150380: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'WAIT_VALUE',
        'resettable': True,
        'type': 'ViInt32'
    },
    1150390: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MODULE_REVISION',
        'resettable': False,
        'type': 'ViString'
    },
    1150409: {
        'access': 'read-write',
        'attribute_class': 'AttributeViReal64TimeDeltaSeconds',
        'channel_based': False,
        'name': 'STREAMING_WRITE_TIMEOUT',
        'resettable': True,
        'type': 'ViReal64',
        'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds'
    },
    1150411: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'AUX_POWER_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1150412: {
        'access': 'read only',
        'channel_based': False,
        'name': 'FPGA_BITFILE_PATH',
        'resettable': False,
        'type': 'ViString'
    },
    1150413: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ABSOLUTE_DELAY',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250001: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'OutputMode',
        'lv_property': 'Output:Output Mode',
        'name': 'OUTPUT_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250003: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'OUTPUT_ENABLED',
        'resettable': True,
        'type': 'ViBoolean'
    },
    1250004: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'OUTPUT_IMPEDANCE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250101: {
        'access': 'read-write',
        'channel_based': False,
        'enum': 'Waveform',
        'name': 'FUNC_WAVEFORM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250102: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FUNC_AMPLITUDE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250103: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FUNC_DC_OFFSET',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250104: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FUNC_FREQUENCY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250105: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FUNC_START_PHASE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250106: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'FUNC_DUTY_CYCLE_HIGH',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250201: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ARB_WAVEFORM_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250202: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ARB_GAIN',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250203: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ARB_OFFSET',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250204: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ARB_SAMPLE_RATE',
        'resettable': True,
        'type': 'ViReal64'
    },
    1250205: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_NUM_WAVEFORMS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250206: {
        'access': 'read only',
        'channel_based': False,
        'name': 'WAVEFORM_QUANTUM',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250207: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MIN_WAVEFORM_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250208: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_WAVEFORM_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250211: {
        'access': 'read-write',
        'channel_based': False,
        'name': 'ARB_SEQUENCE_HANDLE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250212: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_NUM_SEQUENCES',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250213: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MIN_SEQUENCE_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250214: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_SEQUENCE_LENGTH',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250215: {
        'access': 'read only',
        'channel_based': False,
        'name': 'MAX_LOOP_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    }
}

