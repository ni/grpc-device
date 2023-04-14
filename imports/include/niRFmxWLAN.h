
/****************************************************************************************************
*          National Instruments RFmx WLAN
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxWLAN.h
*
* Purpose:  National Instruments RFmx WLAN,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_WLAN_H__
#define __NI_RFMX_WLAN_H__

#include "niRFmxInstr.h"

#define RFMXWLAN_ATTR_SELECTED_PORTS                                                    0x00a00ffd
#define RFMXWLAN_ATTR_CENTER_FREQUENCY                                                  0x00a00001
#define RFMXWLAN_ATTR_REFERENCE_LEVEL                                                   0x00a00002
#define RFMXWLAN_ATTR_EXTERNAL_ATTENUATION                                              0x00a00003
#define RFMXWLAN_ATTR_REFERENCE_LEVEL_HEADROOM                                          0x00a00ffc
#define RFMXWLAN_ATTR_TRIGGER_TYPE                                                      0x00a00004
#define RFMXWLAN_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                       0x00a00005
#define RFMXWLAN_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                         0x00a00006
#define RFMXWLAN_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                      0x00a00007
#define RFMXWLAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                       0x00a00008
#define RFMXWLAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                                  0x00a00fff
#define RFMXWLAN_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                       0x00a00009
#define RFMXWLAN_ATTR_TRIGGER_DELAY                                                     0x00a0000a
#define RFMXWLAN_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                   0x00a0000b
#define RFMXWLAN_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                               0x00a0000c
#define RFMXWLAN_ATTR_TRIGGER_GATE_ENABLED                                              0x00a0002a
#define RFMXWLAN_ATTR_TRIGGER_GATE_LENGTH                                               0x00a0002b
#define RFMXWLAN_ATTR_STANDARD                                                          0x00a0000d
#define RFMXWLAN_ATTR_CHANNEL_BANDWIDTH                                                 0x00a0000e
#define RFMXWLAN_ATTR_NUMBER_OF_FREQUENCY_SEGMENTS                                      0x00a0000f
#define RFMXWLAN_ATTR_NUMBER_OF_RECEIVE_CHAINS                                          0x00a00010
#define RFMXWLAN_ATTR_OFDM_FREQUENCY_SEGMENT_INDEX                                      0x00a00014
#define RFMXWLAN_ATTR_OFDM_TRANSMIT_POWER_CLASS                                         0x00a00015
#define RFMXWLAN_ATTR_OFDM_FREQUENCY_BAND                                               0x00a00016
#define RFMXWLAN_ATTR_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED                             0x00a00027
#define RFMXWLAN_ATTR_OFDM_PPDU_TYPE                                                    0x00a00017
#define RFMXWLAN_ATTR_OFDM_HEADER_DECODING_ENABLED                                      0x00a00028
#define RFMXWLAN_ATTR_OFDM_EHT_SIG_COMPRESSION_ENABLED                                  0x00a0003a
#define RFMXWLAN_ATTR_OFDM_NUMBER_OF_USERS                                              0x00a00018
#define RFMXWLAN_ATTR_OFDM_MCS_INDEX                                                    0x00a00019
#define RFMXWLAN_ATTR_OFDM_FEC_CODING_TYPE                                              0x00a00032
#define RFMXWLAN_ATTR_OFDM_RU_SIZE                                                      0x00a0001a
#define RFMXWLAN_ATTR_OFDM_RU_OFFSET_MRU_INDEX                                          0x00a0001b
#define RFMXWLAN_ATTR_OFDM_GUARD_INTERVAL_TYPE                                          0x00a0001c
#define RFMXWLAN_ATTR_OFDM_LTF_SIZE                                                     0x00a0001d
#define RFMXWLAN_ATTR_OFDM_PRE_FEC_PADDING_FACTOR                                       0x00a00033
#define RFMXWLAN_ATTR_OFDM_LDPC_EXTRA_SYMBOL_SEGMENT                                    0x00a00034
#define RFMXWLAN_ATTR_OFDM_PE_DISAMBIGUITY                                              0x00a00031
#define RFMXWLAN_ATTR_OFDM_STBC_ENABLED                                                 0x00a00035
#define RFMXWLAN_ATTR_OFDM_NUMBER_OF_SPACE_TIME_STREAMS                                 0x00a0001e
#define RFMXWLAN_ATTR_OFDM_SPACE_TIME_STREAM_OFFSET                                     0x00a0001f
#define RFMXWLAN_ATTR_OFDM_NUMBER_OF_HE_SIG_B_SYMBOLS                                   0x00a00020
#define RFMXWLAN_ATTR_OFDM_NUMBER_OF_EHT_SIG_SYMBOLS                                    0x00a0003b
#define RFMXWLAN_ATTR_OFDM_DCM_ENABLED                                                  0x00a00021
#define RFMXWLAN_ATTR_OFDM_NUMBER_OF_LTF_SYMBOLS                                        0x00a00022
#define RFMXWLAN_ATTR_OFDM_MU_MIMO_LTF_MODE_ENABLED                                     0x00a00029
#define RFMXWLAN_ATTR_OFDM_PREAMBLE_PUNCTURING_ENABLED                                  0x00a0002f
#define RFMXWLAN_ATTR_OFDM_PREAMBLE_PUNCTURING_BITMAP                                   0x00a00030
#define RFMXWLAN_ATTR_OFDM_AUTO_PHASE_ROTATION_DETECTION_ENABLED                        0x00a0003c
#define RFMXWLAN_ATTR_OFDM_PHASE_ROTATION_COEFFICIENT_1                                 0x00a00037
#define RFMXWLAN_ATTR_OFDM_PHASE_ROTATION_COEFFICIENT_2                                 0x00a00038
#define RFMXWLAN_ATTR_OFDM_PHASE_ROTATION_COEFFICIENT_3                                 0x00a00039
#define RFMXWLAN_ATTR_AUTO_DETECT_SIGNAL_DETECTED_STANDARD                              0x00a00011
#define RFMXWLAN_ATTR_AUTO_DETECT_SIGNAL_DETECTED_CHANNEL_BANDWIDTH                     0x00a00012
#define RFMXWLAN_ATTR_AUTO_DETECT_SIGNAL_DETECTED_BURST_LENGTH                          0x00a00013
#define RFMXWLAN_ATTR_DSSSMODACC_MEASUREMENT_ENABLED                                    0x00a0300a
#define RFMXWLAN_ATTR_DSSSMODACC_ACQUISITION_LENGTH_MODE                                0x00a0300b
#define RFMXWLAN_ATTR_DSSSMODACC_ACQUISITION_LENGTH                                     0x00a0300c
#define RFMXWLAN_ATTR_DSSSMODACC_MEASUREMENT_OFFSET                                     0x00a0300d
#define RFMXWLAN_ATTR_DSSSMODACC_MAXIMUM_MEASUREMENT_LENGTH                             0x00a0300e
#define RFMXWLAN_ATTR_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE                              0x00a0300f
#define RFMXWLAN_ATTR_DSSSMODACC_PULSE_SHAPING_FILTER_PARAMETER                         0x00a03010
#define RFMXWLAN_ATTR_DSSSMODACC_EQUALIZATION_ENABLED                                   0x00a03011
#define RFMXWLAN_ATTR_DSSSMODACC_BURST_START_DETECTION_ENABLED                          0x00a0307a
#define RFMXWLAN_ATTR_DSSSMODACC_EVM_UNIT                                               0x00a03012
#define RFMXWLAN_ATTR_DSSSMODACC_POWER_MEASUREMENT_ENABLED                              0x00a03013
#define RFMXWLAN_ATTR_DSSSMODACC_POWER_NUMBER_OF_CUSTOM_GATES                           0x00a03014
#define RFMXWLAN_ATTR_DSSSMODACC_POWER_CUSTOM_GATE_START_TIME                           0x00a03015
#define RFMXWLAN_ATTR_DSSSMODACC_POWER_CUSTOM_GATE_STOP_TIME                            0x00a03016
#define RFMXWLAN_ATTR_DSSSMODACC_FREQUENCY_ERROR_CORRECTION_ENABLED                     0x00a0302c
#define RFMXWLAN_ATTR_DSSSMODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED                    0x00a0302d
#define RFMXWLAN_ATTR_DSSSMODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED                    0x00a0302e
#define RFMXWLAN_ATTR_DSSSMODACC_SPECTRUM_INVERTED                                      0x00a0307b
#define RFMXWLAN_ATTR_DSSSMODACC_DATA_DECODING_ENABLED                                  0x00a0307c
#define RFMXWLAN_ATTR_DSSSMODACC_AVERAGING_ENABLED                                      0x00a0302f
#define RFMXWLAN_ATTR_DSSSMODACC_AVERAGING_COUNT                                        0x00a03030
#define RFMXWLAN_ATTR_DSSSMODACC_ALL_TRACES_ENABLED                                     0x00a03031
#define RFMXWLAN_ATTR_DSSSMODACC_NUMBER_OF_ANALYSIS_THREADS                             0x00a03071
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_RMS_EVM_MEAN                                   0x00a03032
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PEAK_EVM_802_11_2016_MEAN                      0x00a0303c
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PEAK_EVM_802_11_2016_MAXIMUM                   0x00a0303d
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PEAK_EVM_802_11_2007_MEAN                      0x00a03035
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PEAK_EVM_802_11_2007_MAXIMUM                   0x00a03036
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PEAK_EVM_802_11_1999_MEAN                      0x00a03033
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PEAK_EVM_802_11_1999_MAXIMUM                   0x00a03034
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_NUMBER_OF_CHIPS_USED                           0x00a0304d
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_FREQUENCY_ERROR_MEAN                           0x00a0304e
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_CHIP_CLOCK_ERROR_MEAN                          0x00a03052
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_IQ_GAIN_IMBALANCE_MEAN                         0x00a03053
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_IQ_QUADRATURE_ERROR_MEAN                       0x00a03057
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_IQ_ORIGIN_OFFSET_MEAN                          0x00a0305b
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_RMS_MAGNITUDE_ERROR_MEAN                       0x00a03062
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_RMS_PHASE_ERROR_MEAN                           0x00a03063
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PREAMBLE_AVERAGE_POWER_MEAN                    0x00a03072
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PREAMBLE_PEAK_POWER_MAXIMUM                    0x00a03073
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_HEADER_AVERAGE_POWER_MEAN                      0x00a03074
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_HEADER_PEAK_POWER_MAXIMUM                      0x00a03075
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_DATA_AVERAGE_POWER_MEAN                        0x00a03076
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_DATA_PEAK_POWER_MAXIMUM                        0x00a03077
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PPDU_AVERAGE_POWER_MEAN                        0x00a03078
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PPDU_PEAK_POWER_MAXIMUM                        0x00a03079
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_CUSTOM_GATE_AVERAGE_POWER_MEAN                 0x00a0303e
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_CUSTOM_GATE_PEAK_POWER_MAXIMUM                 0x00a0303f
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_DATA_MODULATION_FORMAT                         0x00a03068
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PAYLOAD_LENGTH                                 0x00a03069
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PREAMBLE_TYPE                                  0x00a0306a
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_LOCKED_CLOCKS_BIT                              0x00a0306c
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_HEADER_CRC_STATUS                              0x00a0306d
#define RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PSDU_CRC_STATUS                                0x00a0306e
#define RFMXWLAN_ATTR_OFDMMODACC_MEASUREMENT_ENABLED                                    0x00a04000
#define RFMXWLAN_ATTR_OFDMMODACC_AVERAGING_ENABLED                                      0x00a04002
#define RFMXWLAN_ATTR_OFDMMODACC_AVERAGING_COUNT                                        0x00a04003
#define RFMXWLAN_ATTR_OFDMMODACC_AVERAGING_TYPE                                         0x00a040ac
#define RFMXWLAN_ATTR_OFDMMODACC_VECTOR_AVERAGING_TIME_ALIGNMENT_ENABLED                0x00a040ad
#define RFMXWLAN_ATTR_OFDMMODACC_VECTOR_AVERAGING_PHASE_ALIGNMENT_ENABLED               0x00a040ae
#define RFMXWLAN_ATTR_OFDMMODACC_MEASUREMENT_MODE                                       0x00a04066
#define RFMXWLAN_ATTR_OFDMMODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE                        0x00a04093
#define RFMXWLAN_ATTR_OFDMMODACC_EVM_UNIT                                               0x00a04008
#define RFMXWLAN_ATTR_OFDMMODACC_ACQUISITION_LENGTH_MODE                                0x00a04009
#define RFMXWLAN_ATTR_OFDMMODACC_ACQUISITION_LENGTH                                     0x00a0400a
#define RFMXWLAN_ATTR_OFDMMODACC_MEASUREMENT_OFFSET                                     0x00a0400b
#define RFMXWLAN_ATTR_OFDMMODACC_MAXIMUM_MEASUREMENT_LENGTH                             0x00a0400c
#define RFMXWLAN_ATTR_OFDMMODACC_BURST_START_DETECTION_ENABLED                          0x00a04085
#define RFMXWLAN_ATTR_OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD                      0x00a0407e
#define RFMXWLAN_ATTR_OFDMMODACC_COMMON_CLOCK_SOURCE_ENABLED                            0x00a0400d
#define RFMXWLAN_ATTR_OFDMMODACC_AMPLITUDE_TRACKING_ENABLED                             0x00a0400e
#define RFMXWLAN_ATTR_OFDMMODACC_PHASE_TRACKING_ENABLED                                 0x00a0400f
#define RFMXWLAN_ATTR_OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED                  0x00a04010
#define RFMXWLAN_ATTR_OFDMMODACC_SPECTRUM_INVERTED                                      0x00a0407a
#define RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_TYPE                                0x00a04011
#define RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_INTERPOLATION_TYPE                  0x00a0406a
#define RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_SMOOTHING_LENGTH                    0x00a0406b
#define RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_RELATIVE_DELAY_SPREAD               0x00a040b7
#define RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_L_LTF_ENABLED                       0x00a04087
#define RFMXWLAN_ATTR_OFDMMODACC_POWER_MEASUREMENT_ENABLED                              0x00a04017
#define RFMXWLAN_ATTR_OFDMMODACC_POWER_NUMBER_OF_CUSTOM_GATES                           0x00a04018
#define RFMXWLAN_ATTR_OFDMMODACC_POWER_CUSTOM_GATE_START_TIME                           0x00a04019
#define RFMXWLAN_ATTR_OFDMMODACC_POWER_CUSTOM_GATE_STOP_TIME                            0x00a0401a
#define RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED                           0x00a0408d
#define RFMXWLAN_ATTR_OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED                      0x00a0407b
#define RFMXWLAN_ATTR_OFDMMODACC_IQ_IMPAIRMENTS_MODEL                                   0x00a0401b
#define RFMXWLAN_ATTR_OFDMMODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED                   0x00a0401c
#define RFMXWLAN_ATTR_OFDMMODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED                 0x00a0401d
#define RFMXWLAN_ATTR_OFDMMODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED                      0x00a0401e
#define RFMXWLAN_ATTR_OFDMMODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED                  0x00a0407f
#define RFMXWLAN_ATTR_OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE                       0x00a0406c
#define RFMXWLAN_ATTR_OFDMMODACC_DATA_DECODING_ENABLED                                  0x00a0408b
#define RFMXWLAN_ATTR_OFDMMODACC_NOISE_COMPENSATION_ENABLED                             0x00a04067
#define RFMXWLAN_ATTR_OFDMMODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED           0x00a04068
#define RFMXWLAN_ATTR_OFDMMODACC_NOISE_COMPENSATION_REFERENCE_LEVEL_COERCION_LIMIT      0x00a04069
#define RFMXWLAN_ATTR_OFDMMODACC_OPTIMIZE_DYNAMIC_RANGE_FOR_EVM_ENABLED                 0x00a0407c
#define RFMXWLAN_ATTR_OFDMMODACC_OPTIMIZE_DYNAMIC_RANGE_FOR_EVM_MARGIN                  0x00a0407d
#define RFMXWLAN_ATTR_OFDMMODACC_AUTO_LEVEL_ALLOW_OVERFLOW                              0x00a040b1
#define RFMXWLAN_ATTR_OFDMMODACC_ALL_TRACES_ENABLED                                     0x00a04005
#define RFMXWLAN_ATTR_OFDMMODACC_NUMBER_OF_ANALYSIS_THREADS                             0x00a04004
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN                         0x00a0406e
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_COMPOSITE_DATA_RMS_EVM_MEAN                    0x00a0406f
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_COMPOSITE_PILOT_RMS_EVM_MEAN                   0x00a04070
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_STREAM_RMS_EVM_MEAN                            0x00a04074
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_STREAM_RMS_EVM_MAXIMUM                         0x00a04096
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_STREAM_RMS_EVM_MINIMUM                         0x00a04097
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_STREAM_DATA_RMS_EVM_MEAN                       0x00a04075
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_STREAM_PILOT_RMS_EVM_MEAN                      0x00a04076
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_CHAIN_RMS_EVM_MEAN                             0x00a04071
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_CHAIN_RMS_EVM_MAXIMUM                          0x00a04098
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_CHAIN_RMS_EVM_MINIMUM                          0x00a04099
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_CHAIN_DATA_RMS_EVM_MEAN                        0x00a04072
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_CHAIN_PILOT_RMS_EVM_MEAN                       0x00a04073
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_STREAM_RMS_EVM_MEAN                       0x00a04077
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_STREAM_RMS_EVM_MAXIMUM                    0x00a0409a
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_STREAM_RMS_EVM_MINIMUM                    0x00a0409b
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_STREAM_DATA_RMS_EVM_MEAN                  0x00a04078
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_STREAM_PILOT_RMS_EVM_MEAN                 0x00a04079
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_L_SIG_RMS_EVM_MEAN                             0x00a040bb
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SIG_RMS_EVM_MEAN                               0x00a040bc
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SIG_B_RMS_EVM_MEAN                             0x00a040bd
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_U_SIG_RMS_EVM_MEAN                             0x00a040be
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_EHT_SIG_RMS_EVM_MEAN                           0x00a040bf
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_L_STF_AVERAGE_POWER_MEAN                 0x00a0403a
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_L_STF_PEAK_POWER_MAXIMUM                 0x00a0403b
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_L_LTF_AVERAGE_POWER_MEAN                 0x00a0403c
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_L_LTF_PEAK_POWER_MAXIMUM                 0x00a0403d
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_L_SIG_AVERAGE_POWER_MEAN                 0x00a0403e
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_L_SIG_PEAK_POWER_MAXIMUM                 0x00a0403f
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_RL_SIG_AVERAGE_POWER_MEAN                0x00a04040
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_RL_SIG_PEAK_POWER_MAXIMUM                0x00a04041
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_SIG_AVERAGE_POWER_MEAN                0x00a04042
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_SIG_PEAK_POWER_MAXIMUM                0x00a04043
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_SIG_A_AVERAGE_POWER_MEAN             0x00a04044
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_SIG_A_PEAK_POWER_MAXIMUM             0x00a04045
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_SIG_A_AVERAGE_POWER_MEAN              0x00a04046
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_SIG_A_PEAK_POWER_MAXIMUM              0x00a04047
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_U_SIG_AVERAGE_POWER_MEAN                 0x00a040c0
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_U_SIG_PEAK_POWER_MAXIMUM                 0x00a040c1
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_SIG_B_AVERAGE_POWER_MEAN             0x00a04048
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_SIG_B_PEAK_POWER_MAXIMUM             0x00a04049
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_SIG_B_AVERAGE_POWER_MEAN              0x00a0404a
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_SIG_B_PEAK_POWER_MAXIMUM              0x00a0404b
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_STF_AVERAGE_POWER_MEAN                0x00a0404c
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_EHT_SIG_AVERAGE_POWER_MEAN               0x00a040c2
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_EHT_SIG_PEAK_POWER_MAXIMUM               0x00a040c3
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_STF_PEAK_POWER_MAXIMUM                0x00a0404d
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_GF_STF_AVERAGE_POWER_MEAN             0x00a0404e
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_GF_STF_PEAK_POWER_MAXIMUM             0x00a0404f
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_STF_AVERAGE_POWER_MEAN               0x00a04050
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_STF_PEAK_POWER_MAXIMUM               0x00a04051
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_STF_AVERAGE_POWER_MEAN                0x00a04052
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_STF_PEAK_POWER_MAXIMUM                0x00a04053
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_EHT_STF_AVERAGE_POWER_MEAN               0x00a040c4
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_EHT_STF_PEAK_POWER_MAXIMUM               0x00a040c5
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_DLTF_AVERAGE_POWER_MEAN               0x00a04054
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_DLTF_PEAK_POWER_MAXIMUM               0x00a04055
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_ELTF_AVERAGE_POWER_MEAN               0x00a04056
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HT_ELTF_PEAK_POWER_MAXIMUM               0x00a04057
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_LTF_AVERAGE_POWER_MEAN               0x00a04058
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_VHT_LTF_PEAK_POWER_MAXIMUM               0x00a04059
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_LTF_AVERAGE_POWER_MEAN                0x00a0405a
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_HE_LTF_PEAK_POWER_MAXIMUM                0x00a0405b
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_EHT_LTF_AVERAGE_POWER_MEAN               0x00a040c6
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_EHT_LTF_PEAK_POWER_MAXIMUM               0x00a040c7
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_DATA_AVERAGE_POWER_MEAN                  0x00a0405c
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_DATA_PEAK_POWER_MAXIMUM                  0x00a0405d
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_PE_AVERAGE_POWER_MEAN                    0x00a0405e
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_PE_PEAK_POWER_MAXIMUM                    0x00a0405f
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_PPDU_AVERAGE_POWER_MEAN                  0x00a04060
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_PPDU_PEAK_POWER_MAXIMUM                  0x00a04061
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_CUSTOM_GATE_AVERAGE_POWER_MEAN           0x00a04062
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_POWER_CUSTOM_GATE_PEAK_POWER_MAXIMUM           0x00a04063
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_CROSS_POWER_MEAN                               0x00a0408e
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_POWER_MEAN                                0x00a0408f
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_POWER_MAXIMUM                             0x00a0409c
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_USER_POWER_MINIMUM                             0x00a0409d
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SPECTRAL_FLATNESS_MARGIN                       0x00a04023
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SPECTRAL_FLATNESS_MARGIN_MAXIMUM               0x00a0409e
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SPECTRAL_FLATNESS_MARGIN_MINIMUM               0x00a0409f
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SPECTRAL_FLATNESS_MARGIN_SUBCARRIER_INDEX      0x00a04024
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_UNUSED_TONE_ERROR_MARGIN                       0x00a04025
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_UNUSED_TONE_ERROR_MARGIN_RU_INDEX              0x00a04026
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_BURST_START_TIME_MEAN                          0x00a040b0
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_NUMBER_OF_SYMBOLS_USED                         0x00a04016
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_NOISE_COMPENSATION_APPLIED                     0x00a04027
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_FREQUENCY_ERROR_MEAN                           0x00a04028
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_FREQUENCY_ERROR_MAXIMUM                        0x00a040a0
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_FREQUENCY_ERROR_MINIMUM                        0x00a040a1
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_FREQUENCY_ERROR_CCDF_10_PERCENT                0x00a04029
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SYMBOL_CLOCK_ERROR_MEAN                        0x00a0402a
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SYMBOL_CLOCK_ERROR_MAXIMUM                     0x00a040a2
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SYMBOL_CLOCK_ERROR_MINIMUM                     0x00a040a3
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RELATIVE_IQ_ORIGIN_OFFSET_MEAN                 0x00a0402b
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RELATIVE_IQ_ORIGIN_OFFSET_MAXIMUM              0x00a040a4
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RELATIVE_IQ_ORIGIN_OFFSET_MINIMUM              0x00a040a5
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_ABSOLUTE_IQ_ORIGIN_OFFSET_MEAN                 0x00a0402c
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_IQ_GAIN_IMBALANCE_MEAN                         0x00a0402d
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_IQ_GAIN_IMBALANCE_MAXIMUM                      0x00a040a6
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_IQ_GAIN_IMBALANCE_MINIMUM                      0x00a040a7
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_IQ_QUADRATURE_ERROR_MEAN                       0x00a0402e
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_IQ_QUADRATURE_ERROR_MAXIMUM                    0x00a040a8
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_IQ_QUADRATURE_ERROR_MINIMUM                    0x00a040a9
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_IQ_TIMING_SKEW_MEAN                            0x00a0402f
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RMS_COMMON_PHASE_ERROR_MEAN                    0x00a04030
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RMS_COMMON_PILOT_ERROR_MEAN                    0x00a0406d
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PPDU_TYPE                                      0x00a04031
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_MCS_INDEX                                      0x00a04032
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_FEC_CODING_TYPE                                0x00a040aa
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RU_SIZE                                        0x00a04033
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RU_OFFSET_MRU_INDEX                            0x00a04034
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_NUMBER_OF_USERS                                0x00a04035
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_NUMBER_OF_HE_SIG_B_SYMBOLS                     0x00a04036
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_GUARD_INTERVAL_TYPE                            0x00a04037
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_LTF_SIZE                                       0x00a04038
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_NUMBER_OF_SPACE_TIME_STREAMS                   0x00a04039
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SPACE_TIME_STREAM_OFFSET                       0x00a04090
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_DCM_ENABLED                                    0x00a040ab
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_L_SIG_PARITY_CHECK_STATUS                      0x00a04088
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SIG_CRC_STATUS                                 0x00a04089
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SIG_B_CRC_STATUS                               0x00a0408a
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_U_SIG_CRC_STATUS                               0x00a04091
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_EHT_SIG_CRC_STATUS                             0x00a04092
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PSDU_CRC_STATUS                                0x00a0408c
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PE_DURATION                                    0x00a04095
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PHASE_ROTATION_COEFFICIENT_1                   0x00a040b8
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PHASE_ROTATION_COEFFICIENT_2                   0x00a040b9
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PHASE_ROTATION_COEFFICIENT_3                   0x00a040ba
#define RFMXWLAN_ATTR_SEM_MEASUREMENT_ENABLED                                           0x00a05000
#define RFMXWLAN_ATTR_SEM_MASK_TYPE                                                     0x00a05002
#define RFMXWLAN_ATTR_SEM_CARRIER_INTEGRATION_BANDWIDTH                                 0x00a05005
#define RFMXWLAN_ATTR_SEM_NUMBER_OF_OFFSETS                                             0x00a05006
#define RFMXWLAN_ATTR_SEM_OFFSET_START_FREQUENCY                                        0x00a05007
#define RFMXWLAN_ATTR_SEM_OFFSET_STOP_FREQUENCY                                         0x00a05008
#define RFMXWLAN_ATTR_SEM_OFFSET_SIDEBAND                                               0x00a05009
#define RFMXWLAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_START                                   0x00a0500a
#define RFMXWLAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_STOP                                    0x00a0500b
#define RFMXWLAN_ATTR_SEM_SPAN_AUTO                                                     0x00a0500c
#define RFMXWLAN_ATTR_SEM_SPAN                                                          0x00a0500d
#define RFMXWLAN_ATTR_SEM_SWEEP_TIME_AUTO                                               0x00a05011
#define RFMXWLAN_ATTR_SEM_SWEEP_TIME_INTERVAL                                           0x00a05012
#define RFMXWLAN_ATTR_SEM_AVERAGING_ENABLED                                             0x00a05013
#define RFMXWLAN_ATTR_SEM_AVERAGING_COUNT                                               0x00a05014
#define RFMXWLAN_ATTR_SEM_AVERAGING_TYPE                                                0x00a05015
#define RFMXWLAN_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE                                     0x00a05016
#define RFMXWLAN_ATTR_SEM_ALL_TRACES_ENABLED                                            0x00a05017
#define RFMXWLAN_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                                    0x00a05018
#define RFMXWLAN_ATTR_SEM_RESULTS_MEASUREMENT_STATUS                                    0x00a0501b
#define RFMXWLAN_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_INTEGRATED_POWER                     0x00a0501c
#define RFMXWLAN_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_PEAK_POWER                           0x00a0501e
#define RFMXWLAN_ATTR_SEM_RESULTS_CARRIER_PEAK_FREQUENCY                                0x00a0501f
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS                       0x00a05021
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER                0x00a05022
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_INTEGRATED_POWER                0x00a05023
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER                      0x00a05024
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_PEAK_POWER                      0x00a05025
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                           0x00a05026
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                                   0x00a05027
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER                    0x00a05028
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER                    0x00a05029
#define RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY                         0x00a0502a
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS                       0x00a0502b
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER                0x00a0502c
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_INTEGRATED_POWER                0x00a0502d
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER                      0x00a0502e
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_PEAK_POWER                      0x00a0502f
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                           0x00a05030
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                                   0x00a05031
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER                    0x00a05032
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER                    0x00a05033
#define RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY                         0x00a05034
#define RFMXWLAN_ATTR_TXP_MEASUREMENT_ENABLED                                           0x00a01000
#define RFMXWLAN_ATTR_TXP_MAXIMUM_MEASUREMENT_INTERVAL                                  0x00a01002
#define RFMXWLAN_ATTR_TXP_BURST_DETECTION_ENABLED                                       0x00a01003
#define RFMXWLAN_ATTR_TXP_AVERAGING_ENABLED                                             0x00a01004
#define RFMXWLAN_ATTR_TXP_AVERAGING_COUNT                                               0x00a01005
#define RFMXWLAN_ATTR_TXP_ALL_TRACES_ENABLED                                            0x00a01006
#define RFMXWLAN_ATTR_TXP_NUMBER_OF_ANALYSIS_THREADS                                    0x00a01007
#define RFMXWLAN_ATTR_TXP_RESULTS_AVERAGE_POWER_MEAN                                    0x00a01009
#define RFMXWLAN_ATTR_TXP_RESULTS_AVERAGE_POWER_MAXIMUM                                 0x00a01015
#define RFMXWLAN_ATTR_TXP_RESULTS_AVERAGE_POWER_MINIMUM                                 0x00a01016
#define RFMXWLAN_ATTR_TXP_RESULTS_PEAK_POWER_MEAN                                       0x00a01017
#define RFMXWLAN_ATTR_TXP_RESULTS_PEAK_POWER_MAXIMUM                                    0x00a01011
#define RFMXWLAN_ATTR_TXP_RESULTS_PEAK_POWER_MINIMUM                                    0x00a01018
#define RFMXWLAN_ATTR_POWERRAMP_MEASUREMENT_ENABLED                                     0x00a0200a
#define RFMXWLAN_ATTR_POWERRAMP_ACQUISITION_LENGTH                                      0x00a0200c
#define RFMXWLAN_ATTR_POWERRAMP_AVERAGING_ENABLED                                       0x00a02014
#define RFMXWLAN_ATTR_POWERRAMP_AVERAGING_COUNT                                         0x00a02015
#define RFMXWLAN_ATTR_POWERRAMP_ALL_TRACES_ENABLED                                      0x00a02016
#define RFMXWLAN_ATTR_POWERRAMP_NUMBER_OF_ANALYSIS_THREADS                              0x00a02017
#define RFMXWLAN_ATTR_POWERRAMP_RESULTS_RISE_TIME_MEAN                                  0x00a02018
#define RFMXWLAN_ATTR_POWERRAMP_RESULTS_FALL_TIME_MEAN                                  0x00a02019
#define RFMXWLAN_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                                0x00a00024
#define RFMXWLAN_ATTR_SAMPLE_CLOCK_RATE_FACTOR                                          0x00a00036
#define RFMXWLAN_ATTR_LIMITED_CONFIGURATION_CHANGE                                      0x00a00025
#define RFMXWLAN_ATTR_RESULT_FETCH_TIMEOUT                                              0x00a0c000

// Values for RFMXWLAN_ATTR_TRIGGER_TYPE
#define RFMXWLAN_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXWLAN_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXWLAN_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXWLAN_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXWLAN_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXWLAN_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXWLAN_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXWLAN_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXWLAN_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXWLAN_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXWLAN_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXWLAN_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXWLAN_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXWLAN_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXWLAN_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXWLAN_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXWLAN_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXWLAN_VAL_TIMER_EVENT_STR                                                                "TimerEvent"

// Values for RFMXWLAN_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXWLAN_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXWLAN_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXWLAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXWLAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXWLAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXWLAN_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXWLAN_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXWLAN_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXWLAN_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXWLAN_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXWLAN_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXWLAN_ATTR_TRIGGER_GATE_ENABLED
#define RFMXWLAN_VAL_TRIGGER_GATE_ENABLED_FALSE                                                     0
#define RFMXWLAN_VAL_TRIGGER_GATE_ENABLED_TRUE                                                      1

// Values for RFMXWLAN_ATTR_STANDARD
#define RFMXWLAN_VAL_STANDARD_802_11_AG                                                             0
#define RFMXWLAN_VAL_STANDARD_802_11_B                                                              1
#define RFMXWLAN_VAL_STANDARD_802_11_J                                                              2
#define RFMXWLAN_VAL_STANDARD_802_11_P                                                              3
#define RFMXWLAN_VAL_STANDARD_802_11_N                                                              4
#define RFMXWLAN_VAL_STANDARD_802_11_AC                                                             5
#define RFMXWLAN_VAL_STANDARD_802_11_AX                                                             6
#define RFMXWLAN_VAL_STANDARD_802_11_BE                                                             7
#define RFMXWLAN_VAL_STANDARD_UNKNOWN                                                               -1

// Values for RFMXWLAN_ATTR_OFDM_TRANSMIT_POWER_CLASS
#define RFMXWLAN_VAL_OFDM_TRANSMIT_POWER_CLASS_A                                                    0
#define RFMXWLAN_VAL_OFDM_TRANSMIT_POWER_CLASS_B                                                    1
#define RFMXWLAN_VAL_OFDM_TRANSMIT_POWER_CLASS_C                                                    2
#define RFMXWLAN_VAL_OFDM_TRANSMIT_POWER_CLASS_D                                                    3

// Values for RFMXWLAN_ATTR_OFDM_FREQUENCY_BAND
#define RFMXWLAN_VAL_OFDM_FREQUENCY_BAND_2_4GHZ                                                     0
#define RFMXWLAN_VAL_OFDM_FREQUENCY_BAND_5GHZ                                                       1

// Values for RFMXWLAN_ATTR_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED
#define RFMXWLAN_VAL_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED_FALSE                                    0
#define RFMXWLAN_VAL_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED_TRUE                                     1

// Values for RFMXWLAN_ATTR_OFDM_PPDU_TYPE
#define RFMXWLAN_VAL_OFDM_PPDU_TYPE_NON_HT                                                          0
#define RFMXWLAN_VAL_OFDM_PPDU_TYPE_MIXED                                                           1
#define RFMXWLAN_VAL_OFDM_PPDU_TYPE_GREENFIELD                                                      2
#define RFMXWLAN_VAL_OFDM_PPDU_TYPE_SU                                                              3
#define RFMXWLAN_VAL_OFDM_PPDU_TYPE_MU                                                              4
#define RFMXWLAN_VAL_OFDM_PPDU_TYPE_EXTENDED_RANGE_SU                                               5
#define RFMXWLAN_VAL_OFDM_PPDU_TYPE_TRIGGER_BASED                                                   6

// Values for RFMXWLAN_ATTR_OFDM_HEADER_DECODING_ENABLED
#define RFMXWLAN_VAL_OFDM_HEADER_DECODING_ENABLED_FALSE                                             0
#define RFMXWLAN_VAL_OFDM_HEADER_DECODING_ENABLED_TRUE                                              1

// Values for RFMXWLAN_ATTR_OFDM_EHT_SIG_COMPRESSION_ENABLED
#define RFMXWLAN_VAL_OFDM_EHT_SIG_COMPRESSION_ENABLED_FALSE                                         0
#define RFMXWLAN_VAL_OFDM_EHT_SIG_COMPRESSION_ENABLED_TRUE                                          1

// Values for RFMXWLAN_ATTR_OFDM_FEC_CODING_TYPE
#define RFMXWLAN_VAL_OFDM_FEC_CODING_TYPE_BCC                                                       0
#define RFMXWLAN_VAL_OFDM_FEC_CODING_TYPE_LDPC                                                      1

// Values for RFMXWLAN_ATTR_OFDM_GUARD_INTERVAL_TYPE
#define RFMXWLAN_VAL_OFDM_GUARD_INTERVAL_TYPE_1_4                                                   0
#define RFMXWLAN_VAL_OFDM_GUARD_INTERVAL_TYPE_1_8                                                   1
#define RFMXWLAN_VAL_OFDM_GUARD_INTERVAL_TYPE_1_16                                                  2

// Values for RFMXWLAN_ATTR_OFDM_LTF_SIZE
#define RFMXWLAN_VAL_OFDM_LTF_SIZE_NOT_APPLICABLE                                                   -1
#define RFMXWLAN_VAL_OFDM_LTF_SIZE_4X                                                               0
#define RFMXWLAN_VAL_OFDM_LTF_SIZE_2X                                                               1
#define RFMXWLAN_VAL_OFDM_LTF_SIZE_1X                                                               2

// Values for RFMXWLAN_ATTR_OFDM_STBC_ENABLED
#define RFMXWLAN_VAL_OFDM_STBC_ENABLED_FALSE                                                        0
#define RFMXWLAN_VAL_OFDM_STBC_ENABLED_TRUE                                                         1

// Values for RFMXWLAN_ATTR_OFDM_DCM_ENABLED
#define RFMXWLAN_VAL_OFDM_DCM_ENABLED_FALSE                                                         0
#define RFMXWLAN_VAL_OFDM_DCM_ENABLED_TRUE                                                          1

// Values for RFMXWLAN_ATTR_OFDM_MU_MIMO_LTF_MODE_ENABLED
#define RFMXWLAN_VAL_OFDM_MU_MIMO_LTF_MODE_ENABLED_FALSE                                            0
#define RFMXWLAN_VAL_OFDM_MU_MIMO_LTF_MODE_ENABLED_TRUE                                             1

// Values for RFMXWLAN_ATTR_OFDM_PREAMBLE_PUNCTURING_ENABLED
#define RFMXWLAN_VAL_OFDM_PREAMBLE_PUNCTURING_ENABLED_FALSE                                         0
#define RFMXWLAN_VAL_OFDM_PREAMBLE_PUNCTURING_ENABLED_TRUE                                          1

// Values for RFMXWLAN_ATTR_OFDM_AUTO_PHASE_ROTATION_DETECTION_ENABLED
#define RFMXWLAN_VAL_OFDM_AUTO_PHASE_ROTATION_DETECTION_ENABLED_FALSE                               0
#define RFMXWLAN_VAL_OFDM_AUTO_PHASE_ROTATION_DETECTION_ENABLED_TRUE                                1

// Values for RFMXWLAN_ATTR_OFDM_PHASE_ROTATION_COEFFICIENT_1
#define RFMXWLAN_VAL_OFDM_PHASE_ROTATION_COEFFICIENT_1_PLUS_ONE                                     0
#define RFMXWLAN_VAL_OFDM_PHASE_ROTATION_COEFFICIENT_1_MINUS_ONE                                    1

// Values for RFMXWLAN_ATTR_OFDM_PHASE_ROTATION_COEFFICIENT_2
#define RFMXWLAN_VAL_OFDM_PHASE_ROTATION_COEFFICIENT_2_PLUS_ONE                                     0
#define RFMXWLAN_VAL_OFDM_PHASE_ROTATION_COEFFICIENT_2_MINUS_ONE                                    1

// Values for RFMXWLAN_ATTR_OFDM_PHASE_ROTATION_COEFFICIENT_3
#define RFMXWLAN_VAL_OFDM_PHASE_ROTATION_COEFFICIENT_3_PLUS_ONE                                     0
#define RFMXWLAN_VAL_OFDM_PHASE_ROTATION_COEFFICIENT_3_MINUS_ONE                                    1

// Values for RFMXWLAN_ATTR_DSSSMODACC_ACQUISITION_LENGTH_MODE
#define RFMXWLAN_VAL_DSSSMODACC_ACQUISITION_LENGTH_MODE_MANUAL                                      0
#define RFMXWLAN_VAL_DSSSMODACC_ACQUISITION_LENGTH_MODE_AUTO                                        1

// Values for RFMXWLAN_ATTR_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE
#define RFMXWLAN_VAL_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_RECTANGULAR                               0
#define RFMXWLAN_VAL_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_RAISED_COSINE                             1
#define RFMXWLAN_VAL_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_ROOT_RAISED_COSINE                        2
#define RFMXWLAN_VAL_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_GAUSSIAN                                  3

// Values for RFMXWLAN_ATTR_DSSSMODACC_EQUALIZATION_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_EQUALIZATION_ENABLED_FALSE                                          0
#define RFMXWLAN_VAL_DSSSMODACC_EQUALIZATION_ENABLED_TRUE                                           1

// Values for RFMXWLAN_ATTR_DSSSMODACC_BURST_START_DETECTION_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_BURST_START_DETECTION_ENABLED_FALSE                                 0
#define RFMXWLAN_VAL_DSSSMODACC_BURST_START_DETECTION_ENABLED_TRUE                                  1

// Values for RFMXWLAN_ATTR_DSSSMODACC_EVM_UNIT
#define RFMXWLAN_VAL_DSSSMODACC_EVM_UNIT_PERCENTAGE                                                 0
#define RFMXWLAN_VAL_DSSSMODACC_EVM_UNIT_DB                                                         1

// Values for RFMXWLAN_ATTR_DSSSMODACC_POWER_MEASUREMENT_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_POWER_MEASUREMENT_ENABLED_FALSE                                     0
#define RFMXWLAN_VAL_DSSSMODACC_POWER_MEASUREMENT_ENABLED_TRUE                                      1

// Values for RFMXWLAN_ATTR_DSSSMODACC_FREQUENCY_ERROR_CORRECTION_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_FREQUENCY_ERROR_CORRECTION_ENABLED_FALSE                            0
#define RFMXWLAN_VAL_DSSSMODACC_FREQUENCY_ERROR_CORRECTION_ENABLED_TRUE                             1

// Values for RFMXWLAN_ATTR_DSSSMODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED_FALSE                           0
#define RFMXWLAN_VAL_DSSSMODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED_TRUE                            1

// Values for RFMXWLAN_ATTR_DSSSMODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_FALSE                           0
#define RFMXWLAN_VAL_DSSSMODACC_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_TRUE                            1

// Values for RFMXWLAN_ATTR_DSSSMODACC_SPECTRUM_INVERTED
#define RFMXWLAN_VAL_DSSSMODACC_SPECTRUM_INVERTED_FALSE                                             0
#define RFMXWLAN_VAL_DSSSMODACC_SPECTRUM_INVERTED_TRUE                                              1

// Values for RFMXWLAN_ATTR_DSSSMODACC_DATA_DECODING_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_DATA_DECODING_ENABLED_FALSE                                         0
#define RFMXWLAN_VAL_DSSSMODACC_DATA_DECODING_ENABLED_TRUE                                          1

// Values for RFMXWLAN_ATTR_DSSSMODACC_AVERAGING_ENABLED
#define RFMXWLAN_VAL_DSSSMODACC_AVERAGING_ENABLED_FALSE                                             0
#define RFMXWLAN_VAL_DSSSMODACC_AVERAGING_ENABLED_TRUE                                              1

// Values for RFMXWLAN_ATTR_DSSSMODACC_RESULTS_DATA_MODULATION_FORMAT
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_DSSS1MBPS                                    0
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_DSSS2MBPS                                    1
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_CCK5_5MBPS                                   2
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_CCK11MBPS                                    3
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_PBCC5_5MBPS                                  4
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_PBCC11MBPS                                   5
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_PBCC22MBPS                                   6
#define RFMXWLAN_VAL_DSSSMODACC_DATA_MODULATION_FORMAT_PBCC33MBPS                                   7

// Values for RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PREAMBLE_TYPE
#define RFMXWLAN_VAL_DSSSMODACC_PREAMBLE_TYPE_LONG                                                  0
#define RFMXWLAN_VAL_DSSSMODACC_PREAMBLE_TYPE_SHORT                                                 1

// Values for RFMXWLAN_ATTR_DSSSMODACC_RESULTS_HEADER_CRC_STATUS
#define RFMXWLAN_VAL_DSSSMODACC_HEADER_CRC_STATUS_FAIL                                              0
#define RFMXWLAN_VAL_DSSSMODACC_HEADER_CRC_STATUS_PASS                                              1

// Values for RFMXWLAN_ATTR_DSSSMODACC_RESULTS_PSDU_CRC_STATUS
#define RFMXWLAN_VAL_DSSSMODACC_PSDU_CRC_STATUS_FAIL                                                0
#define RFMXWLAN_VAL_DSSSMODACC_PSDU_CRC_STATUS_PASS                                                1

// Values for RFMXWLAN_ATTR_OFDMMODACC_AVERAGING_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_AVERAGING_ENABLED_FALSE                                             0
#define RFMXWLAN_VAL_OFDMMODACC_AVERAGING_ENABLED_TRUE                                              1

// Values for RFMXWLAN_ATTR_OFDMMODACC_AVERAGING_TYPE
#define RFMXWLAN_VAL_OFDMMODACC_AVERAGING_TYPE_RMS                                                  0
#define RFMXWLAN_VAL_OFDMMODACC_AVERAGING_TYPE_VECTOR                                               5

// Values for RFMXWLAN_ATTR_OFDMMODACC_VECTOR_AVERAGING_TIME_ALIGNMENT_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_VECTOR_AVERAGING_TIME_ALIGNMENT_ENABLED_FALSE                       0
#define RFMXWLAN_VAL_OFDMMODACC_VECTOR_AVERAGING_TIME_ALIGNMENT_ENABLED_TRUE                        1

// Values for RFMXWLAN_ATTR_OFDMMODACC_VECTOR_AVERAGING_PHASE_ALIGNMENT_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_VECTOR_AVERAGING_PHASE_ALIGNMENT_ENABLED_FALSE                      0
#define RFMXWLAN_VAL_OFDMMODACC_VECTOR_AVERAGING_PHASE_ALIGNMENT_ENABLED_TRUE                       1

// Values for RFMXWLAN_ATTR_OFDMMODACC_MEASUREMENT_MODE
#define RFMXWLAN_VAL_OFDMMODACC_MEASUREMENT_MODE_MEASURE                                            0
#define RFMXWLAN_VAL_OFDMMODACC_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                              1

// Values for RFMXWLAN_ATTR_OFDMMODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE
#define RFMXWLAN_VAL_OFDMMODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE_ACQUIRED_WAVEFORM                   0
#define RFMXWLAN_VAL_OFDMMODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE_REFERENCE_WAVEFORM                  1

// Values for RFMXWLAN_ATTR_OFDMMODACC_EVM_UNIT
#define RFMXWLAN_VAL_OFDMMODACC_EVM_UNIT_PERCENTAGE                                                 0
#define RFMXWLAN_VAL_OFDMMODACC_EVM_UNIT_DB                                                         1

// Values for RFMXWLAN_ATTR_OFDMMODACC_ACQUISITION_LENGTH_MODE
#define RFMXWLAN_VAL_OFDMMODACC_ACQUISITION_LENGTH_MODE_MANUAL                                      0
#define RFMXWLAN_VAL_OFDMMODACC_ACQUISITION_LENGTH_MODE_AUTO                                        1

// Values for RFMXWLAN_ATTR_OFDMMODACC_BURST_START_DETECTION_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_BURST_START_DETECTION_ENABLED_FALSE                                 0
#define RFMXWLAN_VAL_OFDMMODACC_BURST_START_DETECTION_ENABLED_TRUE                                  1

// Values for RFMXWLAN_ATTR_OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD
#define RFMXWLAN_VAL_OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_DISABLED                          0
#define RFMXWLAN_VAL_OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_INITIAL_PREAMBLE                  1
#define RFMXWLAN_VAL_OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE                          2
#define RFMXWLAN_VAL_OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS               3
#define RFMXWLAN_VAL_OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_PILOTS_AND_DATA          4

// Values for RFMXWLAN_ATTR_OFDMMODACC_COMMON_CLOCK_SOURCE_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_COMMON_CLOCK_SOURCE_ENABLED_FALSE                                   0
#define RFMXWLAN_VAL_OFDMMODACC_COMMON_CLOCK_SOURCE_ENABLED_TRUE                                    1

// Values for RFMXWLAN_ATTR_OFDMMODACC_AMPLITUDE_TRACKING_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_FALSE                                    0
#define RFMXWLAN_VAL_OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_TRUE                                     1

// Values for RFMXWLAN_ATTR_OFDMMODACC_PHASE_TRACKING_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_TRACKING_ENABLED_FALSE                                        0
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_TRACKING_ENABLED_TRUE                                         1

// Values for RFMXWLAN_ATTR_OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_FALSE                         0
#define RFMXWLAN_VAL_OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE                          1

// Values for RFMXWLAN_ATTR_OFDMMODACC_SPECTRUM_INVERTED
#define RFMXWLAN_VAL_OFDMMODACC_SPECTRUM_INVERTED_FALSE                                             0
#define RFMXWLAN_VAL_OFDMMODACC_SPECTRUM_INVERTED_TRUE                                              1

// Values for RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_TYPE
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE                                   0
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE_AND_DATA                          1

// Values for RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_INTERPOLATION_TYPE
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_INTERPOLATION_TYPE_LINEAR                        0
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_INTERPOLATION_TYPE_TRIANGULAR_SMOOTHING          1
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_INTERPOLATION_TYPE_WIENER_FILTER                 2

// Values for RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_L_LTF_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_L_LTF_ENABLED_FALSE                              0
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_L_LTF_ENABLED_TRUE                               1

// Values for RFMXWLAN_ATTR_OFDMMODACC_POWER_MEASUREMENT_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_POWER_MEASUREMENT_ENABLED_FALSE                                     0
#define RFMXWLAN_VAL_OFDMMODACC_POWER_MEASUREMENT_ENABLED_TRUE                                      1

// Values for RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED_FALSE                                  0
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED_TRUE                                   1

// Values for RFMXWLAN_ATTR_OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED_FALSE                             0
#define RFMXWLAN_VAL_OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED_TRUE                              1

// Values for RFMXWLAN_ATTR_OFDMMODACC_IQ_IMPAIRMENTS_MODEL
#define RFMXWLAN_VAL_OFDMMODACC_IQ_IMPAIRMENTS_MODEL_TX                                             0
#define RFMXWLAN_VAL_OFDMMODACC_IQ_IMPAIRMENTS_MODEL_RX                                             1

// Values for RFMXWLAN_ATTR_OFDMMODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED_FALSE                          0
#define RFMXWLAN_VAL_OFDMMODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED_TRUE                           1

// Values for RFMXWLAN_ATTR_OFDMMODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED_FALSE                        0
#define RFMXWLAN_VAL_OFDMMODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED_TRUE                         1

// Values for RFMXWLAN_ATTR_OFDMMODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED_FALSE                             0
#define RFMXWLAN_VAL_OFDMMODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED_TRUE                              1

// Values for RFMXWLAN_ATTR_OFDMMODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED_FALSE                         0
#define RFMXWLAN_VAL_OFDMMODACC_IQ_IMPAIRMENTS_PER_SUBCARRIER_ENABLED_TRUE                          1

// Values for RFMXWLAN_ATTR_OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE
#define RFMXWLAN_VAL_OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE_LIMIT1                             0
#define RFMXWLAN_VAL_OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE_LIMIT2                             1

// Values for RFMXWLAN_ATTR_OFDMMODACC_DATA_DECODING_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_DATA_DECODING_ENABLED_FALSE                                         0
#define RFMXWLAN_VAL_OFDMMODACC_DATA_DECODING_ENABLED_TRUE                                          1

// Values for RFMXWLAN_ATTR_OFDMMODACC_NOISE_COMPENSATION_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_NOISE_COMPENSATION_ENABLED_FALSE                                    0
#define RFMXWLAN_VAL_OFDMMODACC_NOISE_COMPENSATION_ENABLED_TRUE                                     1

// Values for RFMXWLAN_ATTR_OFDMMODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED_FALSE                  0
#define RFMXWLAN_VAL_OFDMMODACC_NOISE_COMPENSATION_INPUT_POWER_CHECK_ENABLED_TRUE                   1

// Values for RFMXWLAN_ATTR_OFDMMODACC_OPTIMIZE_DYNAMIC_RANGE_FOR_EVM_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_OPTIMIZE_DYNAMIC_RANGE_FOR_EVM_ENABLED_FALSE                        0
#define RFMXWLAN_VAL_OFDMMODACC_OPTIMIZE_DYNAMIC_RANGE_FOR_EVM_ENABLED_TRUE                         1

// Values for RFMXWLAN_ATTR_OFDMMODACC_AUTO_LEVEL_ALLOW_OVERFLOW
#define RFMXWLAN_VAL_OFDMMODACC_AUTO_LEVEL_ALLOW_OVERFLOW_FALSE                                     0
#define RFMXWLAN_VAL_OFDMMODACC_AUTO_LEVEL_ALLOW_OVERFLOW_TRUE                                      1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_NOISE_COMPENSATION_APPLIED
#define RFMXWLAN_VAL_OFDMMODACC_NOISE_COMPENSATION_APPLIED_FALSE                                    0
#define RFMXWLAN_VAL_OFDMMODACC_NOISE_COMPENSATION_APPLIED_TRUE                                     1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_FEC_CODING_TYPE
#define RFMXWLAN_VAL_OFDMMODACC_FEC_CODING_TYPE_BCC                                                 0
#define RFMXWLAN_VAL_OFDMMODACC_FEC_CODING_TYPE_LDPC                                                1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_DCM_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_DCM_ENABLED_FALSE                                                   0
#define RFMXWLAN_VAL_OFDMMODACC_DCM_ENABLED_TRUE                                                    1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_L_SIG_PARITY_CHECK_STATUS
#define RFMXWLAN_VAL_OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_NOT_APPLICABLE                            -1
#define RFMXWLAN_VAL_OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_FAIL                                      0
#define RFMXWLAN_VAL_OFDMMODACC_L_SIG_PARITY_CHECK_STATUS_PASS                                      1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SIG_CRC_STATUS
#define RFMXWLAN_VAL_OFDMMODACC_SIG_CRC_STATUS_NOT_APPLICABLE                                       -1
#define RFMXWLAN_VAL_OFDMMODACC_SIG_CRC_STATUS_FAIL                                                 0
#define RFMXWLAN_VAL_OFDMMODACC_SIG_CRC_STATUS_PASS                                                 1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_SIG_B_CRC_STATUS
#define RFMXWLAN_VAL_OFDMMODACC_SIG_B_CRC_STATUS_NOT_APPLICABLE                                     -1
#define RFMXWLAN_VAL_OFDMMODACC_SIG_B_CRC_STATUS_FAIL                                               0
#define RFMXWLAN_VAL_OFDMMODACC_SIG_B_CRC_STATUS_PASS                                               1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_U_SIG_CRC_STATUS
#define RFMXWLAN_VAL_OFDMMODACC_U_SIG_CRC_STATUS_NOT_APPLICABLE                                     -1
#define RFMXWLAN_VAL_OFDMMODACC_U_SIG_CRC_STATUS_FAIL                                               0
#define RFMXWLAN_VAL_OFDMMODACC_U_SIG_CRC_STATUS_PASS                                               1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_EHT_SIG_CRC_STATUS
#define RFMXWLAN_VAL_OFDMMODACC_EHT_SIG_CRC_STATUS_NOT_APPLICABLE                                   -1
#define RFMXWLAN_VAL_OFDMMODACC_EHT_SIG_CRC_STATUS_FAIL                                             0
#define RFMXWLAN_VAL_OFDMMODACC_EHT_SIG_CRC_STATUS_PASS                                             1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PSDU_CRC_STATUS
#define RFMXWLAN_VAL_OFDMMODACC_PSDU_CRC_STATUS_FAIL                                                0
#define RFMXWLAN_VAL_OFDMMODACC_PSDU_CRC_STATUS_PASS                                                1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PHASE_ROTATION_COEFFICIENT_1
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_ROTATION_COEFFICIENT_1_PLUS_ONE                               0
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_ROTATION_COEFFICIENT_1_MINUS_ONE                              1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PHASE_ROTATION_COEFFICIENT_2
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_ROTATION_COEFFICIENT_2_PLUS_ONE                               0
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_ROTATION_COEFFICIENT_2_MINUS_ONE                              1

// Values for RFMXWLAN_ATTR_OFDMMODACC_RESULTS_PHASE_ROTATION_COEFFICIENT_3
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_ROTATION_COEFFICIENT_3_PLUS_ONE                               0
#define RFMXWLAN_VAL_OFDMMODACC_PHASE_ROTATION_COEFFICIENT_3_MINUS_ONE                              1

// Values for RFMXWLAN_ATTR_SEM_MASK_TYPE
#define RFMXWLAN_VAL_SEM_MASK_TYPE_STANDARD                                                         0
#define RFMXWLAN_VAL_SEM_MASK_TYPE_CUSTOM                                                           1

// Values for RFMXWLAN_ATTR_SEM_OFFSET_SIDEBAND
#define RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_NEGATIVE                                                   0
#define RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_POSITIVE                                                   1
#define RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_BOTH                                                       2

// Values for RFMXWLAN_ATTR_SEM_SPAN_AUTO
#define RFMXWLAN_VAL_SEM_SPAN_AUTO_FALSE                                                            0
#define RFMXWLAN_VAL_SEM_SPAN_AUTO_TRUE                                                             1

// Values for RFMXWLAN_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXWLAN_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXWLAN_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXWLAN_ATTR_SEM_AVERAGING_ENABLED
#define RFMXWLAN_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXWLAN_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXWLAN_ATTR_SEM_AVERAGING_TYPE
#define RFMXWLAN_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXWLAN_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXWLAN_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXWLAN_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXWLAN_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXWLAN_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE
#define RFMXWLAN_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXWLAN_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXWLAN_ATTR_SEM_RESULTS_MEASUREMENT_STATUS
#define RFMXWLAN_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXWLAN_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXWLAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXWLAN_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXWLAN_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXWLAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXWLAN_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXWLAN_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXWLAN_ATTR_TXP_BURST_DETECTION_ENABLED
#define RFMXWLAN_VAL_TXP_BURST_DETECTION_ENABLED_FALSE                                              0
#define RFMXWLAN_VAL_TXP_BURST_DETECTION_ENABLED_TRUE                                               1

// Values for RFMXWLAN_ATTR_TXP_AVERAGING_ENABLED
#define RFMXWLAN_VAL_TXP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXWLAN_VAL_TXP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXWLAN_ATTR_POWERRAMP_AVERAGING_ENABLED
#define RFMXWLAN_VAL_POWERRAMP_AVERAGING_ENABLED_FALSE                                              0
#define RFMXWLAN_VAL_POWERRAMP_AVERAGING_ENABLED_TRUE                                               1

// Values for RFMXWLAN_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXWLAN_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXWLAN_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXWLAN_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXWLAN_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXWLAN_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXWLAN_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for MeasurementTypes
#define RFMXWLAN_VAL_TXP                                                                            1<<0
#define RFMXWLAN_VAL_POWERRAMP                                                                      1<<1
#define RFMXWLAN_VAL_DSSSMODACC                                                                     1<<2
#define RFMXWLAN_VAL_OFDMMODACC                                                                     1<<3
#define RFMXWLAN_VAL_SEM                                                                            1<<4

// Values for FrequencyReferenceSource
#define RFMXWLAN_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXWLAN_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXWLAN_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXWLAN_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for Boolean
#define RFMXWLAN_VAL_FALSE                                                                          0
#define RFMXWLAN_VAL_TRUE                                                                           1

// Values for OfdmModAccCalibrationDataValid
#define RFMXWLAN_VAL_OFDMMODACC_CALIBRATION_DATA_VALID_FALSE                                        0
#define RFMXWLAN_VAL_OFDMMODACC_CALIBRATION_DATA_VALID_TRUE                                         1

/* ---------------- RFmxWLAN APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxWLAN_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxWLAN_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxWLAN_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxWLAN_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxWLAN_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxWLAN_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxWLAN_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxWLAN_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxWLAN_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxWLAN_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxWLAN_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxWLAN_BuildSegmentString(
   char selectorString[],
   int32 segmentNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWLAN_BuildChainString(
   char selectorString[],
   int32 chainNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWLAN_BuildGateString(
   char selectorString[],
   int32 gateNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWLAN_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWLAN_BuildUserString(
   char selectorString[],
   int32 userNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWLAN_BuildStreamString(
   char selectorString[],
   int32 streamNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWLAN_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxWLAN_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxWLAN_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxWLAN_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxWLAN_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxWLAN_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxWLAN_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWLAN_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWLAN_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWLAN_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWLAN_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxWLAN_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxWLAN_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxWLAN_AnalyzeSpectrum1Waveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 spectrum[],
   int32 arraySize,
   int32 reset,
   int64 reserved
);

int32 __stdcall RFmxWLAN_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxWLAN_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxWLAN_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxWLAN_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxWLAN_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxWLAN_AutoDetectSignal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxWLAN_CfgSelectedPortsMultiple(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char selectedPorts[]
);

int32 __stdcall RFmxWLAN_OFDMModAccClearNoiseCalibrationDatabase(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxWLAN_OFDMModAccValidateCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* calibrationDataValid
);

int32 __stdcall RFmxWLAN_OFDMModAccCfg1ReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccCfg1ReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 I[],
   float32 Q[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccAutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxWLAN_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxWLAN_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxWLAN_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxWLAN_CfgStandard(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 standard
);

int32 __stdcall RFmxWLAN_CfgChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 channelBandwidth
);

int32 __stdcall RFmxWLAN_CfgNumberOfFrequencySegmentsAndReceiveChains(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfFrequencySegments,
   int32 numberOfReceiveChains
);

int32 __stdcall RFmxWLAN_CfgFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency[],
   int32 numberOfElements
);

int32 __stdcall RFmxWLAN_DSSSModAccCfgAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 acquisitionLengthMode,
   float64 acquisitionLength
);

int32 __stdcall RFmxWLAN_DSSSModAccCfgMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementOffset,
   int32 maximumMeasurementLength
);

int32 __stdcall RFmxWLAN_DSSSModAccCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxWLAN_DSSSModAccCfgEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 EVMUnit
);

int32 __stdcall RFmxWLAN_DSSSModAccCfgPowerMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerMeasurementEnabled
);

int32 __stdcall RFmxWLAN_DSSSModAccCfgPowerMeasurementNumberOfCustomGates(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCustomGates
);

int32 __stdcall RFmxWLAN_DSSSModAccCfgPowerMeasurementCustomGateArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startTime[],
   float64 stopTime[],
   int32 numberOfElements
);

int32 __stdcall RFmxWLAN_SEMCfgSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spanAuto,
   float64 span
);

int32 __stdcall RFmxWLAN_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxWLAN_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxWLAN_SEMCfgMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 maskType
);

int32 __stdcall RFmxWLAN_SEMCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxWLAN_SEMCfgOffsetFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetStartFrequency[],
   float64 offsetStopFrequency[],
   int32 offsetSideband[],
   int32 numberOfElements
);

int32 __stdcall RFmxWLAN_SEMCfgOffsetRelativeLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeLimitStart[],
   float64 relativeLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxWLAN_TXPCfgMaximumMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 maximumMeasurementInterval
);

int32 __stdcall RFmxWLAN_TXPCfgBurstDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 burstDetectionEnabled
);

int32 __stdcall RFmxWLAN_TXPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxWLAN_PowerRampCfgAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 acquisitionLength
);

int32 __stdcall RFmxWLAN_PowerRampCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 acquisitionLengthMode,
   float64 acquisitionLength
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementOffset,
   int32 maximumMeasurementLength
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMode
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 commonClockSourceEnabled
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgAmplitudeTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 amplitudeTrackingEnabled
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 phaseTrackingEnabled
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgSymbolClockErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 symbolClockErrorCorrectionEnabled
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgChannelEstimationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelEstimationType
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 EVMUnit
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgFrequencyErrorEstimationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 frequencyErrorEstimationMethod
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgOptimizeDynamicRangeForEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 optimizeDynamicRangeForEVMEnabled,
   float64 optimizeDynamicRangeForEVMMargin
);

int32 __stdcall RFmxWLAN_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWLAN_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxWLAN_AnalyzeNWaveformsIQ(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0[],
   float64 dx[],
   NIComplexSingle IQ[],
   int32 IQSize[],
   int32 arraySize,
   int32 reset
);

int32 __stdcall RFmxWLAN_AnalyzeNWaveformsIQSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0[],
   float64 dx[],
   float32 I[],
   float32 Q[],
   int32 IQSize[],
   int32 arraySize,
   int32 reset
);

int32 __stdcall RFmxWLAN_AnalyzeNWaveformsSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0[],
   float64 dx[],
   float32 spectrum[],
   int32 spectrumSize[],
   int32 arraySize,
   int32 reset
);

int32 __stdcall RFmxWLAN_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWLAN_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxWLAN_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxWLAN_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxWLAN_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgNReferenceWaveforms(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0[],
   float64 dx[],
   NIComplexSingle referenceWaveform[],
   int32 referenceWaveformSize[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccCfgNReferenceWaveformsSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0[],
   float64 dx[],
   float32 I[],
   float32 Q[],
   int32 referenceWaveformSize[],
   int32 arraySize
);

int32 __stdcall RFmxWLAN_TXPFetchPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 power[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_TXPFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averagePowerMean,
   float64* peakPowerMaximum
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchCustomGatePowersArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 averagePowerMean[],
   float64 peakPowerMaximum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchEVMPerChipMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVMPerChipMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchDecodedPSDUBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedPSDUBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchDecodedHeaderBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedHeaderBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchPPDUInformation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* dataModulationFormat,
   int32* payloadLength,
   int32* preambleType,
   int32* lockedClocksBit,
   int32* headerCRCStatus,
   int32* PSDUCRCStatus
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSEVMMean,
   float64* peakEVM80211_2016Maximum,
   float64* peakEVM80211_2007Maximum,
   float64* peakEVM80211_1999Maximum,
   float64* frequencyErrorMean,
   float64* chipClockErrorMean,
   int32* numberOfChipsUsed
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffsetMean,
   float64* IQGainImbalanceMean,
   float64* IQQuadratureErrorMean
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchAveragePowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* preambleAveragePowerMean,
   float64* headerAveragePowerMean,
   float64* dataAveragePowerMean,
   float64* PPDUAveragePowerMean
);

int32 __stdcall RFmxWLAN_DSSSModAccFetchPeakPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* preamblePeakPowerMaximum,
   float64* headerPeakPowerMaximum,
   float64* dataPeakPowerMaximum,
   float64* PPDUPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_PowerRampFetchRiseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 rawWaveform[],
   float32 processedWaveform[],
   float32 threshold[],
   float32 powerReference[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_PowerRampFetchFallTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 rawWaveform[],
   float32 processedWaveform[],
   float32 threshold[],
   float32 powerReference[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_PowerRampFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* riseTimeMean,
   float64* fallTimeMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchEVMSubcarrierIndices(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 subcarrierIndices[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUnusedToneErrorMarginPerRU(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 unusedToneErrorMarginPerRU[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchStreamRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 streamRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchStreamDataRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 streamDataRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchStreamPilotRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 streamPilotRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchChainRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chainRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchChainDataRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chainDataRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchChainPilotRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chainPilotRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserStreamRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 userStreamRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserStreamDataRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 userStreamDataRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserStreamPilotRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 userStreamPilotRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchStreamRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 streamRMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserStreamRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 userStreamRMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchChainRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chainRMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSubcarrierStreamEVMPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 subcarrierIndex,
   float64* x0,
   float64* dx,
   float32 subcarrierStreamEVMPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSubcarrierChainEVMPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 subcarrierIndex,
   float64* x0,
   float64* dx,
   float32 subcarrierChainEVMPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSymbolStreamEVMPerSubcarrierTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 symbolIndex,
   float64* x0,
   float64* dx,
   float32 symbolStreamEVMPerSubcarrier[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSymbolChainEVMPerSubcarrierTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 symbolIndex,
   float64* x0,
   float64* dx,
   float32 symbolChainEVMPerSubcarrier[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSpectralFlatnessMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectralFlatnessMean[],
   float32 spectralFlatnessLowerMask[],
   float32 spectralFlatnessUpperMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreambleFrequencyErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 preambleFrequencyError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchChannelFrequencyResponseMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 channelFrequencyResponseMeanMagnitude[],
   float32 channelFrequencyResponseMeanPhase[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchGroupDelayMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 groupDelayMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchCommonPilotErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 commonPilotErrorMagnitude[],
   float32 commonPilotErrorPhase[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDataConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle dataConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDataConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPilotConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle pilotConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPilotConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserDataConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle userDataConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserDataConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserPilotConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle userPilotConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserPilotConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUnusedToneErrorMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 unusedToneError[],
   float32 unusedToneErrorMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchIQGainImbalancePerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 IQGainImbalancePerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchIQQuadratureErrorPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 IQQuadratureErrorPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchCustomGatePowersArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 averagePowerMean[],
   float64 peakPowerMaximum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDecodedUSIGBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedUSIGBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDecodedEHTSIGBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedEHTSIGBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDecodedPSDUBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedPSDUBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDecodedServiceBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedServiceBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchReferenceDataConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle referenceDataConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchReferenceDataConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDecodedLSIGBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedLSIGBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDecodedSIGBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedSIGBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDecodedSIGBBitsTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 decodedSIGBBits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPhaseNoisePSDMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseNoisePSDMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchCompositeRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* compositeRMSEVMMean,
   float64* compositeDataRMSEVMMean,
   float64* compositePilotRMSEVMMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchChainRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* chainRMSEVMMean,
   float64* chainDataRMSEVMMean,
   float64* chainPilotRMSEVMMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchStreamRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* streamRMSEVMMean,
   float64* streamDataRMSEVMMean,
   float64* streamPilotRMSEVMMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserStreamRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* userStreamRMSEVMMean,
   float64* userStreamDataRMSEVMMean,
   float64* userStreamPilotRMSEVMMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchNumberofSymbolsUsed(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* numberOfSymbolsUsed
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* frequencyErrorMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchFrequencyErrorCCDF10Percent(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* frequencyErrorCCDF10Percent
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSymbolClockErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* symbolClockErrorMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* relativeIQOriginOffsetMean,
   float64* IQGainImbalanceMean,
   float64* IQQuadratureErrorMean,
   float64* absoluteIQOriginOffsetMean,
   float64* IQTimingSkewMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSpectralFlatness(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* spectralFlatnessMargin,
   int32* spectralFlatnessMarginSubcarrierIndex
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUnusedToneError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* unusedToneErrorMargin,
   int32* unusedToneErrorMarginRUIndex
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreambleAveragePowersCommon(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* LSTFAveragePowerMean,
   float64* LLTFAveragePowerMean,
   float64* LSIGAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreamblePeakPowersCommon(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* LSTFPeakPowerMaximum,
   float64* LLTFPeakPowerMaximum,
   float64* LSIGPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreambleAveragePowers802_11n(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* HTSIGAveragePowerMean,
   float64* HTSTFAveragePowerMean,
   float64* HTDLTFAveragePowerMean,
   float64* HTELTFAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreamblePeakPowers802_11n(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* HTSIGPeakPowerMaximum,
   float64* HTSTFPeakPowerMaximum,
   float64* HTDLTFPeakPowerMaximum,
   float64* HTELTFPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreambleAveragePowers802_11ac(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* VHTSIGAAveragePowerMean,
   float64* VHTSTFAveragePowerMean,
   float64* VHTLTFAveragePowerMean,
   float64* VHTSIGBAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreamblePeakPowers802_11ac(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* VHTSIGAPeakPowerMaximum,
   float64* VHTSTFPeakPowerMaximum,
   float64* VHTLTFPeakPowerMaximum,
   float64* VHTSIGBPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreambleAveragePowers802_11ax(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RLSIGAveragePowerMean,
   float64* HESIGAAveragePowerMean,
   float64* HESIGBAveragePowerMean,
   float64* HESTFAveragePowerMean,
   float64* HELTFAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreambleAveragePowers802_11be(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RLSIGAveragePowerMean,
   float64* USIGAveragePowerMean,
   float64* EHTSIGAveragePowerMean,
   float64* EHTSTFAveragePowerMean,
   float64* EHTLTFAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreamblePeakPowers802_11ax(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RLSIGPeakPowerMaximum,
   float64* HESIGAPeakPowerMaximum,
   float64* HESIGBPeakPowerMaximum,
   float64* HESTFPeakPowerMaximum,
   float64* HELTFPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPreamblePeakPowers802_11be(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RLSIGPeakPowerMaximum,
   float64* USIGPeakPowerMaximum,
   float64* EHTSIGPeakPowerMaximum,
   float64* EHTSTFPeakPowerMaximum,
   float64* EHTLTFPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDataAveragePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* dataAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchDataPeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* dataPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPEAveragePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PEAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPEPeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PEPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPPDUAveragePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PPDUAveragePowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPPDUPeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PPDUPeakPowerMaximum
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchCrossPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* crossPowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchUserPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* userPowerMean
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPPDUType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* PPDUType
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchMCSIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* MCSIndex
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchGuardIntervalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* guardIntervalType
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchNumberOfSpaceTimeStreams(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* numberOfSpaceTimeStreams
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* numberOfUsers
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchRUOffsetAndSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* RUOffset,
   int32* RUSize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchNumberOfHESIGBSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* numberOfHESIGBSymbols
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchLTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* LTFSize
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchLSIGParityCheckStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* LSIGParityCheckStatus
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSIGCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* SIGCRCStatus
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchSIGBCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* SIGBCRCStatus
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPSDUCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* PSDUCRCStatus
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchPEDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PEDuration
);

int32 __stdcall RFmxWLAN_SEMFetchLowerOffsetMarginArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 measurementStatus[],
   float64 margin[],
   float64 marginFrequency[],
   float64 marginAbsolutePower[],
   float64 marginRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SEMFetchLowerOffsetPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 totalAbsolutePower[],
   float64 totalRelativePower[],
   float64 peakAbsolutePower[],
   float64 peakFrequency[],
   float64 peakRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SEMFetchUpperOffsetMarginArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 measurementStatus[],
   float64 margin[],
   float64 marginFrequency[],
   float64 marginAbsolutePower[],
   float64 marginRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SEMFetchUpperOffsetPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 totalAbsolutePower[],
   float64 totalRelativePower[],
   float64 peakAbsolutePower[],
   float64 peakFrequency[],
   float64 peakRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SEMFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   float32 compositeMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWLAN_SEMFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxWLAN_SEMFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxWLAN_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxWLAN_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAbsolutePower,
   float64* totalRelativePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* peakRelativePower
);

int32 __stdcall RFmxWLAN_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxWLAN_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAbsolutePower,
   float64* totalRelativePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* peakRelativePower
);

int32 __stdcall RFmxWLAN_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxWLAN_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxWLAN_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxWLAN_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxWLAN_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxWLAN_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxWLAN_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetTriggerGateEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetTriggerGateEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetTriggerGateLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetTriggerGateLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetStandard(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetStandard(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetNumberOfFrequencySegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetNumberOfFrequencySegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetNumberOfReceiveChains(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetNumberOfReceiveChains(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMFrequencySegmentIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMFrequencySegmentIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMTransmitPowerClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMTransmitPowerClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMFrequencyBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMFrequencyBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMAutoPPDUTypeDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMAutoPPDUTypeDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPPDUType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPPDUType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMHeaderDecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMHeaderDecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMEHTSIGCompressionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMEHTSIGCompressionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMMCSIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMMCSIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMFECCodingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMFECCodingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMRUSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMRUSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMRUOffsetMRUIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMRUOffsetMRUIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMGuardIntervalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMGuardIntervalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMLTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMLTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPreFECPaddingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPreFECPaddingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMLDPCExtraSymbolSegment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMLDPCExtraSymbolSegment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPEDisambiguity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPEDisambiguity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMSTBCEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMSTBCEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMNumberOfSpaceTimeStreams(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMNumberOfSpaceTimeStreams(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMSpaceTimeStreamOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMSpaceTimeStreamOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMNumberOfHESIGBSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMNumberOfHESIGBSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMNumberOfEHTSIGSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMNumberOfEHTSIGSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMDCMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMDCMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMNumberOfLTFSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMNumberOfLTFSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMMUMIMOLTFModeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMMUMIMOLTFModeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPreamblePuncturingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPreamblePuncturingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPreamblePuncturingBitmap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPreamblePuncturingBitmap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMAutoPhaseRotationDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMAutoPhaseRotationDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPhaseRotationCoefficient1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPhaseRotationCoefficient1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPhaseRotationCoefficient2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPhaseRotationCoefficient2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMPhaseRotationCoefficient3(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMPhaseRotationCoefficient3(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetDetectedStandard(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_GetDetectedChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_GetDetectedBurstLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetSampleClockRateFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetSampleClockRateFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetAcquisitionLengthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetAcquisitionLengthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetMaximumMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetMaximumMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetPulseShapingFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetPulseShapingFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetPulseShapingFilterParameter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetPulseShapingFilterParameter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetEqualizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetEqualizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetBurstStartDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetBurstStartDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetPowerMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetPowerMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetPowerNumberOfCustomGates(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetPowerNumberOfCustomGates(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetPowerCustomGateStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetPowerCustomGateStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetPowerCustomGateStopTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetPowerCustomGateStopTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetFrequencyErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetFrequencyErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetChipClockErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetChipClockErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetDataDecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetDataDecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPeakEVM802_11_2016Mean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPeakEVM802_11_2016Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPeakEVM802_11_2007Mean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPeakEVM802_11_2007Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPeakEVM802_11_1999Mean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPeakEVM802_11_1999Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsNumberOfChipsUsed(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsChipClockErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsIQGainImbalanceMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsIQQuadratureErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsIQOriginOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsRMSMagnitudeErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsRMSPhaseErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPreambleAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPreamblePeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsHeaderAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsHeaderPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsDataAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsDataPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPPDUAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPPDUPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsCustomGateAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsCustomGatePeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsDataModulationFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPayloadLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPreambleType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsLockedClocksBit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsHeaderCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_DSSSModAccGetResultsPSDUCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetVectorAveragingTimeAlignmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetVectorAveragingTimeAlignmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetVectorAveragingPhaseAlignmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetVectorAveragingPhaseAlignmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetEVMReferenceDataSymbolsMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetEVMReferenceDataSymbolsMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAcquisitionLengthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAcquisitionLengthMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetMaximumMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetMaximumMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetBurstStartDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetBurstStartDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetFrequencyErrorEstimationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetFrequencyErrorEstimationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAmplitudeTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAmplitudeTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetSymbolClockErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetSymbolClockErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetChannelEstimationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetChannelEstimationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetChannelEstimationInterpolationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetChannelEstimationInterpolationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetChannelEstimationSmoothingLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetChannelEstimationSmoothingLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetChannelEstimationRelativeDelaySpread(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetChannelEstimationRelativeDelaySpread(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetChannelEstimationLLTFEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetChannelEstimationLLTFEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetPowerMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetPowerMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetPowerNumberOfCustomGates(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetPowerNumberOfCustomGates(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetPowerCustomGateStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetPowerCustomGateStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetPowerCustomGateStopTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetPowerCustomGateStopTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetChannelMatrixPowerEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetChannelMatrixPowerEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetIQImpairmentsEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetIQImpairmentsEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetIQImpairmentsModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetIQImpairmentsModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetIQGainImbalanceCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetIQGainImbalanceCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetIQQuadratureErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetIQQuadratureErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetIQTimingSkewCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetIQTimingSkewCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetIQImpairmentsPerSubcarrierEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetIQImpairmentsPerSubcarrierEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetUnusedToneErrorMaskReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetUnusedToneErrorMaskReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetDataDecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetDataDecodingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetNoiseCompensationInputPowerCheckEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetNoiseCompensationInputPowerCheckEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetNoiseCompensationReferenceLevelCoercionLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetNoiseCompensationReferenceLevelCoercionLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetOptimizeDynamicRangeForEVMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetOptimizeDynamicRangeForEVMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetOptimizeDynamicRangeForEVMMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetOptimizeDynamicRangeForEVMMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAutoLevelAllowOverflow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAutoLevelAllowOverflow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsCompositeRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsCompositeDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsCompositePilotRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsStreamRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsStreamRMSEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsStreamRMSEVMMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsStreamDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsStreamPilotRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsChainRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsChainRMSEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsChainRMSEVMMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsChainDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsChainPilotRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserStreamRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserStreamRMSEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserStreamRMSEVMMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserStreamDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserStreamPilotRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLSIGRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSIGRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSIGBRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUSIGRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTSIGRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLSTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLSTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLLTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLLTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLSIGAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLSIGPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRLSIGAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRLSIGPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTSIGAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTSIGPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTSIGAAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTSIGAPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHESIGAAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHESIGAPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUSIGAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUSIGPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTSIGBAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTSIGBPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHESIGBAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHESIGBPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTSTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTSIGAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTSIGPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTSTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTGFSTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTGFSTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTSTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTSTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHESTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHESTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTSTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTSTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTDLTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTDLTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTELTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHTELTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTLTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsVHTLTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHELTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHELTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTLTFAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTLTFPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsDataAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsDataPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPEAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPEPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPPDUAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPPDUPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsCustomGateAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsCustomGatePeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsCrossPowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserPowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUserPowerMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSpectralFlatnessMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSpectralFlatnessMarginMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSpectralFlatnessMarginMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSpectralFlatnessMarginSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUnusedToneErrorMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUnusedToneErrorMarginRUIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsBurstStartTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsNumberOfSymbolsUsed(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsNoiseCompensationApplied(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsFrequencyErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsFrequencyErrorMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsFrequencyErrorCCDF10Percent(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSymbolClockErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSymbolClockErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSymbolClockErrorMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRelativeIQOriginOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRelativeIQOriginOffsetMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRelativeIQOriginOffsetMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsAbsoluteIQOriginOffsetMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsIQGainImbalanceMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsIQGainImbalanceMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsIQGainImbalanceMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsIQQuadratureErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsIQQuadratureErrorMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsIQQuadratureErrorMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsIQTimingSkewMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRMSCommonPhaseErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRMSCommonPilotErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPPDUType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsMCSIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsFECCodingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRUSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRUOffsetMRUIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsNumberOfHESIGBSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsGuardIntervalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsNumberOfSpaceTimeStreams(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSpaceTimeStreamOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsDCMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsLSIGParityCheckStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSIGCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsSIGBCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsUSIGCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsEHTSIGCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPSDUCRCStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPEDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPhaseRotationCoefficient1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPhaseRotationCoefficient2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsPhaseRotationCoefficient3(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetSpanAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetSpanAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsCarrierAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsCarrierPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_TXPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_TXPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_TXPGetMaximumMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_TXPSetMaximumMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_TXPGetBurstDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_TXPSetBurstDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_TXPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_TXPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_TXPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_TXPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_TXPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_TXPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_TXPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_TXPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_TXPGetResultsAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_TXPGetResultsAveragePowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_TXPGetResultsAveragePowerMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_TXPGetResultsPeakPowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_TXPGetResultsPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_TXPGetResultsPeakPowerMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampSetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetResultsRiseTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWLAN_PowerRampGetResultsFallTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#define RFMXWLAN_ATTR_OFDM_HE_LTF_SIZE                                                  0x00a0001d
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_HE_LTF_SIZE                                    0x00a04038
#define RFMXWLAN_ATTR_OFDM_NUMBER_OF_HE_LTF_SYMBOLS                                     0x00a00022
#define RFMXWLAN_ATTR_OFDM_RU_OFFSET                                                    0x00a0001b
#define RFMXWLAN_ATTR_OFDMMODACC_RESULTS_RU_OFFSET                                      0x00a04034
#define RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_SMOOTHING_ENABLED                   0x00a0406a

// Values for RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_TYPE
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_TYPE_CHANNEL_ESTIMATION_REFERENCE                0
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_TYPE_CHANNEL_ESTIMATION_REFERENCE_AND_DATA       1

// Values for RFMXWLAN_ATTR_OFDM_HE_LTF_SIZE
#define RFMXWLAN_VAL_OFDM_HE_LTF_SIZE_4X                                                            0
#define RFMXWLAN_VAL_OFDM_HE_LTF_SIZE_2X                                                            1
#define RFMXWLAN_VAL_OFDM_HE_LTF_SIZE_1X                                                            2
#define RFMXWLAN_VAL_OFDM_HE_LTF_SIZE_NOT_APPLICABLE                                                -1

// Values for RFMXWLAN_ATTR_OFDMMODACC_CHANNEL_ESTIMATION_SMOOTHING_ENABLED
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_SMOOTHING_ENABLED_FALSE                          0
#define RFMXWLAN_VAL_OFDMMODACC_CHANNEL_ESTIMATION_SMOOTHING_ENABLED_TRUE                           1

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxWLAN_AnalyzeIQ(
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

int32 __stdcall RFmxWLAN_AnalyzeIQSplit(
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

int32 __stdcall RFmxWLAN_AnalyzeSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[],
   float64 x0,
   float64 dx,
   float32 spectrum[],
   int32 arraySize,
   int32 reset,
   int32* averagingDone
);

int32 __stdcall RFmxWLAN_GetOFDMHELTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMHELTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsHELTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccFetchHELTFSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* HELTFSize
);

int32 __stdcall RFmxWLAN_GetOFDMNumberHELTFSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMNumberHELTFSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_GetOFDMRUOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_SetOFDMRUOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetResultsRUOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccGetChannelEstimationSmoothingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWLAN_OFDMModAccSetChannelEstimationSmoothingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

#ifdef __cplusplus
}
#endif


#endif

