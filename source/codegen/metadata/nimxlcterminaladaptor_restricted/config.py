# -*- coding: utf-8 -*-
config = {
    "code_readiness": "RestrictedRelease",
    'api_version': '21.0.0',
    'c_header': 'TerminalAdaptorTypes.h',
    'c_function_prefix': 'nimxlc_ta_nimxlc_',
    'service_class_prefix': 'NimxlcTerminalAdaptorRestricted',
    'java_package': 'com.ni.grpc.nimxlcterminaladaptorrestricted',
    'csharp_namespace': 'NationalInstruments.Grpc.NimxlcTerminalAdaptorRestricted',
    'namespace_component': 'nimxlcterminaladaptor_restricted',
    'close_function': 'destroySession',
    'additional_headers': { 
        "custom/nimxlcterminaladaptor_restricted_converters.h": ["service.cpp"],
    },
    'custom_types': [],
    "type_to_grpc_type": {
        'char[]': 'string',
        'float32': 'float',
        'float64': 'double',
        'int16': 'int32',
        'int32': 'int32',
        'int64': 'int64',
        'nimxlc_Session': 'nidevice_grpc.Session',
        'int8': 'int32',
        'uInt16': 'uint32',
        'uInt32': 'uint32',
        'uint32_t': 'uint32',
        'uInt64': 'uint64',
        'uInt8': 'uint32',
        'uInt8[]': 'bytes',
        'NIComplexSingle': 'nidevice_grpc.NIComplexNumberF32',
        'NIComplexDouble': 'nidevice_grpc.NIComplexNumber',
        'nierr_Status': 'NIErrStatus',
        'nimxlc_DeviceContainer': 'repeated NIMXLCDevice',
    },
    'driver_name': 'NI-MXLCTERMINALADAPTOR-RESTRICTED',
    "resource_handle_type": "nimxlc_Session",
    'status_ok': 'status >= 0',
    "windows_only": True,
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'libnimxlcTerminalAdaptor',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nimxlcTerminalAdaptor.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nimxlcTerminalAdaptor.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': False,
    'metadata_version': '0.1',
    'module_name': 'nimxlcterminaladaptor_restricted',
    'session_class_description': 'An handle to a Routing Adaptor session.',
    'session_handle_parameter_name': 'session',
    "duplicate_resource_handles_allowed": True,
}