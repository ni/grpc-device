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
    'resource_handle_type': ['FakeHandle', 'SecondarySessionHandle'],
    'status_ok': 'status >= 0',
    'additional_headers': { 'custom/nifake_non_ivi_errors.h': ['service.cpp'] },
    'custom_types': [
        {
            'name': 'StringAndEnum',
            'grpc_name': 'StringAndEnum',
            'fields': [
                {
                    'type': 'const char[]',
                    'name': 'channelName',
                },
                {
                    'type': 'int32',
                    'enum': 'BeautifulColor',
                    'name': 'color',
                },
                {
                    'type': 'double',
                    'name': 'powerUpState',
                },
            ]
        },
        {
            'name': 'StructWithCoercion_struct',
            'grpc_name': 'StructWithCoercion',
            'fields': [
                {
                    'type': 'myInt16',
                    'name': 'first',
                    'coerced': True
                },
                {
                    'type': 'myUInt16',
                    'name': 'second',
                    'coerced': True
                },
                {
                    'type': 'myInt8',
                    'name': 'third',
                    'coerced': True
                }
            ],
        }
    ],
    'type_to_grpc_type': {
        'FakeHandle': 'nidevice_grpc.Session',
        'char[]': 'string',
        'myInt16': 'int32',
        'myUInt16': 'uint32',
        'myInt8': 'int32',
        'myUInt8[]': 'bytes',
        'CallbackPtr': 'void'
    },
    'code_readiness': 'NextRelease',
    'feature_toggles': {
        'nifake_non_ivi.allow_undefined_attributes': 'Prototype' 
    },
    'split_attributes_by_type': True,
    'supports_raw_attributes': True,
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
    'linux_rt_support': False,
    'metadata_version': '2.0',
    'module_name': 'nifake_non_ivi',
    'session_class_description': 'An NI-FAKE driver that does not use IVI types',
    'session_handle_parameter_name': 'handle',
}
