# -*- coding: utf-8 -*-
functions = {
   'AddCoolFunctionality': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'param',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'TestAddressParameeters': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'space',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'offset',
                'type': 'ViUInt64'
            },
            {
                'direction': 'in',
                'name': 'suggested',
                'type': 'ViAddr'
            },
            {
                'direction': 'out',
                'name': 'actual',
                'type': 'ViAddr'
            },
        ],
        'returns': 'ViStatus'
    },
    'TestLargeEnum': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'LargeValue',
                'name': 'mode',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
}
