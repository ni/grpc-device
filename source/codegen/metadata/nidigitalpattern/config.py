# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 22.8.0d9999
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '22.8.0d9999',
    'c_function_prefix': 'niDigital_',
    'c_header': 'niDigital.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.Digital',
    'custom_types': [
    ],
    'driver_name': 'NI-Digital Pattern Driver',
    'java_package': 'com.ni.grpc.nidigital',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nidigital',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niDigital_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niDigital_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'module_name': 'nidigital',
    'namespace_component': 'nidigitalpattern',
    'service_class_prefix': 'NiDigital',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
