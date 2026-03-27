# -*- coding: utf-8 -*-
config = {
    'api_version': '26.3.0',
    'c_header': 'niBTGeneration.h',
    'c_function_prefix': 'niBTSG_',
    'service_class_prefix': 'NiRFmxBluetoothGen',
    'java_package': 'com.ni.grpc.nirfmxbluetoothgen',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFmxBluetoothGen',
    'namespace_component': 'nirfmxbluetoothgen',
    'close_function': 'CloseSession',
    'custom_types': [],
    'additional_headers': { 
        'custom/nirfmx_errors.h': ['service.cpp'], 
        'niBTGenerationRfsg.h': ['library.h', 'library.cpp', 'library_interface.h', 'compilation_test.cpp']
    },
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
        "niBTSGSession": "nidevice_grpc.Session",
        "ViSession": "nidevice_grpc.Session"
    },
    'code_readiness': 'Release',
    'feature_toggles': {},
    'driver_name': 'NI-RFMXBLUETOOTHGEN',
    'extra_errors_used': [
    ],
    'init_function': 'Initialize',
    'resource_handle_type': ['niBTSGSession', 'ViSession'],
    'status_ok': 'status >= 0',
    'library_info': { 
        'Linux': {
            '64bit': {
                'name': 'nirfmxbtgen',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFmxBTSG.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niBTSG_net.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'metadata_version': '0.1',
    'module_name': 'nirfmxbluetoothgen',
    'session_class_description': 'An RFmx Bluetooth Generation handle',
    'session_handle_parameter_name': 'session',
    'windows_only': True,
    'duplicate_resource_handles_allowed': True
}
