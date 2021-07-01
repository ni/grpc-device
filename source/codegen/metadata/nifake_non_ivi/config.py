# -*- coding: utf-8 -*-
# An NI-FAKE driver that does not use IVI types
config = {
    'api_version': '1.2.0d9',
    'c_header': 'niFakeNonIvi.h',
    'c_function_prefix': 'niFakeNonIvi_',
    'service_class_prefix': 'NiFakeNonIvi',
    'java_package': 'com.ni.grpc.fakenonivi',
    'csharp_namespace': 'NationalInstruments.Grpc.FakeNonIvi',
    'namespace_component': 'nifake_non_ivi',
    'close_function': 'Close',
    'driver_name': 'NI-FAKE-NON-IVI',
    'resource_handle_type': 'FakeHandle',
    'custom_types': [],
    'type_to_grpc_type': {
        'FakeHandle': 'nidevice_grpc.Session',
        'const char*': 'string'
    },
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nifakenonivi',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nifakenonivi_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nifakenonivi_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '2.0',
    'module_name': 'nifake_non_ivi',
    'session_class_description': 'An NI-FAKE driver that does not use IVI types',
    'session_handle_parameter_name': 'handle',
}
