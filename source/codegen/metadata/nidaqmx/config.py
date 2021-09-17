# -*- coding: utf-8 -*-
config = {
    'api_version': '20.0.0',
    'c_header': 'NIDAQmx.h',
    'c_function_prefix': 'DAQmx',
    'service_class_prefix': 'NiDAQmx',
    'java_package': 'com.ni.grpc.nidaqmx',
    'csharp_namespace': 'NationalInstruments.Grpc.NiDAQmx',
    'namespace_component': 'nidaqmx',
    'close_function': 'ClearTask',
    'custom_types': [
        {
            'name': 'AnalogPowerUpChannelsAndState',
            'grpc_name': 'AnalogPowerUpChannelsAndState',
            'fields': [
                {
                    'type': 'const char[]',
                    'name': 'channelNames',
                },
                {
                    'type': 'double',
                    'name': 'state',
                },
                {
                    'type': 'int32',
                    'enum': 'PowerUpChannelType',
                    'name': 'channelType',
                }
            ]
        },
        {
            'name': 'WatchdogExpChannelsAndState',
            'grpc_name': 'WatchdogExpChannelsAndState',
            'fields': [
                {
                    'type': 'const char[]',
                    'name': 'lines',
                },
                {
                    'type': 'int32',
                    'enum': 'DigitalLineState',
                    'name': 'expState'
                }
            ]
        },
        {
            'name': 'DigitalPowerUpTypeAndChannel',
            'grpc_name': 'DigitalPowerUpTypeAndChannel',
            'fields': [
                {
                    'type': 'const char[]',
                    'name': 'channelName',
                },
                {
                    'type': 'int32',
                    'enum': 'PowerUpStates',
                    'name': 'state',
                }
            ]
        },
        {
            'name': 'DigitalPowerUpChannelsAndState',
            'grpc_name': 'DigitalPowerUpChannelsAndState',
            'fields': [
                {
                    'type': 'const char[]',
                    'name': 'channelNames',
                },
                {
                    'type': 'int32',
                    'enum': 'PowerUpStates',
                    'name': 'state',
                }
            ]
        },
        {
            'name': 'DigitalPullUpPullDownChannelsAndState',
            'grpc_name': 'DigitalPullUpPullDownChannelsAndState',
            'fields': [
                {
                    'type': 'const char[]',
                    'name': 'channelNames',
                },
                {
                    'type': 'int32',
                    'enum': 'ResistorState',
                    'name': 'state',
                }
            ]
        },
        {
            'name': 'AnalogPowerUpChannelAndType',
            'grpc_name': 'AnalogPowerUpChannelAndType',
            'fields': [
                {
                    'type': 'const char[]',
                    'name': 'channelName'
                },
                {
                    'type': 'int32',
                    'enum': 'PowerUpChannelType',
                    'name': 'channelType'
                }
            ]
        }
    ],
    'additional_headers': ['custom/nidaqmx_conversions.h'],
    'type_to_grpc_type': {
        'TaskHandle': 'nidevice_grpc.Session',
        'char[]': 'string',
        'float64': 'double',
        'bool32': 'bool',
        'int32': 'int32',
        'uInt32': 'uint32',
        'int16': 'int32',
        'uInt16': 'uint32',
        'int8': 'int32',
        'uInt8[]': 'bytes',
        'uInt64': 'uint64',
        'DAQmxDoneEventCallbackPtr': 'void',
        'DAQmxEveryNSamplesEventCallbackPtr': 'void',
        'DAQmxSignalEventCallbackPtr': 'void',
        'CVIAbsoluteTime': 'google.protobuf.Timestamp'
    },
    'split_attributes_by_type': True,
    'supports_raw_attributes': True,
    'code_readiness': 'NextRelease',
    'feature_toggles': {
        'nidaqmx.allow_undefined_attributes': 'Prototype' 
    },
    'driver_name': 'NI-DAQMX',
    'extra_errors_used': [
    ],
    'init_function': 'CreateTask',
    'resource_handle_type': 'TaskHandle',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nidaqmx',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nicaiu.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nicaiu.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nidaqmx',
    'session_class_description': 'An NI-DAQmx task',
    'session_handle_parameter_name': 'task'
}
