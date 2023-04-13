enums = {
    'AdvanceTriggerType': {
        'values': [
            {
                'name': 'DIGITAL_EDGE',
                'value': 1
            },
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'SOFTWARE',
                'value': 3
            }
        ]
    },
    'AutomaticSGSASharedLOEnabled': {
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
    'ChannelCoupling': {
        'values': [
            {
                'name': 'AC_COUPLED',
                'value': 0
            },
            {
                'name': 'DC_COUPLED',
                'value': 1
            }
        ]
    },
    'CleanerSpectrumEnabled': {
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
    'DigitizerDitherEnabled': {
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
    'DownconverterPreselectorEnabled': {
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
    'ExportSignalSource': {
        'values': [
            {
                'name': 'START_TRIGGER',
                'value': 0
            },
            {
                'name': 'REFERENCE_TRIGGER',
                'value': 1
            },
            {
                'name': 'ADVANCE_TRIGGER',
                'value': 2
            },
            {
                'name': 'READY_FOR_START_EVENT',
                'value': 3
            },
            {
                'name': 'READY_FOR_REFERENCE_EVENT',
                'value': 4
            },
            {
                'name': 'READY_FOR_ADVANCE_EVENT',
                'value': 5
            },
            {
                'name': 'END_OF_RECORD_EVENT',
                'value': 6
            },
            {
                'name': 'DONE_EVENT',
                'value': 7
            },
            {
                'name': 'REFERENCE_CLOCK',
                'value': 8
            }
        ]
    },
    'FrequencyReferenceExportedTerminal': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'NONE',
                'value': ''
            },
            {
                'name': 'REF_OUT',
                'value': 'RefOut'
            },
            {
                'name': 'REF_OUT2',
                'value': 'RefOut2'
            },
            {
                'name': 'CLK_OUT',
                'value': 'ClkOut'
            },
            {
                'name': 'DO_NOT_EXPORT',
                'value': ''
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
            },
            {
                'name': 'REF_IN2',
                'value': 'RefIn2'
            },
            {
                'name': 'PXI_CLK_MASTER',
                'value': 'PXI_ClkMaster'
            }
        ]
    },
    'FrequencySettlingUnits': {
        'values': [
            {
                'name': 'PPM',
                'value': 0
            },
            {
                'name': 'SECONDS_AFTER_IO',
                'value': 2
            },
            {
                'name': 'SECONDS_AFTER_LOCK',
                'value': 1
            }
        ]
    },
    'InputIsolationEnabled': {
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
    'LO2ExportEnabled': {
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
    'LOExportEnabled': {
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
    'LOInjectionSide': {
        'values': [
            {
                'name': 'HIGH_SIDE',
                'value': 0
            },
            {
                'name': 'LOW_SIDE',
                'value': 1
            }
        ]
    },
    'LOLeakageAvoidanceEnabled': {
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
    'LOPllFractionalModeEnabled': {
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
    'LOSharingMode': {
        'values': [
            {
                'name': 'DISABLED',
                'value': 0
            },
            {
                'name': 'EXTERNAL_DAISY_CHAIN',
                'value': 4
            },
            {
                'name': 'EXTERNAL_STAR',
                'value': 3
            }
        ]
    },
    'LOSource': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'AUTOMATIC_SG_SA_SHARED',
                'value': 'Automatic_SG_SA_Shared'
            },
            {
                'name': 'LO_IN',
                'value': 'LO_In'
            },
            {
                'name': 'NONE',
                'value': 'None'
            },
            {
                'name': 'ONBOARD',
                'value': 'Onboard'
            },
            {
                'name': 'SECONDARY',
                'value': 'Secondary'
            },
            {
                'name': 'SG_SA_SHARED',
                'value': 'SG_SA_Shared'
            }
        ]
    },
    'LinearInterpolationFormat': {
        'values': [
            {
                'name': 'MAGNITUDE_AND_PHASE',
                'value': 1
            },
            {
                'name': 'MAGNITUDE_DB_AND_PHASE',
                'value': 2
            },
            {
                'name': 'REAL_AND_IMAGINARY',
                'value': 0
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
    'OptimizePathForSignalBandwidth': {
        'values': [
            {
                'name': 'AUTOMATIC',
                'value': 2
            },
            {
                'name': 'DISABLED',
                'value': 0
            },
            {
                'name': 'ENABLED',
                'value': 1
            }
        ]
    },
    'OspDelayEnabled': {
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
    'OutputTerminal': {
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
                'name': 'PXIE_DSTARC',
                'value': 'PXIe_DStarC'
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
    'OverflowErrorReporting': {
        'values': [
            {
                'name': 'DISABLED',
                'value': 1
            },
            {
                'name': 'WARNING',
                'value': 0
            }
        ]
    },
    'Personality': {
        'values': [
            {
                'name': 'ALL',
                'value': 2147483647
            },
            {
                'name': 'BT',
                'value': 1024
            },
            {
                'name': 'CDMA2K',
                'value': 32
            },
            {
                'name': 'DEMOD',
                'value': 2
            },
            {
                'name': 'EVDO',
                'value': 128
            },
            {
                'name': 'GSM',
                'value': 8
            },
            {
                'name': 'LTE',
                'value': 4
            },
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'NR',
                'value': 256
            },
            {
                'name': 'PULSE',
                'value': 2048
            },
            {
                'name': 'SPECAN',
                'value': 1
            },
            {
                'name': 'TDSCDMA',
                'value': 64
            },
            {
                'name': 'VNA',
                'value': 4096
            },
            {
                'name': 'WCDMA',
                'value': 16
            },
            {
                'name': 'WLAN',
                'value': 512
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
    'RecommendedAcquisitionType': {
        'values': [
            {
                'name': 'IQ',
                'value': 0
            },
            {
                'name': 'IQ_OR_SPECTRAL',
                'value': 2
            },
            {
                'name': 'SPECTRAL',
                'value': 1
            }
        ]
    },
    'RecommendedSpectralFftWindow': {
        'values': [
            {
                'name': 'BLACKMAN',
                'value': 5
            },
            {
                'name': 'BLACKMAN_HARRIS',
                'value': 6
            },
            {
                'name': 'FLAT_TOP',
                'value': 1
            },
            {
                'name': 'GAUSSIAN',
                'value': 4
            },
            {
                'name': 'HAMMING',
                'value': 3
            },
            {
                'name': 'HANNING',
                'value': 2
            },
            {
                'name': 'KAISER_BESSEL',
                'value': 7
            },
            {
                'name': 'NONE',
                'value': 0
            }
        ]
    },
    'SParameterOrientation': {
        'values': [
            {
                'name': 'PORT1_TOWARDS_DUT',
                'value': 0
            },
            {
                'name': 'PORT2_TOWARDS_DUT',
                'value': 1
            }
        ]
    },
    'SParameterType': {
        'values': [
            {
                'name': 'SCALAR',
                'value': 1
            },
            {
                'name': 'VECTOR',
                'value': 2
            }
        ]
    },
    'SelfCalStep': {
        'values': [
            {
                'name': 'AMPLITUDE_ACCURACY',
                'value': 32
            },
            {
                'name': 'DC_OFFSET',
                'value': 512
            },
            {
                'name': 'DIGITIZER_SELF_CAL',
                'value': 8
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
                'name': 'IMAGE_SUPPRESSION',
                'value': 128
            },
            {
                'name': 'LO_SELF_CAL',
                'value': 16
            },
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'PRESELECTOR_ALIGNMENT',
                'value': 1
            },
            {
                'name': 'RESIDUAL_LO_POWER',
                'value': 64
            },
            {
                'name': 'SYNTHESIZER_ALIGNMENT',
                'value': 256
            }
        ]
    },
    'SelfCalibrationValidityCheck': {
        'values': [
            {
                'name': 'ENABLED',
                'value': 1
            },
            {
                'name': 'OFF',
                'value': 0
            }
        ]
    },
    'StartTriggerDigitalEdge': {
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
    'StartTriggerType': {
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
                'name': 'SOFTWARE',
                'value': 3
            }
        ]
    },
    'TuningSpeed': {
        'values': [
            {
                'name': 'FAST',
                'value': 2
            },
            {
                'name': 'MEDIUM',
                'value': 1
            },
            {
                'name': 'NORMAL',
                'value': 0
            }
        ]
    }
}
