# -*- coding: utf-8 -*-
config = {
    'api_version': '27.0.0',
    'c_header': 'niRFmxEVDO.h',
    'c_function_prefix': 'RFmxEVDO_',
    'service_class_prefix': 'NiRFmxEVDO',
    'java_package': 'com.ni.grpc.nirfmxevdo',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxEVDO',
    'namespace_component': 'nirfmxevdo',
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
    'driver_name': 'NI-RFMXEVDO',
    'extra_errors_used': [
    ],
    'init_function': 'Initialize',
    'resource_handle_type': 'niRFmxInstrHandle',
    'status_ok': 'status >= 0',
    'windows_only': True,
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfmxevdo',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxEVDO.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFmxEVDO.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nirfmxevdo',
    'session_class_description': 'An NI-RFmxEVDO instrument handle',
    'session_handle_parameter_name': 'instrumentHandle',
    'duplicate_resource_handles_allowed': True
}
