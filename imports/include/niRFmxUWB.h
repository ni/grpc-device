
/****************************************************************************************************
*          National Instruments RFmx UWB
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2024.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxUWB.h
*
* Purpose:  National Instruments RFmx UWB,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_UWB_H__
#define __NI_RFMX_UWB_H__

#include "niRFmxInstr.h"

#define RFMXUWB_ATTR_SELECTED_PORTS                                          0x00e00ffd
#define RFMXUWB_ATTR_CENTER_FREQUENCY                                        0x00e00001
#define RFMXUWB_ATTR_REFERENCE_LEVEL                                         0x00e00002
#define RFMXUWB_ATTR_EXTERNAL_ATTENUATION                                    0x00e00003
#define RFMXUWB_ATTR_REFERENCE_LEVEL_HEADROOM                                0x00e00ffc
#define RFMXUWB_ATTR_TRIGGER_TYPE                                            0x00e00004
#define RFMXUWB_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                             0x00e00005
#define RFMXUWB_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                               0x00e00006
#define RFMXUWB_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                            0x00e00007
#define RFMXUWB_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                             0x00e00008
#define RFMXUWB_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                        0x00e00fff
#define RFMXUWB_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                             0x00e00009
#define RFMXUWB_ATTR_TRIGGER_DELAY                                           0x00e0000a
#define RFMXUWB_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                         0x00e0000b
#define RFMXUWB_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                     0x00e0000c
#define RFMXUWB_ATTR_HRP_MODE                                                0x00e0000d
#define RFMXUWB_ATTR_BANDWIDTH                                               0x00e0000e
#define RFMXUWB_ATTR_PACKET_CODE_INDEX                                       0x00e00010
#define RFMXUWB_ATTR_PACKET_SYNC_LENGTH                                      0x00e00011
#define RFMXUWB_ATTR_PACKET_DELTA_LENGTH                                     0x00e00012
#define RFMXUWB_ATTR_PACKET_SFD_INDEX                                        0x00e0001c
#define RFMXUWB_ATTR_PACKET_PHR_DATA_RATE_MODE                               0x00e0001d
#define RFMXUWB_ATTR_PACKET_HOP_BURSTS                                       0x00e00013
#define RFMXUWB_ATTR_PACKET_CHIPS_PER_BURST                                  0x00e00014
#define RFMXUWB_ATTR_PACKET_PAYLOAD_LENGTH                                   0x00e00017
#define RFMXUWB_ATTR_PACKET_CONVOLUTIONAL_CODE_CONSTRAINT_LENGTH             0x00e0001e
#define RFMXUWB_ATTR_PACKET_STS_PACKET_CONFIGURATION                         0x00e00018
#define RFMXUWB_ATTR_PACKET_STS_NUMBER_OF_ACTIVE_SEGMENTS                    0x00e00019
#define RFMXUWB_ATTR_PACKET_STS_ACTIVE_SEGMENT_LENGTH                        0x00e0001a
#define RFMXUWB_ATTR_PACKET_STS_ADDITIONAL_GAP                               0x00e0001b
#define RFMXUWB_ATTR_MODACC_MEASUREMENT_ENABLED                              0x00e01000
#define RFMXUWB_ATTR_MODACC_AVERAGING_ENABLED                                0x00e01002
#define RFMXUWB_ATTR_MODACC_AVERAGING_COUNT                                  0x00e01003
#define RFMXUWB_ATTR_MODACC_MAXIMUM_SYNC_LENGTH                              0x00e01020
#define RFMXUWB_ATTR_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD                0x00e01004
#define RFMXUWB_ATTR_MODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED              0x00e01015
#define RFMXUWB_ATTR_MODACC_NRMSE_ENABLED                                    0x00e01021
#define RFMXUWB_ATTR_MODACC_POWER_ENABLED                                    0x00e01022
#define RFMXUWB_ATTR_MODACC_JITTER_ENABLED                                   0x00e01023
#define RFMXUWB_ATTR_MODACC_ALL_TRACES_ENABLED                               0x00e01005
#define RFMXUWB_ATTR_MODACC_NUMBER_OF_ANALYSIS_THREADS                       0x00e01006
#define RFMXUWB_ATTR_MODACC_RESULTS_FREQUENCY_ERROR_MEAN                     0x00e01008
#define RFMXUWB_ATTR_MODACC_RESULTS_CHIP_CLOCK_ERROR_MEAN                    0x00e01009
#define RFMXUWB_ATTR_MODACC_RESULTS_MAIN_LOBE_PEAK_MEAN                      0x00e0100a
#define RFMXUWB_ATTR_MODACC_RESULTS_MAIN_LOBE_PEAK_MAXIMUM                   0x00e0100b
#define RFMXUWB_ATTR_MODACC_RESULTS_MAIN_LOBE_WIDTH_MEAN                     0x00e0100c
#define RFMXUWB_ATTR_MODACC_RESULTS_MAIN_LOBE_WIDTH_MAXIMUM                  0x00e0100d
#define RFMXUWB_ATTR_MODACC_RESULTS_SIDE_LOBE_PEAK_MEAN                      0x00e0100e
#define RFMXUWB_ATTR_MODACC_RESULTS_SIDE_LOBE_PEAK_MAXIMUM                   0x00e0100f
#define RFMXUWB_ATTR_MODACC_RESULTS_PULSE_MONOTONIC_RISE_STATUS              0x00e01010
#define RFMXUWB_ATTR_MODACC_RESULTS_PULSE_MASK_STATUS                        0x00e01024
#define RFMXUWB_ATTR_MODACC_RESULTS_SHR_NRMSE_MEAN                           0x00e01011
#define RFMXUWB_ATTR_MODACC_RESULTS_PHR_NRMSE_MEAN                           0x00e01012
#define RFMXUWB_ATTR_MODACC_RESULTS_PSDU_NRMSE_MEAN                          0x00e01013
#define RFMXUWB_ATTR_MODACC_RESULTS_STS_NRMSE_MEAN                           0x00e01014
#define RFMXUWB_ATTR_MODACC_RESULTS_NRMSE_DETECTED_PSDU_LENGTH               0x00e01025
#define RFMXUWB_ATTR_MODACC_RESULTS_CHIP_RMS_JITTER_MEAN                     0x00e01016
#define RFMXUWB_ATTR_MODACC_RESULTS_SYMBOL_RMS_JITTER_MEAN                   0x00e01017
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_SHR_AVERAGE_POWER_MEAN             0x00e01018
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_SHR_PEAK_POWER_MAXIMUM             0x00e01019
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_PHR_AVERAGE_POWER_MEAN             0x00e0101a
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_PHR_PEAK_POWER_MAXIMUM             0x00e0101b
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_PSDU_AVERAGE_POWER_MEAN            0x00e0101c
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_PSDU_PEAK_POWER_MAXIMUM            0x00e0101d
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_STS_AVERAGE_POWER_MEAN             0x00e0101e
#define RFMXUWB_ATTR_MODACC_RESULTS_POWER_STS_PEAK_POWER_MAXIMUM             0x00e0101f
#define RFMXUWB_ATTR_SEM_MEASUREMENT_ENABLED                                 0x00e02000
#define RFMXUWB_ATTR_SEM_NUMBER_OF_OFFSETS                                   0x00e02002
#define RFMXUWB_ATTR_SEM_OFFSET_START_FREQUENCY                              0x00e02003
#define RFMXUWB_ATTR_SEM_OFFSET_STOP_FREQUENCY                               0x00e02004
#define RFMXUWB_ATTR_SEM_OFFSET_RELATIVE_LIMIT_START                         0x00e02008
#define RFMXUWB_ATTR_SEM_OFFSET_RELATIVE_LIMIT_STOP                          0x00e02009
#define RFMXUWB_ATTR_SEM_SPAN_AUTO                                           0x00e0200a
#define RFMXUWB_ATTR_SEM_SPAN                                                0x00e0200b
#define RFMXUWB_ATTR_SEM_SWEEP_TIME_AUTO                                     0x00e0200c
#define RFMXUWB_ATTR_SEM_SWEEP_TIME_INTERVAL                                 0x00e0200d
#define RFMXUWB_ATTR_SEM_AVERAGING_ENABLED                                   0x00e0200e
#define RFMXUWB_ATTR_SEM_AVERAGING_COUNT                                     0x00e0200f
#define RFMXUWB_ATTR_SEM_AVERAGING_TYPE                                      0x00e02010
#define RFMXUWB_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE                           0x00e02011
#define RFMXUWB_ATTR_SEM_ALL_TRACES_ENABLED                                  0x00e02012
#define RFMXUWB_ATTR_SEM_NUMBER_OF_ANALYSIS_THREADS                          0x00e02013
#define RFMXUWB_ATTR_SEM_RESULTS_MEASUREMENT_STATUS                          0x00e02015
#define RFMXUWB_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_INTEGRATED_POWER           0x00e02016
#define RFMXUWB_ATTR_SEM_RESULTS_CARRIER_ABSOLUTE_PEAK_POWER                 0x00e02017
#define RFMXUWB_ATTR_SEM_RESULTS_CARRIER_PEAK_FREQUENCY                      0x00e02018
#define RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS             0x00e02019
#define RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_INTEGRATED_POWER      0x00e0201a
#define RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_ABSOLUTE_PEAK_POWER            0x00e0201b
#define RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_PEAK_FREQUENCY                 0x00e0201c
#define RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN                         0x00e0201d
#define RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_ABSOLUTE_POWER          0x00e0201e
#define RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_MARGIN_FREQUENCY               0x00e0201f
#define RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS             0x00e02020
#define RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_INTEGRATED_POWER      0x00e02021
#define RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_ABSOLUTE_PEAK_POWER            0x00e02022
#define RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_PEAK_FREQUENCY                 0x00e02023
#define RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN                         0x00e02024
#define RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_ABSOLUTE_POWER          0x00e02025
#define RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_MARGIN_FREQUENCY               0x00e02026
#define RFMXUWB_ATTR_LIMITED_CONFIGURATION_CHANGE                            0x00e00015
#define RFMXUWB_ATTR_RESULT_FETCH_TIMEOUT                                    0x00e0c000

// Values for RFMXUWB_ATTR_TRIGGER_TYPE
#define RFMXUWB_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXUWB_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXUWB_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXUWB_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXUWB_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXUWB_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXUWB_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXUWB_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXUWB_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXUWB_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXUWB_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXUWB_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXUWB_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXUWB_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXUWB_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXUWB_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXUWB_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXUWB_VAL_TIMER_EVENT_STR                                                                "TimerEvent"
#define RFMXUWB_VAL_PULSE_IN_STR                                                                   "PulseIn"
#define RFMXUWB_VAL_DIO_PFI0_STR                                                                   "DIO/PFI0"
#define RFMXUWB_VAL_DIO_PFI1_STR                                                                   "DIO/PFI1"
#define RFMXUWB_VAL_DIO_PFI2_STR                                                                   "DIO/PFI2"
#define RFMXUWB_VAL_DIO_PFI3_STR                                                                   "DIO/PFI3"
#define RFMXUWB_VAL_DIO_PFI4_STR                                                                   "DIO/PFI4"
#define RFMXUWB_VAL_DIO_PFI5_STR                                                                   "DIO/PFI5"
#define RFMXUWB_VAL_DIO_PFI6_STR                                                                   "DIO/PFI6"
#define RFMXUWB_VAL_DIO_PFI7_STR                                                                   "DIO/PFI7"

// Values for RFMXUWB_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXUWB_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXUWB_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXUWB_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXUWB_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXUWB_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXUWB_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXUWB_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXUWB_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXUWB_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXUWB_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXUWB_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXUWB_ATTR_HRP_MODE
#define RFMXUWB_VAL_HRP_MODE_NON_ERDEV                                                             0
#define RFMXUWB_VAL_HRP_MODE_ERDEV_BPRF                                                            1
#define RFMXUWB_VAL_HRP_MODE_ERDEV_HPRF                                                            2

// Values for RFMXUWB_ATTR_PACKET_PHR_DATA_RATE_MODE
#define RFMXUWB_VAL_PACKET_PHR_DATA_RATE_MODE_DRBM_LP                                              0
#define RFMXUWB_VAL_PACKET_PHR_DATA_RATE_MODE_DRBM_HP                                              1
#define RFMXUWB_VAL_PACKET_PHR_DATA_RATE_MODE_DRHM_LR                                              2
#define RFMXUWB_VAL_PACKET_PHR_DATA_RATE_MODE_DRHM_HR                                              3

// Values for RFMXUWB_ATTR_PACKET_CONVOLUTIONAL_CODE_CONSTRAINT_LENGTH
#define RFMXUWB_VAL_PACKET_CONVOLUTIONAL_CODE_CONSTRAINT_LENGTH_CL3                                0
#define RFMXUWB_VAL_PACKET_CONVOLUTIONAL_CODE_CONSTRAINT_LENGTH_CL7                                1

// Values for RFMXUWB_ATTR_MODACC_AVERAGING_ENABLED
#define RFMXUWB_VAL_MODACC_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXUWB_VAL_MODACC_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXUWB_ATTR_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD
#define RFMXUWB_VAL_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_DISABLED                              0
#define RFMXUWB_VAL_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_SYNC                                  1

// Values for RFMXUWB_ATTR_MODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED
#define RFMXUWB_VAL_MODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED_FALSE                               0
#define RFMXUWB_VAL_MODACC_CHIP_CLOCK_ERROR_CORRECTION_ENABLED_TRUE                                1

// Values for RFMXUWB_ATTR_MODACC_NRMSE_ENABLED
#define RFMXUWB_VAL_MODACC_NRMSE_ENABLED_FALSE                                                     0
#define RFMXUWB_VAL_MODACC_NRMSE_ENABLED_TRUE                                                      1

// Values for RFMXUWB_ATTR_MODACC_POWER_ENABLED
#define RFMXUWB_VAL_MODACC_POWER_ENABLED_FALSE                                                     0
#define RFMXUWB_VAL_MODACC_POWER_ENABLED_TRUE                                                      1

// Values for RFMXUWB_ATTR_MODACC_JITTER_ENABLED
#define RFMXUWB_VAL_MODACC_JITTER_ENABLED_FALSE                                                    0
#define RFMXUWB_VAL_MODACC_JITTER_ENABLED_TRUE                                                     1

// Values for RFMXUWB_ATTR_MODACC_RESULTS_PULSE_MONOTONIC_RISE_STATUS
#define RFMXUWB_VAL_MODACC_PULSE_MONOTONIC_RISE_STATUS_NOT_APPLICABLE                              -1
#define RFMXUWB_VAL_MODACC_PULSE_MONOTONIC_RISE_STATUS_FAIL                                        0
#define RFMXUWB_VAL_MODACC_PULSE_MONOTONIC_RISE_STATUS_PASS                                        1

// Values for RFMXUWB_ATTR_MODACC_RESULTS_PULSE_MASK_STATUS
#define RFMXUWB_VAL_MODACC_PULSE_MASK_STATUS_NOT_APPLICABLE                                        -1
#define RFMXUWB_VAL_MODACC_PULSE_MASK_STATUS_FAIL                                                  0
#define RFMXUWB_VAL_MODACC_PULSE_MASK_STATUS_PASS                                                  1

// Values for RFMXUWB_ATTR_SEM_SPAN_AUTO
#define RFMXUWB_VAL_SEM_SPAN_AUTO_FALSE                                                            0
#define RFMXUWB_VAL_SEM_SPAN_AUTO_TRUE                                                             1

// Values for RFMXUWB_ATTR_SEM_SWEEP_TIME_AUTO
#define RFMXUWB_VAL_SEM_SWEEP_TIME_AUTO_FALSE                                                      0
#define RFMXUWB_VAL_SEM_SWEEP_TIME_AUTO_TRUE                                                       1

// Values for RFMXUWB_ATTR_SEM_AVERAGING_ENABLED
#define RFMXUWB_VAL_SEM_AVERAGING_ENABLED_FALSE                                                    0
#define RFMXUWB_VAL_SEM_AVERAGING_ENABLED_TRUE                                                     1

// Values for RFMXUWB_ATTR_SEM_AVERAGING_TYPE
#define RFMXUWB_VAL_SEM_AVERAGING_TYPE_RMS                                                         0
#define RFMXUWB_VAL_SEM_AVERAGING_TYPE_LOG                                                         1
#define RFMXUWB_VAL_SEM_AVERAGING_TYPE_SCALAR                                                      2
#define RFMXUWB_VAL_SEM_AVERAGING_TYPE_MAXIMUM                                                     3
#define RFMXUWB_VAL_SEM_AVERAGING_TYPE_MINIMUM                                                     4

// Values for RFMXUWB_ATTR_SEM_AMPLITUDE_CORRECTION_TYPE
#define RFMXUWB_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_RF_CENTER_FREQUENCY                              0
#define RFMXUWB_VAL_SEM_AMPLITUDE_CORRECTION_TYPE_SPECTRUM_FREQUENCY_BIN                           1

// Values for RFMXUWB_ATTR_SEM_RESULTS_MEASUREMENT_STATUS
#define RFMXUWB_VAL_SEM_MEASUREMENT_STATUS_FAIL                                                    0
#define RFMXUWB_VAL_SEM_MEASUREMENT_STATUS_PASS                                                    1

// Values for RFMXUWB_ATTR_SEM_RESULTS_LOWER_OFFSET_MEASUREMENT_STATUS
#define RFMXUWB_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXUWB_VAL_SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXUWB_ATTR_SEM_RESULTS_UPPER_OFFSET_MEASUREMENT_STATUS
#define RFMXUWB_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL                                       0
#define RFMXUWB_VAL_SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS                                       1

// Values for RFMXUWB_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXUWB_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXUWB_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXUWB_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXUWB_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXUWB_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXUWB_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for MeasurementTypes
#define RFMXUWB_VAL_MODACC                                                                         1<<0
#define RFMXUWB_VAL_SEM                                                                            1<<1

// Values for Boolean
#define RFMXUWB_VAL_FALSE                                                                          0
#define RFMXUWB_VAL_TRUE                                                                           1

/* ---------------- RFmxUWB APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxUWB_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxUWB_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxUWB_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxUWB_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxUWB_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxUWB_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxUWB_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxUWB_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxUWB_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxUWB_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxUWB_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxUWB_BuildOffsetString(
   char selectorString[],
   int32 offsetNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxUWB_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxUWB_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxUWB_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxUWB_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxUWB_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxUWB_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxUWB_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxUWB_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxUWB_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* done
);

int32 __stdcall RFmxUWB_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxUWB_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxUWB_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxUWB_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxUWB_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxUWB_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxUWB_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxUWB_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxUWB_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxUWB_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxUWB_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxUWB_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxUWB_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxUWB_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxUWB_ModAccFetchPulseTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* pulseX0,
   float64* pulseDx,
   float32 pulse[],
   int32 pulseArraySize,
   int32* pulseActualArraySize,
   float64* pulseMaskX0,
   float64* pulseMaskDx,
   float32 pulseUpperMask[],
   float32 pulseLowerMask[],
   int32 pulseMaskArraySize,
   int32* pulseMaskActualArraySize
);

int32 __stdcall RFmxUWB_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxUWB_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxUWB_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxUWB_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxUWB_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxUWB_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxUWB_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxUWB_ModAccFetchCrossCorrelationMagnitudeTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 crossCorrelationMagnitude[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxUWB_SEMFetchSpectrum(
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

int32 __stdcall RFmxUWB_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxUWB_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxUWB_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxUWB_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxUWB_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxUWB_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxUWB_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetHRPMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetHRPMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_GetPacketCodeIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketCodeIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketSyncLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketSyncLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketDeltaLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketDeltaLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketSFDIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketSFDIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketPHRDataRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketPHRDataRateMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketHopBursts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketHopBursts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketChipsPerBurst(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketChipsPerBurst(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketPayloadLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketPayloadLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketConvolutionalCodeConstraintLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketConvolutionalCodeConstraintLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketSTSPacketConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketSTSPacketConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketSTSNumberOfActiveSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketSTSNumberOfActiveSegments(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketSTSActiveSegmentLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketSTSActiveSegmentLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetPacketSTSAdditionalGap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetPacketSTSAdditionalGap(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetMaximumSYNCLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetMaximumSYNCLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetFrequencyErrorEstimationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetFrequencyErrorEstimationMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetChipClockErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetChipClockErrorCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetNRMSEEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetNRMSEEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetPowerEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetPowerEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetJitterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetJitterEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetNumberofAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccSetNumberofAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsChipClockErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsMainLobePeakMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsMainLobePeakMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsMainLobeWidthMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsMainLobeWidthMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSideLobePeakMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSideLobePeakMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPulseMonotonicRiseStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPulseMaskStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSHRNRMSEMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPHRNRMSEMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPSDUNRMSEMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSTSNRMSEMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsNRMSEDetectedPSDULength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsChipRMSJitterMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSymbolRMSJitterMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSHRAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSHRPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPHRAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPHRPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPSDUAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsPSDUPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSTSAveragePowerMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_ModAccGetResultsSTSPeakPowerMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetNumberOfOffsets(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetOffsetStartFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetOffsetStopFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetOffsetRelativeLimitStart(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetOffsetRelativeLimitStop(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetSpanAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetSpanAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetSpan(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_SEMGetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetSweepTimeAuto(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetSweepTimeInterval(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxUWB_SEMGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetAveragingType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetAmplitudeCorrectionType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsCarrierAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsCarrierAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsCarrierPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsLowerOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsLowerOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsLowerOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsLowerOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsLowerOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsLowerOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsLowerOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsUpperOffsetMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsUpperOffsetAbsoluteIntegratedPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsUpperOffsetAbsolutePeakPower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsUpperOffsetPeakFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsUpperOffsetMargin(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsUpperOffsetMarginAbsolutePower(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxUWB_SEMGetResultsUpperOffsetMarginFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif


#endif

