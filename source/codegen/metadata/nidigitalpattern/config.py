# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 19.5.0d7
config = {
    'api_version': '19.5.0d7',
    'c_header': 'niDigital.h',
    'c_function_prefix': 'niDigital_',
    'service_class_prefix': 'NiDigital',
    'java_package': 'com.ni.grpc.nidigital',
    'csharp_namespace': 'NationalInstruments.Grpc.Digital',
    'namespace_component': 'nidigitalpattern',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'burst'
    },
    'custom_types': [
    ],
    'driver_name': 'NI-Digital Pattern Driver',
    'enum_whitelist_suffix': [
    ],
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithOptions',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nidigital',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niDigital_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niDigital_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '2.0',
    'module_name': 'nidigitalpattern',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        },
        {
            'prefix': '',
            'python_name': 'pins'
        },
        {
            'prefix': '',
            'python_name': 'instruments'
        },
        {
            'prefix': 'patternOpcodeEvent',
            'python_name': 'pattern_opcode_events'
        },
        {
            'prefix': 'conditionalJumpTrigger',
            'python_name': 'conditional_jump_triggers'
        },
        {
            'prefix': 'site',
            'python_name': 'sites'
        },
    ],
    'session_class_description': 'An NI-Digital Pattern Driver session',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': True,
}
