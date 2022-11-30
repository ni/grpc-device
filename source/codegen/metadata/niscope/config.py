# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 23.0.0d87
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    'api_version': '23.0.0d87',
    'c_function_prefix': 'niScope_',
    'c_header': 'niScopeCal.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.Scope',
    'custom_types': [
        {
            'fields': [
                {
                    'grpc_type': 'double',
                    'name': 'offset',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'gain',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved1',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved2',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'CoefficientInfo',
            'name': 'niScope_coefficientInfo'
        },
        {
            'fields': [
                {
                    'grpc_type': 'double',
                    'name': 'absoluteInitialX',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'relativeInitialX',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'xIncrement',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'sint32',
                    'name': 'actualSamples',
                    'type': 'ViInt32'
                },
                {
                    'grpc_type': 'double',
                    'name': 'offset',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'gain',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved1',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'reserved2',
                    'type': 'ViReal64'
                }
            ],
            'grpc_name': 'WaveformInfo',
            'name': 'niScope_wfmInfo'
        }
    ],
    'driver_name': 'NI-SCOPE',
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
    'module_name': 'niscope',
    'namespace_component': 'niscope',
    'service_class_prefix': 'NiScope',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
