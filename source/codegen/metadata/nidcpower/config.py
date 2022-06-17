# -*- coding: utf-8 -*-
# This file is generated from NI-DCPower API metadata version 20.7.0d8
config = {
    'api_version': '20.7.0d8',
    'c_header': 'nidcpower.h',
    'c_function_prefix': 'niDCPower_',
    'service_class_prefix': 'NiDCPower',
    'java_package': 'com.ni.grpc.dcpower',
    'csharp_namespace': 'NationalInstruments.Grpc.DCPower',
    'namespace_component': 'nidcpower',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'acquisition'
    },
    'custom_types': [
    ],
    'additional_headers': {'custom/ivi_errors.h': ['service.cpp']},
    'driver_name': 'NI-DCPower',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitializeWithChannels',
    'status_ok': 'status >= 0',
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
    'metadata_version': '2.0',
    'module_name': 'nidcpower',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        }
    ],
    'session_class_description': 'An NI-DCPower session to a National Instruments Programmable Power Supply or Source Measure Unit.',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': False
}
