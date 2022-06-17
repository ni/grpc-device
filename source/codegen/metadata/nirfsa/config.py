# -*- coding: utf-8 -*-
config = {
    'api_version': '21.0.0',
    'c_header': 'niRFSA.h',
    'c_function_prefix': 'niRFSA_',
    'service_class_prefix': 'NiRFSA',
    'java_package': 'com.ni.grpc.rfsa',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFSA',
    'namespace_component': 'nirfsa',
    'close_function': 'Close',
    'custom_types': [
        {
            'name': 'niRFSA_wfmInfo_struct',
            'grpc_name': 'WaveformInfo',
            'fields': [
                {
                    'type': 'ViReal64',
                    'name': 'absoluteInitialX'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'relativeInitialX'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'xIncrement'
                },
                {
                    'type': 'ViInt64', 
                    'name': 'actualSamples'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'offset'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'gain'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved1',
                    'include_in_proto': False,
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved2',
                    'include_in_proto': False,
                },
            ]
        },
        {
            'name': 'niRFSA_coefficientInfo_struct',
            'grpc_name': 'CoefficientInfo',
            'fields': [
                {
                    'type': 'ViReal64', 
                    'name': 'offset'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'gain'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved1',
                    'include_in_proto': False,
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved2',
                    'include_in_proto': False,
                },
            ]
        },
        {
            'name': 'niRFSA_spectrumInfo_struct',
            'grpc_name': 'SpectrumInfo',
            'fields': [
                {
                    'type': 'ViReal64', 
                    'name': 'initialFrequency'
                },
                {
                    'type': 'ViReal64', 
                    'name': 'frequencyIncrement'
                },
                {
                    'type': 'ViInt32', 
                    'name': 'numberOfSpectralLines'
                },
                
                {
                    'type': 'ViReal64', 
                    'name': 'reserved1',
                    'include_in_proto': False,
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved2',
                    'include_in_proto': False,
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved3',
                    'include_in_proto': False,
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved4',
                    'include_in_proto': False,
                },
                {
                    'type': 'ViReal64', 
                    'name': 'reserved5',
                    'include_in_proto': False,
                },
            ]
        }
    ],
    'additional_headers': { 'custom/nirfsa_aliases.h': ['service.cpp', 'library_interface.h'], 'custom/ivi_errors.h': ['service.cpp'] },
    'driver_name': 'NI-RFSA',
    'init_function': 'InitWithOptions',
    'status_ok': 'status >= 0',
    'code_readiness': 'Release',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfsa',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFSA_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFSA_64.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'metadata_version': '1.0',
    'module_name': 'nirfsa',
    'session_class_description': 'An NI-RFSA session.',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': True,
}
