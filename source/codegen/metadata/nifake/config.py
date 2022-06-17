# -*- coding: utf-8 -*-
# This file is generated from NI-FAKE API metadata version 1.2.0d9
config = {
    'api_version': '1.2.0d9',
    'c_header': 'niFake.h',
    'c_function_prefix': 'niFake_',
    'service_class_prefix': 'NiFake',
    'java_package': 'com.ni.grpc.fake',
    'csharp_namespace': 'NationalInstruments.Grpc.Fake',
    'namespace_component': 'nifake',
    'close_function': 'close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'acquisition'
    },
    'custom_types': [
        {
            'name': 'CustomStruct',
            'grpc_name': 'FakeCustomStruct',
            'fields': [
                {
                    'type': 'ViInt32',
                    'name': 'structInt',
                    'grpc_name': 'struct_int'
                },
                {
                    'type': 'ViReal64',
                    'name': 'structDouble',
                    'grpc_name': 'struct_double'
                }
            ]
        },
        {
            'name': 'StringAndTurtle',
            'grpc_name': 'StringAndTurtle',
            'fields': [
                {
                    'type': 'ViConstString',
                    'name': 'stringArg',
                },
                {
                    'type': 'ViInt16',
                    'enum': 'Turtle',
                    'name': 'turtle',
                    'coerced': True,
                }
            ]
        }
    ],
    'driver_name': 'NI-FAKE',
    'enum_whitelist_suffix': [
        '_POINT_FIVE'
    ],
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithOptions',
    'status_ok': 'status >= 0',
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
    'metadata_version': '2.0',
    'module_name': 'nifake',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        },
        {
            'prefix': 'site',
            'python_name': 'sites',
        },
    ],
    'session_class_description': 'An NI-FAKE session to a fake MI driver whose sole purpose is to test nimi-python code generation',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': True,
}
