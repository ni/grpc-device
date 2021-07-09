# -*- coding: utf-8 -*-
functions = {
    'Close': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    },
    'Init': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'sessionName',
                'type': 'const char[]',
                'is_session_name': True
            },
            {
                'direction': 'out',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    },
    'InitWithHandleNameAsSessionName': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'handleName',
                'type': 'const char[]',
                'is_session_name': True
            },
            {
                'direction': 'out',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    },
    'InputArraysWithNarrowIntegerTypes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'u16Array',
                'type': 'const uInt16*',
                'grpc_type': 'repeated uint32',
            },
            {
                'direction': 'in',
                'name': 'i16Array',
                'type': 'const int16*',
                'grpc_type': 'repeated int32',
            },
            {
                'direction': 'in',
                'name': 'i8Array',
                'type': 'const int8*',
                'grpc_type': 'repeated int32',
            }
        ],
        'returns': 'int32'
    }
}
