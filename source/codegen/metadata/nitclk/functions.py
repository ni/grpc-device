# -*- coding: utf-8 -*-
# This file is generated from NI-TClk API metadata version 23.0.0d7
functions = {
    'ConfigureForHomogeneousTriggers': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FinishSyncPulseSenderSynchronize': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'minTime',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'minTime',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'session',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'session',
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
                'grpc_type': 'NiTClkAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViSession': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'session',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'session',
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
                'grpc_type': 'NiTClkAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'session',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'session',
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
                'grpc_type': 'NiTClkAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'bufSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'tags': [
                        'strlen-bug'
                    ],
                    'value': 'bufSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetExtendedErrorInfo': {
        'codegen_method': 'public',
        'is_error_handling': True,
        'parameters': [
            {
                'cppName': 'errorString',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorStringSize'
                },
                'type': 'ViChar[]'
            },
            {
                'cppName': 'errorStringSize',
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'errorStringSize',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Initiate': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'IsDone': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'done',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'done',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'session',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'session',
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
                'grpc_type': 'NiTClkAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'value_raw',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViSession': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'session',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'session',
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
                'grpc_type': 'NiTClkAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'value',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViString': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'session',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'session',
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
                'grpc_type': 'NiTClkAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'value_raw',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetupForSyncPulseSenderSynchronize': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'minTime',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'minTime',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'Synchronize': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'minTclkPeriod',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'minTclkPeriod',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SynchronizeToSyncPulseSender': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'minTime',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'minTime',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'WaitUntilDone': {
        'codegen_method': 'public',
        'parameters': [
            {
                'cppName': 'sessionCount',
                'determine_size_from': [
                    'sessions'
                ],
                'direction': 'in',
                'grpc_type': 'uint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'len',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    }
}
