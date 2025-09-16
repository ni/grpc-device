enums = {
    'AmpPath': {
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
    'AnalogModulationFMBand': {
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
    'AnalogModulationFMNarrowbandIntegrator': {
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
    'AnalogModulationPMMode': {
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
    'AnalogModulationType': {
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
    'AnalogModulationWaveformType': {
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
    'AnySignalOutputTerm': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The signal is not exported.\n'
                },
                'name': 'DO_NOT_EXPORT',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.  For the PXIe-5841 with PXIe-5655, the signal is exported to the PXIe-5841 PFI 0.\n'
                },
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PFI 4 on the front panel DDC connector.\n'
                },
                'name': 'PFI4',
                'value': 'PFI4'
            },
            {
                'documentation': {
                    'description': ' PFI 5 on the front panel DDC connector.\n'
                },
                'name': 'PFI5',
                'value': 'PFI5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar C trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel DIO connector.\n'
                },
                'name': 'DIO0',
                'value': 'DIO/PFI0',
                'order': 1
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel DIO connector.\n'
                },
                'name': 'DIO1',
                'value': 'DIO/PFI1',
                'order': 2
            },
            {
                'documentation': {
                    'description': ' PFI 2 on the front panel DIO connector.\n'
                },
                'name': 'DIO2',
                'value': 'DIO/PFI2',
                'order': 3
            },
            {
                'documentation': {
                    'description': ' PFI 3 on the front panel DIO connector.\n'
                },
                'name': 'DIO3',
                'value': 'DIO/PFI3',
                'order': 4
            },
            {
                'documentation': {
                    'description': ' PFI 4 on the front panel DIO connector.\n'
                },
                'name': 'DIO4',
                'value': 'DIO/PFI4',
                'order': 5
            },
            {
                'documentation': {
                    'description': ' PFI 5 on the front panel DIO connector.\n'
                },
                'name': 'DIO5',
                'value': 'DIO/PFI5',
                'order': 6
            },
            {
                'documentation': {
                    'description': ' PFI 6 on the front panel DIO connector.\n'
                },
                'name': 'DIO6',
                'value': 'DIO/PFI6',
                'order': 7
            },
            {
                'documentation': {
                    'description': ' PFI 7 on the front panel DIO connector.\n'
                },
                'name': 'DIO7',
                'value': 'DIO/PFI7',
                'order': 8
            }
        ]
    },
    'ArbFilterType': {
        'values': [
            {
                'documentation': {
                    'description': ' None'
                },
                'name': 'NONE',
                'value': 10000
            },
            {
                'documentation': {
                    'description': ' Applies a root-raised cosine filter to the data with the alpha value  specified with the NIRFSG_ATTR_ARB_FILTER_ROOT_RAISED_COSINE_ALPHA  attribute. '
                },
                'name': 'ROOT_RAISED_COSINE',
                'value': 10001
            },
            {
                'documentation': {
                    'description': ' Applies a raised cosine filter to the data with the alpha value specified  with the NIRFSG_ATTR_ARB_FILTER_RAISED_COSINE_ALPHA attribute. '
                },
                'name': 'RAISED_COSINE',
                'value': 10002
            }
        ]
    },
    'ArbOnboardSampleClockMode': {
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
    'ArbSampleClockSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Use the AWG module onboard clock as the clock source.\n'
                },
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' Use the external clock as the clock source.\n'
                },
                'name': 'CLK_IN',
                'value': 'ClkIn'
            }
        ]
    },
    'ConfigListTrigOutputTerm': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The signal is not exported.\n'
                },
                'name': 'DO_NOT_EXPORT',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.  For the PXIe-5841 with PXIe-5655, the signal is exported to the PXIe-5841 PFI 0.\n'
                },
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar C trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel DIO connector.\n'
                },
                'name': 'DIO0',
                'value': 'DIO/PFI0',
                'order': 9
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel DIO connector.\n'
                },
                'name': 'DIO1',
                'value': 'DIO/PFI1',
                'order': 10
            },
            {
                'documentation': {
                    'description': ' PFI 2 on the front panel DIO connector.\n'
                },
                'name': 'DIO2',
                'value': 'DIO/PFI2',
                'order': 11
            },
            {
                'documentation': {
                    'description': ' PFI 3 on the front panel DIO connector.\n'
                },
                'name': 'DIO3',
                'value': 'DIO/PFI3',
                'order': 12
            },
            {
                'documentation': {
                    'description': ' PFI 4 on the front panel DIO connector.\n'
                },
                'name': 'DIO4',
                'value': 'DIO/PFI4',
                'order': 13
            },
            {
                'documentation': {
                    'description': ' PFI 5 on the front panel DIO connector.\n'
                },
                'name': 'DIO5',
                'value': 'DIO/PFI5',
                'order': 14
            },
            {
                'documentation': {
                    'description': ' PFI 6 on the front panel DIO connector.\n'
                },
                'name': 'DIO6',
                'value': 'DIO/PFI6',
                'order': 15
            },
            {
                'documentation': {
                    'description': ' PFI 7 on the front panel DIO connector.\n'
                },
                'name': 'DIO7',
                'value': 'DIO/PFI7',
                'order': 16
            }
        ]
    },
    'ConfigListTrigSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.\n'
                },
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 7.\n'
                },
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'documentation': {
                    'description': ' PXI Star trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'documentation': {
                    'description': ' Marker Event 0.\n'
                },
                'name': 'MARKER0_EVENT',
                'value': 'Marker0Event'
            },
            {
                'documentation': {
                    'description': ' Marker Event 1.\n'
                },
                'name': 'MARKER1_EVENT',
                'value': 'Marker1Event'
            },
            {
                'documentation': {
                    'description': ' Marker Event 2.\n'
                },
                'name': 'MARKER2_EVENT',
                'value': 'Marker2Event'
            },
            {
                'documentation': {
                    'description': ' Marker Event 3.\n'
                },
                'name': 'MARKER3_EVENT',
                'value': 'Marker3Event'
            },
            {
                'documentation': {
                    'description': ' Timer Event.\n'
                },
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_IN',
                'value': 'TrigIn'
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel DIO connector.\n'
                },
                'name': 'DIO0',
                'value': 'DIO/PFI0',
                'order': 17
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel DIO connector.\n'
                },
                'name': 'DIO1',
                'value': 'DIO/PFI1',
                'order': 18
            },
            {
                'documentation': {
                    'description': ' PFI 2 on the front panel DIO connector.\n'
                },
                'name': 'DIO2',
                'value': 'DIO/PFI2',
                'order': 19
            },
            {
                'documentation': {
                    'description': ' PFI 3 on the front panel DIO connector.\n'
                },
                'name': 'DIO3',
                'value': 'DIO/PFI3',
                'order': 20
            },
            {
                'documentation': {
                    'description': ' PFI 4 on the front panel DIO connector.\n'
                },
                'name': 'DIO4',
                'value': 'DIO/PFI4',
                'order': 21
            },
            {
                'documentation': {
                    'description': ' PFI 5 on the front panel DIO connector.\n'
                },
                'name': 'DIO5',
                'value': 'DIO/PFI5',
                'order': 22
            },
            {
                'documentation': {
                    'description': ' PFI 6 on the front panel DIO connector.\n'
                },
                'name': 'DIO6',
                'value': 'DIO/PFI6',
                'order': 23
            },
            {
                'documentation': {
                    'description': ' PFI 7 on the front panel DIO connector.\n'
                },
                'name': 'DIO7',
                'value': 'DIO/PFI7',
                'order': 24
            }
        ]
    },
    'ConfigListTriggerDigEdgeEdge': {
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
    'ConfigSettledEventOutputTerm': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' The signal is not exported.\n'
                },
                'name': 'DO_NOT_EXPORT',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar C trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841.\n'
                },
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
            }
        ]
    },
    'ConfigurationListRepeat': {
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
    'DeembeddingType': {
        'values': [
            {
                'documentation': {
                    'description': ' De-embedding is not applied to the measurement. '
                },
                'name': 'NONE',
                'value': 25000
            },
            {
                'documentation': {
                    'description': ' De-embeds the measurement using only the gain term.'
                },
                'name': 'SCALAR',
                'value': 25001
            },
            {
                'documentation': {
                    'description': ' De-embeds the measurement using the gain term and the reflection term.'
                },
                'name': 'VECTOR',
                'value': 25002
            }
        ]
    },
    'DigitalEdgeConfigurationListStepTriggerSource': {
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
                'name': 'PFI2',
                'value': 'PFI2'
            },
            {
                'name': 'PFI3',
                'value': 'PFI3'
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
                'name': 'MARKER0_EVENT',
                'value': 'Marker0Event'
            },
            {
                'name': 'MARKER1_EVENT',
                'value': 'Marker1Event'
            },
            {
                'name': 'MARKER2_EVENT',
                'value': 'Marker2Event'
            },
            {
                'name': 'MARKER3_EVENT',
                'value': 'Marker3Event'
            },
            {
                'name': 'TIMER_EVENT',
                'value': 'TimerEvent'
            },
            {
                'name': 'TRIG_IN',
                'value': 'TrigIn'
            }
        ]
    },
    'DigitalEdgeEdge': {
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
    'DigitalLevelActiveLevel': {
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
    'DigitalModulationType': {
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
    'DigitalModulationWaveformType': {
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
    'EnableValues': {
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
    'FrequencySettlingUnits': {
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
    'GenerationMode': {
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
    'IqOffsetUnits': {
        'values': [
            {
                'name': 'PERCENT',
                'value': 11000
            },
            {
                'name': 'VOLTS',
                'value': 11001
            }
        ]
    },
    'IqOutPortTermConfig': {
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
    'LinearInterpolationFormat': {
        'values': [
            {
                'name': 'REAL_AND_IMAGINARY',
                'value': 26000
            },
            {
                'name': 'MAGNITUDE_AND_PHASE',
                'value': 26001
            },
            {
                'name': 'MAGNITUDE_DB_AND_PHASE',
                'value': 26002
            }
        ]
    },
    'ListStepTriggerType': {
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
    'LoSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Uses an internal LO as the LO source. If you specify an internal LO source, the LO is generated  within the device itself. \n\n PXIe-5840 with PXIe-5653: If the center frequency is greater than or equal to 3.2 GHz,  this configuration uses the PXIe-5653 LO source. For frequencies less than 3.2 GHz,  this configuration uses the PXIe-5840 internal LO. \n PXIe-5841 with PXIe-5655: This configuration uses the onboard LO of the PXIe-5655. \n'
                },
                'name': 'ONBOARD',
                'value': 'Onboard'
            },
            {
                'documentation': {
                    'description': ' Uses an external LO as the LO source. Connect a signal to the LO IN connector on  the device and use the NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY attribute to specify the LO frequency. \n'
                },
                'name': 'LO_IN',
                'value': 'LO_In'
            },
            {
                'documentation': {
                    'description': ' Uses the PXIe-5840 internal LO as the LO source. This value is valid on only the PXIe-5840 with PXIe-5653.'
                },
                'name': 'SECONDARY',
                'value': 'Secondary'
            },
            {
                'documentation': {
                    'description': ' Uses the same internal LO during some RX and TX operations. In this mode, an internal synthesizer  is chosen by the driver and the synthesizer signal is switched to both the RF In and RF Out mixers.  This value is valid on only the PXIe-5830/5831/5841 with PXIe-5655. \n'
                },
                'name': 'SG_SA_SHARED',
                'value': 'SG_SA_Shared'
            },
            {
                'documentation': {
                    'description': ' NI-RFSG internally makes the configuration to share the LO between NI-RFSA and NI-RFSG. This value is valid only on the PXIe-5820/5830/5831/5832/5840/5841. \n'
                },
                'name': 'AUTOMATIC_SG_SA_SHARED',
                'value': 'Automatic_SG_SA_Shared'
            }
        ]
    },
    'LoadOptions': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSG loads all the configurations to the session.'
                },
                'name': 'SKIP_NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' NI-RFSG skips loading the waveform configurations to the session.'
                },
                'name': 'SKIP_WAVEFORMS',
                'value': 1
            }
        ]
    },
    'LoopBandwidth': {
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
    'MarkerEventOutputBehavior': {
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
    'MarkerEventPulseWidthUnits': {
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
    'MarkerEventToggleInitialState': {
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
    'OutputPort': {
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
    'OutputSignal': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'DO_NOT_EXPORT',
                'value': ''
            },
            {
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'name': 'PFI4',
                'value': 'PFI4'
            },
            {
                'name': 'PFI5',
                'value': 'PFI5'
            },
            {
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
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
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'TRIG_OUT',
                'value': 'TrigOut'
            }
        ]
    },
    'OverflowErrorReporting': {
        'values': [
            {
                'documentation': {
                    'description': ' Configures NI-RFSG to return a warning when an OSP overflow occurs.'
                },
                'name': 'WARNING',
                'value': 1301
            },
            {
                'documentation': {
                    'description': ' Configures NI-RFSG to not return an error or a warning when an OSP overflow occurs.'
                },
                'name': 'DISABLED',
                'value': 1302
            }
        ]
    },
    'PPAScriptInheritance': {
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
    'PXIChassisClk10': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Do not drive the PXI_CLK10 signal.\n'
                },
                'name': 'NONE',
                'value': 'None'
            },
            {
                'documentation': {
                    'description': ' Use the highly stable oven-controlled onboard Reference Clock to drive  the PXI_CLK10 signal. This value is not valid on the PXIe-5672.\n'
                },
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' Use the clock present at the front panel REF IN connector to drive the  PXI_CLK10 signal.\n'
                },
                'name': 'REF_IN',
                'value': 'RefIn'
            }
        ]
    },
    'PhaseContinuity': {
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
    'PowerLevelType': {
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
    'PulseModulationMode': {
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
    'RefClockOutputTerm': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Do not export the Reference Clock.\n'
                },
                'name': 'DO_NOT_EXPORT',
                'value': ''
            },
            {
                'documentation': {
                    'description': ' Export the Reference Clock signal to the REF OUT connector of the device.\n'
                },
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'documentation': {
                    'description': ' Export the Reference Clock signal to the REF OUT2 connector of the device, if applicable.\n'
                },
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'documentation': {
                    'description': ' Export the Reference Clock signal to the CLK OUT connector of the device.\n'
                },
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            }
        ]
    },
    'RefClockRate': {
        'values': [
            {
                'name': '10_MHZ',
                'value': 10000000
            },
            {
                'name': 'AUTO',
                'value': -1
            }
        ]
    },
    'RefClockSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' Uses the onboard Reference Clock as the clock source.\n PXIe-5830/5831—For the PXIe-5830, connect the PXIe-5820 REF IN connector to the PXIe-3621 REF OUT connector.  For the PXIe-5831, connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector. \n PXIe-5831 with PXIe-5653—Connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector.  Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXIe-3622 REF IN connector. \n PXIe-5840 with PXIe-5653—Lock to the PXIe-5653 onboard clock. Connect the REF OUT (10 MHz)  connector on the PXIe-5653 to the PXIe-5840 REF IN connector. Configure open NI-RFSA  sessions to the device to use NIRFSA_VAL_REF_IN_STR for the PXIe-5840 or  NIRFSA_VAL_REF_IN_2_STR for the PXIe-5840 with PXIe-5653. \n PXIe-5841 with PXIe-5655—Lock to the PXIe-5655 onboard clock. Connect the REF OUT  connector on the PXIe-5655 to the PXIe-5841 REF IN connector. \n'
                },
                'name': 'ONBOARD_CLOCK',
                'value': 'OnboardClock'
            },
            {
                'documentation': {
                    'description': ' Use the clock signal present at the front panel RefIn connector as the  clock source.\n PXIe-5830/5831—For the PXIe-5830, connect the PXIe-5820 REF IN connector to the PXIe-3621 REF OUT connector.  For the PXIe-5831, connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector. For the PXIe-5830,  lock the external signal to the PXIe-3621 REF IN connector. For the PXIe-5831, lock the external  signal to the PXIe-3622 REF IN connector. \n PXIe-5831 with PXIe-5653—Connect the PXIe-5820 REF IN connector to the PXIe-3622 REF OUT connector.  Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXIe-3622 REF IN connector. Lock the external signal to the PXIe-5653 REF IN connector.  PXIe-5840 with PXIe-5653—Lock to the PXIe-5653 onboard clock.  Connect the REF OUT (10 MHz) connector on the PXIe-5653 to the PXIe-5840 REF IN connector. \n PXIe-5841 with PXIe-5655—Lock to the signal at the REF IN connector on the associated PXIe-5655.  Connect the PXIe-5655 REF OUT connector to the PXIe-5841 REF IN connector. \n'
                },
                'name': 'REF_IN',
                'value': 'RefIn'
            },
            {
                'documentation': {
                    'description': ' Use the PXI_CLK signal, which is present on the PXI backplane, as the  clock source.\n'
                },
                'name': 'PXI_CLK',
                'value': 'PXI_CLK'
            },
            {
                'documentation': {
                    'description': ' Use the clock signal present at the front panel ClkIn connector as the  clock source. This value is not valid for the PXIe-5644/5645/5646 or  PXIe-5820/5830/5831/5831 with PXIe-5653/5840/5840 with PXIe-5653/5841/5841 with PXIe-5655. \n'
                },
                'name': 'CLK_IN',
                'value': 'ClkIn'
            },
            {
                'documentation': {
                    'description': ' This value is valid on only the PXIe-5840 with PXIe-5653. NI-RFSG locks the  Reference Clock to the clock sourced at the PXIe-5840 REF IN terminal that is already  configured by an NI-RFSA session. Connect the PXIe-5840 REF OUT connector to the PXIe-5653  REF IN connector. Configure open NI-RFSA sessions to the device to use NIRFSA_VAL_REF_IN_STR  for the PXIe-5840 or NIRFSA_VAL_ONBOARD_CLOCK_STR for the PXIe-5840 with PXIe-5653. \n'
                },
                'name': 'REF_IN_2',
                'value': 'RefIn2'
            },
            {
                'documentation': {
                    'description': ' This value is valid on only the PXIe-5831 with PXIe-5653 and the PXIe-5840 with PXIe-5653.  PXIe-5831 with PXIe-5653—NI-RFSG configures the PXIe-5653 to export the Reference clock and  configures the PXIe-5820 and PXIe-3622 to use NIRFSG_VAL_PXI_CLK_STR as the Reference Clock source.  Connect the PXIe-5653 REF OUT (10 MHz) connector to the PXI chassis REF IN connector. \n PXIe-5840 with PXIe-5653—NI-RFSG configures the  PXIe-5653 to export the Reference Clock, and configures the PXIe-5840 to use  NIRFSG_VAL_PXI_CLK_STR. Connect the PXIe-5653 REF OUT (10 MHz) connector to the  PXI chassis REF IN connector. For best performance, configure all other devices  in the system to use NIRFSG_VAL_PXI_CLK_STR as the Reference Clock source. \n'
                },
                'name': 'PXI_CLK_MASTER',
                'value': 'PXI_ClkMaster'
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
    'ResetOptions': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSG resets all the configurations.'
                },
                'name': 'SKIP_NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': ' NI-RFSG skips resetting the waveform configurations.'
                },
                'name': 'SKIP_WAVEFORMS',
                'value': 1
            },
            {
                'documentation': {
                    'description': ' NI-RFSG skips resetting the scripts.'
                },
                'name': 'SKIP_SCRIPTS',
                'value': 2
            },
            {
                'documentation': {
                    'description': ' NI-RFSG skips resetting the de-embeding tables.'
                },
                'name': 'SKIP_DEEMBEDING_TABLES',
                'value': 8
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
                'name': 'WAVEFORMS',
                'value': 1
            },
            {
                'name': 'SCRIPTS',
                'value': 2
            },
            {
                'name': 'ROUTES',
                'value': 4
            },
            {
                'name': 'DEEMBEDDING_TABLES',
                'value': 8
            }
        ]
    },
    'RfInLoExportEnabled': {
        'values': [
            {
                'name': 'UNSPECIFIED',
                'value': -2
            },
            {
                'name': 'DISABLE',
                'value': 0
            },
            {
                'name': 'ENABLE',
                'value': 1
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
    'ScriptTriggerType': {
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
    'SelfCalibrateRangeStepsToOmit': {
        'values': [
            {
                'name': 'OMIT_NONE',
                'value': 0
            },
            {
                'name': 'LO_SELF_CAL',
                'value': 1
            },
            {
                'name': 'POWER_LEVEL_ACCURACY',
                'value': 2
            },
            {
                'name': 'RESIDUAL_LO_POWER',
                'value': 4
            },
            {
                'name': 'IMAGE_SUPPRESSION',
                'value': 8
            },
            {
                'name': 'SYNTHESIZER_ALIGNMENT',
                'value': 16
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
    'StartTriggerType': {
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
    'TriggerSource': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel SMB connector.\n'
                },
                'name': 'PFI0',
                'value': 'PFI0'
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel SMB connector.\n'
                },
                'name': 'PFI1',
                'value': 'PFI1'
            },
            {
                'documentation': {
                    'description': ' PFI 2 on the front panel DDC connector.\n'
                },
                'name': 'PFI2',
                'value': 'PFI2'
            },
            {
                'documentation': {
                    'description': ' PFI 3 on the front panel DDC connector.\n'
                },
                'name': 'PFI3',
                'value': 'PFI3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 0.\n'
                },
                'name': 'PXI_TRIG0',
                'value': 'PXI_Trig0'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 1.\n'
                },
                'name': 'PXI_TRIG1',
                'value': 'PXI_Trig1'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 2.\n'
                },
                'name': 'PXI_TRIG2',
                'value': 'PXI_Trig2'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 3.\n'
                },
                'name': 'PXI_TRIG3',
                'value': 'PXI_Trig3'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 4.\n'
                },
                'name': 'PXI_TRIG4',
                'value': 'PXI_Trig4'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 5.\n'
                },
                'name': 'PXI_TRIG5',
                'value': 'PXI_Trig5'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 6.\n'
                },
                'name': 'PXI_TRIG6',
                'value': 'PXI_Trig6'
            },
            {
                'documentation': {
                    'description': ' PXI trigger line 7.\n'
                },
                'name': 'PXI_TRIG7',
                'value': 'PXI_Trig7'
            },
            {
                'documentation': {
                    'description': ' PXI Star trigger line. This value is not valid on the PXIe-5644/5645/5646.\n'
                },
                'name': 'PXI_STAR',
                'value': 'PXI_STAR'
            },
            {
                'documentation': {
                    'description': ' PXIe DStar B trigger line. This value is valid on only the PXIe-5820/5830/5831/5840/5841/5842/5860. \n'
                },
                'name': 'PXIE_DSTARB',
                'value': 'PXIe_DStarB'
            },
            {
                'documentation': {
                    'description': ' Sync Start trigger line.'
                },
                'name': 'SYNC_START_TRIGGER',
                'value': 'Sync_Start'
            },
            {
                'documentation': {
                    'description': ' Sync script trigger line.'
                },
                'name': 'SYNC_SCRIPT_TRIGGER',
                'value': 'Sync_Script'
            },
            {
                'documentation': {
                    'description': ' TRIG IN/OUT terminal.\n'
                },
                'name': 'TRIG_IN',
                'value': 'TrigIn'
            },
            {
                'documentation': {
                    'description': ' PULSE IN terminal.\n'
                },
                'name': 'PULSE_IN',
                'value': 'PulseIn',
                'order': 25
            },
            {
                'documentation': {
                    'description': ' PFI 0 on the front panel DIO connector.\n'
                },
                'name': 'DIO0',
                'value': 'DIO/PFI0',
                'order': 26
            },
            {
                'documentation': {
                    'description': ' PFI 1 on the front panel DIO connector.\n'
                },
                'name': 'DIO1',
                'value': 'DIO/PFI1',
                'order': 27
            },
            {
                'documentation': {
                    'description': ' PFI 2 on the front panel DIO connector.\n'
                },
                'name': 'DIO2',
                'value': 'DIO/PFI2',
                'order': 28
            },
            {
                'documentation': {
                    'description': ' PFI 3 on the front panel DIO connector.\n'
                },
                'name': 'DIO3',
                'value': 'DIO/PFI3',
                'order': 29
            },
            {
                'documentation': {
                    'description': ' PFI 4 on the front panel DIO connector.\n'
                },
                'name': 'DIO4',
                'value': 'DIO/PFI4',
                'order': 30
            },
            {
                'documentation': {
                    'description': ' PFI 5 on the front panel DIO connector.\n'
                },
                'name': 'DIO5',
                'value': 'DIO/PFI5',
                'order': 31
            },
            {
                'documentation': {
                    'description': ' PFI 6 on the front panel DIO connector.\n'
                },
                'name': 'DIO6',
                'value': 'DIO/PFI6',
                'order': 32
            },
            {
                'documentation': {
                    'description': ' PFI 7 on the front panel DIO connector.\n'
                },
                'name': 'DIO7',
                'value': 'DIO/PFI7',
                'order': 33
            }
        ]
    },
    'UpconverterFrequencyOffsetMode': {
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
    'WriteWaveformBurstDetectionMode': {
        'values': [
            {
                'documentation': {
                    'description': ' NI-RFSG automatically detects the burst start and burst stop locations by analyzing the waveform.'
                },
                'name': 'AUTO',
                'value': -1
            },
            {
                'documentation': {
                    'description': ' User sets the burst detection parameters.'
                },
                'name': 'MANUAL',
                'value': 0
            }
        ]
    },
    'YigMainCoil': {
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
    }
}
