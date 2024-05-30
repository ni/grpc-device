functions = {
    'ConvertForPowerUnitsUtility': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'referenceOrTriggerLevelIn',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'inputPowerUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'outputPowerUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'terminalConfiguration',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'bandwidth',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'referenceOrTriggerLevelOut',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DeleteSnapshot': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'personality',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetActiveResultName': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'signalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalType',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'resultSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultName',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'resultSize',
                    'value_twist': 'actualResultSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'actualResultSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultState',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetActiveTableName': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'activeTableName',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeAuthor': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF32': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'float32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF32Array': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF64Array': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredI32': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredI64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredString': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetCalibrationPlaneEnabled': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'calibrationPlaneEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetCalibrationPlaneNames': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'calibrationPlaneNames',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetError': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'name': 'errorCode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'errorDescriptionBufferSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorDescriptionBufferSize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetErrorString': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'errorDescriptionBufferSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorDescriptionBufferSize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetExternalAttenuationTableNames': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'externalAttenuationTableNames',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetForceAllTracesEnabled': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetInitiaitedSnapshotStrings': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'snapshotInfoCacheIndex',
                'type': 'uInt64'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArray',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'personalityIDArraySize',
                    'value_twist': 'personalityIDArrayActualSize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'personalityIDArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArrayActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNames',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'signalNamesSize',
                    'value_twist': 'signalNamesActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNames',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'resultNamesSize',
                    'value_twist': 'resultNamesActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotIdentifiersSize',
                    'value_twist': 'snapshotIdentifiersActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotIdentifiersSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiersActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArray',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotTimestampArraySize',
                    'value_twist': 'snapshotTimestampArrayActualSize'
                },
                'type': 'uInt64[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotTimestampArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArrayActualSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetLatestConfigurationSnapshot': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'include_in_proto': False,
                'name': 'snapshotInfoCacheIndex',
                'type': 'uInt64'
            },
            {
                'direction': 'out',
                'name': 'personalityID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalName',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'signalNameSize',
                    'value_twist': 'signalNameActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalNameSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNameActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifier',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotIdentifierSize',
                    'value_twist': 'snapshotIdentifierActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotIdentifierSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifierActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalConfigurationState',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalTimestamp',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'GetOpenSessionsInformation': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'infoJsonSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'infoJson',
                'size': {
                    'mechanism': 'ivi-dance',
                    'tags': [
                        'strlen-bug'
                    ],
                    'value': 'infoJsonSize'
                },
                'type': 'char[]'
            }            
        ],
        'returns': 'int32'
    },
    'GetPrivilegeLevel': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'name': 'isConnectionAlive',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'privilegeLevel',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetRFmxVersion': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'grpc_name': 'version',
                'name': 'RFmxVersion',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetSessionUniqueIdentifier': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceNames',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'optionString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'sessionUniqueIdentifierSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'sessionUniqueIdentifier',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'sessionUniqueIdentifierSize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetSignalConfigurationState64': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'signalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalType',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'signalState',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'timeStamp',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'GetSnapshotInfoFromCache': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'snapshotInfoCacheIndex',
                'type': 'uInt64'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'personalityIDArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'personalityIDArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArrayActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNames',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'signalNamesSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNames',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'resultNamesSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiers',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'snapshotIdentifiersSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotIdentifiersSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiersActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArray',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'snapshotTimestampArraySize'
                },
                'type': 'uInt64[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotTimestampArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArrayActualSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetSnapshotState': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'personality',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'snapshotState',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetTracesInfoForMonitorSnapshot': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'allTracesEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'LoadAllForRevert': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'LoadConfigurationsFromJSON': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'jsonString',
                'type': 'char[]',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize',
                },
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RegisterSpecialClientSnapshotInterest': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'RequestPrivilege': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'privilegeLevel',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'SaveAllForRevert': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'SaveConfigurationsToJSON': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'signalNames',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'jsonStringOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetForceAllTracesEnabled': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetIOTraceStatus': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'IOTraceStatus',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'UnregisterSpecialClientSnapshotInterest': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetSFPSessionAccessEnabled': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'optionString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'isSFPSessionAccessEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateDefaultSignalConfiguration': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'signalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'personalityID',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'LoadExternalAttenuationTable': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'DefineExternalAttenuationTable': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfPoints',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgSParameterExternalAttenuationTableFrequencies': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'sParameterFrequencies',
                'size': {
                    'mechanism': 'len',
                    'value': 'sParameterFrequenciesArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'sParameterFrequenciesArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgSParameterExternalAttenuationTableSParameter': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'sParameters',
                'size': {
                    'mechanism': 'len',
                    'value': 'sParameterTableSize'
                },
                'type': 'NIComplexDouble[]'
            },
            {
                'direction': 'in',
                'name': 'sParameterTableSize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sParameterOrientation',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DefineSParameterExternalAttenuationTable': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfFrequencyPoints',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'numberOfPorts',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SaveExternalAttenuationTable': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'description',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'CfgExternalAttenuationTableFrequencies': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'frequency',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgExternalAttenuationTableLosses': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'tableName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'externalAttenuation',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ReleaseLicense': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            }            
        ],
        'returns': 'int32'
    }
}