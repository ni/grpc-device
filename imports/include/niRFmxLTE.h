
/****************************************************************************************************
*          National Instruments RFmx LTE
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxLTE.h
*
* Purpose:  National Instruments RFmx LTE,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_LTE_H__
#define __NI_RFMX_LTE_H__

#include "niRFmxInstr.h"

#define RFMXLTE_ATTR_MODACC_MEASUREMENT_ENABLED                                             0x00304000
#define RFMXLTE_ATTR_MODACC_SYNCHRONIZATION_MODE                                            0x00304003
#define RFMXLTE_ATTR_MODACC_MEASUREMENT_OFFSET                                              0x00304004
#define RFMXLTE_ATTR_MODACC_MEASUREMENT_LENGTH                                              0x00304005
#define RFMXLTE_ATTR_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED                             0x00304079
#define RFMXLTE_ATTR_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED                                  0x0030407a
#define RFMXLTE_ATTR_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED                            0x0030407b
#define RFMXLTE_ATTR_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED                          0x0030407c
#define RFMXLTE_ATTR_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED                               0x0030407d
#define RFMXLTE_ATTR_MODACC_SPECTRUM_INVERTED                                               0x00304036
#define RFMXLTE_ATTR_MODACC_CHANNEL_ESTIMATION_TYPE                                         0x00304037
#define RFMXLTE_ATTR_MODACC_EVM_UNIT                                                        0x00304006
#define RFMXLTE_ATTR_MODACC_FFT_WINDOW_TYPE                                                 0x00304038
#define RFMXLTE_ATTR_MODACC_FFT_WINDOW_OFFSET                                               0x00304007
#define RFMXLTE_ATTR_MODACC_FFT_WINDOW_LENGTH                                               0x00304039
#define RFMXLTE_ATTR_MODACC_COMMON_CLOCK_SOURCE_ENABLED                                     0x00304009
#define RFMXLTE_ATTR_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED                               0x00304032
#define RFMXLTE_ATTR_MODACC_SPECTRAL_FLATNESS_CONDITION                                     0x00304008
#define RFMXLTE_ATTR_MODACC_AVERAGING_ENABLED                                               0x0030400a
#define RFMXLTE_ATTR_MODACC_AVERAGING_COUNT                                                 0x0030400b
#define RFMXLTE_ATTR_MODACC_ALL_TRACES_ENABLED                                              0x0030400d
#define RFMXLTE_ATTR_MODACC_NUMBER_OF_ANALYSIS_THREADS                                      0x0030400e
#define RFMXLTE_ATTR_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL                               0x0030407f
#define RFMXLTE_ATTR_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED                           0x00304080
#define RFMXLTE_ATTR_MODACC_TIMING_TRACKING_ENABLED                                         0x00304081
#define RFMXLTE_ATTR_MODACC_PHASE_TRACKING_ENABLED                                          0x00304082
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_COMPOSITE_EVM                                  0x0030400f
#define RFMXLTE_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_COMPOSITE_EVM                              0x00304010
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_COMPOSITE_MAGNITUDE_ERROR                      0x0030403a
#define RFMXLTE_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_COMPOSITE_MAGNITUDE_ERROR                  0x0030403b
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_COMPOSITE_PHASE_ERROR                          0x0030403c
#define RFMXLTE_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_COMPOSITE_PHASE_ERROR                      0x0030403d
#define RFMXLTE_ATTR_MODACC_RESULTS_PEAK_COMPOSITE_EVM_SLOT_INDEX                           0x00304013
#define RFMXLTE_ATTR_MODACC_RESULTS_PEAK_COMPOSITE_EVM_SYMBOL_INDEX                         0x00304014
#define RFMXLTE_ATTR_MODACC_RESULTS_PEAK_COMPOSITE_EVM_SUBCARRIER_INDEX                     0x00304015
#define RFMXLTE_ATTR_MODACC_RESULTS_PUSCH_MEAN_RMS_DATA_EVM                                 0x00304016
#define RFMXLTE_ATTR_MODACC_RESULTS_PUSCH_MAXIMUM_PEAK_DATA_EVM                             0x00304017
#define RFMXLTE_ATTR_MODACC_RESULTS_PUSCH_MEAN_RMS_DMRS_EVM                                 0x00304018
#define RFMXLTE_ATTR_MODACC_RESULTS_PUSCH_MAXIMUM_PEAK_DMRS_EVM                             0x00304019
#define RFMXLTE_ATTR_MODACC_RESULTS_PUSCH_MEAN_DATA_POWER                                   0x0030401a
#define RFMXLTE_ATTR_MODACC_RESULTS_PUSCH_MEAN_DMRS_POWER                                   0x0030401b
#define RFMXLTE_ATTR_MODACC_RESULTS_IN_BAND_EMISSION_MARGIN                                 0x0030402b
#define RFMXLTE_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MAXIMUM_TO_RANGE1_MINIMUM      0x0030402c
#define RFMXLTE_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MAXIMUM_TO_RANGE2_MINIMUM      0x0030402d
#define RFMXLTE_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE1_MAXIMUM_TO_RANGE2_MINIMUM      0x0030402e
#define RFMXLTE_ATTR_MODACC_RESULTS_SPECTRAL_FLATNESS_RANGE2_MAXIMUM_TO_RANGE1_MINIMUM      0x0030402f
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_FREQUENCY_ERROR                                    0x00304022
#define RFMXLTE_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_FREQUENCY_ERROR                            0x00304083
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_IQ_ORIGIN_OFFSET                                   0x00304023
#define RFMXLTE_ATTR_MODACC_RESULTS_MAXIMUM_PEAK_IQ_ORIGIN_OFFSET                           0x00304030
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_IQ_GAIN_IMBALANCE                                  0x00304024
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_QUADRATURE_ERROR                                   0x00304025
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_IQ_TIMING_SKEW                                     0x00304026
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_TIME_OFFSET                                        0x00304027
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_SYMBOL_CLOCK_ERROR                                 0x00304028
#define RFMXLTE_ATTR_MODACC_RESULTS_SUBBLOCK_IN_BAND_EMISSION_MARGIN                        0x0030403e
#define RFMXLTE_ATTR_MODACC_RESULTS_SUBBLOCK_MEAN_IQ_ORIGIN_OFFSET                          0x0030403f
#define RFMXLTE_ATTR_MODACC_RESULTS_SUBBLOCK_MEAN_IQ_GAIN_IMBALANCE                         0x00304040
#define RFMXLTE_ATTR_MODACC_RESULTS_SUBBLOCK_MEAN_QUADRATURE_ERROR                          0x00304041
#define RFMXLTE_ATTR_ACP_MEASUREMENT_ENABLED                                                0x00301000
#define RFMXLTE_ATTR_ACP_SUBBLOCK_INTEGRATION_BANDWIDTH                                     0x0030103f
#define RFMXLTE_ATTR_ACP_COMPONENT_CARRIER_INTEGRATION_BANDWIDTH                            0x00301005
#define RFMXLTE_ATTR_ACP_NUMBER_OF_UTRA_OFFSETS                                             0x0030103a
#define RFMXLTE_ATTR_ACP_NUMBER_OF_EUTRA_OFFSETS                                            0x0030103b
#define RFMXLTE_ATTR_ACP_OFFSET_FREQUENCY                                                   0x0030100a
#define RFMXLTE_ATTR_ACP_OFFSET_INTEGRATION_BANDWIDTH                                       0x0030100e
#define RFMXLTE_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH                                          0x0030101b
#define RFMXLTE_ATTR_ACP_RBW_FILTER_BANDWIDTH                                               0x0030101c
#define RFMXLTE_ATTR_ACP_RBW_FILTER_TYPE                                                    0x0030101d
#define RFMXLTE_ATTR_ACP_SWEEP_TIME_AUTO                                                    0x0030101e
#define RFMXLTE_ATTR_ACP_SWEEP_TIME_INTERVAL                                                0x0030101f
#define RFMXLTE_ATTR_ACP_POWER_UNITS                                                        0x00301013
#define RFMXLTE_ATTR_ACP_MEASUREMENT_METHOD                                                 0x00301012
#define RFMXLTE_ATTR_ACP_SEQUENTIAL_FFT_SIZE                                                0x00301041
#define RFMXLTE_ATTR_ACP_NOISE_CALIBRATION_MODE                                             0x0030104b
#define RFMXLTE_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_AUTO                                   0x0030104a
#define RFMXLTE_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_COUNT                                  0x00301049
#define RFMXLTE_ATTR_ACP_NOISE_COMPENSATION_ENABLED                                         0x00301020
#define RFMXLTE_ATTR_ACP_NOISE_COMPENSATION_TYPE                                            0x00301048
#define RFMXLTE_ATTR_ACP_AVERAGING_ENABLED                                                  0x00301016
#define RFMXLTE_ATTR_ACP_AVERAGING_COUNT                                                    0x00301015
#define RFMXLTE_ATTR_ACP_AVERAGING_TYPE                                                     0x00301018
#define RFMXLTE_ATTR_ACP_MEASUREMENT_MODE                                                   0x00301047
#define RFMXLTE_ATTR_ACP_FFT_OVERLAP_MODE                                                   0x00301045
#define RFMXLTE_ATTR_ACP_FFT_OVERLAP                                                        0x00301046
#define RFMXLTE_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO                                        0x00301034
#define RFMXLTE_ATTR_ACP_NEAR_IF_OUTPUT_POWER_OFFSET                                        0x00301035
#define RFMXLTE_ATTR_ACP_FAR_IF_OUTPUT_POWER_OFFSET                                         0x00301036
#define RFMXLTE_ATTR_ACP_ALL_TRACES_ENABLED                                                 0x00301021
#define RFMXLTE_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                                         0x00301014
#define RFMXLTE_ATTR_ACP_RESULTS_TOTAL_AGGREGATED_POWER                                     0x00301022
#define RFMXLTE_ATTR_ACP_RESULTS_SUBBLOCK_CENTER_FREQUENCY                                  0x00301039
#define RFMXLTE_ATTR_ACP_RESULTS_SUBBLOCK_INTEGRATION_BANDWIDTH                             0x00301037
#define RFMXLTE_ATTR_ACP_RESULTS_SUBBLOCK_POWER                                             0x00301038
#define RFMXLTE_ATTR_ACP_RESULTS_COMPONENT_CARRIER_ABSOLUTE_POWER                           0x00301026
#define RFMXLTE_ATTR_ACP_RESULTS_COMPONENT_CARRIER_RELATIVE_POWER                           0x00301027
#define RFMXLTE_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                                0x0030102c
#define RFMXLTE_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                                0x0030102d
#define RFMXLTE_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                                0x00301032
#define RFMXLTE_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                                0x00301033
#define RFMXLTE_ATTR_CHP_MEASUREMENT_ENABLED                                                0x00303000
#define RFMXLTE_ATTR_CHP_INTEGRATION_BANDWIDTH_TYPE                                         0x00303018
#define RFMXLTE_ATTR_CHP_SUBBLOCK_INTEGRATION_BANDWIDTH                                     0x00303022
#define RFMXLTE_ATTR_CHP_COMPONENT_CARRIER_INTEGRATION_BANDWIDTH                            0x00303002
#define RFMXLTE_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH                                          0x0030300c
#define RFMXLTE_ATTR_CHP_RBW_FILTER_BANDWIDTH                                               0x0030300d
#define RFMXLTE_ATTR_CHP_RBW_FILTER_TYPE                                                    0x0030300e
#define RFMXLTE_ATTR_CHP_SWEEP_TIME_AUTO                                                    0x00303011
#define RFMXLTE_ATTR_CHP_SWEEP_TIME_INTERVAL                                                0x00303012
#define RFMXLTE_ATTR_CHP_NOISE_CALIBRATION_MODE                                             0x00303029
#define RFMXLTE_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_AUTO                                   0x00303028
#define RFMXLTE_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_COUNT                                  0x00303027
#define RFMXLTE_ATTR_CHP_NOISE_COMPENSATION_ENABLED                                         0x00303025
#define RFMXLTE_ATTR_CHP_NOISE_COMPENSATION_TYPE                                            0x00303026
#define RFMXLTE_ATTR_CHP_AVERAGING_ENABLED                                                  0x00303007
#define RFMXLTE_ATTR_CHP_AVERAGING_COUNT                                                    0x00303006
#define RFMXLTE_ATTR_CHP_AVERAGING_TYPE                                                     0x00303009
#define RFMXLTE_ATTR_CHP_MEASUREMENT_MODE                                                   0x00303024
#define RFMXLTE_ATTR_CHP_ALL_TRACES_ENABLED                                                 0x00303014
#define RFMXLTE_ATTR_CHP_NUMBER_OF_ANALYSIS_THREADS                                         0x00303003
#define RFMXLTE_ATTR_CHP_RESULTS_TOTAL_AGGREGATED_POWER                                     0x00303019
#define RFMXLTE_ATTR_CHP_RESULTS_SUBBLOCK_FREQUENCY                                         0x0030301b
#define RFMXLTE_ATTR_CHP_RESULTS_SUBBLOCK_INTEGRATION_BANDWIDTH                             0x0030301c
#define RFMXLTE_ATTR_CHP_RESULTS_SUBBLOCK_POWER                                             0x0030301d
#define RFMXLTE_ATTR_CHP_RESULTS_COMPONENT_CARRIER_ABSOLUTE_POWER                           0x00303015
#define RFMXLTE_ATTR_CHP_RESULTS_COMPONENT_CARRIER_RELATIVE_POWER                           0x00303020
#define RFMXLTE_ATTR_OBW_MEASUREMENT_ENABLED                                                0x00306000
#define RFMXLTE_ATTR_OBW_SPAN                                                               0x00306004
#define RFMXLTE_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH                                          0x0030600c
#define RFMXLTE_ATTR_OBW_RBW_FILTER_BANDWIDTH                                               0x0030600d
#define RFMXLTE_ATTR_OBW_RBW_FILTER_TYPE                                                    0x0030600e
#define RFMXLTE_ATTR_OBW_SWEEP_TIME_AUTO                                                    0x0030600f
#define RFMXLTE_ATTR_OBW_SWEEP_TIME_INTERVAL                                                0x00306010
#define RFMXLTE_ATTR_OBW_AVERAGING_ENABLED                                                  0x00306007
#define RFMXLTE_ATTR_OBW_AVERAGING_COUNT                                                    0x00306006
#define RFMXLTE_ATTR_OBW_AVERAGING_TYPE                                                     0x00306009
#define RFMXLTE_ATTR_OBW_ALL_TRACES_ENABLED                                                 0x00306012
#define RFMXLTE_ATTR_OBW_NUMBER_OF_ANALYSIS_THREADS                                         0x00306003
#define RFMXLTE_ATTR_OBW_RESULTS_OCCUPIED_BANDWIDTH                                         0x00306013
#define RFMXLTE_ATTR_OBW_RESULTS_ABSOLUTE_POWER                                             0x00306014
#define RFMXLTE_ATTR_OBW_RESULTS_START_FREQUENCY                                            0x00306015
#define RFMXLTE_ATTR_OBW_RESULTS_STOP_FREQUENCY                                             0x00306016
#define RFMXLTE_ATTR_SEM_MEASUREMENT_ENABLED                                                0x00308000
#define RFMXLTE_ATTR_SEM_SUBBLOCK_INTEGRATION_BANDWIDTH                                     0x00308051
#define RFMXLTE_ATTR_SEM_SUBBLOCK_AGGREGATED_CHANNEL_BANDWIDTH                              0x00308052
#define RFMXLTE_ATTR_SEM_COMPONENT_CARRIER_INTEGRATION_BANDWIDTH                            0x00308005
#define RFMXLTE_ATTR_SEM_NUMBER_OF_OFFSETS                                                  0x0030800b
#define RFMXLTE_ATTR_SEM_OFFSET_START_FREQUENCY                                             0x00308014
#define RFMXLTE_ATTR_SEM_OFFSET_STOP_FREQUENCY                                              0x00308015
#define RFMXLTE_ATTR_SEM_OFFSET_SIDEBAND                                                    0x00308013
#define RFMXLTE_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH                                        0x00308017
#define RFMXLTE_ATTR_SEM_OFFSET_RBW_FILTER_TYPE                                             0x00308018
#define RFMXLTE_ATTR_SEM_OFFSET_BANDWIDTH_INTEGRAL                                          0x0030800c
#define RFMXLTE_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_START                                        0x00308010
#define RFMXLTE_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_STOP                                         0x00308011
#define RFMXLTE_ATTR_SEM_SWEEP_TIME_AUTO                                                    0x00308025
#define RFMXLTE_ATTR_SEM_SWEEP_TIME_INTERVAL                                                0x00308026
#define RFMXLTE_ATTR_SEM_AVERAGING_ENABLED                                                  0x0030801f
#define RFMXLTE_ATTR_SEM_AVERAGING_COUNT                                                    0x0030801e
#define RFMXLTE_ATTR_SEM_AVERAGING_TYPE                                                     0x00308021
#define RFMXLTE_ATTR_SEM_ALL_TRACES_ENABLED                                                 0x00308027
#define RFMXLTE_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                                         0x0030801d
#define RFMXLTE_ATTR_SEM_RESULTS_TOTAL_AGGREGATED_POWER                                     0x00308028
#define RFMXLTE_ATTR_SEM_RESULTS_MEASUREMENT_STATUS                                         0x00308029
#define RFMXLTE_ATTR_SEM_RESULTS_SUBBLOCK_CENTER_FREQUENCY                                  0x0030804d
#define RFMXLTE_ATTR_SEM_RESULTS_SUBBLOCK_INTEGRATION_BANDWIDTH                             0x0030804e
#define RFMXLTE_ATTR_SEM_RESULTS_SUBBLOCK_POWER                                             0x0030804f
#define RFMXLTE_ATTR_SEM_RESULTS_COMPONENT_CARRIER_ABSOLUTE_INTEGRATED_POWER                0x0030802d
#define RFMXLTE_ATTR_SEM_RESULTS_COMPONENT_CARRIER_RELATIVE_INTEGRATED_POWER                0x0030802e
#define RFMXLTE_ATTR_SEM_RESULTS_COMPONENT_CARRIER_ABSOLUTE_PEAK_POWER                      0x0030802f
#define RFMXLTE_ATTR_SEM_RESULTS_COMPONENT_CARRIER_PEAK_FREQUENCY                           0x00308030
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS                            0x0030803d
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER                     0x00308034
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_INTEGRATED_POWER                     0x00308035
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER                           0x00308036
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_PEAK_POWER                           0x00308037
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                                0x00308038
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                                        0x00308039
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER                         0x0030803a
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER                         0x0030803b
#define RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY                              0x0030803c
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS                            0x0030804a
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER                     0x00308041
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_INTEGRATED_POWER                     0x00308042
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER                           0x00308043
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_PEAK_POWER                           0x00308044
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                                0x00308045
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                                        0x00308046
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER                         0x00308047
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER                         0x00308048
#define RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY                              0x00308049
#define RFMXLTE_ATTR_PVT_MEASUREMENT_ENABLED                                                0x00309000
#define RFMXLTE_ATTR_PVT_MEASUREMENT_METHOD                                                 0x00309002
#define RFMXLTE_ATTR_PVT_AVERAGING_ENABLED                                                  0x00309007
#define RFMXLTE_ATTR_PVT_AVERAGING_COUNT                                                    0x00309009
#define RFMXLTE_ATTR_PVT_AVERAGING_TYPE                                                     0x0030900a
#define RFMXLTE_ATTR_PVT_OFF_POWER_EXCLUSION_BEFORE                                         0x00309015
#define RFMXLTE_ATTR_PVT_OFF_POWER_EXCLUSION_AFTER                                          0x00309016
#define RFMXLTE_ATTR_PVT_ALL_TRACES_ENABLED                                                 0x0030900b
#define RFMXLTE_ATTR_PVT_NUMBER_OF_ANALYSIS_THREADS                                         0x0030900c
#define RFMXLTE_ATTR_PVT_RESULTS_MEASUREMENT_STATUS                                         0x0030900e
#define RFMXLTE_ATTR_PVT_RESULTS_MEAN_ABSOLUTE_OFF_POWER_BEFORE                             0x00309010
#define RFMXLTE_ATTR_PVT_RESULTS_MEAN_ABSOLUTE_OFF_POWER_AFTER                              0x00309011
#define RFMXLTE_ATTR_PVT_RESULTS_MEAN_ABSOLUTE_ON_POWER                                     0x00309012
#define RFMXLTE_ATTR_PVT_RESULTS_BURST_WIDTH                                                0x00309014
#define RFMXLTE_ATTR_LIMITED_CONFIGURATION_CHANGE                                           0x0030d003
#define RFMXLTE_ATTR_RESULT_FETCH_TIMEOUT                                                   0x0030c000
#define RFMXLTE_ATTR_CENTER_FREQUENCY                                                       0x00300001
#define RFMXLTE_ATTR_REFERENCE_LEVEL                                                        0x00300002
#define RFMXLTE_ATTR_EXTERNAL_ATTENUATION                                                   0x00300003
#define RFMXLTE_ATTR_TRIGGER_TYPE                                                           0x00300004
#define RFMXLTE_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                            0x00300005
#define RFMXLTE_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                              0x00300006
#define RFMXLTE_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                           0x00300007
#define RFMXLTE_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                            0x00300008
#define RFMXLTE_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                                       0x00300fff
#define RFMXLTE_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                            0x00300009
#define RFMXLTE_ATTR_TRIGGER_DELAY                                                          0x0030000a
#define RFMXLTE_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                        0x0030000b
#define RFMXLTE_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                                    0x0030000c
#define RFMXLTE_ATTR_DUPLEX_SCHEME                                                          0x0030000d
#define RFMXLTE_ATTR_UPLINK_DOWNLINK_CONFIGURATION                                          0x0030000e
#define RFMXLTE_ATTR_LINK_DIRECTION                                                         0x00300029
#define RFMXLTE_ATTR_NUMBER_OF_SUBBLOCKS                                                    0x00300023
#define RFMXLTE_ATTR_SUBBLOCK_FREQUENCY                                                     0x00300059
#define RFMXLTE_ATTR_BAND                                                                   0x00300017
#define RFMXLTE_ATTR_COMPONENT_CARRIER_SPACING_TYPE                                         0x00300013
#define RFMXLTE_ATTR_COMPONENT_CARRIER_AT_CENTER_FREQUENCY                                  0x00300014
#define RFMXLTE_ATTR_NUMBER_OF_COMPONENT_CARRIERS                                           0x0030000f
#define RFMXLTE_ATTR_COMPONENT_CARRIER_BANDWIDTH                                            0x00300010
#define RFMXLTE_ATTR_COMPONENT_CARRIER_FREQUENCY                                            0x00300011
#define RFMXLTE_ATTR_CELL_ID                                                                0x00300012
#define RFMXLTE_ATTR_CYCLIC_PREFIX_MODE                                                     0x00300015
#define RFMXLTE_ATTR_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED                                  0x00300026
#define RFMXLTE_ATTR_AUTO_DMRS_DETECTION_ENABLED                                            0x00300028
#define RFMXLTE_ATTR_UPLINK_GROUP_HOPPING_ENABLED                                           0x00300019
#define RFMXLTE_ATTR_UPLINK_SEQUENCE_HOPPING_ENABLED                                        0x0030001a
#define RFMXLTE_ATTR_PUSCH_N_DMRS_1                                                         0x0030001f
#define RFMXLTE_ATTR_PUSCH_DELTA_SEQUENCE_SHIFT                                             0x00300021
#define RFMXLTE_ATTR_PUSCH_MODULATION_TYPE                                                  0x0030001b
#define RFMXLTE_ATTR_PUSCH_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS                                0x0030001c
#define RFMXLTE_ATTR_PUSCH_RESOURCE_BLOCK_OFFSET                                            0x0030001e
#define RFMXLTE_ATTR_PUSCH_NUMBER_OF_RESOURCE_BLOCKS                                        0x00300022
#define RFMXLTE_ATTR_PUSCH_N_DMRS_2                                                         0x00300020
#define RFMXLTE_ATTR_PUSCH_POWER                                                            0x00300027
#define RFMXLTE_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                                     0x0030d000
#define RFMXLTE_ATTR_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED                             0x0030d001
#define RFMXLTE_ATTR_TRANSMITTER_ARCHITECTURE                                               0x0030d002
#define RFMXLTE_ATTR_DMRS_OCC_ENABLED                                                       0x00300051
#define RFMXLTE_ATTR_PUSCH_CYCLIC_SHIFT_FIELD                                               0x00300052
#define RFMXLTE_ATTR_SLOTPHASE_MEASUREMENT_ENABLED                                          0x0030a000
#define RFMXLTE_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE                                         0x0030a006
#define RFMXLTE_ATTR_SLOTPHASE_MEASUREMENT_OFFSET                                           0x0030a002
#define RFMXLTE_ATTR_SLOTPHASE_MEASUREMENT_LENGTH                                           0x0030a003
#define RFMXLTE_ATTR_SLOTPHASE_EXCLUSION_PERIOD_ENABLED                                     0x0030a007
#define RFMXLTE_ATTR_SLOTPHASE_COMMON_CLOCK_SOURCE_ENABLED                                  0x0030a008
#define RFMXLTE_ATTR_SLOTPHASE_SPECTRUM_INVERTED                                            0x0030a009
#define RFMXLTE_ATTR_SLOTPHASE_ALL_TRACES_ENABLED                                           0x0030a00b
#define RFMXLTE_ATTR_SLOTPHASE_RESULTS_MAXIMUM_PHASE_DISCONTINUITY                          0x0030a014
#define RFMXLTE_ATTR_SLOTPOWER_MEASUREMENT_ENABLED                                          0x0030b000
#define RFMXLTE_ATTR_SLOTPOWER_MEASUREMENT_OFFSET                                           0x0030b002
#define RFMXLTE_ATTR_SLOTPOWER_MEASUREMENT_LENGTH                                           0x0030b003
#define RFMXLTE_ATTR_SLOTPOWER_COMMON_CLOCK_SOURCE_ENABLED                                  0x0030b005
#define RFMXLTE_ATTR_SLOTPOWER_SPECTRUM_INVERTED                                            0x0030b006
#define RFMXLTE_ATTR_SLOTPOWER_ALL_TRACES_ENABLED                                           0x0030b00a
#define RFMXLTE_ATTR_MODACC_RESULTS_DOWNLINK_DETECTED_CELL_ID                               0x00304053
#define RFMXLTE_ATTR_SPECIAL_SUBFRAME_CONFIGURATION                                         0x0030002a
#define RFMXLTE_ATTR_NUMBER_OF_DUT_ANTENNAS                                                 0x0030002b
#define RFMXLTE_ATTR_TRANSMIT_ANTENNA_TO_ANALYZE                                            0x0030002c
#define RFMXLTE_ATTR_SRS_ENABLED                                                            0x0030002d
#define RFMXLTE_ATTR_SRS_SUBFRAME_CONFIGURATION                                             0x0030002e
#define RFMXLTE_ATTR_SRS_C_SRS                                                              0x0030002f
#define RFMXLTE_ATTR_SRS_B_SRS                                                              0x00300030
#define RFMXLTE_ATTR_SRS_I_SRS                                                              0x00300031
#define RFMXLTE_ATTR_SRS_n_RRC                                                              0x00300032
#define RFMXLTE_ATTR_SRS_n_SRS_CS                                                           0x00300033
#define RFMXLTE_ATTR_SRS_b_HOP                                                              0x00300034
#define RFMXLTE_ATTR_SRS_k_TC                                                               0x00300035
#define RFMXLTE_ATTR_SRS_MAXIMUM_UpPTS_ENABLED                                              0x00300036
#define RFMXLTE_ATTR_SRS_SUBFRAME1_N_RA                                                     0x00300037
#define RFMXLTE_ATTR_SRS_SUBFRAME6_N_RA                                                     0x00300038
#define RFMXLTE_ATTR_SRS_POWER                                                              0x00300039
#define RFMXLTE_ATTR_DOWNLINK_AUTO_CELL_ID_DETECTION_ENABLED                                0x0030003c
#define RFMXLTE_ATTR_DOWNLINK_CHANNEL_CONFIGURATION_MODE                                    0x0030003d
#define RFMXLTE_ATTR_DOWNLINK_USER_DEFINED_CELL_SPECIFIC_RATIO                              0x0030003e
#define RFMXLTE_ATTR_PSS_POWER                                                              0x0030003f
#define RFMXLTE_ATTR_SSS_POWER                                                              0x00300040
#define RFMXLTE_ATTR_PBCH_POWER                                                             0x00300041
#define RFMXLTE_ATTR_PDCCH_POWER                                                            0x00300042
#define RFMXLTE_ATTR_DOWNLINK_NUMBER_OF_SUBFRAMES                                           0x00300043
#define RFMXLTE_ATTR_PCFICH_CFI                                                             0x00300044
#define RFMXLTE_ATTR_PCFICH_POWER                                                           0x00300045
#define RFMXLTE_ATTR_PHICH_RESOURCE                                                         0x00300046
#define RFMXLTE_ATTR_PHICH_DURATION                                                         0x00300047
#define RFMXLTE_ATTR_PHICH_POWER                                                            0x00300048
#define RFMXLTE_ATTR_NUMBER_OF_PDSCH_CHANNELS                                               0x00300049
#define RFMXLTE_ATTR_PDSCH_CW0_MODULATION_TYPE                                              0x0030004a
#define RFMXLTE_ATTR_PDSCH_RESOURCE_BLOCK_ALLOCATION                                        0x0030004b
#define RFMXLTE_ATTR_PDSCH_POWER                                                            0x0030004c
#define RFMXLTE_ATTR_DOWNLINK_TEST_MODEL                                                    0x0030004d
#define RFMXLTE_ATTR_MODACC_MULTICARRIER_FILTER_ENABLED                                     0x00304002
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_SRS_EVM                                        0x00304042
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_SRS_POWER                                          0x00304043
#define RFMXLTE_ATTR_MODACC_RESULTS_PDSCH_MEAN_RMS_EVM                                      0x00304044
#define RFMXLTE_ATTR_MODACC_RESULTS_PDSCH_MEAN_RMS_QPSK_EVM                                 0x00304045
#define RFMXLTE_ATTR_MODACC_RESULTS_PDSCH_MEAN_RMS_16QAM_EVM                                0x00304046
#define RFMXLTE_ATTR_MODACC_RESULTS_PDSCH_MEAN_RMS_64QAM_EVM                                0x00304047
#define RFMXLTE_ATTR_MODACC_RESULTS_PDSCH_MEAN_RMS_256QAM_EVM                               0x00304048
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_CSRS_EVM                                       0x00304049
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_PSS_EVM                                        0x0030404a
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_SSS_EVM                                        0x0030404b
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_PBCH_EVM                                       0x0030404c
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_PCFICH_EVM                                     0x0030404d
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_PDCCH_EVM                                      0x0030404e
#define RFMXLTE_ATTR_MODACC_RESULTS_MEAN_RMS_PHICH_EVM                                      0x0030404f
#define RFMXLTE_ATTR_MODACC_RESULTS_DOWNLINK_OFDM_SYMBOL_TRANSMIT_POWER                     0x00304052
#define RFMXLTE_ATTR_ENODEB_CATEGORY                                                        0x00300050
#define RFMXLTE_ATTR_MODACC_MULTICARRIER_TIME_SYNCHRONIZATION_MODE                          0x0030407e
#define RFMXLTE_ATTR_SEM_UPLINK_MASK_TYPE                                                   0x0030804c
#define RFMXLTE_ATTR_SEM_DOWNLINK_MASK_TYPE                                                 0x00308053
#define RFMXLTE_ATTR_SEM_DELTA_F_MAXIMUM                                                    0x00308054
#define RFMXLTE_ATTR_SEM_AGGREGATED_MAXIMUM_POWER                                           0x00308055
#define RFMXLTE_ATTR_MODACC_RESULTS_DOWNLINK_RS_TRANSMIT_POWER                              0x00304051
#define RFMXLTE_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE                                          0x00301040
#define RFMXLTE_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE                                          0x00303023
#define RFMXLTE_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE                                          0x0030601b
#define RFMXLTE_ATTR_SEM_COMPONENT_CARRIER_MAXIMUM_OUTPUT_POWER                             0x00308056
#define RFMXLTE_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE                                          0x00308057
#define RFMXLTE_ATTR_SEM_OFFSET_RELATIVE_LIMIT_START                                        0x0030801a
#define RFMXLTE_ATTR_SEM_OFFSET_RELATIVE_LIMIT_STOP                                         0x0030801b
#define RFMXLTE_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK                                             0x0030800d
#define RFMXLTE_ATTR_AUTO_PDSCH_CHANNEL_DETECTION_ENABLED                                   0x00304054
#define RFMXLTE_ATTR_AUTO_CONTROL_CHANNEL_POWER_DETECTION_ENABLED                           0x00304055
#define RFMXLTE_ATTR_AUTO_PCFICH_CFI_DETECTION_ENABLED                                      0x00304056
#define RFMXLTE_ATTR_LAA_STARTING_SUBFRAME                                                  0x00304057
#define RFMXLTE_ATTR_LAA_NUMBER_OF_SUBFRAMES                                                0x00304058
#define RFMXLTE_ATTR_LAA_UPLINK_START_POSITION                                              0x00304059
#define RFMXLTE_ATTR_LAA_UPLINK_ENDING_SYMBOL                                               0x0030405a
#define RFMXLTE_ATTR_LAA_DOWNLINK_STARTING_SYMBOL                                           0x0030405b
#define RFMXLTE_ATTR_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS                                  0x0030405c
#define RFMXLTE_ATTR_MI_CONFIGURATION                                                       0x00300053
#define RFMXLTE_ATTR_MODACC_RESULTS_PDSCH_MEAN_RMS_1024QAM_EVM                              0x0030405d
#define RFMXLTE_ATTR_NCELL_ID                                                               0x0030405e
#define RFMXLTE_ATTR_NB_IOT_UPLINK_SUBCARRIER_SPACING                                       0x0030405f
#define RFMXLTE_ATTR_AUTO_NPUSCH_CHANNEL_DETECTION_ENABLED                                  0x00304060
#define RFMXLTE_ATTR_NPUSCH_FORMAT                                                          0x00304061
#define RFMXLTE_ATTR_NPUSCH_TONE_OFFSET                                                     0x00304062
#define RFMXLTE_ATTR_NPUSCH_NUMBER_OF_TONES                                                 0x00304063
#define RFMXLTE_ATTR_NPUSCH_MODULATION_TYPE                                                 0x00304064
#define RFMXLTE_ATTR_NPUSCH_DMRS_BASE_SEQUENCE_MODE                                         0x00304065
#define RFMXLTE_ATTR_NPUSCH_DMRS_BASE_SEQUENCE_INDEX                                        0x00304066
#define RFMXLTE_ATTR_NPUSCH_DMRS_CYCLIC_SHIFT                                               0x00304067
#define RFMXLTE_ATTR_NPUSCH_DMRS_GROUP_HOPPING_ENABLED                                      0x00304069
#define RFMXLTE_ATTR_NPUSCH_DMRS_DELTA_SEQUENCE_SHIFT                                       0x00304068
#define RFMXLTE_ATTR_EMTC_ANALYSIS_ENABLED                                                  0x00304070
#define RFMXLTE_ATTR_MODACC_IN_BAND_EMISSION_MASK_TYPE                                      0x00304071
#define RFMXLTE_ATTR_MODACC_RESULTS_NPUSCH_MEAN_RMS_DATA_EVM                                0x0030406a
#define RFMXLTE_ATTR_MODACC_RESULTS_NPUSCH_MAXIMUM_PEAK_DATA_EVM                            0x0030406b
#define RFMXLTE_ATTR_MODACC_RESULTS_NPUSCH_MEAN_RMS_DMRS_EVM                                0x0030406c
#define RFMXLTE_ATTR_MODACC_RESULTS_NPUSCH_MAXIMUM_PEAK_DMRS_EVM                            0x0030406d
#define RFMXLTE_ATTR_MODACC_RESULTS_NPUSCH_MEAN_DATA_POWER                                  0x0030406e
#define RFMXLTE_ATTR_MODACC_RESULTS_NPUSCH_MEAN_DMRS_POWER                                  0x0030406f
#define RFMXLTE_ATTR_ACP_CONFIGURABLE_NUMBER_OF_OFFSETS_ENABLED                             0x00301044
#define RFMXLTE_ATTR_ACP_EUTRA_OFFSET_DEFINITION                                            0x00301043
#define RFMXLTE_ATTR_ACP_NUMBER_OF_GSM_OFFSETS                                              0x00301042
#define RFMXLTE_ATTR_NPUSCH_STARTING_SLOT                                                   0x00304072
#define RFMXLTE_ATTR_SELECTED_PORTS                                                         0x00300ffd
#define RFMXLTE_ATTR_CENTER_FREQUENCY_FOR_LIMITS                                            0x0030d004
#define RFMXLTE_ATTR_REFERENCE_LEVEL_HEADROOM                                               0x00300ffc
#define RFMXLTE_ATTR_PSSCH_MODULATION_TYPE                                                  0x00300055
#define RFMXLTE_ATTR_PSSCH_RESOURCE_BLOCK_OFFSET                                            0x00300056
#define RFMXLTE_ATTR_PSSCH_NUMBER_OF_RESOURCE_BLOCKS                                        0x00300057
#define RFMXLTE_ATTR_PSSCH_POWER                                                            0x00300058
#define RFMXLTE_ATTR_MODACC_RESULTS_PSSCH_MEAN_RMS_DATA_EVM                                 0x00304073
#define RFMXLTE_ATTR_MODACC_RESULTS_PSSCH_MAXIMUM_PEAK_DATA_EVM                             0x00304074
#define RFMXLTE_ATTR_MODACC_RESULTS_PSSCH_MEAN_RMS_DMRS_EVM                                 0x00304075
#define RFMXLTE_ATTR_MODACC_RESULTS_PSSCH_MAXIMUM_PEAK_DMRS_EVM                             0x00304076
#define RFMXLTE_ATTR_MODACC_RESULTS_PSSCH_MEAN_DATA_POWER                                   0x00304077
#define RFMXLTE_ATTR_MODACC_RESULTS_PSSCH_MEAN_DMRS_POWER                                   0x00304078
#define RFMXLTE_ATTR_SEM_SIDELINK_MASK_TYPE                                                 0x00308058

// Values for RFMXLTE_ATTR_TRIGGER_TYPE
#define RFMXLTE_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXLTE_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXLTE_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXLTE_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXLTE_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXLTE_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXLTE_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXLTE_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXLTE_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXLTE_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXLTE_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXLTE_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXLTE_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXLTE_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXLTE_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXLTE_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXLTE_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXLTE_VAL_TIMER_EVENT_STR                                                                "TimerEvent"

// Values for RFMXLTE_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXLTE_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXLTE_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXLTE_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXLTE_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXLTE_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXLTE_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXLTE_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXLTE_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXLTE_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXLTE_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXLTE_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXLTE_ATTR_DUPLEX_SCHEME
#define RFMXLTE_VAL_DUPLEX_SCHEME_FDD                                                              0
#define RFMXLTE_VAL_DUPLEX_SCHEME_TDD                                                              1
#define RFMXLTE_VAL_DUPLEX_SCHEME_LAA                                                              2

// Values for RFMXLTE_ATTR_UPLINK_DOWNLINK_CONFIGURATION
#define RFMXLTE_VAL_UPLINK_DOWNLINK_CONFIGURATION_0                                                0
#define RFMXLTE_VAL_UPLINK_DOWNLINK_CONFIGURATION_1                                                1
#define RFMXLTE_VAL_UPLINK_DOWNLINK_CONFIGURATION_2                                                2
#define RFMXLTE_VAL_UPLINK_DOWNLINK_CONFIGURATION_3                                                3
#define RFMXLTE_VAL_UPLINK_DOWNLINK_CONFIGURATION_4                                                4
#define RFMXLTE_VAL_UPLINK_DOWNLINK_CONFIGURATION_5                                                5
#define RFMXLTE_VAL_UPLINK_DOWNLINK_CONFIGURATION_6                                                6

// Values for RFMXLTE_ATTR_COMPONENT_CARRIER_SPACING_TYPE
#define RFMXLTE_VAL_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL                                         0
#define RFMXLTE_VAL_COMPONENT_CARRIER_SPACING_TYPE_MINIMUM                                         1
#define RFMXLTE_VAL_COMPONENT_CARRIER_SPACING_TYPE_USER                                            2

// Values for RFMXLTE_ATTR_CYCLIC_PREFIX_MODE
#define RFMXLTE_VAL_CYCLIC_PREFIX_MODE_NORMAL                                                      0
#define RFMXLTE_VAL_CYCLIC_PREFIX_MODE_EXTENDED                                                    1

// Values for RFMXLTE_ATTR_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED
#define RFMXLTE_VAL_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_FALSE                                    0
#define RFMXLTE_VAL_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_TRUE                                     1

// Values for RFMXLTE_ATTR_AUTO_DMRS_DETECTION_ENABLED
#define RFMXLTE_VAL_AUTO_DMRS_DETECTION_ENABLED_FALSE                                              0
#define RFMXLTE_VAL_AUTO_DMRS_DETECTION_ENABLED_TRUE                                               1

// Values for RFMXLTE_ATTR_UPLINK_GROUP_HOPPING_ENABLED
#define RFMXLTE_VAL_UPLINK_GROUP_HOPPING_ENABLED_FALSE                                             0
#define RFMXLTE_VAL_UPLINK_GROUP_HOPPING_ENABLED_TRUE                                              1

// Values for RFMXLTE_ATTR_UPLINK_SEQUENCE_HOPPING_ENABLED
#define RFMXLTE_VAL_UPLINK_SEQUENCE_HOPPING_ENABLED_FALSE                                          0
#define RFMXLTE_VAL_UPLINK_SEQUENCE_HOPPING_ENABLED_TRUE                                           1

// Values for RFMXLTE_ATTR_PUSCH_MODULATION_TYPE
#define RFMXLTE_VAL_PUSCH_MODULATION_TYPE_QPSK                                                     0
#define RFMXLTE_VAL_PUSCH_MODULATION_TYPE_16_QAM                                                   1
#define RFMXLTE_VAL_PUSCH_MODULATION_TYPE_64_QAM                                                   2
#define RFMXLTE_VAL_PUSCH_MODULATION_TYPE_256_QAM                                                  3
#define RFMXLTE_VAL_PUSCH_MODULATION_TYPE_1024_QAM                                                 4

// Values for RFMXLTE_ATTR_MODACC_SYNCHRONIZATION_MODE
#define RFMXLTE_VAL_MODACC_SYNCHRONIZATION_MODE_FRAME                                              0
#define RFMXLTE_VAL_MODACC_SYNCHRONIZATION_MODE_SLOT                                               1
#define RFMXLTE_VAL_MODACC_SYNCHRONIZATION_MODE_MARKER                                             2

// Values for RFMXLTE_ATTR_MODACC_MULTICARRIER_FILTER_ENABLED
#define RFMXLTE_VAL_MODACC_MULTICARRIER_FILTER_ENABLED_FALSE                                       0
#define RFMXLTE_VAL_MODACC_MULTICARRIER_FILTER_ENABLED_TRUE                                        1

// Values for RFMXLTE_ATTR_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED
#define RFMXLTE_VAL_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED_FALSE                               0
#define RFMXLTE_VAL_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED_TRUE                                1

// Values for RFMXLTE_ATTR_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED
#define RFMXLTE_VAL_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED_FALSE                                    0
#define RFMXLTE_VAL_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED_TRUE                                     1

// Values for RFMXLTE_ATTR_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED
#define RFMXLTE_VAL_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED_FALSE                              0
#define RFMXLTE_VAL_MODACC_IQ_GAIN_IMBALANCE_CORRECTION_ENABLED_TRUE                               1

// Values for RFMXLTE_ATTR_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED
#define RFMXLTE_VAL_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED_FALSE                            0
#define RFMXLTE_VAL_MODACC_IQ_QUADRATURE_ERROR_CORRECTION_ENABLED_TRUE                             1

// Values for RFMXLTE_ATTR_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED
#define RFMXLTE_VAL_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED_FALSE                                 0
#define RFMXLTE_VAL_MODACC_IQ_TIMING_SKEW_CORRECTION_ENABLED_TRUE                                  1

// Values for RFMXLTE_ATTR_MODACC_SPECTRUM_INVERTED
#define RFMXLTE_VAL_MODACC_SPECTRUM_INVERTED_FALSE                                                 0
#define RFMXLTE_VAL_MODACC_SPECTRUM_INVERTED_TRUE                                                  1

// Values for RFMXLTE_ATTR_MODACC_CHANNEL_ESTIMATION_TYPE
#define RFMXLTE_VAL_MODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE                                       0
#define RFMXLTE_VAL_MODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE_AND_DATA                              1

// Values for RFMXLTE_ATTR_MODACC_EVM_UNIT
#define RFMXLTE_VAL_MODACC_EVM_UNIT_PERCENTAGE                                                     0
#define RFMXLTE_VAL_MODACC_EVM_UNIT_DB                                                             1

// Values for RFMXLTE_ATTR_MODACC_FFT_WINDOW_TYPE
#define RFMXLTE_VAL_MODACC_FFT_WINDOW_TYPE_3GPP                                                    0
#define RFMXLTE_VAL_MODACC_FFT_WINDOW_TYPE_CUSTOM                                                  1

// Values for RFMXLTE_ATTR_MODACC_COMMON_CLOCK_SOURCE_ENABLED
#define RFMXLTE_VAL_MODACC_COMMON_CLOCK_SOURCE_ENABLED_FALSE                                       0
#define RFMXLTE_VAL_MODACC_COMMON_CLOCK_SOURCE_ENABLED_TRUE                                        1

// Values for RFMXLTE_ATTR_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED
#define RFMXLTE_VAL_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED_FALSE                                 0
#define RFMXLTE_VAL_MODACC_EVM_WITH_EXCLUSION_PERIOD_ENABLED_TRUE                                  1

// Values for RFMXLTE_ATTR_MODACC_SPECTRAL_FLATNESS_CONDITION
#define RFMXLTE_VAL_MODACC_SPECTRAL_FLATNESS_CONDITION_NORMAL                                      0
#define RFMXLTE_VAL_MODACC_SPECTRAL_FLATNESS_CONDITION_EXTREME                                     1

// Values for RFMXLTE_ATTR_MODACC_AVERAGING_ENABLED
#define RFMXLTE_VAL_MODACC_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXLTE_VAL_MODACC_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXLTE_ATTR_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL
#define RFMXLTE_VAL_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL_SLOT                                  0
#define RFMXLTE_VAL_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL_SUBFRAME                              1
#define RFMXLTE_VAL_MODACC_PRE_FFT_ERROR_ESTIMATION_INTERVAL_MEASUREMENT_LENGTH                    2

// Values for RFMXLTE_ATTR_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED
#define RFMXLTE_VAL_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED_FALSE                             0
#define RFMXLTE_VAL_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED_TRUE                              1

// Values for RFMXLTE_ATTR_MODACC_TIMING_TRACKING_ENABLED
#define RFMXLTE_VAL_MODACC_TIMING_TRACKING_ENABLED_FALSE                                           0
#define RFMXLTE_VAL_MODACC_TIMING_TRACKING_ENABLED_TRUE                                            1

// Values for RFMXLTE_ATTR_MODACC_PHASE_TRACKING_ENABLED
#define RFMXLTE_VAL_MODACC_PHASE_TRACKING_ENABLED_FALSE                                            0
#define RFMXLTE_VAL_MODACC_PHASE_TRACKING_ENABLED_TRUE                                             1

// Values for RFMXLTE_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXLTE_VAL_ACP_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXLTE_VAL_ACP_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXLTE_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXLTE_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXLTE_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXLTE_VAL_ACP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXLTE_ATTR_ACP_SWEEP_TIME_AUTO
#define RFMXLTE_VAL_ACP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXLTE_VAL_ACP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXLTE_ATTR_ACP_POWER_UNITS
#define RFMXLTE_VAL_ACP_POWER_UNITS_DBM                                                            0
#define RFMXLTE_VAL_ACP_POWER_UNITS_DBM_BY_HZ                                                      1

// Values for RFMXLTE_ATTR_ACP_MEASUREMENT_METHOD
#define RFMXLTE_VAL_ACP_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXLTE_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1
#define RFMXLTE_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                          2

// Values for RFMXLTE_ATTR_ACP_NOISE_CALIBRATION_MODE
#define RFMXLTE_VAL_ACP_NOISE_CALIBRATION_MODE_MANUAL                                              0
#define RFMXLTE_VAL_ACP_NOISE_CALIBRATION_MODE_AUTO                                                1

// Values for RFMXLTE_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_AUTO
#define RFMXLTE_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE                                     0
#define RFMXLTE_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE                                      1

// Values for RFMXLTE_ATTR_ACP_NOISE_COMPENSATION_ENABLED
#define RFMXLTE_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXLTE_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXLTE_ATTR_ACP_NOISE_COMPENSATION_TYPE
#define RFMXLTE_VAL_ACP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION                           0
#define RFMXLTE_VAL_ACP_NOISE_COMPENSATION_TYPE_ANALYZER_ONLY                                      1

// Values for RFMXLTE_ATTR_ACP_AVERAGING_ENABLED
#define RFMXLTE_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXLTE_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXLTE_ATTR_ACP_AVERAGING_TYPE
#define RFMXLTE_VAL_ACP_AVERAGING_TYPE_RMS                                                         0
#define RFMXLTE_VAL_ACP_AVERAGING_TYPE_LOG                                                         1
#define RFMXLTE_VAL_ACP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXLTE_VAL_ACP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXLTE_VAL_ACP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXLTE_ATTR_ACP_MEASUREMENT_MODE
#define RFMXLTE_VAL_ACP_MEASUREMENT_MODE_MEASURE                                                   0
#define RFMXLTE_VAL_ACP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                     1

// Values for RFMXLTE_ATTR_ACP_FFT_OVERLAP_MODE
#define RFMXLTE_VAL_ACP_FFT_OVERLAP_MODE_DISABLED                                                  0
#define RFMXLTE_VAL_ACP_FFT_OVERLAP_MODE_AUTOMATIC                                                 1
#define RFMXLTE_VAL_ACP_FFT_OVERLAP_MODE_USER_DEFINED                                              2

// Values for RFMXLTE_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXLTE_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                          0
#define RFMXLTE_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                           1

// Values for RFMXLTE_ATTR_CHP_INTEGRATION_BANDWIDTH_TYPE
#define RFMXLTE_VAL_CHP_INTEGRATION_BANDWIDTH_TYPE_SIGNAL_BANDWIDTH                                0
#define RFMXLTE_VAL_CHP_INTEGRATION_BANDWIDTH_TYPE_CHANNEL_BANDWIDTH                               1

// Values for RFMXLTE_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXLTE_VAL_CHP_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXLTE_VAL_CHP_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXLTE_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXLTE_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXLTE_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXLTE_VAL_CHP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXLTE_ATTR_CHP_SWEEP_TIME_AUTO
#define RFMXLTE_VAL_CHP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXLTE_VAL_CHP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXLTE_ATTR_CHP_NOISE_CALIBRATION_MODE
#define RFMXLTE_VAL_CHP_NOISE_CALIBRATION_MODE_MANUAL                                              0
#define RFMXLTE_VAL_CHP_NOISE_CALIBRATION_MODE_AUTO                                                1

// Values for RFMXLTE_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_AUTO
#define RFMXLTE_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE                                     0
#define RFMXLTE_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE                                      1

// Values for RFMXLTE_ATTR_CHP_NOISE_COMPENSATION_ENABLED
#define RFMXLTE_VAL_CHP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXLTE_VAL_CHP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXLTE_ATTR_CHP_NOISE_COMPENSATION_TYPE
#define RFMXLTE_VAL_CHP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION                           0
#define RFMXLTE_VAL_CHP_NOISE_COMPENSATION_TYPE_ANALYZER_ONLY                                      1

// Values for RFMXLTE_ATTR_CHP_AVERAGING_ENABLED
#define RFMXLTE_VAL_CHP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXLTE_VAL_CHP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXLTE_ATTR_CHP_AVERAGING_TYPE
#define RFMXLTE_VAL_CHP_AVERAGING_TYPE_RMS                                                         0
#define RFMXLTE_VAL_CHP_AVERAGING_TYPE_LOG                                                         1
#define RFMXLTE_VAL_CHP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXLTE_VAL_CHP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXLTE_VAL_CHP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXLTE_ATTR_CHP_MEASUREMENT_MODE
#define RFMXLTE_VAL_CHP_MEASUREMENT_MODE_MEASURE                                                   0
#define RFMXLTE_VAL_CHP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                     1

// Values for RFMXLTE_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXLTE_VAL_OBW_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXLTE_VAL_OBW_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXLTE_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXLTE_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXLTE_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXLTE_VAL_OBW_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXLTE_ATTR_OBW_SWEEP_TIME_AUTO
#define RFMXLTE_VAL_OBW_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXLTE_VAL_OBW_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXLTE_ATTR_OBW_AVERAGING_ENABLED
#define RFMXLTE_VAL_OBW_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXLTE_VAL_OBW_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXLTE_ATTR_OBW_AVERAGING_TYPE
#define RFMXLTE_VAL_OBW_AVERAGING_TYPE_RMS                                                         0
#define RFMXLTE_VAL_OBW_AVERAGING_TYPE_LOG                                                         1
#define RFMXLTE_VAL_OBW_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXLTE_VAL_OBW_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXLTE_VAL_OBW_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXLTE_ATTR_SEM_OFFSET_SIDEBAND
#define RFMXLTE_VAL_SEM_OFFSET_SIDEBAND_NEGATIVE                                                   0
#define RFMXLTE_VAL_SEM_OFFSET_SIDEBAND_POSITIVE                                                   1
#define RFMXLTE_VAL_SEM_OFFSET_SIDEBAND_BOTH                                                       2

// Values for RFMXLTE_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXLTE_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FFT_BASED                                           0
#define RFMXLTE_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN                                            1
#define RFMXLTE_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FLAT                                                2

// Values for RFMXLTE_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXLTE_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXLTE_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXLTE_ATTR_SEM_AVERAGING_ENABLED
#define RFMXLTE_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXLTE_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXLTE_ATTR_SEM_AVERAGING_TYPE
#define RFMXLTE_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXLTE_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXLTE_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXLTE_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXLTE_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXLTE_ATTR_SEM_RESULTS_MEASUREMENT_STATUS
#define RFMXLTE_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXLTE_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXLTE_ATTR_DMRS_OCC_ENABLED
#define RFMXLTE_VAL_DMRS_OCC_ENABLED_FALSE                                                         0
#define RFMXLTE_VAL_DMRS_OCC_ENABLED_TRUE                                                          1

// Values for RFMXLTE_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXLTE_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXLTE_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXLTE_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXLTE_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXLTE_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXLTE_ATTR_PVT_MEASUREMENT_METHOD
#define RFMXLTE_VAL_PVT_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXLTE_VAL_PVT_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1

// Values for RFMXLTE_ATTR_PVT_AVERAGING_ENABLED
#define RFMXLTE_VAL_PVT_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXLTE_VAL_PVT_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXLTE_ATTR_PVT_AVERAGING_TYPE
#define RFMXLTE_VAL_PVT_AVERAGING_TYPE_RMS                                                         0
#define RFMXLTE_VAL_PVT_AVERAGING_TYPE_LOG                                                         1

// Values for RFMXLTE_ATTR_PVT_RESULTS_MEASUREMENT_STATUS
#define RFMXLTE_VAL_PVT_RESULTS_MEASUREMENT_STATUS_FAIL                                            0
#define RFMXLTE_VAL_PVT_RESULTS_MEASUREMENT_STATUS_PASS                                            1

// Values for RFMXLTE_ATTR_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED
#define RFMXLTE_VAL_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED_FALSE                               0
#define RFMXLTE_VAL_ACQUISITION_BANDWIDTH_OPTIMIZATION_ENABLED_TRUE                                1

// Values for RFMXLTE_ATTR_TRANSMITTER_ARCHITECTURE
#define RFMXLTE_VAL_TRANSMITTER_ARCHITECTURE_LO_PER_COMPONENT_CARRIER                              0
#define RFMXLTE_VAL_TRANSMITTER_ARCHITECTURE_LO_PER_SUBBLOCK                                       1

// Values for RFMXLTE_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXLTE_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXLTE_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXLTE_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXLTE_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXLTE_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXLTE_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Boolean
#define RFMXLTE_VAL_FALSE                                                                          0
#define RFMXLTE_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXLTE_VAL_ACP                                                                            1 << 0
#define RFMXLTE_VAL_CHP                                                                            1 << 1
#define RFMXLTE_VAL_MODACC                                                                         1 << 2
#define RFMXLTE_VAL_OBW                                                                            1 << 3
#define RFMXLTE_VAL_SEM                                                                            1 << 4
#define RFMXLTE_VAL_PVT                                                                            1 << 5
#define RFMXLTE_VAL_SLOTPHASE                                                                      1 << 6
#define RFMXLTE_VAL_SLOTPOWER                                                                      1 << 7

// Values for FrequencyReferenceSource
#define RFMXLTE_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXLTE_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXLTE_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXLTE_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for RFAttenuationAuto
#define RFMXLTE_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXLTE_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXLTE_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXLTE_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

// Values for RFMXLTE_ATTR_LINK_DIRECTION
#define RFMXLTE_VAL_LINK_DIRECTION_DOWNLINK                                                        0
#define RFMXLTE_VAL_LINK_DIRECTION_UPLINK                                                          1
#define RFMXLTE_VAL_LINK_DIRECTION_SIDELINK                                                        2

// Values for RFMXLTE_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE
#define RFMXLTE_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_FRAME                                           0
#define RFMXLTE_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_SLOT                                            1

// Values for RFMXLTE_ATTR_SLOTPHASE_EXCLUSION_PERIOD_ENABLED
#define RFMXLTE_VAL_SLOTPHASE_EXCLUSION_PERIOD_ENABLED_FALSE                                       0
#define RFMXLTE_VAL_SLOTPHASE_EXCLUSION_PERIOD_ENABLED_TRUE                                        1

// Values for RFMXLTE_ATTR_SLOTPHASE_COMMON_CLOCK_SOURCE_ENABLED
#define RFMXLTE_VAL_SLOTPHASE_COMMON_CLOCK_SOURCE_ENABLED_FALSE                                    0
#define RFMXLTE_VAL_SLOTPHASE_COMMON_CLOCK_SOURCE_ENABLED_TRUE                                     1

// Values for RFMXLTE_ATTR_SLOTPHASE_SPECTRUM_INVERTED
#define RFMXLTE_VAL_SLOTPHASE_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXLTE_VAL_SLOTPHASE_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXLTE_ATTR_SLOTPOWER_COMMON_CLOCK_SOURCE_ENABLED
#define RFMXLTE_VAL_SLOTPOWER_COMMON_CLOCK_SOURCE_ENABLED_FALSE                                    0
#define RFMXLTE_VAL_SLOTPOWER_COMMON_CLOCK_SOURCE_ENABLED_TRUE                                     1

// Values for RFMXLTE_ATTR_SLOTPOWER_SPECTRUM_INVERTED
#define RFMXLTE_VAL_SLOTPOWER_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXLTE_VAL_SLOTPOWER_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXLTE_ATTR_DOWNLINK_AUTO_CELL_ID_DETECTION_ENABLED
#define RFMXLTE_VAL_DOWNLINK_AUTO_CELL_ID_DETECTION_ENABLED_FALSE                                  0
#define RFMXLTE_VAL_DOWNLINK_AUTO_CELL_ID_DETECTION_ENABLED_TRUE                                   1

// Values for RFMXLTE_ATTR_DOWNLINK_CHANNEL_CONFIGURATION_MODE
#define RFMXLTE_VAL_DOWNLINK_CHANNEL_CONFIGURATION_MODE_USER_DEFINED                               1
#define RFMXLTE_VAL_DOWNLINK_CHANNEL_CONFIGURATION_MODE_TEST_MODEL                                 2

// Values for RFMXLTE_ATTR_DOWNLINK_USER_DEFINED_CELL_SPECIFIC_RATIO
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_RATIO_P_B0                                               0
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_RATIO_P_B1                                               1
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_RATIO_P_B2                                               2
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_RATIO_P_B3                                               3

// Values for RFMXLTE_ATTR_PHICH_RESOURCE
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_PHICH_RESOURCE_ONE_SIXTH                                 0
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_PHICH_RESOURCE_HALF                                      1
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_PHICH_RESOURCE_ONE                                       2
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_PHICH_RESOURCE_TWO                                       3

// Values for RFMXLTE_ATTR_PHICH_DURATION
#define RFMXLTE_VAL_DOWNLINK_USER_DEFINED_PHICH_DURATION_NORMAL                                    0

// Values for RFMXLTE_ATTR_PDSCH_CW0_MODULATION_TYPE
#define RFMXLTE_VAL_USER_DEFINED_PDSCH_CW0_MODULATION_TYPE_QPSK                                    0
#define RFMXLTE_VAL_USER_DEFINED_PDSCH_CW0_MODULATION_TYPE_QAM16                                   1
#define RFMXLTE_VAL_USER_DEFINED_PDSCH_CW0_MODULATION_TYPE_QAM64                                   2
#define RFMXLTE_VAL_USER_DEFINED_PDSCH_CW0_MODULATION_TYPE_QAM256                                  3
#define RFMXLTE_VAL_USER_DEFINED_PDSCH_CW0_MODULATION_TYPE_QAM1024                                 4

// Values for RFMXLTE_ATTR_DOWNLINK_TEST_MODEL
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM1_1                                                      0
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM1_2                                                      1
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM2                                                        2
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM2A                                                       3
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM3_1                                                      4
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM3_2                                                      5
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM3_3                                                      6
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM3_1A                                                     7
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM2B                                                       8
#define RFMXLTE_VAL_DOWNLINK_TEST_MODEL_TM3_1B                                                     9

// Values for RFMXLTE_ATTR_ENODEB_CATEGORY
#define RFMXLTE_VAL_ENODEB_WIDE_AREA_BASE_STATION_CATEGORY_A                                       0
#define RFMXLTE_VAL_ENODEB_WIDE_AREA_BASE_STATION_CATEGORY_B_OPTION1                               1
#define RFMXLTE_VAL_ENODEB_WIDE_AREA_BASE_STATION_CATEGORY_B_OPTION2                               2
#define RFMXLTE_VAL_ENODEB_LOCAL_AREA_BASE_STATION                                                 3
#define RFMXLTE_VAL_ENODEB_HOME_BASE_STATION                                                       4
#define RFMXLTE_VAL_ENODEB_MEDIUM_RANGE_BASE_STATION                                               5

// Values for RFMXLTE_ATTR_MODACC_MULTICARRIER_TIME_SYNCHRONIZATION_MODE
#define RFMXLTE_VAL_MODACC_MULTICARRIER_TIME_SYNCHRONIZATION_MODE_COMMON                           0
#define RFMXLTE_VAL_MODACC_MULTICARRIER_TIME_SYNCHRONIZATION_MODE_PER_CARRIER                      1

// Values for RFMXLTE_ATTR_SRS_ENABLED
#define RFMXLTE_VAL_SRS_ENABLED_FALSE                                                              0
#define RFMXLTE_VAL_SRS_ENABLED_TRUE                                                               1

// Values for RFMXLTE_ATTR_SRS_MAXIMUM_UpPTS_ENABLED
#define RRFMXLTE_VAL_SRS_MAXIMUM_UpPTS_ENABLED_FALSE                                               0
#define RRFMXLTE_VAL_SRS_MAXIMUM_UpPTS_ENABLED_TRUE                                                1

// Values for RFMXLTE_ATTR_SEM_UPLINK_MASK_TYPE
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_GENERAL_NS01                                              0
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS03_OR_NS11_OR_NS20_OR_NS21                              1
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS04                                                      2
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS06_OR_NS07                                              3
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_CANS04                                                    4
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_CUSTOM                                                    5
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_GENERAL_CACLASSB                                          6
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_CANCNS01                                                  7
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS27_OR_NS43                                              8
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS35                                                      9
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS28                                                      10
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_CANS09                                                    11
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_CANS10                                                    12

// Values for RFMXLTE_ATTR_SEM_DOWNLINK_MASK_TYPE
#define RFMXLTE_VAL_SEM_DOWNLINK_MASK_TYPE_ENODEB_CATEGORY_BASED                                   0
#define RFMXLTE_VAL_SEM_DOWNLINK_MASK_TYPE_BAND46                                                  1
#define RFMXLTE_VAL_SEM_DOWNLINK_MASK_TYPE_CUSTOM                                                  5

// Values for RFMXLTE_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE
#define RFMXLTE_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXLTE_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXLTE_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE
#define RFMXLTE_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXLTE_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXLTE_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE
#define RFMXLTE_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXLTE_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXLTE_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE
#define RFMXLTE_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXLTE_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXLTE_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK
#define RFMXLTE_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABS_AND_REL                                         0
#define RFMXLTE_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABS_OR_REL                                          1
#define RFMXLTE_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE                                            2
#define RFMXLTE_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_RELATIVE                                            3

// Values for RFMXLTE_ATTR_AUTO_PDSCH_CHANNEL_DETECTION_ENABLED
#define RFMXLTE_VAL_AUTO_PDSCH_CHANNEL_DETECTION_ENABLED_FALSE                                     0
#define RFMXLTE_VAL_AUTO_PDSCH_CHANNEL_DETECTION_ENABLED_TRUE                                      1

// Values for RFMXLTE_ATTR_AUTO_CONTROL_CHANNEL_POWER_DETECTION_ENABLED
#define RFMXLTE_VAL_AUTO_CONTROL_CHANNEL_POWER_DETECTION_ENABLED_FALSE                             0
#define RFMXLTE_VAL_AUTO_CONTROL_CHANNEL_POWER_DETECTION_ENABLED_TRUE                              1

// Values for RFMXLTE_ATTR_AUTO_PCFICH_CFI_DETECTION_ENABLED
#define RFMXLTE_VAL_AUTO_PCFICH_CFI_DETECTION_ENABLED_FALSE                                        0
#define RFMXLTE_VAL_AUTO_PCFICH_CFI_DETECTION_ENABLED_TRUE                                         1

// Values for RFMXLTE_ATTR_LAA_UPLINK_START_POSITION
#define RFMXLTE_VAL_LAA_UPLINK_START_POSITION_00                                                   0
#define RFMXLTE_VAL_LAA_UPLINK_START_POSITION_01                                                   1
#define RFMXLTE_VAL_LAA_UPLINK_START_POSITION_10                                                   2
#define RFMXLTE_VAL_LAA_UPLINK_START_POSITION_11                                                   3

// Values for RFMXLTE_ATTR_LAA_UPLINK_ENDING_SYMBOL
#define RFMXLTE_VAL_LAA_UPLINK_ENDING_SYMBOL_12                                                    12
#define RFMXLTE_VAL_LAA_UPLINK_ENDING_SYMBOL_13                                                    13

// Values for RFMXLTE_ATTR_LAA_DOWNLINK_STARTING_SYMBOL
#define RFMXLTE_VAL_LAA_DOWNLINK_STARTING_SYMBOL_0                                                 0
#define RFMXLTE_VAL_LAA_DOWNLINK_STARTING_SYMBOL_7                                                 7

// Values for RFMXLTE_ATTR_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS
#define RFMXLTE_VAL_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS_3                                        3
#define RFMXLTE_VAL_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS_6                                        6
#define RFMXLTE_VAL_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS_9                                        9
#define RFMXLTE_VAL_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS_10                                       10
#define RFMXLTE_VAL_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS_11                                       11
#define RFMXLTE_VAL_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS_12                                       12
#define RFMXLTE_VAL_LAA_DOWNLINK_NUMBER_OF_ENDING_SYMBOLS_14                                       14

// Values for RFMXLTE_ATTR_NB_IOT_UPLINK_SUBCARRIER_SPACING
#define RFMXLTE_VAL_NB_IOT_UPLINK_SUBCARRIER_SPACING_15KHZ                                         0
#define RFMXLTE_VAL_NB_IOT_UPLINK_SUBCARRIER_SPACING_3_75KHZ                                       1

// Values for RFMXLTE_ATTR_AUTO_NPUSCH_CHANNEL_DETECTION_ENABLED
#define RFMXLTE_VAL_AUTO_NPUSCH_CHANNEL_DETECTION_ENABLED_FALSE                                    0
#define RFMXLTE_VAL_AUTO_NPUSCH_CHANNEL_DETECTION_ENABLED_TRUE                                     1

// Values for RFMXLTE_ATTR_NPUSCH_MODULATION_TYPE
#define RFMXLTE_VAL_NPUSCH_MODULATION_TYPE_BPSK                                                    0
#define RFMXLTE_VAL_NPUSCH_MODULATION_TYPE_QPSK                                                    1

// Values for RFMXLTE_ATTR_NPUSCH_DMRS_BASE_SEQUENCE_MODE
#define RFMXLTE_VAL_NPUSCH_DMRS_BASE_SEQUENCE_MODE_MANUAL                                          0
#define RFMXLTE_VAL_NPUSCH_DMRS_BASE_SEQUENCE_MODE_AUTO                                            1

// Values for RFMXLTE_ATTR_MI_CONFIGURATION
#define RFMXLTE_VAL_MI_CONFIGURATION_TEST_MODEL                                                    0
#define RFMXLTE_VAL_MI_CONFIGURATION_STANDARD                                                      1

// Values for RFMXLTE_ATTR_NPUSCH_DMRS_GROUP_HOPPING_ENABLED
#define RFMXLTE_VAL_NPUSCH_DMRS_GROUP_HOPPING_ENABLED_FALSE                                        0
#define RFMXLTE_VAL_NPUSCH_DMRS_GROUP_HOPPING_ENABLED_TRUE                                         1

// Values for RFMXLTE_ATTR_EMTC_ANALYSIS_ENABLED
#define RFMXLTE_VAL_EMTC_ANALYSIS_ENABLED_FALSE                                                    0
#define RFMXLTE_VAL_EMTC_ANALYSIS_ENABLED_TRUE                                                     1

// Values for RFMXLTE_ATTR_ACP_EUTRA_OFFSET_DEFINITION
#define RFMXLTE_VAL_ACP_EUTRA_OFFSET_DEFINITION_AUTO                                               0
#define RFMXLTE_VAL_ACP_EUTRA_OFFSET_DEFINITION_CLOSEST                                            1
#define RFMXLTE_VAL_ACP_EUTRA_OFFSET_DEFINITION_COMPOSITE                                          2

// Values for RFMXLTE_ATTR_ACP_CONFIGURABLE_NUMBER_OF_OFFSETS_ENABLED
#define RFMXLTE_VAL_ACP_CONFIGURABLE_NUMBER_OF_OFFSETS_ENABLED_FALSE                               0
#define RFMXLTE_VAL_ACP_CONFIGURABLE_NUMBER_OF_OFFSETS_ENABLED_TRUE                                1

// Values for RFMXLTE_ATTR_MODACC_IN_BAND_EMISSION_MASK_TYPE
#define RFMXLTE_VAL_MODACC_IN_BAND_EMISSION_MASK_TYPE_RELEASE_8_10                                 0
#define RFMXLTE_VAL_MODACC_IN_BAND_EMISSION_MASK_TYPE_RELEASE_11_ONWARDS                           1

// Values for RFMXLTE_ATTR_PSSCH_MODULATION_TYPE
#define RFMXLTE_VAL_PSSCH_MODULATION_TYPE_QPSK                                                     0
#define RFMXLTE_VAL_PSSCH_MODULATION_TYPE_QAM16                                                    1
#define RFMXLTE_VAL_PSSCH_MODULATION_TYPE_QAM64                                                    2

// Values for RFMXLTE_ATTR_SEM_SIDELINK_MASK_TYPE
#define RFMXLTE_VAL_SEM_SIDELINK_MASK_TYPE_GENERAL_NS01                                            0
#define RFMXLTE_VAL_SEM_SIDELINK_MASK_TYPE_NS33_OR_NS34                                            1
#define RFMXLTE_VAL_SEM_SIDELINK_MASK_TYPE_CUSTOM                                                  5

// Values for AcpNoiseCalibrationDataValid
#define RFMXLTE_VAL_ACP_NOISE_CALIBRATION_DATA_VALID_FALSE                                         0
#define RFMXLTE_VAL_ACP_NOISE_CALIBRATION_DATA_VALID_TRUE                                          1

// Values for ChpNoiseCalibrationDataValid
#define RFMXLTE_VAL_CHP_NOISE_CALIBRATION_DATA_VALID_FALSE                                         0
#define RFMXLTE_VAL_CHP_NOISE_CALIBRATION_DATA_VALID_TRUE                                          1

/* ---------------- RFmxLTE APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxLTE_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxLTE_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxLTE_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxLTE_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxLTE_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxLTE_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxLTE_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxLTE_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxLTE_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxLTE_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxLTE_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxLTE_BuildClusterString(
   char selectorString[],
   int32 clusterNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxLTE_BuildCarrierString(
   char selectorString[],
   int32 carrierNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxLTE_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxLTE_BuildSubblockString(
   char selectorString[],
   int32 subblockNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxLTE_BuildSubframeString(
   char selectorString[],
   int32 subframeNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxLTE_BuildPDSCHString(
   char selectorString[],
   int32 PDSCHNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxLTE_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxLTE_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxLTE_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxLTE_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxLTE_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxLTE_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxLTE_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxLTE_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxLTE_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxLTE_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxLTE_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxLTE_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxLTE_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxLTE_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxLTE_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxLTE_CfgFrequencyEARFCN(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 linkDirection,
   int32 band,
   int32 EARFCN
);

int32 __stdcall RFmxLTE_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxLTE_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxLTE_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxLTE_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxLTE_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxLTE_ClearNoiseCalibrationDatabase(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxLTE_ACPValidateNoiseCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* noiseCalibrationDataValid
);

int32 __stdcall RFmxLTE_CHPValidateNoiseCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* noiseCalibrationDataValid
);

int32 __stdcall RFmxLTE_CfgAutoResourceBlockDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoResourceBlockDetectionEnabled
);

int32 __stdcall RFmxLTE_CfgNumberOfPUSCHResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfResourceBlockClusters
);

int32 __stdcall RFmxLTE_CfgPUSCHResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 resourceBlockOffset,
   int32 numberOfResourceBlocks
);

int32 __stdcall RFmxLTE_CfgPUSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 modulationType
);

int32 __stdcall RFmxLTE_CfgComponentCarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 componentCarrierSpacingType,
   int32 componentCarrierAtCenterFrequency
);

int32 __stdcall RFmxLTE_CfgComponentCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 componentCarrierBandwidth,
   float64 componentCarrierFrequency,
   int32 cellID
);

int32 __stdcall RFmxLTE_CfgAutoDMRSDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoDMRSDetectionEnabled
);

int32 __stdcall RFmxLTE_CfgNumberOfSubblocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSubblocks
);

int32 __stdcall RFmxLTE_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxLTE_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxLTE_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxLTE_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxLTE_CfgNumberOfComponentCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfComponentCarriers
);

int32 __stdcall RFmxLTE_CfgBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 band
);

int32 __stdcall RFmxLTE_CfgDuplexScheme(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 duplexScheme,
   int32 uplinkDownlinkConfiguration
);

int32 __stdcall RFmxLTE_CfgLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 linkDirection
);

int32 __stdcall RFmxLTE_CfgNumberOfDUTAntennas(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfDUTAntennas
);

int32 __stdcall RFmxLTE_CfgTransmitAntennaToAnalyze(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 transmitAntennaToAnalyze
);

int32 __stdcall RFmxLTE_CfgDownlinkAutoCellIDDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoCellIDDetectionEnabled
);

int32 __stdcall RFmxLTE_CfgDownlinkChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelConfigurationMode
);

int32 __stdcall RFmxLTE_CfgDownlinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 downlinkTestModel
);

int32 __stdcall RFmxLTE_CfgCellSpecificRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 cellSpecificRatio
);

int32 __stdcall RFmxLTE_CfgDownlinkSynchronizationSignal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 PSSPower,
   float64 SSSPower
);

int32 __stdcall RFmxLTE_CfgPBCH(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 PBCHPower
);

int32 __stdcall RFmxLTE_CfgPDCCH(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 PDCCHPower
);

int32 __stdcall RFmxLTE_CfgDownlinkNumberOfSubframes(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSubframes
);

int32 __stdcall RFmxLTE_CfgPCFICH(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 CFI,
   float64 power
);

int32 __stdcall RFmxLTE_CfgPHICH(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 resource,
   int32 duration,
   float64 power
);

int32 __stdcall RFmxLTE_CfgNumberOfPDSCHChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfPDSCHChannels
);

int32 __stdcall RFmxLTE_CfgPDSCH(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 CW0ModulationType,
   char resourceBlockAllocation[],
   float64 power
);

int32 __stdcall RFmxLTE_CfgeNodeBCategory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 eNodeBCategory
);

int32 __stdcall RFmxLTE_CfgNBIoTComponentCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 NCellID,
   int32 uplinkSubcarrierSpacing
);

int32 __stdcall RFmxLTE_CfgAutoNPUSCHChannelDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoNPUSCHChannelDetectionEnabled
);

int32 __stdcall RFmxLTE_CfgNPUSCHFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 format
);

int32 __stdcall RFmxLTE_CfgNPUSCHTones(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 toneOffset,
   int32 numberOfTones,
   int32 modulationType
);

int32 __stdcall RFmxLTE_CfgNPUSCHDMRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 NPUSCHDMRSBaseSequenceMode,
   int32 NPUSCHDMRSBaseSequenceIndex,
   int32 NPUSCHDMRSCyclicShift,
   int32 NPUSCHDMRSGroupHoppingEnabled,
   int32 NPUSCHDMRSDeltaSS
);

int32 __stdcall RFmxLTE_CfgEMTCAnalysisEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 EMTCAnalysisEnabled
);

int32 __stdcall RFmxLTE_CfgNPUSCHStartingSlot(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 startingSlot
);

int32 __stdcall RFmxLTE_CfgPSSCHResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 resourceBlockOffset,
   int32 numberOfResourceBlocks
);

int32 __stdcall RFmxLTE_CfgPSSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 modulationType
);

int32 __stdcall RFmxLTE_CfgComponentCarrierArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 componentCarrierBandwidth[],
   float64 componentCarrierFrequency[],
   int32 cellID[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_CfgDownlinkTestModelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 downlinkTestModel[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxLTE_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxLTE_SEMCfgUplinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkMaskType
);

int32 __stdcall RFmxLTE_SEMCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxLTE_SEMCfgOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetStartFrequency,
   float64 offsetStopFrequency,
   int32 offsetSideband
);

int32 __stdcall RFmxLTE_SEMCfgOffsetRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetRBW,
   int32 offsetRBWFilterType
);

int32 __stdcall RFmxLTE_SEMCfgOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetBandwidthIntegral
);

int32 __stdcall RFmxLTE_SEMCfgOffsetAbsoluteLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetAbsoluteLimitStart,
   float64 offsetAbsoluteLimitStop
);

int32 __stdcall RFmxLTE_SEMCfgDownlinkMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 downlinkMaskType,
   float64 deltaFMaximum,
   float64 aggregatedMaximumPower
);

int32 __stdcall RFmxLTE_SEMCfgOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 limitFailMask
);

int32 __stdcall RFmxLTE_SEMCfgOffsetRelativeLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeLimitStart,
   float64 relativeLimitStop
);

int32 __stdcall RFmxLTE_SEMCfgComponentCarrierMaximumOutputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 componentCarrierMaximumOutputPower
);

int32 __stdcall RFmxLTE_SEMCfgOffsetFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetStartFrequency[],
   float64 offsetStopFrequency[],
   int32 offsetSideband[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_SEMCfgOffsetRBWFilterArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetRBW[],
   int32 offsetRBWFilterType[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_SEMCfgOffsetBandwidthIntegralArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetBandwidthIntegral[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_SEMCfgOffsetAbsoluteLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetAbsoluteLimitStart[],
   float64 offsetAbsoluteLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_SEMCfgOffsetRelativeLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeLimitStart[],
   float64 relativeLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_SEMCfgOffsetLimitFailMaskArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 limitFailMask[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_SEMCfgComponentCarrierMaximumOutputPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 componentCarrierMaximumOutputPower[],
   int32 numberOfElements
);

int32 __stdcall RFmxLTE_PVTCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxLTE_PVTCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxLTE_PVTCfgOFFPowerExclusionPeriods(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 OFFPowerExclusionBefore,
   float64 OFFPowerExclusionAfter
);

int32 __stdcall RFmxLTE_CHPCfgIntegrationBandwidthType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 integrationBandwidthType
);

int32 __stdcall RFmxLTE_CHPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxLTE_CHPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxLTE_CHPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxLTE_OBWCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxLTE_OBWCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxLTE_OBWCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxLTE_ACPCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxLTE_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxLTE_ACPCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxLTE_ACPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxLTE_ACPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxLTE_ACPCfgUTRAAndEUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfUTRAOffsets,
   int32 numberOfEUTRAOffsets
);

int32 __stdcall RFmxLTE_ACPCfgPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnits
);

int32 __stdcall RFmxLTE_ACPCfgConfigurableNumberOfOffsetsEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 configurableNumberOfOffsetsEnabled
);

int32 __stdcall RFmxLTE_ACPCfgNumberOfUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfUTRAOffsets
);

int32 __stdcall RFmxLTE_ACPCfgNumberOfEUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfEUTRAOffsets
);

int32 __stdcall RFmxLTE_ACPCfgNumberOfGSMOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfGSMOffsets
);

int32 __stdcall RFmxLTE_ModAccCfgCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 commonClockSourceEnabled
);

int32 __stdcall RFmxLTE_ModAccCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxLTE_ModAccCfgEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 EVMUnit
);

int32 __stdcall RFmxLTE_ModAccCfgFFTWindowOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 FFTWindowOffset
);

int32 __stdcall RFmxLTE_ModAccCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxLTE_ModAccCfgFFTWindowPosition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindowType,
   float64 FFTWindowOffset,
   float64 FFTWindowLength
);

int32 __stdcall RFmxLTE_ModAccCfgInBandEmissionMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 inBandEmissionMaskType
);

int32 __stdcall RFmxLTE_SlotPowerCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxLTE_SlotPhaseCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxLTE_ModAccFetchSpectralFlatnessTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectralFlatness[],
   float32 spectralFlatnessLowerMask[],
   float32 spectralFlatnessUpperMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle dataConstellation[],
   int32 dataConstellationArraySize,
   int32* dataConstellationActualArraySize,
   NIComplexSingle DMRSConstellation[],
   int32 DMRSConstellationArraySize,
   int32* DMRSConstellationActualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 dataConstellationI[],
   float32 dataConstellationQ[],
   int32 dataConstellationArraySize,
   int32* dataConstellationActualArraySize,
   float32 DMRSConstellationI[],
   float32 DMRSConstellationQ[],
   int32 DMRSConstellationArraySize,
   int32* DMRSConstellationActualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSynchronizationSignalConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle SSSConstellation[],
   NIComplexSingle PSSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSynchronizationSignalConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 SSSConstellationI[],
   float32 SSSConstellationQ[],
   float32 PSSConstellationI[],
   float32 PSSConstellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchNPUSCHConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle dataConstellation[],
   int32 dataConstellationArraySize,
   int32* dataConstellationActualArraySize,
   NIComplexSingle DMRSConstellation[],
   int32 DMRSConstellationArraySize,
   int32* DMRSConstellationActualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchNPUSCHConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 dataConstellationI[],
   float32 dataConstellationQ[],
   int32 dataConstellationArraySize,
   int32* dataConstellationActualArraySize,
   float32 DMRSConstellationI[],
   float32 DMRSConstellationQ[],
   int32 DMRSConstellationArraySize,
   int32* DMRSConstellationActualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle dataConstellation[],
   int32 dataConstellationArraySize,
   int32* dataConstellationActualArraySize,
   NIComplexSingle DMRSConstellation[],
   int32 DMRSConstellationArraySize,
   int32* DMRSConstellationActualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 dataConstellationI[],
   float32 dataConstellationQ[],
   int32 dataConstellationArraySize,
   int32* dataConstellationActualArraySize,
   float32 DMRSConstellationI[],
   float32 DMRSConstellationQ[],
   int32 DMRSConstellationArraySize,
   int32* DMRSConstellationActualArraySize
);

int32 __stdcall RFmxLTE_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxLTE_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxLTE_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxLTE_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxLTE_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxLTE_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxLTE_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxLTE_CfgDownlinkAutoChannelDetection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoPDSCHChannelDetectionEnabled,
   int32 autoControlChannelPowerDetectionEnabled,
   int32 autoPCFICHCFIDetectionEnabled,
   int32 reserved
);

int32 __stdcall RFmxLTE_ACPFetchOffsetMeasurementArray(
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

int32 __stdcall RFmxLTE_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ACPFetchComponentCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ACPFetchAbsolutePowersTrace(
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

int32 __stdcall RFmxLTE_ACPFetchRelativePowersTrace(
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

int32 __stdcall RFmxLTE_ACPFetchTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAggregatedPower
);

int32 __stdcall RFmxLTE_ACPFetchSubblockMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower,
   float64* integrationBandwidth,
   float64* frequency
);

int32 __stdcall RFmxLTE_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower
);

int32 __stdcall RFmxLTE_ACPFetchComponentCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxLTE_CHPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_CHPFetchComponentCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_CHPFetchTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAggregatedPower
);

int32 __stdcall RFmxLTE_CHPFetchSubblockMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower,
   float64* integrationBandwidth,
   float64* frequency
);

int32 __stdcall RFmxLTE_CHPFetchComponentCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxLTE_PVTFetchMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 measurementStatus[],
   float64 meanAbsoluteOFFPowerBefore[],
   float64 meanAbsoluteOFFPowerAfter[],
   float64 meanAbsoluteONPower[],
   float64 burstWidth[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_PVTFetchSignalPowerTrace(
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

int32 __stdcall RFmxLTE_PVTFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* meanAbsoluteOFFPowerBefore,
   float64* meanAbsoluteOFFPowerAfter,
   float64* meanAbsoluteONPower,
   float64* burstWidth
);

int32 __stdcall RFmxLTE_OBWFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_OBWFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* absolutePower,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxLTE_SEMFetchSpectrum(
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

int32 __stdcall RFmxLTE_SEMFetchLowerOffsetPowerArray(
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

int32 __stdcall RFmxLTE_SEMFetchUpperOffsetPowerArray(
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

int32 __stdcall RFmxLTE_SEMFetchLowerOffsetMarginArray(
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

int32 __stdcall RFmxLTE_SEMFetchUpperOffsetMarginArray(
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

int32 __stdcall RFmxLTE_SEMFetchComponentCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absoluteIntegratedPower[],
   float64 relativeIntegratedPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SEMFetchTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAggregatedPower
);

int32 __stdcall RFmxLTE_SEMFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxLTE_SEMFetchSubblockMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockPower,
   float64* integrationBandwidth,
   float64* frequency
);

int32 __stdcall RFmxLTE_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxLTE_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxLTE_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxLTE_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxLTE_SEMFetchComponentCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower
);

int32 __stdcall RFmxLTE_ModAccFetchCompositeEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSCompositeEVM[],
   float64 maximumPeakCompositeEVM[],
   float64 meanFrequencyError[],
   int32 peakCompositeEVMSymbolIndex[],
   int32 peakCompositeEVMSubcarrierIndex[],
   int32 peakCompositeEVMSlotIndex[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchInBandEmissionMarginArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 inBandEmissionMargin[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchIQImpairmentsArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanIQOriginOffset[],
   float64 meanIQGainImbalance[],
   float64 meanIQQuadratureError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHDemodulatedBits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int8 bits[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHDataEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSDataEVM[],
   float64 maximumPeakDataEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHDMRSEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSDMRSEVM[],
   float64 maximumPeakDMRSEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHSymbolPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 PUSCHMeanDataPower[],
   float64 PUSCHMeanDMRSPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSpectralFlatnessArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 range1MaximumToRange1Minimum[],
   float64 range2MaximumToRange2Minimum[],
   float64 range1MaximumToRange2Minimum[],
   float64 range2MaximumToRange1Minimum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchInBandEmissionTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 inBandEmission[],
   float32 inBandEmissionMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchEVMPerSlotTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMPerSlot[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchEVMPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchEVMPerSubcarrierTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 meanRMSEVMPerSubcarrier[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchCompositeMagnitudeAndPhaseErrorArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSCompositeMagnitudeError[],
   float64 maximumPeakCompositeMagnitudeError[],
   float64 meanRMSCompositePhaseError[],
   float64 maximumPeakCompositePhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchMaximumEVMPerSubcarrierTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumEVMPerSubcarrier[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchMaximumEVMPerSlotTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumEVMPerSlot[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchMaximumEVMPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumEVMPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchEVMHighPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVMHighPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchEVMLowPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVMLowPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchRMSMagnitudeErrorPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSMagnitudeErrorPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchMaximumMagnitudeErrorPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumMagnitudeErrorPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchRMSPhaseErrorPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSPhaseErrorPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchMaximumPhaseErrorPerSymbolTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumPhaseErrorPerSymbol[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSubblockInBandEmissionTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 subblockInBandEmission[],
   float64 subblockInBandEmissionMask[],
   float64 subblockInBandEmissionRBIndices[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchCSRSConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle CSRSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchCSRSConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSRSConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle SRSConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSRSConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchCSRSEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSCSRSEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSynchronizationSignalEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSPSSEVM[],
   float64 meanRMSSSSEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchMaximumFrequencyErrorPerSlotTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 maximumFrequencyErrorPerSlot[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchSRSEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSSRSEVM[],
   float64 meanSRSPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCHEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMSEVM[],
   float64 meanRMSQPSKEVM[],
   float64 meanRMS16QAMEVM[],
   float64 meanRMS64QAMEVM[],
   float64 meanRMS256QAMEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkTransmitPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 RSTransmitPower[],
   float64 OFDMSymbolTransmitPower[],
   float64 reserved1[],
   float64 reserved2[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkDetectedCellIDArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 detectedCellID[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPBCHConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PBCHConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPBCHConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPCFICHConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PCFICHConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPCFICHConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPDCCHConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PDCCHConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPDCCHConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPHICHConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle PHICHConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkPHICHConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCHQPSKConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QPSKConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCHQPSKConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH16QAMConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM16Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH16QAMConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH64QAMConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM64Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH64QAMConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH256QAMConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM256Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH256QAMConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH1024QAMEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRMS1024QAMEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH1024QAMConstellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle QAM1024Constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH1024QAMConstellationSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHDataEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 PSSCHMeanRMSDataEVM[],
   float64 PSSCHMaximumPeakDataEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHSymbolPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 PSSCHMeanDataPower[],
   float64 PSSCHMeanDMRSPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHDMRSEVMArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 PSSCHMeanRMSDMRSEVM[],
   float64 PSSCHMaximumPeakDMRSEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_ModAccFetchCompositeEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSCompositeEVM,
   float64* maximumPeakCompositeEVM,
   float64* meanFrequencyError,
   int32* peakCompositeEVMSymbolIndex,
   int32* peakCompositeEVMSubcarrierIndex,
   int32* peakCompositeEVMSlotIndex
);

int32 __stdcall RFmxLTE_ModAccFetchInBandEmissionMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* inBandEmissionMargin
);

int32 __stdcall RFmxLTE_ModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanIQOriginOffset,
   float64* meanIQGainImbalance,
   float64* meanIQQuadratureError
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSDataEVM,
   float64* maximumPeakDataEVM
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkDetectedCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* detectedCellID
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSDMRSEVM,
   float64* maximumPeakDMRSEVM
);

int32 __stdcall RFmxLTE_ModAccFetchPUSCHSymbolPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PUSCHMeanDataPower,
   float64* PUSCHMeanDMRSPower
);

int32 __stdcall RFmxLTE_ModAccFetchSpectralFlatness(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* range1MaximumToRange1Minimum,
   float64* range2MaximumToRange2Minimum,
   float64* range1MaximumToRange2Minimum,
   float64* range2MaximumToRange1Minimum
);

int32 __stdcall RFmxLTE_ModAccFetchCompositeMagnitudeAndPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSCompositeMagnitudeError,
   float64* maxPeakCompositeMagnitudeError,
   float64* meanRMSCompositePhaseError,
   float64* maxPeakCompositePhaseError
);

int32 __stdcall RFmxLTE_ModAccFetchSubblockInBandEmissionMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockInBandEmissionMargin
);

int32 __stdcall RFmxLTE_ModAccFetchSubblockIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* subblockMeanIQOriginOffset,
   float64* subblockMeanIQGainImbalance,
   float64* subblockMeanIQQuadratureError
);

int32 __stdcall RFmxLTE_ModAccFetchCSRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSCSRSEVM
);

int32 __stdcall RFmxLTE_ModAccFetchSynchronizationSignalEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSPSSEVM,
   float64* meanRMSSSSEVM
);

int32 __stdcall RFmxLTE_ModAccFetchSRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSSRSEVM,
   float64* meanSRSPower
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCHEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMSEVM,
   float64* meanRMSQPSKEVM,
   float64* meanRMS16QAMEVM,
   float64* meanRMS64QAMEVM,
   float64* meanRMS256QAMEVM
);

int32 __stdcall RFmxLTE_ModAccFetchDownlinkTransmitPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RSTransmitPower,
   float64* OFDMSymbolTransmitPower,
   float64* reserved1,
   float64* reserved2
);

int32 __stdcall RFmxLTE_ModAccFetchPDSCH1024QAMEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRMS1024QAMEVM
);

int32 __stdcall RFmxLTE_ModAccFetchNPUSCHDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* NPUSCHMeanRMSDataEVM,
   float64* NPUSCHMaximumPeakDataEVM
);

int32 __stdcall RFmxLTE_ModAccFetchNPUSCHDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* NPUSCHMeanRMSDMRSEVM,
   float64* NPUSCHMaximumPeakDMRSEVM
);

int32 __stdcall RFmxLTE_ModAccFetchNPUSCHSymbolPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* NPUSCHMeanDataPower,
   float64* NPUSCHMeanDMRSPower
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PSSCHMeanRMSDataEVM,
   float64* PSSCHMaximumPeakDataEVM
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHSymbolPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PSSCHMeanDataPower,
   float64* PSSCHMeanDMRSPower
);

int32 __stdcall RFmxLTE_ModAccFetchPSSCHDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* PSSCHMeanRMSDMRSEVM,
   float64* PSSCHMaximumPeakDMRSEVM
);

int32 __stdcall RFmxLTE_SlotPowerFetchPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 subframePower[],
   float64 subframePowerDelta[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SlotPhaseFetchPhaseDiscontinuities(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 slotPhaseDiscontinuity[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SlotPhaseFetchSamplePhaseErrorLinearFitTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 samplePhaseErrorLinearFit[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SlotPhaseFetchSamplePhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 samplePhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SlotPhaseFetchMaximumPhaseDiscontinuityArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 maximumPhaseDiscontinuity[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxLTE_SlotPhaseFetchMaximumPhaseDiscontinuity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumPhaseDiscontinuity
);

int32 __stdcall RFmxLTE_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetIQOriginOffsetEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetIQOriginOffsetEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetIQMismatchEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetIQMismatchEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetIQGainImbalanceCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetIQGainImbalanceCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetIQQuadratureErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetIQQuadratureErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetIQTimingSkewCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetIQTimingSkewCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetChannelEstimationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetChannelEstimationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetFFTWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetFFTWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetFFTWindowOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetFFTWindowOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetFFTWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetFFTWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetEVMWithExclusionPeriodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetEVMWithExclusionPeriodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetSpectralFlatnessCondition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetSpectralFlatnessCondition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetPreFFTErrorEstimationInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetPreFFTErrorEstimationInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetSymbolClockErrorEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetSymbolClockErrorEstimationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetTimingTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetTimingTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanRMSCompositeEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMaximumPeakCompositeEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanRMSCompositeMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMaximumPeakCompositeMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanRmsCompositePhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMaximumPeakCompositePhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPeakCompositeEVMSlotIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPeakCompositeEVMSymbolIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPeakCompositeEVMSubcarrierIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPUSCHMeanRMSDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPUSCHMaximumPeakDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPUSCHMeanRMSDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPUSCHMaximumPeakDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPUSCHMeanDataPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPUSCHMeanDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsInBandEmissionMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSpectralFlatnessRange1MaximumToRange1Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSpectralFlatnessRange2MaximumToRange2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSpectralFlatnessRange1MaximumToRange2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSpectralFlatnessRange2MaximumToRange1Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMaximumPeakFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMaximumPeakIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanIQTimingSkew(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanTimeOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanSymbolClockError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSubblockInBandEmissionMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSubblockMeanIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSubblockMeanIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsSubblockMeanQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkDetectedCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetMulticarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetMulticarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanRMSSRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsMeanSRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPDSCHMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPDSCHMeanRMSQPSKEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPDSCHMeanRMS16QAMEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPDSCHMeanRMS64QAMEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPDSCHMeanRMS256QAMEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsRSDownlinkMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkPSSMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkSSSMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkPBCHMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkPCFICHMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPDCCHMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkPHICHMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkOFDMSymbolTransmitPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetMulticarrierTimeSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetMulticarrierTimeSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsDownlinkRSTransmitPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPDSCHMeanRMS1024QAMEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetInBandEmissionMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetInBandEmissionMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsNPUSCHMeanRMSDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsNPUSCHMaximumPeakDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsNPUSCHMeanRMSDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsNPUSCHMaximumPeakDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsNPUSCHMeanDataPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsNPUSCHMeanDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPSSCHMeanRMSDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPSSCHMaximumPeakDataEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPSSCHMeanRMSDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPSSCHMaximumPeakDMRSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPSSCHMeanDataPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ModAccGetResultsPSSCHMeanDMRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetComponentCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetNumberOfUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNumberOfUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNumberOfEUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNumberOfEUTRAOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_ACPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_ACPGetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_ACPGetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_ACPGetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsSubblockCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsComponentCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsComponentCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_ACPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetConfigurableNumberOfOffsetsEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetConfigurableNumberOfOffsetsEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetEUTRAOffsetDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetEUTRAOffsetDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_ACPGetNumberOfGSMOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ACPSetNumberOfGSMOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetIntegrationBandwidthType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetIntegrationBandwidthType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetComponentCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_CHPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_CHPGetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CHPGetResultsTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetResultsSubblockFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetResultsSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetResultsSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetResultsComponentCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetResultsComponentCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_CHPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_CHPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_OBWGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_OBWGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_OBWGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_OBWGetResultsOccupiedBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_OBWGetResultsAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_OBWGetResultsStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_OBWGetResultsStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_OBWGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_OBWSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetSubblockAggregatedChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetComponentCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsTotalAggregatedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsSubblockCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsSubblockIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsSubblockPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsComponentCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsComponentCarrierRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsComponentCarrierAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsComponentCarrierPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMGetUplinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetUplinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetDownlinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetDownlinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetDeltaFMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetDeltaFMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetAggregatedMaximumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetAggregatedMaximumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetComponentCarrierMaximumOutputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetComponentCarrierMaximumOutputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SEMGetOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMGetSidelinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetSidelinkMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetOFFPowerExclusionBefore(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetOFFPowerExclusionBefore(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_PVTGetOFFPowerExclusionAfter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetOFFPowerExclusionAfter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_PVTGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_PVTGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_PVTGetResultsMeanAbsoluteOFFPowerBefore(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_PVTGetResultsMeanAbsoluteOFFPowerAfter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_PVTGetResultsMeanAbsoluteONPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_PVTGetResultsBurstWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxLTE_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxLTE_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxLTE_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxLTE_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetDuplexScheme(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDuplexScheme(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetUplinkDownlinkConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetUplinkDownlinkConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNumberOfSubblocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNumberOfSubblocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSubblockFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetSubblockFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetBand(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetComponentCarrierSpacingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetComponentCarrierSpacingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetComponentCarrierAtCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetComponentCarrierAtCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNumberOfComponentCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNumberOfComponentCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetComponentCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetComponentCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetComponentCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetComponentCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetCyclicPrefixMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetCyclicPrefixMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetAutoResourceBlockDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetAutoResourceBlockDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetAutoDMRSDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetAutoDMRSDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetUplinkGroupHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetUplinkGroupHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetUplinkSequenceHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetUplinkSequenceHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHnDMRS1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHnDMRS1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHDeltaSequenceShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHDeltaSequenceShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHNumberOfResourceBlockClusters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHnDMRS2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHnDMRS2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetAcquisitionBandwidthOptimizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetAcquisitionBandwidthOptimizationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetTransmitterArchitecture(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetTransmitterArchitecture(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDMRSOCCEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDMRSOCCEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPUSCHCyclicShiftField(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPUSCHCyclicShiftField(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSpecialSubframeConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSpecialSubframeConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNumberOfDUTAntennas(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNumberOfDUTAntennas(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetTransmitAntennaToAnalyze(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetTransmitAntennaToAnalyze(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRSSubframeConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRSSubframeConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRS_C_SRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRS_C_SRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRS_B_SRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRS_B_SRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRS_I_SRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRS_I_SRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRS_n_RRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRS_n_RRS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRS_n_SRS_CS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRS_n_SRS_CS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRS_b_Hop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRS_b_Hop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRS_k_TC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRS_k_TC(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRSMaximumUpPTSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRSMaximumUpPTSEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRSSubframe1_N_RA(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRSSubframe1_N_RA(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRSSubframe6_N_RA(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSRSSubframe6_N_RA(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetSRSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkAutoCellIDDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkAutoCellIDDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedCellSpecificRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedCellSpecificRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedPSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedPSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedSSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedSSSPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinUserDefinedPBCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinUserDefinedPBCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetUserDefinedPDCCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetUserDefinedPDCCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedNumberOfSubframes(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedNumberOfSubframes(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedPCFICHCFI(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedPCFICHCFI(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedPCFICHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedPCFICHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedPHICHResource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedPHICHResource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedPHICHDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedPHICHDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkUserDefinedPhichPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkUserDefinedPhichPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetUserDefinedPDSCHNumberOfAllocations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetUserDefinedPDSCHNumberOfAllocations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetUserDefinedPDSCHCW0ModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetUserDefinedPDSCHCW0ModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetUserDefinedPDSCHResourceBlockAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxLTE_SetUserDefinedPDSCHResourceBlockAllocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxLTE_GetUserDefinedPDSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetUserDefinedPDSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetDownlinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetDownlinkTestModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GeteNodeBCategory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SeteNodeBCategory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetAutoPDSCHChannelDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetAutoPDSCHChannelDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetAutoControlChannelPowerDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetAutoControlChannelPowerDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetAutoPCFICHCFIDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetAutoPCFICHCFIDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetLAAStartingSubframe(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLAAStartingSubframe(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetLAANumberOfSubframes(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLAANumberOfSubframes(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetLAAUplinkStartPosition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLAAUplinkStartPosition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetLAAUplinkEndingSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLAAUplinkEndingSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetLAADownlinkStartingSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLAADownlinkStartingSymbol(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetLAADownlinkNumberOfEndingSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetLAADownlinkNumberOfEndingSymbols(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetMiConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetMiConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNCellID(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNBIoTUplinkSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNBIoTUplinkSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetAutoNPUSCHChannelDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetAutoNPUSCHChannelDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHToneOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHToneOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHNumberOfTones(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHNumberOfTones(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHDMRSBaseSequenceMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHDMRSBaseSequenceMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHDMRSBaseSequenceIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHDMRSBaseSequenceIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHDMRSCyclicShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHDMRSCyclicShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHDMRSGroupHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHDMRSGroupHoppingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHDMRSDeltaSequenceShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHDMRSDeltaSequenceShift(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetEMTCAnalysisEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetEMTCAnalysisEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetNPUSCHStartingSlot(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetNPUSCHStartingSlot(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxLTE_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxLTE_GetCenterFrequencyForLimits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetCenterFrequencyForLimits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_GetPSSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPSSCHModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPSSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPSSCHResourceBlockOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPSSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetPSSCHNumberOfResourceBlocks(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetPSSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SetPSSCHPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetExclusionPeriodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetExclusionPeriodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPhaseGetResultsMaximumPhaseDiscontinuity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxLTE_SlotPowerGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPowerSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPowerGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPowerSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPowerGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPowerSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPowerGetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPowerSetCommonClockSourceEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPowerGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPowerSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SlotPowerGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SlotPowerSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#define RFMXLTE_ATTR_SEM_STANDARD_MASK_TYPE                                                 0x0030804c
#define RFMXLTE_ATTR_MODACC_MULTI_CARRIER_FILTER_ENABLED                                    0x00304002
#define RFMXLTE_ATTR_SUBBLOCK_FREQUENCY_DEFINITION                                          0x00300024

// Values for RFMXLTE_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXLTE_VAL_IQ_POWER_EDGE_LEVEL_TYPE_RELATIVE                                              0
#define RFMXLTE_VAL_IQ_POWER_EDGE_LEVEL_TYPE_ABSOLUTE                                              1

// Values for RFMXLTE_ATTR_SEM_STANDARD_MASK_TYPE
#define RFMXLTE_VAL_SEM_STANDARD_MASK_TYPE_GENERAL_NS01                                            0
#define RFMXLTE_VAL_SEM_STANDARD_MASK_TYPE_NS03_OR_NS11_OR_NS20                                    1
#define RFMXLTE_VAL_SEM_STANDARD_MASK_TYPE_NS04                                                    2
#define RFMXLTE_VAL_SEM_STANDARD_MASK_TYPE_NS06_OR_NS07                                            3
#define RFMXLTE_VAL_SEM_STANDARD_MASK_TYPE_CANS04                                                  4
#define RFMXLTE_VAL_SEM_STANDARD_MASK_TYPE_CUSTOM                                                  5

// Values for RFMXLTE_ATTR_SEM_UPLINK_MASK_TYPE
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS03_OR_NS11_OR_NS20                                      1
#define RFMXLTE_VAL_SEM_UPLINK_MASK_TYPE_NS27                                                      8

// Values for RFMXLTE_ATTR_SUBBLOCK_FREQUENCY_DEFINITION
#define RFMXLTE_VAL_SUBBLOCK_FREQUENCY_DEFINITION_RELATIVE                                         0
#define RFMXLTE_VAL_SUBBLOCK_FREQUENCY_DEFINITION_ABSOLUTE                                         1


#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxLTE_SEMGetStandardMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SEMSetStandardMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_SEMCfgStandardMaskType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 standardMaskType
);

int32 __stdcall RFmxLTE_CalculateFrequencyFromEARFCN(
   int32 linkDirection,
   int32 band,
   int32 EARFCN,
   float64 *centerFrequency
);

int32 __stdcall RFmxLTE_ModAccGetMultiCarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_ModAccSetMultiCarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_GetSubblockFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxLTE_SetSubblockFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxLTE_CfgSubblockFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 subblockFrequencyDefinition
);

int32 __stdcall RFmxLTE_AnalyzeIQ(
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

int32 __stdcall RFmxLTE_AnalyzeIQSplit(
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

int32 __stdcall RFmxLTE_AnalyzeSpectrum(
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

