
/****************************************************************************************************
*          National Instruments RFmx GSM
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxGSM.h
*
* Purpose:  National Instruments RFmx GSM,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_GSM_H__
#define __NI_RFMX_GSM_H__

#include "niRFmxInstr.h"

#define RFMXGSM_ATTR_MODACC_MEASUREMENT_ENABLED                              0x00401000
#define RFMXGSM_ATTR_MODACC_AVERAGING_ENABLED                                0x00401002
#define RFMXGSM_ATTR_MODACC_AVERAGING_COUNT                                  0x00401004
#define RFMXGSM_ATTR_MODACC_MEASUREMENT_INTERVAL                             0x0040102a
#define RFMXGSM_ATTR_MODACC_MEASUREMENT_OFFSET                               0x0040102b
#define RFMXGSM_ATTR_MODACC_DROOP_COMPENSATION_ENABLED                       0x00401005
#define RFMXGSM_ATTR_MODACC_ALL_TRACES_ENABLED                               0x00401006
#define RFMXGSM_ATTR_MODACC_NUMBER_OF_ANALYSIS_THREADS                       0x00401007
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_RMS_EVM                         0x00401008
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_RMS_EVM                      0x00401009
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_PEAK_EVM                        0x0040100a
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_PEAK_EVM                     0x0040100b
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_95TH_PERCENTILE_EVM                  0x0040100c
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_PEAK_EVM_SYMBOL                      0x0040100d
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_MAGNITUDE_ERROR                 0x0040100e
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_MAGNITUDE_ERROR              0x0040100f
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_PHASE_ERROR                     0x00401010
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_PHASE_ERROR                  0x00401011
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_FREQUENCY_ERROR                 0x00401012
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_FREQUENCY_ERROR              0x00401013
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_AMPLITUDE_DROOP                 0x00401014
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_AMPLITUDE_DROOP              0x00401015
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_MEAN_RMS_PHASE_ERROR                0x00401016
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_MAXIMUM_RMS_PHASE_ERROR             0x00401017
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_MEAN_PEAK_PHASE_ERROR               0x00401018
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_MAXIMUM_PEAK_PHASE_ERROR            0x00401019
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_PEAK_PHASE_ERROR_SYMBOL             0x0040101a
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_MEAN_FREQUENCY_ERROR                0x0040101b
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_MAXIMUM_FREQUENCY_ERROR             0x0040101c
#define RFMXGSM_ATTR_MODACC_RESULTS_MEAN_IQ_GAIN_IMBALANCE                   0x0040101d
#define RFMXGSM_ATTR_MODACC_RESULTS_MAXIMUM_IQ_GAIN_IMBALANCE                0x0040101e
#define RFMXGSM_ATTR_MODACC_RESULTS_MEAN_IQ_ORIGIN_OFFSET                    0x0040101f
#define RFMXGSM_ATTR_MODACC_RESULTS_MAXIMUM_IQ_ORIGIN_OFFSET                 0x00401020
#define RFMXGSM_ATTR_MODACC_RESULTS_DETECTED_TSC                             0x00401021
#define RFMXGSM_ATTR_ORFS_MEASUREMENT_ENABLED                                0x00402000
#define RFMXGSM_ATTR_ORFS_AVERAGING_ENABLED                                  0x00402002
#define RFMXGSM_ATTR_ORFS_AVERAGING_TYPE                                     0x00402003
#define RFMXGSM_ATTR_ORFS_AVERAGING_COUNT                                    0x00402004
#define RFMXGSM_ATTR_ORFS_MEASUREMENT_INTERVAL                               0x00402025
#define RFMXGSM_ATTR_ORFS_MEASUREMENT_OFFSET                                 0x00402026
#define RFMXGSM_ATTR_ORFS_MEASUREMENT_TYPE                                   0x00402005
#define RFMXGSM_ATTR_ORFS_OFFSET_FREQUENCY_MODE                              0x00402007
#define RFMXGSM_ATTR_ORFS_EVALUATION_SYMBOLS_START                           0x00402011
#define RFMXGSM_ATTR_ORFS_EVALUATION_SYMBOLS_INCLUDE_TSC                     0x00402012
#define RFMXGSM_ATTR_ORFS_EVALUATION_SYMBOLS_STOP                            0x00402013
#define RFMXGSM_ATTR_ORFS_EVALUATION_SYMBOLS_SCOPE                           0x00402024
#define RFMXGSM_ATTR_ORFS_MODULATION_CARRIER_RBW                             0x0040200b
#define RFMXGSM_ATTR_ORFS_MODULATION_NUMBER_OF_OFFSETS                       0x0040201d
#define RFMXGSM_ATTR_ORFS_MODULATION_OFFSET_FREQUENCY                        0x0040201e
#define RFMXGSM_ATTR_ORFS_MODULATION_OFFSET_RBW                              0x0040201f
#define RFMXGSM_ATTR_ORFS_SWITCHING_CARRIER_RBW                              0x0040200e
#define RFMXGSM_ATTR_ORFS_SWITCHING_NUMBER_OF_OFFSETS                        0x00402020
#define RFMXGSM_ATTR_ORFS_SWITCHING_OFFSET_FREQUENCY                         0x00402021
#define RFMXGSM_ATTR_ORFS_SWITCHING_OFFSET_RBW                               0x00402022
#define RFMXGSM_ATTR_ORFS_NOISE_COMPENSATION_ENABLED                         0x00402006
#define RFMXGSM_ATTR_ORFS_ALL_TRACES_ENABLED                                 0x00402014
#define RFMXGSM_ATTR_ORFS_NUMBER_OF_ANALYSIS_THREADS                         0x00402015
#define RFMXGSM_ATTR_PVT_MEASUREMENT_ENABLED                                 0x00403000
#define RFMXGSM_ATTR_PVT_AVERAGING_ENABLED                                   0x00403002
#define RFMXGSM_ATTR_PVT_AVERAGING_TYPE                                      0x00403004
#define RFMXGSM_ATTR_PVT_AVERAGING_COUNT                                     0x00403005
#define RFMXGSM_ATTR_PVT_RBW_FILTER_BANDWIDTH                                0x00403007
#define RFMXGSM_ATTR_PVT_ALL_TRACES_ENABLED                                  0x00403009
#define RFMXGSM_ATTR_PVT_NUMBER_OF_ANALYSIS_THREADS                          0x0040300a
#define RFMXGSM_ATTR_PVT_RESULTS_MEASUREMENT_STATUS                          0x0040300b
#define RFMXGSM_ATTR_PVT_RESULTS_SLOT_AVERAGE_POWER                          0x0040300c
#define RFMXGSM_ATTR_PVT_RESULTS_SLOT_BURST_WIDTH                            0x0040300d
#define RFMXGSM_ATTR_PVT_RESULTS_SLOT_MAXIMUM_POWER                          0x0040300e
#define RFMXGSM_ATTR_PVT_RESULTS_SLOT_MINIMUM_POWER                          0x0040300f
#define RFMXGSM_ATTR_PVT_RESULTS_SLOT_BURST_THRESHOLD                        0x00403010
#define RFMXGSM_ATTR_PVT_RESULTS_SLOT_MEASUREMENT_STATUS                     0x00403011
#define RFMXGSM_ATTR_LIMITED_CONFIGURATION_CHANGE                            0x0040d003
#define RFMXGSM_ATTR_RESULT_FETCH_TIMEOUT                                    0x0040c000
#define RFMXGSM_ATTR_CENTER_FREQUENCY                                        0x00400001
#define RFMXGSM_ATTR_REFERENCE_LEVEL                                         0x00400002
#define RFMXGSM_ATTR_EXTERNAL_ATTENUATION                                    0x00400003
#define RFMXGSM_ATTR_TRIGGER_TYPE                                            0x00400004
#define RFMXGSM_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                             0x00400005
#define RFMXGSM_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                               0x00400006
#define RFMXGSM_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                            0x00400007
#define RFMXGSM_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                             0x00400008
#define RFMXGSM_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                        0x00400fff
#define RFMXGSM_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                             0x00400009
#define RFMXGSM_ATTR_TRIGGER_DELAY                                           0x0040000a
#define RFMXGSM_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                         0x0040000b
#define RFMXGSM_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                     0x0040000c
#define RFMXGSM_ATTR_LINK_DIRECTION                                          0x0040000d
#define RFMXGSM_ATTR_BAND                                                    0x0040000e
#define RFMXGSM_ATTR_SIGNAL_STRUCTURE                                        0x00400017
#define RFMXGSM_ATTR_NUMBER_OF_TIMESLOTS                                     0x0040000f
#define RFMXGSM_ATTR_MODULATION_TYPE                                         0x00400010
#define RFMXGSM_ATTR_BURST_TYPE                                              0x00400011
#define RFMXGSM_ATTR_HB_FILTER_WIDTH                                         0x00400012
#define RFMXGSM_ATTR_AUTO_TSC_DETECTION_ENABLED                              0x00400013
#define RFMXGSM_ATTR_TSC                                                     0x00400014
#define RFMXGSM_ATTR_POWER_CONTROL_LEVEL                                     0x00400015
#define RFMXGSM_ATTR_TIMING_ADVANCE                                          0x00400018
#define RFMXGSM_ATTR_BURST_SYNCHRONIZATION_TYPE                              0x00400016
#define RFMXGSM_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                      0x0040d000
#define RFMXGSM_ATTR_SELECTED_PORTS                                          0x00400ffd
#define RFMXGSM_ATTR_REFERENCE_LEVEL_HEADROOM                                0x00400ffc
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_PEAK_MAGNITUDE_ERROR            0x00401023
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_PEAK_MAGNITUDE_ERROR         0x00401024
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_95TH_PERCENTILE_MAGNITUDE_ERROR      0x00401025
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MEAN_PEAK_PHASE_ERROR                0x00401026
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_MAXIMUM_PEAK_PHASE_ERROR             0x00401027
#define RFMXGSM_ATTR_MODACC_RESULTS_EVM_95TH_PERCENTILE_PHASE_ERROR          0x00401028
#define RFMXGSM_ATTR_MODACC_RESULTS_PFER_95TH_PERCENTILE_PHASE_ERROR         0x00401029

// Values for RFMXGSM_ATTR_TRIGGER_TYPE
#define RFMXGSM_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXGSM_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXGSM_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXGSM_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXGSM_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXGSM_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXGSM_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXGSM_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXGSM_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXGSM_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXGSM_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXGSM_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXGSM_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXGSM_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXGSM_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXGSM_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXGSM_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXGSM_VAL_TIMER_EVENT_STR                                                                "TimerEvent"
#define RFMXGSM_VAL_PULSE_IN_STR                                                                   "PulseIn"
#define RFMXGSM_VAL_DIO_PFI0_STR                                                                   "DIO/PFI0"
#define RFMXGSM_VAL_DIO_PFI1_STR                                                                   "DIO/PFI1"
#define RFMXGSM_VAL_DIO_PFI2_STR                                                                   "DIO/PFI2"
#define RFMXGSM_VAL_DIO_PFI3_STR                                                                   "DIO/PFI3"
#define RFMXGSM_VAL_DIO_PFI4_STR                                                                   "DIO/PFI4"
#define RFMXGSM_VAL_DIO_PFI5_STR                                                                   "DIO/PFI5"
#define RFMXGSM_VAL_DIO_PFI6_STR                                                                   "DIO/PFI6"
#define RFMXGSM_VAL_DIO_PFI7_STR                                                                   "DIO/PFI7"

// Values for RFMXGSM_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXGSM_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXGSM_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXGSM_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXGSM_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXGSM_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXGSM_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXGSM_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXGSM_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXGSM_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXGSM_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXGSM_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXGSM_ATTR_LINK_DIRECTION
#define RFMXGSM_VAL_LINK_DIRECTION_DOWNLINK                                                        0
#define RFMXGSM_VAL_LINK_DIRECTION_UPLINK                                                          1

// Values for RFMXGSM_ATTR_BAND
#define RFMXGSM_VAL_BAND_PGSM                                                                      0
#define RFMXGSM_VAL_BAND_EGSM                                                                      1
#define RFMXGSM_VAL_BAND_RGSM                                                                      2
#define RFMXGSM_VAL_BAND_DCS1800                                                                   3
#define RFMXGSM_VAL_BAND_PCS1900                                                                   4
#define RFMXGSM_VAL_BAND_GSM450                                                                    5
#define RFMXGSM_VAL_BAND_GSM480                                                                    6
#define RFMXGSM_VAL_BAND_GSM850                                                                    7
#define RFMXGSM_VAL_BAND_GSM750                                                                    8
#define RFMXGSM_VAL_BAND_TGSM810                                                                   9

// Values for RFMXGSM_ATTR_SIGNAL_STRUCTURE
#define RFMXGSM_VAL_SIGNAL_STRUCTURE_BURSTED                                                       0
#define RFMXGSM_VAL_SIGNAL_STRUCTURE_CONTINUOUS                                                    1

// Values for RFMXGSM_ATTR_MODULATION_TYPE
#define RFMXGSM_VAL_MODULATION_TYPE_GMSK                                                           0
#define RFMXGSM_VAL_MODULATION_TYPE_8PSK                                                           1
#define RFMXGSM_VAL_MODULATION_TYPE_QPSK                                                           2
#define RFMXGSM_VAL_MODULATION_TYPE_16QAM                                                          3
#define RFMXGSM_VAL_MODULATION_TYPE_32QAM                                                          4

// Values for RFMXGSM_ATTR_BURST_TYPE
#define RFMXGSM_VAL_BURST_TYPE_NB                                                                  0
#define RFMXGSM_VAL_BURST_TYPE_HB                                                                  1
#define RFMXGSM_VAL_BURST_TYPE_AB                                                                  2

// Values for RFMXGSM_ATTR_HB_FILTER_WIDTH
#define RFMXGSM_VAL_HB_FILTER_WIDTH_NARROW                                                         0
#define RFMXGSM_VAL_HB_FILTER_WIDTH_WIDE                                                           1

// Values for RFMXGSM_ATTR_AUTO_TSC_DETECTION_ENABLED
#define RFMXGSM_VAL_AUTO_TSC_DETECTION_ENABLED_FALSE                                               0
#define RFMXGSM_VAL_AUTO_TSC_DETECTION_ENABLED_TRUE                                                1

// Values for RFMXGSM_ATTR_TSC
#define RFMXGSM_VAL_TSC0                                                                           0
#define RFMXGSM_VAL_TSC1                                                                           1
#define RFMXGSM_VAL_TSC2                                                                           2
#define RFMXGSM_VAL_TSC3                                                                           3
#define RFMXGSM_VAL_TSC4                                                                           4
#define RFMXGSM_VAL_TSC5                                                                           5
#define RFMXGSM_VAL_TSC6                                                                           6
#define RFMXGSM_VAL_TSC7                                                                           7

// Values for RFMXGSM_ATTR_BURST_SYNCHRONIZATION_TYPE
#define RFMXGSM_VAL_BURST_SYNC_TYPE_TSC                                                            0
#define RFMXGSM_VAL_BURST_SYNC_TYPE_AMPLITUDE                                                      1
#define RFMXGSM_VAL_BURST_SYNC_TYPE_NONE                                                           2

// Values for RFMXGSM_ATTR_MODACC_AVERAGING_ENABLED
#define RFMXGSM_VAL_MODACC_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXGSM_VAL_MODACC_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXGSM_ATTR_MODACC_MEASUREMENT_INTERVAL
#define RFMXGSM_VAL_MODACC_MEASUREMENT_INTERVAL_NUMBER_OF_TIMESLOTS                                0
#define RFMXGSM_VAL_MODACC_MEASUREMENT_INTERVAL_TIMESLOT_AT_OFFSET                                 1

// Values for RFMXGSM_ATTR_MODACC_DROOP_COMPENSATION_ENABLED
#define RFMXGSM_VAL_MODACC_DROOP_COMPENSATION_ENABLED_FALSE                                        0
#define RFMXGSM_VAL_MODACC_DROOP_COMPENSATION_ENABLED_TRUE                                         1

// Values for RFMXGSM_ATTR_MODACC_RESULTS_DETECTED_TSC
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_UNKNOWN                                                    -1
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC0                                                       0
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC1                                                       1
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC2                                                       2
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC3                                                       3
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC4                                                       4
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC5                                                       5
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC6                                                       6
#define RFMXGSM_VAL_MODACC_DETECTED_TSC_TSC7                                                       7

// Values for RFMXGSM_ATTR_ORFS_AVERAGING_ENABLED
#define RFMXGSM_VAL_ORFS_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXGSM_VAL_ORFS_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXGSM_ATTR_ORFS_AVERAGING_TYPE
#define RFMXGSM_VAL_ORFS_AVERAGING_TYPE_RMS                                                        0
#define RFMXGSM_VAL_ORFS_AVERAGING_TYPE_LOG                                                        1

// Values for RFMXGSM_ATTR_ORFS_MEASUREMENT_INTERVAL
#define RFMXGSM_VAL_ORFS_MEASUREMENT_INTERVAL_NUMBER_OF_TIMESLOTS                                  0
#define RFMXGSM_VAL_ORFS_MEASUREMENT_INTERVAL_TIMESLOT_AT_OFFSET                                   1

// Values for RFMXGSM_ATTR_ORFS_MEASUREMENT_TYPE
#define RFMXGSM_VAL_ORFS_MEASUREMENT_TYPE_MODULATION_AND_SWITCHING                                 0
#define RFMXGSM_VAL_ORFS_MEASUREMENT_TYPE_MODULATION                                               1
#define RFMXGSM_VAL_ORFS_MEASUREMENT_TYPE_SWITCHING                                                2

// Values for RFMXGSM_ATTR_ORFS_OFFSET_FREQUENCY_MODE
#define RFMXGSM_VAL_ORFS_OFFSET_FREQUENCY_MODE_STANDARD                                            0
#define RFMXGSM_VAL_ORFS_OFFSET_FREQUENCY_MODE_SHORT                                               1
#define RFMXGSM_VAL_ORFS_OFFSET_FREQUENCY_MODE_CUSTOM                                              2

// Values for RFMXGSM_ATTR_ORFS_EVALUATION_SYMBOLS_INCLUDE_TSC
#define RFMXGSM_VAL_ORFS_EVALUATION_SYMBOLS_INCLUDE_TSC_FALSE                                      0
#define RFMXGSM_VAL_ORFS_EVALUATION_SYMBOLS_INCLUDE_TSC_TRUE                                       1

// Values for RFMXGSM_ATTR_ORFS_EVALUATION_SYMBOLS_SCOPE
#define RFMXGSM_VAL_ORFS_EVALUATION_SYMBOLS_SCOPE_OFFSET                                           0
#define RFMXGSM_VAL_ORFS_EVALUATION_SYMBOLS_SCOPE_OFFSET_AND_CARRIER                               1

// Values for RFMXGSM_ATTR_ORFS_NOISE_COMPENSATION_ENABLED
#define RFMXGSM_VAL_ORFS_NOISE_COMPENSATION_ENABLED_FALSE                                          0
#define RFMXGSM_VAL_ORFS_NOISE_COMPENSATION_ENABLED_TRUE                                           1

// Values for RFMXGSM_ATTR_PVT_AVERAGING_ENABLED
#define RFMXGSM_VAL_PVT_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXGSM_VAL_PVT_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXGSM_ATTR_PVT_AVERAGING_TYPE
#define RFMXGSM_VAL_PVT_AVERAGING_TYPE_RMS                                                         0
#define RFMXGSM_VAL_PVT_AVERAGING_TYPE_LOG                                                         1
#define RFMXGSM_VAL_PVT_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXGSM_VAL_PVT_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXGSM_ATTR_PVT_RESULTS_MEASUREMENT_STATUS
#define RFMXGSM_VAL_PVT_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXGSM_VAL_PVT_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXGSM_ATTR_PVT_RESULTS_SLOT_MEASUREMENT_STATUS
#define RFMXGSM_VAL_PVT_SLOT_MEASUREMENT_STATUS_FAIL                                               0
#define RFMXGSM_VAL_PVT_SLOT_MEASUREMENT_STATUS_PASS                                               1

// Values for RFMXGSM_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXGSM_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXGSM_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXGSM_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXGSM_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXGSM_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXGSM_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Boolean
#define RFMXGSM_VAL_FALSE                                                                          0
#define RFMXGSM_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXGSM_VAL_MODACC                                                                         1 << 0
#define RFMXGSM_VAL_ORFS                                                                           1 << 1
#define RFMXGSM_VAL_PVT                                                                            1 << 2

// Values for FrequencyReferenceSource
#define RFMXGSM_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXGSM_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXGSM_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXGSM_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for RFAttenuationAuto
#define RFMXGSM_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXGSM_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXGSM_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXGSM_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

/* ---------------- RFmxGSM APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxGSM_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxGSM_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxGSM_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxGSM_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxGSM_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxGSM_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxGSM_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxGSM_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxGSM_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxGSM_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxGSM_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxGSM_BuildSlotString(
   char selectorString[],
   int32 slotNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxGSM_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxGSM_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxGSM_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxGSM_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxGSM_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxGSM_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxGSM_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* done
);

int32 __stdcall RFmxGSM_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxGSM_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxGSM_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxGSM_AnalyzeIQ1WaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 IQI[],
   float32 IQQ[],
   int32 arraySize,
   int32 reset,
   int64 reserved
);

int32 __stdcall RFmxGSM_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxGSM_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxGSM_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxGSM_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxGSM_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxGSM_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxGSM_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxGSM_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxGSM_ORFSCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxGSM_ORFSCfgEvaluationSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 evaluationSymbolsStart,
   int32 evaluationSymbolsIncludeTSC,
   float64 evaluationSymbolsStop
);

int32 __stdcall RFmxGSM_ORFSCfgMeasurementType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementType
);

int32 __stdcall RFmxGSM_ORFSCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxGSM_ORFSCfgOffsetFrequencyMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetFrequencyMode
);

int32 __stdcall RFmxGSM_ModAccCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxGSM_ModAccCfgDroopCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 droopCompensationEnabled
);

int32 __stdcall RFmxGSM_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxGSM_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxGSM_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxGSM_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxGSM_CfgNumberOfTimeslots(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfTimeslots
);

int32 __stdcall RFmxGSM_CfgAutoTSCDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoTSCDetectionEnabled
);

int32 __stdcall RFmxGSM_CfgSignalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 modulationType,
   int32 burstType,
   int32 HBFilterWidth
);

int32 __stdcall RFmxGSM_CfgTSC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 TSC
);

int32 __stdcall RFmxGSM_CfgBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 band
);

int32 __stdcall RFmxGSM_CfgBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 burstSynchronizationType
);

int32 __stdcall RFmxGSM_CfgLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 linkDirection
);

int32 __stdcall RFmxGSM_CfgPowerControlLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerControlLevel
);

int32 __stdcall RFmxGSM_PVTCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxGSM_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxGSM_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxGSM_ORFSCfgModulationCustomOffsetFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 modulationCustomOffsetFrequency[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_ORFSCfgSwitchingCustomOffsetFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 switchingCustomOffsetFrequency[],
   int32 arraySize
);

int32 __stdcall RFmxGSM_CfgFrequencyARFCN(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 linkDirection,
   int32 band,
   int32 ARFCN
);

int32 __stdcall RFmxGSM_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxGSM_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxGSM_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxGSM_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxGSM_CfgIQPowerEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char IQPowerEdgeSource[],
   int32 IQPowerEdgeSlope,
   float64 IQPowerEdgeLevel,
   float64 triggerDelay,
   int32 minimumQuietTimeMode,
   float64 minimumQuietTime,
   int32 IQPowerEdgeLevelType,
   int32 enableTrigger
);

int32 __stdcall RFmxGSM_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxGSM_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxGSM_ModAccFetchDemodulatedBits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int8 demodulatedBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ModAccFetchDetectedTSCArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 detectedTSC[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ModAccFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ModAccFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ModAccFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ModAccFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellationTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ModAccFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 constellationTraceI[],
   float32 constellationTraceQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ModAccFetchDetectedTSC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* detectedTSC
);

int32 __stdcall RFmxGSM_ModAccFetchEVMAmplitudeDroop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanAmplitudeDroop,
   float64* maximumAmplitudeDroop
);

int32 __stdcall RFmxGSM_ModAccFetchEVMMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanMagnitudeError,
   float64* maximumMagnitudeError
);

int32 __stdcall RFmxGSM_ModAccFetchEVMPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanPhaseError,
   float64* maximumPhaseError
);

int32 __stdcall RFmxGSM_ModAccFetchEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSEVM,
   float64* maximumRMSEVM,
   float64* meanPeakEVM,
   float64* maximumPeakEVM,
   float64* ninetyFifthPercentileEVM,
   float64* meanFrequencyError,
   int32* peakEVMSymbol
);

int32 __stdcall RFmxGSM_ModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanIQGainImbalance,
   float64* maximumIQGainImbalance,
   float64* meanIQOriginOffset,
   float64* maximumIQOriginOffset
);

int32 __stdcall RFmxGSM_ModAccFetchPFER(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSPhaseError,
   float64* maximumRMSPhaseError,
   float64* meanPeakPhaseError,
   float64* maximumPeakPhaseError,
   float64* meanFrequencyError,
   int32* peakSymbol
);

int32 __stdcall RFmxGSM_ORFSFetchModulationPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 offsetFrequency[],
   float32 absolutePower[],
   float32 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ORFSFetchModulationResultsArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* modulationCarrierPower,
   float64 lowerRelativePower[],
   float64 upperRelativePower[],
   float64 lowerAbsolutePower[],
   float64 upperAbsolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ORFSFetchSwitchingPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 offsetFrequency[],
   float32 absolutePower[],
   float32 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_ORFSFetchSwitchingResultsArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* switchingCarrierPower,
   float64 lowerRelativePower[],
   float64 upperRelativePower[],
   float64 lowerAbsolutePower[],
   float64 upperAbsolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_PVTFetchSlotMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 slotAveragePower[],
   float64 slotBurstWidth[],
   int32 slotMeasurementStatus[],
   float64 slotMaximumPower[],
   float64 slotMinimumPower[],
   float64 slotBurstThreshold[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_PVTFetchPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 upperMask[],
   float32 signalPower[],
   float32 lowerMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxGSM_PVTFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxGSM_PVTFetchSlotMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* slotAveragePower,
   float64* slotBurstWidth,
   int32* slotMeasurementStatus,
   float64* slotMaximumPower,
   float64* slotMinimumPower,
   float64* slotBurstThreshold
);

int32 __stdcall RFmxGSM_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetDroopCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetDroopCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVM95thpercentileEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMPeakEVMSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanAmplitudeDroop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumAmplitudeDroop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFERMeanRMSPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFERMaximumRMSPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFERMeanPeakPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFERMaximumPeakPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFERPeakPhaseErrorSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFERMeanFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFERMaximumFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsMeanIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsMaximumIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsMeanIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsMaximumIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsDetectedTSC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanPeakMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumPeakMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVM95thPercentileMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMeanPeakPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVMMaximumPeakPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsEVM95thPercentilePhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ModAccGetResultsPFER95thPercentilePhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ORFSGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetMeasurementType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetMeasurementType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetOffsetFrequencyMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetOffsetFrequencyMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetEvaluationSymbolsStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetEvaluationSymbolsStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetEvaluationSymbolsIncludeTSC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetEvaluationSymbolsIncludeTSC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetEvaluationSymbolsStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetEvaluationSymbolsStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetEvaluationSymbolsScope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetEvaluationSymbolsScope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetModulationCarrierRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetModulationCarrierRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetModulationNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetModulationNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetModulationOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetModulationOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetModulationOffsetRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ORFSGetSwitchingCarrierRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetSwitchingCarrierRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetSwitchingNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetSwitchingNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetSwitchingOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetSwitchingOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetSwitchingOffsetRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_ORFSGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_ORFSGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_ORFSSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_PVTGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_PVTSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_PVTGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_PVTSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_PVTGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_PVTSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_PVTGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_PVTSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_PVTGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_PVTSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_PVTGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_PVTSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_PVTGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_PVTSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_PVTGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_PVTGetResultsSlotAveragePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_PVTGetResultsSlotBurstWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_PVTGetResultsSlotMaximumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_PVTGetResultsSlotMinimumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_PVTGetResultsSlotBurstThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_PVTGetResultsSlotMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetSignalStructure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetSignalStructure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetNumberOfTimeslots(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetNumberOfTimeslots(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetBurstType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetBurstType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetHBFilterWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetHBFilterWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetAutoTSCDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetAutoTSCDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetTSC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetTSC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetPowerControlLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetPowerControlLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetTimingAdvance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetTimingAdvance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxGSM_SetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxGSM_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxGSM_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxGSM_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxGSM_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxGSM_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

// Values for RFMXGSM_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXGSM_VAL_MINIMUM_QUIET_TIME_MODE_AUTO                                                   0
#define RFMXGSM_VAL_MINIMUM_QUIET_TIME_MODE_MANUAL                                                 1

// Values for RFMXGSM_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXGSM_VAL_IQ_POWER_EDGE_LEVEL_TYPE_RELATIVE                                              0
#define RFMXGSM_VAL_IQ_POWER_EDGE_LEVEL_TYPE_ABSOLUTE                                              1

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxGSM_CalculateFrequencyFromARFCN(
   int32 linkDirection,
   int32 band,
   int32 ARFCN,
   float64 *centerFrequency
);

int32 __stdcall RFmxGSM_AnalyzeIQ(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   NIComplexSingle IQ[],
   int32 arraySize,
   int32 reset,
   int32* averagingDone
);

int32 __stdcall RFmxGSM_AnalyzeIQSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32 reset,
   int32* averagingDone
);

#ifdef __cplusplus
}
#endif


#endif

