# -*- coding: utf-8 -*-
config = {
    'api_version': '26.0.0',
    'c_header': 'niWLANGeneration.h',  
    'c_function_prefix': 'niWLANG_',
    'service_class_prefix': 'NiRFmxWLANGen',
    'java_package': 'com.ni.grpc.nirfmxwlangen',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxWLANGen',
    'namespace_component': 'nirfmxwlangen',
    'close_function': 'CloseSession',
    'custom_types': [],
    'additional_headers': { 'custom/nirfmx_errors.h': ['service.cpp'],
    'niWLANGenerationRfsg.h': ['library.h', 'library.cpp', 'library_interface.h', 'compilation_test.cpp']},
    'type_to_grpc_type': {
        "char[]": "string",
        "float32": "float",
        "float64": "double",
        "int16": "int32",
        "int32": "int32",
        "int64": "int64",
        "int8": "int32",
        "uInt16": "uint32",
        "uInt32": "uint32",
        "uInt64": "uint64",
        "uInt8": "uint32",
        "uInt8[]": "bytes",
        "NIComplexSingle": "nidevice_grpc.NIComplexNumberF32",
        "NIComplexDouble": "nidevice_grpc.NIComplexNumber",
        "NIComplexNumber": "nidevice_grpc.NIComplexNumber",
        "niWLANGenerationSession": "nidevice_grpc.Session",
        "ViSession": "nidevice_grpc.Session"
    },
    'code_readiness': 'Release',
    'feature_toggles': {},
    'driver_name': 'NI-RFMXWLANGEN',
    'extra_errors_used': [],
    'init_function': 'OpenSession',
    'resource_handle_type': ['niWLANGenerationSession', 'ViSession'],
    'status_ok': 'status >= 0',
    'windows_only': True,
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfmxwlangen',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxWLANG.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niWLANG_net.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'metadata_version': '0.1',
    'module_name': 'nirfmxwlangen',
    'session_class_description': 'An RFmx WLANGen handle',
    'session_handle_parameter_name': 'session',
    'duplicate_resource_handles_allowed': True
}
