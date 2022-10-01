# -*- coding: utf-8 -*-
# This file is generated from NI-DCPower API metadata version 23.0.0d43
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '23.0.0',
    'c_function_prefix': 'niDCPower_',
    'c_header': 'nidcpower.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.DCPower',
    'custom_types': [
    ],
    'driver_name': 'NI-DCPower',
    'java_package': 'com.ni.grpc.dcpower',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nidcpower',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nidcpower_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nidcpower_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'module_name': 'nidcpower',
    'namespace_component': 'nidcpower',
    'service_class_prefix': 'NiDCPower',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
