# -*- coding: utf-8 -*-
# This file is generated from NI-FGEN API metadata version 20.0.0d5
config = {
    'api_version': '20.0.0d5',
    'c_header': 'niFgen.h',
    'c_function_prefix': 'niFgen_',
    'service_class_prefix': 'NiFgen',
    'java_package': 'com.ni.grpc.fgen',
    'csharp_namespace': 'NationalInstruments.Grpc.Fgen',
    'namespace_component': 'nifgen',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'AbortGeneration',
        'initiate_function': 'InitiateGeneration',
        'task': 'generation'
    },
    'custom_types': [
        { 
            'name': 'NIComplexNumber_struct',
            'grpc_name': 'NIComplexNumber',
            'fields': [
                {
                    'type': 'ViReal64',
                    'name': 'real',
                    'grpc_name': 'real'
                },
                {
                    'type': 'ViReal64',
                    'name': 'imaginary',
                    'grpc_name': 'imaginary'
                }
            ]
        },
        { 
            'name': 'NIComplexI16_struct',
            'grpc_name': 'NIComplexInt32',
            'fields': [
                {
                    'type': 'ViInt16',
                    'name': 'real',
                    'grpc_name': 'real'
                },
                {
                    'type': 'ViInt16',
                    'name': 'imaginary',
                    'grpc_name': 'imaginary'
                }
            ]
        }
    ],
    'driver_name': 'NI-FGEN',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitializeWithChannels',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nifgen',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niFgen_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niFgen_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '2.0',
    'module_name': 'nifgen',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        },
        {
            'prefix': 'ScriptTrigger',
            'python_name': 'script_triggers'
        },
        {
            'prefix': 'Marker',
            'python_name': 'markers'
        }
    ],
    'session_class_description': 'An NI-FGEN session to a National Instruments Signal Generator.',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': True,
}
