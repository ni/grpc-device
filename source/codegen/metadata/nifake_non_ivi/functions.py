# -*- coding: utf-8 -*-
functions = {
    'Close': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    },
    'CloseSecondarySession': {
        'custom_close_method': True,
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'secondarySessionHandle',
                'type': 'SecondarySessionHandle',
            },
        ],
        'returns': 'int32',
    },
    'GetCrossDriverSession': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'cross_driver_session': 'FakeCrossDriverHandle',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'crossDriverSession',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetLatestErrorMessage': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'message',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'size'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetStringAsReturnedValue': {
        'status_expression': 'string_out ? 0 : -1',
        'parameters': [
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'buf',
                'size': {
                    'mechanism': 'fixed',
                    'value': '512'
                },
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'string_out',
                'return_value': True,
                'type': 'const char[]'
            },
        ],
        'returns': 'const char*'
    },
    'GetMarbleAttributeDouble': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'MarbleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'double'
            },
        ],
        'returns': 'int32'
    },
    'GetMarbleAttributeInt32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'MarbleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetMarbleAttributeInt32Array': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'MarbleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '10'
                },
                'type': 'int32[]'
            }
        ],
        'returns': 'int32'
    },
    'Init': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'sessionName',
                'type': 'const char[]',
                'is_session_name': True
            },
            {
                'direction': 'out',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'direction': 'out',
                'get_last_error': 'get_last_error',
                'name': 'errorMessage',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'InitFromCrossDriverSession': {
        'init_method': True,
        'parameters': [
            {
                'cross_driver_session': 'FakeCrossDriverHandle',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'crossDriverSession',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    },
    'InitFromCrossDriverSessionArray': {
        'init_method': True,
        'parameters': [
            {
                'cross_driver_session': 'FakeCrossDriverHandle',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'crossDriverSessionArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfCrossDriverSessions'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfCrossDriverSessions',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    },
    'InitSecondarySession': {
        'init_method': True,
        'custom_close': 'CloseSecondarySession(id)',
        'parameters': [
            {
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'secondarySessionHandle',
                'type': 'SecondarySessionHandle',
            },
        ],
        'returns': 'int32',
    },
    'InitWithHandleNameAsSessionName': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'handleName',
                'type': 'const char[]',
                'is_session_name': True
            },
            {
                'direction': 'out',
                'name': 'handle',
                'type': 'FakeHandle'
            }
        ],
        'returns': 'int32'
    },
    'InitWithReturnedSession': {     
        'init_method' : True,
        'status_expression': 'handle == 0xDEADBEEF ? -1 : 0',
        'parameters': [
            {
                'direction': 'in',
                'name': 'handleName',
                'type': 'const char[]',
                'is_session_name': True
            },
            {
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'handle',
                'return_value': True,
                'type': 'FakeHandle'
            },
        ],
    'returns': 'FakeHandle'
    },
    'InputArraysWithNarrowIntegerTypes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'u16Array',
                'type': 'const myUInt16[]',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'i16Array',
                'type': 'const myInt16[]',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'i8Array',
                'type': 'const myInt8[]',
                'coerced': True
            }
        ],
        'returns': 'int32'
    },
    'IotaWithCustomSize': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'sizeOne',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sizeTwo',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(sizeOne < 0) ? sizeTwo : sizeOne + 1'
                },
                'type': 'int32[]'
            },
        ],
        'returns': 'int32'
    },
    'OutputArraysWithNarrowIntegerTypes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'numberOfU16Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'u16Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfU16Samples'
                },
                'type': 'myUInt16[]',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'numberOfI16Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'i16Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfI16Samples'
                },
                'type': 'myInt16[]',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'numberOfI8Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'i8Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfI8Samples'
                },
                'type': 'myInt8[]',
                'coerced': True
            },
        ],
        'returns': 'int32'
    },
    'InputArrayOfBytes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'u8Array',
                'type': 'const myUInt8[]',
            },
        ],
        'returns': 'int32'
    },
    'OutputArrayOfBytes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'numberOfU8Samples',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'u8Data',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfU8Samples'
                },
                'type': 'myUInt8[]',
            },
        ],
        'returns': 'int32'
    },
    'OutputArraysWithPassedInByPtrMechanism': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'i32Data',
                'size': {
                    'mechanism': 'passed-in-by-ptr',
                    'value': 'arraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'out',
                'name': 'u16Data',
                'size': {
                    'mechanism': 'passed-in-by-ptr',
                    'value': 'arraySize'
                },
                'coerced': True,
                'type': 'myUInt16[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RegisterCallback': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'inputData',
                'type': 'myInt16'
            },
            {
                'callback_params': [
                    {
                        'direction': 'out',
                        'name': 'dataOut',
                        'type': 'myInt16'
                    },
                ],
                'direction': 'in',
                'include_in_proto': False,
                'name': 'callbackFunction',
                'type': 'CallbackPtr'
            },
            {
                'callback_token': True,
                'direction': 'out',
                'include_in_proto': False,
                'name': 'callbackData',
                'type': 'void'
            }
        ],
        'stream_response': True,
        'returns': 'int32'
    },
    'ReadStream': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'start',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'stop',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            }
        ],
        'stream_response': True,
        'returns': 'int32'
    },
    'InputTimestamp': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'when',
                'type': 'CVIAbsoluteTime',
                'grpc_type': 'google.protobuf.Timestamp',
            },
        ],
        'returns': 'int32'
    },
    'OutputTimestamp': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'when',
                'type': 'CVIAbsoluteTime',
                'grpc_type': 'google.protobuf.Timestamp',
            },
        ],
        'returns': 'int32'
    },
    'InputVarArgs': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'inputName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'repeating_argument': True,
                'name': 'channelName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'repeating_argument': True,
                'enum': 'BeautifulColor',
                'name': 'color',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'repeating_argument': True,
                'name': 'powerUpState',
                'type': 'double'
            },
            {
                'direction': 'in',
                'repeated_var_args': True,
                'name': 'stringAndEnums',
                'is_compound_type': True,
                'grpc_type': 'repeated StringAndEnum',
                'max_length': 3
            }
        ],
        'returns': 'int32'
    },
    'OutputVarArgs': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'inputName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'repeating_argument': True,
                'name': 'channelName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'repeating_argument': True,
                'enum': 'BeautifulColor',
                'name': 'color',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'repeated_var_args': True,
                'name': 'channelNames',
                'grpc_type': 'repeated string',
                'max_length': 3
            },
            {
                'direction': 'out',
                'repeated_var_args': True,
                'name': 'colors',
                'grpc_type': 'repeated BeautifulColor',
                'max_length': 4
            }
        ],
        'returns': 'int32'
    },
    'ResetMarbleAttribute': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'MarbleAttribute',
                'name': 'attribute',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ScalarsWithNarrowIntegerTypes': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'u16',
                'type': 'myUInt16',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'i16',
                'type': 'myInt16',
                'coerced': True
            },
            {
                'direction': 'in',
                'name': 'i8',
                'type': 'myInt8',
                'coerced': True
            }
        ],
        'returns': 'int32'
    },
    'SetMarbleAttributeDouble': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'MarbleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'double'
            },
        ],
        'returns': 'int32'
    },
    'SetMarbleAttributeInt32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'handle',
                'type': 'FakeHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'MarbleAttribute',
                'name': 'attribute',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'SetColors': {
        'parameters': [
            {
                'direction': 'in',
                'enum': 'BeautifulColor',
                'name': 'colors',
                'type': 'int32[]',
                'size': {
                    'mechanism': 'fixed',
                    'value': '3'
                }
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetStructsWithCoercion': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'numberOfStructs',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'structs',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfStructs'
                },
                'type': 'struct StructWithCoercion_struct[]',
                'grpc_type': 'repeated StructWithCoercion'
            },
        ],
        'returns': 'int32'
    },
    'SetStructsWithCoercion': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'structs',
                'type': 'struct StructWithCoercion_struct[]',
                'grpc_type': 'repeated StructWithCoercion',
                'size': {
                    'mechanism': 'fixed',
                    'value': '3'
                }
            },
        ],
        'returns': 'int32'
    },
    'InputStringValuedEnum': {
        'parameters': [
            {
                'direction': 'in',
                'enum': 'MobileOSNames',
                'name': 'aName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'WriteBooleanArray': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'repeated bool',
                'name': 'bools',
                'type': 'int32[]',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                }
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    }
}
