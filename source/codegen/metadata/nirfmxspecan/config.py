# -*- coding: utf-8 -*-
config = {
    'api_version': '21.0.0',
    'c_header': 'niRFmxSpecAn.h',
    'c_function_prefix': 'RFmxSpecAn_',
    'service_class_prefix': 'NiRFmxSpecAn',
    'java_package': 'com.ni.grpc.nirfmxspecan',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxSpecAn',
    'namespace_component': 'nirfmxspecan',
    'close_function': 'Close',
    'custom_types': [],
    'additional_headers': {},
    'type_to_grpc_type': {
        "char[]": "string",
        "float32": "float",
        "float64": "double",
        "int16": "int32",
        "int32": "int32",
        "int64_t": "int64",
        "niRFmxInstrHandle": "nidevice_grpc.Session",
        "signed char": "int32",
        "signed char[]": "bytes",
        "uInt16": "uint32",
        "uInt32": "uint32",
        "uInt64": "uint64",
        "uInt8": "uint32",
        "NIComplexSingle": "nidevice_grpc.NIComplexNumberF32",
        "NIComplexDouble": "nidevice_grpc.NIComplexNumber",
    },
    'split_attributes_by_type': True,
    'code_readiness': 'NextRelease',
    'feature_toggles': {},
    'driver_name': 'NI-RFMXSPECAN',
    'extra_errors_used': [
    ],
    'init_function': 'Initialize',
    'resource_handle_type': 'niRFmxInstrHandle',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfmxspecan',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxSpecAn.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFmxSpecAn.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nirfmxspecan',
    'session_class_description': 'An NI-RFmxSpecAn instrument handle',
    'session_handle_parameter_name': 'instrumentHandle'
}
