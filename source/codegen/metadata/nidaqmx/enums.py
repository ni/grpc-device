enums = {
    'ACExcitWireMode': {
        'values': [
            {
                'documentation': {
                    'description': '4-wire.'
                },
                'name': '4_WIRE',
                'value': 4
            },
            {
                'documentation': {
                    'description': '5-wire.'
                },
                'name': '5_WIRE',
                'value': 5
            },
            {
                'documentation': {
                    'description': '6-wire.'
                },
                'name': '6_WIRE',
                'value': 6
            }
        ]
    },
    'AccelChargeSensitivityUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'PicoCoulombs per g.'
                },
                'name': 'PICO_COULOMBS_PER_G',
                'value': 16099
            },
            {
                'documentation': {
                    'description': 'PicoCoulombs per m/s^2.'
                },
                'name': 'PICO_COULOMBS_PER_METERS_PER_SECOND_SQUARED',
                'value': 16100
            },
            {
                'documentation': {
                    'description': 'PicoCoulombs per in/s^2.'
                },
                'name': 'PICO_COULOMBS_PER_INCHES_PER_SECOND_SQUARED',
                'value': 16101
            }
        ]
    },
    'AccelSensitivityUnits1': {
        'values': [
            {
                'documentation': {
                    'description': 'mVolts/g.'
                },
                'name': 'M_VOLTS_PER_G',
                'value': 12509
            },
            {
                'documentation': {
                    'description': 'Volts/g.'
                },
                'name': 'VOLTS_PER_G',
                'value': 12510
            }
        ]
    },
    'AccelUnits2': {
        'values': [
            {
                'documentation': {
                    'description': '1 g is approximately equal to 9.81 m/s/s.'
                },
                'name': 'ACCEL_UNIT_G',
                'value': 10186
            },
            {
                'documentation': {
                    'description': 'Meters per second per second.'
                },
                'name': 'METERS_PER_SECOND_SQUARED',
                'value': 12470
            },
            {
                'documentation': {
                    'description': 'Inches per second per second.'
                },
                'name': 'INCHES_PER_SECOND_SQUARED',
                'value': 12471
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'AngleUnits1': {
        'values': [
            {
                'documentation': {
                    'description': 'Degrees.'
                },
                'name': 'DEGREES',
                'value': 10146
            },
            {
                'documentation': {
                    'description': 'Radians.'
                },
                'name': 'RADIANS',
                'value': 10273
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'AngleUnits2': {
        'values': [
            {
                'documentation': {
                    'description': 'Degrees.'
                },
                'name': 'DEGREES',
                'value': 10146
            },
            {
                'documentation': {
                    'description': 'Radians.'
                },
                'name': 'RADIANS',
                'value': 10273
            },
            {
                'documentation': {
                    'description': 'Ticks.'
                },
                'name': 'TICKS',
                'value': 10304
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'AngularVelocityUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Revolutions per minute.'
                },
                'name': 'RPM',
                'value': 16080
            },
            {
                'documentation': {
                    'description': 'Radians per second.'
                },
                'name': 'RADIANS_PER_SECOND',
                'value': 16081
            },
            {
                'documentation': {
                    'description': 'Degrees per second.'
                },
                'name': 'DEGREES_PER_SECOND',
                'value': 16082
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'BridgeConfiguration1': {
        'values': [
            {
                'documentation': {
                    'description': ' Sensor is a full bridge. If you set DAQmx_AI_Excit_UseForScaling to TRUE,  NI-DAQmx divides the measurement by the excitation value. Many sensors scale  data to native units using scaling of volts per excitation.'
                },
                'name': 'FULL_BRIDGE',
                'value': 10182
            },
            {
                'documentation': {
                    'description': ' Sensor is a half bridge. If you set DAQmx_AI_Excit_UseForScaling to TRUE,  NI-DAQmx divides the measurement by the excitation value. Many sensors scale  data to native units using scaling of volts per excitation.'
                },
                'name': 'HALF_BRIDGE',
                'value': 10187
            },
            {
                'documentation': {
                    'description': ' Sensor is a quarter bridge. If you set DAQmx_AI_Excit_UseForScaling to TRUE,  NI-DAQmx divides the measurement by the excitation value. Many sensors scale  data to native units using scaling of volts per excitation.'
                },
                'name': 'QUARTER_BRIDGE',
                'value': 10270
            },
            {
                'documentation': {
                    'description': 'Sensor is not a Wheatstone bridge.'
                },
                'name': 'NO_BRIDGE',
                'value': 10228
            }
        ]
    },
    'BridgeUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Volts per volt.'
                },
                'name': 'VOLTS_PER_VOLT',
                'value': 15896
            },
            {
                'documentation': {
                    'description': 'Millivolts per volt.'
                },
                'name': 'M_VOLTS_PER_VOLT',
                'value': 15897
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            },
            {
                'documentation': {
                    'description': ' Units defined by TEDS information associated with the channel.'
                },
                'name': 'FROM_TEDS',
                'value': 12516
            }
        ]
    },
    'ChargeUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Coulombs.'
                },
                'name': 'COULOMBS',
                'value': 16102
            },
            {
                'documentation': {
                    'description': 'PicoCoulombs.'
                },
                'name': 'PICO_COULOMBS',
                'value': 16103
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'CountDirection1': {
        'values': [
            {
                'documentation': {
                    'description': 'Increment counter.'
                },
                'name': 'COUNT_UP',
                'value': 10128
            },
            {
                'documentation': {
                    'description': 'Decrement counter.'
                },
                'name': 'COUNT_DOWN',
                'value': 10124
            },
            {
                'documentation': {
                    'description': ' The state of a digital line controls the count direction. Each counter has a  default count direction terminal.'
                },
                'name': 'EXT_CONTROLLED',
                'value': 10326
            }
        ]
    },
    'CounterFrequencyMethod': {
        'values': [
            {
                'documentation': {
                    'description': ' Use one counter that uses a constant timebase to measure the input signal.'
                },
                'name': 'LOW_FREQ_1_CTR',
                'value': 10105
            },
            {
                'documentation': {
                    'description': ' Use two counters, one of which counts pulses of the signal to measure during  the specified measurement time.'
                },
                'name': 'HIGH_FREQ_2_CTR',
                'value': 10157
            },
            {
                'documentation': {
                    'description': ' Use one counter to divide the frequency of the input signal to create a  lower-frequency signal that the second counter can more easily measure.'
                },
                'name': 'LARGE_RNG_2_CTR',
                'value': 10205
            },
            {
                'documentation': {
                    'description': ' Uses one counter with configuration options to control the amount of averaging  or filtering applied to the counter measurements. Set filtering options to  balance measurement accuracy and noise versus latency.'
                },
                'name': 'DYN_AVG',
                'value': 16065
            }
        ]
    },
    'CurrentShuntResistorLocationWithDefault': {
        'values': [
            {
                'name': 'DEFAULT',
                'value': -1
            },
            {
                'name': 'INTERNAL',
                'value': 10200
            },
            {
                'name': 'EXTERNAL',
                'value': 10167
            }
        ]
    },
    'CurrentUnits2': {
        'values': [
            {
                'name': 'AMPS',
                'value': 10342
            },
            {
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'DigitalWidthUnits3': {
        'values': [
            {
                'documentation': {
                    'description': 'Seconds.'
                },
                'name': 'SECONDS',
                'value': 10364
            }
        ]
    },
    'Edge1': {
        'values': [
            {
                'documentation': {
                    'description': 'Rising edge(s).'
                },
                'name': 'RISING',
                'value': 10280
            },
            {
                'documentation': {
                    'description': 'Falling edge(s).'
                },
                'name': 'FALLING',
                'value': 10171
            }
        ]
    },
    'EncoderType2': {
        'values': [
            {
                'documentation': {
                    'description': ' If signal A leads signal B, count the rising edges of signal A. If signal B  leads signal A, count the falling edges of signal A.'
                },
                'name': 'X_1',
                'value': 10090
            },
            {
                'documentation': {
                    'description': 'Count the rising and falling edges of signal A.'
                },
                'name': 'X_2',
                'value': 10091
            },
            {
                'documentation': {
                    'description': 'Count the rising and falling edges of signal A and signal B.'
                },
                'name': 'X_4',
                'value': 10092
            },
            {
                'documentation': {
                    'description': ' Increment the count on rising edges of signal A. Decrement the count on rising  edges of signal B.'
                },
                'name': 'TWO_PULSE_COUNTING',
                'value': 10313
            }
        ]
    },
    'EncoderZIndexPhase1': {
        'values': [
            {
                'documentation': {
                    'description': 'Reset the measurement when signal A and signal B are high.'
                },
                'name': 'A_HIGH_B_HIGH',
                'value': 10040
            },
            {
                'documentation': {
                    'description': ' Reset the measurement when signal A is high and signal B is low.'
                },
                'name': 'A_HIGH_B_LOW',
                'value': 10041
            },
            {
                'documentation': {
                    'description': ' Reset the measurement when signal A is low and signal B high.'
                },
                'name': 'A_LOW_B_HIGH',
                'value': 10042
            },
            {
                'documentation': {
                    'description': 'Reset the measurement when signal A and signal B are low.'
                },
                'name': 'A_LOW_B_LOW',
                'value': 10043
            }
        ]
    },
    'ExcitationSource': {
        'values': [
            {
                'documentation': {
                    'description': ' Use the built-in excitation source of the device. If you select this value, you  must specify the amount of excitation.'
                },
                'name': 'INTERNAL',
                'value': 10200
            },
            {
                'documentation': {
                    'description': ' Use an excitation source other than the built-in excitation source of the  device. If you select this value, you must specify the amount of excitation.'
                },
                'name': 'EXTERNAL',
                'value': 10167
            },
            {
                'documentation': {
                    'description': 'Supply no excitation to the channel.'
                },
                'name': 'NONE',
                'value': 10230
            }
        ]
    },
    'FrequencyUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Hertz.'
                },
                'name': 'HZ',
                'value': 10373
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'FrequencyUnits2': {
        'values': [
            {
                'documentation': {
                    'description': 'Hertz.'
                },
                'name': 'HZ',
                'value': 10373
            }
        ]
    },
    'FrequencyUnits3': {
        'values': [
            {
                'documentation': {
                    'description': 'Hertz.'
                },
                'name': 'HZ',
                'value': 10373
            },
            {
                'documentation': {
                    'description': 'Timebase ticks.'
                },
                'name': 'TICKS',
                'value': 10304
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'FuncGenType': {
        'values': [
            {
                'documentation': {
                    'description': 'Sine wave.'
                },
                'name': 'SINE',
                'value': 14751
            },
            {
                'documentation': {
                    'description': 'Triangle wave.'
                },
                'name': 'TRIANGLE',
                'value': 14752
            },
            {
                'documentation': {
                    'description': 'Square wave.'
                },
                'name': 'SQUARE',
                'value': 14753
            },
            {
                'documentation': {
                    'description': 'Sawtooth wave.'
                },
                'name': 'SAWTOOTH',
                'value': 14754
            }
        ]
    },
    'GpsSignalType1': {
        'values': [
            {
                'documentation': {
                    'description': ' Use the IRIG-B synchronization method. The GPS receiver sends one  synchronization pulse per second, as well as information about the number of  days, hours, minutes, and seconds that elapsed since the beginning of the  current year.'
                },
                'name': 'IRIGB',
                'value': 10070
            },
            {
                'documentation': {
                    'description': ' Use the PPS synchronization method. The GPS receiver sends one synchronization  pulse per second, but does not send any timing information. The timestamp  measurement returns the number of seconds that elapsed since the device powered  up unless you set DAQmx_CI_Timestamp_InitialSeconds.'
                },
                'name': 'PPS',
                'value': 10080
            },
            {
                'documentation': {
                    'description': ' Do not synchronize the counter to a GPS receiver. The timestamp measurement  returns the number of seconds that elapsed since the device powered up unless  you set  DAQmx_CI_Timestamp_InitialSeconds.'
                },
                'name': 'NONE',
                'value': 10230
            }
        ]
    },
    'GroupBy': {
        'values': [
            {
                'name': 'GROUP_BY_CHANNEL',
                'value': 0
            },
            {
                'name': 'GROUP_BY_SCAN_NUMBER',
                'value': 1
            }
        ]
    },
    'InputTermCfgWithDefault': {
        'values': [
            {
                'name': 'CFG_DEFAULT',
                'value': -1
            },
            {
                'name': 'RSE',
                'value': 10083
            },
            {
                'name': 'NRSE',
                'value': 10078
            },
            {
                'name': 'DIFF',
                'value': 10106
            },
            {
                'name': 'PSEUDO_DIFF',
                'value': 12529
            }
        ]
    },
    'LVDTSensitivityUnits1': {
        'values': [
            {
                'documentation': {
                    'description': 'mVolts/Volt/mMeter.'
                },
                'name': 'M_VOLTS_PER_VOLT_PER_MILLIMETER',
                'value': 12506
            },
            {
                'documentation': {
                    'description': 'mVolts/Volt/0.001 Inch.'
                },
                'name': 'M_VOLTS_PER_VOLT_PER_MILLI_INCH',
                'value': 12505
            }
        ]
    },
    'LengthUnits2': {
        'values': [
            {
                'documentation': {
                    'description': 'Meters.'
                },
                'name': 'METERS',
                'value': 10219
            },
            {
                'documentation': {
                    'description': 'Inches.'
                },
                'name': 'INCHES',
                'value': 10379
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'LengthUnits3': {
        'values': [
            {
                'documentation': {
                    'description': 'Meters.'
                },
                'name': 'METERS',
                'value': 10219
            },
            {
                'documentation': {
                    'description': 'Inches.'
                },
                'name': 'INCHES',
                'value': 10379
            },
            {
                'documentation': {
                    'description': 'Ticks.'
                },
                'name': 'TICKS',
                'value': 10304
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'Level1': {
        'values': [
            {
                'documentation': {
                    'description': 'High state.'
                },
                'name': 'HIGH',
                'value': 10192
            },
            {
                'documentation': {
                    'description': 'Low state.'
                },
                'name': 'LOW',
                'value': 10214
            }
        ]
    },
    'LineGrouping': {
        'values': [
            {
                'name': 'CHAN_FOR_ALL_LINES',
                'value': 1
            },
            {
                'name': 'CHAN_PER_LINE',
                'value': 0
            }
        ]
    },
    'RVDTSensitivityUnits1': {
        'values': [
            {
                'documentation': {
                    'description': 'mVolts/Volt/Degree.'
                },
                'name': 'M_VOLTS_PER_VOLT_PER_DEGREE',
                'value': 12507
            },
            {
                'documentation': {
                    'description': 'mVolts/Volt/Radian.'
                },
                'name': 'M_VOLTS_PER_VOLT_PER_RADIAN',
                'value': 12508
            }
        ]
    },
    'ResistanceConfiguration': {
        'values': [
            {
                'documentation': {
                    'description': '2-wire mode.'
                },
                'name': '2_WIRE',
                'value': 2
            },
            {
                'documentation': {
                    'description': '3-wire mode.'
                },
                'name': '3_WIRE',
                'value': 3
            },
            {
                'documentation': {
                    'description': '4-wire mode.'
                },
                'name': '4_WIRE',
                'value': 4
            }
        ]
    },
    'ResistanceUnits2': {
        'values': [
            {
                'name': 'OHMS',
                'value': 10384
            },
            {
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'SoundPressureUnits1': {
        'values': [
            {
                'documentation': {
                    'description': 'Pascals.'
                },
                'name': 'PASCALS',
                'value': 10081
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'StrainGageBridgeType1': {
        'values': [
            {
                'documentation': {
                    'description': ' Four active gages with two pairs subjected to equal and opposite strains.'
                },
                'name': 'FULL_BRIDGE_I',
                'value': 10183
            },
            {
                'documentation': {
                    'description': ' Four active gages with two aligned with maximum principal strain and two  Poisson gages in adjacent arms.'
                },
                'name': 'FULL_BRIDGE_II',
                'value': 10184
            },
            {
                'documentation': {
                    'description': ' Four active gages with two aligned with maximum principal strain and two  Poisson gages in opposite arms.'
                },
                'name': 'FULL_BRIDGE_III',
                'value': 10185
            },
            {
                'documentation': {
                    'description': ' Two active gages with one aligned with maximum principal strain and one Poisson  gage.'
                },
                'name': 'HALF_BRIDGE_I',
                'value': 10188
            },
            {
                'documentation': {
                    'description': 'Two active gages with equal and opposite strains.'
                },
                'name': 'HALF_BRIDGE_II',
                'value': 10189
            },
            {
                'documentation': {
                    'description': 'Single active gage.'
                },
                'name': 'QUARTER_BRIDGE_I',
                'value': 10271
            },
            {
                'documentation': {
                    'description': 'Single active gage and one dummy gage.'
                },
                'name': 'QUARTER_BRIDGE_II',
                'value': 10272
            }
        ]
    },
    'StrainUnits1': {
        'values': [
            {
                'documentation': {
                    'description': 'Strain.'
                },
                'name': 'STRAIN',
                'value': 10299
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'TEDSUnits': {
        'values': [
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            },
            {
                'documentation': {
                    'description': ' Units defined by TEDS information associated with the channel.'
                },
                'name': 'FROM_TEDS',
                'value': 12516
            }
        ]
    },
    'TaskControlAction': {
        'values': [
            {
                'name': 'TASK_START',
                'value': 0
            },
            {
                'name': 'TASK_STOP',
                'value': 1
            },
            {
                'name': 'TASK_VERIFY',
                'value': 2
            },
            {
                'name': 'TASK_COMMIT',
                'value': 3
            },
            {
                'name': 'TASK_RESERVE',
                'value': 4
            },
            {
                'name': 'TASK_UNRESERVE',
                'value': 5
            },
            {
                'name': 'TASK_ABORT',
                'value': 6
            }
        ]
    },
    'TimeUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Seconds.'
                },
                'name': 'SECONDS',
                'value': 10364
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'TimeUnits3': {
        'values': [
            {
                'documentation': {
                    'description': 'Seconds.'
                },
                'name': 'SECONDS',
                'value': 10364
            },
            {
                'documentation': {
                    'description': 'Timebase ticks.'
                },
                'name': 'TICKS',
                'value': 10304
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'VelocityIEPESensorSensitivityUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Millivolts per millimeter per second.'
                },
                'name': 'MILLIVOLTS_PER_MILLIMETER_PER_SECOND',
                'value': 15963
            },
            {
                'documentation': {
                    'description': 'Millivolts per inch per second.'
                },
                'name': 'MILLI_VOLTS_PER_INCH_PER_SECOND',
                'value': 15964
            }
        ]
    },
    'VelocityUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Meters per second.'
                },
                'name': 'METERS_PER_SECOND',
                'value': 15959
            },
            {
                'documentation': {
                    'description': 'Inches per second.'
                },
                'name': 'INCHES_PER_SECOND',
                'value': 15960
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'VoltageUnits2': {
        'values': [
            {
                'documentation': {
                    'description': 'Volts.'
                },
                'name': 'VOLTS',
                'value': 10348
            },
            {
                'documentation': {
                    'description': ' Units a custom scale specifies. If you select this value, you must specify a  custom scale name.'
                },
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    }
}
