# -*- coding: utf-8 -*-
# This file is generated from NI-FAKE API metadata version 23.0.0d9999
config = {
    'additional_headers': {
    },
    'api_version': '23.0.0',
    'c_function_prefix': 'niFake_',
    'c_header': 'niFake.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.Fake',
    'custom_types': [
        {
            'fields': [
                {
                    'grpc_type': 'string',
                    'name': 'stringArg',
                    'type': 'ViConstString'
                }
            ],
            'grpc_name': 'CustomNamedType',
            'name': 'namedType_custom'
        },
        {
            'fields': [
                {
                    'grpc_type': 'sint32',
                    'name': 'structInt',
                    'type': 'ViInt32'
                },
                {
                    'grpc_type': 'double',
                    'name': 'structDouble',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'FakeCustomStruct',
            'name': 'CustomStruct'
        },
        {
            'fields': [
                {
                    'grpc_type': 'FakeCustomStruct',
                    'name': 'structCustomStruct',
                    'type': 'struct CustomStruct'
                },
                {
                    'grpc_type': 'CustomStructTypedef',
                    'name': 'structCustomStructTypedef',
                    'type': 'struct CustomStructTypedef_struct'
                }
            ],
            'grpc_name': 'CustomStructNestedTypedef',
            'name': 'CustomStructNestedTypedef_struct'
        },
        {
            'fields': [
                {
                    'grpc_type': 'sint32',
                    'name': 'structInt',
                    'type': 'ViInt32'
                },
                {
                    'grpc_type': 'double',
                    'name': 'structDouble',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'CustomStructTypedef',
            'name': 'CustomStructTypedef_struct'
        },
        {
            'fields': [
                {
                    'grpc_type': 'string',
                    'name': 'stringArg',
                    'type': 'ViConstString'
                },
                {
                    'coerced': True,
                    'enum': 'Turtle',
                    'grpc_type': 'Turtle',
                    'name': 'turtle',
                    'type': 'ViInt16'
                }
            ],
            'grpc_name': 'StringAndTurtle',
            'name': 'StringAndTurtle'
        }
    ],
    'driver_name': 'NI-FAKE',
    'java_package': 'com.ni.grpc.fake',
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
    'linux_rt_support': False,
    'module_name': 'nifake',
    'namespace_component': 'nifake',
    'service_class_prefix': 'NiFake',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
