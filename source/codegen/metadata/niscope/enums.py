# -*- coding: utf-8 -*-
# This file is generated from NI-SCOPE API metadata version 23.0.0d87
enums = {
    'AcquisitionStatus': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_ACQ_IN_PROGRESS',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_ACQ_COMPLETE',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_ACQ_STATUS_UNKNOWN',
                'value': -1
            }
        ]
    },
    'AcquisitionType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_NORMAL',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_FLEXRES',
                'value': 1001
            },
            {
                'name': 'NISCOPE_VAL_DDC',
                'value': 1002
            }
        ]
    },
    'AddressType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_ADDR_PHYSICAL',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_ADDR_VIRTUAL',
                'value': 1
            }
        ]
    },
    'ArrayMeasurement': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_NO_MEASUREMENT',
                'value': 4000
            },
            {
                'name': 'NISCOPE_VAL_LAST_ACQ_HISTOGRAM',
                'value': 4001
            },
            {
                'name': 'NISCOPE_VAL_FFT_PHASE_SPECTRUM',
                'value': 4002
            },
            {
                'name': 'NISCOPE_VAL_FFT_AMP_SPECTRUM_VOLTS_RMS',
                'value': 4003
            },
            {
                'name': 'NISCOPE_VAL_MULTI_ACQ_VOLTAGE_HISTOGRAM',
                'value': 4004
            },
            {
                'name': 'NISCOPE_VAL_MULTI_ACQ_TIME_HISTOGRAM',
                'value': 4005
            },
            {
                'name': 'NISCOPE_VAL_ARRAY_INTEGRAL',
                'value': 4006
            },
            {
                'name': 'NISCOPE_VAL_DERIVATIVE',
                'value': 4007
            },
            {
                'name': 'NISCOPE_VAL_INVERSE',
                'value': 4008
            },
            {
                'name': 'NISCOPE_VAL_HANNING_WINDOW',
                'value': 4009
            },
            {
                'name': 'NISCOPE_VAL_FLAT_TOP_WINDOW',
                'value': 4010
            },
            {
                'name': 'NISCOPE_VAL_POLYNOMIAL_INTERPOLATION',
                'value': 4011
            },
            {
                'name': 'NISCOPE_VAL_MULTIPLY_CHANNELS',
                'value': 4012
            },
            {
                'name': 'NISCOPE_VAL_ADD_CHANNELS',
                'value': 4013
            },
            {
                'name': 'NISCOPE_VAL_SUBTRACT_CHANNELS',
                'value': 4014
            },
            {
                'name': 'NISCOPE_VAL_DIVIDE_CHANNELS',
                'value': 4015
            },
            {
                'name': 'NISCOPE_VAL_MULTI_ACQ_AVERAGE',
                'value': 4016
            },
            {
                'name': 'NISCOPE_VAL_BUTTERWORTH_FILTER',
                'value': 4017
            },
            {
                'name': 'NISCOPE_VAL_CHEBYSHEV_FILTER',
                'value': 4018
            },
            {
                'name': 'NISCOPE_VAL_FFT_AMP_SPECTRUM_DB',
                'value': 4019
            },
            {
                'name': 'NISCOPE_VAL_HAMMING_WINDOW',
                'value': 4020
            },
            {
                'name': 'NISCOPE_VAL_WINDOWED_FIR_FILTER',
                'value': 4021
            },
            {
                'name': 'NISCOPE_VAL_BESSEL_FILTER',
                'value': 4022
            },
            {
                'name': 'NISCOPE_VAL_TRIANGLE_WINDOW',
                'value': 4023
            },
            {
                'name': 'NISCOPE_VAL_BLACKMAN_WINDOW',
                'value': 4024
            },
            {
                'name': 'NISCOPE_VAL_ARRAY_OFFSET',
                'value': 4025
            },
            {
                'name': 'NISCOPE_VAL_ARRAY_GAIN',
                'value': 4026
            }
        ]
    },
    'CableSenseMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_CABLE_SENSE_MODE_DISABLED',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_CABLE_SENSE_MODE_ON_DEMAND',
                'value': 1
            }
        ]
    },
    'CalibrationTypes': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_CAL_EXTERNAL',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_CAL_SELF',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_CAL_MANUFACTURE',
                'value': 2
            }
        ]
    },
    'ClearableMeasurement': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_RISE_TIME',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_ALL_MEASUREMENTS',
                'value': 10000
            },
            {
                'name': 'NISCOPE_VAL_MULTI_ACQ_VOLTAGE_HISTOGRAM',
                'value': 4004
            },
            {
                'name': 'NISCOPE_VAL_MULTI_ACQ_TIME_HISTOGRAM',
                'value': 4005
            },
            {
                'name': 'NISCOPE_VAL_MULTI_ACQ_AVERAGE',
                'value': 4016
            },
            {
                'name': 'NISCOPE_VAL_FREQUENCY',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_AVERAGE_FREQUENCY',
                'value': 1016
            },
            {
                'name': 'NISCOPE_VAL_FFT_FREQUENCY',
                'value': 1008
            },
            {
                'name': 'NISCOPE_VAL_PERIOD',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_AVERAGE_PERIOD',
                'value': 1015
            },
            {
                'name': 'NISCOPE_VAL_FALL_TIME',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_RISE_SLEW_RATE',
                'value': 1010
            },
            {
                'name': 'NISCOPE_VAL_FALL_SLEW_RATE',
                'value': 1011
            },
            {
                'name': 'NISCOPE_VAL_OVERSHOOT',
                'value': 18
            },
            {
                'name': 'NISCOPE_VAL_PRESHOOT',
                'value': 19
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_RMS',
                'value': 4
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_CYCLE_RMS',
                'value': 16
            },
            {
                'name': 'NISCOPE_VAL_AC_ESTIMATE',
                'value': 1012
            },
            {
                'name': 'NISCOPE_VAL_FFT_AMPLITUDE',
                'value': 1009
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_AVERAGE',
                'value': 10
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_CYCLE_AVERAGE',
                'value': 17
            },
            {
                'name': 'NISCOPE_VAL_DC_ESTIMATE',
                'value': 1013
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_MAX',
                'value': 6
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_MIN',
                'value': 7
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_PEAK_TO_PEAK',
                'value': 5
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HIGH',
                'value': 8
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_LOW',
                'value': 9
            },
            {
                'name': 'NISCOPE_VAL_AMPLITUDE',
                'value': 15
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_TOP',
                'value': 1007
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_BASE',
                'value': 1006
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_BASE_TO_TOP',
                'value': 1017
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_NEG',
                'value': 11
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_POS',
                'value': 12
            },
            {
                'name': 'NISCOPE_VAL_DUTY_CYCLE_NEG',
                'value': 13
            },
            {
                'name': 'NISCOPE_VAL_DUTY_CYCLE_POS',
                'value': 14
            },
            {
                'name': 'NISCOPE_VAL_INTEGRAL',
                'value': 1005
            },
            {
                'name': 'NISCOPE_VAL_AREA',
                'value': 1003
            },
            {
                'name': 'NISCOPE_VAL_CYCLE_AREA',
                'value': 1004
            },
            {
                'name': 'NISCOPE_VAL_TIME_DELAY',
                'value': 1014
            },
            {
                'name': 'NISCOPE_VAL_PHASE_DELAY',
                'value': 1018
            },
            {
                'name': 'NISCOPE_VAL_LOW_REF_VOLTS',
                'value': 1000
            },
            {
                'name': 'NISCOPE_VAL_MID_REF_VOLTS',
                'value': 1001
            },
            {
                'name': 'NISCOPE_VAL_HIGH_REF_VOLTS',
                'value': 1002
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN',
                'value': 2000
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_STDEV',
                'value': 2001
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEDIAN',
                'value': 2003
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MODE',
                'value': 2010
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MAX',
                'value': 2005
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MIN',
                'value': 2006
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_PEAK_TO_PEAK',
                'value': 2002
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_STDEV',
                'value': 2007
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_2_STDEV',
                'value': 2008
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_3_STDEV',
                'value': 2009
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_HITS',
                'value': 2004
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HISTOGRAM_NEW_HITS',
                'value': 2011
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MEAN',
                'value': 3000
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_STDEV',
                'value': 3001
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MEDIAN',
                'value': 3003
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MODE',
                'value': 3010
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MAX',
                'value': 3005
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MIN',
                'value': 3006
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_PEAK_TO_PEAK',
                'value': 3002
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_STDEV',
                'value': 3007
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_2_STDEV',
                'value': 3008
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_3_STDEV',
                'value': 3009
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_HITS',
                'value': 3004
            },
            {
                'name': 'NISCOPE_VAL_TIME_HISTOGRAM_NEW_HITS',
                'value': 3011
            }
        ]
    },
    'ClockingTerminalValues': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NISCOPE_VAL_NO_SOURCE',
                'value': 'VAL_NO_SOURCE'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_CLOCK',
                'value': 'VAL_RTSI_CLOCK'
            },
            {
                'name': 'NISCOPE_VAL_EXTERNAL',
                'value': 'VAL_EXTERNAL'
            },
            {
                'name': 'NISCOPE_VAL_PFI_0',
                'value': 'VAL_PFI_0'
            },
            {
                'name': 'NISCOPE_VAL_PFI_1',
                'value': 'VAL_PFI_1'
            },
            {
                'name': 'NISCOPE_VAL_PFI_2',
                'value': 'VAL_PFI_2'
            },
            {
                'name': 'NISCOPE_VAL_CLK_IN',
                'value': 'VAL_CLK_IN'
            },
            {
                'name': 'NISCOPE_VAL_CLK_OUT',
                'value': 'VAL_CLK_OUT'
            },
            {
                'name': 'NISCOPE_VAL_INTERNAL10MHZ_OSC',
                'value': 'VAL_INTERNAL10MHZ_OSC'
            },
            {
                'name': 'NISCOPE_VAL_PXI_CLK',
                'value': 'VAL_PXI_CLK'
            },
            {
                'name': 'NISCOPE_VAL_PXI_CLK10',
                'value': 'VAL_PXI_CLK10'
            },
            {
                'name': 'NISCOPE_VAL_PXI_CLK100',
                'value': 'VAL_PXI_CLK100'
            },
            {
                'name': 'NISCOPE_VAL_PXIE_DSTAR_A',
                'value': 'VAL_PXIE_DSTAR_A'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_CLK_IN',
                'value': 'VAL_AUX_0_CLK_IN'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_CLK_OUT',
                'value': 'VAL_AUX_0_CLK_OUT'
            },
            {
                'name': 'NISCOPE_VAL_ONBOARD_CONFIGURABLE_RATE_CLK',
                'value': 'VAL_ONBOARD_CONFIGURABLE_RATE_CLK'
            }
        ]
    },
    'DataProcessingMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_REAL',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_COMPLEX',
                'value': 1
            }
        ]
    },
    'ExportableSignals': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_REF_TRIGGER',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_START_TRIGGER',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_END_OF_ACQUISITION_EVENT',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_END_OF_RECORD_EVENT',
                'value': 4
            },
            {
                'name': 'NISCOPE_VAL_ADVANCE_TRIGGER',
                'value': 5
            },
            {
                'name': 'NISCOPE_VAL_READY_FOR_ADVANCE_EVENT',
                'value': 6
            },
            {
                'name': 'NISCOPE_VAL_READY_FOR_START_EVENT',
                'value': 7
            },
            {
                'name': 'NISCOPE_VAL_READY_FOR_REF_EVENT',
                'value': 10
            },
            {
                'name': 'NISCOPE_VAL_REF_CLOCK',
                'value': 100
            },
            {
                'name': 'NISCOPE_VAL_5V_OUT',
                'value': 13
            },
            {
                'name': 'NISCOPE_VAL_SAMPLE_CLOCK',
                'value': 101
            }
        ]
    },
    'FIRFilterWindow': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_NONE',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_HANNING',
                'value': 409
            },
            {
                'name': 'NISCOPE_VAL_FLAT_TOP',
                'value': 410
            },
            {
                'name': 'NISCOPE_VAL_HAMMING',
                'value': 420
            },
            {
                'name': 'NISCOPE_VAL_TRIANGLE',
                'value': 423
            },
            {
                'name': 'NISCOPE_VAL_BLACKMAN',
                'value': 424
            }
        ]
    },
    'FetchRelativeTo': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_READ_POINTER',
                'value': 388
            },
            {
                'name': 'NISCOPE_VAL_PRETRIGGER',
                'value': 477
            },
            {
                'name': 'NISCOPE_VAL_NOW',
                'value': 481
            },
            {
                'name': 'NISCOPE_VAL_START',
                'value': 482
            },
            {
                'name': 'NISCOPE_VAL_TRIGGER',
                'value': 483
            }
        ]
    },
    'FlexFIRAntialiasFilterType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_48_TAP_STANDARD',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_48_TAP_HANNING',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_16_TAP_HANNING',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_8_TAP_HANNING',
                'value': 3
            }
        ]
    },
    'GlitchCondition': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_GLITCH_GREATER_THAN',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_GLITCH_LESS_THAN',
                'value': 1
            }
        ]
    },
    'GlitchPolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_GLITCH_POSITIVE',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_GLITCH_NEGATIVE',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_GLITCH_EITHER',
                'value': 3
            }
        ]
    },
    'InputImpedance': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NISCOPE_VAL_50_OHMS',
                'value': 50.0
            },
            {
                'name': 'NISCOPE_VAL_75_OHMS',
                'value': 75.0
            },
            {
                'name': 'NISCOPE_VAL_1_MEG_OHM',
                'value': 1000000.0
            }
        ]
    },
    'MaxInputFrequency': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NISCOPE_VAL_BANDWIDTH_DEVICE_DEFAULT',
                'value': 0.0
            },
            {
                'name': 'NISCOPE_VAL_BANDWIDTH_FULL',
                'value': -1.0
            },
            {
                'name': 'NISCOPE_VAL_20MHZ_BANDWIDTH',
                'value': 20000000.0
            },
            {
                'name': 'NISCOPE_VAL_100MHZ_BANDWIDTH',
                'value': 100000000.0
            },
            {
                'name': 'NISCOPE_VAL_20MHZ_MAX_INPUT_FREQUENCY',
                'value': 20000000.0
            },
            {
                'name': 'NISCOPE_VAL_100MHZ_MAX_INPUT_FREQUENCY',
                'value': 100000000.0
            }
        ]
    },
    'MeasFilterType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_MEAS_LOWPASS',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_MEAS_HIGHPASS',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_MEAS_BANDPASS',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_MEAS_BANDSTOP',
                'value': 3
            }
        ]
    },
    'MeasPercentageMethod': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_MEAS_LOW_HIGH',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_MEAS_MIN_MAX',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_MEAS_BASE_TOP',
                'value': 2
            }
        ]
    },
    'MeasRefLevelUnits': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_MEAS_VOLTAGE',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_MEAS_PERCENTAGE',
                'value': 1
            }
        ]
    },
    'NiScopeInt32AttributeValues': {
        'enum-value-prefix': 'NISCOPE_INT32',
        'generate-mappings': False,
        'values': [
            {
                'name': 'ACQUISITION_TYPE_VAL_NORMAL',
                'value': 0
            },
            {
                'name': 'ACQUISITION_TYPE_VAL_FLEXRES',
                'value': 1001
            },
            {
                'name': 'ACQUISITION_TYPE_VAL_DDC',
                'value': 1002
            },
            {
                'name': 'ADDRESS_TYPE_VAL_ADDR_PHYSICAL',
                'value': 0
            },
            {
                'name': 'ADDRESS_TYPE_VAL_ADDR_VIRTUAL',
                'value': 1
            },
            {
                'name': 'DATA_PROCESSING_MODE_VAL_REAL',
                'value': 0
            },
            {
                'name': 'DATA_PROCESSING_MODE_VAL_COMPLEX',
                'value': 1
            },
            {
                'name': 'FIR_FILTER_WINDOW_VAL_NONE',
                'value': 0
            },
            {
                'name': 'FIR_FILTER_WINDOW_VAL_HANNING',
                'value': 409
            },
            {
                'name': 'FIR_FILTER_WINDOW_VAL_FLAT_TOP',
                'value': 410
            },
            {
                'name': 'FIR_FILTER_WINDOW_VAL_HAMMING',
                'value': 420
            },
            {
                'name': 'FIR_FILTER_WINDOW_VAL_TRIANGLE',
                'value': 423
            },
            {
                'name': 'FIR_FILTER_WINDOW_VAL_BLACKMAN',
                'value': 424
            },
            {
                'name': 'FETCH_RELATIVE_TO_VAL_READ_POINTER',
                'value': 388
            },
            {
                'name': 'FETCH_RELATIVE_TO_VAL_PRETRIGGER',
                'value': 477
            },
            {
                'name': 'FETCH_RELATIVE_TO_VAL_NOW',
                'value': 481
            },
            {
                'name': 'FETCH_RELATIVE_TO_VAL_START',
                'value': 482
            },
            {
                'name': 'FETCH_RELATIVE_TO_VAL_TRIGGER',
                'value': 483
            },
            {
                'name': 'FLEX_FIR_ANTIALIAS_FILTER_TYPE_VAL_48_TAP_STANDARD',
                'value': 0
            },
            {
                'name': 'FLEX_FIR_ANTIALIAS_FILTER_TYPE_VAL_48_TAP_HANNING',
                'value': 1
            },
            {
                'name': 'FLEX_FIR_ANTIALIAS_FILTER_TYPE_VAL_16_TAP_HANNING',
                'value': 2
            },
            {
                'name': 'FLEX_FIR_ANTIALIAS_FILTER_TYPE_VAL_8_TAP_HANNING',
                'value': 3
            },
            {
                'name': 'GLITCH_CONDITION_VAL_GLITCH_GREATER_THAN',
                'value': 2
            },
            {
                'name': 'GLITCH_CONDITION_VAL_GLITCH_LESS_THAN',
                'value': 1
            },
            {
                'name': 'GLITCH_POLARITY_VAL_GLITCH_POSITIVE',
                'value': 1
            },
            {
                'name': 'GLITCH_POLARITY_VAL_GLITCH_NEGATIVE',
                'value': 2
            },
            {
                'name': 'GLITCH_POLARITY_VAL_GLITCH_EITHER',
                'value': 3
            },
            {
                'name': 'MEAS_FILTER_TYPE_VAL_MEAS_LOWPASS',
                'value': 0
            },
            {
                'name': 'MEAS_FILTER_TYPE_VAL_MEAS_HIGHPASS',
                'value': 1
            },
            {
                'name': 'MEAS_FILTER_TYPE_VAL_MEAS_BANDPASS',
                'value': 2
            },
            {
                'name': 'MEAS_FILTER_TYPE_VAL_MEAS_BANDSTOP',
                'value': 3
            },
            {
                'name': 'MEAS_PERCENTAGE_METHOD_VAL_MEAS_LOW_HIGH',
                'value': 0
            },
            {
                'name': 'MEAS_PERCENTAGE_METHOD_VAL_MEAS_MIN_MAX',
                'value': 1
            },
            {
                'name': 'MEAS_PERCENTAGE_METHOD_VAL_MEAS_BASE_TOP',
                'value': 2
            },
            {
                'name': 'MEAS_REF_LEVEL_UNITS_VAL_MEAS_VOLTAGE',
                'value': 0
            },
            {
                'name': 'MEAS_REF_LEVEL_UNITS_VAL_MEAS_PERCENTAGE',
                'value': 1
            },
            {
                'name': 'NOTIFICATION_TYPE_VAL_NOTIFY_NEVER',
                'value': 0
            },
            {
                'name': 'NOTIFICATION_TYPE_VAL_NOTIFY_DONE',
                'value': 1
            },
            {
                'name': 'OVERFLOW_ERROR_REPORTING_VAL_ERROR_REPORTING_ERROR',
                'value': 0
            },
            {
                'name': 'OVERFLOW_ERROR_REPORTING_VAL_ERROR_REPORTING_WARNING',
                'value': 1
            },
            {
                'name': 'OVERFLOW_ERROR_REPORTING_VAL_ERROR_REPORTING_DISABLED',
                'value': 2
            },
            {
                'name': 'P2_P_STREAM_RELATIVE_TO_VAL_STREAM_RELATIVE_TO_START_TRIGGER',
                'value': 0
            },
            {
                'name': 'P2_P_STREAM_RELATIVE_TO_VAL_STREAM_RELATIVE_TO_REFERENCE_TRIGGER',
                'value': 1
            },
            {
                'name': 'P2_P_STREAM_RELATIVE_TO_VAL_STREAM_RELATIVE_TO_SYNC_TRIGGER',
                'value': 2
            },
            {
                'name': 'RIS_METHOD_VAL_RIS_EXACT_NUM_AVERAGES',
                'value': 1
            },
            {
                'name': 'RIS_METHOD_VAL_RIS_MIN_NUM_AVERAGES',
                'value': 2
            },
            {
                'name': 'RIS_METHOD_VAL_RIS_INCOMPLETE',
                'value': 3
            },
            {
                'name': 'RIS_METHOD_VAL_RIS_LIMITED_BIN_WIDTH',
                'value': 5
            },
            {
                'name': 'REF_TRIGGER_DETECTOR_LOCATION_VAL_ANALOG_DETECTION_CIRCUIT',
                'value': 0
            },
            {
                'name': 'REF_TRIGGER_DETECTOR_LOCATION_VAL_DDC_OUTPUT',
                'value': 1
            },
            {
                'name': 'RUNT_POLARITY_VAL_RUNT_POSITIVE',
                'value': 1
            },
            {
                'name': 'RUNT_POLARITY_VAL_RUNT_NEGATIVE',
                'value': 2
            },
            {
                'name': 'RUNT_POLARITY_VAL_RUNT_EITHER',
                'value': 3
            },
            {
                'name': 'RUNT_TIME_CONDITION_VAL_RUNT_TIME_CONDITION_NONE',
                'value': 0
            },
            {
                'name': 'RUNT_TIME_CONDITION_VAL_RUNT_TIME_CONDITION_WITHIN',
                'value': 1
            },
            {
                'name': 'RUNT_TIME_CONDITION_VAL_RUNT_TIME_CONDITION_OUTSIDE',
                'value': 2
            },
            {
                'name': 'SAMPLE_MODE_VAL_REAL_TIME',
                'value': 0
            },
            {
                'name': 'SAMPLE_MODE_VAL_EQUIVALENT_TIME',
                'value': 1
            },
            {
                'name': 'TERMINAL_CONFIGURATION_VAL_SINGLE_ENDED',
                'value': 0
            },
            {
                'name': 'TERMINAL_CONFIGURATION_VAL_UNBALANCED_DIFFERENTIAL',
                'value': 1
            },
            {
                'name': 'TERMINAL_CONFIGURATION_VAL_DIFFERENTIAL',
                'value': 2
            },
            {
                'name': 'TRIGGER_COUPLING_VAL_AC',
                'value': 0
            },
            {
                'name': 'TRIGGER_COUPLING_VAL_DC',
                'value': 1
            },
            {
                'name': 'TRIGGER_COUPLING_VAL_HF_REJECT',
                'value': 3
            },
            {
                'name': 'TRIGGER_COUPLING_VAL_LF_REJECT',
                'value': 4
            },
            {
                'name': 'TRIGGER_COUPLING_VAL_AC_PLUS_HF_REJECT',
                'value': 1001
            },
            {
                'name': 'TRIGGER_MODIFIER_VAL_NO_TRIGGER_MOD',
                'value': 1
            },
            {
                'name': 'TRIGGER_MODIFIER_VAL_AUTO',
                'value': 2
            },
            {
                'name': 'TRIGGER_MODIFIER_VAL_AUTO_LEVEL',
                'value': 3
            },
            {
                'name': 'TRIGGER_SLOPE_VAL_NEGATIVE',
                'value': 0
            },
            {
                'name': 'TRIGGER_SLOPE_VAL_POSITIVE',
                'value': 1
            },
            {
                'name': 'TRIGGER_SLOPE_VAL_SLOPE_EITHER',
                'value': 3
            },
            {
                'name': 'TRIGGER_TYPE_VAL_EDGE_TRIGGER',
                'value': 1
            },
            {
                'name': 'TRIGGER_TYPE_VAL_HYSTERESIS_TRIGGER',
                'value': 1001
            },
            {
                'name': 'TRIGGER_TYPE_VAL_DIGITAL_TRIGGER',
                'value': 1002
            },
            {
                'name': 'TRIGGER_TYPE_VAL_WINDOW_TRIGGER',
                'value': 1003
            },
            {
                'name': 'TRIGGER_TYPE_VAL_SOFTWARE_TRIGGER',
                'value': 1004
            },
            {
                'name': 'TRIGGER_TYPE_VAL_TV_TRIGGER',
                'value': 5
            },
            {
                'name': 'TRIGGER_TYPE_VAL_GLITCH_TRIGGER',
                'value': 4
            },
            {
                'name': 'TRIGGER_TYPE_VAL_WIDTH_TRIGGER',
                'value': 2
            },
            {
                'name': 'TRIGGER_TYPE_VAL_RUNT_TRIGGER',
                'value': 3
            },
            {
                'name': 'TRIGGER_TYPE_VAL_IMMEDIATE_TRIGGER',
                'value': 6
            },
            {
                'name': 'TRIGGER_WINDOW_MODE_VAL_ENTERING_WINDOW',
                'value': 0
            },
            {
                'name': 'TRIGGER_WINDOW_MODE_VAL_LEAVING_WINDOW',
                'value': 1
            },
            {
                'name': 'TRIGGER_WINDOW_MODE_VAL_ENTERING_OR_LEAVING_WINDOW',
                'value': 2
            },
            {
                'name': 'VERTICAL_COUPLING_VAL_AC',
                'value': 0
            },
            {
                'name': 'VERTICAL_COUPLING_VAL_DC',
                'value': 1
            },
            {
                'name': 'VERTICAL_COUPLING_VAL_GND',
                'value': 2
            },
            {
                'name': 'VIDEO_POLARITY_VAL_TV_POSITIVE',
                'value': 1
            },
            {
                'name': 'VIDEO_POLARITY_VAL_TV_NEGATIVE',
                'value': 2
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_NTSC',
                'value': 1
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_PAL',
                'value': 2
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_SECAM',
                'value': 3
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_M_PAL',
                'value': 1001
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_480I_59_94_FIELDS_PER_SECOND',
                'value': 1010
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_480I_60_FIELDS_PER_SECOND',
                'value': 1011
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_480P_59_94_FRAMES_PER_SECOND',
                'value': 1015
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_480P_60_FRAMES_PER_SECOND',
                'value': 1016
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_576I_50_FIELDS_PER_SECOND',
                'value': 1020
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_576P_50_FRAMES_PER_SECOND',
                'value': 1025
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_720P_50_FRAMES_PER_SECOND',
                'value': 1031
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_720P_59_94_FRAMES_PER_SECOND',
                'value': 1032
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_720P_60_FRAMES_PER_SECOND',
                'value': 1033
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_1080I_50_FIELDS_PER_SECOND',
                'value': 1040
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_1080I_59_94_FIELDS_PER_SECOND',
                'value': 1041
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_1080I_60_FIELDS_PER_SECOND',
                'value': 1042
            },
            {
                'name': 'VIDEO_SIGNAL_FORMAT_VAL_VIDEO_1080P_24_FRAMES_PER_SECOND',
                'value': 1045
            },
            {
                'name': 'VIDEO_TRIGGER_EVENT_VAL_TV_EVENT_FIELD1',
                'value': 1
            },
            {
                'name': 'VIDEO_TRIGGER_EVENT_VAL_TV_EVENT_FIELD2',
                'value': 2
            },
            {
                'name': 'VIDEO_TRIGGER_EVENT_VAL_TV_EVENT_ANY_FIELD',
                'value': 3
            },
            {
                'name': 'VIDEO_TRIGGER_EVENT_VAL_TV_EVENT_ANY_LINE',
                'value': 4
            },
            {
                'name': 'VIDEO_TRIGGER_EVENT_VAL_TV_EVENT_LINE_NUMBER',
                'value': 5
            },
            {
                'name': 'WIDTH_CONDITION_VAL_WIDTH_WITHIN',
                'value': 1
            },
            {
                'name': 'WIDTH_CONDITION_VAL_WIDTH_OUTSIDE',
                'value': 2
            },
            {
                'name': 'WIDTH_POLARITY_VAL_WIDTH_POSITIVE',
                'value': 1
            },
            {
                'name': 'WIDTH_POLARITY_VAL_WIDTH_NEGATIVE',
                'value': 2
            },
            {
                'name': 'WIDTH_POLARITY_VAL_WIDTH_EITHER',
                'value': 3
            }
        ]
    },
    'NiScopeReal64AttributeValues': {
        'enum-value-prefix': 'NISCOPE_REAL64',
        'generate-mappings': False,
        'values': [
            {
                'name': 'CABLE_SENSE_MODE_VAL_CABLE_SENSE_MODE_DISABLED',
                'value': 0
            },
            {
                'name': 'CABLE_SENSE_MODE_VAL_CABLE_SENSE_MODE_ON_DEMAND',
                'value': 1
            }
        ]
    },
    'NiScopeReal64AttributeValuesMapped': {
        'enum-value-prefix': 'NISCOPE_REAL64',
        'generate-mappings': True,
        'values': [
            {
                'name': 'INPUT_IMPEDANCE_VAL_50_OHMS',
                'value': 50.0
            },
            {
                'name': 'INPUT_IMPEDANCE_VAL_75_OHMS',
                'value': 75.0
            },
            {
                'name': 'INPUT_IMPEDANCE_VAL_1_MEG_OHM',
                'value': 1000000.0
            },
            {
                'name': 'MAX_INPUT_FREQUENCY_VAL_BANDWIDTH_DEVICE_DEFAULT',
                'value': 0.0
            },
            {
                'name': 'MAX_INPUT_FREQUENCY_VAL_BANDWIDTH_FULL',
                'value': -1.0
            },
            {
                'name': 'MAX_INPUT_FREQUENCY_VAL_20MHZ_BANDWIDTH',
                'value': 20000000.0
            },
            {
                'name': 'MAX_INPUT_FREQUENCY_VAL_100MHZ_BANDWIDTH',
                'value': 100000000.0
            },
            {
                'name': 'MAX_INPUT_FREQUENCY_VAL_20MHZ_MAX_INPUT_FREQUENCY',
                'value': 20000000.0
            },
            {
                'name': 'MAX_INPUT_FREQUENCY_VAL_100MHZ_MAX_INPUT_FREQUENCY',
                'value': 100000000.0
            }
        ]
    },
    'NiScopeStringAttributeValuesMapped': {
        'enum-value-prefix': 'NISCOPE_STRING',
        'generate-mappings': True,
        'values': [
            {
                'name': 'SAMP_CLK_TIMEPACE_SRC_VAL_CLK_IN',
                'value': 'VAL_CLK_IN'
            },
            {
                'name': 'SAMP_CLK_TIMEPACE_SRC_VAL_NO_SOURCE',
                'value': 'VAL_NO_SOURCE'
            },
            {
                'name': 'SAMP_CLK_TIMEPACE_SRC_VAL_PXI_STAR',
                'value': 'VAL_PXI_STAR'
            },
            {
                'name': 'SAMP_CLK_TIMEPACE_SRC_VAL_PXIE_DSTAR_A',
                'value': 'VAL_PXIE_DSTAR_A'
            },
            {
                'name': 'SAMP_CLK_TIMEPACE_SRC_VAL_AUX_0_CLK_IN',
                'value': 'VAL_AUX_0_CLK_IN'
            },
            {
                'name': 'SAMP_CLK_TIMEPACE_SRC_VAL_ONBOARD_CONFIGURABLE_RATE_CLK',
                'value': 'VAL_ONBOARD_CONFIGURABLE_RATE_CLK'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_IMMEDIATE',
                'value': 'VAL_IMMEDIATE'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_EXTERNAL',
                'value': 'VAL_EXTERNAL'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_SW_TRIG_FUNC',
                'value': 'VAL_SW_TRIG_FUNC'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL0',
                'value': 'VAL_TTL0'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL1',
                'value': 'VAL_TTL1'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL2',
                'value': 'VAL_TTL2'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL3',
                'value': 'VAL_TTL3'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL4',
                'value': 'VAL_TTL4'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL5',
                'value': 'VAL_TTL5'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL6',
                'value': 'VAL_TTL6'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_TTL7',
                'value': 'VAL_TTL7'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_ECL0',
                'value': 'VAL_ECL0'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_ECL1',
                'value': 'VAL_ECL1'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PXI_STAR',
                'value': 'VAL_PXI_STAR'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_0',
                'value': 'VAL_RTSI_0'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_1',
                'value': 'VAL_RTSI_1'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_2',
                'value': 'VAL_RTSI_2'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_3',
                'value': 'VAL_RTSI_3'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_4',
                'value': 'VAL_RTSI_4'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_5',
                'value': 'VAL_RTSI_5'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_6',
                'value': 'VAL_RTSI_6'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_RTSI_7',
                'value': 'VAL_RTSI_7'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_0',
                'value': 'VAL_PFI_0'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_1',
                'value': 'VAL_PFI_1'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_2',
                'value': 'VAL_PFI_2'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_3',
                'value': 'VAL_PFI_3'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_4',
                'value': 'VAL_PFI_4'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_5',
                'value': 'VAL_PFI_5'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_6',
                'value': 'VAL_PFI_6'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_PFI_7',
                'value': 'VAL_PFI_7'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_0',
                'value': 'VAL_AUX_0_PFI_0'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_1',
                'value': 'VAL_AUX_0_PFI_1'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_3',
                'value': 'VAL_AUX_0_PFI_3'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_4',
                'value': 'VAL_AUX_0_PFI_4'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_5',
                'value': 'VAL_AUX_0_PFI_5'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_6',
                'value': 'VAL_AUX_0_PFI_6'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_7',
                'value': 'VAL_AUX_0_PFI_7'
            },
            {
                'name': 'TRIGGER_SOURCE_VAL_AUX_0_PFI_2',
                'value': 'VAL_AUX_0_PFI_2'
            }
        ]
    },
    'NotificationType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_NOTIFY_NEVER',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_NOTIFY_DONE',
                'value': 1
            }
        ]
    },
    'Option': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_SELF_CALIBRATE_ALL_CHANNELS',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_RESTORE_EXTERNAL_CALIBRATION',
                'value': 1
            }
        ]
    },
    'OverflowErrorReporting': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_ERROR_REPORTING_ERROR',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_ERROR_REPORTING_WARNING',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_ERROR_REPORTING_DISABLED',
                'value': 2
            }
        ]
    },
    'P2PStreamRelativeTo': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_STREAM_RELATIVE_TO_START_TRIGGER',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_STREAM_RELATIVE_TO_REFERENCE_TRIGGER',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_STREAM_RELATIVE_TO_SYNC_TRIGGER',
                'value': 2
            }
        ]
    },
    'RISMethod': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_RIS_EXACT_NUM_AVERAGES',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_RIS_MIN_NUM_AVERAGES',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_RIS_INCOMPLETE',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_RIS_LIMITED_BIN_WIDTH',
                'value': 5
            }
        ]
    },
    'RefTriggerDetectorLocation': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_ANALOG_DETECTION_CIRCUIT',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_DDC_OUTPUT',
                'value': 1
            }
        ]
    },
    'RuntPolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_RUNT_POSITIVE',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_RUNT_NEGATIVE',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_RUNT_EITHER',
                'value': 3
            }
        ]
    },
    'RuntTimeCondition': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_RUNT_TIME_CONDITION_NONE',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_RUNT_TIME_CONDITION_WITHIN',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_RUNT_TIME_CONDITION_OUTSIDE',
                'value': 2
            }
        ]
    },
    'SampClkTimepaceSrc': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NISCOPE_VAL_CLK_IN',
                'value': 'VAL_CLK_IN'
            },
            {
                'name': 'NISCOPE_VAL_NO_SOURCE',
                'value': 'VAL_NO_SOURCE'
            },
            {
                'name': 'NISCOPE_VAL_PXI_STAR',
                'value': 'VAL_PXI_STAR'
            },
            {
                'name': 'NISCOPE_VAL_PXIE_DSTAR_A',
                'value': 'VAL_PXIE_DSTAR_A'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_CLK_IN',
                'value': 'VAL_AUX_0_CLK_IN'
            },
            {
                'name': 'NISCOPE_VAL_ONBOARD_CONFIGURABLE_RATE_CLK',
                'value': 'VAL_ONBOARD_CONFIGURABLE_RATE_CLK'
            }
        ]
    },
    'SampleMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_REAL_TIME',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_EQUIVALENT_TIME',
                'value': 1
            }
        ]
    },
    'ScalarMeasurement': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_RISE_TIME',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_NO_MEASUREMENT',
                'value': 4000
            },
            {
                'name': 'NISCOPE_VAL_FALL_TIME',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_FREQUENCY',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_PERIOD',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_RMS',
                'value': 4
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_PEAK_TO_PEAK',
                'value': 5
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_MAX',
                'value': 6
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_MIN',
                'value': 7
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_HIGH',
                'value': 8
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_LOW',
                'value': 9
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_AVERAGE',
                'value': 10
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_NEG',
                'value': 11
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_POS',
                'value': 12
            },
            {
                'name': 'NISCOPE_VAL_DUTY_CYCLE_NEG',
                'value': 13
            },
            {
                'name': 'NISCOPE_VAL_DUTY_CYCLE_POS',
                'value': 14
            },
            {
                'name': 'NISCOPE_VAL_AMPLITUDE',
                'value': 15
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_CYCLE_RMS',
                'value': 16
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_CYCLE_AVERAGE',
                'value': 17
            },
            {
                'name': 'NISCOPE_VAL_OVERSHOOT',
                'value': 18
            },
            {
                'name': 'NISCOPE_VAL_PRESHOOT',
                'value': 19
            },
            {
                'name': 'NISCOPE_VAL_LOW_REF_VOLTS',
                'value': 1000
            },
            {
                'name': 'NISCOPE_VAL_MID_REF_VOLTS',
                'value': 1001
            },
            {
                'name': 'NISCOPE_VAL_HIGH_REF_VOLTS',
                'value': 1002
            },
            {
                'name': 'NISCOPE_VAL_AREA',
                'value': 1003
            },
            {
                'name': 'NISCOPE_VAL_CYCLE_AREA',
                'value': 1004
            },
            {
                'name': 'NISCOPE_VAL_INTEGRAL',
                'value': 1005
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_BASE',
                'value': 1006
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_TOP',
                'value': 1007
            },
            {
                'name': 'NISCOPE_VAL_FFT_FREQUENCY',
                'value': 1008
            },
            {
                'name': 'NISCOPE_VAL_FFT_AMPLITUDE',
                'value': 1009
            },
            {
                'name': 'NISCOPE_VAL_RISE_SLEW_RATE',
                'value': 1010
            },
            {
                'name': 'NISCOPE_VAL_FALL_SLEW_RATE',
                'value': 1011
            },
            {
                'name': 'NISCOPE_VAL_AC_ESTIMATE',
                'value': 1012
            },
            {
                'name': 'NISCOPE_VAL_DC_ESTIMATE',
                'value': 1013
            },
            {
                'name': 'NISCOPE_VAL_TIME_DELAY',
                'value': 1014
            },
            {
                'name': 'NISCOPE_VAL_AVERAGE_PERIOD',
                'value': 1015
            },
            {
                'name': 'NISCOPE_VAL_AVERAGE_FREQUENCY',
                'value': 1016
            },
            {
                'name': 'NISCOPE_VAL_VOLTAGE_BASE_TO_TOP',
                'value': 1017
            },
            {
                'name': 'NISCOPE_VAL_PHASE_DELAY',
                'value': 1018
            }
        ]
    },
    'TerminalConfiguration': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_SINGLE_ENDED',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_UNBALANCED_DIFFERENTIAL',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_DIFFERENTIAL',
                'value': 2
            }
        ]
    },
    'TriggerCoupling': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_AC',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_DC',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_HF_REJECT',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_LF_REJECT',
                'value': 4
            },
            {
                'name': 'NISCOPE_VAL_AC_PLUS_HF_REJECT',
                'value': 1001
            }
        ]
    },
    'TriggerModifier': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_NO_TRIGGER_MOD',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_AUTO',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_AUTO_LEVEL',
                'value': 3
            }
        ]
    },
    'TriggerSlope': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_NEGATIVE',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_POSITIVE',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_SLOPE_EITHER',
                'value': 3
            }
        ]
    },
    'TriggerSource': {
        'codegen_method': 'public',
        'generate-mappings': True,
        'values': [
            {
                'name': 'NISCOPE_VAL_IMMEDIATE',
                'value': 'VAL_IMMEDIATE'
            },
            {
                'name': 'NISCOPE_VAL_EXTERNAL',
                'value': 'VAL_EXTERNAL'
            },
            {
                'name': 'NISCOPE_VAL_SW_TRIG_FUNC',
                'value': 'VAL_SW_TRIG_FUNC'
            },
            {
                'name': 'NISCOPE_VAL_TTL0',
                'value': 'VAL_TTL0'
            },
            {
                'name': 'NISCOPE_VAL_TTL1',
                'value': 'VAL_TTL1'
            },
            {
                'name': 'NISCOPE_VAL_TTL2',
                'value': 'VAL_TTL2'
            },
            {
                'name': 'NISCOPE_VAL_TTL3',
                'value': 'VAL_TTL3'
            },
            {
                'name': 'NISCOPE_VAL_TTL4',
                'value': 'VAL_TTL4'
            },
            {
                'name': 'NISCOPE_VAL_TTL5',
                'value': 'VAL_TTL5'
            },
            {
                'name': 'NISCOPE_VAL_TTL6',
                'value': 'VAL_TTL6'
            },
            {
                'name': 'NISCOPE_VAL_TTL7',
                'value': 'VAL_TTL7'
            },
            {
                'name': 'NISCOPE_VAL_ECL0',
                'value': 'VAL_ECL0'
            },
            {
                'name': 'NISCOPE_VAL_ECL1',
                'value': 'VAL_ECL1'
            },
            {
                'name': 'NISCOPE_VAL_PXI_STAR',
                'value': 'VAL_PXI_STAR'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_0',
                'value': 'VAL_RTSI_0'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_1',
                'value': 'VAL_RTSI_1'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_2',
                'value': 'VAL_RTSI_2'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_3',
                'value': 'VAL_RTSI_3'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_4',
                'value': 'VAL_RTSI_4'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_5',
                'value': 'VAL_RTSI_5'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_6',
                'value': 'VAL_RTSI_6'
            },
            {
                'name': 'NISCOPE_VAL_RTSI_7',
                'value': 'VAL_RTSI_7'
            },
            {
                'name': 'NISCOPE_VAL_PFI_0',
                'value': 'VAL_PFI_0'
            },
            {
                'name': 'NISCOPE_VAL_PFI_1',
                'value': 'VAL_PFI_1'
            },
            {
                'name': 'NISCOPE_VAL_PFI_2',
                'value': 'VAL_PFI_2'
            },
            {
                'name': 'NISCOPE_VAL_PFI_3',
                'value': 'VAL_PFI_3'
            },
            {
                'name': 'NISCOPE_VAL_PFI_4',
                'value': 'VAL_PFI_4'
            },
            {
                'name': 'NISCOPE_VAL_PFI_5',
                'value': 'VAL_PFI_5'
            },
            {
                'name': 'NISCOPE_VAL_PFI_6',
                'value': 'VAL_PFI_6'
            },
            {
                'name': 'NISCOPE_VAL_PFI_7',
                'value': 'VAL_PFI_7'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_0',
                'value': 'VAL_AUX_0_PFI_0'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_1',
                'value': 'VAL_AUX_0_PFI_1'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_3',
                'value': 'VAL_AUX_0_PFI_3'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_4',
                'value': 'VAL_AUX_0_PFI_4'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_5',
                'value': 'VAL_AUX_0_PFI_5'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_6',
                'value': 'VAL_AUX_0_PFI_6'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_7',
                'value': 'VAL_AUX_0_PFI_7'
            },
            {
                'name': 'NISCOPE_VAL_AUX_0_PFI_2',
                'value': 'VAL_AUX_0_PFI_2'
            }
        ]
    },
    'TriggerType': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_EDGE_TRIGGER',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_HYSTERESIS_TRIGGER',
                'value': 1001
            },
            {
                'name': 'NISCOPE_VAL_DIGITAL_TRIGGER',
                'value': 1002
            },
            {
                'name': 'NISCOPE_VAL_WINDOW_TRIGGER',
                'value': 1003
            },
            {
                'name': 'NISCOPE_VAL_SOFTWARE_TRIGGER',
                'value': 1004
            },
            {
                'name': 'NISCOPE_VAL_TV_TRIGGER',
                'value': 5
            },
            {
                'name': 'NISCOPE_VAL_GLITCH_TRIGGER',
                'value': 4
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_TRIGGER',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_RUNT_TRIGGER',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_IMMEDIATE_TRIGGER',
                'value': 6
            }
        ]
    },
    'TriggerWindowMode': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_ENTERING_WINDOW',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_LEAVING_WINDOW',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_ENTERING_OR_LEAVING_WINDOW',
                'value': 2
            }
        ]
    },
    'VerticalCoupling': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_AC',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_DC',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_GND',
                'value': 2
            }
        ]
    },
    'VideoPolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_TV_POSITIVE',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_TV_NEGATIVE',
                'value': 2
            }
        ]
    },
    'VideoSignalFormat': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_NTSC',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_PAL',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_SECAM',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_M_PAL',
                'value': 1001
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_480I_59_94_FIELDS_PER_SECOND',
                'value': 1010
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_480I_60_FIELDS_PER_SECOND',
                'value': 1011
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_480P_59_94_FRAMES_PER_SECOND',
                'value': 1015
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_480P_60_FRAMES_PER_SECOND',
                'value': 1016
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_576I_50_FIELDS_PER_SECOND',
                'value': 1020
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_576P_50_FRAMES_PER_SECOND',
                'value': 1025
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_720P_50_FRAMES_PER_SECOND',
                'value': 1031
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_720P_59_94_FRAMES_PER_SECOND',
                'value': 1032
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_720P_60_FRAMES_PER_SECOND',
                'value': 1033
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_1080I_50_FIELDS_PER_SECOND',
                'value': 1040
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_1080I_59_94_FIELDS_PER_SECOND',
                'value': 1041
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_1080I_60_FIELDS_PER_SECOND',
                'value': 1042
            },
            {
                'name': 'NISCOPE_VAL_VIDEO_1080P_24_FRAMES_PER_SECOND',
                'value': 1045
            }
        ]
    },
    'VideoTriggerEvent': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_TV_EVENT_FIELD1',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_TV_EVENT_FIELD2',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_TV_EVENT_ANY_FIELD',
                'value': 3
            },
            {
                'name': 'NISCOPE_VAL_TV_EVENT_ANY_LINE',
                'value': 4
            },
            {
                'name': 'NISCOPE_VAL_TV_EVENT_LINE_NUMBER',
                'value': 5
            }
        ]
    },
    'WhichTrigger': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_SOFTWARE_TRIGGER_START',
                'value': 0
            },
            {
                'name': 'NISCOPE_VAL_SOFTWARE_TRIGGER_ARM_REFERENCE',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_SOFTWARE_TRIGGER_REFERENCE',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_SOFTWARE_TRIGGER_ADVANCE',
                'value': 3
            }
        ]
    },
    'WidthCondition': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_WIDTH_WITHIN',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_OUTSIDE',
                'value': 2
            }
        ]
    },
    'WidthPolarity': {
        'codegen_method': 'public',
        'values': [
            {
                'name': 'NISCOPE_VAL_WIDTH_POSITIVE',
                'value': 1
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_NEGATIVE',
                'value': 2
            },
            {
                'name': 'NISCOPE_VAL_WIDTH_EITHER',
                'value': 3
            }
        ]
    }
}
