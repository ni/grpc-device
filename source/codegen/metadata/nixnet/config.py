# -*- coding: utf-8 -*-
config = {
    'api_version': '21.0.0',
    'c_header': 'nixnet.h',
    'c_function_prefix': 'nx',
    'service_class_prefix': 'NiXnet',
    'java_package': 'com.ni.grpc.xnet',
    'csharp_namespace': 'NationalInstruments.Grpc.NiXnet',
    'namespace_component': 'nixnet',
    'close_function': 'Clear',
    'code_readiness': 'Release',
    'driver_name': 'NI-XNET',
    'status_ok': 'status >= 0',
    'type_to_grpc_type': {
        'nxSessionRef_t': 'nidevice_grpc.Session',
        'nxDatabaseRef_t': 'nidevice_grpc.Session',
        'nxDatabaseRef_t[]': 'repeated nidevice_grpc.Session',
        'u32': 'uint32',
        'u64': 'uint64',
        'u8': 'uint32',
        'f64': 'double',
        'char[]': 'string',
        'const char[]': 'string',
        'nxStatus_t': 'int32',
        'void[]': 'bytes',
        'nxTimestamp1ns_t': 'uint64',
        'nxTimestamp100ns_t': 'uint64'
    },
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nixnet',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nixnet.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nixnet.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nixnet',
    'session_class_description': 'An NI-XNET session.',
    'session_handle_parameter_name': 'vi'
}
