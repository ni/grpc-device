# -*- coding: utf-8 -*-
# This file is generated from NI-SWITCH API metadata version 22.8.0d130
functions = {
    'AbortScan': {
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
    'CanConnect': {
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
                'cppName': 'channel1',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel1',
                'type': 'ViConstString'
            },
            {
                'cppName': 'channel2',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel2',
                'type': 'ViConstString'
            },
            {
                'cppName': 'pathCapability',
                'direction': 'out',
                'enum': 'PathCapability',
                'grpc_type': 'sint32',
                'name': 'pathCapability',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViBoolean': {
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
                'grpc_type': 'NiSwitchAttribute',
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
    'CheckAttributeViInt32': {
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'enum': 'NiSwitchInt32AttributeValues',
                'grpc_field_number': '5',
                'grpc_raw_field_number': '4',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViReal64': {
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'attributeValue_raw',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViSession': {
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'attributeValue',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViString': {
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'attributeValue_raw',
                'type': 'ViString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearError': {
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
    'ClearInterchangeWarnings': {
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
    'Close': {
        'cname': 'niSwitch_close',
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
    'Commit': {
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
    'ConfigureScanList': {
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
                'cppName': 'scanlist',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'scanlist',
                'type': 'ViConstString'
            },
            {
                'cppName': 'scanMode',
                'direction': 'in',
                'enum': 'ScanMode',
                'grpc_type': 'sint32',
                'name': 'scanMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureScanTrigger': {
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
                'cppName': 'scanDelay',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'scanDelay',
                'type': 'ViReal64'
            },
            {
                'cppName': 'triggerInput',
                'direction': 'in',
                'enum': 'TriggerInput',
                'grpc_type': 'sint32',
                'name': 'triggerInput',
                'type': 'ViInt32'
            },
            {
                'cppName': 'scanAdvancedOutput',
                'direction': 'in',
                'enum': 'ScanAdvancedOutput',
                'grpc_type': 'sint32',
                'name': 'scanAdvancedOutput',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Connect': {
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
                'cppName': 'channel1',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel1',
                'type': 'ViConstString'
            },
            {
                'cppName': 'channel2',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel2',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConnectMultiple': {
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
                'cppName': 'connectionList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'connectionList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'Disable': {
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
    'Disconnect': {
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
                'cppName': 'channel1',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel1',
                'type': 'ViConstString'
            },
            {
                'cppName': 'channel2',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel2',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisconnectAll': {
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
    'DisconnectMultiple': {
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
                'cppName': 'disconnectionList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'disconnectionList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorMessage': {
        'cname': 'niSwitch_error_message',
        'codegen_method': 'public',
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
    'ErrorQuery': {
        'cname': 'niSwitch_error_query',
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
                'cppName': 'errorCode',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViInt32'
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
                'grpc_type': 'NiSwitchAttribute',
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
                'grpc_type': 'NiSwitchAttribute',
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
                'grpc_type': 'NiSwitchAttribute',
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
                'grpc_type': 'NiSwitchAttribute',
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
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
                'cppName': 'attributeValue',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'attributeValue',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetChannelName': {
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
                'cppName': 'index',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'index',
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
                'cppName': 'channelNameBuffer',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'channelNameBuffer',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetError': {
        'codegen_method': 'public',
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
                'cppName': 'code',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'code',
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
    'GetNextCoercionRecord': {
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
                'cppName': 'coercionRecord',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'coercionRecord',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetNextInterchangeWarning': {
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
                'cppName': 'interchangeWarning',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'interchangeWarning',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetPath': {
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
                'cppName': 'channel1',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel1',
                'type': 'ViConstString'
            },
            {
                'cppName': 'channel2',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel2',
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
                'cppName': 'path',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'path',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetRelayCount': {
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
                'cppName': 'relayName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'relayName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'relayCount',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'relayCount',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetRelayName': {
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
                'cppName': 'index',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'index',
                'type': 'ViInt32'
            },
            {
                'cppName': 'relayNameBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'relayNameBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'relayNameBuffer',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'relayNameBuffer',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'relayNameBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetRelayPosition': {
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
                'cppName': 'relayName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'relayName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'relayPosition',
                'direction': 'out',
                'enum': 'RelayPosition',
                'grpc_type': 'sint32',
                'name': 'relayPosition',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Init': {
        'cname': 'niSwitch_init',
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
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'get_last_error': 'deprecated',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
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
                'type': 'ViRsrc'
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
                'cppName': 'optionsString',
                'direction': 'in',
                'grpc_name': 'option_string',
                'grpc_type': 'string',
                'name': 'optionsString',
                'type': 'ViConstString'
            },
            {
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'get_last_error': 'deprecated',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitWithTopology': {
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
                'cppName': 'topology',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'topology',
                'type': 'ViConstString'
            },
            {
                'cppName': 'simulate',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'simulate',
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
                'cppName': 'vi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'get_last_error': 'deprecated',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'InitiateScan': {
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
    'InvalidateAllAttributes': {
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
    'IsDebounced': {
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
                'cppName': 'isDebounced',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'isDebounced',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'IsScanning': {
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
                'cppName': 'isScanning',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'isScanning',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'LockSession': {
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
                'cppName': 'callerHasLock',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'RelayControl': {
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
                'cppName': 'relayName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'relayName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'relayAction',
                'direction': 'in',
                'enum': 'RelayAction',
                'grpc_type': 'sint32',
                'name': 'relayAction',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset': {
        'cname': 'niSwitch_reset',
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
    'ResetInterchangeCheck': {
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
    'ResetWithDefaults': {
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
    'RevisionQuery': {
        'cname': 'niSwitch_revision_query',
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
                'cppName': 'instrumentDriverRevision',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'instrumentDriverRevision',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            },
            {
                'cppName': 'firmwareRevision',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'firmwareRevision',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'RouteScanAdvancedOutput': {
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
                'cppName': 'scanAdvancedOutputConnector',
                'direction': 'in',
                'enum': 'ScanAdvancedOutput',
                'grpc_type': 'sint32',
                'name': 'scanAdvancedOutputConnector',
                'type': 'ViInt32'
            },
            {
                'cppName': 'scanAdvancedOutputBusLine',
                'direction': 'in',
                'enum': 'ScanAdvancedOutput',
                'grpc_type': 'sint32',
                'name': 'scanAdvancedOutputBusLine',
                'type': 'ViInt32'
            },
            {
                'cppName': 'invert',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'invert',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'RouteTriggerInput': {
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
                'cppName': 'triggerInputConnector',
                'direction': 'in',
                'enum': 'TriggerInput',
                'grpc_type': 'sint32',
                'name': 'triggerInputConnector',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerInputBusLine',
                'direction': 'in',
                'enum': 'TriggerInput',
                'grpc_type': 'sint32',
                'name': 'triggerInputBusLine',
                'type': 'ViInt32'
            },
            {
                'cppName': 'invert',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'invert',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'Scan': {
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
                'cppName': 'scanlist',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'scanlist',
                'type': 'ViConstString'
            },
            {
                'cppName': 'initiation',
                'direction': 'in',
                'enum': 'HandshakingInitiation',
                'grpc_type': 'sint32',
                'name': 'initiation',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfTest': {
        'cname': 'niSwitch_self_test',
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
    'SendSoftwareTrigger': {
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
    'SetAttributeViBoolean': {
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
                'grpc_type': 'NiSwitchAttribute',
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'enum': 'NiSwitchInt32AttributeValues',
                'grpc_field_number': '5',
                'grpc_raw_field_number': '4',
                'grpc_type': 'sint32',
                'name': 'attributeValue',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'attributeValue_raw',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViSession': {
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'attributeValue',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViString': {
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
                'grpc_type': 'NiSwitchAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'cppName': 'attributeValue',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'attributeValue_raw',
                'type': 'ViString'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetContinuousScan': {
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
                'cppName': 'continuousScan',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'continuousScan',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetPath': {
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
                'cppName': 'pathList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pathList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnlockSession': {
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
                'cppName': 'callerHasLock',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WaitForDebounce': {
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
                'cppName': 'maximumTimeMs',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'maximumTimeMs',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'WaitForScanComplete': {
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
                'cppName': 'maximumTimeMs',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'maximumTimeMs',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    }
}