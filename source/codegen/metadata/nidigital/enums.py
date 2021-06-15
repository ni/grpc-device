# -*- coding: utf-8 -*-
# This file is generated from NI-Digital Pattern Driver API metadata version 19.5.0d7
enums = {
    'BitOrder': {
        'values': [
            {
                'documentation': {
                    'description': 'The most significant bit is first. The first bit is in the 2^n place, where n is the number of bits.'
                },
                'name': 'NIDIGITAL_VAL_MSB_FIRST',
                'value': 2500
            },
            {
                'documentation': {
                    'description': 'The least significant bit is first. The first bit is in the 2^0 place.'
                },
                'name': 'NIDIGITAL_VAL_LSB_FIRST',
                'value': 2501
            }
        ]
    },
    'DigitalEdge': {
        'values': [
            {
                'documentation': {
                    'description': 'Asserts the trigger when the signal transitions from low level to high level.'
                },
                'name': 'NIDIGITAL_VAL_RISING_EDGE',
                'value': 1800
            },
            {
                'documentation': {
                    'description': 'Asserts the trigger when the signal transitions from high level to low level.'
                },
                'name': 'NIDIGITAL_VAL_FALLING_EDGE',
                'value': 1801
            }
        ]
    },
    'DriveFormat': {
        'values': [
            {
                'documentation': {
                    'description': 'Drive format remains at logic level after each bit.'
                },
                'name': 'NIDIGITAL_VAL_NR',
                'value': 1500
            },
            {
                'documentation': {
                    'description': 'Drive format returns to a logic level low after each bit.'
                },
                'name': 'NIDIGITAL_VAL_RL',
                'value': 1501
            },
            {
                'documentation': {
                    'description': 'Drive format returns to a logic level high after each bit.'
                },
                'name': 'NIDIGITAL_VAL_RH',
                'value': 1502
            },
            {
                'documentation': {
                    'description': 'Drive format returns to the complement logic level of the bit after each bit.'
                },
                'name': 'NIDIGITAL_VAL_SBC',
                'value': 1503
            }
        ]
    },
    'ExportSignal': {
        'values': [
            {
                'documentation': {
                    'description': 'Overrides the start trigger.'
                },
                'name': 'NIDIGITAL_VAL_START_TRIGGER',
                'value': 2000
            },
            {
                'documentation': {
                    'description': 'Specifies to route a conditional jump trigger.'
                },
                'name': 'NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER',
                'value': 2001
            },
            {
                'documentation': {
                    'description': 'Specifies to route a pattern opcode event signal.'
                },
                'name': 'NIDIGITAL_VAL_PATTERN_OPCODE_EVENT',
                'value': 2002
            },
            {
                'name': 'NIDIGITAL_VAL_REF_CLOCK',
                'value': 2003
            }
        ]
    },
    'HistoryRamCyclesToAcquire': {
        'values': [
            {
                'documentation': {
                    'description': 'Acquires failed cycles.'
                },
                'name': 'NIDIGITAL_VAL_FAILED_CYCLES',
                'value': 2303
            },
            {
                'documentation': {
                    'description': 'Acquires all cycles.'
                },
                'name': 'NIDIGITAL_VAL_ALL_CYCLES',
                'value': 2304
            }
        ]
    },
    'HistoryRamTriggerType': {
        'values': [
            {
                'documentation': {
                    'description': 'First Failure History RAM trigger'
                },
                'name': 'NIDIGITAL_VAL_FIRST_FAILURE',
                'value': 2200
            },
            {
                'documentation': {
                    'description': 'Cycle Number History RAM trigger.'
                },
                'name': 'NIDIGITAL_VAL_CYCLE_NUMBER',
                'value': 2201
            },
            {
                'documentation': {
                    'description': 'Pattern Label History RAM trigger'
                },
                'name': 'NIDIGITAL_VAL_PATTERN_LABEL',
                'value': 2202
            }
        ]
    },
    'FrequencyMeasurementMode': {
        'values': [
            {
                'documentation': {
                    'description': 'Frequency measurements are made serially for groups of channels associated with a single frequency counter for each group.\n\nMaximum frequency measured: 200 MHz.'
                },
                'name': 'NIDIGITAL_VAL_BANKED',
                'value': 3700
            },
            {
                'documentation': {
                    'description': 'Frequency measurements are made by multiple frequency counters in parallel.\n\nMaximum frequency measured: 100 MHz.'
                },
                'name': 'NIDIGITAL_VAL_PARALLEL',
                'value': 3701
            }
        ]
    },
    'PpmuApertureTimeUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Unit in seconds.'
                },
                'name': 'NIDIGITAL_VAL_SECONDS',
                'value': 2100
            }
        ]
    },
    'PpmuCurrentLimitBehavior': {
        'values': [
            {
                'documentation': {
                    'description': 'Controls output current so that it does not exceed the current limit. Power continues to generate even if the current limit is reached.'
                },
                'name': 'NIDIGITAL_VAL_CURRENT_REGULATE',
                'value': 3100
            }
        ]
    },
    'PpmuMeasurementType': {
        'values': [
            {
                'documentation': {
                    'description': 'The PPMU measures current.'
                },
                'name': 'NIDIGITAL_VAL_MEASURE_CURRENT',
                'value': 2400
            },
            {
                'documentation': {
                    'description': 'The PPMU measures voltage.'
                },
                'name': 'NIDIGITAL_VAL_MEASURE_VOLTAGE',
                'value': 2401
            }
        ]
    },
    'PpmuOutputFunction': {
        'values': [
            {
                'documentation': {
                    'description': 'The PPMU forces voltage to the DUT.'
                },
                'name': 'NIDIGITAL_VAL_DC_VOLTAGE',
                'value': 1300
            },
            {
                'documentation': {
                    'description': 'The PPMU forces current to the DUT.'
                },
                'name': 'NIDIGITAL_VAL_DC_CURRENT',
                'value': 1301
            }
        ]
    },
    'PinState': {
        'values': [
            {
                'documentation': {
                    'description': 'A digital state of 0.'
                },
                'name': 'NIDIGITAL_VAL_0',
                'python_name': 'ZERO',
                'pretty_name': '0',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'A digital state of 1.'
                },
                'name': 'NIDIGITAL_VAL_1',
                'python_name': 'ONE',
                'pretty_name': '1',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'A digital state of L (low).'
                },
                'name': 'NIDIGITAL_VAL_L',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'A digital state of H (high).'
                },
                'name': 'NIDIGITAL_VAL_H',
                'value': 4
            },
            {
                'documentation': {
                    'description': 'A digital state of X (non-drive state).'
                },
                'name': 'NIDIGITAL_VAL_X',
                'value': 5
            },
            {
                'documentation': {
                    'description': 'A digital state of M (midband).'
                },
                'name': 'NIDIGITAL_VAL_M',
                'value': 6
            },
            {
                'documentation': {
                    'description': 'A digital state of V (compare high or low, not midband; store results from capture functionality if configured).'
                },
                'name': 'NIDIGITAL_VAL_V',
                'value': 7
            },
            {
                'documentation': {
                    'description': 'A digital state of D (drive data from source functionality if configured).'
                },
                'name': 'NIDIGITAL_VAL_D',
                'value': 8
            },
            {
                'documentation': {
                    'description': 'A digital state of E (compare data from source functionality if configured).'
                },
                'name': 'NIDIGITAL_VAL_E',
                'value': 9
            },
            {
                'documentation': {
                    'description': 'Not a pin state is used for non-existent DUT cycles.'
                },
                'name': 'NIDIGITAL_VAL_NOT_A_PIN_STATE',
                'pretty_name': 'Not a Pin State',
                'value': 254
            },
            {
                'documentation': {
                    'description': 'Pin state could not be acquired because none of the pins mapped to the instrument in a multi-instrument session had any failures.'
                },
                'name': 'NIDIGITAL_VAL_PIN_STATE_NOT_ACQUIRED',
                'pretty_name': 'Pin State Not Acquired',
                'value': 255
            }
        ]
    },
    'SelectedFunction': {
        'values': [
            {
                'documentation': {
                    'description': 'The pattern sequencer controls the specified pin(s). If a pattern is currently bursting, the pin immediately switches to bursting the pattern. This option disconnects the PPMU.'
                },
                'name': 'NIDIGITAL_VAL_DIGITAL',
                'value': 1100
            },
            {
                'documentation': {
                    'description': 'The PPMU controls the specified pin(s) and connects the PPMU. The pin driver is in a non-drive state, and the active load is disabled. The PPMU does not start sourcing or measuring until Source or Measure(PpmuMeasurementType) is called.'
                },
                'name': 'NIDIGITAL_VAL_PPMU',
                'value': 1101
            },
            {
                'documentation': {
                    'description': 'Puts the digital driver in a non-drive state, disables the active load, disconnects the PPMU, and closes the I/O switch connecting the instrument channel.'
                },
                'name': 'NIDIGITAL_VAL_OFF',
                'value': 1102
            },
            {
                'documentation': {
                    'description': 'The I/O switch connecting the instrument channel is open to the I/O connector. If the PPMU is sourcing, it is stopped prior to opening the I/O switch.'
                },
                'name': 'NIDIGITAL_VAL_DISCONNECT',
                'value': 1103
            }
        ]
    },
    'SiteResultType': {
        'values': [
            {
                'documentation': {
                    'description': 'Pass/fail site result.'
                },
                'name': 'NIDIGITAL_VAL_PASS_FAIL',
                'value': 3300
            },
            {
                'documentation': {
                    'description': 'Capture waveform site result.'
                },
                'name': 'NIDIGITAL_VAL_CAPTURE_WAVEFORM',
                'value': 3301
            }
        ]
    },
    'SoftwareTrigger': {
        'values': [
            {
                'documentation': {
                    'description': 'Overrides the start trigger.'
                },
                'name': 'NIDIGITAL_VAL_START_TRIGGER',
                'value': 2000
            },
            {
                'documentation': {
                    'description': 'Specifies to route a pattern opcode event signal.'
                },
                'name': 'NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER',
                'value': 2001
            }
        ]
    },
    'SourceDataMapping': {
        'values': [
            {
                'documentation': {
                    'description': 'Broadcasts the waveform you specify to all sites.'
                },
                'name': 'NIDIGITAL_VAL_BROADCAST',
                'value': 2600
            },
            {
                'documentation': {
                    'description': 'Sources unique waveform data to each site.'
                },
                'name': 'NIDIGITAL_VAL_SITE_UNIQUE',
                'value': 2601
            }
        ]
    },
    'TdrEndpointTermination': {
        'values': [
            {
                'documentation': {
                    'description': 'TDR channels are connected to an open circuit.'
                },
                'name': 'NIDIGITAL_VAL_TDR_TO_OPEN',
                'value': 3600
            },
            {
                'documentation': {
                    'description': 'TDR channels are connected to a short to ground.'
                },
                'name': 'NIDIGITAL_VAL_TDR_TO_SHORT_TO_GROUND',
                'value': 3601
            }
        ]
    },
    'TerminationMode': {
        'values': [
            {
                'documentation': {
                    'description': 'The active load provides a constant current to a commutating voltage (Vcom).'
                },
                'name': 'NIDIGITAL_VAL_ACTIVE_LOAD',
                'value': 1200
            },
            {
                'documentation': {
                    'description': 'The pin driver drives Vterm.'
                },
                'name': 'NIDIGITAL_VAL_VTERM',
                'value': 1201
            },
            {
                'documentation': {
                    'description': 'The pin driver is in a non-drive state (in a high-impedance state) and the active load is disabled.'
                },
                'name': 'NIDIGITAL_VAL_HIGH_Z',
                'value': 1202
            }
        ]
    },
    'TimeSetEdgeType': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies the drive on edge of the time set.'
                },
                'name': 'NIDIGITAL_VAL_DRIVE_ON',
                'value': 2800
            },
            {
                'documentation': {
                    'description': 'Specifies the drive data edge of the time set.'
                },
                'name': 'NIDIGITAL_VAL_DRIVE_DATA',
                'value': 2801
            },
            {
                'documentation': {
                    'description': 'Specifies the drive return edge of the time set.'
                },
                'name': 'NIDIGITAL_VAL_DRIVE_RETURN',
                'value': 2802
            },
            {
                'documentation': {
                    'description': 'Specifies the drive off edge of the time set.'
                },
                'name': 'NIDIGITAL_VAL_DRIVE_OFF',
                'value': 2803
            },
            {
                'documentation': {
                    'description': 'Specifies the compare strobe of the time set.'
                },
                'name': 'NIDIGITAL_VAL_COMPARE_STROBE',
                'value': 2804
            },
            {
                'documentation': {
                    'description': 'Specifies the drive data 2 edge of the time set.'
                },
                'name': 'NIDIGITAL_VAL_DRIVE_DATA2',
                'value': 2805
            },
            {
                'documentation': {
                    'description': 'Specifies the drive return 2 edge of the time set.'
                },
                'name': 'NIDIGITAL_VAL_DRIVE_RETURN2',
                'value': 2806
            },
            {
                'documentation': {
                    'description': 'Specifies the compare strobe 2 of the time set.'
                },
                'name': 'NIDIGITAL_VAL_COMPARE_STROBE2',
                'value': 2807
            }
        ]
    },
    'TriggerType': {
        'values': [
            {
                'documentation': {
                    'description': 'Disables the start trigger.'
                },
                'name': 'NIDIGITAL_VAL_NONE',
                'value': 1700
            },
            {
                'documentation': {
                    'description': 'Digital edge trigger.'
                },
                'name': 'NIDIGITAL_VAL_DIGITAL_EDGE',
                'value': 1701
            },
            {
                'documentation': {
                    'description': 'Software start trigger.'
                },
                'name': 'NIDIGITAL_VAL_SOFTWARE',
                'value': 1702
            }
        ]
    },
    'WriteStaticPinState': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies to drive low.'
                },
                'name': 'NIDIGITAL_VAL_0',
                'python_name': 'ZERO',
                'pretty_name': '0',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies to drive high.'
                },
                'name': 'NIDIGITAL_VAL_1',
                'python_name': 'ONE',
                'pretty_name': '1',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies to not drive.'
                },
                'name': 'NIDIGITAL_VAL_X',
                'value': 5
            }
        ]
    }
}
