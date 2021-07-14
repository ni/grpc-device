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
    ],
    'type_to_grpc_type': {
        'TaskHandle': 'nidevice_grpc.Session',
        'const char[]': 'string',
        'char[]': 'string',
        'float64': 'double',
        'bool32': 'bool',
        'int32': 'int32',
        'uInt32': 'uint32',
        'int16': 'int32',
        'uInt16': 'uint32',
        'int8': 'int32',
        'uInt8[]': 'bytes'
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
                'type': 'cdll'
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
