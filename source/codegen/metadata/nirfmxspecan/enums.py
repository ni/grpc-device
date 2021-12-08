enums = {
    'AcpAmplitudeCorrectionType': {
        'values': [
            {
                'documentation': {
                    'description': ' All the frequency bins in the spectrum are compensated with a single external attenuation value that corresponds to the RF center frequency.'
                },
                'name': 'RF_CENTER_FREQUENCY',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An individual frequency bin in the spectrum is compensated with the external attenuation value corresponding to that frequency.'
                },
                'name': 'SPECTRUM_FREQUENCY_BIN',
                'value': 1
            }
        ]
    },
    'AcpAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The ACP measurement uses the RFMXSPECAN_ATTR_ACP_AVERAGING_COUNT attribute as the number of acquisitions over which the ACP measurement is averaged. '
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AcpAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power spectrum is linearly averaged. RMS averaging reduces signal fluctuations but not the noise floor.  '
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power spectrum is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power spectrum is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The peak power in the spectrum at each frequency bin is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The least power in the spectrum at each frequency bin is retained from one acquisition to the next. '
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'AcpCarrierMode': {
        'values': [
            {
                'documentation': {
                    'description': ' The carrier power is not considered as part of the total carrier power.'
                },
                'name': 'PASSIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The carrier power is considered as part of the total carrier power.'
                },
                'name': 'ACTIVE',
                'value': 1
            }
        ]
    },
    'AcpCarrierRrcFilterEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The channel power of the acquired carrier channel is measured directly.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement applies the RRC filter on the acquired carrier channel before measuring the carrier channel power.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AcpFftOverlapMode': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the overlap between the chunks.'
                },
                'name': 'DISABLED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measurement sets the overlap based on the value you have set for the RFMXSPECAN_ATTR_ACP_FFT_WINDOW attribute. When you set the RFMXSPECAN_ATTR_ACP_FFT_WINDOW attribute to any value other than RFMXSPECAN_VAL_ACP_FFT_WINDOW_NONE, the number of overlapped samples between consecutive chunks is set to 50% of the value of the RFMXSPECAN_ATTR_ACP_SEQUENTIAL_FFT_SIZE attribute. When you set the RFMXSPECAN_ATTR_ACP_FFT_WINDOW attribute to RFMXSPECAN_VAL_ACP_FFT_WINDOW_NONE, the chunks are not overlapped and the overlap is set to 0%.'
                },
                'name': 'AUTOMATIC',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Measurement uses the overlap that you specify in the RFMXSPECAN_ATTR_ACP_FFT_OVERLAP attribute.'
                },
                'name': 'USER_DEFINED',
                'value': 2
            }
        ]
    },
    'AcpFftWindow': {
        'values': [
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is shorter than the window length. You can also use this window type to separate two tones with frequencies close to each other but with almost equal amplitudes.'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measures single-tone amplitudes accurately.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is longer than the window length. You can also use this window type to provide better frequency resolution for noise measurements.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Analyzes closely-spaced sine waves.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Provides a good balance of spectral leakage, frequency resolution, and amplitude attenuation. Hence, this windowing is useful for time-frequency analysis.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Analyzes single tone because it has a low maximum side lobe level and a high side lobe roll-off rate.  '
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Useful as a good general purpose window, having side lobe rejection greater than 90 dB and having a moderately wide main lobe. '
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Separates two tones with frequencies close to each other but with widely-differing amplitudes.'
                },
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'AcpIFOutputPowerOffsetAuto': {
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
    'AcpMeasurementMethod': {
        'values': [
            {
                'documentation': {
                    'description': ' The ACP measurement acquires the spectrum using the same signal analyzer setting across frequency bands. Use this method when measurement speed is desirable over higher dynamic range. '
                },
                'name': 'NORMAL',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The ACP measurement acquires the spectrum using the hardware-specific optimizations for different frequency bands. Use this method to get the best dynamic range.\n\n   Supported devices: PXIe-5665/5668'
                },
                'name': 'DYNAMIC_RANGE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The ACP measurement acquires I/Q samples for a duration specified by the RFMXSPECAN_ATTR_ACP_SWEEP_TIME_INTERVAL attribute. These samples are divided into smaller chunks. The size of each chunk is defined by the RFMXSPECAN_ATTR_ACP_SEQUENTIAL_FFT_SIZE attribute. The overlap between the chunks is defined by the RFMXSPECAN_ATTR_ACP_FFT_OVERLAP_MODE attribute. FFT is computed on each of these chunks. The resultant FFTs are averaged to get the spectrum and is used to compute ACP. If the total acquired samples is not an integer multiple of the FFT size, the remaining samples at the end of acquisition are not used for the measurement. Use this method to optimize ACP measurement speed. Accuracy of the results may be reduced when using this measurement method.'
                },
                'name': 'SEQUENTIAL_FFT',
                'value': 2
            }
        ]
    },
    'AcpMeasurementMode': {
        'values': [
            {
                'documentation': {
                    'description': ' ACP measurement is performed on the acquired signal.  '
                },
                'name': 'MEASURE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Manual noise calibration of the signal analyzer is performed for the ACP measurement.'
                },
                'name': 'CALIBRATE_NOISE_FLOOR',
                'value': 1
            }
        ]
    },
    'AcpNoiseCalibrationAveragingAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' RFmx uses the averages that you set for the RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_COUNT attribute.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' When you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_NORMAL, RFmx uses a noise calibration averaging count of 32. When you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE and the sweep time is less than 5 ms, RFmx uses a noise calibration averaging count of 15. When you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE and the sweep time is greater than or equal to 5 ms, RFmx uses a noise calibration averaging count of 5.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AcpNoiseCalibrationMode': {
        'values': [
            {
                'documentation': {
                    'description': ' When you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_MODE attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR, you can initiate instrument noise calibration for the ACP measurement manually. When you set the RFMXSPECAN_ATTR_ACP_MEASUREMENT_MODE attribute to RFMXSPECAN_VAL_ACP_MEASUREMENT_MODE_MEASURE, you can initiate the ACP measurement manually.'
                },
                'name': 'MANUAL',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' When you set the RFMXSPECAN_ATTR_ACP_NOISE_COMPENSATION_ENABLED to RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE, RFmx sets the Input Isolation Enabled attribute to Enabled and calibrates the instrument noise in the current state of the instrument. RFmx then resets the Input Isolation Enabled attribute and performs the ACP measurement, including compensation for noise of the instrument. RFmx skips noise calibration in this mode if valid noise calibration data is already cached. When you set the RFMXSPECAN_ATTR_ACP_NOISE_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE, RFmx does not calibrate instrument noise and only performs the ACP measurement without compensating for noise of the instrument.'
                },
                'name': 'AUTO',
                'value': 1
            }
        ]
    },
    'AcpNoiseCompensationEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables noise compensation.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables noise compensation.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AcpNoiseCompensationType': {
        'values': [
            {
                'documentation': {
                    'description': ' Compensates for noise from the analyzer and the 50-ohm termination. The measured power values are in excess of the thermal noise floor.'
                },
                'name': 'ANALYZER_AND_TERMINATION',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Compensates for the analyzer noise only.'
                },
                'name': 'ANALYZER_ONLY',
                'value': 1
            }
        ]
    },
    'AcpOffsetEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the offset channel for ACP measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables the offset channel for ACP measurement.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AcpOffsetFrequencyDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' The offset frequency is defined from the center of the closest carrier to the center of the offset channel.'
                },
                'name': 'CARRIER_CENTER_TO_OFFSET_CENTER',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The offset frequency is defined from the center of the closest carrier to the nearest edge of the offset channel.'
                },
                'name': 'CARRIER_CENTER_TO_OFFSET_EDGE',
                'value': 1
            }
        ]
    },
    'AcpOffsetPowerReferenceCarrier': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement uses the power measured in the carrier closest to the offset channel center frequency, as the power reference.'
                },
                'name': 'CLOSEST',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement uses the highest power measured among all the active carriers as the power reference.'
                },
                'name': 'HIGHEST',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The measurement uses the sum of powers measured in all the active carriers as the power reference.'
                },
                'name': 'COMPOSITE',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The measurement uses the power measured in the carrier that has an index specified by the RFMXSPECAN_ATTR_ACP_OFFSET_POWER_REFERENCE_SPECIFIC attribute, as the power reference.'
                },
                'name': 'SPECIFIC',
                'value': 3
            }
        ]
    },
    'AcpOffsetRrcFilterEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The channel power of the acquired offset channel is measured directly.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement applies the RRC filter on the acquired offset channel before measuring the offset channel power.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AcpOffsetSideband': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures a lower offset segment to the left of the leftmost carrier. '
                },
                'name': 'NEGATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Configures an upper offset segment to the right of the rightmost carrier.  '
                },
                'name': 'POSITIVE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Configures both negative and positive offset segments.'
                },
                'name': 'BOTH',
                'value': 2
            }
        ]
    },
    'AcpPowerUnits': {
        'values': [
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm.'
                },
                'name': 'DBM',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm/Hz.'
                },
                'name': 'DBM_PER_HZ',
                'value': 1
            }
        ]
    },
    'AcpRbwAutoBandwidth': {
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
    'AcpRbwFilterBandwidthDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 3dB bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_ACP_RBW_FILTER_TYPE attribute to RFMXSPECAN_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED, RBW is the 3dB bandwidth of the window specified by the RFMXSPECAN_ATTR_ACP_FFT_WINDOW attribute.'
                },
                'name': '3_DB',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the bin width of the spectrum computed using FFT when you set the RFMXSPECAN_ATTR_ACP_RBW_FILTER_TYPE attribute to FFT Based.'
                },
                'name': 'BIN_WIDTH',
                'value': 2
            }
        ]
    },
    'AcpRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' No RBW filtering is performed.'
                },
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An RBW filter with a Gaussian response is applied.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' An RBW filter with a flat response is applied.'
                },
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'AcpSweepTimeAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement uses the sweep time that you specify in the RFMXSPECAN_ATTR_ACP_SWEEP_TIME_INTERVAL attribute.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement calculates the sweep time based on the value of the RFMXSPECAN_ATTR_ACP_RBW_FILTER_BANDWIDTH attribute.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AmpmAMToAMCurveFitType': {
        'values': [
            {
                'name': 'LEAST_SQUARE',
                'value': 0
            },
            {
                'name': 'LEAST_ABSOLUTE_RESIDUAL',
                'value': 1
            },
            {
                'name': 'BISQUARE',
                'value': 2
            }
        ]
    },
    'AmpmAMToAMEnabled': {
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
    'AmpmAMToPMCurveFitType': {
        'values': [
            {
                'name': 'LEAST_SQUARE',
                'value': 0
            },
            {
                'name': 'LEAST_ABSOLUTE_RESIDUAL',
                'value': 1
            },
            {
                'name': 'BISQUARE',
                'value': 2
            }
        ]
    },
    'AmpmAMToPMEnabled': {
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
    'AmpmAutoCarrierDetectionEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables auto detection of carrier offset and carrier bandwidth.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables auto detection of carrier offset and carrier bandwidth.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AmpmAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The AMPM measurement uses the RFMXSPECAN_ATTR_AMPM_AVERAGING_COUNT attribute as the number of acquisitions over which the signal for the AMPM measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AmpmCompressionPointEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables computation of compression points.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables computation of compression points.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AmpmCompressionPointGainReference': {
        'values': [
            {
                'documentation': {
                    'description': ' Measurement computes the gain reference to be used for compression point calculation. The computed gain reference is also returned as RFMXSPECAN_ATTR_AMPM_RESULTS_MEAN_LINEAR_GAIN result.'
                },
                'name': 'AUTO',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measurement uses the gain corresponding to the reference power that you specify for the RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_POWER attribute as gain reference. The reference power can be configured as either input or output power based on the value of the RFMXSPECAN_ATTR_AMPM_REFERENCE_POWER_TYPE attribute.'
                },
                'name': 'REFERENCE_POWER',
                'value': 1
            }
        ]
    },
    'AmpmEqualizerMode': {
        'values': [
            {
                'documentation': {
                    'description': ' Equalization is not performed.'
                },
                'name': 'OFF',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The equalizer is turned on to compensate for the effect of the channel.'
                },
                'name': 'TRAIN',
                'value': 1
            }
        ]
    },
    'AmpmEvmEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables EVM computation. NaN is returned as Mean RMS EVM.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables EVM computation.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AmpmFrequencyOffsetCorrectionEnabled': {
        'values': [
            {
                'documentation': {
                    'description': '  The measurement does not perform frequency offset correction.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': '  The measurement computes and corrects any frequency offset between the reference and the acquired waveforms.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AmpmIQOriginOffsetCorrectionEnabled': {
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
    'AmpmMeasurementSampleRateMode': {
        'values': [
            {
                'documentation': {
                    'description': ' The acquisition sample rate is defined by the value of the RFMXSPECAN_ATTR_AMPM_MEASUREMENT_SAMPLE_RATE attribute.'
                },
                'name': 'USER',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The acquisition sample rate is set to match the sample rate of the reference waveform.'
                },
                'name': 'REFERENCE_WAVEFORM',
                'value': 1
            }
        ]
    },
    'AmpmReferencePowerType': {
        'values': [
            {
                'documentation': {
                    'description': ' The instantaneous powers at the input port of device under test (DUT) forms the x-axis of AM to AM and AM to PM traces.'
                },
                'name': 'INPUT',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The instantaneous powers at the output port of DUT forms the x-axis of AM to AM and AM to PM traces.'
                },
                'name': 'OUTPUT',
                'value': 1
            }
        ]
    },
    'AmpmSignalType': {
        'values': [
            {
                'documentation': {
                    'description': ' The reference waveform is a cellular or connectivity standard signal.'
                },
                'name': 'MODULATED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The reference waveform is a continuous signal comprising of one or more tones.'
                },
                'name': 'TONES',
                'value': 1
            }
        ]
    },
    'AmpmSynchronizationMethod': {
        'values': [
            {
                'documentation': {
                    'description': ' Synchronizes the acquired and reference waveforms assuming that sample rate is sufficient to prevent aliasing in intermediate operations. This method is recommended when the measurement sampling rate is high.'
                },
                'name': 'DIRECT',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Synchronizes the acquired and  reference waveforms while ascertaining that intermediate operations are not impacted by aliasing. This method is recommended for non-contiguous carriers separated by a large gap, and/or when the measurement sampling rate is low. Refer to AMPM concept help for more information.'
                },
                'name': 'ALIAS_PROTECTED',
                'value': 2
            }
        ]
    },
    'AmpmThresholdEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' All samples are considered for the AMPM measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Samples above the threshold level specified in the RFMXSPECAN_ATTR_AMPM_THRESHOLD_LEVEL attribute are considered for the AMPM measurement.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'AmpmThresholdType': {
        'values': [
            {
                'documentation': {
                    'description': ' The threshold is relative to the peak power of the acquired samples.'
                },
                'name': 'RELATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The threshold is the absolute power, in dBm.'
                },
                'name': 'ABSOLUTE',
                'value': 1
            }
        ]
    },
    'CcdfRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement does not use any RBW filtering.'
                },
                'name': 'NONE',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a Gaussian response.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a flat response.'
                },
                'name': 'FLAT',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The RRC filter with the roll-off specified by the RFMXSPECAN_ATTR_CCDF_RBW_FILTER_RRC_ALPHA attribute is used as the RBW filter.'
                },
                'name': 'RRC',
                'value': 6
            }
        ]
    },
    'CcdfThresholdEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' All samples are considered for the CCDF measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The samples above the threshold level specified in the RFMXSPECAN_ATTR_CCDF_THRESHOLD_LEVEL attribute are considered for the CCDF measurement.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'CcdfThresholdType': {
        'values': [
            {
                'documentation': {
                    'description': ' The threshold is relative to the peak power of the acquired samples.'
                },
                'name': 'RELATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The threshold is the absolute power, in dBm.'
                },
                'name': 'ABSOLUTE',
                'value': 1
            }
        ]
    },
    'ChpAmplitudeCorrectionType': {
        'values': [
            {
                'documentation': {
                    'description': ' All the frequency bins in the spectrum are compensated with a single external attenuation value that corresponds to the RF center frequency.'
                },
                'name': 'RF_CENTER_FREQUENCY',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An individual frequency bin in the spectrum is compensated with the external attenuation value corresponding to that frequency.'
                },
                'name': 'SPECTRUM_FREQUENCY_BIN',
                'value': 1
            }
        ]
    },
    'ChpAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The CHP measurement uses the RFMXSPECAN_ATTR_CHP_AVERAGING_COUNT attribute as the number of acquisitions over which the CHP measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'ChpAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power spectrum is linearly averaged. RMS averaging reduces signal fluctuations but not the noise floor.  '
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power spectrum is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power spectrum is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The peak power in the spectrum at each frequency bin is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The least power in the spectrum at each frequency bin is retained from one acquisition to the next. '
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'ChpCarrierRrcFilterEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The channel power of the acquired channel is measured directly.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement applies the RRC filter on the acquired channel before measuring the channel power.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'ChpFftWindow': {
        'values': [
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is shorter than the window length. You can also use this window type to separate two tones with frequencies close to each other but with almost equal amplitudes.  '
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measures single-tone amplitudes accurately.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is longer than the window length. You can also use this window type to provide better frequency resolution for noise measurements.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Analyzes closely-spaced sine waves.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Provides a good balance of spectral leakage, frequency resolution, and amplitude attenuation. Hence, this windowing is useful for time-frequency analysis.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Analyzes single tone because it has a low maximum side lobe level and a high side lobe roll-off rate. '
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Useful as a good general purpose window, having side lobe rejection greater than 90 dB and having a moderately wide main lobe. '
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Separates two tones with frequencies close to each other but with widely-differing amplitudes. '
                },
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'ChpMeasurementMode': {
        'values': [
            {
                'documentation': {
                    'description': ' CHP measurement is performed on the acquired signal.'
                },
                'name': 'MEASURE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Manual noise calibration of the signal analyzer is performed for the CHP measurement.'
                },
                'name': 'CALIBRATE_NOISE_FLOOR',
                'value': 1
            }
        ]
    },
    'ChpNoiseCalibrationAveragingAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' RFmx uses the averages that you set for the RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_COUNT attribute. '
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' RFmx uses a noise calibration averaging count of 32.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'ChpNoiseCalibrationMode': {
        'values': [
            {
                'documentation': {
                    'description': ' When you set the RFMXSPECAN_ATTR_CHP_MEASUREMENT_MODE attribute to RFMXSPECAN_VAL_CHP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR, you can initiate instrument noise calibration for the CHP measurement manually. When you set the RFMXSPECAN_ATTR_CHP_MEASUREMENT_MODE attribute to RFMXSPECAN_VAL_CHP_MEASUREMENT_MODE_MEASURE, you can initiate the CHP measurement manually.'
                },
                'name': 'MANUAL',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' When you set the RFMXSPECAN_ATTR_CHP_NOISE_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_ENABLED_TRUE, RFmx sets Input Isolation Enabled to Enabled and calibrates the intrument noise in the current state of the instrument. RFmx then resets the Input Isolation Enabled attribute and performs the CHP measurement, including compensation for noise of the instrument. RFmx skips noise calibration in this mode if valid noise calibration data is already cached. When you set the RFMXSPECAN_ATTR_CHP_NOISE_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_ENABLED_FALSE, RFmx does not calibrate instrument noise and performs only the CHP measurement without compensating for the noise contribution of the instrument.'
                },
                'name': 'AUTO',
                'value': 1
            }
        ]
    },
    'ChpNoiseCompensationEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables noise compensation.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables noise compensation.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'ChpNoiseCompensationType': {
        'values': [
            {
                'documentation': {
                    'description': ' Compensates for noise from the analyzer and the 50 ohm termination. The measured power values are in excess of the thermal noise floor.'
                },
                'name': 'ANALYZER_AND_TERMINATION',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Compensates for the analyzer noise only.'
                },
                'name': 'ANALYZER_ONLY',
                'value': 1
            }
        ]
    },
    'ChpRbwAutoBandwidth': {
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
    'ChpRbwFilterBandwidthDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 3 dB bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_CHP_RBW_FILTER_TYPE attribute to RFMXSPECAN_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED, RBW is the 3 dB bandwidth of the window specified by the RFMXSPECAN_ATTR_CHP_FFT_WINDOW attribute.'
                },
                'name': '3_DB',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the spectrum bin width computed using an FFT when you set the RFMXSPECAN_ATTR_CHP_RBW_FILTER_TYPE attribute to FFT Based.'
                },
                'name': 'BIN_WIDTH',
                'value': 2
            }
        ]
    },
    'ChpRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' No RBW filtering is performed.'
                },
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An RBW filter with a Gaussian response is applied.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' An RBW filter with a flat response is applied. '
                },
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'ChpSweepTimeAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement uses the sweep time that you specify in the RFMXSPECAN_ATTR_CHP_SWEEP_TIME_INTERVAL attribute. '
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement calculates the sweep time based on the value of the RFMXSPECAN_ATTR_CHP_RBW_FILTER_BANDWIDTH attribute.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DigitalEdgeTriggerEdge': {
        'values': [
            {
                'documentation': {
                    'description': ' The trigger asserts on the rising edge of the signal.'
                },
                'name': 'RISING_EDGE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The trigger asserts on the falling edge of the signal.'
                },
                'name': 'FALLING_EDGE',
                'value': 1
            }
        ]
    },
    'DigitalEdgeTriggerSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The trigger is received on PFI 0.'
                },
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PFI 1.'
                },
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 0.'
                },
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 1.'
                },
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 2.'
                },
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 3.'
                },
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 4.'
                },
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 5.'
                },
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 6.'
                },
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on PXI trigger line 7.'
                },
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on the PXI star trigger line. '
                },
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on the PXIe DStar B trigger line.   '
                },
                'name': 'PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'documentation': {
                    'description': ' The trigger is received from the timer event.'
                },
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            }
        ]
    },
    'DpdApplyDpdCfrEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables CFR. The maximum increase in PAPR, after pre-distortion, is limited to 6 dB.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables CFR.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdApplyDpdCfrMethod': {
        'values': [
            {
                'documentation': {
                    'description': ' Hard clips the signal such that the target PAPR is achieved.'
                },
                'name': 'CLIPPING',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Scales the peaks in the signal using weighted window function to get smooth peaks and achieve the target PAPR.'
                },
                'name': 'PEAK_WINDOWING',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Scales the peaks using modified sigmoid transfer function to get smooth peaks and achieve the target PAPR. This method does not support the filter operation.'
                },
                'name': 'SIGMOID',
                'value': 2
            }
        ]
    },
    'DpdApplyDpdCfrTargetPaprType': {
        'values': [
            {
                'documentation': {
                    'description': ' Sets the target PAPR for pre-distorted waveform equal to the PAPR of input waveform.'
                },
                'name': 'INPUT_PAPR',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Sets the target PAPR equal to the value that you set for the Apply DPD CFR Target PAPR attribute.'
                },
                'name': 'CUSTOM',
                'value': 1
            }
        ]
    },
    'DpdApplyDpdCfrWindowType': {
        'values': [
            {
                'documentation': {
                    'description': ' Uses the flat top window function to scale peaks.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Uses the Hanning window function to scale peaks.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Uses the Hamming window function to scale peaks.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Uses the Gaussian window function to scale peaks.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Uses the Blackman window function to scale peaks.'
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Uses the Blackman-Harris window function to scale peaks.'
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Uses the Kaiser-Bessel window function to scale peaks.'
                },
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'DpdApplyDpdConfigurationInput': {
        'values': [
            {
                'documentation': {
                    'description': ' Uses the computed DPD polynomial or lookup table for applying DPD on an input waveform using the same RFmx session handle. The configuration parameters for applying DPD such as the RFMXSPECAN_ATTR_DPD_DUT_AVERAGE_INPUT_POWER, RFMXSPECAN_ATTR_DPD_MODEL, RFMXSPECAN_ATTR_DPD_MEASUREMENT_SAMPLE_RATE, DPD polynomial, and lookup table  are obtained from the DPD measurement configuration. '
                },
                'name': 'MEASUREMENT',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Applies DPD by using a computed DPD polynomial or lookup table on an input waveform. You must set the configuration parameters for applying DPD such as the  RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DUT_AVERAGE_INPUT_POWER, RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL, RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEASUREMENT_SAMPLE_RATE, DPD polynomial, and lookup table.  '
                },
                'name': 'USER',
                'value': 1
            }
        ]
    },
    'DpdApplyDpdLookupTableCorrectionType': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement predistorts the magnitude and phase of the input waveform.'
                },
                'name': 'MAGNITUDE_AND_PHASE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement predistorts only the magnitude of the input waveform.'
                },
                'name': 'MAGNITUDE_ONLY',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The measurement predistorts only the phase of the input waveform.'
                },
                'name': 'PHASE_ONLY',
                'value': 2
            }
        ]
    },
    'DpdApplyDpdMemoryModelCorrectionType': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement predistorts the magnitude and phase of the input waveform.'
                },
                'name': 'MAGNITUDE_AND_PHASE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement predistorts only the magnitude of the input waveform.'
                },
                'name': 'MAGNITUDE_ONLY',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The measurement predistorts only the phase of the input waveform.'
                },
                'name': 'PHASE_ONLY',
                'value': 2
            }
        ]
    },
    'DpdApplyDpdUserDpdModel': {
        'values': [
            {
                'documentation': {
                    'description': ' This model computes the complex gain coefficients applied to linearize systems with negligible memory effects.'
                },
                'name': 'LOOKUP_TABLE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' This model computes the memory polynomial predistortion coefficients used to linearize systems with moderate memory effects.'
                },
                'name': 'MEMORY_POLYNOMIAL',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' This model computes the generalized memory polynomial predistortion coefficients used to linearize systems with significant memory effects.'
                },
                'name': 'GENERALIZED_MEMORY_POLYNOMIAL',
                'value': 2
            }
        ]
    },
    'DpdApplyDpdUserLookupTableType': {
        'values': [
            {
                'documentation': {
                    'description': ' Input powers in the LUT are specified in dBm.'
                },
                'name': 'LOG',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Input powers in the LUT are specified in watts.'
                },
                'name': 'LINEAR',
                'value': 1
            }
        ]
    },
    'DpdAutoCarrierDetectionEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables auto detection of carrier offset and carrier bandwidth.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables auto detection of carrier offset and carrier bandwidth.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The DPD measurement uses the RFMXSPECAN_ATTR_DPD_AVERAGING_COUNT attribute as the number of acquisitions over which the signal for the DPD measurement is averaged. '
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdFrequencyOffsetCorrectionEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement computes and corrects any frequency offset between the reference and the acquired waveforms.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement does not perform frequency offset correction.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdIQOriginOffsetCorrectionEnabled': {
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
    'DpdIterativeDpdEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' RFmx computes the DPD Results DPD Polynomial without considering the value of the DPD Previous DPD Polynomial.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' RFmx computes the DPD Results DPD Polynomial based on the value of the DPD Previous DPD Polynomial.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdLookupTableAMToAMCurveFitType': {
        'values': [
            {
                'name': 'LEAST_SQUARE',
                'value': 0
            },
            {
                'name': 'LEAST_ABSOLUTE_RESIDUAL',
                'value': 1
            },
            {
                'name': 'BISQUARE',
                'value': 2
            }
        ]
    },
    'DpdLookupTableAMToPMCurveFitType': {
        'values': [
            {
                'name': 'LEAST_SQUARE',
                'value': 0
            },
            {
                'name': 'LEAST_ABSOLUTE_RESIDUAL',
                'value': 1
            },
            {
                'name': 'BISQUARE',
                'value': 2
            }
        ]
    },
    'DpdLookupTableThresholdEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' All samples are considered for the DPD measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Only samples above the threshold level which you specify in the RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_LEVEL attribute are considered for the DPD measurement.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdLookupTableThresholdType': {
        'values': [
            {
                'documentation': {
                    'description': ' The threshold is relative to the peak power of the acquired samples.'
                },
                'name': 'RELATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The threshold is the absolute power, in dBm.'
                },
                'name': 'ABSOLUTE',
                'value': 1
            }
        ]
    },
    'DpdLookupTableType': {
        'values': [
            {
                'documentation': {
                    'description': ' Input powers in the LUT are specified in dBm.'
                },
                'name': 'LOG',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Input powers in the LUT are specified in watts.'
                },
                'name': 'LINEAR',
                'value': 1
            }
        ]
    },
    'DpdMeasurementSampleRateMode': {
        'values': [
            {
                'documentation': {
                    'description': ' The acquisition sample rate is defined by the value of the RFMXSPECAN_ATTR_DPD_MEASUREMENT_SAMPLE_RATE attribute.'
                },
                'name': 'USER',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The acquisition sample rate is set to match the sample rate of the reference waveform.'
                },
                'name': 'REFERENCE_WAVEFORM',
                'value': 1
            }
        ]
    },
    'DpdModel': {
        'values': [
            {
                'documentation': {
                    'description': ' This model computes the complex gain coefficients applied when performing digital predistortion to linearize systems with negligible memory effects.'
                },
                'name': 'LOOKUP_TABLE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' This model computes the memory polynomial predistortion coefficients used to linearize systems with moderate memory effects.'
                },
                'name': 'MEMORY_POLYNOMIAL',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' This model computes the generalized memory polynomial predistortion coefficients used to linearize systems with significant memory effects.'
                },
                'name': 'GENERALIZED_MEMORY_POLYNOMIAL',
                'value': 2
            }
        ]
    },
    'DpdNmseEnabled': {
        'values': [
            {
                'documentation': {
                    'description': '  Disables NMSE computation. NaN is returned as NMSE.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables NMSE computation.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdPreDpdCfrEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the CFR. The RFmxSpecAn_DPDApplyPreDPDSignalConditioning function returns an error when the CFR is disabled.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables the CFR.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdPreDpdCfrFilterEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the filter operation when performing CFR.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables filter operation when performing CFR. Filter operation is not supported when you set the RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_METHOD attribute to RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_SIGMOID.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'DpdPreDpdCfrMethod': {
        'values': [
            {
                'documentation': {
                    'description': ' Hard clips the signal such that the target PAPR is achieved.'
                },
                'name': 'CLIPPING',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Scales the peaks in the signal using weighted window function to get smooth peaks and achieve the target PAPR.'
                },
                'name': 'PEAK_WINDOWING',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Scales the peaks using modified sigmoid transfer function to get smooth peaks and achieve the target PAPR. This method does not support the filter operation.'
                },
                'name': 'SIGMOID',
                'value': 2
            }
        ]
    },
    'DpdPreDpdCfrWindowType': {
        'values': [
            {
                'documentation': {
                    'description': ' Uses the flat top window function to scale peaks.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Uses the Hanning window function to scale peaks.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Uses the Hamming window function to scale peaks.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Uses the Gaussian window function to scale peaks.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Uses the Blackman window function to scale peaks.'
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Uses the Blackman-Harris window function to scale peaks.'
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Uses the Kaiser-Bessel window function to scale peaks.'
                },
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'DpdSignalType': {
        'values': [
            {
                'documentation': {
                    'description': ' The reference waveform is a cellular or connectivity standard signal.'
                },
                'name': 'MODULATED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The reference waveform is a continuous signal comprising one or more tones.'
                },
                'name': 'TONES',
                'value': 1
            }
        ]
    },
    'DpdSynchronizationMethod': {
        'values': [
            {
                'documentation': {
                    'description': ' Synchronizes the acquired and reference waveforms assuming that sample rate is sufficient to prevent aliasing in intermediate operations. This method is recommended when measurement sampling rate is high.'
                },
                'name': 'DIRECT',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Synchronizes the acquired and  reference waveforms while ascertaining that intermediate operations are not impacted by aliasing. This method is recommended for non-contiguous carriers separated by a large gap, and/or when measurement sampling rate is low. Refer to DPD concept help for more information.'
                },
                'name': 'ALIAS_PROTECTED',
                'value': 2
            }
        ]
    },
    'DpdTargetGainType': {
        'values': [
            {
                'documentation': {
                    'description': ' The DPD polynomial or lookup table is computed by assuming that the linearized gain expected from the DUT after applying DPD on the input waveform is equal to the average power gain provided by the DUT without DPD.'
                },
                'name': 'AVERAGE_GAIN',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The DPD polynomial or lookup table is computed by assuming that the linearized gain expected from the DUT after applying DPD on the input waveform is equal to the gain provided by the DUT, without DPD, to the parts of the reference waveform that do not drive the DUT into non-linear gain-expansion or compression regions of its input-output characteristics.\n\n The measurement computes the linear region gain as the average gain experienced by the parts of the reference waveform that are below a threshold which is computed as shown in the following equation:\n\n   Linear region threshold (dBm) = Max {-25, Min {reference waveform power} + 6, DUT Average Input Power -15}'
                },
                'name': 'LINEAR_REGION_GAIN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The DPD polynomial or lookup table is computed by assuming that the linearized gain expected from the DUT after applying DPD on the input waveform is equal to the average power gain provided by the DUT, without DPD, to all the samples of the reference waveform for which the magnitude is greater than the peak power in the reference waveform (dBm) - 0.5dB.'
                },
                'name': 'PEAK_INPUT_POWER_GAIN',
                'value': 2
            }
        ]
    },
    'FcntAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The FCnt measurement uses the RFMXSPECAN_ATTR_FCNT_AVERAGING_COUNT attribute as the number of acquisitions over which the FCnt measurement is averaged.  '
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'FcntAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The mean of the instantaneous signal phase difference over multiple acquisitions is used for the frequency measurement. '
                },
                'name': 'MEAN',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' The maximum instantaneous signal phase difference over multiple acquisitions is used for the frequency measurement. '
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The minimum instantaneous signal phase difference over multiple acquisitions is used for the frequency measurement. '
                },
                'name': 'MINIMUM',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' The maximum instantaneous signal phase difference over multiple acquisitions is used for the frequency measurement. The sign of the phase difference is ignored to find the maximum instantaneous value.'
                },
                'name': 'MINMAX',
                'value': 7
            }
        ]
    },
    'FcntRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement does not use any RBW filtering.'
                },
                'name': 'NONE',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a Gaussian response.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a flat response.'
                },
                'name': 'FLAT',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The RRC filter with the roll-off specified by RFMXSPECAN_ATTR_FCNT_RBW_FILTER_RRC_ALPHA attribute is used as the RBW filter.'
                },
                'name': 'RRC',
                'value': 6
            }
        ]
    },
    'FcntThresholdEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' All samples are considered for the FCnt measurement. '
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The samples above the threshold level specified in the RFMXSPECAN_ATTR_FCNT_THRESHOLD_LEVEL attribute are considered for the FCnt measurement. '
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'FcntThresholdType': {
        'values': [
            {
                'documentation': {
                    'description': ' The threshold is relative to the peak power of the acquired samples.'
                },
                'name': 'RELATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The threshold is the absolute power, in dBm.'
                },
                'name': 'ABSOLUTE',
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
    'HarmAutoHarmonicsSetupEnabled': {
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
    'HarmAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The Harmonics measurement uses the RFMXSPECAN_ATTR_HARM_AVERAGING_COUNT attribute as the number of acquisitions over which the Harmonics measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'HarmAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power trace is linearly averaged. RMS averaging reduces signal fluctuations but not the noise floor. '
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power trace is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power trace is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The maximum instantaneous power in the power trace is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The minimum instantaneous power in the power trace is retained from one acquisition to the next.'
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'HarmHarmonicEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the harmonic for measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables the harmonic for measurement.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'HarmMeasurementMethod': {
        'values': [
            {
                'documentation': {
                    'description': ' The harmonics measurement acquires the signal using the same signal analyzer setting across frequency bands. Use this method when the measurement speed is desirable over higher dynamic range.\n\n   Supported devices: PXIe-5644/5645/5646, PXIe-5663/5665/5668'
                },
                'name': 'TIME_DOMAIN',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The harmonics measurement acquires the signal using the hardware-specific features, such as the IF filter and IF gain, for different frequency bands. Use this method to get the best dynamic range.\n\n   Supported devices: PXIe-5665/5668'
                },
                'name': 'DYNAMIC_RANGE',
                'value': 2
            }
        ]
    },
    'HarmNoiseCompensationEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables compensation of the average harmonic powers for the noise floor of the signal analyzer.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables compensation of the average harmonic powers for the noise floor of the signal analyzer. The noise floor of the signal analyzer is measured for the RF path used by the harmonics measurement and cached for future use. If the signal analyzer or measurement parameters change, noise floors are measured again.\n\n   Supported devices: PXIe-5663/5665/5668'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'HarmRbwFilterType': {
        'values': [
            {
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'name': 'FLAT',
                'value': 2
            },
            {
                'name': 'NONE',
                'value': 5
            },
            {
                'name': 'RRC',
                'value': 6
            }
        ]
    },
    'IMAmplitudeCorrectionType': {
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
    'IMAutoIntermodsSetupEnabled': {
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
    'IMAveragingEnabled': {
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
    'IMAveragingType': {
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
    'IMFftWindow': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'name': 'HANNING',
                'value': 2
            },
            {
                'name': 'HAMMING',
                'value': 3
            },
            {
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'IMFrequencyDefinition': {
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
    'IMIFOutputPowerOffsetAuto': {
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
    'IMIntermodEnabled': {
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
    'IMIntermodSide': {
        'values': [
            {
                'name': 'LOWER',
                'value': 0
            },
            {
                'name': 'UPPER',
                'value': 1
            },
            {
                'name': 'BOTH',
                'value': 2
            }
        ]
    },
    'IMLocalPeakSearchEnabled': {
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
    'IMMeasurementMethod': {
        'values': [
            {
                'name': 'NORMAL',
                'value': 0
            },
            {
                'name': 'DYNAMIC_RANGE',
                'value': 1
            },
            {
                'name': 'SEGMENTED',
                'value': 2
            }
        ]
    },
    'IMRbwFilterAutoBandwidth': {
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
    'IMRbwFilterType': {
        'values': [
            {
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'IMSweepTimeAuto': {
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
    'IQBandwidthAuto': {
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
    'IQDeleteRecordOnFetch': {
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
                'documentation': {
                    'description': ' This is the normal mode of RFmx operation. All configuration changes in RFmxInstr attributes or in personality attributes will be applied during RFmx Commit.'
                },
                'name': 'DISABLED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Signal configuration and RFmxInstr configuration are locked after the first Commit or Initiate of the named signal configuration. Any configuration change thereafter either in RFmxInstr attributes or personality attributes will not be considered by subsequent RFmx Commits or Initiates of this signal.  Use No Change if you have created named signal configurations for all measurement configurations but are setting some RFmxInstr attributes. Refer to the Limitations of the Limited Configuration Change Attribute topic for more details about the limitations of using this mode. '
                },
                'name': 'NO_CHANGE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Signal configuration, other than center frequency, external attenuation, and RFInstr configuration, is locked after first Commit or Initiate of the named signal configuration. Thereafter, only the Center Frequency and RFMXSPECAN_ATTR_EXTERNAL_ATTENUATION attribute value changes will be considered by subsequent driver Commits or Initiates of this signal.  Refer to the Limitations of the  Limited Configuration Change Attribute topic for more details about the limitations of using this mode.  '
                },
                'name': 'FREQUENCY',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Signal configuration, other than the reference level and RFInstr configuration, is locked after first Commit or Initiate of the named signal configuration. Thereafter only the RFMXSPECAN_ATTR_REFERENCE_LEVEL attribute value change will be considered by subsequent driver Commits or Initiates of this signal. If you have configured this signal to use an IQ Power Edge Trigger, NI recommends that you set the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE to RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE so that the trigger level is automatically adjusted as you adjust the reference level. Refer to the Limitations of the Limited Configuration Change Attribute topic for more details about the limitations of using this mode. '
                },
                'name': 'REFERENCE_LEVEL',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Signal configuration, other than center frequency, reference level, external attenuation, and RFInstr configuration, is locked after first Commit or Initiate of the named signal configuration. Thereafter only Center Frequency, RFMXSPECAN_ATTR_REFERENCE_LEVEL, and RFMXSPECAN_ATTR_EXTERNAL_ATTENUATION attribute value changes will be considered by subsequent driver Commits or Initiates of this signal. If you have configured this signal to use an IQ Power Edge Trigger, NI recommends you set the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE to RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE so that the trigger level is automatically adjusted as you adjust the reference level. Refer to the Limitations of the Limited Configuration Change Attribute topic for more details about the limitations of using this mode. '
                },
                'name': 'FREQUENCY_AND_REFERENCE_LEVEL',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Signal configuration, other than Selected Ports, Center frequency, Reference level, External attenuation, and RFInstr configuration, is locked after first Commit or Initiate of the named signal configuration. Thereafter only Selected Ports, Center Frequency, RFMXSPECAN_ATTR_REFERENCE_LEVEL, and RFMXSPECAN_ATTR_EXTERNAL_ATTENUATION attribute value changes will be considered by subsequent driver Commits or Initiates of this signal. If you have configured this signal to use an IQ Power Edge Trigger, NI recommends you set the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE to RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE so that the trigger level is automatically adjusted as you adjust the reference level. Refer to the Limitations of the Limited Configuration Change Attribute topic for more details about the limitations of using this mode.'
                },
                'name': 'SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL',
                'value': 5
            }
        ]
    },
    'MarkerNextPeak': {
        'values': [
            {
                'name': 'NEXT_HIGHEST',
                'value': 0
            },
            {
                'name': 'NEXT_LEFT',
                'value': 1
            },
            {
                'name': 'NEXT_RIGHT',
                'value': 2
            }
        ]
    },
    'MarkerTrace': {
        'values': [
            {
                'name': 'ACP_SPECTRUM',
                'value': 0
            },
            {
                'name': 'CCDF_GAUSSIAN_PROBABILITIES_TRACE',
                'value': 1
            },
            {
                'name': 'CCDF_PROBABILITIES_TRACE',
                'value': 2
            },
            {
                'name': 'CHP_SPECTRUM',
                'value': 3
            },
            {
                'name': 'FCNT_POWER_TRACE',
                'value': 4
            },
            {
                'name': 'OBW_SPECTRUM',
                'value': 5
            },
            {
                'name': 'SEM_SPECTRUM',
                'value': 6
            },
            {
                'name': 'SPECTRUM',
                'value': 7
            },
            {
                'name': 'TXP_POWER_TRACE',
                'value': 8
            }
        ]
    },
    'MarkerType': {
        'values': [
            {
                'name': 'OFF',
                'value': 0
            },
            {
                'name': 'NORMAL',
                'value': 1
            },
            {
                'name': 'DELTA',
                'value': 3
            }
        ]
    },
    'MeasurementTypes': {
        'values': [
            {
                'name': 'ACP',
                'value': 1
            },
            {
                'name': 'CCDF',
                'value': 2
            },
            {
                'name': 'CHP',
                'value': 4
            },
            {
                'name': 'FCNT',
                'value': 8
            },
            {
                'name': 'HARMONICS',
                'value': 16
            },
            {
                'name': 'OBW',
                'value': 32
            },
            {
                'name': 'SEM',
                'value': 64
            },
            {
                'name': 'SPECTRUM',
                'value': 128
            },
            {
                'name': 'SPUR',
                'value': 256
            },
            {
                'name': 'TXP',
                'value': 512
            },
            {
                'name': 'AMPM',
                'value': 1024
            },
            {
                'name': 'DPD',
                'value': 2048
            },
            {
                'name': 'IQ',
                'value': 4096
            },
            {
                'name': 'IM',
                'value': 8192
            },
            {
                'name': 'NF',
                'value': 16384
            },
            {
                'name': 'PHASENOISE',
                'value': 32768
            },
            {
                'name': 'PAVT',
                'value': 65536
            }
        ]
    },
    'NFAveragingEnabled': {
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
    'NFCalibrationLossCompensationEnabled': {
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
    'NFColdSourceMode': {
        'values': [
            {
                'name': 'MEASURE',
                'value': 0
            },
            {
                'name': 'CALIBRATE',
                'value': 1
            }
        ]
    },
    'NFDutInputLossCompensationEnabled': {
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
    'NFDutOutputLossCompensationEnabled': {
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
    'NFDutType': {
        'values': [
            {
                'name': 'AMPLIFIER',
                'value': 0
            },
            {
                'name': 'DOWNCONVERTER',
                'value': 1
            },
            {
                'name': 'UPCONVERTER',
                'value': 2
            }
        ]
    },
    'NFExternalPreampPresent': {
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
    'NFFrequencyConverterFrequencyContext': {
        'values': [
            {
                'name': 'RF',
                'value': 0
            },
            {
                'name': 'IF',
                'value': 1
            }
        ]
    },
    'NFFrequencyConverterSideband': {
        'values': [
            {
                'name': 'LSB',
                'value': 0
            },
            {
                'name': 'USB',
                'value': 1
            }
        ]
    },
    'NFMeasurementMethod': {
        'values': [
            {
                'name': 'Y_FACTOR',
                'value': 0
            },
            {
                'name': 'COLD_SOURCE',
                'value': 1
            }
        ]
    },
    'NFYFactorMode': {
        'values': [
            {
                'name': 'MEASURE',
                'value': 0
            },
            {
                'name': 'CALIBRATE',
                'value': 1
            }
        ]
    },
    'NFYFactorNoiseSourceLossCompensationEnabled': {
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
    'ObwAmplitudeCorrectionType': {
        'values': [
            {
                'documentation': {
                    'description': ' All the frequency bins in the spectrum are compensated with a single external attenuation value that corresponds to the RF center frequency.'
                },
                'name': 'RF_CENTER_FREQUENCY',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An individual frequency bin in the spectrum is compensated with the external attenuation value corresponding to that frequency.'
                },
                'name': 'SPECTRUM_FREQUENCY_BIN',
                'value': 1
            }
        ]
    },
    'ObwAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The OBW measurement uses the RFMXSPECAN_ATTR_OBW_AVERAGING_COUNT attribute as the number of acquisitions over which the OBW measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'ObwAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power spectrum is linearly averaged. RMS averaging reduces signal fluctuations but not the noise floor.  '
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power spectrum is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power spectrum is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The peak power in the spectrum at each frequency bin is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The least power in the spectrum at each frequency bin is retained from one acquisition to the next. '
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'ObwFftWindow': {
        'values': [
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is shorter than the window length. You can also use this window type to separate two tones with frequencies close to each other but with almost equal amplitudes.  '
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measures single-tone amplitudes accurately.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is longer than the window length. You can also use this window type to provide better frequency resolution for noise measurements.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Analyzes closely-spaced sine waves.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Provides a good balance of spectral leakage, frequency resolution, and amplitude attenuation. Hence, this windowing is useful for time-frequency analysis.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Analyzes single tone because it has a low maximum side lobe level and a high side lobe roll-off rate. '
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Useful as a good general purpose window, having side lobe rejection greater than 90 dB and having a moderately wide main lobe. '
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Separates two tones with frequencies close to each other but with widely-differing amplitudes. '
                },
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'ObwPowerUnits': {
        'values': [
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm.'
                },
                'name': 'DBM',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm/Hz.'
                },
                'name': 'DBM_PER_HZ',
                'value': 1
            }
        ]
    },
    'ObwRbwAutoBandwidth': {
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
    'ObwRbwFilterBandwidthDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 3 dB bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_OBW_RBW_FILTER_TYPE attribute to RFMXSPECAN_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED, RBW is the 3 dB bandwidth of the window specified by the RFMXSPECAN_ATTR_OBW_FFT_WINDOW attribute.'
                },
                'name': '3_DB',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the spectrum bin width computed using an FFT when you set the RFMXSPECAN_ATTR_OBW_RBW_FILTER_TYPE attribute to FFT Based.'
                },
                'name': 'BIN_WIDTH',
                'value': 2
            }
        ]
    },
    'ObwRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' No RBW filtering is performed.'
                },
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a Gaussian response.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The RBW filter  has a flat response.'
                },
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'ObwSweepTimeAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement uses the sweep time that you specify in the RFMXSPECAN_ATTR_OBW_SWEEP_TIME_INTERVAL attribute. '
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement calculates the sweep time based on the value of the RFMXSPECAN_ATTR_OBW_RBW_FILTER_BANDWIDTH attribute.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'PavtFrequencyOffsetCorrectionEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the frequency offset correction.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables the frequency offset correction. The measurement computes and corrects any frequency offset between the reference and the acquired waveforms.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'PavtFrequencyTrackingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the drift correction for the measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables the drift correction. The measurement corrects and reports the frequency offset per segment.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'PavtMeasurementIntervalMode': {
        'values': [
            {
                'documentation': {
                    'description': ' The time offset from the start of segment and the duration over which the measurement is performed is uniform for all segments and is given by the RFMXSPECAN_ATTR_PAVT_MEASUREMENT_OFFSET attribute and the RFMXSPECAN_ATTR_PAVT_MEASUREMENT_LENGTH attribute respectively.'
                },
                'name': 'UNIFORM',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The time offset from the start of segment and the duration over which the measurement is performed is configured separately for each segment and is given by the RFMXSPECAN_ATTR_PAVT_SEGMENT_MEASUREMENT_OFFSET attribute and the RFMXSPECAN_ATTR_PAVT_SEGMENT_MEASUREMENT_LENGTH attribute respectively.'
                },
                'name': 'VARIABLE',
                'value': 1
            }
        ]
    },
    'PavtMeasurementLocationType': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed over a single record across multiple segments separated in time. The measurement locations of the segments are specified by the RFMXSPECAN_ATTR_PAVT_SEGMENT_START_TIME attribute. The number of segments is equal to the number of segment start times.'
                },
                'name': 'TIME',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement is performed across segments obtained in multiple records, where each record is obtained when a trigger is received. The number of segments is equal to the number of triggers (records).'
                },
                'name': 'TRIGGER',
                'value': 1
            }
        ]
    },
    'PavtPhaseUnwrapEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Phase measurement results are wrapped within +/-180 degrees.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Phase measurement results are unwrapped.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'PavtSegmentType': {
        'values': [
            {
                'documentation': {
                    'description': ' Phase and amplitude is measured in this segment.'
                },
                'name': 'PHASE_AND_AMPLITUDE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Amplitude is measured in this segment.'
                },
                'name': 'AMPLITUDE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Frequency error is measured in this segment.'
                },
                'name': 'FREQUENCY_ERROR_MEASUREMENT',
                'value': 2
            }
        ]
    },
    'PhaseNoiseCancellationEnabled': {
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
    'PhaseNoiseFftWindow': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'name': 'HANNING',
                'value': 2
            },
            {
                'name': 'HAMMING',
                'value': 3
            },
            {
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'PhaseNoiseIntegratedNoiseRangeDefinition': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'MEASUREMENT',
                'value': 1
            },
            {
                'name': 'CUSTOM',
                'value': 2
            }
        ]
    },
    'PhaseNoiseRangeDefinition': {
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
    'PhaseNoiseSmoothingType': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'LINEAR',
                'value': 1
            },
            {
                'name': 'LOGARITHMIC',
                'value': 2
            },
            {
                'name': 'MEDIAN',
                'value': 3
            }
        ]
    },
    'PhaseNoiseSpurRemovalEnabled': {
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
                'documentation': {
                    'description': ' All the frequency bins in the spectrum are compensated with a single external attenuation value that corresponds to the RF center frequency.'
                },
                'name': 'RF_CENTER_FREQUENCY',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An individual frequency bin in the spectrum is compensated with the external attenuation value corresponding to that frequency.'
                },
                'name': 'SPECTRUM_FREQUENCY_BIN',
                'value': 1
            }
        ]
    },
    'SemAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The SEM measurement uses the RFMXSPECAN_ATTR_SEM_AVERAGING_COUNT attribute as the number of acquisitions over which the SEM measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power spectrum is linearly averaged. RMS averaging reduces signal fluctuations but not the noise floor.  '
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power spectrum is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power spectrum is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The peak power in the spectrum at each frequency bin is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The least power in the spectrum at each frequency bin is retained from one acquisition to the next. '
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'SemCarrierEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The carrier power is not considered as part of the total carrier power.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The carrier power is considered as part of the total carrier power.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemCarrierRbwAutoBandwidth': {
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
    'SemCarrierRbwFilterBandwidthDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 3 dB bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_TYPE attribute to RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_TYPE_FFT_BASED, RBW is the 3 dB bandwidth of the window specified by the RFMXSPECAN_ATTR_SEM_FFT_WINDOW attribute.'
                },
                'name': '3_DB',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the spectrum bin width computed using an FFT when you set the RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_TYPE attribute to FFT Based.'
                },
                'name': 'BIN_WIDTH',
                'value': 2
            }
        ]
    },
    'SemCarrierRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' No RBW filtering is performed.'
                },
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a Gaussian response.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a flat response.'
                },
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'SemCarrierRrcFilterEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The channel power of the acquired carrier channel is measured directly.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement applies the RRC filter on the acquired carrier channel before measuring the carrier channel power.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemCompositeMeasurementStatus': {
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
    'SemFftWindow': {
        'values': [
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is shorter than the window length. You can also use this window type to separate two tones with frequencies close to each other but with almost equal amplitudes.  '
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measures single-tone amplitudes accurately.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is longer than the window length. You can also use this window type to provide better frequency resolution for noise measurements.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Analyzes closely-spaced sine waves.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Provides a good balance of spectral leakage, frequency resolution, and amplitude attenuation. Hence, this windowing is useful for time-frequency analysis.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Analyzes single tone because it has a low maximum side lobe level and a high side lobe roll-off rate. '
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Useful as a good general purpose window, having side lobe rejection greater than 90 dB and having a moderately wide main lobe. '
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Separates two tones with frequencies close to each other but with widely-differing amplitudes. '
                },
                'name': 'KAISER_BESSEL',
                'value': 7
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
    'SemOffsetAbsoluteLimitMode': {
        'values': [
            {
                'documentation': {
                    'description': ' The line specified by the RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_START and RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_STOP attribute values as the two ends is considered as the mask.'
                },
                'name': 'MANUAL',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The two ends of the line are coupled to the value of the RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_START attribute.'
                },
                'name': 'COUPLE',
                'value': 1
            }
        ]
    },
    'SemOffsetEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the offset segment for the SEM measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables the offset segment for the SEM measurement.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SemOffsetFrequencyDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' The start frequency and stop frequency are defined from the center of the closest carrier channel bandwidth to the center of the offset segment measurement bandwidth.\n\nMeasurement Bandwidth = Resolution Bandwidth * Bandwidth Integral.'
                },
                'name': 'CARRIER_CENTER_TO_MEASUREMENT_BANDWIDTH_CENTER',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The start frequency and stop frequency are defined from the center of the closest carrier channel bandwidth to the nearest edge of the offset segment measurement bandwidth.'
                },
                'name': 'CARRIER_CENTER_TO_MEASUREMENT_BANDWIDTH_EDGE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The start frequency and stop frequency are defined from the nearest edge of the closest carrier channel bandwidth to the center of the nearest offset segment measurement bandwidth.'
                },
                'name': 'CARRIER_EDGE_TO_MEASUREMENT_BANDWIDTH_CENTER',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The start frequency and stop frequency are defined from the nearest edge of the closest carrier channel bandwidth to the edge of the nearest offset segment measurement bandwidth.'
                },
                'name': 'CARRIER_EDGE_TO_MEASUREMENT_BANDWIDTH_EDGE',
                'value': 3
            }
        ]
    },
    'SemOffsetLimitFailMask': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement fails if the power in the segment exceeds both the absolute and relative masks.'
                },
                'name': 'ABSOLUTE_AND_RELATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement fails if the power in the segment exceeds either the absolute or relative mask.'
                },
                'name': 'ABSOLUTE_OR_RELATIVE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The measurement fails if the power in the segment exceeds the absolute mask.'
                },
                'name': 'ABSOLUTE',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The measurement fails if the power in the segment exceeds the relative mask.'
                },
                'name': 'RELATIVE',
                'value': 3
            }
        ]
    },
    'SemOffsetRbwAutoBandwidth': {
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
    'SemOffsetRbwFilterBandwidthDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 3dB bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_TYPE attribute to RFMXSPECAN_VAL_SEM_RBW_FILTER_TYPE_FFT_BASED, RBW is the 3dB bandwidth of the window specified by the RFMXSPECAN_ATTR_SEM_FFT_WINDOW attribute.'
                },
                'name': '3_DB',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the spectrum bin width computed using FFT when you set the RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_TYPE attribute to FFT Based.'
                },
                'name': 'BIN_WIDTH',
                'value': 2
            }
        ]
    },
    'SemOffsetRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' No RBW filtering is performed.'
                },
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a Gaussian response.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a flat response.'
                },
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'SemOffsetRelativeLimitMode': {
        'values': [
            {
                'documentation': {
                    'description': ' The line specified by the RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_START and RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_STOP attribute values as the two ends is considered as the mask.'
                },
                'name': 'MANUAL',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The two ends of the line are coupled to the value of the RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_START attribute.'
                },
                'name': 'COUPLE',
                'value': 1
            }
        ]
    },
    'SemOffsetSideband': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures a lower offset segment to the left of the leftmost carrier. '
                },
                'name': 'NEGATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Configures an upper offset segment to the right of the rightmost carrier.  '
                },
                'name': 'POSITIVE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Configures both negative and positive offset segments.'
                },
                'name': 'BOTH',
                'value': 2
            }
        ]
    },
    'SemPowerUnits': {
        'values': [
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm.'
                },
                'name': 'DBM',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm/Hz.'
                },
                'name': 'DBM_PER_HZ',
                'value': 1
            }
        ]
    },
    'SemReferenceType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power reference is the integrated power of the closest carrier.'
                },
                'name': 'INTEGRATION',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power reference is the peak power of the closest carrier.'
                },
                'name': 'PEAK',
                'value': 1
            }
        ]
    },
    'SemSweepTimeAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement uses the sweep time that you specify in the RFMXSPECAN_ATTR_SEM_SWEEP_TIME_INTERVAL attribute.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement calculates the sweep time based on the value of the RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH and  RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_BANDWIDTH attributes.'
                },
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
    'SpectrumAmplitudeCorrectionType': {
        'values': [
            {
                'documentation': {
                    'description': ' All the frequency bins in the spectrum are compensated with a single external attenuation value that corresponds to the RF center frequency.'
                },
                'name': 'RF_CENTER_FREQUENCY',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An individual frequency bin in the spectrum is compensated with the external attenuation value corresponding to that frequency.'
                },
                'name': 'SPECTRUM_FREQUENCY_BIN',
                'value': 1
            }
        ]
    },
    'SpectrumAnalysisInput': {
        'values': [
            {
                'documentation': {
                    'description': ' Measurement analyzes the acquired I+jQ data, resulting generally in a spectrum that is not symmetric around 0 Hz. Spectrum trace result contains both positive and negative frequencies. Since the RMS power of the complex envelope is 3.01 dB higher than that of its equivalent real RF signal, the spectrum trace result of the acquired I+jQ data is scaled by -3.01 dB. '
                },
                'name': 'IQ',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measurement ignores the Q data from the acquired I+jQ data and analyzes I+j0, resulting in a spectrum that is symmetric around 0 Hz. Spectrum trace result contains positive frequencies only. Spectrum of I+j0 data is scaled by +3.01 dB to account for the power of the negative frequencies that are not returned in the spectrum trace.'
                },
                'name': 'I_ONLY',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Measurement ignores the I data from the acquired I+jQ data and analyzes Q+j0, resulting in a spectrum that is symmetric around 0 Hz. Spectrum trace result contains positive frequencies only. Spectrum of Q+j0 data is scaled by +3.01 dB to account for the power of the negative frequencies that are not returned in the spectrum trace.'
                },
                'name': 'Q_ONLY',
                'value': 2
            }
        ]
    },
    'SpectrumAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The spectrum measurement uses the RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_COUNT attribute as the number of acquisitions over which the spectrum measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpectrumAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power spectrum is linearly averaged. RMS averaging reduces signal fluctuations but not the noise floor.  '
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power spectrum is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power spectrum is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The peak power in the spectrum at each frequency bin is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The least power in the spectrum at each frequency bin is retained from one acquisition to the next. '
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'SpectrumDetectorType': {
        'values': [
            {
                'documentation': {
                    'description': ' The detector is disabled.'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The middle sample in the bucket is detected.'
                },
                'name': 'SAMPLE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The maximum value of the samples within the bucket is detected if the signal only rises or if the signal only falls. If the signal, within a bucket, both rises and falls, then the maximum and minimum values of the samples are detected in alternate buckets.'
                },
                'name': 'NORMAL',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The maximum value of the samples in the bucket is detected.'
                },
                'name': 'PEAK',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The minimum value of the samples in the bucket is detected.'
                },
                'name': 'NEGATIVE_PEAK',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' The average RMS of all the samples in the bucket is detected.'
                },
                'name': 'AVERAGE_RMS',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' The average voltage of all the samples in the bucket is detected. '
                },
                'name': 'AVERAGE_VOLTAGE',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' The average log of all the samples in the bucket is detected.'
                },
                'name': 'AVERAGE_LOG',
                'value': 7
            }
        ]
    },
    'SpectrumFftWindow': {
        'values': [
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is shorter than the window length. You can also use this window type to separate two tones with frequencies close to each other but with almost equal amplitudes.  '
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measures single-tone amplitudes accurately.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is longer than the window length. You can also use this window type to provide better frequency resolution for noise measurements.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Analyzes closely-spaced sine waves.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Provides a good balance of spectral leakage, frequency resolution, and amplitude attenuation. Hence, this windowing is useful for time-frequency analysis.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Analyzes single tone because it has a low maximum side lobe level and a high side lobe roll-off rate. '
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Useful as a good general purpose window, having side lobe rejection greater than 90 dB and having a moderately wide main lobe. '
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Separates two tones with frequencies close to each other but with widely-differing amplitudes. '
                },
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'SpectrumMeasurementMode': {
        'values': [
            {
                'documentation': {
                    'description': ' Spectrum measurement is performed on the acquired signal. '
                },
                'name': 'MEASURE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Manual noise calibration of the signal analyzer is performed for the spectrum measurement.'
                },
                'name': 'CALIBRATE_NOISE_FLOOR',
                'value': 1
            }
        ]
    },
    'SpectrumNoiseCalibrationAveragingAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' RFmx uses the averages that you set for the RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_AVERAGING_COUNT attribute.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' RFmx uses a noise calibration averaging count of 32.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpectrumNoiseCalibrationMode': {
        'values': [
            {
                'documentation': {
                    'description': ' When you set the RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_MODE attribute to RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR, you can initiate instrument noise calibration for the spectrum measurement manually. When you set the RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_MODE attribute to RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_MODE_MEASURE, you can initiate the spectrum measurement manually.'
                },
                'name': 'MANUAL',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' When you set the RFMXSPECAN_ATTR_SPECTRUM_NOISE_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_ENABLED_TRUE, RFmx sets the Input Isolation Enabled attribute to Enabled and calibrates the intrument noise in the current state of the instrument. RFmx then resets the Input Isolation Enabled attribute and performs the spectrum measurement, including compensation for noise from the instrument. RFmx skips noise calibration in this mode if valid noise calibration data is already cached. When you set the RFMXSPECAN_ATTR_SPECTRUM_NOISE_COMPENSATION_ENABLED attribute to RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_ENABLED_FALSE, RFmx does not calibrate instrument noise and performs only the spectrum measurement without compensating for the noise from the instrument.'
                },
                'name': 'AUTO',
                'value': 1
            }
        ]
    },
    'SpectrumNoiseCompensationEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables compensation of the spectrum for the noise floor of the signal analyzer.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables compensation of the spectrum for the noise floor of the signal analyzer. The noise floor of the signal analyzer is measured for the RF path used by the Spectrum measurement and cached for future use. If signal analyzer or measurement parameters change, noise floors are measured again.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpectrumNoiseCompensationType': {
        'values': [
            {
                'documentation': {
                    'description': ' Compensates for noise from the analyzer and the 50 ohm termination. The measured power values are in excess of the thermal noise floor.'
                },
                'name': 'ANALYZER_AND_TERMINATION',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Compensates for the analyzer noise only.'
                },
                'name': 'ANALYZER_ONLY',
                'value': 1
            }
        ]
    },
    'SpectrumPowerUnits': {
        'values': [
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm.'
                },
                'name': 'DBM',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBm/Hz.'
                },
                'name': 'DBM_PER_HZ',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBW.'
                },
                'name': 'DBW',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBV.'
                },
                'name': 'DBV',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBmV.'
                },
                'name': 'DBMV',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in dBuV.'
                },
                'name': 'DBUV',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in W.'
                },
                'name': 'WATTS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in volts.'
                },
                'name': 'VOLTS',
                'value': 7
            },
            {
                'documentation': {
                    'description': ' The absolute powers are reported in volts2.'
                },
                'name': 'VOLTS_SQUARED',
                'value': 8
            }
        ]
    },
    'SpectrumRbwAutoBandwidth': {
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
    'SpectrumRbwFilterBandwidthDefinition': {
        'values': [
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 3dB bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_TYPE attribute to RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_TYPE_FFT_BASED, RBW is the 3dB bandwidth of the window specified by the RFMXSPECAN_ATTR_SPECTRUM_FFT_WINDOW attribute.'
                },
                'name': '3_DB',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 6dB bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_TYPE attribute to FFT Based, RBW is the 6dB bandwidth of the window specified by the RFMXSPECAN_ATTR_SPECTRUM_FFT_WINDOW attribute.'
                },
                'name': '6_DB',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the spectrum bin width computed using FFT when you set the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_TYPE attribute to FFT Based.'
                },
                'name': 'BIN_WIDTH',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the ENBW bandwidth of the RBW filter. When you set the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_TYPE attribute to FFT Based, RBW is the ENBW  bandwidth of the window specified by the RFMXSPECAN_ATTR_SPECTRUM_FFT_WINDOW attribute.'
                },
                'name': 'ENBW',
                'value': 3
            }
        ]
    },
    'SpectrumRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' No RBW filtering is performed.'
                },
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a Gaussian response.'
                },
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a flat response.'
                },
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'SpectrumSweepTimeAuto': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement uses the sweep time that you specify in the RFMXSPECAN_ATTR_SPECTRUM_SWEEP_TIME_INTERVAL attribute. '
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement calculates the sweep time based on the value of the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_BANDWIDTH attribute.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpectrumVbwFilterAutoBandwidth': {
        'values': [
            {
                'documentation': {
                    'description': ' Specify the video bandwidth in the RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_BANDWIDTH attribute. The RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_VBW_TO_RBW_RATIO attribute is disregarded in this mode.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Specify video bandwidth in terms of the VBW to RBW ratio. The value of the video bandwidth is then computed by using the RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_VBW_TO_RBW_RATIO attribute and the RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_BANDWIDTH attribute. The value of the RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_BANDWIDTH attribute is disregarded in this mode.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpurAbsoluteLimitMode': {
        'values': [
            {
                'name': 'MANUAL',
                'value': 0
            },
            {
                'name': 'COUPLE',
                'value': 1
            }
        ]
    },
    'SpurAmplitudeCorrectionType': {
        'values': [
            {
                'documentation': {
                    'description': ' All the frequency bins in the spectrum are compensated with a single external attenuation value that corresponds to the RF center frequency.'
                },
                'name': 'RF_CENTER_FREQUENCY',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' An individual frequency bin in the spectrum is compensated with the external attenuation value corresponding to that frequency.'
                },
                'name': 'SPECTRUM_FREQUENCY_BIN',
                'value': 1
            }
        ]
    },
    'SpurAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The Spur measurement uses the RFMXSPECAN_ATTR_SPUR_AVERAGING_COUNT attribute as the number of acquisitions over which the Spur measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpurAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power spectrum is linearly averaged. RMS averaging reduces signal fluctuations but not the noise floor.  '
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power spectrum is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power spectrum is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The peak power in the spectrum at each frequency bin is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The least power in the spectrum at each frequency bin is retained from one acquisition to the next. '
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'SpurFftWindow': {
        'values': [
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is shorter than the window length. You can also use this window type to separate two tones with frequencies close to each other but with almost equal amplitudes.  '
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Measures single-tone amplitudes accurately.'
                },
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Analyzes transients for which duration is longer than the window length. You can also use this window type to provide better frequency resolution for noise measurements.'
                },
                'name': 'HANNING',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Analyzes closely-spaced sine waves.'
                },
                'name': 'HAMMING',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' Provides a balance of spectral leakage, frequency resolution, and amplitude attenuation. This windowing is useful for time-frequency analysis.'
                },
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' Analyzes single tone because it has a low maximum side lobe level and a high side lobe roll-off rate. '
                },
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' Useful as a good general purpose window, having side lobe rejection greater than 90 dB and having a moderately wide main lobe. '
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' Separates two tones with frequencies close to each other but with widely-differing amplitudes.'
                },
                'name': 'KAISER_BESSEL',
                'value': 7
            }
        ]
    },
    'SpurMeasurementStatus': {
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
    'SpurRangeDetectorType': {
        'values': [
            {
                'documentation': {
                    'description': ' The detector is disabled.'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The middle sample in the bucket is detected.'
                },
                'name': 'SAMPLE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The maximum value of the samples within the bucket is detected if the signal only rises or if the signal only falls. If the signal, within a bucket, both rises and falls, then the maximum and minimum values of the samples are detected in alternate buckets.'
                },
                'name': 'NORMAL',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The maximum value of the samples in the bucket is detected.'
                },
                'name': 'PEAK',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The minimum value of the samples in the bucket is detected.'
                },
                'name': 'NEGATIVE_PEAK',
                'value': 4
            },
            {
                'documentation': {
                    'description': ' The average RMS of all the samples in the bucket is detected.'
                },
                'name': 'AVERAGE_RMS',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' The average voltage of all the samples in the bucket is detected. '
                },
                'name': 'AVERAGE_VOLTAGE',
                'value': 6
            },
            {
                'documentation': {
                    'description': ' The average log of all the samples in the bucket is detected.'
                },
                'name': 'AVERAGE_LOG',
                'value': 7
            }
        ]
    },
    'SpurRangeEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the acquisition of the frequency range.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Enables measurement of Spurs in the frequency range.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpurRangeStatus': {
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
    'SpurRangeVbwFilterAutoBandwidth': {
        'values': [
            {
                'documentation': {
                    'description': ' Specify the video bandwidth in the RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_BANDWIDTH attribute. The Spur VBW to RBW Ratio attribute is disregarded in this mode.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Specify video bandwidth in terms of the VBW to RBW ratio. The value of the video bandwidth is then computed by using the RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_VBW_TO_RBW_RATIO attribute and the RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_BANDWIDTH attribute. The value of the RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_BANDWIDTH attribute is disregarded in this mode.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'SpurRbwAutoBandwidth': {
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
    'SpurRbwFilterBandwidthDefinition': {
        'values': [
            {
                'name': '3_DB',
                'value': 0
            },
            {
                'name': 'BIN_WIDTH',
                'value': 2
            },
            {
                'name': 'ENBW',
                'value': 3
            }
        ]
    },
    'SpurRbwFilterType': {
        'values': [
            {
                'name': 'FFT_BASED',
                'value': 0
            },
            {
                'name': 'GAUSSIAN',
                'value': 1
            },
            {
                'name': 'FLAT',
                'value': 2
            }
        ]
    },
    'SpurSweepTimeAuto': {
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
                'documentation': {
                    'description': ' The minimum quiet time for triggering is the value of the RFMXSPECAN_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION attribute. '
                },
                'name': 'MANUAL',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The measurement computes the minimum quiet time used for triggering.'
                },
                'name': 'AUTO',
                'value': 1
            }
        ]
    },
    'TriggerType': {
        'values': [
            {
                'documentation': {
                    'description': ' No Reference Trigger is configured.'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The Reference Trigger is not asserted until a digital edge is detected. The source of the digital edge is specified using the RFMXSPECAN_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE attribute.'
                },
                'name': 'DIGITAL_EDGE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The Reference Trigger is asserted when the signal changes past the level specified by the slope (rising or falling), which is configured using the RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE attribute.'
                },
                'name': 'IQ_POWER_EDGE',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The Reference Trigger is not asserted until a software trigger occurs. '
                },
                'name': 'SOFTWARE',
                'value': 3
            }
        ]
    },
    'TxpAveragingEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' The measurement is performed on a single acquisition.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The TXP measurement uses the RFMXSPECAN_ATTR_TXP_AVERAGING_COUNT attribute as the number of acquisitions over which the TXP measurement is averaged.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'TxpAveragingType': {
        'values': [
            {
                'documentation': {
                    'description': ' The power trace is linearly averaged.'
                },
                'name': 'RMS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The power trace is averaged in a logarithmic scale.'
                },
                'name': 'LOG',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The square root of the power trace is averaged.'
                },
                'name': 'SCALAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The maximum instantaneous power in the power trace is retained from one acquisition to the next.'
                },
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'documentation': {
                    'description': ' The minimum instantaneous power in the power trace is retained from one acquisition to the next.'
                },
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'TxpRbwFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' The RBW filter has a Gaussian response.'
                },
                'name': 'NONE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The RBW filter has a flat response.'
                },
                'name': 'GAUSSIAN',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' The measurement does not use any RBW filtering.'
                },
                'name': 'FLAT',
                'value': 5
            },
            {
                'documentation': {
                    'description': ' The RRC filter with the roll-off specified by the RFMXSPECAN_ATTR_TXP_RBW_FILTER_ALPHA attribute is used as the RBW filter.'
                },
                'name': 'RRC',
                'value': 6
            }
        ]
    },
    'TxpThresholdEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' All the acquired samples are considered for the TXP measurement.'
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The samples above the threshold level specified in the RFMXSPECAN_ATTR_TXP_THRESHOLD_LEVEL attribute are considered for the TXP measurement.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    },
    'TxpThresholdType': {
        'values': [
            {
                'documentation': {
                    'description': ' The threshold is relative to the peak power of the acquired samples.'
                },
                'name': 'RELATIVE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The threshold is the absolute power, in dBm.'
                },
                'name': 'ABSOLUTE',
                'value': 1
            }
        ]
    },
    'TxpVbwFilterAutoBandwidth': {
        'values': [
            {
                'documentation': {
                    'description': ' Specify the video bandwidth in the RFMXSPECAN_ATTR_TXP_VBW_FILTER_BANDWIDTH attribute. The RFMXSPECAN_ATTR_TXP_VBW_FILTER_VBW_TO_RBW_RATIO attribute is disregarded in this mode. '
                },
                'name': 'FALSE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Specify video bandwidth in terms of the VBW to RBW ratio. The value of the video bandwidth is then computed by using the RFMXSPECAN_ATTR_TXP_VBW_FILTER_VBW_TO_RBW_RATIO attribute and the RFMXSPECAN_ATTR_TXP_RBW_FILTER_BANDWIDTH attribute. The value of the RFMXSPECAN_ATTR_TXP_VBW_FILTER_BANDWIDTH attribute is disregarded in this mode.'
                },
                'name': 'TRUE',
                'value': 1
            }
        ]
    }
}
