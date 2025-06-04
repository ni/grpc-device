
/****************************************************************************************************
*          National Instruments RFmx SpecAn
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2024.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxSpecAn.h
*
* Purpose:  National Instruments RFmx SpecAn,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_SPECAN_H__
#define __NI_RFMX_SPECAN_H__

#include "niRFmxInstr.h"

#define RFMXSPECAN_ATTR_SELECTED_PORTS                                                 0x00100ffd
#define RFMXSPECAN_ATTR_CENTER_FREQUENCY                                               0x00100001
#define RFMXSPECAN_ATTR_REFERENCE_LEVEL                                                0x00100002
#define RFMXSPECAN_ATTR_EXTERNAL_ATTENUATION                                           0x00100003
#define RFMXSPECAN_ATTR_REFERENCE_LEVEL_HEADROOM                                       0x00100ffc
#define RFMXSPECAN_ATTR_TRIGGER_TYPE                                                   0x00100004
#define RFMXSPECAN_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                    0x00100005
#define RFMXSPECAN_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                      0x00100006
#define RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                   0x00100007
#define RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                    0x00100008
#define RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                               0x00100fff
#define RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                    0x00100009
#define RFMXSPECAN_ATTR_TRIGGER_DELAY                                                  0x0010000a
#define RFMXSPECAN_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                0x0010000b
#define RFMXSPECAN_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                            0x0010000c
#define RFMXSPECAN_ATTR_NUMBER_OF_STEPS                                                0x00100ff8
#define RFMXSPECAN_ATTR_LIST_STEP_TIMER_DURATION                                       0x00100ff9
#define RFMXSPECAN_ATTR_LIST_STEP_TIMER_OFFSET                                         0x00100ff7
#define RFMXSPECAN_ATTR_ACP_MEASUREMENT_ENABLED                                        0x00101000
#define RFMXSPECAN_ATTR_ACP_NUMBER_OF_CARRIERS                                         0x00101002
#define RFMXSPECAN_ATTR_ACP_CARRIER_MODE                                               0x00101003
#define RFMXSPECAN_ATTR_ACP_CARRIER_FREQUENCY                                          0x00101004
#define RFMXSPECAN_ATTR_ACP_CARRIER_INTEGRATION_BANDWIDTH                              0x00101005
#define RFMXSPECAN_ATTR_ACP_CARRIER_RRC_FILTER_ENABLED                                 0x00101006
#define RFMXSPECAN_ATTR_ACP_CARRIER_RRC_FILTER_ALPHA                                   0x00101007
#define RFMXSPECAN_ATTR_ACP_NUMBER_OF_OFFSETS                                          0x00101008
#define RFMXSPECAN_ATTR_ACP_OFFSET_ENABLED                                             0x00101009
#define RFMXSPECAN_ATTR_ACP_OFFSET_FREQUENCY                                           0x0010100a
#define RFMXSPECAN_ATTR_ACP_OFFSET_SIDEBAND                                            0x0010100b
#define RFMXSPECAN_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER                             0x0010100c
#define RFMXSPECAN_ATTR_ACP_OFFSET_POWER_REFERENCE_SPECIFIC                            0x0010100d
#define RFMXSPECAN_ATTR_ACP_OFFSET_INTEGRATION_BANDWIDTH                               0x0010100e
#define RFMXSPECAN_ATTR_ACP_OFFSET_RELATIVE_ATTENUATION                                0x0010100f
#define RFMXSPECAN_ATTR_ACP_OFFSET_RRC_FILTER_ENABLED                                  0x00101010
#define RFMXSPECAN_ATTR_ACP_OFFSET_RRC_FILTER_ALPHA                                    0x00101011
#define RFMXSPECAN_ATTR_ACP_OFFSET_FREQUENCY_DEFINITION                                0x00101037
#define RFMXSPECAN_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH                                  0x0010101b
#define RFMXSPECAN_ATTR_ACP_RBW_FILTER_BANDWIDTH                                       0x0010101c
#define RFMXSPECAN_ATTR_ACP_RBW_FILTER_TYPE                                            0x0010101d
#define RFMXSPECAN_ATTR_ACP_RBW_FILTER_BANDWIDTH_DEFINITION                            0x00101038
#define RFMXSPECAN_ATTR_ACP_SWEEP_TIME_AUTO                                            0x0010101e
#define RFMXSPECAN_ATTR_ACP_SWEEP_TIME_INTERVAL                                        0x0010101f
#define RFMXSPECAN_ATTR_ACP_DETECTOR_TYPE                                              0x00101042
#define RFMXSPECAN_ATTR_ACP_DETECTOR_POINTS                                            0x00101043
#define RFMXSPECAN_ATTR_ACP_POWER_UNITS                                                0x00101013
#define RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD                                         0x00101012
#define RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_MODE                                     0x00101041
#define RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_AUTO                           0x00101040
#define RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_COUNT                          0x0010103f
#define RFMXSPECAN_ATTR_ACP_NOISE_COMPENSATION_ENABLED                                 0x00101020
#define RFMXSPECAN_ATTR_ACP_NOISE_COMPENSATION_TYPE                                    0x0010103e
#define RFMXSPECAN_ATTR_ACP_AVERAGING_ENABLED                                          0x00101016
#define RFMXSPECAN_ATTR_ACP_AVERAGING_COUNT                                            0x00101015
#define RFMXSPECAN_ATTR_ACP_AVERAGING_TYPE                                             0x00101018
#define RFMXSPECAN_ATTR_ACP_MEASUREMENT_MODE                                           0x0010103d
#define RFMXSPECAN_ATTR_ACP_FFT_WINDOW                                                 0x00101019
#define RFMXSPECAN_ATTR_ACP_FFT_PADDING                                                0x0010101a
#define RFMXSPECAN_ATTR_ACP_FFT_OVERLAP_MODE                                           0x0010103b
#define RFMXSPECAN_ATTR_ACP_FFT_OVERLAP                                                0x0010103c
#define RFMXSPECAN_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO                                0x00101034
#define RFMXSPECAN_ATTR_ACP_NEAR_IF_OUTPUT_POWER_OFFSET                                0x00101035
#define RFMXSPECAN_ATTR_ACP_FAR_IF_OUTPUT_POWER_OFFSET                                 0x00101036
#define RFMXSPECAN_ATTR_ACP_SEQUENTIAL_FFT_SIZE                                        0x0010103a
#define RFMXSPECAN_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE                                  0x00101039
#define RFMXSPECAN_ATTR_ACP_ALL_TRACES_ENABLED                                         0x00101021
#define RFMXSPECAN_ATTR_ACP_NUMBER_OF_ANALYSIS_THREADS                                 0x00101014
#define RFMXSPECAN_ATTR_ACP_RESULTS_TOTAL_CARRIER_POWER                                0x00101022
#define RFMXSPECAN_ATTR_ACP_RESULTS_FREQUENCY_RESOLUTION                               0x00101023
#define RFMXSPECAN_ATTR_ACP_RESULTS_CARRIER_FREQUENCY                                  0x00101024
#define RFMXSPECAN_ATTR_ACP_RESULTS_CARRIER_INTEGRATION_BANDWIDTH                      0x00101025
#define RFMXSPECAN_ATTR_ACP_RESULTS_CARRIER_ABSOLUTE_POWER                             0x00101026
#define RFMXSPECAN_ATTR_ACP_RESULTS_CARRIER_TOTAL_RELATIVE_POWER                       0x00101027
#define RFMXSPECAN_ATTR_ACP_RESULTS_LOWER_OFFSET_FREQUENCY_REFERENCE_CARRIER           0x00101028
#define RFMXSPECAN_ATTR_ACP_RESULTS_LOWER_OFFSET_FREQUENCY                             0x00101029
#define RFMXSPECAN_ATTR_ACP_RESULTS_LOWER_OFFSET_INTEGRATION_BANDWIDTH                 0x0010102a
#define RFMXSPECAN_ATTR_ACP_RESULTS_LOWER_OFFSET_POWER_REFERENCE_CARRIER               0x0010102b
#define RFMXSPECAN_ATTR_ACP_RESULTS_LOWER_OFFSET_ABSOLUTE_POWER                        0x0010102c
#define RFMXSPECAN_ATTR_ACP_RESULTS_LOWER_OFFSET_RELATIVE_POWER                        0x0010102d
#define RFMXSPECAN_ATTR_ACP_RESULTS_UPPER_OFFSET_FREQUENCY_REFERENCE_CARRIER           0x0010102e
#define RFMXSPECAN_ATTR_ACP_RESULTS_UPPER_OFFSET_FREQUENCY                             0x0010102f
#define RFMXSPECAN_ATTR_ACP_RESULTS_UPPER_OFFSET_INTEGRATION_BANDWIDTH                 0x00101030
#define RFMXSPECAN_ATTR_ACP_RESULTS_UPPER_OFFSET_POWER_REFERENCE_CARRIER               0x00101031
#define RFMXSPECAN_ATTR_ACP_RESULTS_UPPER_OFFSET_ABSOLUTE_POWER                        0x00101032
#define RFMXSPECAN_ATTR_ACP_RESULTS_UPPER_OFFSET_RELATIVE_POWER                        0x00101033
#define RFMXSPECAN_ATTR_CCDF_MEASUREMENT_ENABLED                                       0x00102000
#define RFMXSPECAN_ATTR_CCDF_MEASUREMENT_INTERVAL                                      0x00102002
#define RFMXSPECAN_ATTR_CCDF_NUMBER_OF_RECORDS                                         0x00102004
#define RFMXSPECAN_ATTR_CCDF_RBW_FILTER_BANDWIDTH                                      0x00102007
#define RFMXSPECAN_ATTR_CCDF_RBW_FILTER_TYPE                                           0x00102008
#define RFMXSPECAN_ATTR_CCDF_RBW_FILTER_RRC_ALPHA                                      0x00102006
#define RFMXSPECAN_ATTR_CCDF_THRESHOLD_ENABLED                                         0x00102009
#define RFMXSPECAN_ATTR_CCDF_THRESHOLD_TYPE                                            0x0010200b
#define RFMXSPECAN_ATTR_CCDF_THRESHOLD_LEVEL                                           0x0010200a
#define RFMXSPECAN_ATTR_CCDF_ALL_TRACES_ENABLED                                        0x0010200d
#define RFMXSPECAN_ATTR_CCDF_NUMBER_OF_ANALYSIS_THREADS                                0x00102003
#define RFMXSPECAN_ATTR_CCDF_RESULTS_MEAN_POWER                                        0x0010200e
#define RFMXSPECAN_ATTR_CCDF_RESULTS_MEAN_POWER_PERCENTILE                             0x0010200f
#define RFMXSPECAN_ATTR_CCDF_RESULTS_TEN_PERCENT_POWER                                 0x00102010
#define RFMXSPECAN_ATTR_CCDF_RESULTS_ONE_PERCENT_POWER                                 0x00102011
#define RFMXSPECAN_ATTR_CCDF_RESULTS_ONE_TENTH_PERCENT_POWER                           0x00102012
#define RFMXSPECAN_ATTR_CCDF_RESULTS_ONE_HUNDREDTH_PERCENT_POWER                       0x00102013
#define RFMXSPECAN_ATTR_CCDF_RESULTS_ONE_THOUSANDTH_PERCENT_POWER                      0x00102014
#define RFMXSPECAN_ATTR_CCDF_RESULTS_ONE_TEN_THOUSANDTH_PERCENT_POWER                  0x00102015
#define RFMXSPECAN_ATTR_CCDF_RESULTS_PEAK_POWER                                        0x00102016
#define RFMXSPECAN_ATTR_CCDF_RESULTS_MEASURED_SAMPLES_COUNT                            0x00102017
#define RFMXSPECAN_ATTR_CHP_MEASUREMENT_ENABLED                                        0x00103000
#define RFMXSPECAN_ATTR_CHP_SPAN                                                       0x00103004
#define RFMXSPECAN_ATTR_CHP_NUMBER_OF_CARRIERS                                         0x00103018
#define RFMXSPECAN_ATTR_CHP_CARRIER_FREQUENCY                                          0x00103019
#define RFMXSPECAN_ATTR_CHP_CARRIER_INTEGRATION_BANDWIDTH                              0x00103002
#define RFMXSPECAN_ATTR_CHP_CARRIER_RRC_FILTER_ENABLED                                 0x0010300f
#define RFMXSPECAN_ATTR_CHP_CARRIER_RRC_FILTER_ALPHA                                   0x00103010
#define RFMXSPECAN_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH                                  0x0010300c
#define RFMXSPECAN_ATTR_CHP_RBW_FILTER_BANDWIDTH                                       0x0010300d
#define RFMXSPECAN_ATTR_CHP_RBW_FILTER_TYPE                                            0x0010300e
#define RFMXSPECAN_ATTR_CHP_RBW_FILTER_BANDWIDTH_DEFINITION                            0x0010301e
#define RFMXSPECAN_ATTR_CHP_SWEEP_TIME_AUTO                                            0x00103011
#define RFMXSPECAN_ATTR_CHP_SWEEP_TIME_INTERVAL                                        0x00103012
#define RFMXSPECAN_ATTR_CHP_DETECTOR_TYPE                                              0x00103013
#define RFMXSPECAN_ATTR_CHP_DETECTOR_POINTS                                            0x00103026
#define RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_MODE                                     0x00103025
#define RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_AUTO                           0x00103024
#define RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_COUNT                          0x00103023
#define RFMXSPECAN_ATTR_CHP_NOISE_COMPENSATION_ENABLED                                 0x00103021
#define RFMXSPECAN_ATTR_CHP_NOISE_COMPENSATION_TYPE                                    0x00103022
#define RFMXSPECAN_ATTR_CHP_AVERAGING_ENABLED                                          0x00103007
#define RFMXSPECAN_ATTR_CHP_AVERAGING_COUNT                                            0x00103006
#define RFMXSPECAN_ATTR_CHP_AVERAGING_TYPE                                             0x00103009
#define RFMXSPECAN_ATTR_CHP_MEASUREMENT_MODE                                           0x00103020
#define RFMXSPECAN_ATTR_CHP_FFT_WINDOW                                                 0x0010300a
#define RFMXSPECAN_ATTR_CHP_FFT_PADDING                                                0x0010300b
#define RFMXSPECAN_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE                                  0x0010301f
#define RFMXSPECAN_ATTR_CHP_ALL_TRACES_ENABLED                                         0x00103014
#define RFMXSPECAN_ATTR_CHP_NUMBER_OF_ANALYSIS_THREADS                                 0x00103003
#define RFMXSPECAN_ATTR_CHP_RESULTS_TOTAL_CARRIER_POWER                                0x0010301a
#define RFMXSPECAN_ATTR_CHP_RESULTS_FREQUENCY_RESOLUTION                               0x00103017
#define RFMXSPECAN_ATTR_CHP_RESULTS_CARRIER_FREQUENCY                                  0x0010301b
#define RFMXSPECAN_ATTR_CHP_RESULTS_CARRIER_INTEGRATION_BANDWIDTH                      0x0010301c
#define RFMXSPECAN_ATTR_CHP_RESULTS_CARRIER_ABSOLUTE_POWER                             0x00103015
#define RFMXSPECAN_ATTR_CHP_RESULTS_CARRIER_PSD                                        0x00103016
#define RFMXSPECAN_ATTR_CHP_RESULTS_CARRIER_RELATIVE_POWER                             0x0010301d
#define RFMXSPECAN_ATTR_FCNT_MEASUREMENT_ENABLED                                       0x00104000
#define RFMXSPECAN_ATTR_FCNT_MEASUREMENT_INTERVAL                                      0x00104002
#define RFMXSPECAN_ATTR_FCNT_RBW_FILTER_BANDWIDTH                                      0x0010400a
#define RFMXSPECAN_ATTR_FCNT_RBW_FILTER_TYPE                                           0x0010400b
#define RFMXSPECAN_ATTR_FCNT_RBW_FILTER_RRC_ALPHA                                      0x00104009
#define RFMXSPECAN_ATTR_FCNT_THRESHOLD_ENABLED                                         0x0010400c
#define RFMXSPECAN_ATTR_FCNT_THRESHOLD_TYPE                                            0x0010400e
#define RFMXSPECAN_ATTR_FCNT_THRESHOLD_LEVEL                                           0x0010400d
#define RFMXSPECAN_ATTR_FCNT_AVERAGING_ENABLED                                         0x00104006
#define RFMXSPECAN_ATTR_FCNT_AVERAGING_COUNT                                           0x00104005
#define RFMXSPECAN_ATTR_FCNT_AVERAGING_TYPE                                            0x00104008
#define RFMXSPECAN_ATTR_FCNT_ALL_TRACES_ENABLED                                        0x00104010
#define RFMXSPECAN_ATTR_FCNT_NUMBER_OF_ANALYSIS_THREADS                                0x00104003
#define RFMXSPECAN_ATTR_FCNT_RESULTS_AVERAGE_RELATIVE_FREQUENCY                        0x00104011
#define RFMXSPECAN_ATTR_FCNT_RESULTS_AVERAGE_ABSOLUTE_FREQUENCY                        0x00104013
#define RFMXSPECAN_ATTR_FCNT_RESULTS_MEAN_PHASE                                        0x00104012
#define RFMXSPECAN_ATTR_FCNT_RESULTS_ALLAN_DEVIATION                                   0x00104014
#define RFMXSPECAN_ATTR_HARM_MEASUREMENT_ENABLED                                       0x00105000
#define RFMXSPECAN_ATTR_HARM_FUNDAMENTAL_RBW_FILTER_BANDWIDTH                          0x00105004
#define RFMXSPECAN_ATTR_HARM_FUNDAMENTAL_RBW_FILTER_TYPE                               0x00105005
#define RFMXSPECAN_ATTR_HARM_FUNDAMENTAL_RBW_FILTER_ALPHA                              0x00105003
#define RFMXSPECAN_ATTR_HARM_FUNDAMENTAL_MEASUREMENT_INTERVAL                          0x00105006
#define RFMXSPECAN_ATTR_HARM_NUMBER_OF_HARMONICS                                       0x00105007
#define RFMXSPECAN_ATTR_HARM_AUTO_SETUP_ENABLED                                        0x00105008
#define RFMXSPECAN_ATTR_HARM_HARMONIC_ENABLED                                          0x00105009
#define RFMXSPECAN_ATTR_HARM_HARMONIC_ORDER                                            0x0010500a
#define RFMXSPECAN_ATTR_HARM_HARMONIC_BANDWIDTH                                        0x00105018
#define RFMXSPECAN_ATTR_HARM_HARMONIC_MEASUREMENT_INTERVAL                             0x0010500b
#define RFMXSPECAN_ATTR_HARM_MEASUREMENT_METHOD                                        0x0010501a
#define RFMXSPECAN_ATTR_HARM_NOISE_COMPENSATION_ENABLED                                0x0010501b
#define RFMXSPECAN_ATTR_HARM_AVERAGING_ENABLED                                         0x0010500d
#define RFMXSPECAN_ATTR_HARM_AVERAGING_COUNT                                           0x0010500c
#define RFMXSPECAN_ATTR_HARM_AVERAGING_TYPE                                            0x0010500f
#define RFMXSPECAN_ATTR_HARM_ALL_TRACES_ENABLED                                        0x00105010
#define RFMXSPECAN_ATTR_HARM_NUMBER_OF_ANALYSIS_THREADS                                0x00105002
#define RFMXSPECAN_ATTR_HARM_RESULTS_TOTAL_HARMONIC_DISTORTION                         0x00105013
#define RFMXSPECAN_ATTR_HARM_RESULTS_AVERAGE_FUNDAMENTAL_POWER                         0x00105012
#define RFMXSPECAN_ATTR_HARM_RESULTS_FUNDAMENTAL_FREQUENCY                             0x00105011
#define RFMXSPECAN_ATTR_HARM_RESULTS_HARMONIC_AVERAGE_ABSOLUTE_POWER                   0x00105016
#define RFMXSPECAN_ATTR_HARM_RESULTS_HARMONIC_AVERAGE_RELATIVE_POWER                   0x00105017
#define RFMXSPECAN_ATTR_HARM_RESULTS_HARMONIC_FREQUENCY                                0x00105014
#define RFMXSPECAN_ATTR_HARM_RESULTS_HARMONIC_RBW                                      0x00105015
#define RFMXSPECAN_ATTR_OBW_MEASUREMENT_ENABLED                                        0x00106000
#define RFMXSPECAN_ATTR_OBW_SPAN                                                       0x00106004
#define RFMXSPECAN_ATTR_OBW_BANDWIDTH_PERCENTAGE                                       0x00106002
#define RFMXSPECAN_ATTR_OBW_POWER_UNITS                                                0x00106018
#define RFMXSPECAN_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH                                  0x0010600c
#define RFMXSPECAN_ATTR_OBW_RBW_FILTER_BANDWIDTH                                       0x0010600d
#define RFMXSPECAN_ATTR_OBW_RBW_FILTER_TYPE                                            0x0010600e
#define RFMXSPECAN_ATTR_OBW_RBW_FILTER_BANDWIDTH_DEFINITION                            0x00106019
#define RFMXSPECAN_ATTR_OBW_SWEEP_TIME_AUTO                                            0x0010600f
#define RFMXSPECAN_ATTR_OBW_SWEEP_TIME_INTERVAL                                        0x00106010
#define RFMXSPECAN_ATTR_OBW_AVERAGING_ENABLED                                          0x00106007
#define RFMXSPECAN_ATTR_OBW_AVERAGING_COUNT                                            0x00106006
#define RFMXSPECAN_ATTR_OBW_AVERAGING_TYPE                                             0x00106009
#define RFMXSPECAN_ATTR_OBW_FFT_WINDOW                                                 0x0010600a
#define RFMXSPECAN_ATTR_OBW_FFT_PADDING                                                0x0010600b
#define RFMXSPECAN_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE                                  0x0010601a
#define RFMXSPECAN_ATTR_OBW_ALL_TRACES_ENABLED                                         0x00106012
#define RFMXSPECAN_ATTR_OBW_NUMBER_OF_ANALYSIS_THREADS                                 0x00106003
#define RFMXSPECAN_ATTR_OBW_RESULTS_OCCUPIED_BANDWIDTH                                 0x00106013
#define RFMXSPECAN_ATTR_OBW_RESULTS_AVERAGE_POWER                                      0x00106014
#define RFMXSPECAN_ATTR_OBW_RESULTS_START_FREQUENCY                                    0x00106015
#define RFMXSPECAN_ATTR_OBW_RESULTS_STOP_FREQUENCY                                     0x00106016
#define RFMXSPECAN_ATTR_OBW_RESULTS_FREQUENCY_RESOLUTION                               0x00106017
#define RFMXSPECAN_ATTR_SEM_MEASUREMENT_ENABLED                                        0x00108000
#define RFMXSPECAN_ATTR_SEM_NUMBER_OF_CARRIERS                                         0x00108002
#define RFMXSPECAN_ATTR_SEM_CARRIER_ENABLED                                            0x00108003
#define RFMXSPECAN_ATTR_SEM_CARRIER_FREQUENCY                                          0x00108004
#define RFMXSPECAN_ATTR_SEM_CARRIER_INTEGRATION_BANDWIDTH                              0x00108005
#define RFMXSPECAN_ATTR_SEM_CARRIER_CHANNEL_BANDWIDTH                                  0x0010804b
#define RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_AUTO_BANDWIDTH                          0x00108006
#define RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_BANDWIDTH                               0x00108007
#define RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_TYPE                                    0x00108008
#define RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_BANDWIDTH_DEFINITION                    0x0010804e
#define RFMXSPECAN_ATTR_SEM_CARRIER_RRC_FILTER_ENABLED                                 0x00108009
#define RFMXSPECAN_ATTR_SEM_CARRIER_RRC_FILTER_ALPHA                                   0x0010800a
#define RFMXSPECAN_ATTR_SEM_NUMBER_OF_OFFSETS                                          0x0010800b
#define RFMXSPECAN_ATTR_SEM_OFFSET_ENABLED                                             0x00108012
#define RFMXSPECAN_ATTR_SEM_OFFSET_START_FREQUENCY                                     0x00108014
#define RFMXSPECAN_ATTR_SEM_OFFSET_STOP_FREQUENCY                                      0x00108015
#define RFMXSPECAN_ATTR_SEM_OFFSET_SIDEBAND                                            0x00108013
#define RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_AUTO_BANDWIDTH                           0x00108016
#define RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH                                0x00108017
#define RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_TYPE                                     0x00108018
#define RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH_DEFINITION                     0x0010804d
#define RFMXSPECAN_ATTR_SEM_OFFSET_BANDWIDTH_INTEGRAL                                  0x0010800c
#define RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_ATTENUATION                                0x0010800e
#define RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK                                     0x0010800d
#define RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_MODE                                 0x0010800f
#define RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_START                                0x00108010
#define RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_STOP                                 0x00108011
#define RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_MODE                                 0x00108019
#define RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_START                                0x0010801a
#define RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_STOP                                 0x0010801b
#define RFMXSPECAN_ATTR_SEM_OFFSET_FREQUENCY_DEFINITION                                0x0010804c
#define RFMXSPECAN_ATTR_SEM_POWER_UNITS                                                0x0010801c
#define RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE                                             0x00108024
#define RFMXSPECAN_ATTR_SEM_SWEEP_TIME_AUTO                                            0x00108025
#define RFMXSPECAN_ATTR_SEM_SWEEP_TIME_INTERVAL                                        0x00108026
#define RFMXSPECAN_ATTR_SEM_AVERAGING_ENABLED                                          0x0010801f
#define RFMXSPECAN_ATTR_SEM_AVERAGING_COUNT                                            0x0010801e
#define RFMXSPECAN_ATTR_SEM_AVERAGING_TYPE                                             0x00108021
#define RFMXSPECAN_ATTR_SEM_FFT_WINDOW                                                 0x00108022
#define RFMXSPECAN_ATTR_SEM_FFT_PADDING                                                0x00108023
#define RFMXSPECAN_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE                                  0x0010804f
#define RFMXSPECAN_ATTR_SEM_ALL_TRACES_ENABLED                                         0x00108027
#define RFMXSPECAN_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                                 0x0010801d
#define RFMXSPECAN_ATTR_SEM_RESULTS_TOTAL_CARRIER_POWER                                0x00108028
#define RFMXSPECAN_ATTR_SEM_RESULTS_COMPOSITE_MEASUREMENT_STATUS                       0x00108029
#define RFMXSPECAN_ATTR_SEM_RESULTS_FREQUENCY_RESOLUTION                               0x0010802a
#define RFMXSPECAN_ATTR_SEM_RESULTS_CARRIER_TOTAL_RELATIVE_POWER                       0x0010802e
#define RFMXSPECAN_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_POWER                             0x0010802d
#define RFMXSPECAN_ATTR_SEM_RESULTS_CARRIER_PEAK_ABSOLUTE_POWER                        0x0010802f
#define RFMXSPECAN_ATTR_SEM_RESULTS_CARRIER_PEAK_FREQUENCY                             0x00108030
#define RFMXSPECAN_ATTR_SEM_RESULTS_CARRIER_FREQUENCY                                  0x0010802b
#define RFMXSPECAN_ATTR_SEM_RESULTS_CARRIER_INTEGRATION_BANDWIDTH                      0x0010802c
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS                    0x0010803d
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_TOTAL_ABSOLUTE_POWER                  0x00108034
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_TOTAL_RELATIVE_POWER                  0x00108035
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_ABSOLUTE_POWER                   0x00108036
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_RELATIVE_POWER                   0x00108037
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                        0x00108038
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                                0x00108039
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER                 0x0010803a
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_RELATIVE_POWER                 0x0010803b
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY                      0x0010803c
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_START_FREQUENCY                       0x00108031
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_STOP_FREQUENCY                        0x00108032
#define RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_POWER_REFERENCE_CARRIER               0x00108033
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS                    0x0010804a
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_TOTAL_ABSOLUTE_POWER                  0x00108041
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_TOTAL_RELATIVE_POWER                  0x00108042
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_ABSOLUTE_POWER                   0x00108043
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_RELATIVE_POWER                   0x00108044
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                        0x00108045
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                                0x00108046
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER                 0x00108047
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_RELATIVE_POWER                 0x00108048
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY                      0x00108049
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_START_FREQUENCY                       0x0010803e
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_STOP_FREQUENCY                        0x0010803f
#define RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_POWER_REFERENCE_CARRIER               0x00108040
#define RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_ENABLED                                   0x00109000
#define RFMXSPECAN_ATTR_SPECTRUM_SPAN                                                  0x00109003
#define RFMXSPECAN_ATTR_SPECTRUM_POWER_UNITS                                           0x00109015
#define RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_AUTO_BANDWIDTH                             0x0010900b
#define RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_BANDWIDTH                                  0x0010900c
#define RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_TYPE                                       0x0010900d
#define RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION                       0x00109016
#define RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH                             0x0010901a
#define RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_BANDWIDTH                                  0x0010901b
#define RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_VBW_TO_RBW_RATIO                           0x0010901c
#define RFMXSPECAN_ATTR_SPECTRUM_SWEEP_TIME_AUTO                                       0x0010900e
#define RFMXSPECAN_ATTR_SPECTRUM_SWEEP_TIME_INTERVAL                                   0x0010900f
#define RFMXSPECAN_ATTR_SPECTRUM_DETECTOR_TYPE                                         0x00109018
#define RFMXSPECAN_ATTR_SPECTRUM_DETECTOR_POINTS                                       0x00109019
#define RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_MODE                                0x00109022
#define RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO                      0x00109021
#define RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_AVERAGING_COUNT                     0x00109020
#define RFMXSPECAN_ATTR_SPECTRUM_NOISE_COMPENSATION_ENABLED                            0x00109010
#define RFMXSPECAN_ATTR_SPECTRUM_NOISE_COMPENSATION_TYPE                               0x0010901f
#define RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_ENABLED                                     0x00109006
#define RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_COUNT                                       0x00109005
#define RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_TYPE                                        0x00109008
#define RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_MODE                                      0x0010901e
#define RFMXSPECAN_ATTR_SPECTRUM_FFT_WINDOW                                            0x00109009
#define RFMXSPECAN_ATTR_SPECTRUM_FFT_PADDING                                           0x0010900a
#define RFMXSPECAN_ATTR_SPECTRUM_FFT_OVERLAP_MODE                                      0x00109024
#define RFMXSPECAN_ATTR_SPECTRUM_FFT_OVERLAP                                           0x00109025
#define RFMXSPECAN_ATTR_SPECTRUM_FFT_OVERLAP_TYPE                                      0x00109026
#define RFMXSPECAN_ATTR_SPECTRUM_AMPLITUDE_CORRECTION_TYPE                             0x00109017
#define RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_METHOD                                    0x00109027
#define RFMXSPECAN_ATTR_SPECTRUM_SEQUENTIAL_FFT_SIZE                                   0x00109028
#define RFMXSPECAN_ATTR_SPECTRUM_ANALYSIS_INPUT                                        0x00109023
#define RFMXSPECAN_ATTR_SPECTRUM_NUMBER_OF_ANALYSIS_THREADS                            0x00109002
#define RFMXSPECAN_ATTR_SPECTRUM_RESULTS_PEAK_AMPLITUDE                                0x00109012
#define RFMXSPECAN_ATTR_SPECTRUM_RESULTS_PEAK_FREQUENCY                                0x00109013
#define RFMXSPECAN_ATTR_SPECTRUM_RESULTS_FREQUENCY_RESOLUTION                          0x00109014
#define RFMXSPECAN_ATTR_SPUR_MEASUREMENT_ENABLED                                       0x0010a000
#define RFMXSPECAN_ATTR_SPUR_NUMBER_OF_RANGES                                          0x0010a004
#define RFMXSPECAN_ATTR_SPUR_RANGE_ENABLED                                             0x0010a005
#define RFMXSPECAN_ATTR_SPUR_RANGE_START_FREQUENCY                                     0x0010a008
#define RFMXSPECAN_ATTR_SPUR_RANGE_STOP_FREQUENCY                                      0x0010a009
#define RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_AUTO_BANDWIDTH                           0x0010a013
#define RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_BANDWIDTH                                0x0010a014
#define RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_TYPE                                     0x0010a015
#define RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_BANDWIDTH_DEFINITION                     0x0010a023
#define RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH                           0x0010a027
#define RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_BANDWIDTH                                0x0010a028
#define RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_VBW_TO_RBW_RATIO                         0x0010a029
#define RFMXSPECAN_ATTR_SPUR_RANGE_SWEEP_TIME_AUTO                                     0x0010a016
#define RFMXSPECAN_ATTR_SPUR_RANGE_SWEEP_TIME_INTERVAL                                 0x0010a017
#define RFMXSPECAN_ATTR_SPUR_RANGE_DETECTOR_TYPE                                       0x0010a025
#define RFMXSPECAN_ATTR_SPUR_RANGE_DETECTOR_POINTS                                     0x0010a026
#define RFMXSPECAN_ATTR_SPUR_RANGE_ABSOLUTE_LIMIT_MODE                                 0x0010a010
#define RFMXSPECAN_ATTR_SPUR_RANGE_ABSOLUTE_LIMIT_START                                0x0010a011
#define RFMXSPECAN_ATTR_SPUR_RANGE_ABSOLUTE_LIMIT_STOP                                 0x0010a012
#define RFMXSPECAN_ATTR_SPUR_RANGE_RELATIVE_ATTENUATION                                0x0010a006
#define RFMXSPECAN_ATTR_SPUR_RANGE_PEAK_THRESHOLD                                      0x0010a021
#define RFMXSPECAN_ATTR_SPUR_RANGE_PEAK_EXCURSION                                      0x0010a022
#define RFMXSPECAN_ATTR_SPUR_RANGE_NUMBER_OF_SPURS_TO_REPORT                           0x0010a007
#define RFMXSPECAN_ATTR_SPUR_AVERAGING_ENABLED                                         0x0010a00b
#define RFMXSPECAN_ATTR_SPUR_AVERAGING_COUNT                                           0x0010a00a
#define RFMXSPECAN_ATTR_SPUR_AVERAGING_TYPE                                            0x0010a00d
#define RFMXSPECAN_ATTR_SPUR_FFT_WINDOW                                                0x0010a00f
#define RFMXSPECAN_ATTR_SPUR_TRACE_RANGE_INDEX                                         0x0010a020
#define RFMXSPECAN_ATTR_SPUR_AMPLITUDE_CORRECTION_TYPE                                 0x0010a024
#define RFMXSPECAN_ATTR_SPUR_ALL_TRACES_ENABLED                                        0x0010a018
#define RFMXSPECAN_ATTR_SPUR_NUMBER_OF_ANALYSIS_THREADS                                0x0010a003
#define RFMXSPECAN_ATTR_SPUR_RESULTS_MEASUREMENT_STATUS                                0x0010a019
#define RFMXSPECAN_ATTR_SPUR_RESULTS_RANGE_MEASUREMENT_STATUS                          0x0010a01e
#define RFMXSPECAN_ATTR_SPUR_RESULTS_RANGE_NUMBER_OF_DETECTED_SPURS                    0x0010a01f
#define RFMXSPECAN_ATTR_SPUR_RESULTS_RANGE_FREQUENCY                                   0x0010a01a
#define RFMXSPECAN_ATTR_SPUR_RESULTS_RANGE_MARGIN                                      0x0010a01d
#define RFMXSPECAN_ATTR_SPUR_RESULTS_RANGE_AMPLITUDE                                   0x0010a01b
#define RFMXSPECAN_ATTR_SPUR_RESULTS_RANGE_ABSOLUTE_LIMIT                              0x0010a01c
#define RFMXSPECAN_ATTR_TXP_MEASUREMENT_ENABLED                                        0x0010b000
#define RFMXSPECAN_ATTR_TXP_MEASUREMENT_INTERVAL                                       0x0010b002
#define RFMXSPECAN_ATTR_TXP_RBW_FILTER_BANDWIDTH                                       0x0010b00a
#define RFMXSPECAN_ATTR_TXP_RBW_FILTER_TYPE                                            0x0010b00b
#define RFMXSPECAN_ATTR_TXP_RBW_FILTER_ALPHA                                           0x0010b009
#define RFMXSPECAN_ATTR_TXP_VBW_FILTER_AUTO_BANDWIDTH                                  0x0010b017
#define RFMXSPECAN_ATTR_TXP_VBW_FILTER_BANDWIDTH                                       0x0010b018
#define RFMXSPECAN_ATTR_TXP_VBW_FILTER_VBW_TO_RBW_RATIO                                0x0010b019
#define RFMXSPECAN_ATTR_TXP_THRESHOLD_ENABLED                                          0x0010b00c
#define RFMXSPECAN_ATTR_TXP_THRESHOLD_TYPE                                             0x0010b00e
#define RFMXSPECAN_ATTR_TXP_THRESHOLD_LEVEL                                            0x0010b00d
#define RFMXSPECAN_ATTR_TXP_AVERAGING_ENABLED                                          0x0010b006
#define RFMXSPECAN_ATTR_TXP_AVERAGING_COUNT                                            0x0010b005
#define RFMXSPECAN_ATTR_TXP_AVERAGING_TYPE                                             0x0010b008
#define RFMXSPECAN_ATTR_TXP_ALL_TRACES_ENABLED                                         0x0010b010
#define RFMXSPECAN_ATTR_TXP_NUMBER_OF_ANALYSIS_THREADS                                 0x0010b003
#define RFMXSPECAN_ATTR_TXP_RESULTS_AVERAGE_MEAN_POWER                                 0x0010b011
#define RFMXSPECAN_ATTR_TXP_RESULTS_PEAK_TO_AVERAGE_RATIO                              0x0010b012
#define RFMXSPECAN_ATTR_TXP_RESULTS_MAXIMUM_POWER                                      0x0010b013
#define RFMXSPECAN_ATTR_TXP_RESULTS_MINIMUM_POWER                                      0x0010b014
#define RFMXSPECAN_ATTR_AMPM_MEASUREMENT_ENABLED                                       0x0010e000
#define RFMXSPECAN_ATTR_AMPM_MEASUREMENT_SAMPLE_RATE_MODE                              0x0010e00b
#define RFMXSPECAN_ATTR_AMPM_MEASUREMENT_SAMPLE_RATE                                   0x0010e00c
#define RFMXSPECAN_ATTR_AMPM_MEASUREMENT_INTERVAL                                      0x0010e009
#define RFMXSPECAN_ATTR_AMPM_SIGNAL_TYPE                                               0x0010e00a
#define RFMXSPECAN_ATTR_AMPM_SYNCHRONIZATION_METHOD                                    0x0010e02a
#define RFMXSPECAN_ATTR_AMPM_AUTO_CARRIER_DETECTION_ENABLED                            0x0010e02b
#define RFMXSPECAN_ATTR_AMPM_NUMBER_OF_CARRIERS                                        0x0010e02c
#define RFMXSPECAN_ATTR_AMPM_CARRIER_OFFSET                                            0x0010e02d
#define RFMXSPECAN_ATTR_AMPM_CARRIER_BANDWIDTH                                         0x0010e02e
#define RFMXSPECAN_ATTR_AMPM_DUT_AVERAGE_INPUT_POWER                                   0x0010e010
#define RFMXSPECAN_ATTR_AMPM_AM_TO_AM_CURVE_FIT_ORDER                                  0x0010e002
#define RFMXSPECAN_ATTR_AMPM_AM_TO_AM_CURVE_FIT_TYPE                                   0x0010e003
#define RFMXSPECAN_ATTR_AMPM_AM_TO_PM_CURVE_FIT_ORDER                                  0x0010e004
#define RFMXSPECAN_ATTR_AMPM_AM_TO_PM_CURVE_FIT_TYPE                                   0x0010e005
#define RFMXSPECAN_ATTR_AMPM_THRESHOLD_ENABLED                                         0x0010e00d
#define RFMXSPECAN_ATTR_AMPM_THRESHOLD_TYPE                                            0x0010e00e
#define RFMXSPECAN_ATTR_AMPM_THRESHOLD_LEVEL                                           0x0010e00f
#define RFMXSPECAN_ATTR_AMPM_THRESHOLD_DEFINITION                                      0x0010e03c
#define RFMXSPECAN_ATTR_AMPM_FREQUENCY_OFFSET_CORRECTION_ENABLED                       0x0010e021
#define RFMXSPECAN_ATTR_AMPM_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED                       0x0010e029
#define RFMXSPECAN_ATTR_AMPM_AM_TO_AM_ENABLED                                          0x0010e031
#define RFMXSPECAN_ATTR_AMPM_AM_TO_PM_ENABLED                                          0x0010e032
#define RFMXSPECAN_ATTR_AMPM_EVM_ENABLED                                               0x0010e033
#define RFMXSPECAN_ATTR_AMPM_EQUALIZER_MODE                                            0x0010e02f
#define RFMXSPECAN_ATTR_AMPM_EQUALIZER_FILTER_LENGTH                                   0x0010e030
#define RFMXSPECAN_ATTR_AMPM_AVERAGING_ENABLED                                         0x0010e006
#define RFMXSPECAN_ATTR_AMPM_AVERAGING_COUNT                                           0x0010e007
#define RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_ENABLED                                 0x0010e024
#define RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_LEVEL                                   0x0010e025
#define RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_GAIN_REFERENCE                          0x0010e034
#define RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_POWER                    0x0010e035
#define RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_USER_GAIN                               0x0010e036
#define RFMXSPECAN_ATTR_AMPM_MAXIMUM_TIMING_ERROR                                      0x0010e022
#define RFMXSPECAN_ATTR_AMPM_REFERENCE_POWER_TYPE                                      0x0010e023
#define RFMXSPECAN_ATTR_AMPM_ALL_TRACES_ENABLED                                        0x0010e011
#define RFMXSPECAN_ATTR_AMPM_NUMBER_OF_ANALYSIS_THREADS                                0x0010e012
#define RFMXSPECAN_ATTR_AMPM_RESULTS_MEAN_LINEAR_GAIN                                  0x0010e016
#define RFMXSPECAN_ATTR_AMPM_RESULTS_1_DB_COMPRESSION_POINT                            0x0010e01d
#define RFMXSPECAN_ATTR_AMPM_RESULTS_INPUT_COMPRESSION_POINT                           0x0010e026
#define RFMXSPECAN_ATTR_AMPM_RESULTS_OUTPUT_COMPRESSION_POINT                          0x0010e027
#define RFMXSPECAN_ATTR_AMPM_RESULTS_COMPRESSION_POINT_GAIN_REFERENCE                  0x0010e037
#define RFMXSPECAN_ATTR_AMPM_RESULTS_PEAK_REFERENCE_POWER                              0x0010e038
#define RFMXSPECAN_ATTR_AMPM_RESULTS_PEAK_REFERENCE_POWER_GAIN                         0x0010e039
#define RFMXSPECAN_ATTR_AMPM_RESULTS_MEAN_RMS_EVM                                      0x0010e018
#define RFMXSPECAN_ATTR_AMPM_RESULTS_GAIN_ERROR_RANGE                                  0x0010e01b
#define RFMXSPECAN_ATTR_AMPM_RESULTS_PHASE_ERROR_RANGE                                 0x0010e01c
#define RFMXSPECAN_ATTR_AMPM_RESULTS_MEAN_PHASE_ERROR                                  0x0010e017
#define RFMXSPECAN_ATTR_AMPM_RESULTS_AM_TO_AM_CURVE_FIT_RESIDUAL                       0x0010e019
#define RFMXSPECAN_ATTR_AMPM_RESULTS_AM_TO_PM_CURVE_FIT_RESIDUAL                       0x0010e01a
#define RFMXSPECAN_ATTR_AMPM_RESULTS_AM_TO_AM_CURVE_FIT_COEFFICIENTS                   0x0010e014
#define RFMXSPECAN_ATTR_AMPM_RESULTS_AM_TO_PM_CURVE_FIT_COEFFICIENTS                   0x0010e015
#define RFMXSPECAN_ATTR_DPD_MEASUREMENT_ENABLED                                        0x0010f000
#define RFMXSPECAN_ATTR_DPD_MEASUREMENT_SAMPLE_RATE_MODE                               0x0010f002
#define RFMXSPECAN_ATTR_DPD_MEASUREMENT_SAMPLE_RATE                                    0x0010f003
#define RFMXSPECAN_ATTR_DPD_MEASUREMENT_INTERVAL                                       0x0010f004
#define RFMXSPECAN_ATTR_DPD_SIGNAL_TYPE                                                0x0010f005
#define RFMXSPECAN_ATTR_DPD_SYNCHRONIZATION_METHOD                                     0x0010f04a
#define RFMXSPECAN_ATTR_DPD_AUTO_CARRIER_DETECTION_ENABLED                             0x0010f04b
#define RFMXSPECAN_ATTR_DPD_NUMBER_OF_CARRIERS                                         0x0010f04c
#define RFMXSPECAN_ATTR_DPD_CARRIER_OFFSET                                             0x0010f04d
#define RFMXSPECAN_ATTR_DPD_CARRIER_BANDWIDTH                                          0x0010f04e
#define RFMXSPECAN_ATTR_DPD_DUT_AVERAGE_INPUT_POWER                                    0x0010f007
#define RFMXSPECAN_ATTR_DPD_MODEL                                                      0x0010f008
#define RFMXSPECAN_ATTR_DPD_TARGET_GAIN_TYPE                                           0x0010f037
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_TYPE                                          0x0010f038
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_ORDER                      0x0010f009
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_TYPE                       0x0010f00a
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_ORDER                      0x0010f00b
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_TYPE                       0x0010f00c
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_ENABLED                             0x0010f00d
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_TYPE                                0x0010f00e
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_LEVEL                               0x0010f00f
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_DEFINITION                          0x0010f06d
#define RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_STEP_SIZE                                     0x0010f010
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_ORDER                                    0x0010f011
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_MEMORY_DEPTH                             0x0010f012
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_ORDER_TYPE                               0x0010f04f
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LEAD_ORDER                               0x0010f013
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LAG_ORDER                                0x0010f014
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LEAD_MEMORY_DEPTH                        0x0010f015
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LAG_MEMORY_DEPTH                         0x0010f016
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_MAXIMUM_LEAD                             0x0010f017
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_MAXIMUM_LAG                              0x0010f018
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LEAD_ORDER_TYPE                          0x0010f050
#define RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LAG_ORDER_TYPE                           0x0010f051
#define RFMXSPECAN_ATTR_DPD_DVR_NUMBER_OF_SEGMENTS                                     0x0010f067
#define RFMXSPECAN_ATTR_DPD_DVR_LINEAR_MEMORY_DEPTH                                    0x0010f068
#define RFMXSPECAN_ATTR_DPD_DVR_NONLINEAR_MEMORY_DEPTH                                 0x0010f069
#define RFMXSPECAN_ATTR_DPD_DVR_DDR_ENABLED                                            0x0010f06a
#define RFMXSPECAN_ATTR_DPD_MEASUREMENT_MODE                                           0x0010f06b
#define RFMXSPECAN_ATTR_DPD_ITERATIVE_DPD_ENABLED                                      0x0010f01a
#define RFMXSPECAN_ATTR_DPD_FREQUENCY_OFFSET_CORRECTION_ENABLED                        0x0010f039
#define RFMXSPECAN_ATTR_DPD_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED                        0x0010f065
#define RFMXSPECAN_ATTR_DPD_AVERAGING_ENABLED                                          0x0010f01c
#define RFMXSPECAN_ATTR_DPD_AVERAGING_COUNT                                            0x0010f01d
#define RFMXSPECAN_ATTR_DPD_MAXIMUM_TIMING_ERROR                                       0x0010f03a
#define RFMXSPECAN_ATTR_DPD_NMSE_ENABLED                                               0x0010f03b
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED                                        0x0010f03c
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_METHOD                                         0x0010f03e
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_MAXIMUM_ITERATIONS                             0x0010f03d
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_TARGET_PAPR                                    0x0010f041
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_WINDOW_TYPE                                    0x0010f042
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_WINDOW_LENGTH                                  0x0010f043
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_SHAPING_FACTOR                                 0x0010f044
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_SHAPING_THRESHOLD                              0x0010f045
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_FILTER_ENABLED                                 0x0010f060
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_NUMBER_OF_CARRIERS                             0x0010f062
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CARRIER_OFFSET                                     0x0010f063
#define RFMXSPECAN_ATTR_DPD_PRE_DPD_CARRIER_BANDWIDTH                                  0x0010f064
#define RFMXSPECAN_ATTR_DPD_ALL_TRACES_ENABLED                                         0x0010f01f
#define RFMXSPECAN_ATTR_DPD_NUMBER_OF_ANALYSIS_THREADS                                 0x0010f020
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT                              0x0010f021
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE                     0x0010f022
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_MEMORY_MODEL_CORRECTION_TYPE                     0x0010f036
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED                                      0x0010f046
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_METHOD                                       0x0010f047
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_MAXIMUM_ITERATIONS                           0x0010f048
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE                             0x0010f049
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_TARGET_PAPR                                  0x0010f05a
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_WINDOW_TYPE                                  0x0010f05b
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_WINDOW_LENGTH                                0x0010f05c
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_SHAPING_FACTOR                               0x0010f05d
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_SHAPING_THRESHOLD                            0x0010f05e
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DUT_AVERAGE_INPUT_POWER                     0x0010f025
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL                                   0x0010f026
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEASUREMENT_SAMPLE_RATE                     0x0010f027
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_LOOKUP_TABLE_TYPE                           0x0010f040
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_LOOKUP_TABLE_INPUT_POWER                    0x0010e028
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_ORDER                     0x0010f02a
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_MEMORY_DEPTH              0x0010f02b
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LEAD_ORDER                0x0010f02c
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LAG_ORDER                 0x0010f02d
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LEAD_MEMORY_DEPTH         0x0010f02e
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_LAG_MEMORY_DEPTH          0x0010f02f
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_MAXIMUM_LEAD              0x0010f030
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_MEMORY_POLYNOMIAL_MAXIMUM_LAG               0x0010f031
#define RFMXSPECAN_ATTR_DPD_RESULTS_AVERAGE_GAIN                                       0x0010f033
#define RFMXSPECAN_ATTR_DPD_RESULTS_NMSE                                               0x0010f05f
#define RFMXSPECAN_ATTR_IDPD_MEASUREMENT_ENABLED                                       0x00140000
#define RFMXSPECAN_ATTR_IDPD_EQUALIZER_MODE                                            0x00140002
#define RFMXSPECAN_ATTR_IDPD_EQUALIZER_FILTER_LENGTH                                   0x00140003
#define RFMXSPECAN_ATTR_IDPD_MEASUREMENT_SAMPLE_RATE_MODE                              0x00140004
#define RFMXSPECAN_ATTR_IDPD_MEASUREMENT_SAMPLE_RATE                                   0x00140005
#define RFMXSPECAN_ATTR_IDPD_SIGNAL_TYPE                                               0x00140006
#define RFMXSPECAN_ATTR_IDPD_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT                  0x0014000b
#define RFMXSPECAN_ATTR_IDPD_DUT_AVERAGE_INPUT_POWER                                   0x0014000c
#define RFMXSPECAN_ATTR_IDPD_AVERAGING_ENABLED                                         0x0014000f
#define RFMXSPECAN_ATTR_IDPD_AVERAGING_COUNT                                           0x00140010
#define RFMXSPECAN_ATTR_IDPD_EVM_ENABLED                                               0x00140013
#define RFMXSPECAN_ATTR_IDPD_EVM_UNIT                                                  0x00140014
#define RFMXSPECAN_ATTR_IDPD_IMPAIRMENT_ESTIMATION_START                               0x00140015
#define RFMXSPECAN_ATTR_IDPD_IMPAIRMENT_ESTIMATION_STOP                                0x00140016
#define RFMXSPECAN_ATTR_IDPD_SYNCHRONIZATION_ESTIMATION_START                          0x00140017
#define RFMXSPECAN_ATTR_IDPD_SYNCHRONIZATION_ESTIMATION_STOP                           0x00140018
#define RFMXSPECAN_ATTR_IDPD_GAIN_EXPANSION                                            0x00140019
#define RFMXSPECAN_ATTR_IDPD_TARGET_GAIN                                               0x00140027
#define RFMXSPECAN_ATTR_IDPD_POWER_LINEARITY_TRADEOFF                                  0x0014001b
#define RFMXSPECAN_ATTR_IDPD_RESULTS_GAIN                                              0x0014001d
#define RFMXSPECAN_ATTR_IDPD_RESULTS_MEAN_RMS_EVM                                      0x0014001e
#define RFMXSPECAN_ATTR_IDPD_ALL_TRACES_ENABLED                                        0x0014001f
#define RFMXSPECAN_ATTR_IDPD_NUMBER_OF_ANALYSIS_THREADS                                0x00140021
#define RFMXSPECAN_ATTR_IQ_MEASUREMENT_ENABLED                                         0x0010f100
#define RFMXSPECAN_ATTR_IQ_MEASUREMENT_MODE                                            0x0010f10c
#define RFMXSPECAN_ATTR_IQ_SAMPLE_RATE                                                 0x0010f102
#define RFMXSPECAN_ATTR_IQ_ACQUISITION_TIME                                            0x0010f104
#define RFMXSPECAN_ATTR_IQ_PRETRIGGER_TIME                                             0x0010f105
#define RFMXSPECAN_ATTR_IQ_BANDWIDTH_AUTO                                              0x0010f108
#define RFMXSPECAN_ATTR_IQ_BANDWIDTH                                                   0x0010f109
#define RFMXSPECAN_ATTR_IQ_NUMBER_OF_RECORDS                                           0x0010f103
#define RFMXSPECAN_ATTR_IQ_DELETE_RECORD_ON_FETCH                                      0x0010f10a
#define RFMXSPECAN_ATTR_IM_MEASUREMENT_ENABLED                                         0x00110000
#define RFMXSPECAN_ATTR_IM_FREQUENCY_DEFINITION                                        0x00110002
#define RFMXSPECAN_ATTR_IM_FUNDAMENTAL_LOWER_TONE_FREQUENCY                            0x00110003
#define RFMXSPECAN_ATTR_IM_FUNDAMENTAL_UPPER_TONE_FREQUENCY                            0x00110004
#define RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED                                0x00110005
#define RFMXSPECAN_ATTR_IM_MAXIMUM_INTERMOD_ORDER                                      0x00110006
#define RFMXSPECAN_ATTR_IM_NUMBER_OF_INTERMODS                                         0x00110007
#define RFMXSPECAN_ATTR_IM_INTERMOD_ENABLED                                            0x00110008
#define RFMXSPECAN_ATTR_IM_INTERMOD_ORDER                                              0x00110009
#define RFMXSPECAN_ATTR_IM_INTERMOD_SIDE                                               0x0011000a
#define RFMXSPECAN_ATTR_IM_LOWER_INTERMOD_FREQUENCY                                    0x0011000b
#define RFMXSPECAN_ATTR_IM_UPPER_INTERMOD_FREQUENCY                                    0x0011000c
#define RFMXSPECAN_ATTR_IM_MEASUREMENT_METHOD                                          0x0011000d
#define RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED                                   0x0011002a
#define RFMXSPECAN_ATTR_IM_RBW_FILTER_AUTO_BANDWIDTH                                   0x0011000e
#define RFMXSPECAN_ATTR_IM_RBW_FILTER_BANDWIDTH                                        0x0011000f
#define RFMXSPECAN_ATTR_IM_RBW_FILTER_TYPE                                             0x00110010
#define RFMXSPECAN_ATTR_IM_SWEEP_TIME_AUTO                                             0x00110011
#define RFMXSPECAN_ATTR_IM_SWEEP_TIME_INTERVAL                                         0x00110012
#define RFMXSPECAN_ATTR_IM_AVERAGING_ENABLED                                           0x00110013
#define RFMXSPECAN_ATTR_IM_AVERAGING_COUNT                                             0x00110014
#define RFMXSPECAN_ATTR_IM_AVERAGING_TYPE                                              0x00110016
#define RFMXSPECAN_ATTR_IM_FFT_WINDOW                                                  0x00110017
#define RFMXSPECAN_ATTR_IM_FFT_PADDING                                                 0x00110018
#define RFMXSPECAN_ATTR_IM_IF_OUTPUT_POWER_OFFSET_AUTO                                 0x00110019
#define RFMXSPECAN_ATTR_IM_NEAR_IF_OUTPUT_POWER_OFFSET                                 0x0011001a
#define RFMXSPECAN_ATTR_IM_FAR_IF_OUTPUT_POWER_OFFSET                                  0x0011001b
#define RFMXSPECAN_ATTR_IM_AMPLITUDE_CORRECTION_TYPE                                   0x0011002b
#define RFMXSPECAN_ATTR_IM_ALL_TRACES_ENABLED                                          0x0011001c
#define RFMXSPECAN_ATTR_IM_NUMBER_OF_ANALYSIS_THREADS                                  0x0011001d
#define RFMXSPECAN_ATTR_IM_RESULTS_LOWER_TONE_POWER                                    0x0011001f
#define RFMXSPECAN_ATTR_IM_RESULTS_UPPER_TONE_POWER                                    0x00110021
#define RFMXSPECAN_ATTR_IM_RESULTS_INTERMOD_ORDER                                      0x00110022
#define RFMXSPECAN_ATTR_IM_RESULTS_LOWER_INTERMOD_POWER                                0x00110024
#define RFMXSPECAN_ATTR_IM_RESULTS_UPPER_INTERMOD_POWER                                0x00110026
#define RFMXSPECAN_ATTR_IM_RESULTS_WORST_CASE_INTERMOD_ABSOLUTE_POWER                  0x00110032
#define RFMXSPECAN_ATTR_IM_RESULTS_LOWER_INTERMOD_RELATIVE_POWER                       0x00110030
#define RFMXSPECAN_ATTR_IM_RESULTS_UPPER_INTERMOD_RELATIVE_POWER                       0x00110031
#define RFMXSPECAN_ATTR_IM_RESULTS_WORST_CASE_INTERMOD_RELATIVE_POWER                  0x00110033
#define RFMXSPECAN_ATTR_IM_RESULTS_LOWER_OUTPUT_INTERCEPT_POWER                        0x00110027
#define RFMXSPECAN_ATTR_IM_RESULTS_UPPER_OUTPUT_INTERCEPT_POWER                        0x00110028
#define RFMXSPECAN_ATTR_IM_RESULTS_WORST_CASE_OUTPUT_INTERCEPT_POWER                   0x00110029
#define RFMXSPECAN_ATTR_NF_MEASUREMENT_ENABLED                                         0x00120001
#define RFMXSPECAN_ATTR_NF_DUT_TYPE                                                    0x0012003a
#define RFMXSPECAN_ATTR_NF_FREQUENCY_CONVERTER_LO_FREQUENCY                            0x0012003c
#define RFMXSPECAN_ATTR_NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT                       0x0012003e
#define RFMXSPECAN_ATTR_NF_FREQUENCY_CONVERTER_SIDEBAND                                0x0012003f
#define RFMXSPECAN_ATTR_NF_FREQUENCY_CONVERTER_IMAGE_REJECTION                         0x00120040
#define RFMXSPECAN_ATTR_NF_FREQUENCY_LIST                                              0x00120004
#define RFMXSPECAN_ATTR_NF_MEASUREMENT_BANDWIDTH                                       0x00120005
#define RFMXSPECAN_ATTR_NF_MEASUREMENT_INTERVAL                                        0x00120006
#define RFMXSPECAN_ATTR_NF_AVERAGING_ENABLED                                           0x00120007
#define RFMXSPECAN_ATTR_NF_AVERAGING_COUNT                                             0x00120008
#define RFMXSPECAN_ATTR_NF_CALIBRATION_SETUP_ID                                        0x00120034
#define RFMXSPECAN_ATTR_NF_EXTERNAL_PREAMP_PRESENT                                     0x00120035
#define RFMXSPECAN_ATTR_NF_EXTERNAL_PREAMP_FREQUENCY                                   0x00120036
#define RFMXSPECAN_ATTR_NF_EXTERNAL_PREAMP_GAIN                                        0x00120037
#define RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED                         0x00120011
#define RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS_FREQUENCY                                    0x00120013
#define RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS                                              0x00120012
#define RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS_TEMPERATURE                                  0x00120014
#define RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED                        0x00120015
#define RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS_FREQUENCY                                   0x00120017
#define RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS                                             0x00120016
#define RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS_TEMPERATURE                                 0x00120018
#define RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS_COMPENSATION_ENABLED                       0x0012001d
#define RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS_FREQUENCY                                  0x0012001f
#define RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS                                            0x0012001e
#define RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS_TEMPERATURE                                0x00120020
#define RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD                                          0x00120009
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_MODE                                               0x0012000a
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_TYPE                                  0x00120041
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_RF_SIGNAL_GENERATOR_PORT              0x00120042
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_ENR_FREQUENCY                         0x0012000d
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_ENR                                   0x0012000c
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_COLD_TEMPERATURE                      0x0012000e
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_OFF_TEMPERATURE                       0x0012000f
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_SETTLING_TIME                         0x00120010
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED             0x00120019
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS_FREQUENCY                        0x0012001b
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS                                  0x0012001a
#define RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS_TEMPERATURE                      0x0012001c
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_MODE                                            0x0012002b
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_INPUT_TERMINATION_VSWR                          0x0012002c
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_INPUT_TERMINATION_VSWR_FREQUENCY                0x0012002d
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_INPUT_TERMINATION_TEMPERATURE                   0x0012002e
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S_PARAMETERS_FREQUENCY                      0x00120033
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S21                                         0x0012002f
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S12                                         0x00120030
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S11                                         0x00120031
#define RFMXSPECAN_ATTR_NF_COLD_SOURCE_DUT_S22                                         0x00120032
#define RFMXSPECAN_ATTR_NF_DEVICE_TEMPERATURE_TOLERANCE                                0x00120039
#define RFMXSPECAN_ATTR_NF_NUMBER_OF_ANALYSIS_THREADS                                  0x00120021
#define RFMXSPECAN_ATTR_NF_RESULTS_DUT_NOISE_FIGURE                                    0x00120022
#define RFMXSPECAN_ATTR_NF_RESULTS_DUT_NOISE_TEMPERATURE                               0x00120023
#define RFMXSPECAN_ATTR_NF_RESULTS_DUT_GAIN                                            0x00120024
#define RFMXSPECAN_ATTR_NF_RESULTS_ANALYZER_NOISE_FIGURE                               0x00120025
#define RFMXSPECAN_ATTR_NF_RESULTS_MEASUREMENT_Y_FACTOR                                0x00120026
#define RFMXSPECAN_ATTR_NF_RESULTS_CALIBRATION_Y_FACTOR                                0x00120027
#define RFMXSPECAN_ATTR_NF_RESULTS_Y_FACTOR_HOT_POWER                                  0x00120028
#define RFMXSPECAN_ATTR_NF_RESULTS_Y_FACTOR_COLD_POWER                                 0x00120029
#define RFMXSPECAN_ATTR_NF_RESULTS_COLD_SOURCE_POWER                                   0x0012002a
#define RFMXSPECAN_ATTR_PHASENOISE_MEASUREMENT_ENABLED                                 0x00130000
#define RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION                                    0x00130002
#define RFMXSPECAN_ATTR_PHASENOISE_START_FREQUENCY                                     0x00130003
#define RFMXSPECAN_ATTR_PHASENOISE_STOP_FREQUENCY                                      0x00130004
#define RFMXSPECAN_ATTR_PHASENOISE_RBW_PERCENTAGE                                      0x00130005
#define RFMXSPECAN_ATTR_PHASENOISE_NUMBER_OF_RANGES                                    0x00130008
#define RFMXSPECAN_ATTR_PHASENOISE_RANGE_START_FREQUENCY                               0x00130009
#define RFMXSPECAN_ATTR_PHASENOISE_RANGE_STOP_FREQUENCY                                0x0013000a
#define RFMXSPECAN_ATTR_PHASENOISE_RANGE_RBW_PERCENTAGE                                0x0013000b
#define RFMXSPECAN_ATTR_PHASENOISE_RANGE_AVERAGING_COUNT                               0x0013000c
#define RFMXSPECAN_ATTR_PHASENOISE_AVERAGING_MULTIPLIER                                0x00130006
#define RFMXSPECAN_ATTR_PHASENOISE_FFT_WINDOW                                          0x00130007
#define RFMXSPECAN_ATTR_PHASENOISE_SMOOTHING_TYPE                                      0x0013000d
#define RFMXSPECAN_ATTR_PHASENOISE_SMOOTHING_PERCENTAGE                                0x0013000e
#define RFMXSPECAN_ATTR_PHASENOISE_SPOT_NOISE_FREQUENCY_LIST                           0x0013000f
#define RFMXSPECAN_ATTR_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION                   0x00130010
#define RFMXSPECAN_ATTR_PHASENOISE_INTEGRATED_NOISE_START_FREQUENCY                    0x00130011
#define RFMXSPECAN_ATTR_PHASENOISE_INTEGRATED_NOISE_STOP_FREQUENCY                     0x00130012
#define RFMXSPECAN_ATTR_PHASENOISE_SPUR_REMOVAL_ENABLED                                0x0013001d
#define RFMXSPECAN_ATTR_PHASENOISE_SPUR_REMOVAL_PEAK_EXCURSION                         0x0013001e
#define RFMXSPECAN_ATTR_PHASENOISE_CANCELLATION_ENABLED                                0x0013001f
#define RFMXSPECAN_ATTR_PHASENOISE_CANCELLATION_THRESHOLD                              0x00130020
#define RFMXSPECAN_ATTR_PHASENOISE_CANCELLATION_FREQUENCY                              0x00130021
#define RFMXSPECAN_ATTR_PHASENOISE_CANCELLATION_REFERENCE_PHASE_NOISE                  0x00130022
#define RFMXSPECAN_ATTR_PHASENOISE_ALL_TRACES_ENABLED                                  0x00130013
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_CARRIER_POWER                               0x00130015
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_CARRIER_FREQUENCY                           0x00130016
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_SPOT_PHASE_NOISE                            0x00130017
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_INTEGRATED_PHASE_NOISE                      0x00130018
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_INTEGRATED_NOISE_RESIDUAL_PM_IN_RADIAN      0x00130019
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_INTEGRATED_NOISE_RESIDUAL_PM_IN_DEGREE      0x0013001a
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_INTEGRATED_NOISE_RESIDUAL_FM                0x0013001b
#define RFMXSPECAN_ATTR_PHASENOISE_RESULTS_INTEGRATED_NOISE_JITTER                     0x0013001c
#define RFMXSPECAN_ATTR_PAVT_MEASUREMENT_ENABLED                                       0x00107000
#define RFMXSPECAN_ATTR_PAVT_MEASUREMENT_LOCATION_TYPE                                 0x00107002
#define RFMXSPECAN_ATTR_PAVT_MEASUREMENT_BANDWIDTH                                     0x0010700d
#define RFMXSPECAN_ATTR_PAVT_MEASUREMENT_INTERVAL_MODE                                 0x00107015
#define RFMXSPECAN_ATTR_PAVT_NUMBER_OF_SEGMENTS                                        0x00107003
#define RFMXSPECAN_ATTR_PAVT_SEGMENT_TYPE                                              0x00107010
#define RFMXSPECAN_ATTR_PAVT_SEGMENT_START_TIME                                        0x00107004
#define RFMXSPECAN_ATTR_PAVT_MEASUREMENT_OFFSET                                        0x00107005
#define RFMXSPECAN_ATTR_PAVT_MEASUREMENT_LENGTH                                        0x00107006
#define RFMXSPECAN_ATTR_PAVT_SEGMENT_MEASUREMENT_OFFSET                                0x00107011
#define RFMXSPECAN_ATTR_PAVT_SEGMENT_MEASUREMENT_LENGTH                                0x00107012
#define RFMXSPECAN_ATTR_PAVT_PHASE_UNWRAP_ENABLED                                      0x00107013
#define RFMXSPECAN_ATTR_PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED                       0x0010700c
#define RFMXSPECAN_ATTR_PAVT_FREQUENCY_TRACKING_ENABLED                                0x00107016
#define RFMXSPECAN_ATTR_PAVT_ALL_TRACES_ENABLED                                        0x00107007
#define RFMXSPECAN_ATTR_PAVT_RESULTS_MEAN_RELATIVE_PHASE                               0x0010700a
#define RFMXSPECAN_ATTR_PAVT_RESULTS_MEAN_RELATIVE_AMPLITUDE                           0x0010700b
#define RFMXSPECAN_ATTR_PAVT_RESULTS_MEAN_ABSOLUTE_PHASE                               0x0010700f
#define RFMXSPECAN_ATTR_PAVT_RESULTS_MEAN_ABSOLUTE_AMPLITUDE                           0x0010700e
#define RFMXSPECAN_ATTR_PAVT_RESULTS_FREQUENCY_ERROR_MEAN                              0x00107014
#define RFMXSPECAN_ATTR_POWERLIST_MEASUREMENT_ENABLED                                  0x00150000
#define RFMXSPECAN_ATTR_POWERLIST_NUMBER_OF_SEGMENTS                                   0x00150002
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_LENGTH                                       0x00150003
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_FREQUENCY                                    0x00150004
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_REFERENCE_LEVEL                              0x00150005
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_MEASUREMENT_LENGTH                           0x00150006
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_MEASUREMENT_OFFSET                           0x00150007
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_RBW_FILTER_BANDWIDTH                         0x00150008
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_RBW_FILTER_TYPE                              0x00150009
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_RBW_FILTER_ALPHA                             0x0015000a
#define RFMXSPECAN_ATTR_POWERLIST_SEGMENT_TRIGGER_TYPE                                 0x0015000b
#define RFMXSPECAN_ATTR_POWERLIST_RESULTS_MEAN_ABSOLUTE_POWER                          0x0015000c
#define RFMXSPECAN_ATTR_POWERLIST_RESULTS_MAXIMUM_POWER                                0x0015000d
#define RFMXSPECAN_ATTR_POWERLIST_RESULTS_MINIMUM_POWER                                0x0015000e
#define RFMXSPECAN_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                             0x0010000d
#define RFMXSPECAN_ATTR_LIMITED_CONFIGURATION_CHANGE                                   0x0010000e
#define RFMXSPECAN_ATTR_SELECTED_PATH                                                  0x0010000f
#define RFMXSPECAN_ATTR_RESULT_FETCH_TIMEOUT                                           0x0010c000

// Values for RFMXSPECAN_ATTR_TRIGGER_TYPE
#define RFMXSPECAN_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXSPECAN_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXSPECAN_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXSPECAN_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXSPECAN_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXSPECAN_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXSPECAN_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXSPECAN_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXSPECAN_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXSPECAN_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXSPECAN_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXSPECAN_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXSPECAN_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXSPECAN_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXSPECAN_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXSPECAN_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXSPECAN_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXSPECAN_VAL_TIMER_EVENT_STR                                                                "TimerEvent"
#define RFMXSPECAN_VAL_PULSE_IN_STR                                                                   "PulseIn"
#define RFMXSPECAN_VAL_DIO_PFI0_STR                                                                   "DIO/PFI0"
#define RFMXSPECAN_VAL_DIO_PFI1_STR                                                                   "DIO/PFI1"
#define RFMXSPECAN_VAL_DIO_PFI2_STR                                                                   "DIO/PFI2"
#define RFMXSPECAN_VAL_DIO_PFI3_STR                                                                   "DIO/PFI3"
#define RFMXSPECAN_VAL_DIO_PFI4_STR                                                                   "DIO/PFI4"
#define RFMXSPECAN_VAL_DIO_PFI5_STR                                                                   "DIO/PFI5"
#define RFMXSPECAN_VAL_DIO_PFI6_STR                                                                   "DIO/PFI6"
#define RFMXSPECAN_VAL_DIO_PFI7_STR                                                                   "DIO/PFI7"

// Values for RFMXSPECAN_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXSPECAN_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXSPECAN_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXSPECAN_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXSPECAN_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXSPECAN_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXSPECAN_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXSPECAN_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXSPECAN_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXSPECAN_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXSPECAN_ATTR_ACP_CARRIER_MODE
#define RFMXSPECAN_VAL_ACP_CARRIER_MODE_PASSIVE                                                       0
#define RFMXSPECAN_VAL_ACP_CARRIER_MODE_ACTIVE                                                        1

// Values for RFMXSPECAN_ATTR_ACP_CARRIER_RRC_FILTER_ENABLED
#define RFMXSPECAN_VAL_ACP_CARRIER_RRC_FILTER_ENABLED_FALSE                                           0
#define RFMXSPECAN_VAL_ACP_CARRIER_RRC_FILTER_ENABLED_TRUE                                            1

// Values for RFMXSPECAN_ATTR_ACP_OFFSET_ENABLED
#define RFMXSPECAN_VAL_ACP_OFFSET_FREQUENCY_ENABLED_FALSE                                             0
#define RFMXSPECAN_VAL_ACP_OFFSET_FREQUENCY_ENABLED_TRUE                                              1

// Values for RFMXSPECAN_ATTR_ACP_OFFSET_SIDEBAND
#define RFMXSPECAN_VAL_ACP_OFFSET_SIDEBAND_NEGATIVE                                                   0
#define RFMXSPECAN_VAL_ACP_OFFSET_SIDEBAND_POSITIVE                                                   1
#define RFMXSPECAN_VAL_ACP_OFFSET_SIDEBAND_BOTH                                                       2

// Values for RFMXSPECAN_ATTR_ACP_OFFSET_POWER_REFERENCE_CARRIER
#define RFMXSPECAN_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_CLOSEST                                     0
#define RFMXSPECAN_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_HIGHEST                                     1
#define RFMXSPECAN_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_COMPOSITE                                   2
#define RFMXSPECAN_VAL_ACP_OFFSET_POWER_REFERENCE_CARRIER_SPECIFIC                                    3

// Values for RFMXSPECAN_ATTR_ACP_OFFSET_RRC_FILTER_ENABLED
#define RFMXSPECAN_VAL_ACP_OFFSET_RRC_FILTER_ENABLED_FALSE                                            0
#define RFMXSPECAN_VAL_ACP_OFFSET_RRC_FILTER_ENABLED_TRUE                                             1

// Values for RFMXSPECAN_ATTR_ACP_OFFSET_FREQUENCY_DEFINITION
#define RFMXSPECAN_VAL_ACP_CARRIER_CENTER_TO_OFFSET_CENTER                                            0
#define RFMXSPECAN_VAL_ACP_CARRIER_CENTER_TO_OFFSET_EDGE                                              1

// Values for RFMXSPECAN_ATTR_ACP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_ACP_RBW_AUTO_FALSE                                                             0
#define RFMXSPECAN_VAL_ACP_RBW_AUTO_TRUE                                                              1

// Values for RFMXSPECAN_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_ACP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXSPECAN_VAL_ACP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXSPECAN_VAL_ACP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXSPECAN_ATTR_ACP_RBW_FILTER_BANDWIDTH_DEFINITION
#define RFMXSPECAN_VAL_ACP_RBW_FILTER_BANDWIDTH_DEFINITION_3DB                                        0
#define RFMXSPECAN_VAL_ACP_RBW_FILTER_BANDWIDTH_DEFINITION_BIN_WIDTH                                  2

// Values for RFMXSPECAN_ATTR_ACP_SWEEP_TIME_AUTO
#define RFMXSPECAN_VAL_ACP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXSPECAN_VAL_ACP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXSPECAN_ATTR_ACP_DETECTOR_TYPE
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_NONE                                                         0
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_SAMPLE                                                       1
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_NORMAL                                                       2
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_PEAK                                                         3
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_NEGATIVE_PEAK                                                4
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_AVERAGE_RMS                                                  5
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_AVERAGE_VOLTAGE                                              6
#define RFMXSPECAN_VAL_ACP_DETECTOR_TYPE_AVERAGE_LOG                                                  7

// Values for RFMXSPECAN_ATTR_ACP_POWER_UNITS
#define RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM                                                            0
#define RFMXSPECAN_VAL_ACP_POWER_UNITS_DBM_PER_HZ                                                     1

// Values for RFMXSPECAN_ATTR_ACP_MEASUREMENT_METHOD
#define RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_NORMAL                                                  0
#define RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_DYNAMIC_RANGE                                           1
#define RFMXSPECAN_VAL_ACP_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                          2

// Values for RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_MODE
#define RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_MODE_MANUAL                                              0
#define RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_MODE_AUTO                                                1

// Values for RFMXSPECAN_ATTR_ACP_NOISE_CALIBRATION_AVERAGING_AUTO
#define RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE                                     0
#define RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE                                      1

// Values for RFMXSPECAN_ATTR_ACP_NOISE_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXSPECAN_ATTR_ACP_NOISE_COMPENSATION_TYPE
#define RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION                           0
#define RFMXSPECAN_VAL_ACP_NOISE_COMPENSATION_TYPE_ANALYZER_ONLY                                      1

// Values for RFMXSPECAN_ATTR_ACP_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_ACP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_ACP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_ACP_AVERAGING_TYPE
#define RFMXSPECAN_VAL_ACP_AVERAGING_TYPE_RMS                                                         0
#define RFMXSPECAN_VAL_ACP_AVERAGING_TYPE_LOG                                                         1
#define RFMXSPECAN_VAL_ACP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXSPECAN_VAL_ACP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXSPECAN_VAL_ACP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXSPECAN_ATTR_ACP_MEASUREMENT_MODE
#define RFMXSPECAN_VAL_ACP_MEASUREMENT_MODE_MEASURE                                                   0
#define RFMXSPECAN_VAL_ACP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                     1

// Values for RFMXSPECAN_ATTR_ACP_FFT_WINDOW
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_NONE                                                            0
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_HANNING                                                         2
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_HAMMING                                                         3
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXSPECAN_VAL_ACP_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXSPECAN_ATTR_ACP_FFT_OVERLAP_MODE
#define RFMXSPECAN_VAL_ACP_FFT_OVERLAP_MODE_DISABLED                                                  0
#define RFMXSPECAN_VAL_ACP_FFT_OVERLAP_MODE_AUTOMATIC                                                 1
#define RFMXSPECAN_VAL_ACP_FFT_OVERLAP_MODE_USER_DEFINED                                              2

// Values for RFMXSPECAN_ATTR_ACP_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXSPECAN_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                          0
#define RFMXSPECAN_VAL_ACP_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                           1

// Values for RFMXSPECAN_ATTR_ACP_AMPLITUDE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXSPECAN_VAL_ACP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXSPECAN_ATTR_CCDF_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_CCDF_RBW_FILTER_TYPE_NONE                                                      5
#define RFMXSPECAN_VAL_CCDF_RBW_FILTER_TYPE_GAUSSIAN                                                  1
#define RFMXSPECAN_VAL_CCDF_RBW_FILTER_TYPE_FLAT                                                      2
#define RFMXSPECAN_VAL_CCDF_RBW_FILTER_TYPE_RRC                                                       6

// Values for RFMXSPECAN_ATTR_CCDF_THRESHOLD_ENABLED
#define RFMXSPECAN_VAL_CCDF_THRESHOLD_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_CCDF_THRESHOLD_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_CCDF_THRESHOLD_TYPE
#define RFMXSPECAN_VAL_CCDF_THRESHOLD_TYPE_RELATIVE                                                   0
#define RFMXSPECAN_VAL_CCDF_THRESHOLD_TYPE_ABSOLUTE                                                   1

// Values for RFMXSPECAN_ATTR_CHP_CARRIER_RRC_FILTER_ENABLED
#define RFMXSPECAN_VAL_CHP_CARRIER_RRC_FILTER_ENABLED_FALSE                                           0
#define RFMXSPECAN_VAL_CHP_CARRIER_RRC_FILTER_ENABLED_TRUE                                            1

// Values for RFMXSPECAN_ATTR_CHP_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_CHP_RBW_AUTO_FALSE                                                             0
#define RFMXSPECAN_VAL_CHP_RBW_AUTO_TRUE                                                              1

// Values for RFMXSPECAN_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_CHP_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXSPECAN_VAL_CHP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXSPECAN_VAL_CHP_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXSPECAN_ATTR_CHP_RBW_FILTER_BANDWIDTH_DEFINITION
#define RFMXSPECAN_VAL_CHP_RBW_FILTER_BANDWIDTH_DEFINITION_3DB                                        0
#define RFMXSPECAN_VAL_CHP_RBW_FILTER_BANDWIDTH_DEFINITION_BIN_WIDTH                                  2

// Values for RFMXSPECAN_ATTR_CHP_SWEEP_TIME_AUTO
#define RFMXSPECAN_VAL_CHP_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXSPECAN_VAL_CHP_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXSPECAN_ATTR_CHP_DETECTOR_TYPE
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_NONE                                                         0
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_SAMPLE                                                       1
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_NORMAL                                                       2
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_PEAK                                                         3
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_NEGATIVE_PEAK                                                4
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_AVERAGE_RMS                                                  5
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_AVERAGE_VOLTAGE                                              6
#define RFMXSPECAN_VAL_CHP_DETECTOR_TYPE_AVERAGE_LOG                                                  7

// Values for RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_MODE
#define RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_MODE_MANUAL                                              0
#define RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_MODE_AUTO                                                1

// Values for RFMXSPECAN_ATTR_CHP_NOISE_CALIBRATION_AVERAGING_AUTO
#define RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE                                     0
#define RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE                                      1

// Values for RFMXSPECAN_ATTR_CHP_NOISE_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_ENABLED_FALSE                                           0
#define RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_ENABLED_TRUE                                            1

// Values for RFMXSPECAN_ATTR_CHP_NOISE_COMPENSATION_TYPE
#define RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION                           0
#define RFMXSPECAN_VAL_CHP_NOISE_COMPENSATION_TYPE_ANALYZER_ONLY                                      1

// Values for RFMXSPECAN_ATTR_CHP_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_CHP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_CHP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_CHP_AVERAGING_TYPE
#define RFMXSPECAN_VAL_CHP_AVERAGING_TYPE_RMS                                                         0
#define RFMXSPECAN_VAL_CHP_AVERAGING_TYPE_LOG                                                         1
#define RFMXSPECAN_VAL_CHP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXSPECAN_VAL_CHP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXSPECAN_VAL_CHP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXSPECAN_ATTR_CHP_MEASUREMENT_MODE
#define RFMXSPECAN_VAL_CHP_MEASUREMENT_MODE_MEASURE                                                   0
#define RFMXSPECAN_VAL_CHP_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                     1

// Values for RFMXSPECAN_ATTR_CHP_FFT_WINDOW
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_NONE                                                            0
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_HANNING                                                         2
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_HAMMING                                                         3
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXSPECAN_VAL_CHP_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXSPECAN_ATTR_CHP_AMPLITUDE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXSPECAN_VAL_CHP_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXSPECAN_ATTR_FCNT_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_FCNT_RBW_FILTER_TYPE_GAUSSIAN                                                  1
#define RFMXSPECAN_VAL_FCNT_RBW_FILTER_TYPE_FLAT                                                      2
#define RFMXSPECAN_VAL_FCNT_RBW_FILTER_TYPE_NONE                                                      5
#define RFMXSPECAN_VAL_FCNT_RBW_FILTER_TYPE_RRC                                                       6

// Values for RFMXSPECAN_ATTR_FCNT_THRESHOLD_ENABLED
#define RFMXSPECAN_VAL_FCNT_THRESHOLD_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_FCNT_THRESHOLD_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_FCNT_THRESHOLD_TYPE
#define RFMXSPECAN_VAL_FCNT_THRESHOLD_TYPE_RELATIVE                                                   0
#define RFMXSPECAN_VAL_FCNT_THRESHOLD_TYPE_ABSOLUTE                                                   1

// Values for RFMXSPECAN_ATTR_FCNT_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_FCNT_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_FCNT_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_FCNT_AVERAGING_TYPE
#define RFMXSPECAN_VAL_FCNT_AVERAGING_TYPE_MAXIMUM                                                    3
#define RFMXSPECAN_VAL_FCNT_AVERAGING_TYPE_MINIMUM                                                    4
#define RFMXSPECAN_VAL_FCNT_AVERAGING_TYPE_MEAN                                                       6
#define RFMXSPECAN_VAL_FCNT_AVERAGING_TYPE_MINMAX                                                     7

// Values for RFMXSPECAN_ATTR_HARM_FUNDAMENTAL_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_HARM_RBW_FILTER_TYPE_GAUSSIAN                                                  1
#define RFMXSPECAN_VAL_HARM_RBW_FILTER_TYPE_FLAT                                                      2
#define RFMXSPECAN_VAL_HARM_RBW_FILTER_TYPE_NONE                                                      5
#define RFMXSPECAN_VAL_HARM_RBW_FILTER_TYPE_RRC                                                       6

// Values for RFMXSPECAN_ATTR_HARM_AUTO_SETUP_ENABLED
#define RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_FALSE                                        0
#define RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE                                         1

// Values for RFMXSPECAN_ATTR_HARM_HARMONIC_ENABLED
#define RFMXSPECAN_VAL_HARM_HARMONIC_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_HARM_HARMONIC_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_HARM_MEASUREMENT_METHOD
#define RFMXSPECAN_VAL_HARM_MEASUREMENT_METHOD_TIME_DOMAIN                                            0
#define RFMXSPECAN_VAL_HARM_MEASUREMENT_METHOD_DYNAMIC_RANGE                                          2

// Values for RFMXSPECAN_ATTR_HARM_NOISE_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_HARM_NOISE_COMPENSATION_ENABLED_FALSE                                          0
#define RFMXSPECAN_VAL_HARM_NOISE_COMPENSATION_ENABLED_TRUE                                           1

// Values for RFMXSPECAN_ATTR_HARM_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_HARM_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_HARM_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_HARM_AVERAGING_TYPE
#define RFMXSPECAN_VAL_HARM_AVERAGING_TYPE_RMS                                                        0
#define RFMXSPECAN_VAL_HARM_AVERAGING_TYPE_LOG                                                        1
#define RFMXSPECAN_VAL_HARM_AVERAGING_TYPE_SCALAR                                                     2
#define RFMXSPECAN_VAL_HARM_AVERAGING_TYPE_MAXIMUM                                                    3
#define RFMXSPECAN_VAL_HARM_AVERAGING_TYPE_MINIMUM                                                    4

// Values for RFMXSPECAN_ATTR_OBW_POWER_UNITS
#define RFMXSPECAN_VAL_OBW_POWER_UNITS_DBM                                                            0
#define RFMXSPECAN_VAL_OBW_POWER_UNITS_DBM_PER_HZ                                                     1

// Values for RFMXSPECAN_ATTR_OBW_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_OBW_RBW_AUTO_FALSE                                                             0
#define RFMXSPECAN_VAL_OBW_RBW_AUTO_TRUE                                                              1

// Values for RFMXSPECAN_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_OBW_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXSPECAN_VAL_OBW_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXSPECAN_VAL_OBW_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXSPECAN_ATTR_OBW_RBW_FILTER_BANDWIDTH_DEFINITION
#define RFMXSPECAN_VAL_OBW_RBW_FILTER_BANDWIDTH_DEFINITION_3DB                                        0
#define RFMXSPECAN_VAL_OBW_RBW_FILTER_BANDWIDTH_DEFINITION_BIN_WIDTH                                  2

// Values for RFMXSPECAN_ATTR_OBW_SWEEP_TIME_AUTO
#define RFMXSPECAN_VAL_OBW_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXSPECAN_VAL_OBW_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXSPECAN_ATTR_OBW_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_OBW_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_OBW_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_OBW_AVERAGING_TYPE
#define RFMXSPECAN_VAL_OBW_AVERAGING_TYPE_RMS                                                         0
#define RFMXSPECAN_VAL_OBW_AVERAGING_TYPE_LOG                                                         1
#define RFMXSPECAN_VAL_OBW_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXSPECAN_VAL_OBW_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXSPECAN_VAL_OBW_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXSPECAN_ATTR_OBW_FFT_WINDOW
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_NONE                                                            0
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_HANNING                                                         2
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_HAMMING                                                         3
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXSPECAN_VAL_OBW_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXSPECAN_ATTR_OBW_AMPLITUDE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXSPECAN_VAL_OBW_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXSPECAN_ATTR_SEM_CARRIER_ENABLED
#define RFMXSPECAN_VAL_SEM_ENABLED_FALSE                                                              0
#define RFMXSPECAN_VAL_SEM_ENABLED_TRUE                                                               1

// Values for RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_AUTO_FALSE                                                     0
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_AUTO_TRUE                                                      1

// Values for RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_TYPE_FFT_BASED                                          0
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_TYPE_GAUSSIAN                                           1
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_TYPE_FLAT                                               2

// Values for RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_BANDWIDTH_DEFINITION
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_BANDWIDTH_DEFINITION_3DB                                0
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_BANDWIDTH_DEFINITION_BIN_WIDTH                          2

// Values for RFMXSPECAN_ATTR_SEM_CARRIER_RRC_FILTER_ENABLED
#define RFMXSPECAN_VAL_SEM_RRC_FILTER_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_SEM_RRC_FILTER_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_ENABLED
#define RFMXSPECAN_VAL_SEM_OFFSET_ENABLED_FALSE                                                       0
#define RFMXSPECAN_VAL_SEM_OFFSET_ENABLED_TRUE                                                        1

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_SIDEBAND
#define RFMXSPECAN_VAL_SEM_OFFSET_SIDEBAND_NEGATIVE                                                   0
#define RFMXSPECAN_VAL_SEM_OFFSET_SIDEBAND_POSITIVE                                                   1
#define RFMXSPECAN_VAL_SEM_OFFSET_SIDEBAND_BOTH                                                       2

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_SEM_RBW_AUTO_FALSE                                                             0
#define RFMXSPECAN_VAL_SEM_RBW_AUTO_TRUE                                                              1

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SEM_RBW_FILTER_TYPE_FFT_BASED                                                  0
#define RFMXSPECAN_VAL_SEM_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXSPECAN_VAL_SEM_RBW_FILTER_TYPE_FLAT                                                       2

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_BANDWIDTH_DEFINITION
#define RFMXSPECAN_VAL_SEM_OFFSET_RBW_FILTER_BANDWIDTH_DEFINITION_3DB                                 0
#define RFMXSPECAN_VAL_SEM_OFFSET_RBW_FILTER_BANDWIDTH_DEFINITION_BIN_WIDTH                           2

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_LIMIT_FAIL_MASK
#define RFMXSPECAN_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE_AND_RELATIVE                               0
#define RFMXSPECAN_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE_OR_RELATIVE                                1
#define RFMXSPECAN_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE                                            2
#define RFMXSPECAN_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_RELATIVE                                            3

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_ABSOLUTE_LIMIT_MODE
#define RFMXSPECAN_VAL_SEM_OFFSET_ABSOLUTE_LIMIT_MODE_MANUAL                                          0
#define RFMXSPECAN_VAL_SEM_OFFSET_ABSOLUTE_LIMIT_MODE_COUPLE                                          1

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_RELATIVE_LIMIT_MODE
#define RFMXSPECAN_VAL_SEM_OFFSET_RELATIVE_LIMIT_MODE_MANUAL                                          0
#define RFMXSPECAN_VAL_SEM_OFFSET_RELATIVE_LIMIT_MODE_COUPLE                                          1

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_FREQUENCY_DEFINITION
#define RFMXSPECAN_VAL_SEM_CARRIER_CENTER_TO_MEASUREMENT_BANDWIDTH_CENTER                             0
#define RFMXSPECAN_VAL_SEM_CARRIER_CENTER_TO_MEASUREMENT_BANDWIDTH_EDGE                               1
#define RFMXSPECAN_VAL_SEM_CARRIER_EDGE_TO_MEASUREMENT_BANDWIDTH_CENTER                               2
#define RFMXSPECAN_VAL_SEM_CARRIER_EDGE_TO_MEASUREMENT_BANDWIDTH_EDGE                                 3

// Values for RFMXSPECAN_ATTR_SEM_POWER_UNITS
#define RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM                                                            0
#define RFMXSPECAN_VAL_SEM_POWER_UNITS_DBM_PER_HZ                                                     1

// Values for RFMXSPECAN_ATTR_SEM_REFERENCE_TYPE
#define RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_INTEGRATION                                                 0
#define RFMXSPECAN_VAL_SEM_REFERENCE_TYPE_PEAK                                                        1

// Values for RFMXSPECAN_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXSPECAN_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXSPECAN_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXSPECAN_ATTR_SEM_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_SEM_AVERAGING_TYPE
#define RFMXSPECAN_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXSPECAN_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXSPECAN_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXSPECAN_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXSPECAN_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXSPECAN_ATTR_SEM_FFT_WINDOW
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_NONE                                                            0
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_FLAT_TOP                                                        1
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_HANNING                                                         2
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_HAMMING                                                         3
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_GAUSSIAN                                                        4
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_BLACKMAN                                                        5
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_BLACKMAN_HARRIS                                                 6
#define RFMXSPECAN_VAL_SEM_FFT_WINDOW_KAISER_BESSEL                                                   7

// Values for RFMXSPECAN_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXSPECAN_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXSPECAN_ATTR_SEM_RESULTS_COMPOSITE_MEASUREMENT_STATUS
#define RFMXSPECAN_VAL_SEM_COMPOSITE_MEASUREMENT_STATUS_FAIL                                          0
#define RFMXSPECAN_VAL_SEM_COMPOSITE_MEASUREMENT_STATUS_PASS                                          1

// Values for RFMXSPECAN_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXSPECAN_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXSPECAN_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXSPECAN_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXSPECAN_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXSPECAN_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXSPECAN_ATTR_SPECTRUM_POWER_UNITS
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_DBM                                                       0
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_DBM_PER_HZ                                                1
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_DBW                                                       2
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_DBV                                                       3
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_DBMV                                                      4
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_DBUV                                                      5
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_WATTS                                                     6
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_VOLTS                                                     7
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_VOLTS_SQUARED                                             8

// Values for RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_SPECTRUM_RBW_AUTO_FALSE                                                        0
#define RFMXSPECAN_VAL_SPECTRUM_RBW_AUTO_TRUE                                                         1

// Values for RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_TYPE_FFT_BASED                                             0
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN                                              1
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_TYPE_FLAT                                                  2

// Values for RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION_3DB                                   0
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION_6DB                                   1
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION_BIN_WIDTH                             2
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_BANDWIDTH_DEFINITION_ENBW                                  3

// Values for RFMXSPECAN_ATTR_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH_FALSE                                       0
#define RFMXSPECAN_VAL_SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH_TRUE                                        1

// Values for RFMXSPECAN_ATTR_SPECTRUM_SWEEP_TIME_AUTO
#define RFMXSPECAN_VAL_SPECTRUM_SWEEP_TIME_AUTO_FALSE                                                 0
#define RFMXSPECAN_VAL_SPECTRUM_SWEEP_TIME_AUTO_TRUE                                                  1

// Values for RFMXSPECAN_ATTR_SPECTRUM_DETECTOR_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_NONE                                                    0
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_SAMPLE                                                  1
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_NORMAL                                                  2
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_PEAK                                                    3
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_NEGATIVE_PEAK                                           4
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_AVERAGE_RMS                                             5
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_AVERAGE_VOLTAGE                                         6
#define RFMXSPECAN_VAL_SPECTRUM_DETECTOR_TYPE_AVERAGE_LOG                                             7

// Values for RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_MODE
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_MODE_MANUAL                                         0
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_MODE_AUTO                                           1

// Values for RFMXSPECAN_ATTR_SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO_FALSE                                0
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_AVERAGING_AUTO_TRUE                                 1

// Values for RFMXSPECAN_ATTR_SPECTRUM_NOISE_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_ENABLED_FALSE                                      0
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_ENABLED_TRUE                                       1

// Values for RFMXSPECAN_ATTR_SPECTRUM_NOISE_COMPENSATION_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_TYPE_ANALYZER_AND_TERMINATION                      0
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_COMPENSATION_TYPE_ANALYZER_ONLY                                 1

// Values for RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_ENABLED_FALSE                                               0
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_ENABLED_TRUE                                                1

// Values for RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_TYPE_RMS                                                    0
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_TYPE_LOG                                                    1
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_TYPE_SCALAR                                                 2
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_TYPE_MAXIMUM                                                3
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_TYPE_MINIMUM                                                4

// Values for RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_MODE
#define RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_MODE_MEASURE                                              0
#define RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_MODE_CALIBRATE_NOISE_FLOOR                                1

// Values for RFMXSPECAN_ATTR_SPECTRUM_FFT_WINDOW
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_NONE                                                       0
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_FLAT_TOP                                                   1
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_HANNING                                                    2
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_HAMMING                                                    3
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_GAUSSIAN                                                   4
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_BLACKMAN                                                   5
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_BLACKMAN_HARRIS                                            6
#define RFMXSPECAN_VAL_SPECTRUM_FFT_WINDOW_KAISER_BESSEL                                              7

// Values for RFMXSPECAN_ATTR_SPECTRUM_FFT_OVERLAP_MODE
#define RFMXSPECAN_VAL_SPECTRUM_FFT_OVERLAP_MODE_DISABLED                                             0
#define RFMXSPECAN_VAL_SPECTRUM_FFT_OVERLAP_MODE_AUTOMATIC                                            1
#define RFMXSPECAN_VAL_SPECTRUM_FFT_OVERLAP_MODE_USER_DEFINED                                         2

// Values for RFMXSPECAN_ATTR_SPECTRUM_FFT_OVERLAP_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_FFT_OVERLAP_TYPE_RMS                                                  0
#define RFMXSPECAN_VAL_SPECTRUM_FFT_OVERLAP_TYPE_MAX                                                  3

// Values for RFMXSPECAN_ATTR_SPECTRUM_AMPLITUDE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                         0
#define RFMXSPECAN_VAL_SPECTRUM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                      1

// Values for RFMXSPECAN_ATTR_SPECTRUM_MEASUREMENT_METHOD
#define RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_METHOD_NORMAL                                             0
#define RFMXSPECAN_VAL_SPECTRUM_MEASUREMENT_METHOD_SEQUENTIAL_FFT                                     2

// Values for RFMXSPECAN_ATTR_SPECTRUM_ANALYSIS_INPUT
#define RFMXSPECAN_VAL_SPECTRUM_ANALYSIS_INPUT_IQ                                                     0
#define RFMXSPECAN_VAL_SPECTRUM_ANALYSIS_INPUT_I_ONLY                                                 1
#define RFMXSPECAN_VAL_SPECTRUM_ANALYSIS_INPUT_Q_ONLY                                                 2

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_ENABLED
#define RFMXSPECAN_VAL_SPUR_RANGE_ENABLED_FALSE                                                       0
#define RFMXSPECAN_VAL_SPUR_RANGE_ENABLED_TRUE                                                        1

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_SPUR_RBW_AUTO_FALSE                                                            0
#define RFMXSPECAN_VAL_SPUR_RBW_AUTO_TRUE                                                             1

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SPUR_RBW_FILTER_TYPE_FFT_BASED                                                 0
#define RFMXSPECAN_VAL_SPUR_RBW_FILTER_TYPE_GAUSSIAN                                                  1
#define RFMXSPECAN_VAL_SPUR_RBW_FILTER_TYPE_FLAT                                                      2

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_BANDWIDTH_DEFINITION
#define RFMXSPECAN_VAL_SPUR_RANGE_RBW_FILTER_BANDWIDTH_DEFINITION_3DB                                 0
#define RFMXSPECAN_VAL_SPUR_RANGE_RBW_FILTER_BANDWIDTH_DEFINITION_BIN_WIDTH                           2
#define RFMXSPECAN_VAL_SPUR_RANGE_RBW_FILTER_BANDWIDTH_DEFINITION_ENBW                                3

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH_FALSE                                     0
#define RFMXSPECAN_VAL_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH_TRUE                                      1

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_SWEEP_TIME_AUTO
#define RFMXSPECAN_VAL_SPUR_SWEEP_TIME_AUTO_FALSE                                                     0
#define RFMXSPECAN_VAL_SPUR_SWEEP_TIME_AUTO_TRUE                                                      1

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_DETECTOR_TYPE
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_NONE                                                  0
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_SAMPLE                                                1
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_NORMAL                                                2
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_PEAK                                                  3
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_NEGATIVE_PEAK                                         4
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_AVERAGE_RMS                                           5
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_AVERAGE_VOLTAGE                                       6
#define RFMXSPECAN_VAL_SPUR_RANGE_DETECTOR_TYPE_AVERAGE_LOG                                           7

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_ABSOLUTE_LIMIT_MODE
#define RFMXSPECAN_VAL_SPUR_ABSOLUTE_LIMIT_MODE_MANUAL                                                0
#define RFMXSPECAN_VAL_SPUR_ABSOLUTE_LIMIT_MODE_COUPLE                                                1

// Values for RFMXSPECAN_ATTR_SPUR_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_SPUR_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_SPUR_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_SPUR_AVERAGING_TYPE
#define RFMXSPECAN_VAL_SPUR_AVERAGING_TYPE_RMS                                                        0
#define RFMXSPECAN_VAL_SPUR_AVERAGING_TYPE_LOG                                                        1
#define RFMXSPECAN_VAL_SPUR_AVERAGING_TYPE_SCALAR                                                     2
#define RFMXSPECAN_VAL_SPUR_AVERAGING_TYPE_MAXIMUM                                                    3
#define RFMXSPECAN_VAL_SPUR_AVERAGING_TYPE_MINIMUM                                                    4

// Values for RFMXSPECAN_ATTR_SPUR_FFT_WINDOW
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_NONE                                                           0
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_FLAT_TOP                                                       1
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_HANNING                                                        2
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_HAMMING                                                        3
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_GAUSSIAN                                                       4
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_BLACKMAN                                                       5
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_BLACKMAN_HARRIS                                                6
#define RFMXSPECAN_VAL_SPUR_FFT_WINDOW_KAISER_BESSEL                                                  7

// Values for RFMXSPECAN_ATTR_SPUR_AMPLITUDE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_SPUR_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                             0
#define RFMXSPECAN_VAL_SPUR_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                          1

// Values for RFMXSPECAN_ATTR_SPUR_RESULTS_MEASUREMENT_STATUS
#define RFMXSPECAN_VAL_SPUR_MEASUREMENT_STATUS_FAIL                                                   0
#define RFMXSPECAN_VAL_SPUR_MEASUREMENT_STATUS_PASS                                                   1

// Values for RFMXSPECAN_ATTR_SPUR_RESULTS_RANGE_MEASUREMENT_STATUS
#define RFMXSPECAN_VAL_SPUR_RANGE_STATUS_FAIL                                                         0
#define RFMXSPECAN_VAL_SPUR_RANGE_STATUS_PASS                                                         1

// Values for RFMXSPECAN_ATTR_TXP_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_TXP_RBW_FILTER_TYPE_GAUSSIAN                                                   1
#define RFMXSPECAN_VAL_TXP_RBW_FILTER_TYPE_FLAT                                                       2
#define RFMXSPECAN_VAL_TXP_RBW_FILTER_TYPE_NONE                                                       5
#define RFMXSPECAN_VAL_TXP_RBW_FILTER_TYPE_RRC                                                        6

// Values for RFMXSPECAN_ATTR_TXP_VBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_TXP_VBW_FILTER_AUTO_BANDWIDTH_FALSE                                            0
#define RFMXSPECAN_VAL_TXP_VBW_FILTER_AUTO_BANDWIDTH_TRUE                                             1

// Values for RFMXSPECAN_ATTR_TXP_THRESHOLD_ENABLED
#define RFMXSPECAN_VAL_TXP_THRESHOLD_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_TXP_THRESHOLD_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_TXP_THRESHOLD_TYPE
#define RFMXSPECAN_VAL_TXP_THRESHOLD_TYPE_RELATIVE                                                    0
#define RFMXSPECAN_VAL_TXP_THRESHOLD_TYPE_ABSOLUTE                                                    1

// Values for RFMXSPECAN_ATTR_TXP_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_TXP_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_TXP_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_TXP_AVERAGING_TYPE
#define RFMXSPECAN_VAL_TXP_AVERAGING_TYPE_RMS                                                         0
#define RFMXSPECAN_VAL_TXP_AVERAGING_TYPE_LOG                                                         1
#define RFMXSPECAN_VAL_TXP_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXSPECAN_VAL_TXP_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXSPECAN_VAL_TXP_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXSPECAN_ATTR_AMPM_MEASUREMENT_SAMPLE_RATE_MODE
#define RFMXSPECAN_VAL_AMPM_MEASUREMENT_SAMPLE_RATE_MODE_USER                                         0
#define RFMXSPECAN_VAL_AMPM_MEASUREMENT_SAMPLE_RATE_MODE_REFERENCE_WAVEFORM                           1

// Values for RFMXSPECAN_ATTR_AMPM_SIGNAL_TYPE
#define RFMXSPECAN_VAL_AMPM_SIGNAL_TYPE_MODULATED                                                     0
#define RFMXSPECAN_VAL_AMPM_SIGNAL_TYPE_TONES                                                         1

// Values for RFMXSPECAN_ATTR_AMPM_SYNCHRONIZATION_METHOD
#define RFMXSPECAN_VAL_AMPM_SYNCHRONIZATION_METHOD_DIRECT                                             1
#define RFMXSPECAN_VAL_AMPM_SYNCHRONIZATION_METHOD_ALIAS_PROTECTED                                    2

// Values for RFMXSPECAN_ATTR_AMPM_AUTO_CARRIER_DETECTION_ENABLED
#define RFMXSPECAN_VAL_AMPM_AUTO_CARRIER_DETECTION_ENABLED_FALSE                                      0
#define RFMXSPECAN_VAL_AMPM_AUTO_CARRIER_DETECTION_ENABLED_TRUE                                       1

// Values for RFMXSPECAN_ATTR_AMPM_AM_TO_AM_CURVE_FIT_TYPE
#define RFMXSPECAN_VAL_AMPM_AM_TO_AM_CURVE_FIT_TYPE_LEAST_SQUARE                                      0
#define RFMXSPECAN_VAL_AMPM_AM_TO_AM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL                           1
#define RFMXSPECAN_VAL_AMPM_AM_TO_AM_CURVE_FIT_TYPE_BISQUARE                                          2

// Values for RFMXSPECAN_ATTR_AMPM_AM_TO_PM_CURVE_FIT_TYPE
#define RFMXSPECAN_VAL_AMPM_AM_TO_PM_CURVE_FIT_TYPE_LEAST_SQUARE                                      0
#define RFMXSPECAN_VAL_AMPM_AM_TO_PM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL                           1
#define RFMXSPECAN_VAL_AMPM_AM_TO_PM_CURVE_FIT_TYPE_BISQUARE                                          2

// Values for RFMXSPECAN_ATTR_AMPM_THRESHOLD_ENABLED
#define RFMXSPECAN_VAL_AMPM_THRESHOLD_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_AMPM_THRESHOLD_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_AMPM_THRESHOLD_TYPE
#define RFMXSPECAN_VAL_AMPM_THRESHOLD_TYPE_RELATIVE                                                   0
#define RFMXSPECAN_VAL_AMPM_THRESHOLD_TYPE_ABSOLUTE                                                   1

// Values for RFMXSPECAN_ATTR_AMPM_THRESHOLD_DEFINITION
#define RFMXSPECAN_VAL_AMPM_THRESHOLD_DEFINITION_INPUT_AND_OUTPUT                                     0
#define RFMXSPECAN_VAL_AMPM_THRESHOLD_DEFINITION_REFERENCE_POWER_TYPE                                 1

// Values for RFMXSPECAN_ATTR_AMPM_FREQUENCY_OFFSET_CORRECTION_ENABLED
#define RFMXSPECAN_VAL_AMPM_FREQUENCY_OFFSET_CORRECTION_ENABLED_FALSE                                 0
#define RFMXSPECAN_VAL_AMPM_FREQUENCY_OFFSET_CORRECTION_ENABLED_TRUE                                  1

// Values for RFMXSPECAN_ATTR_AMPM_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED
#define RFMXSPECAN_VAL_AMPM_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_FALSE                                 0
#define RFMXSPECAN_VAL_AMPM_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_TRUE                                  1

// Values for RFMXSPECAN_ATTR_AMPM_AM_TO_AM_ENABLED
#define RFMXSPECAN_VAL_AMPM_AM_TO_AM_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_AMPM_AM_TO_AM_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_AMPM_AM_TO_PM_ENABLED
#define RFMXSPECAN_VAL_AMPM_AM_TO_PM_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_AMPM_AM_TO_PM_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_AMPM_EVM_ENABLED
#define RFMXSPECAN_VAL_AMPM_EVM_ENABLED_FALSE                                                         0
#define RFMXSPECAN_VAL_AMPM_EVM_ENABLED_TRUE                                                          1

// Values for RFMXSPECAN_ATTR_AMPM_EQUALIZER_MODE
#define RFMXSPECAN_VAL_AMPM_EQUALIZER_MODE_OFF                                                        0
#define RFMXSPECAN_VAL_AMPM_EQUALIZER_MODE_TRAIN                                                      1

// Values for RFMXSPECAN_ATTR_AMPM_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_AMPM_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_AMPM_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_ENABLED
#define RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_ENABLED_FALSE                                           0
#define RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_ENABLED_TRUE                                            1

// Values for RFMXSPECAN_ATTR_AMPM_COMPRESSION_POINT_GAIN_REFERENCE
#define RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_AUTO                                     0
#define RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_REFERENCE_POWER                          1
#define RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_MAX_GAIN                                 2
#define RFMXSPECAN_VAL_AMPM_COMPRESSION_POINT_GAIN_REFERENCE_USER_DEFINED                             3

// Values for RFMXSPECAN_ATTR_AMPM_REFERENCE_POWER_TYPE
#define RFMXSPECAN_VAL_AMPM_REFERENCE_POWER_TYPE_INPUT                                                0
#define RFMXSPECAN_VAL_AMPM_REFERENCE_POWER_TYPE_OUTPUT                                               1

// Values for RFMXSPECAN_ATTR_DPD_MEASUREMENT_SAMPLE_RATE_MODE
#define RFMXSPECAN_VAL_DPD_MEASUREMENT_SAMPLE_RATE_MODE_USER                                          0
#define RFMXSPECAN_VAL_DPD_MEASUREMENT_SAMPLE_RATE_MODE_REFERENCE_WAVEFORM                            1

// Values for RFMXSPECAN_ATTR_DPD_SIGNAL_TYPE
#define RFMXSPECAN_VAL_DPD_SIGNAL_TYPE_MODULATED                                                      0
#define RFMXSPECAN_VAL_DPD_SIGNAL_TYPE_TONES                                                          1

// Values for RFMXSPECAN_ATTR_DPD_SYNCHRONIZATION_METHOD
#define RFMXSPECAN_VAL_DPD_SYNCHRONIZATION_METHOD_DIRECT                                              1
#define RFMXSPECAN_VAL_DPD_SYNCHRONIZATION_METHOD_ALIAS_PROTECTED                                     2

// Values for RFMXSPECAN_ATTR_DPD_AUTO_CARRIER_DETECTION_ENABLED
#define RFMXSPECAN_VAL_DPD_AUTO_CARRIER_DETECTION_ENABLED_FALSE                                       0
#define RFMXSPECAN_VAL_DPD_AUTO_CARRIER_DETECTION_ENABLED_TRUE                                        1

// Values for RFMXSPECAN_ATTR_DPD_MODEL
#define RFMXSPECAN_VAL_DPD_MODEL_LOOKUP_TABLE                                                         0
#define RFMXSPECAN_VAL_DPD_MODEL_MEMORY_POLYNOMIAL                                                    1
#define RFMXSPECAN_VAL_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL                                        2
#define RFMXSPECAN_VAL_DPD_MODEL_DECOMPOSED_VECTOR_ROTATION                                           3

// Values for RFMXSPECAN_ATTR_DPD_TARGET_GAIN_TYPE
#define RFMXSPECAN_VAL_DPD_TARGET_GAIN_TYPE_AVERAGE_GAIN                                              0
#define RFMXSPECAN_VAL_DPD_TARGET_GAIN_TYPE_LINEAR_REGION_GAIN                                        1
#define RFMXSPECAN_VAL_DPD_TARGET_GAIN_TYPE_PEAK_INPUT_POWER_GAIN                                     2

// Values for RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_TYPE
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_TYPE_LOG                                                      0
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_TYPE_LINEAR                                                   1

// Values for RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_TYPE
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_TYPE_LEAST_SQUARE                          0
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL               1
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_AM_CURVE_FIT_TYPE_BISQUARE                              2

// Values for RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_TYPE
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_TYPE_LEAST_SQUARE                          0
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_TYPE_LEAST_ABSOLUTE_RESIDUAL               1
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_AM_TO_PM_CURVE_FIT_TYPE_BISQUARE                              2

// Values for RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_ENABLED
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_ENABLED_FALSE                                       0
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_ENABLED_TRUE                                        1

// Values for RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_TYPE
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_TYPE_RELATIVE                                       0
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_TYPE_ABSOLUTE                                       1

// Values for RFMXSPECAN_ATTR_DPD_LOOKUP_TABLE_THRESHOLD_DEFINITION
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_DEFINITION_INPUT_AND_OUTPUT                         0
#define RFMXSPECAN_VAL_DPD_LOOKUP_TABLE_THRESHOLD_DEFINITION_INPUT                                    1

// Values for RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_ORDER_TYPE
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_ORDER_TYPE_ALL_ORDERS                                    0
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_ORDER_TYPE_ODD_ORDERS_ONLY                               1
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_ORDER_TYPE_EVEN_ORDERS_ONLY                              2

// Values for RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LEAD_ORDER_TYPE
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_LEAD_ORDER_TYPE_ALL_ORDERS                               0
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_LEAD_ORDER_TYPE_ODD_ORDERS_ONLY                          1
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_LEAD_ORDER_TYPE_EVEN_ORDERS_ONLY                         2

// Values for RFMXSPECAN_ATTR_DPD_MEMORY_POLYNOMIAL_LAG_ORDER_TYPE
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_LAG_ORDER_TYPE_ALL_ORDERS                                0
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_LAG_ORDER_TYPE_ODD_ORDERS_ONLY                           1
#define RFMXSPECAN_VAL_DPD_MEMORY_POLYNOMIAL_LAG_ORDER_TYPE_EVEN_ORDERS_ONLY                          2

// Values for RFMXSPECAN_ATTR_DPD_DVR_DDR_ENABLED
#define RFMXSPECAN_VAL_DPD_DVR_DDR_ENABLED_FALSE                                                      0
#define RFMXSPECAN_VAL_DPD_DVR_DDR_ENABLED_TRUE                                                       1

// Values for RFMXSPECAN_ATTR_DPD_MEASUREMENT_MODE
#define RFMXSPECAN_VAL_DPD_MEASUREMENT_MODE_ACQUIRE_AND_EXTRACT                                       0
#define RFMXSPECAN_VAL_DPD_MEASUREMENT_MODE_EXTRACT_ONLY                                              1

// Values for RFMXSPECAN_ATTR_DPD_ITERATIVE_DPD_ENABLED
#define RFMXSPECAN_VAL_DPD_ITERATIVE_DPD_ENABLED_FALSE                                                0
#define RFMXSPECAN_VAL_DPD_ITERATIVE_DPD_ENABLED_TRUE                                                 1

// Values for RFMXSPECAN_ATTR_DPD_FREQUENCY_OFFSET_CORRECTION_ENABLED
#define RFMXSPECAN_VAL_DPD_FREQUENCY_OFFSET_CORRECTION_ENABLED_FALSE                                  0
#define RFMXSPECAN_VAL_DPD_FREQUENCY_OFFSET_CORRECTION_ENABLED_TRUE                                   1

// Values for RFMXSPECAN_ATTR_DPD_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED
#define RFMXSPECAN_VAL_DPD_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_FALSE                                  0
#define RFMXSPECAN_VAL_DPD_IQ_ORIGIN_OFFSET_CORRECTION_ENABLED_TRUE                                   1

// Values for RFMXSPECAN_ATTR_DPD_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_DPD_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXSPECAN_VAL_DPD_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXSPECAN_ATTR_DPD_NMSE_ENABLED
#define RFMXSPECAN_VAL_DPD_NMSE_ENABLED_FALSE                                                         0
#define RFMXSPECAN_VAL_DPD_NMSE_ENABLED_TRUE                                                          1

// Values for RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_ENABLED
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_FALSE                                                  0
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_ENABLED_TRUE                                                   1

// Values for RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_METHOD
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_CLIPPING                                                0
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_PEAK_WINDOWING                                          1
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_METHOD_SIGMOID                                                 2

// Values for RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_WINDOW_TYPE
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_WINDOW_TYPE_FLAT_TOP                                           1
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_WINDOW_TYPE_HANNING                                            2
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_WINDOW_TYPE_HAMMING                                            3
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_WINDOW_TYPE_GAUSSIAN                                           4
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_WINDOW_TYPE_BLACKMAN                                           5
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_WINDOW_TYPE_BLACKMAN_HARRIS                                    6
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_WINDOW_TYPE_KAISER_BESSEL                                      7

// Values for RFMXSPECAN_ATTR_DPD_PRE_DPD_CFR_FILTER_ENABLED
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_FILTER_ENABLED_FALSE                                           0
#define RFMXSPECAN_VAL_DPD_PRE_DPD_CFR_FILTER_ENABLED_TRUE                                            1

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_CONFIGURATION_INPUT
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_MEASUREMENT                                  0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CONFIGURATION_INPUT_USER                                         1

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE_MAGNITUDE_AND_PHASE                 0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE_MAGNITUDE_ONLY                      1
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE_PHASE_ONLY                          2

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_MEMORY_MODEL_CORRECTION_TYPE
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_MEMORY_MODEL_CORRECTION_TYPE_MAGNITUDE_AND_PHASE                 0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_MEMORY_MODEL_CORRECTION_TYPE_MAGNITUDE_ONLY                      1
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_MEMORY_MODEL_CORRECTION_TYPE_PHASE_ONLY                          2

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_ENABLED
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_FALSE                                                0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_ENABLED_TRUE                                                 1

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_METHOD
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_CLIPPING                                              0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_PEAK_WINDOWING                                        1
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_METHOD_SIGMOID                                               2

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE_INPUT_PAPR                                  0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_TARGET_PAPR_TYPE_CUSTOM                                      1

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_CFR_WINDOW_TYPE
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_WINDOW_TYPE_FLAT_TOP                                         1
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_WINDOW_TYPE_HANNING                                          2
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_WINDOW_TYPE_HAMMING                                          3
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_WINDOW_TYPE_GAUSSIAN                                         4
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_WINDOW_TYPE_BLACKMAN                                         5
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_WINDOW_TYPE_BLACKMAN_HARRIS                                  6
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_CFR_WINDOW_TYPE_KAISER_BESSEL                                    7

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_DPD_MODEL
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_LOOKUP_TABLE                                      0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_MEMORY_POLYNOMIAL                                 1
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_DPD_MODEL_GENERALIZED_MEMORY_POLYNOMIAL                     2

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_USER_LOOKUP_TABLE_TYPE
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_LOOKUP_TABLE_TYPE_LOG                                       0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_USER_LOOKUP_TABLE_TYPE_LINEAR                                    1

// Values for RFMXSPECAN_ATTR_IDPD_EQUALIZER_MODE
#define RFMXSPECAN_VAL_IDPD_EQUALIZER_MODE_OFF                                                        0
#define RFMXSPECAN_VAL_IDPD_EQUALIZER_MODE_TRAIN                                                      1
#define RFMXSPECAN_VAL_IDPD_EQUALIZER_MODE_HOLD                                                       2

// Values for RFMXSPECAN_ATTR_IDPD_MEASUREMENT_SAMPLE_RATE_MODE
#define RFMXSPECAN_VAL_IDPD_MEASUREMENT_SAMPLE_RATE_MODE_USER                                         0
#define RFMXSPECAN_VAL_IDPD_MEASUREMENT_SAMPLE_RATE_MODE_REFERENCE_WAVEFORM                           1

// Values for RFMXSPECAN_ATTR_IDPD_SIGNAL_TYPE
#define RFMXSPECAN_VAL_IDPD_SIGNAL_TYPE_MODULATED                                                     0
#define RFMXSPECAN_VAL_IDPD_SIGNAL_TYPE_TONES                                                         1

// Values for RFMXSPECAN_ATTR_IDPD_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT
#define RFMXSPECAN_VAL_IDPD_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT_FALSE                            0
#define RFMXSPECAN_VAL_IDPD_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT_TRUE                             1

// Values for RFMXSPECAN_ATTR_IDPD_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_IDPD_AVERAGING_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_IDPD_AVERAGING_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_IDPD_EVM_ENABLED
#define RFMXSPECAN_VAL_IDPD_EVM_ENABLED_FALSE                                                         0
#define RFMXSPECAN_VAL_IDPD_EVM_ENABLED_TRUE                                                          1

// Values for RFMXSPECAN_ATTR_IDPD_EVM_UNIT
#define RFMXSPECAN_VAL_IDPD_EVM_UNIT_PERCENTAGE                                                       0
#define RFMXSPECAN_VAL_IDPD_EVM_UNIT_DB                                                               1

// Values for RFMXSPECAN_ATTR_IQ_MEASUREMENT_MODE
#define RFMXSPECAN_VAL_IQ_MEASUREMENT_MODE_NORMAL                                                     0
#define RFMXSPECAN_VAL_IQ_MEASUREMENT_MODE_RAWIQ                                                      1

// Values for RFMXSPECAN_ATTR_IQ_BANDWIDTH_AUTO
#define RFMXSPECAN_VAL_IQ_AUTO_BANDWIDTH_FALSE                                                        0
#define RFMXSPECAN_VAL_IQ_AUTO_BANDWIDTH_TRUE                                                         1

// Values for RFMXSPECAN_ATTR_IQ_DELETE_RECORD_ON_FETCH
#define RFMXSPECAN_VAL_IQ_DELETE_RECORD_ON_FETCH_FALSE                                                0
#define RFMXSPECAN_VAL_IQ_DELETE_RECORD_ON_FETCH_TRUE                                                 1

// Values for RFMXSPECAN_ATTR_IM_FREQUENCY_DEFINITION
#define RFMXSPECAN_VAL_IM_FREQUENCY_DEFINITION_RELATIVE                                               0
#define RFMXSPECAN_VAL_IM_FREQUENCY_DEFINITION_ABSOLUTE                                               1

// Values for RFMXSPECAN_ATTR_IM_AUTO_INTERMODS_SETUP_ENABLED
#define RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_FALSE                                          0
#define RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE                                           1

// Values for RFMXSPECAN_ATTR_IM_INTERMOD_ENABLED
#define RFMXSPECAN_VAL_IM_INTERMOD_ENABLED_FALSE                                                      0
#define RFMXSPECAN_VAL_IM_INTERMOD_ENABLED_TRUE                                                       1

// Values for RFMXSPECAN_ATTR_IM_INTERMOD_SIDE
#define RFMXSPECAN_VAL_IM_INTERMOD_SIDE_LOWER                                                         0
#define RFMXSPECAN_VAL_IM_INTERMOD_SIDE_UPPER                                                         1
#define RFMXSPECAN_VAL_IM_INTERMOD_SIDE_BOTH                                                          2

// Values for RFMXSPECAN_ATTR_IM_MEASUREMENT_METHOD
#define RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_NORMAL                                                   0
#define RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_DYNAMIC_RANGE                                            1
#define RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_SEGMENTED                                                2

// Values for RFMXSPECAN_ATTR_IM_LOCAL_PEAK_SEARCH_ENABLED
#define RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_FALSE                                             0
#define RFMXSPECAN_VAL_IM_LOCAL_PEAK_SEARCH_ENABLED_TRUE                                              1

// Values for RFMXSPECAN_ATTR_IM_RBW_FILTER_AUTO_BANDWIDTH
#define RFMXSPECAN_VAL_IM_RBW_FILTER_AUTO_BANDWIDTH_FALSE                                             0
#define RFMXSPECAN_VAL_IM_RBW_FILTER_AUTO_BANDWIDTH_TRUE                                              1

// Values for RFMXSPECAN_ATTR_IM_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_IM_RBW_FILTER_TYPE_FFT_BASED                                                   0
#define RFMXSPECAN_VAL_IM_RBW_FILTER_TYPE_GAUSSIAN                                                    1
#define RFMXSPECAN_VAL_IM_RBW_FILTER_TYPE_FLAT                                                        2

// Values for RFMXSPECAN_ATTR_IM_SWEEP_TIME_AUTO
#define RFMXSPECAN_VAL_IM_SWEEP_TIME_AUTO_FALSE                                                       0
#define RFMXSPECAN_VAL_IM_SWEEP_TIME_AUTO_TRUE                                                        1

// Values for RFMXSPECAN_ATTR_IM_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_IM_AVERAGING_ENABLED_FALSE                                                     0
#define RFMXSPECAN_VAL_IM_AVERAGING_ENABLED_TRUE                                                      1

// Values for RFMXSPECAN_ATTR_IM_AVERAGING_TYPE
#define RFMXSPECAN_VAL_IM_AVERAGING_TYPE_RMS                                                          0
#define RFMXSPECAN_VAL_IM_AVERAGING_TYPE_LOG                                                          1
#define RFMXSPECAN_VAL_IM_AVERAGING_TYPE_SCALAR                                                       2
#define RFMXSPECAN_VAL_IM_AVERAGING_TYPE_MAXIMUM                                                      3
#define RFMXSPECAN_VAL_IM_AVERAGING_TYPE_MINIMUM                                                      4

// Values for RFMXSPECAN_ATTR_IM_FFT_WINDOW
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_NONE                                                             0
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_FLAT_TOP                                                         1
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_HANNING                                                          2
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_HAMMING                                                          3
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_GAUSSIAN                                                         4
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_BLACKMAN                                                         5
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_BLACKMAN_HARRIS                                                  6
#define RFMXSPECAN_VAL_IM_FFT_WINDOW_KAISER_BESSEL                                                    7

// Values for RFMXSPECAN_ATTR_IM_IF_OUTPUT_POWER_OFFSET_AUTO
#define RFMXSPECAN_VAL_IM_IF_OUTPUT_POWER_OFFSET_AUTO_FALSE                                           0
#define RFMXSPECAN_VAL_IM_IF_OUTPUT_POWER_OFFSET_AUTO_TRUE                                            1

// Values for RFMXSPECAN_ATTR_IM_AMPLITUDE_CORRECTION_TYPE
#define RFMXSPECAN_VAL_IM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                               0
#define RFMXSPECAN_VAL_IM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                            1

// Values for RFMXSPECAN_ATTR_NF_DUT_TYPE
#define RFMXSPECAN_VAL_NF_DUT_TYPE_AMPLIFIER                                                          0
#define RFMXSPECAN_VAL_NF_DUT_TYPE_DOWNCONVERTER                                                      1
#define RFMXSPECAN_VAL_NF_DUT_TYPE_UPCONVERTER                                                        2

// Values for RFMXSPECAN_ATTR_NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT
#define RFMXSPECAN_VAL_NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT_RF                                    0
#define RFMXSPECAN_VAL_NF_FREQUENCY_CONVERTER_FREQUENCY_CONTEXT_IF                                    1

// Values for RFMXSPECAN_ATTR_NF_FREQUENCY_CONVERTER_SIDEBAND
#define RFMXSPECAN_VAL_NF_FREQUENCY_CONVERTER_SIDEBAND_LSB                                            0
#define RFMXSPECAN_VAL_NF_FREQUENCY_CONVERTER_SIDEBAND_USB                                            1

// Values for RFMXSPECAN_ATTR_NF_AVERAGING_ENABLED
#define RFMXSPECAN_VAL_NF_AVERAGING_ENABLED_FALSE                                                     0
#define RFMXSPECAN_VAL_NF_AVERAGING_ENABLED_TRUE                                                      1

// Values for RFMXSPECAN_ATTR_NF_EXTERNAL_PREAMP_PRESENT
#define RFMXSPECAN_VAL_NF_EXTERNAL_PREAMP_PRESENT_FALSE                                               0
#define RFMXSPECAN_VAL_NF_EXTERNAL_PREAMP_PRESENT_TRUE                                                1

// Values for RFMXSPECAN_ATTR_NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED_FALSE                                   0
#define RFMXSPECAN_VAL_NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED_TRUE                                    1

// Values for RFMXSPECAN_ATTR_NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED_FALSE                                  0
#define RFMXSPECAN_VAL_NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED_TRUE                                   1

// Values for RFMXSPECAN_ATTR_NF_CALIBRATION_LOSS_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_NF_CALIBRATION_LOSS_COMPENSATION_ENABLED_FALSE                                 0
#define RFMXSPECAN_VAL_NF_CALIBRATION_LOSS_COMPENSATION_ENABLED_TRUE                                  1

// Values for RFMXSPECAN_ATTR_NF_MEASUREMENT_METHOD
#define RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_Y_FACTOR                                                 0
#define RFMXSPECAN_VAL_NF_MEASUREMENT_METHOD_COLD_SOURCE                                              1

// Values for RFMXSPECAN_ATTR_NF_Y_FACTOR_MODE
#define RFMXSPECAN_VAL_NF_Y_FACTOR_MODE_MEASURE                                                       0
#define RFMXSPECAN_VAL_NF_Y_FACTOR_MODE_CALIBRATE                                                     1

// Values for RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_TYPE
#define RFMXSPECAN_VAL_NF_Y_FACTOR_NOISE_SOURCE_TYPE_EXTERNAL_NOISE_SOURCE                            0
#define RFMXSPECAN_VAL_NF_Y_FACTOR_NOISE_SOURCE_TYPE_RF_SIGNAL_GENERATOR                              1

// Values for RFMXSPECAN_ATTR_NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED
#define RFMXSPECAN_VAL_NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED_FALSE                       0
#define RFMXSPECAN_VAL_NF_Y_FACTOR_NOISE_SOURCE_LOSS_COMPENSATION_ENABLED_TRUE                        1

// Values for RFMXSPECAN_ATTR_NF_COLD_SOURCE_MODE
#define RFMXSPECAN_VAL_NF_COLD_SOURCE_MODE_MEASURE                                                    0
#define RFMXSPECAN_VAL_NF_COLD_SOURCE_MODE_CALIBRATE                                                  1

// Values for RFMXSPECAN_ATTR_PHASENOISE_RANGE_DEFINITION
#define RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_MANUAL                                             0
#define RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_AUTO                                               1

// Values for RFMXSPECAN_ATTR_PHASENOISE_FFT_WINDOW
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_NONE                                                     0
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_FLAT_TOP                                                 1
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_HANNING                                                  2
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_HAMMING                                                  3
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_GAUSSIAN                                                 4
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_BLACKMAN                                                 5
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_BLACKMAN_HARRIS                                          6
#define RFMXSPECAN_VAL_PHASENOISE_FFT_WINDOW_KAISER_BESSEL                                            7

// Values for RFMXSPECAN_ATTR_PHASENOISE_SMOOTHING_TYPE
#define RFMXSPECAN_VAL_PHASENOISE_SMOOTHING_TYPE_NONE                                                 0
#define RFMXSPECAN_VAL_PHASENOISE_SMOOTHING_TYPE_LINEAR                                               1
#define RFMXSPECAN_VAL_PHASENOISE_SMOOTHING_TYPE_LOGARITHMIC                                          2
#define RFMXSPECAN_VAL_PHASENOISE_SMOOTHING_TYPE_MEDIAN                                               3

// Values for RFMXSPECAN_ATTR_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION
#define RFMXSPECAN_VAL_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION_NONE                              0
#define RFMXSPECAN_VAL_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION_MEASUREMENT                       1
#define RFMXSPECAN_VAL_PHASENOISE_INTEGRATED_NOISE_RANGE_DEFINITION_CUSTOM                            2

// Values for RFMXSPECAN_ATTR_PHASENOISE_SPUR_REMOVAL_ENABLED
#define RFMXSPECAN_VAL_PHASENOISE_SPUR_REMOVAL_ENABLED_FALSE                                          0
#define RFMXSPECAN_VAL_PHASENOISE_SPUR_REMOVAL_ENABLED_TRUE                                           1

// Values for RFMXSPECAN_ATTR_PHASENOISE_CANCELLATION_ENABLED
#define RFMXSPECAN_VAL_PHASENOISE_CANCELLATION_ENABLED_FALSE                                          0
#define RFMXSPECAN_VAL_PHASENOISE_CANCELLATION_ENABLED_TRUE                                           1

// Values for RFMXSPECAN_ATTR_PAVT_MEASUREMENT_LOCATION_TYPE
#define RFMXSPECAN_VAL_PAVT_MEASUREMENT_LOCATION_TYPE_TIME                                            0
#define RFMXSPECAN_VAL_PAVT_MEASUREMENT_LOCATION_TYPE_TRIGGER                                         1

// Values for RFMXSPECAN_ATTR_PAVT_MEASUREMENT_INTERVAL_MODE
#define RFMXSPECAN_VAL_PAVT_MEASUREMENT_INTERVAL_MODE_UNIFORM                                         0
#define RFMXSPECAN_VAL_PAVT_MEASUREMENT_INTERVAL_MODE_VARIABLE                                        1

// Values for RFMXSPECAN_ATTR_PAVT_SEGMENT_TYPE
#define RFMXSPECAN_VAL_PAVT_SEGMENT_TYPE_PHASE_AND_AMPLITUDE                                          0
#define RFMXSPECAN_VAL_PAVT_SEGMENT_TYPE_AMPLITUDE                                                    1
#define RFMXSPECAN_VAL_PAVT_SEGMENT_TYPE_FREQUENCY_ERROR_MEASUREMENT                                  2

// Values for RFMXSPECAN_ATTR_PAVT_PHASE_UNWRAP_ENABLED
#define RFMXSPECAN_VAL_PAVT_PHASE_UNWRAP_ENABLED_FALSE                                                0
#define RFMXSPECAN_VAL_PAVT_PHASE_UNWRAP_ENABLED_TRUE                                                 1

// Values for RFMXSPECAN_ATTR_PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED
#define RFMXSPECAN_VAL_PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED_FALSE                                 0
#define RFMXSPECAN_VAL_PAVT_FREQUENCY_OFFSET_CORRECTION_ENABLED_TRUE                                  1

// Values for RFMXSPECAN_ATTR_PAVT_FREQUENCY_TRACKING_ENABLED
#define RFMXSPECAN_VAL_PAVT_FREQUENCY_TRACKING_ENABLED_FALSE                                          0
#define RFMXSPECAN_VAL_PAVT_FREQUENCY_TRACKING_ENABLED_TRUE                                           1

// Values for RFMXSPECAN_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXSPECAN_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXSPECAN_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXSPECAN_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXSPECAN_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXSPECAN_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXSPECAN_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for AmpmReferenceWaveformIdleDurationPresent
#define RFMXSPECAN_VAL_AMPM_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT_FALSE                            0
#define RFMXSPECAN_VAL_AMPM_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT_TRUE                             1

// Values for DpdReferenceWaveformIdleDurationPresent
#define RFMXSPECAN_VAL_DPD_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT_FALSE                             0
#define RFMXSPECAN_VAL_DPD_REFERENCE_WAVEFORM_IDLE_DURATION_PRESENT_TRUE                              1

// Values for MarkerNextPeak
#define RFMXSPECAN_VAL_MARKER_NEXT_PEAK_NEXT_HIGHEST                                                  0
#define RFMXSPECAN_VAL_MARKER_NEXT_PEAK_NEXT_LEFT                                                     1
#define RFMXSPECAN_VAL_MARKER_NEXT_PEAK_NEXT_RIGHT                                                    2

// Values for MeasurementTypes
#define RFMXSPECAN_VAL_ACP                                                                            1<<0
#define RFMXSPECAN_VAL_CCDF                                                                           1<<1
#define RFMXSPECAN_VAL_CHP                                                                            1<<2
#define RFMXSPECAN_VAL_FCNT                                                                           1<<3
#define RFMXSPECAN_VAL_HARMONICS                                                                      1<<4
#define RFMXSPECAN_VAL_OBW                                                                            1<<5
#define RFMXSPECAN_VAL_SEM                                                                            1<<6
#define RFMXSPECAN_VAL_SPECTRUM                                                                       1<<7
#define RFMXSPECAN_VAL_SPUR                                                                           1<<8
#define RFMXSPECAN_VAL_TXP                                                                            1<<9
#define RFMXSPECAN_VAL_AMPM                                                                           1<<10
#define RFMXSPECAN_VAL_DPD                                                                            1<<11
#define RFMXSPECAN_VAL_IQ                                                                             1<<12
#define RFMXSPECAN_VAL_IM                                                                             1<<13
#define RFMXSPECAN_VAL_NF                                                                             1<<14
#define RFMXSPECAN_VAL_PHASENOISE                                                                     1<<15
#define RFMXSPECAN_VAL_PAVT                                                                           1<<16
#define RFMXSPECAN_VAL_IDPD                                                                           1<<17
#define RFMXSPECAN_VAL_POWERLIST                                                                      1<<18

// Values for SpectrumNoiseCalibrationDataValid
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_DATA_VALID_FALSE                                    0
#define RFMXSPECAN_VAL_SPECTRUM_NOISE_CALIBRATION_DATA_VALID_TRUE                                     1

// Values for ChpNoiseCalibrationDataValid
#define RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_DATA_VALID_FALSE                                         0
#define RFMXSPECAN_VAL_CHP_NOISE_CALIBRATION_DATA_VALID_TRUE                                          1

// Values for AcpNoiseCalibrationDataValid
#define RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_DATA_VALID_FALSE                                         0
#define RFMXSPECAN_VAL_ACP_NOISE_CALIBRATION_DATA_VALID_TRUE                                          1

// Values for NFCalibrationDataValid
#define RFMXSPECAN_VAL_NF_CALIBRATION_DATA_VALID_FALSE                                                0
#define RFMXSPECAN_VAL_NF_CALIBRATION_DATA_VALID_TRUE                                                 1

// Values for DpdApplyDpdIdleDurationPresent
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_IDLE_DURATION_PRESENT_FALSE                                      0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_IDLE_DURATION_PRESENT_TRUE                                       1

// Values for MarkerPeakExcursionEnabled
#define RFMXSPECAN_VAL_MARKER_PEAK_EXCURSION_ENABLED_FALSE                                            0
#define RFMXSPECAN_VAL_MARKER_PEAK_EXCURSION_ENABLED_TRUE                                             1

// Values for MarkerType
#define RFMXSPECAN_VAL_MARKER_TYPE_OFF                                                                0
#define RFMXSPECAN_VAL_MARKER_TYPE_NORMAL                                                             1
#define RFMXSPECAN_VAL_MARKER_TYPE_DELTA                                                              3
#define RFMXSPECAN_VAL_MARKER_TYPE_FIXED                                                              4

// Values for MarkerTrace
#define RFMXSPECAN_VAL_MARKER_TRACE_ACP_SPECTRUM                                                      0
#define RFMXSPECAN_VAL_MARKER_TRACE_CCDF_GAUSSIAN_PROBABILITIES_TRACE                                 1
#define RFMXSPECAN_VAL_MARKER_TRACE_CCDF_PROBABILITIES_TRACE                                          2
#define RFMXSPECAN_VAL_MARKER_TRACE_CHP_SPECTRUM                                                      3
#define RFMXSPECAN_VAL_MARKER_TRACE_FCNT_POWER_TRACE                                                  4
#define RFMXSPECAN_VAL_MARKER_TRACE_OBW_SPECTRUM                                                      5
#define RFMXSPECAN_VAL_MARKER_TRACE_SEM_SPECTRUM                                                      6
#define RFMXSPECAN_VAL_MARKER_TRACE_SPECTRUM                                                          7
#define RFMXSPECAN_VAL_MARKER_TRACE_TXP_POWER_TRACE                                                   8

// Values for MarkerThresholdEnabled
#define RFMXSPECAN_VAL_MARKER_THRESHOLD_ENABLED_FALSE                                                 0
#define RFMXSPECAN_VAL_MARKER_THRESHOLD_ENABLED_TRUE                                                  1

// Values for Boolean
#define RFMXSPECAN_VAL_FALSE                                                                          0
#define RFMXSPECAN_VAL_TRUE                                                                           1

// Values for RFAttenuationAuto
#define RFMXSPECAN_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXSPECAN_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXSPECAN_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXSPECAN_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

// Values for RFMXSPECAN_ATTR_MARKER_FUNCTION_TYPE
#define RFMXSPECAN_VAL_MARKER_FUNCTION_TYPE_OFF                                                       0
#define RFMXSPECAN_VAL_MARKER_FUNCTION_TYPE_BAND_POWER                                                1

// Values for FrequencyReferenceSource
#define RFMXSPECAN_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXSPECAN_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXSPECAN_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXSPECAN_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for NFDutInputLossS2pSParameterOrientation
#define RFMXSPECAN_VAL_NF_DUT_INPUT_LOSS_S2P_S_PARAMETER_ORIENTATION_PORT1_TOWARDS_DUT                0
#define RFMXSPECAN_VAL_NF_DUT_INPUT_LOSS_S2P_S_PARAMETER_ORIENTATION_PORT2_TOWARDS_DUT                1

// Values for NFDutOutputLossS2pSParameterOrientation
#define RFMXSPECAN_VAL_NF_DUT_OUTPUT_LOSS_S2P_S_PARAMETER_ORIENTATION_PORT1_TOWARDS_DUT               0
#define RFMXSPECAN_VAL_NF_DUT_OUTPUT_LOSS_S2P_S_PARAMETER_ORIENTATION_PORT2_TOWARDS_DUT               1

// Values for NFCalibrationLossS2pSParameterOrientation
#define RFMXSPECAN_VAL_NF_CALIBRATION_LOSS_S2P_S_PARAMETER_ORIENTATION_PORT1_TOWARDS_DUT              0
#define RFMXSPECAN_VAL_NF_CALIBRATION_LOSS_S2P_S_PARAMETER_ORIENTATION_PORT2_TOWARDS_DUT              1

// Values for NFColdSourceDutS2pSParameterOrientation
#define RFMXSPECAN_VAL_NF_COLD_SOURCE_DUT_S2P_S_PARAMETER_ORIENTATION_PORT1_TOWARDS_DUT               0
#define RFMXSPECAN_VAL_NF_COLD_SOURCE_DUT_S2P_S_PARAMETER_ORIENTATION_PORT2_TOWARDS_DUT               1

/* ---------------- RFmxSpecAn APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxSpecAn_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxSpecAn_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxSpecAn_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxSpecAn_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxSpecAn_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxSpecAn_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxSpecAn_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxSpecAn_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxSpecAn_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxSpecAn_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxSpecAn_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_BuildListString(
   char listName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_BuildListStepString(
   char listName[],
   char resultName[],
   int32 stepNumber,
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_BuildCarrierString2(
   char selectorString[],
   int32 carrierNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildHarmonicString2(
   char selectorString[],
   int32 harmonicNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildIntermodString(
   char selectorString[],
   int32 intermodNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildMarkerString2(
   char selectorString[],
   int32 markerNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildOffsetString2(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildRangeString2(
   char selectorString[],
   int32 rangeNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildSegmentString(
   char selectorString[],
   int32 segmentNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildSpurString2(
   char selectorString[],
   int32 spurNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxSpecAn_BuildCarrierString(
   char signalName[],
   char resultName[],
   int32 carrierNumber,
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_BuildHarmonicString(
   char signalName[],
   char resultName[],
   int32 harmonicNumber,
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_BuildMarkerString(
   char signalName[],
   char resultName[],
   int32 markerNumber,
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_BuildOffsetString(
   char signalName[],
   char resultName[],
   int32 offsetNumber,
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_BuildRangeString(
   char signalName[],
   char resultName[],
   int32 rangeNumber,
   int32 selectorStringLength,
   char selectorString[]
);


int32 __stdcall RFmxSpecAn_BuildRangeSpurString(
   char signalName[],
   char resultName[],
   int32 rangeNumber,
   int32 spurNumber,
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxSpecAn_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_NFCfgFrequencyList_StartStopPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startFrequency,
   float64 stopFrequency,
   int32 numberOfPoints
);

int32 __stdcall RFmxSpecAn_NFCfgFrequencyList_StartStopStep(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startFrequency,
   float64 stopFrequency,
   float64 stepSize
);

int32 __stdcall RFmxSpecAn_NFRecommendReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 DUTMaxGain,
   float64 DUTMaxNoiseFigure,
   float64* referenceLevel
);

int32 __stdcall RFmxSpecAn_NFValidateCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* calibrationDataValid
);

int32 __stdcall RFmxSpecAn_SpectrumValidateNoiseCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* noiseCalibrationDataValid
);

int32 __stdcall RFmxSpecAn_AMPMCfgReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize,
   int32 idleDurationPresent,
   int32 signalType
);

int32 __stdcall RFmxSpecAn_AMPMCfgReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 referenceWaveformI[],
   float32 referenceWaveformQ[],
   int32 arraySize,
   int32 idleDurationPresent,
   int32 signalType
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDUserDPDPolynomial(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexSingle DPDPolynomial[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDUserDPDPolynomialSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 DPDPolynomialI[],
   float32 DPDPolynomialQ[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDUserLookupTable(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 LUTInputPowers[],
   NIComplexSingle LUTComplexGains[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDUserLookupTableSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 LUTInputPowers[],
   float32 LUTComplexGainsI[],
   float32 LUTComplexGainsQ[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDCfgPreviousDPDPolynomial(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexSingle previousDPDPolynomial[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDCfgPreviousDPDPolynomialSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 previousDPDPolynomialI[],
   float32 previousDPDPolynomialQ[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDCfgReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize,
   int32 idleDurationPresent,
   int32 signalType
);

int32 __stdcall RFmxSpecAn_DPDCfgReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 referenceWaveformI[],
   float32 referenceWaveformQ[],
   int32 arraySize,
   int32 idleDurationPresent,
   int32 signalType
);

int32 __stdcall RFmxSpecAn_DPDCfgExtractModelTargetWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle targetWaveform[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDCfgExtractModelTargetWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 targetWaveformI[],
   float32 targetWaveformQ[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_ACPValidateNoiseCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* noiseCalibrationDataValid
);

int32 __stdcall RFmxSpecAn_CHPValidateNoiseCalibrationData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* noiseCalibrationDataValid
);

int32 __stdcall RFmxSpecAn_MarkerCfgNumberOfMarkers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfMarkers
);

int32 __stdcall RFmxSpecAn_MarkerCfgPeakExcursion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 peakExcursionEnabled,
   float64 peakExcursion
);

int32 __stdcall RFmxSpecAn_MarkerCfgReferenceMarker(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 referenceMarker
);

int32 __stdcall RFmxSpecAn_MarkerCfgThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 thresholdEnabled,
   float64 threshold
);

int32 __stdcall RFmxSpecAn_MarkerCfgTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 trace
);

int32 __stdcall RFmxSpecAn_MarkerCfgType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 markerType
);

int32 __stdcall RFmxSpecAn_MarkerCfgXLocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 markerXLocation
);

int32 __stdcall RFmxSpecAn_MarkerCfgYLocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 markerYLocation
);

int32 __stdcall RFmxSpecAn_MarkerCfgFunctionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 functionType
);

int32 __stdcall RFmxSpecAn_MarkerCfgBandSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 span
);

int32 __stdcall RFmxSpecAn_PAVTCfgSegmentStartTimeStep(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSegments,
   float64 segment0StartTime,
   float64 segmentInterval
);

int32 __stdcall RFmxSpecAn_IDPDCfgReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize,
   int32 idleDurationPresent,
   int32 signalType
);

int32 __stdcall RFmxSpecAn_IDPDCfgReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 referenceWaveformI[],
   float32 referenceWaveformQ[],
   int32 arraySize,
   int32 idleDurationPresent,
   int32 signalType
);

int32 __stdcall RFmxSpecAn_IDPDCfgPredistortedWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle predistortedWaveform[],
   int32 arraySize,
   float64 targetGain
);

int32 __stdcall RFmxSpecAn_IDPDCfgPredistortedWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 predistortedWaveformI[],
   float32 predistortedWaveformQ[],
   int32 arraySize,
   float64 targetGain
);

int32 __stdcall RFmxSpecAn_IDPDCfgEqualizerCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle equalizerCoefficients[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_IDPDCfgEqualizerCoefficientsSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 equalizerCoefficientsI[],
   float32 equalizerCoefficientsQ[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxSpecAn_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxSpecAn_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxSpecAn_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 bandwidth,
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxSpecAn_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxSpecAn_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_ClearNoiseCalibrationDatabase(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxSpecAn_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_CreateList(
   niRFmxInstrHandle instrumentHandle,
   char listName[]
);

int32 __stdcall RFmxSpecAn_CreateListStep(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* createdStepIndex
);

int32 __stdcall RFmxSpecAn_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxSpecAn_DeleteList(
   niRFmxInstrHandle instrumentHandle,
   char listName[]
);

int32 __stdcall RFmxSpecAn_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxSpecAn_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxSpecAn_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxSpecAn_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxSpecAn_IMCfgAutoIntermodsSetup(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoIntermodsSetupEnabled,
   int32 maximumIntermodOrder
);

int32 __stdcall RFmxSpecAn_IMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_IMCfgFFT(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindow,
   float64 FFTPadding
);

int32 __stdcall RFmxSpecAn_IMCfgFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 frequencyDefinition
);

int32 __stdcall RFmxSpecAn_IMCfgFundamentalTones(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 lowerToneFrequency,
   float64 upperToneFrequency
);

int32 __stdcall RFmxSpecAn_IMCfgIntermod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 intermodOrder,
   float64 lowerIntermodFrequency,
   float64 upperIntermodFrequency,
   int32 intermodSide,
   int32 intermodEnabled
);

int32 __stdcall RFmxSpecAn_IMCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxSpecAn_IMCfgNumberOfIntermods(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfIntermods
);

int32 __stdcall RFmxSpecAn_IMCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_IMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxSpecAn_IMCfgIntermodArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 intermodOrder[],
   float64 lowerIntermodFrequency[],
   float64 upperIntermodFrequency[],
   int32 intermodSide[],
   int32 intermodEnabled[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_SpurCfgFFTWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindow
);

int32 __stdcall RFmxSpecAn_SpurCfgNumberOfRanges(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfRanges
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeAbsoluteLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 absoluteLimitMode,
   float64 absoluteLimitStart,
   float64 absoluteLimitStop
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeDetector(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 detectorType,
   int32 detectorPoints
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startFrequency,
   float64 stopFrequency,
   int32 rangeEnabled
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeNumberOfSpursToReport(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSpursToReport
);

int32 __stdcall RFmxSpecAn_SpurCfgRangePeakCriteria(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 threshold,
   float64 excursion
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeAttenuation
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeVBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 VBWAuto,
   float64 VBW,
   float64 VBWToRBWRatio
);

int32 __stdcall RFmxSpecAn_SpurCfgTraceRangeIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 traceRangeIndex
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeAbsoluteLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 absoluteLimitMode[],
   float64 absoluteLimitStart[],
   float64 absoluteLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeDetectorArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 detectorType[],
   int32 detectorPoints[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startFrequency[],
   float64 stopFrequency[],
   int32 rangeEnabled[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeNumberOfSpursToReportArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSpursToReport[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangePeakCriteriaArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 threshold[],
   float64 excursion[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeRBWArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto[],
   float64 RBW[],
   int32 RBWFilterType[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeRelativeAttenuationArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeAttenuation[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeSweepTimeArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto[],
   float64 sweepTimeInterval[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SpurCfgRangeVBWFilterArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 VBWAuto[],
   float64 VBW[],
   float64 VBWToRBWRatio[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_ACPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_ACPCfgCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 integrationBandwidth
);

int32 __stdcall RFmxSpecAn_ACPCfgCarrierMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 carrierMode
);

int32 __stdcall RFmxSpecAn_ACPCfgCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierFrequency
);

int32 __stdcall RFmxSpecAn_ACPCfgCarrierRRCFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RRCFilterEnabled,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_ACPCfgFFT(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindow,
   float64 FFTPadding
);

int32 __stdcall RFmxSpecAn_ACPCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxSpecAn_ACPCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxSpecAn_ACPCfgNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCarriers
);

int32 __stdcall RFmxSpecAn_ACPCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetFrequencyDefinition
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 integrationBandwidth
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetPowerReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetReferenceCarrier,
   int32 offsetReferenceSpecific
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeAttenuation
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetRRCFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RRCFilterEnabled,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_ACPCfgOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetFrequency,
   int32 offsetSideband,
   int32 offsetEnabled
);

int32 __stdcall RFmxSpecAn_ACPCfgPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnits
);

int32 __stdcall RFmxSpecAn_ACPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_ACPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxSpecAn_ACPCfgDetector(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 detectorType,
   int32 detectorPoints
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetFrequency[],
   int32 offsetSideband[],
   int32 offsetEnabled[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetIntegrationBandwidthArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 integrationBandwidth[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetPowerReferenceArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetPowerReferenceCarrier[],
   int32 offsetPowerReferenceSpecific[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetRelativeAttenuationArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeAttenuation[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_ACPCfgOffsetRRCFilterArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RRCFilterEnabled[],
   float64 RRCAlpha[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_HarmCfgAutoHarmonics(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoHarmonicsSetupEnabled
);

int32 __stdcall RFmxSpecAn_HarmCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_HarmCfgFundamentalMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxSpecAn_HarmCfgFundamentalRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 RBW,
   int32 RBWFilterType,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_HarmCfgHarmonic(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 harmonicOrder,
   float64 harmonicBandwidth,
   int32 harmonicEnabled,
   float64 harmonicMeasurementInterval
);

int32 __stdcall RFmxSpecAn_HarmCfgNumberOfHarmonics(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfHarmonics
);

int32 __stdcall RFmxSpecAn_HarmCfgHarmonicArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 harmonicOrder[],
   float64 harmonicBandwidth[],
   int32 harmonicEnabled[],
   float64 harmonicMeasurementInterval[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SEMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_SEMCfgCarrierChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierChannelBandwidth
);

int32 __stdcall RFmxSpecAn_SEMCfgCarrierEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 carrierEnabled
);

int32 __stdcall RFmxSpecAn_SEMCfgCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 integrationBandwidth
);

int32 __stdcall RFmxSpecAn_SEMCfgCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierFrequency
);

int32 __stdcall RFmxSpecAn_SEMCfgCarrierRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_SEMCfgCarrierRRCFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RRCFilterEnabled,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_SEMCfgFFT(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindow,
   float64 FFTPadding
);

int32 __stdcall RFmxSpecAn_SEMCfgNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCarriers
);

int32 __stdcall RFmxSpecAn_SEMCfgNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfOffsets
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetAbsoluteLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 absoluteLimitMode,
   float64 absoluteLimitStart,
   float64 absoluteLimitStop
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 bandwidthIntegral
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 offsetFrequencyDefinition
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetStartFrequency,
   float64 offsetStopFrequency,
   int32 offsetEnabled,
   int32 offsetSideband
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 limitFailMask
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeAttenuation
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetRelativeLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 relativeLimitMode,
   float64 relativeLimitStart,
   float64 relativeLimitStop
);

int32 __stdcall RFmxSpecAn_SEMCfgPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnits
);

int32 __stdcall RFmxSpecAn_SEMCfgReferenceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 referenceType
);

int32 __stdcall RFmxSpecAn_SEMCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetAbsoluteLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 absoluteLimitMode[],
   float64 absoluteLimitStart[],
   float64 absoluteLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetFrequencyArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetStartFrequency[],
   float64 offsetStopFrequency[],
   int32 offsetEnabled[],
   int32 offsetSideband[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetRBWFilterArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto[],
   float64 RBW[],
   int32 RBWFilterType[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetRelativeAttenuationArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 relativeAttenuation[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_SEMCfgOffsetRelativeLimitArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 relativeLimitMode[],
   float64 relativeLimitStart[],
   float64 relativeLimitStop[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgAutoRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startFrequency,
   float64 stopFrequency,
   float64 RBWPercentage
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgAveragingMultiplier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingMultiplier
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgCancellation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 cancellationEnabled,
   float64 cancellationThreshold,
   float32 frequency[],
   float32 referencePhaseNoise[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgIntegratedNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 integratedNoiseRangeDefinition,
   float64 integratedNoiseStartFrequency[],
   float64 integratedNoiseStopFrequency[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgNumberOfRanges(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfRanges
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgRangeDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 rangeDefinition
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgSmoothing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 smoothingType,
   float64 smoothingPercentage
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgSpotNoiseFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 frequencyList[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgSpurRemoval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spurRemovalEnabled,
   float64 peakExcursion
);

int32 __stdcall RFmxSpecAn_PhaseNoiseCfgRangeArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 rangeStartFrequency[],
   float64 rangeStopFrequency[],
   float64 rangeRBWPercentage[],
   int32 rangeAveragingCount[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_PAVTCfgMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementBandwidth
);

int32 __stdcall RFmxSpecAn_PAVTCfgMeasurementIntervalMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementIntervalMode
);

int32 __stdcall RFmxSpecAn_PAVTCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementOffset,
   float64 measurementLength
);

int32 __stdcall RFmxSpecAn_PAVTCfgMeasurementLocationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementLocationType
);

int32 __stdcall RFmxSpecAn_PAVTCfgNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSegments
);

int32 __stdcall RFmxSpecAn_PAVTCfgSegmentMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 segmentMeasurementOffset,
   float64 segmentMeasurementLength
);

int32 __stdcall RFmxSpecAn_PAVTCfgSegmentType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 segmentType
);

int32 __stdcall RFmxSpecAn_PAVTCfgSegmentMeasurementIntervalArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 segmentMeasurementOffset[],
   float64 segmentMeasurementLength[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_PAVTCfgSegmentStartTimeList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 segmentStartTime[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_PAVTCfgSegmentTypeArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 segmentType[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_NFCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxSpecAn_NFCfgCalibrationLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 calibrationLossCompensationEnabled,
   float64 calibrationLossFrequency[],
   float64 calibrationLoss[],
   float64 calibrationLossTemperature,
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgColdSourceDUTSParameters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 DUTSParametersFrequency[],
   float64 DUTS21[],
   float64 DUTS12[],
   float64 DUTS11[],
   float64 DUTS22[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgColdSourceInputTermination(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 terminationVSWR[],
   float64 terminationVSWRFrequency[],
   float64 terminationTemperature,
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgColdSourceMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 coldSourceMode
);

int32 __stdcall RFmxSpecAn_NFCfgDUTInputLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 DUTInputLossCompensationEnabled,
   float64 DUTInputLossFrequency[],
   float64 DUTInputLoss[],
   float64 DUTInputLossTemperature,
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgDUTOutputLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 DUTOutputLossCompensationEnabled,
   float64 DUTOutputLossFrequency[],
   float64 DUTOutputLoss[],
   float64 DUTOutputLossTemperature,
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 frequencyList[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementBandwidth
);

int32 __stdcall RFmxSpecAn_NFCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxSpecAn_NFCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxSpecAn_NFCfgYFactorMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 yFactorMode
);

int32 __stdcall RFmxSpecAn_NFCfgYFactorNoiseSourceENR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 ENRFrequency[],
   float64 ENR[],
   float64 coldTemperature,
   float64 offTemperature,
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgYFactorNoiseSourceLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseSourceLossCompensationEnabled,
   float64 noiseSourceLossFrequency[],
   float64 noiseSourceLoss[],
   float64 noiseSourceLossTemperature,
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFCfgYFactorNoiseSourceSettlingTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 settlingTime
);

int32 __stdcall RFmxSpecAn_FCntCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_FCntCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxSpecAn_FCntCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 RBW,
   int32 RBWFilterType,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_FCntCfgThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 thresholdEnabled,
   float64 thresholdLevel,
   int32 thresholdType
);

int32 __stdcall RFmxSpecAn_SpectrumCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_SpectrumCfgDetector(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 detectorType,
   int32 detectorPoints
);

int32 __stdcall RFmxSpecAn_SpectrumCfgFFT(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindow,
   float64 FFTPadding
);

int32 __stdcall RFmxSpecAn_SpectrumCfgNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 noiseCompensationEnabled
);

int32 __stdcall RFmxSpecAn_SpectrumCfgPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 spectrumPowerUnits
);

int32 __stdcall RFmxSpecAn_SpectrumCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_SpectrumCfgSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 span
);

int32 __stdcall RFmxSpecAn_SpectrumCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxSpecAn_SpectrumCfgVBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 VBWAuto,
   float64 VBW,
   float64 VBWToRBWRatio
);

int32 __stdcall RFmxSpecAn_SpectrumCfgMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 measurementMethod
);

int32 __stdcall RFmxSpecAn_AMPMCfgAMToAMCurveFit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 AMToAMCurveFitOrder,
   int32 AMToAMCurveFitType
);

int32 __stdcall RFmxSpecAn_AMPMCfgAMToPMCurveFit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 AMToPMCurveFitOrder,
   int32 AMToPMCurveFitType
);

int32 __stdcall RFmxSpecAn_AMPMCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxSpecAn_AMPMCfgCompressionPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 compressionPointEnabled,
   float64 compressionLevel[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_AMPMCfgDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 DUTAverageInputPower
);

int32 __stdcall RFmxSpecAn_AMPMCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxSpecAn_AMPMCfgMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sampleRateMode,
   float64 sampleRate
);

int32 __stdcall RFmxSpecAn_AMPMCfgReferencePowerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 referencePowerType
);

int32 __stdcall RFmxSpecAn_AMPMCfgSynchronizationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMethod
);

int32 __stdcall RFmxSpecAn_AMPMCfgThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 thresholdEnabled,
   float64 thresholdLevel,
   int32 thresholdType
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDConfigurationInput(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 configurationInput
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDLookupTableCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 LUTCorrectionType
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDMemoryModelCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 memoryModelCorrectionType
);

int32 __stdcall RFmxSpecAn_DPDCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount
);

int32 __stdcall RFmxSpecAn_DPDCfgDPDModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 DPDModel
);

int32 __stdcall RFmxSpecAn_DPDCfgDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 DUTAverageInputPower
);

int32 __stdcall RFmxSpecAn_DPDCfgGeneralizedMemoryPolynomialCrossTerms(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 memoryPolynomialLeadOrder,
   int32 memoryPolynomialLagOrder,
   int32 memoryPolynomialLeadMemoryDepth,
   int32 memoryPolynomialLagMemoryDepth,
   int32 memoryPolynomialMaximumLead,
   int32 memoryPolynomialMaximumLag
);

int32 __stdcall RFmxSpecAn_DPDCfgIterativeDPDEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 iterativeDPDEnabled
);

int32 __stdcall RFmxSpecAn_DPDCfgLookupTableAMToAMCurveFit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 AMToAMCurveFitOrder,
   int32 AMToAMCurveFitType
);

int32 __stdcall RFmxSpecAn_DPDCfgLookupTableAMToPMCurveFit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 AMToPMCurveFitOrder,
   int32 AMToPMCurveFitType
);

int32 __stdcall RFmxSpecAn_DPDCfgLookupTableStepSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 stepSize
);

int32 __stdcall RFmxSpecAn_DPDCfgLookupTableThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 thresholdEnabled,
   float64 thresholdLevel,
   int32 thresholdType
);

int32 __stdcall RFmxSpecAn_DPDCfgLookupTableType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 lookupTableType
);

int32 __stdcall RFmxSpecAn_DPDCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxSpecAn_DPDCfgMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sampleRateMode,
   float64 sampleRate
);

int32 __stdcall RFmxSpecAn_DPDCfgMemoryPolynomial(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 memoryPolynomialOrder,
   int32 memoryPolynomialMemoryDepth
);

int32 __stdcall RFmxSpecAn_DPDCfgSynchronizationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 synchronizationMethod
);

int32 __stdcall RFmxSpecAn_CCDFCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxSpecAn_CCDFCfgNumberOfRecords(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfRecords
);

int32 __stdcall RFmxSpecAn_CCDFCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 RBW,
   int32 RBWFilterType,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_CCDFCfgThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 thresholdEnabled,
   float64 thresholdLevel,
   int32 thresholdType
);

int32 __stdcall RFmxSpecAn_CHPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_CHPCfgCarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 carrierFrequency
);

int32 __stdcall RFmxSpecAn_CHPCfgFFT(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindow,
   float64 FFTPadding
);

int32 __stdcall RFmxSpecAn_CHPCfgIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 integrationBandwidth
);

int32 __stdcall RFmxSpecAn_CHPCfgNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfCarriers
);

int32 __stdcall RFmxSpecAn_CHPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_CHPCfgRRCFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RRCFilterEnabled,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_CHPCfgSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 span
);

int32 __stdcall RFmxSpecAn_CHPCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxSpecAn_CHPCfgDetector(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 detectorType,
   int32 detectorPoints
);

int32 __stdcall RFmxSpecAn_OBWCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_OBWCfgBandwidthPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 bandwidthPercentage
);

int32 __stdcall RFmxSpecAn_OBWCfgFFT(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 FFTWindow,
   float64 FFTPadding
);

int32 __stdcall RFmxSpecAn_OBWCfgPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 powerUnits
);

int32 __stdcall RFmxSpecAn_OBWCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 RBWAuto,
   float64 RBW,
   int32 RBWFilterType
);

int32 __stdcall RFmxSpecAn_OBWCfgSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 span
);

int32 __stdcall RFmxSpecAn_OBWCfgSweepTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sweepTimeAuto,
   float64 sweepTimeInterval
);

int32 __stdcall RFmxSpecAn_TXPCfgAveraging(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 averagingEnabled,
   int32 averagingCount,
   int32 averagingType
);

int32 __stdcall RFmxSpecAn_TXPCfgMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementInterval
);

int32 __stdcall RFmxSpecAn_TXPCfgRBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 RBW,
   int32 RBWFilterType,
   float64 RRCAlpha
);

int32 __stdcall RFmxSpecAn_TXPCfgThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 thresholdEnabled,
   float64 thresholdLevel,
   int32 thresholdType
);

int32 __stdcall RFmxSpecAn_TXPCfgVBWFilter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 VBWAuto,
   float64 VBW,
   float64 VBWToRBWRatio
);

int32 __stdcall RFmxSpecAn_IQCfgAcquisition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 sampleRate,
   int32 numberOfRecords,
   float64 acquisitionTime,
   float64 pretriggerTime
);

int32 __stdcall RFmxSpecAn_IQCfgBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 bandwidthAuto,
   float64 bandwidth
);

int32 __stdcall RFmxSpecAn_PowerListCfgRBWFilterArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 RBW[],
   int32 RBWFilterType[],
   float64 RRCAlpha[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxSpecAn_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxSpecAn_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxSpecAn_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxSpecAn_NFGetCalibrationSetupId(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFSetCalibrationSetupId(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_HarmFetchHarmonicMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 averageRelativePower[],
   float64 averageAbsolutePower[],
   float64 RBW[],
   float64 frequency[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_IQFetchData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 recordToFetch,
   int64 samplesToRead,
   float64* t0,
   float64* dt,
   NIComplexSingle data[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IQFetchDataSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 recordToFetch,
   int64 samplesToRead,
   float64* t0,
   float64* dt,
   float32 dataI[],
   float32 dataQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_MarkerNextPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 nextPeak,
   int32 *nextPeakFound
);

int32 __stdcall RFmxSpecAn_MarkerPeakSearch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *numberOfPeaks
);

int32 __stdcall RFmxSpecAn_NFClearCalibrationDatabase(
   niRFmxInstrHandle instrumentHandle,
   char calibrationSetupID[]
);

int32 __stdcall RFmxSpecAn_NFLoadDUTInputLossFromS2p(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 DUTInputLossCompensationEnabled,
   char DUTInputLossS2pFilePath[],
   int32 DUTInputLossSParameterOrientation,
   float64 DUTInputLossTemperature
);

int32 __stdcall RFmxSpecAn_NFLoadDUTOutputLossFromS2p(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 DUTOutputLossCompensationEnabled,
   char DUTOutputLossS2pFilePath[],
   int32 DUTOutputLossSParameterOrientation,
   float64 DUTOutputLossTemperature
);

int32 __stdcall RFmxSpecAn_NFLoadCalibrationLossFromS2p(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 calibrationLossCompensationEnabled,
   char calibrationLossS2pFilePath[],
   int32 calibrationLossSParameterOrientation,
   float64 calibrationLossTemperature
);

int32 __stdcall RFmxSpecAn_NFLoadColdSourceDUTSParametersFromS2p(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char DUTSParametersS2pFilePath[],
   int32 DUTSParameterOrientation
);

int32 __stdcall RFmxSpecAn_SpectrumCfgFrequencyStartStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startFrequency,
   float64 stopFrequency
);

int32 __stdcall RFmxSpecAn_DPDApplyDigitalPredistortion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0In,
   float64 dxIn,
   NIComplexSingle waveformIn[],
   int32 arraySizeIn,
   int32 idleDurationPresent,
   float64 measurementTimeout,
   float64* x0Out,
   float64* dxOut,
   NIComplexSingle waveformOut[],
   int32 arraySizeOut,
   int32* actualArraySize,
   float64* PAPR,
   float64* powerOffset
);

int32 __stdcall RFmxSpecAn_DPDApplyDigitalPredistortionSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0In,
   float64 dxIn,
   float32 waveformInI[],
   float32 waveformInQ[],
   int32 arraySizeIn,
   int32 idleDurationPresent,
   float64 measurementTimeout,
   float64* x0Out,
   float64* dxOut,
   float32 waveformOutI[],
   float32 waveformOutQ[],
   int32 arraySizeOut,
   int32* actualArraySize,
   float64* PAPR,
   float64* powerOffset
);

int32 __stdcall RFmxSpecAn_DPDApplyPreDPDSignalConditioning(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0In,
   float64 dxIn,
   NIComplexSingle waveformIn[],
   int32 arraySizeIn,
   int32 idleDurationPresent,
   float64* x0Out,
   float64* dxOut,
   NIComplexSingle waveformOut[],
   int32 arraySizeOut,
   int32* actualArraySize,
   float64* PAPR
);

int32 __stdcall RFmxSpecAn_DPDApplyPreDPDSignalConditioningSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0In,
   float64 dxIn,
   float32 waveformInI[],
   float32 waveformInQ[],
   int32 arraySizeIn,
   int32 idleDurationPresent,
   float64* x0Out,
   float64* dxOut,
   float32 waveformOutI[],
   float32 waveformOutQ[],
   int32 arraySizeOut,
   int32* actualArraySize,
   float64* PAPR
);

int32 __stdcall RFmxSpecAn_ACPCfgCarrierAndOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 integrationBandwidth,
   int32 numberOfOffsets,
   float64 channelSpacing
);

int32 __stdcall RFmxSpecAn_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxSpecAn_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxSpecAn_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxSpecAn_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxSpecAn_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxSpecAn_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxSpecAn_IMFetchInterceptPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 intermodOrder[],
   float64 worstCaseOutputInterceptPower[],
   float64 lowerOutputInterceptPower[],
   float64 upperOutputInterceptPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IMFetchIntermodMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 intermodOrder[],
   float64 lowerIntermodAbsolutePower[],
   float64 upperIntermodAbsolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IMFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 spectrumIndex,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IMFetchFundamentalMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerTonePower,
   float64* upperTonePower
);

int32 __stdcall RFmxSpecAn_IMFetchInterceptPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* intermodOrder,
   float64* worstCaseOutputInterceptPower,
   float64* lowerOutputInterceptPower,
   float64* upperOutputInterceptPower
);

int32 __stdcall RFmxSpecAn_IMFetchIntermodMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* intermodOrder,
   float64* lowerIntermodAbsolutePower,
   float64* upperIntermodAbsolutePower
);

int32 __stdcall RFmxSpecAn_NFFetchAnalyzerNoiseFigure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 analyzerNoiseFigure[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_NFFetchColdSourcePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 coldSourcePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_NFFetchDUTNoiseFigureAndGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 DUTNoiseFigure[],
   float64 DUTNoiseTemperature[],
   float64 DUTGain[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_NFFetchYFactorPowers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 hotPower[],
   float64 coldPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_NFFetchYFactors(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 measurementYFactor[],
   float64 calibrationYFactor[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_FCntFetchFrequencyTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 frequencyTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_FCntFetchPhaseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 phaseTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_FCntFetchPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 powerTrace[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_FCntFetchAllanDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* allanDeviation
);

int32 __stdcall RFmxSpecAn_FCntFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageRelativeFrequency,
   float64* averageAbsoluteFrequency,
   float64* meanPhase
);

int32 __stdcall RFmxSpecAn_FCntRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageRelativeFrequency,
   float64* averageAbsoluteFrequency,
   float64* meanPhase
);

int32 __stdcall RFmxSpecAn_SpectrumFetchPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 power[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpectrumFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpectrumRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpectrumFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* peakAmplitude,
   float64* peakFrequency,
   float64* frequencyResolution
);

int32 __stdcall RFmxSpecAn_SpurFetchAllSpurs(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 spurFrequency[],
   float64 spurAmplitude[],
   float64 spurMargin[],
   float64 spurAbsoluteLimit[],
   int32 spurRangeIndex[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpurFetchRangeAbsoluteLimitTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 absoluteLimit[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpurFetchRangeSpectrumTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 rangeSpectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpurFetchRangeStatusArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 rangeStatus[],
   int32 numberOfDetectedSpurs[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpurFetchSpurMeasurementArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 spurFrequency[],
   float64 spurAmplitude[],
   float64 spurAbsoluteLimit[],
   float64 spurMargin[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SpurFetchMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus
);

int32 __stdcall RFmxSpecAn_SpurFetchRangeStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* rangeStatus,
   int32* detectedSpurs
);

int32 __stdcall RFmxSpecAn_SpurFetchSpurMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* spurFrequency,
   float64* spurAmplitude,
   float64* spurMargin,
   float64* spurAbsoluteLimit
);

int32 __stdcall RFmxSpecAn_AMPMFetchAMToAMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 referencePowers[],
   float32 measuredAMToAM[],
   float32 curveFitAMToAM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchAMToPMTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 referencePowers[],
   float32 measuredAMToPM[],
   float32 curveFitAMToPM[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchCompressionPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 inputCompressionPoint[],
   float64 outputCompressionPoint[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchCurveFitCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 AMToAMCoefficients[],
   float32 AMToPMCoefficients[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchProcessedMeanAcquiredWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle processedMeanAcquiredWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchProcessedMeanAcquiredWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 processedMeanAcquiredWaveformI[],
   float32 processedMeanAcquiredWaveformQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchProcessedReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle processedReferenceWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchProcessedReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 processedReferenceWaveformI[],
   float32 processedReferenceWaveformQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchRelativePhaseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 relativePhase[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchRelativePowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 relativePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMFetchCurveFitResidual(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* AMToAMResidual,
   float64* AMToPMResidual
);

int32 __stdcall RFmxSpecAn_AMPMFetchDUTCharacteristics(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanLinearGain,
   float64* onedBCompressionPoint,
   float64* meanRMSEVM
);

int32 __stdcall RFmxSpecAn_AMPMFetchError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* gainErrorRange,
   float64* phaseErrorRange,
   float64* meanPhaseError
);

int32 __stdcall RFmxSpecAn_DPDFetchDPDPolynomial(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle DPDPolynomial[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchDPDPolynomialSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 DPDPolynomialI[],
   float32 DPDPolynomialQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchDVRModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle DVRModel[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchDVRModelSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 DVRModelI[],
   float32 DVRModelQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchLookupTable(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 inputPowers[],
   NIComplexSingle complexGains[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchLookupTableSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 inputPowers[],
   float32 complexGainsI[],
   float32 complexGainsQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchProcessedMeanAcquiredWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle processedMeanAcquiredWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchProcessedMeanAcquiredWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 processedMeanAcquiredWaveformI[],
   float32 processedMeanAcquiredWaveformQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchProcessedReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle processedReferenceWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchProcessedReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 processedReferenceWaveformI[],
   float32 processedReferenceWaveformQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDFetchApplyDPDPreCFRPAPR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* preCFRPAPR
);

int32 __stdcall RFmxSpecAn_DPDFetchAverageGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageGain
);

int32 __stdcall RFmxSpecAn_DPDFetchNMSE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* NMSE
);

int32 __stdcall RFmxSpecAn_ACPFetchAbsolutePowersTrace(
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

int32 __stdcall RFmxSpecAn_ACPFetchOffsetMeasurementArray(
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

int32 __stdcall RFmxSpecAn_ACPFetchRelativePowersTrace(
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

int32 __stdcall RFmxSpecAn_ACPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_ACPFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* totalRelativePower,
   float64* carrierOffset,
   float64* integrationBandwidth
);

int32 __stdcall RFmxSpecAn_ACPFetchFrequencyResolution(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* frequencyResolution
);

int32 __stdcall RFmxSpecAn_ACPFetchOffsetMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* lowerRelativePower,
   float64* upperRelativePower,
   float64* lowerAbsolutePower,
   float64* upperAbsolutePower
);

int32 __stdcall RFmxSpecAn_ACPFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxSpecAn_ACPRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierAbsolutePower,
   float64* offsetCh0LowerRelativePower,
   float64* offsetCh0UpperRelativePower,
   float64* offsetCh1LowerRelativePower,
   float64* offsetCh1UpperRelativePower
);

int32 __stdcall RFmxSpecAn_CCDFFetchGaussianProbabilitiesTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 gaussianProbabilities[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_CCDFFetchProbabilitiesTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 probabilities[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_CCDFFetchBasicPowerProbabilities(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* tenPercentPower,
   float64* onePercentPower,
   float64* oneTenthPercentPower,
   float64* oneHundredthPercentPower,
   float64* oneThousandthPercentPower,
   float64* oneTenThousandthPercentPower
);

int32 __stdcall RFmxSpecAn_CCDFFetchPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanPower,
   float64* meanPowerPercentile,
   float64* peakPower,
   int32* measuredSamplesCount
);

int32 __stdcall RFmxSpecAn_CCDFRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanPower,
   float64* meanPowerPercentile,
   float64* peakPower,
   int32* measuredSamplesCount
);

int32 __stdcall RFmxSpecAn_CHPFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_CHPFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxSpecAn_CHPRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* PSD
);

int32 __stdcall RFmxSpecAn_CHPFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* PSD,
   float64* relativePower
);

int32 __stdcall RFmxSpecAn_HarmFetchHarmonicPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 power[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_HarmFetchHarmonicMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageRelativePower,
   float64* averageAbsolutePower,
   float64* RBW,
   float64* frequency
);

int32 __stdcall RFmxSpecAn_HarmFetchTHD(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalHarmonicDistortion,
   float64* averageFundamentalPower,
   float64* fundamentalFrequency
);

int32 __stdcall RFmxSpecAn_HarmRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalHarmonicDistortion,
   float64* averageFundamentalPower
);

int32 __stdcall RFmxSpecAn_SEMFetchAbsoluteMaskTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 absoluteMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SEMFetchLowerOffsetMarginArray(
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

int32 __stdcall RFmxSpecAn_SEMFetchLowerOffsetPowerArray(
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

int32 __stdcall RFmxSpecAn_SEMFetchRelativeMaskTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 relativeMask[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SEMFetchSpectrum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_SEMFetchUpperOffsetMarginArray(
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

int32 __stdcall RFmxSpecAn_SEMFetchUpperOffsetPowerArray(
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

int32 __stdcall RFmxSpecAn_SEMFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* absolutePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* totalRelativePower
);

int32 __stdcall RFmxSpecAn_SEMFetchCompositeMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* compositeMeasurementStatus
);

int32 __stdcall RFmxSpecAn_SEMFetchFrequencyResolution(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* frequencyResolution
);

int32 __stdcall RFmxSpecAn_SEMFetchLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxSpecAn_SEMFetchLowerOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAbsolutePower,
   float64* totalRelativePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* peakRelativePower
);

int32 __stdcall RFmxSpecAn_SEMFetchTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalCarrierPower
);

int32 __stdcall RFmxSpecAn_SEMFetchUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32* measurementStatus,
   float64* margin,
   float64* marginFrequency,
   float64* marginAbsolutePower,
   float64* marginRelativePower
);

int32 __stdcall RFmxSpecAn_SEMFetchUpperOffsetPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* totalAbsolutePower,
   float64* totalRelativePower,
   float64* peakAbsolutePower,
   float64* peakFrequency,
   float64* peakRelativePower
);

int32 __stdcall RFmxSpecAn_OBWFetchSpectrumTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 spectrum[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_OBWFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* averagePower,
   float64* frequencyResolution,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxSpecAn_OBWRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* occupiedBandwidth,
   float64* averagePower,
   float64* frequencyResolution,
   float64* startFrequency,
   float64* stopFrequency
);

int32 __stdcall RFmxSpecAn_TXPFetchPowerTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 power[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_TXPFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageMeanPower,
   float64* peakToAverageRatio,
   float64* maximumPower,
   float64* minimumPower
);

int32 __stdcall RFmxSpecAn_TXPRead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageMeanPower,
   float64* peakToAverageRatio,
   float64* maximumPower,
   float64* minimumPower
);

int32 __stdcall RFmxSpecAn_PhaseNoiseFetchIntegratedNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 integratedPhaseNoise[],
   float64 residualPMInRadian[],
   float64 residualPMInDegree[],
   float64 residualFM[],
   float64 jitter[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseFetchMeasuredLogPlotTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 frequency[],
   float32 measuredPhaseNoise[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseFetchSmoothedLogPlotTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 frequency[],
   float32 smoothedPhaseNoise[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseFetchSpotNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 spotPhaseNoise[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseFetchCarrierMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* carrierFrequency,
   float64* carrierPower
);

int32 __stdcall RFmxSpecAn_PAVTFetchAmplitudeTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 traceIndex,
   float64* x0,
   float64* dx,
   float32 amplitude[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PAVTFetchPhaseAndAmplitudeArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanRelativePhase[],
   float64 meanRelativeAmplitude[],
   float64 meanAbsolutePhase[],
   float64 meanAbsoluteAmplitude[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PAVTFetchPhaseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 traceIndex,
   float64* x0,
   float64* dx,
   float32 phase[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PAVTFetchPhaseAndAmplitude(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* meanRelativePhase,
   float64* meanRelativeAmplitude,
   float64* meanAbsolutePhase,
   float64* meanAbsoluteAmplitude
);

int32 __stdcall RFmxSpecAn_IDPDFetchProcessedMeanAcquiredWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle processedMeanAcquiredWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDFetchProcessedMeanAcquiredWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 processedMeanAcquiredWaveformI[],
   float32 processedMeanAcquiredWaveformQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDFetchProcessedReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle processedReferenceWaveform[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDFetchProcessedReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 processedReferenceWaveformI[],
   float32 processedReferenceWaveformQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDFetchPredistortedWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle predistortedWaveform[],
   float64* PAPR,
   float64* powerOffset,
   float64* gain,
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDFetchPredistortedWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 predistortedWaveformI[],
   float32 predistortedWaveformQ[],
   float64* PAPR,
   float64* powerOffset,
   float64* gain,
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDFetchEqualizerCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle equalizerCoefficients[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDFetchEqualizerCoefficientsSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 equalizerCoefficientsI[],
   float32 equalizerCoefficientsQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDGetEqualizerReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* x0,
   float64* dx,
   NIComplexSingle equalizerReferenceWaveform[],
   float64* PAPR,
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_IDPDGetEqualizerReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* x0,
   float64* dx,
   float32 equalizerReferenceWaveformI[],
   float32 equalizerReferenceWaveformQ[],
   float64* PAPR,
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListFetchMeanAbsolutePowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 meanAbsolutePower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListFetchMaximumPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 maximumPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListFetchMinimumPowerArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 minimumPower[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxSpecAn_MarkerFetchXY(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* markerXLocation,
   float64* markerYLocation
);

int32 __stdcall RFmxSpecAn_MarkerFetchFunctionValue(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* functionValue
);

int32 __stdcall RFmxSpecAn_IQGetRecordsDone(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* recordsDone
);

int32 __stdcall RFmxSpecAn_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetNumberOfSteps(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SetNumberOfSteps(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetListStepTimerDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetListStepTimerDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetListStepTimerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetListStepTimerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_GetSelectedPath(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_SetSelectedPath(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetCarrierMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetCarrierMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetCarrierRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetCarrierRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetCarrierRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetCarrierRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetPowerReferenceSpecific(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetPowerReferenceSpecific(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsFrequencyResolution(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsCarrierTotalRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsLowerOffsetFrequencyReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsLowerOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsLowerOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsLowerOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsLowerOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsLowerOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsUpperOffsetFrequencyReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsUpperOffsetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsUpperOffsetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsUpperOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsUpperOffsetAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_ACPGetResultsUpperOffsetRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetNumberOfRecords(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetNumberOfRecords(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetRBWFilterRRCAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetRBWFilterRRCAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsMeanPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsMeanPowerPercentile(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsTenPercentPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsOnePercentPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsOneTenthPercentPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsOneHundredthPercentPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsOneThousandthPercentPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsOneTenThousandthPercentPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsPeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CCDFGetResultsMeasuredSampleCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetCarrierRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetCarrierRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetCarrierRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetCarrierRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsFrequencyResolution(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsCarrierPSD(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsCarrierRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetRBWFilterRRCAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetRBWFilterRRCAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetResultsAverageRelativeFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetResultsAverageAbsoluteFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetResultsMeanPhase(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_FCntGetResultsAllanDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetFundamentalRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetFundamentalRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetFundamentalRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetFundamentalRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetFundamentalRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetFundamentalRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetFundamentalMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetFundamentalMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetNumberOfHarmonics(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetNumberOfHarmonics(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetAutoSetupEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetAutoSetupEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetHarmonicEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetHarmonicEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetHarmonicOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetHarmonicOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetHarmonicBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetHarmonicBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetHarmonicMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetHarmonicMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetResultsTotalHarmonicDistortion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetResultsAverageFundamentalPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetResultsFundamentalFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetResultsHarmonicAverageAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetResultsHarmonicAverageRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetResultsHarmonicFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_HarmGetResultsHarmonicRBW(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetBandwidthPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetBandwidthPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetResultsOccupiedBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetResultsAveragePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetResultsStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetResultsStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_OBWGetResultsFrequencyResolution(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierChannelBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetCarrierRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetCarrierRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetBandwidthIntegral(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetLimitFailMask(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetAbsoluteLimitMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetAbsoluteLimitMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRelativeLimitMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRelativeLimitMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetOffsetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetReferenceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetReferenceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsTotalCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsCompositeMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsFrequencyResolution(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsCarrierTotalRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsCarrierAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsCarrierPeakAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsCarrierPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsCarrierIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetTotalAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetTotalRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetPeakAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetPeakRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsLowerOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetTotalAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetTotalRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetPeakAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetPeakRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetMarginRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SEMGetResultsUpperOffsetPowerReferenceCarrier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetPowerUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetVBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetVBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetVBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetVBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetVBWFilterVBWToRBWRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetVBWFilterVBWToRBWRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetNoiseCalibrationMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetNoiseCalibrationAveragingAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetNoiseCalibrationAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetNoiseCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetNoiseCompensationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetFFTOverlapMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetFFTOverlap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetFFTOverlapType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetFFTOverlapType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetSequentialFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetAnalysisInput(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetAnalysisInput(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetResultsPeakAmplitude(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetResultsPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpectrumGetResultsFrequencyResolution(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetNumberOfRanges(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetNumberOfRanges(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeRBWFilterBandwidthDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeVBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeVBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeVBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeVBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeVBWFilterVBWToRBWRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeVBWFilterVBWToRBWRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeDetectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeDetectorPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeAbsoluteLimitMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeAbsoluteLimitMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeAbsoluteLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeAbsoluteLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeRelativeAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangePeakThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangePeakThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangePeakExcursion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangePeakExcursion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetRangeNumberOfSpursToReport(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetRangeNumberOfSpursToReport(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetTraceRangeIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetTraceRangeIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetResultsRangeMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetResultsRangeNumberOfDetectedSpurs(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetResultsRangeFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetResultsRangeMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetResultsRangeAmplitude(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SpurGetResultsRangeAbsoluteLimit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetVBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetVBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetVBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetVBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetVBWFilterVBWToRBWRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetVBWFilterVBWToRBWRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetResultsAverageMeanPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetResultsPeaktoAverageRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetResultsMaximumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_TXPGetResultsMinimumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetMeasurementSampleRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetMeasurementSampleRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetSignalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetSignalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetSynchronizationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetSynchronizationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAutoCarrierDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAutoCarrierDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetCarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetCarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAMToAMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAMToAMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAMToAMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAMToAMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAMToPMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAMToPMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAMToPMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAMToPMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetThresholdDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetThresholdDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetFrequencyOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetFrequencyOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAMToAMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAMToAMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAMToPMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAMToPMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetEVMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetEVMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetEqualizerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetEqualizerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetEqualizerFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetEqualizerFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetCompressionPointEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetCompressionPointEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetCompressionPointLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMSetCompressionPointLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_AMPMGetCompressionPointGainReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetCompressionPointGainReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetCompressionPointGainReferencePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetCompressionPointGainReferencePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetCompressionPointUserGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetCompressionPointUserGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetMaximumTimingError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetMaximumTimingError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetReferencePowerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetReferencePowerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsMeanLinearGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResults1dBCompressionPoint(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsInputCompressionPoint(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsOutputCompressionPoint(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsCompressionPointGainReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsPeakReferencePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsPeakReferencePowerGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsGainErrorRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsPhaseErrorRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsMeanPhaseError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsAMToAMCurveFitResidual(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsAMToPMCurveFitResidual(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsAMToAMCurveFitCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_AMPMGetResultsAMToPMCurveFitCoefficients(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMeasurementSampleRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMeasurementSampleRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetSignalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetSignalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetSynchronizationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetSynchronizationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetAutoCarrierDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetAutoCarrierDetectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetCarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetCarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetTargetGainType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetTargetGainType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableAMToAMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableAMToAMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableAMToAMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableAMToAMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableAMToPMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableAMToPMCurveFitOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableAMToPMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableAMToPMCurveFitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableThresholdEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableThresholdType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableThresholdDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableThresholdDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetLookupTableStepSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetLookupTableStepSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialOrderType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialOrderType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialLeadOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialLeadOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialLagOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialLagOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialLeadMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialLeadMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialLagMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialLagMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialMaximumLead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialMaximumLead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialMaximumLag(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialMaximumLag(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialLeadOrderType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialLeadOrderType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMemoryPolynomialLagOrderType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMemoryPolynomialLagOrderType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetDVRNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetDVRNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetDVRLinearMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetDVRLinearMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetDVRNonlinearMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetDVRNonlinearMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetDVRDDREnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetDVRDDREnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetIterativeDPDEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetIterativeDPDEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetFrequencyOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetFrequencyOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetIQOriginOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetMaximumTimingError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetMaximumTimingError(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetNMSEEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetNMSEEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFREnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFREnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRMaximumIterations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRMaximumIterations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRTargetPAPR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRTargetPAPR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRShapingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRShapingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRShapingThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRShapingThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCFRNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCFRNumberOfCarriers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCarrierOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetPreDPDCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetPreDPDCarrierBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetNumberofAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetNumberofAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDConfigurationInput(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDConfigurationInput(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDLookupTableCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDLookupTableCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDMemoryModelCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDMemoryModelCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFREnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFREnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRMaximumIterations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRMaximumIterations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRTargetPAPRType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRTargetPAPRType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRTargetPAPR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRTargetPAPR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRShapingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRShapingFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDCFRShapingThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDCFRShapingThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserDPDModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserDPDModel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserLookupTableType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserLookupTableType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserLookupTableInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserLookupTableInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLeadOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLeadOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLagOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLagOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLeadMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLeadMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialLagMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialLagMemoryDepth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialMaximumLead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialMaximumLead(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDUserMemoryPolynomialMaximumLag(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDUserMemoryPolynomialMaximumLag(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetResultsAverageGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetResultsNMSE(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetEqualizerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetEqualizerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetEqualizerFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetEqualizerFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetMeasurementSampleRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetMeasurementSampleRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetMeasurementSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetSignalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetSignalType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetReferenceWaveformIdleDurationPresent(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetReferenceWaveformIdleDurationPresent(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetDUTAverageInputPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetEVMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetEVMEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetImpairmentEstimationStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetImpairmentEstimationStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetImpairmentEstimationStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetImpairmentEstimationStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetSynchronizationEstimationStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetSynchronizationEstimationStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetSynchronizationEstimationStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetSynchronizationEstimationStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetGainExpansion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetGainExpansion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetTargetGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetTargetGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetPowerLinearityTradeoff(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetPowerLinearityTradeoff(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetResultsGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetResultsMeanRMSEVM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IDPDGetNumberofAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IDPDSetNumberofAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetMeasurementMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetSampleRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetAcquisitionTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetAcquisitionTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetPretriggerTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetPretriggerTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetBandwidthAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetBandwidthAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetNumberOfRecords(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetNumberOfRecords(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IQGetDeleteRecordOnFetch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IQSetDeleteRecordOnFetch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetFrequencyDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetFundamentalLowerToneFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetFundamentalLowerToneFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetFundamentalUpperToneFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetFundamentalUpperToneFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetAutoIntermodsSetupEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetAutoIntermodsSetupEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetMaximumIntermodOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetMaximumIntermodOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetNumberOfIntermods(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetNumberOfIntermods(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetIntermodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetIntermodEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetIntermodOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetIntermodOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetIntermodSide(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetIntermodSide(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetLowerIntermodFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetLowerIntermodFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetUpperIntermodFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetUpperIntermodFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetLocalPeakSearchEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetLocalPeakSearchEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetRBWFilterAutoBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetFFTPadding(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetIFOutputPowerOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetNearIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetFarIFOutputPowerOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsFundamentalLowerTonePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsFundamentalUpperTonePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsIntermodOrder(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsLowerIntermodPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsUpperIntermodPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsWorstCaseIntermodAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsLowerIntermodRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsUpperIntermodRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsWorstCaseIntermodRelativePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsLowerOutputInterceptPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsUpperOutputInterceptPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_IMGetResultsWorstCaseOutputInterceptPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetDUTType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetDUTType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetFrequencyConverterLOFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetFrequencyConverterLOFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetFrequencyConverterFrequencyContext(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetFrequencyConverterFrequencyContext(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetFrequencyConverterSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetFrequencyConverterSideband(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetFrequencyConverterImageRejection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetFrequencyConverterImageRejection(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetMeasurementInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetExternalPreampPresent(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetExternalPreampPresent(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetExternalPreampFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetExternalPreampFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetExternalPreampGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetExternalPreampGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetDUTInputLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetDUTInputLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetDUTInputLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetDUTInputLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetDUTInputLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetDUTInputLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetDUTInputLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetDUTInputLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetDUTOutputLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetDUTOutputLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetDUTOutputLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetDUTOutputLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetDUTOutputLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetDUTOutputLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetDUTOutputLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetDUTOutputLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetCalibrationLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetCalibrationLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetCalibrationLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetCalibrationLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetCalibrationLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetCalibrationLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetCalibrationLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetCalibrationLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetMeasurementMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetYFactorMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetYFactorMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceRFSignalGeneratorPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceRFSignalGeneratorPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceENRFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceENRFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceENR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceENR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceColdTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceColdTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceOffTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceOffTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceSettlingTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceSettlingTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceLossCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceLossFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetYFactorNoiseSourceLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetYFactorNoiseSourceLossTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceInputTerminationVSWR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceInputTerminationVSWR(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceInputTerminationVSWRFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceInputTerminationVSWRFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceInputTerminationTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceInputTerminationTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceDUTSParametersFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceDUTSParametersFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceDUTS21(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceDUTS21(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceDUTS12(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceDUTS12(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceDUTS11(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceDUTS11(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetColdSourceDUTS22(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFSetColdSourceDUTS22(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_NFGetDeviceTemperatureTolerance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetDeviceTemperatureTolerance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_NFSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_NFGetResultsDUTNoiseFigure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsDUTNoiseTemperature(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsDUTGain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsAnalyzerNoiseFigure(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsMeasurementYFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsCalibrationYFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsYFactorHotPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsYFactorColdPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_NFGetResultsColdSourcePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetRangeDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetRangeDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetRBWPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetRBWPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetNumberOfRanges(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetNumberOfRanges(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetRangeStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetRangeStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetRangeStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetRangeStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetRangeRBWPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetRangeRBWPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetRangeAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetRangeAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetAveragingMultiplier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetAveragingMultiplier(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetFFTWindow(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetSmoothingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetSmoothingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetSmoothingPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetSmoothingPercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetSpotNoiseFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetSpotNoiseFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetIntegratedNoiseRangeDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetIntegratedNoiseRangeDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetIntegratedNoiseStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetIntegratedNoiseStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetIntegratedNoiseStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetIntegratedNoiseStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetSpurRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetSpurRemovalEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetSpurRemovalPeakExcursion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetSpurRemovalPeakExcursion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetCancellationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetCancellationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetCancellationThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetCancellationThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetCancellationFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetCancellationFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetCancellationReferencePhaseNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetCancellationReferencePhaseNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsCarrierPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsCarrierFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsSpotPhaseNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsIntegratedPhaseNoise(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsResidualPMInRadian(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsResidualPMInDegree(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsResidualFM(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PhaseNoiseGetResultsJitter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PAVTGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetMeasurementLocationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetMeasurementLocationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetMeasurementIntervalMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetMeasurementIntervalMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetSegmentType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetSegmentType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetSegmentStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetSegmentStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetSegmentMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetSegmentMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetSegmentMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetSegmentMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetPhaseUnwrapEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetPhaseUnwrapEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetFrequencyOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetFrequencyOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetFrequencyTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetFrequencyTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetResultsMeanRelativePhase(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetResultsMeanRelativeAmplitude(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetResultsMeanAbsolutePhase(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetResultsMeanAbsoluteAmplitude(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTGetResultsFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PowerListGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PowerListSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PowerListGetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_PowerListSetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentRBWFilterBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentRBWFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentRBWFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetSegmentTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListSetSegmentTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetResultsMeanAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetResultsMaximumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxSpecAn_PowerListGetResultsMinimumPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */

