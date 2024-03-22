functions_override_metadata = {
    'IDPDCfgReferenceWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdReferenceWaveformIdleDurationPresent',
                'grpc_raw_field_number': '6',
                'grpc_field_number': '8',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdSignalType',
                'grpc_raw_field_number': '7',
                'grpc_field_number': '9',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
}
