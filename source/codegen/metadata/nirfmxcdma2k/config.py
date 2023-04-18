# -*- coding: utf-8 -*-
config = {
    'api_version': '23.0.0',
    'c_header': 'niRFmxCDMA2k.h',
    'c_function_prefix': 'RFmxCDMA2k_',
    'service_class_prefix': 'NiRFmxCDMA2k',
    'java_package': 'com.ni.grpc.nirfmxcdma2k',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxCDMA2k',
    'namespace_component': 'nirfmxcdma2k',
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
    'driver_name': 'NI-rfmxcdma2k',
    'extra_errors_used': [
    ],
    'init_function': 'Initialize',
    'resource_handle_type': 'niRFmxInstrHandle',
    'status_ok': 'status >= 0',
    'windows_only': True,
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfmxcdma2k',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxCDMA2k.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFmxCDMA2k.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nirfmxcdma2k',
    'session_class_description': 'An NI-RFmxCDMA2k instrument handle',
    'session_handle_parameter_name': 'instrumentHandle',
    'duplicate_resource_handles_allowed': True
}
