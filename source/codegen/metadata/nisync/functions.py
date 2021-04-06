# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 20.5.0d7
functions = {
    'init': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'direction': 'in',
                'name': 'IDQuery',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'direction': 'out',
                'name': 'vi',
                'type': 'ViSession'
            },
        ],
        'returns': 'ViStatus'
    },
    'close': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
        ],
        'returns': 'ViStatus'
    },
    'ConnectTrigTerminals': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'srcTerminal',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'destTerminal',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'syncClock',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'invert',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'updateEdge',
                'type': 'ViInt32'
            },
        ],
        'returns': 'ViStatus'
    },
    'DisconnectTrigTerminals': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'srcTerminal',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'destTerminal',
                'type': 'ViConstString'
            },
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt32': {
        'parameters': [
            {
            'direction': 'in',
            'name': 'vi',
            'type': 'ViSession'
            },
            {
            'direction': 'in',
            'name': 'terminalName',
            'type': 'ViConstString'
            },
            {
            'direction': 'in',
            'name': 'attribute',
            'type': 'ViAttr'
            },
            {
            'direction': 'out',
            'name': 'value',
            'type': 'ViInt32'
            },
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'terminalName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt32'
            },
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'terminalName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViReal64'
            },
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'terminalName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViReal64'
            },
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViBoolean': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'terminalName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViBoolean'
            },
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViBoolean': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'terminalName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViBoolean'
            },
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession',
            },
            {
                'direction': 'in',
                'name': 'terminalName',
                'type': 'ViConstString',
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr',
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViChar',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                }
            },
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession',
            },
            {
                'direction': 'in',
                'name': 'terminalName',
                'type': 'ViConstString',
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViConstString',
            },
        ],
        'returns': 'ViStatus'
    },
}
