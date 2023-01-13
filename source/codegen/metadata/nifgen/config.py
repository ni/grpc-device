# -*- coding: utf-8 -*-
# This file is generated from NI-FGEN API metadata version 23.0.0f157
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '23.0.0f157',
    'c_function_prefix': 'niFgen_',
    'c_header': 'niFgen.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.Fgen',
    'custom_types': [
    ],
    'driver_name': 'NI-FGEN',
    'java_package': 'com.ni.grpc.fgen',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nifgen',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niFgen_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niFgen_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'module_name': 'nifgen',
    'namespace_component': 'nifgen',
    'service_class_prefix': 'NiFgen',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
