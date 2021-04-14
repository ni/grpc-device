functions = {
  'AbortWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'CommitWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeMeasureTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgePulseTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeSequenceAdvanceTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeShutdownTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeSourceTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeStartTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureOvp': {
    'cname' : 'niDCPower_ConfigureOVP',
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'enabled',
        'direction': 'in',
        'type': 'ViBoolean'
      },
      {
        'name': 'limit',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeMeasureTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgePulseTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeSequenceAdvanceTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeShutdownTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeSourceTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeStartTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSourceModeWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'sourceMode',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'CreateAdvancedSequenceCommitStepWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'setAsActiveStep',
        'direction': 'in',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'CreateAdvancedSequenceStepWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'setAsActiveStep',
        'direction': 'in',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'CreateAdvancedSequenceWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'sequenceName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeIdCount',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'attributeIds',
        'direction': 'in',
        'type': 'ViInt32[]',
        'size': {
          'mechanism': 'len',
          'value': 'attributeIdCount'
        }
      },
      {
        'name': 'setAsActiveSequence',
        'direction': 'in',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'CreateAdvancedSequence': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'sequenceName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeIdCount',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'attributeIds',
        'direction': 'in',
        'type': 'ViInt32[]',
        'size': {
          'mechanism': 'len',
          'value': 'attributeIdCount'
        }
      },
      {
        'name': 'setAsActiveSequence',
        'direction': 'in',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'DeleteAdvancedSequenceWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'sequenceName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisablePulseTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisableSequenceAdvanceTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisableShutdownTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisableSourceTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisableStartTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ErrorQuery': {
    'cname' : 'niDCPower_error_query',
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'errorCode',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'errorMessage',
        'direction': 'in',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'fixed',
          'value': 256
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'ExportSignalWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'signal',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'signalIdentifier',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'outputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'InitializeWithIndependentChannels': {
    'init_method' : True,
    'parameters': [
      {
        'name': 'resourceName',
        'direction': 'in',
        'type': 'ViRsrc'
      },
      {
        'name': 'reset',
        'direction': 'in',
        'type': 'ViBoolean'
      },
      {
        'name': 'optionString',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'vi',
        'direction': 'out',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'InitiateWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'InvalidateAllAttributes': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ResetWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'SendSoftwareEdgeTriggerWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'trigger',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'WaitForEventWithChannels': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'eventId',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'timeout',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'Abort': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustCurrentLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'numberOfMeasurements',
        'direction': 'in',
        'type': 'ViUInt32'
      },
      {
        'name': 'requestedOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      },
      {
        'name': 'measuredOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustCurrentMeasurement': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'numberOfMeasurements',
        'direction': 'in',
        'type': 'ViUInt32'
      },
      {
        'name': 'reportedOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      },
      {
        'name': 'measuredOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustInternalReference': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'internalReference',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'adjustedInternalReference',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustOutputResistance': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'numberOfMeasurements',
        'direction': 'in',
        'type': 'ViUInt32'
      },
      {
        'name': 'requestedOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      },
      {
        'name': 'measuredOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustResidualCurrentOffset': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustResidualVoltageOffset': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustVoltageLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'numberOfMeasurements',
        'direction': 'in',
        'type': 'ViUInt32'
      },
      {
        'name': 'requestedOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      },
      {
        'name': 'measuredOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'CalAdjustVoltageMeasurement': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'numberOfMeasurements',
        'direction': 'in',
        'type': 'ViUInt32'
      },
      {
        'name': 'reportedOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      },
      {
        'name': 'measuredOutputs',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'numberOfMeasurements'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'CalSelfCalibrate': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ChangeExtCalPassword': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'oldPassword',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'newPassword',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ClearError': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ClearInterchangeWarnings': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'Close': {
      'cname' : 'niDCPower_close',
     'parameters': [
       {
         'name': 'vi',
         'direction': 'in',
         'type': 'ViSession'
       }
     ],
     'returns': 'ViStatus'
   },
  'CloseExtCal': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'action',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'Commit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureApertureTime': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'apertureTime',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'units',
        'direction': 'in',
        'type': 'ViInt32',
        'enum': 'ApertureTimeUnits'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureAutoZero': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'autoZero',
        'direction': 'in',
        'type': 'ViInt32',
        'enum': 'AutoZero'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureCurrentLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'level',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureCurrentLevelRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureCurrentLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'behavior',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'limit',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureCurrentLimitRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeMeasureTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgePulseTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeSequenceAdvanceTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeSourceTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureDigitalEdgeStartTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'inputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'edge',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureOutputEnabled': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'enabled',
        'direction': 'in',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureOutputFunction': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'function',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureOutputResistance': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'resistance',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePowerLineFrequency': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'powerlineFrequency',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseBiasCurrentLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'level',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseBiasCurrentLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'limit',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseBiasVoltageLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'level',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseBiasVoltageLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'limit',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseCurrentLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'level',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseCurrentLevelRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseCurrentLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'limit',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseCurrentLimitRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseVoltageLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'level',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseVoltageLevelRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseVoltageLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'limit',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigurePulseVoltageLimitRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSense': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'sense',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeMeasureTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgePulseTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeSequenceAdvanceTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeSourceTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSoftwareEdgeStartTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureSourceMode': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'sourceMode',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureVoltageLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'level',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureVoltageLevelRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureVoltageLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'limit',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConfigureVoltageLimitRange': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'range',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ConnectInternalReference': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'internalReference',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'CreateAdvancedSequenceStep': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'setAsActiveStep',
        'direction': 'in',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'DeleteAdvancedSequence': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'sequenceName',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'Disable': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisablePulseTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisableSequenceAdvanceTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisableSourceTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'DisableStartTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ErrorMessage': {
    'cname' : 'niDCPower_error_message',
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'errorCode',
        'direction': 'in',
        'type': 'ViStatus'
      },
      {
        'name': 'errorMessage',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'fixed',
          'value': 256
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'ExportAttributeConfigurationFile': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'filePath',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'ExportSignal': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'signal',
        'direction': 'in',
        'type': 'ViInt32',
        'enum': 'ExportSignal'
      },
      {
        'name': 'signalIdentifier',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'outputTerminal',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'FetchMultiple': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'timeout',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'count',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'voltageMeasurements',
        'direction': 'out',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'passed-in',
          'value': 'count'
        }
      },
      {
        'name': 'currentMeasurements',
        'direction': 'out',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'passed-in',
          'value': 'count'
        }
      },
      {
        'name': 'inCompliance',
        'direction': 'out',
        'type': 'ViBoolean[]',
        'size': {
          'mechanism': 'passed-in',
          'value': 'count'
        }
      },
      {
        'name': 'actualCount',
        'direction': 'out',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetAttributeViBoolean': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'out',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetAttributeViInt32': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'out',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetAttributeViInt64': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'out',
        'type': 'ViInt64'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetAttributeViReal64': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetAttributeViSession': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'out',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetAttributeViString': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'bufferSize',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'attributeValue',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'ivi-dance',
          'value': 'bufferSize'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'GetCalUserDefinedInfo': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'info',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'fixed',
          'value': 256
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'GetCalUserDefinedInfoMaxSize': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'infoSize',
        'direction': 'out',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetChannelName': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'index',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'bufferSize',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'channelName',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'ivi-dance',
          'value': 'bufferSize'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'GetChannelNameFromString': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'index',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'bufferSize',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'channelName',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'ivi-dance',
          'value': 'bufferSize'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'GetError': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'code',
        'direction': 'out',
        'type': 'ViStatus'
      },
      {
        'name': 'bufferSize',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'description',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'ivi-dance',
          'value': 'bufferSize'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'GetExtCalLastDateAndTime': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'year',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'month',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'day',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'hour',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'minute',
        'direction': 'out',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetExtCalLastTemp': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'temperature',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetExtCalRecommendedInterval': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'months',
        'direction': 'out',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetNextCoercionRecord': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'bufferSize',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'coercionRecord',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'ivi-dance',
          'value': 'bufferSize'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'GetNextInterchangeWarning': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'bufferSize',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'interchangeWarning',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'ivi-dance',
          'value': 'bufferSize'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'GetSelfCalLastDateAndTime': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'year',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'month',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'day',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'hour',
        'direction': 'out',
        'type': 'ViInt32'
      },
      {
        'name': 'minute',
        'direction': 'out',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'GetSelfCalLastTemp': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'temperature',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'ImportAttributeConfigurationFile': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'filePath',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'InitExtCal': {
    'init_method' : True,
    'parameters': [
      {
        'name': 'resourceName',
        'direction': 'in',
        'type': 'ViRsrc'
      },
      {
        'name': 'password',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'vi',
        'direction': 'out',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'InitializeWithChannels': {
    'init_method' : True,
    'parameters': [
      {
        'name': 'resourceName',
        'direction': 'in',
        'type': 'ViRsrc'
      },
      {
        'name': 'channels',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'reset',
        'direction': 'in',
        'type': 'ViBoolean'
      },
      {
        'name': 'optionString',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'vi',
        'direction': 'out',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'Initiate': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'LockSession': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'callerHasLock',
        'direction': 'out',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'Measure': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'measurementType',
        'direction': 'in',
        'type': 'ViInt32',
        'enum': 'MeasurementTypes'
      },
      {
        'name': 'measurement',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'MeasureMultiple': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'voltageMeasurements',
        'direction': 'out',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'source-code'
        }
      },
      {
        'name': 'currentMeasurements',
        'direction': 'out',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'source-code'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'QueryInCompliance': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'inCompliance',
        'direction': 'out',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'QueryMaxCurrentLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'voltageLevel',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'maxCurrentLimit',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'QueryMaxVoltageLevel': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'currentLimit',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'maxVoltageLevel',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'QueryMinCurrentLimit': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'voltageLevel',
        'direction': 'in',
        'type': 'ViReal64'
      },
      {
        'name': 'minCurrentLimit',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'QueryOutputState': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'outputState',
        'direction': 'in',
        'type': 'ViInt32',
        'enum': 'OutputStates'
      },
      {
        'name': 'inState',
        'direction': 'out',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'ReadCurrentTemperature': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'temperature',
        'direction': 'out',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'Reset': {
    'cname' : 'niDCPower_reset',
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ResetDevice': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ResetInterchangeCheck': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'ResetWithDefaults': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'RevisionQuery': {
    'cname' : 'niDCPower_revision_query',
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'instrumentDriverRevision',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'fixed',
          'value': '256'
        }
      },
      {
        'name': 'firmwareRevision',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'fixed',
          'value': '256'
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'SelfTest': {
    'cname' : 'niDCPower_self_test',
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'selfTestResult',
        'direction': 'out',
        'type': 'ViInt16'
      },
      {
        'name': 'selfTestMessage',
        'direction': 'out',
        'type': 'ViChar[]',
        'size': {
          'mechanism': 'fixed',
          'value': 256
        }
      }
    ],
    'returns': 'ViStatus'
  },
  'SendSoftwareEdgeTrigger': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'trigger',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetAttributeViBoolean': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'in',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetAttributeViInt32': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'in',
        'type': 'ViInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetAttributeViInt64': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'in',
        'type': 'ViInt64'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetAttributeViReal64': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetAttributeViSession': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'in',
        'type': 'ViSession'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetAttributeViString': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'attributeId',
        'direction': 'in',
        'type': 'ViAttr'
      },
      {
        'name': 'attributeValue',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetCalUserDefinedInfo': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'info',
        'direction': 'in',
        'type': 'ViConstString'
      }
    ],
    'returns': 'ViStatus'
  },
  'SetSequence': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'channelName',
        'direction': 'in',
        'type': 'ViConstString'
      },
      {
        'name': 'values',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'size'
        }
      },
      {
        'name': 'sourceDelays',
        'direction': 'in',
        'type': 'ViReal64[]',
        'size': {
          'mechanism': 'len',
          'value': 'size'
        }
      },
      {
        'name': 'size',
        'direction': 'in',
        'type': 'ViUInt32'
      }
    ],
    'returns': 'ViStatus'
  },
  'UnlockSession': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'callerHasLock',
        'direction': 'out',
        'type': 'ViBoolean'
      }
    ],
    'returns': 'ViStatus'
  },
  'WaitForEvent': {
    'parameters': [
      {
        'name': 'vi',
        'direction': 'in',
        'type': 'ViSession'
      },
      {
        'name': 'eventId',
        'direction': 'in',
        'type': 'ViInt32'
      },
      {
        'name': 'timeout',
        'direction': 'in',
        'type': 'ViReal64'
      }
    ],
    'returns': 'ViStatus'
  }
}
