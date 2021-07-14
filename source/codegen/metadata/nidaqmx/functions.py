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
                'type': 'int32'
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
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'customScaleName',
                'type': 'const char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateAOVoltageChan': {
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
                'type': 'int32'
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
                'type': 'int32'
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
                'type': 'int32'
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
    'ReadAnalogF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'fillMode',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
                'type': 'bool32',
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
    },
    'WriteAnalogF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'bool32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'GroupBy',
                'name': 'dataLayout',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const float64[]'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'reserved',
                'pass_null': True,
                'type': 'bool32',
            }
        ],
        'returns': 'int32'
    }
}
