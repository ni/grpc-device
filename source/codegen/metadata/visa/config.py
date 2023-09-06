# -*- coding: utf-8 -*-
config = {
    'additional_headers': {},
    'api_version': '23.0.0',
    'c_function_prefix': 'vi',
    'c_header': 'visa.h',
    'close_function': 'Close',
    'code_readiness': 'NextRelease',
    'csharp_namespace': 'NationalInstruments.Grpc.Visa',
    'custom_header_suffix': '_attributes.h',
    'custom_types': [],
    'driver_name': 'VISA',
    'extra_errors_used': [],
    'init_function': 'Open',
    'java_package': 'com.ni.grpc.visa',
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
                'name': 'visa64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'metadata_version': '0.1',
    'module_name': 'visa',
    'namespace_component': 'visa',
    'resource_handle_type': ['ViSession','ViObject'],
    'service_class_prefix': 'Visa',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