#define RFMXSPECAN_ATTR_CHP_INTEGRATION_BANDWIDTH                                      0x00103002
#define RFMXSPECAN_ATTR_CHP_RRC_FILTER_ENABLED                                         0x0010300f
#define RFMXSPECAN_ATTR_CHP_RRC_FILTER_ALPHA                                           0x00103010
#define RFMXSPECAN_ATTR_CHP_RESULTS_AVERAGE_CHANNEL_POWER                              0x00103015
#define RFMXSPECAN_ATTR_CHP_RESULTS_AVERAGE_CHANNEL_PSD                                0x00103016
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_HEADROOM_MODE                                    0x0010f023
#define RFMXSPECAN_ATTR_DPD_APPLY_DPD_HEADROOM                                         0x0010f024
#define RFMXSPECAN_ATTR_REFERENCE_LEVEL_UNITS                                          0x00100ffe
#define RFMXSPECAN_ATTR_PAVT_MEASUREMENT_START_TIME                                    0x00107004

// Values for RFMXSPECAN_ATTR_ACP_OFFSET_RRC_FILTER_ENABLED
#define RFMXSPECAN_VAL_ACP_RRC_FILTER_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_ACP_RRC_FILTER_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_ACP_OFFSET_ENABLED
#define RFMXSPECAN_VAL_ACP_OFFSET_ENABLED_FALSE                                                       0
#define RFMXSPECAN_VAL_ACP_OFFSET_ENABLED_TRUE                                                        1

