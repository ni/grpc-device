# -*- coding: utf-8 -*-
# This file is generated from NI-SWITCH API metadata version 19.6.0d7
config = {
    'api_version': '19.6.0d7',
    'c_header': 'niswitch.h',
    'c_function_prefix': 'niSwitch_',
    'service_class_prefix': 'NiSwitch',
    'java_package': 'com.ni.grpc.niswitch',
    'csharp_namespace': 'NationalInstruments.Grpc.Switch',
    'namespace_component': 'niswitch',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'AbortScan',
        'initiate_function': 'InitiateScan',
        'task': 'scan'
    },
    'custom_types': [
    ],
    'additional_headers': {'custom/ivi_errors.h': ['service.cpp']},
    'driver_name': 'NI-SWITCH',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithTopology',
    'status_ok': 'status >= 0',
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
    'metadata_version': '2.0',
    'module_name': 'niswitch',
    'session_class_description': 'An NI-SWITCH session to a National Instruments Switch Module',
    'session_handle_parameter_name': 'vi'
}
