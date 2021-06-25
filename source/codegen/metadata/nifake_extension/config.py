# -*- coding: utf-8 -*-
# An NI-FAKE Extension that adds fake features to ni-fake sessions
config = {
    'api_version': '1.2.0d9',
    'c_header': 'niFake.h',
    'c_function_prefix': 'niFakeExtension_',
    'service_class_prefix': 'NiFakeExtension',
    'java_package': 'com.ni.grpc.fakeextension',
    'csharp_namespace': 'NationalInstruments.Grpc.FakeExtension',
    'namespace_component': 'nifake_extension',
    'close_function': None,
    'driver_name': 'NI-FAKE-EXTENSION',
    'custom_types': [],
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nifake',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nifake_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nifake_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '2.0',
    'module_name': 'nifake_extension',
    'session_class_description': 'An NI-FAKE Extension that adds fake features to ni-fake sessions',
    'session_handle_parameter_name': 'vi',
}
