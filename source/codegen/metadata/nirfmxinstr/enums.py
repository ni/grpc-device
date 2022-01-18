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
    'AutomaticSGSASharedLO': {
        'values': [
            {
                'name': 'AUTOMATIC_SG_SA_SHARED_LO_DISABLED',
                'value': 0
            },
            {
                'name': 'AUTOMATIC_SG_SA_SHARED_LO_ENABLED',
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
    'CleanerSpectrum': {
        'values': [
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
    'LOPllFractionalMode': {
        'values': [
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
    'SelfCalibrationValidityCheck': {
        'values': [
            {
                'name': 'OFF',
                'value': 0
            },
            {
                'name': 'ENABLED',
                'value': 1
            }
        ]
    },
    'StartTriggerDigitalEdge': {
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
    'TriggerExportOutputTerminal': {
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
