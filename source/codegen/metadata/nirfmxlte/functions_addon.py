functions_override_metadata = {
    'CfgPSSCHModulationType': {
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
                'enum': 'PsschModulationType',
                'grpc_field_number': '4',
                'grpc_raw_field_number': '3',
                'name': 'modulationType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
}
