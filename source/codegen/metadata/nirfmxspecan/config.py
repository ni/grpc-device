# -*- coding: utf-8 -*-
config = {
    'api_version': '24.5.0',
    'c_header': 'niRFmxSpecAn.h',
    'c_function_prefix': 'RFmxSpecAn_',
    'service_class_prefix': 'NiRFmxSpecAn',
    'java_package': 'com.ni.grpc.nirfmxspecan',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxSpecAn',
    'namespace_component': 'nirfmxspecan',
    'close_function': 'Close',
    'custom_types': [],
    'additional_headers': { 'custom/nirfmx_errors.h': ['service.cpp'] },
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
    'driver_name': 'NI-RFMXSPECAN',
    'extra_errors_used': [
    ],
    'init_function': 'Initialize',
    'resource_handle_type': 'niRFmxInstrHandle',
    'status_ok': 'status >= 0',
    'windows_only': True,
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
    'linux_rt_support': False,
    'metadata_version': '0.1',
    'module_name': 'nirfmxspecan',
    'session_class_description': 'An NI-RFmxSpecAn instrument handle',
    'session_handle_parameter_name': 'instrumentHandle',
    'duplicate_resource_handles_allowed': True
}
