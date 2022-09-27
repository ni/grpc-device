# -*- coding: utf-8 -*-
# This file is generated from NI-SWITCH API metadata version 22.8.0d130
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '22.8.0d130',
    'c_function_prefix': 'niSwitch_',
    'c_header': 'niswitch.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.Switch',
    'custom_types': [
    ],
    'driver_name': 'NI-SWITCH',
    'java_package': 'com.ni.grpc.niswitch',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'niswitch',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niswitch_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niswitch_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'module_name': 'niswitch',
    'namespace_component': 'niswitch',
    'service_class_prefix': 'NiSwitch',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
