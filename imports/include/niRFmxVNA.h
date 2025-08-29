
/****************************************************************************************************
*          National Instruments RFmx VNA
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2024.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxVNA.h
*
* Purpose:  National Instruments RFmx VNA,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_VNA_H__
#define __NI_RFMX_VNA_H__

#include "niRFmxInstr.h"

#define RFMXVNA_ATTR_TRIGGER_TYPE                                                0x00d00042
#define RFMXVNA_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                 0x00d00043
#define RFMXVNA_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                   0x00d00044
#define RFMXVNA_ATTR_TRIGGER_MODE                                                0x00d00045
#define RFMXVNA_ATTR_TRIGGER_DELAY                                               0x00d00070
#define RFMXVNA_ATTR_READY_FOR_TRIGGER_EVENT_OUTPUT_TERMINAL                     0x00d00063
#define RFMXVNA_ATTR_READY_FOR_TRIGGER_EVENT_TERMINAL_NAME                       0x00d00064
#define RFMXVNA_ATTR_READY_FOR_TRIGGER_EVENT_LEVEL                               0x00d00065
#define RFMXVNA_ATTR_INDEX_EVENT_OUTPUT_TERMINAL                                 0x00d00066
#define RFMXVNA_ATTR_INDEX_EVENT_TERMINAL_NAME                                   0x00d00067
#define RFMXVNA_ATTR_INDEX_EVENT_LEVEL                                           0x00d00068
#define RFMXVNA_ATTR_SWEEP_TYPE                                                  0x00d0002e
#define RFMXVNA_ATTR_FREQUENCY_LIST                                              0x00d00002
#define RFMXVNA_ATTR_START_FREQUENCY                                             0x00d00051
#define RFMXVNA_ATTR_STOP_FREQUENCY                                              0x00d00052
#define RFMXVNA_ATTR_CW_FREQUENCY                                                0x00d0006a
#define RFMXVNA_ATTR_NUMBER_OF_POINTS                                            0x00d00053
#define RFMXVNA_ATTR_POWER_LEVEL                                                 0x00d00003
#define RFMXVNA_ATTR_TEST_RECEIVER_ATTENUATION                                   0x00d0000a
#define RFMXVNA_ATTR_IF_BANDWIDTH                                                0x00d00004
#define RFMXVNA_ATTR_AUTO_IF_BANDWIDTH_SCALING_ENABLED                           0x00d00046
#define RFMXVNA_ATTR_SWEEP_SEQUENCE                                              0x00d0002d
#define RFMXVNA_ATTR_SWEEP_DELAY                                                 0x00d00005
#define RFMXVNA_ATTR_DWELL_TIME                                                  0x00d00006
#define RFMXVNA_ATTR_NUMBER_OF_SEGMENTS                                          0x00d00001
#define RFMXVNA_ATTR_SEGMENT_ENABLED                                             0x00d0002f
#define RFMXVNA_ATTR_SEGMENT_START_FREQUENCY                                     0x00d00054
#define RFMXVNA_ATTR_SEGMENT_STOP_FREQUENCY                                      0x00d00055
#define RFMXVNA_ATTR_SEGMENT_NUMBER_OF_FREQUENCY_POINTS                          0x00d00056
#define RFMXVNA_ATTR_SEGMENT_POWER_LEVEL_ENABLED                                 0x00d00048
#define RFMXVNA_ATTR_SEGMENT_POWER_LEVEL                                         0x00d00049
#define RFMXVNA_ATTR_SEGMENT_IF_BANDWIDTH_ENABLED                                0x00d0004a
#define RFMXVNA_ATTR_SEGMENT_IF_BANDWIDTH                                        0x00d0004b
#define RFMXVNA_ATTR_SEGMENT_TEST_RECEIVER_ATTENUATION_ENABLED                   0x00d0004c
#define RFMXVNA_ATTR_SEGMENT_TEST_RECEIVER_ATTENUATION                           0x00d0004d
#define RFMXVNA_ATTR_SEGMENT_DWELL_TIME_ENABLED                                  0x00d0004e
#define RFMXVNA_ATTR_SEGMENT_DWELL_TIME                                          0x00d0004f
#define RFMXVNA_ATTR_PULSE_MODE_ENABLED                                          0x00d00031
#define RFMXVNA_ATTR_PULSE_TRIGGER_TYPE                                          0x00d00033
#define RFMXVNA_ATTR_PULSE_DIGITAL_EDGE_TRIGGER_SOURCE                           0x00d00034
#define RFMXVNA_ATTR_PULSE_PERIOD                                                0x00d00035
#define RFMXVNA_ATTR_PULSE_MODULATOR_DELAY                                       0x00d00037
#define RFMXVNA_ATTR_PULSE_MODULATOR_WIDTH                                       0x00d00038
#define RFMXVNA_ATTR_PULSE_ACQUISITION_AUTO                                      0x00d00039
#define RFMXVNA_ATTR_PULSE_ACQUISITION_DELAY                                     0x00d0003a
#define RFMXVNA_ATTR_PULSE_ACQUISITION_WIDTH                                     0x00d0003b
#define RFMXVNA_ATTR_PULSE_GENERATOR_ENABLED                                     0x00d0003e
#define RFMXVNA_ATTR_PULSE_GENERATOR_EXPORT_OUTPUT_TERMINAL                      0x00d0003f
#define RFMXVNA_ATTR_PULSE_GENERATOR_TERMINAL_NAME                               0x00d00050
#define RFMXVNA_ATTR_PULSE_GENERATOR_DELAY                                       0x00d00040
#define RFMXVNA_ATTR_PULSE_GENERATOR_WIDTH                                       0x00d00041
#define RFMXVNA_ATTR_X_AXIS_VALUES                                               0x00d00057
#define RFMXVNA_ATTR_AVERAGING_ENABLED                                           0x00d00007
#define RFMXVNA_ATTR_AVERAGING_COUNT                                             0x00d00008
#define RFMXVNA_ATTR_CORRECTION_ENABLED                                          0x00d0000b
#define RFMXVNA_ATTR_CORRECTION_INTERPOLATION_ENABLED                            0x00d00058
#define RFMXVNA_ATTR_CORRECTION_PORT_SUBSET_ENABLED                              0x00d0000e
#define RFMXVNA_ATTR_CORRECTION_PORT_SUBSET_PORTS                                0x00d0000f
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_ENABLED                           0x00d00026
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DELAY_DOMAIN                      0x00d0005f
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DELAY                             0x00d00027
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DISTANCE                          0x00d00060
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DISTANCE_UNIT                     0x00d00061
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_VELOCITY_FACTOR                   0x00d00062
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DC_LOSS_ENABLED                   0x00d00028
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DC_LOSS                           0x00d00029
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS1_ENABLED                     0x00d00059
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS1_FREQUENCY                   0x00d0005a
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS1                             0x00d0005b
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS2_ENABLED                     0x00d0005c
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS2_FREQUENCY                   0x00d0005d
#define RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS2                             0x00d0005e
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_PORTS                                0x00d00010
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_CONNECTOR_TYPE                       0x00d00011
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_CALKIT_TYPE                          0x00d00012
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_CALKIT_ELECTRONIC_RESOURCE_NAME      0x00d00013
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_CALKIT_ELECTRONIC_ORIENTATION        0x00d0001e
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_CALKIT_MECHANICAL_NAME               0x00d00014
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_METHOD                               0x00d00015
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_THRU_METHOD                          0x00d00017
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_THRU_COAX_DELAY                      0x00d00018
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_STEP_COUNT                           0x00d00019
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_STEP_DESCRIPTION                     0x00d0001a
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_STEP_VCAL_ORIENTATION                0x00d00071
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_STEP_PORT_ASSIGNMENT                 0x00d00072
#define RFMXVNA_ATTR_CORRECTION_CALIBRATION_ESTIMATED_THRU_DELAY                 0x00d00800
#define RFMXVNA_ATTR_SPARAMS_MEASUREMENT_ENABLED                                 0x00d01000
#define RFMXVNA_ATTR_SPARAMS_NUMBER_OF_SPARAMETERS                               0x00d01002
#define RFMXVNA_ATTR_SPARAMS_RECEIVER_PORT                                       0x00d01003
#define RFMXVNA_ATTR_SPARAMS_SOURCE_PORT                                         0x00d01004
#define RFMXVNA_ATTR_SPARAMS_FORMAT                                              0x00d01005
#define RFMXVNA_ATTR_SPARAMS_MAGNITUDE_UNITS                                     0x00d01006
#define RFMXVNA_ATTR_SPARAMS_PHASE_TRACE_TYPE                                    0x00d01007
#define RFMXVNA_ATTR_SPARAMS_GROUP_DELAY_APERTURE_MODE                           0x00d0101c
#define RFMXVNA_ATTR_SPARAMS_GROUP_DELAY_APERTURE_POINTS                         0x00d0101d
#define RFMXVNA_ATTR_SPARAMS_GROUP_DELAY_APERTURE_PERCENTAGE                     0x00d0101e
#define RFMXVNA_ATTR_SPARAMS_GROUP_DELAY_APERTURE_FREQUENCY_SPAN                 0x00d0101f
#define RFMXVNA_ATTR_SPARAMS_MATH_FUNCTION                                       0x00d0101a
#define RFMXVNA_ATTR_SPARAMS_MATH_ACTIVE_MEASUREMENT_MEMORY                      0x00d0101b
#define RFMXVNA_ATTR_SPARAMS_RESULTS_CORRECTION_STATE                            0x00d01018
#define RFMXVNA_ATTR_SPARAMS_RESULTS_CORRECTION_LEVEL                            0x00d01020
#define RFMXVNA_ATTR_SPARAMS_SNP_DATA_FORMAT                                     0x00d01013
#define RFMXVNA_ATTR_SPARAMS_SNP_USER_COMMENT                                    0x00d01014
#define RFMXVNA_ATTR_SPARAMS_SNP_PORTS                                           0x00d01015
#define RFMXVNA_ATTR_WAVES_MEASUREMENT_ENABLED                                   0x00d02000
#define RFMXVNA_ATTR_WAVES_NUMBER_OF_WAVES                                       0x00d02002
#define RFMXVNA_ATTR_WAVES_RECEIVER                                              0x00d02003
#define RFMXVNA_ATTR_WAVES_RECEIVER_PORT                                         0x00d02004
#define RFMXVNA_ATTR_WAVES_SOURCE_PORT                                           0x00d02005
#define RFMXVNA_ATTR_WAVES_FORMAT                                                0x00d02006
#define RFMXVNA_ATTR_WAVES_MAGNITUDE_UNITS                                       0x00d02007
#define RFMXVNA_ATTR_WAVES_PHASE_TRACE_TYPE                                      0x00d02008
#define RFMXVNA_ATTR_WAVES_GROUP_DELAY_APERTURE_MODE                             0x00d02015
#define RFMXVNA_ATTR_WAVES_GROUP_DELAY_APERTURE_POINTS                           0x00d02016
#define RFMXVNA_ATTR_WAVES_GROUP_DELAY_APERTURE_PERCENTAGE                       0x00d02017
#define RFMXVNA_ATTR_WAVES_GROUP_DELAY_APERTURE_FREQUENCY_SPAN                   0x00d02018
#define RFMXVNA_ATTR_WAVES_RESULTS_CORRECTION_STATE                              0x00d02013
#define RFMXVNA_ATTR_WAVES_RESULTS_CORRECTION_LEVEL                              0x00d02019
#define RFMXVNA_ATTR_IQ_MEASUREMENT_ENABLED                                      0x00d0100a
#define RFMXVNA_ATTR_IQ_ACQUISITION_TIME                                         0x00d0100d
#define RFMXVNA_ATTR_IQ_RECEIVER_PORT                                            0x00d0100f
#define RFMXVNA_ATTR_IQ_SOURCE_PORT                                              0x00d01010
#define RFMXVNA_ATTR_IQ_RESULTS_CORRECTION_STATE                                 0x00d01019
#define RFMXVNA_ATTR_LIMITED_CONFIGURATION_CHANGE                                0x00d0200b
#define RFMXVNA_ATTR_SOURCE_POWER_MODE                                           0x00d0200c
#define RFMXVNA_ATTR_GROUND_TERMINATED_PORTS                                     0x00d0200d
#define RFMXVNA_ATTR_RESULT_FETCH_TIMEOUT                                        0x00d0c000

// Values for RFMXVNA_ATTR_TRIGGER_TYPE
#define RFMXVNA_VAL_TRIGGER_TYPE_NONE                                                                             0
#define RFMXVNA_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                                     1
#define RFMXVNA_VAL_TRIGGER_TYPE_SOFTWARE                                                                         2

// Values for RFMXVNA_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXVNA_VAL_PFI0_STR                                                                                      "PFI0"
#define RFMXVNA_VAL_PFI1_STR                                                                                      "PFI1"
#define RFMXVNA_VAL_PXI_TRIG0_STR                                                                                 "PXI_Trig0"
#define RFMXVNA_VAL_PXI_TRIG1_STR                                                                                 "PXI_Trig1"
#define RFMXVNA_VAL_PXI_TRIG2_STR                                                                                 "PXI_Trig2"
#define RFMXVNA_VAL_PXI_TRIG3_STR                                                                                 "PXI_Trig3"
#define RFMXVNA_VAL_PXI_TRIG4_STR                                                                                 "PXI_Trig4"
#define RFMXVNA_VAL_PXI_TRIG5_STR                                                                                 "PXI_Trig5"
#define RFMXVNA_VAL_PXI_TRIG6_STR                                                                                 "PXI_Trig6"
#define RFMXVNA_VAL_PXI_TRIG7_STR                                                                                 "PXI_Trig7"
#define RFMXVNA_VAL_PXI_STAR_STR                                                                                  "PXI_STAR"
#define RFMXVNA_VAL_PXIE_DSTARB_STR                                                                               "PXIe_DStarB"
#define RFMXVNA_VAL_TIMER_EVENT_STR                                                                               "TimerEvent"

// Values for RFMXVNA_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXVNA_VAL_DIGITAL_EDGE_RISING_EDGE                                                                      0
#define RFMXVNA_VAL_DIGITAL_EDGE_FALLING_EDGE                                                                     1

// Values for RFMXVNA_ATTR_TRIGGER_MODE
#define RFMXVNA_VAL_TRIGGER_MODE_SIGNAL                                                                           0
#define RFMXVNA_VAL_TRIGGER_MODE_SWEEP                                                                            1
#define RFMXVNA_VAL_TRIGGER_MODE_POINT                                                                            2
#define RFMXVNA_VAL_TRIGGER_MODE_SEGMENT                                                                          3

// Values for RFMXVNA_ATTR_READY_FOR_TRIGGER_EVENT_LEVEL
#define RFMXVNA_VAL_READY_FOR_TRIGGER_EVENT_LEVEL_ACTIVE_HIGH                                                     0
#define RFMXVNA_VAL_READY_FOR_TRIGGER_EVENT_LEVEL_ACTIVE_LOW                                                      1

// Values for RFMXVNA_ATTR_INDEX_EVENT_LEVEL
#define RFMXVNA_VAL_INDEX_EVENT_LEVEL_ACTIVE_HIGH                                                                 0
#define RFMXVNA_VAL_INDEX_EVENT_LEVEL_ACTIVE_LOW                                                                  1

// Values for RFMXVNA_ATTR_SWEEP_TYPE
#define RFMXVNA_VAL_SWEEP_TYPE_LIST                                                                               0
#define RFMXVNA_VAL_SWEEP_TYPE_LINEAR                                                                             1
#define RFMXVNA_VAL_SWEEP_TYPE_SEGMENT                                                                            2
#define RFMXVNA_VAL_SWEEP_TYPE_CW_TIME                                                                            4

// Values for RFMXVNA_ATTR_AUTO_IF_BANDWIDTH_SCALING_ENABLED
#define RFMXVNA_VAL_AUTO_IF_BANDWIDTH_SCALING_ENABLED_FALSE                                                       0
#define RFMXVNA_VAL_AUTO_IF_BANDWIDTH_SCALING_ENABLED_TRUE                                                        1

// Values for RFMXVNA_ATTR_SWEEP_SEQUENCE
#define RFMXVNA_VAL_SWEEP_SEQUENCE_STANDARD                                                                       0
#define RFMXVNA_VAL_SWEEP_SEQUENCE_POINT                                                                          1

// Values for RFMXVNA_ATTR_SEGMENT_ENABLED
#define RFMXVNA_VAL_SEGMENT_ENABLED_FALSE                                                                         0
#define RFMXVNA_VAL_SEGMENT_ENABLED_TRUE                                                                          1

// Values for RFMXVNA_ATTR_SEGMENT_POWER_LEVEL_ENABLED
#define RFMXVNA_VAL_SEGMENT_POWER_LEVEL_ENABLED_FALSE                                                             0
#define RFMXVNA_VAL_SEGMENT_POWER_LEVEL_ENABLED_TRUE                                                              1

// Values for RFMXVNA_ATTR_SEGMENT_IF_BANDWIDTH_ENABLED
#define RFMXVNA_VAL_SEGMENT_IF_BANDWIDTH_ENABLED_FALSE                                                            0
#define RFMXVNA_VAL_SEGMENT_IF_BANDWIDTH_ENABLED_TRUE                                                             1

// Values for RFMXVNA_ATTR_SEGMENT_TEST_RECEIVER_ATTENUATION_ENABLED
#define RFMXVNA_VAL_SEGMENT_TEST_RECEIVER_ATTENUATION_ENABLED_FALSE                                               0
#define RFMXVNA_VAL_SEGMENT_TEST_RECEIVER_ATTENUATION_ENABLED_TRUE                                                1

// Values for RFMXVNA_ATTR_SEGMENT_DWELL_TIME_ENABLED
#define RFMXVNA_VAL_SEGMENT_DWELL_TIME_ENABLED_FALSE                                                              0
#define RFMXVNA_VAL_SEGMENT_DWELL_TIME_ENABLED_TRUE                                                               1

// Values for RFMXVNA_ATTR_PULSE_MODE_ENABLED
#define RFMXVNA_VAL_PULSE_MODE_ENABLED_FALSE                                                                      0
#define RFMXVNA_VAL_PULSE_MODE_ENABLED_TRUE                                                                       1

// Values for RFMXVNA_ATTR_PULSE_TRIGGER_TYPE
#define RFMXVNA_VAL_PULSE_TRIGGER_TYPE_NONE                                                                       0
#define RFMXVNA_VAL_PULSE_TRIGGER_TYPE_DIGITAL_EDGE                                                               1

// Values for RFMXVNA_ATTR_PULSE_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXVNA_VAL_PFI0_STR                                                                                      "PFI0"
#define RFMXVNA_VAL_PFI1_STR                                                                                      "PFI1"
#define RFMXVNA_VAL_PXI_TRIG0_STR                                                                                 "PXI_Trig0"
#define RFMXVNA_VAL_PXI_TRIG1_STR                                                                                 "PXI_Trig1"
#define RFMXVNA_VAL_PXI_TRIG2_STR                                                                                 "PXI_Trig2"
#define RFMXVNA_VAL_PXI_TRIG3_STR                                                                                 "PXI_Trig3"
#define RFMXVNA_VAL_PXI_TRIG4_STR                                                                                 "PXI_Trig4"
#define RFMXVNA_VAL_PXI_TRIG5_STR                                                                                 "PXI_Trig5"
#define RFMXVNA_VAL_PXI_TRIG6_STR                                                                                 "PXI_Trig6"
#define RFMXVNA_VAL_PXI_TRIG7_STR                                                                                 "PXI_Trig7"
#define RFMXVNA_VAL_PXI_STAR_STR                                                                                  "PXI_STAR"
#define RFMXVNA_VAL_PXIE_DSTARB_STR                                                                               "PXIe_DStarB"

// Values for RFMXVNA_ATTR_PULSE_ACQUISITION_AUTO
#define RFMXVNA_VAL_PULSE_ACQUISITION_AUTO_FALSE                                                                  0
#define RFMXVNA_VAL_PULSE_ACQUISITION_AUTO_TRUE                                                                   1

// Values for RFMXVNA_ATTR_PULSE_GENERATOR_ENABLED
#define RFMXVNA_VAL_PULSE_GENERATOR_ENABLED_FALSE                                                                 0
#define RFMXVNA_VAL_PULSE_GENERATOR_ENABLED_TRUE                                                                  1

// Values for RFMXVNA_ATTR_AVERAGING_ENABLED
#define RFMXVNA_VAL_AVERAGING_ENABLED_FALSE                                                                       0
#define RFMXVNA_VAL_AVERAGING_ENABLED_TRUE                                                                        1

// Values for RFMXVNA_ATTR_CORRECTION_ENABLED
#define RFMXVNA_VAL_CORRECTION_ENABLED_FALSE                                                                      0
#define RFMXVNA_VAL_CORRECTION_ENABLED_TRUE                                                                       1

// Values for RFMXVNA_ATTR_CORRECTION_INTERPOLATION_ENABLED
#define RFMXVNA_VAL_CORRECTION_INTERPOLATION_ENABLED_FALSE                                                        0
#define RFMXVNA_VAL_CORRECTION_INTERPOLATION_ENABLED_TRUE                                                         1

// Values for RFMXVNA_ATTR_CORRECTION_PORT_SUBSET_ENABLED
#define RFMXVNA_VAL_CORRECTION_PORT_SUBSET_ENABLED_FALSE                                                          0
#define RFMXVNA_VAL_CORRECTION_PORT_SUBSET_ENABLED_TRUE                                                           1

// Values for RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_ENABLED
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_ENABLED_FALSE                                                       0
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_ENABLED_TRUE                                                        1

// Values for RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DELAY_DOMAIN
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_DELAY_DOMAIN_DELAY                                                  0
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_DELAY_DOMAIN_DISTANCE                                               1

// Values for RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DISTANCE_UNIT
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_DISTANCE_UNIT_METERS                                                0
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_DISTANCE_UNIT_FEET                                                  1
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_DISTANCE_UNIT_INCHES                                                2

// Values for RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_DC_LOSS_ENABLED
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_DC_LOSS_ENABLED_FALSE                                               0
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_DC_LOSS_ENABLED_TRUE                                                1

// Values for RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS1_ENABLED
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_LOSS1_ENABLED_FALSE                                                 0
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_LOSS1_ENABLED_TRUE                                                  1

// Values for RFMXVNA_ATTR_CORRECTION_PORT_EXTENSION_LOSS2_ENABLED
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_LOSS2_ENABLED_FALSE                                                 0
#define RFMXVNA_VAL_CORRECTION_PORT_EXTENSION_LOSS2_ENABLED_TRUE                                                  1

// Values for RFMXVNA_ATTR_CORRECTION_CALIBRATION_CALKIT_TYPE
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_CALKIT_TYPE_ELECTRONIC                                                 0
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_CALKIT_TYPE_MECHANICAL                                                 1

// Values for RFMXVNA_ATTR_CORRECTION_CALIBRATION_METHOD
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_METHOD_SOL                                                             0
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_METHOD_SOLT                                                            1
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_METHOD_TRL                                                             2

// Values for RFMXVNA_ATTR_CORRECTION_CALIBRATION_THRU_METHOD
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_THRU_METHOD_AUTO                                                       0
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_THRU_METHOD_DEFINED_THRU                                               1
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_THRU_METHOD_FLUSH_THRU                                                 2
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_THRU_METHOD_UNDEFINED_THRU                                             3
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_THRU_METHOD_VCAL_THRU_AS_UNKNOWN_THRU                                  5

// Values for RFMXVNA_ATTR_SPARAMS_FORMAT
#define RFMXVNA_VAL_SPARAMS_FORMAT_MAGNITUDE                                                                      0
#define RFMXVNA_VAL_SPARAMS_FORMAT_PHASE                                                                          1
#define RFMXVNA_VAL_SPARAMS_FORMAT_COMPLEX                                                                        2
#define RFMXVNA_VAL_SPARAMS_FORMAT_SWR                                                                            3
#define RFMXVNA_VAL_SPARAMS_FORMAT_SMITH_IMPEDANCE                                                                4
#define RFMXVNA_VAL_SPARAMS_FORMAT_SMITH_ADMITTANCE                                                               5
#define RFMXVNA_VAL_SPARAMS_FORMAT_POLAR                                                                          6
#define RFMXVNA_VAL_SPARAMS_FORMAT_GROUP_DELAY                                                                    7

// Values for RFMXVNA_ATTR_SPARAMS_MAGNITUDE_UNITS
#define RFMXVNA_VAL_SPARAMS_MAGNITUDE_UNITS_DB                                                                    0
#define RFMXVNA_VAL_SPARAMS_MAGNITUDE_UNITS_LINEAR                                                                1

// Values for RFMXVNA_ATTR_SPARAMS_PHASE_TRACE_TYPE
#define RFMXVNA_VAL_SPARAMS_PHASE_TRACE_TYPE_WRAPPED                                                              0
#define RFMXVNA_VAL_SPARAMS_PHASE_TRACE_TYPE_UNWRAPPED                                                            1

// Values for RFMXVNA_ATTR_SPARAMS_GROUP_DELAY_APERTURE_MODE
#define RFMXVNA_VAL_SPARAMS_GROUP_DELAY_APERTURE_MODE_POINTS                                                      0
#define RFMXVNA_VAL_SPARAMS_GROUP_DELAY_APERTURE_MODE_PERCENTAGE                                                  1
#define RFMXVNA_VAL_SPARAMS_GROUP_DELAY_APERTURE_MODE_FREQUENCY_SPAN                                              2

// Values for RFMXVNA_ATTR_SPARAMS_MATH_FUNCTION
#define RFMXVNA_VAL_SPARAMS_MATH_FUNCTION_OFF                                                                     0
#define RFMXVNA_VAL_SPARAMS_MATH_FUNCTION_ADD                                                                     1
#define RFMXVNA_VAL_SPARAMS_MATH_FUNCTION_SUBTRACT                                                                2
#define RFMXVNA_VAL_SPARAMS_MATH_FUNCTION_MULTIPLY                                                                3
#define RFMXVNA_VAL_SPARAMS_MATH_FUNCTION_DIVIDE                                                                  4

// Values for RFMXVNA_ATTR_SPARAMS_RESULTS_CORRECTION_STATE
#define RFMXVNA_VAL_SPARAMS_CORRECTION_STATE_NONE                                                                 0
#define RFMXVNA_VAL_SPARAMS_CORRECTION_STATE_CORRECTED                                                            1
#define RFMXVNA_VAL_SPARAMS_CORRECTION_STATE_INTERPOLATED                                                         2
#define RFMXVNA_VAL_SPARAMS_CORRECTION_STATE_SETTINGS_MODIFIED                                                    3

// Values for RFMXVNA_ATTR_SPARAMS_SNP_DATA_FORMAT
#define RFMXVNA_VAL_SPARAMS_SNP_DATA_FORMAT_AUTO                                                                  0
#define RFMXVNA_VAL_SPARAMS_SNP_DATA_FORMAT_LOG_MAGNITUDE_ANGLE                                                   1
#define RFMXVNA_VAL_SPARAMS_SNP_DATA_FORMAT_REAL_IMAGINARY                                                        2
#define RFMXVNA_VAL_SPARAMS_SNP_DATA_FORMAT_LINEAR_MAGNITUDE_ANGLE                                                3

// Values for RFMXVNA_ATTR_WAVES_RECEIVER
#define RFMXVNA_VAL_WAVES_RECEIVER_TEST                                                                           0
#define RFMXVNA_VAL_WAVES_RECEIVER_REFERENCE                                                                      1

// Values for RFMXVNA_ATTR_WAVES_FORMAT
#define RFMXVNA_VAL_WAVES_FORMAT_MAGNITUDE                                                                        0
#define RFMXVNA_VAL_WAVES_FORMAT_PHASE                                                                            1
#define RFMXVNA_VAL_WAVES_FORMAT_COMPLEX                                                                          2
#define RFMXVNA_VAL_WAVES_FORMAT_SWR                                                                              3
#define RFMXVNA_VAL_WAVES_FORMAT_SMITH_IMPEDANCE                                                                  4
#define RFMXVNA_VAL_WAVES_FORMAT_SMITH_ADMITTANCE                                                                 5
#define RFMXVNA_VAL_WAVES_FORMAT_POLAR                                                                            6
#define RFMXVNA_VAL_WAVES_FORMAT_GROUP_DELAY                                                                      7

// Values for RFMXVNA_ATTR_WAVES_MAGNITUDE_UNITS
#define RFMXVNA_VAL_WAVES_MAGNITUDE_UNITS_DBM                                                                     0
#define RFMXVNA_VAL_WAVES_MAGNITUDE_UNITS_DBMV                                                                    1
#define RFMXVNA_VAL_WAVES_MAGNITUDE_UNITS_DBUV                                                                    2
#define RFMXVNA_VAL_WAVES_MAGNITUDE_UNITS_DBMA                                                                    3
#define RFMXVNA_VAL_WAVES_MAGNITUDE_UNITS_W                                                                       4
#define RFMXVNA_VAL_WAVES_MAGNITUDE_UNITS_V                                                                       5
#define RFMXVNA_VAL_WAVES_MAGNITUDE_UNITS_A                                                                       6

// Values for RFMXVNA_ATTR_WAVES_PHASE_TRACE_TYPE
#define RFMXVNA_VAL_WAVES_PHASE_TRACE_TYPE_WRAPPED                                                                0
#define RFMXVNA_VAL_WAVES_PHASE_TRACE_TYPE_UNWRAPPED                                                              1

// Values for RFMXVNA_ATTR_WAVES_GROUP_DELAY_APERTURE_MODE
#define RFMXVNA_VAL_WAVES_GROUP_DELAY_APERTURE_MODE_POINTS                                                        0
#define RFMXVNA_VAL_WAVES_GROUP_DELAY_APERTURE_MODE_PERCENTAGE                                                    1
#define RFMXVNA_VAL_WAVES_GROUP_DELAY_APERTURE_MODE_FREQUENCY_SPAN                                                2

// Values for RFMXVNA_ATTR_WAVES_RESULTS_CORRECTION_STATE
#define RFMXVNA_VAL_WAVES_CORRECTION_STATE_NONE                                                                   0
#define RFMXVNA_VAL_WAVES_CORRECTION_STATE_CORRECTED                                                              1
#define RFMXVNA_VAL_WAVES_CORRECTION_STATE_INTERPOLATED                                                           2
#define RFMXVNA_VAL_WAVES_CORRECTION_STATE_SETTINGS_MODIFIED                                                      3

// Values for RFMXVNA_ATTR_IQ_RESULTS_CORRECTION_STATE
#define RFMXVNA_VAL_IQ_CORRECTION_STATE_NONE                                                                      0
#define RFMXVNA_VAL_IQ_CORRECTION_STATE_CORRECTED                                                                 1
#define RFMXVNA_VAL_IQ_CORRECTION_STATE_INTERPOLATED                                                              2
#define RFMXVNA_VAL_IQ_CORRECTION_STATE_SETTINGS_MODIFIED                                                         3

// Values for RFMXVNA_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXVNA_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                                         0
#define RFMXVNA_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                                        1

// Values for RFMXVNA_ATTR_SOURCE_POWER_MODE
#define RFMXVNA_VAL_SOURCE_POWER_MODE_AUTO                                                                        0
#define RFMXVNA_VAL_SOURCE_POWER_MODE_OFF                                                                         1

// Values for FrequencyReferenceSource
#define RFMXVNA_VAL_ONBOARD_CLOCK_STR                                                                             "OnboardClock"
#define RFMXVNA_VAL_REF_IN_STR                                                                                    "RefIn"
#define RFMXVNA_VAL_PXI_CLK_STR                                                                                   "PXI_Clk"
#define RFMXVNA_VAL_CLK_IN_STR                                                                                    "ClkIn"
#define RFMXVNA_VAL_REF_IN2_STR                                                                                   "RefIn2"
#define RFMXVNA_VAL_PXI_CLK_MASTER_STR                                                                            "PXI_Clk_Master"

// Values for Boolean
#define RFMXVNA_VAL_FALSE                                                                                         0
#define RFMXVNA_VAL_TRUE                                                                                          1

// Values for RestoreConfiguration
#define RFMXVNA_VAL_RESTORE_CONFIGURATION_NONE                                                                    0
#define RFMXVNA_VAL_RESTORE_CONFIGURATION_STIMULUS                                                                1

// Values for MeasurementTypes
#define RFMXVNA_VAL_SPARAMS                                                                                       1<<0
#define RFMXVNA_VAL_WAVES                                                                                         1<<1
#define RFMXVNA_VAL_IQ                                                                                            1<<2

// Values for CalFrequencyGrid
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_DIRECTIVITY                                                                0
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_SOURCE_MATCH                                                               1
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_REFLECTION_TRACKING                                                        2
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_TRANSMISSION_TRACKING                                                      3
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_LOAD_MATCH                                                                 4
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_K                                                                          5
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_ALPHA                                                                      6
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_BETA                                                                       7
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_GAMMA                                                                      8
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_DELTA                                                                      9
#define RFMXVNA_VAL_CAL_FREQUENCY_GRID_SWITCH_TERM                                                                10

// Values for CalErrorTerm
#define RFMXVNA_VAL_CAL_ERROR_TERM_DIRECTIVITY                                                                    0
#define RFMXVNA_VAL_CAL_ERROR_TERM_SOURCE_MATCH                                                                   1
#define RFMXVNA_VAL_CAL_ERROR_TERM_REFLECTION_TRACKING                                                            2
#define RFMXVNA_VAL_CAL_ERROR_TERM_TRANSMISSION_TRACKING                                                          3
#define RFMXVNA_VAL_CAL_ERROR_TERM_LOAD_MATCH                                                                     4
#define RFMXVNA_VAL_CAL_ERROR_TERM_K                                                                              5
#define RFMXVNA_VAL_CAL_ERROR_TERM_ALPHA                                                                          6
#define RFMXVNA_VAL_CAL_ERROR_TERM_BETA                                                                           7
#define RFMXVNA_VAL_CAL_ERROR_TERM_GAMMA                                                                          8
#define RFMXVNA_VAL_CAL_ERROR_TERM_DELTA                                                                          9
#define RFMXVNA_VAL_CAL_ERROR_TERM_SWITCH_TERM                                                                    10

// Values for SParameterOrientation
#define RFMXVNA_VAL_SPARAMETER_ORIENTATION_PORT1_TOWARDS_VNA                                                      0
#define RFMXVNA_VAL_SPARAMETER_ORIENTATION_PORT2_TOWARDS_VNA                                                      1

// Values for CalkitManagerCalkitConnectorGender
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CONNECTOR_GENDER_MALE                                                   0
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CONNECTOR_GENDER_FEMALE                                                 1
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CONNECTOR_GENDER_NO_GENDER                                              2

// Values for CalkitManagerCalkitTrlReferencePlane
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_TRL_REFERENCE_PLANE_THRU                                                0
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_TRL_REFERENCE_PLANE_REFLECT                                             1

// Values for CalkitManagerCalkitCalibrationElementType
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_TYPE_LOAD                                           0
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_TYPE_OPEN                                           1
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_TYPE_SHORT                                          2
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_TYPE_THRU                                           3
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_TYPE_LINE                                           4
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_TYPE_REFLECT                                        5
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_TYPE_TERMINATION                                    6

// Values for CalkitManagerCalkitCalibrationElementSParameterDefinition
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_SPARAMETER_DEFINITION_REFLECT_MODEL                 0
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_SPARAMETER_DEFINITION_SPARAMETER                    1
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_SPARAMETER_DEFINITION_DELAY_MODEL                   2
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_SPARAMETER_DEFINITION_UNKNOWN                       3

// Values for CalkitManagerCalkitCalibrationElementReflectModelType
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_REFLECT_MODEL_TYPE_REFLECT_OPEN                     0
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_REFLECT_MODEL_TYPE_REFLECT_SHORT                    1
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_REFLECT_MODEL_TYPE_LOAD                             2

// Values for CalkitManagerCalkitCalibrationElementReflectModelSParameterAvailability
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_REFLECT_MODEL_SPARAMETER_AVAILABILITY_ESTIMATE      0
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_REFLECT_MODEL_SPARAMETER_AVAILABILITY_KNOWN         1

// Values for CalkitManagerCalkitCalibrationElementSParameterAvailability
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_SPARAMETER_AVAILABILITY_ESTIMATE                    0
#define RFMXVNA_VAL_CALKIT_MANAGER_CALKIT_CALIBRATION_ELEMENT_SPARAMETER_AVAILABILITY_KNOWN                       1

// Values for MarkerSearchMode
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_NONE                                                                       0
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_MAX                                                                        1
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_MIN                                                                        2
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_PEAK                                                                       3
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_NEXT_PEAK                                                                  4
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_NEXT_LEFT_PEAK                                                             5
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_NEXT_RIGHT_PEAK                                                            6
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_TARGET                                                                     7
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_NEXT_LEFT_TARGET                                                           8
#define RFMXVNA_VAL_MARKER_SEARCH_MODE_NEXT_RIGHT_TARGET                                                          9

// Values for MarkerType
#define RFMXVNA_VAL_MARKER_TYPE_OFF                                                                               0
#define RFMXVNA_VAL_MARKER_TYPE_NORMAL                                                                            1
#define RFMXVNA_VAL_MARKER_TYPE_DELTA                                                                             2
#define RFMXVNA_VAL_MARKER_TYPE_FIXED                                                                             3

// Values for MarkerPeakSearchThresholdEnabled
#define RFMXVNA_VAL_MARKER_PEAK_SEARCH_THRESHOLD_ENABLED_FALSE                                                    0
#define RFMXVNA_VAL_MARKER_PEAK_SEARCH_THRESHOLD_ENABLED_TRUE                                                     1

// Values for MarkerPeakSearchExcursionEnabled
#define RFMXVNA_VAL_MARKER_PEAK_SEARCH_EXCURSION_ENABLED_FALSE                                                    0
#define RFMXVNA_VAL_MARKER_PEAK_SEARCH_EXCURSION_ENABLED_TRUE                                                     1

// Values for MarkerMode
#define RFMXVNA_VAL_MARKER_MODE_CONTINUOUS                                                                        0
#define RFMXVNA_VAL_MARKER_MODE_DISCRETE                                                                          1

// Values for RFAttenuationAuto
#define RFMXVNA_VAL_RF_ATTENUATION_AUTO_FALSE                                                                     0
#define RFMXVNA_VAL_RF_ATTENUATION_AUTO_TRUE                                                                      1

// Values for MechanicalAttenuationAuto
#define RFMXVNA_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                                             0
#define RFMXVNA_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                                              1

/* ---------------- RFmxVNA APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxVNA_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxVNA_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxVNA_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxVNA_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxVNA_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxVNA_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxVNA_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxVNA_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxVNA_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxVNA_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxVNA_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxVNA_BuildPortString(
   char selectorString[],
   char portString[],
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildSegmentString(
   char selectorString[],
   int32 segmentNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildSParameterString(
   char selectorString[],
   int32 sParameterNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildWaveString(
   char selectorString[],
   int32 waveNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildCalstepString(
   char selectorString[],
   int32 calstepNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildCalkitString(
   char selectorString[],
   char calkitID[],
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildConnectorString(
   char selectorString[],
   char connectorID[],
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildCalibrationElementString(
   char selectorString[],
   char calibrationElementID[],
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildPulseGeneratorString(
   char selectorString[],
   int32 pulseGeneratorNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildMarkerString(
   char selectorString[],
   int32 markerNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_BuildMeasurementMemoryString(
   char selectorString[],
   char measurementMemoryName[],
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxVNA_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxVNA_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxVNA_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsCfgSParameter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char sParameter[]
);

int32 __stdcall RFmxVNA_SParamsExportToSnPFile(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char snpFilePath[]
);

int32 __stdcall RFmxVNA_WavesCfgWave(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char wave[]
);

int32 __stdcall RFmxVNA_CalibrationInitiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_CalibrationAcquire(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxVNA_CalibrationAbort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_CalibrationSave(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[]
);

int32 __stdcall RFmxVNA_ClearCalset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[]
);

int32 __stdcall RFmxVNA_CalsetLoadFromFile(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[],
   char calsetFilePath[]
);

int32 __stdcall RFmxVNA_CalsetSaveToFile(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[],
   char calsetFilePath[]
);

int32 __stdcall RFmxVNA_AutoDetectvCalOrientation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxVNA_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_CopyCalset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char sourceCalsetName[],
   char newCalsetName[]
);

int32 __stdcall RFmxVNA_SelectActiveCalset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[],
   int32 restoreConfiguration
);

int32 __stdcall RFmxVNA_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxVNA_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxVNA_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxVNA_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxVNA_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxVNA_CalsetEmbedFixtureS2p(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[],
   char fixtureS2pFilePath[],
   char vnaPort[],
   int32 sParameterOrientation,
   char newCalsetName[]
);

int32 __stdcall RFmxVNA_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxVNA_DeselectActiveCalset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_LoadDataToMeasurementMemoryFromFile(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char filePath[],
   char parameter[],
   char measurementMemoryName[]
);

int32 __stdcall RFmxVNA_CopyDataToMeasurementMemory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char measurementMemoryName[]
);

int32 __stdcall RFmxVNA_ClearMeasurementMemoryNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_CalkitManagerImportCalkit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calkitFilePath[]
);

int32 __stdcall RFmxVNA_CalkitManagerExportCalkit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calkitID[],
   char calkitFilePath[]
);

int32 __stdcall RFmxVNA_CalkitManagerCreateCalkit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calkitID[]
);

int32 __stdcall RFmxVNA_CalkitManagerRemoveCalkit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calkitID[]
);

int32 __stdcall RFmxVNA_CalkitManagerValidateCalkit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calkitID[]
);

int32 __stdcall RFmxVNA_CalkitManagerGetCalkitIDs(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char calkitIDs[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitAddConnector(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char connectorID[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitRemoveConnector(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char connectorID[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitGetConnectorIDs(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char connectorIDs[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitAddCalibrationElement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calibrationElementID[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitRemoveCalibrationElement(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calibrationElementID[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitGetCalibrationElementIDs(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char calibrationElementIDs[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitSetDescription(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calkitDescription[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitGetDescription(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char calkitDescription[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitSetVersion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calkitVersion[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitGetVersion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char calkitVersion[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitSetTRLReferencePlane(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 referencePlane
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitSetLRLLineAutoChar(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 autoCharacterizationEnabled
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorSetDescription(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char description[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorGetDescription(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char description[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorSetGender(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 connectorGender
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorSetType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char connectorType[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorGetType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char connectorType[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorSetImpedance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 impedance
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorSetMinimumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 minimumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorSetMaximumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 maximumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSetDescription(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char description[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementGetDescription(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char description[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSetPortConnectors(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char connectorIDs[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementGetPortConnectors(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char connectorIDs[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSetSParameterDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sParameterDefinition
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSetMinimumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 minimumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSetMaximumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 maximumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetModelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 modelType
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetSParamAvailability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sParameterAvailability
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetC0(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 c0
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetC1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 c1
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetC2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 c2
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetC3(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 c3
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetOffsetDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetDelay
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetOffsetLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetLoss
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetOffsetZ0(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 offsetZ0
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelSetReferenceImpedance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceImpedance
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementDelayModelSetDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 delay
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetSParamAvailability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 sParameterAvailability
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetFromFile(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char fileName[]
);

int32 __stdcall RFmxVNA_MarkerCfgNumberOfMarkers(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 numberOfMarkers
);

int32 __stdcall RFmxVNA_MarkerCfgType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 markerType
);

int32 __stdcall RFmxVNA_MarkerCfgReferenceMarker(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 referenceMarker
);

int32 __stdcall RFmxVNA_MarkerCfgDataSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char dataSource[]
);

int32 __stdcall RFmxVNA_MarkerCfgPeakSearchThreshold(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 thresholdEnabled,
   float64 threshold
);

int32 __stdcall RFmxVNA_MarkerCfgPeakSearchExcursion(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 peakExcursionEnabled,
   float64 peakExcursion
);

int32 __stdcall RFmxVNA_MarkerCfgMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 markerMode
);

int32 __stdcall RFmxVNA_MarkerCfgTargetValue(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 targetValue
);

int32 __stdcall RFmxVNA_CfgCorrectionPortSubset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char portSubset[]
);

int32 __stdcall RFmxVNA_MarkerCfgX(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 markerX
);

int32 __stdcall RFmxVNA_MarkerCfgY(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 markerY1,
   float64 markerY2
);

int32 __stdcall RFmxVNA_CalsetGetFrequencyGrid(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[],
   int32 errorTermIdentifier,
   float64 frequencyGrid[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalsetGetErrorTerm(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[],
   int32 errorTermIdentifier,
   char measurementPort[],
   char sourcePort[],
   NIComplexSingle errorTerm[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalsetGetErrorTermSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char calsetName[],
   int32 errorTermIdentifier,
   char measurementPort[],
   char sourcePort[],
   float32 errorTermI[],
   float32 errorTermQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementGetTypes(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 calibrationElementTypes[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 frequency[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS11(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s11[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS11Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s11I[],
   float64 s11Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS12(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s12[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS12Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s12I[],
   float64 s12Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS21(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s21[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS21Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s21I[],
   float64 s21Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS22(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s22[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetS22Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s22I[],
   float64 s22Q[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_MarkerSearch(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 searchMode
);

int32 __stdcall RFmxVNA_MarkerFetchX(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* markerX
);

int32 __stdcall RFmxVNA_MarkerFetchY(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* markerY1,
   float64* markerY2
);

int32 __stdcall RFmxVNA_SParamsGetSParameter(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char sParameter[]
);

int32 __stdcall RFmxVNA_WavesGetWave(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char wave[]
);

int32 __stdcall RFmxVNA_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxVNA_GetAllCalsetNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char calsetNames[]
);

int32 __stdcall RFmxVNA_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxVNA_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxVNA_GetMeasurementMemoryNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char measurementMemoryNames[]
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSetTypes(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 calibrationElementTypes[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 frequency[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS11(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s11[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS11Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s11I[],
   float64 s11Q[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS12(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s12[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS12Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s12I[],
   float64 s12Q[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS21(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s21[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS21Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s21I[],
   float64 s21Q[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS22(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   NIComplexDouble s22[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterSetS22Split(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 s22I[],
   float64 s22Q[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_SParamsFetchXData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 X[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SParamsFetchYData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 Y1[],
   float32 Y2[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_WavesFetchXData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64 X[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_WavesFetchYData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 Y1[],
   float32 Y2[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_IQFetchData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   NIComplexSingle data[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_IQFetchDataSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 dataI[],
   float32 dataQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_GetMeasurementMemoryXData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 measurementMemoryX[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_GetMeasurementMemoryYData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 measurementMemoryY1[],
   float32 measurementMemoryY2[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitGetTRLReferencePlane(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* referencePlane
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitGetLRLLineAutoChar(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* autoCharacterizationEnabled
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorGetGender(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* connectorGender
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorGetImpedance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* impedance
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorGetMinimumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* minimumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitConnectorGetMaximumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* maximumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementGetSParameterDefinition(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* sParameterDefinition
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementGetMinimumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* minimumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementGetMaximumFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* maximumFrequency
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetModelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* modelType
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetSParamAvailability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* sParameterAvailability
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetC0(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* c0
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetC1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* c1
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetC2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* c2
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetC3(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* c3
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetOffsetDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* offsetDelay
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetOffsetLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* offsetLoss
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetOffsetZ0(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* offsetZ0
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementReflectModelGetReferenceImpedance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* referenceImpedance
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementDelayModelGetDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64* delay
);

int32 __stdcall RFmxVNA_CalkitManagerCalkitCalibrationElementSParameterGetSParamAvailability(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* sParameterAvailability
);

int32 __stdcall RFmxVNA_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetTriggerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetTriggerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetReadyForTriggerEventOutputTerminal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetReadyForTriggerEventOutputTerminal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetReadyForTriggerEventTerminalName(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetReadyForTriggerEventLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetReadyForTriggerEventLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetIndexEventOutputTerminal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetIndexEventOutputTerminal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetIndexEventTerminalName(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetIndexEventLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetIndexEventLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSweepType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSweepType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxVNA_SetFrequencyList(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxVNA_GetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCWFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCWFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetNumberOfPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetNumberOfPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetPowerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPowerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetTestReceiverAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetTestReceiverAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetIFBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetIFBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetAutoIFBandwidthScalingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetAutoIFBandwidthScalingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSweepSequence(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSweepSequence(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSweepDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetSweepDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetDwellTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetDwellTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetNumberOfSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentNumberOfFrequencyPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentNumberOfFrequencyPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentPowerLevelEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentPowerLevelEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentPowerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentPowerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentIFBandwidthEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentIFBandwidthEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentIFBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentIFBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentTestReceiverAttenuationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentTestReceiverAttenuationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentTestReceiverAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentTestReceiverAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentDwellTimeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentDwellTimeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSegmentDwellTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetSegmentDwellTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetPulseModeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseModeEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetPulseTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetPulseDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetPulseDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetPulsePeriod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPulsePeriod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetPulseModulatorDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseModulatorDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetPulseModulatorWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseModulatorWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetPulseAcquisitionAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseAcquisitionAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetPulseAcquisitionDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseAcquisitionDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetPulseAcquisitionWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseAcquisitionWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetPulseGeneratorEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseGeneratorEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetPulseGeneratorExportOutputTerminal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetPulseGeneratorExportOutputTerminal(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetPulseGeneratorTerminalName(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetPulseGeneratorDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseGeneratorDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetPulseGeneratorWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetPulseGeneratorWidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetXAxisValues(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxVNA_GetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionInterpolationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionInterpolationEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortSubsetEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortSubsetEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortSubsetPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionPortSubsetPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionDelayDomain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionDelayDomain(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionDistance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionDistance(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionDistanceUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionDistanceUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionVelocityFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionVelocityFactor(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionDCLossEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionDCLossEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionDCLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionDCLoss(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionLoss1Enabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionLoss1Enabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionLoss1Frequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionLoss1Frequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionLoss1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionLoss1(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionLoss2Enabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionLoss2Enabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionLoss2Frequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionLoss2Frequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionPortExtensionLoss2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionPortExtensionLoss2(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationConnectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationConnectorType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationCalkitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationCalkitType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationCalkitElectronicResourceName(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationCalkitElectronicResourceName(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationCalkitElectronicOrientation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationCalkitElectronicOrientation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationCalkitMechanicalName(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationCalkitMechanicalName(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationThruMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationThruMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationThruCoaxDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationThruCoaxDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationStepCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationStepCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationStepDescription(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationStepVCalOrientation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationStepVCalOrientation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationStepPortAssignment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetCorrectionCalibrationStepPortAssignment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetCorrectionCalibrationEstimatedThruDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetSourcePowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetSourcePowerMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_GetGroundTerminatedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SetGroundTerminatedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetNumberOfSParameters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetNumberOfSParameters(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetReceiverPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsSetReceiverPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsGetSourcePort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsSetSourcePort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsGetFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetMagnitudeUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetMagnitudeUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetPhaseTraceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetPhaseTraceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetGroupDelayApertureMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetGroupDelayApertureMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetGroupDelayAperturePoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetGroupDelayAperturePoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetGroupDelayAperturePercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetGroupDelayAperturePercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetGroupDelayApertureFrequencySpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetGroupDelayApertureFrequencySpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetMathFunction(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetMathFunction(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetMathActiveMeasurementMemory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsSetMathActiveMeasurementMemory(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsGetResultsCorrectionState(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsGetResultsCorrectionLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsGetSnPDataFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SParamsSetSnPDataFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_SParamsGetSnPUserComment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsSetSnPUserComment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsGetSnPPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_SParamsSetSnPPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_WavesGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_WavesGetNumberOfWaves(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetNumberOfWaves(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_WavesGetReceiver(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetReceiver(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_WavesGetReceiverPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_WavesSetReceiverPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_WavesGetSourcePort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_WavesSetSourcePort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_WavesGetFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetFormat(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_WavesGetMagnitudeUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetMagnitudeUnits(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_WavesGetPhaseTraceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetPhaseTraceType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_WavesGetGroupDelayApertureMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetGroupDelayApertureMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_WavesGetGroupDelayAperturePoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetGroupDelayAperturePoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_WavesGetGroupDelayAperturePercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetGroupDelayAperturePercentage(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_WavesGetGroupDelayApertureFrequencySpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_WavesSetGroupDelayApertureFrequencySpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_WavesGetResultsCorrectionState(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_WavesGetResultsCorrectionLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_IQGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_IQSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxVNA_IQGetAcquisitionTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxVNA_IQSetAcquisitionTime(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxVNA_IQGetReceiverPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_IQSetReceiverPort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_IQGetSourcePort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxVNA_IQSetSourcePort(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxVNA_IQGetResultsCorrectionState(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

#ifdef __cplusplus
}
#endif

/* ---------------- Obsolete Section ------------------ */
#define RFMXVNA_ATTR_NUMBER_OF_FREQUENCY_POINTS                                  0x00d00053
// Values for RFMXVNA_ATTR_CORRECTION_CALIBRATION_THRU_METHOD
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_THRU_METHOD_UNDEFINED_THRU_USING_DEFINED_THRU                          4
#define RFMXVNA_VAL_CORRECTION_CALIBRATION_THRU_METHOD_DELAY_THRU_USING_DEFINED_THRU                              5

#ifdef __cplusplus
extern "C"
{
#endif

int32 __stdcall RFmxVNA_CfgFrequencyListStartStopPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 startFrequency,
   float64 stopFrequency,
   int32 numberOfPoints
);

int32 __stdcall RFmxVNA_SParamsFetchRealData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 realData[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SParamsFetchComplexData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle complexData[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_SParamsFetchComplexDataSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 complexDataI[],
   float32 complexDataQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_WavesFetchRealData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 realData[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_WavesFetchComplexData(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle complexData[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_WavesFetchComplexDataSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 complexDataI[],
   float32 complexDataQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxVNA_GetNumberOfFrequencyPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxVNA_SetNumberOfFrequencyPoints(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

#ifdef __cplusplus
}
#endif


#endif

