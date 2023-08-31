enums = {
    'AcpAveragingEnabled': {
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
    'AcpBurstSynchronizationType': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'PREAMBLE',
                'value': 1
            },
            {
                'name': 'SYNC_WORD',
                'value': 2
            }
        ]
    },
    'AcpOffsetChannelMode': {
        'values': [
            {
                'name': 'SYMMETRIC',
                'value': 0
            },
            {
                'name': 'INBAND',
                'value': 1
            }
        ]
    },
    'AcpResultsMeasurementStatus': {
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
    'ChannelSoundingPacketFormat': {
        'values': [
            {
                'name': 'SYNC',
                'value': 0
            },
            {
                'name': 'CS_TONE',
                'value': 1
            },
            {
                'name': 'CS_TONE_AFTER_SYNC',
                'value': 2
            },
            {
                'name': 'CS_TONE_BEFORE_SYNC',
                'value': 3
            }
        ]
    },
    'ChannelSoundingSyncSequence': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'SOUNDING_SEQUENCE_32_BIT',
                'value': 1
            },
            {
                'name': 'SOUNDING_SEQUENCE_96_BIT',
                'value': 2
            }
        ]
    },
    'ChannelSoundingToneExtensionSlot': {
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
    'DirectionFindingMode': {
        'values': [
            {
                'name': 'DISABLED',
                'value': 0
            },
            {
                'name': 'ANGLE_OF_ARRIVAL',
                'value': 1
            },
            {
                'name': 'ANGLE_OF_DEPARTURE',
                'value': 2
            }
        ]
    },
    'FrequencyRangeAveragingEnabled': {
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
                'name': 'MODACC',
                'value': 2
            },
            {
                'name': 'TWENTY_DB_BANDWIDTH',
                'value': 4
            },
            {
                'name': 'FREQUENCY_RANGE',
                'value': 8
            },
            {
                'name': 'ACP',
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
    'ModAccBurstSynchronizationType': {
        'enum-value-prefix': 'MODACC_BURST_SYNCHRONIZATION_TYPE',
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'PREAMBLE',
                'value': 1
            },
            {
                'name': 'SYNC_WORD',
                'value': 2
            }
        ]
    },
    'ModAccIQOriginOffsetCorrectionEnabled': {
        'enum-value-prefix': 'MODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED',
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
    'PacketType': {
        'values': [
            {
                'name': 'UNKNOWN',
                'value': -1
            },
            {
                'name': 'DH1',
                'value': 0
            },
            {
                'name': 'DH3',
                'value': 1
            },
            {
                'name': 'DH5',
                'value': 2
            },
            {
                'name': 'DM1',
                'value': 3
            },
            {
                'name': 'DM3',
                'value': 4
            },
            {
                'name': 'DM5',
                'value': 5
            },
            {
                'name': '2_DH1',
                'value': 6
            },
            {
                'name': '2_DH3',
                'value': 7
            },
            {
                'name': '2_DH5',
                'value': 8
            },
            {
                'name': '3_DH1',
                'value': 9
            },
            {
                'name': '3_DH3',
                'value': 10
            },
            {
                'name': '3_DH5',
                'value': 11
            },
            {
                'name': '2_EV3',
                'value': 12
            },
            {
                'name': '2_EV5',
                'value': 13
            },
            {
                'name': '3_EV3',
                'value': 14
            },
            {
                'name': '3_EV5',
                'value': 15
            },
            {
                'name': 'LE',
                'value': 16
            },
            {
                'name': 'LE_CS',
                'value': 17
            }
        ]
    },
    'PayloadBitPattern': {
        'values': [
            {
                'name': 'STANDARD_DEFINED',
                'value': 0
            },
            {
                'name': '11110000',
                'value': 1
            },
            {
                'name': '10101010',
                'value': 2
            }
        ]
    },
    'PayloadLengthMode': {
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
    'Standard': {
        'values': [
            {
                'name': 'BR',
                'value': 0
            },
            {
                'name': 'EDR',
                'value': 0
            },
            {
                'name': 'LE',
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
    'TwentydBBandwidthAveragingEnabled': {
        'enum-value-prefix': 'TWENTY_DB_BANDWIDTH_AVERAGING_ENABLED',
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
    'TxpBurstSynchronizationType': {
        'values': [
            {
                'name': 'NONE',
                'value': 0
            },
            {
                'name': 'PREAMBLE',
                'value': 1
            },
            {
                'name': 'SYNC_WORD',
                'value': 2
            }
        ]
    }
}
