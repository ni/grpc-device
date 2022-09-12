# -*- coding: utf-8 -*- 
# This file is generated from NI-FAKE API metadata version 1.2.0d9
config = {
    'api_version': '1.2.0d9',
    'c_function_prefix': 'niFake_',
    'c_header': 'niFake.h',
    'close_function': 'close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'acquisition'
    },
    'csharp_namespace': 'NationalInstruments.Grpc.Fake',
    'custom_types': [
        {
            'fields': [
                {
                    'grpc_name': 'struct_int',
                    'name': 'structInt',
                    'type': 'ViInt32'
                },
                {
                    'grpc_name': 'struct_double',
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
                    'name': 'stringArg',
                    'type': 'ViConstString'
                },
                {
                    'coerced': True,
                    'enum': 'Turtle',
                    'name': 'turtle',
                    'type': 'ViInt16'
                }
            ],
            'grpc_name': 'StringAndTurtle',
            'name': 'StringAndTurtle'
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
    'metadata_version': '2.0',
    'module_name': 'nifake',
    'namespace_component': 'nifake',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        },
        {
            'prefix': 'site',
            'python_name': 'sites'
        }
    ],
    'service_class_prefix': 'NiFake',
    'session_class_description': 'An NI-FAKE session to a fake MI driver whose sole purpose is to test nimi-python code generation',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0',
    'uses_nitclk': True
}