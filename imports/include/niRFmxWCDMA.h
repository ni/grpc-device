
/****************************************************************************************************
*          National Instruments RFmx WCDMA
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxWCDMA.h
*
* Purpose:  National Instruments RFmx WCDMA,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_WCDMA_H__
#define __NI_RFMX_WCDMA_H__

#include "niRFmxInstr.h"

#define RFMXWCDMA_ATTR_MODACC_MEASUREMENT_ENABLED                                     0x00511000
#define RFMXWCDMA_ATTR_MODACC_SYNCHRONIZATION_MODE                                    0x00511002
#define RFMXWCDMA_ATTR_MODACC_MEASUREMENT_OFFSET                                      0x00511003
#define RFMXWCDMA_ATTR_MODACC_MEASUREMENT_LENGTH                                      0x00511004
#define RFMXWCDMA_ATTR_MODACC_SPECTRUM_INVERTED                                       0x00511005
#define RFMXWCDMA_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED                               0x00511006
#define RFMXWCDMA_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                       0x0051103c
#define RFMXWCDMA_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED                     0x0051103d
#define RFMXWCDMA_ATTR_MODACC_TRANSIENT_REMOVAL_ENABLED                               0x00511007
#define RFMXWCDMA_ATTR_MODACC_RRC_FILTER_ENABLED                                      0x0051103b
#define RFMXWCDMA_ATTR_MODACC_ALL_TRACES_ENABLED                                      0x00511008
#define RFMXWCDMA_ATTR_MODACC_DOWNLINK_TIMING_CHANNEL_SPREADING_FACTOR                0x00511009
#define RFMXWCDMA_ATTR_MODACC_DOWNLINK_TIMING_CHANNEL_CODE                            0x0051100a
#define RFMXWCDMA_ATTR_MODACC_RESULTS_RMS_EVM                                         0x00511011
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_EVM                                        0x00511012
#define RFMXWCDMA_ATTR_MODACC_RESULTS_RMS_MAGNITUDE_ERROR                             0x00511013
#define RFMXWCDMA_ATTR_MODACC_RESULTS_RMS_PHASE_ERROR                                 0x00511014
#define RFMXWCDMA_ATTR_MODACC_RESULTS_RHO                                             0x00511015
#define RFMXWCDMA_ATTR_MODACC_RESULTS_IQ_ORIGIN_OFFSET                                0x00511016
#define RFMXWCDMA_ATTR_MODACC_RESULTS_IQ_GAIN_IMBALANCE                               0x0051102d
#define RFMXWCDMA_ATTR_MODACC_RESULTS_IQ_QUADRATURE_ERROR                             0x0051102e
#define RFMXWCDMA_ATTR_MODACC_RESULTS_FREQUENCY_ERROR                                 0x00511017
#define RFMXWCDMA_ATTR_MODACC_RESULTS_CHIP_RATE_ERROR                                 0x00511018
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_CDE                                        0x00511019
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_CDE_CODE                                   0x0051101b
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_CDE_BRANCH                                 0x0051102a
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE                                 0x0051101c
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_SPREADING_FACTOR                0x0051101d
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_CODE                            0x0051101e
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_BRANCH                          0x0051102b
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PSCH_POWER                                      0x0051101f
#define RFMXWCDMA_ATTR_MODACC_RESULTS_SSCH_POWER                                      0x00511020
#define RFMXWCDMA_ATTR_MODACC_RESULTS_DPCH_TIMING_OFFSET                              0x00511021
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_RCDE                                       0x00511022
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_RCDE_SPREADING_FACTOR                      0x00511023
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_RCDE_CODE                                  0x00511024
#define RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_RCDE_BRANCH                                0x0051102c
#define RFMXWCDMA_ATTR_MODACC_RESULTS_NUMBER_OF_DETECTED_CHANNELS                     0x00511025
#define RFMXWCDMA_ATTR_MODACC_RESULTS_DETECTED_SPREADING_FACTOR                       0x00511026
#define RFMXWCDMA_ATTR_MODACC_RESULTS_DETECTED_SPREADING_CODE                         0x00511027
#define RFMXWCDMA_ATTR_MODACC_RESULTS_DETECTED_MODULATION_TYPE                        0x00511028
#define RFMXWCDMA_ATTR_MODACC_RESULTS_DETECTED_BRANCH                                 0x00511029
#define RFMXWCDMA_ATTR_ACP_MEASUREMENT_ENABLED                                        0x00501000
#define RFMXWCDMA_ATTR_ACP_CARRIER_INTEGRATION_BANDWIDTH                              0x00501005
#define RFMXWCDMA_ATTR_ACP_NUMBER_OF_OFFSETS                                          0x00501008
#define RFMXWCDMA_ATTR_ACP_OFFSET_FREQUENCY                                           0x0050100a
#define RFMXWCDMA_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER                             0x0050100c
#define RFMXWCDMA_ATTR_ACP_OFFSET_POWER_REFERENCE_SPECIFIC                            0x0050100d
#define RFMXWCDMA_ATTR_ACP_OFFSET_INTEGRATION_BANDWIDTH                               0x0050100e
#define RFMXWCDMA_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH                                  0x0050101b
#define RFMXWCDMA_ATTR_ACP_RBW_FILTER_BANDWIDTH                                       0x0050101c
#define RFMXWCDMA_ATTR_ACP_RBW_FILTER_TYPE                                            0x0050101d
#define RFMXWCDMA_ATTR_ACP_SWEEP_TIME_AUTO                                            0x0050101e
#define RFMXWCDMA_ATTR_ACP_SWEEP_TIME_INTERVAL                                        0x0050101f
#define RFMXWCDMA_ATTR_ACP_MEASUREMENT_METHOD                                         0x00501012
#define RFMXWCDMA_ATTR_ACP_NOISE_COMPENSATION_ENABLED                                 0x00501020
#define RFMXWCDMA_ATTR_ACP_AVERAGING_ENABLED                                          0x00501016
#define RFMXWCDMA_ATTR_ACP_AVERAGING_COUNT                                            0x00501015
#define RFMXWCDMA_ATTR_ACP_AVERAGING_TYPE                                             0x00501018
#define RFMXWCDMA_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO                                0x00501034
#define RFMXWCDMA_ATTR_ACP_NEAR_IF_OUTPUT_POWER_OFFSET                                0x00501035
#define RFMXWCDMA_ATTR_ACP_FAR_IF_OUTPUT_POWER_OFFSET                                 0x00501036
#define RFMXWCDMA_ATTR_ACP_ALL_TRACES_ENABLED                                         0x00501021
#define RFMXWCDMA_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                                 0x00501014
#define RFMXWCDMA_ATTR_ACP_RESULTS_TOTAL_CARRIER_POWER                                0x00501022
#define RFMXWCDMA_ATTR_ACP_RESULTS_CARRIER_ABSOLUTE_POWER                             0x00501026
#define RFMXWCDMA_ATTR_ACP_RESULTS_CARRIER_RELATIVE_POWER                             0x00501027
#define RFMXWCDMA_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                        0x0050102c
#define RFMXWCDMA_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                        0x0050102d
#define RFMXWCDMA_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                        0x00501032
#define RFMXWCDMA_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                        0x00501033
#define RFMXWCDMA_ATTR_CHP_MEASUREMENT_ENABLED                                        0x00503000
#define RFMXWCDMA_ATTR_CHP_CARRIER_INTEGRATION_BANDWIDTH                              0x00503002
#define RFMXWCDMA_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH                                  0x0050300c
#define RFMXWCDMA_ATTR_CHP_RBW_FILTER_BANDWIDTH                                       0x0050300d
#define RFMXWCDMA_ATTR_CHP_RBW_FILTER_TYPE                                            0x0050300e
#define RFMXWCDMA_ATTR_CHP_SWEEP_TIME_AUTO                                            0x00503011
#define RFMXWCDMA_ATTR_CHP_SWEEP_TIME_INTERVAL                                        0x00503012
#define RFMXWCDMA_ATTR_CHP_AVERAGING_ENABLED                                          0x00503007
#define RFMXWCDMA_ATTR_CHP_AVERAGING_COUNT                                            0x00503006
#define RFMXWCDMA_ATTR_CHP_AVERAGING_TYPE                                             0x00503009
#define RFMXWCDMA_ATTR_CHP_ALL_TRACES_ENABLED                                         0x00503014
#define RFMXWCDMA_ATTR_CHP_NUMBER_OF_ANALYSIS_THREADS                                 0x00503003
#define RFMXWCDMA_ATTR_CHP_RESULTS_TOTAL_CARRIER_POWER                                0x00503018
#define RFMXWCDMA_ATTR_CHP_RESULTS_CARRIER_ABSOLUTE_POWER                             0x00503015
#define RFMXWCDMA_ATTR_CHP_RESULTS_CARRIER_RELATIVE_POWER                             0x00503019
#define RFMXWCDMA_ATTR_OBW_MEASUREMENT_ENABLED                                        0x00506000
#define RFMXWCDMA_ATTR_OBW_SPAN                                                       0x00506004
#define RFMXWCDMA_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH                                  0x0050600c
#define RFMXWCDMA_ATTR_OBW_RBW_FILTER_BANDWIDTH                                       0x0050600d
#define RFMXWCDMA_ATTR_OBW_RBW_FILTER_TYPE                                            0x0050600e
#define RFMXWCDMA_ATTR_OBW_SWEEP_TIME_AUTO                                            0x0050600f
#define RFMXWCDMA_ATTR_OBW_SWEEP_TIME_INTERVAL                                        0x00506010
#define RFMXWCDMA_ATTR_OBW_AVERAGING_ENABLED                                          0x00506007
#define RFMXWCDMA_ATTR_OBW_AVERAGING_COUNT                                            0x00506006
#define RFMXWCDMA_ATTR_OBW_AVERAGING_TYPE                                             0x00506009
#define RFMXWCDMA_ATTR_OBW_ALL_TRACES_ENABLED                                         0x00506012
#define RFMXWCDMA_ATTR_OBW_NUMBER_OF_ANALYSIS_THREADS                                 0x00506003
#define RFMXWCDMA_ATTR_OBW_RESULTS_OCCUPIED_BANDWIDTH                                 0x00506013
#define RFMXWCDMA_ATTR_OBW_RESULTS_ABSOLUTE_POWER                                     0x00506014
#define RFMXWCDMA_ATTR_OBW_RESULTS_START_FREQUENCY                                    0x00506015
#define RFMXWCDMA_ATTR_OBW_RESULTS_STOP_FREQUENCY                                     0x00506016
#define RFMXWCDMA_ATTR_SEM_MEASUREMENT_ENABLED                                        0x00508000
#define RFMXWCDMA_ATTR_SEM_CARRIER_INTEGRATION_BANDWIDTH                              0x00508005
#define RFMXWCDMA_ATTR_SEM_NUMBER_OF_OFFSETS                                          0x0050800b
#define RFMXWCDMA_ATTR_SEM_OFFSET_START_FREQUENCY                                     0x00508014
#define RFMXWCDMA_ATTR_SEM_OFFSET_STOP_FREQUENCY                                      0x00508015
#define RFMXWCDMA_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH                                0x00508017
#define RFMXWCDMA_ATTR_SEM_OFFSET_RBW_FILTER_TYPE                                     0x00508018
#define RFMXWCDMA_ATTR_SEM_OFFSET_BANDWIDTH_INTEGRAL                                  0x0050800c
#define RFMXWCDMA_ATTR_SEM_SWEEP_TIME_AUTO                                            0x00508025
#define RFMXWCDMA_ATTR_SEM_SWEEP_TIME_INTERVAL                                        0x00508026
#define RFMXWCDMA_ATTR_SEM_AVERAGING_ENABLED                                          0x0050801f
#define RFMXWCDMA_ATTR_SEM_AVERAGING_COUNT                                            0x0050801e
#define RFMXWCDMA_ATTR_SEM_AVERAGING_TYPE                                             0x00508021
#define RFMXWCDMA_ATTR_SEM_ALL_TRACES_ENABLED                                         0x00508027
#define RFMXWCDMA_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                                 0x0050801d
#define RFMXWCDMA_ATTR_SEM_RESULTS_TOTAL_CARRIER_POWER                                0x00508028
#define RFMXWCDMA_ATTR_SEM_RESULTS_MEASUREMENT_STATUS                                 0x00508029
#define RFMXWCDMA_ATTR_SEM_RESULTS_CARRIER_RELATIVE_INTEGRATED_POWER                  0x0050802e
#define RFMXWCDMA_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_INTEGRATED_POWER                  0x0050802d
#define RFMXWCDMA_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_PEAK_POWER                        0x0050802f
#define RFMXWCDMA_ATTR_SEM_RESULTS_CARRIER_PEAK_FREQUENCY                             0x00508030
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS                    0x0050803d
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER             0x00508034
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_INTEGRATED_POWER             0x00508035
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER                   0x00508036
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_PEAK_POWER                   0x00508037
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                        0x00508038
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                                0x00508039
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER                 0x0050803a
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER                 0x0050803b
#define RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY                      0x0050803c
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS                    0x0050804a
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER             0x00508041
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_INTEGRATED_POWER             0x00508042
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER                   0x00508043
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_PEAK_POWER                   0x00508044
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                        0x00508045
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                                0x00508046
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER                 0x00508047
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER                 0x00508048
#define RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY                      0x00508049
#define RFMXWCDMA_ATTR_QEVM_MEASUREMENT_ENABLED                                       0x00512000
#define RFMXWCDMA_ATTR_QEVM_MEASUREMENT_LENGTH                                        0x00512003
#define RFMXWCDMA_ATTR_QEVM_AVERAGING_ENABLED                                         0x00512005
#define RFMXWCDMA_ATTR_QEVM_AVERAGING_COUNT                                           0x00512006
#define RFMXWCDMA_ATTR_QEVM_SPECTRUM_INVERTED                                         0x00512007
#define RFMXWCDMA_ATTR_QEVM_IQ_OFFSET_REMOVAL_ENABLED                                 0x00512008
#define RFMXWCDMA_ATTR_QEVM_RRC_FILTER_ENABLED                                        0x0051200b
#define RFMXWCDMA_ATTR_QEVM_ALL_TRACES_ENABLED                                        0x0051200c
#define RFMXWCDMA_ATTR_QEVM_NUMBER_OF_ANALYSIS_THREADS                                0x0051200d
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MEAN_RMS_EVM                                      0x0051200e
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MAXIMUM_RMS_EVM                                   0x0051200f
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MEAN_PEAK_EVM                                     0x00512010
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MAXIMUM_PEAK_EVM                                  0x00512011
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MEAN_MAGNITUDE_ERROR                              0x00512012
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MAXIMUM_MAGNITUDE_ERROR                           0x00512013
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MEAN_PHASE_ERROR                                  0x00512014
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MAXIMUM_PHASE_ERROR                               0x00512015
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MEAN_FREQUENCY_ERROR                              0x00512016
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MAXIMUM_FREQUENCY_ERROR                           0x00512017
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MEAN_IQ_ORIGIN_OFFSET                             0x00512018
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MAXIMUM_IQ_ORIGIN_OFFSET                          0x00512019
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MEAN_CHIP_RATE_ERROR                              0x0051201a
#define RFMXWCDMA_ATTR_QEVM_RESULTS_MAXIMUM_CHIP_RATE_ERROR                           0x0051201b
#define RFMXWCDMA_ATTR_SLOTPHASE_MEASUREMENT_ENABLED                                  0x00514000
#define RFMXWCDMA_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE                                 0x00514002
#define RFMXWCDMA_ATTR_SLOTPHASE_MEASUREMENT_OFFSET                                   0x00514003
#define RFMXWCDMA_ATTR_SLOTPHASE_MEASUREMENT_LENGTH                                   0x00514004
#define RFMXWCDMA_ATTR_SLOTPHASE_SPECTRUM_INVERTED                                    0x00514007
#define RFMXWCDMA_ATTR_SLOTPHASE_TRANSIENT_REMOVAL_ENABLED                            0x00514008
#define RFMXWCDMA_ATTR_SLOTPHASE_RRC_FILTER_ENABLED                                   0x00514009
#define RFMXWCDMA_ATTR_SLOTPHASE_ALL_TRACES_ENABLED                                   0x0051400c
#define RFMXWCDMA_ATTR_SLOTPHASE_RESULTS_MAXIMUM_PHASE_DISCONTINUITY                  0x0051400e
#define RFMXWCDMA_ATTR_SLOTPHASE_RESULTS_DISCONTINUITY_COUNT_GREATER_THAN_LIMIT1      0x0051400f
#define RFMXWCDMA_ATTR_SLOTPHASE_RESULTS_DISCONTINUITY_COUNT_GREATER_THAN_LIMIT2      0x00514010
#define RFMXWCDMA_ATTR_SLOTPHASE_RESULTS_DISCONTINUITY_MINIMUM_DISTANCE               0x00514011
#define RFMXWCDMA_ATTR_LIMITED_CONFIGURATION_CHANGE                                   0x0050d003
#define RFMXWCDMA_ATTR_RESULT_FETCH_TIMEOUT                                           0x0050c000
#define RFMXWCDMA_ATTR_CENTER_FREQUENCY                                               0x00500001
#define RFMXWCDMA_ATTR_REFERENCE_LEVEL                                                0x00500002
#define RFMXWCDMA_ATTR_EXTERNAL_ATTENUATION                                           0x00500003
#define RFMXWCDMA_ATTR_TRIGGER_TYPE                                                   0x00500004
#define RFMXWCDMA_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                    0x00500005
#define RFMXWCDMA_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                      0x00500006
#define RFMXWCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                   0x00500007
#define RFMXWCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                    0x00500008
#define RFMXWCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                               0x00500fff
#define RFMXWCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                    0x00500009
#define RFMXWCDMA_ATTR_TRIGGER_DELAY                                                  0x0050000a
#define RFMXWCDMA_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                0x0050000b
#define RFMXWCDMA_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                            0x0050000c
#define RFMXWCDMA_ATTR_LINK_DIRECTION                                                 0x0050000d
#define RFMXWCDMA_ATTR_BAND                                                           0x00500020
#define RFMXWCDMA_ATTR_NUMBER_OF_CARRIERS                                             0x0050000e
#define RFMXWCDMA_ATTR_CARRIER_FREQUENCY                                              0x0050000f
#define RFMXWCDMA_ATTR_CHANNEL_CONFIGURATION_MODE                                     0x00500010
#define RFMXWCDMA_ATTR_NUMBER_OF_CHANNELS                                             0x00500014
#define RFMXWCDMA_ATTR_SPREADING_FACTOR                                               0x00500015
#define RFMXWCDMA_ATTR_SPREADING_CODE                                                 0x00500016
#define RFMXWCDMA_ATTR_MODULATION_TYPE                                                0x00500017
#define RFMXWCDMA_ATTR_BRANCH                                                         0x00500018
#define RFMXWCDMA_ATTR_UPLINK_TEST_MODEL                                              0x00500019
#define RFMXWCDMA_ATTR_DOWNLINK_TEST_MODEL                                            0x0050001a
#define RFMXWCDMA_ATTR_UPLINK_SCRAMBLING_TYPE                                         0x0050001b
#define RFMXWCDMA_ATTR_UPLINK_SCRAMBLING_CODE                                         0x0050001c
#define RFMXWCDMA_ATTR_DOWNLINK_SCRAMBLING_TYPE                                       0x0050001d
#define RFMXWCDMA_ATTR_DOWNLINK_SCRAMBLING_PRIMARY_CODE                               0x0050001e
#define RFMXWCDMA_ATTR_DOWNLINK_SCRAMBLING_SECONDARY_CODE                             0x0050001f
#define RFMXWCDMA_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                             0x0050d000
#define RFMXWCDMA_ATTR_CDA_MEASUREMENT_ENABLED                                        0x00515000
#define RFMXWCDMA_ATTR_CDA_SYNCHRONIZATION_MODE                                       0x00515002
#define RFMXWCDMA_ATTR_CDA_MEASUREMENT_OFFSET                                         0x00515003
#define RFMXWCDMA_ATTR_CDA_MEASUREMENT_LENGTH                                         0x00515004
#define RFMXWCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_SPREADING_FACTOR                       0x00515009
#define RFMXWCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_SPREADING_CODE                         0x0051500a
#define RFMXWCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_MODULATION_TYPE                        0x0051500b
#define RFMXWCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_BRANCH                                 0x0051500c
#define RFMXWCDMA_ATTR_CDA_POWER_UNIT                                                 0x0051500d
#define RFMXWCDMA_ATTR_CDA_SPECTRUM_INVERTED                                          0x00515005
#define RFMXWCDMA_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED                                  0x00515006
#define RFMXWCDMA_ATTR_CDA_RRC_FILTER_ENABLED                                         0x00515007
#define RFMXWCDMA_ATTR_CDA_ALL_TRACES_ENABLED                                         0x00515015
#define RFMXWCDMA_ATTR_CDA_RESULTS_RMS_SYMBOL_EVM                                     0x00515017
#define RFMXWCDMA_ATTR_CDA_RESULTS_PEAK_SYMBOL_EVM                                    0x00515018
#define RFMXWCDMA_ATTR_CDA_RESULTS_RMS_SYMBOL_MAGNITUDE_ERROR                         0x00515019
#define RFMXWCDMA_ATTR_CDA_RESULTS_RMS_SYMBOL_PHASE_ERROR                             0x0051501a
#define RFMXWCDMA_ATTR_CDA_RESULTS_MEAN_SYMBOL_POWER                                  0x0051501c
#define RFMXWCDMA_ATTR_CDA_RESULTS_CHIP_RATE_ERROR                                    0x0051502d
#define RFMXWCDMA_ATTR_CDA_RESULTS_TOTAL_POWER                                        0x0051501b
#define RFMXWCDMA_ATTR_CDA_RESULTS_TOTAL_ACTIVE_POWER                                 0x0051501f
#define RFMXWCDMA_ATTR_CDA_RESULTS_MEAN_ACTIVE_POWER                                  0x00515022
#define RFMXWCDMA_ATTR_CDA_RESULTS_PEAK_ACTIVE_POWER                                  0x00515021
#define RFMXWCDMA_ATTR_CDA_RESULTS_MEAN_INACTIVE_POWER                                0x00515024
#define RFMXWCDMA_ATTR_CDA_RESULTS_PEAK_INACTIVE_POWER                                0x00515023
#define RFMXWCDMA_ATTR_CDA_RESULTS_I_MEAN_ACTIVE_POWER                                0x00515029
#define RFMXWCDMA_ATTR_CDA_RESULTS_Q_MEAN_ACTIVE_POWER                                0x0051502a
#define RFMXWCDMA_ATTR_CDA_RESULTS_I_PEAK_INACTIVE_POWER                              0x0051502b
#define RFMXWCDMA_ATTR_CDA_RESULTS_Q_PEAK_INACTIVE_POWER                              0x0051502c
#define RFMXWCDMA_ATTR_SLOTPOWER_MEASUREMENT_ENABLED                                  0x00516000
#define RFMXWCDMA_ATTR_SLOTPOWER_SYNCHRONIZATION_MODE                                 0x00516007
#define RFMXWCDMA_ATTR_SLOTPOWER_MEASUREMENT_OFFSET                                   0x00516002
#define RFMXWCDMA_ATTR_SLOTPOWER_MEASUREMENT_LENGTH                                   0x00516003
#define RFMXWCDMA_ATTR_SLOTPOWER_SPECTRUM_INVERTED                                    0x00516004
#define RFMXWCDMA_ATTR_SLOTPOWER_RRC_FILTER_ENABLED                                   0x00516005
#define RFMXWCDMA_ATTR_MODACC_RESULTS_MULTI_CARRIER_IQ_ORIGIN_OFFSET                  0x0051102f
#define RFMXWCDMA_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE                                  0x00501038
#define RFMXWCDMA_ATTR_ACP_SEQUENTIAL_FFT_SIZE                                        0x00501039
#define RFMXWCDMA_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE                                  0x0050301b
#define RFMXWCDMA_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE                                  0x0050601a
#define RFMXWCDMA_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE                                  0x0050804c
#define RFMXWCDMA_ATTR_TRANSMITTER_ARCHITECTURE                                       0x0050d001
#define RFMXWCDMA_ATTR_SELECTED_PORTS                                                 0x00500ffd
#define RFMXWCDMA_ATTR_REFERENCE_LEVEL_HEADROOM                                       0x00500ffc
#define RFMXWCDMA_ATTR_ACP_FFT_OVERLAP_MODE                                           0x0050103a
#define RFMXWCDMA_ATTR_ACP_FFT_OVERLAP                                                0x0050103b

// Values for RFMXWCDMA_ATTR_TRIGGER_TYPE
#define RFMXWCDMA_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXWCDMA_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXWCDMA_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXWCDMA_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXWCDMA_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXWCDMA_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXWCDMA_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXWCDMA_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXWCDMA_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXWCDMA_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXWCDMA_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXWCDMA_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXWCDMA_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXWCDMA_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXWCDMA_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXWCDMA_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXWCDMA_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXWCDMA_VAL_TIMER_EVENT_STR                                                                "TimerEvent"
#define RFMXWCDMA_VAL_PULSE_IN_STR                                                                   "PulseIn"
#define RFMXWCDMA_VAL_DIO_PFI0_STR                                                                   "DIO/PFI0"
#define RFMXWCDMA_VAL_DIO_PFI1_STR                                                                   "DIO/PFI1"
#define RFMXWCDMA_VAL_DIO_PFI2_STR                                                                   "DIO/PFI2"
#define RFMXWCDMA_VAL_DIO_PFI3_STR                                                                   "DIO/PFI3"
#define RFMXWCDMA_VAL_DIO_PFI4_STR                                                                   "DIO/PFI4"
#define RFMXWCDMA_VAL_DIO_PFI5_STR                                                                   "DIO/PFI5"
#define RFMXWCDMA_VAL_DIO_PFI6_STR                                                                   "DIO/PFI6"
#define RFMXWCDMA_VAL_DIO_PFI7_STR                                                                   "DIO/PFI7"

// Values for RFMXWCDMA_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXWCDMA_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXWCDMA_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXWCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXWCDMA_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXWCDMA_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXWCDMA_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXWCDMA_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXWCDMA_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXWCDMA_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXWCDMA_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXWCDMA_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXWCDMA_ATTR_CHANNEL_CONFIGURATION_MODE
#define RFMXWCDMA_VAL_CHANNEL_CONFIGURATION_MODE_AUTO_DETECT                                         0
#define RFMXWCDMA_VAL_CHANNEL_CONFIGURATION_MODE_USER_DEFINED                                        1
#define RFMXWCDMA_VAL_CHANNEL_CONFIGURATION_MODE_TEST_MODEL                                          2

// Values for RFMXWCDMA_ATTR_MODULATION_TYPE
#define RFMXWCDMA_VAL_MODULATION_TYPE_BPSK_QPSK                                                      0
#define RFMXWCDMA_VAL_MODULATION_TYPE_4PAM_16QAM                                                     1
#define RFMXWCDMA_VAL_MODULATION_TYPE_64QAM                                                          2

// Values for RFMXWCDMA_ATTR_BRANCH
#define RFMXWCDMA_VAL_BRANCH_I                                                                       0
#define RFMXWCDMA_VAL_BRANCH_Q                                                                       1
#define RFMXWCDMA_VAL_BRANCH_I_AND_Q                                                                 2

// Values for RFMXWCDMA_ATTR_UPLINK_TEST_MODEL
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_2_1                                                      0
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_2_2                                                      1
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_2_3                                                      2
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_2_4                                                      3
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_2_5                                                      4
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_10_1_4_SUBTEST1                                          5
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_10_1_4_SUBTEST2                                          6
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_10_1_4_SUBTEST3                                          7
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_10_1_4_SUBTEST4                                          8
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_10_1_4_SUBTEST5                                          9
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R6C_10_1_4_SUBTEST6                                          10
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_10_1_4_SUBTEST1                                          11
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_10_1_4_SUBTEST2                                          12
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_10_1_4_SUBTEST3                                          13
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_10_1_4_SUBTEST4                                          14
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_11_1_3_SUBTEST1                                          15
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_11_1_3_SUBTEST2                                          16
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_11_1_3_SUBTEST3                                          17
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_11_1_3_SUBTEST4                                          18
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R7C_11_1_3_SUBTEST5                                          19
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R8C_11_1_3_SUBTEST1                                          20
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R8C_11_1_3_SUBTEST2                                          21
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R8C_11_1_3_SUBTEST3                                          22
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R8C_11_1_3_SUBTEST4                                          23
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R8C_11_1_3_SUBTEST5                                          24
#define RFMXWCDMA_VAL_UPLINK_TEST_MODEL_R8C_11_1_4_SUBTEST1                                          25

// Values for RFMXWCDMA_ATTR_DOWNLINK_TEST_MODEL
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_1_16DPCH                                        0
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_1_32DPCH                                        1
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_1_64DPCH                                        2
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_1_16DPCH_SCCPCH                                 3
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_1_32DPCH_SCCPCH                                 4
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_1_64DPCH_SCCPCH                                 5
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_2                                               6
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_2_SCCPCH                                        7
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_3_16DPCH                                        8
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_3_32DPCH                                        9
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_3_16DPCH_SCCPCH                                 10
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_3_32DPCH_SCCPCH                                 11
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_4                                               12
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_4_PCPICH                                        13
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_5_2HSPDSCH_16QAM                                14
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_5_4HSPDSCH_4DPCH_16QAM                          15
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_5_4HSPDSCH_14DPCH_16QAM                         16
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_5_8HSPDSCH_16QAM                                17
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_6_4HSPDSCH_64QAM                                18
#define RFMXWCDMA_VAL_DOWNLINK_TEST_MODEL_TEST_MODEL_6_8HSPDSCH_64QAM                                19

// Values for RFMXWCDMA_ATTR_UPLINK_SCRAMBLING_TYPE
#define RFMXWCDMA_VAL_UPLINK_SCRAMBLING_TYPE_LONG                                                    0
#define RFMXWCDMA_VAL_UPLINK_SCRAMBLING_TYPE_SHORT                                                   1

// Values for RFMXWCDMA_ATTR_DOWNLINK_SCRAMBLING_TYPE
#define RFMXWCDMA_VAL_DOWNLINK_SCRAMBLING_TYPE_STANDARD                                              0
#define RFMXWCDMA_VAL_DOWNLINK_SCRAMBLING_TYPE_LEFT                                                  1
#define RFMXWCDMA_VAL_DOWNLINK_SCRAMBLING_TYPE_RIGHT                                                 2

// Values for RFMXWCDMA_ATTR_MODACC_SYNCHRONIZATION_MODE
#define RFMXWCDMA_VAL_MODACC_SYNCHRONIZATION_MODE_FRAME                                              0
#define RFMXWCDMA_VAL_MODACC_SYNCHRONIZATION_MODE_SLOT                                               1
#define RFMXWCDMA_VAL_MODACC_SYNCHRONIZATION_MODE_ARBITRARY                                          2
#define RFMXWCDMA_VAL_MODACC_SYNCHRONIZATION_MODE_MARKER                                             3

// Values for RFMXWCDMA_ATTR_MODACC_SPECTRUM_INVERTED
#define RFMXWCDMA_VAL_MODACC_SPECTRUM_INVERTED_FALSE                                                 0
#define RFMXWCDMA_VAL_MODACC_SPECTRUM_INVERTED_TRUE                                                  1

// Values for RFMXWCDMA_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXWCDMA_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                         0
#define RFMXWCDMA_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                          1

// Values for RFMXWCDMA_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXWCDMA_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                 0
#define RFMXWCDMA_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                  1

// Values for RFMXWCDMA_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXWCDMA_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                               0
#define RFMXWCDMA_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                1

// Values for RFMXWCDMA_ATTR_MODACC_TRANSIENT_REMOVAL_ENABLED
#define RFMXWCDMA_VAL_MODACC_TRANSIENT_REMOVAL_ENABLED_FALSE                                         0
#define RFMXWCDMA_VAL_MODACC_TRANSIENT_REMOVAL_ENABLED_TRUE                                          1

// Values for RFMXWCDMA_ATTR_MODACC_RRC_FILTER_ENABLED
#define RFMXWCDMA_VAL_MODACC_RRC_FILTER_ENABLED_FALSE                                                0
#define RFMXWCDMA_VAL_MODACC_RRC_FILTER_ENABLED_TRUE                                                 1

// Values for RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_CDE_BRANCH
#define RFMXWCDMA_VAL_MODACC_PEAK_CDE_BRANCH_I                                                       0
#define RFMXWCDMA_VAL_MODACC_PEAK_CDE_BRANCH_Q                                                       1
#define RFMXWCDMA_VAL_MODACC_PEAK_CDE_BRANCH_I_AND_Q                                                 2

// Values for RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_BRANCH
#define RFMXWCDMA_VAL_MODACC_PEAK_ACTIVE_CDE_BRANCH_I                                                0
#define RFMXWCDMA_VAL_MODACC_PEAK_ACTIVE_CDE_BRANCH_Q                                                1
#define RFMXWCDMA_VAL_MODACC_PEAK_ACTIVE_CDE_BRANCH_I_AND_Q                                          2

// Values for RFMXWCDMA_ATTR_MODACC_RESULTS_PEAK_RCDE_BRANCH
#define RFMXWCDMA_VAL_MODACC_PEAK_RCDE_BRANCH_I                                                      0
#define RFMXWCDMA_VAL_MODACC_PEAK_RCDE_BRANCH_Q                                                      1
#define RFMXWCDMA_VAL_MODACC_PEAK_RCDE_BRANCH_I_AND_Q                                                2

// Values for RFMXWCDMA_ATTR_MODACC_RESULTS_DETECTED_MODULATION_TYPE
#define RFMXWCDMA_VAL_MODACC_DETECTED_MODULATION_TYPE_BPSK_QPSK                                      0
#define RFMXWCDMA_VAL_MODACC_DETECTED_MODULATION_TYPE_4PAM_16QAM                                     1
#define RFMXWCDMA_VAL_MODACC_DETECTED_MODULATION_TYPE_64QAM                                          2

// Values for RFMXWCDMA_ATTR_MODACC_RESULTS_DETECTED_BRANCH
#define RFMXWCDMA_VAL_MODACC_DETECTED_BRANCH_I                                                       0
#define RFMXWCDMA_VAL_MODACC_DETECTED_BRANCH_Q                                                       1
#define RFMXWCDMA_VAL_MODACC_DETECTED_BRANCH_I_AND_Q                                                 2

// Values for RFMXWCDMA_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER
#define RFMXWCDMA_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_CLOSEST                                     0
#define RFMXWCDMA_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_HIGHEST                                     1
#define RFMXWCDMA_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_COMPOSITE                                   2
#define RFMXWCDMA_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_SPECIFIC                                    3

// Values for RFMXWCDMA_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXWCDMA_VAL_ACP_RBW_AUTO_FALSE                                                             0
#define RFMXWCDMA_VAL_ACP_RBW_AUTO_TRUE                                                              1

// Values for RFMXWCDMA_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXWCDMA_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXWCDMA_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXWCDMA_VAL_ACP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXWCDMA_ATTR_ACP_SWEEP_TIME_AUTO
#define RFMXWCDMA_VAL_ACP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXWCDMA_VAL_ACP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXWCDMA_ATTR_ACP_MEASUREMENT_METHOD
#define RFMXWCDMA_VAL_ACP_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXWCDMA_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1
#define RFMXWCDMA_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                          2

// Values for RFMXWCDMA_ATTR_ACP_NOISE_COMPENSATION_ENABLED
#define RFMXWCDMA_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXWCDMA_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXWCDMA_ATTR_ACP_AVERAGING_ENABLED
#define RFMXWCDMA_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXWCDMA_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXWCDMA_ATTR_ACP_AVERAGING_TYPE
#define RFMXWCDMA_VAL_ACP_AVERAGING_TYPE_RMS                                                         0
#define RFMXWCDMA_VAL_ACP_AVERAGING_TYPE_LOG                                                         1
#define RFMXWCDMA_VAL_ACP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXWCDMA_VAL_ACP_AVERAGING_TYPE_MAX                                                         3
#define RFMXWCDMA_VAL_ACP_AVERAGING_TYPE_MIN                                                         4

// Values for RFMXWCDMA_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXWCDMA_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                          0
#define RFMXWCDMA_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                           1

// Values for RFMXWCDMA_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXWCDMA_VAL_CHP_RBW_AUTO_FALSE                                                             0
#define RFMXWCDMA_VAL_CHP_RBW_AUTO_TRUE                                                              1

// Values for RFMXWCDMA_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXWCDMA_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXWCDMA_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXWCDMA_VAL_CHP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXWCDMA_ATTR_CHP_SWEEP_TIME_AUTO
#define RFMXWCDMA_VAL_CHP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXWCDMA_VAL_CHP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXWCDMA_ATTR_CHP_AVERAGING_ENABLED
#define RFMXWCDMA_VAL_CHP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXWCDMA_VAL_CHP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXWCDMA_ATTR_CHP_AVERAGING_TYPE
#define RFMXWCDMA_VAL_CHP_AVERAGING_TYPE_RMS                                                         0
#define RFMXWCDMA_VAL_CHP_AVERAGING_TYPE_LOG                                                         1
#define RFMXWCDMA_VAL_CHP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXWCDMA_VAL_CHP_AVERAGING_TYPE_MAX                                                         3
#define RFMXWCDMA_VAL_CHP_AVERAGING_TYPE_MIN                                                         4

// Values for RFMXWCDMA_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXWCDMA_VAL_OBW_RBW_AUTO_FALSE                                                             0
#define RFMXWCDMA_VAL_OBW_RBW_AUTO_TRUE                                                              1

// Values for RFMXWCDMA_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXWCDMA_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXWCDMA_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXWCDMA_VAL_OBW_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXWCDMA_ATTR_OBW_SWEEP_TIME_AUTO
#define RFMXWCDMA_VAL_OBW_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXWCDMA_VAL_OBW_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXWCDMA_ATTR_OBW_AVERAGING_ENABLED
#define RFMXWCDMA_VAL_OBW_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXWCDMA_VAL_OBW_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXWCDMA_ATTR_OBW_AVERAGING_TYPE
#define RFMXWCDMA_VAL_OBW_AVERAGING_TYPE_RMS                                                         0
#define RFMXWCDMA_VAL_OBW_AVERAGING_TYPE_LOG                                                         1
#define RFMXWCDMA_VAL_OBW_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXWCDMA_VAL_OBW_AVERAGING_TYPE_MAX                                                         3
#define RFMXWCDMA_VAL_OBW_AVERAGING_TYPE_MIN                                                         4

// Values for RFMXWCDMA_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXWCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FFT_BASED                                           0
#define RFMXWCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN                                            1
#define RFMXWCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FLAT                                                2
#define RFMXWCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_4                                       3
#define RFMXWCDMA_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_5                                       4

// Values for RFMXWCDMA_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXWCDMA_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXWCDMA_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXWCDMA_ATTR_SEM_AVERAGING_ENABLED
#define RFMXWCDMA_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXWCDMA_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXWCDMA_ATTR_SEM_AVERAGING_TYPE
#define RFMXWCDMA_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXWCDMA_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXWCDMA_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXWCDMA_VAL_SEM_AVERAGING_TYPE_MAX                                                         3
#define RFMXWCDMA_VAL_SEM_AVERAGING_TYPE_MIN                                                         4

// Values for RFMXWCDMA_ATTR_SEM_RESULTS_MEASUREMENT_STATUS
#define RFMXWCDMA_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXWCDMA_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXWCDMA_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXWCDMA_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXWCDMA_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXWCDMA_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXWCDMA_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXWCDMA_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXWCDMA_ATTR_QEVM_AVERAGING_ENABLED
#define RFMXWCDMA_VAL_QEVM_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXWCDMA_VAL_QEVM_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXWCDMA_ATTR_QEVM_SPECTRUM_INVERTED
#define RFMXWCDMA_VAL_QEVM_SPECTRUM_INVERTED_FALSE                                                   0
#define RFMXWCDMA_VAL_QEVM_SPECTRUM_INVERTED_TRUE                                                    1

// Values for RFMXWCDMA_ATTR_QEVM_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXWCDMA_VAL_QEVM_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                           0
#define RFMXWCDMA_VAL_QEVM_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                            1

// Values for RFMXWCDMA_ATTR_QEVM_RRC_FILTER_ENABLED
#define RFMXWCDMA_VAL_QEVM_RRC_FILTER_ENABLED_FALSE                                                  0
#define RFMXWCDMA_VAL_QEVM_RRC_FILTER_ENABLED_TRUE                                                   1

// Values for RFMXWCDMA_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE
#define RFMXWCDMA_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_FRAME                                           0
#define RFMXWCDMA_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_SLOT                                            1

// Values for RFMXWCDMA_ATTR_SLOTPHASE_SPECTRUM_INVERTED
#define RFMXWCDMA_VAL_SLOTPHASE_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXWCDMA_VAL_SLOTPHASE_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXWCDMA_ATTR_SLOTPHASE_TRANSIENT_REMOVAL_ENABLED
#define RFMXWCDMA_VAL_SLOTPHASE_TRANSIENT_REMOVAL_ENABLED_FALSE                                      0
#define RFMXWCDMA_VAL_SLOTPHASE_TRANSIENT_REMOVAL_ENABLED_TRUE                                       1

// Values for RFMXWCDMA_ATTR_SLOTPHASE_RRC_FILTER_ENABLED
#define RFMXWCDMA_VAL_SLOTPHASE_RRC_FILTER_ENABLED_FALSE                                             0
#define RFMXWCDMA_VAL_SLOTPHASE_RRC_FILTER_ENABLED_TRUE                                              1

// Values for RFMXWCDMA_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXWCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXWCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXWCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXWCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXWCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXWCDMA_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Boolean
#define RFMXWCDMA_VAL_FALSE                                                                          0
#define RFMXWCDMA_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXWCDMA_VAL_MODACC                                                                         1 << 0
#define RFMXWCDMA_VAL_ACP                                                                            1 << 1
#define RFMXWCDMA_VAL_CHP                                                                            1 << 2
#define RFMXWCDMA_VAL_OBW                                                                            1 << 3
#define RFMXWCDMA_VAL_SEM                                                                            1 << 4
#define RFMXWCDMA_VAL_QEVM                                                                           1 << 5
#define RFMXWCDMA_VAL_SLOTPHASE                                                                      1 << 6
#define RFMXWCDMA_VAL_CDA                                                                            1 << 7
#define RFMXWCDMA_VAL_SLOTPOWER                                                                      1 << 8

// Values for FrequencyReferenceSource
#define RFMXWCDMA_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXWCDMA_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXWCDMA_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXWCDMA_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for RFMXWCDMA_ATTR_LINK_DIRECTION
#define RFMXWCDMA_VAL_LINK_DIRECTION_DOWNLINK                                                        0
#define RFMXWCDMA_VAL_LINK_DIRECTION_UPLINK                                                          1

// Values for RFAttenuationAuto
#define RFMXWCDMA_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXWCDMA_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXWCDMA_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXWCDMA_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

// Values for RFMXWCDMA_ATTR_CDA_SYNCHRONIZATION_MODE
#define RFMXWCDMA_VAL_CDA_SYNCHRONIZATION_MODE_FRAME                                                 0
#define RFMXWCDMA_VAL_CDA_SYNCHRONIZATION_MODE_SLOT                                                  1
#define RFMXWCDMA_VAL_CDA_SYNCHRONIZATION_MODE_ARBITRARY                                             2

// Values for RFMXWCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_MODULATION_TYPE
#define RFMXWCDMA_VAL_CDA_MEASUREMENT_CHANNEL_MODULATION_TYPE_BPSK_QPSK                              0
#define RFMXWCDMA_VAL_CDA_MEASUREMENT_CHANNEL_MODULATION_TYPE_4PAM_16QAM                             1

// Values for RFMXWCDMA_ATTR_CDA_MEASUREMENT_CHANNEL_BRANCH
#define RFMXWCDMA_VAL_CDA_MEASUREMENT_CHANNEL_BRANCH_I                                               0
#define RFMXWCDMA_VAL_CDA_MEASUREMENT_CHANNEL_BRANCH_Q                                               1

// Values for RFMXWCDMA_ATTR_CDA_POWER_UNIT
#define RFMXWCDMA_VAL_CDA_POWER_UNIT_DB                                                              0
#define RFMXWCDMA_VAL_CDA_POWER_UNIT_DBM                                                             1

// Values for RFMXWCDMA_ATTR_CDA_SPECTRUM_INVERTED
#define RFMXWCDMA_VAL_CDA_SPECTRUM_INVERTED_FALSE                                                    0
#define RFMXWCDMA_VAL_CDA_SPECTRUM_INVERTED_TRUE                                                     1

// Values for RFMXWCDMA_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXWCDMA_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                            0
#define RFMXWCDMA_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                             1

// Values for RFMXWCDMA_ATTR_CDA_RRC_FILTER_ENABLED
#define RFMXWCDMA_VAL_CDA_RRC_FILTER_ENABLED_FALSE                                                   0
#define RFMXWCDMA_VAL_CDA_RRC_FILTER_ENABLED_TRUE                                                    1

// Values for RFMXWCDMA_ATTR_SLOTPOWER_SYNCHRONIZATION_MODE
#define RFMXWCDMA_VAL_SLOTPOWER_SYNCHRONIZATION_MODE_FRAME                                           0
#define RFMXWCDMA_VAL_SLOTPOWER_SYNCHRONIZATION_MODE_SLOT                                            1

// Values for RFMXWCDMA_ATTR_SLOTPOWER_SPECTRUM_INVERTED
#define RFMXWCDMA_VAL_SLOTPOWER_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXWCDMA_VAL_SLOTPOWER_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXWCDMA_ATTR_SLOTPOWER_RRC_FILTER_ENABLED
#define RFMXWCDMA_VAL_SLOTPOWER_RRC_FILTER_ENABLED_FALSE                                             0
#define RFMXWCDMA_VAL_SLOTPOWER_RRC_FILTER_ENABLED_TRUE                                              1

// Values for RFMXWCDMA_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE
#define RFMXWCDMA_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXWCDMA_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXWCDMA_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE
#define RFMXWCDMA_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXWCDMA_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXWCDMA_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE
#define RFMXWCDMA_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXWCDMA_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXWCDMA_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE
#define RFMXWCDMA_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXWCDMA_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXWCDMA_ATTR_TRANSMITTER_ARCHITECTURE
#define RFMXWCDMA_VAL_TRANSMITTER_ARCHITECTURE_LO_PER_CARRIER                                        0
#define RFMXWCDMA_VAL_TRANSMITTER_ARCHITECTURE_LO_PER_BAND                                           1

// Values for RFMXWCDMA_ATTR_ACP_FFT_OVERLAP_MODE
#define RFMXWCDMA_VAL_ACP_FFT_OVERLAP_MODE_DISABLED                                                  0
#define RFMXWCDMA_VAL_ACP_FFT_OVERLAP_MODE_AUTOMATIC                                                 1

/* ---------------- RFmxWCDMA APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxWCDMA_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxWCDMA_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxWCDMA_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxWCDMA_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxWCDMA_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxWCDMA_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxWCDMA_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxWCDMA_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxWCDMA_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxWCDMA_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxWCDMA_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxWCDMA_BuildCarrierString(
   char selectorString[],
   int32 carrierNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWCDMA_BuildChannelString(
   char selectorString[],
   int32 channelNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWCDMA_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxWCDMA_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxWCDMA_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxWCDMA_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxWCDMA_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxWCDMA_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxWCDMA_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* done
);

int32 __stdcall RFmxWCDMA_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWCDMA_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWCDMA_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWCDMA_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxWCDMA_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWCDMA_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxWCDMA_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxWCDMA_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxWCDMA_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxWCDMA_CfgContiguousCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCarriers,
   int32 carrierAtCenterFrequency
);

int32 __stdcall RFmxWCDMA_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxWCDMA_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxWCDMA_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxWCDMA_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxWCDMA_ModAccCfgReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_ModAccCfgReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 referenceWaveformI[],
   float32 referenceWaveformQ[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_CfgNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCarriers
);

int32 __stdcall RFmxWCDMA_CfgNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfChannels
);

int32 __stdcall RFmxWCDMA_CfgUplinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkTestModel
);

int32 __stdcall RFmxWCDMA_CfgUplinkScrambling(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkScramblingCode,
   int32 uplinkScramblingType
);

int32 __stdcall RFmxWCDMA_CfgUserDefinedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spreadingFactor,
   int32 spreadingCode,
   int32 modulationType,
   int32 branch
);

int32 __stdcall RFmxWCDMA_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxWCDMA_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxWCDMA_CfgBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 band
);

int32 __stdcall RFmxWCDMA_CfgCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierFrequency
);

int32 __stdcall RFmxWCDMA_CfgChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelConfigurationMode
);

int32 __stdcall RFmxWCDMA_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxWCDMA_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxWCDMA_CfgUserDefinedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spreadingFactor[],
   int32 spreadingCode[],
   int32 modulationType[],
   int32 branch[],
   int32 numberOfElements
);

int32 __stdcall RFmxWCDMA_CfgCarrierFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierFrequency[],
   int32 numberOfElements
);

int32 __stdcall RFmxWCDMA_CfgUplinkScramblingArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkScramblingType[],
   int32 uplinkScramblingCode[],
   int32 numberOfElements
);

int32 __stdcall RFmxWCDMA_CfgUplinkTestModelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkTestModel[],
   int32 numberOfElements
);

int32 __stdcall RFmxWCDMA_CfgNumberOfChannelsArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfChannels[],
   int32 numberOfElements
);

int32 __stdcall RFmxWCDMA_OBWCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxWCDMA_OBWCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxWCDMA_OBWCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxWCDMA_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxWCDMA_ACPCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxWCDMA_ACPCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxWCDMA_ACPCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxWCDMA_ACPCfgOffsetPowerReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetPowerReferenceCarrier,
   int32 offsetPowerReferenceSpecific
);

int32 __stdcall RFmxWCDMA_ACPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxWCDMA_ACPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxWCDMA_SlotPhaseCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxWCDMA_QEVMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxWCDMA_QEVMCfgMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementLength
);

int32 __stdcall RFmxWCDMA_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxWCDMA_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxWCDMA_ModAccCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxWCDMA_CHPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxWCDMA_CHPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxWCDMA_CHPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxWCDMA_CDACfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxWCDMA_CDACfgMeasurementChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spreadingFactor,
   int32 spreadingCode,
   int32 modulationType,
   int32 branch
);

int32 __stdcall RFmxWCDMA_CDACfgPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnit
);

int32 __stdcall RFmxWCDMA_SlotPowerCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxWCDMA_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxWCDMA_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxWCDMA_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWCDMA_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxWCDMA_CfgFrequencyUARFCN(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 linkDirection,
   int32 band,
   int32 UARFCN
);

int32 __stdcall RFmxWCDMA_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxWCDMA_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxWCDMA_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxWCDMA_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxWCDMA_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxWCDMA_OBWFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_OBWFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* absolutePower,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxWCDMA_ModAccFetchDetectedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 detectedSpreadingFactor[],
   int32 detectedSpreadingCode[],
   int32 detectedModulationType[],
   int32 detectedBranch[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 referenceWaveformI[],
   float32 referenceWaveformQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 constellationI[],
   float32 constellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchRCDETrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 RCDE[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 RMSEVM[],
   float64 peakEVM[],
   float64 rho[],
   float64 frequencyError[],
   float64 chipRateError[],
   float64 RMSMagnitudeError[],
   float64 RMSPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchIQImpairmentsArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 IQOriginOffset[],
   float64 IQGainImbalance[],
   float64 IQQuadratureError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchPeakCDEArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 peakCDE[],
   int32 peakCDECode[],
   int32 peakCDEBranch[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchPeakActiveCDEArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 peakActiveCDE[],
   int32 peakActiveCDESpreadingFactor[],
   int32 peakActiveCDECode[],
   int32 peakActiveCDEBranch[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchRCDEArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 peakRCDE[],
   int32 peakRCDESpreadingFactor[],
   int32 peakRCDECode[],
   int32 peakRCDEBranch[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchNumberOfDetectedChannelsArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 numberofDetectedChannels[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccFetchDetectedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* detectedSpreadingFactor,
   int32* detectedSpreadingCode,
   int32* detectedModulationType,
   int32* detectedBranch
);

int32 __stdcall RFmxWCDMA_ModAccFetchEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSEVM,
   float64* peakEVM,
   float64* rho,
   float64* frequencyError,
   float64* chipRateError,
   float64* RMSMagnitudeError,
   float64* RMSPhaseError
);

int32 __stdcall RFmxWCDMA_ModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffset,
   float64* IQGainImbalance,
   float64* IQQuadratureError
);

int32 __stdcall RFmxWCDMA_ModAccFetchNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* numberOfDetectedChannels
);

int32 __stdcall RFmxWCDMA_ModAccFetchPeakActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakActiveCDE,
   int32* peakActiveCDESpreadingFactor,
   int32* peakActiveCDECode,
   int32* peakActiveCDEBranch
);

int32 __stdcall RFmxWCDMA_ModAccFetchPeakCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakCDE,
   int32* peakCDECode,
   int32* peakCDEBranch
);

int32 __stdcall RFmxWCDMA_ModAccFetchRCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakRCDE,
   int32* peakRCDESpreadingFactor,
   int32* peakRCDECode,
   int32* peakRCDEBranch
);

int32 __stdcall RFmxWCDMA_ModAccFetchMulticarrierIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* multicarrierIQOriginOffset,
   float64* multicarrierIQGainImbalance,
   float64* multicarrierIQQuadratureError
);

int32 __stdcall RFmxWCDMA_SlotPhaseFetchPhaseDiscontinuities(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 slotPhaseDiscontinuity[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SlotPhaseFetchChipPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chipPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SlotPhaseFetchChipPhaseErrorLinearFitTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chipPhaseErrorLinearFit[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SlotPhaseFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumPhaseDiscontinuity,
   int32* discontinuityCountGreaterThanLimit1,
   int32* discontinuityCountGreaterThanLimit2,
   int32* discontinuityMinimumDistance
);

int32 __stdcall RFmxWCDMA_SEMFetchCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absoluteIntegratedPower[],
   float64 relativeIntegratedPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_SEMFetchLowerOffsetMarginArray(
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

int32 __stdcall RFmxWCDMA_SEMFetchLowerOffsetPowerArray(
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

int32 __stdcall RFmxWCDMA_SEMFetchSpectrum(
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

int32 __stdcall RFmxWCDMA_SEMFetchUpperOffsetMarginArray(
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

int32 __stdcall RFmxWCDMA_SEMFetchUpperOffsetPowerArray(
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

int32 __stdcall RFmxWCDMA_SEMFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower
);

int32 __stdcall RFmxWCDMA_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxWCDMA_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxWCDMA_SEMFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxWCDMA_SEMFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxWCDMA_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxWCDMA_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxWCDMA_QEVMFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_QEVMFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_QEVMFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 constellationI[],
   float32 constellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_QEVMFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_QEVMFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_QEVMFetchEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSEVM,
   float64* maximumPeakEVM,
   float64* meanFrequencyError,
   float64* meanMagnitudeError,
   float64* meanPhaseError,
   float64* meanChipRateError
);

int32 __stdcall RFmxWCDMA_QEVMFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanIQOriginOffset,
   float64* meanIQGainImbalance,
   float64* meanIQQuadratureError,
   float64* maximumIQOriginOffset,
   float64* maximumIQGainImbalance,
   float64* maximumIQQuadratureError
);

int32 __stdcall RFmxWCDMA_ACPFetchCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ACPFetchOffsetMeasurementArray(
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

int32 __stdcall RFmxWCDMA_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ACPFetchRelativePowersTrace(
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

int32 __stdcall RFmxWCDMA_ACPFetchAbsolutePowersTrace(
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

int32 __stdcall RFmxWCDMA_ACPFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxWCDMA_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower
);

int32 __stdcall RFmxWCDMA_ACPFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxWCDMA_CHPFetchCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CHPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CHPFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxWCDMA_CHPFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxWCDMA_CDAFetchSymbolEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CDAFetchSymbolMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolMagnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CDAFetchSymbolPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CDAFetchCodeDomainPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 codeDomainPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CDAFetchCodeDomainIAndQPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 ICodeDomainPowers[],
   float32 QCodeDomainPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CDAFetchSymbolPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_CDAFetchSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSSymbolEVM,
   float64* peakSymbolEVM,
   float64* RMSSymbolMagnitudeError,
   float64* RMSSymbolPhaseError,
   float64* meanSymbolPower,
   float64* chipRateError
);

int32 __stdcall RFmxWCDMA_CDAFetchCodeDomainPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalPower,
   float64* totalActivePower,
   float64* meanActivePower,
   float64* peakActivePower,
   float64* meanInactivePower,
   float64* peakInactivePower
);

int32 __stdcall RFmxWCDMA_CDAFetchCodeDomainIAndQPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IMeanActivePower,
   float64* QMeanActivePower,
   float64* IPeakInactivePower,
   float64* QPeakInactivePower
);

int32 __stdcall RFmxWCDMA_SlotPowerFetchPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 slotPower[],
   float64 slotPowerDelta[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxWCDMA_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetTransientRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetTransientRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetDownlinkTimingChannelSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetDownlinkTimingChannelSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetDownlinkTimingChannelCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccSetDownlinkTimingChannelCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsRMSMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsRMSPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakCDECode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakCDEBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakActiveCDESpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakActiveCDECode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakActiveCDEBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsSSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsDPCHTimingOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakRCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakRCDESpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakRCDECode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsPeakRCDEBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsDetectedSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsDetectedSpreadingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsDetectedModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsDetectedBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ModAccGetResultsMultiCarrierIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetOffsetPowerReferenceSpecific(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetOffsetPowerReferenceSpecific(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetResultsCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_ACPSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_ACPGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetResultsCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CHPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetResultsOccupiedBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetResultsAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetResultsStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetResultsStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_OBWSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsCarrierRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsCarrierAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsCarrierPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SEMSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMaximumRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMeanPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMaximumPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMeanMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMaximumMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMeanPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMaximumPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMeanFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMaximumFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMeanIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMaximumIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMeanChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_QEVMGetResultsMaximumChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetTransientRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetTransientRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetResultsMaximumPhaseDiscontinuity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetResultsDiscontinuityCountGreaterThanLimit1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetResultsDiscontinuityCountGreaterThanLimit2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPhaseGetResultsDiscontinuityMinimumDistance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxWCDMA_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxWCDMA_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetSpreadingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetSpreadingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetUplinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetUplinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetDownlinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetDownlinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetUplinkScramblingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetUplinkScramblingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetUplinkScramblingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetUplinkScramblingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetDownlinkScramblingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetDownlinkScramblingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetDownlinkScramblingPrimaryCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetDownlinkScramblingPrimaryCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetDownlinkScramblingSecondaryCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetDownlinkScramblingSecondaryCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_GetTransmitterArchitecture(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SetTransmitterArchitecture(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxWCDMA_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxWCDMA_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetMeasurementChannelSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetMeasurementChannelSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetMeasurementChannelSpreadingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetMeasurementChannelSpreadingCode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetMeasurementChannelModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetMeasurementChannelModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetMeasurementChannelBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetMeasurementChannelBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_CDASetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsRMSSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsPeakSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsRMSSymbolMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsRMSSymbolPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsMeanSymbolPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsTotalPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsTotalActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsPeakActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsMeanInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsIMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsQMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsIPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_CDAGetResultsQPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxWCDMA_SlotPowerSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxWCDMA_CalculateFrequencyFromUARFCN(
   int32 linkDirection,
   int32 band,
   int32 UARFCN,
   float64 *centerFrequency
);

int32 __stdcall RFmxWCDMA_AnalyzeIQ(
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

int32 __stdcall RFmxWCDMA_AnalyzeIQSplit(
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

int32 __stdcall RFmxWCDMA_AnalyzeSpectrum(
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

