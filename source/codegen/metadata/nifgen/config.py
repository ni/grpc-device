config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '20.0.0d5',
    'c_function_prefix': 'niFgen_',
    'c_header': 'niFgen.h',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'AbortGeneration',
        'initiate_function': 'InitiateGeneration',
        'task': 'generation'
    },
    'csharp_namespace': 'NationalInstruments.Grpc.Fgen',
    'custom_types': [
    ],
    'driver_name': 'NI-FGEN',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitializeWithChannels',
    'java_package': 'com.ni.grpc.fgen',
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
    'linux_rt_support': False,
    'metadata_version': '2.0',
    'module_name': 'nifgen',
    'namespace_component': 'nifgen',
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
    'service_class_prefix': 'NiFgen',
    'session_class_description': 'An NI-FGEN session to a National Instruments Signal Generator.',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0',
    'uses_nitclk': True
}