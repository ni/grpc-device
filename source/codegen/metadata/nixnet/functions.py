functions = {
    'Blink': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'interfaceRef',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'BlinkMode',
                'name': 'modifier',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'Clear': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ConnectTerminals': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'TerminalName',
                'name': 'source',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'TerminalName',
                'name': 'destination',
                'type': 'const char[]'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ConvertByteArrayToFramesSinglePoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'sizeOfValueBuffer'
                },
                'type': 'u8[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'number_of_frames',
                'proto_only': True,
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'max_payload_per_frame',
                'proto_only': True,
                'type': 'u32',
            },
            {
                'direction': 'in',
                'name': 'protocol',
                'proto_only': True,
                'enum': 'Protocol',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sizeOfBuffer'
                },
                'type': 'u8[]',
                'grpc_type': 'repeated FrameBufferResponse',
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['number_of_bytes_returned', 'protocol', 'enetflags_output_map_']
            },
            {
                'direction': 'in',
                'name': 'sizeOfBuffer',
                'hardcoded_value': 'get_frame_buffer_size(number_of_frames, max_payload_per_frame, protocol)',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'numberOfBytesReturned',
                'type': 'u32',
                'include_in_proto': False
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ConvertFramesToByteArraySinglePoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'frameBuffer',
                'type': 'u8',
                'pointer': True,
                'grpc_type': 'repeated FrameBufferRequest',
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['enetflags_input_map_']
            },
            {
                'direction': 'in',
                'name': 'numberOfBytesForFrames',
                'hardcoded_value': 'frame_buffer.size()',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sizeOfValueBuffer'
                },
                'type': 'u8[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ConvertFramesToSignalsSinglePoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'name': 'numberOfSignals',
                'direction': 'in',
                'type': 'u32',
                'proto_only': True
            },
            {
                'direction': 'in',
                'name': 'frameBuffer',
                'type': 'u8',
                'pointer': True,
                'grpc_type': 'repeated FrameBufferRequest',
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['enetflags_input_map_']
            },
            {
                'direction': 'in',
                'name': 'numberOfBytesForFrames',
                'hardcoded_value': 'frame_buffer.size()',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSignals'
                },
                'type': 'f64[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfValueBuffer',
                'include_in_proto': False,
                'hardcoded_value': 'number_of_signals * sizeof(f64)',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'timestampBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSignals'
                },
                'type': 'nxTimestamp100ns_t[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfTimestampBuffer',
                'include_in_proto': False,
                'hardcoded_value': 'number_of_signals * sizeof(f64)',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ConvertSignalsToFramesSinglePoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'sizeOfValueBuffer'
                },
                'type': 'f64[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'number_of_frames',
                'proto_only': True,
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'max_payload_per_frame',
                'proto_only': True,
                'type': 'u32',
            },
            {
                'direction': 'in',
                'name': 'protocol',
                'proto_only': True,
                'enum': 'Protocol',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sizeOfBuffer'
                },
                'type': 'u8[]',
                'grpc_type': 'repeated FrameBufferResponse',
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['number_of_bytes_returned', 'protocol', 'enetflags_output_map_']
            },
            {
                'direction': 'in',
                'name': 'sizeOfBuffer',
                'hardcoded_value': 'get_frame_buffer_size(number_of_frames, max_payload_per_frame, protocol)',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'numberOfBytesReturned',
                'type': 'u32',
                'include_in_proto': False
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ConvertTimestamp100nsTo1ns': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'from_timestamp_100ns',
                'type': 'nxTimestamp100ns_t'
            },
            {
                'direction': 'out',
                'name': 'to_timestamp_1ns',
                'type': 'nxTimestamp1ns_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ConvertTimestamp1nsTo100ns': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'from_timestamp_1ns',
                'type': 'nxTimestamp1ns_t'
            },
            {
                'direction': 'out',
                'name': 'to_timestamp_100ns',
                'type': 'nxTimestamp100ns_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'CreateSession': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'databaseName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'clusterName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'list',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'grpc_name': 'interface_name',
                'name': 'interface',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'CreateSessionMode',
                'name': 'mode',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'session',
                'type': 'nxSessionRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'CreateSessionByRef': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'numberOfDatabaseRef',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfDatabaseRef'
                },
                'name': 'arrayOfDatabaseRef',
                'type': 'nxDatabaseRef_t[]'
            },
            {
                'direction': 'in',
                'grpc_name': 'interface_name',
                'name': 'interface',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'CreateSessionMode',
                'name': 'mode',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'session',
                'type': 'nxSessionRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbAddAlias': {
        'cname': 'nxdbAddAlias',
        'parameters': [
            {
                'direction': 'in',
                'name': 'databaseAlias',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'databaseFilepath',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'defaultBaudRate',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbAddAlias64': {
        'cname': 'nxdbAddAlias64',
        'parameters': [
            {
                'direction': 'in',
                'name': 'databaseAlias',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'databaseFilepath',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'defaultBaudRate',
                'type': 'u64'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbCloseDatabase': {
        'cname': 'nxdbCloseDatabase',
        'custom_close_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'database',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'name': 'closeAllRefs',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbCreateObject': {
        'cname': 'nxdbCreateObject',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'parentObject',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'name': 'objectClass',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'objectName',
                'type': 'const char[]'
            },
            {
                'cross_driver_session': 'nxDatabaseRef_t',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbDeleteObject': {
        'cname': 'nxdbDeleteObject',
        'custom_close_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbDeploy': {
        'cname': 'nxdbDeploy',
        'parameters': [
            {
                'direction': 'in',
                'name': 'ipAddress',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'databaseAlias',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'waitForComplete',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'percentComplete',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbFindObject': {
        'cname': 'nxdbFindObject',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'parentObject',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'name': 'objectClass',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'objectName',
                'type': 'const char[]'
            },
            {
                'cross_driver_session': 'nxDatabaseRef_t',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbGetDBCAttribute': {
        'cname': 'nxdbGetDBCAttribute',
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'enum': 'GetDBCAttributeMode',
                'name': 'mode',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'attributeName',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'attributeTextSize',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'attributeText',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'attributeTextSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'isDefault',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbGetDBCAttributeSize': {
        'cname': 'nxdbGetDBCAttributeSize',
        'parameters': [
            {
                'direction': 'in',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'enum': 'GetDBCAttributeMode',
                'name': 'mode',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'attributeName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'attributeTextSize',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbGetDatabaseList': {
        'cname': 'nxdbGetDatabaseList',
        'codegen_method': 'CustomCode',
        'include_in_client': False,
        'parameters': [
            {
                'direction': 'in',
                'name': 'ipAddress',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'sizeofAliasBuffer',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'aliasBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sizeofAliasBuffer'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'sizeofFilepathBuffer',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'filepathBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sizeofFilepathBuffer'
                },
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'numberOfDatabases',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbGetDatabaseListSizes': {
        'cname': 'nxdbGetDatabaseListSizes',
        'parameters': [
            {
                'direction': 'in',
                'name': 'ipAddress',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'sizeofAliasBuffer',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'sizeofFilepathBuffer',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbGetProperty': {
        'cname': 'nxdbGetProperty',
        'codegen_method': 'CustomCodeCustomProtoMessage',
        'include_in_client': False,
        'parameters': [
            {
                'direction': 'in',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'enum': 'DBProperty',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'propertySize',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'enum': 'DBPropertyValue',
                'size': {
                    'mechanism': 'custom-code',
                    'value': ''
                },
                'name': 'propertyValue',
                'type': 'void *'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbGetPropertySize': {
        'cname': 'nxdbGetPropertySize',
        'parameters': [
            {
                'direction': 'in',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'enum': 'DBProperty',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'propertySize',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbMerge': {
        'cname': 'nxdbMerge',
        'parameters': [
            {
                'direction': 'in',
                'name': 'targetCluster',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'name': 'sourceObj',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'enum': 'CopyMode',
                'name': 'copyMode',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'prefix',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'waitForComplete',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'percentComplete',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbOpenDatabase': {
        'cname': 'nxdbOpenDatabase',
        'custom_close': 'DbCloseDatabase(id, false)',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'databaseName',
                'type': 'const char[]'
            },
            {
                'direction': 'out',
                'name': 'database',
                'type': 'nxDatabaseRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbRemoveAlias': {
        'cname': 'nxdbRemoveAlias',
        'parameters': [
            {
                'direction': 'in',
                'name': 'databaseAlias',
                'type': 'const char[]'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbSaveDatabase': {
        'cname': 'nxdbSaveDatabase',
        'parameters': [
            {
                'direction': 'in',
                'name': 'database',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'name': 'dbFilepath',
                'type': 'const char[]'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbSetProperty': {
        'cname': 'nxdbSetProperty',
        'codegen_method': 'CustomCodeCustomProtoMessage',
        'include_in_client': False,
        'parameters': [
            {
                'direction': 'in',
                'name': 'dbObject',
                'type': 'nxDatabaseRef_t'
            },
            {
                'direction': 'in',
                'enum': 'DBProperty',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'propertySize',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'propertyValue',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'propertySize'
                },
                'type': 'void *'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DbUndeploy': {
        'cname': 'nxdbUndeploy',
        'parameters': [
            {
                'direction': 'in',
                'name': 'ipAddress',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'name': 'databaseAlias',
                'type': 'const char[]'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'DisconnectTerminals': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'TerminalName',
                'name': 'source',
                'type': 'const char[]'
            },
            {
                'direction': 'in',
                'enum': 'TerminalName',
                'name': 'destination',
                'type': 'const char[]'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'Flush': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'FutureTimeTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'when',
                'type': 'nxTimestamp1ns_t'
            },
            {
                'direction': 'in',
                'enum': 'TimeScale',
                'name': 'timescale',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'GetProperty': {
        'codegen_method': 'CustomCodeCustomProtoMessage',
        'include_in_client': False,
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'Property',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'include_in_proto': False,
                'direction': 'in',
                'name': 'propertySize',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'enum': 'PropertyValue',
                'name': 'propertyValue',
                'size': {
                    'mechanism': 'custom-code',
                    'value': ''
                },
                'type': 'void *'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'GetPropertySize': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'Property',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'propertySize',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'GetSubProperty': {
        'codegen_method': 'CustomCodeCustomProtoMessage',
        'include_in_client': False,
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'activeIndex',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'enum': 'SubProperty',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'propertySize',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'enum': 'SubPropertyValue',
                'size': {
                    'mechanism': 'custom-code',
                    'value': ''
                },
                'name': 'propertyValue',
                'type': 'void *'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'GetSubPropertySize': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'activeIndex',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'enum': 'SubProperty',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'propertySize',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ReadFrame': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'number_of_frames',
                'proto_only': True,
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'max_payload_per_frame',
                'proto_only': True,
                'type': 'u32',
            },
            {
                'direction': 'in',
                'name': 'protocol',
                'proto_only': True,
                'enum': 'Protocol',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'buffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sizeOfBuffer'
                },
                'type': 'u8[]',
                'grpc_type': 'repeated FrameBufferResponse',
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['number_of_bytes_returned', 'protocol', 'enetflags_output_map_']
            },
            {
                'direction': 'in',
                'name': 'sizeOfBuffer',
                'hardcoded_value': 'get_frame_buffer_size(number_of_frames, max_payload_per_frame, protocol)',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'in',
                'enum': 'TimeOut',
                'name': 'timeout',
                'type': 'f64'
            },
            {
                'direction': 'out',
                'name': 'numberOfBytesReturned',
                'type': 'u32',
                'include_in_proto': False
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ReadSignalSinglePoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'numberOfSignals',
                'type': 'u32',
                'proto_only': True
            },
            {
                'direction': 'out',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSignals'
                },
                'type': 'f64[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'sizeOfValueBuffer',
                'hardcoded_value': 'number_of_signals * sizeof(f64)',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'timestampBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSignals'
                },
                'type': 'nxTimestamp100ns_t[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfTimestampBuffer',
                'include_in_proto': False,
                'hardcoded_value': 'number_of_signals * sizeof(f64)',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ReadSignalWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'TimeOut',
                'name': 'timeout',
                'type': 'f64'
            },
            {
                'direction': 'in',
                'name': 'samplesPerSignal',
                'type': 'u32',
                'proto_only': True
            },
            {
                'direction': 'in',
                'name': 'numberOfSignals',
                'type': 'u32',
                'proto_only': True
            },
            {
                'direction': 'out',
                'name': 'startTime',
                'type': 'nxTimestamp100ns_t'
            },
            {
                'direction': 'out',
                'name': 'deltaTime',
                'type': 'f64'
            },
            {
                'direction': 'out',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'samples_per_signal * number_of_signals'
                },
                'type': 'f64[]',
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['number_of_values_returned', 'number_of_signals']
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'hardcoded_value': 'samples_per_signal * number_of_signals * sizeof(f64)',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'numberOfValuesReturned',
                'include_in_proto': False,
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ReadSignalXY': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'timeLimit',
                'pointer': True,
                'input_passed_by_ptr': True,
                'type': 'nxTimestamp100ns_t'
            },
            {
                'direction': 'in',
                'name': 'samplesPerSignal',
                'type': 'u32',
                'proto_only': True
            },
            {
                'direction': 'in',
                'name': 'numberOfSignals',
                'type': 'u32',
                'proto_only': True
            },
            {
                'direction': 'out',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'samples_per_signal * number_of_signals'
                },
                'type': 'f64[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'hardcoded_value': 'samples_per_signal * number_of_signals * sizeof(f64)',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'timestampBuffer',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'samples_per_signal * number_of_signals'
                },
                'type': 'nxTimestamp100ns_t[]'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'sizeOfTimestampBuffer',
                'hardcoded_value': 'samples_per_signal * number_of_signals * sizeof(f64)',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'numPairsBuffer',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfSignals'
                },
                'type': 'u32[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfNumPairsBuffer',
                'include_in_proto': False,
                'hardcoded_value': 'number_of_signals * sizeof(u32)',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ReadState': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'ReadState',
                'name': 'stateID',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'stateSize',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'stateValue',
                'type': 'void *',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'stateSize'
                },
                'grpc_type' : 'ReadStateValue'
            },
            {
                'direction': 'out',
                'name': 'fault',
                'type': 'nxStatus_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'ReadStateTimeTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'TimeOut',
                'name': 'timeout',
                'type': 'f64'
            },
            {
                'direction': 'in',
                'name': 'stateSize',
                'type': 'u32',
                'hardcoded_value': 'sizeof(nxTimeLocalNetwork_t)',
                'include_in_proto': False
            },
            {
                'direction': 'out',
                'name': 'stateValue',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'stateSize'
                },
                'type': 'struct _nxTimeLocalNetwork_t',
                'grpc_type' : 'TimeLocalNetwork'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'SetProperty': {
        'codegen_method': 'CustomCodeCustomProtoMessage',
        'include_in_client': False,
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'Property',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'propertySize',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'enum': 'PropertyValue',
                'size': {
                    'mechanism': 'len',
                    'value': 'propertySize'
                },
                'name': 'propertyValue',
                'type': 'void *'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'SetSubProperty': {
        'codegen_method': 'CustomCodeCustomProtoMessage',
        'include_in_client': False,
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'activeIndex',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'enum': 'SubProperty',
                'name': 'propertyID',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'name': 'propertySize',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'propertyValue',
                'enum': 'SubPropertyValue',
                'size': {
                    'mechanism': 'len',
                    'value': 'propertySize'
                },
                'type': 'void *'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'Start': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'StartStopScope',
                'name': 'scope',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'StatusToString': {
        'status_expression' : '0',
        'parameters': [
            {
                'direction': 'in',
                'name': 'statusID',
                'type': 'nxStatus_t'
            },
            {
                'direction': 'in',
                'include_in_proto': False,
                'hardcoded_value': '2048U',
                'name': 'sizeofString',
                'type': 'u32'
            },
            {
                'direction': 'out',
                'name': 'statusDescription',
                'size': {
                    'mechanism': 'fixed',
                    'value': 2048
                },
                'type': 'char[]'
            }
        ],
        'returns': 'void'
    },
    'Stop': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'StartStopScope',
                'name': 'scope',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'SystemClose': {
        'custom_close_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'system',
                'type': 'nxSessionRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'SystemOpen': {
        'custom_close': 'SystemClose(id)',
        'init_method': True,
        'parameters': [
            {
                'direction': 'out',
                'name': 'system',
                'type': 'nxSessionRef_t'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'Wait': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'WaitCondition',
                'name': 'condition',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'paramIn',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'f64'
            },
            {
                'direction': 'out',
                'name': 'paramOut',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'WriteFrame': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'buffer',
                'type': 'u8',
                'pointer': True,
                'grpc_type': 'repeated FrameBufferRequest',
                'supports_standard_copy_convert': True,
                'additional_arguments_to_copy_convert': ['enetflags_input_map_']
            },
            {
                'direction': 'in',
                'name': 'numberOfBytesForFrames',
                'hardcoded_value': 'buffer.size()',
                'type': 'u32',
                'include_in_proto': False
            },
            {
                'direction': 'in',
                'enum': 'TimeOut',
                'name': 'timeout',
                'type': 'f64'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'WriteSignalSinglePoint': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'sizeOfValueBuffer'
                },
                'type': 'f64[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'WriteSignalWaveform': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'TimeOut',
                'name': 'timeout',
                'type': 'f64'
            },
            {
                'direction': 'in',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'sizeOfValueBuffer'
                },
                'type': 'f64[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'WriteSignalXY': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'TimeOut',
                'name': 'timeout',
                'type': 'f64'
            },
            {
                'direction': 'in',
                'name': 'valueBuffer',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'sizeOfValueBuffer'
                },
                'type': 'f64[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfValueBuffer',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'timestampBuffer',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'sizeOfTimestampBuffer'
                },
                'type': 'nxTimestamp100ns_t[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfTimestampBuffer',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'numPairsBuffer',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'sizeOfNumPairsBuffer'
                },
                'type': 'u32[]'
            },
            {
                'direction': 'in',
                'name': 'sizeOfNumPairsBuffer',
                'type': 'u32'
            }
        ],
        'returns': 'nxStatus_t'
    },
    'WriteState': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t'
            },
            {
                'direction': 'in',
                'enum': 'WriteState',
                'name': 'stateID',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'stateSize',
                'type': 'u32'
            },
            {
                'direction': 'in',
                'name': 'stateValue',
                'size': {
                    'mechanism': 'len-in-bytes',
                    'value': 'stateSize'
                },
                'type': 'void *',
                'grpc_type' : 'WriteStateValue'
            }
        ],
        'returns': 'nxStatus_t'
    }
}
