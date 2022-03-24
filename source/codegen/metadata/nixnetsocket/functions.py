functions = {
    'Accept': {
        'cname': 'nxaccept',
        'init_method': True,
        'status_expression': 'socket_out == -1 ? -1 : 0',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'out',
                'grpc_type': 'SockAddr',
                'name': 'addr',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'out',
                'name': 'addrlen',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
            {
                'direction': 'out',
                'cpp_local_name': 'socket_out',
                'name': 'socket',
                'return_value': True,
                'type': 'nxSOCKET'
            },
        ],
        'returns': 'nxSOCKET'
    },
    'Bind': {
        'cname': 'nxbind',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'grpc_type': 'SockAddr',
                'name': 'name',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'in',
                'name': 'namelen',
                'hardcoded_value': 'name.size()',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
        ],
        'returns': 'int32_t'
    },
    'Connect': {
        'cname': 'nxconnect',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'grpc_type': 'SockAddr',
                'name': 'name',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'in',
                'name': 'namelen',
                'hardcoded_value': 'name.size()',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
        ],
        'returns': 'int32_t'
    },
    'InetAToN': {
        'cname': 'nxinet_aton',
        'parameters': [
            {
                'direction': 'in',
                'name': 'stack_ref',
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in',
                'name': 'cp',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'IPv4Addr',
                'name': 'name',
                'supports_standard_copy_convert': True,
                'supports_standard_output_allocation': True,
                'type': 'nxin_addr'
            },
        ],
        'returns': 'int32_t'
    },
    'InetPToN': {
        'cname': 'nxinet_pton',
        'parameters': [
            {
                'direction': 'in',
                'name': 'stack_ref',
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in',
                'name': 'af',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'src',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'grpc_type': 'Addr',
                'name': 'dst',
                'supports_standard_output_allocation': True,
                "additional_arguments_to_output_allocation": ["af"],
                'supports_standard_copy_convert': True,
                'type': 'void'
            },
        ],
        'returns': 'int32_t'
    },
    'FreeAddrInfo': {
        'codegen_method': 'private',
        'cname': 'nxfreeaddrinfo',
        'parameters': [
            {
                'direction': 'in',
                'name': 'res',
                'type': 'nxaddrinfo',
                'pointer': True
            }
        ],
        'returns': 'int32_t'
    },
    'GetAddrInfo': {
        'cname': 'nxgetaddrinfo',
        'parameters': [
            {
                'direction': 'in', 
                'name': 'stack_ref', 
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in',
                'name': 'node',
                'type': 'const char[]',
                'proto_only': True
            },
            {
                'direction': 'in',
                'name': 'node_api',
                'type': 'const char[]',
                'hardcoded_value': 'request->node() == "" ? nullptr : node',
                'include_in_proto': False
            },
            {
                'direction': 'in',
                'name': 'service',
                'type': 'const char[]',
                'proto_only': True
            },
            {
                'direction': 'in',
                'name': 'service_api',
                'type': 'const char[]',
                'hardcoded_value': 'request->service() == "" ? nullptr : service',
                'include_in_proto': False
            },
            {
                'direction': 'in',
                'name': 'hints',
                'supports_standard_copy_convert': True,
                'grpc_type': 'AddrInfoHint',
                'pointer': True,
                'type': 'nxaddrinfo'
            },
            {
                'direction': 'out',
                'name': 'res',
                'supports_standard_copy_convert': True,
                'supports_standard_output_allocation': True,
                'additional_arguments_to_output_allocation': ['library_'],
                'pointer': True,
                'type': 'nxaddrinfo'
            }
        ],
        'returns': 'int32_t'
    },
    'GetNameInfo': {
        'cname': 'nxgetnameinfo',
        'parameters': [
            {
                'direction': 'in', 
                'name': 'stack_ref', 
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in',
                'grpc_type': 'SockAddr',
                'name': 'addr',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'in',
                'name': 'addr_len',
                'hardcoded_value': 'addr.size()',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
            {
                'direction': 'out',
                'name': 'host',
                'type': 'char[]',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'host_len'
                }
            },
            {
                'direction': 'in',
                'name': 'host_len',
                'type': 'nxsocklen_t'
            },
            {
                'direction': 'out',
                'name': 'serv',
                'type': 'char[]',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'serv_len'
                }
            },
            {
                'direction': 'in',
                'name': 'serv_len',
                'type': 'nxsocklen_t'
            },
            {
                'direction': 'in',
                'name': 'flags',
                'type': 'int32_t',
                'enum': 'GetNameInfoFlags'
            },
        ],
        'returns': 'int32_t'
    },
    'Listen': {
        'cname': 'nxlisten',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'name': 'backlog',
                'type': 'int32_t'
            },
        ],
        'returns': 'int32_t'
    },
    'SendTo': {
        'cname': 'nxsendto',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'name': 'dataptr',
                'pointer': True,
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'pointer': True,
                'grpc_type': 'bytes',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'flags',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'grpc_type': 'SockAddr',
                'name': 'to',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'in',
                'name': 'tolen',
                'hardcoded_value': 'to.size()',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
        ],
        'returns': 'int32_t'
    },
    'Send': {
        'cname': 'nxsend',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'name': 'dataptr',
                'pointer': True,
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'pointer': True,
                'grpc_type': 'bytes',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'flags',
                'type': 'int32_t'
            },
        ],
        'returns': 'int32_t'
    },
    'RecvFrom': {
        'cname': 'nxrecvfrom',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'out',
                'name': 'mem',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'grpc_type': 'bytes',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'flags',
                'type': 'int32_t'
            },
            {
                'direction': 'out',
                'grpc_type': 'SockAddr',
                'name': 'from',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'out',
                'name': 'fromlen',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
        ],
        'returns': 'int32_t'
    },
    'Recv': {
        'cname': 'nxrecv',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'out',
                'name': 'mem',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
                'grpc_type': 'bytes',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'flags',
                'type': 'int32_t'
            },
        ],
        'returns': 'int32_t'
    },
    'GetSockName': {
        'cname': 'nxgetsockname',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'out',
                'grpc_type': 'SockAddr',
                'name': 'addr',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'out',
                'name': 'addrlen',
                'hardcoded_value': 'static_cast<nxsocklen_t>(sizeof(addr.storage))',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
        ],
        'returns': 'int32_t'
    },
    'GetPeerName': {
        'cname': 'nxgetpeername',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'out',
                'grpc_type': 'SockAddr',
                'name': 'addr',
                'supports_standard_output_allocation': True,
                'supports_standard_copy_convert': True,
                'type': 'nxsockaddr'
            },
            {
                'direction': 'out',
                'name': 'addrlen',
                'hardcoded_value': 'static_cast<nxsocklen_t>(sizeof(addr.storage))',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            },
        ],
        'returns': 'int32_t'
    },
    'Shutdown': {
        'cname': 'nxshutdown',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
             {
                'direction': 'in',
                'name': 'how',
                'type': 'int32_t',
                'enum': 'Shutdown'
            },
        ],
        'returns': 'int32_t'
    },
    'Close': {
        'cname': 'nxclose',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            }
        ],
        'returns': 'int32_t'
    },
    'GetLastErrorNum': {
        'codegen_method': 'private',
        'cname': 'nxgetlasterrornum',
        'parameters': [],
        'returns': 'int32_t'
    },
    'GetLastErrorStr': {
        'codegen_method': 'private',
        'cname': 'nxgetlasterrorstr',
        'status_expression': 'error ? 0 : -1',
        'parameters': [
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'buf',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'bufLen'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'bufLen',
                'type': 'size_t'
            },
            {
                'direction': 'out',
                'name': 'error',
                'return_value': True,
                'type': 'char[]'
            },
        ],
        'returns': 'char*'
    },
    'GetSockOpt': {
        'cname': 'nxgetsockopt',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'int32_t',
                'enum': 'SocketOptionLevel'
            },
            {
                'direction': 'in',
                'name': 'optname',
                'type': 'int32_t',
                'enum': 'OptName'
            },
            {
                'direction': 'out',
                'name': 'optval',
                'grpc_type': 'SockOptData',
                'supports_standard_output_allocation': True,
                "additional_arguments_to_output_allocation": ["optname"],
                'supports_standard_copy_convert': True,
                'pointer': True,
                'type': 'void *'
            },
            {
                'direction': 'out',
                'name': 'optlen',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            }
        ],
        'returns': 'int32_t'
    },
    'IpStackClear': {
        'custom_close_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'stack_ref',
                'type': 'nxIpStackRef_t'
            },
        ],
        'returns': 'int32_t'
    },
    'IpStackCreate': {
        'custom_close': 'IpStackClear(id)',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'stack_name',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'config',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'stack_ref',
                'type': 'nxIpStackRef_t'
            },
        ],
        'returns': 'int32_t'
    },
    'IpStackFreeInfo': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'firstVirtualInterface',
                'pointer': True,
                'type': 'nxVirtualInterface_t',
            },
        ],
        'returns': 'int32_t'
    },
    'IpStackGetInfo': {
        'parameters': [
            {
                'direction': 'in', 
                'name': 'stack_ref', 
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in',
                'hardcoded_value': 'nxIPSTACK_INFO_ID',
                'include_in_proto': False,
                'name': 'info_id',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'virtual_interfaces',
                'pointer': True,
                'supports_standard_output_allocation': True,
                'additional_arguments_to_output_allocation': ['library_'],
                'supports_standard_copy_convert': True,
                'type': 'nxVirtualInterface_t',
            },
        ],
        'returns': 'int32_t',
    },
    'IpStackWaitForInterface': {
        'parameters': [
            {
                'direction': 'in', 
                'name': 'stack_ref',
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in', 
                'name': 'localInterface', 
                'type': 'const char[]'
            },
            {
                'direction': 'in', 
                'name': 'timeoutMs', 
                'type': 'int32_t'
            },
        ],
        'returns': 'int32_t',
    },
    'IsSet': {
        'cname': 'nxfd_isset',
        'status_expression': '0',
        'parameters': [
            {
                'direction': 'in',
                'name': 'fd',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'name': 'set',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['session_repository_'],
                'type': 'nxfd_set'
            },
            {
                'direction': 'out',
                'name': 'is_set',
                'return_value': True,
                'type': 'int32_t'
            }
        ],
        'returns': 'int32_t'
    },
    'Select': {
        'cname': 'nxselect',
        'parameters': [
            {
                'direction': 'in',
                'hardcoded_value': '0',
                'include_in_proto': False,
                'name': 'nfds',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'read_fds',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['session_repository_'],
                'type': 'nxfd_set'
            },
            {
                'direction': 'in',
                'name': 'write_fds',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['session_repository_'],
                'type': 'nxfd_set'
            },
            {
                'direction': 'in',
                'name': 'except_fds',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['session_repository_'],
                'type': 'nxfd_set'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'pointer': True,
                'supports_standard_copy_convert': True,
                'type': 'nxtimeval'
            },
        ],
        'returns': 'int32_t'
    },
    'SetSockOpt': {
        'cname': 'nxsetsockopt',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'int32_t',
                'enum': 'SocketOptionLevel'
            },
            {
                'direction': 'in',
                'name': 'optname',
                'type': 'int32_t',
                'enum': 'OptName'
            },
            {
                'direction': 'in',
                'name': 'opt_data',
                'grpc_type': 'SockOptData',
                'supports_standard_copy_convert': True,
                'proto_only': True,
                'type': 'SockOptDataInputConverter'
            },
            {
                'direction': 'in',
                'name': 'optval',
                'hardcoded_value': 'opt_data.data()',
                'include_in_proto': False,
                'pointer': True,
                'type': 'void'
            },
            {
                'direction': 'in',
                'name': 'optlen',
                'hardcoded_value': 'opt_data.size()',
                'include_in_proto': False,
                'type': 'nxsocklen_t'
            }
        ],
        'returns': 'int32_t'
    },
    'Socket': {
        'cname': 'nxsocket',
        'init_method': True,
        'status_expression': 'socket == -1 ? -1 : 0',
        'parameters': [
            {
                'direction': 'in',
                'name': 'stack_ref',
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in',
                'name': 'domain',
                'type': 'int32_t',
                'enum': 'AddressFamily'
            },
            {
                'direction': 'in',
                'name': 'type',
                'type': 'int32_t',
                'enum': 'SocketProtocolType'
            },
            {
                'direction': 'in',
                'name': 'prototcol',
                'type': 'int32_t',
                'enum': 'IPProtocol'
            },
            {
                'direction': 'out',
                'name': 'socket',
                'return_value': True,
                'type': 'nxSOCKET'
            },
        ],
        'returns': 'nxSOCKET'
    },
}