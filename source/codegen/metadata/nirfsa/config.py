# -*- coding: utf-8 -*-
# This file is generated from NI-RFSA API metadata version 27.0.0d9999
config = {
    'api_version': '26.8.0',
    'c_header': 'niRFSA.h',
    'c_function_prefix': 'niRFSA_',
    'c_header': 'niRFSA.h',
    'close_function': 'Close',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFSA',
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
                }
            ],
            'grpc_name': 'CoefficientInfo',
            'name': 'niRFSA_coefficientInfo'
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
                    'grpc_type': 'int64',
                    'name': 'actualSamples',
                    'type': 'ViInt64'
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
                }
            ],
            'grpc_name': 'WaveformInfo',
            'name': 'niRFSA_wfmInfo'
        },
        {
            'fields': [
                {
                    'grpc_type': 'double',
                    'name': 'initialFrequency',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'double',
                    'name': 'frequencyIncrement',
                    'type': 'ViReal64'
                },
                {
                    'grpc_type': 'sint32',
                    'name': 'numberOfSpectralLines',
                    'type': 'ViInt32'
                }
            ],
            'grpc_name': 'SpectrumInfo',
            'name': 'niRFSA_spectrumInfo'
        }
    ],
    'driver_name': 'NI-RFSA',
    'java_package': 'com.ni.grpc.rfsa',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfsa',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFSA.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFSA_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'module_name': 'nirfsa',
    'namespace_component': 'nirfsa',
    'service_class_prefix': 'NiRFSA',
    'session_handle_parameter_name': 'vi',
    'status_ok': 'status >= 0'
}
