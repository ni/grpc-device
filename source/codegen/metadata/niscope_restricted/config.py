# -*- coding: utf-8 -*-
config = {
    'additional_headers': {
        'custom/ivi_errors.h': [
            'service.cpp'
        ]
    },
    "code_readiness": "Release",
    "is_restricted": True,
    "api_version": "23.0.0",
    "c_header": "niScopeCal.h",
    "c_function_prefix": "niScope_",
    "service_class_prefix": "NiScopeRestricted",
    "java_package": "com.ni.grpc.scoperestricted",
    "csharp_namespace": "NationalInstruments.Grpc.NiScopeRestricted",
    "namespace_component": "niscope_restricted",
    'close_function': None,
    "custom_types": [],
    "type_to_grpc_type": {
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
    },
    "driver_name": "NI-SCOPE-RESTRICTED",
    "status_ok": "status >= 0",
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'niscope',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niScope_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niScope_64.dll',
                'type': 'cdll'
            }
        }
    },
    "linux_rt_support": True,
    "module_name": "niscope_restricted",
    'session_handle_parameter_name': 'vi',
    "duplicate_resource_handles_allowed": True,
}
