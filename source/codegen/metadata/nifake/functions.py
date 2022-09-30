# -*- coding: utf-8 -*-
# This file is generated from NI-FAKE API metadata version 1.2.0d9
functions = {
    'Abort': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Aborts a previously initiated thingie.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'AcceptListOfDurationsInSeconds': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Accepts list of floats or hightime.timedelta instances representing time delays.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
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
                'documentation': {
                    'description': 'Count of input values.'
                },
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
                'documentation': {
                    'description': 'A collection of time delay values.'
                },
                'grpc_type': 'repeated double',
                'name': 'delays',
                'python_api_converter_name': 'convert_timedeltas_to_seconds_real64',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViReal64[]',
                'type_in_documentation': 'hightime.timedelta, datetime.timedelta, or float in seconds'
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
        'documentation': {
            'description': 'This function accepts an array of booleans.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of elements in the array.'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'in',
                'documentation': {
                    'description': 'Input boolean array'
                },
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
        'documentation': {
            'description': 'This function returns an array of booleans.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of elements in the array.'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains an array of booleans'
                },
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
    'CreateConfigurationList': {
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
    'DoubleAllTheNums': {
        'documentation': {
            'description': 'Test for buffer with converter'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
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
                'documentation': {
                    'description': 'Number of elements in the number array'
                },
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
                'documentation': {
                    'description': 'numbers is an array of numbers we want to double.'
                },
                'grpc_type': 'repeated double',
                'name': 'numbers',
                'python_api_converter_name': 'convert_double_each_element',
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
        'documentation': {
            'description': 'This function returns an array of enums, stored as 16 bit integers under the hood.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of elements in the array.'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains an array of enums, stored as 16 bit integers under the hood '
                },
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
        'documentation': {
            'description': 'This function takes one parameter other than the session, which happens to be an enum and has a default value.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aTurtle',
                'default_value': 'Turtle.LEONARDO',
                'direction': 'in',
                'documentation': {
                    'description': 'Indicates a ninja turtle',
                    'table_body': [
                        [
                            '0',
                            'Leonardo'
                        ],
                        [
                            '1',
                            'Donatello'
                        ],
                        [
                            '2',
                            'Raphael'
                        ],
                        [
                            '3',
                            'Mich elangelo'
                        ]
                    ]
                },
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'name': 'aTurtle',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationBuffer': {
        'documentation': {
            'description': 'Export configuration buffer.'
        },
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
                'python_api_converter_name': 'convert_to_bytes',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]',
                'type_in_documentation': 'bytes',
                'use_array': True
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchWaveform': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Returns waveform data.'
        },
        'method_templates': [
            {
                'documentation_filename': 'default_method',
                'method_python_name_suffix': '',
                'session_filename': 'default_method'
            },
            {
                'documentation_filename': 'numpy_method',
                'method_python_name_suffix': '_into',
                'session_filename': 'numpy_read_method'
            }
        ],
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfSamples',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of samples to return'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfSamples',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformData',
                'direction': 'out',
                'documentation': {
                    'description': 'Samples fetched from the device. Array should be numberOfSamples big.'
                },
                'grpc_type': 'repeated double',
                'name': 'waveformData',
                'numpy': True,
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'cppName': 'actualNumberOfSamples',
                'direction': 'out',
                'documentation': {
                    'description': 'Number of samples actually fetched.'
                },
                'grpc_type': 'sint32',
                'name': 'actualNumberOfSamples',
                'type': 'ViInt32',
                'use_in_python_api': False
            }
        ],
        'returns': 'ViStatus'
    },
    'GetABoolean': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Returns a boolean.',
            'note': 'This function rules!'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aBoolean',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a boolean.'
                },
                'grpc_type': 'bool',
                'name': 'aBoolean',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetANumber': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Returns a number.',
            'note': 'This function rules!'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a number.'
                },
                'grpc_type': 'sint32',
                'name': 'aNumber',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAStringOfFixedMaximumSize': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Illustrates returning a string of fixed size.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'documentation': {
                    'description': 'String comes back here. Buffer must be 256 big.'
                },
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
        'documentation': {
            'description': 'Returns a string using the IVI dance.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of bytes in aString You can IVI-dance with this.'
                },
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns the string.'
                },
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
                'grpc_type': 'string',
                'name': 'arrayOut',
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
        'documentation': {
            'description': 'This function returns the size of the array for use in custom-code size mechanism.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'sizeOut',
                'direction': 'out',
                'documentation': {
                    'description': 'Size of array'
                },
                'grpc_type': 'sint32',
                'name': 'sizeOut',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetArrayUsingIviDance': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'This function returns an array of float whose size is determined with the IVI dance.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'arraySize',
                'direction': 'in',
                'documentation': {
                    'description': 'Specifies the size of the buffer for copyint arrayOut onto.'
                },
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'arrayOut',
                'direction': 'out',
                'documentation': {
                    'description': 'The array returned by this function'
                },
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
                'enum': 'Color',
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
        'documentation': {
            'description': 'Queries the value of a ViBoolean attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns the value of the attribute.'
                },
                'grpc_type': 'bool',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt32': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Queries the value of a ViInt32 attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns the value of the attribute.'
                },
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt64': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Queries the value of a ViInt64 attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns the value of the attribute.'
                },
                'grpc_type': 'int64',
                'name': 'attributeValue',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Queries the value of a ViReal attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns the value of the attribute.'
                },
                'grpc_type': 'double',
                'name': 'attributeValue',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViSession': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'attributeId',
                'type': 'ViInt32'
            },
            {
                'cppName': 'sessionOut',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'sessionOut',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViString': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Queries the value of a ViBoolean attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of bytes in attributeValue. You can IVI-dance with this.'
                },
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns the value of the attribute.'
                },
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
        'documentation': {
            'description': 'Returns the date and time of the last calibration performed.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'calType',
                'direction': 'in',
                'documentation': {
                    'description': 'Specifies the type of calibration performed (external or self-calibration).'
                },
                'grpc_type': 'sint32',
                'name': 'calType',
                'type': 'ViInt32'
            },
            {
                'cppName': 'month',
                'direction': 'out',
                'documentation': {
                    'description': 'Indicates the **month** of the last calibration.'
                },
                'grpc_type': 'sint32',
                'name': 'month',
                'type': 'ViInt32'
            },
            {
                'cppName': 'day',
                'direction': 'out',
                'documentation': {
                    'description': 'Indicates the **day** of the last calibration.'
                },
                'grpc_type': 'sint32',
                'name': 'day',
                'type': 'ViInt32'
            },
            {
                'cppName': 'year',
                'direction': 'out',
                'documentation': {
                    'description': 'Indicates the **year** of the last calibration.'
                },
                'grpc_type': 'sint32',
                'name': 'year',
                'type': 'ViInt32'
            },
            {
                'cppName': 'hour',
                'direction': 'out',
                'documentation': {
                    'description': 'Indicates the **hour** of the last calibration.'
                },
                'grpc_type': 'sint32',
                'name': 'hour',
                'type': 'ViInt32'
            },
            {
                'cppName': 'minute',
                'direction': 'out',
                'documentation': {
                    'description': 'Indicates the **minute** of the last calibration.'
                },
                'grpc_type': 'sint32',
                'name': 'minute',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCalInterval': {
        'documentation': {
            'description': 'Returns the recommended maximum interval, in **months**, between external calibrations.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'months',
                'direction': 'out',
                'documentation': {
                    'description': 'Specifies the recommended maximum interval, in **months**, between external calibrations.'
                },
                'grpc_type': 'sint32',
                'name': 'months',
                'python_api_converter_name': 'convert_month_to_timedelta',
                'type': 'ViInt32',
                'type_in_documentation': 'hightime.timedelta'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCustomType': {
        'documentation': {
            'description': 'This function returns a custom type.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'cs',
                'direction': 'out',
                'documentation': {
                    'description': 'Set using custom type'
                },
                'grpc_type': 'FakeCustomStruct',
                'name': 'cs',
                'type': 'struct CustomStruct'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetCustomTypeArray': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'This function returns a custom type.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of elements in the array.'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'cs',
                'direction': 'out',
                'documentation': {
                    'description': 'Get using custom type'
                },
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
        'documentation': {
            'description': 'Returns an enum value',
            'note': 'Splinter is not supported.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aQuantity',
                'direction': 'out',
                'documentation': {
                    'description': 'This is an amount.',
                    'note': 'The amount will be between -2^31 and (2^31-1)'
                },
                'grpc_type': 'sint32',
                'name': 'aQuantity',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aTurtle',
                'direction': 'out',
                'documentation': {
                    'description': 'Indicates a ninja turtle',
                    'table_body': [
                        [
                            '0',
                            'Leonardo'
                        ],
                        [
                            '1',
                            'Donatello'
                        ],
                        [
                            '2',
                            'Raphael'
                        ],
                        [
                            '3',
                            'Mich elangelo'
                        ]
                    ]
                },
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
        'documentation': {
            'description': 'Returns the error information associated with the session.'
        },
        'is_error_handling': True,
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns errorCode for the session. If you pass 0 for bufferSize, you can pass VI_NULL for this.'
                },
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'bufferSize',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of bytes in description buffer.'
                },
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'description',
                'direction': 'out',
                'documentation': {
                    'description': 'At least bufferSize big, string comes out here.'
                },
                'grpc_type': 'string',
                'name': 'description',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'GetViInt32Array': {
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
        'documentation': {
            'description': 'Import configuration buffer.'
        },
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
                'python_api_converter_name': 'convert_to_bytes',
                'size': {
                    'mechanism': 'len',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]',
                'type_in_documentation': 'bytes'
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
        'documentation': {
            'description': 'Creates a new IVI instrument driver session.'
        },
        'init_method': True,
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'documentation': {
                    'caution': 'This is just some string.',
                    'description': 'Contains the **resource_name** of the device to initialize.'
                },
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViString'
            },
            {
                'cppName': 'idQuery',
                'default_value': False,
                'direction': 'in',
                'documentation': {
                    'description': 'NI-FAKE is probably not needed.',
                    'table_body': [
                        [
                            'VI_TRUE (default)',
                            '1',
                            'Perform ID Query'
                        ],
                        [
                            'VI_FALSE',
                            '0',
                            'Skip ID Query'
                        ]
                    ]
                },
                'grpc_type': 'bool',
                'name': 'idQuery',
                'type': 'ViBoolean',
                'use_in_python_api': False
            },
            {
                'cppName': 'resetDevice',
                'default_value': False,
                'direction': 'in',
                'documentation': {
                    'description': 'Specifies whether to reset',
                    'table_body': [
                        [
                            'VI_TRUE (default)',
                            '1',
                            'Reset Device'
                        ],
                        [
                            'VI_FALSE',
                            '0',
                            "Don't Reset"
                        ]
                    ]
                },
                'grpc_type': 'bool',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'optionString',
                'direction': 'in',
                'documentation': {
                    'description': 'Some options'
                },
                'grpc_type': 'string',
                'name': 'optionString',
                'python_api_converter_name': 'convert_init_with_options_dictionary',
                'type': 'ViConstString',
                'type_in_documentation': 'dict'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'documentation': {
                    'description': 'Returns a ViSession handle that you use.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus',
        'use_session_lock': False
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
        'documentation': {
            'description': 'Initiates a thingie.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'MultipleArrayTypes': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Receives and returns multiple types of arrays.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'outputArraySize',
                'direction': 'in',
                'documentation': {
                    'description': 'Size of the array that will be returned.'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'outputArraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'outputArray',
                'direction': 'out',
                'documentation': {
                    'description': 'Array that will be returned.',
                    'note': 'The size must be at least outputArraySize.'
                },
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
                'documentation': {
                    'description': 'An array of doubles with fixed size.'
                },
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
                'documentation': {
                    'description': 'Size of inputArrayOfFloats and inputArrayOfIntegers'
                },
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
                'documentation': {
                    'description': 'Array of floats'
                },
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
                'default_value': None,
                'direction': 'in',
                'documentation': {
                    'description': 'Array of integers. Optional. If passed in then size must match that of inputArrayOfFloats.'
                },
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
        'documentation': {
            'description': 'Function to test multiple arrays that use the same size'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'values1',
                'direction': 'in',
                'documentation': {
                    'description': 'Array 1 of same size.'
                },
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
                'documentation': {
                    'description': 'Array 2 of same size.'
                },
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
                'documentation': {
                    'description': 'Array 3 of same size.'
                },
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
                'documentation': {
                    'description': 'Array 4 of same size.'
                },
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
                'documentation': {
                    'description': 'Size for all arrays'
                },
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
        'documentation': {
            'description': 'Function to test multiple arrays that use the same size'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'values1',
                'direction': 'in',
                'documentation': {
                    'description': 'Array 1 of same size.'
                },
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
                'documentation': {
                    'description': 'Array 2 of same size.'
                },
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
                'documentation': {
                    'description': 'Array 3 of same size.'
                },
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
                'documentation': {
                    'description': 'Array 4 of same size.'
                },
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
                'documentation': {
                    'description': 'Array 5 of same size.'
                },
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
                'documentation': {
                    'description': 'Size for all arrays'
                },
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
        'documentation': {
            'description': 'This function takes one parameter other than the session.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'in',
                'documentation': {
                    'description': 'Contains a number'
                },
                'grpc_type': 'sint32',
                'name': 'aNumber',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ParametersAreMultipleTypes': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Has parameters of multiple types.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aBoolean',
                'direction': 'in',
                'documentation': {
                    'description': 'Contains a boolean.'
                },
                'grpc_type': 'bool',
                'name': 'aBoolean',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'anInt32',
                'direction': 'in',
                'documentation': {
                    'description': 'Contains a 32-bit integer.'
                },
                'grpc_type': 'sint32',
                'name': 'anInt32',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anInt64',
                'direction': 'in',
                'documentation': {
                    'description': 'Contains a 64-bit integer.'
                },
                'grpc_type': 'int64',
                'name': 'anInt64',
                'type': 'ViInt64'
            },
            {
                'cppName': 'anIntEnum',
                'direction': 'in',
                'documentation': {
                    'description': 'Indicates a ninja turtle',
                    'table_body': [
                        [
                            '0',
                            'Leonardo'
                        ],
                        [
                            '1',
                            'Donatello'
                        ],
                        [
                            '2',
                            'Raphael'
                        ],
                        [
                            '3',
                            'Mich elangelo'
                        ]
                    ]
                },
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'name': 'anIntEnum',
                'type': 'ViInt16'
            },
            {
                'cppName': 'aFloat',
                'direction': 'in',
                'documentation': {
                    'description': 'The measured value.'
                },
                'grpc_type': 'double',
                'name': 'aFloat',
                'type': 'ViReal64'
            },
            {
                'cppName': 'aFloatEnum',
                'direction': 'in',
                'documentation': {
                    'description': 'A float enum.'
                },
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
                'documentation': {
                    'description': 'Number of bytes allocated for aString'
                },
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
                'documentation': {
                    'description': 'An IVI dance string.'
                },
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
        'documentation': {
            'description': 'This function takes no parameters other than the session.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'python_name': 'simple_function',
        'returns': 'ViStatus'
    },
    'Read': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Acquires a single measurement and returns the measured value.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'maximumTime',
                'direction': 'in',
                'documentation': {
                    'description': 'Specifies the **maximum_time** allowed in seconds.'
                },
                'grpc_type': 'double',
                'name': 'maximumTime',
                'python_api_converter_name': 'convert_timedelta_to_seconds_real64',
                'type': 'ViReal64',
                'type_in_documentation': 'hightime.timedelta'
            },
            {
                'cppName': 'reading',
                'direction': 'out',
                'documentation': {
                    'description': 'The measured value.'
                },
                'grpc_type': 'double',
                'name': 'reading',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadDataWithInOutIviTwist': {
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
        'documentation': {
            'description': 'Acquires a single measurement and returns the measured value.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'maximumTime',
                'direction': 'in',
                'documentation': {
                    'description': 'Specifies the **maximum_time** allowed in milliseconds.'
                },
                'grpc_type': 'sint32',
                'name': 'maximumTime',
                'python_api_converter_name': 'convert_timedelta_to_milliseconds_int32',
                'type': 'ViInt32',
                'type_in_documentation': 'hightime.timedelta'
            },
            {
                'cppName': 'reading',
                'direction': 'out',
                'documentation': {
                    'description': 'The measured value.'
                },
                'grpc_type': 'double',
                'name': 'reading',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReturnANumberAndAString': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Returns a number and a string.',
            'note': 'This function rules!'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a number.'
                },
                'grpc_type': 'sint32',
                'name': 'aNumber',
                'type': 'ViInt16'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a string. Buffer must be 256 bytes or larger.'
                },
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
        'documentation': {
            'description': 'Returns a hightime.timedelta instance.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'timedelta',
                'direction': 'out',
                'documentation': {
                    'description': 'Duration in seconds.'
                },
                'grpc_type': 'double',
                'name': 'timedelta',
                'python_api_converter_name': 'convert_seconds_real64_to_timedelta',
                'type': 'ViReal64',
                'type_in_documentation': 'hightime.timedelta'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReturnListOfDurationsInSeconds': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Returns a list of hightime.timedelta instances.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numberOfElements',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of elements in output.'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'numberOfElements',
                'type': 'ViInt32'
            },
            {
                'cppName': 'timedeltas',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a list of hightime.timedelta instances.'
                },
                'grpc_type': 'repeated double',
                'name': 'timedeltas',
                'python_api_converter_name': 'convert_seconds_real64_to_timedeltas',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfElements'
                },
                'type': 'ViReal64[]',
                'type_in_documentation': 'hightime.timedelta'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReturnMultipleTypes': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Returns multiple types.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aBoolean',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a boolean.'
                },
                'grpc_type': 'bool',
                'name': 'aBoolean',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'anInt32',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a 32-bit integer.'
                },
                'grpc_type': 'sint32',
                'name': 'anInt32',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anInt64',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains a 64-bit integer.'
                },
                'grpc_type': 'int64',
                'name': 'anInt64',
                'type': 'ViInt64'
            },
            {
                'cppName': 'anIntEnum',
                'direction': 'out',
                'documentation': {
                    'description': 'Indicates a ninja turtle',
                    'table_body': [
                        [
                            '0',
                            'Leonardo'
                        ],
                        [
                            '1',
                            'Donatello'
                        ],
                        [
                            '2',
                            'Raphael'
                        ],
                        [
                            '3',
                            'Mich elangelo'
                        ]
                    ]
                },
                'enum': 'Turtle',
                'grpc_type': 'sint32',
                'name': 'anIntEnum',
                'type': 'ViInt16'
            },
            {
                'cppName': 'aFloat',
                'direction': 'out',
                'documentation': {
                    'description': 'The measured value.'
                },
                'grpc_type': 'double',
                'name': 'aFloat',
                'type': 'ViReal64'
            },
            {
                'cppName': 'aFloatEnum',
                'direction': 'out',
                'documentation': {
                    'description': 'A float enum.'
                },
                'grpc_type': 'double',
                'mapped-enum': 'FloatEnum',
                'name': 'aFloatEnum',
                'type': 'ViReal64'
            },
            {
                'cppName': 'arraySize',
                'direction': 'in',
                'documentation': {
                    'description': 'Number of measurements to acquire.'
                },
                'grpc_type': 'sint32',
                'is_size_param': True,
                'name': 'arraySize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'anArray',
                'direction': 'out',
                'documentation': {
                    'description': 'An array of measurement values.',
                    'note': 'The size must be at least arraySize.'
                },
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
                'documentation': {
                    'description': 'Number of bytes allocated for aString'
                },
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'stringSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'aString',
                'direction': 'out',
                'documentation': {
                    'description': 'An IVI dance string.'
                },
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
    'SetAttributeViBoolean': {
        'codegen_method': 'private',
        'documentation': {
            'description': 'This function sets the value of a ViBoolean attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the value that you want to set the attribute to.'
                },
                'grpc_type': 'bool',
                'name': 'attributeValue',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt32': {
        'codegen_method': 'private',
        'documentation': {
            'description': 'This function sets the value of a ViInt32 attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the value that you want to set the attribute to.'
                },
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
        'documentation': {
            'description': 'This function sets the value of a ViInt64 attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the value that you want to set the attribute to.'
                },
                'grpc_type': 'int64',
                'name': 'attributeValue_raw',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'codegen_method': 'private',
        'documentation': {
            'description': 'This function sets the value of a ViReal64 attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the value that you want to set the attribute to.'
                },
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
        'documentation': {
            'description': 'This function sets the value of a ViString attribute.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'channelName',
                'direction': 'in',
                'documentation': {
                    'description': 'This is the channel(s) that this function will apply to.'
                },
                'grpc_type': 'string',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'attributeId',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the ID of an attribute.'
                },
                'grpc_type': 'NiFakeAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'documentation': {
                    'description': 'Pass the value that you want to set the attribute to.'
                },
                'grpc_type': 'string',
                'name': 'attributeValue_raw',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetCustomType': {
        'documentation': {
            'description': 'This function takes a custom type.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'cs',
                'direction': 'in',
                'documentation': {
                    'description': 'Set using custom type'
                },
                'grpc_type': 'FakeCustomStruct',
                'name': 'cs',
                'type': 'struct CustomStruct'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetCustomTypeArray': {
        'documentation': {
            'description': 'This function takes an array of custom types.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
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
                'documentation': {
                    'description': 'Number of elements in the array.'
                },
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
                'documentation': {
                    'description': 'Set using custom type'
                },
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
        'documentation': {
            'description': 'This function takes one parameter other than the session, which happens to be a string-valued enum and has a default value.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi**'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aMobileOSName',
                'default_value': 'MobileOSNames.ANDROID',
                'direction': 'in',
                'documentation': {
                    'description': 'Indicates a Mobile OS',
                    'table_body': [
                        [
                            'ANDROID',
                            'Android'
                        ],
                        [
                            'IOS',
                            'iOS'
                        ],
                        [
                            'NONE',
                            'None'
                        ]
                    ]
                },
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
        'documentation': {
            'description': 'This function takes two parameters other than the session.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'aNumber',
                'direction': 'in',
                'documentation': {
                    'description': 'Contains a number'
                },
                'grpc_type': 'double',
                'name': 'aNumber',
                'type': 'ViReal64'
            },
            {
                'cppName': 'aString',
                'direction': 'in',
                'documentation': {
                    'description': 'Contains a string'
                },
                'grpc_type': 'string',
                'name': 'aString',
                'type': 'ViString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Use64BitNumber': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Returns a number and a string.',
            'note': 'This function rules!'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'input',
                'direction': 'in',
                'documentation': {
                    'description': 'A big number on its way in.'
                },
                'grpc_type': 'int64',
                'name': 'input',
                'type': 'ViInt64'
            },
            {
                'cppName': 'output',
                'direction': 'out',
                'documentation': {
                    'description': 'A big number on its way out.'
                },
                'grpc_type': 'int64',
                'name': 'output',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'UseATwoDimensionParameter': {
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
        'documentation': {
            'description': 'Writes waveform to the driver'
        },
        'method_templates': [
            {
                'documentation_filename': 'default_method',
                'method_python_name_suffix': '',
                'session_filename': 'default_method'
            },
            {
                'documentation_filename': 'numpy_method',
                'method_python_name_suffix': '_numpy',
                'session_filename': 'numpy_write_method'
            }
        ],
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
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
                'documentation': {
                    'description': 'How many samples the waveform contains.'
                },
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
                'documentation': {
                    'description': 'Waveform data.'
                },
                'grpc_type': 'repeated double',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfSamples'
                },
                'type': 'ViReal64[]',
                'use_array': True
            }
        ],
        'returns': 'ViStatus'
    },
    'close': {
        'codegen_method': 'public',
        'documentation': {
            'description': 'Closes the specified session and deallocates resources that it reserved.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'python_name': '_close',
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'error_message': {
        'codegen_method': 'private',
        'documentation': {
            'description': 'Takes the errorCode returned by a functiona and returns it as a user-readable string.'
        },
        'is_error_handling': True,
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorCode',
                'direction': 'in',
                'documentation': {
                    'description': 'The errorCode returned from the instrument.'
                },
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'documentation': {
                    'description': 'The error information formatted into a string.'
                },
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'self_test': {
        'codegen_method': 'private',
        'documentation': {
            'description': 'Performs a self-test.'
        },
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'documentation': {
                    'description': 'Identifies a particular instrument session. You obtain the **vi** parameter from niFake_InitWithOptions.'
                },
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'selfTestResult',
                'direction': 'out',
                'documentation': {
                    'description': 'Contains the value returned from the instrument self-test. Zero indicates success.'
                },
                'grpc_type': 'sint32',
                'name': 'selfTestResult',
                'type': 'ViInt16'
            },
            {
                'cppName': 'selfTestMessage',
                'direction': 'out',
                'documentation': {
                    'description': 'This parameter contains the string returned from the instrument self-test. The array must contain at least 256 elements.'
                },
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
    }
}