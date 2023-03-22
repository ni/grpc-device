
/****************************************************************************************************
*          National Instruments RFmx CDMA2k
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxCDMA2k.h
*
* Purpose:  National Instruments RFmx CDMA2k,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_CDMA2K_H__
#define __NI_RFMX_CDMA2K_H__

#include "niRFmxInstr.h"

#define RFMXCDMA2K_ATTR_MODACC_MEASUREMENT_ENABLED                              0x00611000
#define RFMXCDMA2K_ATTR_MODACC_SYNCHRONIZATION_MODE                             0x00611005
#define RFMXCDMA2K_ATTR_MODACC_MEASUREMENT_OFFSET                               0x00611006
#define RFMXCDMA2K_ATTR_MODACC_MEASUREMENT_LENGTH                               0x00611007
#define RFMXCDMA2K_ATTR_MODACC_SPECTRUM_INVERTED                                0x00611009
#define RFMXCDMA2K_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED                        0x00611008
#define RFMXCDMA2K_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                0x006110a1
#define RFMXCDMA2K_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED              0x006110a2
#define RFMXCDMA2K_ATTR_MODACC_RECEIVE_FILTER_ENABLED                           0x006110a3
#define RFMXCDMA2K_ATTR_MODACC_MULTI_CARRIER_FILTER_ENABLED                     0x00611010
#define RFMXCDMA2K_ATTR_MODACC_ALL_TRACES_ENABLED                               0x00611015
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_RMS_EVM                                  0x00611020
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_EVM                                 0x00611021
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_RMS_MAGNITUDE_ERROR                      0x00611022
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_RMS_PHASE_ERROR                          0x00611023
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_RHO                                      0x00611028
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_IQ_ORIGIN_OFFSET                         0x00611024
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_IQ_GAIN_IMBALANCE                        0x00611025
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_IQ_QUADRATURE_ERROR                      0x00611026
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_FREQUENCY_ERROR                          0x00611027
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_CHIP_RATE_ERROR                          0x00611033
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_CDE                                 0x00611029
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_CDE_WALSH_CODE_NUMBER               0x0061102b
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_CDE_BRANCH                          0x00611038
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE                          0x0061102c
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_WALSH_CODE_LENGTH        0x0061102d
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_WALSH_CODE_NUMBER        0x0061102f
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_BRANCH                   0x00611039
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_SLOT_TIMING_ERROR                        0x00611030
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_NUMBER_OF_DETECTED_CHANNELS              0x00611034
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_DETECTED_WALSH_CODE_LENGTH               0x00611035
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_DETECTED_WALSH_CODE_NUMBER               0x00611036
#define RFMXCDMA2K_ATTR_MODACC_RESULTS_DETECTED_BRANCH                          0x00611037
#define RFMXCDMA2K_ATTR_ACP_MEASUREMENT_ENABLED                                 0x00601000
#define RFMXCDMA2K_ATTR_ACP_CARRIER_INTEGRATION_BANDWIDTH                       0x00601005
#define RFMXCDMA2K_ATTR_ACP_NUMBER_OF_OFFSETS                                   0x00601008
#define RFMXCDMA2K_ATTR_ACP_OFFSET_FREQUENCY                                    0x0060100a
#define RFMXCDMA2K_ATTR_ACP_OFFSET_INTEGRATION_BANDWIDTH                        0x0060100e
#define RFMXCDMA2K_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH                           0x0060101b
#define RFMXCDMA2K_ATTR_ACP_RBW_FILTER_BANDWIDTH                                0x0060101c
#define RFMXCDMA2K_ATTR_ACP_RBW_FILTER_TYPE                                     0x0060101d
#define RFMXCDMA2K_ATTR_ACP_SWEEP_TIME_AUTO                                     0x0060101e
#define RFMXCDMA2K_ATTR_ACP_SWEEP_TIME_INTERVAL                                 0x0060101f
#define RFMXCDMA2K_ATTR_ACP_MEASUREMENT_METHOD                                  0x00601012
#define RFMXCDMA2K_ATTR_ACP_NOISE_COMPENSATION_ENABLED                          0x00601020
#define RFMXCDMA2K_ATTR_ACP_AVERAGING_ENABLED                                   0x00601016
#define RFMXCDMA2K_ATTR_ACP_AVERAGING_COUNT                                     0x00601015
#define RFMXCDMA2K_ATTR_ACP_AVERAGING_TYPE                                      0x00601018
#define RFMXCDMA2K_ATTR_ACP_FFT_OVERLAP_MODE                                    0x00601039
#define RFMXCDMA2K_ATTR_ACP_FFT_OVERLAP                                         0x0060103a
#define RFMXCDMA2K_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO                         0x00601034
#define RFMXCDMA2K_ATTR_ACP_NEAR_IF_OUTPUT_POWER_OFFSET                         0x00601035
#define RFMXCDMA2K_ATTR_ACP_FAR_IF_OUTPUT_POWER_OFFSET                          0x00601036
#define RFMXCDMA2K_ATTR_ACP_ALL_TRACES_ENABLED                                  0x00601021
#define RFMXCDMA2K_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                          0x00601014
#define RFMXCDMA2K_ATTR_ACP_RESULTS_CARRIER_ABSOLUTE_POWER                      0x00601026
#define RFMXCDMA2K_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                 0x0060102c
#define RFMXCDMA2K_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                 0x0060102d
#define RFMXCDMA2K_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                 0x00601032
#define RFMXCDMA2K_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                 0x00601033
#define RFMXCDMA2K_ATTR_ACP_SEQUENTIAL_FFT_SIZE                                 0x00601038
#define RFMXCDMA2K_ATTR_CHP_MEASUREMENT_ENABLED                                 0x00603000
#define RFMXCDMA2K_ATTR_CHP_INTEGRATION_BANDWIDTH                               0x00603002
#define RFMXCDMA2K_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH                           0x0060300c
#define RFMXCDMA2K_ATTR_CHP_RBW_FILTER_BANDWIDTH                                0x0060300d
#define RFMXCDMA2K_ATTR_CHP_RBW_FILTER_TYPE                                     0x0060300e
#define RFMXCDMA2K_ATTR_CHP_SWEEP_TIME_AUTO                                     0x00603011
#define RFMXCDMA2K_ATTR_CHP_SWEEP_TIME_INTERVAL                                 0x00603012
#define RFMXCDMA2K_ATTR_CHP_AVERAGING_ENABLED                                   0x00603007
#define RFMXCDMA2K_ATTR_CHP_AVERAGING_COUNT                                     0x00603006
#define RFMXCDMA2K_ATTR_CHP_AVERAGING_TYPE                                      0x00603009
#define RFMXCDMA2K_ATTR_CHP_ALL_TRACES_ENABLED                                  0x00603014
#define RFMXCDMA2K_ATTR_CHP_NUMBER_OF_ANALYSIS_THREADS                          0x00603003
#define RFMXCDMA2K_ATTR_CHP_RESULTS_CARRIER_ABSOLUTE_POWER                      0x00603015
#define RFMXCDMA2K_ATTR_OBW_MEASUREMENT_ENABLED                                 0x00606000
#define RFMXCDMA2K_ATTR_OBW_SPAN                                                0x00606004
#define RFMXCDMA2K_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH                           0x0060600c
#define RFMXCDMA2K_ATTR_OBW_RBW_FILTER_BANDWIDTH                                0x0060600d
#define RFMXCDMA2K_ATTR_OBW_RBW_FILTER_TYPE                                     0x0060600e
#define RFMXCDMA2K_ATTR_OBW_SWEEP_TIME_AUTO                                     0x0060600f
#define RFMXCDMA2K_ATTR_OBW_SWEEP_TIME_INTERVAL                                 0x00606010
#define RFMXCDMA2K_ATTR_OBW_AVERAGING_ENABLED                                   0x00606007
#define RFMXCDMA2K_ATTR_OBW_AVERAGING_COUNT                                     0x00606006
#define RFMXCDMA2K_ATTR_OBW_AVERAGING_TYPE                                      0x00606009
#define RFMXCDMA2K_ATTR_OBW_ALL_TRACES_ENABLED                                  0x00606012
#define RFMXCDMA2K_ATTR_OBW_NUMBER_OF_ANALYSIS_THREADS                          0x00606003
#define RFMXCDMA2K_ATTR_OBW_RESULTS_OCCUPIED_BANDWIDTH                          0x00606013
#define RFMXCDMA2K_ATTR_OBW_RESULTS_ABSOLUTE_POWER                              0x00606014
#define RFMXCDMA2K_ATTR_OBW_RESULTS_START_FREQUENCY                             0x00606015
#define RFMXCDMA2K_ATTR_OBW_RESULTS_STOP_FREQUENCY                              0x00606016
#define RFMXCDMA2K_ATTR_SEM_MEASUREMENT_ENABLED                                 0x00608000
#define RFMXCDMA2K_ATTR_SEM_CARRIER_INTEGRATION_BANDWIDTH                       0x00608005
#define RFMXCDMA2K_ATTR_SEM_NUMBER_OF_OFFSETS                                   0x0060800b
#define RFMXCDMA2K_ATTR_SEM_OFFSET_START_FREQUENCY                              0x00608014
#define RFMXCDMA2K_ATTR_SEM_OFFSET_STOP_FREQUENCY                               0x00608015
#define RFMXCDMA2K_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH                         0x00608017
#define RFMXCDMA2K_ATTR_SEM_OFFSET_RBW_FILTER_TYPE                              0x00608018
#define RFMXCDMA2K_ATTR_SEM_OFFSET_BANDWIDTH_INTEGRAL                           0x0060800c
#define RFMXCDMA2K_ATTR_SEM_SWEEP_TIME_AUTO                                     0x00608025
#define RFMXCDMA2K_ATTR_SEM_SWEEP_TIME_INTERVAL                                 0x00608026
#define RFMXCDMA2K_ATTR_SEM_AVERAGING_ENABLED                                   0x0060801f
#define RFMXCDMA2K_ATTR_SEM_AVERAGING_COUNT                                     0x0060801e
#define RFMXCDMA2K_ATTR_SEM_AVERAGING_TYPE                                      0x00608021
#define RFMXCDMA2K_ATTR_SEM_ALL_TRACES_ENABLED                                  0x00608027
#define RFMXCDMA2K_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                          0x0060801d
#define RFMXCDMA2K_ATTR_SEM_RESULTS_MEASUREMENT_STATUS                          0x00608029
#define RFMXCDMA2K_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_INTEGRATED_POWER           0x0060802d
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS             0x0060803d
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER      0x00608034
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_INTEGRATED_POWER      0x00608035
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER            0x00608036
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_PEAK_POWER            0x00608037
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                 0x00608038
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                         0x00608039
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER          0x0060803a
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER          0x0060803b
#define RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY               0x0060803c
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS             0x0060804a
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER      0x00608041
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_INTEGRATED_POWER      0x00608042
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER            0x00608043
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_PEAK_POWER            0x00608044
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                 0x00608045
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                         0x00608046
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER          0x00608047
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER          0x00608048
#define RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY               0x00608049
#define RFMXCDMA2K_ATTR_QEVM_MEASUREMENT_ENABLED                                0x00612000
#define RFMXCDMA2K_ATTR_QEVM_MEASUREMENT_LENGTH                                 0x00612002
#define RFMXCDMA2K_ATTR_QEVM_AVERAGING_ENABLED                                  0x00612003
#define RFMXCDMA2K_ATTR_QEVM_AVERAGING_COUNT                                    0x00612004
#define RFMXCDMA2K_ATTR_QEVM_SPECTRUM_INVERTED                                  0x00612005
#define RFMXCDMA2K_ATTR_QEVM_IQ_OFFSET_REMOVAL_ENABLED                          0x00612006
#define RFMXCDMA2K_ATTR_QEVM_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                  0x00612007
#define RFMXCDMA2K_ATTR_QEVM_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED                0x00612008
#define RFMXCDMA2K_ATTR_QEVM_RECEIVE_FILTER_ENABLED                             0x00612009
#define RFMXCDMA2K_ATTR_QEVM_ALL_TRACES_ENABLED                                 0x0061200a
#define RFMXCDMA2K_ATTR_QEVM_NUMBER_OF_ANALYSIS_THREADS                         0x0061200b
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_RMS_EVM                               0x0061200d
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_RMS_EVM                            0x0061200e
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_PEAK_EVM                              0x0061200f
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_PEAK_EVM                           0x00612010
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_MAGNITUDE_ERROR                       0x00612011
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_MAGNITUDE_ERROR                    0x00612012
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_PHASE_ERROR                           0x00612013
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_PHASE_ERROR                        0x00612014
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_FREQUENCY_ERROR                       0x00612015
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_FREQUENCY_ERROR                    0x00612016
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_IQ_ORIGIN_OFFSET                      0x00612017
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_IQ_ORIGIN_OFFSET                   0x00612018
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_IQ_GAIN_IMBALANCE                     0x00612019
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_IQ_GAIN_IMBALANCE                  0x0061201a
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_IQ_QUADRATURE_ERROR                   0x0061201b
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_IQ_QUADRATURE_ERROR                0x0061201c
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MEAN_CHIP_RATE_ERROR                       0x0061201d
#define RFMXCDMA2K_ATTR_QEVM_RESULTS_MAXIMUM_CHIP_RATE_ERROR                    0x0061201e
#define RFMXCDMA2K_ATTR_LIMITED_CONFIGURATION_CHANGE                            0x0060d003
#define RFMXCDMA2K_ATTR_RESULT_FETCH_TIMEOUT                                    0x0060c000
#define RFMXCDMA2K_ATTR_CENTER_FREQUENCY                                        0x00600001
#define RFMXCDMA2K_ATTR_REFERENCE_LEVEL                                         0x00600002
#define RFMXCDMA2K_ATTR_EXTERNAL_ATTENUATION                                    0x00600003
#define RFMXCDMA2K_ATTR_TRIGGER_TYPE                                            0x00600004
#define RFMXCDMA2K_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                             0x00600005
#define RFMXCDMA2K_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                               0x00600006
#define RFMXCDMA2K_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                            0x00600007
#define RFMXCDMA2K_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                             0x00600008
#define RFMXCDMA2K_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                        0x00600fff
#define RFMXCDMA2K_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                             0x00600009
#define RFMXCDMA2K_ATTR_TRIGGER_DELAY                                           0x0060000a
#define RFMXCDMA2K_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                         0x0060000b
#define RFMXCDMA2K_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                     0x0060000c
#define RFMXCDMA2K_ATTR_LINK_DIRECTION                                          0x0060000d
#define RFMXCDMA2K_ATTR_BAND_CLASS                                              0x00600010
#define RFMXCDMA2K_ATTR_RADIO_CONFIGURATION                                     0x00600011
#define RFMXCDMA2K_ATTR_CHANNEL_CONFIGURATION_MODE                              0x00600012
#define RFMXCDMA2K_ATTR_NUMBER_OF_CHANNELS                                      0x00600016
#define RFMXCDMA2K_ATTR_WALSH_CODE_LENGTH                                       0x00600017
#define RFMXCDMA2K_ATTR_WALSH_CODE_NUMBER                                       0x00600018
#define RFMXCDMA2K_ATTR_BRANCH                                                  0x00600019
#define RFMXCDMA2K_ATTR_UPLINK_SPREADING_LONG_CODE_MASK                         0x0060001e
#define RFMXCDMA2K_ATTR_DOWNLINK_SPREADING_PN_OFFSET                            0x00600020
#define RFMXCDMA2K_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                      0x0060d000
#define RFMXCDMA2K_ATTR_CDA_MEASUREMENT_ENABLED                                 0x00613000
#define RFMXCDMA2K_ATTR_CDA_SYNCHRONIZATION_MODE                                0x00613002
#define RFMXCDMA2K_ATTR_CDA_MEASUREMENT_OFFSET                                  0x00613003
#define RFMXCDMA2K_ATTR_CDA_MEASUREMENT_LENGTH                                  0x00613004
#define RFMXCDMA2K_ATTR_CDA_BASE_SPREADING_FACTOR                               0x00613005
#define RFMXCDMA2K_ATTR_CDA_MEASUREMENT_CHANNEL_WALSH_CODE_LENGTH               0x00613006
#define RFMXCDMA2K_ATTR_CDA_MEASUREMENT_CHANNEL_WALSH_CODE_NUMBER               0x00613007
#define RFMXCDMA2K_ATTR_CDA_MEASUREMENT_CHANNEL_BRANCH                          0x00613008
#define RFMXCDMA2K_ATTR_CDA_POWER_UNIT                                          0x00613009
#define RFMXCDMA2K_ATTR_CDA_SPECTRUM_INVERTED                                   0x0061300a
#define RFMXCDMA2K_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED                           0x0061300b
#define RFMXCDMA2K_ATTR_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                   0x0061300c
#define RFMXCDMA2K_ATTR_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED                 0x0061300d
#define RFMXCDMA2K_ATTR_CDA_RECEIVE_FILTER_ENABLED                              0x0061300e
#define RFMXCDMA2K_ATTR_CDA_ALL_TRACES_ENABLED                                  0x0061300f
#define RFMXCDMA2K_ATTR_CDA_RESULTS_RMS_SYMBOL_EVM                              0x00613012
#define RFMXCDMA2K_ATTR_CDA_RESULTS_PEAK_SYMBOL_EVM                             0x00613013
#define RFMXCDMA2K_ATTR_CDA_RESULTS_RMS_SYMBOL_MAGNITUDE_ERROR                  0x00613014
#define RFMXCDMA2K_ATTR_CDA_RESULTS_RMS_SYMBOL_PHASE_ERROR                      0x00613015
#define RFMXCDMA2K_ATTR_CDA_RESULTS_MEAN_SYMBOL_POWER                           0x00613016
#define RFMXCDMA2K_ATTR_CDA_RESULTS_TOTAL_POWER                                 0x00613017
#define RFMXCDMA2K_ATTR_CDA_RESULTS_TOTAL_ACTIVE_POWER                          0x00613018
#define RFMXCDMA2K_ATTR_CDA_RESULTS_MEAN_ACTIVE_POWER                           0x00613019
#define RFMXCDMA2K_ATTR_CDA_RESULTS_PEAK_ACTIVE_POWER                           0x0061301a
#define RFMXCDMA2K_ATTR_CDA_RESULTS_MEAN_INACTIVE_POWER                         0x0061301b
#define RFMXCDMA2K_ATTR_CDA_RESULTS_PEAK_INACTIVE_POWER                         0x0061301c
#define RFMXCDMA2K_ATTR_CDA_RESULTS_I_MEAN_ACTIVE_POWER                         0x0061301d
#define RFMXCDMA2K_ATTR_CDA_RESULTS_I_PEAK_INACTIVE_POWER                       0x0061301e
#define RFMXCDMA2K_ATTR_CDA_RESULTS_Q_MEAN_ACTIVE_POWER                         0x0061301f
#define RFMXCDMA2K_ATTR_CDA_RESULTS_Q_PEAK_INACTIVE_POWER                       0x00613020
#define RFMXCDMA2K_ATTR_CDA_RESULTS_MEAN_PILOT_POWER                            0x00613021
#define RFMXCDMA2K_ATTR_CDA_RESULTS_IQ_ORIGIN_OFFSET                            0x00613022
#define RFMXCDMA2K_ATTR_CDA_RESULTS_IQ_GAIN_IMBALANCE                           0x00613023
#define RFMXCDMA2K_ATTR_CDA_RESULTS_IQ_QUADRATURE_ERROR                         0x00613024
#define RFMXCDMA2K_ATTR_CDA_RESULTS_FREQUENCY_ERROR                             0x00613025
#define RFMXCDMA2K_ATTR_CDA_RESULTS_CHIP_RATE_ERROR                             0x00613026
#define RFMXCDMA2K_ATTR_SLOTPOWER_MEASUREMENT_ENABLED                           0x00614000
#define RFMXCDMA2K_ATTR_SLOTPOWER_SYNCHRONIZATION_MODE                          0x00614002
#define RFMXCDMA2K_ATTR_SLOTPOWER_MEASUREMENT_OFFSET                            0x00614003
#define RFMXCDMA2K_ATTR_SLOTPOWER_MEASUREMENT_LENGTH                            0x00614004
#define RFMXCDMA2K_ATTR_SLOTPOWER_SPECTRUM_INVERTED                             0x00614005
#define RFMXCDMA2K_ATTR_SLOTPOWER_RECEIVE_FILTER_ENABLED                        0x00614006
#define RFMXCDMA2K_ATTR_SLOTPHASE_MEASUREMENT_ENABLED                           0x00615000
#define RFMXCDMA2K_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE                          0x00615002
#define RFMXCDMA2K_ATTR_SLOTPHASE_MEASUREMENT_OFFSET                            0x00615003
#define RFMXCDMA2K_ATTR_SLOTPHASE_MEASUREMENT_LENGTH                            0x00615004
#define RFMXCDMA2K_ATTR_SLOTPHASE_SPECTRUM_INVERTED                             0x00615005
#define RFMXCDMA2K_ATTR_SLOTPHASE_RECEIVE_FILTER_ENABLED                        0x00615006
#define RFMXCDMA2K_ATTR_SLOTPHASE_TRANSIENT_DURATION                            0x00615007
#define RFMXCDMA2K_ATTR_SLOTPHASE_ALL_TRACES_ENABLED                            0x00615008
#define RFMXCDMA2K_ATTR_SLOTPHASE_RESULTS_MAXIMUM_PHASE_DISCONTINUITY           0x0061500b
#define RFMXCDMA2K_ATTR_SELECTED_PORTS                                          0x00600ffd
#define RFMXCDMA2K_ATTR_REFERENCE_LEVEL_HEADROOM                                0x00600ffc

// Values for RFMXCDMA2K_ATTR_TRIGGER_TYPE
#define RFMXCDMA2K_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXCDMA2K_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXCDMA2K_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXCDMA2K_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXCDMA2K_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXCDMA2K_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXCDMA2K_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXCDMA2K_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXCDMA2K_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXCDMA2K_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXCDMA2K_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXCDMA2K_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXCDMA2K_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXCDMA2K_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXCDMA2K_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXCDMA2K_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXCDMA2K_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXCDMA2K_VAL_TIMER_EVENT_STR                                                                "TimerEvent"

// Values for RFMXCDMA2K_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXCDMA2K_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXCDMA2K_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXCDMA2K_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXCDMA2K_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXCDMA2K_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXCDMA2K_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXCDMA2K_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXCDMA2K_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXCDMA2K_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXCDMA2K_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXCDMA2K_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXCDMA2K_ATTR_LINK_DIRECTION
#define RFMXCDMA2K_VAL_LINK_DIRECTION_DOWNLINK                                                        0
#define RFMXCDMA2K_VAL_LINK_DIRECTION_UPLINK                                                          1

// Values for RFMXCDMA2K_ATTR_RADIO_CONFIGURATION
#define RFMXCDMA2K_VAL_RADIO_CONFIGURATION_RC1                                                        0
#define RFMXCDMA2K_VAL_RADIO_CONFIGURATION_RC2                                                        1
#define RFMXCDMA2K_VAL_RADIO_CONFIGURATION_RC3                                                        2
#define RFMXCDMA2K_VAL_RADIO_CONFIGURATION_RC4                                                        3
#define RFMXCDMA2K_VAL_RADIO_CONFIGURATION_RC5                                                        4

// Values for RFMXCDMA2K_ATTR_CHANNEL_CONFIGURATION_MODE
#define RFMXCDMA2K_VAL_CHANNEL_CONFIGURATION_MODE_AUTO_DETECT                                         0
#define RFMXCDMA2K_VAL_CHANNEL_CONFIGURATION_MODE_USER_DEFINED                                        1

// Values for RFMXCDMA2K_ATTR_BRANCH
#define RFMXCDMA2K_VAL_BRANCH_I                                                                       0
#define RFMXCDMA2K_VAL_BRANCH_Q                                                                       1
#define RFMXCDMA2K_VAL_BRANCH_I_AND_Q                                                                 2

// Values for RFMXCDMA2K_ATTR_MODACC_SYNCHRONIZATION_MODE
#define RFMXCDMA2K_VAL_MODACC_SYNCHRONIZATION_MODE_FRAME                                              0
#define RFMXCDMA2K_VAL_MODACC_SYNCHRONIZATION_MODE_SLOT                                               1
#define RFMXCDMA2K_VAL_MODACC_SYNCHRONIZATION_MODE_ARBITRARY                                          2

// Values for RFMXCDMA2K_ATTR_MODACC_SPECTRUM_INVERTED
#define RFMXCDMA2K_VAL_MODACC_SPECTRUM_INVERTED_FALSE                                                 0
#define RFMXCDMA2K_VAL_MODACC_SPECTRUM_INVERTED_TRUE                                                  1

// Values for RFMXCDMA2K_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                         0
#define RFMXCDMA2K_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                          1

// Values for RFMXCDMA2K_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                 0
#define RFMXCDMA2K_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                  1

// Values for RFMXCDMA2K_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                               0
#define RFMXCDMA2K_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                1

// Values for RFMXCDMA2K_ATTR_MODACC_RECEIVE_FILTER_ENABLED
#define RFMXCDMA2K_VAL_MODACC_RECEIVE_FILTER_ENABLED_FALSE                                            0
#define RFMXCDMA2K_VAL_MODACC_RECEIVE_FILTER_ENABLED_TRUE                                             1

// Values for RFMXCDMA2K_ATTR_MODACC_MULTI_CARRIER_FILTER_ENABLED
#define RFMXCDMA2K_VAL_MODACC_MULTI_CARRIER_FILTER_ENABLED_FALSE                                      0
#define RFMXCDMA2K_VAL_MODACC_MULTI_CARRIER_FILTER_ENABLED_TRUE                                       1

// Values for RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_CDE_BRANCH
#define RFMXCDMA2K_VAL_MODACC_PEAK_CDE_BRANCH_I                                                       0
#define RFMXCDMA2K_VAL_MODACC_PEAK_CDE_BRANCH_Q                                                       1
#define RFMXCDMA2K_VAL_MODACC_PEAK_CDE_BRANCH_I_AND_Q                                                 2

// Values for RFMXCDMA2K_ATTR_MODACC_RESULTS_PEAK_ACTIVE_CDE_BRANCH
#define RFMXCDMA2K_VAL_MODACC_PEAK_ACTIVE_CDE_BRANCH_I                                                0
#define RFMXCDMA2K_VAL_MODACC_PEAK_ACTIVE_CDE_BRANCH_Q                                                1
#define RFMXCDMA2K_VAL_MODACC_PEAK_ACTIVE_CDE_BRANCH_I_AND_Q                                          2

// Values for RFMXCDMA2K_ATTR_MODACC_RESULTS_DETECTED_BRANCH
#define RFMXCDMA2K_VAL_MODACC_DETECTED_BRANCH_I                                                       0
#define RFMXCDMA2K_VAL_MODACC_DETECTED_BRANCH_Q                                                       1
#define RFMXCDMA2K_VAL_MODACC_DETECTED_BRANCH_I_AND_Q                                                 2

// Values for RFMXCDMA2K_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXCDMA2K_VAL_ACP_RBW_AUTO_FALSE                                                             0
#define RFMXCDMA2K_VAL_ACP_RBW_AUTO_TRUE                                                              1

// Values for RFMXCDMA2K_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXCDMA2K_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXCDMA2K_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXCDMA2K_VAL_ACP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXCDMA2K_ATTR_ACP_SWEEP_TIME_AUTO
#define RFMXCDMA2K_VAL_ACP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXCDMA2K_VAL_ACP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXCDMA2K_ATTR_ACP_MEASUREMENT_METHOD
#define RFMXCDMA2K_VAL_ACP_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXCDMA2K_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1
#define RFMXCDMA2K_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                          2

// Values for RFMXCDMA2K_ATTR_ACP_NOISE_COMPENSATION_ENABLED
#define RFMXCDMA2K_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXCDMA2K_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXCDMA2K_ATTR_ACP_AVERAGING_ENABLED
#define RFMXCDMA2K_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXCDMA2K_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXCDMA2K_ATTR_ACP_AVERAGING_TYPE
#define RFMXCDMA2K_VAL_ACP_AVERAGING_TYPE_RMS                                                         0
#define RFMXCDMA2K_VAL_ACP_AVERAGING_TYPE_LOG                                                         1
#define RFMXCDMA2K_VAL_ACP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXCDMA2K_VAL_ACP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXCDMA2K_VAL_ACP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXCDMA2K_ATTR_ACP_FFT_OVERLAP_MODE
#define RFMXCDMA2K_VAL_ACP_FFT_OVERLAP_MODE_DISABLED                                                  0
#define RFMXCDMA2K_VAL_ACP_FFT_OVERLAP_MODE_AUTOMATIC                                                 1

// Values for RFMXCDMA2K_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXCDMA2K_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                          0
#define RFMXCDMA2K_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                           1

// Values for RFMXCDMA2K_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXCDMA2K_VAL_CHP_RBW_AUTO_FALSE                                                             0
#define RFMXCDMA2K_VAL_CHP_RBW_AUTO_TRUE                                                              1

// Values for RFMXCDMA2K_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXCDMA2K_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXCDMA2K_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXCDMA2K_VAL_CHP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXCDMA2K_ATTR_CHP_SWEEP_TIME_AUTO
#define RFMXCDMA2K_VAL_CHP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXCDMA2K_VAL_CHP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXCDMA2K_ATTR_CHP_AVERAGING_ENABLED
#define RFMXCDMA2K_VAL_CHP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXCDMA2K_VAL_CHP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXCDMA2K_ATTR_CHP_AVERAGING_TYPE
#define RFMXCDMA2K_VAL_CHP_AVERAGING_TYPE_RMS                                                         0
#define RFMXCDMA2K_VAL_CHP_AVERAGING_TYPE_LOG                                                         1
#define RFMXCDMA2K_VAL_CHP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXCDMA2K_VAL_CHP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXCDMA2K_VAL_CHP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXCDMA2K_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXCDMA2K_VAL_OBW_RBW_AUTO_FALSE                                                             0
#define RFMXCDMA2K_VAL_OBW_RBW_AUTO_TRUE                                                              1

// Values for RFMXCDMA2K_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXCDMA2K_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXCDMA2K_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXCDMA2K_VAL_OBW_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXCDMA2K_ATTR_OBW_SWEEP_TIME_AUTO
#define RFMXCDMA2K_VAL_OBW_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXCDMA2K_VAL_OBW_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXCDMA2K_ATTR_OBW_AVERAGING_ENABLED
#define RFMXCDMA2K_VAL_OBW_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXCDMA2K_VAL_OBW_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXCDMA2K_ATTR_OBW_AVERAGING_TYPE
#define RFMXCDMA2K_VAL_OBW_AVERAGING_TYPE_RMS                                                         0
#define RFMXCDMA2K_VAL_OBW_AVERAGING_TYPE_LOG                                                         1
#define RFMXCDMA2K_VAL_OBW_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXCDMA2K_VAL_OBW_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXCDMA2K_VAL_OBW_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXCDMA2K_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXCDMA2K_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FFT_BASED                                           0
#define RFMXCDMA2K_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN                                            1
#define RFMXCDMA2K_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FLAT                                                2
#define RFMXCDMA2K_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_4                                       3
#define RFMXCDMA2K_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_5                                       4

// Values for RFMXCDMA2K_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXCDMA2K_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXCDMA2K_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXCDMA2K_ATTR_SEM_AVERAGING_ENABLED
#define RFMXCDMA2K_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXCDMA2K_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXCDMA2K_ATTR_SEM_AVERAGING_TYPE
#define RFMXCDMA2K_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXCDMA2K_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXCDMA2K_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXCDMA2K_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXCDMA2K_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXCDMA2K_ATTR_SEM_RESULTS_MEASUREMENT_STATUS
#define RFMXCDMA2K_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXCDMA2K_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXCDMA2K_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXCDMA2K_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXCDMA2K_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXCDMA2K_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXCDMA2K_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXCDMA2K_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXCDMA2K_ATTR_QEVM_AVERAGING_ENABLED
#define RFMXCDMA2K_VAL_QEVM_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXCDMA2K_VAL_QEVM_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXCDMA2K_ATTR_QEVM_SPECTRUM_INVERTED
#define RFMXCDMA2K_VAL_QEVM_SPECTRUM_INVERTED_FALSE                                                   0
#define RFMXCDMA2K_VAL_QEVM_SPECTRUM_INVERTED_TRUE                                                    1

// Values for RFMXCDMA2K_ATTR_QEVM_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_QEVM_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                           0
#define RFMXCDMA2K_VAL_QEVM_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                            1

// Values for RFMXCDMA2K_ATTR_QEVM_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_QEVM_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                   0
#define RFMXCDMA2K_VAL_QEVM_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                    1

// Values for RFMXCDMA2K_ATTR_QEVM_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_QEVM_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                                 0
#define RFMXCDMA2K_VAL_QEVM_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                  1

// Values for RFMXCDMA2K_ATTR_QEVM_RECEIVE_FILTER_ENABLED
#define RFMXCDMA2K_VAL_QEVM_RECEIVE_FILTER_ENABLED_FALSE                                              0
#define RFMXCDMA2K_VAL_QEVM_RECEIVE_FILTER_ENABLED_TRUE                                               1

// Values for RFMXCDMA2K_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXCDMA2K_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXCDMA2K_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXCDMA2K_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXCDMA2K_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXCDMA2K_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXCDMA2K_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Boolean
#define RFMXCDMA2K_VAL_FALSE                                                                          0
#define RFMXCDMA2K_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXCDMA2K_VAL_MODACC                                                                         1 << 0
#define RFMXCDMA2K_VAL_ACP                                                                            1 << 1
#define RFMXCDMA2K_VAL_CHP                                                                            1 << 2
#define RFMXCDMA2K_VAL_OBW                                                                            1 << 3
#define RFMXCDMA2K_VAL_SEM                                                                            1 << 4
#define RFMXCDMA2K_VAL_QEVM                                                                           1 << 5
#define RFMXCDMA2K_VAL_CDA                                                                            1 << 6
#define RFMXCDMA2K_VAL_SLOTPHASE                                                                      1 << 7
#define RFMXCDMA2K_VAL_SLOTPOWER                                                                      1 << 8

// Values for FrequencyReferenceSource
#define RFMXCDMA2K_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXCDMA2K_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXCDMA2K_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXCDMA2K_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for RFMXCDMA2K_ATTR_LINK_DIRECTION
#define RFMXCDMA2K_VAL_LINK_DIRECTION_UPLINK                                                          1

// Values for RFAttenuationAuto
#define RFMXCDMA2K_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXCDMA2K_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXCDMA2K_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXCDMA2K_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

// Values for RFMXCDMA2K_ATTR_CDA_SYNCHRONIZATION_MODE
#define RFMXCDMA2K_VAL_CDA_SYNCHRONIZATION_MODE_FRAME                                                 0
#define RFMXCDMA2K_VAL_CDA_SYNCHRONIZATION_MODE_SLOT                                                  1
#define RFMXCDMA2K_VAL_CDA_SYNCHRONIZATION_MODE_ARBITRARY                                             2

// Values for RFMXCDMA2K_ATTR_CDA_POWER_UNIT
#define RFMXCDMA2K_VAL_CDA_POWER_UNIT_DB                                                              0
#define RFMXCDMA2K_VAL_CDA_POWER_UNIT_DBM                                                             1

// Values for RFMXCDMA2K_ATTR_CDA_SPECTRUM_INVERTED
#define RFMXCDMA2K_VAL_CDA_SPECTRUM_INVERTED_FALSE                                                    0
#define RFMXCDMA2K_VAL_CDA_SPECTRUM_INVERTED_TRUE                                                     1

// Values for RFMXCDMA2K_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                            0
#define RFMXCDMA2K_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                             1

// Values for RFMXCDMA2K_ATTR_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                    0
#define RFMXCDMA2K_VAL_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                     1

// Values for RFMXCDMA2K_ATTR_CDA_MEASUREMENT_CHANNEL_BRANCH
#define RFMXCDMA2K_VAL_CDA_MEASUREMENT_CHANNEL_BRANCH_I                                               0
#define RFMXCDMA2K_VAL_CDA_MEASUREMENT_CHANNEL_BRANCH_Q                                               1

// Values for RFMXCDMA2K_ATTR_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXCDMA2K_VAL_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                                  0
#define RFMXCDMA2K_VAL_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                   1

// Values for RFMXCDMA2K_ATTR_SLOTPOWER_SYNCHRONIZATION_MODE
#define RFMXCDMA2K_VAL_SLOTPOWER_SYNCHRONIZATION_MODE_FRAME                                           0
#define RFMXCDMA2K_VAL_SLOTPOWER_SYNCHRONIZATION_MODE_SLOT                                            1

// Values for RFMXCDMA2K_ATTR_SLOTPOWER_SPECTRUM_INVERTED
#define RFMXCDMA2K_VAL_SLOTPOWER_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXCDMA2K_VAL_SLOTPOWER_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXCDMA2K_ATTR_SLOTPOWER_RECEIVE_FILTER_ENABLED
#define RFMXCDMA2K_VAL_SLOTPOWER_RECEIVE_FILTER_ENABLED_FALSE                                         0
#define RFMXCDMA2K_VAL_SLOTPOWER_RECEIVE_FILTER_ENABLED_TRUE                                          1

// Values for RFMXCDMA2K_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE
#define RFMXCDMA2K_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_FRAME                                           0
#define RFMXCDMA2K_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_SLOT                                            1

// Values for RFMXCDMA2K_ATTR_SLOTPHASE_SPECTRUM_INVERTED
#define RFMXCDMA2K_VAL_SLOTPHASE_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXCDMA2K_VAL_SLOTPHASE_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXCDMA2K_ATTR_SLOTPHASE_RECEIVE_FILTER_ENABLED
#define RFMXCDMA2K_VAL_SLOTPHASE_RECEIVE_FILTER_ENABLED_FALSE                                         0
#define RFMXCDMA2K_VAL_SLOTPHASE_RECEIVE_FILTER_ENABLED_TRUE                                          1

// Values for RFMXCDMA2K_ATTR_CDA_RECEIVE_FILTER_ENABLED
#define RFMXCDMA2K_VAL_CDA_RECEIVE_FILTER_ENABLED_FALSE                                               0
#define RFMXCDMA2K_VAL_CDA_RECEIVE_FILTER_ENABLED_TRUE                                                1

/* ---------------- RFmxCDMA2k APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxCDMA2k_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxCDMA2k_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxCDMA2k_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxCDMA2k_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxCDMA2k_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxCDMA2k_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxCDMA2k_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxCDMA2k_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxCDMA2k_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxCDMA2k_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxCDMA2k_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxCDMA2k_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxCDMA2k_BuildChannelString(
   char selectorString[],
   int32 channelNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxCDMA2k_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxCDMA2k_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxCDMA2k_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxCDMA2k_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxCDMA2k_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxCDMA2k_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* done
);

int32 __stdcall RFmxCDMA2k_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxCDMA2k_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxCDMA2k_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxCDMA2k_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxCDMA2k_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxCDMA2k_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxCDMA2k_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxCDMA2k_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxCDMA2k_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxCDMA2k_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxCDMA2k_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxCDMA2k_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxCDMA2k_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxCDMA2k_CfgFrequencyChannelNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 linkDirection,
   int32 bandClass,
   int32 channelNumber
);

int32 __stdcall RFmxCDMA2k_CfgBandClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 bandClass
);

int32 __stdcall RFmxCDMA2k_CfgChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelConfigurationMode
);

int32 __stdcall RFmxCDMA2k_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxCDMA2k_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxCDMA2k_CfgNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfChannels
);

int32 __stdcall RFmxCDMA2k_CfgRadioConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 radioConfiguration
);

int32 __stdcall RFmxCDMA2k_CfgUplinkSpreading(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 uplinkSpreadingLongCodeMask
);

int32 __stdcall RFmxCDMA2k_CfgUserDefinedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 walshCodeLength,
   int32 walshCodeNumber,
   int32 branch
);

int32 __stdcall RFmxCDMA2k_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxCDMA2k_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxCDMA2k_CfgUserDefinedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 walshCodeLength[],
   int32 walshCodeNumber[],
   int32 branch[],
   int32 numberOfElements
);

int32 __stdcall RFmxCDMA2k_ModAccCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxCDMA2k_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxCDMA2k_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxCDMA2k_QEVMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxCDMA2k_QEVMCfgMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementLength
);

int32 __stdcall RFmxCDMA2k_CHPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxCDMA2k_CHPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxCDMA2k_CHPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxCDMA2k_OBWCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxCDMA2k_OBWCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxCDMA2k_OBWCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxCDMA2k_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxCDMA2k_ACPCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxCDMA2k_ACPCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxCDMA2k_ACPCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxCDMA2k_ACPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxCDMA2k_ACPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxCDMA2k_CDACfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxCDMA2k_CDACfgMeasurementChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 walshCodeLength,
   int32 walshCodeNumber,
   int32 branch
);

int32 __stdcall RFmxCDMA2k_CDACfgPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnit
);

int32 __stdcall RFmxCDMA2k_SlotPowerCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxCDMA2k_SlotPhaseCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxCDMA2k_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxCDMA2k_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxCDMA2k_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxCDMA2k_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxCDMA2k_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxCDMA2k_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxCDMA2k_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxCDMA2k_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxCDMA2k_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxCDMA2k_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxCDMA2k_QEVMFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_QEVMFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_QEVMFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_QEVMFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_QEVMFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_QEVMFetchEVM(
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

int32 __stdcall RFmxCDMA2k_QEVMFetchIQImpairments(
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

int32 __stdcall RFmxCDMA2k_SEMFetchLowerOffsetMarginArray(
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

int32 __stdcall RFmxCDMA2k_SEMFetchLowerOffsetPowerArray(
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

int32 __stdcall RFmxCDMA2k_SEMFetchSpectrum(
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

int32 __stdcall RFmxCDMA2k_SEMFetchUpperOffsetMarginArray(
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

int32 __stdcall RFmxCDMA2k_SEMFetchUpperOffsetPowerArray(
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

int32 __stdcall RFmxCDMA2k_SEMFetchCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsoluteIntegratedPower
);

int32 __stdcall RFmxCDMA2k_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxCDMA2k_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxCDMA2k_SEMFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxCDMA2k_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxCDMA2k_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxCDMA2k_ModAccFetchDetectedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 detectedWalshCodeLength[],
   int32 detectedWalshCodeNumber[],
   int32 detectedBranch[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_ModAccFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_ModAccFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_ModAccFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_ModAccFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_ModAccFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_ModAccFetchDetectedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* detectedWalshCodeLength,
   int32* detectedWalshCodeNumber,
   int32* detectedBranch
);

int32 __stdcall RFmxCDMA2k_ModAccFetchEVM(
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

int32 __stdcall RFmxCDMA2k_ModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffset,
   float64* IQGainImbalance,
   float64* IQQuadratureError
);

int32 __stdcall RFmxCDMA2k_ModAccFetchNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* numberOfDetectedChannels
);

int32 __stdcall RFmxCDMA2k_ModAccFetchPeakActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakActiveCDE,
   int32* peakActiveCDEWalshCodeLength,
   int32* peakActiveCDEWalshCodeNumber,
   int32* peakActiveCDEBranch
);

int32 __stdcall RFmxCDMA2k_ModAccFetchPeakCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakCDE,
   int32* peakCDEWalshCodeNumber,
   int32* peakCDEBranch
);

int32 __stdcall RFmxCDMA2k_ACPFetchOffsetMeasurementArray(
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

int32 __stdcall RFmxCDMA2k_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_ACPFetchRelativePowersTrace(
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

int32 __stdcall RFmxCDMA2k_ACPFetchAbsolutePowersTrace(
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

int32 __stdcall RFmxCDMA2k_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower
);

int32 __stdcall RFmxCDMA2k_ACPFetchCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsolutePower
);

int32 __stdcall RFmxCDMA2k_CHPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CHPFetchCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsolutePower
);

int32 __stdcall RFmxCDMA2k_OBWFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_OBWFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* absolutePower,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxCDMA2k_CDAFetchSymbolEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CDAFetchSymbolMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolMagnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CDAFetchSymbolPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CDAFetchCodeDomainIAndQPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 ICodeDomainPowers[],
   float32 QCodeDomainPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CDAFetchSymbolPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CDAFetchSymbolConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle symbolConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CDAFetchSymbolConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 I[],
   float32 Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_CDAFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffset,
   float64* IQGainImbalance,
   float64* IQQuadratureError
);

int32 __stdcall RFmxCDMA2k_CDAFetchSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* RMSSymbolEVM,
   float64* peakSymbolEVM,
   float64* RMSSymbolMagnitudeError,
   float64* RMSSymbolPhaseError,
   float64* meanSymbolPower,
   float64* frequencyError,
   float64* chipRateError
);

int32 __stdcall RFmxCDMA2k_CDAFetchCodeDomainPower(
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

int32 __stdcall RFmxCDMA2k_CDAFetchCodeDomainIAndQPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IMeanActivePower,
   float64* QMeanActivePower,
   float64* IPeakInactivePower,
   float64* QPeakInactivePower
);

int32 __stdcall RFmxCDMA2k_SlotPowerFetchPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 slotPower[],
   float64 slotPowerDelta[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SlotPhaseFetchPhaseDiscontinuities(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 slotPhaseDiscontinuity[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SlotPhaseFetchChipPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chipPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SlotPhaseFetchChipPhaseErrorLinearFitTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chipPhaseErrorLinearFit[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxCDMA2k_SlotPhaseFetchMaximumPhaseDiscontinuity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumPhaseDiscontinuity
);

int32 __stdcall RFmxCDMA2k_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetMultiCarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetMultiCarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsRMSMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsRMSPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakCDEWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakCDEBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakActiveCDEWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakActiveCDEWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsPeakActiveCDEBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsSlotTimingError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsDetectedWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsDetectedWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ModAccGetResultsDetectedBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetAdvancedIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetAdvancedIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetAdvancedNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetAdvancedNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetAdvancedFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetAdvancedFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_ACPSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CHPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CHPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetResultsOccupiedBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetResultsAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetResultsStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_OBWGetResultsStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMeanChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_QEVMGetResultsMaximumChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetLinkDirection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetBandClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetBandClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetRadioConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetRadioConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetUplinkSpreadingLongCodeMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetUplinkSpreadingLongCodeMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetDownlinkSpreadingPNOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetDownlinkSpreadingPNOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxCDMA2k_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxCDMA2k_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetBaseSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetBaseSpreadingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetMeasurementChannelWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetMeasurementChannelWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetMeasurementChannelWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetMeasurementChannelWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetMeasurementChannelBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetMeasurementChannelBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDASetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsRMSSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsPeakSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsRMSSymbolMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsRMSSymbolPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsMeanSymbolPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsTotalPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsTotalActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsPeakActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsMeanInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsIMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsIPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsQMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsQPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsMeanPilotPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_CDAGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPowerSetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetTransientDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetTransientDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxCDMA2k_SlotPhaseGetResultsMaximumPhaseDiscontinuity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxCDMA2k_CalculateFrequencyFromChannelNumber(
   int32 linkDirection,
   int32 bandClass,
   int32 channelNumber,
   float64* centerFrequency
);

int32 __stdcall RFmxCDMA2k_AnalyzeIQ(
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

int32 __stdcall RFmxCDMA2k_AnalyzeIQSplit(
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

int32 __stdcall RFmxCDMA2k_AnalyzeSpectrum(
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

