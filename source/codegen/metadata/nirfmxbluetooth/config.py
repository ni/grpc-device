# -*- coding: utf-8 -*-
config = {
    'api_version': '25.0.0',
    'c_header': 'niRFmxBT.h',
    'c_function_prefix': 'RFmxBT_',
    'service_class_prefix': 'NiRFmxBluetooth',
    'java_package': 'com.ni.grpc.nirfmxbluetooth',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxBluetooth',
    'namespace_component': 'nirfmxbluetooth',
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
    'driver_name': 'NI-RFMXBLUETOOTH',
    'extra_errors_used': [
    ],
    'init_function': 'Initialize',
    'resource_handle_type': 'niRFmxInstrHandle',
    'status_ok': 'status >= 0',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfmxbt',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxBT.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFmxBT.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'metadata_version': '0.1',
    'module_name': 'nirfmxbluetooth',
    'session_class_description': 'An NI-RFmxBluetooth instrument handle',
    'session_handle_parameter_name': 'instrumentHandle',
    'windows_only': True,
    'duplicate_resource_handles_allowed': True
}
