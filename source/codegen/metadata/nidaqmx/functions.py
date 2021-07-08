functions = {
    'ClearTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'CreateAIVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'physicalChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToChannel',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'InputTermCfgWithDefault',
                'name': 'terminalConfig',
                'type': 'int'
            },
            {
                'direction': 'in',
                'name': 'minVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'maxVal',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'VoltageUnits2',
                'name': 'units',
                'type': 'int'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateDIChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToLines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'LineGrouping',
                'name': 'lineGrouping',
                'type': 'int'
            }
        ],
        'returns': 'int32'
    },
    'CreateDOChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'nameToAssignToLines',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'LineGrouping',
                'name': 'lineGrouping',
                'type': 'int'
            }
        ],
        'returns': 'int32'
    },
    'CreateTask': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'is_session_name': True,
                'name': 'sessionName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'StartTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    },
    'StopTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            }
        ],
        'returns': 'int32'
    }
}
