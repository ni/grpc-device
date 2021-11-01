enums = {
    'AcquisitionType': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures NI-RFSA for I/Q acquisitions.'
                },
                'name': 'IQ',
                'value': 100
            },
            {
                'documentation': {
                    'description': ' Configures NI-RFSA for spectrum acquisitions.'
                },
                'name': 'SPECTRUM',
                'value': 101
            }
        ]
    },
    'AnalogSlope': {
        'values': [
            {
                'documentation': {
                    'description': ' The trigger asserts when the signal power is rising.'
                },
                'name': 'RISING_SLOPE',
                'value': 1000
            },
            {
                'documentation': {
                    'description': ' The trigger asserts when the signal power is falling.'
                },
                'name': 'FALLING_SLOPE',
                'value': 1001
            }
        ]
    },
    'AveragingMode': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures NI-RFSA to perform no averaging on acquisitions.'
                },
                'name': 'NO_AVERAGING',
                'value': 400
            },
            {
                'documentation': {
                    'description': ' Configures NI-RFSA for root-mean-square (RMS) averaging. RMS averaging reduces signal  fluctuations but not the  noise floor. RMS averaging averages the energy, or power, of the signal. This  averaging prevents noise floor reduction and gives averaged RMS quantities of  single-channel measurements zero phase. RMS averaging for dual-channel  measurements preserves important phase information.'
                },
                'name': 'RMS_AVERAGING',
                'value': 401
            },
            {
                'documentation': {
                    'description': ' Configures NI-RFSA for vector averaging. Vector averaging reduces noise  from synchronous signals. Vector averaging computes the average of complex  quantities directly, which means that it allows separate averaging for real  and imaginary parts. Complex averaging such as vector averaging reduces  noise and usually requires a trigger to improve block-to-block phase coherence.'
                },
                'name': 'VECTOR_AVERAGING',
                'value': 402
            },
            {
                'documentation': {
                    'description': ' Configures NI-RFSA for peak-hold averaging. Peak-hold averaging retains the  RMS peak levels of the averaged quantities. The peak-hold averaging process  performs peak-hold at each frequency bin separately to retain peak RMS levels  from one FFT record to the next.'
                },
                'name': 'PEAK_HOLD_AVERAGING',
                'value': 403
            },
            {
                'documentation': {
                    'description': ' Min Hold averaging'
                },
                'name': 'MIN_HOLD_AVERAGING',
                'value': 404
            },
            {
                'documentation': {
                    'description': ' Scalar averaging'
                },
                'name': 'SCALAR_AVERAGING',
                'value': 405
            },
            {
                'documentation': {
                    'description': ' Log averaging'
                },
                'name': 'LOG_AVERAGING',
                'value': 406
            }
        ]
    },
    'BandwidthType': {
        'values': [
            {
                'documentation': {
                    'description': ' Defines the resolution bandwidth (RBW) in terms of the 3 dB bandwidth of the  window specified by the NIRFSA_ATTR_FFT_WINDOW_TYPE attribute.'
                },
                'name': 'RBW_3_DB',
                'value': 300
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the 6 dB bandwidth of the window specified by the  NIRFSA_ATTR_FFT_WINDOW_TYPE attribute.'
                },
                'name': 'RBW_6_DB',
                'value': 301
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the display resolution, which is the ratio of the  sampling frequency to the number of samples that you acquire.'
                },
                'name': 'RBW_BIN_WIDTH',
                'value': 302
            },
            {
                'documentation': {
                    'description': ' Defines the RBW in terms of the equivalent noise bandwidth  (ENBW) of the window specified by the NIRFSA_ATTR_FFT_WINDOW_TYPE attribute.'
                },
                'name': 'RBW_ENBW',
                'value': 303
            }
        ]
    },
    'CalIFAttenTableSelection': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the standard IF attenuation table is used for the external calibration.'
                },
                'name': 'EXT_CAL_IF_ATTENUATION_TABLE_STANDARD',
                'value': 2900
            },
            {
                'documentation': {
                    'description': ' Specifies that the adjacent channel power ratio (ACPR) IF attenuation table is used for the  external calibration. You can only select this value if you set the  NIRFSA_ATTR_CAL_IF_FILTER_SELECTION attribute to NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_1  or NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_2. '
                },
                'name': 'EXT_CAL_IF_ATTENUATION_TABLE_ACPR',
                'value': 2901
            }
        ]
    },
    'CalIFFilterSelection': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the 5 MHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_1',
                'value': 2100
            },
            {
                'documentation': {
                    'description': ' Specifies that the through filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_2',
                'value': 2101
            },
            {
                'documentation': {
                    'description': ' Specifies that the 300 kHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_3',
                'value': 2102
            },
            {
                'documentation': {
                    'description': ' Specifies that the 20 MHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_4',
                'value': 2103
            },
            {
                'documentation': {
                    'description': ' Specifies that the 1.4 MHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_5',
                'value': 2104
            },
            {
                'documentation': {
                    'description': ' Specifies that the 425 kHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_6',
                'value': 2105
            },
            {
                'documentation': {
                    'description': ' Specifies that the 110 kHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_7',
                'value': 2106
            },
            {
                'documentation': {
                    'description': ' Specifies that the 30 kHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_8',
                'value': 2107
            },
            {
                'documentation': {
                    'description': ' Specifies that the 100 MHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_9',
                'value': 2108
            },
            {
                'documentation': {
                    'description': ' Specifies that the 320 MHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_10',
                'value': 2109
            },
            {
                'documentation': {
                    'description': ' Specifies that the 1 GHz filter path is used during calibration.'
                },
                'name': 'EXT_CAL_IF_FILTER_PATH_11',
                'value': 2110
            }
        ]
    },
    'CalToneMode': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the calibration tone for the associated path.'
                },
                'name': 'DISABLED',
                'value': 2700
            },
            {
                'documentation': {
                    'description': ' Injects the calibration tone into the low band RF path.'
                },
                'name': 'LOWBAND_RF',
                'value': 2701
            },
            {
                'documentation': {
                    'description': ' Injects the calibration tone into the high band RF path.'
                },
                'name': 'HIGHBAND_RF',
                'value': 2702
            },
            {
                'documentation': {
                    'description': ' Injects the calibration tone into the high band IF path.'
                },
                'name': 'HIGHBAND_IF',
                'value': 2703
            },
            {
                'documentation': {
                    'description': ' Injects the calibration tone into the low band RF path (bypass the ALC).'
                },
                'name': 'LOWBAND_RF_WITHOUT_ALC',
                'value': 2704
            },
            {
                'documentation': {
                    'description': ' Injects the calibration tone into the high band RF path (through the Comb Generator).'
                },
                'name': 'COMB_GENERATOR',
                'value': 2705
            }
        ]
    },
    'ChannelCoupling': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the RF input channel is AC-coupled. For low frequencies  (less than 10 MHz), accuracy decreases because NI-RFSA does not calibrate the configuration.'
                },
                'name': 'AC',
                'value': 3001
            },
            {
                'documentation': {
                    'description': ' Specifies that the RF input channel is DC-coupled. NI-RFSA enforces a minimum  RF attenuation for device protection.'
                },
                'name': 'DC',
                'value': 3002
            }
        ]
    },
    'ConditioningCalToneMode': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the calibration tone for the associated path.'
                },
                'name': 'DISABLED',
                'value': 2700
            },
            {
                'documentation': {
                    'description': ' Injects the calibration tone into the low band RF path.'
                },
                'name': 'LOWBAND_RF',
                'value': 2701
            },
            {
                'documentation': {
                    'description': ' Injects the calibration tone into the high band RF path.'
                },
                'name': 'HIGHBAND_RF',
                'value': 2702
            }
        ]
    },
    'DeembeddingType': {
        'values': [
            {
                'documentation': {
                    'description': ' De-embedding is not applied to the measurement.'
                },
                'name': 'NONE',
                'value': 3900
            },
            {
                'documentation': {
                    'description': ' De-embeds the measurement using only the gain term.'
                },
                'name': 'SCALAR',
                'value': 3901
            },
            {
                'documentation': {
                    'description': ' De-embeds the measurement using the gain term and the reflection term.'
                },
                'name': 'VECTOR',
                'value': 3902
            }
        ]
    },
    'DeviceResponse': {
        'values': [
            {
                'name': 'DOWNCONVERTER_IF_RESPONSE',
                'value': 2800
            },
            {
                'name': 'DOWNCONVERTER_RF_RESPONSE',
                'value': 2801
            },
            {
                'name': 'DOWNCONVERTER_COMBINED_RESPONSE',
                'value': 2802
            },
            {
                'name': 'VSA_IF_RESPONSE',
                'value': 2803
            },
            {
                'name': 'VSA_COMBINED_RESPONSE',
                'value': 2804
            }
        ]
    },
    'DigitalEdge': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSA detects a rising edge.'
                },
                'name': 'RISING_EDGE',
                'value': 900
            },
            {
                'documentation': {
                    'description': ' NI-RFSA detects a falling edge.'
                },
                'name': 'FALLING_EDGE',
                'value': 901
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
                'name': 'RTSI0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'RTSI1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'RTSI2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'RTSI3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'RTSI4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'RTSI5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'RTSI6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'RTSI7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            }
        ]
    },
    'DigitizerSampleClockOutTerminal': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The Sample clock is not exported.'
                },
                'name': 'NONE',
                'value': 'None'
            },
            {
                'documentation': {
                    'description': ' Export the clock on the CLK OUT terminal on the Digitizer.'
                },
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            }
        ]
    },
    'DigitizerSampleClockTimebaseSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The digitizer uses its onboard clock as the Sample clock timebase.'
                },
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' The digitizer uses the signal present at the CLK IN connector as the  Sample clock timebase.'
                },
                'name': 'CLK_IN',
                'value': 'ClkIn'
            },
            {
                'documentation': {
                    'description': ' The digitizer uses the signal generated on the 100 MHz REF OUT terminal on the PXIe-5653 as the  Sample clock timebase. This value is supported only for PXIe-5603 and PXIe-5665.'
                },
                'name': 'LO_REF_CLK',
                'value': 'LORefClk'
            },
            {
                'documentation': {
                    'description': ' The digitizer uses the signal present at the PXI Star line as the  Sample clock timebase.'
                },
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            }
        ]
    },
    'DownconverterFrequencyOffsetMode': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSA places the downconverter center frequency outside of the signal bandwidth if the  NIRFSA_ATTR_SIGNAL_BANDWIDTH attribute has been set and can be avoided. '
                },
                'name': 'AUTOMATIC',
                'value': 1903
            },
            {
                'documentation': {
                    'description': ' NI-RFSA places the downconverter center frequency outside of the signal bandwidth if the NIRFSA_ATTR_SIGNAL_BANDWIDTH  attribute has been set and can be avoided. NI-RFSA returns an error if the NIRFSA_ATTR_SIGNAL_BANDWIDTH attribute has  not been set, or if the signal bandwidth is too large. '
                },
                'name': 'ENABLED',
                'value': 1901
            },
            {
                'documentation': {
                    'description': ' NI-RFSA uses the offset that you specified with the NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET or  NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY attributes. '
                },
                'name': 'USER_DEFINED',
                'value': 1904
            }
        ]
    },
    'DownconverterPreselectorEnabledAttr': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the preselector.'
                },
                'name': 'DISABLED',
                'value': 2600
            },
            {
                'documentation': {
                    'description': ' The preselector is automatically enabled when it is in the signal path and is automatically  disabled when it is not in the signal path. Only devices with a preselector on the downconverter support this option.  Use the NIRFSA_ATTR_PRESELECTOR_PRESENT attribute to determine if the downconverter has a preselector.'
                },
                'name': 'ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 2601
            },
            {
                'documentation': {
                    'description': ' Enables the preselector. If the preselector is not in a signal path or if the preselector is not supported on the device,  NI-RFSA returns an error. Select the NIRFSA_VAL_PRESELECTOR_ENABLED_WHEN_IN_SIGNAL_PATH whenever possible avoid an error.'
                },
                'name': 'ENABLED',
                'value': 2602
            }
        ]
    },
    'EnabledAttr': {
        'values': [
            {
                'documentation': {
                    'description': ' Disable.'
                },
                'name': 'DISABLED',
                'value': 1900
            },
            {
                'documentation': {
                    'description': ' Enable.'
                },
                'name': 'ENABLED',
                'value': 1901
            }
        ]
    },
    'ExportTerminal': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The signal is not exported.'
                },
                'name': 'DO_NOT_EXPORT',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PFI 0.  For the PXIe-5841 with PXIe-5655, the signal is exported to the PXIe-5841 PFI 0.'
                },
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PFI 1.'
                },
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 0.'
                },
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 1.'
                },
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 2.'
                },
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 3.'
                },
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 4.'
                },
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 5.'
                },
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 6.'
                },
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to PXI trigger line 7.'
                },
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to the PXI star trigger line.'
                },
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on the PXIe DStar C trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.'
                },
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to the PXI/PXIe-5652 Ref Out.'
                },
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to the PXI/PXIe-5652 Ref Out 2.'
                },
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'documentation': {
                    'description': ' The signal is exported to the PXIe-5622 Clk Out.'
                },
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            }
        ]
    },
    'FetchRelativeTo': {
        'values': [
            {
                'documentation': {
                    'description': ' Fetching occurs relative to the most recently acquired data. The value of the  NIRFSA_ATTR_FETCH_OFFSET attribute must be negative.'
                },
                'name': 'MOST_RECENT_SAMPLE',
                'value': 700
            },
            {
                'documentation': {
                    'description': ' Fetching occurs at the first sample acquired by the device. If the device wraps  its buffer, the first sample is no longer available. In this case, NI-RFSA  returns an error if the fetch offset is in the overwritten data.'
                },
                'name': 'FIRST_SAMPLE',
                'value': 701
            },
            {
                'documentation': {
                    'description': ' Fetching occurs relative to the Reference trigger. This value behaves like  NIRFSA_VAL_FIRST_SAMPLE if no Reference trigger is configured.'
                },
                'name': 'REF_TRIGGER',
                'value': 702
            },
            {
                'documentation': {
                    'description': ' Fetching occurs relative to the first pretrigger sample acquired. This value  behaves like NIRFSA_VAL_FIRST_SAMPLE if no Reference trigger is configured.'
                },
                'name': 'FIRST_PRETRIGGER_SAMPLE',
                'value': 703
            },
            {
                'documentation': {
                    'description': ' Fetching occurs after the last fetched sample.'
                },
                'name': 'CURRENT_READ_POSITION',
                'value': 704
            }
        ]
    },
    'FftWindowType': {
        'values': [
            {
                'documentation': {
                    'description': ' No window is applied.'
                },
                'name': 'UNIFORM',
                'value': 500
            },
            {
                'documentation': {
                    'description': ' The Hanning window is useful for analyzing transients longer than the time  duration of the window, and also for general-purpose applications. A Hanning  window is applied to the waveform using the  following equation:\n y[i] = 0.5 x x[i] x [1-cos(w)]\n where w = (2 pi)i/n and n = waveform size. '
                },
                'name': 'HANNING',
                'value': 501
            },
            {
                'documentation': {
                    'description': ' A Hamming window is applied to the waveform using the following equation: \n y[i] = x[i] [0.54 - 0.46cos(w)] \n where w = (2 pi)i/n and n = the waveform size.\n\n  the Hamming window does not get as close to zero near the edges as does the  Hanning window. ',
                    'note': ' Hanning and Hamming windows are somewhat similar. However, in the time domain, '
                },
                'name': 'HAMMING',
                'value': 502
            },
            {
                'documentation': {
                    'description': ' A Blackman-Harris window is applied to the waveform using the following  equation:\n y[i] = x[i] x [0.42323 - 0.49755cos(w) + 0.07922cos(2w)]\n where w = (2)i/n and n = the waveform size. '
                },
                'name': 'BLACKMAN_HARRIS',
                'value': 503
            },
            {
                'documentation': {
                    'description': ' An Exact Blackman window is applied to the waveform using the following  equation:\n y[i] = x[i] x [a0 - a1cos(w) + a2cos(2w)]\n where    w = (2 pi)i/n\n          n = the waveform size\n \t\ta0 = 7938/18608\n \t\ta1 = 9240/18608\n \t\ta2 = 1430/18608 '
                },
                'name': 'EXACT_BLACKMAN',
                'value': 504
            },
            {
                'documentation': {
                    'description': ' A Blackman window is useful for analyzing transient signals, and provides  similar windowing to Hanning and Hamming windows but adds one additional  cosine term to reduce ripple. A Blackman window is applied to the waveform  using the following equation:\n y[i] = x[i] x [0.42 - 0.50cos(w) + 0.08cos(2w)]\n where w = (2 pi)i/n and n = the waveform size. '
                },
                'name': 'BLACKMAN',
                'value': 505
            },
            {
                'documentation': {
                    'description': ' The fifth-order Flat Top window has the best amplitude accuracy of all the  window functions. The increased amplitude accuracy (+/-0.02 dB for signals  exactly between integral cycles) is at the expense of frequency selectivity.  The Flat Top window is most useful in accurately measuring the amplitude of  single frequency components with little nearby spectral energy in the signal.\n A fifth-order Flat Top window is applied to the waveform using the following equation:\n y[i] = x[i] x [a0 - a1cos(w) + a2cos(2w) - a3cos(3w) + a4cos(4w)]\n where w = (2 pi)i/n\n \t   n = the waveform size\n       a0 = 0.215578948\n       a1 = 0.41663158\n \t   a2 = 0.277263158\n \t   a3 = 0.083578947\n \t   a4 = 0.006947368 '
                },
                'name': 'FLAT_TOP',
                'value': 506
            },
            {
                'documentation': {
                    'description': ' A 4-term Blackman-Harris window is a general purpose window; it has side-lobe rejection  in the upper 90 dB, with moderately wide side lobe.\n\n A 4-term Blackman Harris window is applied to the waveform using the following  equation:\n y[i] = x[i] x [0.422323 - 0.49755cos(w) + 0.07922cos(2w)]\n where w = (2 pi)i/n and n = the waveform size. '
                },
                'name': '4_TERM_BLACKMAN_HARRIS',
                'value': 507
            },
            {
                'documentation': {
                    'description': ' A 7-term Blackman-Harris window has the highest dynamic range;  it is ideal for signal-to-noise ratio applications.\n\n A 7-term Blackman Harris window is applied to the waveform using the following  equation:\n y[i] = x[i] x [a0 - a1cos(w) + a2cos(2w) - a3cos(3w) + a4cos(4w) - a5cos(5w) + a6cos(6w)]\n where w = (2 pi)i/n\n n is the waveform size\n a0 = 0.27105140069342\n a1 = 0.43329793923448\n a2 = 0.21812299954311\n a3 = 0.06592544638803\n a4 = 0.01081174209837\n a5 = 0.00077658482522\n a6 = 0.00001388721735 '
                },
                'name': '7_TERM_BLACKMAN_HARRIS',
                'value': 508
            },
            {
                'documentation': {
                    'description': ' The Low Side Lobe window further reduces the size of the main lobe.  Refer to the NIRFSA_ATTR_FFT_WINDOW_TYPE topic in the NI RF Vector Signal Analyzers  Help for the equation that defines the Low Side Lobe window. '
                },
                'name': 'LOW_SIDE_LOBE',
                'value': 509
            },
            {
                'documentation': {
                    'description': ' Gaussian Window.  '
                },
                'name': 'GAUSSIAN',
                'value': 510
            },
            {
                'documentation': {
                    'description': ' Kaiser-Bessel window.  '
                },
                'name': 'KAISER_BESSEL',
                'value': 511
            }
        ]
    },
    'FrequencySettlingUnits': {
        'values': [
            {
                'documentation': {
                    'description': ' Specify frequency settling time in parts per million (PPM).'
                },
                'name': 'PPM',
                'value': 2000
            },
            {
                'documentation': {
                    'description': ' Specify frequency settling in time after lock (seconds).'
                },
                'name': 'SECONDS_AFTER_LOCK',
                'value': 2001
            },
            {
                'documentation': {
                    'description': ' Specify frequency settling time after I/O (seconds).'
                },
                'name': 'SECONDS_AFTER_IO',
                'value': 2002
            }
        ]
    },
    'GeneralTriggerType': {
        'values': [
            {
                'documentation': {
                    'description': ' The trigger is not configured.'
                },
                'name': 'NONE',
                'value': 600
            },
            {
                'documentation': {
                    'description': ' The trigger is configured to be a digital edge trigger.'
                },
                'name': 'DIGITAL_EDGE',
                'value': 601
            },
            {
                'documentation': {
                    'description': ' The trigger is configured to be a software trigger. You can assert the software  trigger by calling the niRFSA_SendSoftwareEdgeTrigger function.'
                },
                'name': 'SOFTWARE_EDGE',
                'value': 604
            }
        ]
    },
    'IfFilter': {
        'values': [
            {
                'documentation': {
                    'description': ' Uses the 187.5 MHz wide bandwidth filter.'
                },
                'name': '187_5_MHZ_WIDE',
                'value': 1400
            },
            {
                'documentation': {
                    'description': ' Uses the 187.5 MHz narrow bandwidth filter.'
                },
                'name': '187_5_MHZ_NARROW',
                'value': 1401
            },
            {
                'documentation': {
                    'description': ' Uses the 53 MHz filter.'
                },
                'name': '53_MHZ',
                'value': 1402
            },
            {
                'documentation': {
                    'description': ' Bypasses the IF filter.'
                },
                'name': 'BYPASS',
                'value': 1403
            }
        ]
    },
    'InputPort': {
        'values': [
            {
                'documentation': {
                    'description': ' Enables the RF IN port.'
                },
                'name': 'RF_IN',
                'value': 2000
            },
            {
                'documentation': {
                    'description': ' Enables the I/Q IN port.'
                },
                'name': 'IQ_IN',
                'value': 2001
            },
            {
                'documentation': {
                    'description': ' Enables the CAL IN port.'
                },
                'name': 'CAL_IN',
                'value': 2002
            },
            {
                'documentation': {
                    'description': ' Enables the I terminals of the I/Q IN port.'
                },
                'name': 'I_ONLY',
                'value': 2003
            }
        ]
    },
    'IqInPortTermConfig': {
        'values': [
            {
                'documentation': {
                    'description': ' Sets the terminal configuration to Differential.'
                },
                'name': 'DIFFERENTIAL',
                'value': 2100
            },
            {
                'documentation': {
                    'description': ' Sets the terminal configuration to Single-Ended.'
                },
                'name': 'SINGLE_ENDED',
                'value': 2101
            }
        ]
    },
    'LinearInterpolationFormat': {
        'values': [
            {
                'name': 'REAL_AND_IMAGINARY',
                'value': 4000
            },
            {
                'name': 'MAGNITUDE_AND_PHASE',
                'value': 4001
            },
            {
                'name': 'MAGNITUDE_DB_AND_PHASE',
                'value': 4002
            }
        ]
    },
    'LoInjectionSideValues': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures the LO signal that the NI-RFSA device generates at a frequency higher than  the RF frequency. This LO frequency is given by the formula fLO = fRF + fIF.'
                },
                'name': 'HIGH_SIDE',
                'value': 1300
            },
            {
                'documentation': {
                    'description': ' Configures the LO signal that the NI-RFSA device generates at a frequency lower than  the RF frequency. This LO frequency is given by the formula fLO = fRF - fIF.'
                },
                'name': 'LOW_SIDE',
                'value': 1301
            }
        ]
    },
    'LoPathSelection': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the LO path 1 is used. This value is the default. '
                },
                'name': 'EXT_CAL_LO_PATH_1',
                'value': 2300
            },
            {
                'documentation': {
                    'description': ' Specifies that the LO path 2 is used.'
                },
                'name': 'EXT_CAL_LO_PATH_2',
                'value': 2301
            },
            {
                'documentation': {
                    'description': ' Specifies that the LO path 3 is used.'
                },
                'name': 'EXT_CAL_LO_PATH_3',
                'value': 2302
            },
            {
                'documentation': {
                    'description': ' Specifies that the LO path 4 is used.'
                },
                'name': 'EXT_CAL_LO_PATH_4',
                'value': 2303
            },
            {
                'documentation': {
                    'description': ' Specifies that the LO path 5 is used.'
                },
                'name': 'EXT_CAL_LO_PATH_5',
                'value': 2304
            }
        ]
    },
    'LoSourceSelection': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the onboard synthesizer is used to generate the LO signal that downconverts the RF input signal. \n\n PXIe-5831—This configuration uses the onboard LO of the PXIe-3622, using the LO2 stage. \n PXIe-5831 with PXIe-5653—This configuration uses the onboard LO of the PXIe5653 when associated with the PXIe-3622. \n PXIe-5840 with PXIe-5653—If the center frequency is greater than or equal to 3.2 GHz,  this configuration uses the PXIe-5653 LO source. For frequencies less than 3.2 GHz, this configuration  uses the PXIe-5840 internal LO. If NI-RFSA is operating in Spectrum mode, this configuration uses the  PXIe-5840 internal LO regardless of the frequency. \n PXIe-5841 with PXIe-5655—This configuration uses the onboard LO of the PXIe-5655.'
                },
                'name': 'ONBOARD',
                'value': 'Onboard'
            },
            {
                'documentation': {
                    'description': ' Specifies that the LO source used to downconvert the RF input signal is  connected to the LO IN connector on the front panel.'
                },
                'name': 'LO_IN',
                'value': 'LO_In'
            },
            {
                'documentation': {
                    'description': ' Uses the PXIe-5831/5840 internal LO as the LO source. This value is valid on only the PXIe-5840 with PXIe-5653 or PXIe-5831 with PXIe-5653.'
                },
                'name': 'LO_SOURCE_SECONDARY',
                'value': 'Secondary'
            },
            {
                'documentation': {
                    'description': ' Uses the same internal LO during NI-RFSA and NI-RFSG sessions. NI-RFSA selects an internal synthesizer  and the synthesizer signal is switched to both the RF Out and RF In mixers. This value is valid on only the PXIe-5830/5831/5841 with PXIe-5655.'
                },
                'name': 'LO_SOURCE_SG_SA_SHARED',
                'value': 'SG_SA_Shared'
            }
        ]
    },
    'LoYIGMainCoilDrive': {
        'values': [
            {
                'documentation': {
                    'description': ' Adjusts the YIG main coil on the LO for an underdamped response.'
                },
                'name': 'NORMAL',
                'value': 2400
            },
            {
                'documentation': {
                    'description': ' Adjusts the YIG main coil on the LO for an overdamped response.'
                },
                'name': 'FAST',
                'value': 2401
            }
        ]
    },
    'LoopBandwidth': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the downconverter module uses a narrow loop bandwidth.'
                },
                'name': 'NARROW',
                'value': 800
            },
            {
                'documentation': {
                    'description': ' Specifies that the downconverter module uses a medium loop bandwidth.'
                },
                'name': 'MEDIUM',
                'value': 801
            },
            {
                'documentation': {
                    'description': ' Specifies that the downconverter module uses a wide loop bandwidth.'
                },
                'name': 'WIDE',
                'value': 802
            }
        ]
    },
    'NotchFilterEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies the notch filter will not be used.'
                },
                'name': 'DISABLED',
                'value': 3400
            },
            {
                'documentation': {
                    'description': ' Specifies that a notch filter will be used if available.'
                },
                'name': 'ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 3401
            },
            {
                'documentation': {
                    'description': ' Specifies that the notch filter will be used.'
                },
                'name': 'ENABLED',
                'value': 3402
            }
        ]
    },
    'OverflowErrorReporting': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures NI-RFSA to return a warning when an ADC or onboard signal processing (OSP) overflow occurs.'
                },
                'name': 'WARNING',
                'value': 1301
            },
            {
                'documentation': {
                    'description': ' Configures NI-RFSA to not return an error or a warning when an ADC or OSP overflow occurs.'
                },
                'name': 'DISABLED',
                'value': 1302
            }
        ]
    },
    'PowerSpectrumUnits': {
        'values': [
            {
                'documentation': {
                    'description': ' Units are dB with reference to 1 milliwatt.'
                },
                'name': 'DBM',
                'value': 200
            },
            {
                'documentation': {
                    'description': ' Units are in volts squared.'
                },
                'name': 'VOLTS_SQUARED',
                'value': 201
            },
            {
                'documentation': {
                    'description': ' Units are dB with reference to 1 millivolt.'
                },
                'name': 'DBMV',
                'value': 202
            },
            {
                'documentation': {
                    'description': ' Units are dB with reference to 1 microvolt.'
                },
                'name': 'DBUV',
                'value': 203
            },
            {
                'documentation': {
                    'description': ' Units are in volts.'
                },
                'name': 'VOLTS',
                'value': 204
            },
            {
                'documentation': {
                    'description': ' Units are in watts.'
                },
                'name': 'WATTS',
                'value': 205
            }
        ]
    },
    'PulseWidthUnitType': {
        'values': [
            {
                'documentation': {
                    'description': ' Units are seconds.'
                },
                'name': 'SECONDS',
                'value': 6200
            },
            {
                'documentation': {
                    'description': ' Units are clock periods.'
                },
                'name': 'CLOCK_PERIODS',
                'value': 6201
            }
        ]
    },
    'PxiChassisClk10Source': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The device does not drive the PXI 10 MHz backplane Reference clock.'
                },
                'name': 'NONE',
                'value': 'None'
            },
            {
                'documentation': {
                    'description': ' The device drives the PXI 10 MHz backplane Reference clock with the PXI-5600  onboard clock. You must connect the 10 MHz OUT connector to the PXI 10 MHz  I/O connector on the PXI-5600 front panel to use this option.'
                },
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' The device drives the PXI 10 MHz backplane Reference clock with the reference  source attached to the PXI-5600 FREQ REF IN connector. You must connect the  10 MHz OUT connector to the PXI 10 MHz I/O connector on the PXI-5600 front  panel to use this option.'
                },
                'name': 'REF_IN',
                'value': 'RefIn'
            }
        ]
    },
    'RefClockOutTerminal': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The Reference clock is not exported.'
                },
                'name': 'NONE',
                'value': 'None'
            },
            {
                'documentation': {
                    'description': ' Export the clock on the REF IN/OUT terminal on the 5652 or on the REF OUT terminals on the PXIe-5653,  or the REF OUT terminal on the PXIe-5644/5645/5646, PXIe-5694, and PXIe-5820/5830/5831/5840/5841.'
                },
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'documentation': {
                    'description': ' Export the clock on the REF OUT2 terminal on the LO. This connector does not  exist on some versions of the PXI/PXIe-5652.'
                },
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'documentation': {
                    'description': ' Export the clock on the CLK OUT terminal on the Digitizer.'
                },
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            },
            {
                'documentation': {
                    'description': ' Export the RF Condiioner REF OUT terminal on the PXIe-5694. This value is  valid only for the PXIe-5667.'
                },
                'name': 'IF_COND_REF_OUT',
                'value': 'IFCondRefOut'
            }
        ]
    },
    'RefClockSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' No Reference clock is required for the current device configuration. This value is valid only for the PXIe-5694. '
                },
                'name': 'NONE',
                'value': 'None'
            },
            {
                'documentation': {
                    'description': ' PXI-5661-NI-RFSA locks the NI-RFSA device to the PXI-5600 RF downconverter onboard clock. \n\n PXIe-5663/5663E-NI-RFSA locks the PXIe-5663/5663E to the PXI/PXIe-5652 LO source onboard clock. Connect  the REF OUT2 connector (if it exists) on the PXI/PXIe-5652 to the CLK IN terminal on the  PXIe-5622. On versions of the PXIe-5663/5663E that lack a REF OUT2 connector on the PXI/PXIe-5652,  connect the REF IN/OUT connector on the PXI/PXIe-5652 to the CLK IN terminal on the PXIe-5622. \n\n PXIe-5665-NI-RFSA locks the PXIe-5665 to the PXIe-5653 LO source onboard clock. Connect the 100 MHz REF OUT  terminal on the PXIe-5653 to the CLK IN terminal on the PXIe-5622. \n\n PXIe-5667-NI-RFSA locks the PXIe-5667 to the PXIe-5653 LO source onboard clock.  Connect the 100 MHz REF OUT terminal on the PXIe-5653 to the CLK IN terminal on the PXIe-5622,  and connect the 10 MHZ REF OUT terminal on the PXIe-5653 to the REF/LO IN connector on the PXIe-5694.\n\n PXIe-5668-Lock the PXIe-5668 to the PXIe-5653 LO SOURCE onboard clock. Connect the LO2  OUT connector on the PXIe-5606 to the CLK IN connector on the PXIe-5624. \n\n PXIe-5644/5645/5646, PXIe-5820/5840/5841—Lock the NI-RFSA device to its onboard clock. PXIe-5830/5831—For the PXIe-5830, connect the PXIe-5820 REF IN connector to the PXIe3621 REF OUT connector. For the PXIe-5831,  connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector. \n\n PXIe-5831 with PXIe-5653—Connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector. Connect the PXIe-5653 REF OUT (10 MHz)  connector to the PXIe-3622 REF IN connector. \n\n PXIe-5840 with PXIe-5653—Lock to the PXIe-5653 onboard clock. Connect the REF OUT (10 MHz) connector on the  PXIe-5653 to the PXIe-5840 REF IN connector. Configure open NI-RFSG sessions to the device to use NIRFSG_VAL_REF_IN_STR  for the PXIe-5840 or NIRFSG_VAL_REF_IN_2_STR for the PXIe-5840 with PXIe-5653. \n\n PXIe-5841 with PXIe-5655—Lock to the PXIe-5655 onboard clock. Connect the REF OUT connector on  the PXIe-5655 to the PXIe-5841 REF IN connector.'
                },
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' PXI-5661—NI-RFSA locks the NI-RFSA device to the signal at the external FREQ REF IN  connector on the PXI-5600. \n\n PXIe-5663/5663E—Connect the external signal to the PXI/PXIe-5652 REF IN/OUT connector. Connect the  REF OUT2 connector (if it exists) on the PXI/PXIe-5652 to the CLK IN terminal on the PXIe-5622. On  versions of the 5663/5663E that lack a REF OUT2 connector on the PXI/PXIe-5652, this configuration  can only be used in external digitizer mode.\n\n PXIe-5665—Connect the external signal to the PXIe-5653 REF IN connector. Connect the 100 MHz REF OUT  terminal on the PXIe-5653 to the CLK IN terminal on the PXIe-5622. If your external clock signal frequency is set to a frequency other than 10 MHz,  set the NIRFSA_ATTR_REF_CLOCK_RATE attribute according to the frequency of your external clock signal.\n\n PXIe-5667—Connect the external signal to the PXIe-5653 REF IN connector. Connect the 100 MHz REF OUT terminal  on the PXIe-5653 to the CLK IN terminal on the PXIe-5622, and connect the 10 MHZ REF OUT terminal on  the PXIe-5653 to the REF/LO IN connector on the PXIe-5694. If your external clock signal frequency is  set to a frequency other than 10 MHz, set the NIRFSA_ATTR_REF_CLOCK_RATE attribute according  to the frequency of your external clock signal. \n\n PXIe-5694—Connect the Reference clock signal to the REF/LO IN connector on the PXIe-5694 front panel.\n\n PXIe-5644/5645/5646, PXIe-5820/5840/5841—Lock the NI-RFSA device to the signal at the external REF IN connector. \n PXIe-5830/5831—For the PXIe-5830, connect the PXIe-5820 REF IN connector to the PXIe3621 REF OUT connector.  For the PXIe-5831, connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector.  For the PXIe-5830, lock the external signal to the PXIe-3621 REF IN connector. For the PXIe-5831,  lock the external signal to the PXIe-3622 REF IN connector. \n PXIe-5831 with PXIe-5653—Connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector.  Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXIe-3622 REF IN connector. Lock the external signal to the PXIe-5653 REF IN connector. \n PXIe-5840 with PXIe-5653—Lock to the signal at the REF IN connector on the associated PXIe-5653. Connect the  REF OUT (10 MHz) connector on the PXIe-5653 to the PXIe-5840 REF IN connector. \n PXIe-5841 with PXIe-5655—Lock to the signal at the REF IN connector on the associated PXIe-5655.  Connect the REF OUT connector on the PXIe-5655 to the PXIe-5841 REF IN.'
                },
                'name': 'REF_IN',
                'value': 'RefIn'
            },
            {
                'documentation': {
                    'description': ' PXI-5661-NI-RFSA locks the NI-RFSA device to the PXI backplane clock using the PXI-5600.  You must connect the PXI 10 MHz connector to the REF IN connector on the  PXI-5600 front panel to use this option. \n\n PXIe-5668-Lock the PXIe-5653 to the PXI backplane clock. Connect the PXIe-5606 LO2  OUT to the LO2 IN connector on the PXIe-5624. \n\n PXIe-5644/5645/5646, PXIe-5663/5663E/5665/5667, PXIe-5694, PXIe-5820/5830/5831/5831 with PXIe-5653/5840/5841/5840 with PXIe-5653/5841/5841 with PXIe-5655-Lock the device to the PXI backplane clock. '
                },
                'name': 'PXI_CLK',
                'value': 'PXI_Clk'
            },
            {
                'documentation': {
                    'description': ' PXI-5661-This configuration does not apply to the PXI-5661. \n\n PXIe-5663/5663E-Lock the PXIe-5663/5663E to an external 10 MHz signal.  Connect the external signal to the  CLK IN connector on the PXIe-5622, and connect the PXIe-5622 CLK OUT connector to the  FREQ REF IN connector  on the PXI/PXIe-5652.\n\n PXIe-5665-NI-RFSA locks the PXIe-5665 to an external 100 MHz signal.  Connect the external signal to the CLK IN  connector on the PXIe-5622, and connect the PXIe-5622 CLK OUT connector to the REF IN  connector on the PXIe-5653. Set the NIRFSA_ATTR_REF_CLOCK_RATE attribute to 100 MHz. \n\n PXIe-5667-NI-RFSA locks the PXIe-5667 to an external 100 MHz signal. Connect the external signal  to the CLK IN connector on the PXIe-5622, and connect the PXIe-5622 CLK OUT connector to the REF IN  connector on the PXIe-5653. Connect the 10 MHZ REF OUT terminal on the PXIe-5653 to the REF/LO IN connector  on the PXIe-5694. Set the NIRFSA_ATTR_REF_CLOCK_RATE attribute to 100 MHz.\n\n PXIe-5668-Lock the PXIe-5668 to an external 100 MHz signal. Connect the external signal to the CLK IN  connector on the PXIe-5624, and connect the PXIe-5624 CLK OUT connector to the REF IN connector on the PXIe-5653.  Set the clock rate parameter to 100 MHz. \n\n PXIe-5644/5645/5646, PXIe-5820/5830/5831/5831 with PXIe-5653/5840/5840 with PXIe-5653/5841/5841 with PXIe-5655-This configuration does not apply. '
                },
                'name': 'CLK_IN',
                'value': 'ClkIn'
            },
            {
                'documentation': {
                    'description': ' PXIe-5840 with PXIe-5653—NI-RFSA locks the device to the clock sourced at the PXIe-5840 REF IN terminal that  is already configured by an NI-RFSG session. Connect the PXIe-5840 REF OUT connector to the PXIe-5653 REF IN connector.  Configure open NI-RFSG sessions to the device to use NIRFSG_VAL_REF_IN_2_STR for the PXIe-5840 or NIRFSG_VAL_ONBOARD_CLOCK_STR for the PXIe-5840 with PXIe-5653. \n\n PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5644/5645/5646, PXIe-5820/5830/5831/5831 with PXIe-5653/5840/5841/5841 with PXIe-5655—This configuration does not apply. '
                },
                'name': 'REF_IN_2',
                'value': 'RefIn2'
            },
            {
                'documentation': {
                    'description': ' PXIe-5831 with PXIe-5653—NI-RFSA configures the PXIe-5653 to export the Reference clock and configures the PXIe-5820 and PXIe-3622  to use PXI_Clk as the Reference Clock source. Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXI chassis REF IN connector. \n PXIe-5840 with PXIe-5653—NI-RFSA configures the PXIe-5653 to export the Reference Clock, and configures the  PXIe-5840 to use NIRFSA_VAL_PXI_CLK_STR. Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXI chassis REF IN connector.  For best performance, configure all other devices in the system to use NIRFSA_VAL_PXI_CLK_STR as the Reference Clock source. \n\n PXI-5661, PXIe-5663/5663E/5665/5667/5668, PXIe-5644/5645/5646, PXIe-5820/5830/5840/5841/5841 with PXIe-5655—This configuration does not apply. '
                },
                'name': 'PXI_CLK_MASTER',
                'value': 'PXI_ClkMaster'
            }
        ]
    },
    'RefTriggerType': {
        'values': [
            {
                'documentation': {
                    'description': ' No Reference trigger is configured.'
                },
                'name': 'NONE',
                'value': 600
            },
            {
                'documentation': {
                    'description': ' The Reference trigger is not asserted until a digital edge is detected. The  source of the digital edge is specified with the NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_SOURCE attribute.'
                },
                'name': 'DIGITAL_EDGE',
                'value': 601
            },
            {
                'documentation': {
                    'description': ' The Reference trigger is asserted when the signal is changing past the level  specified with the slope (rising or falling) configured with the  NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_SLOPE attribute.'
                },
                'name': 'IQ_POWER_EDGE',
                'value': 603
            },
            {
                'documentation': {
                    'description': ' The Reference trigger is not asserted until a software trigger occurs. You can  assert the software trigger by calling the niRFSA_SendSoftwareEdgeTrigger  function and passing NIRFSA_VAL_REF_TRIGGER as the trigger parameter.'
                },
                'name': 'SOFTWARE_EDGE',
                'value': 604
            },
            {
                'documentation': {
                    'description': ' The Reference trigger is asserted when the I or Q signal is changed past the level  specified with the slope configured with the NIRFSA_ATTR_IQ_ANALOG_EDGE_REF_TRIGGER_SLOPE  attribute. This value is supported only for the PXIe-5644/5645 devices.'
                },
                'name': 'IQ_ANALOG_EDGE',
                'value': 605
            }
        ]
    },
    'ResetWithOptionsStepsToOmit': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'ROUTES',
                'value': 1
            },
            {
                'name': 'DEEMBEDDING_TABLES',
                'value': 2
            }
        ]
    },
    'RfLBSigCondPathSel': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies to use RF Lowband Signal Conditioning Path 1. This value is default.'
                },
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_1',
                'value': 3700
            },
            {
                'documentation': {
                    'description': ' Specifies to use RF Lowband Signal Conditioning Path 2.'
                },
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_2',
                'value': 3701
            },
            {
                'documentation': {
                    'description': ' Specifies to use RF Lowband Signal Conditioning Path 3.'
                },
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_3',
                'value': 3702
            },
            {
                'documentation': {
                    'description': ' Specifies to use RF Lowband Signal Conditioning Path 4.'
                },
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_4',
                'value': 3703
            },
            {
                'documentation': {
                    'description': ' Specifies to use RF Lowband Signal Conditioning Path 5.'
                },
                'name': 'EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_5',
                'value': 3704
            }
        ]
    },
    'RfPathSelection': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies to use RF band 1. This value is the default.'
                },
                'name': 'EXT_CAL_RF_BAND_1',
                'value': 1700
            },
            {
                'documentation': {
                    'description': ' Specifies to use RF band 2.'
                },
                'name': 'EXT_CAL_RF_BAND_2',
                'value': 1701
            },
            {
                'documentation': {
                    'description': ' Specifies to use RF band 3.'
                },
                'name': 'EXT_CAL_RF_BAND_3',
                'value': 1702
            },
            {
                'documentation': {
                    'description': ' Specifies to use RF band 4.'
                },
                'name': 'EXT_CAL_RF_BAND_4',
                'value': 1703
            }
        ]
    },
    'RfPreampEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables the RF preamplifier. '
                },
                'name': 'DISABLED',
                'value': 2500
            },
            {
                'documentation': {
                    'description': ' Enables the RF preamplifier when the RF preamplifier is present in the signal path  and disables the preamplifier when it is not in the path. Only devices with an RF  preamplifier on the downconverter support this option. Use the NIRFSA_ATTR_RF_PREAMP_PRESENT  attribute to determine whether the downconverter has a preamplifier.'
                },
                'name': 'ENABLED_WHEN_IN_SIGNAL_PATH',
                'value': 2501
            },
            {
                'documentation': {
                    'description': ' Enables the RF preamplifier. If the RF preamplifier is not in a signal path,  NI-RFSA returns an error. Select the NIRFSA_VAL_RF_PREAMP_ENABLED_WHEN_IN_SIGNAL_PATH  option whenever possible to avoid an error.'
                },
                'name': 'ENABLED',
                'value': 2502
            },
            {
                'documentation': {
                    'description': ' Enables the RF preamplifier automatically based on the value of the NIRFSA_ATTR_REFERENCE_LEVEL attribute. This value is valid only for the PXIe-5644/5645/5646, PXIe-5667, and PXIe-5830/5831/5840/5841.'
                },
                'name': 'AUTOMATIC',
                'value': 2503
            }
        ]
    },
    'RfPreselectorFilter': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that no filter is used'
                },
                'name': 'FILTER_PATH_NONE',
                'value': 3300
            },
            {
                'documentation': {
                    'description': ' Specifies that the 19-35 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_1',
                'value': 3301
            },
            {
                'documentation': {
                    'description': ' Specifies that the 33-61 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_2',
                'value': 3302
            },
            {
                'documentation': {
                    'description': ' Specifies that the 59-110 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_3',
                'value': 3303
            },
            {
                'documentation': {
                    'description': ' Specifies that the 90-167 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_4',
                'value': 3304
            },
            {
                'documentation': {
                    'description': ' Specifies that the 140-245 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_5',
                'value': 3305
            },
            {
                'documentation': {
                    'description': ' Specifies that the 205-370 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_6',
                'value': 3306
            },
            {
                'documentation': {
                    'description': ' Specifies that the 330-595 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_7',
                'value': 3307
            },
            {
                'documentation': {
                    'description': ' Specifies that the 550-975 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_8',
                'value': 3308
            },
            {
                'documentation': {
                    'description': ' Specifies that the 910-1600 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_9',
                'value': 3309
            },
            {
                'documentation': {
                    'description': ' Specifies that the 1520-2040 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_10',
                'value': 3310
            },
            {
                'documentation': {
                    'description': ' Specifies that the 1960-2540 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_11',
                'value': 3311
            },
            {
                'documentation': {
                    'description': ' Specifies that the 2460-3040 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_12',
                'value': 3312
            },
            {
                'documentation': {
                    'description': ' Specifies that the 2960-3840 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_13',
                'value': 3313
            },
            {
                'documentation': {
                    'description': ' Specifies that the 3760-4640 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_14',
                'value': 3314
            },
            {
                'documentation': {
                    'description': ' Specifies that the 4560-5840 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_15',
                'value': 3315
            },
            {
                'documentation': {
                    'description': ' Specifies that the 5760-7040 MHz pre-selector filter is used'
                },
                'name': 'FILTER_PATH_16',
                'value': 3316
            },
            {
                'documentation': {
                    'description': ' Specifies that the external pre-selector filter is used'
                },
                'name': 'FILTER_PATH_EXTERNAL_FILTER',
                'value': 3317
            }
        ]
    },
    'SelfCalibrateSteps': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'ALIGNMENT',
                'value': 1
            },
            {
                'name': 'GAIN_REFERENCE',
                'value': 2
            },
            {
                'name': 'IF_FLATNESS',
                'value': 4
            },
            {
                'name': 'DIGITIZER_SELF_CAL',
                'value': 8
            },
            {
                'name': 'LO_SELF_CAL',
                'value': 16
            },
            {
                'name': 'AMPLITUDE_ACCURACY',
                'value': 32
            },
            {
                'name': 'RESIDUAL_LO_POWER',
                'value': 64
            },
            {
                'name': 'IMAGE_SUPPRESSION',
                'value': 128
            },
            {
                'name': 'SYNTHESIZER_ALIGNMENT',
                'value': 256
            },
            {
                'name': 'DC_OFFSET',
                'value': 512
            }
        ]
    },
    'Signal': {
        'values': [
            {
                'name': 'START_TRIGGER',
                'value': 1100
            },
            {
                'name': 'REF_TRIGGER',
                'value': 702
            },
            {
                'name': 'ADVANCE_TRIGGER',
                'value': 1102
            },
            {
                'name': 'ARM_REF_TRIGGER',
                'value': 1103
            },
            {
                'name': 'READY_FOR_START_EVENT',
                'value': 1200
            },
            {
                'name': 'READY_FOR_REF_EVENT',
                'value': 1201
            },
            {
                'name': 'READY_FOR_ADVANCE_EVENT',
                'value': 1202
            },
            {
                'name': 'END_OF_RECORD_EVENT',
                'value': 1203
            },
            {
                'name': 'DONE_EVENT',
                'value': 1204
            },
            {
                'name': 'REF_CLOCK',
                'value': 1205
            },
            {
                'name': 'USER',
                'value': 1206
            }
        ]
    },
    'SignalConditioningEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the signal conditioning will be enabled.'
                },
                'name': 'ENABLED',
                'value': 3600
            },
            {
                'documentation': {
                    'description': ' Specifies that all signal conditioning will be bypassed.'
                },
                'name': 'BYPASSED',
                'value': 3601
            }
        ]
    },
    'SparameterOrientation': {
        'values': [
            {
                'name': 'PORT1_TOWARDS_DUT',
                'value': 3800
            },
            {
                'name': 'PORT2_TOWARDS_DUT',
                'value': 3801
            }
        ]
    },
    'StepGainEnabled': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the step gain amplifier will be disabled.'
                },
                'name': 'DISABLED',
                'value': 3200
            },
            {
                'documentation': {
                    'description': ' Specifies that the step gain amplifier will be enabled.'
                },
                'name': 'ENABLED',
                'value': 3201
            }
        ]
    },
    'TriggerSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The trigger is received on PFI 0.  For the PXIe-5841 with PXIe-5655, the trigger is received on the PXIe-5841 PFI 0.'
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
                    'description': ' The trigger is received on the PXI star trigger line.'
                },
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on the PXIe DStar B trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.'
                },
                'name': 'PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'documentation': {
                    'description': ' The trigger is received on expiration of the specified Timer Event Interval.'
                },
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'documentation': {
                    'description': ' The device is reconfigured when the acquisition reaches the end of record event.'
                },
                'name': 'END_OF_RECORD_EVENT',
                'value': 'EndOfRecordEvent'
            },
            {
                'documentation': {
                    'description': ' The device uses the Start trigger to start the timer.'
                },
                'name': 'START_TRIGGER',
                'value': 'StartTrigger'
            },
            {
                'documentation': {
                    'description': ' The device uses the Reference trigger to start the timer.'
                },
                'name': 'REFERENCE_TRIGGER',
                'value': 'ReferenceTrigger'
            },
            {
                'name': 'SYNC_START_TRIGGER',
                'value': 'Sync_Start'
            },
            {
                'name': 'SYNC_REF_TRIGGER',
                'value': 'Sync_Ref'
            },
            {
                'name': 'SYNC_ADVANCE_TRIGGER',
                'value': 'Sync_Advance'
            }
        ]
    },
    'UnspecifiedAttr': {
        'values': [
            {
                'documentation': {
                    'description': ' The LO signal is not exported from the RF OUT LO OUT terminal.'
                },
                'name': 'DISABLED',
                'value': 1900
            },
            {
                'documentation': {
                    'description': ' The LO signal is exported from the RF OUT LO OUT terminal.'
                },
                'name': 'ENABLED',
                'value': 1901
            },
            {
                'documentation': {
                    'description': ' The LO signal may or may not be exported to the RF OUT LO OUT terminal, because NI-RFSG may be controlling it.'
                },
                'name': 'UNSPECIFIED',
                'value': 1902
            }
        ]
    }
}
