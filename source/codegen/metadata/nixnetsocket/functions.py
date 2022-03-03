functions = {
    'Close': {
        'cname': 'nxclose',
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
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
