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
    'AIMeasurementType': {
        'values': [
            {
                'documentation': {
                    'description': 'Voltage measurement.'
                },
                'name': 'VOLTAGE',
                'value': 10322
            },
            {
                'documentation': {
                    'description': 'Voltage RMS measurement.'
                },
                'name': 'VOLTAGE_RMS',
                'value': 10350
            },
            {
                'documentation': {
                    'description': 'Current measurement.'
                },
                'name': 'CURRENT',
                'value': 10134
            },
            {
                'documentation': {
                    'description': 'Current RMS measurement.'
                },
                'name': 'CURRENT_RMS',
                'value': 10351
            },
            {
                'documentation': {
                    'description': ' Voltage measurement with an excitation source. You can use this measurement  type for custom sensors that require excitation, but you must use a custom  scale to scale the measured voltage.'
                },
                'name': 'VOLTAGE_CUSTOM_WITH_EXCITATION',
                'value': 10323
            },
            {
                'documentation': {
                    'description': 'Measure voltage ratios from a Wheatstone bridge.'
                },
                'name': 'BRIDGE',
                'value': 15908
            },
            {
                'documentation': {
                    'description': ' Frequency measurement using a frequency to voltage converter.'
                },
                'name': 'FREQ_VOLTAGE',
                'value': 10181
            },
            {
                'documentation': {
                    'description': 'Resistance measurement.'
                },
                'name': 'RESISTANCE',
                'value': 10278
            },
            {
                'documentation': {
                    'description': 'Temperature measurement using a thermocouple.'
                },
                'name': 'TEMP_TC',
                'value': 10303
            },
            {
                'documentation': {
                    'description': 'Temperature measurement using a thermistor.'
                },
                'name': 'TEMP_THRMSTR',
                'value': 10302
            },
            {
                'documentation': {
                    'description': 'Temperature measurement using an RTD.'
                },
                'name': 'TEMP_RTD',
                'value': 10301
            },
            {
                'documentation': {
                    'description': ' Temperature measurement using a built-in sensor on a terminal block or device.  On SCXI modules, for example, this could be the CJC sensor.'
                },
                'name': 'TEMP_BUILT_IN_SENSOR',
                'value': 10311
            },
            {
                'documentation': {
                    'description': 'Strain measurement.'
                },
                'name': 'STRAIN_GAGE',
                'value': 10300
            },
            {
                'documentation': {
                    'description': 'Strain measurement using a rosette strain gage.'
                },
                'name': 'ROSETTE_STRAIN_GAGE',
                'value': 15980
            },
            {
                'documentation': {
                    'description': 'Position measurement using an LVDT.'
                },
                'name': 'POSITION_LVDT',
                'value': 10352
            },
            {
                'documentation': {
                    'description': 'Position measurement using an RVDT.'
                },
                'name': 'POSITION_RVDT',
                'value': 10353
            },
            {
                'documentation': {
                    'description': 'Position measurement using an eddy current proximity probe.'
                },
                'name': 'POSITION_EDDY_CURRENT_PROXIMITY_PROBE',
                'value': 14835
            },
            {
                'documentation': {
                    'description': 'Acceleration measurement using an accelerometer.'
                },
                'name': 'ACCELEROMETER',
                'value': 10356
            },
            {
                'documentation': {
                    'description': 'Acceleration measurement using a charge-based sensor.'
                },
                'name': 'ACCELERATION_CHARGE',
                'value': 16104
            },
            {
                'documentation': {
                    'description': ' Acceleration measurement using a 4 wire DC voltage based sensor.'
                },
                'name': 'ACCELERATION_4_WIRE_DC_VOLTAGE',
                'value': 16106
            },
            {
                'documentation': {
                    'description': 'Velocity measurement using an IEPE Sensor.'
                },
                'name': 'VELOCITY_IEPE_SENSOR',
                'value': 15966
            },
            {
                'documentation': {
                    'description': 'Force measurement using a bridge-based sensor.'
                },
                'name': 'FORCE_BRIDGE',
                'value': 15899
            },
            {
                'documentation': {
                    'description': 'Force measurement using an IEPE Sensor.'
                },
                'name': 'FORCE_IEPE_SENSOR',
                'value': 15895
            },
            {
                'documentation': {
                    'description': 'Pressure measurement using a bridge-based sensor.'
                },
                'name': 'PRESSURE_BRIDGE',
                'value': 15902
            },
            {
                'documentation': {
                    'description': 'Sound pressure measurement using a microphone.'
                },
                'name': 'SOUND_PRESSURE_MICROPHONE',
                'value': 10354
            },
            {
                'documentation': {
                    'description': 'Torque measurement using a bridge-based sensor.'
                },
                'name': 'TORQUE_BRIDGE',
                'value': 15905
            },
            {
                'documentation': {
                    'description': 'Measurement type defined by TEDS.'
                },
                'name': 'TEDS_SENSOR',
                'value': 12531
            },
            {
                'documentation': {
                    'description': 'Charge measurement.'
                },
                'name': 'CHARGE',
                'value': 16105
            }
        ]
    },
    'AOOutputChannelType': {
        'values': [
            {
                'documentation': {
                    'description': 'Voltage generation.'
                },
                'name': 'VOLTAGE',
                'value': 10322
            },
            {
                'documentation': {
                    'description': 'Current generation.'
                },
                'name': 'CURRENT',
                'value': 10134
            },
            {
                'documentation': {
                    'description': 'Function generation.'
                },
                'name': 'FUNC_GEN',
                'value': 14750
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
    'AcquisitionType': {
        'values': [
            {
                'documentation': {
                    'description': 'Acquire or generate a finite number of samples.'
                },
                'name': 'FINITE_SAMPS',
                'value': 10178
            },
            {
                'documentation': {
                    'description': 'Acquire or generate samples until you stop the task.'
                },
                'name': 'CONT_SAMPS',
                'value': 10123
            },
            {
                'documentation': {
                    'description': ' Acquire or generate samples continuously using hardware timing without a  buffer. Hardware timed single point sample mode is supported only for the  sample clock and change detection timing types.'
                },
                'name': 'HW_TIMED_SINGLE_POINT',
                'value': 12522
            }
        ]
    },
    'AltRef': {
        'values': [
            {
                'name': 'MSL',
                'value': 16005
            },
            {
                'name': 'HAE',
                'value': 16006
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
    'AntStatus': {
        'values': [
            {
                'name': 'UNKNOWN',
                'value': 12588
            },
            {
                'name': 'NORMAL',
                'value': 10459
            },
            {
                'name': 'ABSENT',
                'value': 15994
            },
            {
                'name': 'OVERCURRENT',
                'value': 15995
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
    'BridgeElectricalUnits': {
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
            }
        ]
    },
    'BridgePhysicalUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Newtons.'
                },
                'name': 'NEWTONS',
                'value': 15875
            },
            {
                'documentation': {
                    'description': 'Pounds.'
                },
                'name': 'POUNDS',
                'value': 15876
            },
            {
                'documentation': {
                    'description': 'kilograms-force.'
                },
                'name': 'KILOGRAM_FORCE',
                'value': 15877
            },
            {
                'documentation': {
                    'description': 'Pascals.'
                },
                'name': 'PASCALS',
                'value': 10081
            },
            {
                'documentation': {
                    'description': 'Pounds per square inch.'
                },
                'name': 'POUNDS_PER_SQUARE_INCH',
                'value': 15879
            },
            {
                'documentation': {
                    'description': 'Bar.'
                },
                'name': 'BAR',
                'value': 15880
            },
            {
                'documentation': {
                    'description': 'Newton metres.'
                },
                'name': 'NEWTON_METERS',
                'value': 15881
            },
            {
                'documentation': {
                    'description': 'Ounce-inches.'
                },
                'name': 'INCH_OUNCES',
                'value': 15882
            },
            {
                'documentation': {
                    'description': 'Pound-inches.'
                },
                'name': 'INCH_POUNDS',
                'value': 15883
            },
            {
                'documentation': {
                    'description': 'Pound-feet.'
                },
                'name': 'FOOT_POUNDS',
                'value': 15884
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
    'BusType': {
        'values': [
            {
                'documentation': {
                    'description': 'PCI.'
                },
                'name': 'PCI',
                'value': 12582
            },
            {
                'documentation': {
                    'description': 'PCI Express.'
                },
                'name': 'PC_IE',
                'value': 13612
            },
            {
                'documentation': {
                    'description': 'PXI.'
                },
                'name': 'PXI',
                'value': 12583
            },
            {
                'documentation': {
                    'description': 'PXI Express.'
                },
                'name': 'PX_IE',
                'value': 14706
            },
            {
                'documentation': {
                    'description': 'SCXI.'
                },
                'name': 'SCXI',
                'value': 12584
            },
            {
                'documentation': {
                    'description': 'SCC.'
                },
                'name': 'SCC',
                'value': 14707
            },
            {
                'documentation': {
                    'description': 'PC Card/PCMCIA.'
                },
                'name': 'PC_CARD',
                'value': 12585
            },
            {
                'documentation': {
                    'description': 'USB.'
                },
                'name': 'USB',
                'value': 12586
            },
            {
                'documentation': {
                    'description': 'CompactDAQ.'
                },
                'name': 'COMPACT_DAQ',
                'value': 14637
            },
            {
                'documentation': {
                    'description': 'CompactRIO.'
                },
                'name': 'COMPACT_RIO',
                'value': 16143
            },
            {
                'documentation': {
                    'description': 'TCP/IP.'
                },
                'name': 'TCPIP',
                'value': 14828
            },
            {
                'documentation': {
                    'description': 'Unknown bus type.'
                },
                'name': 'UNKNOWN',
                'value': 12588
            },
            {
                'documentation': {
                    'description': 'SwitchBlock.'
                },
                'name': 'SWITCH_BLOCK',
                'value': 15870
            }
        ]
    },
    'CIMeasurementType': {
        'values': [
            {
                'documentation': {
                    'description': 'Count edges of a digital signal.'
                },
                'name': 'COUNT_EDGES',
                'value': 10125
            },
            {
                'documentation': {
                    'description': 'Measure the frequency of a digital signal.'
                },
                'name': 'FREQ',
                'value': 10179
            },
            {
                'documentation': {
                    'description': 'Measure the period of a digital signal.'
                },
                'name': 'PERIOD',
                'value': 10256
            },
            {
                'documentation': {
                    'description': 'Measure the width of a pulse of a digital signal.'
                },
                'name': 'PULSE_WIDTH',
                'value': 10359
            },
            {
                'documentation': {
                    'description': ' Measure the time between state transitions of a digital signal.'
                },
                'name': 'SEMI_PERIOD',
                'value': 10289
            },
            {
                'documentation': {
                    'description': ' Pulse measurement, returning the result as frequency and duty cycle.'
                },
                'name': 'PULSE_FREQUENCY',
                'value': 15864
            },
            {
                'documentation': {
                    'description': ' Pulse measurement, returning the result as high time and low time.'
                },
                'name': 'PULSE_TIME',
                'value': 15865
            },
            {
                'documentation': {
                    'description': ' Pulse measurement, returning the result as high ticks and low ticks.'
                },
                'name': 'PULSE_TICKS',
                'value': 15866
            },
            {
                'documentation': {
                    'description': 'Measure the duty cycle of a digital signal.'
                },
                'name': 'DUTY_CYCLE',
                'value': 16070
            },
            {
                'documentation': {
                    'description': 'Angular position measurement using an angular encoder.'
                },
                'name': 'POSITION_ANG_ENCODER',
                'value': 10360
            },
            {
                'documentation': {
                    'description': 'Linear position measurement using a linear encoder.'
                },
                'name': 'POSITION_LIN_ENCODER',
                'value': 10361
            },
            {
                'documentation': {
                    'description': 'Angular velocity measurement using an angular encoder.'
                },
                'name': 'VELOCITY_ANG_ENCODER',
                'value': 16078
            },
            {
                'documentation': {
                    'description': 'Linear velocity measurement using a linear encoder.'
                },
                'name': 'VELOCITY_LIN_ENCODER',
                'value': 16079
            },
            {
                'documentation': {
                    'description': 'Measure time between edges of two digital signals.'
                },
                'name': 'TWO_EDGE_SEP',
                'value': 10267
            },
            {
                'documentation': {
                    'description': ' Timestamp measurement, synchronizing the counter to a GPS receiver.'
                },
                'name': 'GPS_TIMESTAMP',
                'value': 10362
            }
        ]
    },
    'CJCSource1': {
        'values': [
            {
                'documentation': {
                    'description': ' Use a cold-junction compensation channel built into the terminal block.'
                },
                'name': 'BUILT_IN',
                'value': 10200
            },
            {
                'documentation': {
                    'description': 'You must specify the cold-junction temperature.'
                },
                'name': 'CONST_VAL',
                'value': 10116
            },
            {
                'documentation': {
                    'description': 'Use a channel for cold-junction compensation.'
                },
                'name': 'CHAN',
                'value': 10113
            }
        ]
    },
    'COOutputType': {
        'values': [
            {
                'documentation': {
                    'description': ' Generate pulses defined by the time the pulse is at a low state and the time  the pulse is at a high state.'
                },
                'name': 'PULSE_TIME',
                'value': 10269
            },
            {
                'documentation': {
                    'description': 'Generate digital pulses defined by frequency and duty cycle.'
                },
                'name': 'PULSE_FREQ',
                'value': 10119
            },
            {
                'documentation': {
                    'description': ' Generate digital pulses defined by the number of timebase ticks that the pulse  is at a low state and the number of timebase ticks that the pulse is at a high  state.'
                },
                'name': 'PULSE_TICKS',
                'value': 10268
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
    'Coupling1': {
        'values': [
            {
                'documentation': {
                    'description': 'Remove the DC offset from the signal.'
                },
                'name': 'AC',
                'value': 10045
            },
            {
                'documentation': {
                    'description': 'Allow NI-DAQmx to measure all of the signal.'
                },
                'name': 'DC',
                'value': 10050
            },
            {
                'documentation': {
                    'description': ' Remove the signal from the measurement and measure only ground.'
                },
                'name': 'GND',
                'value': 10066
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
    'DigitalLineState': {
        'values': [
            {
                'documentation': {
                    'description': 'Logic high.'
                },
                'name': 'HIGH',
                'value': 10192
            },
            {
                'documentation': {
                    'description': 'Logic low.'
                },
                'name': 'LOW',
                'value': 10214
            },
            {
                'documentation': {
                    'description': ' High-impedance state. You can select this state only on devices with  bidirectional lines.  You cannot select this state for dedicated digital output  lines. On some devices, you can select this value only for entire ports.'
                },
                'name': 'TRISTATE',
                'value': 10310
            },
            {
                'documentation': {
                    'description': ' Do not change the state of the lines. On some devices, you can select this  value only for entire ports.'
                },
                'name': 'NO_CHANGE',
                'value': 10160
            }
        ]
    },
    'DigitalPatternCondition1': {
        'values': [
            {
                'documentation': {
                    'description': ' Trigger when the physical channels match the specified pattern.'
                },
                'name': 'PATTERN_MATCHES',
                'value': 10254
            },
            {
                'documentation': {
                    'description': ' Trigger when the physical channels do not match the specified pattern.'
                },
                'name': 'PATTERN_DOES_NOT_MATCH',
                'value': 10253
            }
        ]
    },
    'DigitalPowerUpChannelType': {
        'values': [
            {
                'documentation': {
                    'description': 'High logic.'
                },
                'name': 'HIGH',
                'value': 10192
            },
            {
                'documentation': {
                    'description': 'Low logic.'
                },
                'name': 'LOW',
                'value': 10214
            },
            {
                'documentation': {
                    'description': 'High-impedance state. You can select this state only on devices with bidirectional ports, and you can select it only for entire ports. You cannot select this state for dedicated digital output lines.'
                },
                'name': 'TRISTATE',
                'value': 10310
            }
        ]
    },
    'DigitalPullUpPullDownState': {
        'values': [
            {
                'name': 'PULL_UP',
                'value': 15950
            },
            {
                'name': 'PULL_DOWN',
                'value': 15951
            },
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
    'EddyCurrentProxProbeSensitivityUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'mVolts/mil.'
                },
                'name': 'M_VOLTS_PER_MIL',
                'value': 14836
            },
            {
                'documentation': {
                    'description': 'Volts/mil.'
                },
                'name': 'VOLTS_PER_MIL',
                'value': 14837
            },
            {
                'documentation': {
                    'description': 'mVolts/mMeter.'
                },
                'name': 'M_VOLTS_PER_MILLIMETER',
                'value': 14838
            },
            {
                'documentation': {
                    'description': 'Volts/mMeter.'
                },
                'name': 'VOLTS_PER_MILLIMETER',
                'value': 14839
            },
            {
                'documentation': {
                    'description': 'mVolts/micron.'
                },
                'name': 'M_VOLTS_PER_MICRON',
                'value': 14840
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
    'EveryNSamplesEventType': {
        'values': [
            {
                'name': 'ACQUIRED_INTO_BUFFER',
                'value': 1
            },
            {
                'name': 'TRANSFERRED_FROM_BUFFER',
                'value': 2
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
    'FilterType2': {
        'values': [
            {
                'documentation': {
                    'description': 'Lowpass filter.'
                },
                'name': 'LOWPASS',
                'value': 16071
            },
            {
                'documentation': {
                    'description': 'Highpass filter.'
                },
                'name': 'HIGHPASS',
                'value': 16072
            },
            {
                'documentation': {
                    'description': 'Bandpass filter.'
                },
                'name': 'BANDPASS',
                'value': 16073
            },
            {
                'documentation': {
                    'description': 'Notch filter.'
                },
                'name': 'NOTCH',
                'value': 16074
            },
            {
                'documentation': {
                    'description': 'Custom filter.'
                },
                'name': 'CUSTOM',
                'value': 10137
            }
        ]
    },
    'ForceIEPESensorSensitivityUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Millivolts per newton.'
                },
                'name': 'M_VOLTS_PER_NEWTON',
                'value': 15891
            },
            {
                'documentation': {
                    'description': 'Millivolts per pound.'
                },
                'name': 'M_VOLTS_PER_POUND',
                'value': 15892
            }
        ]
    },
    'ForceIEPEUnits': {
        'values': [
            {
                'name': 'NEWTONS',
                'value': 15875
            },
            {
                'name': 'POUNDS',
                'value': 15876
            },
            {
                'name': 'FROM_CUSTOM_SCALE',
                'value': 10065
            }
        ]
    },
    'ForceUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Newtons.'
                },
                'name': 'NEWTONS',
                'value': 15875
            },
            {
                'documentation': {
                    'description': 'Pounds.'
                },
                'name': 'POUNDS',
                'value': 15876
            },
            {
                'documentation': {
                    'description': 'Kilograms-force.'
                },
                'name': 'KILOGRAM_FORCE',
                'value': 15877
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
    'InvertPolarity': {
        'values': [
            {
                'name': 'DO_NOT_INVERT_POLARITY',
                'value': 0
            },
            {
                'name': 'INVERT_POLARITY',
                'value': 1
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
                'name': 'CHAN_PER_LINE',
                'value': 0
            },
            {
                'name': 'CHAN_FOR_ALL_LINES',
                'value': 1
            }
        ]
    },
    'LoggingMode': {
        'values': [
            {
                'documentation': {
                    'description': 'Disable logging for the task.'
                },
                'name': 'OFF',
                'value': 10231
            },
            {
                'documentation': {
                    'description': ' Enable logging for the task. You cannot read data using an NI-DAQmx Read  function when using this mode. If you require access to the data, read from the  TDMS file.'
                },
                'name': 'LOG',
                'value': 15844
            },
            {
                'documentation': {
                    'description': ' Enable both logging and reading data for the task. You must use an NI-DAQmx  Read function to read samples for NI-DAQmx to stream them to disk.'
                },
                'name': 'LOG_AND_READ',
                'value': 15842
            }
        ]
    },
    'LoggingOperation': {
        'values': [
            {
                'documentation': {
                    'description': ' Open an existing TDMS file, and append data to that file. If the file does not  exist, NI-DAQmx returns an error.'
                },
                'name': 'OPEN',
                'value': 10437
            },
            {
                'documentation': {
                    'description': ' Open an existing TDMS file, and append data to that file. If the file does not  exist, NI-DAQmx creates a new TDMS file.'
                },
                'name': 'OPEN_OR_CREATE',
                'value': 15846
            },
            {
                'documentation': {
                    'description': 'Create a new TDMS file, or replace an existing TDMS file.'
                },
                'name': 'CREATE_OR_REPLACE',
                'value': 15847
            },
            {
                'documentation': {
                    'description': ' Create a new TDMS file. If the file already exists, NI-DAQmx returns an error.'
                },
                'name': 'CREATE',
                'value': 15848
            }
        ]
    },
    'LogicFamily': {
        'values': [
            {
                'documentation': {
                    'description': 'Compatible with 2.5 V CMOS signals.'
                },
                'name': '2POINT_5_V',
                'value': 14620
            },
            {
                'documentation': {
                    'description': 'Compatible with LVTTL signals.'
                },
                'name': '3POINT_3_V',
                'value': 14621
            },
            {
                'documentation': {
                    'description': 'Compatible with TTL and 5 V CMOS signals.'
                },
                'name': '5_V',
                'value': 14619
            }
        ]
    },
    'NavMeasurementType': {
        'values': [
            {
                'name': 'ALTITUDE',
                'value': 15997
            },
            {
                'name': 'LONGITUDE',
                'value': 15998
            },
            {
                'name': 'LATITUDE',
                'value': 15999
            },
            {
                'name': 'SPEED_OVER_GROUND',
                'value': 16000
            },
            {
                'name': 'TRACK',
                'value': 16001
            },
            {
                'name': 'TIMESTAMP',
                'value': 15986
            },
            {
                'name': 'VERT_VELOCITY',
                'value': 16003
            }
        ]
    },
    'NavMode': {
        'values': [
            {
                'name': 'MOBILE',
                'value': 15989
            },
            {
                'name': 'STATIONARY_WITH_SURVEY',
                'value': 15990
            },
            {
                'name': 'STATIONARY_WITH_PRESET_LOCATION',
                'value': 15991
            }
        ]
    },
    'Polarity2': {
        'values': [
            {
                'documentation': {
                    'description': 'High state is the active state.'
                },
                'name': 'ACTIVE_HIGH',
                'value': 10095
            },
            {
                'documentation': {
                    'description': 'Low state is the active state.'
                },
                'name': 'ACTIVE_LOW',
                'value': 10096
            }
        ]
    },
    'PowerUpChannelType': {
        'values': [
            {
                'name': 'CHANNEL_VOLTAGE',
                'value': 0
            },
            {
                'name': 'CHANNEL_CURRENT',
                'value': 1
            }
        ]
    },
    'PressureUnits': {
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
                    'description': 'Pounds per square inch.'
                },
                'name': 'POUNDS_PER_SQUARE_INCH',
                'value': 15879
            },
            {
                'documentation': {
                    'description': 'Bar.'
                },
                'name': 'BAR',
                'value': 15880
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
    'ProductCategory': {
        'values': [
            {
                'documentation': {
                    'description': 'M Series DAQ.'
                },
                'name': 'M_SERIES_DAQ',
                'value': 14643
            },
            {
                'documentation': {
                    'description': 'X Series DAQ.'
                },
                'name': 'X_SERIES_DAQ',
                'value': 15858
            },
            {
                'documentation': {
                    'description': 'E Series DAQ.'
                },
                'name': 'E_SERIES_DAQ',
                'value': 14642
            },
            {
                'documentation': {
                    'description': 'S Series DAQ.'
                },
                'name': 'S_SERIES_DAQ',
                'value': 14644
            },
            {
                'documentation': {
                    'description': 'B Series DAQ.'
                },
                'name': 'B_SERIES_DAQ',
                'value': 14662
            },
            {
                'documentation': {
                    'description': 'SC Series DAQ.'
                },
                'name': 'SC_SERIES_DAQ',
                'value': 14645
            },
            {
                'documentation': {
                    'description': 'USB DAQ.'
                },
                'name': 'USBDAQ',
                'value': 14646
            },
            {
                'documentation': {
                    'description': 'AO Series.'
                },
                'name': 'AO_SERIES',
                'value': 14647
            },
            {
                'documentation': {
                    'description': 'Digital I/O.'
                },
                'name': 'DIGITAL_IO',
                'value': 14648
            },
            {
                'documentation': {
                    'description': 'TIO Series.'
                },
                'name': 'TIO_SERIES',
                'value': 14661
            },
            {
                'documentation': {
                    'description': 'Dynamic Signal Acquisition.'
                },
                'name': 'DYNAMIC_SIGNAL_ACQUISITION',
                'value': 14649
            },
            {
                'documentation': {
                    'description': 'Switches.'
                },
                'name': 'SWITCHES',
                'value': 14650
            },
            {
                'documentation': {
                    'description': 'CompactDAQ chassis.'
                },
                'name': 'COMPACT_DAQ_CHASSIS',
                'value': 14658
            },
            {
                'documentation': {
                    'description': 'CompactRIO Chassis.'
                },
                'name': 'COMPACT_RIO_CHASSIS',
                'value': 16144
            },
            {
                'documentation': {
                    'description': 'C Series I/O module.'
                },
                'name': 'C_SERIES_MODULE',
                'value': 14659
            },
            {
                'documentation': {
                    'description': 'SCXI module.'
                },
                'name': 'SCXI_MODULE',
                'value': 14660
            },
            {
                'documentation': {
                    'description': 'SCC Connector Block.'
                },
                'name': 'SCC_CONNECTOR_BLOCK',
                'value': 14704
            },
            {
                'documentation': {
                    'description': 'SCC Module.'
                },
                'name': 'SCC_MODULE',
                'value': 14705
            },
            {
                'documentation': {
                    'description': 'NI ELVIS.'
                },
                'name': 'NIELVIS',
                'value': 14755
            },
            {
                'documentation': {
                    'description': 'Network DAQ.'
                },
                'name': 'NETWORK_DAQ',
                'value': 14829
            },
            {
                'documentation': {
                    'description': 'SC Express.'
                },
                'name': 'SC_EXPRESS',
                'value': 15886
            },
            {
                'documentation': {
                    'description': 'FieldDAQ.'
                },
                'name': 'FIELD_DAQ',
                'value': 16151
            },
            {
                'documentation': {
                    'description': 'Unknown category.'
                },
                'name': 'UNKNOWN',
                'value': 12588
            }
        ]
    },
    'RTDType1': {
        'values': [
            {
                'documentation': {
                    'description': 'Pt3750.'
                },
                'name': 'PT_3750',
                'value': 12481
            },
            {
                'documentation': {
                    'description': 'Pt3851.'
                },
                'name': 'PT_3851',
                'value': 10071
            },
            {
                'documentation': {
                    'description': 'Pt3911.'
                },
                'name': 'PT_3911',
                'value': 12482
            },
            {
                'documentation': {
                    'description': 'Pt3916.'
                },
                'name': 'PT_3916',
                'value': 10069
            },
            {
                'documentation': {
                    'description': 'Pt3920.'
                },
                'name': 'PT_3920',
                'value': 10053
            },
            {
                'documentation': {
                    'description': 'Pt3928.'
                },
                'name': 'PT_3928',
                'value': 12483
            },
            {
                'documentation': {
                    'description': ' You must use DAQmx_AI_RTD_A, DAQmx_AI_RTD_B, and DAQmx_AI_RTD_C to supply the  coefficients for the Callendar-Van Dusen equation.'
                },
                'name': 'CUSTOM',
                'value': 10137
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
    'SaveOptions': {
        'values': [
            {
                'name': 'OVERWRITE',
                'value': 1
            },
            {
                'name': 'ALLOW_INTERACTIVE_EDITING',
                'value': 2
            },
            {
                'name': 'ALLOW_INTERACTIVE_DELETION',
                'value': 4
            }
        ]
    },
    'ScaleType': {
        'values': [
            {
                'documentation': {
                    'description': ' Scale values by using the equation y=mx+b, where x is a prescaled value and y  is a scaled value.'
                },
                'name': 'LINEAR',
                'value': 10447
            },
            {
                'documentation': {
                    'description': ' Scale values proportionally from a range of pre-scaled values to a range of  scaled values.'
                },
                'name': 'MAP_RANGES',
                'value': 10448
            },
            {
                'documentation': {
                    'description': 'Scale values by using an Nth order polynomial equation.'
                },
                'name': 'POLYNOMIAL',
                'value': 10449
            },
            {
                'documentation': {
                    'description': ' Map an array of pre-scaled values to an array of corresponding scaled values,  with all other values scaled proportionally.'
                },
                'name': 'TABLE',
                'value': 10450
            }
        ]
    },
    'Signal': {
        'values': [
            {
                'name': 'AI_CONVERT_CLOCK',
                'value': 12484
            },
            {
                'name': '10_M_HZ_REF_CLOCK',
                'value': 12536
            },
            {
                'name': '20_M_HZ_TIMEBASE_CLOCK',
                'value': 12486
            },
            {
                'name': 'SAMPLE_CLOCK',
                'value': 12487
            },
            {
                'name': 'ADVANCE_TRIGGER',
                'value': 12488
            },
            {
                'name': 'REFERENCE_TRIGGER',
                'value': 12490
            },
            {
                'name': 'START_TRIGGER',
                'value': 12491
            },
            {
                'name': 'ADV_CMPLT_EVENT',
                'value': 12492
            },
            {
                'name': 'AI_HOLD_CMPLT_EVENT',
                'value': 12493
            },
            {
                'name': 'COUNTER_OUTPUT_EVENT',
                'value': 12494
            },
            {
                'name': 'CHANGE_DETECTION_EVENT',
                'value': 12511
            },
            {
                'name': 'WDT_EXPIRED_EVENT',
                'value': 12512
            }
        ]
    },
    'Signal2': {
        'values': [
            {
                'documentation': {
                    'description': ' Timed Loop executes each time the Sample Complete Event occurs.'
                },
                'name': 'SAMPLE_COMPLETE_EVENT',
                'value': 12530
            },
            {
                'documentation': {
                    'description': ' Timed Loop executes each time the Counter Output Event occurs.'
                },
                'name': 'COUNTER_OUTPUT_EVENT',
                'value': 12494
            },
            {
                'documentation': {
                    'description': ' Timed Loop executes each time the Change Detection Event occurs.'
                },
                'name': 'CHANGE_DETECTION_EVENT',
                'value': 12511
            },
            {
                'documentation': {
                    'description': 'Timed Loop executes on each active edge of the Sample Clock.'
                },
                'name': 'SAMPLE_CLOCK',
                'value': 12487
            }
        ]
    },
    'Slope1': {
        'values': [
            {
                'documentation': {
                    'description': 'Trigger on the rising slope of the signal.'
                },
                'name': 'RISING_SLOPE',
                'value': 10280
            },
            {
                'documentation': {
                    'description': 'Trigger on the falling slope of the signal.'
                },
                'name': 'FALLING_SLOPE',
                'value': 10171
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
    'StrainGageRosetteType': {
        'values': [
            {
                'documentation': {
                    'description': ' A rectangular rosette consists of three strain gages, each separated by a 45  degree angle.'
                },
                'name': 'RECTANGULAR_ROSETTE',
                'value': 15968
            },
            {
                'documentation': {
                    'description': ' A delta rosette consists of three strain gages, each separated by a 60 degree  angle.'
                },
                'name': 'DELTA_ROSETTE',
                'value': 15969
            },
            {
                'documentation': {
                    'description': ' A tee rosette consists of two gages oriented at 90 degrees with respect to each  other.'
                },
                'name': 'TEE_ROSETTE',
                'value': 15970
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
    'TemperatureUnits': {
        'values': [
            {
                'name': 'DEG_C',
                'value': 10143
            },
            {
                'name': 'DEG_F',
                'value': 10144
            },
            {
                'name': 'KELVINS',
                'value': 10325
            },
            {
                'name': 'DEG_R',
                'value': 10145
            }
        ]
    },
    'ThermocoupleType1': {
        'values': [
            {
                'documentation': {
                    'description': 'J-type thermocouple.'
                },
                'name': 'J_TYPE_TC',
                'value': 10072
            },
            {
                'documentation': {
                    'description': 'K-type thermocouple.'
                },
                'name': 'K_TYPE_TC',
                'value': 10073
            },
            {
                'documentation': {
                    'description': 'N-type thermocouple.'
                },
                'name': 'N_TYPE_TC',
                'value': 10077
            },
            {
                'documentation': {
                    'description': 'R-type thermocouple.'
                },
                'name': 'R_TYPE_TC',
                'value': 10082
            },
            {
                'documentation': {
                    'description': 'S-type thermocouple.'
                },
                'name': 'S_TYPE_TC',
                'value': 10085
            },
            {
                'documentation': {
                    'description': 'T-type thermocouple.'
                },
                'name': 'T_TYPE_TC',
                'value': 10086
            },
            {
                'documentation': {
                    'description': 'B-type thermocouple.'
                },
                'name': 'B_TYPE_TC',
                'value': 10047
            },
            {
                'documentation': {
                    'description': 'E-type thermocouple.'
                },
                'name': 'E_TYPE_TC',
                'value': 10055
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
    'Timescale2': {
        'values': [
            {
                'documentation': {
                    'description': 'Use the host device.'
                },
                'name': 'HOST_TIME',
                'value': 16126
            },
            {
                'documentation': {
                    'description': 'Use the I/O device.'
                },
                'name': 'IO_DEVICE_TIME',
                'value': 16127
            }
        ]
    },
    'TimestampEvent': {
        'values': [
            {
                'name': 'START_TRIGGER',
                'value': 12491
            },
            {
                'name': 'REFERENCE_TRIGGER',
                'value': 12490
            },
            {
                'name': 'ARM_START_TRIGGER',
                'value': 14641
            },
            {
                'name': 'FIRST_SAMPLE_TIMESTAMP',
                'value': 16130
            }
        ]
    },
    'TorqueUnits': {
        'values': [
            {
                'documentation': {
                    'description': 'Newton meters.'
                },
                'name': 'NEWTON_METERS',
                'value': 15881
            },
            {
                'documentation': {
                    'description': 'Ounce-inches.'
                },
                'name': 'INCH_OUNCES',
                'value': 15882
            },
            {
                'documentation': {
                    'description': 'Pound-inches.'
                },
                'name': 'INCH_POUNDS',
                'value': 15883
            },
            {
                'documentation': {
                    'description': 'Pound-feet.'
                },
                'name': 'FOOT_POUNDS',
                'value': 15884
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
    'TriggerUsage': {
        'values': [
            {
                'name': 'ADVANCE',
                'value': 12488
            },
            {
                'name': 'PAUSE',
                'value': 12489
            },
            {
                'name': 'REFERENCE',
                'value': 12490
            },
            {
                'name': 'START',
                'value': 12491
            },
            {
                'name': 'HANDSHAKE',
                'value': 10389
            },
            {
                'name': 'ARM_START',
                'value': 14641
            }
        ]
    },
    'UnitsPreScaled': {
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
                    'description': 'Amperes.'
                },
                'name': 'AMPS',
                'value': 10342
            },
            {
                'documentation': {
                    'description': 'Degrees Fahrenheit.'
                },
                'name': 'DEG_F',
                'value': 10144
            },
            {
                'documentation': {
                    'description': 'Degrees Celsius.'
                },
                'name': 'DEG_C',
                'value': 10143
            },
            {
                'documentation': {
                    'description': 'Degrees Rankine.'
                },
                'name': 'DEG_R',
                'value': 10145
            },
            {
                'documentation': {
                    'description': 'Kelvins.'
                },
                'name': 'KELVINS',
                'value': 10325
            },
            {
                'documentation': {
                    'description': 'Strain.'
                },
                'name': 'STRAIN',
                'value': 10299
            },
            {
                'documentation': {
                    'description': 'Ohms.'
                },
                'name': 'OHMS',
                'value': 10384
            },
            {
                'documentation': {
                    'description': 'Hertz.'
                },
                'name': 'HZ',
                'value': 10373
            },
            {
                'documentation': {
                    'description': 'Seconds.'
                },
                'name': 'SECONDS',
                'value': 10364
            },
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
                    'description': '1 g is approximately equal to 9.81 m/s/s.'
                },
                'name': 'G',
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
                    'description': 'Pascals.'
                },
                'name': 'PASCALS',
                'value': 10081
            },
            {
                'documentation': {
                    'description': 'Newtons.'
                },
                'name': 'NEWTONS',
                'value': 15875
            },
            {
                'documentation': {
                    'description': 'Pounds.'
                },
                'name': 'POUNDS',
                'value': 15876
            },
            {
                'documentation': {
                    'description': 'Kilograms-force.'
                },
                'name': 'KILOGRAM_FORCE',
                'value': 15877
            },
            {
                'documentation': {
                    'description': 'Pounds per square inch.'
                },
                'name': 'POUNDS_PER_SQUARE_INCH',
                'value': 15879
            },
            {
                'documentation': {
                    'description': 'Bar.'
                },
                'name': 'BAR',
                'value': 15880
            },
            {
                'documentation': {
                    'description': 'Newton meters.'
                },
                'name': 'NEWTON_METERS',
                'value': 15881
            },
            {
                'documentation': {
                    'description': 'Ounce-inches.'
                },
                'name': 'INCH_OUNCES',
                'value': 15882
            },
            {
                'documentation': {
                    'description': 'Pound-inches.'
                },
                'name': 'INCH_POUNDS',
                'value': 15883
            },
            {
                'documentation': {
                    'description': 'Pound-feet.'
                },
                'name': 'FOOT_POUNDS',
                'value': 15884
            },
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
                    'description': ' Units defined by TEDS information associated with the channel.'
                },
                'name': 'FROM_TEDS',
                'value': 12516
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
    },
    'WatchdogAOOutputType': {
        'values': [
            {
                'name': 'VOLTAGE',
                'value': 10322
            },
            {
                'name': 'CURRENT',
                'value': 10134
            },
            {
                'name': 'NO_CHANGE',
                'value': 10160
            }
        ]
    },
    'WatchdogCOExpirState': {
        'values': [
            {
                'documentation': {
                    'description': 'Low logic.'
                },
                'name': 'LOW',
                'value': 10214
            },
            {
                'documentation': {
                    'description': 'High logic.'
                },
                'name': 'HIGH',
                'value': 10192
            },
            {
                'documentation': {
                    'description': ' Expiration does not affect the state of the counter output. The channels retain  their states at the time of the watchdog timer expiration, and no further  counter generation runs.'
                },
                'name': 'NO_CHANGE',
                'value': 10160
            }
        ]
    },
    'WatchdogControlAction': {
        'values': [
            {
                'name': 'RESET_TIMER',
                'value': 0
            },
            {
                'name': 'CLEAR_EXPIRATION',
                'value': 1
            }
        ]
    },
    'WindowTriggerCondition1': {
        'values': [
            {
                'documentation': {
                    'description': 'Trigger when the signal enters the window.'
                },
                'name': 'ENTERING_WIN',
                'value': 10163
            },
            {
                'documentation': {
                    'description': 'Trigger when the signal leaves the window.'
                },
                'name': 'LEAVING_WIN',
                'value': 10208
            }
        ]
    },
    'WriteBasicTEDSOptions': {
        'values': [
            {
                'name': 'WRITE_TO_EEPROM',
                'value': 12538
            },
            {
                'name': 'WRITE_TO_PROM',
                'value': 12539
            },
            {
                'name': 'DO_NOT_WRITE',
                'value': 12540
            }
        ]
    }
}
