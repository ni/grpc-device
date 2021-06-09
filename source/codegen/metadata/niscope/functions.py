# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 20.5.0d7
functions = {
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
    'AcquisitionStatus': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'out',
                'enum': 'AcquisitionStatus',
                'name': 'acquisitionStatus',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ActualMeasWfmSize': {
        'codegen_method': 'public',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'ArrayMeasurement',
                'name': 'arrayMeasFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'measWaveformSize',
                'type': 'ViInt32'
            }
        ],
        'render_in_session_base': True,
        'returns': 'ViStatus'
    },
    'ActualNumWfms': {
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
                'direction': 'out',
                'name': 'numWfms',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ActualRecordLength':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'recordLength',
                'direction':'out',
                'type':'ViInt32'
            }
        ],
        'returns':'ViStatus'
    },
    'AddWaveformProcessing': {
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
                'enum': 'ArrayMeasurement',
                'name': 'measFunction',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'AdjustSampleClockRelativeDelay':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'delay',
                'direction':'in',
                'type':'ViReal64'
            }
        ],
        'returns':'ViStatus'
    },
    'AutoSetup': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'CableSenseSignalStart': {
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
    'CableSenseSignalStop': {
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
    'CalFetchDate': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'CalibrationTypes',
                'name': 'whichOne',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'year',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'month',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'day',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CalFetchTemperature': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'whichOne',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'temperature',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'CalSelfCalibrate': {
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
                'enum': 'Option',
                'name': 'option',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'CheckAttributeViBoolean':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'in',
                'type':'ViBoolean'
            }
        ],
        'returns':'ViStatus'
    },
    'CheckAttributeViInt32':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'in',
                'type':'ViInt32',
                'grpc_raw_field_number':'4',
                'grpc_field_number':'5'
            }
        ],
        'returns':'ViStatus'
    },
    'CheckAttributeViInt64':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'in',
                'type':'ViInt64',
                'grpc_raw_field_number':'4',
                'grpc_field_number':'5'
            }
        ],
        'returns':'ViStatus'
    },
    'CheckAttributeViReal64':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'in',
                'type':'ViReal64',
                'grpc_raw_field_number':'4',
                'grpc_field_number':'5'
            }
        ],
        'returns':'ViStatus'
    },
    'CheckAttributeViSession':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'in',
                'type':'ViSession'
            }
        ],
        'returns':'ViStatus'
    },
    'CheckAttributeViString':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'in',
                'type':'ViConstString'
            }
        ],
        'returns':'ViStatus'
    },
    'ClearWaveformMeasurementStats': {
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
                'enum': 'ClearableMeasurement',
                'name': 'clearableMeasurementFunction',
                'type': 'ViInt32'
            }
        ],
        'returns': 'ViStatus'
    },
    'ClearWaveformProcessing': {
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
    'Close':{
        'cname' : 'niScope_close',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            }
        ],
        'returns':'ViStatus'
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
    'ConfigureAcquisition':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'acquisitionType',
                'direction':'in',
                'type':'ViInt32'
            }
        ],
        'returns':'ViStatus'
    },
    'ConfigureChanCharacteristics': {
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
                'name': 'inputImpedance',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'maxInputFrequency',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureClock':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'inputClockSource',
                'direction':'in',
                'type':'ViConstString',
            },
            {
                'name':'outputClockSource',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'clockSyncPulseSource',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'masterEnabled',
                'direction':'in',
                'type':'ViBoolean'
            }
        ],
        'returns':'ViStatus'
    },
    'ConfigureEqualizationFilterCoefficients': {
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
                'name': 'numberOfCoefficients',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'coefficients',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfCoefficients'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureHorizontalTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'minSampleRate',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'minNumPts',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'refPosition',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numRecords',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'enforceRealtime',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureRefLevels': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'low',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'mid',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'high',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerDigital': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'enum': 'TriggerSlope',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerEdge': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'TriggerSlope',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerGlitch': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'width',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'GlitchPolarity',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'GlitchCondition',
                'name': 'glitchCondition',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            },
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerHysteresis': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'hysteresis',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'TriggerSlope',
                'name': 'slope',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerImmediate': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerRunt': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'lowThreshold',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'highThreshold',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'RuntPolarity',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            },
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerSoftware': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerVideo': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'enableDcRestore',
                'type': 'ViBoolean'
            },
            {
                'direction': 'in',
                'enum': 'VideoSignalFormat',
                'name': 'signalFormat',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'VideoTriggerEvent',
                'name': 'event',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'lineNumber',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'VideoPolarity',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            }
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerWidth': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'triggerSource',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'level',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'lowThreshold',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'highThreshold',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'WidthPolarity',
                'name': 'polarity',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'WidthCondition',
                'name': 'condition',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'enum': 'TriggerCoupling',
                'name': 'triggerCoupling',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'holdoff',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'delay',
                'type': 'ViReal64'
            },
        ],
        'returns': 'ViStatus'
    },
    'ConfigureTriggerWindow':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'triggerSource',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'lowLevel',
                'direction':'in',
                'type':'ViReal64'
            },
            {
                'name':'highLevel',
                'direction':'in',
                'type':'ViReal64'
            },
            {
                'name':'windowMode',
                'direction':'in',
                'type':'ViInt32',
                'enum':'TriggerWindowMode'
            },
            {
                'name':'triggerCoupling',
                'direction':'in',
                'type':'ViInt32',
                'enum':'TriggerCoupling'
            },
            {
                'name':'holdoff',
                'direction':'in',
                'type':'ViReal64'
            },
            {
                'name':'delay',
                'direction':'in',
                'type':'ViReal64'
            }
        ],
        'returns':'ViStatus'
    },
    'ConfigureVertical': {
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
            },
            {
                'direction': 'in',
                'name': 'offset',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'VerticalCoupling',
                'name': 'coupling',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'probeAttenuation',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'enabled',
                'type': 'ViBoolean'
            }
        ],
        'returns': 'ViStatus'
    },
    'Disable': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ErrorHandler':{
        'cname' : 'niScope_errorHandler',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'errorCode',
                'direction':'in',
                'type':'ViStatus'
            },
            {
                'name':'errorSource',
                'direction':'in',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'fixed',
                    'value': 642
                }
            },
            {
                'name':'errorDescription',
                'direction':'out',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'fixed',
                    'value': 642
                }
            }
        ],
        'returns':'ViStatus'
    },
    'ExportAttributeConfigurationBuffer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'configuration',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]',
                'use_array': True
            }
        ],
        'returns': 'ViStatus'
    },
    'ExportAttributeConfigurationFile': {
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
    'ExportSignal':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'signal',
                'direction':'in',
                'type':'ViInt32',
                'enum':'ExportableSignals'
            },
            {
                'name':'signalIdentifier',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'outputTerminal',
                'direction':'in',
                'type':'ViConstString',
            }
        ],
        'returns':'ViStatus'
    },
    'Fetch': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchArrayMeasurement': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'ArrayMeasurement',
                'name': 'arrayMeasFunction',
                'type': 'ViInt32'
            },
            {
                'include_in_proto': False,
                'direction': 'in',
                'name': 'measurementWaveformSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'measWfm',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(measurement_waveform_size * actual_num_wfms)'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary16': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViInt16[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary32': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViInt32[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchBinary8': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'numpy': True,
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViInt8[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchComplex':{
        'codegen_method': 'CustomCode',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'timeout',
                'direction':'in',
                'type':'ViReal64'
            },
            {
                'name':'numSamples',
                'direction':'in',
                'type':'ViInt32'
            },
            {
                'name':'wfm',
                'direction':'out',
                'size':{
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type':'struct NIComplexNumber_struct[]',
                'grpc_type': 'repeated NIComplexNumber'
            },
            {
                'name':'wfmInfo',
                'direction':'out',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'self._actual_num_wfms()'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns':'ViStatus'
    },
    'FetchComplexBinary16':{
        'codegen_method': 'CustomCode',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'timeout',
                'direction':'in',
                'type':'ViReal64'
            },
            {
                'name':'numSamples',
                'direction':'in',
                'type':'ViInt32'
            },
            {
                'name':'wfm',
                'direction':'out',              
                'type': 'struct NIComplexI16_struct[]',
                'grpc_type': 'repeated NIComplexInt32',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                }
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns':'ViStatus'
    },
    'FetchMeasurement': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'ScalarMeasurement',
                'name': 'scalarMeasFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'result',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'FetchMeasurementStats': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'ScalarMeasurement',
                'name': 'scalarMeasFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'result',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'mean',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'stdev',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'min',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'max',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            },
            {
                'direction': 'out',
                'name': 'numInStats',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViInt32[]'
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
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
    'GetAttributeViSession':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'out',
                'type':'ViSession'
            }
        ],
        'returns':'ViStatus'
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'bufSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'value',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufSize'
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
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'direction': 'out',
                'name': 'channelString',
                'type': 'ViChar[]'
            },
        ],
        'returns': 'ViStatus'
    },
    'GetChannelNameFromString': {
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
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'bufferSize'
                },
                'direction': 'out',
                'name': 'name',
                'type': 'ViChar[]'
            },
        ],
        'returns': 'ViStatus'
    },
    'GetEqualizationFilterCoefficients': {
        'codegen_method': 'public',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'numberOfCoefficients',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'coefficients',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'numberOfCoefficients'
                },
                'type': 'ViReal64[]'
            }
        ],
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
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
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
    'GetErrorMessage':{
        'codegen_method': 'public',
        'is_error_handling': True,
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'errorCode',
                'direction':'in',
                'type':'ViStatus'
            },
            {
                'name':'bufferSize',
                'direction':'in',
                'type':'ViInt32'
            },
            {
                'name':'errorMessage',
                'direction':'out',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'ivi-dance',
                    'value':'bufferSize'
                }
            }
        ],
        'returns':'ViStatus',
        'use_session_lock': False
    },
    'GetFrequencyResponse':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channel',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'bufferSize',
                'direction':'in',
                'type':'ViInt32'
            },
            {
                'name':'frequencies',
                'direction':'out',
                'type':'ViReal64[]',
                'size':{
                    'mechanism':'passed-in',
                    'value':'bufferSize'
                }
            },
            {
                'name':'amplitudes',
                'direction':'out',
                'type':'ViReal64[]',
                'size':{
                    'mechanism':'passed-in',
                    'value':'bufferSize'
                }
            },
            {
                'name':'phases',
                'direction':'out',
                'type':'ViReal64[]',
                'size':{
                    'mechanism':'passed-in',
                    'value':'bufferSize'
                }
            },
            {
                'name':'numberOfFrequencies',
                'direction':'out',
                'type':'ViInt32'
            }
        ],
        'returns':'ViStatus'
    },
    'GetNormalizationCoefficients':{
        'codegen_method': 'CustomCode',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'include_in_proto': False,
                'name':'bufferSize',
                'direction':'in',
                'type':'ViInt32'
            },
            {
                'size': {
                    'mechanism': 'ivi_dance_with_a_twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfCoefficientSets',
                },
                'direction': 'out',
                'type': 'struct niScope_coefficientInfo[]',
                'name': 'coefficientInfo',
                'grpc_type': 'repeated CoefficientInfo'
            },
            {
                'name':'numberOfCoefficientSets',
                'direction':'out',
                'type':'ViInt32'
            }
        ],
        'returns':'ViStatus'
    },
    'GetScalingCoefficients': {
        'codegen_method': 'CustomCode',
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
                'include_in_proto': False,
                'direction': 'in',
                'name': 'bufferSize',
                'type': 'ViInt32'
            },
            {
                'size': {
                    'mechanism': 'ivi_dance_with_a_twist',
                    'value': 'bufferSize',
                    'value_twist': 'numberOfCoefficientSets',
                },
                'direction': 'out',
                'type': 'struct niScope_coefficientInfo[]',
                'name': 'coefficientInfo',
                'grpc_type': 'repeated CoefficientInfo'
            },
            {
                'direction': 'out',
                'name': 'numberOfCoefficientSets',
                'type': 'ViInt32'
            },
        ],
        'returns': 'ViStatus'
    },
    'GetStreamEndpointHandle':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'streamName',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'writerHandle',
                'direction':'out',
                'type':'ViUInt32'
            }
        ],
        'returns':'ViStatus'
    },
    'ImportAttributeConfigurationBuffer': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'name': 'sizeInBytes',
                'type': 'ViInt32'
            },
            {
                'direction': 'in',
                'name': 'configuration',
                'size': {
                    'mechanism': 'len',
                    'value': 'sizeInBytes'
                },
                'type': 'ViInt8[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'ImportAttributeConfigurationFile': {
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
    'Init':{
        'init_method': True,
        'cname' : 'niScope_init',
        'parameters':[
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'ViRsrc'
            },
            {
                'name':'idQuery',
                'direction':'in',
                'type':'ViBoolean'
            },
            {
                'name':'resetDevice',
                'direction':'in',
                'type':'ViBoolean'
            },
            {
                'name':'vi',
                'direction':'out',
                'type':'ViSession'
            }
        ],
        'returns':'ViStatus'
    },
    'InitWithOptions': {
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
            }
        ],
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'InitiateAcquisition': {
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
    'LockSession': {
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
        'returns': 'ViStatus',
        'use_session_lock': False
    },
    'ProbeCompensationSignalStart': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'ProbeCompensationSignalStop': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
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
                'direction': 'in',
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'name': 'numSamples',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'waveform',
                'size': {
                    'mechanism': 'custom-code',
                    'value': '(num_samples * actual_num_wfms)'
                },
                'type': 'ViReal64[]',
                'use_array': True
            },
            {
                'direction': 'out',
                'name': 'wfmInfo',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'struct niScope_wfmInfo[]',
                'grpc_type': 'repeated WaveformInfo'
            }
        ],
        'returns': 'ViStatus'
    },
    'ReadMeasurement': {
        'codegen_method': 'CustomCode',
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
                'name': 'timeout',
                'type': 'ViReal64'
            },
            {
                'direction': 'in',
                'enum': 'ScalarMeasurement',
                'name': 'scalarMeasFunction',
                'type': 'ViInt32'
            },
            {
                'direction': 'out',
                'name': 'result',
                'size': {
                    'mechanism': 'custom-code',
                    'value': 'actual_num_wfms'
                },
                'type': 'ViReal64[]'
            }
        ],
        'returns': 'ViStatus'
    },
    'Reset':{
        'cname' : 'niScope_reset',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            }
        ],
        'returns':'ViStatus'
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
    'ResetWithDefaults': {
        'codegen_method': 'no',
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            }
        ],
        'returns': 'ViStatus'
    },
    'RevisionQuery':{
        'cname' : 'niScope_revision_query',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'driverRevision',
                'direction':'out',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'fixed',
                    'value':256
                }
            },
            {
                'name':'firmwareRevision',
                'direction':'out',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'fixed',
                    'value':256
                }
            }
        ],
        'returns':'ViStatus'
    },
    'SampleMode':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'sampleMode',
                'direction':'out',
                'type':'ViInt32'
            }
        ],
        'returns':'ViStatus'
    },
    'SampleRate':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'sampleRate',
                'direction':'out',
                'type':'ViReal64'
            }
        ],
        'returns':'ViStatus'
    },
    'SelfTest':{
        'cname' : 'niScope_self_test',
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'selfTestResult',
                'direction':'out',
                'type':'ViInt16'
            },
            {
                'name':'selfTestMessage',
                'direction':'out',
                'type':'ViChar[]',
                'size':{
                    'mechanism':'fixed',
                    'value': 256
                }
            }
        ],
        'returns':'ViStatus'
    },
    'SendSoftwareTriggerEdge': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'vi',
                'type': 'ViSession'
            },
            {
                'direction': 'in',
                'enum': 'WhichTrigger',
                'name': 'whichTrigger',
                'type': 'ViInt32'
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt32',
                'grpc_raw_field_number':'4',
                'grpc_field_number':'5'
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViInt64',
                'grpc_raw_field_number':'4',
                'grpc_field_number':'5'
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
                'type': 'ViAttr'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'ViReal64',
                'grpc_raw_field_number':'4',
                'grpc_field_number':'5'
            }
        ],
        'returns': 'ViStatus'
    },
    'SetAttributeViSession':{
        'parameters':[
            {
                'name':'vi',
                'direction':'in',
                'type':'ViSession'
            },
            {
                'name':'channelList',
                'direction':'in',
                'type':'ViConstString'
            },
            {
                'name':'attributeId',
                'direction':'in',
                'type':'ViAttr'
            },
            {
                'name':'value',
                'direction':'in',
                'type':'ViSession'
            }
        ],
        'returns':'ViStatus'
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
                'name': 'channelList',
                'type': 'ViConstString'
            },
            {
                'direction': 'in',
                'name': 'attributeId',
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
    'UnlockSession': {
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
        'returns': 'ViStatus',
        'use_session_lock': False
    },
}