// Values for RFMXSPECAN_ATTR_CHP_RRC_FILTER_ENABLED
#define RFMXSPECAN_VAL_CHP_RRC_FILTER_ENABLED_FALSE                                                   0
#define RFMXSPECAN_VAL_CHP_RRC_FILTER_ENABLED_TRUE                                                    1

// Values for RFMXSPECAN_ATTR_SEM_RESULTS_COMPOSITE_MEASUREMENT_STATUS
#define RFMXSPECAN_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXSPECAN_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXSPECAN_ATTR_ACP_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_ACP_RBW_FILTER_TYPE_SYNCH_TUNED_4                                              3
#define RFMXSPECAN_VAL_ACP_RBW_FILTER_TYPE_SYNCH_TUNED_5                                              4

// Values for RFMXSPECAN_ATTR_CCDF_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_CCDF_RBW_FILTER_TYPE_SYNCH_TUNED_4                                             3
#define RFMXSPECAN_VAL_CCDF_RBW_FILTER_TYPE_SYNCH_TUNED_5                                             4

// Values for RFMXSPECAN_ATTR_CHP_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_CHP_RBW_FILTER_TYPE_SYNCH_TUNED_4                                              3
#define RFMXSPECAN_VAL_CHP_RBW_FILTER_TYPE_SYNCH_TUNED_5                                              4

