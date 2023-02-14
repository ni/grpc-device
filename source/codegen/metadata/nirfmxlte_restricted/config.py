# -*- coding: utf-8 -*-
config = {
    "code_readiness": "Release",
    "is_restricted": True,
    "api_version": "21.0.0",
    "c_header": "niRFmxLTE.h",
    "c_function_prefix": "RFmxLTE_",
    "service_class_prefix": "NiRFmxLTERestricted",
    "java_package": "com.ni.grpc.nirfmxlterestricted",
    "csharp_namespace": "NationalInstruments.Grpc.NiRFmxLTERestricted",
    "namespace_component": "nirfmxlte_restricted",
    'close_function': None,
    "custom_types": [],
    "type_to_grpc_type": {
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
    "driver_name": "NI-RFMXLTE-RESTRICTED",
    "resource_handle_type": "niRFmxInstrHandle",
    "status_ok": "status >= 0",
    "windows_only": True,
    "library_info": {
        "Linux": {
            "64bit": {
                "name": "nirfmxlte",
                "type": "cdll",
                "abi_version": "1"
            }
        },
        "Windows": {
            "32bit": {
                "name": "niRFmxLTE.dll",
                "type": "windll"
            },
            "64bit": {
                "name": "niRFmxLTE.dll",
                "type": "cdll"
            }
        },
    },
    "linux_rt_support": False,
    "metadata_version": "0.1",
    "module_name": "nirfmxlte_restricted",
    "session_class_description": "An NI-RFmxLTE instrument handle",
    'session_handle_parameter_name': 'instrumentHandle',
    "duplicate_resource_handles_allowed": True,
}
