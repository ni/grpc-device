
/****************************************************************************************************
*          National Instruments RFmx EVDO
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2021.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxEVDO.h
*
* Purpose:  National Instruments RFmx EVDO,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_EVDO_H__
#define __NI_RFMX_EVDO_H__

#include "niRFmxInstr.h"

#define RFMXEVDO_ATTR_MODACC_MEASUREMENT_ENABLED                                   0x00811000
#define RFMXEVDO_ATTR_MODACC_SYNCHRONIZATION_MODE                                  0x00811002
#define RFMXEVDO_ATTR_MODACC_MEASUREMENT_OFFSET                                    0x00811004
#define RFMXEVDO_ATTR_MODACC_MEASUREMENT_LENGTH                                    0x00811005
#define RFMXEVDO_ATTR_MODACC_SPECTRUM_INVERTED                                     0x00811006
#define RFMXEVDO_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED                             0x00811007
#define RFMXEVDO_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                     0x008110a1
#define RFMXEVDO_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED                   0x008110a2
#define RFMXEVDO_ATTR_MODACC_RECEIVE_FILTER_ENABLED                                0x008110a3
#define RFMXEVDO_ATTR_MODACC_MULTI_CARRIER_FILTER_ENABLED                          0x00811008
#define RFMXEVDO_ATTR_MODACC_ALL_TRACES_ENABLED                                    0x0081100c
#define RFMXEVDO_ATTR_MODACC_RESULTS_FREQUENCY_ERROR                               0x0081100f
#define RFMXEVDO_ATTR_MODACC_RESULTS_CHIP_RATE_ERROR                               0x00811010
#define RFMXEVDO_ATTR_MODACC_RESULTS_IQ_ORIGIN_OFFSET                              0x00811011
#define RFMXEVDO_ATTR_MODACC_RESULTS_IQ_GAIN_IMBALANCE                             0x00811012
#define RFMXEVDO_ATTR_MODACC_RESULTS_IQ_QUADRATURE_ERROR                           0x00811013
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_RMS_EVM                                0x00811014
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_EVM                               0x00811015
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_RMS_MAGNITUDE_ERROR                    0x00811016
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_RMS_PHASE_ERROR                        0x00811017
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_RHO                                    0x00811018
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_CDE                               0x00811019
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_CDE_WALSH_CODE_NUMBER             0x0081101b
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_CDE_BRANCH                        0x0081104d
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_ACTIVE_CDE                        0x0081101c
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_ACTIVE_CDE_WALSH_CODE_LENGTH      0x0081101d
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_ACTIVE_CDE_WALSH_CODE_NUMBER      0x0081101e
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_ACTIVE_CDE_BRANCH                 0x0081104e
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_DETECTED_DATA_MODULATION_TYPE          0x0081101f
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_NUMBER_OF_DETECTED_CHANNELS            0x00811020
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_DETECTED_WALSH_CODE_LENGTH             0x00811021
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_DETECTED_WALSH_CODE_NUMBER             0x00811022
#define RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_DETECTED_BRANCH                        0x00811023
#define RFMXEVDO_ATTR_ACP_MEASUREMENT_ENABLED                                      0x00801000
#define RFMXEVDO_ATTR_ACP_CARRIER_INTEGRATION_BANDWIDTH                            0x00801005
#define RFMXEVDO_ATTR_ACP_NUMBER_OF_OFFSETS                                        0x00801008
#define RFMXEVDO_ATTR_ACP_OFFSET_FREQUENCY                                         0x0080100a
#define RFMXEVDO_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER                           0x0080100c
#define RFMXEVDO_ATTR_ACP_OFFSET_POWER_REFERENCE_SPECIFIC                          0x0080100d
#define RFMXEVDO_ATTR_ACP_OFFSET_INTEGRATION_BANDWIDTH                             0x0080100e
#define RFMXEVDO_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH                                0x0080101b
#define RFMXEVDO_ATTR_ACP_RBW_FILTER_BANDWIDTH                                     0x0080101c
#define RFMXEVDO_ATTR_ACP_RBW_FILTER_TYPE                                          0x0080101d
#define RFMXEVDO_ATTR_ACP_SWEEP_TIME_AUTO                                          0x0080101e
#define RFMXEVDO_ATTR_ACP_SWEEP_TIME_INTERVAL                                      0x0080101f
#define RFMXEVDO_ATTR_ACP_MEASUREMENT_METHOD                                       0x00801012
#define RFMXEVDO_ATTR_ACP_NOISE_COMPENSATION_ENABLED                               0x00801020
#define RFMXEVDO_ATTR_ACP_AVERAGING_ENABLED                                        0x00801016
#define RFMXEVDO_ATTR_ACP_AVERAGING_COUNT                                          0x00801015
#define RFMXEVDO_ATTR_ACP_AVERAGING_TYPE                                           0x00801018
#define RFMXEVDO_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO                              0x00801034
#define RFMXEVDO_ATTR_ACP_NEAR_IF_OUTPUT_POWER_OFFSET                              0x00801035
#define RFMXEVDO_ATTR_ACP_FAR_IF_OUTPUT_POWER_OFFSET                               0x00801036
#define RFMXEVDO_ATTR_ACP_ALL_TRACES_ENABLED                                       0x00801021
#define RFMXEVDO_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                               0x00801014
#define RFMXEVDO_ATTR_ACP_RESULTS_TOTAL_CARRIER_POWER                              0x00801022
#define RFMXEVDO_ATTR_ACP_RESULTS_CARRIER_ABSOLUTE_POWER                           0x00801026
#define RFMXEVDO_ATTR_ACP_RESULTS_CARRIER_RELATIVE_POWER                           0x00801027
#define RFMXEVDO_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                      0x0080102c
#define RFMXEVDO_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                      0x0080102d
#define RFMXEVDO_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                      0x00801032
#define RFMXEVDO_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                      0x00801033
#define RFMXEVDO_ATTR_ACP_SEQUENTIAL_FFT_SIZE                                      0x00801038
#define RFMXEVDO_ATTR_CHP_MEASUREMENT_ENABLED                                      0x00803000
#define RFMXEVDO_ATTR_CHP_CARRIER_INTEGRATION_BANDWIDTH                            0x00803002
#define RFMXEVDO_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH                                0x0080300c
#define RFMXEVDO_ATTR_CHP_RBW_FILTER_BANDWIDTH                                     0x0080300d
#define RFMXEVDO_ATTR_CHP_RBW_FILTER_TYPE                                          0x0080300e
#define RFMXEVDO_ATTR_CHP_SWEEP_TIME_AUTO                                          0x00803011
#define RFMXEVDO_ATTR_CHP_SWEEP_TIME_INTERVAL                                      0x00803012
#define RFMXEVDO_ATTR_CHP_AVERAGING_ENABLED                                        0x00803007
#define RFMXEVDO_ATTR_CHP_AVERAGING_COUNT                                          0x00803006
#define RFMXEVDO_ATTR_CHP_AVERAGING_TYPE                                           0x00803009
#define RFMXEVDO_ATTR_CHP_ALL_TRACES_ENABLED                                       0x00803014
#define RFMXEVDO_ATTR_CHP_NUMBER_OF_ANALYSIS_THREADS                               0x00803003
#define RFMXEVDO_ATTR_CHP_RESULTS_TOTAL_CARRIER_POWER                              0x00803018
#define RFMXEVDO_ATTR_CHP_RESULTS_CARRIER_ABSOLUTE_POWER                           0x00803015
#define RFMXEVDO_ATTR_CHP_RESULTS_CARRIER_RELATIVE_POWER                           0x00803019
#define RFMXEVDO_ATTR_OBW_MEASUREMENT_ENABLED                                      0x00806000
#define RFMXEVDO_ATTR_OBW_SPAN                                                     0x00806004
#define RFMXEVDO_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH                                0x0080600c
#define RFMXEVDO_ATTR_OBW_RBW_FILTER_BANDWIDTH                                     0x0080600d
#define RFMXEVDO_ATTR_OBW_RBW_FILTER_TYPE                                          0x0080600e
#define RFMXEVDO_ATTR_OBW_SWEEP_TIME_AUTO                                          0x0080600f
#define RFMXEVDO_ATTR_OBW_SWEEP_TIME_INTERVAL                                      0x00806010
#define RFMXEVDO_ATTR_OBW_AVERAGING_ENABLED                                        0x00806007
#define RFMXEVDO_ATTR_OBW_AVERAGING_COUNT                                          0x00806006
#define RFMXEVDO_ATTR_OBW_AVERAGING_TYPE                                           0x00806009
#define RFMXEVDO_ATTR_OBW_ALL_TRACES_ENABLED                                       0x00806012
#define RFMXEVDO_ATTR_OBW_NUMBER_OF_ANALYSIS_THREADS                               0x00806003
#define RFMXEVDO_ATTR_OBW_RESULTS_OCCUPIED_BANDWIDTH                               0x00806013
#define RFMXEVDO_ATTR_OBW_RESULTS_ABSOLUTE_POWER                                   0x00806014
#define RFMXEVDO_ATTR_OBW_RESULTS_START_FREQUENCY                                  0x00806015
#define RFMXEVDO_ATTR_OBW_RESULTS_STOP_FREQUENCY                                   0x00806016
#define RFMXEVDO_ATTR_SEM_MEASUREMENT_ENABLED                                      0x00808000
#define RFMXEVDO_ATTR_SEM_CARRIER_INTEGRATION_BANDWIDTH                            0x00808005
#define RFMXEVDO_ATTR_SEM_NUMBER_OF_OFFSETS                                        0x0080800b
#define RFMXEVDO_ATTR_SEM_OFFSET_START_FREQUENCY                                   0x00808014
#define RFMXEVDO_ATTR_SEM_OFFSET_STOP_FREQUENCY                                    0x00808015
#define RFMXEVDO_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH                              0x00808017
#define RFMXEVDO_ATTR_SEM_OFFSET_RBW_FILTER_TYPE                                   0x00808018
#define RFMXEVDO_ATTR_SEM_OFFSET_BANDWIDTH_INTEGRAL                                0x0080800c
#define RFMXEVDO_ATTR_SEM_SWEEP_TIME_AUTO                                          0x00808025
#define RFMXEVDO_ATTR_SEM_SWEEP_TIME_INTERVAL                                      0x00808026
#define RFMXEVDO_ATTR_SEM_AVERAGING_ENABLED                                        0x0080801f
#define RFMXEVDO_ATTR_SEM_AVERAGING_COUNT                                          0x0080801e
#define RFMXEVDO_ATTR_SEM_AVERAGING_TYPE                                           0x00808021
#define RFMXEVDO_ATTR_SEM_ALL_TRACES_ENABLED                                       0x00808027
#define RFMXEVDO_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                               0x0080801d
#define RFMXEVDO_ATTR_SEM_RESULTS_TOTAL_CARRIER_POWER                              0x00808028
#define RFMXEVDO_ATTR_SEM_RESULTS_COMPOSITE_MEASUREMENT_STATUS                     0x00808029
#define RFMXEVDO_ATTR_SEM_RESULTS_CARRIER_RELATIVE_INTEGRATED_POWER                0x0080802e
#define RFMXEVDO_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_INTEGRATED_POWER                0x0080802d
#define RFMXEVDO_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_PEAK_POWER                      0x0080802f
#define RFMXEVDO_ATTR_SEM_RESULTS_CARRIER_PEAK_FREQUENCY                           0x00808030
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS                  0x0080803d
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER           0x00808034
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_INTEGRATED_POWER           0x00808035
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER                 0x00808036
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_RELATIVE_PEAK_POWER                 0x00808037
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                      0x00808038
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                              0x00808039
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER               0x0080803a
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER               0x0080803b
#define RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY                    0x0080803c
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS                  0x0080804a
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER           0x00808041
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_INTEGRATED_POWER           0x00808042
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER                 0x00808043
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_RELATIVE_PEAK_POWER                 0x00808044
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                      0x00808045
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                              0x00808046
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER               0x00808047
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER               0x00808048
#define RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY                    0x00808049
#define RFMXEVDO_ATTR_LIMITED_CONFIGURATION_CHANGE                                 0x0080d003
#define RFMXEVDO_ATTR_RESULT_FETCH_TIMEOUT                                         0x0080c000
#define RFMXEVDO_ATTR_CENTER_FREQUENCY                                             0x00800001
#define RFMXEVDO_ATTR_REFERENCE_LEVEL                                              0x00800002
#define RFMXEVDO_ATTR_EXTERNAL_ATTENUATION                                         0x00800003
#define RFMXEVDO_ATTR_TRIGGER_TYPE                                                 0x00800004
#define RFMXEVDO_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                  0x00800005
#define RFMXEVDO_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                    0x00800006
#define RFMXEVDO_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                 0x00800007
#define RFMXEVDO_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                  0x00800008
#define RFMXEVDO_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                             0x00800fff
#define RFMXEVDO_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                  0x00800009
#define RFMXEVDO_ATTR_TRIGGER_DELAY                                                0x0080000a
#define RFMXEVDO_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                              0x0080000b
#define RFMXEVDO_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                          0x0080000c
#define RFMXEVDO_ATTR_BAND_CLASS                                                   0x00800010
#define RFMXEVDO_ATTR_NUMBER_OF_CARRIERS                                           0x0080000e
#define RFMXEVDO_ATTR_CARRIER_FREQUENCY                                            0x0080000f
#define RFMXEVDO_ATTR_PHYSICAL_LAYER_SUBTYPE                                       0x00800011
#define RFMXEVDO_ATTR_CHANNEL_CONFIGURATION_MODE                                   0x00800012
#define RFMXEVDO_ATTR_UPLINK_NUMBER_OF_CHANNELS                                    0x00800018
#define RFMXEVDO_ATTR_UPLINK_DATA_MODULATION_TYPE                                  0x00800019
#define RFMXEVDO_ATTR_UPLINK_WALSH_CODE_LENGTH                                     0x0080001a
#define RFMXEVDO_ATTR_UPLINK_WALSH_CODE_NUMBER                                     0x0080001b
#define RFMXEVDO_ATTR_UPLINK_BRANCH                                                0x0080001c
#define RFMXEVDO_ATTR_UPLINK_SPREADING_I_MASK                                      0x00800029
#define RFMXEVDO_ATTR_UPLINK_SPREADING_Q_MASK                                      0x0080002a
#define RFMXEVDO_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                           0x0080d000
#define RFMXEVDO_ATTR_CDA_MEASUREMENT_ENABLED                                      0x00813000
#define RFMXEVDO_ATTR_CDA_SYNCHRONIZATION_MODE                                     0x00813002
#define RFMXEVDO_ATTR_CDA_MEASUREMENT_OFFSET                                       0x00813003
#define RFMXEVDO_ATTR_CDA_MEASUREMENT_LENGTH                                       0x00813004
#define RFMXEVDO_ATTR_CDA_UPLINK_WALSH_CODE_LENGTH                                 0x00813005
#define RFMXEVDO_ATTR_CDA_UPLINK_WALSH_CODE_NUMBER                                 0x00813006
#define RFMXEVDO_ATTR_CDA_UPLINK_BRANCH                                            0x00813007
#define RFMXEVDO_ATTR_CDA_POWER_UNIT                                               0x00813008
#define RFMXEVDO_ATTR_CDA_SPECTRUM_INVERTED                                        0x00813009
#define RFMXEVDO_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED                                0x0081300a
#define RFMXEVDO_ATTR_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED                        0x0081300b
#define RFMXEVDO_ATTR_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED                      0x0081300c
#define RFMXEVDO_ATTR_CDA_RECEIVE_FILTER_ENABLED                                   0x0081300d
#define RFMXEVDO_ATTR_CDA_ALL_TRACES_ENABLED                                       0x0081300e
#define RFMXEVDO_ATTR_CDA_RESULTS_FREQUENCY_ERROR                                  0x00813011
#define RFMXEVDO_ATTR_CDA_RESULTS_CHIP_RATE_ERROR                                  0x00813012
#define RFMXEVDO_ATTR_CDA_RESULTS_IQ_ORIGIN_OFFSET                                 0x00813013
#define RFMXEVDO_ATTR_CDA_RESULTS_IQ_GAIN_IMBALANCE                                0x00813014
#define RFMXEVDO_ATTR_CDA_RESULTS_IQ_QUADRATURE_ERROR                              0x00813015
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_RMS_SYMBOL_EVM                            0x00813016
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_PEAK_SYMBOL_EVM                           0x00813017
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_RMS_SYMBOL_MAGNITUDE_ERROR                0x00813018
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_RMS_SYMBOL_PHASE_ERROR                    0x00813019
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_MEAN_SYMBOL_POWER                         0x0081301a
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_TOTAL_POWER                               0x0081301b
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_TOTAL_ACTIVE_POWER                        0x0081301c
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_MEAN_ACTIVE_POWER                         0x0081301d
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_PEAK_ACTIVE_POWER                         0x0081301e
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_MEAN_INACTIVE_POWER                       0x0081301f
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_PEAK_INACTIVE_POWER                       0x00813020
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_I_MEAN_ACTIVE_POWER                       0x00813021
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_I_PEAK_INACTIVE_POWER                     0x00813022
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_Q_MEAN_ACTIVE_POWER                       0x00813023
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_Q_PEAK_INACTIVE_POWER                     0x00813024
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_MEAN_PILOT_POWER                          0x00813025
#define RFMXEVDO_ATTR_CDA_RESULTS_UPLINK_MEAN_AUXILIARY_PILOT_POWER                0x00813026
#define RFMXEVDO_ATTR_SLOTPOWER_MEASUREMENT_ENABLED                                0x00814000
#define RFMXEVDO_ATTR_SLOTPOWER_SYNCHRONIZATION_MODE                               0x00814002
#define RFMXEVDO_ATTR_SLOTPOWER_MEASUREMENT_OFFSET                                 0x00814003
#define RFMXEVDO_ATTR_SLOTPOWER_MEASUREMENT_LENGTH                                 0x00814004
#define RFMXEVDO_ATTR_SLOTPOWER_SPECTRUM_INVERTED                                  0x00814005
#define RFMXEVDO_ATTR_SLOTPOWER_RECEIVE_FILTER_ENABLED                             0x00814006
#define RFMXEVDO_ATTR_SLOTPHASE_MEASUREMENT_ENABLED                                0x00815000
#define RFMXEVDO_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE                               0x00815002
#define RFMXEVDO_ATTR_SLOTPHASE_MEASUREMENT_OFFSET                                 0x00815003
#define RFMXEVDO_ATTR_SLOTPHASE_MEASUREMENT_LENGTH                                 0x00815004
#define RFMXEVDO_ATTR_SLOTPHASE_SPECTRUM_INVERTED                                  0x00815005
#define RFMXEVDO_ATTR_SLOTPHASE_RECEIVE_FILTER_ENABLED                             0x00815006
#define RFMXEVDO_ATTR_SLOTPHASE_TRANSIENT_DURATION                                 0x00815007
#define RFMXEVDO_ATTR_SLOTPHASE_ALL_TRACES_ENABLED                                 0x00815008
#define RFMXEVDO_ATTR_SLOTPHASE_RESULTS_MAXIMUM_HALF_SLOT_PHASE_DISCONTINUITY      0x0081500b
#define RFMXEVDO_ATTR_SELECTED_PORTS                                               0x00800ffd
#define RFMXEVDO_ATTR_REFERENCE_LEVEL_HEADROOM                                     0x00800ffc
#define RFMXEVDO_ATTR_ACP_FFT_OVERLAP_MODE                                         0x00801039
#define RFMXEVDO_ATTR_ACP_FFT_OVERLAP                                              0x0080103a

// Values for RFMXEVDO_ATTR_TRIGGER_TYPE
#define RFMXEVDO_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXEVDO_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXEVDO_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXEVDO_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXEVDO_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXEVDO_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXEVDO_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXEVDO_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXEVDO_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXEVDO_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXEVDO_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXEVDO_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXEVDO_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXEVDO_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXEVDO_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXEVDO_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXEVDO_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXEVDO_VAL_TIMER_EVENT_STR                                                                "TimerEvent"
#define RFMXEVDO_VAL_PULSE_IN_STR                                                                   "PulseIn"
#define RFMXEVDO_VAL_DIO_PFI0_STR                                                                   "DIO/PFI0"
#define RFMXEVDO_VAL_DIO_PFI1_STR                                                                   "DIO/PFI1"
#define RFMXEVDO_VAL_DIO_PFI2_STR                                                                   "DIO/PFI2"
#define RFMXEVDO_VAL_DIO_PFI3_STR                                                                   "DIO/PFI3"
#define RFMXEVDO_VAL_DIO_PFI4_STR                                                                   "DIO/PFI4"
#define RFMXEVDO_VAL_DIO_PFI5_STR                                                                   "DIO/PFI5"
#define RFMXEVDO_VAL_DIO_PFI6_STR                                                                   "DIO/PFI6"
#define RFMXEVDO_VAL_DIO_PFI7_STR                                                                   "DIO/PFI7"

// Values for RFMXEVDO_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXEVDO_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXEVDO_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXEVDO_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXEVDO_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXEVDO_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXEVDO_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXEVDO_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXEVDO_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXEVDO_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXEVDO_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXEVDO_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXEVDO_ATTR_PHYSICAL_LAYER_SUBTYPE
#define RFMXEVDO_VAL_PHYSICAL_LAYER_SUBTYPE_0_1                                                     0
#define RFMXEVDO_VAL_PHYSICAL_LAYER_SUBTYPE_2                                                       1
#define RFMXEVDO_VAL_PHYSICAL_LAYER_SUBTYPE_3                                                       2

// Values for RFMXEVDO_ATTR_CHANNEL_CONFIGURATION_MODE
#define RFMXEVDO_VAL_CHANNEL_CONFIGURATION_MODE_AUTO_DETECT                                         0
#define RFMXEVDO_VAL_CHANNEL_CONFIGURATION_MODE_USER_DEFINED                                        1

// Values for RFMXEVDO_ATTR_UPLINK_DATA_MODULATION_TYPE
#define RFMXEVDO_VAL_UPLINK_DATA_MODULATION_TYPE_AUTO                                               0
#define RFMXEVDO_VAL_UPLINK_DATA_MODULATION_TYPE_DATA_CHANNEL_ABSENT                                1
#define RFMXEVDO_VAL_UPLINK_DATA_MODULATION_TYPE_B4                                                 2
#define RFMXEVDO_VAL_UPLINK_DATA_MODULATION_TYPE_Q4                                                 3
#define RFMXEVDO_VAL_UPLINK_DATA_MODULATION_TYPE_Q2                                                 4
#define RFMXEVDO_VAL_UPLINK_DATA_MODULATION_TYPE_Q4Q2                                               5
#define RFMXEVDO_VAL_UPLINK_DATA_MODULATION_TYPE_E4E2                                               6

// Values for RFMXEVDO_ATTR_UPLINK_BRANCH
#define RFMXEVDO_VAL_UPLINK_BRANCH_I                                                                0
#define RFMXEVDO_VAL_UPLINK_BRANCH_Q                                                                1
#define RFMXEVDO_VAL_UPLINK_BRANCH_I_AND_Q                                                          2

// Values for RFMXEVDO_ATTR_MODACC_SYNCHRONIZATION_MODE
#define RFMXEVDO_VAL_MODACC_SYNCHRONIZATION_MODE_FRAME                                              0
#define RFMXEVDO_VAL_MODACC_SYNCHRONIZATION_MODE_SLOT                                               1
#define RFMXEVDO_VAL_MODACC_SYNCHRONIZATION_MODE_ARBITRARY                                          2

// Values for RFMXEVDO_ATTR_MODACC_SPECTRUM_INVERTED
#define RFMXEVDO_VAL_MODACC_SPECTRUM_INVERTED_FALSE                                                 0
#define RFMXEVDO_VAL_MODACC_SPECTRUM_INVERTED_TRUE                                                  1

// Values for RFMXEVDO_ATTR_MODACC_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXEVDO_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                         0
#define RFMXEVDO_VAL_MODACC_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                          1

// Values for RFMXEVDO_ATTR_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXEVDO_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                 0
#define RFMXEVDO_VAL_MODACC_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                  1

// Values for RFMXEVDO_ATTR_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXEVDO_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                               0
#define RFMXEVDO_VAL_MODACC_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                1

// Values for RFMXEVDO_ATTR_MODACC_RECEIVE_FILTER_ENABLED
#define RFMXEVDO_VAL_MODACC_RECEIVE_FILTER_ENABLED_FALSE                                            0
#define RFMXEVDO_VAL_MODACC_RECEIVE_FILTER_ENABLED_TRUE                                             1

// Values for RFMXEVDO_ATTR_MODACC_MULTI_CARRIER_FILTER_ENABLED
#define RFMXEVDO_VAL_MODACC_MULTI_CARRIER_FILTER_ENABLED_FALSE                                      0
#define RFMXEVDO_VAL_MODACC_MULTI_CARRIER_FILTER_ENABLED_TRUE                                       1

// Values for RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_CDE_BRANCH
#define RFMXEVDO_VAL_MODACC_UPLINK_PEAK_CDE_BRANCH_I                                                0
#define RFMXEVDO_VAL_MODACC_UPLINK_PEAK_CDE_BRANCH_Q                                                1

// Values for RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_PEAK_ACTIVE_CDE_BRANCH
#define RFMXEVDO_VAL_MODACC_UPLINK_PEAK_ACTIVE_CDE_BRANCH_I                                         0
#define RFMXEVDO_VAL_MODACC_UPLINK_PEAK_ACTIVE_CDE_BRANCH_Q                                         1
#define RFMXEVDO_VAL_MODACC_UPLINK_PEAK_ACTIVE_CDE_BRANCH_I_AND_Q                                   2

// Values for RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_DETECTED_DATA_MODULATION_TYPE
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_DATA_MODULATION_TYPE_DATA_CHANNEL_ABSENT                1
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_DATA_MODULATION_TYPE_B4                                 2
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_DATA_MODULATION_TYPE_Q4                                 3
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_DATA_MODULATION_TYPE_Q2                                 4
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_DATA_MODULATION_TYPE_Q4Q2                               5
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_DATA_MODULATION_TYPE_E4E2                               6

// Values for RFMXEVDO_ATTR_MODACC_RESULTS_UPLINK_DETECTED_BRANCH
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_BRANCH_I                                                0
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_BRANCH_Q                                                1
#define RFMXEVDO_VAL_MODACC_UPLINK_DETECTED_BRANCH_I_AND_Q                                          2

// Values for RFMXEVDO_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER
#define RFMXEVDO_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_CLOSEST                                     0
#define RFMXEVDO_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_HIGHEST                                     1
#define RFMXEVDO_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_COMPOSITE                                   2
#define RFMXEVDO_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_SPECIFIC                                    3

// Values for RFMXEVDO_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXEVDO_VAL_ACP_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXEVDO_VAL_ACP_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXEVDO_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXEVDO_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXEVDO_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXEVDO_VAL_ACP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXEVDO_ATTR_ACP_SWEEP_TIME_AUTO
#define RFMXEVDO_VAL_ACP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXEVDO_VAL_ACP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXEVDO_ATTR_ACP_MEASUREMENT_METHOD
#define RFMXEVDO_VAL_ACP_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXEVDO_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1
#define RFMXEVDO_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                          2

// Values for RFMXEVDO_ATTR_ACP_NOISE_COMPENSATION_ENABLED
#define RFMXEVDO_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXEVDO_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXEVDO_ATTR_ACP_AVERAGING_ENABLED
#define RFMXEVDO_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXEVDO_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXEVDO_ATTR_ACP_AVERAGING_TYPE
#define RFMXEVDO_VAL_ACP_AVERAGING_TYPE_RMS                                                         0
#define RFMXEVDO_VAL_ACP_AVERAGING_TYPE_LOG                                                         1
#define RFMXEVDO_VAL_ACP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXEVDO_VAL_ACP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXEVDO_VAL_ACP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXEVDO_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXEVDO_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                          0
#define RFMXEVDO_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                           1

// Values for RFMXEVDO_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXEVDO_VAL_CHP_RBW_AUTO_FALSE                                                             0
#define RFMXEVDO_VAL_CHP_RBW_AUTO_TRUE                                                              1

// Values for RFMXEVDO_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXEVDO_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXEVDO_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXEVDO_VAL_CHP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXEVDO_ATTR_CHP_SWEEP_TIME_AUTO
#define RFMXEVDO_VAL_CHP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXEVDO_VAL_CHP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXEVDO_ATTR_CHP_AVERAGING_ENABLED
#define RFMXEVDO_VAL_CHP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXEVDO_VAL_CHP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXEVDO_ATTR_CHP_AVERAGING_TYPE
#define RFMXEVDO_VAL_CHP_AVERAGING_TYPE_RMS                                                         0
#define RFMXEVDO_VAL_CHP_AVERAGING_TYPE_LOG                                                         1
#define RFMXEVDO_VAL_CHP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXEVDO_VAL_CHP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXEVDO_VAL_CHP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXEVDO_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXEVDO_VAL_OBW_RBW_AUTO_FALSE                                                             0
#define RFMXEVDO_VAL_OBW_RBW_AUTO_TRUE                                                              1

// Values for RFMXEVDO_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXEVDO_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXEVDO_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXEVDO_VAL_OBW_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXEVDO_ATTR_OBW_SWEEP_TIME_AUTO
#define RFMXEVDO_VAL_OBW_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXEVDO_VAL_OBW_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXEVDO_ATTR_OBW_AVERAGING_ENABLED
#define RFMXEVDO_VAL_OBW_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXEVDO_VAL_OBW_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXEVDO_ATTR_OBW_AVERAGING_TYPE
#define RFMXEVDO_VAL_OBW_AVERAGING_TYPE_RMS                                                         0
#define RFMXEVDO_VAL_OBW_AVERAGING_TYPE_LOG                                                         1
#define RFMXEVDO_VAL_OBW_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXEVDO_VAL_OBW_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXEVDO_VAL_OBW_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXEVDO_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXEVDO_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FFT_BASED                                           0
#define RFMXEVDO_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN                                            1
#define RFMXEVDO_VAL_SEM_OFFSET_RBW_FILTER_TYPE_FLAT                                                2
#define RFMXEVDO_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_4                                       3
#define RFMXEVDO_VAL_SEM_OFFSET_RBW_FILTER_TYPE_SYNCH_TUNED_5                                       4

// Values for RFMXEVDO_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXEVDO_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXEVDO_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXEVDO_ATTR_SEM_AVERAGING_ENABLED
#define RFMXEVDO_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXEVDO_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXEVDO_ATTR_SEM_AVERAGING_TYPE
#define RFMXEVDO_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXEVDO_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXEVDO_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXEVDO_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXEVDO_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXEVDO_ATTR_SEM_RESULTS_COMPOSITE_MEASUREMENT_STATUS
#define RFMXEVDO_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXEVDO_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXEVDO_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXEVDO_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXEVDO_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXEVDO_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXEVDO_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXEVDO_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXEVDO_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXEVDO_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXEVDO_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXEVDO_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXEVDO_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for Boolean
#define RFMXEVDO_VAL_FALSE                                                                          0
#define RFMXEVDO_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXEVDO_VAL_MODACC                                                                         1 << 0
#define RFMXEVDO_VAL_ACP                                                                            1 << 1
#define RFMXEVDO_VAL_CHP                                                                            1 << 2
#define RFMXEVDO_VAL_OBW                                                                            1 << 3
#define RFMXEVDO_VAL_SEM                                                                            1 << 4
#define RFMXEVDO_VAL_CDA                                                                            1 << 5
#define RFMXEVDO_VAL_SLOTPHASE                                                                      1 << 6
#define RFMXEVDO_VAL_SLOTPOWER                                                                      1 << 7

// Values for FrequencyReferenceSource
#define RFMXEVDO_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXEVDO_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXEVDO_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXEVDO_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for RFMXEVDO_ATTR_LINK_DIRECTION
#define RFMXEVDO_VAL_LINK_DIRECTION_UPLINK                                                          1

// Values for RFAttenuationAuto
#define RFMXEVDO_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXEVDO_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXEVDO_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXEVDO_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

// Values for RFMXEVDO_ATTR_CDA_SYNCHRONIZATION_MODE
#define RFMXEVDO_VAL_CDA_SYNCHRONIZATION_MODE_FRAME                                                 0
#define RFMXEVDO_VAL_CDA_SYNCHRONIZATION_MODE_SLOT                                                  1
#define RFMXEVDO_VAL_CDA_SYNCHRONIZATION_MODE_ARBITRARY                                             2

// Values for RFMXEVDO_ATTR_CDA_UPLINK_BRANCH
#define RFMXEVDO_VAL_CDA_UPLINK_BRANCH_I                                                            0
#define RFMXEVDO_VAL_CDA_UPLINK_BRANCH_Q                                                            1
#define RFMXEVDO_VAL_CDA_UPLINK_BRANCH_I_AND_Q                                                      2

// Values for RFMXEVDO_ATTR_CDA_POWER_UNIT
#define RFMXEVDO_VAL_CDA_POWER_UNIT_DB                                                              0
#define RFMXEVDO_VAL_CDA_POWER_UNIT_DBM                                                             1

// Values for RFMXEVDO_ATTR_CDA_SPECTRUM_INVERTED
#define RFMXEVDO_VAL_CDA_SPECTRUM_INVERTED_FALSE                                                    0
#define RFMXEVDO_VAL_CDA_SPECTRUM_INVERTED_TRUE                                                     1

// Values for RFMXEVDO_ATTR_CDA_IQ_OFFSET_REMOVAL_ENABLED
#define RFMXEVDO_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_FALSE                                            0
#define RFMXEVDO_VAL_CDA_IQ_OFFSET_REMOVAL_ENABLED_TRUE                                             1

// Values for RFMXEVDO_ATTR_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED
#define RFMXEVDO_VAL_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_FALSE                                    0
#define RFMXEVDO_VAL_CDA_IQ_GAIN_IMBALANCE_REMOVAL_ENABLED_TRUE                                     1

// Values for RFMXEVDO_ATTR_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED
#define RFMXEVDO_VAL_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_FALSE                                  0
#define RFMXEVDO_VAL_CDA_IQ_QUADRATURE_ERROR_REMOVAL_ENABLED_TRUE                                   1

// Values for RFMXEVDO_ATTR_CDA_RECEIVE_FILTER_ENABLED
#define RFMXEVDO_VAL_CDA_RECEIVE_FILTER_ENABLED_FALSE                                               0
#define RFMXEVDO_VAL_CDA_RECEIVE_FILTER_ENABLED_TRUE                                                1

// Values for RFMXEVDO_ATTR_SLOTPOWER_SYNCHRONIZATION_MODE
#define RFMXEVDO_VAL_SLOTPOWER_SYNCHRONIZATION_MODE_FRAME                                           0
#define RFMXEVDO_VAL_SLOTPOWER_SYNCHRONIZATION_MODE_SLOT                                            1

// Values for RFMXEVDO_ATTR_SLOTPOWER_SPECTRUM_INVERTED
#define RFMXEVDO_VAL_SLOTPOWER_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXEVDO_VAL_SLOTPOWER_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXEVDO_ATTR_SLOTPOWER_RECEIVE_FILTER_ENABLED
#define RFMXEVDO_VAL_SLOTPOWER_RECEIVE_FILTER_ENABLED_FALSE                                         0
#define RFMXEVDO_VAL_SLOTPOWER_RECEIVE_FILTER_ENABLED_TRUE                                          1

// Values for RFMXEVDO_ATTR_SLOTPHASE_SYNCHRONIZATION_MODE
#define RFMXEVDO_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_FRAME                                           0
#define RFMXEVDO_VAL_SLOTPHASE_SYNCHRONIZATION_MODE_SLOT                                            1

// Values for RFMXEVDO_ATTR_SLOTPHASE_SPECTRUM_INVERTED
#define RFMXEVDO_VAL_SLOTPHASE_SPECTRUM_INVERTED_FALSE                                              0
#define RFMXEVDO_VAL_SLOTPHASE_SPECTRUM_INVERTED_TRUE                                               1

// Values for RFMXEVDO_ATTR_SLOTPHASE_RECEIVE_FILTER_ENABLED
#define RFMXEVDO_VAL_SLOTPHASE_RECEIVE_FILTER_ENABLED_FALSE                                         0
#define RFMXEVDO_VAL_SLOTPHASE_RECEIVE_FILTER_ENABLED_TRUE                                          1

// Values for RFMXEVDO_ATTR_ACP_FFT_OVERLAP_MODE
#define RFMXEVDO_VAL_ACP_FFT_OVERLAP_MODE_DISABLED                                                  0
#define RFMXEVDO_VAL_ACP_FFT_OVERLAP_MODE_AUTOMATIC                                                 1

/* ---------------- RFmxEVDO APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxEVDO_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxEVDO_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxEVDO_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxEVDO_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxEVDO_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxEVDO_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxEVDO_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxEVDO_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxEVDO_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxEVDO_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxEVDO_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxEVDO_BuildChannelString(
   char selectorString[],
   int32 channelNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxEVDO_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxEVDO_BuildCarrierString(
   char selectorString[],
   int32 carrierNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxEVDO_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxEVDO_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxEVDO_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxEVDO_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxEVDO_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxEVDO_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* done
);

int32 __stdcall RFmxEVDO_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxEVDO_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxEVDO_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxEVDO_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxEVDO_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxEVDO_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxEVDO_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxEVDO_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxEVDO_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxEVDO_CfgContiguousCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCarriers,
   int32 carrierAtCenterFrequency,
   int32 bandClass
);

int32 __stdcall RFmxEVDO_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxEVDO_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxEVDO_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxEVDO_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxEVDO_CfgFrequencyChannelNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 linkDirection,
   int32 bandClass,
   int32 channelNumber
);

int32 __stdcall RFmxEVDO_CfgUplinkNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkNumberOfChannels
);

int32 __stdcall RFmxEVDO_CfgUplinkDataModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkDataModulationType
);

int32 __stdcall RFmxEVDO_CfgUplinkUserDefinedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkWalshCodeLength,
   int32 uplinkWalshCodeNumber,
   int32 uplinkBranch
);

int32 __stdcall RFmxEVDO_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxEVDO_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxEVDO_CfgUplinkSpreading(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 uplinkSpreadingIMask,
   int64 uplinkSpreadingQMask
);

int32 __stdcall RFmxEVDO_CfgBandClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 bandClass
);

int32 __stdcall RFmxEVDO_CfgCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierFrequency
);

int32 __stdcall RFmxEVDO_CfgPhysicalLayerSubtype(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 physicalLayerSubtype
);

int32 __stdcall RFmxEVDO_CfgChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 channelConfigurationMode
);

int32 __stdcall RFmxEVDO_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxEVDO_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxEVDO_CfgNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCarriers
);

int32 __stdcall RFmxEVDO_CfgUplinkUserDefinedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 uplinkWalshCodeLength[],
   int32 uplinkWalshCodeNumber[],
   int32 uplinkBranch[],
   int32 numberOfElements
);

int32 __stdcall RFmxEVDO_CfgCarrierFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierFrequency[],
   int32 numberOfElements
);

int32 __stdcall RFmxEVDO_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxEVDO_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxEVDO_CHPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxEVDO_CHPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxEVDO_CHPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxEVDO_OBWCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxEVDO_OBWCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxEVDO_OBWCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxEVDO_ModAccCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxEVDO_ModAccCfgMultiCarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 multiCarrierFilterEnabled
);

int32 __stdcall RFmxEVDO_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxEVDO_ACPCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxEVDO_ACPCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxEVDO_ACPCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxEVDO_ACPCfgOffsetPowerReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetPowerReferenceCarrier,
   int32 offsetPowerReferenceSpecific
);

int32 __stdcall RFmxEVDO_ACPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxEVDO_ACPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxEVDO_CDACfgPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnit
);

int32 __stdcall RFmxEVDO_CDACfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxEVDO_CDACfgUplinkMeasurementChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 walshCodeLength,
   int32 walshCodeNumber,
   int32 branch
);

int32 __stdcall RFmxEVDO_SlotPhaseCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxEVDO_SlotPowerCfgSynchronizationModeAndInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMode,
   int32 measurementOffset,
   int32 measurementLength
);

int32 __stdcall RFmxEVDO_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxEVDO_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxEVDO_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxEVDO_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxEVDO_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxEVDO_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxEVDO_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxEVDO_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxEVDO_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxEVDO_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxEVDO_ACPFetchCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absolutePower[],
   float64 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ACPFetchOffsetMeasurementArray(
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

int32 __stdcall RFmxEVDO_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ACPFetchRelativePowersTrace(
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

int32 __stdcall RFmxEVDO_ACPFetchAbsolutePowersTrace(
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

int32 __stdcall RFmxEVDO_ACPFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* relativePower
);

int32 __stdcall RFmxEVDO_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower
);

int32 __stdcall RFmxEVDO_ACPFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxEVDO_ModAccFetchConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle constellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ModAccFetchConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 constellationI[],
   float32 constellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ModAccFetchUplinkDetectedChannelArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 uplinkDetectedWalshCodeLength[],
   int32 uplinkDetectedWalshCodeNumber[],
   int32 uplinkDetectedBranch[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ModAccFetchEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 EVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ModAccFetchMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 magnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ModAccFetchPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ModAccFetchUplinkDetectedDataModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* uplinkDetectedDataModulationType
);

int32 __stdcall RFmxEVDO_ModAccFetchUplinkDetectedChannel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* uplinkDetectedWalshCodeLength,
   int32* uplinkDetectedWalshCodeNumber,
   int32* uplinkDetectedBranch
);

int32 __stdcall RFmxEVDO_ModAccFetchUplinkEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* uplinkRMSEVM,
   float64* uplinkPeakEVM,
   float64* uplinkRho,
   float64* frequencyError,
   float64* chipRateError,
   float64* uplinkRMSMagnitudeError,
   float64* uplinkRMSPhaseError
);

int32 __stdcall RFmxEVDO_ModAccFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffset,
   float64* IQGainImbalance,
   float64* IQQuadratureError
);

int32 __stdcall RFmxEVDO_ModAccFetchUplinkNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* uplinkNumberOfDetectedChannels
);

int32 __stdcall RFmxEVDO_ModAccFetchUplinkPeakActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* uplinkPeakActiveCDE,
   int32* uplinkPeakActiveCDEWalshCodeLength,
   int32* uplinkPeakActiveCDEWalshCodeNumber,
   int32* uplinkPeakActiveCDEBranch
);

int32 __stdcall RFmxEVDO_ModAccFetchUplinkPeakCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* uplinkPeakCDE,
   int32* uplinkPeakCDEWalshCodeNumber,
   int32* uplinkPeakCDEBranch
);

int32 __stdcall RFmxEVDO_OBWFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_OBWFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* absolutePower,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxEVDO_CHPFetchCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 carrierAbsolutePower[],
   float64 carrierRelativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CHPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CHPFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsolutePower,
   float64* carrierRelativePower
);

int32 __stdcall RFmxEVDO_CHPFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxEVDO_SEMFetchCarrierMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 absoluteIntegratedPower[],
   float64 relativeIntegratedPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SEMFetchLowerOffsetMarginArray(
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

int32 __stdcall RFmxEVDO_SEMFetchLowerOffsetPowerArray(
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

int32 __stdcall RFmxEVDO_SEMFetchSpectrum(
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

int32 __stdcall RFmxEVDO_SEMFetchUpperOffsetMarginArray(
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

int32 __stdcall RFmxEVDO_SEMFetchUpperOffsetPowerArray(
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

int32 __stdcall RFmxEVDO_SEMFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower
);

int32 __stdcall RFmxEVDO_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxEVDO_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxEVDO_SEMFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxEVDO_SEMFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxEVDO_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxEVDO_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absoluteIntegratedPower,
   float64* relativeIntegratedPower,
   float64* absolutePeakPower,
   float64* peakFrequency,
   float64* relativePeakPower
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkSymbolEVMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolEVM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkSymbolMagnitudeErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolMagnitudeError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkSymbolPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkCodeDomainIAndQPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 ICodeDomainPowers[],
   float32 QCodeDomainPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkSymbolPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolPowers[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkSymbolConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle symbolConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkSymbolConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 symbolConstellationI[],
   float32 symbolConstellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_CDAFetchIQImpairments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IQOriginOffset,
   float64* IQGainImbalance,
   float64* IQQuadratureError
);

int32 __stdcall RFmxEVDO_CDAFetchUplinkSymbolEVM(
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

int32 __stdcall RFmxEVDO_CDAFetchUplinkCodeDomainPower(
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

int32 __stdcall RFmxEVDO_CDAFetchUplinkCodeDomainIAndQPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* IMeanActivePower,
   float64* QMeanActivePower,
   float64* IPeakInactivePower,
   float64* QPeakInactivePower
);

int32 __stdcall RFmxEVDO_SlotPhaseFetchPhaseDiscontinuities(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 halfSlotPhaseDiscontinuity[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SlotPhaseFetchChipPhaseErrorTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chipPhaseError[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SlotPhaseFetchChipPhaseErrorLinearFitTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 chipPhaseErrorLinearFit[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_SlotPhaseFetchMaximumHalfSlotPhaseDiscontinuity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* maximumHalfSlotPhaseDiscontinuity
);

int32 __stdcall RFmxEVDO_SlotPowerFetchPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 halfSlotPower[],
   float64 halfSlotPowerDelta[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxEVDO_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetMultiCarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetMultiCarrierFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkRMSMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkRMSPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkRho(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakCDEWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakCDEBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakActiveCDE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakActiveCDEWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakActiveCDEWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkPeakActiveCDEBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkDetectedDataModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkNumberOfDetectedChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkDetectedWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkDetectedWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ModAccGetResultsUplinkDetectedBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetOffsetPowerReferenceSpecific(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetOffsetPowerReferenceSpecific(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetResultsCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_ACPGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_ACPSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_ACPGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CHPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CHPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CHPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CHPGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CHPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CHPGetResultsCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_OBWGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_OBWGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_OBWSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_OBWGetResultsOccupiedBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_OBWGetResultsAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_OBWGetResultsStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_OBWGetResultsStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsCompositeMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsCarrierRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsCarrierAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsCarrierPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetRelativeIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetRelativePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetBandClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetBandClass(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetPhysicalLayerSubtype(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetPhysicalLayerSubtype(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetChannelConfigurationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetUplinkNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetUplinkNumberOfChannels(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetUplinkDataModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetUplinkDataModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetUplinkWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetUplinkWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetUplinkWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetUplinkWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetUplinkBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SetUplinkBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_GetUplinkSpreadingImask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 *attrVal
);

int32 __stdcall RFmxEVDO_SetUplinkSpreadingImask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 attrVal
);

int32 __stdcall RFmxEVDO_GetUplinkSpreadingQmask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 *attrVal
);

int32 __stdcall RFmxEVDO_SetUplinkSpreadingQmask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int64 attrVal
);

int32 __stdcall RFmxEVDO_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxEVDO_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxEVDO_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetUplinkWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetUplinkWalshCodeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetUplinkWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetUplinkWalshCodeNumber(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetUplinkBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetUplinkBranch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetPowerUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetIQOffsetRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetIQGainImbalanceRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetIQQuadratureErrorRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_CDASetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsFrequencyError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsChipRateError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsIQOriginOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsIQGainImbalance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsIQQuadratureError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkRMSSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkPeakSymbolEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkRMSSymbolMagnitudeError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkRMSSymbolPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkMeanSymbolPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkTotalPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkTotalActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkPeakActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkMeanInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkIMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkIPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkQMeanActivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkQPeakInactivePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkMeanPilotPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_CDAGetResultsUplinkMeanAuxiliaryPilotPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPowerSetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetSynchronizationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetSpectrumInverted(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetReceiveFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetTransientDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetTransientDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxEVDO_SlotPhaseGetResultsMaximumHalfSlotPhaseDiscontinuity(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

// Values for RFMXEVDO_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXEVDO_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FALSE                                      0
#define RFMXEVDO_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_TRUE                                       1

// Values for RFMXEVDO_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXEVDO_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FALSE                                      0
#define RFMXEVDO_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_TRUE                                       1

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxEVDO_CalculateFrequencyFromChannelNumber(
   int32 linkDirection,
   int32 bandClass,
   int32 channelNumber,
   float64 *centerFrequency
);

int32 __stdcall RFmxEVDO_AnalyzeIQ(
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

int32 __stdcall RFmxEVDO_AnalyzeIQSplit(
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

int32 __stdcall RFmxEVDO_AnalyzeSpectrum(
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

