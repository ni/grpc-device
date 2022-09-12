{
    'Abort': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'AbortKeepAlive': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ApplyLevelsAndTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'levelsSheet',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timingSheet',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'initialStateHighPins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'initialStateLowPins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'initialStateTristatePins',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ApplyTDROffsets': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numOffsets',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'selectDigitalFunction',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'waitUntilDone',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'BurstPatternSynchronized': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'direction': 'in',
                'name': 'sessions',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'selectDigitalFunction',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'waitUntilDone',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'frequency',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'Commit': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureActiveLoadLevels': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'iol',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'ioh',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'vcom',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureCycleNumberHistoryRAMTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'cycleNumber',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeConditionalJumpTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdge',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureDigitalEdgeStartTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'source',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdge',
                'name': 'edge',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureFirstFailureHistoryRAMTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureHistoryRAMCyclesToAcquire': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'HistoryRamCyclesToAcquire',
                'name': 'cyclesToAcquire',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigurePatternBurstSites': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'label',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'vectorOffset',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'cycleOffset',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'pretriggerSamples',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeConditionalJumpTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureSoftwareEdgeStartTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureStartLabel': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'label',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTerminationMode': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'TerminationMode',
                'name': 'mode',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetCompareEdgesStrobe': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'strobeEdge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetCompareEdgesStrobe2x': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'strobeEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'strobe2Edge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetDriveEdges': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DriveFormat',
                'name': 'format',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'driveOnEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveDataEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveReturnEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveOffEdge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetDriveEdges2x': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DriveFormat',
                'name': 'format',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'driveOnEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveDataEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveReturnEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveOffEdge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveData2Edge',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'driveReturn2Edge',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetDriveFormat': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'DriveFormat',
                'name': 'driveFormat',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetEdge': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'TimeSetEdgeType',
                'name': 'edge',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'time',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetEdgeMultiplier': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'edgeMultiplier',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetPeriod': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'period',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureVoltageLevels': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'vil',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'vih',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'vol',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'voh',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'vterm',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateCaptureWaveformFromFileDigicapture': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformFilePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateCaptureWaveformParallel': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateCaptureWaveformSerial': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'sampleWidth',
                'type': 'ViUInt32'
            },
            {
                'direction': 'in',
                'enum': 'BitOrder',
                'name': 'bitOrder',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateChannelMap': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'numSites',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreatePinGroup': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'pinGroupName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'pinList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreatePinMap': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'dutPinList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'systemPinList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateSourceWaveformFromFileTDMS': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformFilePath',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'writeWaveformData',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateSourceWaveformParallel': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'SourceDataMapping',
                'name': 'dataMapping',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateSourceWaveformSerial': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pinList',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'SourceDataMapping',
                'name': 'dataMapping',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'sampleWidth',
                'type': 'ViUInt32'
            },
            {
                'direction': 'in',
                'enum': 'BitOrder',
                'name': 'bitOrder',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CreateTimeSet': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'name',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DeleteAllTimeSets': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableConditionalJumpTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerIdentifier',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'DisableSites': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableMatchFailCombination': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'direction': 'in',
                'name': 'sessions',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'syncSession',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableSites': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'ExportSignal',
                'name': 'signal',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'signalIdentifier',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'samplesToRead',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'dataBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'dataBufferSize',
                    'value_twist': 'actualNumWaveforms'
                },
                'type': 'ViUInt32[]'
            },
            {
                'direction': 'out',
                'name': 'actualNumWaveforms',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'sampleIndex',
                'type': 'ViInt64'
            },
            {
                'direction': 'out',
                'name': 'patternIndex',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'timeSetIndex',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'vectorNumber',
                'type': 'ViInt64'
            },
            {
                'direction': 'out',
                'name': 'cycleNumber',
                'type': 'ViInt64'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'site',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'sampleIndex',
                'type': 'ViInt64'
            },
            {
                'direction': 'in',
                'name': 'dutCycleIndex',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'pinDataBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'enum': 'PinState',
                'name': 'expectedPinStates',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinDataBufferSize',
                    'value_twist': 'actualNumPinData'
                },
                'type': 'ViUInt8[]'
            },
            {
                'direction': 'out',
                'enum': 'PinState',
                'name': 'actualPinStates',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinDataBufferSize',
                    'value_twist': 'actualNumPinData'
                },
                'type': 'ViUInt8[]'
            },
            {
                'direction': 'out',
                'name': 'perPinPassFail',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinDataBufferSize',
                    'value_twist': 'actualNumPinData'
                },
                'type': 'ViBoolean[]'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'sampleIndex',
                'type': 'ViInt64'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'FrequencyMeasurementMode',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'frequenciesBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'frequencies',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'frequenciesBufferSize',
                    'value_twist': 'actualNumFrequencies'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViSession': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'index',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'indices',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'errorCode',
                'type': 'ViStatus'
            },
            {
                'direction': 'in',
                'name': 'errorDescriptionBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'failureCount',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumRead'
                },
                'type': 'ViInt64[]'
            },
            {
                'direction': 'out',
                'name': 'actualNumRead',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetHistoryRAMSampleCount': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'patternIndex',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'pinIndexesBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'pinIndexes',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'pinIndexesBufferSize',
                    'value_twist': 'actualNumPins'
                },
                'type': 'ViInt32[]'
            },
            {
                'direction': 'out',
                'name': 'actualNumPins',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetPatternPinList': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'startLabel',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'pinListBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'pinIndex',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'pinIndexes',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumValues'
                },
                'type': 'ViInt32[]'
            },
            {
                'direction': 'out',
                'name': 'siteNumbers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumValues'
                },
                'type': 'ViInt32[]'
            },
            {
                'direction': 'out',
                'name': 'channelIndexes',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumValues'
                },
                'type': 'ViInt32[]'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'passFailBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'passFail',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'passFailBufferSize',
                    'value_twist': 'actualNumSites'
                },
                'type': 'ViBoolean[]'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'siteList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'SiteResultType',
                'name': 'siteResultType',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'siteNumbersBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'siteNumbers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'siteNumbersBufferSize',
                    'value_twist': 'actualNumSiteNumbers'
                },
                'type': 'ViInt32[]'
            },
            {
                'direction': 'out',
                'name': 'actualNumSiteNumbers',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetTimeSetDriveFormat': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pin',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'enum': 'DriveFormat',
                'name': 'format',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetTimeSetEdge': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pin',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'TimeSetEdgeType',
                'name': 'edge',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'time',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetTimeSetEdgeMultiplier': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'pin',
                'repeated_capability_type': 'pins',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'timeSetIndex',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'nameBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'timeSetName',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'direction': 'in',
                'name': 'idQuery',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'direction': 'out',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
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
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'direction': 'in',
                'name': 'idQuery',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'resetDevice',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'optionString',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'get_last_error': 'get_last_error_message',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'IsDone': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'done',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'IsSiteEnabled': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'site',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadPattern': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadPinMap': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'pin',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'site',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'apertureTime',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'PpmuApertureTimeUnits',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'PpmuCurrentLimitBehavior',
                'name': 'behavior',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'PpmuOutputFunction',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'lowerVoltageLimit',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'PpmuMeasurementType',
                'name': 'measurementType',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'measurements',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumRead'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadSequencerFlag': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'flag',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadSequencerRegister': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'reg',
                'type': 'ViConstString'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadStatic': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'enum': 'PinState',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'bufferSize',
                    'value_twist': 'actualNumRead'
                },
                'type': 'ViUInt8[]'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            }
        ],
        'returns': 'ViStatus'
    },
    'ResetDevice': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelectFunction': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'SelectedFunction',
                'name': 'function',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'SelfCalibrate': {
        'parameters': [
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'name': 'testResult',
                'type': 'ViInt16'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'SoftwareTrigger',
                'name': 'trigger',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViReal64': {
        'codegen_method': 'public',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViSession': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'TDR': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'applyOffsets',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'name': 'offsetsBufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'offsets',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'offsetsBufferSize',
                    'value_twist': 'actualNumOffsets'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'actualNumOffsets',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnloadAllPatterns': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSequencerFlag': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'flag',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSequencerFlagSynchronized': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'sessionCount',
                'type': 'ViUInt32'
            },
            {
                'direction': 'in',
                'name': 'sessions',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'sessionCount'
                },
                'type': 'ViSession[]'
            },
            {
                'direction': 'in',
                'name': 'flag',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSequencerRegister': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'reg',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteSourceWaveformBroadcastU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'is_repeated_capability': True,
                'name': 'siteList',
                'repeated_capability_type': 'sites',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'waveformName',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numWaveforms',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'samplesPerWaveform',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
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
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'WriteStaticPinState',
                'name': 'state',
                'type': 'ViUInt8'
            }
        ],
        'returns': 'ViStatus'
    }
}