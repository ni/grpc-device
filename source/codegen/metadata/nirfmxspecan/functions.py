functions = {
    'ACPCfgAveraging': {
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
                'enum': 'AcpAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AcpAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgCarrierAndOffsets': {
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
                'name': 'integrationBandwidth',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'numberOfOffsets',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'channelSpacing',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgCarrierFrequency': {
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
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgCarrierIntegrationBandwidth': {
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
                'name': 'integrationBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgCarrierMode': {
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
                'enum': 'AcpCarrierMode',
                'name': 'carrierMode',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgCarrierRRCFilter': {
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
                'enum': 'AcpCarrierRrcFilterEnabled',
                'name': 'rrcFilterEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgDetector': {
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
                'enum': 'AcpDetectorType',
                'name': 'detectorType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'detectorPoints',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgFFT': {
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
                'enum': 'AcpFftWindow',
                'name': 'fftWindow',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'fftPadding',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgMeasurementMethod': {
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
                'enum': 'AcpMeasurementMethod',
                'name': 'measurementMethod',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgNoiseCompensationEnabled': {
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
                'enum': 'AcpNoiseCompensationEnabled',
                'name': 'noiseCompensationEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgNumberOfCarriers': {
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
                'name': 'numberOfCarriers',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgNumberOfOffsets': {
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
                'name': 'numberOfOffsets',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffset': {
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
                'name': 'offsetFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AcpOffsetSideband',
                'name': 'offsetSideband',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AcpOffsetEnabled',
                'name': 'offsetEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetArray': {
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
                'name': 'offsetFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'enum': 'AcpOffsetSideband',
                'name': 'offsetSideband',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'enum': 'AcpOffsetEnabled',
                'name': 'offsetEnabled',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetFrequencyDefinition': {
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
                'enum': 'AcpOffsetFrequencyDefinition',
                'name': 'offsetFrequencyDefinition',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetIntegrationBandwidth': {
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
                'name': 'integrationBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetIntegrationBandwidthArray': {
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
                'name': 'integrationBandwidth',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetPowerReference': {
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
                'enum': 'AcpOffsetPowerReferenceCarrier',
                'name': 'offsetReferenceCarrier',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'offsetReferenceSpecific',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetPowerReferenceArray': {
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
                'enum': 'AcpOffsetPowerReferenceCarrier',
                'name': 'offsetPowerReferenceCarrier',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'offsetPowerReferenceSpecific',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetRRCFilter': {
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
                'enum': 'AcpOffsetRrcFilterEnabled',
                'name': 'rrcFilterEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetRRCFilterArray': {
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
                'enum': 'AcpOffsetRrcFilterEnabled',
                'name': 'rrcFilterEnabled',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetRelativeAttenuation': {
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
                'name': 'relativeAttenuation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgOffsetRelativeAttenuationArray': {
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
                'name': 'relativeAttenuation',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgPowerUnits': {
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
                'enum': 'AcpPowerUnits',
                'name': 'powerUnits',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgRBWFilter': {
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
                'enum': 'AcpRbwAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AcpRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ACPCfgSweepTime': {
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
                'enum': 'AcpSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPFetchAbsolutePowersTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'traceIndex',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'absolutePowersTrace',
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
    'ACPFetchCarrierMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'absolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'carrierOffset',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'integrationBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPFetchFrequencyResolution': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequencyResolution',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPFetchOffsetMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'lowerRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'upperRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'lowerAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'upperAbsolutePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPFetchOffsetMeasurementArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'lowerRelativePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'upperRelativePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'lowerAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'upperAbsolutePower',
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
    'ACPFetchRelativePowersTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'traceIndex',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'relativePowersTrace',
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
    'ACPFetchSpectrum': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spectrum',
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
    'ACPFetchTotalCarrierPower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalCarrierPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'carrierAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'offsetCh0LowerRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'offsetCh0UpperRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'offsetCh1LowerRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'offsetCh1UpperRelativePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'ACPValidateNoiseCalibrationData': {
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
                'enum': 'AcpNoiseCalibrationDataValid',
                'name': 'noiseCalibrationDataValid',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgAMToAMCurveFit': {
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
                'name': 'amToAMCurveFitOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmAMToAMCurveFitType',
                'name': 'amToAMCurveFitType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgAMToPMCurveFit': {
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
                'name': 'amToPMCurveFitOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmAMToPMCurveFitType',
                'name': 'amToPMCurveFitType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgAveraging': {
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
                'enum': 'AmpmAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgCompressionPoints': {
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
                'enum': 'AmpmCompressionPointEnabled',
                'name': 'compressionPointEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'compressionLevel',
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
    'AMPMCfgDUTAverageInputPower': {
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
                'name': 'dutAverageInputPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgMeasurementInterval': {
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
                'name': 'measurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgMeasurementSampleRate': {
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
                'enum': 'AmpmMeasurementSampleRateMode',
                'name': 'sampleRateMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampleRate',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgReferencePowerType': {
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
                'enum': 'AmpmReferencePowerType',
                'name': 'referencePowerType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgReferenceWaveform': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgReferenceWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_AMPMCfgReferenceWaveform',
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(referenceWaveform)',
                'direction': 'in',
                'name': 'referenceWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgReferenceWaveformSplit': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveformI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveformQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'AmpmSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgSynchronizationMethod': {
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
                'enum': 'AmpmSynchronizationMethod',
                'name': 'synchronizationMethod',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMCfgThreshold': {
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
                'enum': 'AmpmThresholdEnabled',
                'name': 'thresholdEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'thresholdLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'AmpmThresholdType',
                'name': 'thresholdType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'AMPMFetchAMToAMTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'referencePowers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'measuredAMToAM',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'curveFitAMToAM',
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
    'AMPMFetchAMToPMTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'referencePowers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'measuredAMToPM',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'curveFitAMToPM',
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
    'AMPMFetchCompressionPoints': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'inputCompressionPoint',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'outputCompressionPoint',
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
    'AMPMFetchCurveFitCoefficients': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'amToAMCoefficients',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'amToPMCoefficients',
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
    'AMPMFetchCurveFitResidual': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'amToAMResidual',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'amToPMResidual',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'AMPMFetchDUTCharacteristics': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanLinearGain',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'grpc_name': 'one_db_compression_point',
                'name': 'onedBCompressionPoint',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'grpc_name': 'mean_rms_evm',
                'name': 'meanRMSEVM',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'AMPMFetchError': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'gainErrorRange',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'phaseErrorRange',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanPhaseError',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'AMPMFetchProcessedMeanAcquiredWaveform': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'AMPMFetchProcessedMeanAcquiredWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_AMPMFetchProcessedMeanAcquiredWaveform',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(processedMeanAcquiredWaveform)',
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveform',
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
    'AMPMFetchProcessedMeanAcquiredWaveformSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveformQ',
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
    'AMPMFetchProcessedReferenceWaveform': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'AMPMFetchProcessedReferenceWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_AMPMFetchProcessedReferenceWaveform',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(processedReferenceWaveform)',
                'direction': 'out',
                'name': 'processedReferenceWaveform',
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
    'AMPMFetchProcessedReferenceWaveformSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveformQ',
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
    'AMPMFetchRelativePhaseTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'relativePhase',
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
    'AMPMFetchRelativePowerTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'relativePower',
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
    'AbortMeasurements': {
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
    },
    'AnalyzeIQ1Waveform': {
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
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'iq',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reset',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0',
                'include_in_proto': False,
                'name': 'reserved',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'AnalyzeIQ1WaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_AnalyzeIQ1Waveform',
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
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(IQ)',
                'direction': 'in',
                'name': 'iq',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reset',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0',
                'include_in_proto': False,
                'name': 'reserved',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'AnalyzeIQ1WaveformSplit': {
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
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'iqi',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'iqq',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reset',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0',
                'include_in_proto': False,
                'name': 'reserved',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'AnalyzeSpectrum1Waveform': {
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
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'spectrum',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reset',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'hardcoded_value': '0',
                'include_in_proto': False,
                'name': 'reserved',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'AutoLevel': {
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
                'name': 'bandwidth',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'measurementInterval',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'referenceLevel',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'BuildCarrierString': {
        'cname': 'RFmxSpecAn_BuildCarrierString2',
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'carrierNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildHarmonicString': {
        'cname': 'RFmxSpecAn_BuildHarmonicString2',
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'harmonicNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildIntermodString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'intermodNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildListStepString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'listName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'stepNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildListString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'listName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'selectorStringLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildMarkerString': {
        'cname': 'RFmxSpecAn_BuildMarkerString2',
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'markerNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildOffsetString': {
        'cname': 'RFmxSpecAn_BuildOffsetString2',
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'offsetNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildRangeSpurString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'signalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'rangeNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'spurNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildRangeString': {
        'cname': 'RFmxSpecAn_BuildRangeString2',
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'rangeNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildSegmentString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'segmentNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildSignalString': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'signalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'selectorStringLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorString',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'BuildSpurString': {
        'cname': 'RFmxSpecAn_BuildSpurString2',
        'parameters': [
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'spurNumber',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorStringOutLength',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'selectorStringOut',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'selectorStringOutLength'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'CCDFCfgMeasurementInterval': {
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
                'name': 'measurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CCDFCfgNumberOfRecords': {
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
                'name': 'numberOfRecords',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CCDFCfgRBWFilter': {
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
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'CcdfRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CCDFCfgThreshold': {
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
                'enum': 'CcdfThresholdEnabled',
                'name': 'thresholdEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'thresholdLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'CcdfThresholdType',
                'name': 'thresholdType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CCDFFetchBasicPowerProbabilities': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'tenPercentPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'onePercentPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'oneTenthPercentPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'oneHundredthPercentPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'oneThousandthPercentPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'oneTenThousandthPercentPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CCDFFetchGaussianProbabilitiesTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'gaussianProbabilities',
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
    'CCDFFetchPower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanPowerPercentile',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'measuredSamplesCount',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CCDFFetchProbabilitiesTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'probabilities',
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
    'CCDFRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanPowerPercentile',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'measuredSamplesCount',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgAveraging': {
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
                'enum': 'ChpAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ChpAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgCarrierOffset': {
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
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgDetector': {
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
                'enum': 'ChpDetectorType',
                'name': 'detectorType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'detectorPoints',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgFFT': {
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
                'enum': 'ChpFftWindow',
                'name': 'fftWindow',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'fftPadding',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgIntegrationBandwidth': {
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
                'name': 'integrationBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgNumberOfCarriers': {
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
                'name': 'numberOfCarriers',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgRBWFilter': {
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
                'enum': 'ChpRbwAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ChpRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgRRCFilter': {
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
                'enum': 'ChpCarrierRrcFilterEnabled',
                'name': 'rrcFilterEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgSpan': {
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
                'name': 'span',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPCfgSweepTime': {
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
                'enum': 'ChpSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPFetchCarrierMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'absolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'psd',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'relativePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPFetchSpectrum': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spectrum',
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
    'CHPFetchTotalCarrierPower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalCarrierPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'absolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'psd',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CHPValidateNoiseCalibrationData': {
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
                'enum': 'ChpNoiseCalibrationDataValid',
                'name': 'noiseCalibrationDataValid',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgDigitalEdgeTrigger': {
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
                'enum': 'DigitalEdgeTriggerSource',
                'name': 'digitalEdgeSource',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'DigitalEdgeTriggerEdge',
                'name': 'digitalEdge',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'triggerDelay',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'enableTrigger',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgExternalAttenuation': {
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
                'name': 'externalAttenuation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgFrequency': {
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
                'name': 'centerFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgFrequencyReference': {
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
                'enum': 'FrequencyReferenceSource',
                'name': 'frequencyReferenceSource',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'frequencyReferenceFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgIQPowerEdgeTrigger': {
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
                'name': 'iqPowerEdgeSource',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'iqPowerEdgeLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'IQPowerEdgeTriggerSlope',
                'name': 'iqPowerEdgeSlope',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'triggerDelay',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TriggerMinimumQuietTimeMode',
                'name': 'triggerMinQuietTimeMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'triggerMinQuietTimeDuration',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'enableTrigger',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CfgMechanicalAttenuation': {
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
                'enum': 'MechanicalAttenuationAuto',
                'name': 'mechanicalAttenuationAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'mechanicalAttenuationValue',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgRF': {
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
                'name': 'centerFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'externalAttenuation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgRFAttenuation': {
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
                'enum': 'RFAttenuationAuto',
                'name': 'rfAttenuationAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rfAttenuationValue',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgReferenceLevel': {
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
                'name': 'referenceLevel',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'CfgSoftwareEdgeTrigger': {
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
                'name': 'triggerDelay',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'enableTrigger',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CheckMeasurementStatus': {
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
                'grpc_type': 'bool',
                'name': 'isDone',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ClearAllNamedResults': {
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
    },
    'ClearNamedResult': {
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
    },
    'ClearNoiseCalibrationDatabase': {
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
    },
    'CloneSignalConfiguration': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'oldSignalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'newSignalName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'Close': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'forceDestroy',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'Commit': {
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
    },
    'CreateList': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'listName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'CreateListStep': {
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
                'name': 'createdStepIndex',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'CreateSignalConfiguration': {
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
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyDigitalPredistortion': {
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
                'name': 'x0In',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dxIn',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'waveformIn',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySizeIn'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeIn',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdApplyDpdIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'measurementTimeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'waveformOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerOffset',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyDigitalPredistortionInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDApplyDigitalPredistortion',
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
                'name': 'x0In',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dxIn',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(waveformIn)',
                'direction': 'in',
                'name': 'waveformIn',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySizeIn'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeIn',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdApplyDpdIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'measurementTimeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(waveformOut)',
                'direction': 'out',
                'name': 'waveformOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerOffset',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyDigitalPredistortionSplit': {
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
                'name': 'x0In',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dxIn',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'waveformInI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySizeIn'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'waveformInQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySizeIn'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeIn',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdApplyDpdIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'measurementTimeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'waveformOutI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'waveformOutQ',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerOffset',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyPreDPDSignalConditioning': {
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
                'name': 'x0In',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dxIn',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'waveformIn',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySizeIn'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeIn',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdApplyDpdIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'waveformOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyPreDPDSignalConditioningInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDApplyPreDPDSignalConditioning',
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
                'name': 'x0In',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dxIn',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(waveformIn)',
                'direction': 'in',
                'name': 'waveformIn',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySizeIn'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeIn',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdApplyDpdIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(waveformOut)',
                'direction': 'out',
                'name': 'waveformOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDApplyPreDPDSignalConditioningSplit': {
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
                'name': 'x0In',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dxIn',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'waveformInI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySizeIn'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'waveformInQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySizeIn'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeIn',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdApplyDpdIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0Out',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dxOut',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'waveformOutI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'waveformOutQ',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySizeOut',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySizeOut',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDConfigurationInput': {
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
                'enum': 'DpdApplyDpdConfigurationInput',
                'name': 'configurationInput',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDLookupTableCorrectionType': {
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
                'enum': 'DpdApplyDpdLookupTableCorrectionType',
                'name': 'lutCorrectionType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDMemoryModelCorrectionType': {
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
                'enum': 'DpdApplyDpdMemoryModelCorrectionType',
                'name': 'memoryModelCorrectionType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDUserDPDPolynomial': {
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
                'name': 'dpdPolynomial',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDUserDPDPolynomialInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDCfgApplyDPDUserDPDPolynomial',
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
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(DPDPolynomial)',
                'direction': 'in',
                'name': 'dpdPolynomial',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDUserDPDPolynomialSplit': {
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
                'name': 'dpdPolynomialI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'dpdPolynomialQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDUserLookupTable': {
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
                'name': 'lutInputPowers',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'lutComplexGains',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDUserLookupTableInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDCfgApplyDPDUserLookupTable',
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
                'name': 'lutInputPowers',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(LUTComplexGains)',
                'direction': 'in',
                'name': 'lutComplexGains',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgApplyDPDUserLookupTableSplit': {
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
                'name': 'lutInputPowers',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'lutComplexGainsI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'lutComplexGainsQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgAveraging': {
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
                'enum': 'DpdAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgDPDModel': {
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
                'enum': 'DpdModel',
                'name': 'dpdModel',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgDUTAverageInputPower': {
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
                'name': 'dutAverageInputPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgExtractModelTargetWaveform': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'targetWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgExtractModelTargetWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDCfgExtractModelTargetWaveform',
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(targetWaveform)',
                'direction': 'in',
                'name': 'targetWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgExtractModelTargetWaveformSplit': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'targetWaveformI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'targetWaveformQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgGeneralizedMemoryPolynomialCrossTerms': {
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
                'name': 'memoryPolynomialLeadOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'memoryPolynomialLagOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'memoryPolynomialLeadMemoryDepth',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'memoryPolynomialLagMemoryDepth',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'memoryPolynomialMaximumLead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'memoryPolynomialMaximumLag',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgIterativeDPDEnabled': {
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
                'enum': 'DpdIterativeDpdEnabled',
                'name': 'iterativeDPDEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgLookupTableAMToAMCurveFit': {
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
                'name': 'amToAMCurveFitOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdLookupTableAMToAMCurveFitType',
                'name': 'amToAMCurveFitType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgLookupTableAMToPMCurveFit': {
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
                'name': 'amToPMCurveFitOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdLookupTableAMToPMCurveFitType',
                'name': 'amToPMCurveFitType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgLookupTableStepSize': {
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
                'name': 'stepSize',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgLookupTableThreshold': {
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
                'enum': 'DpdLookupTableThresholdEnabled',
                'name': 'thresholdEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'thresholdLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'DpdLookupTableThresholdType',
                'name': 'thresholdType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgLookupTableType': {
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
                'enum': 'DpdLookupTableType',
                'name': 'lookupTableType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgMeasurementInterval': {
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
                'name': 'measurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgMeasurementSampleRate': {
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
                'enum': 'DpdMeasurementSampleRateMode',
                'name': 'sampleRateMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sampleRate',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgMemoryPolynomial': {
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
                'name': 'memoryPolynomialOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'memoryPolynomialMemoryDepth',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgPreviousDPDPolynomial': {
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
                'name': 'previousDPDPolynomial',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgPreviousDPDPolynomialInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDCfgPreviousDPDPolynomial',
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
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(previousDPDPolynomial)',
                'direction': 'in',
                'name': 'previousDPDPolynomial',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgPreviousDPDPolynomialSplit': {
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
                'name': 'previousDPDPolynomialI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'previousDPDPolynomialQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgReferenceWaveform': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgReferenceWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDCfgReferenceWaveform',
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(referenceWaveform)',
                'direction': 'in',
                'name': 'referenceWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgReferenceWaveformSplit': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveformI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveformQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'DpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDCfgSynchronizationMethod': {
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
                'enum': 'DpdSynchronizationMethod',
                'name': 'synchronizationMethod',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'DPDFetchApplyDPDPreCFRPAPR': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'grpc_name': 'pre_cfr_papr',
                'name': 'preCFRPAPR',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDFetchAverageGain': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageGain',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDFetchDPDPolynomial': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dpdPolynomial',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'DPDFetchDPDPolynomialInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDFetchDPDPolynomial',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(DPDPolynomial)',
                'direction': 'out',
                'name': 'dpdPolynomial',
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
    'DPDFetchDPDPolynomialSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dpdPolynomialI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'dpdPolynomialQ',
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
    'DPDFetchDVRModel': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dvrModel',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'DPDFetchDVRModelInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDFetchDVRModel',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(DVRModel)',
                'direction': 'out',
                'name': 'dvrModel',
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
    'DPDFetchDVRModelSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dvrModelI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'dvrModelQ',
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
    'DPDFetchLookupTable': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'inputPowers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'complexGains',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'DPDFetchLookupTableInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDFetchLookupTable',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'inputPowers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(complexGains)',
                'direction': 'out',
                'name': 'complexGains',
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
    'DPDFetchLookupTableSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'inputPowers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'complexGainsI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'complexGainsQ',
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
    'DPDFetchNMSE': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'nmse',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'DPDFetchProcessedMeanAcquiredWaveform': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'DPDFetchProcessedMeanAcquiredWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDFetchProcessedMeanAcquiredWaveform',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(processedMeanAcquiredWaveform)',
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveform',
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
    'DPDFetchProcessedMeanAcquiredWaveformSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveformQ',
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
    'DPDFetchProcessedReferenceWaveform': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'DPDFetchProcessedReferenceWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_DPDFetchProcessedReferenceWaveform',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(processedReferenceWaveform)',
                'direction': 'out',
                'name': 'processedReferenceWaveform',
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
    'DPDFetchProcessedReferenceWaveformSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveformQ',
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
    'DeleteList': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'listName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'DeleteSignalConfiguration': {
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
            }
        ],
        'returns': 'int32'
    },
    'DisableTrigger': {
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
    },
    'FCntCfgAveraging': {
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
                'enum': 'FcntAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'FcntAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'FCntCfgMeasurementInterval': {
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
                'name': 'measurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'FCntCfgRBWFilter': {
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
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'FcntRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'FCntCfgThreshold': {
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
                'enum': 'FcntThresholdEnabled',
                'name': 'thresholdEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'thresholdLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'FcntThresholdType',
                'name': 'thresholdType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'FCntFetchAllanDeviation': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'allanDeviation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'FCntFetchFrequencyTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequencyTrace',
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
    'FCntFetchMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageRelativeFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageAbsoluteFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanPhase',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'FCntFetchPhaseTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'phaseTrace',
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
    'FCntFetchPowerTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerTrace',
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
    'FCntRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageRelativeFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageAbsoluteFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanPhase',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'GetAllNamedResultNames': {
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
                'name': 'resultNames',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'resultNamesBufferSize',
                    'value_twist': 'actualResultNamesSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultNamesBufferSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualResultNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'defaultResultExists',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeF32': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
    'GetAttributeF32Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
    'GetAttributeF64': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
    'GetAttributeF64Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
    'GetAttributeI16': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int16'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeI32': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
    'GetAttributeI32Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'int32[]'
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
    'GetAttributeI64': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
    'GetAttributeI64Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'int64[]'
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
    'GetAttributeI8': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int8'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeI8Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'int8[]'
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
    'GetAttributeNIComplexDoubleArray': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'NIComplexDouble[]'
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
    'GetAttributeNIComplexSingleArray': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'NIComplexSingle[]'
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
    'GetAttributeString': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
    'GetAttributeU16': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'uInt16'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeU32': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeU32Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'uInt32[]'
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
    'GetAttributeU64Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'uInt64[]'
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
    'GetAttributeU8': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'uInt8'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeU8Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
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
                'type': 'uInt8[]'
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
    'GetError': {
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
    'HarmCfgAutoHarmonics': {
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
                'enum': 'HarmAutoHarmonicsSetupEnabled',
                'name': 'autoHarmonicsSetupEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'HarmCfgAveraging': {
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
                'enum': 'HarmAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'HarmAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'HarmCfgFundamentalMeasurementInterval': {
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
                'name': 'measurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'HarmCfgFundamentalRBW': {
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
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'HarmRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'HarmCfgHarmonic': {
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
                'name': 'harmonicOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'harmonicBandwidth',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'HarmHarmonicEnabled',
                'name': 'harmonicEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'harmonicMeasurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'HarmCfgHarmonicArray': {
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
                'name': 'harmonicOrder',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'harmonicBandwidth',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'enum': 'HarmHarmonicEnabled',
                'name': 'harmonicEnabled',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'harmonicMeasurementInterval',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'HarmCfgNumberOfHarmonics': {
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
                'name': 'numberOfHarmonics',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'HarmFetchHarmonicMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'HarmFetchHarmonicMeasurementArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageRelativePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'averageAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'rbw',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'frequency',
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
    'HarmFetchHarmonicPowerTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'power',
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
    'HarmFetchTHD': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalHarmonicDistortion',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageFundamentalPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'fundamentalFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'HarmRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalHarmonicDistortion',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageFundamentalPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgEqualizerCoefficients': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'equalizerCoefficients',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgEqualizerCoefficientsInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDCfgEqualizerCoefficients',
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(equalizerCoefficients)',
                'direction': 'in',
                'name': 'equalizerCoefficients',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgEqualizerCoefficientsSplit': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'equalizerCoefficientsI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'equalizerCoefficientsQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgPredistortedWaveform': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'predistortedWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'targetGain',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgPredistortedWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDCfgPredistortedWaveform',
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(predistortedWaveform)',
                'direction': 'in',
                'name': 'predistortedWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'targetGain',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgPredistortedWaveformSplit': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'predistortedWaveformI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'predistortedWaveformQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'targetGain',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgReferenceWaveform': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgReferenceWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDCfgReferenceWaveform',
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(referenceWaveform)',
                'direction': 'in',
                'name': 'referenceWaveform',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'casted_name': 'arraySize/2',
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IDPDCfgReferenceWaveformSplit': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveformI',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'referenceWaveformQ',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdReferenceWaveformIdleDurationPresent',
                'name': 'idleDurationPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IdpdSignalType',
                'name': 'signalType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IDPDFetchEqualizerCoefficients': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'equalizerCoefficients',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'IDPDFetchEqualizerCoefficientsInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDFetchEqualizerCoefficients',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(equalizerCoefficients)',
                'direction': 'out',
                'name': 'equalizerCoefficients',
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
    'IDPDFetchEqualizerCoefficientsSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'equalizerCoefficientsI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'equalizerCoefficientsQ',
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
    'IDPDFetchPredistortedWaveform': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'predistortedWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerOffset',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'gain',
                'type': 'float64'
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
    'IDPDFetchPredistortedWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDFetchPredistortedWaveform',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(predistortedWaveform)',
                'direction': 'out',
                'name': 'predistortedWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerOffset',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'gain',
                'type': 'float64'
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
    'IDPDFetchPredistortedWaveformSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'predistortedWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'predistortedWaveformQ',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'powerOffset',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'gain',
                'type': 'float64'
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
    'IDPDFetchProcessedMeanAcquiredWaveform': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'IDPDFetchProcessedMeanAcquiredWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDFetchProcessedMeanAcquiredWaveform',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(processedMeanAcquiredWaveform)',
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveform',
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
    'IDPDFetchProcessedMeanAcquiredWaveformSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'processedMeanAcquiredWaveformQ',
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
    'IDPDFetchProcessedReferenceWaveform': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'IDPDFetchProcessedReferenceWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDFetchProcessedReferenceWaveform',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(processedReferenceWaveform)',
                'direction': 'out',
                'name': 'processedReferenceWaveform',
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
    'IDPDFetchProcessedReferenceWaveformSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'processedReferenceWaveformQ',
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
    'IDPDGetEqualizerReferenceWaveform': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'equalizerReferenceWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
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
    'IDPDGetEqualizerReferenceWaveformInterleavedIQ': {
        'cname': 'RFmxSpecAn_IDPDGetEqualizerReferenceWaveform',
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(equalizerReferenceWaveform)',
                'direction': 'out',
                'name': 'equalizerReferenceWaveform',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
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
    'IDPDGetEqualizerReferenceWaveformSplit': {
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
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'equalizerReferenceWaveformI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'equalizerReferenceWaveformQ',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'papr',
                'type': 'float64'
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
    'IMCfgAutoIntermodsSetup': {
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
                'enum': 'IMAutoIntermodsSetupEnabled',
                'name': 'autoIntermodsSetupEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'maximumIntermodOrder',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgAveraging': {
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
                'enum': 'IMAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IMAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgFFT': {
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
                'enum': 'IMFftWindow',
                'name': 'fftWindow',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'fftPadding',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgFrequencyDefinition': {
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
                'enum': 'IMFrequencyDefinition',
                'name': 'frequencyDefinition',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgFundamentalTones': {
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
                'name': 'lowerToneFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'upperToneFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgIntermod': {
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
                'name': 'intermodOrder',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'lowerIntermodFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'upperIntermodFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'IMIntermodSide',
                'name': 'intermodSide',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'IMIntermodEnabled',
                'name': 'intermodEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgIntermodArray': {
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
                'name': 'intermodOrder',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'lowerIntermodFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'upperIntermodFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'enum': 'IMIntermodSide',
                'name': 'intermodSide',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'enum': 'IMIntermodEnabled',
                'name': 'intermodEnabled',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgMeasurementMethod': {
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
                'enum': 'IMMeasurementMethod',
                'name': 'measurementMethod',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgNumberOfIntermods': {
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
                'name': 'numberOfIntermods',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgRBWFilter': {
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
                'enum': 'IMRbwFilterAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'IMRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'IMCfgSweepTime': {
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
                'enum': 'IMSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IMFetchFundamentalMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'lowerTonePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'upperTonePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IMFetchInterceptPower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'intermodOrder',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'worstCaseOutputInterceptPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'lowerOutputInterceptPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'upperOutputInterceptPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IMFetchInterceptPowerArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'intermodOrder',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'out',
                'name': 'worstCaseOutputInterceptPower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'lowerOutputInterceptPower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'upperOutputInterceptPower',
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
    'IMFetchIntermodMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'intermodOrder',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'lowerIntermodPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'upperIntermodPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IMFetchIntermodMeasurementArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'intermodOrder',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'out',
                'name': 'lowerIntermodPower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'upperIntermodPower',
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
    'IMFetchSpectrum': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'spectrumIndex',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spectrum',
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
    'IQCfgAcquisition': {
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
                'name': 'sampleRate',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'numberOfRecords',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'acquisitionTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'pretriggerTime',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IQCfgBandwidth': {
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
                'enum': 'IQBandwidthAuto',
                'name': 'bandwidthAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'bandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'IQFetchData': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'recordToFetch',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'samplesToRead',
                'type': 'int64'
            },
            {
                'direction': 'out',
                'name': 't0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dt',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'data',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'NIComplexSingle[]'
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
    'IQFetchDataInterleavedIQ': {
        'cname': 'RFmxSpecAn_IQFetchData',
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'recordToFetch',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'samplesToRead',
                'type': 'int64'
            },
            {
                'direction': 'out',
                'name': 't0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dt',
                'type': 'float64'
            },
            {
                'casted_name': 'reinterpret_cast<NIComplexSingle*>(data)',
                'direction': 'out',
                'name': 'data',
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
    'IQFetchDataSplit': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'recordToFetch',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'samplesToRead',
                'type': 'int64'
            },
            {
                'direction': 'out',
                'name': 't0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dt',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dataI',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'dataQ',
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
    'IQGetRecordsDone': {
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
                'name': 'recordsDone',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'Initialize': {
        'custom_close': 'Close(id, RFMXSPECAN_VAL_FALSE)',
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'optionString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'grpc_name': 'instrument',
                'name': 'handleOut',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'name': 'isNewSession',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'get_last_error': 'deprecated',
                'name': 'errorMessage',
                'type': 'char[]'
            },
            {
                'cppName': 'initializationBehavior',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.SessionInitializationBehavior',
                'name': 'initializationBehavior',
                'proto_only': True,
                'type': 'int32'
            },
            {
                'cppName': 'newSessionInitialized',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'newSessionInitialized',
                'proto_only': True,
                'type': 'bool'
            }
        ],
        'returns': 'int32'
    },
    'InitializeFromNIRFSASession': {
        'custom_close': 'Close(id, RFMXSPECAN_VAL_FALSE)',
        'init_method': True,
        'parameters': [
            {
                'cross_driver_session': 'ViSession',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.Session',
                'name': 'nirfsaSession',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'grpc_name': 'instrument',
                'name': 'handleOut',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'get_last_error': 'deprecated',
                'name': 'errorMessage',
                'type': 'char[]'
            },
            {
                'cppName': 'initializationBehavior',
                'direction': 'in',
                'grpc_type': 'nidevice_grpc.SessionInitializationBehavior',
                'name': 'initializationBehavior',
                'proto_only': True,
                'type': 'int32'
            },
            {
                'cppName': 'newSessionInitialized',
                'direction': 'out',
                'grpc_type': 'bool',
                'name': 'newSessionInitialized',
                'proto_only': True,
                'type': 'bool'
            }
        ],
        'returns': 'int32'
    },
    'Initiate': {
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
                'name': 'resultName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgBandSpan': {
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
                'name': 'span',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgFunctionType': {
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
                'enum': 'MarkerFunctionType',
                'name': 'functionType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgNumberOfMarkers': {
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
                'name': 'numberOfMarkers',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgPeakExcursion': {
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
                'enum': 'MarkerPeakExcursionEnabled',
                'name': 'peakExcursionEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'peakExcursion',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgReferenceMarker': {
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
                'name': 'referenceMarker',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgThreshold': {
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
                'enum': 'MarkerThresholdEnabled',
                'name': 'thresholdEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'threshold',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgTrace': {
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
                'enum': 'MarkerTrace',
                'name': 'trace',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgType': {
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
                'enum': 'MarkerType',
                'name': 'markerType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgXLocation': {
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
                'name': 'markerXLocation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'MarkerCfgYLocation': {
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
                'name': 'markerYLocation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'MarkerFetchFunctionValue': {
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
                'name': 'functionValue',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'MarkerFetchXY': {
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
                'name': 'markerXLocation',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'markerYLocation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'MarkerNextPeak': {
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
                'enum': 'MarkerNextPeak',
                'name': 'nextPeak',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'nextPeakFound',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'MarkerPeakSearch': {
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
                'name': 'numberOfPeaks',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgAveraging': {
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
                'enum': 'NFAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgCalibrationLoss': {
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
                'enum': 'NFCalibrationLossCompensationEnabled',
                'name': 'calibrationLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'calibrationLossFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'calibrationLoss',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'calibrationLossTemperature',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgColdSourceDUTSParameters': {
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
                'grpc_name': 'dut_s_parameters_frequency',
                'name': 'dutsParametersFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'grpc_name': 'dut_s21',
                'name': 'duts21',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'grpc_name': 'dut_s12',
                'name': 'duts12',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'grpc_name': 'dut_s11',
                'name': 'duts11',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'grpc_name': 'dut_s22',
                'name': 'duts22',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
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
    'NFCfgColdSourceInputTermination': {
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
                'name': 'terminationVSWR',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'terminationVSWRFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'terminationTemperature',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgColdSourceMode': {
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
                'enum': 'NFColdSourceMode',
                'name': 'coldSourceMode',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgDUTInputLoss': {
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
                'enum': 'NFDutInputLossCompensationEnabled',
                'name': 'dutInputLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'dutInputLossFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'dutInputLoss',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'dutInputLossTemperature',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgDUTOutputLoss': {
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
                'enum': 'NFDutOutputLossCompensationEnabled',
                'name': 'dutOutputLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'dutOutputLossFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'dutOutputLoss',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'dutOutputLossTemperature',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgFrequencyList': {
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
                'name': 'frequencyList',
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
    'NFCfgFrequencyListStartStopPoints': {
        'cname': 'RFmxSpecAn_NFCfgFrequencyList_StartStopPoints',
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
                'name': 'startFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'stopFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'numberOfPoints',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgFrequencyListStartStopStep': {
        'cname': 'RFmxSpecAn_NFCfgFrequencyList_StartStopStep',
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
                'name': 'startFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'stopFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'stepSize',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgMeasurementBandwidth': {
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
                'name': 'measurementBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgMeasurementInterval': {
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
                'name': 'measurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgMeasurementMethod': {
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
                'enum': 'NFMeasurementMethod',
                'name': 'measurementMethod',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgYFactorMode': {
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
                'enum': 'NFYFactorMode',
                'name': 'yFactorMode',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgYFactorNoiseSourceENR': {
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
                'name': 'enrFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'enr',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'coldTemperature',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'offTemperature',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgYFactorNoiseSourceLoss': {
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
                'enum': 'NFYFactorNoiseSourceLossCompensationEnabled',
                'name': 'noiseSourceLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'noiseSourceLossFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'noiseSourceLoss',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'noiseSourceLossTemperature',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFCfgYFactorNoiseSourceSettlingTime': {
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
                'name': 'settlingTime',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFClearCalibrationDatabase': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'calibrationSetupID',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'NFFetchAnalyzerNoiseFigure': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'analyzerNoiseFigure',
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
    'NFFetchColdSourcePower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'coldSourcePower',
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
    'NFFetchDUTNoiseFigureAndGain': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dutNoiseFigure',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'dutNoiseTemperature',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'dutGain',
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
    'NFFetchYFactorPowers': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'hotPower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'coldPower',
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
    'NFFetchYFactors': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'measurementYFactor',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'calibrationYFactor',
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
    'NFLoadCalibrationLossFromS2p': {
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
                'enum': 'NFCalibrationLossCompensationEnabled',
                'name': 'calibrationLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'calibrationLossS2pFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'NFCalibrationLossS2pSParameterOrientation',
                'name': 'calibrationLossSParameterOrientation',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'calibrationLossTemperature',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFLoadColdSourceDUTSParametersFromS2p': {
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
                'grpc_name': 'dut_s_parameters_s2p_file_path',
                'name': 'dutsParametersS2pFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'NFColdSourceDutS2pSParameterOrientation',
                'grpc_name': 'dut_s_parameter_orientation',
                'name': 'dutsParameterOrientation',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFLoadColdSourceInputTerminationFromS1p': {
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
                'name': 'terminationS1pFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'terminationTemperature',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFLoadDUTInputLossFromS2p': {
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
                'enum': 'NFDutInputLossCompensationEnabled',
                'name': 'dutInputLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'dutInputLossS2pFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'NFDutInputLossS2pSParameterOrientation',
                'name': 'dutInputLossSParameterOrientation',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'dutInputLossTemperature',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFLoadDUTOutputLossFromS2p': {
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
                'enum': 'NFDutOutputLossCompensationEnabled',
                'name': 'dutOutputLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'dutOutputLossS2pFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'NFDutOutputLossS2pSParameterOrientation',
                'name': 'dutOutputLossSParameterOrientation',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'dutOutputLossTemperature',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFLoadExternalPreampGainFromS2p': {
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
                'enum': 'NFExternalPreampPresent',
                'name': 'externalPreampPresent',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'externalPreampGainS2pFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'NFExternalPreampGainS2pSParameterOrientation',
                'name': 'externalPreampGainSParameterOrientation',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'NFLoadYFactorNoiseSourceLossFromS2p': {
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
                'enum': 'NFYFactorNoiseSourceLossCompensationEnabled',
                'name': 'noiseSourceLossCompensationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'noiseSourceLossS2pFilePath',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'enum': 'NFYFactorNoiseSourceLossS2pSParameterOrientation',
                'name': 'noiseSourceLossSParameterOrientation',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'noiseSourceLossTemperature',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFRecommendReferenceLevel': {
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
                'name': 'dutMaxGain',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'dutMaxNoiseFigure',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'referenceLevel',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'NFValidateCalibrationData': {
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
                'enum': 'NFCalibrationDataValid',
                'name': 'calibrationDataValid',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'OBWCfgAveraging': {
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
                'enum': 'ObwAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'ObwAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'OBWCfgBandwidthPercentage': {
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
                'name': 'bandwidthPercentage',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'OBWCfgFFT': {
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
                'enum': 'ObwFftWindow',
                'name': 'fftWindow',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'fftPadding',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'OBWCfgPowerUnits': {
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
                'enum': 'ObwPowerUnits',
                'name': 'powerUnits',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'OBWCfgRBWFilter': {
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
                'enum': 'ObwRbwAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'ObwRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'OBWCfgSpan': {
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
                'name': 'span',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'OBWCfgSweepTime': {
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
                'enum': 'ObwSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'OBWFetchMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'occupiedBandwidth',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averagePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequencyResolution',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'startFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'stopFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'OBWFetchSpectrumTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spectrum',
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
    'OBWRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'occupiedBandwidth',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averagePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequencyResolution',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'startFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'stopFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgMeasurementBandwidth': {
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
                'name': 'measurementBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgMeasurementInterval': {
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
                'name': 'measurementOffset',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'measurementLength',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgMeasurementIntervalMode': {
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
                'enum': 'PavtMeasurementIntervalMode',
                'name': 'measurementIntervalMode',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgMeasurementLocationType': {
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
                'enum': 'PavtMeasurementLocationType',
                'name': 'measurementLocationType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgNumberOfSegments': {
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
                'name': 'numberOfSegments',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgSegmentMeasurementInterval': {
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
                'name': 'segmentMeasurementOffset',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'segmentMeasurementLength',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgSegmentMeasurementIntervalArray': {
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
                'name': 'segmentMeasurementOffset',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'segmentMeasurementLength',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgSegmentStartTimeList': {
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
                'name': 'segmentStartTime',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgSegmentStartTimeStep': {
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
                'name': 'numberOfSegments',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'segment0StartTime',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'segmentInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgSegmentType': {
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
                'enum': 'PavtSegmentType',
                'name': 'segmentType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PAVTCfgSegmentTypeArray': {
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
                'enum': 'PavtSegmentType',
                'name': 'segmentType',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PAVTFetchAmplitudeTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'traceIndex',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'amplitude',
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
    'PAVTFetchPhaseAndAmplitude': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanRelativePhase',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanRelativeAmplitude',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanAbsolutePhase',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanAbsoluteAmplitude',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PAVTFetchPhaseAndAmplitudeArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanRelativePhase',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'meanRelativeAmplitude',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'meanAbsolutePhase',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'meanAbsoluteAmplitude',
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
    'PAVTFetchPhaseTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'traceIndex',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'phase',
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
    'PhaseNoiseCfgAutoRange': {
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
                'name': 'startFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'stopFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'rbwPercentage',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseCfgAveragingMultiplier': {
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
                'name': 'averagingMultiplier',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseCfgCancellation': {
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
                'enum': 'PhaseNoiseCancellationEnabled',
                'name': 'cancellationEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'cancellationThreshold',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'frequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'referencePhaseNoise',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseCfgIntegratedNoise': {
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
                'enum': 'PhaseNoiseIntegratedNoiseRangeDefinition',
                'name': 'integratedNoiseRangeDefinition',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'integratedNoiseStartFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'integratedNoiseStopFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
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
    'PhaseNoiseCfgNumberOfRanges': {
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
                'name': 'numberOfRanges',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseCfgRangeArray': {
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
                'name': 'rangeStartFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'rangeStopFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'rangeRBWPercentage',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'rangeAveragingCount',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseCfgRangeDefinition': {
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
                'enum': 'PhaseNoiseRangeDefinition',
                'name': 'rangeDefinition',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseCfgSmoothing': {
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
                'enum': 'PhaseNoiseSmoothingType',
                'name': 'smoothingType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'smoothingPercentage',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseCfgSpotNoiseFrequencyList': {
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
                'name': 'frequencyList',
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
    'PhaseNoiseCfgSpurRemoval': {
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
                'enum': 'PhaseNoiseSpurRemovalEnabled',
                'name': 'spurRemovalEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'peakExcursion',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseFetchCarrierMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'carrierFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'carrierPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'PhaseNoiseFetchIntegratedNoise': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'integratedPhaseNoise',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'residualPMInRadian',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'residualPMInDegree',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'residualFM',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'jitter',
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
    'PhaseNoiseFetchMeasuredLogPlotTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'measuredPhaseNoise',
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
    'PhaseNoiseFetchSmoothedLogPlotTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'out',
                'name': 'smoothedPhaseNoise',
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
    'PhaseNoiseFetchSpotNoise': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spotPhaseNoise',
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
    'PowerListCfgRBWFilterArray': {
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
                'name': 'rbw',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'rbwFilterType',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'arraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
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
    'PowerListFetchMaximumPowerArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'maximumPower',
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
    'PowerListFetchMeanAbsolutePowerArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'meanAbsolutePower',
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
    'PowerListFetchMinimumPowerArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'minimumPower',
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
    'ResetAttribute': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'ResetToDefault': {
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
    },
    'SEMCfgAveraging': {
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
                'enum': 'SemAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'SemAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgCarrierChannelBandwidth': {
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
                'name': 'carrierChannelBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgCarrierEnabled': {
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
                'enum': 'SemCarrierEnabled',
                'name': 'carrierEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgCarrierFrequency': {
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
                'name': 'carrierFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgCarrierIntegrationBandwidth': {
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
                'name': 'integrationBandwidth',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgCarrierRBWFilter': {
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
                'enum': 'SemCarrierRbwAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'SemCarrierRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgCarrierRRCFilter': {
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
                'enum': 'SemCarrierRrcFilterEnabled',
                'name': 'rrcFilterEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgFFT': {
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
                'enum': 'SemFftWindow',
                'name': 'fftWindow',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'fftPadding',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgNumberOfCarriers': {
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
                'name': 'numberOfCarriers',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgNumberOfOffsets': {
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
                'name': 'numberOfOffsets',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetAbsoluteLimit': {
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
                'enum': 'SemOffsetAbsoluteLimitMode',
                'name': 'absoluteLimitMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStart',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStop',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetAbsoluteLimitArray': {
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
                'enum': 'SemOffsetAbsoluteLimitMode',
                'name': 'absoluteLimitMode',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStart',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStop',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetBandwidthIntegral': {
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
                'name': 'bandwidthIntegral',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetFrequency': {
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
                'name': 'offsetStartFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'offsetStopFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'SemOffsetEnabled',
                'name': 'offsetEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'SemOffsetSideband',
                'name': 'offsetSideband',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetFrequencyArray': {
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
                'name': 'offsetStartFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'offsetStopFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'enum': 'SemOffsetEnabled',
                'name': 'offsetEnabled',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'enum': 'SemOffsetSideband',
                'name': 'offsetSideband',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetFrequencyDefinition': {
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
                'enum': 'SemOffsetFrequencyDefinition',
                'name': 'offsetFrequencyDefinition',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetLimitFailMask': {
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
                'enum': 'SemOffsetLimitFailMask',
                'name': 'limitFailMask',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetRBWFilter': {
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
                'enum': 'SemOffsetRbwAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'SemOffsetRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetRBWFilterArray': {
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
                'enum': 'SemOffsetRbwAutoBandwidth',
                'name': 'rbwAuto',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'enum': 'SemOffsetRbwFilterType',
                'name': 'rbwFilterType',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetRelativeAttenuation': {
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
                'name': 'relativeAttenuation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetRelativeAttenuationArray': {
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
                'name': 'relativeAttenuation',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetRelativeLimit': {
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
                'enum': 'SemOffsetRelativeLimitMode',
                'name': 'relativeLimitMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'relativeLimitStart',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'relativeLimitStop',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgOffsetRelativeLimitArray': {
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
                'enum': 'SemOffsetRelativeLimitMode',
                'name': 'relativeLimitMode',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'relativeLimitStart',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'relativeLimitStop',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgPowerUnits': {
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
                'enum': 'SemPowerUnits',
                'name': 'powerUnits',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgReferenceType': {
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
                'enum': 'SemReferenceType',
                'name': 'referenceType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMCfgSweepTime': {
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
                'enum': 'SemSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchAbsoluteMaskTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'absoluteMask',
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
    'SEMFetchCarrierMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'absolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalRelativePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchCompositeMeasurementStatus': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SemCompositeMeasurementStatus',
                'name': 'compositeMeasurementStatus',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchFrequencyResolution': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequencyResolution',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchLowerOffsetMargin': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SemLowerOffsetMeasurementStatus',
                'name': 'measurementStatus',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'margin',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'marginFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'marginAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'marginRelativePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchLowerOffsetMarginArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SemLowerOffsetMeasurementStatus',
                'name': 'measurementStatus',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'out',
                'name': 'margin',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'marginFrequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'marginAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'marginRelativePower',
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
    'SEMFetchLowerOffsetPower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakRelativePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchLowerOffsetPowerArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'totalRelativePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'peakAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'peakFrequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'peakRelativePower',
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
    'SEMFetchRelativeMaskTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'relativeMask',
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
    'SEMFetchSpectrum': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spectrum',
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
    'SEMFetchTotalCarrierPower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalCarrierPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchUpperOffsetMargin': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SemUpperOffsetMeasurementStatus',
                'name': 'measurementStatus',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'margin',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'marginFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'marginAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'marginRelativePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchUpperOffsetMarginArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SemUpperOffsetMeasurementStatus',
                'name': 'measurementStatus',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'out',
                'name': 'margin',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'marginFrequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'marginAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'marginRelativePower',
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
    'SEMFetchUpperOffsetPower': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalRelativePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakAbsolutePower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakRelativePower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SEMFetchUpperOffsetPowerArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'totalAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'totalRelativePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'peakAbsolutePower',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'peakFrequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'peakRelativePower',
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
    'SelectMeasurements': {
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
                'enum': 'MeasurementTypes',
                'name': 'measurements',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'grpc_type': 'bool',
                'name': 'enableAllTraces',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SendSoftwareEdgeTrigger': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeF32': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'float32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeF32Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeF64': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeF64Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
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
    'SetAttributeI16': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'int16'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeI32': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeI32Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeI64': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeI64Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'int64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeI8': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'int8'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeI8Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'int8[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeNIComplexDoubleArray': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexDouble[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeNIComplexSingleArray': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'NIComplexSingle[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeString': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeU16': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'uInt16'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeU32': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'uInt32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeU32Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'uInt32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeU64Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'uInt64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeU8': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'uInt8'
            }
        ],
        'returns': 'int32'
    },
    'SetAttributeU8Array': {
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
                'grpc_type': 'NiRFmxSpecAnAttribute',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'len',
                    'value': 'arraySize'
                },
                'type': 'uInt8[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgAveraging': {
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
                'enum': 'SpectrumAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'SpectrumAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgDetector': {
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
                'enum': 'SpectrumDetectorType',
                'name': 'detectorType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'detectorPoints',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgFFT': {
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
                'enum': 'SpectrumFftWindow',
                'name': 'fftWindow',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'fftPadding',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgFrequencyStartStop': {
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
                'name': 'startFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'stopFrequency',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgMeasurementMethod': {
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
                'enum': 'SpectrumMeasurementMethod',
                'name': 'measurementMethod',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgNoiseCompensationEnabled': {
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
                'enum': 'SpectrumNoiseCompensationEnabled',
                'name': 'noiseCompensationEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgPowerUnits': {
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
                'enum': 'SpectrumPowerUnits',
                'name': 'spectrumPowerUnits',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgRBWFilter': {
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
                'enum': 'SpectrumRbwAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'SpectrumRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgSpan': {
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
                'name': 'span',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgSweepTime': {
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
                'enum': 'SpectrumSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumCfgVBWFilter': {
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
                'enum': 'SpectrumVbwFilterAutoBandwidth',
                'name': 'vbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'vbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'vbwToRBWRatio',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumFetchMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakAmplitude',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'frequencyResolution',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpectrumFetchPowerTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'power',
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
    'SpectrumFetchSpectrum': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spectrum',
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
    'SpectrumRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spectrum',
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
    'SpectrumValidateNoiseCalibrationData': {
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
                'enum': 'SpectrumNoiseCalibrationDataValid',
                'name': 'noiseCalibrationDataValid',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgAveraging': {
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
                'enum': 'SpurAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'SpurAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgFFTWindowType': {
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
                'enum': 'SpurFftWindow',
                'name': 'fftWindow',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgNumberOfRanges': {
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
                'name': 'numberOfRanges',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeAbsoluteLimit': {
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
                'enum': 'SpurAbsoluteLimitMode',
                'name': 'absoluteLimitMode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStart',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStop',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeAbsoluteLimitArray': {
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
                'enum': 'SpurAbsoluteLimitMode',
                'name': 'absoluteLimitMode',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStart',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'absoluteLimitStop',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeDetector': {
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
                'enum': 'SpurRangeDetectorType',
                'name': 'detectorType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'detectorPoints',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeDetectorArray': {
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
                'enum': 'SpurRangeDetectorType',
                'name': 'detectorType',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'detectorPoints',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeFrequency': {
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
                'name': 'startFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'stopFrequency',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'SpurRangeEnabled',
                'name': 'rangeEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeFrequencyArray': {
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
                'name': 'startFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'stopFrequency',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'enum': 'SpurRangeEnabled',
                'name': 'rangeEnabled',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeNumberOfSpursToReport': {
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
                'name': 'numberOfSpursToReport',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeNumberOfSpursToReportArray': {
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
                'name': 'numberOfSpursToReport',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangePeakCriteria': {
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
                'name': 'threshold',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'excursion',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangePeakCriteriaArray': {
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
                'name': 'threshold',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'excursion',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeRBWArray': {
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
                'enum': 'SpurRbwAutoBandwidth',
                'name': 'rbwAuto',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'enum': 'SpurRbwFilterType',
                'name': 'rbwFilterType',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeRBWFilter': {
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
                'enum': 'SpurRbwAutoBandwidth',
                'name': 'rbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'SpurRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeRelativeAttenuation': {
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
                'name': 'relativeAttenuation',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeRelativeAttenuationArray': {
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
                'name': 'relativeAttenuation',
                'size': {
                    'mechanism': 'len',
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeSweepTime': {
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
                'enum': 'SpurSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeSweepTimeArray': {
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
                'enum': 'SpurSweepTimeAuto',
                'name': 'sweepTimeAuto',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'sweepTimeInterval',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeVBWFilter': {
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
                'enum': 'SpurRangeVbwFilterAutoBandwidth',
                'name': 'vbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'vbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'vbwToRBWRatio',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgRangeVBWFilterArray': {
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
                'enum': 'SpurRangeVbwFilterAutoBandwidth',
                'name': 'vbwAuto',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'vbw',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'vbwToRBWRatio',
                'size': {
                    'mechanism': 'len',
                    'tags': [
                        'optional'
                    ],
                    'value': 'numberOfElements'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'numberOfElements',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurCfgTraceRangeIndex': {
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
                'name': 'traceRangeIndex',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurFetchAllSpurs': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spurFrequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'spurAmplitude',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'spurMargin',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'spurAbsoluteLimit',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'spurRangeIndex',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'int32[]'
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
    'SpurFetchMeasurementStatus': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SpurMeasurementStatus',
                'name': 'measurementStatus',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurFetchRangeAbsoluteLimitTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'absoluteLimit',
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
    'SpurFetchRangeSpectrumTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'rangeSpectrum',
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
    'SpurFetchRangeStatus': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SpurRangeStatus',
                'name': 'rangeStatus',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'detectedSpurs',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SpurFetchRangeStatusArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'enum': 'SpurRangeStatus',
                'name': 'rangeStatus',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'out',
                'name': 'numberOfDetectedSpurs',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'int32[]'
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
    'SpurFetchSpurMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spurFrequency',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spurAmplitude',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spurMargin',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spurAbsoluteLimit',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'SpurFetchSpurMeasurementArray': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'spurFrequency',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'spurAmplitude',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'spurAbsoluteLimit',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'out',
                'name': 'spurMargin',
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
    'TXPCfgAveraging': {
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
                'enum': 'TxpAveragingEnabled',
                'name': 'averagingEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'averagingCount',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'enum': 'TxpAveragingType',
                'name': 'averagingType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'TXPCfgMeasurementInterval': {
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
                'name': 'measurementInterval',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'TXPCfgRBWFilter': {
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
                'name': 'rbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TxpRbwFilterType',
                'name': 'rbwFilterType',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'rrcAlpha',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'TXPCfgThreshold': {
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
                'enum': 'TxpThresholdEnabled',
                'name': 'thresholdEnabled',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'thresholdLevel',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'enum': 'TxpThresholdType',
                'name': 'thresholdType',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'TXPCfgVBWFilter': {
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
                'enum': 'TxpVbwFilterAutoBandwidth',
                'name': 'vbwAuto',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'vbw',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'vbwToRBWRatio',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'TXPFetchMeasurement': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageMeanPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakToAverageRatio',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'maximumPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'minimumPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'TXPFetchPowerTrace': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'x0',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'dx',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'power',
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
    'TXPRead': {
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
                'name': 'timeout',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'averageMeanPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'peakToAverageRatio',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'maximumPower',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'minimumPower',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'WaitForAcquisitionComplete': {
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'WaitForMeasurementComplete': {
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
                'name': 'timeout',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    }
}
