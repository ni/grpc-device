enums = {
    'Boolean': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DigitalEdgeTriggerEdge': {
        'values': [
            {
                'name': 'RISING_EDGE',
                'value': 0
            },
            {
                'name': 'FALLING_EDGE',
                'value': 1
            }
        ]
    },
    'DsssModAccAcquisitionLengthMode': {
        'values': [
            {
                'name': 'DSSSMODACC_ACQUISITION_LENGTH_MODE_MANUAL',
                'value': 0
            },
            {
                'name': 'DSSSMODACC_ACQUISITION_LENGTH_MODE_AUTO',
                'value': 1
            }
        ]
    },
    'DsssModAccAveragingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccBurstStartDetectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccChipClockErrorCorrectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccDataDecodingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccDataModulationFormat': {
        'values': [
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_DSSS1_MBPS',
                'value': 0
            },
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_DSSS2_MBPS',
                'value': 1
            },
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_CCK5_5_MBPS',
                'value': 2
            },
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_CCK11_MBPS',
                'value': 3
            },
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_PBCC5_5_MBPS',
                'value': 4
            },
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_PBCC11_MBPS',
                'value': 5
            },
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_PBCC22_MBPS',
                'value': 6
            },
            {
                'name': 'DSSSMODACC_DATA_MODULATION_FORMAT_PBCC33_MBPS',
                'value': 7
            }
        ]
    },
    'DsssModAccEqualizationEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccEvmUnit': {
        'values': [
            {
                'name': 'DSSSMODACC_EVM_UNIT_PERCENTAGE',
                'value': 0
            },
            {
                'name': 'DSSSMODACC_EVM_UNIT_DB',
                'value': 1
            }
        ]
    },
    'DsssModAccFrequencyErrorCorrectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccIQOriginOffsetCorrectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccPayloadHeaderCrcStatus': {
        'values': [
            {
                'name': 'DSSSMODACC_HEADER_CRC_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'DSSSMODACC_HEADER_CRC_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'DsssModAccPowerMeasurementEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DsssModAccPreambleType': {
        'values': [
            {
                'name': 'DSSSMODACC_PREAMBLE_TYPE_LONG',
                'value': 0
            },
            {
                'name': 'DSSSMODACC_PREAMBLE_TYPE_SHORT',
                'value': 1
            }
        ]
    },
    'DsssModAccPsduCrcStaus': {
        'values': [
            {
                'name': 'DSSSMODACC_PSDU_CRC_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'DSSSMODACC_PSDU_CRC_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'DsssModAccPulseShapingFilterType': {
        'values': [
            {
                'name': 'DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_RECTANGULAR',
                'value': 0
            },
            {
                'name': 'DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_RAISED_COSINE',
                'value': 1
            },
            {
                'name': 'DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_ROOT_RAISED_COSINE',
                'value': 2
            },
            {
                'name': 'DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_GAUSSIAN',
                'value': 3
            }
        ]
    },
    'DsssModAccSpectrumInverted': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'FrequencyReferenceSource': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'name': 'REF_IN',
                'value': 'RefIn'
            },
            {
                'name': 'PXI_CLK',
                'value': 'PXI_Clk'
            },
            {
                'name': 'CLK_IN',
                'value': 'ClkIn'
            }
        ]
    },
    'IQPowerEdgeTriggerLevelType': {
        'values': [
            {
                'name': 'RELATIVE',
                'value': 0
            },
            {
                'name': 'ABSOLUTE',
                'value': 1
            }
        ]
    },
    'IQPowerEdgeTriggerSlope': {
        'values': [
            {
                'name': 'RISING_SLOPE',
                'value': 0
            },
            {
                'name': 'FALLING_SLOPE',
                'value': 1
            }
        ]
    },
    'LimitedConfigurationChange': {
        'values': [
            {
                'name': 'DISABLED',
                'value': 0
            },
            {
                'name': 'NO_CHANGE',
                'value': 1
            },
            {
                'name': 'FREQUENCY',
                'value': 2
            },
            {
                'name': 'REFERENCE_LEVEL',
                'value': 3
            },
            {
                'name': 'FREQUENCY_AND_REFERENCE_LEVEL',
                'value': 4
            },
            {
                'name': 'SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL',
                'value': 5
            }
        ]
    },
    'MeasurementTypes': {
        'values': [
            {
                'name': 'TXP',
                'value': 1
            },
            {
                'name': 'POWERRAMP',
                'value': 2
            },
            {
                'name': 'DSSSMODACC',
                'value': 4
            },
            {
                'name': 'OFDMMODACC',
                'value': 8
            },
            {
                'name': 'SEM',
                'value': 16
            }
        ]
    },
    'MechanicalAttenuationAuto': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmAutoPhaseRotationDetectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmAutoPpduTypeDetectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmDcmEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmEhtSigCompressionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmFecCodingType': {
        'values': [
            {
                'name': 'BCC',
                'value': 0
            },
            {
                'name': 'LDPC',
                'value': 1
            }
        ]
    },
    'OfdmFrequencyBand': {
        'values': [
            {
                'name': '2_4_GHZ',
                'value': 0
            },
            {
                'name': '5_GHZ',
                'value': 1
            }
        ]
    },
    'OfdmGuardIntervalType': {
        'values': [
            {
                'name': '1_4',
                'value': 0
            },
            {
                'name': '1_8',
                'value': 1
            },
            {
                'name': '1_16',
                'value': 2
            }
        ]
    },
    'OfdmHeaderDecodingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmLtfSize': {
        'values': [
            {
                'name': 'NOT_APPLICABLE',
                'value': -1
            },
            {
                'name': '4_X',
                'value': 0
            },
            {
                'name': '2_X',
                'value': 1
            },
            {
                'name': '1_X',
                'value': 2
            }
        ]
    },
    'OfdmMUMimoLtfModeEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccAcquisitionLengthMode': {
        'values': [
            {
                'name': 'OFDMMODACC_ACQUISITION_LENGTH_MODE_MANUAL',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_ACQUISITION_LENGTH_MODE_AUTO',
                'value': 1
            }
        ]
    },
    'OfdmModAccAmplitudeTrackingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccAutoLevelAllowOverflow': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccAveragingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccAveragingType': {
        'values': [
            {
                'name': 'OFDMMODACC_AVERAGING_TYPE_RMS',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_AVERAGING_TYPE_VECTOR',
                'value': 5
            }
        ]
    },
    'OfdmModAccBurstStartDetectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccCalibrationDataValid': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccChannelEstimationLLtfEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccChannelEstimationSmoothingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccChannelEstimationType': {
        'values': [
            {
                'name': 'OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE_AND_DATA',
                'value': 1
            }
        ]
    },
    'OfdmModAccChannelMatrixPowerEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccCommonClockSourceEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccDataDecodingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccDcmEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccEhtSigCrcStatus': {
        'values': [
            {
                'name': 'OFDMMODACC_EHT_SIG_CRC_STATUS_NOT_APPLICABLE',
                'value': -1
            },
            {
                'name': 'OFDMMODACC_EHT_SIG_CRC_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_EHT_SIG_CRC_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'OfdmModAccEvmReferenceDataSymbolsMode': {
        'values': [
            {
                'name': 'OFDMMODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE_ACQUIRED_WAVEFORM',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE_REFERENCE_WAVEFORM',
                'value': 1
            }
        ]
    },
    'OfdmModAccEvmUnit': {
        'values': [
            {
                'name': 'OFDMMODACC_EVM_UNIT_PERCENTAGE',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_EVM_UNIT_DB',
                'value': 1
            }
        ]
    },
    'OfdmModAccFecCodingType': {
        'values': [
            {
                'name': 'OFDMMODACC_FEC_CODING_TYPE_BCC',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_FEC_CODING_TYPE_LDPC',
                'value': 1
            }
        ]
    },
    'OfdmModAccFrequencyErrorEstimationMethod': {
        'values': [
            {
                'name': 'OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_DISABLED',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_INITIAL_PREAMBLE',
                'value': 1
            },
            {
                'name': 'OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE',
                'value': 2
            },
            {
                'name': 'OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS',
                'value': 3
            },
            {
                'name': 'OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_PILOTS_AND_DATA',
                'value': 4
            }
        ]
    },
    'OfdmModAccIQGainImbalanceCorrectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccIQImpairmentsEstimationEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccIQImpairmentsModel': {
        'values': [
            {
                'name': 'OFDMMODACC_IQ_IMPAIRMENTS_MODEL_TX',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_IQ_IMPAIRMENTS_MODEL_RX',
                'value': 1
            }
        ]
    },
    'OfdmModAccIQImpairmentsPerSubcarrierEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccIQQuadratureErrorCorrectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccIQTimingSkewCorrectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccLSigParityCheckStatus': {
        'values': [
            {
                'name': 'OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_NOT_APPLICABLE',
                'value': -1
            },
            {
                'name': 'OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'OfdmModAccMeasurementMode': {
        'values': [
            {
                'name': 'OFDMMODACC_MEASUREMENT_MODE_MEASURE',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR',
                'value': 1
            }
        ]
    },
    'OfdmModAccNoiseCompensationApplied': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccNoiseCompensationEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccNoiseCompensationInputPowerCheckEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccOptimizeDynamicRangeForEvmEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccPhaseTrackingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccPowerMeasurementEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccPsduCrcStatus': {
        'values': [
            {
                'name': 'OFDMMODACC_PSDU_CRC_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_PSDU_CRC_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'OfdmModAccSigBCrcStatus': {
        'values': [
            {
                'name': 'OFDMMODACC_SIG_B_CRC_STATUS_NOT_APPLICABLE',
                'value': -1
            },
            {
                'name': 'OFDMMODACC_SIG_B_CRC_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_SIG_B_CRC_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'OfdmModAccSigCrcStatus': {
        'values': [
            {
                'name': 'OFDMMODACC_SIG_CRC_STATUS_NOT_APPLICABLE',
                'value': -1
            },
            {
                'name': 'OFDMMODACC_SIG_CRC_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_SIG_CRC_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'OfdmModAccSpectrumInverted': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccSymbolClockErrorCorrectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccUSigCrcStatus': {
        'values': [
            {
                'name': 'OFDMMODACC_U_SIG_CRC_STATUS_NOT_APPLICABLE',
                'value': -1
            },
            {
                'name': 'OFDMMODACC_U_SIG_CRC_STATUS_FAIL',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_U_SIG_CRC_STATUS_PASS',
                'value': 1
            }
        ]
    },
    'OfdmModAccUnusedToneErrorMaskReference': {
        'values': [
            {
                'name': 'OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE_LIMIT1',
                'value': 0
            },
            {
                'name': 'OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE_LIMIT2',
                'value': 1
            }
        ]
    },
    'OfdmModAccVectorAveragingPhaseAlignmentEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmModAccVectorAveragingTimeAlignmentEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmPhaseRotationCoefficient1': {
        'values': [
            {
                'name': 'PLUS_ONE',
                'value': 0
            },
            {
                'name': 'MINUS_ONE',
                'value': 1
            }
        ]
    },
    'OfdmPhaseRotationCoefficient2': {
        'values': [
            {
                'name': 'PLUS_ONE',
                'value': 0
            },
            {
                'name': 'MINUS_ONE',
                'value': 1
            }
        ]
    },
    'OfdmPhaseRotationCoefficient3': {
        'values': [
            {
                'name': 'PLUS_ONE',
                'value': 0
            },
            {
                'name': 'MINUS_ONE',
                'value': 1
            }
        ]
    },
    'OfdmPpduType': {
        'values': [
            {
                'name': 'NON_HT',
                'value': 0
            },
            {
                'name': 'MIXED',
                'value': 1
            },
            {
                'name': 'GREENFIELD',
                'value': 2
            },
            {
                'name': 'SU',
                'value': 3
            },
            {
                'name': 'MU',
                'value': 4
            },
            {
                'name': 'EXTENDED_RANGE_SU',
                'value': 5
            },
            {
                'name': 'TRIGGER_BASED',
                'value': 6
            }
        ]
    },
    'OfdmPreamblePuncturingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmStbcEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'OfdmTransmitPowerClass': {
        'values': [
            {
                'name': 'A',
                'value': 0
            },
            {
                'name': 'B',
                'value': 1
            },
            {
                'name': 'C',
                'value': 2
            },
            {
                'name': 'D',
                'value': 3
            }
        ]
    },
    'PowerRampAveragingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'RFAttenuationAuto': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemAmplitudeCorrectionType': {
        'values': [
            {
                'name': 'RF_CENTER_FREQUENCY',
                'value': 0
            },
            {
                'name': 'SPECTRUM_FREQUENCY_BIN',
                'value': 1
            }
        ]
    },
    'SemAveragingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemAveragingType': {
        'values': [
            {
                'name': 'RMS',
                'value': 0
            },
            {
                'name': 'LOG',
                'value': 1
            },
            {
                'name': 'SCALAR',
                'value': 2
            },
            {
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'SemLowerOffsetMeasurementStatus': {
        'values': [
            {
                'name': 'FAIL',
                'value': 0
            },
            {
                'name': 'PASS',
                'value': 1
            }
        ]
    },
    'SemMaskType': {
        'values': [
            {
                'name': 'STANDARD',
                'value': 0
            },
            {
                'name': 'CUSTOM',
                'value': 1
            }
        ]
    },
    'SemMeasurementStatus': {
        'values': [
            {
                'name': 'FAIL',
                'value': 0
            },
            {
                'name': 'PASS',
                'value': 1
            }
        ]
    },
    'SemOffsetSideband': {
        'values': [
            {
                'name': 'NEGATIVE',
                'value': 0
            },
            {
                'name': 'POSITIVE',
                'value': 1
            },
            {
                'name': 'BOTH',
                'value': 2
            }
        ]
    },
    'SemSpanAuto': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemSweepTimeAuto': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemUpperOffsetMeasurementStatus': {
        'values': [
            {
                'name': 'FAIL',
                'value': 0
            },
            {
                'name': 'PASS',
                'value': 1
            }
        ]
    },
    'Standard': {
        'values': [
            {
                'name': '802_11_AG',
                'value': 0
            },
            {
                'name': '802_11_B',
                'value': 1
            },
            {
                'name': '802_11_J',
                'value': 2
            },
            {
                'name': '802_11_P',
                'value': 3
            },
            {
                'name': '802_11_N',
                'value': 4
            },
            {
                'name': '802_11_AC',
                'value': 5
            },
            {
                'name': '802_11_AX',
                'value': 6
            },
            {
                'name': '802_11_BE',
                'value': 7
            },
            {
                'name': 'UNKNOWN',
                'value': -1
            }
        ]
    },
    'TriggerGateEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'TriggerMinimumQuietTimeMode': {
        'values': [
            {
                'name': 'MANUAL',
                'value': 0
            },
            {
                'name': 'AUTO',
                'value': 1
            }
        ]
    },
    'TriggerType': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'DIGITAL_EDGE',
                'value': 1
            },
            {
                'name': 'IQ_POWER_EDGE',
                'value': 2
            },
            {
                'name': 'SOFTWARE',
                'value': 3
            }
        ]
    },
    'TxpAveragingEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'TxpBurstDetectionEnabled': {
        'values': [
            {
                'name': 'FALSE',
                'value': 0
            },
            {
                'name': 'TRUE',
                'value': 1
            }
        ]
    }
}
