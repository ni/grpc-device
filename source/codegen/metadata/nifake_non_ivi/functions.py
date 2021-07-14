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
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'i16Array',
                'type': 'const int16*',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'i8Array',
                'type': 'const int8*',
                'coerced': True
            }
        ],
        'returns': 'int32'
    },
    'OutputArraysWithNarrowIntegerTypes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'numberOfU16Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'u16Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfU16Samples'
                },
                'type': 'uInt16[]',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'numberOfI16Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'i16Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfI16Samples'
                },
                'type': 'int16[]',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'numberOfI8Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'i8Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfI8Samples'
                },
                'type': 'int8[]',
                'coerced': True
            },
        ],
        'returns': 'int32'
    },
    'InputArrayOfBytes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'u8Array',
                'type': 'const uInt8*',
                'grpc_type': 'bytes',
            },
        ],
        'returns': 'int32'
    },
    'OutputArrayOfBytes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'numberOfU8Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'u8Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfU8Samples'
                },
                'type': 'uInt8[]',
                'grpc_type': 'bytes'
            },
        ],
        'returns': 'int32'
    },
}
