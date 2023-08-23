# -*- coding: utf-8 -*-
config = {
    'api_version': '23.5.0.49319-0+f167',
    'c_header': 'visa.h',
    'c_function_prefix': 'vi',
    'java_package': 'com.ni.grpc.nivisa',
    'csharp_namespace': 'NationalInstruments.Grpc.NiVISA',
    'close_function': 'Close',
    'custom_types': [],
    'additional_headers': {},
    'code_readiness': 'NextRelease',
    'driver_name': 'NI-VISA Library',
    'extra_errors_used': [
    ],
    'init_function': 'Open',
    'status_ok': 'status >= 0',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'visa',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'visa32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nivisa64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'metadata_version': '0.1',
    'module_name': 'nivisa',
    'namespace_component': 'nivisa',    
    'service_class_prefix': 'NiVISA',
    'session_handle_parameter_name': 'vi'
}
