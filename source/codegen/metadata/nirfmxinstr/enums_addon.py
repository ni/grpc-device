# These dictionaries are applied to the generated enums dictionary at build time
# Any changes to the API should be made here. enums.py is code generated

enums_override_metadata = {
    'SParameterType': {
        'values': [
            {
                'name': 'AMPLITUDE_AND_PHASE_FLATNESS',
                'value': 4,
                'deprecated': True
            },
            {
                'name': 'AMPLITUDE_FLATNESS',
                'value': 3
            },
            {
                'name': 'SCALAR',
                'value': 1
            },
            {
                'name': 'VECTOR',
                'value': 2
            }
        ]
    },
}

enums_validation_suppressions = {
    "FrequencyReferenceExportedTerminal": ["ENUMS_SHOULD_NOT_HAVE_DUPLICATE_VALUES"]
}
