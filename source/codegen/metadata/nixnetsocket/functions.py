functions = {
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
    'Recv': {
        'cname': 'nxrecv',
        'parameters': [
            {
                'direction': 'in',
                'name': 'socket',
                'type': 'nxSOCKET'
            },
            {
                'direction': 'in',
                'name': 'mem',
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
                'type': 'int32_t'
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
        'cname': 'nxgetlasterrornum',
        'parameters': [],
        'returns': 'int32_t'
    },
    'GetLastErrorStr': {
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
    'Socket': {
        'cname': 'nxsocket',
        'init_method': True,
        'status_expression': 'socket == -1 ? -1 : 0',
        'parameters': [
            {
                'direction': 'in',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'stack_ref',
                'type': 'nxIpStackRef_t'
            },
            {
                'direction': 'in',
                'name': 'domain',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'type',
                'type': 'int32_t'
            },
            {
                'direction': 'in',
                'name': 'prototcol',
                'type': 'int32_t'
            },
            {
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'socket',
                'return_value': True,
                'type': 'nxSOCKET'
            },
        ],
        'returns': 'nxSOCKET'
    },
}
