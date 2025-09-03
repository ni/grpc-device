# -*- coding: utf-8 -*-
config = {
    'api_version': '25.8.0',
    'c_header': 'niRFmxVNA.h',
    'c_function_prefix': 'RFmxVNA_',
    'service_class_prefix': 'NiRFmxVNA',
    'java_package': 'com.ni.grpc.nirfmxvna',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxVNA',
    'namespace_component': 'nirfmxvna',
    'close_function': 'Close',
    'custom_types': [],
    'additional_headers': {},
    'type_to_grpc_type': {
        "char[]": "string",
        "float32": "float",
        "float64": "double",
        "int16": "int32",
        "int32": "int32",
        "int64": "int64",
        "niRFmxInstrHandle": "nidevice_grpc.Session",
        "int8": "int32",
        "uInt16": "uint32",
        "uInt32": "uint32",
        "uInt64": "uint64",
        "uInt8": "uint32",
        "uInt8[]": "bytes",
        "NIComplexSingle": "nidevice_grpc.NIComplexNumberF32",
        "NIComplexDouble": "nidevice_grpc.NIComplexNumber",
    },
    'code_readiness': 'Release',
    'feature_toggles': {},
    'driver_name': 'NI-rfmxvna',
    'extra_errors_used': [
    ],
    'init_function': 'Initialize',
    'resource_handle_type': 'niRFmxInstrHandle',
    'status_ok': 'status >= 0',
    'windows_only': True,
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfmxvna',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxVNA.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFmxVNA.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nirfmxvna',
    'session_class_description': 'An NI-RFmxVNA instrument handle',
    'session_handle_parameter_name': 'instrumentHandle',
    'duplicate_resource_handles_allowed': True
}