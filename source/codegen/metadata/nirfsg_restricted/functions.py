functions = {
    'GetError': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'direction': 'in',
                'name': 'errorDescriptionBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorDescriptionBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorMessage': {
        'cname': 'niRFSG_error_message',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'direction': 'out',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 1024
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateDeembeddingSparameterTable': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfFrequencies',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'numberOfPorts',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSparameterTableFrequencies': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'frequencies',
                'size': {
                    'mechanism': 'len',
                    'value': 'frequenciesSize'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'in',
                'name': 'frequenciesSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSparameterTableSparameters': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'port',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.NIComplexNumber',
                'name': 'sparameterTable',
                'size': {
                    'mechanism': 'len',
                    'value': 'sparameterTableSize'
                },
                'type': 'NIComplexNumber_struct[]'
            },
            {
                'direction': 'in',
                'name': 'sparameterTableSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'SParameterOrientation',
                'name': 'sparameterOrientation',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetDeembeddingTableNumberOfPorts': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'numberOfPorts',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    }
}
