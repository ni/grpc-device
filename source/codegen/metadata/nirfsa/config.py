# -*- coding: utf-8 -*-
config = {
    'api_version': '21.0.0',
    'c_header': 'niRFSA.h',
    'c_function_prefix': 'niRFSA_',
    'service_class_prefix': 'NiRFSA',
    'java_package': 'com.ni.grpc.rfsa',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFSA',
    'namespace_component': 'nirfsa',
    'close_function': 'Close',
    'custom_types': [
    ],
    'driver_name': 'NI-RFSA',
    'init_function': 'InitWithOptions',
    'code_readiness': 'NextRelease',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfsa',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFSA_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFSA_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '1.0',
    'module_name': 'nirfsa',
    'session_class_description': 'An NI-RFSA session.',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': True,
}
