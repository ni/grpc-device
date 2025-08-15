functions = {
    'GetError': {
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
    'GetErrorMessage': {
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
                'cppName': 'errorCode',
                'direction': 'in',
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
                'cppName': 'errorMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetStartTimestampInformation': {
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
                'cppName': 'sysTimeIn128BitsT1',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t1',
                'grpc_type': 'uint32',
                'name': 'sysTimeIn128BitsT1',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sysTimeIn128BitsT2',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t2',
                'grpc_type': 'uint32',
                'name': 'sysTimeIn128BitsT2',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sysTimeIn128BitsT3',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t3',
                'grpc_type': 'uint32',
                'name': 'sysTimeIn128BitsT3',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sysTimeIn128BitsT4',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t4',
                'grpc_type': 'uint32',
                'name': 'sysTimeIn128BitsT4',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'deviceTimeInAbsoluteTimeUnits',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'deviceTimeInAbsoluteTimeUnits',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetStartTimestampInformationWithChannels': {
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numberOfChannels',
                'direction': 'in',
                'grpc_type': 'uint32',
                'is_size_param': True,
                'name': 'numberOfChannels',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sysTimeIn128BitsT1Array',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t1_array',
                'grpc_type': 'repeated uint32',
                'name': 'sysTimeIn128BitsT1Array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfChannels'
                },
                'type': 'ViUInt32[]'
            },
            {
                'cppName': 'sysTimeIn128BitsT2Array',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t2_array',
                'grpc_type': 'repeated uint32',
                'name': 'sysTimeIn128BitsT2Array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfChannels'
                },
                'type': 'ViUInt32[]'
            },
            {
                'cppName': 'sysTimeIn128BitsT3Array',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t3_array',
                'grpc_type': 'repeated uint32',
                'name': 'sysTimeIn128BitsT3Array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfChannels'
                },
                'type': 'ViUInt32[]'
            },
            {
                'cppName': 'sysTimeIn128BitsT4Array',
                'direction': 'out',
                'grpc_name': 'sys_time_in_128_bits_t4_array',
                'grpc_type': 'repeated uint32',
                'name': 'sysTimeIn128BitsT4Array',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfChannels'
                },
                'type': 'ViUInt32[]'
            },
            {
                'cppName': 'deviceTimeInAbsoluteTimeUnitsArray',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'deviceTimeInAbsoluteTimeUnitsArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfChannels'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
}
