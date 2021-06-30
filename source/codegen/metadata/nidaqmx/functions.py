# -*- coding: utf-8 -*-
functions = {
    'ClearTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32',
    },
    'CreateTask': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'sessionName',
                'type': 'const char*'
            },
            {
                'direction': 'out',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32',
    }
}