// Values for RFMXSPECAN_ATTR_FCNT_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_FCNT_RBW_FILTER_TYPE_SYNCH_TUNED_4                                             3
#define RFMXSPECAN_VAL_FCNT_RBW_FILTER_TYPE_SYNCH_TUNED_5                                             4

// Values for RFMXSPECAN_ATTR_HARM_FUNDAMENTAL_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_HARM_RBW_FILTER_TYPE_SYNCH_TUNED_4                                             3
#define RFMXSPECAN_VAL_HARM_RBW_FILTER_TYPE_SYNCH_TUNED_5                                             4

// Values for RFMXSPECAN_ATTR_IM_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_IM_RBW_FILTER_TYPE_SYNCH_TUNED_4                                               3
#define RFMXSPECAN_VAL_IM_RBW_FILTER_TYPE_SYNCH_TUNED_5                                               4

// Values for RFMXSPECAN_ATTR_OBW_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_OBW_RBW_FILTER_TYPE_SYNCH_TUNED_4                                              3
#define RFMXSPECAN_VAL_OBW_RBW_FILTER_TYPE_SYNCH_TUNED_5                                              4

// Values for RFMXSPECAN_ATTR_SEM_OFFSET_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SEM_RBW_FILTER_TYPE_SYNCH_TUNED_4                                              3
#define RFMXSPECAN_VAL_SEM_RBW_FILTER_TYPE_SYNCH_TUNED_5                                              4

