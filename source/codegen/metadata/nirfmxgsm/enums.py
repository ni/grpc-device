enums = {
    'AutoTscDetectionEnabled': {
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
    'Band': {
        'values': [
            {
                'name': 'PGSM',
                'value': 0
            },
            {
                'name': 'EGSM',
                'value': 1
            },
            {
                'name': 'RGSM',
                'value': 2
            },
            {
                'name': 'DCS1800',
                'value': 3
            },
            {
                'name': 'PCS1900',
                'value': 4
            },
            {
                'name': 'GSM450',
                'value': 5
            },
            {
                'name': 'GSM480',
                'value': 6
            },
            {
                'name': 'GSM850',
                'value': 7
            },
            {
                'name': 'GSM750',
                'value': 8
            },
            {
                'name': 'TGSM810',
                'value': 9
            }
        ]
    },
    'BurstSynchronizationType': {
        'values': [
            {
                'name': 'TSC',
                'value': 0
            },
            {
                'name': 'AMPLITUDE',
                'value': 1
            },
            {
                'name': 'NONE',
                'value': 2
            }
        ]
    },
    'BurstType': {
        'values': [
            {
                'name': 'NB',
                'value': 0
            },
            {
                'name': 'HB',
                'value': 1
            },
            {
                'name': 'AB',
                'value': 2
            }
        ]
    },
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
    'HBFilterWidth': {
        'values': [
            {
                'name': 'NARROW',
                'value': 0
            },
            {
                'name': 'WIDE',
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
    'LinkDirection': {
        'values': [
            {
                'name': 'DOWNLINK',
                'value': 0
            },
            {
                'name': 'UPLINK',
                'value': 1
            }
        ]
    },
    'MeasurementTypes': {
        'values': [
            {
                'name': 'MODACC',
                'value': 1
            },
            {
                'name': 'ORFS',
                'value': 2
            },
            {
                'name': 'PVT',
                'value': 4
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
    'ModAccAveragingEnabled': {
        'enum-value-prefix': 'MODACC_AVERAGING_ENABLED',
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
    'ModAccDetectedTsc': {
        'enum-value-prefix': 'MODACC_DETECTED_TSC',
        'values': [
            {
                'name': 'UNKNOWN',
                'value': -1
            },
            {
                'name': 'TSC0',
                'value': 0
            },
            {
                'name': 'TSC1',
                'value': 1
            },
            {
                'name': 'TSC2',
                'value': 2
            },
            {
                'name': 'TSC3',
                'value': 3
            },
            {
                'name': 'TSC4',
                'value': 4
            },
            {
                'name': 'TSC5',
                'value': 5
            },
            {
                'name': 'TSC6',
                'value': 6
            },
            {
                'name': 'TSC7',
                'value': 7
            }
        ]
    },
    'ModAccDroopCompensationEnabled': {
        'enum-value-prefix': 'MODACC_DROOP_COMPENSATION_ENABLED',
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
    'ModulationType': {
        'values': [
            {
                'name': 'GMSK',
                'value': 0
            },
            {
                'name': '8PSK',
                'value': 1
            },
            {
                'name': 'QPSK',
                'value': 2
            },
            {
                'name': '16QAM',
                'value': 3
            },
            {
                'name': '32QAM',
                'value': 4
            }
        ]
    },
    'OrfsAveragingEnabled': {
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
    'OrfsAveragingType': {
        'values': [
            {
                'name': 'RMS',
                'value': 0
            },
            {
                'name': 'LOG',
                'value': 1
            }
        ]
    },
    'OrfsEvaluationSymbolsIncludeTsc': {
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
    'OrfsEvaluationSymbolsScope': {
        'values': [
            {
                'name': 'OFFSET',
                'value': 0
            },
            {
                'name': 'OFFSET_AND_CARRIER',
                'value': 1
            }
        ]
    },
    'OrfsMeasurementType': {
        'values': [
            {
                'name': 'MODULATION_AND_SWITCHING',
                'value': 0
            },
            {
                'name': 'MODULATION',
                'value': 1
            },
            {
                'name': 'SWITCHING',
                'value': 2
            }
        ]
    },
    'OrfsNoiseCompensationEnabled': {
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
    'OrfsOffsetFrequencyMode': {
        'values': [
            {
                'name': 'STANDARD',
                'value': 0
            },
            {
                'name': 'SHORT',
                'value': 1
            },
            {
                'name': 'CUSTOM',
                'value': 2
            }
        ]
    },
    'PvtAveragingEnabled': {
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
    'PvtAveragingType': {
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
                'name': 'MAXIMUM',
                'value': 3
            },
            {
                'name': 'MINIMUM',
                'value': 4
            }
        ]
    },
    'PvtMeasurementStatus': {
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
    'PvtSlotMeasurementStatus': {
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
    'SignalStructure': {
        'values': [
            {
                'name': 'BURSTED',
                'value': 0
            },
            {
                'name': 'CONTINUOUS',
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
    'Tsc': {
        'values': [
            {
                'name': 'TSC0',
                'value': 0
            },
            {
                'name': 'TSC1',
                'value': 1
            },
            {
                'name': 'TSC2',
                'value': 2
            },
            {
                'name': 'TSC3',
                'value': 3
            },
            {
                'name': 'TSC4',
                'value': 4
            },
            {
                'name': 'TSC5',
                'value': 5
            },
            {
                'name': 'TSC6',
                'value': 6
            },
            {
                'name': 'TSC7',
                'value': 7
            }
        ]
    }
}
