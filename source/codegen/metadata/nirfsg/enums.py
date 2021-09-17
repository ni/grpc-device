enums = {
    'AttrAmpPathRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Sets the amplification path to use the high power path. \n'
                },
                'name': 'HIGH_POWER',
                'value': 16000
            },
            {
                'documentation': {
                    'description': ' Sets the amplification path to use the low harmonic path. \n'
                },
                'name': 'LOW_HARMONIC',
                'value': 16001
            }
        ]
    },
    'AttrAnalogModulationFMBandRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies narrowband frequency modulation.\n'
                },
                'name': 'NARROWBAND',
                'value': 17000
            },
            {
                'documentation': {
                    'description': ' Specifies wideband frequency modulation.\n'
                },
                'name': 'WIDEBAND',
                'value': 17001
            }
        ]
    },
    'AttrAnalogModulationFMNarrowbandIntegratorRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies a range from 100 Hz to 1 kHz.\n'
                },
                'name': '100_HZ_TO_1_KHZ',
                'value': 18000
            },
            {
                'documentation': {
                    'description': ' Specifies a range from 1 kHz to 10 kHz.\n'
                },
                'name': '1_KHZ_TO_10_KHZ',
                'value': 18001
            },
            {
                'documentation': {
                    'description': ' Specifies a range from 10 kHz to 100 kHz.\n'
                },
                'name': '10_KHZ_TO_100_KHZ',
                'value': 18002
            }
        ]
    },
    'AttrAnalogModulationPMModeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies high deviation. High deviation comes at the expense of a higher phase noise.\n'
                },
                'name': 'HIGH_DEVIATION',
                'value': 19000
            },
            {
                'documentation': {
                    'description': ' Specifies low phase noise. Low phase noise comes at the expense of a lower maximum deviation.\n'
                },
                'name': 'LOW_PHASE_NOISE',
                'value': 19001
            }
        ]
    },
    'AttrAnalogModulationTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables analog modulation.\n'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Specifies that the analog modulation type is FM.\n'
                },
                'name': 'FM',
                'value': 2000
            },
            {
                'documentation': {
                    'description': ' Specifies that the analog modulation type is PM.\n'
                },
                'name': 'PM',
                'value': 2001
            },
            {
                'documentation': {
                    'description': ' Specifies that the analog modulation type is AM.\n'
                },
                'name': 'AM',
                'value': 2002
            }
        ]
    },
    'AttrAnalogModulationWaveformTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the analog modulation waveform type is sine.\n'
                },
                'name': 'SINE',
                'value': 3000
            },
            {
                'documentation': {
                    'description': ' Specifies that the analog modulation waveform type is square.\n'
                },
                'name': 'SQUARE',
                'value': 3001
            },
            {
                'documentation': {
                    'description': ' Specifies that the analog modulation waveform type is triangle.\n'
                },
                'name': 'TRIANGLE',
                'value': 3002
            }
        ]
    },
    'AttrAnySignalOutputTermRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The signal is not exported.\n'
                },
                'name': 'DO_NOT_EXPORT_STR',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.  For the PXIe-5841 with PXIe-5655, the signal is exported to the PXIe-5841 PFI 0.\n'
                },
                'name': 'PFI0_STR',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1_STR',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PFI 4 on the front panel DDC connector.\n'
                },
                'name': 'PFI4_STR',
                'value': 'PFI4'
            },
            {
                'documentation': {
                    'description': ' PFI 5 on the front panel DDC connector.\n'
                },
                'name': 'PFI5_STR',
                'value': 'PFI5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar C trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARC_STR',
                'value': 'PXIe_DStarC'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_OUT_STR',
                'value': 'TrigOut'
            }
        ]
    },
    'AttrArbFilterTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' None'
                },
                'name': 'ARB_FILTER_TYPE_NONE',
                'value': 10000
            },
            {
                'documentation': {
                    'description': ' Applies a root-raised cosine filter to the data with the alpha value  specified with the NIRFSG_ATTR_ARB_FILTER_ROOT_RAISED_COSINE_ALPHA  attribute. '
                },
                'name': 'ARB_FILTER_TYPE_ROOT_RAISED_COSINE',
                'value': 10001
            },
            {
                'documentation': {
                    'description': ' Applies a raised cosine filter to the data with the alpha value specified  with the NIRFSG_ATTR_ARB_FILTER_RAISED_COSINE_ALPHA attribute. '
                },
                'name': 'ARB_FILTER_TYPE_RAISED_COSINE',
                'value': 10002
            }
        ]
    },
    'AttrArbOnboardSampleClockModeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the clock mode is high resoultion. High resolution  sampling is when a sample rate is generated by a high resolution clock  source.\n'
                },
                'name': 'HIGH_RESOLUTION',
                'value': 6000
            },
            {
                'documentation': {
                    'description': ' Specifies that the clock mode is divide down. Divide down sampling is  when sample rates are generated by dividing the source frequency.\n'
                },
                'name': 'DIVIDE_DOWN',
                'value': 6001
            }
        ]
    },
    'AttrArbSampleClockSourceRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Use the AWG module onboard clock as the clock source.\n'
                },
                'name': 'ONBOARD_CLOCK_STR',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' Use the external clock as the clock source.\n'
                },
                'name': 'CLK_IN_STR',
                'value': 'ClkIn'
            }
        ]
    },
    'AttrConfigListTrigOutputTermRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The signal is not exported.\n'
                },
                'name': 'DO_NOT_EXPORT_STR',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.  For the PXIe-5841 with PXIe-5655, the signal is exported to the PXIe-5841 PFI 0.\n'
                },
                'name': 'PFI0_STR',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1_STR',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar C trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARC_STR',
                'value': 'PXIe_DStarC'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_OUT_STR',
                'value': 'TrigOut'
            }
        ]
    },
    'AttrConfigListTrigSourceRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.\n'
                },
                'name': 'PFI0_STR',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1_STR',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 7.\n'
                },
                'name': 'PXI_TRIG7_STR',
                'value': 'PXI_Trig7'
            },
            {
                'documentation': {
                    'description': ' PXI Star trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARB_STR',
                'value': 'PXIe_DStarB'
            },
            {
                'documentation': {
                    'description': ' Marker Event 0.\n'
                },
                'name': 'MARKER0_EVENT_STR',
                'value': 'Marker0Event'
            },
            {
                'documentation': {
                    'description': ' Marker Event 1.\n'
                },
                'name': 'MARKER1_EVENT_STR',
                'value': 'Marker1Event'
            },
            {
                'documentation': {
                    'description': ' Marker Event 2.\n'
                },
                'name': 'MARKER2_EVENT_STR',
                'value': 'Marker2Event'
            },
            {
                'documentation': {
                    'description': ' Marker Event 3.\n'
                },
                'name': 'MARKER3_EVENT_STR',
                'value': 'Marker3Event'
            },
            {
                'documentation': {
                    'description': ' Timer Event.\n'
                },
                'name': 'TIMER_EVENT_STR',
                'value': 'TimerEvent'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_IN_STR',
                'value': 'TrigIn'
            }
        ]
    },
    'AttrConfigListTriggerDigEdgeEdgeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies the rising edge as the active edge.  The rising edge  occurs when the signal transitions from low level to high level.\n'
                },
                'name': 'RISING_EDGE',
                'value': 0
            }
        ]
    },
    'AttrConfigSettledEventOutputTermRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The signal is not exported.\n'
                },
                'name': 'DO_NOT_EXPORT_STR',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar C trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARC_STR',
                'value': 'PXIe_DStarC'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_OUT_STR',
                'value': 'TrigOut'
            }
        ]
    },
    'AttrConfigurationListRepeatRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSG runs the configuration list continuously.\n'
                },
                'name': 'CONFIGURATION_LIST_REPEAT_CONTINUOUS',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' NI-RFSG runs the configuration list only once.'
                },
                'name': 'CONFIGURATION_LIST_REPEAT_SINGLE',
                'value': 1
            }
        ]
    },
    'AttrDigitalEdgeEdgeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Occurs when the signal transitions from low level to high level. \n'
                },
                'name': 'RISING_EDGE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Occurs when the signal transitions from high level to low level. \n'
                },
                'name': 'FALLING_EDGE',
                'value': 1
            }
        ]
    },
    'AttrDigitalLevelActiveLevelRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Trigger when the digital trigger signal is high. \n'
                },
                'name': 'ACTIVE_HIGH',
                'value': 9000
            },
            {
                'documentation': {
                    'description': ' Trigger when the digital trigger signal is low. \n'
                },
                'name': 'ACTIVE_LOW',
                'value': 9001
            }
        ]
    },
    'AttrDigitalModulationTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Disables digital modulation.\n'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Specifies that the digital modulation type is frequency-shift keying  (FSK).\n'
                },
                'name': 'FSK',
                'value': 4000
            },
            {
                'documentation': {
                    'description': ' Specifies that the digital modulation type is on-off keying (OOK).\n'
                },
                'name': 'OOK',
                'value': 4001
            },
            {
                'documentation': {
                    'description': ' Specifies that the digital modulation type is PSK.\n'
                },
                'name': 'PSK',
                'value': 4002
            }
        ]
    },
    'AttrDigitalModulationWaveformTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the digital modulation waveform type is pseudorandom bit  sequence (PRBS).\n'
                },
                'name': 'PRBS',
                'value': 5000
            },
            {
                'documentation': {
                    'description': ' Specifies that the digital modulation waveform type is user defined. To  specify the user-defined waveform, call the  niRFSG_ConfigureDigitalModulationUserDefinedWaveform function.\n'
                },
                'name': 'USER_DEFINED',
                'value': 5001
            }
        ]
    },
    'AttrFrequencySettlingUnitsRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies the value in Frequency Settling is the time to wait after the  frequency PLL locks.\n'
                },
                'name': 'TIME_AFTER_LOCK',
                'value': 12000
            },
            {
                'documentation': {
                    'description': ' Specifies the value in Frequency Settling is the time to wait after all  writes to change the frequency occur.\n'
                },
                'name': 'TIME_AFTER_IO',
                'value': 12001
            },
            {
                'documentation': {
                    'description': ' Specifies the value in Frequency Settling is the minimum frequency  accuracy when settling completes. Units are in parts per million (PPM or  1E-6).\n'
                },
                'name': 'PPM',
                'value': 12002
            }
        ]
    },
    'AttrGenerationModeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures the RF signal generator to generate a CW signal. \n'
                },
                'name': 'CW',
                'value': 1000
            },
            {
                'documentation': {
                    'description': ' Configures the RF signal generator to generate the arbitrary waveform  specified by the NIRFSG_ATTR_ARB_SELECTED_WAVEFORM attribute. \n'
                },
                'name': 'ARB_WAVEFORM',
                'value': 1001
            },
            {
                'documentation': {
                    'description': ' Configures the RF signal generator to generate arbitrary waveforms as  directed by the NIRFSG_ATTR_SELECTED_SCRIPT attribute. \n'
                },
                'name': 'SCRIPT',
                'value': 1002
            }
        ]
    },
    'AttrIqOutPortTermConfigRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Sets the terminal configuration to differential. \n'
                },
                'name': 'DIFFERENTIAL',
                'value': 15000
            },
            {
                'documentation': {
                    'description': ' Sets the terminal configuration to single-ended. \n'
                },
                'name': 'SINGLE_ENDED',
                'value': 15001
            }
        ]
    },
    'AttrLoSourceRangetTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Uses an internal LO as the LO source. If you specify an internal LO source, the LO is generated  within the device itself. \n\n PXIe-5840 with PXIe-5653: If the center frequency is greater than or equal to 3.2 GHz,  this configuration uses the PXIe-5653 LO source. For frequencies less than 3.2 GHz,  this configuration uses the PXIe-5840 internal LO. \n PXIe-5841 with PXIe-5655: This configuration uses the onboard LO of the PXIe-5655. \n'
                },
                'name': 'LO_SOURCE_ONBOARD_STR',
                'value': 'Onboard'
            },
            {
                'documentation': {
                    'description': ' Uses an external LO as the LO source. Connect a signal to the LO IN connector on  the device and use the NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY attribute to specify the LO frequency. \n'
                },
                'name': 'LO_SOURCE_LO_IN_STR',
                'value': 'LO_In'
            },
            {
                'documentation': {
                    'description': ' Uses the PXIe-5840 internal LO as the LO source. This value is valid on only the PXIe-5840 with PXIe-5653.'
                },
                'name': 'LO_SOURCE_SECONDARY_STR',
                'value': 'Secondary'
            },
            {
                'documentation': {
                    'description': ' Uses the same internal LO during some RX and TX operations. In this mode, an internal synthesizer  is chosen by the driver and the synthesizer signal is switched to both the RF In and RF Out mixers.  This value is valid on only the PXIe-5830/5831/5841 with PXIe-5655. \n'
                },
                'name': 'LO_SOURCE_SG_SA_SHARED_STR',
                'value': 'SG_SA_Shared'
            },
            {
                'documentation': {
                    'description': ' NI-RFSG internally makes the configuration to share the LO between NI-RFSA and NI-RFSG. This value is valid only on the PXIe-5820/5830/5831/5832/5840/5841. \n'
                },
                'name': 'LO_SOURCE_AUTOMATIC_SG_SA_SHARED_STR',
                'value': 'AUTOMATIC_SG_SA_SHARED_STR'
            }
        ]
    },
    'AttrLoopBandwidthRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the device uses a narrow loop bandwidth.\n'
                },
                'name': 'NARROW',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Specifies that the device uses a medium loop bandwidth.\n'
                },
                'name': 'MEDIUM',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Specifies that the device uses a wide loop bandwidth.\n'
                },
                'name': 'WIDE',
                'value': 2
            }
        ]
    },
    'AttrMarkerEventOutputBehaviorRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies the Marker Event output behavior as pulse.  \n'
                },
                'name': 'PULSE',
                'value': 23000
            },
            {
                'documentation': {
                    'description': ' Specifies the Marker Event output behavior as toggle. \n'
                },
                'name': 'TOGGLE',
                'value': 23001
            }
        ]
    },
    'AttrMarkerEventPulseWidthUnitsRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies the Marker Event pulse width units as seconds.  \n'
                },
                'name': 'SECONDS',
                'value': 22000
            },
            {
                'documentation': {
                    'description': ' Specifies the Marker Event pulse width units as Sample Clock periods. \n'
                },
                'name': 'SAMPLE_CLOCK_PERIODS',
                'value': 22001
            }
        ]
    },
    'AttrMarkerEventToggleInitialStateRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies the initial state of the Marker Event toggle behavior as digital low. \n'
                },
                'name': 'DIGITAL_LOW',
                'value': 21000
            },
            {
                'documentation': {
                    'description': ' Specifies the initial state of the Marker Event toggle behavior as digital high. \n'
                },
                'name': 'DIGITAL_HIGH',
                'value': 21001
            }
        ]
    },
    'AttrOutputPortRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Enables the RF OUT port. \n'
                },
                'name': 'RF_OUT',
                'value': 14000
            },
            {
                'documentation': {
                    'description': ' Enables the I/Q OUT port. \n'
                },
                'name': 'IQ_OUT',
                'value': 14001
            },
            {
                'documentation': {
                    'description': ' Enables the CAL OUT port. \n'
                },
                'name': 'CAL_OUT',
                'value': 14002
            },
            {
                'documentation': {
                    'description': ' Enables the I connectors of the I/Q OUT port. \n'
                },
                'name': 'I_ONLY',
                'value': 14003
            }
        ]
    },
    'AttrPPAScriptInheritanceTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Errors out if different values are detected in the script.\n'
                },
                'name': 'EXACT_MATCH',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Uses the minimum value found in the script.\n'
                },
                'name': 'MINIMUM',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Uses the maximum value found in the script.\n'
                },
                'name': 'MAXIMUM',
                'value': 2
            }
        ]
    },
    'AttrPXIChassisClk10RangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Do not drive the PXI_CLK10 signal.\n'
                },
                'name': 'NONE_STR',
                'value': 'None'
            },
            {
                'documentation': {
                    'description': ' Use the highly stable oven-controlled onboard Reference Clock to drive  the PXI_CLK10 signal. This value is not valid on the PXIe-5672.\n'
                },
                'name': 'ONBOARD_CLOCK_STR',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' Use the clock present at the front panel REF IN connector to drive the  PXI_CLK10 signal.\n'
                },
                'name': 'REF_IN_STR',
                'value': 'RefIn'
            }
        ]
    },
    'AttrPhaseContinuityRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Auto'
                },
                'name': 'AUTO',
                'value': -1
            },
            {
                'documentation': {
                    'description': ' Enabled'
                },
                'name': 'ENABLE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Disabled'
                },
                'name': 'DISABLE',
                'value': 0
            }
        ]
    },
    'AttrPowerLevelTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Specifies that the power level type is average power. Average power  indicates the desired power averaged in time. The driver maximizes the  dynamic range by scaling the IQ waveform. If you write more than one  waveform, NI-RFSG scales each waveform without preserving the power level  ratio between the waveforms. This value is not valid for the PXIe-5820. \n'
                },
                'name': 'AVERAGE_POWER',
                'value': 7000
            },
            {
                'documentation': {
                    'description': ' Specifies that the power level type is peak power. Peak power indicates  the maximum power level of the RF signal averaged over one period of the  RF carrier signal frequency (the peak envelope power). This setting  requires that the magnitude of the IQ waveform must always be less than  or equal to one. When using the peak power level type, the power level of  the RF signal matches the specified power level at moments when the  magnitude of the IQ waveform equals one. If you write more than one  waveform, the relative scaling between waveforms is preserved.\n'
                },
                'name': 'PEAK_POWER',
                'value': 7001
            }
        ]
    },
    'AttrPulseModulationModeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Provides for a more optimal power output match for the device during the off cycle of the pulse mode operation.  \n'
                },
                'name': 'OPTIMAL_MATCH',
                'value': 20000
            },
            {
                'documentation': {
                    'description': ' Allows for the best on/off power ratio of the pulsed signal. \n'
                },
                'name': 'HIGH_ISOLATION',
                'value': 20001
            }
        ]
    },
    'AttrRefClockOutputTermRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Do not export the Reference Clock.\n'
                },
                'name': 'DO_NOT_EXPORT_STR',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' Export the Reference Clock signal to the REF OUT connector of the device.\n'
                },
                'name': 'REF_OUT_STR',
                'value': 'RefOut'
            },
            {
                'documentation': {
                    'description': ' Export the Reference Clock signal to the REF OUT2 connector of the device, if applicable.\n'
                },
                'name': 'REF_OUT2_STR',
                'value': 'RefOut2'
            },
            {
                'documentation': {
                    'description': ' Export the Reference Clock signal to the CLK OUT connector of the device.\n'
                },
                'name': 'CLK_OUT_STR',
                'value': 'ClkOut'
            }
        ]
    },
    'AttrRefClockSourceRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Uses the onboard Reference Clock as the clock source.\n PXIe-5830/5831�For the PXIe-5830, connect the PXIe-5820 REF IN connector to the PXIe-3621 REF OUT connector.  For the PXIe-5831, connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector. \n PXIe-5831 with PXIe-5653�Connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector.  Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXIe-3622 REF IN connector. \n PXIe-5840 with PXIe-5653�Lock to the PXIe-5653 onboard clock. Connect the REF OUT (10 MHz)  connector on the PXIe-5653 to the PXIe-5840 REF IN connector. Configure open NI-RFSA  sessions to the device to use NIRFSA_VAL_REF_IN_STR for the PXIe-5840 or  NIRFSA_VAL_REF_IN_2_STR for the PXIe-5840 with PXIe-5653. \n PXIe-5841 with PXIe-5655�Lock to the PXIe-5655 onboard clock. Connect the REF OUT  connector on the PXIe-5655 to the PXIe-5841 REF IN connector. \n'
                },
                'name': 'ONBOARD_CLOCK_STR',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' Use the clock signal present at the front panel RefIn connector as the  clock source.\n PXIe-5830/5831�For the PXIe-5830, connect the PXIe-5820 REF IN connector to the PXIe-3621 REF OUT connector.  For the PXIe-5831, connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector. For the PXIe-5830,  lock the external signal to the PXIe-3621 REF IN connector. For the PXIe-5831, lock the external  signal to the PXIe-3622 REF IN connector. \n PXIe-5831 with PXIe-5653�Connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector.  Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXIe-3622 REF IN connector. Lock the external signal to the PXIe-5653 REF IN connector.  PXIe-5840 with PXIe-5653�Lock to the PXIe-5653 onboard clock.  Connect the REF OUT (10 MHz) connector on the PXIe-5653 to the PXIe-5840 REF IN connector. \n PXIe-5841 with PXIe-5655�Lock to the signal at the REF IN connector on the associated PXIe-5655.  Connect the PXIe-5655 REF OUT connector to the PXIe-5841 REF IN connector. \n'
                },
                'name': 'REF_IN_STR',
                'value': 'RefIn'
            },
            {
                'documentation': {
                    'description': ' Use the PXI_CLK signal, which is present on the PXI backplane, as the  clock source.\n'
                },
                'name': 'PXI_CLK_STR',
                'value': 'PXI_CLK'
            },
            {
                'documentation': {
                    'description': ' Use the clock signal present at the front panel ClkIn connector as the  clock source. This value is not valid for the PXIe-5644/5645/5646 or  PXIe-5820/5830/5831/5831 with PXIe-5653/5840/5840 with PXIe-5653/5841/5841 with PXIe-5655. \n'
                },
                'name': 'CLK_IN_STR',
                'value': 'ClkIn'
            },
            {
                'documentation': {
                    'description': ' This value is valid on only the PXIe-5840 with PXIe-5653. NI-RFSG locks the  Reference Clock to the clock sourced at the PXIe-5840 REF IN terminal that is already  configured by an NI-RFSA session. Connect the PXIe-5840 REF OUT connector to the PXIe-5653  REF IN connector. Configure open NI-RFSA sessions to the device to use NIRFSA_VAL_REF_IN_STR  for the PXIe-5840 or NIRFSA_VAL_ONBOARD_CLOCK_STR for the PXIe-5840 with PXIe-5653. \n'
                },
                'name': 'REF_IN_2_STR',
                'value': 'RefIn2'
            },
            {
                'documentation': {
                    'description': ' This value is valid on only the PXIe-5831 with PXIe-5653 and the PXIe-5840 with PXIe-5653.  PXIe-5831 with PXIe-5653�NI-RFSG configures the PXIe-5653 to export the Reference clock and  configures the PXIe-5820 and PXIe-3622 to use NIRFSG_VAL_PXI_CLK_STR as the Reference Clock source.  Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXI chassis REF IN connector. \n PXIe-5840 with PXIe-5653�NI-RFSG configures the  PXIe-5653 to export the Reference Clock, and configures the PXIe-5840 to use  NIRFSG_VAL_PXI_CLK_STR. Connect the PXIe-5653 REF OUT (10 MHz) connector to the  PXI chassis REF IN connector. For best performance, configure all other devices  in the system to use NIRFSG_VAL_PXI_CLK_STR as the Reference Clock source. \n'
                },
                'name': 'PXI_CLK_MASTER_STR',
                'value': 'PXI_ClkMaster'
            }
        ]
    },
    'AttrTriggerSourceRangeTable': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.\n'
                },
                'name': 'PFI0_STR',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1_STR',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PFI 2 on the front panel DDC connector.\n'
                },
                'name': 'PFI2_STR',
                'value': 'PFI2'
            },
            {
                'documentation': {
                    'description': ' PFI 3 on the front panel DDC connector.\n'
                },
                'name': 'PFI3_STR',
                'value': 'PFI3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 7.\n'
                },
                'name': 'PXI_TRIG7_STR',
                'value': 'PXI_Trig7'
            },
            {
                'documentation': {
                    'description': ' PXI Star trigger line. This value is not valid on the PXIe-5644/5645/5646.\n'
                },
                'name': 'PXI_STAR_STR',
                'value': 'PXI_STAR'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar B trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841. \n'
                },
                'name': 'PXIE_DSTARB_STR',
                'value': 'PXIe_DStarB'
            },
            {
                'documentation': {
                    'description': ' Sync Start trigger line.'
                },
                'name': 'SYNC_START_TRIGGER_STR',
                'value': 'Sync_Start'
            },
            {
                'documentation': {
                    'description': ' Sync script trigger line.'
                },
                'name': 'SYNC_SCRIPT_TRIGGER_STR',
                'value': 'Sync_Script'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_IN_STR',
                'value': 'TrigIn'
            }
        ]
    },
    'AttrUpconverterFrequencyOffsetModeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSG places the upconverter center frequency outside of the signal bandwidth if the  NIRFSG_ATTR_SIGNAL_BANDWIDTH attribute has been set and can be avoided. '
                },
                'name': 'AUTO',
                'value': -1
            },
            {
                'documentation': {
                    'description': ' NI-RFSG places the upconverter center frequency outside of the signal bandwidth if the NIRFSG_ATTR_SIGNAL_BANDWIDTH attribute  has been set and can be avoided. NI-RFSG returns an error if unable to avoid the specified signal bandwidth,  or if the NIRFSG_ATTR_SIGNAL_BANDWIDTH attribute has not been set. '
                },
                'name': 'ENABLE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' NI-RFSG uses the offset that you specified with the NIRFSG_ATTR_UPCONVERTER_FREQUENCY_OFFSET  or NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY attributes. '
                },
                'name': 'USER_DEFINED',
                'value': 5001
            }
        ]
    },
    'AttrYigMainCoilRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Adjusts the YIG main coil for an underdampened response. \n'
                },
                'name': 'SLOW',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' Adjusts the YIG main coil for an overdampened response. \n'
                },
                'name': 'FAST',
                'value': 1
            }
        ]
    },
    'DeembeddingType': {
        'values': [
            {
                'documentation': {
                    'description': ' De-embedding is not applied to the measurement. '
                },
                'name': 'DEEMBEDDING_TYPE_NONE',
                'value': 25000
            },
            {
                'documentation': {
                    'description': ' De-embeds the measurement using only the gain term.'
                },
                'name': 'DEEMBEDDING_TYPE_SCALAR',
                'value': 25001
            },
            {
                'documentation': {
                    'description': ' De-embeds the measurement using the gain term and the reflection term.'
                },
                'name': 'DEEMBEDDING_TYPE_VECTOR',
                'value': 25002
            }
        ]
    },
    'DigitalEdgeConfigurationListStepTriggerSource': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'PFI0_STR',
                'value': 'PFI0'
            },
            {
                'name': 'PFI1_STR',
                'value': 'PFI1'
            },
            {
                'name': 'PFI2_STR',
                'value': 'PFI2'
            },
            {
                'name': 'PFI3_STR',
                'value': 'PFI3'
            },
            {
                'name': 'PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'PXI_TRIG7_STR',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'PXI_STAR_STR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'MARKER0_EVENT_STR',
                'value': 'Marker0Event'
            },
            {
                'name': 'MARKER1_EVENT_STR',
                'value': 'Marker1Event'
            },
            {
                'name': 'MARKER2_EVENT_STR',
                'value': 'Marker2Event'
            },
            {
                'name': 'MARKER3_EVENT_STR',
                'value': 'Marker3Event'
            },
            {
                'name': 'TIMER_EVENT_STR',
                'value': 'TimerEvent'
            },
            {
                'name': 'TRIG_IN_STR',
                'value': 'TrigIn'
            }
        ]
    },
    'DigitalEdgeScriptTriggerIdentifier': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'SCRIPT_TRIGGER0',
                'value': 'scriptTrigger0'
            },
            {
                'name': 'SCRIPT_TRIGGER1',
                'value': 'scriptTrigger1'
            },
            {
                'name': 'SCRIPT_TRIGGER2',
                'value': 'scriptTrigger2'
            },
            {
                'name': 'SCRIPT_TRIGGER3',
                'value': 'scriptTrigger3'
            }
        ]
    },
    'Enable_values': {
        'values': [
            {
                'documentation': {
                    'description': ' Enabled'
                },
                'name': 'ENABLE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' Disabled'
                },
                'name': 'DISABLE',
                'value': 0
            }
        ]
    },
    'LinearInterpolationFormat': {
        'values': [
            {
                'name': 'LINEAR_INTERPOLATION_FORMAT_REAL_AND_IMAGINARY',
                'value': 26000
            },
            {
                'name': 'LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_AND_PHASE',
                'value': 26001
            },
            {
                'name': 'LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_DB_AND_PHASE',
                'value': 26002
            }
        ]
    },
    'ListStepTriggerTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Generation starts immediately.  No trigger is configured. \n'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The data operation does not start until a digital edge is detected.  The  source  of the digital edge is specified in the   NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE attribute, and the active  edge is specified in the NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE  attribute. \n'
                },
                'name': 'DIGITAL_EDGE',
                'value': 1
            }
        ]
    },
    'Module': {
        'values': [
            {
                'name': 'PRIMARY_MODULE',
                'value': 13000
            },
            {
                'name': 'AWG',
                'value': 13001
            },
            {
                'name': 'LO',
                'value': 13002
            }
        ]
    },
    'OutputSignal': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'DO_NOT_EXPORT_STR',
                'value': ''
            },
            {
                'name': 'PFI0_STR',
                'value': 'PFI0'
            },
            {
                'name': 'PFI1_STR',
                'value': 'PFI1'
            },
            {
                'name': 'PFI4_STR',
                'value': 'PFI4'
            },
            {
                'name': 'PFI5_STR',
                'value': 'PFI5'
            },
            {
                'name': 'PXI_STAR_STR',
                'value': 'PXI_STAR'
            },
            {
                'name': 'PXI_TRIG0_STR',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'PXI_TRIG1_STR',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'PXI_TRIG2_STR',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'PXI_TRIG3_STR',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'PXI_TRIG4_STR',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'PXI_TRIG5_STR',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'PXI_TRIG6_STR',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'REF_OUT2_STR',
                'value': 'RefOut2'
            },
            {
                'name': 'REF_OUT_STR',
                'value': 'RefOut'
            },
            {
                'name': 'TRIG_OUT_STR',
                'value': 'TrigOut'
            }
        ]
    },
    'OverflowErrorReportingRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures NI-RFSG to return a warning when an OSP overflow occurs.'
                },
                'name': 'ERROR_REPORTING_WARNING',
                'value': 1301
            },
            {
                'documentation': {
                    'description': ' Configures NI-RFSG to not return an error or a warning when an OSP overflow occurs.'
                },
                'name': 'ERROR_REPORTING_DISABLED',
                'value': 1302
            }
        ]
    },
    'RelativeTo': {
        'values': [
            {
                'name': 'START_OF_WAVEFORM',
                'value': 8000
            },
            {
                'name': 'CURRENT_POSITION',
                'value': 8001
            }
        ]
    },
    'RoutedSignal': {
        'values': [
            {
                'name': 'CONFIGURATION_LIST_STEP_TRIGGER',
                'value': 6
            },
            {
                'name': 'CONFIGURATION_SETTLED_EVENT',
                'value': 7
            },
            {
                'name': 'DONE_EVENT',
                'value': 5
            },
            {
                'name': 'MARKER_EVENT',
                'value': 2
            },
            {
                'name': 'REF_CLOCK',
                'value': 3
            },
            {
                'name': 'SCRIPT_TRIGGER',
                'value': 1
            },
            {
                'name': 'STARTED_EVENT',
                'value': 4
            },
            {
                'name': 'START_TRIGGER',
                'value': 0
            }
        ]
    },
    'SParameterOrientation': {
        'values': [
            {
                'name': 'PORT1_TOWARDS_DUT',
                'value': 24000
            },
            {
                'name': 'PORT2_TOWARDS_DUT',
                'value': 24001
            }
        ]
    },
    'ScriptTriggerTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Setting trigger attributes to this value specifies that no trigger is   configured. Signal generation starts immediately. \n'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The data operation does not start until a digital edge is detected. The  source of the digital edge is specified in the  NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE attribute, and the active edge is  specified in the NIRFSG_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE attribute. \n'
                },
                'name': 'DIGITAL_EDGE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The data operation does not start until a digital level is detected. The  source of the digital level is specified in the  NIRFSG_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE attribute, and the active level is  specified in the NIRFSG_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL attribute. \n'
                },
                'name': 'DIGITAL_LEVEL',
                'value': 8000
            },
            {
                'documentation': {
                    'description': ' The data operation does not start until a software event occurs. You may  create a software event by calling the niRFSG_SendSoftwareEdgeTrigger function. \n'
                },
                'name': 'SOFTWARE',
                'value': 2
            }
        ]
    },
    'SignalIdentifier': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'NONE',
                'value': ''
            },
            {
                'name': 'SCRIPT_TRIGGER0',
                'value': 'scriptTrigger0'
            },
            {
                'name': 'SCRIPT_TRIGGER1',
                'value': 'scriptTrigger1'
            },
            {
                'name': 'SCRIPT_TRIGGER2',
                'value': 'scriptTrigger2'
            },
            {
                'name': 'SCRIPT_TRIGGER3',
                'value': 'scriptTrigger3'
            },
            {
                'name': 'MARKER0',
                'value': 'marker0'
            },
            {
                'name': 'MARKER1',
                'value': 'marker1'
            },
            {
                'name': 'MARKER2',
                'value': 'marker2'
            },
            {
                'name': 'MARKER3',
                'value': 'marker3'
            }
        ]
    },
    'StartTriggerTypeRangeTable': {
        'values': [
            {
                'documentation': {
                    'description': ' Setting trigger attributes to this value specifies that no trigger is  configured. \n'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' The data operation does not start until a digital edge is detected. The  source of the digital edge is specified in the  NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE attribute, and the active  edge is specified in the NIRFSG_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE  attribute. \n'
                },
                'name': 'DIGITAL_EDGE',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' The data operation does not start until a software event occurs. You may  create a software event by calling the niRFSG_SendSoftwareEdgeTrigger function. \n'
                },
                'name': 'SOFTWARE',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' Data operation does not start until the endpoint reaches a threshold  specified in the NIRFSG_ATTR_P2P_ENDPOINT_FULLNESS_START_TRIGGER_LEVEL  attribute. \n'
                },
                'name': 'P2_P_ENDPOINT_FULLNESS',
                'value': 3
            }
        ]
    },
    'WriteWaveformBurstDetectionMode': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSG automatically detects the burst start and burst stop locations by analyzing the waveform. NIRFSG_VAL_WRITE_WAVEFORM_BURST_DETECTION_MODE_MANUAL (0) User sets the burst detection parameters.'
                },
                'name': 'WRITE_WAVEFORM_BURST_DETECTION_MODE_AUTO',
                'value': -1
            }
        ]
    }
}
