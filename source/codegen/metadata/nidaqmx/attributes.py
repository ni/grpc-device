attributes = {
    'Buffer': {
        6252: {
            'access': 'read-write',
            'name': 'INPUT_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        6253: {
            'access': 'read-write',
            'name': 'OUTPUT_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        8970: {
            'access': 'read',
            'name': 'INPUT_ONBRD_BUF_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        8971: {
            'access': 'read-write',
            'name': 'OUTPUT_ONBRD_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        }
    },
    'Scale': {
        4646: {
            'access': 'read-write',
            'name': 'DESCR',
            'resettable': False,
            'type': 'char[]'
        },
        4647: {
            'access': 'read-write',
            'name': 'LIN_SLOPE',
            'resettable': False,
            'type': 'float64'
        },
        4648: {
            'access': 'read-write',
            'name': 'LIN_Y_INTERCEPT',
            'resettable': False,
            'type': 'float64'
        },
        4649: {
            'access': 'read-write',
            'name': 'MAP_SCALED_MAX',
            'resettable': False,
            'type': 'float64'
        },
        4656: {
            'access': 'read-write',
            'name': 'MAP_SCALED_MIN',
            'resettable': False,
            'type': 'float64'
        },
        4657: {
            'access': 'read-write',
            'name': 'MAP_PRE_SCALED_MAX',
            'resettable': False,
            'type': 'float64'
        },
        4658: {
            'access': 'read-write',
            'name': 'MAP_PRE_SCALED_MIN',
            'resettable': False,
            'type': 'float64'
        },
        4660: {
            'access': 'read-write',
            'name': 'POLY_FORWARD_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        4661: {
            'access': 'read-write',
            'name': 'POLY_REVERSE_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        4662: {
            'access': 'read-write',
            'name': 'TABLE_SCALED_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        4663: {
            'access': 'read-write',
            'name': 'TABLE_PRE_SCALED_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        6391: {
            'access': 'read-write',
            'enum': 'UnitsPreScaled',
            'name': 'PRE_SCALED_UNITS',
            'resettable': False,
            'type': 'int32'
        },
        6427: {
            'access': 'read-write',
            'name': 'SCALED_UNITS',
            'resettable': False,
            'type': 'char[]'
        },
        6441: {
            'access': 'read',
            'enum': 'ScaleType',
            'name': 'TYPE',
            'resettable': False,
            'type': 'int32'
        }
    }
}
