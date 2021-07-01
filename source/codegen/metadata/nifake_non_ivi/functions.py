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
                'type': 'const char*',
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
                'type': 'const char*',
                'is_session_name': True
            },
            {
                'direction': 'out',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    }
}
