# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 20.5.0d7
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '20.5.0d7',
    'c_function_prefix': 'niScope_',
    'c_header': 'niScope.h',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'InitiateAcquisition',
        'task': 'acquisition'
    },
    'csharp_namespace': 'NationalInstruments.Grpc.Scope',
    'custom_types': [
        {
            'fields': [
                {
                    'grpc_name': 'absolute_initial_x',
                    'grpc_type': 'double',
                    'name': 'absoluteInitialX',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'relative_initial_x',
                    'grpc_type': 'double',
                    'name': 'relativeInitialX',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'x_increment',
                    'grpc_type': 'double',
                    'name': 'xIncrement',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'actual_samples',
                    'grpc_type': 'sint32',
                    'name': 'actualSamples',
                    'type': 'ViInt32'
                },
                {
                    'grpc_name': 'offset',
                    'grpc_type': 'double',
                    'name': 'offset',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'gain',
                    'grpc_type': 'double',
                    'name': 'gain',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'reserved1',
                    'grpc_type': 'double',
                    'name': 'reserved1',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'reserved2',
                    'grpc_type': 'double',
                    'name': 'reserved2',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'WaveformInfo',
            'name': 'niScope_wfmInfo'
        },
        {
            'fields': [
                {
                    'grpc_name': 'offset',
                    'grpc_type': 'double',
                    'name': 'offset',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'gain',
                    'grpc_type': 'double',
                    'name': 'gain',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'reserved1',
                    'grpc_type': 'double',
                    'name': 'reserved1',
                    'type': 'ViReal64'
                },
                {
                    'grpc_name': 'reserved2',
                    'grpc_type': 'double',
                    'name': 'reserved2',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'CoefficientInfo',
            'name': 'niScope_coefficientInfo'
        }
    ],
    'driver_name': 'NI-SCOPE',
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithOptions',
    'java_package': 'com.ni.grpc.scope',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'niscope',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niScope_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niScope_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'metadata_version': '2.0',
    'module_name': 'niscope',
    'namespace_component': 'niscope',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        }
    ],
    'service_class_prefix': 'NiScope',
    'session_class_description': 'An NI-SCOPE session to a National Instruments Digitizer.',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0',
    'uses_nitclk': True
}
