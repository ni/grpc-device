
/****************************************************************************************************
*          National Instruments RFmx TDSCDMA
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxTDSCDMA.h
*
* Purpose:  National Instruments RFmx TDSCDMA,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_TDSCDMA_H__
#define __NI_RFMX_TDSCDMA_H__

#include "niRFmxInstr.h"

#define RFMXTDSCDMA_ATTR_MODACC_MEASUREMENT_ENABLED                                  0x00711000
#define RFMXTDSCDMA_ATTR_MODACC_AVERAGING_ENABLED                                    0x0071100b
#define RFMXTDSCDMA_ATTR_MODACC_AVERAGING_COUNT                                      0x0071100d
#define RFMXTDSCDMA_ATTR_MODACC_SYNCHRONIZATION_MODE                                 0x00711002
#define RFMXTDSCDMA_ATTR_MODACC_MEASUREMENT_OFFSET                                   0x00711003
#define RFMXTDSCDMA_ATTR_MODACC_MEASUREMENT_LENGTH                                   0x00711004
#define RFMXTDSCDMA_ATTR_MODACC_SPECTRUM_INVERTED                                    0x0071100a
#define RFMXTDSCDMA_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED                            0x0071101b
#define RFMXTDSCDMA_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                    0x00711011
#define RFMXTDSCDMA_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED                  0x00711012
#define RFMXTDSCDMA_ATTR_MODACC_RRC_FILTER_ENABLED                                   0x00711013
#define RFMXTDSCDMA_ATTR_MODACC_ALL_TRACES_ENABLED                                   0x0071101c
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_COMPOSITE_EVM                            0x00711080
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_COMPOSITE_EVM                           0x00711081
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_COMPOSITE_MAGNITUDE_ERROR                0x00711082
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_COMPOSITE_PHASE_ERROR                    0x00711083
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_IQ_ORIGIN_OFFSET                             0x00711084
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_IQ_GAIN_IMBALANCE                            0x00711085
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_IQ_QUADRATURE_ERROR                          0x00711086
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_FREQUENCY_ERROR                              0x00711087
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_CHIP_RATE_ERROR                              0x007110a9
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_COMPOSITE_RHO                                0x00711088
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MAXIMUM_COMPOSITE_RHO                        0x007110b3
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_MIDAMBLE_EVM                             0x0071108a
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_MIDAMBLE_EVM                            0x0071108b
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_MIDAMBLE_MAGNITUDE_ERROR                 0x0071108c
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_MIDAMBLE_PHASE_ERROR                     0x0071108d
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MIDAMBLE_RHO                                 0x0071108e
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MIDAMBLE_POWER                               0x0071108f
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MIDAMBLE_CODE                                0x00711090
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MIDAMBLE_SHIFT                               0x00711091
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_DATA_EVM                                 0x00711092
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_EVM                                0x00711093
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_DATA_MAGNITUDE_ERROR                     0x00711094
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_DATA_PHASE_ERROR                         0x00711095
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_DATA_RHO                                     0x00711096
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_CDE                                0x00711097
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_DATA_CDE                        0x007110bf
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_CDE_SPREADING_FACTOR               0x00711098
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_CDE_CODE                           0x00711099
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_ACTIVE_CDE                         0x0071109a
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_DATA_ACTIVE_CDE                 0x007110c0
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_ACTIVE_CDE_SPREADING_FACTOR        0x0071109b
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_ACTIVE_CDE_CODE                    0x0071109c
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_ACTIVE_CDE_NUMBER_OF_CHANNELS      0x0071109d
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_RCDE                               0x007110a0
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_DATA_RCDE                       0x007110c1
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_RCDE_SPREADING_FACTOR              0x007110a1
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_DATA_RCDE_CODE                          0x007110a2
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_DATA_FIELD_1_POWER                           0x0071109e
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_DATA_FIELD_2_POWER                           0x0071109f
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_NUMBER_OF_DETECTED_CHANNELS                  0x007110a3
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_DETECTED_SLOT_INDEX                          0x007110a4
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_DETECTED_SPREADING_FACTOR                    0x007110a5
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_DETECTED_MODULATION_TYPE                     0x007110a6
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_DETECTED_CHANNELIZATION_CODE                 0x007110a7
#define RFMXTDSCDMA_ATTR_ACP_MEASUREMENT_ENABLED                                     0x00701000
#define RFMXTDSCDMA_ATTR_ACP_CARRIER_INTEGRATION_BANDWIDTH                           0x00701005
#define RFMXTDSCDMA_ATTR_ACP_NUMBER_OF_OFFSETS                                       0x00701008
#define RFMXTDSCDMA_ATTR_ACP_OFFSET_FREQUENCY                                        0x0070100a
#define RFMXTDSCDMA_ATTR_ACP_OFFSET_INTEGRATION_BANDWIDTH                            0x0070100e
#define RFMXTDSCDMA_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH                               0x0070101b
#define RFMXTDSCDMA_ATTR_ACP_RBW_FILTER_BANDWIDTH                                    0x0070101c
#define RFMXTDSCDMA_ATTR_ACP_RBW_FILTER_TYPE                                         0x0070101d
#define RFMXTDSCDMA_ATTR_ACP_SWEEP_TIME_AUTO                                         0x0070101e
#define RFMXTDSCDMA_ATTR_ACP_SWEEP_TIME_INTERVAL                                     0x0070101f
#define RFMXTDSCDMA_ATTR_ACP_MEASUREMENT_METHOD                                      0x00701012
#define RFMXTDSCDMA_ATTR_ACP_SEQUENTIAL_FFT_SIZE                                     0x00701038
#define RFMXTDSCDMA_ATTR_ACP_NOISE_COMPENSATION_ENABLED                              0x00701020
#define RFMXTDSCDMA_ATTR_ACP_AVERAGING_ENABLED                                       0x00701016
#define RFMXTDSCDMA_ATTR_ACP_AVERAGING_COUNT                                         0x00701015
#define RFMXTDSCDMA_ATTR_ACP_AVERAGING_TYPE                                          0x00701018
#define RFMXTDSCDMA_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO                             0x00701034
#define RFMXTDSCDMA_ATTR_ACP_NEAR_IF_OUTPUT_POWER_OFFSET                             0x00701035
#define RFMXTDSCDMA_ATTR_ACP_FAR_IF_OUTPUT_POWER_OFFSET                              0x00701036
#define RFMXTDSCDMA_ATTR_ACP_ALL_TRACES_ENABLED                                      0x00701021
#define RFMXTDSCDMA_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                              0x00701014
#define RFMXTDSCDMA_ATTR_ACP_RESULTS_CARRIER_ABSOLUTE_POWER                          0x00701026
#define RFMXTDSCDMA_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                     0x0070102c
#define RFMXTDSCDMA_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                     0x0070102d
#define RFMXTDSCDMA_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                     0x00701032
#define RFMXTDSCDMA_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                     0x00701033
#define RFMXTDSCDMA_ATTR_CHP_MEASUREMENT_ENABLED                                     0x00703000
#define RFMXTDSCDMA_ATTR_CHP_INTEGRATION_BANDWIDTH                                   0x00703002
#define RFMXTDSCDMA_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH                               0x0070300c
#define RFMXTDSCDMA_ATTR_CHP_RBW_FILTER_BANDWIDTH                                    0x0070300d
#define RFMXTDSCDMA_ATTR_CHP_RBW_FILTER_TYPE                                         0x0070300e
#define RFMXTDSCDMA_ATTR_CHP_SWEEP_TIME_AUTO                                         0x00703011
#define RFMXTDSCDMA_ATTR_CHP_SWEEP_TIME_INTERVAL                                     0x00703012
#define RFMXTDSCDMA_ATTR_CHP_AVERAGING_ENABLED                                       0x00703007
#define RFMXTDSCDMA_ATTR_CHP_AVERAGING_COUNT                                         0x00703006
#define RFMXTDSCDMA_ATTR_CHP_AVERAGING_TYPE                                          0x00703009
#define RFMXTDSCDMA_ATTR_CHP_ALL_TRACES_ENABLED                                      0x00703014
#define RFMXTDSCDMA_ATTR_CHP_NUMBER_OF_ANALYSIS_THREADS                              0x00703003
#define RFMXTDSCDMA_ATTR_CHP_RESULTS_CARRIER_ABSOLUTE_POWER                          0x00703015
#define RFMXTDSCDMA_ATTR_OBW_MEASUREMENT_ENABLED                                     0x00706000
#define RFMXTDSCDMA_ATTR_OBW_SPAN                                                    0x00706004
#define RFMXTDSCDMA_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH                               0x0070600c
#define RFMXTDSCDMA_ATTR_OBW_RBW_FILTER_BANDWIDTH                                    0x0070600d
#define RFMXTDSCDMA_ATTR_OBW_RBW_FILTER_TYPE                                         0x0070600e
#define RFMXTDSCDMA_ATTR_OBW_SWEEP_TIME_AUTO                                         0x0070600f
#define RFMXTDSCDMA_ATTR_OBW_SWEEP_TIME_INTERVAL                                     0x00706010
#define RFMXTDSCDMA_ATTR_OBW_AVERAGING_ENABLED                                       0x00706007
#define RFMXTDSCDMA_ATTR_OBW_AVERAGING_COUNT                                         0x00706006
#define RFMXTDSCDMA_ATTR_OBW_AVERAGING_TYPE                                          0x00706009
#define RFMXTDSCDMA_ATTR_OBW_ALL_TRACES_ENABLED                                      0x00706012
#define RFMXTDSCDMA_ATTR_OBW_NUMBER_OF_ANALYSIS_THREADS                              0x00706003
#define RFMXTDSCDMA_ATTR_OBW_RESULTS_OCCUPIED_BANDWIDTH                              0x00706013
#define RFMXTDSCDMA_ATTR_OBW_RESULTS_ABSOLUTE_POWER                                  0x00706014
#define RFMXTDSCDMA_ATTR_OBW_RESULTS_START_FREQUENCY                                 0x00706015
#define RFMXTDSCDMA_ATTR_OBW_RESULTS_STOP_FREQUENCY                                  0x00706016
#define RFMXTDSCDMA_ATTR_SEM_MEASUREMENT_ENABLED                                     0x00708000
#define RFMXTDSCDMA_ATTR_SEM_CARRIER_INTEGRATION_BANDWIDTH                           0x00708005
#define RFMXTDSCDMA_ATTR_SEM_NUMBER_OF_OFFSETS                                       0x0070800b
#define RFMXTDSCDMA_ATTR_SEM_OFFSET_START_FREQUENCY                                  0x00708014
#define RFMXTDSCDMA_ATTR_SEM_OFFSET_STOP_FREQUENCY                                   0x00708015
#define RFMXTDSCDMA_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH                             0x00708017
#define RFMXTDSCDMA_ATTR_SEM_OFFSET_RBW_FILTER_TYPE                                  0x00708018
#define RFMXTDSCDMA_ATTR_SEM_OFFSET_BANDWIDTH_INTEGRAL                               0x0070800c
#define RFMXTDSCDMA_ATTR_SEM_SWEEP_TIME_AUTO                                         0x00708025
#define RFMXTDSCDMA_ATTR_SEM_SWEEP_TIME_INTERVAL                                     0x00708026
#define RFMXTDSCDMA_ATTR_SEM_AVERAGING_ENABLED                                       0x0070801f
#define RFMXTDSCDMA_ATTR_SEM_AVERAGING_COUNT                                         0x0070801e
#define RFMXTDSCDMA_ATTR_SEM_AVERAGING_TYPE                                          0x00708021
#define RFMXTDSCDMA_ATTR_SEM_ALL_TRACES_ENABLED                                      0x00708027
#define RFMXTDSCDMA_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                              0x0070801d
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_MEASUREMENT_STATUS                              0x00708029
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_INTEGRATED_POWER               0x0070802d
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS                 0x0070803d
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER          0x00708034
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_INTEGRATED_POWER          0x00708035
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER                0x00708036
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_PEAK_POWER                0x00708037
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                     0x00708038
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                             0x00708039
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER              0x0070803a
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER              0x0070803b
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY                   0x0070803c
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS                 0x0070804a
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER          0x00708041
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_INTEGRATED_POWER          0x00708042
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER                0x00708043
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_PEAK_POWER                0x00708044
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                     0x00708045
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                             0x00708046
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER              0x00708047
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER              0x00708048
#define RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY                   0x00708049
#define RFMXTDSCDMA_ATTR_CDA_MEASUREMENT_ENABLED                                     0x00713000
#define RFMXTDSCDMA_ATTR_CDA_AVERAGING_ENABLED                                       0x0071302a
#define RFMXTDSCDMA_ATTR_CDA_AVERAGING_COUNT                                         0x0071302c
#define RFMXTDSCDMA_ATTR_CDA_SYNCHRONIZATION_MODE                                    0x00713002
#define RFMXTDSCDMA_ATTR_CDA_MEASUREMENT_OFFSET                                      0x00713003
#define RFMXTDSCDMA_ATTR_CDA_BASE_SPREADING_FACTOR                                   0x00713004
#define RFMXTDSCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_SPREADING_FACTOR                    0x00713005
#define RFMXTDSCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_CHANNELIZATION_CODE                 0x00713006
#define RFMXTDSCDMA_ATTR_CDA_SPECTRUM_INVERTED                                       0x00713007
#define RFMXTDSCDMA_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED                               0x00713008
#define RFMXTDSCDMA_ATTR_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                       0x00713009
#define RFMXTDSCDMA_ATTR_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED                     0x0071300a
#define RFMXTDSCDMA_ATTR_CDA_POWER_UNIT                                              0x0071300b
#define RFMXTDSCDMA_ATTR_CDA_RRC_FILTER_ENABLED                                      0x0071300c
#define RFMXTDSCDMA_ATTR_CDA_ALL_TRACES_ENABLED                                      0x0071300d
#define RFMXTDSCDMA_ATTR_CDA_NUMBER_OF_ANALYSIS_THREADS                              0x0071300e
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_SYMBOL_POWER                               0x0071302d
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_RMS_SYMBOL_EVM                             0x00713010
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MAXIMUM_PEAK_SYMBOL_EVM                         0x00713021
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_RMS_SYMBOL_MAGNITUDE_ERROR                 0x00713012
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_RMS_SYMBOL_PHASE_ERROR                     0x00713013
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_IQ_ORIGIN_OFFSET                                0x00713014
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_IQ_GAIN_IMBALANCE                               0x00713015
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_IQ_QUADRATURE_ERROR                             0x00713016
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_FREQUENCY_ERROR                                 0x00713017
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_CHIP_RATE_ERROR                                 0x00713018
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_TOTAL_POWER                                0x00713019
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MAXIMUM_TOTAL_POWER                             0x00713024
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_TOTAL_ACTIVE_POWER                         0x0071301a
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MAXIMUM_TOTAL_ACTIVE_POWER                      0x00713025
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_ACTIVE_POWER                               0x0071301b
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MAXIMUM_PEAK_ACTIVE_POWER                       0x00713027
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MEAN_INACTIVE_POWER                             0x0071301d
#define RFMXTDSCDMA_ATTR_CDA_RESULTS_MAXIMUM_PEAK_INACTIVE_POWER                     0x00713029
#define RFMXTDSCDMA_ATTR_PVT_MEASUREMENT_ENABLED                                     0x00707000
#define RFMXTDSCDMA_ATTR_PVT_MEASUREMENT_METHOD                                      0x00707002
#define RFMXTDSCDMA_ATTR_PVT_RRC_FILTER_ENABLED                                      0x00707005
#define RFMXTDSCDMA_ATTR_PVT_AVERAGING_ENABLED                                       0x00707006
#define RFMXTDSCDMA_ATTR_PVT_AVERAGING_COUNT                                         0x00707007
#define RFMXTDSCDMA_ATTR_PVT_AVERAGING_TYPE                                          0x00707008
#define RFMXTDSCDMA_ATTR_PVT_ALL_TRACES_ENABLED                                      0x00707009
#define RFMXTDSCDMA_ATTR_PVT_NUMBER_OF_ANALYSIS_THREADS                              0x0070700a
#define RFMXTDSCDMA_ATTR_PVT_NUMBER_OF_SEGMENTS                                      0x0070700c
#define RFMXTDSCDMA_ATTR_PVT_SEGMENT_START                                           0x0070700d
#define RFMXTDSCDMA_ATTR_PVT_SEGMENT_STOP                                            0x0070700e
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_MEASUREMENT_STATUS                              0x0070700f
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_MEAN_ABSOLUTE_ON_POWER                          0x00707010
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_MEAN_ABSOLUTE_OFF_POWER                         0x00707011
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_MAXIMUM_ABSOLUTE_POWER                          0x00707012
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_MINIMUM_ABSOLUTE_POWER                          0x00707013
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_BURST_WIDTH                                     0x00707014
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_SEGMENT_STATUS                                  0x00707017
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_SEGMENT_MARGIN                                  0x00707018
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_SEGMENT_MARGIN_TIME                             0x00707019
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_SEGMENT_MEAN_ABSOLUTE_POWER                     0x0070701b
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_SEGMENT_MAXIMUM_ABSOLUTE_POWER                  0x0070701c
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_SEGMENT_MINIMUM_ABSOLUTE_POWER                  0x0070701d
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_MIDAMBLE_CODE                                   0x0070701e
#define RFMXTDSCDMA_ATTR_PVT_RESULTS_MIDAMBLE_SHIFT                                  0x0070701f
#define RFMXTDSCDMA_ATTR_LIMITED_CONFIGURATION_CHANGE                                0x0070d003
#define RFMXTDSCDMA_ATTR_RESULT_FETCH_TIMEOUT                                        0x0070c000
#define RFMXTDSCDMA_ATTR_CENTER_FREQUENCY                                            0x00700001
#define RFMXTDSCDMA_ATTR_REFERENCE_LEVEL                                             0x00700002
#define RFMXTDSCDMA_ATTR_EXTERNAL_ATTENUATION                                        0x00700003
#define RFMXTDSCDMA_ATTR_TRIGGER_TYPE                                                0x00700004
#define RFMXTDSCDMA_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                 0x00700005
#define RFMXTDSCDMA_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                   0x00700006
#define RFMXTDSCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                0x00700007
#define RFMXTDSCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                 0x00700008
#define RFMXTDSCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                            0x00700fff
#define RFMXTDSCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                 0x00700009
#define RFMXTDSCDMA_ATTR_TRIGGER_DELAY                                               0x0070000a
#define RFMXTDSCDMA_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                             0x0070000b
#define RFMXTDSCDMA_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                         0x0070000c
#define RFMXTDSCDMA_ATTR_CHANNEL_CONFIGURATION_MODE                                  0x00700010
#define RFMXTDSCDMA_ATTR_NUMBER_OF_CHANNELS                                          0x00700014
#define RFMXTDSCDMA_ATTR_CHANNEL_TYPE                                                0x00700016
#define RFMXTDSCDMA_ATTR_SLOT_INDEX                                                  0x00700015
#define RFMXTDSCDMA_ATTR_MODULATION_TYPE                                             0x00700017
#define RFMXTDSCDMA_ATTR_SLOT_FORMAT                                                 0x00700018
#define RFMXTDSCDMA_ATTR_CHANNELIZATION_CODE                                         0x00700019
#define RFMXTDSCDMA_ATTR_UPLINK_SCRAMBLING_CODE                                      0x0070001a
#define RFMXTDSCDMA_ATTR_MIDAMBLE_AUTO_DETECTION_MODE                                0x00711007
#define RFMXTDSCDMA_ATTR_MAXIMUM_NUMBER_OF_USERS                                     0x0070001b
#define RFMXTDSCDMA_ATTR_MIDAMBLE_SHIFT                                              0x00711009
#define RFMXTDSCDMA_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                          0x0070d000
#define RFMXTDSCDMA_ATTR_PILOT_CODE                                                  0x0070001c
#define RFMXTDSCDMA_ATTR_MODACC_SLOT_TYPE                                            0x00711006
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_PILOT_EVM                                0x007110ae
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PEAK_PILOT_EVM                               0x007110af
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_PILOT_MAGNITUDE_ERROR                    0x007110b0
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_RMS_PILOT_PHASE_ERROR                        0x007110b1
#define RFMXTDSCDMA_ATTR_MODACC_RESULTS_PILOT_RHO                                    0x007110b2
#define RFMXTDSCDMA_ATTR_SLOTPOWER_MEASUREMENT_ENABLED                               0x00709000
#define RFMXTDSCDMA_ATTR_SLOTPOWER_MEASUREMENT_LENGTH                                0x00709002
#define RFMXTDSCDMA_ATTR_SLOTPOWER_SPECTRUM_INVERTED                                 0x00709003
#define RFMXTDSCDMA_ATTR_SLOTPOWER_RRC_FILTER_ENABLED                                0x00709004
#define RFMXTDSCDMA_ATTR_SELECTED_PORTS                                              0x00700ffd
#define RFMXTDSCDMA_ATTR_REFERENCE_LEVEL_HEADROOM                                    0x00700ffc
#define RFMXTDSCDMA_ATTR_ACP_FFT_OVERLAP_MODE                                        0x00701039
#define RFMXTDSCDMA_ATTR_ACP_FFT_OVERLAP                                             0x0070103a

// Values for RFMXTDSCDMA_ATTR_TRIGGER_TYPE
#define RFMXTDSCDMA_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXTDSCDMA_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXTDSCDMA_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXTDSCDMA_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXTDSCDMA_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXTDSCDMA_VAL_PFI0                                                                           "PFI0"
#define RFMXTDSCDMA_VAL_PFI1                                                                           "PFI1"
#define RFMXTDSCDMA_VAL_PXI_TRIG0                                                                      "PXI_Trig0"
#define RFMXTDSCDMA_VAL_PXI_TRIG1                                                                      "PXI_Trig1"
#define RFMXTDSCDMA_VAL_PXI_TRIG2                                                                      "PXI_Trig2"
#define RFMXTDSCDMA_VAL_PXI_TRIG3                                                                      "PXI_Trig3"
#define RFMXTDSCDMA_VAL_PXI_TRIG4                                                                      "PXI_Trig4"
#define RFMXTDSCDMA_VAL_PXI_TRIG5                                                                      "PXI_Trig5"
#define RFMXTDSCDMA_VAL_PXI_TRIG6                                                                      "PXI_Trig6"
#define RFMXTDSCDMA_VAL_PXI_TRIG7                                                                      "PXI_Trig7"
#define RFMXTDSCDMA_VAL_PXI_STAR                                                                       "PXI_STAR"
#define RFMXTDSCDMA_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXTDSCDMA_VAL_TIMER_EVENT_STR                                                                "TimerEvent"

// Values for RFMXTDSCDMA_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXTDSCDMA_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXTDSCDMA_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXTDSCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXTDSCDMA_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXTDSCDMA_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXTDSCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXTDSCDMA_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXTDSCDMA_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXTDSCDMA_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXTDSCDMA_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXTDSCDMA_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXTDSCDMA_ATTR_CHANNEL_CONFIGURATION_MODE
#define RFMXTDSCDMA_VAL_CHANNEL_CONFIGURATION_MODE_AUTO_DETECT                                         0
#define RFMXTDSCDMA_VAL_CHANNEL_CONFIGURATION_MODE_USER_DEFINED                                        1

// Values for RFMXTDSCDMA_ATTR_CHANNEL_TYPE
#define RFMXTDSCDMA_VAL_CHANNEL_TYPE_IDLE                                                              0
#define RFMXTDSCDMA_VAL_CHANNEL_TYPE_DPCH                                                              1
#define RFMXTDSCDMA_VAL_CHANNEL_TYPE_EDCH                                                              2
#define RFMXTDSCDMA_VAL_CHANNEL_TYPE_HSSICH                                                            3

// Values for RFMXTDSCDMA_ATTR_MODULATION_TYPE
#define RFMXTDSCDMA_VAL_MODULATION_TYPE_QPSK                                                           0
#define RFMXTDSCDMA_VAL_MODULATION_TYPE_8PSK                                                           1
#define RFMXTDSCDMA_VAL_MODULATION_TYPE_16QAM                                                          2

// Values for RFMXTDSCDMA_ATTR_MIDAMBLE_AUTO_DETECTION_MODE
#define RFMXTDSCDMA_VAL_MIDAMBLE_AUTO_DETECTION_MODE_OFF                                               0
#define RFMXTDSCDMA_VAL_MIDAMBLE_AUTO_DETECTION_MODE_MIDAMBLE_SHIFT                                    1

// Values for RFMXTDSCDMA_ATTR_MODACC_AVERAGING_ENABLED
#define RFMXTDSCDMA_VAL_MODACC_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXTDSCDMA_VAL_MODACC_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXTDSCDMA_ATTR_MODACC_SYNCHRONIZATION_MODE
#define RFMXTDSCDMA_VAL_MODACC_SYNCHRONIZATION_MODE_SLOT                                               0
#define RFMXTDSCDMA_VAL_MODACC_SYNCHRONIZATION_MODE_SUBFRAME                                           1

// Values for RFMXTDSCDMA_ATTR_MODACC_SPECTRUM_INVERTED
#define RFMXTDSCDMA_VAL_MODACC_SPECTRUM_INVERTED_FALSE                                                 0
#define RFMXTDSCDMA_VAL_MODACC_SPECTRUM_INVERTED_TRUE                                                  1

// Values for RFMXTDSCDMA_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXTDSCDMA_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                         0
#define RFMXTDSCDMA_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                          1

// Values for RFMXTDSCDMA_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXTDSCDMA_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                 0
#define RFMXTDSCDMA_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                  1

// Values for RFMXTDSCDMA_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXTDSCDMA_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                               0
#define RFMXTDSCDMA_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                1

// Values for RFMXTDSCDMA_ATTR_MODACC_RRC_FILTER_ENABLED
#define RFMXTDSCDMA_VAL_MODACC_RRC_FILTER_ENABLED_FALSE                                                0
#define RFMXTDSCDMA_VAL_MODACC_RRC_FILTER_ENABLED_TRUE                                                 1

// Values for RFMXTDSCDMA_ATTR_MODACC_RESULTS_DETECTED_MODULATION_TYPE
#define RFMXTDSCDMA_VAL_MODACC_DETECTED_MODULATION_TYPE_QPSK                                           0
#define RFMXTDSCDMA_VAL_MODACC_DETECTED_MODULATION_TYPE_8PSK                                           1
#define RFMXTDSCDMA_VAL_MODACC_DETECTED_MODULATION_TYPE_16QAM                                          2

// Values for RFMXTDSCDMA_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXTDSCDMA_VAL_ACP_RBW_AUTO_FALSE                                                             0
#define RFMXTDSCDMA_VAL_ACP_RBW_AUTO_TRUE                                                              1

// Values for RFMXTDSCDMA_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXTDSCDMA_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXTDSCDMA_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXTDSCDMA_VAL_ACP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXTDSCDMA_ATTR_ACP_SWEEP_TIME_AUTO
#define RFMXTDSCDMA_VAL_ACP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXTDSCDMA_VAL_ACP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXTDSCDMA_ATTR_ACP_MEASUREMENT_METHOD
#define RFMXTDSCDMA_VAL_ACP_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXTDSCDMA_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1
#define RFMXTDSCDMA_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                          2

// Values for RFMXTDSCDMA_ATTR_ACP_NOISE_COMPENSATION_ENABLED
#define RFMXTDSCDMA_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXTDSCDMA_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXTDSCDMA_ATTR_ACP_AVERAGING_ENABLED
#define RFMXTDSCDMA_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXTDSCDMA_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXTDSCDMA_ATTR_ACP_AVERAGING_TYPE
#define RFMXTDSCDMA_VAL_ACP_AVERAGING_TYPE_RMS                                                         0
#define RFMXTDSCDMA_VAL_ACP_AVERAGING_TYPE_LOG                                                         1
#define RFMXTDSCDMA_VAL_ACP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXTDSCDMA_VAL_ACP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXTDSCDMA_VAL_ACP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXTDSCDMA_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXTDSCDMA_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                          0
#define RFMXTDSCDMA_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                           1

// Values for RFMXTDSCDMA_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXTDSCDMA_VAL_CHP_RBW_AUTO_FALSE                                                             0
#define RFMXTDSCDMA_VAL_CHP_RBW_AUTO_TRUE                                                              1

// Values for RFMXTDSCDMA_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXTDSCDMA_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXTDSCDMA_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXTDSCDMA_VAL_CHP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXTDSCDMA_ATTR_CHP_SWEEP_TIME_AUTO
#define RFMXTDSCDMA_VAL_CHP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXTDSCDMA_VAL_CHP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXTDSCDMA_ATTR_CHP_AVERAGING_ENABLED
#define RFMXTDSCDMA_VAL_CHP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXTDSCDMA_VAL_CHP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXTDSCDMA_ATTR_CHP_AVERAGING_TYPE
#define RFMXTDSCDMA_VAL_CHP_AVERAGING_TYPE_RMS                                                         0
#define RFMXTDSCDMA_VAL_CHP_AVERAGING_TYPE_LOG                                                         1
#define RFMXTDSCDMA_VAL_CHP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXTDSCDMA_VAL_CHP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXTDSCDMA_VAL_CHP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXTDSCDMA_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXTDSCDMA_VAL_OBW_RBW_AUTO_FALSE                                                             0
#define RFMXTDSCDMA_VAL_OBW_RBW_AUTO_TRUE                                                              1

// Values for RFMXTDSCDMA_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXTDSCDMA_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXTDSCDMA_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXTDSCDMA_VAL_OBW_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXTDSCDMA_ATTR_OBW_SWEEP_TIME_AUTO
#define RFMXTDSCDMA_VAL_OBW_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXTDSCDMA_VAL_OBW_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXTDSCDMA_ATTR_OBW_AVERAGING_ENABLED
#define RFMXTDSCDMA_VAL_OBW_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXTDSCDMA_VAL_OBW_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXTDSCDMA_ATTR_OBW_AVERAGING_TYPE
#define RFMXTDSCDMA_VAL_OBW_AVERAGING_TYPE_RMS                                                         0
#define RFMXTDSCDMA_VAL_OBW_AVERAGING_TYPE_LOG                                                         1
#define RFMXTDSCDMA_VAL_OBW_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXTDSCDMA_VAL_OBW_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXTDSCDMA_VAL_OBW_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXTDSCDMA_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXTDSCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FFT_BASED                                           0
#define RFMXTDSCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN                                            1
#define RFMXTDSCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FLAT                                                2
#define RFMXTDSCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_4                                       3
#define RFMXTDSCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_5                                       4

// Values for RFMXTDSCDMA_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXTDSCDMA_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXTDSCDMA_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXTDSCDMA_ATTR_SEM_AVERAGING_ENABLED
#define RFMXTDSCDMA_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXTDSCDMA_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXTDSCDMA_ATTR_SEM_AVERAGING_TYPE
#define RFMXTDSCDMA_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXTDSCDMA_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXTDSCDMA_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXTDSCDMA_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXTDSCDMA_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXTDSCDMA_ATTR_SEM_RESULTS_MEASUREMENT_STATUS
#define RFMXTDSCDMA_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXTDSCDMA_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXTDSCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXTDSCDMA_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXTDSCDMA_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXTDSCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXTDSCDMA_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXTDSCDMA_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXTDSCDMA_ATTR_CDA_AVERAGING_ENABLED
#define RFMXTDSCDMA_VAL_CDA_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXTDSCDMA_VAL_CDA_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXTDSCDMA_ATTR_CDA_SYNCHRONIZATION_MODE
#define RFMXTDSCDMA_VAL_CDA_SYNCHRONIZATION_MODE_SLOT                                                  0

// Values for RFMXTDSCDMA_ATTR_CDA_SPECTRUM_INVERTED
#define RFMXTDSCDMA_VAL_CDA_SPECTRUM_INVERTED_FALSE                                                    0
#define RFMXTDSCDMA_VAL_CDA_SPECTRUM_INVERTED_TRUE                                                     1

// Values for RFMXTDSCDMA_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXTDSCDMA_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                            0
#define RFMXTDSCDMA_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                             1

// Values for RFMXTDSCDMA_ATTR_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXTDSCDMA_VAL_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                    0
#define RFMXTDSCDMA_VAL_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                     1

// Values for RFMXTDSCDMA_ATTR_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXTDSCDMA_VAL_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                                  0
#define RFMXTDSCDMA_VAL_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                   1

// Values for RFMXTDSCDMA_ATTR_CDA_POWER_UNIT
#define RFMXTDSCDMA_VAL_CDA_POWER_UNIT_DB                                                              0
#define RFMXTDSCDMA_VAL_CDA_POWER_UNIT_DBM                                                             1

// Values for RFMXTDSCDMA_ATTR_CDA_RRC_FILTER_ENABLED
#define RFMXTDSCDMA_VAL_CDA_RRC_FILTER_ENABLED_FALSE                                                   0
#define RFMXTDSCDMA_VAL_CDA_RRC_FILTER_ENABLED_TRUE                                                    1

// Values for RFMXTDSCDMA_ATTR_PVT_MEASUREMENT_METHOD
#define RFMXTDSCDMA_VAL_PVT_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXTDSCDMA_VAL_PVT_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1

// Values for RFMXTDSCDMA_ATTR_PVT_RRC_FILTER_ENABLED
#define RFMXTDSCDMA_VAL_PVT_RRC_FILTER_ENABLED_FALSE                                                   0
#define RFMXTDSCDMA_VAL_PVT_RRC_FILTER_ENABLED_TRUE                                                    1

// Values for RFMXTDSCDMA_ATTR_PVT_AVERAGING_ENABLED
#define RFMXTDSCDMA_VAL_PVT_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXTDSCDMA_VAL_PVT_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXTDSCDMA_ATTR_PVT_AVERAGING_TYPE
#define RFMXTDSCDMA_VAL_PVT_AVERAGING_TYPE_RMS                                                         0
#define RFMXTDSCDMA_VAL_PVT_AVERAGING_TYPE_LOG                                                         1

// Values for RFMXTDSCDMA_ATTR_PVT_RESULTS_MEASUREMENT_STATUS
#define RFMXTDSCDMA_VAL_PVT_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXTDSCDMA_VAL_PVT_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXTDSCDMA_ATTR_PVT_RESULTS_SEGMENT_STATUS
#define RFMXTDSCDMA_VAL_PVT_SEGMENT_STATUS_FAIL                                                        0
#define RFMXTDSCDMA_VAL_PVT_SEGMENT_STATUS_PASS                                                        1

// Values for RFMXTDSCDMA_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXTDSCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXTDSCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXTDSCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXTDSCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXTDSCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXTDSCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Boolean
#define RFMXTDSCDMA_VAL_FALSE                                                                          0
#define RFMXTDSCDMA_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXTDSCDMA_VAL_MODACC                                                                         1 << 0
#define RFMXTDSCDMA_VAL_ACP                                                                            1 << 1
#define RFMXTDSCDMA_VAL_CHP                                                                            1 << 2
#define RFMXTDSCDMA_VAL_OBW                                                                            1 << 3
#define RFMXTDSCDMA_VAL_SEM                                                                            1 << 4
#define RFMXTDSCDMA_VAL_CDA                                                                            1 << 5
#define RFMXTDSCDMA_VAL_PVT                                                                            1 << 6
#define RFMXTDSCDMA_VAL_SLOTPOWER                                                                      1 << 7

// Values for FrequencyReferenceSource
#define RFMXTDSCDMA_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXTDSCDMA_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXTDSCDMA_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXTDSCDMA_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for RFAttenuationAuto
#define RFMXTDSCDMA_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXTDSCDMA_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXTDSCDMA_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXTDSCDMA_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

// Values for RFMXTDSCDMA_ATTR_MODACC_SLOT_TYPE
#define RFMXTDSCDMA_VAL_MODACC_SLOT_TYPE_TRAFFIC                                                       0
#define RFMXTDSCDMA_VAL_MODACC_SLOT_TYPE_PILOT                                                         1

// Values for RFMXTDSCDMA_ATTR_SLOTPOWER_SPECTRUM_INVERTED
#define RFMXTDSCDMA_VAL_SLOTPOWER_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXTDSCDMA_VAL_SLOTPOWER_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXTDSCDMA_ATTR_SLOTPOWER_RRC_FILTER_ENABLED
#define RFMXTDSCDMA_VAL_SLOTPOWER_RRC_FILTER_ENABLED_FALSE                                             0
#define RFMXTDSCDMA_VAL_SLOTPOWER_RRC_FILTER_ENABLED_TRUE                                              1

// Values for RFMXTDSCDMA_ATTR_ACP_FFT_OVERLAP_MODE
#define RFMXTDSCDMA_VAL_ACP_FFT_OVERLAP_MODE_DISABLED                                                  0
#define RFMXTDSCDMA_VAL_ACP_FFT_OVERLAP_MODE_AUTOMATIC                                                 1

/* ---------------- RFmxTDSCDMA APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxTDSCDMA_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxTDSCDMA_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxTDSCDMA_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxTDSCDMA_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxTDSCDMA_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxTDSCDMA_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxTDSCDMA_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxTDSCDMA_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxTDSCDMA_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxTDSCDMA_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxTDSCDMA_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxTDSCDMA_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxTDSCDMA_BuildChannelString(
   char selectorString[],
   int32 channelNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxTDSCDMA_BuildSegmentString(
   char selectorString[],
   int32 segmentNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxTDSCDMA_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxTDSCDMA_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxTDSCDMA_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxTDSCDMA_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* done
);

int32 __stdcall RFmxTDSCDMA_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxTDSCDMA_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxTDSCDMA_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxTDSCDMA_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxTDSCDMA_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxTDSCDMA_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxTDSCDMA_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxTDSCDMA_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxTDSCDMA_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxTDSCDMA_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxTDSCDMA_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxTDSCDMA_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxTDSCDMA_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxTDSCDMA_CfgMidambleShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 midambleAutoDetectionMode,
   int32 maximumNumberOfUsers,
   int32 midambleShift
);

int32 __stdcall RFmxTDSCDMA_CfgChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelConfigurationMode
);

int32 __stdcall RFmxTDSCDMA_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxTDSCDMA_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxTDSCDMA_CfgNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfChannels
);

int32 __stdcall RFmxTDSCDMA_CfgUplinkScramblingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkScramblingCode
);

int32 __stdcall RFmxTDSCDMA_CfgUserDefinedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 slotIndex,
   int32 channelType,
   int32 slotFormat,
   int32 modulationType,
   int32 channelizationCode
);

int32 __stdcall RFmxTDSCDMA_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxTDSCDMA_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxTDSCDMA_CfgPilot(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 pilotCode
);

int32 __stdcall RFmxTDSCDMA_CfgUserDefinedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 slotIndex[],
   int32 channelType[],
   int32 slotFormat[],
   int32 modulationType[],
   int32 channelizationCode[],
   int32 numberOfElements
);

int32 __stdcall RFmxTDSCDMA_ModAccCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxTDSCDMA_ModAccCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxTDSCDMA_ModAccCfgSlotType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 slotType
);

int32 __stdcall RFmxTDSCDMA_PVTCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxTDSCDMA_PVTCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxTDSCDMA_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxTDSCDMA_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxTDSCDMA_CHPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxTDSCDMA_CHPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxTDSCDMA_CHPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxTDSCDMA_OBWCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxTDSCDMA_OBWCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxTDSCDMA_OBWCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxTDSCDMA_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxTDSCDMA_ACPCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxTDSCDMA_ACPCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxTDSCDMA_ACPCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxTDSCDMA_ACPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxTDSCDMA_ACPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxTDSCDMA_CDACfgSynchronizationModeAndOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset
);

int32 __stdcall RFmxTDSCDMA_CDACfgMeasurementChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spreadingFactor,
   int32 channelizationCode
);

int32 __stdcall RFmxTDSCDMA_CDACfgPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnit
);

int32 __stdcall RFmxTDSCDMA_CDACfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxTDSCDMA_SlotPowerCfgMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementLength
);

int32 __stdcall RFmxTDSCDMA_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxTDSCDMA_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxTDSCDMA_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxTDSCDMA_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxTDSCDMA_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxTDSCDMA_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxTDSCDMA_CfgFrequencyChannelNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelNumber
);

int32 __stdcall RFmxTDSCDMA_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMeanSymbolEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 meanSymbolEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMeanSymbolMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 meanSymbolMagnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMeanSymbolPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 meanSymbolPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchSymbolConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle symbolConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchSymbolConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMeanCodeDomainPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 meanCodeDomainPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMaximumSymbolEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 maximumSymbolEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMaximumSymbolMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 maximumSymbolMagnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMaximumSymbolPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 maximumSymbolPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchMaximumCodeDomainPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 maximumCodeDomainPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CDAFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffset,
   float64* IQGainImbalance,
   float64* IQQuadratureError
);

int32 __stdcall RFmxTDSCDMA_CDAFetchCodeDomainPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanTotalPower,
   float64* meanTotalActivePower,
   float64* meanActivePower,
   float64* maximumPeakActivePower,
   float64* meanInactivePower,
   float64* maximumPeakInactivePower
);

int32 __stdcall RFmxTDSCDMA_CDAFetchSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSSymbolEVM,
   float64* maximumPeakSymbolEVM,
   float64* frequencyError,
   float64* chipRateError,
   float64* meanRMSSymbolMagnitudeError,
   float64* meanRMSSymbolPhaseError,
   float64* meanSymbolPower
);

int32 __stdcall RFmxTDSCDMA_ACPFetchOffsetMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 lowerRelativePower[],
   float64 upperRelativePower[],
   float64 lowerAbsolutePower[],
   float64 upperAbsolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ACPFetchAbsolutePowersTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 traceIndex,
   float64* x0,
   float64* dx,
   float32 absolutePowersTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ACPFetchRelativePowersTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 traceIndex,
   float64* x0,
   float64* dx,
   float32 relativePowersTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ACPFetchCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsolutePower
);

int32 __stdcall RFmxTDSCDMA_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower
);

int32 __stdcall RFmxTDSCDMA_OBWFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_OBWFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* absolutePower,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxTDSCDMA_PVTFetchSegmentMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 segmentStatus[],
   float64 segmentMargin[],
   float64 segmentMarginTime[],
   float64 segmentMeanAbsolutePower[],
   float64 segmentMaximumAbsolutePower[],
   float64 segmentMinimumAbsolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_PVTFetchSignalPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 signalPower[],
   float32 absoluteLimit[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_PVTFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxTDSCDMA_PVTFetchPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanAbsoluteONPower,
   float64* meanAbsoluteOFFPower
);

int32 __stdcall RFmxTDSCDMA_PVTFetchSegmentMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* segmentStatus,
   float64* segmentMargin,
   float64* segmentMarginTime,
   float64* segmentMeanAbsolutePower,
   float64* segmentMaximumAbsolutePower,
   float64* segmentMinimumAbsolutePower
);

int32 __stdcall RFmxTDSCDMA_CHPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_CHPFetchCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsolutePower
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchDetectedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 detectedSlotIndex[],
   int32 detectedSpreadingFactor[],
   int32 detectedModulationType[],
   int32 detectedChannelizationCode[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchCodeDomainErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 codeDomainError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchMaximumEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchMaximumMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumMagnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchMaximumPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchMaximumCodeDomainErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 maximumCodeDomainError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchDetectedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* detectedSlotIndex,
   int32* detectedSpreadingFactor,
   int32* detectedModulationType,
   int32* detectedChannelizationCode
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSDataEVM,
   float64* peakDataEVM,
   float64* dataRho,
   float64* RMSDataMagnitudeError,
   float64* RMSDataPhaseError
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchMidambleAndDataPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* midamblePower,
   float64* dataField1Power,
   float64* dataField2Power
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffset,
   float64* IQGainImbalance,
   float64* IQQuadratureError
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* numberOfDetectedChannels
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchCompositeEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSCompositeEVM,
   float64* peakCompositeEVM,
   float64* compositeRho,
   float64* frequencyError,
   float64* chipRateError,
   float64* RMSCompositeMagnitudeError,
   float64* RMSCompositePhaseError
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchMidambleEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSMidambleEVM,
   float64* peakMidambleEVM,
   float64* midambleRho,
   float64* RMSMidambleMagnitudeError,
   float64* RMSMidamblePhaseError
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchDataCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumPeakDataCDE,
   int32* peakDataCDESpreadingFactor,
   int32* peakDataCDECode
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchDataActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumPeakDataActiveCDE,
   int32* peakDataActiveCDESpreadingFactor,
   int32* peakDataActiveCDECode,
   int32* peakDataActiveCDENumberOfChannels
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchDataRCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumPeakDataRCDE,
   int32* peakDataRCDESpreadingFactor,
   int32* peakDataRCDECode
);

int32 __stdcall RFmxTDSCDMA_ModAccFetchPilotEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSPilotEVM,
   float64* peakPilotEVM,
   float64* pilotRho,
   float64* RMSPilotMagnitudeError,
   float64* RMSPilotPhaseError
);

int32 __stdcall RFmxTDSCDMA_SEMFetchLowerOffsetMarginArray(
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

int32 __stdcall RFmxTDSCDMA_SEMFetchLowerOffsetPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absoluteIntegratedPower[],
   float64 relativeIntegratedPower[],
   float64 absolutePeakPower[],
   float64 peakFrequency[],
   float64 relativePeakPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SEMFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   float32 relativeMask[],
   float32 absoluteMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SEMFetchUpperOffsetMarginArray(
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

int32 __stdcall RFmxTDSCDMA_SEMFetchUpperOffsetPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absoluteIntegratedPower[],
   float64 relativeIntegratedPower[],
   float64 absolutePeakPower[],
   float64 peakFrequency[],
   float64 relativePeakPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_SEMFetchCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsoluteIntegratedPower
);

int32 __stdcall RFmxTDSCDMA_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxTDSCDMA_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxTDSCDMA_SEMFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxTDSCDMA_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxTDSCDMA_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxTDSCDMA_SlotPowerFetchPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 slotPower[],
   float64 slotPowerDelta[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxTDSCDMA_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSCompositeEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakCompositeEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSCompositeMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSCompositePhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsCompositeRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMaximumCompositeRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSMidambleEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakMidambleEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSMidambleMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSMidamblePhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMidambleRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMidamblePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMidambleCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMidambleShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSDataMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSDataPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsDataRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMaximumPeakDataCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataCDESpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataCDECode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMaximumPeakDataActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataActiveCDESpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataActiveCDECode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataActiveCDENumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataRCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsMaximumPeakDataRCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataRCDESpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakDataRCDECode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsDataField1Power(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsDataField2Power(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsDetectedSlotIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsDetectedSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsDetectedModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsDetectedChannelizationCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetSlotType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccSetSlotType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSPilotEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPeakPilotEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSPilotMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsRMSPilotPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ModAccGetResultsPilotRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_ACPGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CHPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetResultsOccupiedBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetResultsAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetResultsStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_OBWGetResultsStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetBaseSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetBaseSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetMeasurementChannelSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetMeasurementChannelSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetMeasurementChannelChannelizationCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetMeasurementChannelChannelizationCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDASetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanSymbolPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanRMSSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMaximumPeakSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanRMSSymbolMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanRMSSymbolPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanTotalPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMaximumTotalPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanTotalActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMaximumTotalActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMaximumPeakActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMeanInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_CDAGetResultsMaximumPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetSegmentStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetSegmentStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsMeanAbsoluteONPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsMeanAbsoluteOFFPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsMaximumAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsMinimumAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsBurstWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsSegmentStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsSegmentMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsSegmentMarginTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsSegmentMeanAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsSegmentMaximumAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsSegmentMinimumAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsMidambleCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_PVTGetResultsMidambleShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetChannelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetChannelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetSlotIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetSlotIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetSlotFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetSlotFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetChannelizationCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetChannelizationCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetUplinkScramblingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetUplinkScramblingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetMidambleAutoDetectionMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetMidambleAutoDetectionMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetMaximumNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetMaximumNumberOfUsers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetMidambleShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetMidambleShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetPilotCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetPilotCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxTDSCDMA_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SlotPowerSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#define RFMXTDSCDMA_ATTR_MIDAMBLE_CODE                                               0x00711008

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxTDSCDMA_CfgMidamble(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 midambleAutoDetectionMode,
   int32 midambleCode,
   int32 midambleShift
);

int32 __stdcall RFmxTDSCDMA_GetMidambleCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxTDSCDMA_SetMidambleCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxTDSCDMA_AnalyzeIQ(
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

int32 __stdcall RFmxTDSCDMA_AnalyzeIQSplit(
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

int32 __stdcall RFmxTDSCDMA_AnalyzeSpectrum(
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

#ifdef __cplusplus
}
#endif


#endif

