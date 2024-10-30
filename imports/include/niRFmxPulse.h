
/****************************************************************************************************
*          National Instruments RFmx Pulse
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2024.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxPulse.h
*
* Purpose:  National Instruments RFmx Pulse,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_PULSE_H__
#define __NI_RFMX_PULSE_H__

#include "niRFmxInstr.h"

#define RFMXPULSE_ATTR_SELECTED_PORTS                                                            0x00c00ffd
#define RFMXPULSE_ATTR_CENTER_FREQUENCY                                                          0x00c00001
#define RFMXPULSE_ATTR_REFERENCE_LEVEL                                                           0x00c00002
#define RFMXPULSE_ATTR_EXTERNAL_ATTENUATION                                                      0x00c00003
#define RFMXPULSE_ATTR_REFERENCE_LEVEL_HEADROOM                                                  0x00c00ffc
#define RFMXPULSE_ATTR_TRIGGER_TYPE                                                              0x00c00004
#define RFMXPULSE_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                               0x00c00005
#define RFMXPULSE_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                                 0x00c00006
#define RFMXPULSE_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                              0x00c00007
#define RFMXPULSE_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                               0x00c00008
#define RFMXPULSE_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                                          0x00c00fff
#define RFMXPULSE_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                               0x00c00009
#define RFMXPULSE_ATTR_TRIGGER_DELAY                                                             0x00c0000a
#define RFMXPULSE_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                           0x00c0000b
#define RFMXPULSE_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                                       0x00c0000c
#define RFMXPULSE_ATTR_MEASUREMENT_BANDWIDTH                                                     0x00c00017
#define RFMXPULSE_ATTR_MEASUREMENT_FILTER_TYPE                                                   0x00c00018
#define RFMXPULSE_ATTR_ACQUISITION_LENGTH                                                        0x00c00011
#define RFMXPULSE_ATTR_MAXIMUM_PULSE_COUNT_ENABLED                                               0x00c00012
#define RFMXPULSE_ATTR_MAXIMUM_PULSE_COUNT                                                       0x00c00013
#define RFMXPULSE_ATTR_SEGMENTED_ACQUISITION_ENABLED                                             0x00c00014
#define RFMXPULSE_ATTR_NUMBER_OF_SEGMENTS                                                        0x00c00015
#define RFMXPULSE_ATTR_SEGMENT_ACQUISITION_LENGTH                                                0x00c00016
#define RFMXPULSE_ATTR_PULSE_MEASUREMENT_ENABLED                                                 0x00c01000
#define RFMXPULSE_ATTR_PULSE_MULTIBURST_ENABLED                                                  0x00c010de
#define RFMXPULSE_ATTR_PULSE_MULTIBURST_LENGTH                                                   0x00c010df
#define RFMXPULSE_ATTR_PULSE_DETECTION_REFERENCE                                                 0x00c01002
#define RFMXPULSE_ATTR_PULSE_DETECTION_THRESHOLD                                                 0x00c01003
#define RFMXPULSE_ATTR_PULSE_DETECTION_HYSTERESIS                                                0x00c01004
#define RFMXPULSE_ATTR_PULSE_DETECTION_MINIMUM_OFF_DURATION                                      0x00c01005
#define RFMXPULSE_ATTR_PULSE_DETECTION_MINIMUM_WIDTH                                             0x00c01006
#define RFMXPULSE_ATTR_PULSE_DETECTION_MAXIMUM_WIDTH                                             0x00c01007
#define RFMXPULSE_ATTR_PULSE_METRICS_ENABLED                                                     0x00c0109a
#define RFMXPULSE_ATTR_PULSE_METRICS_AMPLITUDE_DEVIATION_UNIT                                    0x00c010dd
#define RFMXPULSE_ATTR_PULSE_LEVEL_COMPUTATION_METHOD                                            0x00c01008
#define RFMXPULSE_ATTR_PULSE_AMPLITUDE_LEVEL_DOMAIN                                              0x00c01009
#define RFMXPULSE_ATTR_PULSE_UPPER_THRESHOLD_LEVEL                                               0x00c0100a
#define RFMXPULSE_ATTR_PULSE_WIDTH_THRESHOLD_LEVEL                                               0x00c0100b
#define RFMXPULSE_ATTR_PULSE_LOWER_THRESHOLD_LEVEL                                               0x00c0100c
#define RFMXPULSE_ATTR_PULSE_DROOP_COMPENSATION_ENABLED                                          0x00c0100d
#define RFMXPULSE_ATTR_PULSE_MEASUREMENT_POINT_REFERENCE                                         0x00c0108a
#define RFMXPULSE_ATTR_PULSE_MEASUREMENT_POINT_OFFSET                                            0x00c0108b
#define RFMXPULSE_ATTR_PULSE_MEASUREMENT_POINT_AVERAGING_DURATION                                0x00c0108c
#define RFMXPULSE_ATTR_PULSE_MULTIPLE_MEASUREMENT_POINTS_ENABLED                                 0x00c010e3
#define RFMXPULSE_ATTR_PULSE_MULTIPLE_MEASUREMENT_POINTS_WINDOW_START                            0x00c010e4
#define RFMXPULSE_ATTR_PULSE_MULTIPLE_MEASUREMENT_POINTS_WINDOW_STOP                             0x00c010e5
#define RFMXPULSE_ATTR_PULSE_MULTIPLE_MEASUREMENT_POINTS_WINDOW_STEP_SIZE                        0x00c010e6
#define RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_DEVIATION_RANGE_REFERENCE                       0x00c0108d
#define RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_DEVIATION_RANGE_LENGTH                          0x00c0108e
#define RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_DEVIATION_RANGE_EDGE_START                      0x00c0108f
#define RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_DEVIATION_RANGE_EDGE_STOP                       0x00c01090
#define RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_MODULATION_TYPE                                 0x00c0109b
#define RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_CW_FREQUENCY_OFFSET_AUTO                        0x00c0109c
#define RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_CW_FREQUENCY_OFFSET                             0x00c0109d
#define RFMXPULSE_ATTR_PULSE_STABILITY_ENABLED                                                   0x00c01099
#define RFMXPULSE_ATTR_PULSE_STABILITY_MEASUREMENT_OFFSET                                        0x00c01092
#define RFMXPULSE_ATTR_PULSE_STABILITY_REFERENCE_OFFSET                                          0x00c01093
#define RFMXPULSE_ATTR_PULSE_STABILITY_PULSE_TO_PULSE_OFFSET                                     0x00c01094
#define RFMXPULSE_ATTR_PULSE_STABILITY_FREQUENCY_ERROR_COMPENSATION                              0x00c01089
#define RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_ENABLED                                               0x00c010e7
#define RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE                                 0x00c010e8
#define RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_KEEP_OUT_TIME_AUTO                                    0x00c010e9
#define RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_KEEP_OUT_TIME                                         0x00c010ea
#define RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_MINIMUM_CORRELATION                                   0x00c010eb
#define RFMXPULSE_ATTR_PULSE_ALL_TRACES_ENABLED                                                  0x00c0100e
#define RFMXPULSE_ATTR_PULSE_ACQUISITION_TRACE_SELECT                                            0x00c0110e
#define RFMXPULSE_ATTR_PULSE_ACQUISITION_TRACE_SUBSET_OFFSET                                     0x00c0110f
#define RFMXPULSE_ATTR_PULSE_ACQUISITION_TRACE_SUBSET_LENGTH                                     0x00c01110
#define RFMXPULSE_ATTR_PULSE_TRACE_RANGE_AUTO                                                    0x00c01108
#define RFMXPULSE_ATTR_PULSE_TRACE_RANGE_REFERENCE                                               0x00c01109
#define RFMXPULSE_ATTR_PULSE_TRACE_RANGE_OFFSET                                                  0x00c0110a
#define RFMXPULSE_ATTR_PULSE_TRACE_RANGE_LENGTH                                                  0x00c0110b
#define RFMXPULSE_ATTR_PULSE_SELECTED_BURST_TRACE                                                0x00c010e0
#define RFMXPULSE_ATTR_PULSE_SELECTED_PULSE_TRACE                                                0x00c01091
#define RFMXPULSE_ATTR_PULSE_AMPLITUDE_TRACE_UNIT                                                0x00c010dc
#define RFMXPULSE_ATTR_PULSE_NUMBER_OF_ANALYSIS_THREADS                                          0x00c01088
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_COUNT                                                 0x00c0100f
#define RFMXPULSE_ATTR_PULSE_RESULTS_BURST_INDEX                                                 0x00c010e1
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_POSITION_INDEX                                        0x00c010e2
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOP_LEVEL                                                   0x00c01010
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOP_LEVEL_MEAN                                              0x00c01011
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOP_LEVEL_MAXIMUM                                           0x00c01012
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOP_LEVEL_MINIMUM                                           0x00c01013
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOP_LEVEL_STANDARD_DEVIATION                                0x00c01014
#define RFMXPULSE_ATTR_PULSE_RESULTS_BASE_LEVEL                                                  0x00c01015
#define RFMXPULSE_ATTR_PULSE_RESULTS_BASE_LEVEL_MEAN                                             0x00c01016
#define RFMXPULSE_ATTR_PULSE_RESULTS_BASE_LEVEL_MAXIMUM                                          0x00c01017
#define RFMXPULSE_ATTR_PULSE_RESULTS_BASE_LEVEL_MINIMUM                                          0x00c01018
#define RFMXPULSE_ATTR_PULSE_RESULTS_BASE_LEVEL_STANDARD_DEVIATION                               0x00c01019
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_ON_LEVEL                                            0x00c0101a
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_ON_LEVEL_MEAN                                       0x00c0101b
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_ON_LEVEL_MAXIMUM                                    0x00c0101c
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_ON_LEVEL_MINIMUM                                    0x00c0101d
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_ON_LEVEL_STANDARD_DEVIATION                         0x00c0101e
#define RFMXPULSE_ATTR_PULSE_RESULTS_PEAK_LEVEL                                                  0x00c0101f
#define RFMXPULSE_ATTR_PULSE_RESULTS_PEAK_LEVEL_MEAN                                             0x00c01020
#define RFMXPULSE_ATTR_PULSE_RESULTS_PEAK_LEVEL_MAXIMUM                                          0x00c01021
#define RFMXPULSE_ATTR_PULSE_RESULTS_PEAK_LEVEL_MINIMUM                                          0x00c01022
#define RFMXPULSE_ATTR_PULSE_RESULTS_PEAK_LEVEL_STANDARD_DEVIATION                               0x00c01023
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_LEVEL                                               0x00c01024
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_LEVEL_MEAN                                          0x00c01025
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_LEVEL_MAXIMUM                                       0x00c01026
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_LEVEL_MINIMUM                                       0x00c01027
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_LEVEL_STANDARD_DEVIATION                            0x00c01028
#define RFMXPULSE_ATTR_PULSE_RESULTS_OVERSHOOT                                                   0x00c01029
#define RFMXPULSE_ATTR_PULSE_RESULTS_OVERSHOOT_MEAN                                              0x00c0102a
#define RFMXPULSE_ATTR_PULSE_RESULTS_OVERSHOOT_MAXIMUM                                           0x00c0102b
#define RFMXPULSE_ATTR_PULSE_RESULTS_OVERSHOOT_MINIMUM                                           0x00c0102c
#define RFMXPULSE_ATTR_PULSE_RESULTS_OVERSHOOT_STANDARD_DEVIATION                                0x00c0102d
#define RFMXPULSE_ATTR_PULSE_RESULTS_DROOP                                                       0x00c0102e
#define RFMXPULSE_ATTR_PULSE_RESULTS_DROOP_MEAN                                                  0x00c0102f
#define RFMXPULSE_ATTR_PULSE_RESULTS_DROOP_MAXIMUM                                               0x00c01030
#define RFMXPULSE_ATTR_PULSE_RESULTS_DROOP_MINIMUM                                               0x00c01031
#define RFMXPULSE_ATTR_PULSE_RESULTS_DROOP_STANDARD_DEVIATION                                    0x00c01032
#define RFMXPULSE_ATTR_PULSE_RESULTS_RIPPLE                                                      0x00c01033
#define RFMXPULSE_ATTR_PULSE_RESULTS_RIPPLE_MEAN                                                 0x00c01034
#define RFMXPULSE_ATTR_PULSE_RESULTS_RIPPLE_MAXIMUM                                              0x00c01035
#define RFMXPULSE_ATTR_PULSE_RESULTS_RIPPLE_MINIMUM                                              0x00c01036
#define RFMXPULSE_ATTR_PULSE_RESULTS_RIPPLE_STANDARD_DEVIATION                                   0x00c01037
#define RFMXPULSE_ATTR_PULSE_RESULTS_RISE_TIME                                                   0x00c01038
#define RFMXPULSE_ATTR_PULSE_RESULTS_RISE_TIME_MEAN                                              0x00c01039
#define RFMXPULSE_ATTR_PULSE_RESULTS_RISE_TIME_MAXIMUM                                           0x00c0103a
#define RFMXPULSE_ATTR_PULSE_RESULTS_RISE_TIME_MINIMUM                                           0x00c0103b
#define RFMXPULSE_ATTR_PULSE_RESULTS_RISE_TIME_STANDARD_DEVIATION                                0x00c0103c
#define RFMXPULSE_ATTR_PULSE_RESULTS_RISE_EDGE                                                   0x00c0110c
#define RFMXPULSE_ATTR_PULSE_RESULTS_FALL_TIME                                                   0x00c0103d
#define RFMXPULSE_ATTR_PULSE_RESULTS_FALL_TIME_MEAN                                              0x00c0103e
#define RFMXPULSE_ATTR_PULSE_RESULTS_FALL_TIME_MAXIMUM                                           0x00c0103f
#define RFMXPULSE_ATTR_PULSE_RESULTS_FALL_TIME_MINIMUM                                           0x00c01040
#define RFMXPULSE_ATTR_PULSE_RESULTS_FALL_TIME_STANDARD_DEVIATION                                0x00c01041
#define RFMXPULSE_ATTR_PULSE_RESULTS_FALL_EDGE                                                   0x00c0110d
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_WIDTH                                                 0x00c01042
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_WIDTH_MEAN                                            0x00c01043
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_WIDTH_MAXIMUM                                         0x00c01044
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_WIDTH_MINIMUM                                         0x00c01045
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_WIDTH_STANDARD_DEVIATION                              0x00c01046
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_OFF_DURATION                                          0x00c01047
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_OFF_DURATION_MEAN                                     0x00c01048
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_OFF_DURATION_MAXIMUM                                  0x00c01049
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_OFF_DURATION_MINIMUM                                  0x00c0104a
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_OFF_DURATION_STANDARD_DEVIATION                       0x00c0104b
#define RFMXPULSE_ATTR_PULSE_RESULTS_DUTY_CYCLE                                                  0x00c0104c
#define RFMXPULSE_ATTR_PULSE_RESULTS_DUTY_CYCLE_MEAN                                             0x00c0104d
#define RFMXPULSE_ATTR_PULSE_RESULTS_DUTY_CYCLE_MAXIMUM                                          0x00c0104e
#define RFMXPULSE_ATTR_PULSE_RESULTS_DUTY_CYCLE_MINIMUM                                          0x00c0104f
#define RFMXPULSE_ATTR_PULSE_RESULTS_DUTY_CYCLE_STANDARD_DEVIATION                               0x00c01050
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_REPETITION_INTERVAL                                   0x00c01051
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_REPETITION_INTERVAL_MEAN                              0x00c01052
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_REPETITION_INTERVAL_MAXIMUM                           0x00c01053
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_REPETITION_INTERVAL_MINIMUM                           0x00c01054
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_REPETITION_INTERVAL_STANDARD_DEVIATION                0x00c01055
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_PHASE                                               0x00c0105b
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_PHASE_MEAN                                          0x00c0105c
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_PHASE_MAXIMUM                                       0x00c0105d
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_PHASE_MINIMUM                                       0x00c0105e
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_PHASE_STANDARD_DEVIATION                            0x00c0105f
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_PHASE_DIFFERENCE                             0x00c01098
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_PHASE_DIFFERENCE_MEAN                        0x00c01061
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_PHASE_DIFFERENCE_MAXIMUM                     0x00c01062
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_PHASE_DIFFERENCE_MINIMUM                     0x00c01063
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_PHASE_DIFFERENCE_STANDARD_DEVIATION          0x00c01064
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_DEVIATION                                             0x00c01065
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_DEVIATION_MEAN                                        0x00c01066
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_DEVIATION_MAXIMUM                                     0x00c01067
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_DEVIATION_MINIMUM                                     0x00c01068
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_DEVIATION_STANDARD_DEVIATION                          0x00c01069
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_RMS                                             0x00c0109e
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_RMS_MEAN                                        0x00c0109f
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_RMS_MAXIMUM                                     0x00c010a0
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_RMS_MINIMUM                                     0x00c010a1
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_RMS_STANDARD_DEVIATION                          0x00c010a2
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_PEAK                                            0x00c010a3
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_PEAK_MEAN                                       0x00c010a4
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_PEAK_MAXIMUM                                    0x00c010a5
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_PEAK_MINIMUM                                    0x00c010a6
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_PEAK_STANDARD_DEVIATION                         0x00c010a7
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_ERROR_PEAK_LOCATION                                   0x00c010a8
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_FREQUENCY                                           0x00c0106a
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_FREQUENCY_MEAN                                      0x00c0106b
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_FREQUENCY_MAXIMUM                                   0x00c0106c
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_FREQUENCY_MINIMUM                                   0x00c0106d
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_FREQUENCY_STANDARD_DEVIATION                        0x00c0106e
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_FREQUENCY_DIFFERENCE                         0x00c0106f
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_FREQUENCY_DIFFERENCE_MEAN                    0x00c01070
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_FREQUENCY_DIFFERENCE_MAXIMUM                 0x00c01071
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_FREQUENCY_DIFFERENCE_MINIMUM                 0x00c01072
#define RFMXPULSE_ATTR_PULSE_RESULTS_PULSE_TO_PULSE_FREQUENCY_DIFFERENCE_STANDARD_DEVIATION      0x00c01073
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_DEVIATION                                         0x00c01074
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_DEVIATION_MEAN                                    0x00c01075
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_DEVIATION_MAXIMUM                                 0x00c01076
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_DEVIATION_MINIMUM                                 0x00c01077
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_DEVIATION_STANDARD_DEVIATION                      0x00c01078
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_RMS                                         0x00c010a9
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_RMS_MEAN                                    0x00c010aa
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_RMS_MAXIMUM                                 0x00c010ab
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_RMS_MINIMUM                                 0x00c010ac
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_RMS_STANDARD_DEVIATION                      0x00c010ad
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_PEAK                                        0x00c010ae
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_PEAK_MEAN                                   0x00c010af
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_PEAK_MAXIMUM                                0x00c010b0
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_PEAK_MINIMUM                                0x00c010b1
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_PEAK_STANDARD_DEVIATION                     0x00c010b2
#define RFMXPULSE_ATTR_PULSE_RESULTS_FREQUENCY_ERROR_PEAK_LOCATION                               0x00c010b3
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE                                               0x00c010b4
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE_MEAN                                          0x00c010b5
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE_MAXIMUM                                       0x00c010b6
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE_MINIMUM                                       0x00c010b7
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE_STANDARD_DEVIATION                            0x00c010b8
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY                                    0x00c010b9
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY_MEAN                               0x00c010ba
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY_MAXIMUM                            0x00c010bb
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY_MINIMUM                            0x00c010bc
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY_STANDARD_DEVIATION                 0x00c010bd
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY                                     0x00c010be
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY_MEAN                                0x00c010bf
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY_MAXIMUM                             0x00c010c0
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY_MINIMUM                             0x00c010c1
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY_STANDARD_DEVIATION                  0x00c010c2
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE2                                              0x00c010cd
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE2_MEAN                                         0x00c010ce
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE2_MAXIMUM                                      0x00c010cf
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE2_MINIMUM                                      0x00c010d0
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_RATE2_STANDARD_DEVIATION                           0x00c010d1
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY2                                   0x00c010d2
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY2_MEAN                              0x00c010d3
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY2_MAXIMUM                           0x00c010d4
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY2_MINIMUM                           0x00c010d5
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_START_FREQUENCY2_STANDARD_DEVIATION                0x00c010d6
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY2                                    0x00c010d7
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY2_MEAN                               0x00c010d8
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY2_MAXIMUM                            0x00c010d9
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY2_MINIMUM                            0x00c010da
#define RFMXPULSE_ATTR_PULSE_RESULTS_FM_CHIRP_STOP_FREQUENCY2_STANDARD_DEVIATION                 0x00c010db
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_AMPLITUDE_STABILITY                                 0x00c01095
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_PHASE_STABILITY                                     0x00c01096
#define RFMXPULSE_ATTR_PULSE_RESULTS_AVERAGE_TOTAL_STABILITY                                     0x00c01097
#define RFMXPULSE_ATTR_PULSE_RESULTS_AMPLITUDE_STABILITY                                         0x00c01079
#define RFMXPULSE_ATTR_PULSE_RESULTS_AMPLITUDE_STABILITY_MEAN                                    0x00c0107a
#define RFMXPULSE_ATTR_PULSE_RESULTS_AMPLITUDE_STABILITY_MAXIMUM                                 0x00c0107b
#define RFMXPULSE_ATTR_PULSE_RESULTS_AMPLITUDE_STABILITY_MINIMUM                                 0x00c0107c
#define RFMXPULSE_ATTR_PULSE_RESULTS_AMPLITUDE_STABILITY_STANDARD_DEVIATION                      0x00c0107d
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_STABILITY                                             0x00c0107e
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_STABILITY_MEAN                                        0x00c0107f
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_STABILITY_MAXIMUM                                     0x00c01080
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_STABILITY_MINIMUM                                     0x00c01081
#define RFMXPULSE_ATTR_PULSE_RESULTS_PHASE_STABILITY_STANDARD_DEVIATION                          0x00c01082
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOTAL_STABILITY                                             0x00c01083
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOTAL_STABILITY_MEAN                                        0x00c01084
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOTAL_STABILITY_MAXIMUM                                     0x00c01085
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOTAL_STABILITY_MINIMUM                                     0x00c01086
#define RFMXPULSE_ATTR_PULSE_RESULTS_TOTAL_STABILITY_STANDARD_DEVIATION                          0x00c01087
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_MAINLOBE_WIDTH                                0x00c010ec
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_MAINLOBE_WIDTH_MEAN                           0x00c010ed
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_MAINLOBE_WIDTH_MAXIMUM                        0x00c010ee
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_MAINLOBE_WIDTH_MINIMUM                        0x00c010ef
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_MAINLOBE_WIDTH_STANDARD_DEVIATION             0x00c010f0
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_DELAY                                         0x00c010f1
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_DELAY_MEAN                                    0x00c010f2
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_DELAY_MAXIMUM                                 0x00c010f3
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_DELAY_MINIMUM                                 0x00c010f4
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_DELAY_STANDARD_DEVIATION                      0x00c010f5
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_SIDELOBE_LEVEL                           0x00c010f6
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_SIDELOBE_LEVEL_MEAN                      0x00c010f7
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_SIDELOBE_LEVEL_MAXIMUM                   0x00c010f8
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_SIDELOBE_LEVEL_MINIMUM                   0x00c010f9
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_SIDELOBE_LEVEL_STANDARD_DEVIATION        0x00c010fa
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_COMPRESSION_RATIO                             0x00c010fb
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_COMPRESSION_RATIO_MEAN                        0x00c010fc
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_COMPRESSION_RATIO_MAXIMUM                     0x00c010fd
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_COMPRESSION_RATIO_MINIMUM                     0x00c010fe
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_COMPRESSION_RATIO_STANDARD_DEVIATION          0x00c010ff
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_CORRELATION                              0x00c01100
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_CORRELATION_MEAN                         0x00c01101
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_CORRELATION_MAXIMUM                      0x00c01102
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_CORRELATION_MINIMUM                      0x00c01103
#define RFMXPULSE_ATTR_PULSE_RESULTS_TIME_SIDELOBE_PEAK_CORRELATION_STANDARD_DEVIATION           0x00c01104
#define RFMXPULSE_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                                        0x00c0000d
#define RFMXPULSE_ATTR_RESULT_FETCH_TIMEOUT                                                      0x00c0c000

// Values for RFMXPULSE_ATTR_TRIGGER_TYPE
#define RFMXPULSE_VAL_TRIGGER_TYPE_NONE                                               0
#define RFMXPULSE_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                       1
#define RFMXPULSE_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                      2
#define RFMXPULSE_VAL_TRIGGER_TYPE_SOFTWARE                                           3

// Values for RFMXPULSE_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PFI0_STR                            "PFI0"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PFI1_STR                            "PFI1"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0_STR                       "PXI_Trig0"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG1_STR                       "PXI_Trig1"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG2_STR                       "PXI_Trig2"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG3_STR                       "PXI_Trig3"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG4_STR                       "PXI_Trig4"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG5_STR                       "PXI_Trig5"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG6_STR                       "PXI_Trig6"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG7_STR                       "PXI_Trig7"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXI_STAR_STR                        "PXI_STAR"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_PXIE_DSTARB_STR                     "PXIe_DStarB"
#define RFMXPULSE_VAL_DIGITAL_EDGE_TRIGGER_SOURCE_TIMER_EVENT_STR                     "TimerEvent"

// Values for RFMXPULSE_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXPULSE_VAL_DIGITAL_EDGE_RISING_EDGE                                        0
#define RFMXPULSE_VAL_DIGITAL_EDGE_FALLING_EDGE                                       1

// Values for RFMXPULSE_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXPULSE_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                       0
#define RFMXPULSE_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                       1

// Values for RFMXPULSE_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXPULSE_VAL_IQ_POWER_EDGE_RISING_SLOPE                                      0
#define RFMXPULSE_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                     1

// Values for RFMXPULSE_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXPULSE_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                          0
#define RFMXPULSE_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                            1

// Values for RFMXPULSE_ATTR_MEASUREMENT_FILTER_TYPE
#define RFMXPULSE_VAL_MEASUREMENT_FILTER_TYPE_RECTANGULAR                             0
#define RFMXPULSE_VAL_MEASUREMENT_FILTER_TYPE_GAUSSIAN                                1

// Values for RFMXPULSE_ATTR_MAXIMUM_PULSE_COUNT_ENABLED
#define RFMXPULSE_VAL_MAXIMUM_PULSE_COUNT_ENABLED_FALSE                               0
#define RFMXPULSE_VAL_MAXIMUM_PULSE_COUNT_ENABLED_TRUE                                1

// Values for RFMXPULSE_ATTR_SEGMENTED_ACQUISITION_ENABLED
#define RFMXPULSE_VAL_SEGMENTED_ACQUISITION_ENABLED_FALSE                             0
#define RFMXPULSE_VAL_SEGMENTED_ACQUISITION_ENABLED_TRUE                              1

// Values for RFMXPULSE_ATTR_PULSE_MULTIBURST_ENABLED
#define RFMXPULSE_VAL_MULTIBURST_ENABLED_FALSE                                        0
#define RFMXPULSE_VAL_MULTIBURST_ENABLED_TRUE                                         1

// Values for RFMXPULSE_ATTR_PULSE_DETECTION_REFERENCE
#define RFMXPULSE_VAL_PULSE_DETECTION_REFERENCE_REFERENCE_LEVEL                       0
#define RFMXPULSE_VAL_PULSE_DETECTION_REFERENCE_ABSOLUTE                              1
#define RFMXPULSE_VAL_PULSE_DETECTION_REFERENCE_PEAK                                  2

// Values for RFMXPULSE_ATTR_PULSE_METRICS_ENABLED
#define RFMXPULSE_VAL_PULSE_METRICS_ENABLED_FALSE                                     0
#define RFMXPULSE_VAL_PULSE_METRICS_ENABLED_TRUE                                      1

// Values for RFMXPULSE_ATTR_PULSE_METRICS_AMPLITUDE_DEVIATION_UNIT
#define RFMXPULSE_VAL_PULSE_METRICS_AMPLITUDE_DEVIATION_UNIT_PERCENTAGE               0
#define RFMXPULSE_VAL_PULSE_METRICS_AMPLITUDE_DEVIATION_UNIT_DB                       1

// Values for RFMXPULSE_ATTR_PULSE_LEVEL_COMPUTATION_METHOD
#define RFMXPULSE_VAL_PULSE_LEVEL_COMPUTATION_METHOD_MEAN                             0
#define RFMXPULSE_VAL_PULSE_LEVEL_COMPUTATION_METHOD_MEDIAN                           1
#define RFMXPULSE_VAL_PULSE_LEVEL_COMPUTATION_METHOD_MODE                             2

// Values for RFMXPULSE_ATTR_PULSE_AMPLITUDE_LEVEL_DOMAIN
#define RFMXPULSE_VAL_PULSE_AMPLITUDE_LEVEL_DOMAIN_VOLTS                              0
#define RFMXPULSE_VAL_PULSE_AMPLITUDE_LEVEL_DOMAIN_WATTS                              1

// Values for RFMXPULSE_ATTR_PULSE_DROOP_COMPENSATION_ENABLED
#define RFMXPULSE_VAL_PULSE_DROOP_COMPENSATION_ENABLED_FALSE                          0
#define RFMXPULSE_VAL_PULSE_DROOP_COMPENSATION_ENABLED_TRUE                           1

// Values for RFMXPULSE_ATTR_PULSE_MEASUREMENT_POINT_REFERENCE
#define RFMXPULSE_VAL_PULSE_MEASUREMENT_POINT_REFERENCE_RISE                          0
#define RFMXPULSE_VAL_PULSE_MEASUREMENT_POINT_REFERENCE_CENTER                        1
#define RFMXPULSE_VAL_PULSE_MEASUREMENT_POINT_REFERENCE_FALL                          2

// Values for RFMXPULSE_ATTR_PULSE_MULTIPLE_MEASUREMENT_POINTS_ENABLED
#define RFMXPULSE_VAL_PULSE_MULTIPLE_MEASUREMENT_POINTS_ENABLED_FALSE                 0
#define RFMXPULSE_VAL_PULSE_MULTIPLE_MEASUREMENT_POINTS_ENABLED_TRUE                  1

// Values for RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_DEVIATION_RANGE_REFERENCE
#define RFMXPULSE_VAL_PULSE_FREQUENCY_AND_PHASE_DEVIATION_RANGE_REFERENCE_EDGE        0
#define RFMXPULSE_VAL_PULSE_FREQUENCY_AND_PHASE_DEVIATION_RANGE_REFERENCE_CENTER      1

// Values for RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_MODULATION_TYPE
#define RFMXPULSE_VAL_PULSE_MODULATION_TYPE_CW                                        0
#define RFMXPULSE_VAL_PULSE_MODULATION_TYPE_LINEAR_FM                                 1
#define RFMXPULSE_VAL_PULSE_MODULATION_TYPE_TRIANGULAR_FM                             2

// Values for RFMXPULSE_ATTR_PULSE_FREQUENCY_AND_PHASE_CW_FREQUENCY_OFFSET_AUTO
#define RFMXPULSE_VAL_PULSE_CW_FREQUENCY_OFFSET_AUTO_FALSE                            0
#define RFMXPULSE_VAL_PULSE_CW_FREQUENCY_OFFSET_AUTO_TRUE                             1

// Values for RFMXPULSE_ATTR_PULSE_STABILITY_ENABLED
#define RFMXPULSE_VAL_PULSE_STABILITY_ENABLED_FALSE                                   0
#define RFMXPULSE_VAL_PULSE_STABILITY_ENABLED_TRUE                                    1

// Values for RFMXPULSE_ATTR_PULSE_STABILITY_FREQUENCY_ERROR_COMPENSATION
#define RFMXPULSE_VAL_PULSE_STABILITY_FREQUENCY_ERROR_COMPENSATION_OFF                0
#define RFMXPULSE_VAL_PULSE_STABILITY_FREQUENCY_ERROR_COMPENSATION_ON                 1

// Values for RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_ENABLED
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_ENABLED_FALSE                               0
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_ENABLED_TRUE                                1

// Values for RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE_NONE                  0
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE_FLATTOP               1
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE_HANNING               2
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE_HAMMING               3
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE_GAUSSIAN              4
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE_BLACKMAN              5
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_REFERENCE_WINDOW_TYPE_DOLPH_CHEBYSHEV       6

// Values for RFMXPULSE_ATTR_PULSE_TIME_SIDELOBE_KEEP_OUT_TIME_AUTO
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_KEEP_OUT_TIME_AUTO_FALSE                    0
#define RFMXPULSE_VAL_PULSE_TIME_SIDELOBE_KEEP_OUT_TIME_AUTO_TRUE                     1

// Values for RFMXPULSE_ATTR_PULSE_ACQUISITION_TRACE_SELECT
#define RFMXPULSE_VAL_PULSE_ACQUISITION_TRACE_SELECT_ALL_PULSES                       0
#define RFMXPULSE_VAL_PULSE_ACQUISITION_TRACE_SELECT_SUBSET                           1

// Values for RFMXPULSE_ATTR_PULSE_TRACE_RANGE_AUTO
#define RFMXPULSE_VAL_PULSE_TRACE_RANGE_AUTO_FALSE                                    0
#define RFMXPULSE_VAL_PULSE_TRACE_RANGE_AUTO_TRUE                                     1

// Values for RFMXPULSE_ATTR_PULSE_TRACE_RANGE_REFERENCE
#define RFMXPULSE_VAL_PULSE_TRACE_RANGE_REFERENCE_RISE                                0
#define RFMXPULSE_VAL_PULSE_TRACE_RANGE_REFERENCE_CENTER                              1
#define RFMXPULSE_VAL_PULSE_TRACE_RANGE_REFERENCE_FALL                                2

// Values for RFMXPULSE_ATTR_PULSE_AMPLITUDE_TRACE_UNIT
#define RFMXPULSE_VAL_PULSE_AMPLITUDE_TRACE_UNIT_DBM                                  0
#define RFMXPULSE_VAL_PULSE_AMPLITUDE_TRACE_UNIT_VOLTS                                1
#define RFMXPULSE_VAL_PULSE_AMPLITUDE_TRACE_UNIT_WATTS                                2

// Values for Boolean
#define RFMXPULSE_VAL_FALSE                                                           0
#define RFMXPULSE_VAL_TRUE                                                            1

// Values for FrequencyReferenceSource
#define RFMXPULSE_VAL_ONBOARD_CLOCK_STR                                               "OnboardClock"
#define RFMXPULSE_VAL_REF_IN_STR                                                      "RefIn"
#define RFMXPULSE_VAL_PXI_CLK_STR                                                     "PXI_Clk"
#define RFMXPULSE_VAL_CLK_IN_STR                                                      "ClkIn"
#define RFMXPULSE_VAL_REF_IN2_STR                                                     "RefIn2"
#define RFMXPULSE_VAL_PXI_CLK_MASTER_STR                                              "PXI_Clk_Master"

// Values for RFAttenuationAuto
#define RFMXPULSE_VAL_RF_ATTENUATION_AUTO_FALSE                                       0
#define RFMXPULSE_VAL_RF_ATTENUATION_AUTO_TRUE                                        1

// Values for MeasurementTypes
#define RFMXPULSE_VAL_PULSE                                                           1<<0

// Values for MechanicalAttenuationAuto
#define RFMXPULSE_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                               0
#define RFMXPULSE_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                1

/* ---------------- RFmxPulse APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxPulse_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxPulse_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxPulse_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxPulse_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxPulse_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxPulse_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxPulse_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxPulse_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxPulse_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxPulse_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxPulse_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxPulse_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxPulse_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxPulse_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxPulse_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxPulse_Cfg1ReferenceWaveform(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   NIComplexSingle referenceWaveform[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_Cfg1ReferenceWaveformSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 x0,
   float64 dx,
   float32 referenceWaveformI[],
   float32 referenceWaveformQ[],
   int32 arraySize
);

int32 __stdcall RFmxPulse_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxPulse_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxPulse_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 bandwidth,
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxPulse_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxPulse_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxPulse_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxPulse_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxPulse_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxPulse_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxPulse_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxPulse_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxPulse_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxPulse_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxPulse_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxPulse_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxPulse_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxPulse_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxPulse_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxPulse_FetchAcquiredAmplitudeTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* sampleDuration,
   float32 amplitude[],
   int32 amplitudeArraySize,
   int32* amplitudeActualArraySize,
   int32 startIndex[],
   float64 startTimeStamp[],
   int32 startArraysSize,
   int32* startActualArraysSize
);

int32 __stdcall RFmxPulse_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxPulse_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxPulse_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxPulse_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxPulse_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxPulse_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxPulse_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxPulse_FetchAmplitudeTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 amplitude[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchIQTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle IQData[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchIQTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 IQDataI[],
   float32 IQDataQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchStabilityTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 pulseAmplitudeStability[],
   float32 pulsePhaseStability[],
   float32 pulseTotalStability[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchPulseToPulseStabilityTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 pulseIndex[],
   float64 pulseToPulseAmplitudeStability[],
   float64 pulseToPulsePhaseStability[],
   float64 pulseToPulseTotalStability[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchFrequencyTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 frequency[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchPhaseWrappedTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 wrappedPhase[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchBurstSelectedPositionStabilityTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 pulseAmplitudeStability[],
   float32 pulsePhaseStability[],
   float32 pulseTotalStability[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchMultipleMeasurementPointsStabilityTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 pulseAverageAmplitudeStability[],
   float32 pulseAveragePhaseStability[],
   float32 pulseAverageTotalStability[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchIntrapulseStabilityTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 intrapulseAmplitudeStability[],
   float32 intrapulsePhaseStability[],
   float32 intrapulseTotalStability[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchBurstIntrapulseStabilityTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 intrapulseAverageAmplitudeStability[],
   float32 intrapulseAveragePhaseStability[],
   float32 intrapulseAverageTotalStability[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_FetchTimeSidelobeTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 timeSidelobe[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxPulse_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxPulse_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxPulse_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxPulse_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxPulse_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxPulse_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxPulse_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetMeasurementBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetMeasurementFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetMeasurementFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetMaximumPulseCountEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetMaximumPulseCountEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetMaximumPulseCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetMaximumPulseCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetSegmentedAcquisitionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetSegmentedAcquisitionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_SetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_GetSegmentAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetSegmentAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMultiburstEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMultiburstEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMultiburstLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMultiburstLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetDetectionReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetDetectionReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetDetectionThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetDetectionThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetDetectionHysteresis(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetDetectionHysteresis(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetDetectionMinimumOffDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetDetectionMinimumOffDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetDetectionMinimumWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetDetectionMinimumWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetDetectionMaximumWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetDetectionMaximumWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMetricsEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMetricsEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMetricsAmplitudeDeviationUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMetricsAmplitudeDeviationUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetLevelComputationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetLevelComputationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetAmplitudeLevelDomain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetAmplitudeLevelDomain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetUpperThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetUpperThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetWidthThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetWidthThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetLowerThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetLowerThresholdLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetDroopCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetDroopCompensationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMeasurementPointReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMeasurementPointReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMeasurementPointOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMeasurementPointOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMeasurementPointAveragingDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMeasurementPointAveragingDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMultipleMeasurementPointsEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMultipleMeasurementPointsEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMultipleMeasurementPointsWindowStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMultipleMeasurementPointsWindowStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMultipleMeasurementPointsWindowStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMultipleMeasurementPointsWindowStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetMultipleMeasurementPointsWindowStepSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetMultipleMeasurementPointsWindowStepSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetFrequencyAndPhaseDeviationRangeReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetFrequencyAndPhaseDeviationRangeReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetFrequencyAndPhaseDeviationRangeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetFrequencyAndPhaseDeviationRangeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetFrequencyAndPhaseDeviationRangeEdgeStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetFrequencyAndPhaseDeviationRangeEdgeStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetFrequencyAndPhaseDeviationRangeEdgeStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetFrequencyAndPhaseDeviationRangeEdgeStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetFrequencyAndPhaseModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetFrequencyAndPhaseModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetFrequencyAndPhaseCWFrequencyOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetFrequencyAndPhaseCWFrequencyOffsetAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetFrequencyAndPhaseCWFrequencyOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetFrequencyAndPhaseCWFrequencyOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetStabilityEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetStabilityEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetStabilityMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetStabilityMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetStabilityReferenceOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetStabilityReferenceOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetStabilityPulseToPulseOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetStabilityPulseToPulseOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetStabilityFrequencyErrorCompensation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetStabilityFrequencyErrorCompensation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTimeSidelobeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTimeSidelobeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTimeSidelobeReferenceWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTimeSidelobeReferenceWindowType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTimeSidelobeKeepOutTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTimeSidelobeKeepOutTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTimeSidelobeKeepOutTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTimeSidelobeKeepOutTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTimeSidelobeMinimumCorrelation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTimeSidelobeMinimumCorrelation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetAcquisitionTraceSelect(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetAcquisitionTraceSelect(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetAcquisitionTraceSubsetOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetAcquisitionTraceSubsetOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetAcquisitionTraceSubsetLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetAcquisitionTraceSubsetLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTraceRangeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTraceRangeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTraceRangeReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTraceRangeReference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTraceRangeOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTraceRangeOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetTraceRangeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetTraceRangeLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxPulse_PulseGetSelectedBurstTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetSelectedBurstTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetSelectedPulseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetSelectedPulseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetAmplitudeTraceUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetAmplitudeTraceUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsBurstIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPulsePositionIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTopLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTopLevelMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTopLevelMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTopLevelMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTopLevelStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsBaseLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsBaseLevelMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsBaseLevelMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsBaseLevelMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsBaseLevelStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageOnLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageOnLevelMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageOnLevelMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageOnLevelMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageOnLevelStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPeakLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPeakLevelMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPeakLevelMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPeakLevelMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPeakLevelStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageLevelMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageLevelMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageLevelMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageLevelStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsOvershoot(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsOvershootMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsOvershootMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsOvershootMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsOvershootStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDroop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsDroopMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDroopMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDroopMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDroopStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRipple(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsRippleMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRippleMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRippleMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRippleStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRiseTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsRiseTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRiseTimeMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRiseTimeMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRiseTimeStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsRiseEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFallTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFallTimeMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFallTimeMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFallTimeMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFallTimeStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFallEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseWidthMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseWidthMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseWidthMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseWidthStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseOffDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseOffDurationMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseOffDurationMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseOffDurationMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseOffDurationStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDutyCycle(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsDutyCycleMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDutyCycleMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDutyCycleMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsDutyCycleStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseRepetitionInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseRepetitionIntervalMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseRepetitionIntervalMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseRepetitionIntervalMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseRepetitionIntervalStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAveragePhase(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsAveragePhaseMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAveragePhaseMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAveragePhaseMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAveragePhaseStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulsePhaseDifference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulsePhaseDifferenceMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulsePhaseDifferenceMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulsePhaseDifferenceMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulsePhaseDifferenceStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseDeviationMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseDeviationMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseDeviationMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseDeviationStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorRMSMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorRMSMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorRMSMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorRMSStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorPeakMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorPeakMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorPeakMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorPeakStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseErrorPeakLocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageFrequencyMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageFrequencyMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageFrequencyMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageFrequencyStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulseFrequencyDifference(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulseFrequencyDifferenceMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulseFrequencyDifferenceMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulseFrequencyDifferenceMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPulseToPulseFrequencyDifferenceStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyDeviationMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyDeviationMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyDeviationMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyDeviationStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorRMS(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorRMSMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorRMSMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorRMSMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorRMSStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorPeak(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorPeakMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorPeakMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorPeakMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorPeakStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFrequencyErrorPeakLocation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRateMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRateMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRateMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRateStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequencyMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequencyMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequencyMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequencyStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequencyMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequencyMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequencyMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequencyStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRate2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRate2Mean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRate2Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRate2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpRate2StandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequency2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequency2Mean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequency2Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequency2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStartFrequency2StandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequency2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequency2Mean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequency2Maximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequency2Minimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsFMChirpStopFrequency2StandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageAmplitudeStability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAveragePhaseStability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAverageTotalStability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAmplitudeStability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsAmplitudeStabilityMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAmplitudeStabilityMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAmplitudeStabilityMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsAmplitudeStabilityStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseStability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseStabilityMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseStabilityMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseStabilityMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsPhaseStabilityStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTotalStability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTotalStabilityMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTotalStabilityMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTotalStabilityMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTotalStabilityStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeMainlobeWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeMainlobeWidthMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeMainlobeWidthMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeMainlobeWidthMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeMainlobeWidthStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeDelayMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeDelayMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeDelayMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeDelayStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakSidelobeLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakSidelobeLevelMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakSidelobeLevelMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakSidelobeLevelMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakSidelobeLevelStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeCompressionRatio(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeCompressionRatioMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeCompressionRatioMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeCompressionRatioMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobeCompressionRatioStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakCorrelation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakCorrelationMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakCorrelationMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakCorrelationMinimum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxPulse_PulseGetResultsTimeSidelobePeakCorrelationStandardDeviation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif


#endif

