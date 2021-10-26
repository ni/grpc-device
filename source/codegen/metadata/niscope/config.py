# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 20.5.0d7
config = {
    'api_version': '20.5.0d7',
    'c_header': 'niScope.h',
    'c_function_prefix': 'niScope_',
    'service_class_prefix': 'NiScope',
    'java_package': 'com.ni.grpc.scope',
    'csharp_namespace': 'NationalInstruments.Grpc.Scope',
    'namespace_component': 'niscope',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'InitiateAcquisition',
        'task': 'acquisition'
    },
    'custom_types': [],
    'driver_name': 'NI-SCOPE',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithOptions',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'niscope',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niScope_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niScope_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '2.0',
    'module_name': 'niscope',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        }
    ],
    'session_class_description': 'An NI-SCOPE session to a National Instruments Digitizer.',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': True,
}
