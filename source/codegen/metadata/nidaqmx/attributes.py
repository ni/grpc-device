attributes = {
    'Buffer': {
        6252: {
            'access': 'read-write',
            'name': 'INPUT_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        6253: {
            'access': 'read-write',
            'name': 'OUTPUT_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        },
        8970: {
            'access': 'read',
            'name': 'INPUT_ONBRD_BUF_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        8971: {
            'access': 'read-write',
            'name': 'OUTPUT_ONBRD_BUF_SIZE',
            'resettable': True,
            'type': 'uInt32'
        }
    },
    'Device': {
        1585: {
            'access': 'read',
            'name': 'PRODUCT_TYPE',
            'resettable': False,
            'type': 'char[]'
        },
        1586: {
            'access': 'read',
            'name': 'SERIAL_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        8906: {
            'access': 'read',
            'name': 'IS_SIMULATED',
            'resettable': False,
            'type': 'bool32'
        },
        8989: {
            'access': 'read',
            'name': 'PRODUCT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        8990: {
            'access': 'read',
            'name': 'AI_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8991: {
            'access': 'read',
            'name': 'AO_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8992: {
            'access': 'read',
            'name': 'DI_LINES',
            'resettable': False,
            'type': 'char[]'
        },
        8993: {
            'access': 'read',
            'name': 'DI_PORTS',
            'resettable': False,
            'type': 'char[]'
        },
        8994: {
            'access': 'read',
            'name': 'DO_LINES',
            'resettable': False,
            'type': 'char[]'
        },
        8995: {
            'access': 'read',
            'name': 'DO_PORTS',
            'resettable': False,
            'type': 'char[]'
        },
        8996: {
            'access': 'read',
            'name': 'CI_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8997: {
            'access': 'read',
            'name': 'CO_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        8998: {
            'access': 'read',
            'enum': 'BusType',
            'name': 'BUS_TYPE',
            'resettable': False,
            'type': 'int32'
        },
        8999: {
            'access': 'read',
            'name': 'PCI_BUS_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9000: {
            'access': 'read',
            'name': 'PCI_DEV_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9001: {
            'access': 'read',
            'name': 'PXI_CHASSIS_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9002: {
            'access': 'read',
            'name': 'PXI_SLOT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        9020: {
            'access': 'read',
            'name': 'NUM_DMA_CHANS',
            'resettable': False,
            'type': 'uInt32'
        },
        10628: {
            'access': 'read',
            'name': 'ANLG_TRIG_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10629: {
            'access': 'read',
            'name': 'DIG_TRIG_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10630: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'AI_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10631: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'AO_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10632: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'DI_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10633: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'DO_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10634: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'CI_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10635: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'CO_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        10636: {
            'access': 'read',
            'name': 'AI_MAX_SINGLE_CHAN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10637: {
            'access': 'read',
            'name': 'AI_MAX_MULTI_CHAN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10638: {
            'access': 'read',
            'name': 'AI_MIN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10639: {
            'access': 'read',
            'name': 'AI_SIMULTANEOUS_SAMPLING_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10640: {
            'access': 'read',
            'name': 'AI_VOLTAGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10641: {
            'access': 'read',
            'name': 'AI_CURRENT_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10642: {
            'access': 'read',
            'name': 'AI_FREQ_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10643: {
            'access': 'read',
            'name': 'AI_GAINS',
            'resettable': False,
            'type': 'float64[]'
        },
        10644: {
            'access': 'read',
            'enum': 'Coupling1',
            'name': 'AI_COUPLINGS',
            'resettable': False,
            'type': 'int32[]'
        },
        10645: {
            'access': 'read',
            'name': 'AI_LOWPASS_CUTOFF_FREQ_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10646: {
            'access': 'read',
            'name': 'AO_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10647: {
            'access': 'read',
            'name': 'AO_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10648: {
            'access': 'read',
            'name': 'AO_MIN_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10649: {
            'access': 'read',
            'name': 'DI_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10650: {
            'access': 'read',
            'name': 'DO_MAX_RATE',
            'resettable': False,
            'type': 'float64'
        },
        10651: {
            'access': 'read',
            'name': 'AO_VOLTAGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10652: {
            'access': 'read',
            'name': 'AO_CURRENT_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10653: {
            'access': 'read',
            'name': 'AO_GAINS',
            'resettable': False,
            'type': 'float64[]'
        },
        10654: {
            'access': 'read',
            'name': 'CI_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        10655: {
            'access': 'read',
            'name': 'CI_MAX_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        10656: {
            'access': 'read',
            'name': 'CI_MAX_TIMEBASE',
            'resettable': False,
            'type': 'float64'
        },
        10657: {
            'access': 'read',
            'name': 'CO_MAX_SIZE',
            'resettable': False,
            'type': 'uInt32'
        },
        10658: {
            'access': 'read',
            'name': 'CO_MAX_TIMEBASE',
            'resettable': False,
            'type': 'float64'
        },
        10665: {
            'access': 'read',
            'enum': 'ProductCategory',
            'name': 'PRODUCT_CATEGORY',
            'resettable': False,
            'type': 'int32'
        },
        10678: {
            'access': 'read',
            'name': 'CHASSIS_MODULE_DEV_NAMES',
            'resettable': False,
            'type': 'char[]'
        },
        10679: {
            'access': 'read',
            'name': 'COMPACT_DAQ_CHASSIS_DEV_NAME',
            'resettable': False,
            'type': 'char[]'
        },
        10680: {
            'access': 'read',
            'name': 'COMPACT_DAQ_SLOT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        10697: {
            'access': 'read',
            'name': 'AI_VOLTAGE_INT_EXCIT_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10698: {
            'access': 'read',
            'name': 'AI_VOLTAGE_INT_EXCIT_RANGE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10699: {
            'access': 'read',
            'name': 'AI_CURRENT_INT_EXCIT_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10703: {
            'access': 'read',
            'name': 'AI_LOWPASS_CUTOFF_FREQ_RANGE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        10773: {
            'access': 'read',
            'name': 'AI_RESISTANCE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        10816: {
            'access': 'read',
            'name': 'TERMINALS',
            'resettable': False,
            'type': 'char[]'
        },
        10890: {
            'access': 'read',
            'name': 'CARRIER_SERIAL_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        10891: {
            'access': 'read',
            'name': 'TCPIP_HOSTNAME',
            'resettable': False,
            'type': 'char[]'
        },
        10892: {
            'access': 'read',
            'name': 'TCPIP_ETHERNET_IP',
            'resettable': False,
            'type': 'char[]'
        },
        10893: {
            'access': 'read',
            'name': 'TCPIP_WIRELESS_IP',
            'resettable': False,
            'type': 'char[]'
        },
        12123: {
            'access': 'read',
            'name': 'CO_SAMP_CLK_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        12141: {
            'access': 'read',
            'name': 'ACCESSORY_PRODUCT_TYPES',
            'resettable': False,
            'type': 'char[]'
        },
        12142: {
            'access': 'read',
            'name': 'ACCESSORY_PRODUCT_NUMS',
            'resettable': False,
            'type': 'uInt32[]'
        },
        12143: {
            'access': 'read',
            'name': 'ACCESSORY_SERIAL_NUMS',
            'resettable': False,
            'type': 'uInt32[]'
        },
        12240: {
            'access': 'read',
            'name': 'AI_BRIDGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        12242: {
            'access': 'read',
            'enum': 'AIMeasurementType',
            'name': 'AI_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12243: {
            'access': 'read',
            'enum': 'AOOutputChannelType',
            'name': 'AO_SUPPORTED_OUTPUT_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12244: {
            'access': 'read',
            'enum': 'CIMeasurementType',
            'name': 'CI_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12245: {
            'access': 'read',
            'enum': 'COOutputType',
            'name': 'CO_SUPPORTED_OUTPUT_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12246: {
            'access': 'read',
            'name': 'TEDS_HWTEDS_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        12252: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'AI_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12253: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'AO_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12254: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'CI_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12255: {
            'access': 'read',
            'enum': 'AcquisitionType',
            'name': 'CO_SAMP_MODES',
            'resettable': False,
            'type': 'int32[]'
        },
        12319: {
            'access': 'read',
            'name': 'TIME_TRIG_SUPPORTED',
            'resettable': False,
            'type': 'bool32'
        },
        12320: {
            'access': 'read',
            'name': 'CI_CURRENT_UTC_OFFSET',
            'resettable': False,
            'type': 'int32'
        },
        12321: {
            'access': 'read',
            'name': 'CI_UTC_OFFSET_READY',
            'resettable': False,
            'type': 'bool32'
        },
        12322: {
            'access': 'read',
            'name': 'NAV_PHYSICAL_CHANS',
            'resettable': False,
            'type': 'char[]'
        },
        12323: {
            'access': 'read',
            'enum': 'NavMeasurementType',
            'name': 'NAV_SUPPORTED_MEAS_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12324: {
            'access': 'read',
            'enum': 'TriggerUsage',
            'name': 'NAV_TRIG_USAGE',
            'resettable': False,
            'type': 'int32[]'
        },
        12325: {
            'access': 'read-write',
            'enum': 'NavMode',
            'name': 'NAV_MODE',
            'resettable': False,
            'type': 'int32'
        },
        12326: {
            'access': 'read-write',
            'name': 'NAV_PRESET_LAT',
            'resettable': False,
            'type': 'float64'
        },
        12327: {
            'access': 'read-write',
            'name': 'NAV_PRESET_LONG',
            'resettable': False,
            'type': 'float64'
        },
        12328: {
            'access': 'read-write',
            'name': 'NAV_PRESET_ALT',
            'resettable': False,
            'type': 'float64'
        },
        12329: {
            'access': 'read-write',
            'enum': 'AltRef',
            'name': 'NAV_ALT_REF',
            'resettable': False,
            'type': 'int32'
        },
        12330: {
            'access': 'read-write',
            'name': 'NAV_PPS_COMPEN',
            'resettable': False,
            'type': 'float64'
        },
        12331: {
            'access': 'read-write',
            'name': 'NAV_NUM_SURVEY_FIXES',
            'resettable': False,
            'type': 'uInt32'
        },
        12332: {
            'access': 'read',
            'name': 'NAV_REMAINING_SURVEY_FIXES',
            'resettable': False,
            'type': 'uInt32'
        },
        12333: {
            'access': 'read',
            'name': 'NAV_HAS_FIX',
            'resettable': False,
            'type': 'bool32'
        },
        12334: {
            'access': 'read',
            'enum': 'AntStatus',
            'name': 'NAV_ANT_STATUS',
            'resettable': False,
            'type': 'int32'
        },
        12335: {
            'access': 'read',
            'name': 'NAV_UTC_OFFSET_READY',
            'resettable': False,
            'type': 'bool32'
        },
        12336: {
            'access': 'read',
            'name': 'NAV_CURRENT_UTC_OFFSET',
            'resettable': False,
            'type': 'int32'
        },
        12337: {
            'access': 'read',
            'name': 'NAV_NUM_SATS',
            'resettable': False,
            'type': 'uInt32'
        },
        12338: {
            'access': 'read',
            'name': 'NAV_PDOP',
            'resettable': False,
            'type': 'float64'
        },
        12339: {
            'access': 'read',
            'name': 'NAV_HDOP',
            'resettable': False,
            'type': 'float64'
        },
        12340: {
            'access': 'read',
            'name': 'NAV_VDOP',
            'resettable': False,
            'type': 'float64'
        },
        12488: {
            'access': 'read',
            'name': 'AI_DIG_FLTR_LOWPASS_CUTOFF_FREQ_DISCRETE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        12489: {
            'access': 'read',
            'name': 'AI_DIG_FLTR_LOWPASS_CUTOFF_FREQ_RANGE_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        12551: {
            'access': 'read',
            'enum': 'FilterType2',
            'name': 'AI_DIG_FLTR_TYPES',
            'resettable': False,
            'type': 'int32[]'
        },
        12561: {
            'access': 'read',
            'name': 'AI_CHARGE_RNGS',
            'resettable': False,
            'type': 'float64[]'
        },
        12609: {
            'access': 'read',
            'name': 'NUM_TIME_TRIGS',
            'resettable': False,
            'type': 'uInt32'
        },
        12610: {
            'access': 'read',
            'name': 'NUM_TIMESTAMP_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12641: {
            'access': 'read',
            'name': 'COMPACT_RIO_CHASSIS_DEV_NAME',
            'resettable': False,
            'type': 'char[]'
        },
        12642: {
            'access': 'read',
            'name': 'COMPACT_RIO_SLOT_NUM',
            'resettable': False,
            'type': 'uInt32'
        },
        12643: {
            'access': 'read',
            'name': 'AI_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12644: {
            'access': 'read',
            'name': 'AI_NUM_SYNC_PULSE_SRCS',
            'resettable': False,
            'type': 'uInt32'
        },
        12645: {
            'access': 'read',
            'name': 'AO_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12646: {
            'access': 'read',
            'name': 'AO_NUM_SYNC_PULSE_SRCS',
            'resettable': False,
            'type': 'uInt32'
        },
        12647: {
            'access': 'read',
            'name': 'DI_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12648: {
            'access': 'read',
            'name': 'DO_NUM_SAMP_TIMING_ENGINES',
            'resettable': False,
            'type': 'uInt32'
        },
        12657: {
            'access': 'read',
            'name': 'FIELD_DAQ_DEV_NAME',
            'resettable': False,
            'type': 'char[]'
        },
        12664: {
            'access': 'read',
            'name': 'FIELD_DAQ_BANK_DEV_NAMES',
            'resettable': False,
            'type': 'char[]'
        }
    },
    'Scale': {
        4646: {
            'access': 'read-write',
            'name': 'DESCR',
            'resettable': False,
            'type': 'char[]'
        },
        4647: {
            'access': 'read-write',
            'name': 'LIN_SLOPE',
            'resettable': False,
            'type': 'float64'
        },
        4648: {
            'access': 'read-write',
            'name': 'LIN_Y_INTERCEPT',
            'resettable': False,
            'type': 'float64'
        },
        4649: {
            'access': 'read-write',
            'name': 'MAP_SCALED_MAX',
            'resettable': False,
            'type': 'float64'
        },
        4656: {
            'access': 'read-write',
            'name': 'MAP_SCALED_MIN',
            'resettable': False,
            'type': 'float64'
        },
        4657: {
            'access': 'read-write',
            'name': 'MAP_PRE_SCALED_MAX',
            'resettable': False,
            'type': 'float64'
        },
        4658: {
            'access': 'read-write',
            'name': 'MAP_PRE_SCALED_MIN',
            'resettable': False,
            'type': 'float64'
        },
        4660: {
            'access': 'read-write',
            'name': 'POLY_FORWARD_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        4661: {
            'access': 'read-write',
            'name': 'POLY_REVERSE_COEFF',
            'resettable': False,
            'type': 'float64[]'
        },
        4662: {
            'access': 'read-write',
            'name': 'TABLE_SCALED_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        4663: {
            'access': 'read-write',
            'name': 'TABLE_PRE_SCALED_VALS',
            'resettable': False,
            'type': 'float64[]'
        },
        6391: {
            'access': 'read-write',
            'enum': 'UnitsPreScaled',
            'name': 'PRE_SCALED_UNITS',
            'resettable': False,
            'type': 'int32'
        },
        6427: {
            'access': 'read-write',
            'name': 'SCALED_UNITS',
            'resettable': False,
            'type': 'char[]'
        },
        6441: {
            'access': 'read',
            'enum': 'ScaleType',
            'name': 'TYPE',
            'resettable': False,
            'type': 'int32'
        }
    }
}
