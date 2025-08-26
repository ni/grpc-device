# -*- coding: utf-8 -*-
# This file is generated from NI-DMM API metadata version 25.8.0d9999
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '25.8.0d9999',
    'c_function_prefix': 'niDMM_',
    'c_header': 'nidmmRemoteDebug.h',
    'close_function': None,
    'csharp_namespace': 'NationalInstruments.Grpc.DmmRestricted',
    'custom_types': [
    ],
    'driver_name': 'NI-DMM-RESTRICTED',
    'is_restricted': True,
    'java_package': 'com.ni.grpc.dmmrestricted',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nidmm',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nidmm_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nidmm_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'module_name': 'nidmm_restricted',
    'namespace_component': 'nidmm_restricted',
    'service_class_prefix': 'NiDmmRestricted',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
