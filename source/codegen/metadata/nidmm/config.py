# -*- coding: utf-8 -*-
# This file is generated from NI-DMM API metadata version 19.6.0d7
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '19.6.0d7',
    'c_function_prefix': 'niDMM_',
    'c_header': 'nidmm.h',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'acquisition'
    },
    'csharp_namespace': 'NationalInstruments.Grpc.Dmm',
    'custom_types': [
    ],
    'driver_name': 'NI-DMM',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithOptions',
    'java_package': 'com.ni.grpc.dmm',
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
    'metadata_version': '2.0',
    'module_name': 'nidmm',
    'namespace_component': 'nidmm',
    'repeated_capabilities': [
    ],
    'service_class_prefix': 'NiDmm',
    'session_class_description': 'An NI-DMM session to a National Instruments Digital Multimeter',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
