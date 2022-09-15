# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 22.8.0d9999
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
    'AbortKeepAlive': {
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
    'ApplyLevelsAndTiming': {
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
        'cname': 'niDigital_ApplyTDROffsets',
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
    'ClockGeneratorGenerateClock': {
        'cname': 'niDigital_ClockGenerator_GenerateClock',
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
    'ConfigureActiveLoadLevels': {
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
    'ConfigurePatternBurstSites': {
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
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTimeSetCompareEdgesStrobe': {
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
    'ConfigureTimeSetCompareEdgesStrobe2X': {
        'cname': 'niDigital_ConfigureTimeSetCompareEdgesStrobe2x',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
    'ConfigureTimeSetDriveEdges2X': {
        'cname': 'niDigital_ConfigureTimeSetDriveEdges2x',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
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
    'CreateSourceWaveformFromFileTDMS': {
        'cname': 'niDigital_CreateSourceWaveformFromFileTDMS',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
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
                'cppName': 'pinList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinList',
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
    'DisableSites': {
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
            }
        ],
        'returns': 'ViStatus'
    },
    'EnableSites': {
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
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorMessage': {
        'cname': 'niDigital_error_message',
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
    'FetchCaptureWaveformU32': {
        'codegen_method': 'library-only',
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
        'cname': 'niDigital_FetchHistoryRAMCycleInformation',
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
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'site',
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
        'cname': 'niDigital_FetchHistoryRAMCyclePinData',
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
        'cname': 'niDigital_FetchHistoryRAMScanCycleNumber',
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
                'cppName': 'site',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'site',
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
    'FrequencyCounterMeasureFrequency': {
        'cname': 'niDigital_FrequencyCounter_MeasureFrequency',
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
                'grpc_type': 'bool',
                'name': 'value',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt32': {
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
                'grpc_type': 'sint32',
                'name': 'value',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViInt64': {
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
                'grpc_type': 'int64',
                'name': 'value',
                'type': 'ViInt64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViReal64': {
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
                'grpc_type': 'double',
                'name': 'value',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'GetAttributeViString': {
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
                'grpc_type': 'string',
                'name': 'index',
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
        'cname': 'niDigital_GetHistoryRAMSampleCount',
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
        'returns': 'ViStatus'
    },
    'GetPatternPinList': {
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
        'returns': 'ViStatus'
    },
    'GetPinResultsPinInformation': {
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
                'cppName': 'pin',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pin',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'pin',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pin',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
                'cppName': 'pin',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pin',
                'type': 'ViConstString'
            },
            {
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
        'returns': 'ViStatus'
    },
    'GetTimeSetPeriod': {
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
                'cppName': 'timeSet',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timeSet',
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
    'InitWithOptions': {
        'codegen_method': 'private',
        'parameters': [
            {
                'cppName': 'resourceName',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'resourceName',
                'type': 'ViConstString'
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
                'cppName': 'newVi',
                'direction': 'out',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'newVi',
                'type': 'ViSession'
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
    'IsDone': {
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
                'cppName': 'levelsFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'levelsFilePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LoadPattern': {
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
    'LoadPinMap': {
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
                'cppName': 'pinMapFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'pinMapFilePath',
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
                'cppName': 'specificationsFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'specificationsFilePath',
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
                'cppName': 'timingFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'timingFilePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'LockSession': {
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
                'cppName': 'callerHasLock',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'PPMUMeasure': {
        'cname': 'niDigital_PPMU_Measure',
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
                'cppName': 'measurementType',
                'direction': 'in',
                'enum': 'PPMUMeasurementType',
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
    'ReadSequencerFlag': {
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
                'cppName': 'flag',
                'direction': 'in',
                'grpc_type': 'string',
                'mapped-enum': 'SequencerFlag',
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
                'cppName': 'reg',
                'direction': 'in',
                'grpc_type': 'string',
                'mapped-enum': 'SequencerRegister',
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
                'cppName': 'channelList',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'channelList',
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
    'SelfCalibrate': {
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
    'SelfTest': {
        'cname': 'niDigital_self_test',
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
                'grpc_type': 'bool',
                'name': 'value',
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
                'enum': 'NiDigitalInt32AttributeValues',
                'grpc_type': 'sint32',
                'name': 'value',
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
                'grpc_type': 'int64',
                'name': 'value_raw',
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
                'grpc_type': 'double',
                'name': 'value_raw',
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
                'grpc_type': 'string',
                'name': 'value_raw',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'TDR': {
        'cname': 'niDigital_TDR',
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
                'cppName': 'specificationsFilePath',
                'direction': 'in',
                'grpc_type': 'string',
                'name': 'specificationsFilePath',
                'type': 'ViConstString'
            }
        ],
        'returns': 'ViStatus'
    },
    'UnlockSession': {
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
                'cppName': 'callerHasLock',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'callerHasLock',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'WaitUntilDone': {
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
                'cppName': 'flag',
                'direction': 'in',
                'grpc_type': 'string',
                'mapped-enum': 'SequencerFlag',
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
                'cppName': 'reg',
                'direction': 'in',
                'grpc_type': 'string',
                'mapped-enum': 'SequencerRegister',
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
        'cname': 'niDigital_WriteSourceWaveformDataFromFileTDMS',
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
                'type': 'ViUInt32[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'WriteStatic': {
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
