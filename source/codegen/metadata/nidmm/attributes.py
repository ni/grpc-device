# -*- coding: utf-8 -*-
# This file is generated from NI-DMM API metadata version 22.8.0d9999
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
    1150002: {
        'codegen_method': 'public',
        'enum': 'MeasurementDestinationSlope',
        'grpc_type': 'sint32',
        'name': 'MEAS_DEST_SLOPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150003: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SHUNT_VALUE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150010: {
        'codegen_method': 'public',
        'enum': 'SampleTrigSlope',
        'grpc_type': 'sint32',
        'name': 'SAMPLE_TRIGGER_SLOPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150014: {
        'codegen_method': 'public',
        'enum': 'OperationMode',
        'grpc_type': 'sint32',
        'name': 'OPERATION_MODE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150018: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'WAVEFORM_RATE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150019: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'WAVEFORM_POINTS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150022: {
        'codegen_method': 'public',
        'enum': 'ADCCalibration',
        'grpc_type': 'sint32',
        'name': 'ADC_CALIBRATION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150023: {
        'codegen_method': 'public',
        'enum': 'OffsetCompensatedOhms',
        'grpc_type': 'sint32',
        'name': 'OFFSET_COMP_OHMS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150025: {
        'codegen_method': 'public',
        'enum': 'CurrentSource',
        'grpc_type': 'double',
        'name': 'CURRENT_SOURCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150026: {
        'codegen_method': 'public',
        'enum': 'DCNoiseRejection',
        'grpc_type': 'sint32',
        'name': 'DC_NOISE_REJECTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150027: {
        'codegen_method': 'public',
        'enum': 'WaveformCoupling',
        'grpc_type': 'sint32',
        'name': 'WAVEFORM_COUPLING',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150028: {
        'codegen_method': 'public',
        'enum': 'SettleTime',
        'grpc_type': 'double',
        'name': 'SETTLE_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150029: {
        'codegen_method': 'public',
        'enum': 'InputResistance',
        'grpc_type': 'double',
        'name': 'INPUT_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150032: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'NUMBER_OF_AVERAGES',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150034: {
        'codegen_method': 'public',
        'enum': 'Latency',
        'grpc_type': 'sint32',
        'name': 'LATENCY',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150037: {
        'codegen_method': 'public',
        'enum': 'BufferSize',
        'grpc_type': 'sint32',
        'name': 'BUFFER_SIZE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150044: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'FREQ_VOLTAGE_AUTO_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150045: {
        'codegen_method': 'public',
        'enum': 'CableCompensationType',
        'grpc_type': 'sint32',
        'name': 'CABLE_COMP_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150046: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SHORT_CABLE_COMP_REACTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150047: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'SHORT_CABLE_COMP_RESISTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150048: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OPEN_CABLE_COMP_SUSCEPTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150049: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'OPEN_CABLE_COMP_CONDUCTANCE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150052: {
        'codegen_method': 'public',
        'enum': 'LCCalculationModel',
        'grpc_type': 'sint32',
        'name': 'LC_CALCULATION_MODEL',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150053: {
        'codegen_method': 'public',
        'enum': 'DCBias',
        'grpc_type': 'sint32',
        'name': 'DC_BIAS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150054: {
        'codegen_method': 'public',
        'grpc_type': 'string',
        'name': 'SERIAL_NUMBER',
        'resettable': False,
        'type': 'ViString'
    },
    1150055: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'LC_NUMBER_MEAS_TO_AVERAGE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150061: {
        'codegen_method': 'public',
        'grpc_type': 'sint32',
        'name': 'INSTRUMENT_PRODUCT_ID',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150120: {
        'codegen_method': 'public',
        'enum': 'RTDType',
        'grpc_type': 'sint32',
        'name': 'TEMP_RTD_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150121: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_RTD_A',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150122: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_RTD_B',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150123: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_RTD_C',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150124: {
        'codegen_method': 'public',
        'enum': 'ThermistorType',
        'grpc_type': 'sint32',
        'name': 'TEMP_THERMISTOR_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1150125: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_THERMISTOR_A',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150126: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_THERMISTOR_B',
        'resettable': False,
        'type': 'ViReal64'
    },
    1150127: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_THERMISTOR_C',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250001: {
        'codegen_method': 'public',
        'enum': 'Function',
        'grpc_type': 'sint32',
        'name': 'FUNCTION',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250002: {
        'codegen_method': 'public',
        'enum': 'Range',
        'grpc_type': 'double',
        'name': 'RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250003: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RESOLUTION_DIGITS',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250004: {
        'codegen_method': 'public',
        'enum': 'TriggerSource',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_SOURCE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250005: {
        'codegen_method': 'public',
        'enum': 'TriggerDelays',
        'grpc_type': 'double',
        'name': 'TRIGGER_DELAY',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250006: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AC_MIN_FREQ',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250007: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AC_MAX_FREQ',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250008: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'RESOLUTION_ABSOLUTE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250101: {
        'codegen_method': 'public',
        'enum': 'FrequencyVoltageRange',
        'grpc_type': 'double',
        'name': 'FREQ_VOLTAGE_RANGE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250201: {
        'codegen_method': 'public',
        'enum': 'TransducerType',
        'grpc_type': 'sint32',
        'name': 'TEMP_TRANSDUCER_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250231: {
        'codegen_method': 'public',
        'enum': 'ThermocoupleType',
        'grpc_type': 'sint32',
        'name': 'TEMP_TC_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250232: {
        'codegen_method': 'public',
        'enum': 'ThermocoupleReferenceJunctionType',
        'grpc_type': 'sint32',
        'name': 'TEMP_TC_REF_JUNC_TYPE',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250233: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_TC_FIXED_REF_JUNC',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250242: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'TEMP_RTD_RES',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250301: {
        'codegen_method': 'public',
        'enum': 'SampleCount',
        'grpc_type': 'sint32',
        'name': 'SAMPLE_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250302: {
        'codegen_method': 'public',
        'enum': 'SampleTrigger',
        'grpc_type': 'sint32',
        'name': 'SAMPLE_TRIGGER',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250303: {
        'codegen_method': 'public',
        'enum': 'SampleInterval',
        'grpc_type': 'double',
        'name': 'SAMPLE_INTERVAL',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250304: {
        'codegen_method': 'public',
        'enum': 'TriggerCount',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_COUNT',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250305: {
        'codegen_method': 'public',
        'enum': 'MeasurementCompleteDest',
        'grpc_type': 'sint32',
        'name': 'MEAS_COMPLETE_DEST',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250321: {
        'codegen_method': 'public',
        'enum': 'ApertureTime',
        'grpc_type': 'double',
        'name': 'APERTURE_TIME',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250322: {
        'codegen_method': 'public',
        'enum': 'ApertureTimeUnits',
        'grpc_type': 'sint32',
        'name': 'APERTURE_TIME_UNITS',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250331: {
        'codegen_method': 'public',
        'grpc_type': 'double',
        'name': 'AUTO_RANGE_VALUE',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250332: {
        'codegen_method': 'public',
        'enum': 'AutoZero',
        'grpc_type': 'sint32',
        'name': 'AUTO_ZERO',
        'resettable': False,
        'type': 'ViInt32'
    },
    1250333: {
        'codegen_method': 'public',
        'enum': 'PowerlineFrequency',
        'grpc_type': 'double',
        'name': 'POWERLINE_FREQ',
        'resettable': False,
        'type': 'ViReal64'
    },
    1250334: {
        'codegen_method': 'public',
        'enum': 'TriggerSlope',
        'grpc_type': 'sint32',
        'name': 'TRIGGER_SLOPE',
        'resettable': False,
        'type': 'ViInt32'
    }
}
