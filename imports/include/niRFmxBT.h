
/****************************************************************************************************
*          National Instruments RFmx BT
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2024.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxBT.h
*
* Purpose:  National Instruments RFmx BT,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_BT_H__
#define __NI_RFMX_BT_H__

#include "niRFmxInstr.h"

#define RFMXBT_ATTR_SELECTED_PORTS                                                                 0x00b00ffd
#define RFMXBT_ATTR_CENTER_FREQUENCY                                                               0x00b00001
#define RFMXBT_ATTR_REFERENCE_LEVEL                                                                0x00b00002
#define RFMXBT_ATTR_EXTERNAL_ATTENUATION                                                           0x00b00003
#define RFMXBT_ATTR_REFERENCE_LEVEL_HEADROOM                                                       0x00b00ffc
#define RFMXBT_ATTR_TRIGGER_TYPE                                                                   0x00b00004
#define RFMXBT_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                                    0x00b00005
#define RFMXBT_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                                      0x00b00006
#define RFMXBT_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                                   0x00b00007
#define RFMXBT_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                                    0x00b00008
#define RFMXBT_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                                               0x00b00fff
#define RFMXBT_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                                    0x00b00009
#define RFMXBT_ATTR_TRIGGER_DELAY                                                                  0x00b0000a
#define RFMXBT_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                                0x00b0000b
#define RFMXBT_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                                            0x00b0000c
#define RFMXBT_ATTR_PACKET_TYPE                                                                    0x00b0000d
#define RFMXBT_ATTR_DATA_RATE                                                                      0x00b0000e
#define RFMXBT_ATTR_BANDWIDTH_BIT_PERIOD_PRODUCT                                                   0x00b00034
#define RFMXBT_ATTR_BD_ADDRESS_LAP                                                                 0x00b0000f
#define RFMXBT_ATTR_ACCESS_ADDRESS                                                                 0x00b00011
#define RFMXBT_ATTR_PAYLOAD_BIT_PATTERN                                                            0x00b00012
#define RFMXBT_ATTR_PAYLOAD_LENGTH_MODE                                                            0x00b00013
#define RFMXBT_ATTR_PAYLOAD_LENGTH                                                                 0x00b00014
#define RFMXBT_ATTR_DIRECTION_FINDING_MODE                                                         0x00b0002c
#define RFMXBT_ATTR_CTE_LENGTH                                                                     0x00b0002d
#define RFMXBT_ATTR_CTE_SLOT_DURATION                                                              0x00b0002e
#define RFMXBT_ATTR_CTE_NUMBER_OF_TRANSMIT_SLOTS                                                   0x00b0002f
#define RFMXBT_ATTR_CHANNEL_SOUNDING_PACKET_FORMAT                                                 0x00b00030
#define RFMXBT_ATTR_CHANNEL_SOUNDING_SYNC_SEQUENCE                                                 0x00b00031
#define RFMXBT_ATTR_CHANNEL_SOUNDING_PHASE_MEASUREMENT_PERIOD                                      0x00b00032
#define RFMXBT_ATTR_CHANNEL_SOUNDING_TONE_EXTENSION_SLOT                                           0x00b00033
#define RFMXBT_ATTR_CHANNEL_SOUNDING_NUMBER_OF_ANTENNA_PATH                                        0x00b00036
#define RFMXBT_ATTR_CHANNEL_SOUNDING_ANTENNA_SWITCH_TIME                                           0x00b00035
#define RFMXBT_ATTR_ZADOFF_CHU_INDEX                                                               0x00b00039
#define RFMXBT_ATTR_HIGH_DATA_THROUGHPUT_PACKET_FORMAT                                             0x00b00038
#define RFMXBT_ATTR_VHDT_MODE_ENABLED                                                              0x00b00040
#define RFMXBT_ATTR_CHANNEL_NUMBER                                                                 0x00b00017
#define RFMXBT_ATTR_DETECTED_PACKET_TYPE                                                           0x00b00019
#define RFMXBT_ATTR_DETECTED_DATA_RATE                                                             0x00b0002a
#define RFMXBT_ATTR_DETECTED_PAYLOAD_LENGTH                                                        0x00b0002b
#define RFMXBT_ATTR_MODACC_MEASUREMENT_ENABLED                                                     0x00b04000
#define RFMXBT_ATTR_MODACC_BURST_SYNCHRONIZATION_TYPE                                              0x00b0402b
#define RFMXBT_ATTR_MODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED                                     0x00b04003
#define RFMXBT_ATTR_MODACC_AVERAGING_ENABLED                                                       0x00b04004
#define RFMXBT_ATTR_MODACC_AVERAGING_COUNT                                                         0x00b04005
#define RFMXBT_ATTR_MODACC_ALL_TRACES_ENABLED                                                      0x00b04006
#define RFMXBT_ATTR_MODACC_NUMBER_OF_ANALYSIS_THREADS                                              0x00b04007
#define RFMXBT_ATTR_MODACC_RESULTS_DF1AVG_MEAN                                                     0x00b04009
#define RFMXBT_ATTR_MODACC_RESULTS_DF1AVG_MAXIMUM                                                  0x00b0400a
#define RFMXBT_ATTR_MODACC_RESULTS_DF1AVG_MINIMUM                                                  0x00b0400b
#define RFMXBT_ATTR_MODACC_RESULTS_PEAK_DF1MAX_MAXIMUM                                             0x00b0400c
#define RFMXBT_ATTR_MODACC_RESULTS_MINIMUM_DF1MAX_MINIMUM                                          0x00b0400d
#define RFMXBT_ATTR_MODACC_RESULTS_PERCENTAGE_OF_SYMBOLS_ABOVE_DF1MAX_THRESHOLD                    0x00b0402c
#define RFMXBT_ATTR_MODACC_RESULTS_DF2AVG_MEAN                                                     0x00b0400e
#define RFMXBT_ATTR_MODACC_RESULTS_DF2AVG_MAXIMUM                                                  0x00b0400f
#define RFMXBT_ATTR_MODACC_RESULTS_DF2AVG_MINIMUM                                                  0x00b04010
#define RFMXBT_ATTR_MODACC_RESULTS_PEAK_DF2MAX_MAXIMUM                                             0x00b04011
#define RFMXBT_ATTR_MODACC_RESULTS_MINIMUM_DF2MAX_MINIMUM                                          0x00b04012
#define RFMXBT_ATTR_MODACC_RESULTS_PERCENTAGE_OF_SYMBOLS_ABOVE_DF2MAX_THRESHOLD                    0x00b04013
#define RFMXBT_ATTR_MODACC_RESULTS_DF3AVG_MEAN                                                     0x00b04034
#define RFMXBT_ATTR_MODACC_RESULTS_PERCENTAGE_OF_SYMBOLS_ABOVE_DF4AVG_THRESHOLD                    0x00b04035
#define RFMXBT_ATTR_MODACC_RESULTS_BR_INITIAL_FREQUENCY_ERROR_MAXIMUM                              0x00b04014
#define RFMXBT_ATTR_MODACC_RESULTS_BR_PEAK_FREQUENCY_DRIFT_MAXIMUM                                 0x00b04015
#define RFMXBT_ATTR_MODACC_RESULTS_BR_PEAK_FREQUENCY_DRIFT_RATE_MAXIMUM                            0x00b04016
#define RFMXBT_ATTR_MODACC_RESULTS_EDR_HEADER_FREQUENCY_ERROR_WI_MAXIMUM                           0x00b04017
#define RFMXBT_ATTR_MODACC_RESULTS_EDR_PEAK_FREQUENCY_ERROR_WI_PLUS_W0_MAXIMUM                     0x00b04018
#define RFMXBT_ATTR_MODACC_RESULTS_EDR_PEAK_FREQUENCY_ERROR_W0_MAXIMUM                             0x00b04019
#define RFMXBT_ATTR_MODACC_RESULTS_LE_INITIAL_FREQUENCY_ERROR_MAXIMUM                              0x00b04031
#define RFMXBT_ATTR_MODACC_RESULTS_LE_PEAK_FREQUENCY_ERROR_MAXIMUM                                 0x00b0401a
#define RFMXBT_ATTR_MODACC_RESULTS_LE_INITIAL_FREQUENCY_DRIFT_MAXIMUM                              0x00b0401b
#define RFMXBT_ATTR_MODACC_RESULTS_LE_PEAK_FREQUENCY_DRIFT_MAXIMUM                                 0x00b0401c
#define RFMXBT_ATTR_MODACC_RESULTS_LE_PEAK_FREQUENCY_DRIFT_RATE_MAXIMUM                            0x00b0401d
#define RFMXBT_ATTR_MODACC_RESULTS_PEAK_RMS_DEVM_MAXIMUM                                           0x00b0401e
#define RFMXBT_ATTR_MODACC_RESULTS_RMS_DEVM_MEAN                                                   0x00b0401f
#define RFMXBT_ATTR_MODACC_RESULTS_PEAK_DEVM_MAXIMUM                                               0x00b04020
#define RFMXBT_ATTR_MODACC_RESULTS_99_PERCENT_DEVM                                                 0x00b04021
#define RFMXBT_ATTR_MODACC_RESULTS_PERCENTAGE_OF_SYMBOLS_BELOW_99_PERCENT_DEVM_LIMIT               0x00b04022
#define RFMXBT_ATTR_MODACC_RESULTS_AVERAGE_RMS_MAGNITUDE_ERROR_MEAN                                0x00b0402d
#define RFMXBT_ATTR_MODACC_RESULTS_PEAK_RMS_MAGNITUDE_ERROR_MAXIMUM                                0x00b0402e
#define RFMXBT_ATTR_MODACC_RESULTS_AVERAGE_RMS_PHASE_ERROR_MEAN                                    0x00b0402f
#define RFMXBT_ATTR_MODACC_RESULTS_PEAK_RMS_PHASE_ERROR_MAXIMUM                                    0x00b04030
#define RFMXBT_ATTR_MODACC_RESULTS_PREAMBLE_RMS_EVM_MEAN                                           0x00b04036
#define RFMXBT_ATTR_MODACC_RESULTS_CONTROL_HEADER_RMS_EVM_MEAN                                     0x00b04037
#define RFMXBT_ATTR_MODACC_RESULTS_PAYLOAD_RMS_EVM_MEAN                                            0x00b04038
#define RFMXBT_ATTR_MODACC_RESULTS_IQ_ORIGIN_OFFSET_MEAN                                           0x00b04023
#define RFMXBT_ATTR_MODACC_RESULTS_CLOCK_DRIFT_MEAN                                                0x00b04032
#define RFMXBT_ATTR_MODACC_RESULTS_PREAMBLE_START_TIME_MEAN                                        0x00b04033
#define RFMXBT_ATTR_MODACC_RESULTS_FRACTIONAL_TIME_OFFSET_MEAN                                     0x00b04039
#define RFMXBT_ATTR_ACP_MEASUREMENT_ENABLED                                                        0x00b05000
#define RFMXBT_ATTR_ACP_OFFSET_CHANNEL_MODE                                                        0x00b05002
#define RFMXBT_ATTR_ACP_NUMBER_OF_OFFSETS                                                          0x00b05003
#define RFMXBT_ATTR_ACP_OFFSET_FREQUENCY                                                           0x00b05004
#define RFMXBT_ATTR_ACP_REFERENCE_CHANNEL_BANDWIDTH_MODE                                           0x00b05016
#define RFMXBT_ATTR_ACP_REFERENCE_CHANNEL_BANDWIDTH                                                0x00b05015
#define RFMXBT_ATTR_ACP_BURST_SYNCHRONIZATION_TYPE                                                 0x00b05012
#define RFMXBT_ATTR_ACP_AVERAGING_ENABLED                                                          0x00b05005
#define RFMXBT_ATTR_ACP_AVERAGING_COUNT                                                            0x00b05006
#define RFMXBT_ATTR_ACP_ALL_TRACES_ENABLED                                                         0x00b05007
#define RFMXBT_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                                                 0x00b05008
#define RFMXBT_ATTR_ACP_RESULTS_MEASUREMENT_STATUS                                                 0x00b0500a
#define RFMXBT_ATTR_ACP_RESULTS_REFERENCE_CHANNEL_POWER                                            0x00b0500b
#define RFMXBT_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                                        0x00b0500c
#define RFMXBT_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                                        0x00b0500d
#define RFMXBT_ATTR_ACP_RESULTS_LOWER_OFFSET_MARGIN                                                0x00b0500e
#define RFMXBT_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                                        0x00b0500f
#define RFMXBT_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                                        0x00b05010
#define RFMXBT_ATTR_ACP_RESULTS_UPPER_OFFSET_MARGIN                                                0x00b05011
#define RFMXBT_ATTR_20DB_BANDWIDTH_MEASUREMENT_ENABLED                                             0x00b02000
#define RFMXBT_ATTR_20DB_BANDWIDTH_AVERAGING_ENABLED                                               0x00b02002
#define RFMXBT_ATTR_20DB_BANDWIDTH_AVERAGING_COUNT                                                 0x00b02003
#define RFMXBT_ATTR_20DB_BANDWIDTH_ALL_TRACES_ENABLED                                              0x00b02004
#define RFMXBT_ATTR_20DB_BANDWIDTH_NUMBER_OF_ANALYSIS_THREADS                                      0x00b02005
#define RFMXBT_ATTR_20DB_BANDWIDTH_RESULTS_PEAK_POWER                                              0x00b02007
#define RFMXBT_ATTR_20DB_BANDWIDTH_RESULTS_BANDWIDTH                                               0x00b02008
#define RFMXBT_ATTR_20DB_BANDWIDTH_RESULTS_HIGH_FREQUENCY                                          0x00b02009
#define RFMXBT_ATTR_20DB_BANDWIDTH_RESULTS_LOW_FREQUENCY                                           0x00b0200a
#define RFMXBT_ATTR_FREQUENCY_RANGE_MEASUREMENT_ENABLED                                            0x00b03000
#define RFMXBT_ATTR_FREQUENCY_RANGE_SPAN                                                           0x00b03002
#define RFMXBT_ATTR_FREQUENCY_RANGE_AVERAGING_ENABLED                                              0x00b03003
#define RFMXBT_ATTR_FREQUENCY_RANGE_AVERAGING_COUNT                                                0x00b03004
#define RFMXBT_ATTR_FREQUENCY_RANGE_ALL_TRACES_ENABLED                                             0x00b03005
#define RFMXBT_ATTR_FREQUENCY_RANGE_NUMBER_OF_ANALYSIS_THREADS                                     0x00b03006
#define RFMXBT_ATTR_FREQUENCY_RANGE_RESULTS_HIGH_FREQUENCY                                         0x00b03008
#define RFMXBT_ATTR_FREQUENCY_RANGE_RESULTS_LOW_FREQUENCY                                          0x00b03009
#define RFMXBT_ATTR_MODSPECTRUM_MEASUREMENT_ENABLED                                                0x00b0f000
#define RFMXBT_ATTR_MODSPECTRUM_BURST_SYNCHRONIZATION_TYPE                                         0x00b0f002
#define RFMXBT_ATTR_MODSPECTRUM_AVERAGING_ENABLED                                                  0x00b0f003
#define RFMXBT_ATTR_MODSPECTRUM_AVERAGING_COUNT                                                    0x00b0f004
#define RFMXBT_ATTR_MODSPECTRUM_ALL_TRACES_ENABLED                                                 0x00b0f005
#define RFMXBT_ATTR_MODSPECTRUM_NUMBER_OF_ANALYSIS_THREADS                                         0x00b0f006
#define RFMXBT_ATTR_MODSPECTRUM_RESULTS_BANDWIDTH                                                  0x00b0f008
#define RFMXBT_ATTR_MODSPECTRUM_RESULTS_HIGH_FREQUENCY                                             0x00b0f009
#define RFMXBT_ATTR_MODSPECTRUM_RESULTS_LOW_FREQUENCY                                              0x00b0f00a
#define RFMXBT_ATTR_TXP_MEASUREMENT_ENABLED                                                        0x00b01000
#define RFMXBT_ATTR_TXP_BURST_SYNCHRONIZATION_TYPE                                                 0x00b01010
#define RFMXBT_ATTR_TXP_AVERAGING_ENABLED                                                          0x00b01002
#define RFMXBT_ATTR_TXP_AVERAGING_COUNT                                                            0x00b01003
#define RFMXBT_ATTR_TXP_ALL_TRACES_ENABLED                                                         0x00b01004
#define RFMXBT_ATTR_TXP_NUMBER_OF_ANALYSIS_THREADS                                                 0x00b01005
#define RFMXBT_ATTR_TXP_RESULTS_AVERAGE_POWER_MEAN                                                 0x00b01007
#define RFMXBT_ATTR_TXP_RESULTS_AVERAGE_POWER_MAXIMUM                                              0x00b01008
#define RFMXBT_ATTR_TXP_RESULTS_AVERAGE_POWER_MINIMUM                                              0x00b01009
#define RFMXBT_ATTR_TXP_RESULTS_PEAK_POWER_MAXIMUM                                                 0x00b0100a
#define RFMXBT_ATTR_TXP_RESULTS_PEAK_TO_AVERAGE_POWER_RATIO_MAXIMUM                                0x00b0100b
#define RFMXBT_ATTR_TXP_RESULTS_EDR_GFSK_AVERAGE_POWER_MEAN                                        0x00b0100c
#define RFMXBT_ATTR_TXP_RESULTS_EDR_DPSK_AVERAGE_POWER_MEAN                                        0x00b0100d
#define RFMXBT_ATTR_TXP_RESULTS_EDR_DPSK_GFSK_AVERAGE_POWER_RATIO_MEAN                             0x00b01013
#define RFMXBT_ATTR_TXP_RESULTS_LE_CTE_REFERENCE_PERIOD_AVERAGE_POWER_MEAN                         0x00b01014
#define RFMXBT_ATTR_TXP_RESULTS_LE_CTE_REFERENCE_PERIOD_PEAK_ABSOLUTE_POWER_DEVIATION_MAXIMUM      0x00b01015
#define RFMXBT_ATTR_TXP_RESULTS_LE_CTE_TRANSMIT_SLOT_AVERAGE_POWER_MEAN                            0x00b01016
#define RFMXBT_ATTR_TXP_RESULTS_LE_CTE_TRANSMIT_SLOT_PEAK_ABSOLUTE_POWER_DEVIATION_MAXIMUM         0x00b01017
#define RFMXBT_ATTR_TXP_RESULTS_LE_CS_PHASE_MEASUREMENT_PERIOD_AVERAGE_POWER_MEAN                  0x00b01018
#define RFMXBT_ATTR_POWERRAMP_MEASUREMENT_ENABLED                                                  0x00b0e000
#define RFMXBT_ATTR_POWERRAMP_BURST_SYNCHRONIZATION_TYPE                                           0x00b0e002
#define RFMXBT_ATTR_POWERRAMP_AVERAGING_ENABLED                                                    0x00b0e005
#define RFMXBT_ATTR_POWERRAMP_AVERAGING_COUNT                                                      0x00b0e006
#define RFMXBT_ATTR_POWERRAMP_NUMBER_OF_ANALYSIS_THREADS                                           0x00b0e007
#define RFMXBT_ATTR_POWERRAMP_RESULTS_RISE_TIME_MEAN                                               0x00b0e009
#define RFMXBT_ATTR_POWERRAMP_RESULTS_FALL_TIME_MEAN                                               0x00b0e00a
#define RFMXBT_ATTR_POWERRAMP_RESULTS_40DB_FALL_TIME_MEAN                                          0x00b0e00b
#define RFMXBT_ATTR_LIMITED_CONFIGURATION_CHANGE                                                   0x00b0d000
#define RFMXBT_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                                             0x00b0d001
#define RFMXBT_ATTR_RESULT_FETCH_TIMEOUT                                                           0x00b0c000

// Values for RFMXBT_ATTR_TRIGGER_TYPE
#define RFMXBT_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXBT_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXBT_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXBT_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXBT_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXBT_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXBT_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXBT_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXBT_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXBT_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXBT_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXBT_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXBT_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXBT_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXBT_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXBT_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXBT_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXBT_VAL_TIMER_EVENT_STR                                                                "TimerEvent"
#define RFMXBT_VAL_PULSE_IN_STR                                                                   "PulseIn"
#define RFMXBT_VAL_DIO_PFI0_STR                                                                   "DIO/PFI0"
#define RFMXBT_VAL_DIO_PFI1_STR                                                                   "DIO/PFI1"
#define RFMXBT_VAL_DIO_PFI2_STR                                                                   "DIO/PFI2"
#define RFMXBT_VAL_DIO_PFI3_STR                                                                   "DIO/PFI3"
#define RFMXBT_VAL_DIO_PFI4_STR                                                                   "DIO/PFI4"
#define RFMXBT_VAL_DIO_PFI5_STR                                                                   "DIO/PFI5"
#define RFMXBT_VAL_DIO_PFI6_STR                                                                   "DIO/PFI6"
#define RFMXBT_VAL_DIO_PFI7_STR                                                                   "DIO/PFI7"

// Values for RFMXBT_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXBT_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXBT_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXBT_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXBT_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXBT_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXBT_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXBT_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXBT_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXBT_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXBT_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXBT_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXBT_ATTR_PACKET_TYPE
#define RFMXBT_VAL_PACKET_TYPE_UNKNOWN                                                            -1
#define RFMXBT_VAL_PACKET_TYPE_DH1                                                                0
#define RFMXBT_VAL_PACKET_TYPE_DH3                                                                1
#define RFMXBT_VAL_PACKET_TYPE_DH5                                                                2
#define RFMXBT_VAL_PACKET_TYPE_DM1                                                                3
#define RFMXBT_VAL_PACKET_TYPE_DM3                                                                4
#define RFMXBT_VAL_PACKET_TYPE_DM5                                                                5
#define RFMXBT_VAL_PACKET_TYPE_2_DH1                                                              6
#define RFMXBT_VAL_PACKET_TYPE_2_DH3                                                              7
#define RFMXBT_VAL_PACKET_TYPE_2_DH5                                                              8
#define RFMXBT_VAL_PACKET_TYPE_3_DH1                                                              9
#define RFMXBT_VAL_PACKET_TYPE_3_DH3                                                              10
#define RFMXBT_VAL_PACKET_TYPE_3_DH5                                                              11
#define RFMXBT_VAL_PACKET_TYPE_2_EV3                                                              12
#define RFMXBT_VAL_PACKET_TYPE_2_EV5                                                              13
#define RFMXBT_VAL_PACKET_TYPE_3_EV3                                                              14
#define RFMXBT_VAL_PACKET_TYPE_3_EV5                                                              15
#define RFMXBT_VAL_PACKET_TYPE_LE                                                                 16
#define RFMXBT_VAL_PACKET_TYPE_LE_CS                                                              17
#define RFMXBT_VAL_PACKET_TYPE_LE_HDT                                                             18

// Values for RFMXBT_ATTR_PAYLOAD_BIT_PATTERN
#define RFMXBT_VAL_PAYLOAD_BIT_PATTERN_STANDARD_DEFINED                                           0
#define RFMXBT_VAL_PAYLOAD_BIT_PATTERN_11110000                                                   1
#define RFMXBT_VAL_PAYLOAD_BIT_PATTERN_10101010                                                   2

// Values for RFMXBT_ATTR_PAYLOAD_LENGTH_MODE
#define RFMXBT_VAL_PAYLOAD_LENGTH_MODE_MANUAL                                                     0
#define RFMXBT_VAL_PAYLOAD_LENGTH_MODE_AUTO                                                       1

// Values for RFMXBT_ATTR_DIRECTION_FINDING_MODE
#define RFMXBT_VAL_DIRECTION_FINDING_MODE_DISABLED                                                0
#define RFMXBT_VAL_DIRECTION_FINDING_MODE_ANGLE_OF_ARRIVAL                                        1
#define RFMXBT_VAL_DIRECTION_FINDING_MODE_ANGLE_OF_DEPARTURE                                      2

// Values for RFMXBT_ATTR_CHANNEL_SOUNDING_PACKET_FORMAT
#define RFMXBT_VAL_CHANNEL_SOUNDING_PACKET_FORMAT_SYNC                                            0
#define RFMXBT_VAL_CHANNEL_SOUNDING_PACKET_FORMAT_CS_TONE                                         1
#define RFMXBT_VAL_CHANNEL_SOUNDING_PACKET_FORMAT_CS_TONE_AFTER_SYNC                              2
#define RFMXBT_VAL_CHANNEL_SOUNDING_PACKET_FORMAT_CS_TONE_BEFORE_SYNC                             3

// Values for RFMXBT_ATTR_CHANNEL_SOUNDING_SYNC_SEQUENCE
#define RFMXBT_VAL_CHANNEL_SOUNDING_SYNC_SEQUENCE_NONE                                            0
#define RFMXBT_VAL_CHANNEL_SOUNDING_SYNC_SEQUENCE_SOUNDING_SEQUENCE_32_BIT                        1
#define RFMXBT_VAL_CHANNEL_SOUNDING_SYNC_SEQUENCE_SOUNDING_SEQUENCE_96_BIT                        2
#define RFMXBT_VAL_CHANNEL_SOUNDING_SYNC_SEQUENCE_PAYLOAD_PATTERN                                 3

// Values for RFMXBT_ATTR_CHANNEL_SOUNDING_TONE_EXTENSION_SLOT
#define RFMXBT_VAL_CHANNEL_SOUNDING_TONE_EXTENSION_SLOT_DISABLED                                  0
#define RFMXBT_VAL_CHANNEL_SOUNDING_TONE_EXTENSION_SLOT_ENABLED                                   1

// Values for RFMXBT_ATTR_HIGH_DATA_THROUGHPUT_PACKET_FORMAT
#define RFMXBT_VAL_HIGH_DATA_THROUGHPUT_PACKET_FORMAT_SHORT_FORMAT                                0
#define RFMXBT_VAL_HIGH_DATA_THROUGHPUT_PACKET_FORMAT_FORMAT0                                     1
#define RFMXBT_VAL_HIGH_DATA_THROUGHPUT_PACKET_FORMAT_FORMAT1                                     2

// Values for RFMXBT_ATTR_VHDT_MODE_ENABLED
#define RFMXBT_VAL_VHDT_MODE_ENABLED_FALSE                                                        0
#define RFMXBT_VAL_VHDT_MODE_ENABLED_TRUE                                                         1

// Values for RFMXBT_ATTR_MODACC_BURST_SYNCHRONIZATION_TYPE
#define RFMXBT_VAL_MODACC_BURST_SYNCHRONIZATION_TYPE_NONE                                         0
#define RFMXBT_VAL_MODACC_BURST_SYNCHRONIZATION_TYPE_PREAMBLE                                     1
#define RFMXBT_VAL_MODACC_BURST_SYNCHRONIZATION_TYPE_SYNC_WORD                                    2

// Values for RFMXBT_ATTR_MODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED
#define RFMXBT_VAL_MODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_FALSE                               0
#define RFMXBT_VAL_MODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_TRUE                                1

// Values for RFMXBT_ATTR_MODACC_AVERAGING_ENABLED
#define RFMXBT_VAL_MODACC_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXBT_VAL_MODACC_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXBT_ATTR_ACP_OFFSET_CHANNEL_MODE
#define RFMXBT_VAL_ACP_OFFSET_CHANNEL_MODE_SYMMETRIC                                              0
#define RFMXBT_VAL_ACP_OFFSET_CHANNEL_MODE_INBAND                                                 1

// Values for RFMXBT_ATTR_ACP_REFERENCE_CHANNEL_BANDWIDTH_MODE
#define RFMXBT_VAL_ACP_REFERENCE_CHANNEL_BANDWIDTH_MODE_AUTO                                      0
#define RFMXBT_VAL_ACP_REFERENCE_CHANNEL_BANDWIDTH_MODE_MANUAL                                    1

// Values for RFMXBT_ATTR_ACP_BURST_SYNCHRONIZATION_TYPE
#define RFMXBT_VAL_ACP_BURST_SYNCHRONIZATION_TYPE_NONE                                            0
#define RFMXBT_VAL_ACP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE                                        1
#define RFMXBT_VAL_ACP_BURST_SYNCHRONIZATION_TYPE_SYNC_WORD                                       2

// Values for RFMXBT_ATTR_ACP_AVERAGING_ENABLED
#define RFMXBT_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXBT_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXBT_ATTR_ACP_RESULTS_MEASUREMENT_STATUS
#define RFMXBT_VAL_ACP_RESULTS_MEASUREMENT_STATUS_NOT_APPLICABLE                                  -1
#define RFMXBT_VAL_ACP_RESULTS_MEASUREMENT_STATUS_FAIL                                            0
#define RFMXBT_VAL_ACP_RESULTS_MEASUREMENT_STATUS_PASS                                            1

// Values for RFMXBT_ATTR_20DB_BANDWIDTH_AVERAGING_ENABLED
#define RFMXBT_VAL_20DB_BANDWIDTH_AVERAGING_ENABLED_FALSE                                         0
#define RFMXBT_VAL_20DB_BANDWIDTH_AVERAGING_ENABLED_TRUE                                          1

// Values for RFMXBT_ATTR_FREQUENCY_RANGE_AVERAGING_ENABLED
#define RFMXBT_VAL_FREQUENCY_RANGE_AVERAGING_ENABLED_FALSE                                        0
#define RFMXBT_VAL_FREQUENCY_RANGE_AVERAGING_ENABLED_TRUE                                         1

// Values for RFMXBT_ATTR_MODSPECTRUM_BURST_SYNCHRONIZATION_TYPE
#define RFMXBT_VAL_MODSPECTRUM_BURST_SYNCHRONIZATION_TYPE_NONE                                    0
#define RFMXBT_VAL_MODSPECTRUM_BURST_SYNCHRONIZATION_TYPE_PREAMBLE                                1
#define RFMXBT_VAL_MODSPECTRUM_BURST_SYNCHRONIZATION_TYPE_SYNC_WORD                               2

// Values for RFMXBT_ATTR_MODSPECTRUM_AVERAGING_ENABLED
#define RFMXBT_VAL_MODSPECTRUM_AVERAGING_ENABLED_FALSE                                            0
#define RFMXBT_VAL_MODSPECTRUM_AVERAGING_ENABLED_TRUE                                             1

// Values for RFMXBT_ATTR_TXP_BURST_SYNCHRONIZATION_TYPE
#define RFMXBT_VAL_TXP_BURST_SYNCHRONIZATION_TYPE_NONE                                            0
#define RFMXBT_VAL_TXP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE                                        1
#define RFMXBT_VAL_TXP_BURST_SYNCHRONIZATION_TYPE_SYNC_WORD                                       2

// Values for RFMXBT_ATTR_TXP_AVERAGING_ENABLED
#define RFMXBT_VAL_TXP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXBT_VAL_TXP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXBT_ATTR_POWERRAMP_BURST_SYNCHRONIZATION_TYPE
#define RFMXBT_VAL_POWERRAMP_BURST_SYNCHRONIZATION_TYPE_NONE                                      0
#define RFMXBT_VAL_POWERRAMP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE                                  1
#define RFMXBT_VAL_POWERRAMP_BURST_SYNCHRONIZATION_TYPE_SYNC_WORD                                 2

// Values for RFMXBT_ATTR_POWERRAMP_AVERAGING_ENABLED
#define RFMXBT_VAL_POWERRAMP_AVERAGING_ENABLED_FALSE                                              0
#define RFMXBT_VAL_POWERRAMP_AVERAGING_ENABLED_TRUE                                               1

// Values for RFMXBT_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXBT_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXBT_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXBT_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXBT_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXBT_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXBT_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Standard
#define RFMXBT_VAL_STANDARD_BR                                                                    0
#define RFMXBT_VAL_STANDARD_EDR                                                                   0
#define RFMXBT_VAL_STANDARD_LE                                                                    1

// Values for Boolean
#define RFMXBT_VAL_FALSE                                                                          0
#define RFMXBT_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXBT_VAL_TXP                                                                            1<<0
#define RFMXBT_VAL_MODACC                                                                         1<<1
#define RFMXBT_VAL_20DB_BANDWIDTH                                                                 1<<2
#define RFMXBT_VAL_FREQUENCY_RANGE                                                                1<<3
#define RFMXBT_VAL_ACP                                                                            1<<4
#define RFMXBT_VAL_POWERRAMP                                                                      1<<5
#define RFMXBT_VAL_MODSPECTRUM                                                                    1<<6

// Values for FrequencyReferenceSource
#define RFMXBT_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXBT_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXBT_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXBT_VAL_CLK_IN_STR                                                                     "ClkIn"

/* ---------------- RFmxBT APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxBT_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxBT_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxBT_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxBT_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxBT_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxBT_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxBT_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxBT_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxBT_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxBT_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxBT_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxBT_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxBT_BuildSlotString(
   char selectorString[],
   int32 slotNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxBT_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxBT_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxBT_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxBT_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxBT_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxBT_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxBT_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxBT_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxBT_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxBT_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxBT_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxBT_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxBT_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxBT_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxBT_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxBT_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxBT_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxBT_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxBT_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxBT_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxBT_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxBT_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxBT_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxBT_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxBT_AutoDetectSignal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxBT_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxBT_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxBT_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxBT_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxBT_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxBT_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxBT_CfgFrequencyChannelNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 standard,
   int32 channelNumber
);

int32 __stdcall RFmxBT_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxBT_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxBT_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxBT_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxBT_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxBT_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxBT_TXPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxBT_TXPCfgBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 burstSynchronizationType
);

int32 __stdcall RFmxBT_ModAccCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxBT_ModAccCfgBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 burstSynchronizationType
);

int32 __stdcall RFmxBT_20dBBandwidthCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxBT_FrequencyRangeCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxBT_FrequencyRangeCfgSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 span
);

int32 __stdcall RFmxBT_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxBT_ACPCfgBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 burstSynchronizationType
);

int32 __stdcall RFmxBT_ACPCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxBT_ACPCfgOffsetChannelMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetChannelMode
);

int32 __stdcall RFmxBT_PowerRampCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxBT_PowerRampCfgBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 burstSynchronizationType
);

int32 __stdcall RFmxBT_ModSpectrumCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxBT_ModSpectrumCfgBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 burstSynchronizationType
);

int32 __stdcall RFmxBT_CfgChannelNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelNumber
);

int32 __stdcall RFmxBT_CfgDataRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 dataRate
);

int32 __stdcall RFmxBT_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxBT_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxBT_CfgLEDirectionFinding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 directionFindingMode,
   float64 CTELength,
   float64 CTESlotDuration
);

int32 __stdcall RFmxBT_CfgPacketType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 packetType
);

int32 __stdcall RFmxBT_CfgPayloadBitPattern(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 payloadBitPattern
);

int32 __stdcall RFmxBT_CfgPayloadLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 payloadLengthMode,
   int32 payloadLength
);

int32 __stdcall RFmxBT_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxBT_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxBT_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxBT_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxBT_CfgIQPowerEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char IQPowerEdgeSource[],
   int32 IQPowerEdgeSlope,
   float64 IQPowerEdgeLevel,
   float64 triggerDelay,
   int32 triggerMinQuietTimeMode,
   float64 triggerMinQuietTimeDuration,
   int32 IQPowerEdgeLevelType,
   int32 enableTrigger
);

int32 __stdcall RFmxBT_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxBT_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxBT_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxBT_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxBT_TXPFetchLECTETransmitSlotPowersArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 transmitSlotAveragePowerMean[],
   float64 transmitSlotPeakAbsolutePowerDeviationMaximum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_TXPFetchPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 power[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_TXPFetchEDRPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* EDRGFSKAveragePowerMean,
   float64* EDRDPSKAveragePowerMean,
   float64* EDR_DPSK_GFSKAveragePowerRatioMean
);

int32 __stdcall RFmxBT_TXPFetchLECTEReferencePeriodPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* referencePeriodAveragePowerMean,
   float64* referencePeriodPeakAbsolutePowerDeviationMaximum
);

int32 __stdcall RFmxBT_TXPFetchLECTETransmitSlotPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* transmitSlotAveragePowerMean,
   float64* transmitSlotPeakAbsolutePowerDeviationMaximum
);

int32 __stdcall RFmxBT_TXPFetchPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averagePowerMean,
   float64* averagePowerMaximum,
   float64* averagePowerMinimum,
   float64* peakToAveragePowerRatioMaximum
);

int32 __stdcall RFmxBT_ModAccFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 constellationI[],
   float32 constellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchCSDetrendedPhaseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 CSDetrendedPhase[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchCSToneTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 CSToneAmplitude[],
   float32 CSTonePhase[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchDemodulatedBitTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int8 demodulatedBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchDEVMPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 DEVMPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchEVMPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 EVMPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchDf1maxTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 time[],
   float32 df1max[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchDf2maxTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 time[],
   float32 df2max[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchDf4avgTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 time[],
   float32 df4avg[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchFrequencyErrorTraceBR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 time[],
   float32 frequencyError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchFrequencyErrorTraceLE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 time[],
   float32 frequencyError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchFrequencyErrorWiPlusW0TraceEDR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 time[],
   float32 frequencyErrorWiPlusW0[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchFrequencyTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 frequency[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchRMSDEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 RMSDEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ModAccFetchDEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakRMSDEVMMaximum,
   float64* peakDEVMMaximum,
   float64* ninetyninePercentDEVM
);

int32 __stdcall RFmxBT_ModAccFetchDEVMMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageRMSMagnitudeErrorMean,
   float64* peakRMSMagnitudeErrorMaximum
);

int32 __stdcall RFmxBT_ModAccFetchDEVMPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageRMSPhaseErrorMean,
   float64* peakRMSPhaseErrorMaximum
);

int32 __stdcall RFmxBT_ModAccFetchDf1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* df1avgMaximum,
   float64* df1avgMinimum
);

int32 __stdcall RFmxBT_ModAccFetchDf2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* df2avgMinimum,
   float64* percentageOfSymbolsAboveDf2maxThreshold
);

int32 __stdcall RFmxBT_ModAccFetchFrequencyErrorBR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* initialFrequencyErrorMaximum,
   float64* peakFrequencyDriftMaximum,
   float64* peakFrequencyDriftRateMaximum
);

int32 __stdcall RFmxBT_ModAccFetchFrequencyErrorEDR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* headerFrequencyErrorWiMaximum,
   float64* peakFrequencyErrorWiPlusW0Maximum,
   float64* peakFrequencyErrorW0Maximum
);

int32 __stdcall RFmxBT_ModAccFetchFrequencyErrorLE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakFrequencyErrorMaximum,
   float64* initialFrequencyDriftMaximum,
   float64* peakFrequencyDriftMaximum,
   float64* peakFrequencyDriftRateMaximum
);

int32 __stdcall RFmxBT_20dBBandwidthFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_20dBBandwidthFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakPower,
   float64* bandwidth,
   float64* highFrequency,
   float64* lowFrequency
);

int32 __stdcall RFmxBT_FrequencyRangeFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_FrequencyRangeFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* highFrequency,
   float64* lowFrequency
);

int32 __stdcall RFmxBT_ACPFetchAbsolutePowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 absolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ACPFetchMaskTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 limitWithExceptionMask[],
   float32 limitWithoutExceptionMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ACPFetchOffsetMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 lowerAbsolutePower[],
   float64 upperAbsolutePower[],
   float64 lowerRelativePower[],
   float64 upperRelativePower[],
   float64 lowerMargin[],
   float64 upperMargin[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_ACPFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxBT_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerMargin,
   float64* upperMargin
);

int32 __stdcall RFmxBT_ACPFetchReferenceChannelPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* referenceChannelPower
);

int32 __stdcall RFmxBT_ModSpectrumFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxBT_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxBT_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxBT_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxBT_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxBT_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxBT_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxBT_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetPacketType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetPacketType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetDataRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetDataRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetBandwidthBitPeriodProduct(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetBandwidthBitPeriodProduct(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetBDAddressLAP(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetBDAddressLAP(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetAccessAddress(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetAccessAddress(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetPayloadBitPattern(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetPayloadBitPattern(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetPayloadLengthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetPayloadLengthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetPayloadLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetPayloadLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetDirectionFindingMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetDirectionFindingMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetCTELength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetCTELength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetCTESlotDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetCTESlotDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetCTENumberOfTransmitSlots(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_GetChannelSoundingPacketFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetChannelSoundingPacketFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetChannelSoundingSyncSequence(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetChannelSoundingSyncSequence(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetChannelSoundingPhaseMeasurementPeriod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetChannelSoundingPhaseMeasurementPeriod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetChannelSoundingToneExtensionSlot(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetChannelSoundingToneExtensionSlot(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetChannelSoundingNumberOfAntennaPath(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetChannelSoundingNumberOfAntennaPath(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetChannelSoundingAntennaSwitchTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetChannelSoundingAntennaSwitchTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetZadoffChuIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetZadoffChuIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetHighDataThroughputPacketFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetHighDataThroughputPacketFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetVHDTModeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetVHDTModeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetChannelNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetChannelNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetDetectedPacketType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_GetDetectedDataRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_GetDetectedPayloadLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModAccGetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModAccSetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModAccGetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModAccSetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModAccGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModAccSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsDf1avgMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsDf1avgMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsDf1avgMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPeakDf1maxMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsMinimumDf1maxMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPercentageOfSymbolsAboveDf1maxThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsDf2avgMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsDf2avgMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsDf2avgMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPeakDf2maxMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsMinimumDf2maxMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPercentageOfSymbolsAboveDf2maxThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsDf3avgMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPercentageOfSymbolsAboveDf4avgThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsBRInitialFrequencyErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsBRPeakFrequencyDriftMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsBRPeakFrequencyDriftRateMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsEDRHeaderFrequencyErrorWiMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsEDRPeakFrequencyErrorWiPlusW0Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsEDRPeakFrequencyErrorW0Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsLEInitialFrequencyErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsLEPeakFrequencyErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsLEInitialFrequencyDriftMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsLEPeakFrequencyDriftMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsLEPeakFrequencyDriftRateMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPeakRMSDEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsRMSDEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPeakDEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResults99PercentDEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPercentageOfSymbolsBelow99PercentDEVMLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsAverageRMSMagnitudeErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPeakRMSMagnitudeErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsAverageRMSPhaseErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPeakRMSPhaseErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPreambleRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsControlHeaderRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPayloadRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsIQOriginOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsClockDriftMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsPreambleStartTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModAccGetResultsFractionalTimeOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetOffsetChannelMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetOffsetChannelMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetReferenceChannelBandwidthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetReferenceChannelBandwidthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetReferenceChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPSetReferenceChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_ACPGetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsReferenceChannelPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ACPGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetResultsPeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetResultsBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetResultsHighFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_20dBBandwidthGetResultsLowFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeSetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetResultsHighFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_FrequencyRangeGetResultsLowFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumSetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetResultsBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetResultsHighFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_ModSpectrumGetResultsLowFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_TXPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_TXPGetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_TXPSetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_TXPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_TXPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_TXPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_TXPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_TXPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_TXPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_TXPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_TXPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsAveragePowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsAveragePowerMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsPeakToAveragePowerRatioMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsEDRGFSKAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsEDRDPSKAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsEDR_DPSK_GFSKAveragePowerRatioMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsLECTEReferencePeriodAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsLECTEReferencePeriodPeakAbsolutePowerDeviationMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsLECTETransmitSlotAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsLECTETransmitSlotPeakAbsolutePowerDeviationMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_TXPGetResultsLECSPhaseMeasurementPeriodAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_PowerRampGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_PowerRampSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_PowerRampGetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_PowerRampSetBurstSynchronizationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_PowerRampGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_PowerRampSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_PowerRampGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_PowerRampSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_PowerRampGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxBT_PowerRampSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxBT_PowerRampGetResultsRiseTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_PowerRampGetResultsFallTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxBT_PowerRampGetResults40dBFallTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

// Values for RFMXBT_ATTR_DIRECTION_FINDING_MODE
#define RFMXBT_VAL_DIRECTION_FINDING_MODE_ENABLED                                                 1

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxBT_CfgDirectionFinding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 directionFindingMode,
   float64 CTELength
);

int32 __stdcall RFmxBT_AnalyzeIQ(
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

int32 __stdcall RFmxBT_AnalyzeIQSplit(
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