// Values for RFMXSPECAN_ATTR_SEM_CARRIER_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_TYPE_SYNCH_TUNED_4                                      3
#define RFMXSPECAN_VAL_SEM_CARRIER_RBW_FILTER_TYPE_SYNCH_TUNED_5                                      4

// Values for RFMXSPECAN_ATTR_SPECTRUM_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_TYPE_SYNCH_TUNED_4                                         3
#define RFMXSPECAN_VAL_SPECTRUM_RBW_FILTER_TYPE_SYNCH_TUNED_5                                         4

// Values for RFMXSPECAN_ATTR_SPUR_RANGE_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_SPUR_RBW_FILTER_TYPE_SYNCH_TUNED_4                                             3
#define RFMXSPECAN_VAL_SPUR_RBW_FILTER_TYPE_SYNCH_TUNED_5                                             4

// Values for RFMXSPECAN_ATTR_TXP_RBW_FILTER_TYPE
#define RFMXSPECAN_VAL_TXP_RBW_FILTER_TYPE_SYNCH_TUNED_4                                              3
#define RFMXSPECAN_VAL_TXP_RBW_FILTER_TYPE_SYNCH_TUNED_5                                              4

// Values for RFMXSPECAN_ATTR_DPD_APPLY_DPD_HEADROOM_MODE
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_HEADROOM_MODE_OFF                                                0
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_HEADROOM_MODE_AUTO                                               1
#define RFMXSPECAN_VAL_DPD_APPLY_DPD_HEADROOM_MODE_MANUAL                                             2

