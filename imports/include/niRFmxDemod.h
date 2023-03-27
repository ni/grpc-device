
/****************************************************************************************************
*          National Instruments RFmx Demod
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxDemod.h
*
* Purpose:  National Instruments RFmx Demod,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_DEMOD_H__
#define __NI_RFMX_DEMOD_H__

#include "niRFmxInstr.h"

#define RFMXDEMOD_ATTR_ADEMOD_MEASUREMENT_ENABLED                                         0x00200039
#define RFMXDEMOD_ATTR_ADEMOD_AUDIO_MEASUREMENT_ENABLED                                   0x00200040
#define RFMXDEMOD_ATTR_ADEMOD_MODULATION_TYPE                                             0x0020000e
#define RFMXDEMOD_ATTR_ADEMOD_AM_CARRIER_SUPPRESSED                                       0x00200002
#define RFMXDEMOD_ATTR_ADEMOD_RBW_FILTER_TYPE                                             0x00200010
#define RFMXDEMOD_ATTR_ADEMOD_RBW_FILTER_BANDWIDTH                                        0x00200011
#define RFMXDEMOD_ATTR_ADEMOD_RBW_FILTER_ALPHA                                            0x00200012
#define RFMXDEMOD_ATTR_ADEMOD_MEASUREMENT_INTERVAL                                        0x0020000d
#define RFMXDEMOD_ATTR_ADEMOD_CARRIER_CORRECTION_FREQUENCY_ENABLED                        0x0020000a
#define RFMXDEMOD_ATTR_ADEMOD_CARRIER_CORRECTION_PHASE_ENABLED                            0x0020000b
#define RFMXDEMOD_ATTR_ADEMOD_FM_DEEMPHASIS                                               0x0020000c
#define RFMXDEMOD_ATTR_ADEMOD_AUDIO_FILTER_TYPE                                           0x00200003
#define RFMXDEMOD_ATTR_ADEMOD_AUDIO_FILTER_LOWER_CUTOFF_FREQUENCY                         0x00200004
#define RFMXDEMOD_ATTR_ADEMOD_AUDIO_FILTER_UPPER_CUTOFF_FREQUENCY                         0x00200005
#define RFMXDEMOD_ATTR_ADEMOD_AVERAGING_ENABLED                                           0x00200006
#define RFMXDEMOD_ATTR_ADEMOD_AVERAGING_COUNT                                             0x00200007
#define RFMXDEMOD_ATTR_ADEMOD_AVERAGING_TYPE                                              0x00200009
#define RFMXDEMOD_ATTR_ADEMOD_ALL_TRACES_ENABLED                                          0x00200013
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_MEAN_CARRIER_FREQUENCY_ERROR                        0x00200014
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_MEAN_CARRIER_POWER                                  0x00200015
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_MEAN_MODULATION_FREQUENCY                           0x00200016
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AVERAGE_SINAD                                       0x00200017
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AVERAGE_THD_WITH_NOISE                              0x00200018
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AVERAGE_THD                                         0x00200019
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AVERAGE_SNR                                         0x0020001a
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MEAN_STANDARD_DEVIATION         0x0020001b
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MEAN_HALF_PEAK_TO_PEAK          0x0020001c
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MEAN_POSITIVE_PEAK              0x0020001d
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MEAN_NEGATIVE_PEAK              0x0020001e
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MEAN_RMS                        0x0020001f
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MAXIMUM_STANDARD_DEVIATION      0x00200020
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MAXIMUM_HALF_PEAK_TO_PEAK       0x00200021
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MAXIMUM_POSITIVE_PEAK           0x00200022
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MAXIMUM_NEGATIVE_PEAK           0x00200023
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_AM_MODULATION_DEPTH_MAXIMUM_RMS                     0x00200024
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MEAN_STANDARD_DEVIATION                0x00200025
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MEAN_HALF_PEAK_TO_PEAK                 0x00200026
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MEAN_POSITIVE_PEAK                     0x00200027
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MEAN_NEGATIVE_PEAK                     0x00200028
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MEAN_RMS                               0x00200029
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MAXIMUM_STANDARD_DEVIATION             0x0020002a
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MAXIMUM_HALF_PEAK_TO_PEAK              0x0020002b
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MAXIMUM_POSITIVE_PEAK                  0x0020002c
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MAXIMUM_NEGATIVE_PEAK                  0x0020002d
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_FM_DEVIATION_MAXIMUM_RMS                            0x0020002e
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MEAN_STANDARD_DEVIATION                0x0020002f
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MEAN_HALF_PEAK_TO_PEAK                 0x00200030
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MEAN_POSITIVE_PEAK                     0x00200031
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MEAN_NEGATIVE_PEAK                     0x00200032
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MEAN_RMS                               0x00200033
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MAXIMUM_STANDARD_DEVIATION             0x00200034
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MAXIMUM_HALF_PEAK_TO_PEAK              0x00200035
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MAXIMUM_POSITIVE_PEAK                  0x00200036
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MAXIMUM_NEGATIVE_PEAK                  0x00200037
#define RFMXDEMOD_ATTR_ADEMOD_RESULTS_PM_DEVIATION_MAXIMUM_RMS                            0x00200038
#define RFMXDEMOD_ATTR_DDEMOD_MEASUREMENT_ENABLED                                         0x00201000
#define RFMXDEMOD_ATTR_DDEMOD_MODULATION_TYPE                                             0x0020100b
#define RFMXDEMOD_ATTR_DDEMOD_M                                                           0x00201009
#define RFMXDEMOD_ATTR_DDEMOD_SPECTRUM_INVERTED                                           0x00201012
#define RFMXDEMOD_ATTR_DDEMOD_PSK_FORMAT                                                  0x0020100e
#define RFMXDEMOD_ATTR_DDEMOD_DIFFERENTIAL_ENABLED                                        0x00201005
#define RFMXDEMOD_ATTR_DDEMOD_SYMBOL_RATE                                                 0x00201013
#define RFMXDEMOD_ATTR_DDEMOD_NUMBER_OF_SYMBOLS                                           0x0020100d
#define RFMXDEMOD_ATTR_DDEMOD_SAMPLES_PER_SYMBOL                                          0x00201011
#define RFMXDEMOD_ATTR_DDEMOD_EVM_NORMALIZATION_REFERENCE                                 0x00201039
#define RFMXDEMOD_ATTR_DDEMOD_FSK_DEVIATION                                               0x00201008
#define RFMXDEMOD_ATTR_DDEMOD_FSK_REFERENCE_COMPENSATION_ENABLED                          0x00201038
#define RFMXDEMOD_ATTR_DDEMOD_SYMBOL_MAP_TYPE                                             0x00201040
#define RFMXDEMOD_ATTR_DDEMOD_PULSE_SHAPING_FILTER_TYPE                                   0x0020100f
#define RFMXDEMOD_ATTR_DDEMOD_PULSE_SHAPING_FILTER_PARAMETER                              0x00201010
#define RFMXDEMOD_ATTR_DDEMOD_MEASUREMENT_FILTER_TYPE                                     0x0020100a
#define RFMXDEMOD_ATTR_DDEMOD_EQUALIZER_MODE                                              0x00201006
#define RFMXDEMOD_ATTR_DDEMOD_EQUALIZER_FILTER_LENGTH                                     0x00201036
#define RFMXDEMOD_ATTR_DDEMOD_EQUALIZER_TRAINING_COUNT                                    0x00201037
#define RFMXDEMOD_ATTR_DDEMOD_EQUALIZER_CONVERGENCE_FACTOR                                0x00201007
#define RFMXDEMOD_ATTR_DDEMOD_SYNCHRONIZATION_ENABLED                                     0x00201014
#define RFMXDEMOD_ATTR_DDEMOD_SYNCHRONIZATION_BITS                                        0x0020101f
#define RFMXDEMOD_ATTR_DDEMOD_SYNCHRONIZATION_MEASUREMENT_OFFSET                          0x00201034
#define RFMXDEMOD_ATTR_DDEMOD_AVERAGING_ENABLED                                           0x00201002
#define RFMXDEMOD_ATTR_DDEMOD_AVERAGING_COUNT                                             0x00201003
#define RFMXDEMOD_ATTR_DDEMOD_ALL_TRACES_ENABLED                                          0x00201015
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_CARRIER_MEAN_FREQUENCY_OFFSET                       0x00201021
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_CARRIER_MEAN_FREQUENCY_DRIFT                        0x00201022
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_CARRIER_MEAN_PHASE_ERROR                            0x00201023
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_EVM_MEAN_RMS                                        0x00201024
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_EVM_MAXIMUM_RMS                                     0x00201025
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_EVM_MEAN_PEAK                                       0x00201026
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_EVM_MAXIMUM_PEAK                                    0x00201027
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_EVM_MEAN_MODULATION_ERROR_RATIO                     0x00201028
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_OFFSET_EVM_MEAN_RMS                                 0x0020103a
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_OFFSET_EVM_MEAN_PEAK                                0x0020103b
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_OFFSET_EVM_MAXIMUM_RMS                              0x0020103c
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_OFFSET_EVM_MAXIMUM_PEAK                             0x0020103d
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_MAGNITUDE_ERROR_MEAN                                0x00201029
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_MAGNITUDE_ERROR_MAXIMUM                             0x0020102a
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_PHASE_ERROR_MEAN                                    0x0020102b
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_PHASE_ERROR_MAXIMUM                                 0x0020102c
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_FSK_MEAN_DEVIATION                                  0x0020102d
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_FSK_MEAN_RMS_FSK_ERROR                              0x0020102e
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_FSK_MAXIMUM_PEAK_FSK_ERROR                          0x0020102f
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_IQ_IMPAIRMENTS_MEAN_IQ_ORIGIN_OFFSET                0x00201032
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_IQ_IMPAIRMENTS_MEAN_IQ_GAIN_IMBALANCE               0x00201030
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_IQ_IMPAIRMENTS_MEAN_QUADRATURE_SKEW                 0x00201031
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_MEAN_RHO_FACTOR                                     0x0020103e
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_MEAN_AMPLITUDE_DROOP                                0x0020103f
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_SYNC_FOUND                                          0x00201035
#define RFMXDEMOD_ATTR_RESULT_FETCH_TIMEOUT                                               0x00203000
#define RFMXDEMOD_ATTR_LIMITED_CONFIGURATION_CHANGE                                       0x0020200e
#define RFMXDEMOD_ATTR_CENTER_FREQUENCY                                                   0x00202001
#define RFMXDEMOD_ATTR_REFERENCE_LEVEL                                                    0x00202003
#define RFMXDEMOD_ATTR_EXTERNAL_ATTENUATION                                               0x00202002
#define RFMXDEMOD_ATTR_TRIGGER_TYPE                                                       0x00202004
#define RFMXDEMOD_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                        0x00202005
#define RFMXDEMOD_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                          0x00202006
#define RFMXDEMOD_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                       0x00202007
#define RFMXDEMOD_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                        0x00202008
#define RFMXDEMOD_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                                   0x00202fff
#define RFMXDEMOD_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                        0x00202009
#define RFMXDEMOD_ATTR_TRIGGER_DELAY                                                      0x0020200a
#define RFMXDEMOD_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                    0x0020200b
#define RFMXDEMOD_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                                0x0020200c
#define RFMXDEMOD_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                                 0x0020200d
#define RFMXDEMOD_ATTR_DDEMOD_SIGNAL_STRUCTURE                                            0x00201041
#define RFMXDEMOD_ATTR_DDEMOD_BURST_START_EXCLUSION_SYMBOLS                               0x00201042
#define RFMXDEMOD_ATTR_DDEMOD_BURST_END_EXCLUSION_SYMBOLS                                 0x00201043
#define RFMXDEMOD_ATTR_DDEMOD_IQ_OFFSET_REMOVAL_ENABLED                                   0x00201044
#define RFMXDEMOD_ATTR_DDEMOD_CFO_ESTIMATION_MODE                                         0x00201045
#define RFMXDEMOD_ATTR_DDEMOD_SEARCH_LENGTH_AUTO                                          0x00201047
#define RFMXDEMOD_ATTR_DDEMOD_SEARCH_LENGTH                                               0x00201048
#define RFMXDEMOD_ATTR_SELECTED_PORTS                                                     0x00202ffd
#define RFMXDEMOD_ATTR_REFERENCE_LEVEL_HEADROOM                                           0x00202ffc

// Values for RFMXDEMOD_ATTR_TRIGGER_TYPE
#define RFMXDEMOD_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXDEMOD_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXDEMOD_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXDEMOD_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXDEMOD_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXDEMOD_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXDEMOD_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXDEMOD_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXDEMOD_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXDEMOD_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXDEMOD_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXDEMOD_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXDEMOD_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXDEMOD_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXDEMOD_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXDEMOD_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXDEMOD_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXDEMOD_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXDEMOD_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXDEMOD_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXDEMOD_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXDEMOD_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXDEMOD_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXDEMOD_VAL_TIMER_EVENT_STR                                                                "TimerEvent"

// Values for RFMXDEMOD_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXDEMOD_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXDEMOD_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXDEMOD_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXDEMOD_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXDEMOD_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXDEMOD_ATTR_ADEMOD_AM_CARRIER_SUPPRESSED
#define RFMXDEMOD_VAL_ADEMOD_AM_CARRIER_SUPPRESSED_FALSE                                             0
#define RFMXDEMOD_VAL_ADEMOD_AM_CARRIER_SUPPRESSED_TRUE                                              1

// Values for RFMXDEMOD_ATTR_ADEMOD_AUDIO_FILTER_TYPE
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_FILTER_TYPE_NONE                                                  0
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_FILTER_TYPE_CUSTOM                                                1
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_FILTER_TYPE_A_WEIGHT                                              2
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_FILTER_TYPE_B_WEIGHT                                              3
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_FILTER_TYPE_C_WEIGHT                                              4
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_FILTER_TYPE_CCITT                                                 5
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_FILTER_TYPE_ITU_R_468_4                                           6

// Values for RFMXDEMOD_ATTR_ADEMOD_AVERAGING_ENABLED
#define RFMXDEMOD_VAL_ADEMOD_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXDEMOD_VAL_ADEMOD_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXDEMOD_ATTR_ADEMOD_AVERAGING_TYPE
#define RFMXDEMOD_VAL_ADEMOD_AVERAGING_TYPE_LINEAR                                                   0
#define RFMXDEMOD_VAL_ADEMOD_AVERAGING_TYPE_MAXIMUM                                                  1
#define RFMXDEMOD_VAL_ADEMOD_AVERAGING_TYPE_MINIMUM                                                  2

// Values for RFMXDEMOD_ATTR_ADEMOD_CARRIER_CORRECTION_FREQUENCY_ENABLED
#define RFMXDEMOD_VAL_ADEMOD_CARRIER_FREQUENCY_CORRECTION_ENABLED_FALSE                              0
#define RFMXDEMOD_VAL_ADEMOD_CARRIER_FREQUENCY_CORRECTION_ENABLED_TRUE                               1

// Values for RFMXDEMOD_ATTR_ADEMOD_CARRIER_CORRECTION_PHASE_ENABLED
#define RFMXDEMOD_VAL_ADEMOD_CARRIER_PHASE_CORRECTION_ENABLED_FALSE                                  0
#define RFMXDEMOD_VAL_ADEMOD_CARRIER_PHASE_CORRECTION_ENABLED_TRUE                                   1

// Values for RFMXDEMOD_ATTR_ADEMOD_AUDIO_MEASUREMENT_ENABLED
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_MEASUREMENT_ENABLED_FALSE                                         0
#define RFMXDEMOD_VAL_ADEMOD_AUDIO_MEASUREMENT_ENABLED_TRUE                                          1

// Values for RFMXDEMOD_ATTR_ADEMOD_MODULATION_TYPE
#define RFMXDEMOD_VAL_ADEMOD_MODULATION_TYPE_AM                                                      0
#define RFMXDEMOD_VAL_ADEMOD_MODULATION_TYPE_FM                                                      1
#define RFMXDEMOD_VAL_ADEMOD_MODULATION_TYPE_PM                                                      2

// Values for RFMXDEMOD_ATTR_ADEMOD_RBW_FILTER_TYPE
#define RFMXDEMOD_VAL_ADEMOD_RBW_FILTER_TYPE_NONE                                                    0
#define RFMXDEMOD_VAL_ADEMOD_RBW_FILTER_TYPE_GAUSSIAN                                                1
#define RFMXDEMOD_VAL_ADEMOD_RBW_FILTER_TYPE_FLAT                                                    2
#define RFMXDEMOD_VAL_ADEMOD_RBW_FILTER_TYPE_SYNCH_TUNED_4                                           3
#define RFMXDEMOD_VAL_ADEMOD_RBW_FILTER_TYPE_SYNCH_TUNED_5                                           4
#define RFMXDEMOD_VAL_ADEMOD_RBW_FILTER_TYPE_RRC                                                     5

// Values for RFMXDEMOD_ATTR_DDEMOD_AVERAGING_ENABLED
#define RFMXDEMOD_VAL_DDEMOD_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXDEMOD_VAL_DDEMOD_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXDEMOD_ATTR_DDEMOD_EQUALIZER_MODE
#define RFMXDEMOD_VAL_DDEMOD_EQUALIZER_MODE_OFF                                                      0
#define RFMXDEMOD_VAL_DDEMOD_EQUALIZER_MODE_TRAIN                                                    1
#define RFMXDEMOD_VAL_DDEMOD_EQUALIZER_MODE_HOLD                                                     2

// Values for RFMXDEMOD_ATTR_DDEMOD_EVM_NORMALIZATION_REFERENCE
#define RFMXDEMOD_VAL_DDEMOD_EVM_NORMALIZATION_REFERENCE_PEAK                                        0
#define RFMXDEMOD_VAL_DDEMOD_EVM_NORMALIZATION_REFERENCE_RMS                                         1

// Values for RFMXDEMOD_ATTR_DDEMOD_FSK_REFERENCE_COMPENSATION_ENABLED
#define RFMXDEMOD_VAL_DDEMOD_FSK_REFERENCE_COMPENSATION_ENABLED_FALSE                                0
#define RFMXDEMOD_VAL_DDEMOD_FSK_REFERENCE_COMPENSATION_ENABLED_TRUE                                 1

// Values for RFMXDEMOD_ATTR_DDEMOD_M
#define RFMXDEMOD_VAL_DDEMOD_M_2                                                                     2
#define RFMXDEMOD_VAL_DDEMOD_M_4                                                                     4
#define RFMXDEMOD_VAL_DDEMOD_M_8                                                                     8
#define RFMXDEMOD_VAL_DDEMOD_M_16                                                                    16
#define RFMXDEMOD_VAL_DDEMOD_M_32                                                                    32
#define RFMXDEMOD_VAL_DDEMOD_M_64                                                                    64
#define RFMXDEMOD_VAL_DDEMOD_M_128                                                                   128
#define RFMXDEMOD_VAL_DDEMOD_M_256                                                                   256
#define RFMXDEMOD_VAL_DDEMOD_M_512                                                                   512
#define RFMXDEMOD_VAL_DDEMOD_M_1024                                                                  1024
#define RFMXDEMOD_VAL_DDEMOD_M_2048                                                                  2048
#define RFMXDEMOD_VAL_DDEMOD_M_4096                                                                  4096

// Values for RFMXDEMOD_ATTR_DDEMOD_MEASUREMENT_FILTER_TYPE
#define RFMXDEMOD_VAL_DDEMOD_MEASUREMENT_FILTER_TYPE_AUTO                                            0
#define RFMXDEMOD_VAL_DDEMOD_MEASUREMENT_FILTER_TYPE_CUSTOM                                          1

// Values for RFMXDEMOD_ATTR_DDEMOD_MODULATION_TYPE
#define RFMXDEMOD_VAL_DDEMOD_MODULATION_TYPE_ASK                                                     0
#define RFMXDEMOD_VAL_DDEMOD_MODULATION_TYPE_FSK                                                     1
#define RFMXDEMOD_VAL_DDEMOD_MODULATION_TYPE_PSK                                                     2
#define RFMXDEMOD_VAL_DDEMOD_MODULATION_TYPE_QAM                                                     3
#define RFMXDEMOD_VAL_DDEMOD_MODULATION_TYPE_MSK                                                     4

// Values for RFMXDEMOD_ATTR_DDEMOD_DIFFERENTIAL_ENABLED
#define RFMXDEMOD_VAL_DDEMOD_DIFFERENTIAL_ENABLED_FALSE                                              0
#define RFMXDEMOD_VAL_DDEMOD_DIFFERENTIAL_ENABLED_TRUE                                               1

// Values for RFMXDEMOD_ATTR_DDEMOD_PSK_FORMAT
#define RFMXDEMOD_VAL_DDEMOD_PSK_FORMAT_NORMAL                                                       0
#define RFMXDEMOD_VAL_DDEMOD_PSK_FORMAT_OFFSET_QPSK                                                  1
#define RFMXDEMOD_VAL_DDEMOD_PSK_FORMAT_PI_BY_4_QPSK                                                 2
#define RFMXDEMOD_VAL_DDEMOD_PSK_FORMAT_PI_BY_8_8PSK                                                 3
#define RFMXDEMOD_VAL_DDEMOD_PSK_FORMAT_3PI_BY_8_8PSK                                                4

// Values for RFMXDEMOD_ATTR_DDEMOD_PULSE_SHAPING_FILTER_TYPE
#define RFMXDEMOD_VAL_DDEMOD_PULSE_SHAPING_FILTER_TYPE_RECTANGULAR                                   0
#define RFMXDEMOD_VAL_DDEMOD_PULSE_SHAPING_FILTER_TYPE_RAISED_COSINE                                 1
#define RFMXDEMOD_VAL_DDEMOD_PULSE_SHAPING_FILTER_TYPE_ROOT_RAISED_COSINE                            2
#define RFMXDEMOD_VAL_DDEMOD_PULSE_SHAPING_FILTER_TYPE_GAUSSIAN                                      3
#define RFMXDEMOD_VAL_DDEMOD_PULSE_SHAPING_FILTER_TYPE_CUSTOM                                        4
#define RFMXDEMOD_VAL_DDEMOD_PULSE_SHAPING_FILTER_TYPE_HALF_SINE                                     5
#define RFMXDEMOD_VAL_DDEMOD_PULSE_SHAPING_FILTER_TYPE_LINEARIZED_GMSK_EDGE                          6

// Values for RFMXDEMOD_ATTR_DDEMOD_SPECTRUM_INVERTED
#define RFMXDEMOD_VAL_DDEMOD_SPECTRUM_INVERTED_FALSE                                                 0
#define RFMXDEMOD_VAL_DDEMOD_SPECTRUM_INVERTED_TRUE                                                  1

// Values for RFMXDEMOD_ATTR_DDEMOD_SYMBOL_MAP_TYPE
#define RFMXDEMOD_VAL_DDEMOD_SYMBOL_MAP_TYPE_AUTO                                                    0
#define RFMXDEMOD_VAL_DDEMOD_SYMBOL_MAP_TYPE_CUSTOM                                                  1

// Values for RFMXDEMOD_ATTR_DDEMOD_SYNCHRONIZATION_ENABLED
#define RFMXDEMOD_VAL_DDEMOD_SYNCHRONIZATION_ENABLED_FALSE                                           0
#define RFMXDEMOD_VAL_DDEMOD_SYNCHRONIZATION_ENABLED_TRUE                                            1

// Values for RFMXDEMOD_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXDEMOD_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXDEMOD_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXDEMOD_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXDEMOD_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXDEMOD_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXDEMOD_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Boolean
#define RFMXDEMOD_VAL_FALSE                                                                          0
#define RFMXDEMOD_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXDEMOD_VAL_ADEMOD                                                                         1 << 0
#define RFMXDEMOD_VAL_DDEMOD                                                                         1 << 1

// Values for FrequencyReferenceSource
#define RFMXDEMOD_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXDEMOD_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXDEMOD_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXDEMOD_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for RFAttenuationAuto
#define RFMXDEMOD_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXDEMOD_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXDEMOD_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXDEMOD_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

// Values for RFMXDEMOD_ATTR_DDEMOD_SIGNAL_STRUCTURE
#define RFMXDEMOD_VAL_DDEMOD_SIGNAL_STRUCTURE_BURSTED                                                0
#define RFMXDEMOD_VAL_DDEMOD_SIGNAL_STRUCTURE_CONTINUOUS                                             1

// Values for RFMXDEMOD_ATTR_DDEMOD_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXDEMOD_VAL_DDEMOD_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                         0
#define RFMXDEMOD_VAL_DDEMOD_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                          1

// Values for RFMXDEMOD_ATTR_DDEMOD_CFO_ESTIMATION_MODE
#define RFMXDEMOD_VAL_DDEMOD_CFO_ESTIMATION_MODE_NARROW                                              0
#define RFMXDEMOD_VAL_DDEMOD_CFO_ESTIMATION_MODE_WIDE                                                1

// Values for RFMXDEMOD_ATTR_DDEMOD_SEARCH_LENGTH_AUTO
#define RFMXDEMOD_VAL_DDEMOD_SEARCH_LENGTH_AUTO_FALSE                                                0
#define RFMXDEMOD_VAL_DDEMOD_SEARCH_LENGTH_AUTO_TRUE                                                 1

/* ---------------- RFmxDemod APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxDemod_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxDemod_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxDemod_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxDemod_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxDemod_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxDemod_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxDemod_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxDemod_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxDemod_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxDemod_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxDemod_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxDemod_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxDemod_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxDemod_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxDemod_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxDemod_DDemodSetSymbolMap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodSetSymbolMapSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 I[],
   float32 Q[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgSymbolMap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 symbolMapType,
   NIComplexSingle symbolMap[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgSymbolMapSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 symbolMapType,
   float32 I[],
   float32 Q[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgEqualizerInitialCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle equalizerInitialCoefficients[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgEqualizerInitialCoefficientsSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxDemod_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxDemod_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxDemod_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 bandwidth,
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxDemod_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxDemod_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxDemod_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxDemod_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxDemod_AnalyzeIQ1Waveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   NIComplexSingle IQ[],
   int32 arraySize,
   int32 reset,
   int64 reserved
);

int32 __stdcall RFmxDemod_AnalyzeIQ1WaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32 reset,
   int64 reserved
);

int32 __stdcall RFmxDemod_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxDemod_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxDemod_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxDemod_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxDemod_DDemodCfgModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 modulationType,
   int32 M,
   int32 differentialEnabled
);

int32 __stdcall RFmxDemod_DDemodCfgM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 M
);

int32 __stdcall RFmxDemod_DDemodCfgNumberOfSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSymbols
);

int32 __stdcall RFmxDemod_DDemodCfgSamplesPerSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 samplesPerSymbol
);

int32 __stdcall RFmxDemod_DDemodCfgSymbolRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 symbolRate
);

int32 __stdcall RFmxDemod_DDemodCfgPSKFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 PSKFormat
);

int32 __stdcall RFmxDemod_DDemodCfgFSKDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 FSKDeviation,
   int32 FSKRefCompEnabled
);

int32 __stdcall RFmxDemod_DDemodCfgSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spectrumInverted
);

int32 __stdcall RFmxDemod_DDemodCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxDemod_DDemodCfgPulseShapingFilterCustomCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 pulseShapingFilterCustomCoefficients[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgMeasurementFilterCustomCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 measurementFilterCustomCoefficients[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgSynchronization(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationEnabled,
   int8 syncBits[],
   int32 measurementOffset,
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgEVMNormalizationReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 EVMNormRef
);

int32 __stdcall RFmxDemod_DDemodCfgSignalStructure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 signalStructure
);

int32 __stdcall RFmxDemod_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxDemod_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxDemod_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxDemod_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxDemod_ADemodCfgModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 modulationType
);

int32 __stdcall RFmxDemod_ADemodCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxDemod_ADemodCfgAMCarrierSuppressed(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 AMCarrierSuppressedEnabled
);

int32 __stdcall RFmxDemod_ADemodCfgAudioFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 audioFilterType,
   float64 audioFilterLowerCutoffFrequency,
   float64 audioFilterUpperCutoffFrequency
);

int32 __stdcall RFmxDemod_ADemodCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxDemod_ADemodCfgCarrierCorrection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 carrierFrequencyCorrectionEnabled,
   int32 carrierPhaseCorrectionEnabled
);

int32 __stdcall RFmxDemod_ADemodCfgFMDeEmphasis(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 deEmphasis
);

int32 __stdcall RFmxDemod_ADemodCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 RBW,
   int32 RBWFilterType,
   float64 RBWRRCAlpha
);

int32 __stdcall RFmxDemod_DDemodCfgEqualizer(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 equalizerMode,
   int32 equalizerFilterLength,
   float64 x0,
   float64 dx,
   NIComplexSingle equalizerInitialCoefficients[],
   int32 equalizerTrainingCount,
   float64 equalizerConvergenceFactor,
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgEqualizerSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 equalizerMode,
   int32 equalizerFilterLength,
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 equalizerTrainingCount,
   float64 equalizerConvergenceFactor,
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgMeasurementFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementFilterType,
   float64 x0,
   float64 dx,
   float32 measurementFilterCustomCoefficients[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodCfgPulseShapingFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 pulseShapingFilterType,
   float64 pulseShapingFilterParameter,
   float64 x0,
   float64 dx,
   float32 pulseShapingFilterCustomCoefficients[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxDemod_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxDemod_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxDemod_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxDemod_CfgIQPowerEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char IQPowerEdgeSource[],
   float64 IQPowerEdgeLevel,
   int32 IQPowerEdgeSlope,
   float64 triggerDelay,
   int32 triggerMinQuietTimeMode,
   float64 triggerMinQuietTimeDuration,
   int32 enableTrigger
);

int32 __stdcall RFmxDemod_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxDemod_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxDemod_SetAttributeNIComplexSingle(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal
);

int32 __stdcall RFmxDemod_GetAttributeNIComplexSingle(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle *attrVal
);

int32 __stdcall RFmxDemod_SetAttributeNIComplexDouble(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal
);

int32 __stdcall RFmxDemod_GetAttributeNIComplexDouble(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetEqualizerInitialCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* x0,
   float64* dx,
   NIComplexSingle equalizerInitialCoefficients[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodGetEqualizerInitialCoefficientsSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* x0,
   float64* dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodGetSymbolMap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexSingle symbolMap[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodGetSymbolMapSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchOffsetEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 offsetEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchEqualizerCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle equalizerCoefficients[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchEqualizerCoefficientsSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchFSKDeviationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 FSKError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchMeasurementWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle measurementWaveform[],
   int32 arraySize,
   int32* actualArraySize,
   int32* samplesPerSymbol,
   float64* symbolRate
);

int32 __stdcall RFmxDemod_DDemodFetchMeasurementWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize,
   int32* samplesPerSymbol,
   float64* symbolRate
);

int32 __stdcall RFmxDemod_DDemodFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellationTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchOffsetConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle offsetConstellationTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchOffsetConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchDemodulatedBits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int8 demodulatedBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_DDemodFetchEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSEVM,
   float64* maximumRMSEVM,
   float64* meanModulationErrorRatio,
   float64* maximumPeakEVM,
   float64* meanPeakEVM
);

int32 __stdcall RFmxDemod_DDemodFetchOffsetEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSOffsetEVM,
   float64* maximumRMSOffsetEVM,
   float64* maximumPeakOffsetEVM,
   float64* meanPeakOffsetEVM
);

int32 __stdcall RFmxDemod_DDemodFetchMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanMagnitudeError,
   float64* maximumMagnitudeError
);

int32 __stdcall RFmxDemod_DDemodFetchPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanPhaseError,
   float64* maximumPhaseError
);

int32 __stdcall RFmxDemod_DDemodFetchFSKResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanFSKDeviation,
   float64* meanRMSFSKError,
   float64* maximumPeakFSKError
);

int32 __stdcall RFmxDemod_DDemodFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanIQGainImbalance,
   float64* meanQuadratureSkew,
   float64* meanIQOriginOffset
);

int32 __stdcall RFmxDemod_DDemodFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanFrequencyOffset,
   float64* meanFrequencyDrift,
   float64* meanPhaseError
);

int32 __stdcall RFmxDemod_DDemodFetchMeanIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32* meanIQOriginOffset
);

int32 __stdcall RFmxDemod_DDemodFetchMeanQuadratureSkew(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32* meanQuadratureSkew
);

int32 __stdcall RFmxDemod_DDemodFetchMeanRhoFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRhoFactor
);

int32 __stdcall RFmxDemod_DDemodFetchSyncFound(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* syncFound
);

int32 __stdcall RFmxDemod_DDemodFetchMeanAmplitudeDroop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanAmplitudeDroop
);

int32 __stdcall RFmxDemod_DDemodRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanFrequencyOffset,
   float64* meanRMSEVM,
   float64* maximumPeakEVM,
   float64* meanModulationErrorRatio
);

int32 __stdcall RFmxDemod_ADemodFetchDemodSignalTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 demodulatedSignal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_ADemodFetchDemodSpectrumTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 demodulatedSpectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxDemod_ADemodFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanCarrierFrequencyError,
   float64* meanCarrierPower
);

int32 __stdcall RFmxDemod_ADemodFetchMeanModulationFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanModulationFrequency
);

int32 __stdcall RFmxDemod_ADemodFetchAMMaximumModulationDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumModulationDepth,
   float64* maximumHalfPeakToPeak,
   float64* maximumRMS,
   float64* maximumPositivePeak,
   float64* maximumNegativePeak
);

int32 __stdcall RFmxDemod_ADemodFetchAMMeanModulationDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanModulationDepth,
   float64* meanHalfPeakToPeak,
   float64* meanRMS,
   float64* meanPositivePeak,
   float64* meanNegativePeak
);

int32 __stdcall RFmxDemod_ADemodReadAM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanModulationDepth,
   float64* meanCarrierPower
);

int32 __stdcall RFmxDemod_ADemodFetchFMMaximumDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumDeviation,
   float64* maximumHalfPeakToPeak,
   float64* maximumRMS,
   float64* maximumPositivePeak,
   float64* maximumNegativePeak
);

int32 __stdcall RFmxDemod_ADemodFetchFMMeanDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanDeviation,
   float64* meanHalfPeakToPeak,
   float64* meanRMS,
   float64* meanPositivePeak,
   float64* meanNegativePeak
);

int32 __stdcall RFmxDemod_ADemodReadFM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanDeviation,
   float64* meanCarrierFrequencyError
);

int32 __stdcall RFmxDemod_ADemodFetchPMMaximumDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumDeviation,
   float64* maximumHalfPeakToPeak,
   float64* maximumRMS,
   float64* maximumPositivePeak,
   float64* maximumNegativePeak
);

int32 __stdcall RFmxDemod_ADemodFetchPMMeanDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanDeviation,
   float64* meanHalfPeakToPeak,
   float64* meanRMS,
   float64* meanPositivePeak,
   float64* meanNegativePeak
);

int32 __stdcall RFmxDemod_ADemodReadPM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanDeviation,
   float64* meanCarrierFrequencyError
);

int32 __stdcall RFmxDemod_ADemodFetchDistortions(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageSINAD,
   float64* averageSNR,
   float64* averageTHD,
   float64* averageTHDWithNoise
);

int32 __stdcall RFmxDemod_ADemodGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAudioMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAudioMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAMCarrierSuppressed(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAMCarrierSuppressed(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetCarrierCorrectionFrequencyEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetCarrierCorrectionFrequencyEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetCarrierCorrectionPhaseEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetCarrierCorrectionPhaseEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetFMDeEmphasis(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetFMDeEmphasis(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAudioFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAudioFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAudioFilterLowerCutoffFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAudioFilterLowerCutoffFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAudioFilterUpperCutoffFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAudioFilterUpperCutoffFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_ADemodSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsMeanCarrierFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsMeanCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsMeanModulationFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAverageSINAD(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAverageTHDWithNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAverageTHD(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAverageSNR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMeanStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMeanHalfPeaktoPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMeanPositivePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMeanNegativePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMeanRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMaximumStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMaximumHalfPeaktoPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMaximumPositivePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMaximumNegativePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsAMModulationDepthMaximumRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMeanStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMeanHalfPeaktoPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMeanPositivePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMeanNegativePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMeanRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMaximumStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMaximumHalfPeaktoPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMaximumPositivePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMaximumNegativePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsFMDeviationMaximumRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMeanStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMeanHalfPeaktoPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMeanPositivePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMeanNegativePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMeanRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMaximumStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMaximumHalfPeaktoPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMaximumPositivePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMaximumNegativePeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_ADemodGetResultsPMDeviationMaximumRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetPSKFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetPSKFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetDifferentialEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetDifferentialEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSymbolRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSymbolRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetNumberOfSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetNumberOfSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSamplesPerSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSamplesPerSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetEVMNormalizationReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetEVMNormalizationReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetFSKDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetFSKDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetFSKReferenceCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetFSKReferenceCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSymbolMapType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSymbolMapType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetPulseShapingFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetPulseShapingFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetPulseShapingFilterParameter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetPulseShapingFilterParameter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetMeasurementFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetMeasurementFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetEqualizerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetEqualizerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetEqualizerFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetEqualizerFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetEqualizerTrainingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetEqualizerTrainingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetEqualizerConvergenceFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetEqualizerConvergenceFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSynchronizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSynchronizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSynchronizationBits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int8 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxDemod_DDemodSetSynchronizationBits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxDemod_DDemodGetSynchronizationMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSynchronizationMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsCarrierMeanFrequencyOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsCarrierMeanFrequencyDrift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsCarrierMeanPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsEVMMeanRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsEVMMaximumRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsEVMMeanPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsEVMMaximumPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsEVMMeanModulationErrorRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsOffsetEVMMeanRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsOffsetEVMMeanPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsOffsetEVMMaximumRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsOffsetEVMMaximumPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsMagnitudeErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsMagnitudeErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsPhaseErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsPhaseErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsFSKMeanDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsFSKMeanRMSFSKError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsFSKMaximumPeakFSKError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsIQImpairmentsMeanIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsIQImpairmentsMeanIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsIQImpairmentsMeanQuadratureSkew(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsMeanRhoFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsMeanAmplitudeDroop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsSyncFound(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSignalStructure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSignalStructure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetBurstStartExclusionSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetBurstStartExclusionSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetBurstEndExclusionSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetBurstEndExclusionSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetCFOEstimationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetCFOEstimationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSearchLengthAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSearchLengthAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_DDemodGetSearchLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodSetSearchLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxDemod_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxDemod_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxDemod_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxDemod_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxDemod_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxDemod_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxDemod_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxDemod_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxDemod_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_CARRIER_MEAN_FREQUENCY_ERROR                        0x00201021
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_FSK_MEAN_RMS_DEVIATION_ERROR                        0x0020102e
#define RFMXDEMOD_ATTR_DDEMOD_RESULTS_FSK_MEAN_PEAK_DEVIATION_ERROR                       0x0020102f

// Values for RFMXDEMOD_ATTR_DDEMOD_SAMPLES_PER_SYMBOL
#define RFMXDEMOD_VAL_DDEMOD_SAMPLES_PER_SYMBOL_AUTO                                                 -1
#define RFMXDEMOD_VAL_DDEMOD_SAMPLES_PER_SYMBOL_4                                                    4
#define RFMXDEMOD_VAL_DDEMOD_SAMPLES_PER_SYMBOL_8                                                    8
#define RFMXDEMOD_VAL_DDEMOD_SAMPLES_PER_SYMBOL_16                                                   16

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxDemod_DDemodGetResultsCarrierMeanFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsFSKMeanRMSDeviationError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxDemod_DDemodGetResultsFSKMeanPeakDeviationError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif


#endif

