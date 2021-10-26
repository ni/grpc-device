# -*- coding: utf-8 -*-
config = {
    'api_version': '21.0.0',
    'c_header': 'niRFSG.h',
    'c_function_prefix': 'niRFSG_',
    'service_class_prefix': 'NiRFSG',
    'java_package': 'com.ni.grpc.nirfsg',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFSG',
    'namespace_component': 'nirfsg',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'generation'
    },
    'custom_types': [],
    'code_readiness': 'NextRelease',
    'driver_name': 'NI-RFSG',
    'extra_errors_used': [
    ],
    'init_function': 'InitWithOptions',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfsg',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFSG_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFSG_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nirfsg',
    'session_class_description': 'An NI-RFSG session to a National Instruments RF Vector Signal Generator.',
    'session_handle_parameter_name': 'vi'
}