// Values for RFMXSPECAN_ATTR_ACP_AVERAGING_TYPE
#define RFMXSPECAN_VAL_ACP_AVERAGING_TYPE_VECTOR                                                      5

// Values for RFMXSPECAN_ATTR_SEM_AVERAGING_TYPE
#define RFMXSPECAN_VAL_SEM_AVERAGING_TYPE_VECTOR                                                      5

// Values for RFMXSPECAN_ATTR_SPECTRUM_AVERAGING_TYPE
#define RFMXSPECAN_VAL_SPECTRUM_AVERAGING_TYPE_VECTOR                                                 5

// Values for RFMXSPECAN_ATTR_SPUR_AVERAGING_TYPE
#define RFMXSPECAN_VAL_SPUR_AVERAGING_TYPE_VECTOR                                                     5

// Values for RFMXSPECAN_ATTR_OBW_AVERAGING_TYPE
#define RFMXSPECAN_VAL_OBW_AVERAGING_TYPE_VECTOR                                                      5

// Values for RFMXSPECAN_ATTR_CHP_AVERAGING_TYPE
#define RFMXSPECAN_VAL_CHP_AVERAGING_TYPE_VECTOR                                                      5

// Values for RFMXSPECAN_ATTR_SPECTRUM_POWER_UNITS
#define RFMXSPECAN_VAL_SPECTRUM_POWER_UNITS_REFERENCE_LEVEL_UNITS                                     9

