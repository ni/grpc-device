enums = {
    'DigitalEdgeTriggerEdge': {
        'values': [
            {
                'name': 'RISING',
                'value': 0
            },
            {
                'name': 'FALLING',
                'value': 1
            }
        ]
    },
    'DigitalEdgeTriggerSource': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            }
        ]
    },
    'DsssModAccAcquisitionLengthMode': {
        'enum-value-prefix': 'DSSSMODACC_ACQUISITION_LENGTH_MODE',
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
    'DsssModAccAveragingEnabled': {
        'enum-value-prefix': 'DSSSMODACC_AVERAGING_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_BURST_START_DETECTION_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_DATA_DECODING_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_DATA_MODULATION_FORMAT',
        'values': [
            {
                'name': 'DSSS1MBPS',
                'value': 0
            },
            {
                'name': 'DSSS2MBPS',
                'value': 1
            },
            {
                'name': 'CCK5_5MBPS',
                'value': 2
            },
            {
                'name': 'CCK11MBPS',
                'value': 3
            },
            {
                'name': 'PBCC5_5MBPS',
                'value': 4
            },
            {
                'name': 'PBCC11MBPS',
                'value': 5
            },
            {
                'name': 'PBCC22MBPS',
                'value': 6
            },
            {
                'name': 'PBCC33MBPS',
                'value': 7
            }
        ]
    },
    'DsssModAccEqualizationEnabled': {
        'enum-value-prefix': 'DSSSMODACC_EQUALIZATION_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_EVM_UNIT',
        'values': [
            {
                'name': 'PERCENTAGE',
                'value': 0
            },
            {
                'name': 'DB',
                'value': 1
            }
        ]
    },
    'DsssModAccFrequencyErrorCorrectionEnabled': {
        'enum-value-prefix': 'DSSSMODACC_FREQUENCY_ERROR_CORRECTION_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_PAYLOAD_HEADER_CRC_STATUS',
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
    'DsssModAccPowerMeasurementEnabled': {
        'enum-value-prefix': 'DSSSMODACC_POWER_MEASUREMENT_ENABLED',
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
        'enum-value-prefix': 'DSSSMODACC_PREAMBLE_TYPE',
        'values': [
            {
                'name': 'LONG',
                'value': 0
            },
            {
                'name': 'SHORT',
                'value': 1
            }
        ]
    },
    'DsssModAccPsduCrcStatus': {
        'enum-value-prefix': 'DSSSMODACC_PSDU_CRC_STATUS',
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
    'DsssModAccPulseShapingFilterType': {
        'enum-value-prefix': 'DSSSMODACC_PULSE_SHAPING_FILTER_TYPE',
        'values': [
            {
                'name': 'RECTANGULAR',
                'value': 0
            },
            {
                'name': 'RAISED_COSINE',
                'value': 1
            },
            {
                'name': 'ROOT_RAISED_COSINE',
                'value': 2
            },
            {
                'name': 'GAUSSIAN',
                'value': 3
            }
        ]
    },
    'DsssModAccSpectrumInverted': {
        'enum-value-prefix': 'DSSSMODACC_SPECTRUM_INVERTED',
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
                'name': 'RISING',
                'value': 0
            },
            {
                'name': 'FALLING',
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
                'name': '2_4GHZ',
                'value': 0
            },
            {
                'name': '5GHZ',
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
                'name': '4X',
                'value': 0
            },
            {
                'name': '2X',
                'value': 1
            },
            {
                'name': '1X',
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
        'enum-value-prefix': 'OFDMMODACC_ACQUISITION_LENGTH_MODE',
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
    'OfdmModAccAmplitudeTrackingEnabled': {
        'enum-value-prefix': 'OFDMMODACC_AMPLITUDE_TRACKING_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_AUTO_LEVEL_ALLOW_OVERFLOW',
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
        'enum-value-prefix': 'OFDMMODACC_AVERAGING_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_AVERAGING_TYPE',
        'values': [
            {
                'name': 'RMS',
                'value': 0
            },
            {
                'name': 'VECTOR',
                'value': 5
            }
        ]
    },
    'OfdmModAccBurstStartDetectionEnabled': {
        'enum-value-prefix': 'OFDMMODACC_BURST_START_DETECTION_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_CALIBRATION_DATA_VALID',
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
    'OfdmModAccChannelEstimationInterpolationType': {
        'enum-value-prefix': 'OFDMMODACC_CHANNEL_ESTIMATION_INTERPOLATION_TYPE',
        'values': [
            {
                'name': 'LINEAR',
                'value': 0
            },
            {
                'name': 'TRIANGULAR_SMOOTHING',
                'value': 1
            },
            {
                'name': 'WIENER_FILTER',
                'value': 2
            }
        ]
    },
    'OfdmModAccChannelEstimationLLtfEnabled': {
        'enum-value-prefix': 'OFDMMODACC_CHANNEL_ESTIMATION_L_LTF_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_CHANNEL_ESTIMATION_TYPE',
        'values': [
            {
                'name': 'REFERENCE',
                'value': 0
            },
            {
                'name': 'REFERENCE_AND_DATA',
                'value': 1
            }
        ]
    },
    'OfdmModAccChannelMatrixPowerEnabled': {
        'enum-value-prefix': 'OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_COMMON_CLOCK_SOURCE_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_DATA_DECODING_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_DCM_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_EHT_SIG_CRC_STATUS',
        'values': [
            {
                'name': 'NOT_APPLICABLE',
                'value': -1
            },
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
    'OfdmModAccEvmReferenceDataSymbolsMode': {
        'enum-value-prefix': 'OFDMMODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE',
        'values': [
            {
                'name': 'ACQUIRED_WAVEFORM',
                'value': 0
            },
            {
                'name': 'REFERENCE_WAVEFORM',
                'value': 1
            }
        ]
    },
    'OfdmModAccEvmUnit': {
        'enum-value-prefix': 'OFDMMODACC_EVM_UNIT',
        'values': [
            {
                'name': 'PERCENTAGE',
                'value': 0
            },
            {
                'name': 'DB',
                'value': 1
            }
        ]
    },
    'OfdmModAccFecCodingType': {
        'enum-value-prefix': 'OFDMMODACC_FEC_CODING_TYPE',
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
    'OfdmModAccFrequencyErrorEstimationMethod': {
        'enum-value-prefix': 'OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD',
        'values': [
            {
                'name': 'DISABLED',
                'value': 0
            },
            {
                'name': 'INITIAL_PREAMBLE',
                'value': 1
            },
            {
                'name': 'PREAMBLE',
                'value': 2
            },
            {
                'name': 'PREAMBLE_AND_PILOTS',
                'value': 3
            },
            {
                'name': 'PREAMBLE_PILOTS_AND_DATA',
                'value': 4
            }
        ]
    },
    'OfdmModAccIQGainImbalanceCorrectionEnabled': {
        'enum-value-prefix': 'OFDMMODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_IQ_IMPAIRMENTS_MODEL',
        'values': [
            {
                'name': 'TX',
                'value': 0
            },
            {
                'name': 'RX',
                'value': 1
            }
        ]
    },
    'OfdmModAccIQImpairmentsPerSubcarrierEnabled': {
        'enum-value-prefix': 'OFDMMODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_L_SIG_PARITY_CHECK_STATUS',
        'values': [
            {
                'name': 'NOT_APPLICABLE',
                'value': -1
            },
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
    'OfdmModAccMeasurementMode': {
        'enum-value-prefix': 'OFDMMODACC_MEASUREMENT_MODE',
        'values': [
            {
                'name': 'MEASURE',
                'value': 0
            },
            {
                'name': 'CALIBRATE_NOISE_FLOOR',
                'value': 1
            }
        ]
    },
    'OfdmModAccNoiseCompensationApplied': {
        'enum-value-prefix': 'OFDMMODACC_NOISE_COMPENSATION_APPLIED',
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
        'enum-value-prefix': 'OFDMMODACC_NOISE_COMPENSATION_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_OPTIMIZE_DYNAMIC_RANGE_FOR_EVM_ENABLED',
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
    'OfdmModAccPhaseRotationCoefficient1': {
        'enum-value-prefix': 'OFDMMODACC_PHASE_ROTATION_COEFFICIENT_1',
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
    'OfdmModAccPhaseRotationCoefficient2': {
        'enum-value-prefix': 'OFDMMODACC_PHASE_ROTATION_COEFFICIENT_2',
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
    'OfdmModAccPhaseRotationCoefficient3': {
        'enum-value-prefix': 'OFDMMODACC_PHASE_ROTATION_COEFFICIENT_3',
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
    'OfdmModAccPhaseTrackingEnabled': {
        'enum-value-prefix': 'OFDMMODACC_PHASE_TRACKING_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_POWER_MEASUREMENT_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_PSDU_CRC_STATUS',
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
    'OfdmModAccSigBCrcStatus': {
        'enum-value-prefix': 'OFDMMODACC_SIG_B_CRC_STATUS',
        'values': [
            {
                'name': 'NOT_APPLICABLE',
                'value': -1
            },
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
    'OfdmModAccSigCrcStatus': {
        'enum-value-prefix': 'OFDMMODACC_SIG_CRC_STATUS',
        'values': [
            {
                'name': 'NOT_APPLICABLE',
                'value': -1
            },
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
    'OfdmModAccSpectrumInverted': {
        'enum-value-prefix': 'OFDMMODACC_SPECTRUM_INVERTED',
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
        'enum-value-prefix': 'OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_U_SIG_CRC_STATUS',
        'values': [
            {
                'name': 'NOT_APPLICABLE',
                'value': -1
            },
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
    'OfdmModAccUnusedToneErrorMaskReference': {
        'enum-value-prefix': 'OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE',
        'values': [
            {
                'name': 'LIMIT1',
                'value': 0
            },
            {
                'name': 'LIMIT2',
                'value': 1
            }
        ]
    },
    'OfdmModAccVectorAveragingPhaseAlignmentEnabled': {
        'enum-value-prefix': 'OFDMMODACC_VECTOR_AVERAGING_PHASE_ALIGNMENT_ENABLED',
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
        'enum-value-prefix': 'OFDMMODACC_VECTOR_AVERAGING_TIME_ALIGNMENT_ENABLED',
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
        'enum-value-prefix': 'OFDM_PHASE_ROTATION_COEFFICIENT_1',
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
        'enum-value-prefix': 'OFDM_PHASE_ROTATION_COEFFICIENT_2',
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
        'enum-value-prefix': 'OFDM_PHASE_ROTATION_COEFFICIENT_3',
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
        'enum-value-prefix': 'POWERRAMP_AVERAGING_ENABLED',
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
