# -*- coding: utf-8 -*-
# This file is generated from NI-FAKE API metadata version 23.0.0d26
enums = {
    'Bitfield': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'FLAG_A',
                'value': 1
            },
            {
                'name': 'FLAG_B',
                'value': 2
            },
            {
                'name': 'FLAG_C',
                'value': 4
            },
            {
                'name': 'FLAG_D',
                'value': 8
            }
        ]
    },
    'DecimalMixedNumber': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'TWENTY_TWO',
                'value': 22
            },
            {
                'name': 'TWO_POINT_TWO',
                'value': 2.2
            },
            {
                'name': 'NEGATIVE_THREE',
                'value': -3
            },
            {
                'name': 'MAX_INT_32',
                'value': 2147483647
            },
            {
                'name': 'MAX_INT_32_PLUS_ONE',
                'value': 2147483648.0
            },
            {
                'name': 'MIN_INT_32',
                'value': -2147483648
            },
            {
                'name': 'MIN_INT_32_MINUS_ONE',
                'value': -2147483649.0
            }
        ]
    },
    'DecimalWholeNumber': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ZERO',
                'value': 0
            },
            {
                'name': 'NEGATIVE_ONE',
                'value': -1
            },
            {
                'name': 'TWENTY_TWO',
                'value': 22
            }
        ]
    },
    'DecimalWholeNumberMapped': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'ZERO',
                'value': 0.0
            },
            {
                'name': 'NEGATIVE_ONE',
                'value': -1.0
            },
            {
                'name': 'TWENTY_TWO',
                'value': 22.0
            }
        ]
    },
    'EnumWithGrpcNameValues': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'ALTERED_GRPC_NAME_ONE',
                'value': 1
            },
            {
                'name': 'TWO',
                'value': 2
            }
        ]
    },
    'FloatEnum': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'THREE_POINT_FIVE',
                'value': 3.5
            },
            {
                'name': 'FOUR_POINT_FIVE',
                'value': 4.5
            },
            {
                'name': 'FIVE_POINT_FIVE',
                'value': 5.5
            },
            {
                'name': 'SIX_POINT_FIVE',
                'value': 6.5
            },
            {
                'name': 'SEVEN_POINT_FIVE',
                'value': 7.5
            }
        ]
    },
    'GrpcColorOverride': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'RED',
                'value': 1
            },
            {
                'name': 'BLUE',
                'value': 2
            },
            {
                'name': 'YELLOW',
                'value': 5
            },
            {
                'name': 'BLACK',
                'value': 42
            }
        ]
    },
    'MobileOSNames': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'ANDROID',
                'value': 'Android'
            },
            {
                'name': 'IOS',
                'value': 'iOS'
            },
            {
                'name': 'NONE',
                'value': 'None'
            }
        ]
    },
    'NiFakeInt32AttributeValues': {
        'enum-value-prefix': 'NIFAKE_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'GRPC_COLOR_OVERRIDE_RED',
                'value': 1
            },
            {
                'name': 'GRPC_COLOR_OVERRIDE_BLUE',
                'value': 2
            },
            {
                'name': 'GRPC_COLOR_OVERRIDE_YELLOW',
                'value': 5
            },
            {
                'name': 'GRPC_COLOR_OVERRIDE_BLACK',
                'value': 42
            }
        ]
    },
    'NiFakeReal64AttributeValuesMapped': {
        'enum-value-prefix': 'NIFAKE_REAL64',
        'generate-mappings': True,
        'values': [
            {
                'name': 'FLOAT_ENUM_THREE_POINT_FIVE',
                'value': 3.5
            },
            {
                'name': 'FLOAT_ENUM_FOUR_POINT_FIVE',
                'value': 4.5
            },
            {
                'name': 'FLOAT_ENUM_FIVE_POINT_FIVE',
                'value': 5.5
            },
            {
                'name': 'FLOAT_ENUM_SIX_POINT_FIVE',
                'value': 6.5
            },
            {
                'name': 'FLOAT_ENUM_SEVEN_POINT_FIVE',
                'value': 7.5
            }
        ]
    },
    'Turtle': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'LEONARDO',
                'value': 0
            },
            {
                'name': 'DONATELLO',
                'value': 1
            },
            {
                'name': 'RAPHAEL',
                'value': 2
            },
            {
                'name': 'MICHELANGELO',
                'value': 3
            }
        ]
    }
}