// Values for RFMXSPECAN_ATTR_REFERENCE_LEVEL_UNITS
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_DBM                                                      0
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_DBW                                                      2
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_DBV                                                      3
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_DBMV                                                     4
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_DBUV                                                     5
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_WATTS                                                    6
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_VOLTS                                                    7
#define RFMXSPECAN_VAL_REFERENCE_LEVEL_UNITS_VOLTS_SQUARED                                            8

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxSpecAn_CHPSetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetIntegrationBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetRRCFilterAlpha(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPSetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetRRCFilterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsAverageChannelPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_CHPGetResultsAverageChannelPSD(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_SetAttributeCSGArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxSpecAn_DPDApplyDPD(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0In,
   float64 dxIn,
   NIComplexSingle waveformIn[],
   int32 arraySizeIn,
   int32 idleDurationPresent,
   float64 measurementTimeout,
   float64* x0Out,
   float64* dxOut,
   NIComplexSingle waveformOut[],
   int32 arraySizeOut,
   int32* actualArraySize,
   float64* appliedHeadroom
);

int32 __stdcall RFmxSpecAn_DPDCfgApplyDPDHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 headroomMode,
   float64 headroom
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDHeadroomMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDHeadroomMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxSpecAn_DPDGetApplyDPDHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_DPDSetApplyDPDHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_CHPFetchMeasurement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* averageChannelPower,
   float64* averageChannelPSD,
   float64* frequencyResolution
);

int32 __stdcall RFmxSpecAn_CfgReferenceLevelUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 referenceLevelUnits
);

int32 __stdcall RFmxSpecAn_AnalyzeIQ(
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

int32 __stdcall RFmxSpecAn_AnalyzeIQSplit(
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

int32 __stdcall RFmxSpecAn_AnalyzeSpectrum(
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

int32 __stdcall RFmxSpecAn_PAVTGetMeasurementStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxSpecAn_PAVTSetMeasurementStartTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxSpecAn_PAVTCfgMeasurementStartTimeList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementStartTime[],
   int32 numberOfElements
);

int32 __stdcall RFmxSpecAn_PAVTCfgMeasurementStartTimeStep(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfSegments,
   float64 segment0MeasurementStartTime,
   float64 segmentInterval
);

#ifdef __cplusplus
}
#endif


#endif

