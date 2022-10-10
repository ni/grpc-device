# -*- coding: utf-8 -*-
# This file is generated from NI-FAKE API metadata version 23.0.0d26
functions = {
    'Abort': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'AcceptListOfDurationsInSeconds': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'count',
                'determine_size_from': [
                    'delays'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'count',
                'type': 'ViInt32'
            },
            {
                'cppName': 'delays',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'delays',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'AcceptViSessionArray': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'direction': 'in',
                'grpc_type': 'uint32',
                'is_size_param': True,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessionArray',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessionArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'AcceptViUInt32Array': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'arrayLen',
                'determine_size_from': [
                    'uInt32Array'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'arrayLen',
                'type': 'ViInt32'
            },
            {
                'cppName': 'uInt32Array',
                'direction': 'in',
                'grpc_type': 'repeated uint32',
                'name': 'uInt32Array',
                'size': {
                    'mechanism': 'len',
                    'value': 'arrayLen'
                },
                'type': 'ViUInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'BoolArrayInputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'in',
                'grpc_type': 'repeated bool',
                'name': 'anArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'ViBoolean[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'BoolArrayOutputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'out',
                'grpc_type': 'repeated bool',
                'name': 'anArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'ViBoolean[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Close': {
        'cname': 'niFake_close',
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'CloseExtCal': {
        'codegen_method': 'public',
        'custom_close_method': True,
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'action',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'action',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CommandWithReservedParam': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'reserved',
                'direction': 'in',
                'grpc_type': 'bool',
                'hardcoded_value': 'nullptr',
                'include_in_proto': False,
                'name': 'reserved',
                'pointer': True,
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'Control4022': {
        'cname': 'niFake_4022Control',
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViString'
            },
            {
                'cppName': 'configuration',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'configuration',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateConfigurationList': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'numberOfListAttributes',
                'determine_size_from': [
                    'listAttributeIds'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfListAttributes',
                'type': 'ViInt32'
            },
            {
                'cppName': 'listAttributeIds',
                'direction': 'in',
                'grpc_type': 'repeated NiFakeAttribute',
                'name': 'listAttributeIds',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfListAttributes'
                },
                'type': 'ViAttr[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'CustomNestedStructRoundtrip': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'nestedCustomTypeIn',
                'direction': 'in',
                'grpc_type': 'CustomStructNestedTypedef',
                'name': 'nestedCustomTypeIn',
                'type': 'struct CustomStructNestedTypedef_struct'
            },
            {
                'cppName': 'nestedCustomTypeOut',
                'direction': 'out',
                'grpc_type': 'CustomStructNestedTypedef',
                'name': 'nestedCustomTypeOut',
                'type': 'struct CustomStructNestedTypedef_struct'
            }
        ],
        'returns': 'ViStatus'
    },
    'DoubleAllTheNums': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberCount',
                'determine_size_from': [
                    'numbers'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberCount',
                'type': 'ViInt32'
            },
            {
                'cppName': 'numbers',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'numbers',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberCount'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnumArrayOutputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'out',
                'enum': 'Turtle',
                'grpc_type': 'repeated sint32',
                'name': 'anArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'ViInt16[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnumInputFunctionWithDefaults': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aTurtle',
                'direction': 'in',
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'name': 'aTurtle',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorMessage': {
        'cname': 'niFake_error_message',
        'codegen_method': 'private',
        'is_error_handling': True,
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationBuffer': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sizeInBytes',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'cppName': 'configuration',
                'direction': 'out',
                'grpc_type': 'bytes',
                'name': 'configuration',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchWaveform': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformData',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'waveformData',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'actualNumberOfSamples',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumberOfSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetABoolean': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aBoolean',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'aBoolean',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetANumber': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'aNumber',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAStringOfFixedMaximumSize': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'aString',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAnIviDanceString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'aString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAnIviDanceWithATwistArray': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aString',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'aString',
                'type': 'ViConstString'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arrayOut',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'arrayOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualSize'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'actualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAnIviDanceWithATwistArrayOfCustomType': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arrayOut',
                'direction': 'out',
                'grpc_type': 'repeated FakeCustomStruct',
                'name': 'arrayOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualSize'
                },
                'type': 'struct CustomStruct[]'
            },
            {
                'cppName': 'actualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAnIviDanceWithATwistArrayWithInputArray': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'dataIn',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'dataIn',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySizeIn'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'arraySizeIn',
                'determine_size_from': [
                    'dataIn'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'arraySizeIn',
                'type': 'ViInt32'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arrayOut',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'arrayOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualSize'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'actualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAnIviDanceWithATwistByteArray': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arrayOut',
                'direction': 'out',
                'grpc_type': 'bytes',
                'name': 'arrayOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualSize'
                },
                'type': 'ViInt8[]'
            },
            {
                'cppName': 'actualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAnIviDanceWithATwistString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'aString',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualSize'
                },
                'type': 'ViChar[]'
            },
            {
                'cppName': 'actualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAnIviDanceWithATwistStringStrlenBug': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'stringOut',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'stringOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'tags': [
                        'strlen-bug'
                    ],
                    'value': 'bufferSize',
                    'value_twist': 'actualSize'
                },
                'type': 'ViChar[]'
            },
            {
                'cppName': 'actualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetArraySizeForCustomCode': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sizeOut',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'sizeOut',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetArrayUsingIviDance': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'arraySize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arrayOut',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'arrayOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetArrayViUInt8WithEnum': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'arrayLen',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'arrayLen',
                'type': 'ViInt32'
            },
            {
                'cppName': 'uInt8EnumArray',
                'direction': 'out',
                'enum': 'GrpcColorOverride',
                'grpc_type': 'bytes',
                'name': 'uInt8EnumArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arrayLen'
                },
                'type': 'ViUInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViBoolean': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt32': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'attributeValue',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViSession': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'attributeValue',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'attributeValue',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetBitfieldAsEnumArray': {
        'codegen_method': 'public',
        'parameters': [
            {
                'bitfield_as_enum_array': 'Bitfield',
                'cppName': 'flags',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'flags',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCalDateAndTime': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'calType',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'calType',
                'type': 'ViInt32'
            },
            {
                'cppName': 'month',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'month',
                'type': 'ViInt32'
            },
            {
                'cppName': 'day',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'day',
                'type': 'ViInt32'
            },
            {
                'cppName': 'year',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'year',
                'type': 'ViInt32'
            },
            {
                'cppName': 'hour',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'hour',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minute',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'minute',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCalInterval': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'months',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'months',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCustomType': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'cs',
                'direction': 'out',
                'grpc_type': 'FakeCustomStruct',
                'name': 'cs',
                'type': 'struct CustomStruct'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCustomTypeArray': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'cs',
                'direction': 'out',
                'grpc_type': 'repeated FakeCustomStruct',
                'name': 'cs',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'struct CustomStruct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetEnumValue': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aQuantity',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'aQuantity',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aTurtle',
                'direction': 'out',
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'name': 'aTurtle',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetError': {
        'codegen_method': 'private',
        'is_error_handling': True,
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'description',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'description',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetViInt32Array': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'arrayLen',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'arrayLen',
                'type': 'ViInt32'
            },
            {
                'cppName': 'int32Array',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'int32Array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arrayLen'
                },
                'type': 'ViInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetViUInt32Array': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'arrayLen',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'arrayLen',
                'type': 'ViInt32'
            },
            {
                'cppName': 'uInt32Array',
                'direction': 'out',
                'grpc_type': 'repeated uint32',
                'name': 'uInt32Array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arrayLen'
                },
                'type': 'ViUInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetViUInt8': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aUint8Number',
                'direction': 'out',
                'grpc_type': 'uint32',
                'name': 'aUint8Number',
                'type': 'ViUInt8'
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationBuffer': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sizeInBytes',
                'determine_size_from': [
                    'configuration'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'cppName': 'configuration',
                'direction': 'in',
                'grpc_type': 'bytes',
                'name': 'configuration',
                'size': {
                    'mechanism': 'len',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitExtCal': {
        'codegen_method': 'public',
        'custom_close': 'CloseExtCal(id, 0)',
        'init_method': True,
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'cppName': 'calibrationPassword',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'calibrationPassword',
                'type': 'ViString'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitWithOptions': {
        'codegen_method': 'public',
        'init_method': True,
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViString'
            },
            {
                'cppName': 'idQuery',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'idQuery',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'resetDevice',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'optionString',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'optionString',
                'type': 'ViConstString'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitWithVarArgs': {
        'codegen_method': 'public',
        'init_method': True,
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'stringArg',
                'direction': 'in',
                'grpc_type': 'string',
                'include_in_proto': False,
                'name': 'stringArg',
                'repeating_argument': True,
                'type': 'ViConstString'
            },
            {
                'cppName': 'turtle',
                'direction': 'in',
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'name': 'turtle',
                'repeating_argument': True,
                'type': 'ViInt16'
            },
            {
                'cppName': 'nameAndTurtle',
                'direction': 'in',
                'grpc_type': 'repeated StringAndTurtle',
                'is_compound_type': True,
                'max_length': 3,
                'name': 'nameAndTurtle',
                'repeated_var_args': True,
                'type': '...'
            }
        ],
        'returns': 'ViStatus'
    },
    'Initiate': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'MethodUsingEnumWithGrpcNameValues': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'usingEnum',
                'direction': 'in',
                'enum': 'EnumWithGrpcNameValues',
                'grpc_type': 'sint32',
                'name': 'usingEnum',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'MethodUsingWholeAndFractionalNumbers': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'wholeNumber',
                'direction': 'out',
                'enum': 'DecimalWholeNumber',
                'grpc_type': 'sint32',
                'name': 'wholeNumber',
                'type': 'ViInt32'
            },
            {
                'cppName': 'fractionalNumber',
                'direction': 'out',
                'grpc_type': 'double',
                'mapped-enum': 'DecimalMixedNumber',
                'name': 'fractionalNumber',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'MethodUsingWholeMappedNumbers': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'wholeNumber',
                'direction': 'out',
                'grpc_type': 'double',
                'mapped-enum': 'DecimalWholeNumberMapped',
                'name': 'wholeNumber',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'MethodWithGetLastErrorParam': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'lastError',
                'direction': 'out',
                'get_last_error': 'deprecated',
                'grpc_type': 'string',
                'name': 'lastError',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MethodWithGrpcFieldNumber': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_field_number': '5',
                'grpc_mapped_field_number': '6',
                'grpc_raw_field_number': '4',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'MethodWithGrpcOnlyParam': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'simpleParam',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'simpleParam',
                'type': 'ViInt32'
            },
            {
                'cppName': 'grpcOnlyParam',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'grpcOnlyParam',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'MultipleArrayTypes': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'outputArraySize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'outputArraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'outputArray',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'outputArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'outputArraySize'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'outputArrayOfFixedLength',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'outputArrayOfFixedLength',
                'size': {
                    'mechanism': 'fixed',
                    'value': 3
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'inputArraySizes',
                'determine_size_from': [
                    'inputArrayOfFloats',
                    'inputArrayOfIntegers'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'inputArraySizes',
                'type': 'ViInt32'
            },
            {
                'cppName': 'inputArrayOfFloats',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'inputArrayOfFloats',
                'size': {
                    'mechanism': 'len',
                    'value': 'inputArraySizes'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'inputArrayOfIntegers',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'inputArrayOfIntegers',
                'size': {
                    'mechanism': 'len',
                    'value': 'inputArraySizes'
                },
                'type': 'ViInt16[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MultipleArraysSameSize': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'values1',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values1',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'values2',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values2',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'values3',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values3',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'values4',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values4',
                'size': {
                    'mechanism': 'len',
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'values1',
                    'values2',
                    'values3',
                    'values4'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'size',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'MultipleArraysSameSizeWithOptional': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'values1',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values1',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'values2',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values2',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'values3',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values3',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'values4',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'values4',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'size'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'values5',
                'direction': 'in',
                'grpc_type': 'repeated FakeCustomStruct',
                'name': 'values5',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'size'
                },
                'type': 'struct CustomStruct[]'
            },
            {
                'cppName': 'size',
                'determine_size_from': [
                    'values1',
                    'values2',
                    'values3',
                    'values4',
                    'values5'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': True,
                'name': 'size',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'OneInputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'aNumber',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ParametersAreMultipleTypes': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aBoolean',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'aBoolean',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'anInt32',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'anInt32',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anInt64',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'anInt64',
                'type': 'ViInt64'
            },
            {
                'cppName': 'anIntEnum',
                'direction': 'in',
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'name': 'anIntEnum',
                'type': 'ViInt16'
            },
            {
                'cppName': 'aFloat',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'aFloat',
                'type': 'ViReal64'
            },
            {
                'cppName': 'aFloatEnum',
                'direction': 'in',
                'grpc_type': 'double',
                'mapped-enum': 'FloatEnum',
                'name': 'aFloatEnum',
                'type': 'ViReal64'
            },
            {
                'cppName': 'stringSize',
                'determine_size_from': [
                    'aString'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'stringSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aString',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'aString',
                'size': {
                    'mechanism': 'len',
                    'value': 'stringSize'
                },
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'PoorlyNamedSimpleFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Read': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'maximumTime',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'maximumTime',
                'type': 'ViReal64'
            },
            {
                'cppName': 'reading',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'reading',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadDataWithInOutIviTwist': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'data',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'bufferSize'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadDataWithMultipleIviTwistParamSets': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arrayOut',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'arrayOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualSize'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'actualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'otherBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'otherBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'otherArrayOut',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'otherArrayOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'otherBufferSize',
                    'value_twist': 'otherActualSize'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'otherActualSize',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'otherActualSize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadFromChannel': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'maximumTime',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'maximumTime',
                'type': 'ViInt32'
            },
            {
                'cppName': 'reading',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'reading',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReturnANumberAndAString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'aNumber',
                'type': 'ViInt16'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'aString',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReturnDurationInSeconds': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'timedelta',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'timedelta',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReturnListOfDurationsInSeconds': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'timedeltas',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'timedeltas',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReturnMultipleTypes': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aBoolean',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'aBoolean',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'anInt32',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'anInt32',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anInt64',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'anInt64',
                'type': 'ViInt64'
            },
            {
                'cppName': 'anIntEnum',
                'direction': 'out',
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'name': 'anIntEnum',
                'type': 'ViInt16'
            },
            {
                'cppName': 'aFloat',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'aFloat',
                'type': 'ViReal64'
            },
            {
                'cppName': 'aFloatEnum',
                'direction': 'out',
                'grpc_type': 'double',
                'mapped-enum': 'FloatEnum',
                'name': 'aFloatEnum',
                'type': 'ViReal64'
            },
            {
                'cppName': 'arraySize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'anArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySize'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'stringSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'stringSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'aString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'stringSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfTest': {
        'cname': 'niFake_self_test',
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'selfTestResult',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'selfTestResult',
                'type': 'ViInt16'
            },
            {
                'cppName': 'selfTestMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'selfTestMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViBoolean': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt32': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'enum': 'NiFakeInt32AttributeValues',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt64': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'attributeValue_raw',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'double',
                'mapped-enum': 'NiFakeReal64AttributeValuesMapped',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViString': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'attributeValue_raw',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetCustomType': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'cs',
                'direction': 'in',
                'grpc_type': 'FakeCustomStruct',
                'name': 'cs',
                'type': 'struct CustomStruct'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetCustomTypeArray': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'determine_size_from': [
                    'cs'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'cs',
                'direction': 'in',
                'grpc_type': 'repeated FakeCustomStruct',
                'name': 'cs',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'struct CustomStruct[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'StringValuedEnumInputFunctionWithDefaults': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aMobileOSName',
                'direction': 'in',
                'grpc_type': 'string',
                'mapped-enum': 'MobileOSNames',
                'name': 'aMobileOSName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'TwoInputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'aNumber',
                'type': 'ViReal64'
            },
            {
                'cppName': 'aString',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'aString',
                'type': 'ViString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Use64BitNumber': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'input',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'input',
                'type': 'ViInt64'
            },
            {
                'cppName': 'output',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'output',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'UseATwoDimensionParameter': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'array',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'array',
                'size': {
                    'mechanism': 'two-dimension',
                    'value': 'arrayLengths'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'arrayLengths',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'arrayLengths',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'arraySize',
                'determine_size_from': [
                    'arrayLengths'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'arraySize',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ViInt16ArrayInputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'determine_size_from': [
                    'anArray'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'in',
                'grpc_type': 'repeated sint32',
                'name': 'anArray',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'ViInt16[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ViUInt8ArrayInputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'in',
                'grpc_type': 'bytes',
                'name': 'anArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'ViUInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ViUInt8ArrayOutputFunction': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'out',
                'grpc_type': 'bytes',
                'name': 'anArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'ViUInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteWaveform': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfSamples',
                'determine_size_from': [
                    'waveform'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveform',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'waveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    }
}
