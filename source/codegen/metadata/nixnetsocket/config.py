# -*- coding: utf-8 -*-
config = {
    'api_version': '21.8.0',
    'c_header': 'nxsocket.h',
    'c_function_prefix': 'nx',
    'service_class_prefix': 'NiXnetSocket',
    'java_package': 'com.ni.grpc.xnetsocket',
    'csharp_namespace': 'NationalInstruments.Grpc.NiXnetSocket',
    'namespace_component': 'nixnetsocket',
    'close_function': 'Close',
    'custom_types': [],
    'additional_headers': { 
        "custom/xnetsocket_converters.h": ["service.cpp"],
        "custom/xnetsocket_errors.h": ["service.cpp"],
        "custom/xnetsocket_aliases.h": ["library_interface.h"] 
    },
    'get_last_error': [
        {
            'name': 'error_message',
            'type': 'char[]'
        }, 
        {
            'name': 'error_num', 
            'type': 'int32_t'
        }
    ],
    'type_to_grpc_type': {
        'nxSOCKET': 'nidevice_grpc.Session',
        'nxfd_set': 'repeated nidevice_grpc.Session',
        'nxIpStackRef_t': 'nidevice_grpc.Session',
        'char[]': 'string',
        'int32_t': 'int32',
        'void*': 'bytes',
        'int': 'int32',
        'nxsocklen_t': 'int32',
        'size_t': 'uint64',
        'uint32_t': 'uint32',
        'uint16_t': 'uint16',
        'int64_t': 'int64',
        'nxaddrinfo': 'repeated AddrInfo',
        'nxlinger': 'Linger',
        'nxsockaddr': 'SockAddr',
        'nxtimeval': 'google.protobuf.Duration',
        'nxVirtualInterface_t': 'repeated VirtualInterface',
        'nixnetsocket_grpc::IpStackInfoString': 'string'
    },
    'code_readiness': 'Release',
    'driver_name': 'NI-XNETSOCKET',
    'extra_errors_used': [
    ],
    'init_function': 'Socket',
    'resource_handle_type': ['nxSOCKET', 'nxIpStackRef_t'],
    'status_ok': 'status >= 0',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nixntipstack',
                'type': 'cdll',
                'abi_version': '1'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nixntipstack.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nixntipstack.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'metadata_version': '0.1',
    'module_name': 'nixnetsocket',
    'session_class_description': 'An NI-XNET ethernet socket',
    'session_handle_parameter_name': 'socket'
}
