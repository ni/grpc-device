# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 19.5.0d7
functions = {
    'Abort': {
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
    'AbortKeepAlive': {
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
    'ApplyLevelsAndTiming': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'cppName': 'levelsSheet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'levelsSheet',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timingSheet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timingSheet',
                'type': 'ViConstString'
            },
            {
                'cppName': 'initialStateHighPins',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'initialStateHighPins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'initialStateLowPins',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'initialStateLowPins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'initialStateTristatePins',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'initialStateTristatePins',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ApplyTDROffsets': {
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
                'cppName': 'numOffsets',
                'determine_size_from': [
                    'offsets'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'numOffsets',
                'type': 'ViInt32'
            },
            {
                'cppName': 'offsets',
                'direction': 'in',
                'grpc_type': 'repeated double',
                'name': 'offsets',
                'size': {
                    'mechanism': 'len',
                    'value': 'numOffsets'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'BurstPattern': {
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
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'cppName': 'startLabel',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'cppName': 'selectDigitalFunction',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'selectDigitalFunction',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'waitUntilDone',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'waitUntilDone',
                'type': 'ViBoolean'
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
    },
    'BurstPatternSynchronized': {
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
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'startLabel',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'cppName': 'selectDigitalFunction',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'selectDigitalFunction',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'waitUntilDone',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'waitUntilDone',
                'type': 'ViBoolean'
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
    'ClockGeneratorAbort': {
        'cname': 'niDigital_ClockGenerator_Abort',
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
            }
        ],
        'returns': 'ViStatus'
    },
    'ClockGeneratorGenerateClock': {
        'cname': 'niDigital_ClockGenerator_GenerateClock',
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
                'cppName': 'frequency',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'frequency',
                'type': 'ViReal64'
            },
            {
                'cppName': 'selectDigitalFunction',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'selectDigitalFunction',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClockGeneratorInitiate': {
        'cname': 'niDigital_ClockGenerator_Initiate',
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
            }
        ],
        'returns': 'ViStatus'
    },
    'Close': {
        'cname': 'niDigital_close',
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
    'ConfigureActiveLoadLevels': {
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
                'cppName': 'iol',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'iol',
                'type': 'ViReal64'
            },
            {
                'cppName': 'ioh',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'ioh',
                'type': 'ViReal64'
            },
            {
                'cppName': 'vcom',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'vcom',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureCycleNumberHistoryRAMTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'cycleNumber',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'cycleNumber',
                'type': 'ViInt64'
            },
            {
                'cppName': 'pretriggerSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'pretriggerSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeConditionalJumpTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerIdentifier',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
            },
            {
                'cppName': 'source',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edge',
                'direction': 'in',
                'enum': 'DigitalEdge',
                'grpc_type': 'sint32',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeStartTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'source',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edge',
                'direction': 'in',
                'enum': 'DigitalEdge',
                'grpc_type': 'sint32',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureFirstFailureHistoryRAMTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pretriggerSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'pretriggerSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureHistoryRAMCyclesToAcquire': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'cyclesToAcquire',
                'direction': 'in',
                'enum': 'HistoryRamCyclesToAcquire',
                'grpc_type': 'sint32',
                'name': 'cyclesToAcquire',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigurePatternBurstSites': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigurePatternLabelHistoryRAMTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'label',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'label',
                'type': 'ViConstString'
            },
            {
                'cppName': 'vectorOffset',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'vectorOffset',
                'type': 'ViInt64'
            },
            {
                'cppName': 'cycleOffset',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'cycleOffset',
                'type': 'ViInt64'
            },
            {
                'cppName': 'pretriggerSamples',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'pretriggerSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeConditionalJumpTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerIdentifier',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeStartTrigger': {
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
    'ConfigureStartLabel': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'label',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'label',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTerminationMode': {
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
                'cppName': 'mode',
                'direction': 'in',
                'enum': 'TerminationMode',
                'grpc_type': 'sint32',
                'name': 'mode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetCompareEdgesStrobe': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'strobeEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'strobeEdge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetCompareEdgesStrobe2x': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'strobeEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'strobeEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'strobe2Edge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'strobe2Edge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetDriveEdges': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'format',
                'direction': 'in',
                'enum': 'DriveFormat',
                'grpc_type': 'sint32',
                'name': 'format',
                'type': 'ViInt32'
            },
            {
                'cppName': 'driveOnEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveOnEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveDataEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveDataEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveReturnEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveReturnEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveOffEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveOffEdge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetDriveEdges2x': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'format',
                'direction': 'in',
                'enum': 'DriveFormat',
                'grpc_type': 'sint32',
                'name': 'format',
                'type': 'ViInt32'
            },
            {
                'cppName': 'driveOnEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveOnEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveDataEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveDataEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveReturnEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveReturnEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveOffEdge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveOffEdge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveData2Edge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveData2Edge',
                'type': 'ViReal64'
            },
            {
                'cppName': 'driveReturn2Edge',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'driveReturn2Edge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetDriveFormat': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'driveFormat',
                'direction': 'in',
                'enum': 'DriveFormat',
                'grpc_type': 'sint32',
                'name': 'driveFormat',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetEdge': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edge',
                'direction': 'in',
                'enum': 'TimeSetEdgeType',
                'grpc_type': 'sint32',
                'name': 'edge',
                'type': 'ViInt32'
            },
            {
                'cppName': 'time',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'time',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetEdgeMultiplier': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edgeMultiplier',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'edgeMultiplier',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetPeriod': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'period',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'period',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureVoltageLevels': {
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
                'cppName': 'vil',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'vil',
                'type': 'ViReal64'
            },
            {
                'cppName': 'vih',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'vih',
                'type': 'ViReal64'
            },
            {
                'cppName': 'vol',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'vol',
                'type': 'ViReal64'
            },
            {
                'cppName': 'voh',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'voh',
                'type': 'ViReal64'
            },
            {
                'cppName': 'vterm',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'vterm',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateCaptureWaveformFromFileDigicapture': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformFilePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateCaptureWaveformParallel': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateCaptureWaveformSerial': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'sampleWidth',
                'direction': 'in',
                'grpc_type': 'uint32',
                'name': 'sampleWidth',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'bitOrder',
                'direction': 'in',
                'enum': 'BitOrder',
                'grpc_type': 'sint32',
                'name': 'bitOrder',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateChannelMap': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'numSites',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numSites',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreatePinGroup': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinGroupName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinGroupName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreatePinMap': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'dutPinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'dutPinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'systemPinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'systemPinList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateSourceWaveformFromFileTDMS': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformFilePath',
                'type': 'ViConstString'
            },
            {
                'cppName': 'writeWaveformData',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'writeWaveformData',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateSourceWaveformParallel': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'dataMapping',
                'direction': 'in',
                'enum': 'SourceDataMapping',
                'grpc_type': 'sint32',
                'name': 'dataMapping',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateSourceWaveformSerial': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'dataMapping',
                'direction': 'in',
                'enum': 'SourceDataMapping',
                'grpc_type': 'sint32',
                'name': 'dataMapping',
                'type': 'ViInt32'
            },
            {
                'cppName': 'sampleWidth',
                'direction': 'in',
                'grpc_type': 'uint32',
                'name': 'sampleWidth',
                'type': 'ViUInt32'
            },
            {
                'cppName': 'bitOrder',
                'direction': 'in',
                'enum': 'BitOrder',
                'grpc_type': 'sint32',
                'name': 'bitOrder',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateTimeSet': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'name',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'name',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteAllTimeSets': {
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
    'DisableConditionalJumpTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'triggerIdentifier',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableSites': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableStartTrigger': {
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
    'EnableMatchFailCombination': {
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
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'syncSession',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'syncSession',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableSites': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'EndChannelMap': {
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
    'ErrorMessage': {
        'cname': 'niDigital_error_message',
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
    'ExportSignal': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'signal',
                'direction': 'in',
                'enum': 'ExportSignal',
                'grpc_type': 'sint32',
                'name': 'signal',
                'type': 'ViInt32'
            },
            {
                'cppName': 'signalIdentifier',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'signalIdentifier',
                'type': 'ViConstString'
            },
            {
                'cppName': 'outputTerminal',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'outputTerminal',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchCaptureWaveformU32': {
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
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'samplesToRead',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'samplesToRead',
                'type': 'ViInt32'
            },
            {
                'cppName': 'timeout',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'cppName': 'dataBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'dataBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'out',
                'grpc_type': 'repeated uint32',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataBufferSize',
                    'value_twist': 'actualNumWaveforms'
                },
                'type': 'ViUInt32[]'
            },
            {
                'cppName': 'actualNumWaveforms',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumWaveforms',
                'type': 'ViInt32'
            },
            {
                'cppName': 'actualSamplesPerWaveform',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualSamplesPerWaveform',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchHistoryRAMCycleInformation': {
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
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'cppName': 'sampleIndex',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'sampleIndex',
                'type': 'ViInt64'
            },
            {
                'cppName': 'patternIndex',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'patternIndex',
                'type': 'ViInt32'
            },
            {
                'cppName': 'timeSetIndex',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'timeSetIndex',
                'type': 'ViInt32'
            },
            {
                'cppName': 'vectorNumber',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'vectorNumber',
                'type': 'ViInt64'
            },
            {
                'cppName': 'cycleNumber',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'cycleNumber',
                'type': 'ViInt64'
            },
            {
                'cppName': 'numDutCycles',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'numDutCycles',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchHistoryRAMCyclePinData': {
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
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'site',
                'type': 'ViConstString'
            },
            {
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'sampleIndex',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'sampleIndex',
                'type': 'ViInt64'
            },
            {
                'cppName': 'dutCycleIndex',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'dutCycleIndex',
                'type': 'ViInt32'
            },
            {
                'cppName': 'pinDataBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'pinDataBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'expectedPinStates',
                'direction': 'out',
                'enum': 'PinState',
                'grpc_type': 'bytes',
                'name': 'expectedPinStates',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinDataBufferSize',
                    'value_twist': 'actualNumPinData'
                },
                'type': 'ViUInt8[]'
            },
            {
                'cppName': 'actualPinStates',
                'direction': 'out',
                'enum': 'PinState',
                'grpc_type': 'bytes',
                'name': 'actualPinStates',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinDataBufferSize',
                    'value_twist': 'actualNumPinData'
                },
                'type': 'ViUInt8[]'
            },
            {
                'cppName': 'perPinPassFail',
                'direction': 'out',
                'grpc_type': 'repeated bool',
                'name': 'perPinPassFail',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinDataBufferSize',
                    'value_twist': 'actualNumPinData'
                },
                'type': 'ViBoolean[]'
            },
            {
                'cppName': 'actualNumPinData',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumPinData',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchHistoryRAMScanCycleNumber': {
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
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'cppName': 'sampleIndex',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'sampleIndex',
                'type': 'ViInt64'
            },
            {
                'cppName': 'scanCycleNumber',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'scanCycleNumber',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'FrequencyCounterConfigureMeasurementMode': {
        'cname': 'niDigital_FrequencyCounter_ConfigureMeasurementMode',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'measurementMode',
                'direction': 'in',
                'enum': 'FrequencyMeasurementMode',
                'grpc_type': 'sint32',
                'name': 'measurementMode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'FrequencyCounterConfigureMeasurementTime': {
        'cname': 'niDigital_FrequencyCounter_ConfigureMeasurementTime',
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
                'cppName': 'measurementTime',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'measurementTime',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'FrequencyCounterMeasureFrequency': {
        'cname': 'niDigital_FrequencyCounter_MeasureFrequency',
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
                'cppName': 'frequenciesBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'frequenciesBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'frequencies',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'frequencies',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'frequenciesBufferSize',
                    'value_twist': 'actualNumFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'actualNumFrequencies',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumFrequencies',
                'type': 'ViInt32'
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'value',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'value',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'value',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
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
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
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
                'cppName': 'nameBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'name',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'name',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'nameBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetChannelNameFromString': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'indices',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'indices',
                'type': 'ViConstString'
            },
            {
                'cppName': 'nameBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'names',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'names',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'nameBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'render_in_session_base': True,
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
                'cppName': 'errorCode',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'cppName': 'errorDescriptionBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'errorDescriptionBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'errorDescription',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'errorDescription',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'errorDescriptionBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetFailCount': {
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
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'failureCount',
                'direction': 'out',
                'grpc_type': 'repeated int64',
                'name': 'failureCount',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumRead'
                },
                'type': 'ViInt64[]'
            },
            {
                'cppName': 'actualNumRead',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumRead',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetHistoryRAMSampleCount': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'cppName': 'sampleCount',
                'direction': 'out',
                'grpc_type': 'int64',
                'name': 'sampleCount',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetPatternName': {
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
                'cppName': 'patternIndex',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'patternIndex',
                'type': 'ViInt32'
            },
            {
                'cppName': 'nameBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'name',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'name',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'nameBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'render_in_session_base': True,
        'returns': 'ViStatus'
    },
    'GetPatternPinIndexes': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'startLabel',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'cppName': 'pinIndexesBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'pinIndexesBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'pinIndexes',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'pinIndexes',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinIndexesBufferSize',
                    'value_twist': 'actualNumPins'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'actualNumPins',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumPins',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetPatternPinList': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'startLabel',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'cppName': 'pinListBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'pinListBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'pinList',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'pinList',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'pinListBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetPinName': {
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
                'cppName': 'pinIndex',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'pinIndex',
                'type': 'ViInt32'
            },
            {
                'cppName': 'nameBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'name',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'name',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'nameBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'render_in_session_base': True,
        'returns': 'ViStatus'
    },
    'GetPinResultsPinInformation': {
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
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'pinIndexes',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'pinIndexes',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumValues'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'siteNumbers',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'siteNumbers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumValues'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'channelIndexes',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'channelIndexes',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumValues'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'actualNumValues',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumValues',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSitePassFail': {
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
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'passFailBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'passFailBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'passFail',
                'direction': 'out',
                'grpc_type': 'repeated bool',
                'name': 'passFail',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'passFailBufferSize',
                    'value_twist': 'actualNumSites'
                },
                'type': 'ViBoolean[]'
            },
            {
                'cppName': 'actualNumSites',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumSites',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetSiteResultsSiteNumbers': {
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
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'siteResultType',
                'direction': 'in',
                'enum': 'SiteResultType',
                'grpc_type': 'sint32',
                'name': 'siteResultType',
                'type': 'ViInt32'
            },
            {
                'cppName': 'siteNumbersBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'siteNumbersBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'siteNumbers',
                'direction': 'out',
                'grpc_type': 'repeated sint32',
                'name': 'siteNumbers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'siteNumbersBufferSize',
                    'value_twist': 'actualNumSiteNumbers'
                },
                'type': 'ViInt32[]'
            },
            {
                'cppName': 'actualNumSiteNumbers',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumSiteNumbers',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetTimeSetDriveFormat': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pin',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pin',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'format',
                'direction': 'out',
                'enum': 'DriveFormat',
                'grpc_type': 'sint32',
                'name': 'format',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetTimeSetEdge': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pin',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pin',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edge',
                'direction': 'in',
                'enum': 'TimeSetEdgeType',
                'grpc_type': 'sint32',
                'name': 'edge',
                'type': 'ViInt32'
            },
            {
                'cppName': 'time',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'time',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetTimeSetEdgeMultiplier': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pin',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'pin',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'edgeMultiplier',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'edgeMultiplier',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetTimeSetName': {
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
                'cppName': 'timeSetIndex',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'timeSetIndex',
                'type': 'ViInt32'
            },
            {
                'cppName': 'nameBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'name',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'name',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'nameBufferSize'
                },
                'type': 'ViChar[]'
            }
        ],
        'render_in_session_base': True,
        'returns': 'ViStatus'
    },
    'GetTimeSetPeriod': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'timeSetName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'period',
                'direction': 'out',
                'grpc_type': 'double',
                'name': 'period',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'Init': {
        'cname': 'niDigital_init',
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
                'get_last_error': 'get_last_error_message',
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
            },
            {
                'cppName': 'errorMessage',
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
                'grpc_type': 'string',
                'name': 'errorMessage',
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Initiate': {
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
    'IsDone': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
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
    'IsSiteEnabled': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'cppName': 'enable',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'enable',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadLevels': {
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
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadPattern': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadPinMap': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadSpecifications': {
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
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadTiming': {
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
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
                'type': 'ViConstString'
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
        'render_in_session_base': True,
        'returns': 'ViStatus'
    },
    'MapPinToChannel': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'pin',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pin',
                'type': 'ViConstString'
            },
            {
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'site',
                'type': 'ViInt32'
            },
            {
                'cppName': 'channel',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channel',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureApertureTime': {
        'cname': 'niDigital_PPMU_ConfigureApertureTime',
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
                'cppName': 'apertureTime',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'apertureTime',
                'type': 'ViReal64'
            },
            {
                'cppName': 'units',
                'direction': 'in',
                'enum': 'PpmuApertureTimeUnits',
                'grpc_type': 'sint32',
                'name': 'units',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureCurrentLevel': {
        'cname': 'niDigital_PPMU_ConfigureCurrentLevel',
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
                'cppName': 'currentLevel',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'currentLevel',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureCurrentLevelRange': {
        'cname': 'niDigital_PPMU_ConfigureCurrentLevelRange',
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
                'cppName': 'range',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'range',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureCurrentLimit': {
        'cname': 'niDigital_PPMU_ConfigureCurrentLimit',
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
                'cppName': 'behavior',
                'direction': 'in',
                'enum': 'PpmuCurrentLimitBehavior',
                'grpc_type': 'sint32',
                'name': 'behavior',
                'type': 'ViInt32'
            },
            {
                'cppName': 'limit',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'limit',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureCurrentLimitRange': {
        'cname': 'niDigital_PPMU_ConfigureCurrentLimitRange',
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
                'cppName': 'range',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'range',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureOutputFunction': {
        'cname': 'niDigital_PPMU_ConfigureOutputFunction',
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
                'cppName': 'outputFunction',
                'direction': 'in',
                'enum': 'PpmuOutputFunction',
                'grpc_type': 'sint32',
                'name': 'outputFunction',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureVoltageLevel': {
        'cname': 'niDigital_PPMU_ConfigureVoltageLevel',
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
                'cppName': 'voltageLevel',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'voltageLevel',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUConfigureVoltageLimits': {
        'cname': 'niDigital_PPMU_ConfigureVoltageLimits',
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
                'cppName': 'lowerVoltageLimit',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'lowerVoltageLimit',
                'type': 'ViReal64'
            },
            {
                'cppName': 'upperVoltageLimit',
                'direction': 'in',
                'grpc_type': 'double',
                'name': 'upperVoltageLimit',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUMeasure': {
        'cname': 'niDigital_PPMU_Measure',
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
                'cppName': 'measurementType',
                'direction': 'in',
                'enum': 'PpmuMeasurementType',
                'grpc_type': 'sint32',
                'name': 'measurementType',
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
                'cppName': 'measurements',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'measurements',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumRead'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'actualNumRead',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumRead',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUSource': {
        'cname': 'niDigital_PPMU_Source',
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
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadSequencerFlag': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'flag',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'flag',
                'type': 'ViConstString'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadSequencerRegister': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'reg',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'reg',
                'type': 'ViConstString'
            },
            {
                'cppName': 'value',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadStatic': {
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
                'cppName': 'bufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'data',
                'direction': 'out',
                'enum': 'PinState',
                'grpc_type': 'bytes',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumRead'
                },
                'type': 'ViUInt8[]'
            },
            {
                'cppName': 'actualNumRead',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumRead',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset': {
        'cname': 'niDigital_reset',
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
    'ResetAttribute': {
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
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attributeId',
                'type': 'ViAttr'
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetDevice': {
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
    'SelectFunction': {
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
                'cppName': 'function',
                'direction': 'in',
                'enum': 'SelectedFunction',
                'grpc_type': 'sint32',
                'name': 'function',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfCalibrate': {
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
    'SelfTest': {
        'cname': 'niDigital_self_test',
        'codegen_method': 'public',
        'method_name_for_documentation': 'self_test',
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'testResult',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'testResult',
                'type': 'ViInt16'
            },
            {
                'cppName': 'testMessage',
                'direction': 'out',
                'grpc_type': 'string',
                'name': 'testMessage',
                'size': {
                    'mechanism': 'fixed',
                    'value': 2048
                },
                'type': 'ViChar[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'SendSoftwareEdgeTrigger': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'trigger',
                'direction': 'in',
                'enum': 'SoftwareTrigger',
                'grpc_type': 'sint32',
                'name': 'trigger',
                'type': 'ViInt32'
            },
            {
                'cppName': 'triggerIdentifier',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'value',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'enum': 'NiDigitalInt32AttributeValues',
                'grpc_type': 'sint32',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViInt64': {
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'int64',
                'name': 'value_raw',
                'type': 'ViInt64'
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
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
                'cppName': 'attribute',
                'direction': 'in',
                'grpc_type': 'NiDigitalAttribute',
                'name': 'attribute',
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
    'TDR': {
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
                'cppName': 'applyOffsets',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'applyOffsets',
                'type': 'ViBoolean'
            },
            {
                'cppName': 'offsetsBufferSize',
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'name': 'offsetsBufferSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'offsets',
                'direction': 'out',
                'grpc_type': 'repeated double',
                'name': 'offsets',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'offsetsBufferSize',
                    'value_twist': 'actualNumOffsets'
                },
                'type': 'ViReal64[]'
            },
            {
                'cppName': 'actualNumOffsets',
                'direction': 'out',
                'grpc_type': 'sint32',
                'name': 'actualNumOffsets',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnloadAllPatterns': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'unloadKeepAlivePattern',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'unloadKeepAlivePattern',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnloadSpecifications': {
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
                'cppName': 'filePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'filePath',
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
        'render_in_session_base': True,
        'returns': 'ViStatus'
    },
    'WaitUntilDone': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
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
    },
    'WriteSequencerFlag': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'flag',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'flag',
                'type': 'ViConstString'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSequencerFlagSynchronized': {
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
                'cppName': 'sessions',
                'direction': 'in',
                'grpc_type': 'repeated nidevice_grpc.Session',
                'name': 'sessions',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'cppName': 'flag',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'flag',
                'type': 'ViConstString'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSequencerRegister': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'reg',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'reg',
                'type': 'ViConstString'
            },
            {
                'cppName': 'value',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSourceWaveformBroadcastU32': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformSize',
                'determine_size_from': [
                    'waveformData'
                ],
                'direction': 'in',
                'grpc_type': 'sint32',
                'include_in_proto': False,
                'is_size_param': True,
                'linked_params_are_optional': False,
                'name': 'waveformSize',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformData',
                'direction': 'in',
                'grpc_type': 'repeated uint32',
                'name': 'waveformData',
                'size': {
                    'mechanism': 'len',
                    'value': 'waveformSize'
                },
                'type': 'ViUInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSourceWaveformDataFromFileTDMS': {
        'parameters': [
            {
                'cppName': 'vi',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformFilePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSourceWaveformSiteUniqueU32': {
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
                'cppName': 'siteList',
                'direction': 'in',
                'grpc_type': 'string',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'cppName': 'waveformName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'cppName': 'numWaveforms',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'numWaveforms',
                'type': 'ViInt32'
            },
            {
                'cppName': 'samplesPerWaveform',
                'direction': 'in',
                'grpc_type': 'sint32',
                'name': 'samplesPerWaveform',
                'type': 'ViInt32'
            },
            {
                'cppName': 'waveformData',
                'direction': 'in',
                'grpc_type': 'repeated uint32',
                'name': 'waveformData',
                'size': {
                    'mechanism': 'fixed',
                    'value': 1
                },
                'type': 'ViUInt32[]',
                'use_array': True
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteStatic': {
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
                'cppName': 'state',
                'direction': 'in',
                'enum': 'WriteStaticPinState',
                'grpc_type': 'uint32',
                'name': 'state',
                'type': 'ViUInt8'
            }
        ],
        'returns': 'ViStatus'
    }
}