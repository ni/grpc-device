# -*- coding: utf-8 -*-
# This file is generated from NI-Dmm API metadata version 19.6.0d7
config = {
    'api_version': '19.6.0d7',
    'c_header': 'nidmm.h',
    'c_function_prefix': 'niDMM_',
    'service_class_prefix': 'NiDmm',
    'java_package': 'com.ni.grpc.dmm',
    'csharp_namespace': 'NationalInstruments.Grpc.Dmm',
    'namespace_component': 'nidmm',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'acquisition'
    },
    'custom_types': [
    ],
    'additional_headers': {'custom/ivi_errors.h': ['service.cpp']},
    'driver_name': 'NI-DMM',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithOptions',
    'status_ok': 'status >= 0',
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
    'repeated_capabilities': [
    ],
    'session_class_description': 'An NI-DMM session to a National Instruments Digital Multimeter',
    'session_handle_parameter_name': 'vi'
}
