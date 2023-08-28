functions = {
    'AssertIntrSignal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AssertInterruptSignalMode',
                'name': 'mode',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'statusId',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'AssertTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'TriggerProtocol',
                'name': 'protocol',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'AssertUtilSignal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AssertUtilSignalMode',
                'name': 'mode',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'Clear': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Close': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'SessionOrObjectData',
                'name': 'objectHandle',
                'type': 'ViObject'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableEvent': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'EventType',
                'grpc_type': 'uint32',
                'name': 'eventType',
                'type': 'ViEventType'
            },
            {
                'direction': 'in',
                'enum': 'EventMechanism',
                'name': 'eventMechanism',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'DiscardEvents': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'EventType',
                'grpc_type': 'uint32',
                'name': 'eventType',
                'type': 'ViEventType'
            },
            {
                'direction': 'in',
                'enum': 'EventMechanism',
                'name': 'eventMechanism',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableEvent': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'EventType',
                'grpc_type': 'uint32',
                'name': 'eventType',
                'type': 'ViEventType'
            },
            {
                'direction': 'in',
                'enum': 'EventMechanism',
                'name': 'eventMechanism',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint32',
                'name': 'filterContext',
                'type': 'ViEventFilter'
            }
        ],
        'returns': 'ViStatus'
    },
    'FindNext': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'findHandle',
                'type': 'ViFindList'
            },
            {
                'direction': 'out',
                'name': 'instrumentDescriptor',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FindRsrc': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'rsrcManagerHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'expression',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'findHandle',
                'type': 'ViFindList'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'returnCount',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'repeated string',
                'name': 'instrumentDescriptor',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Flush': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'BufferMask',
                'name': 'mask',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttribute': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'SessionOrObjectData',
                'name': 'objectHandle',
                'type': 'ViObject'
            },
            {
                'direction': 'in',
                'name': 'attributeName',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'grpc_type': 'AttributeValueData',
                'name': 'attributeValue',
                'type': 'void'
            }
        ],
        'returns': 'ViStatus'
    },
    'GpibCommand': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'bytes',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViByte[]'
            },
            {
                'direction': 'in',
                'name': 'count',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'name': 'returnCount',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GpibControlATN': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'GpibControlAtnMode',
                'name': 'mode',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'GpibControlREN': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'GpibControlRenMode',
                'name': 'mode',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'GpibPassControl': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'primaryAddress',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'name': 'secondaryAddress',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'GpibSendIFC': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'In16Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'In32Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'In64Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'In8Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt8'
            }
        ],
        'returns': 'ViStatus'
    },
    'Lock': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'LockState',
                'grpc_type': 'uint32',
                'name': 'lockType',
                'type': 'ViAccessMode'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViUInt32'
            },
            {
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'requestedKey',
                'type': 'ViConstKeyId'
            },
            {
                'direction': 'out',
                'name': 'accessKey',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MapAddressEx': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'mapSize',
                'type': 'ViBusSize'
            },
            {
                'direction': 'in',
                'name': 'ownerAccess',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'suggestedAddress',
                'type': 'ViAddr'
            },
            {
                'direction': 'out',
                'name': 'address',
                'type': 'ViAddr'
            }
        ],
        'returns': 'ViStatus'
    },
    'MapTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'TriggerLine',
                'name': 'triggerSource',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'enum': 'TriggerLine',
                'name': 'triggerDestination',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'mode',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'MemAlloc': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint32',
                'name': 'size',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'uint32',
                'name': 'offset',
                'type': 'ViBusAddress'
            }
        ],
        'returns': 'ViStatus'
    },
    'MemAllocEx': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'size',
                'type': 'ViBusSize'
            },
            {
                'direction': 'out',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            }
        ],
        'returns': 'ViStatus'
    },
    'MemFreeEx': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveIn16Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'count'
                },
                'type': 'ViUInt16[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveIn32Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'count'
                },
                'type': 'ViUInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveIn64Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'count'
                },
                'type': 'ViUInt64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveIn8Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'count'
                },
                'type': 'ViUInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveOut16Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'in',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViUInt16[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveOut32Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'in',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViUInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveOut64Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'in',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViUInt64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'MoveOut8Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint64',
                'name': 'count',
                'type': 'ViBusSize'
            },
            {
                'direction': 'in',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViUInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Open': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'rsrcManagerHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'instrumentDescriptor',
                'type': 'ViConstRsrc'
            },
            {
                'direction': 'in',
                'enum': 'LockState',
                'grpc_type': 'uint32',
                'name': 'accessMode',
                'type': 'ViAccessMode'
            },
            {
                'direction': 'in',
                'name': 'openTimeout',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'OpenDefaultRM': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'rsrcManagerHandle',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Out16Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'Out32Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Out64Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'Out8Ex': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'AddressSpace',
                'name': 'addressSpace',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'fixed64',
                'name': 'offset',
                'type': 'ViBusAddress64'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt8'
            }
        ],
        'returns': 'ViStatus'
    },
    'ParseRsrcEx': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'sessionHandle',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViConstRsrc'
            },
            {
                'direction': 'out',
                'name': 'interfaceType',
                'type': 'ViUInt16'
            },
            {
                'direction': 'out',
                'name': 'interfaceNumber',
                'type': 'ViUInt16'
            },
            {
                'direction': 'out',
                'name': 'resourceClass',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'out',
                'name': 'expandedUnaliasedName',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            },
            {
                'direction': 'out',
                'name': 'aliasIfExists',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Peek16': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'void'
    },
    'Peek32': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'void'
    },
    'Peek64': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt64'
            }
        ],
        'returns': 'void'
    },
    'Peek8': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViUInt8'
            }
        ],
        'returns': 'void'
    },
    'Poke16': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'void'
    },
    'Poke32': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'void'
    },
    'Poke64': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt64'
            }
        ],
        'returns': 'void'
    },
    'Poke8': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'address',
                'type': 'ViAddr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViUInt8'
            }
        ],
        'returns': 'void'
    },
    'PxiReserveTriggers': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'cnt',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'trigBuses',
                'size': {
                    'mechanism': 'len',
                    'value': 'cnt'
                },
                'type': 'ViInt16[]'
            },
            {
                'direction': 'in',
                'name': 'trigLines',
                'size': {
                    'mechanism': 'len',
                    'value': 'cnt'
                },
                'type': 'ViInt16[]'
            },
            {
                'direction': 'out',
                'name': 'failureIndex',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'Read': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'grpc_type': 'bytes',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'returnCount'
                },
                'type': 'ViByte[]'
            },
            {
                'direction': 'in',
                'name': 'count',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'name': 'returnCount',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadAsync': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'grpc_type': 'bytes',
                'include_in_proto': False,
                'name': 'readBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'count'
                },
                'type': 'ViByte[]'
            },
            {
                'direction': 'in',
                'name': 'count',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'uint32',
                'name': 'jobIdentifier',
                'type': 'ViJobId'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadSTB': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'statusByte',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttribute': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'SessionOrObjectData',
                'name': 'objectHandle',
                'type': 'ViObject'
            },
            {
                'direction': 'in',
                'name': 'attributeName',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'grpc_type': 'AttributeValueData',
                'name': 'attributeValue',
                'type': 'ViAttrState'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetBuf': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'BufferMask',
                'name': 'mask',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'StatusDesc': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'grpc_type': 'SessionOrObjectData',
                'name': 'objectHandle',
                'type': 'ViObject'
            },
            {
                'direction': 'in',
                'name': 'statusValue',
                'type': 'ViStatus'
            },
            {
                'direction': 'out',
                'name': 'statusDescription',
                'size': {
                    'mechanism': 'fixed',
                    'value': 256
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Terminate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'degree',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'uint32',
                'name': 'jobIdentifier',
                'type': 'ViJobId'
            }
        ],
        'returns': 'ViStatus'
    },
    'Unlock': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnmapAddress': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnmapTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'TriggerLine',
                'name': 'triggerSource',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'enum': 'TriggerLine',
                'name': 'triggerDestination',
                'type': 'ViInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'UsbControlIn': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'bmRequestType',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'bRequest',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'wValue',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'name': 'wIndex',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'name': 'wLength',
                'type': 'ViUInt16'
            },
            {
                'direction': 'out',
                'grpc_type': 'bytes',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'returnCount'
                },
                'type': 'ViByte[]'
            },
            {
                'direction': 'out',
                'name': 'returnCount',
                'type': 'ViUInt16'
            }
        ],
        'returns': 'ViStatus'
    },
    'UsbControlOut': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'bmRequestType',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'bRequest',
                'type': 'ViInt16'
            },
            {
                'direction': 'in',
                'name': 'wValue',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'name': 'wIndex',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'name': 'wLength',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'grpc_type': 'bytes',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'wLength'
                },
                'type': 'ViByte[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'VxiCommandQuery': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'VxiCmdType',
                'name': 'mode',
                'type': 'ViUInt16'
            },
            {
                'direction': 'in',
                'name': 'command',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'name': 'commandResponse',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'WaitOnEvent': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'EventType',
                'grpc_type': 'uint32',
                'name': 'inEventType',
                'type': 'ViEventType'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'enum': 'EventType',
                'grpc_type': 'uint32',
                'name': 'outEventType',
                'type': 'ViEventType'
            },
            {
                'direction': 'out',
                'grpc_type': 'uint32',
                'name': 'eventHandle',
                'type': 'ViEvent'
            }
        ],
        'returns': 'ViStatus'
    },
    'Write': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'bytes',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViByte[]'
            },
            {
                'direction': 'in',
                'name': 'count',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'name': 'returnCount',
                'type': 'ViUInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteAsync': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'grpc_type': 'bytes',
                'name': 'buffer',
                'size': {
                    'mechanism': 'len',
                    'value': 'count'
                },
                'type': 'ViByte[]'
            },
            {
                'direction': 'in',
                'name': 'count',
                'type': 'ViUInt32'
            },
            {
                'direction': 'out',
                'grpc_type': 'uint32',
                'name': 'jobIdentifier',
                'type': 'ViJobId'
            }
        ],
        'returns': 'ViStatus'
    }
}
