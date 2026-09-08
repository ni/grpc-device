
/****************************************************************************************************
*          National Instruments RFmx OFDM
*----------------------------------------------------------------------------------------------------
*   Copyright(c) National Instruments 2026.  All Rights Reserved.
*----------------------------------------------------------------------------------------------------
*
* Title:    niRFmxOFDM.h
*
* Purpose:  National Instruments RFmx OFDM,
*                                Attribute IDs,
*                                Attribute Values,
*                                Functions Declarations.
*
*****************************************************************************************************/

#ifndef __NI_RFMX_OFDM_H__
#define __NI_RFMX_OFDM_H__

#include "niRFmxInstr.h"

#define RFMXOFDM_ATTR_SELECTED_PORTS                                                           0x00f00ffd
#define RFMXOFDM_ATTR_CENTER_FREQUENCY                                                         0x00f00001
#define RFMXOFDM_ATTR_REFERENCE_LEVEL                                                          0x00f00002
#define RFMXOFDM_ATTR_EXTERNAL_ATTENUATION                                                     0x00f00003
#define RFMXOFDM_ATTR_REFERENCE_LEVEL_HEADROOM                                                 0x00f00ffc
#define RFMXOFDM_ATTR_TRIGGER_TYPE                                                             0x00f00004
#define RFMXOFDM_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE                                              0x00f00005
#define RFMXOFDM_ATTR_DIGITAL_EDGE_TRIGGER_EDGE                                                0x00f00006
#define RFMXOFDM_ATTR_IQ_POWER_EDGE_TRIGGER_SOURCE                                             0x00f00007
#define RFMXOFDM_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL                                              0x00f00008
#define RFMXOFDM_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE                                         0x00f00fff
#define RFMXOFDM_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE                                              0x00f00009
#define RFMXOFDM_ATTR_TRIGGER_DELAY                                                            0x00f0000a
#define RFMXOFDM_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE                                          0x00f0000b
#define RFMXOFDM_ATTR_TRIGGER_MINIMUM_QUIET_TIME_DURATION                                      0x00f0000c
#define RFMXOFDM_ATTR_FRAME_FFT_SIZE                                                           0x00f0000f
#define RFMXOFDM_ATTR_FRAME_SUBCARRIER_SPACING                                                 0x00f00010
#define RFMXOFDM_ATTR_FRAME_GUARD_INTERVAL_PREFIX                                              0x00f00011
#define RFMXOFDM_ATTR_FRAME_GUARD_INTERVAL_SUFFIX                                              0x00f00012
#define RFMXOFDM_ATTR_FRAME_GUARD_INTERVAL_REPEAT_INDEX                                        0x00f00013
#define RFMXOFDM_ATTR_FRAME_NUMBER_OF_RESOURCE_ALLOCATIONS                                     0x00f00014
#define RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_TYPE                                           0x00f00015
#define RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_SYMBOL_RANGE                                   0x00f00016
#define RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_SUBCARRIER_RANGE                               0x00f00017
#define RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_DATA_TYPE                                      0x00f00018
#define RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_MODULATION_TYPE                                0x00f00019
#define RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_IQ_VALUES                                      0x00f0001a
#define RFMXOFDM_ATTR_MODACC_MEASUREMENT_ENABLED                                               0x00f01000
#define RFMXOFDM_ATTR_MODACC_AVERAGING_ENABLED                                                 0x00f01002
#define RFMXOFDM_ATTR_MODACC_AVERAGING_COUNT                                                   0x00f01003
#define RFMXOFDM_ATTR_MODACC_EVM_UNIT                                                          0x00f01004
#define RFMXOFDM_ATTR_MODACC_ACQUISITION_LENGTH                                                0x00f01005
#define RFMXOFDM_ATTR_MODACC_MEASUREMENT_OFFSET                                                0x00f0100b
#define RFMXOFDM_ATTR_MODACC_MAXIMUM_MEASUREMENT_LENGTH                                        0x00f0100c
#define RFMXOFDM_ATTR_MODACC_AUTO_SYMBOL_TIME_ADJUSTMENT_ENABLED                               0x00f0101c
#define RFMXOFDM_ATTR_MODACC_SYMBOL_TIME_ADJUSTMENT                                            0x00f0100d
#define RFMXOFDM_ATTR_MODACC_SYMBOL_CLOCK_OFFSET_CORRECTION_ENABLED                            0x00f0100f
#define RFMXOFDM_ATTR_MODACC_CHANNEL_ESTIMATION_SMOOTHING_METHOD                               0x00f01010
#define RFMXOFDM_ATTR_MODACC_CHANNEL_ESTIMATION_SMOOTHING_WINDOW_LENGTH                        0x00f01011
#define RFMXOFDM_ATTR_MODACC_AMPLITUDE_TRACKING_ENABLED                                        0x00f01012
#define RFMXOFDM_ATTR_MODACC_PHASE_TRACKING_ENABLED                                            0x00f01013
#define RFMXOFDM_ATTR_MODACC_TIME_TRACKING_ENABLED                                             0x00f01014
#define RFMXOFDM_ATTR_MODACC_MULTICARRIER_FILTER_TYPE                                          0x00f0101d
#define RFMXOFDM_ATTR_MODACC_MULTICARRIER_FILTER_WINDOWED_SINC_6DB_BANDWIDTH                   0x00f0101e
#define RFMXOFDM_ATTR_MODACC_MULTICARRIER_FILTER_WINDOWED_SINC_AUTO_FILTER_LENGTH_ENABLED      0x00f0101f
#define RFMXOFDM_ATTR_MODACC_MULTICARRIER_FILTER_WINDOWED_SINC_50DB_BANDWIDTH                  0x00f01020
#define RFMXOFDM_ATTR_MODACC_MULTICARRIER_FILTER_WINDOWED_SINC_FILTER_LENGTH                   0x00f01021
#define RFMXOFDM_ATTR_MODACC_ALL_TRACES_ENABLED                                                0x00f01006
#define RFMXOFDM_ATTR_MODACC_NUMBER_OF_ANALYSIS_THREADS                                        0x00f01007
#define RFMXOFDM_ATTR_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN                                    0x00f01008
#define RFMXOFDM_ATTR_MODACC_RESULTS_COMPOSITE_DATA_RMS_EVM_MEAN                               0x00f01009
#define RFMXOFDM_ATTR_MODACC_RESULTS_COMPOSITE_PILOT_RMS_EVM_MEAN                              0x00f0100a
#define RFMXOFDM_ATTR_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM                                0x00f01019
#define RFMXOFDM_ATTR_MODACC_RESULTS_COMPOSITE_DATA_PEAK_EVM_MAXIMUM                           0x00f0101a
#define RFMXOFDM_ATTR_MODACC_RESULTS_COMPOSITE_PILOT_PEAK_EVM_MAXIMUM                          0x00f0101b
#define RFMXOFDM_ATTR_MODACC_RESULTS_NUMBER_OF_SYMBOLS_USED                                    0x00f01016
#define RFMXOFDM_ATTR_MODACC_RESULTS_FREQUENCY_ERROR_MEAN                                      0x00f01017
#define RFMXOFDM_ATTR_MODACC_RESULTS_SYMBOL_CLOCK_ERROR_MEAN                                   0x00f01018
#define RFMXOFDM_ATTR_AUTO_LEVEL_INITIAL_REFERENCE_LEVEL                                       0x00f0000d
#define RFMXOFDM_ATTR_LIMITED_CONFIGURATION_CHANGE                                             0x00f0000e
#define RFMXOFDM_ATTR_RESULT_FETCH_TIMEOUT                                                     0x00f0c000

// Values for RFMXOFDM_ATTR_TRIGGER_TYPE
#define RFMXOFDM_VAL_TRIGGER_TYPE_NONE                                                              0
#define RFMXOFDM_VAL_TRIGGER_TYPE_DIGITAL_EDGE                                                      1
#define RFMXOFDM_VAL_TRIGGER_TYPE_IQ_POWER_EDGE                                                     2
#define RFMXOFDM_VAL_TRIGGER_TYPE_SOFTWARE                                                          3

// Values for RFMXOFDM_ATTR_DIGITAL_EDGE_TRIGGER_SOURCE
#define RFMXOFDM_VAL_PFI0_STR                                                                       "PFI0"
#define RFMXOFDM_VAL_PFI1_STR                                                                       "PFI1"
#define RFMXOFDM_VAL_PXI_TRIG0_STR                                                                  "PXI_Trig0"
#define RFMXOFDM_VAL_PXI_TRIG1_STR                                                                  "PXI_Trig1"
#define RFMXOFDM_VAL_PXI_TRIG2_STR                                                                  "PXI_Trig2"
#define RFMXOFDM_VAL_PXI_TRIG3_STR                                                                  "PXI_Trig3"
#define RFMXOFDM_VAL_PXI_TRIG4_STR                                                                  "PXI_Trig4"
#define RFMXOFDM_VAL_PXI_TRIG5_STR                                                                  "PXI_Trig5"
#define RFMXOFDM_VAL_PXI_TRIG6_STR                                                                  "PXI_Trig6"
#define RFMXOFDM_VAL_PXI_TRIG7_STR                                                                  "PXI_Trig7"
#define RFMXOFDM_VAL_PXI_STAR_STR                                                                   "PXI_STAR"
#define RFMXOFDM_VAL_PXIE_DSTARB_STR                                                                "PXIe_DStarB"
#define RFMXOFDM_VAL_TIMER_EVENT_STR                                                                "TimerEvent"
#define RFMXOFDM_VAL_PULSE_IN_STR                                                                   "PulseIn"
#define RFMXOFDM_VAL_DIO_PFI0_STR                                                                   "DIO/PFI0"
#define RFMXOFDM_VAL_DIO_PFI1_STR                                                                   "DIO/PFI1"
#define RFMXOFDM_VAL_DIO_PFI2_STR                                                                   "DIO/PFI2"
#define RFMXOFDM_VAL_DIO_PFI3_STR                                                                   "DIO/PFI3"
#define RFMXOFDM_VAL_DIO_PFI4_STR                                                                   "DIO/PFI4"
#define RFMXOFDM_VAL_DIO_PFI5_STR                                                                   "DIO/PFI5"
#define RFMXOFDM_VAL_DIO_PFI6_STR                                                                   "DIO/PFI6"
#define RFMXOFDM_VAL_DIO_PFI7_STR                                                                   "DIO/PFI7"

// Values for RFMXOFDM_ATTR_DIGITAL_EDGE_TRIGGER_EDGE
#define RFMXOFDM_VAL_DIGITAL_EDGE_RISING_EDGE                                                       0
#define RFMXOFDM_VAL_DIGITAL_EDGE_FALLING_EDGE                                                      1

// Values for RFMXOFDM_ATTR_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE
#define RFMXOFDM_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE                                      0
#define RFMXOFDM_VAL_IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_ABSOLUTE                                      1

// Values for RFMXOFDM_ATTR_IQ_POWER_EDGE_TRIGGER_SLOPE
#define RFMXOFDM_VAL_IQ_POWER_EDGE_RISING_SLOPE                                                     0
#define RFMXOFDM_VAL_IQ_POWER_EDGE_FALLING_SLOPE                                                    1

// Values for RFMXOFDM_ATTR_TRIGGER_MINIMUM_QUIET_TIME_MODE
#define RFMXOFDM_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL                                         0
#define RFMXOFDM_VAL_TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO                                           1

// Values for RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_TYPE
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_TYPE_PREAMBLE                                              0
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_TYPE_CHANNEL_ESTIMATION                                    1
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_TYPE_DATA                                                  2
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_TYPE_PILOT                                                 3

// Values for RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_DATA_TYPE
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_DATA_TYPE_UNKNOWN                                          0
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_DATA_TYPE_CUSTOM                                           1

// Values for RFMXOFDM_ATTR_FRAME_RESOURCE_ALLOCATION_MODULATION_TYPE
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_UNKNOWN                                    0
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_BPSK                                       1
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_QPSK                                       2
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_8_QAM                                      3
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_16_QAM                                     4
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_32_QAM                                     5
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_64_QAM                                     6
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_128_QAM                                    7
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_256_QAM                                    8
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_512_QAM                                    9
#define RFMXOFDM_VAL_RESOURCE_ALLOCATION_MODULATION_TYPE_1024_QAM                                   10

// Values for RFMXOFDM_ATTR_MODACC_AVERAGING_ENABLED
#define RFMXOFDM_VAL_MODACC_AVERAGING_ENABLED_FALSE                                                 0
#define RFMXOFDM_VAL_MODACC_AVERAGING_ENABLED_TRUE                                                  1

// Values for RFMXOFDM_ATTR_MODACC_EVM_UNIT
#define RFMXOFDM_VAL_MODACC_EVM_UNIT_PERCENTAGE                                                     0
#define RFMXOFDM_VAL_MODACC_EVM_UNIT_DB                                                             1

// Values for RFMXOFDM_ATTR_MODACC_AUTO_SYMBOL_TIME_ADJUSTMENT_ENABLED
#define RFMXOFDM_VAL_MODACC_AUTO_SYMBOL_TIME_ADJUSTMENT_ENABLED_FALSE                               0
#define RFMXOFDM_VAL_MODACC_AUTO_SYMBOL_TIME_ADJUSTMENT_ENABLED_TRUE                                1

// Values for RFMXOFDM_ATTR_MODACC_SYMBOL_CLOCK_OFFSET_CORRECTION_ENABLED
#define RFMXOFDM_VAL_MODACC_SYMBOL_CLOCK_OFFSET_CORRECTION_ENABLED_FALSE                            0
#define RFMXOFDM_VAL_MODACC_SYMBOL_CLOCK_OFFSET_CORRECTION_ENABLED_TRUE                             1

// Values for RFMXOFDM_ATTR_MODACC_CHANNEL_ESTIMATION_SMOOTHING_METHOD
#define RFMXOFDM_VAL_MODACC_CHANNEL_ESTIMATION_SMOOTHING_METHOD_NONE                                0
#define RFMXOFDM_VAL_MODACC_CHANNEL_ESTIMATION_SMOOTHING_METHOD_RECTANGULAR_WINDOW                  1
#define RFMXOFDM_VAL_MODACC_CHANNEL_ESTIMATION_SMOOTHING_METHOD_TRIANGULAR_WINDOW                   2

// Values for RFMXOFDM_ATTR_MODACC_AMPLITUDE_TRACKING_ENABLED
#define RFMXOFDM_VAL_MODACC_AMPLITUDE_TRACKING_ENABLED_FALSE                                        0
#define RFMXOFDM_VAL_MODACC_AMPLITUDE_TRACKING_ENABLED_TRUE                                         1

// Values for RFMXOFDM_ATTR_MODACC_PHASE_TRACKING_ENABLED
#define RFMXOFDM_VAL_MODACC_PHASE_TRACKING_ENABLED_FALSE                                            0
#define RFMXOFDM_VAL_MODACC_PHASE_TRACKING_ENABLED_TRUE                                             1

// Values for RFMXOFDM_ATTR_MODACC_TIME_TRACKING_ENABLED
#define RFMXOFDM_VAL_MODACC_TIME_TRACKING_ENABLED_FALSE                                             0
#define RFMXOFDM_VAL_MODACC_TIME_TRACKING_ENABLED_TRUE                                              1

// Values for RFMXOFDM_ATTR_MODACC_MULTICARRIER_FILTER_TYPE
#define RFMXOFDM_VAL_MODACC_MULTICARRIER_FILTER_TYPE_NONE                                           0
#define RFMXOFDM_VAL_MODACC_MULTICARRIER_FILTER_TYPE_WINDOWED_SINC                                  1

// Values for RFMXOFDM_ATTR_MODACC_MULTICARRIER_FILTER_WINDOWED_SINC_AUTO_FILTER_LENGTH_ENABLED
#define RFMXOFDM_VAL_MODACC_MULTICARRIER_FILTER_WINDOWED_SINC_AUTO_FILTER_LENGTH_ENABLED_FALSE      0
#define RFMXOFDM_VAL_MODACC_MULTICARRIER_FILTER_WINDOWED_SINC_AUTO_FILTER_LENGTH_ENABLED_TRUE       1

// Values for RFMXOFDM_ATTR_LIMITED_CONFIGURATION_CHANGE
#define RFMXOFDM_VAL_LIMITED_CONFIGURATION_CHANGE_DISABLED                                          0
#define RFMXOFDM_VAL_LIMITED_CONFIGURATION_CHANGE_NO_CHANGE                                         1
#define RFMXOFDM_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY                                         2
#define RFMXOFDM_VAL_LIMITED_CONFIGURATION_CHANGE_REFERENCE_LEVEL                                   3
#define RFMXOFDM_VAL_LIMITED_CONFIGURATION_CHANGE_FREQUENCY_AND_REFERENCE_LEVEL                     4
#define RFMXOFDM_VAL_LIMITED_CONFIGURATION_CHANGE_SELECTED_PORTS_FREQUENCY_AND_REFERENCE_LEVEL      5

// Values for FrequencyReferenceSource
#define RFMXOFDM_VAL_ONBOARD_CLOCK_STR                                                              "OnboardClock"
#define RFMXOFDM_VAL_REF_IN_STR                                                                     "RefIn"
#define RFMXOFDM_VAL_PXI_CLK_STR                                                                    "PXI_Clk"
#define RFMXOFDM_VAL_CLK_IN_STR                                                                     "ClkIn"

// Values for Boolean
#define RFMXOFDM_VAL_FALSE                                                                          0
#define RFMXOFDM_VAL_TRUE                                                                           1

// Values for MeasurementTypes
#define RFMXOFDM_VAL_MODACC                                                                         1<<0

// Values for RFAttenuationAuto
#define RFMXOFDM_VAL_RF_ATTENUATION_AUTO_FALSE                                                      0
#define RFMXOFDM_VAL_RF_ATTENUATION_AUTO_TRUE                                                       1

// Values for MechanicalAttenuationAuto
#define RFMXOFDM_VAL_MECHANICAL_ATTENUATION_AUTO_FALSE                                              0
#define RFMXOFDM_VAL_MECHANICAL_ATTENUATION_AUTO_TRUE                                               1

/* ---------------- RFmxOFDM APIs ------------------ */


#ifdef __cplusplus
extern "C"
{
#endif


int32 __stdcall RFmxOFDM_ResetAttribute(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID
);

int32 __stdcall RFmxOFDM_Initialize(
   char resourceName[],
   char optionString[],
   niRFmxInstrHandle *handleOut,
   int32 *isNewSession
);

int32 __stdcall RFmxOFDM_InitializeFromNIRFSASession(
   uInt32 NIRFSASession,
   niRFmxInstrHandle *handleOut
);

int32 __stdcall RFmxOFDM_Close(
   niRFmxInstrHandle instrumentHandle,
   int32 forceDestroy
);

int32 __stdcall RFmxOFDM_GetErrorString(
   niRFmxInstrHandle instrumentHandle,
   int32 errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxOFDM_GetError(
   niRFmxInstrHandle instrumentHandle,
   int32* errorCode,
   int32 errorDescriptionBufferSize,
   char errorDescription[]
);

int32 __stdcall RFmxOFDM_CfgFrequencyReference(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   char frequencyReferenceSource[],
   float64 frequencyReferenceFrequency
);

int32 __stdcall RFmxOFDM_CfgMechanicalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 mechanicalAttenuationAuto,
   float64 mechanicalAttenuationValue
);

int32 __stdcall RFmxOFDM_CfgRFAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char channelName[],
   int32 RFAttenuationAuto,
   float64 RFAttenuationValue
);

int32 __stdcall RFmxOFDM_WaitForAcquisitionComplete(
   niRFmxInstrHandle instrumentHandle,
   float64 timeout
);


int32 __stdcall RFmxOFDM_BuildSignalString(
   char signalName[],
   char resultName[],
   int32 selectorStringLength,
   char selectorString[]
);

int32 __stdcall RFmxOFDM_BuildAllocationString(
   char selectorString[],
   int32 allocationNumber,
   int32 selectorStringOutLength,
   char selectorStringOut[]
);

int32 __stdcall RFmxOFDM_SetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeI8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeI8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeI16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int16* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeI32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeI32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeI64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeI64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeU8(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeU8Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt8 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeU16(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt16* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeU32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeU32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeU64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   uInt64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeF32(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeF32Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float32 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetAttributeF64(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64* attrVal
);

int32 __stdcall RFmxOFDM_SetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeF64Array(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   float64 attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeNIComplexSingleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexSingle attrVal[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_SetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAttributeNIComplexDoubleArray(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   NIComplexDouble attrVal[],
   int32 arraySize,
   int32* actualArraySize
);


int32 __stdcall RFmxOFDM_SetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   char attrVal[]
);

int32 __stdcall RFmxOFDM_GetAttributeString(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attributeID,
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxOFDM_AnalyzeIQ1Waveform(
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

int32 __stdcall RFmxOFDM_AnalyzeIQ1WaveformSplit(
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

int32 __stdcall RFmxOFDM_AnalyzeSpectrum1Waveform(
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

int32 __stdcall RFmxOFDM_AutoLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 bandwidth,
   float64 measurementInterval,
   float64* referenceLevel
);

int32 __stdcall RFmxOFDM_CheckMeasurementStatus(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32* isDone
);

int32 __stdcall RFmxOFDM_ClearAllNamedResults(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxOFDM_ClearNamedResult(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxOFDM_CloneSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char oldSignalName[],
   char newSignalName[]
);

int32 __stdcall RFmxOFDM_Commit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxOFDM_CreateSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxOFDM_DeleteSignalConfiguration(
   niRFmxInstrHandle instrumentHandle,
   char signalName[]
);

int32 __stdcall RFmxOFDM_Initiate(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultName[]
);

int32 __stdcall RFmxOFDM_ResetToDefault(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxOFDM_SendSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle
);

int32 __stdcall RFmxOFDM_WaitForMeasurementComplete(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout
);

int32 __stdcall RFmxOFDM_LoadResourceAllocationCustomIQValuesFromFile(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char filePath[]
);

int32 __stdcall RFmxOFDM_CfgExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 externalAttenuation
);

int32 __stdcall RFmxOFDM_CfgFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency
);

int32 __stdcall RFmxOFDM_CfgReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 referenceLevel
);

int32 __stdcall RFmxOFDM_CfgRF(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 centerFrequency,
   float64 referenceLevel,
   float64 externalAttenuation
);

int32 __stdcall RFmxOFDM_AbortMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxOFDM_CfgDigitalEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char digitalEdgeSource[],
   int32 digitalEdge,
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxOFDM_CfgIQPowerEdgeTrigger(
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

int32 __stdcall RFmxOFDM_CfgSoftwareEdgeTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 triggerDelay,
   int32 enableTrigger
);

int32 __stdcall RFmxOFDM_DisableTrigger(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[]
);

int32 __stdcall RFmxOFDM_GetAllNamedResultNames(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char resultNames[],
   int32 resultNamesBufferSize,
   int32* actualResultNamesSize,
   int32* defaultResultExists
);

int32 __stdcall RFmxOFDM_SelectMeasurements(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   uInt32 measurements,
   int32 enableAllTraces
);

int32 __stdcall RFmxOFDM_ModAccFetchDataRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 dataRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchPilotRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 pilotRMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchRMSEVMPerSubcarrierMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMPerSubcarrierMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchRMSEVMPerSymbolMeanTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float64* x0,
   float64* dx,
   float32 RMSEVMPerSymbolMean[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchChannelFrequencyResponseMeanTrace(
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

int32 __stdcall RFmxOFDM_ModAccFetchEVMSubcarrierIndices(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   int32 subcarrierIndices[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchDataConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle dataConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchDataConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 dataConstellationI[],
   float32 dataConstellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchPilotConstellationTrace(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   NIComplexSingle pilotConstellation[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_ModAccFetchPilotConstellationTraceSplit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 timeout,
   float32 pilotConstellationI[],
   float32 pilotConstellationQ[],
   int32 arraySize,
   int32* actualArraySize
);

int32 __stdcall RFmxOFDM_GetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxOFDM_SetSelectedPorts(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxOFDM_GetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetCenterFrequency(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetExternalAttenuation(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetReferenceLevelHeadroom(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetTriggerType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxOFDM_SetDigitalEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxOFDM_GetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetDigitalEdgeTriggerEdge(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxOFDM_SetIQPowerEdgeTriggerSource(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxOFDM_GetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetIQPowerEdgeTriggerLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetIQPowerEdgeTriggerLevelType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetIQPowerEdgeTriggerSlope(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetTriggerDelay(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetTriggerMinimumQuietTimeMode(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetTriggerMinimumQuietTimeDuration(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetFrameFFTSize(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetFrameSubcarrierSpacing(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameGuardIntervalPrefix(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxOFDM_SetFrameGuardIntervalPrefix(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetFrameGuardIntervalSuffix(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxOFDM_SetFrameGuardIntervalSuffix(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetFrameGuardIntervalRepeatIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetFrameGuardIntervalRepeatIndex(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameNumberOfResourceAllocations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetFrameNumberOfResourceAllocations(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameResourceAllocationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetFrameResourceAllocationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameResourceAllocationSymbolRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxOFDM_SetFrameResourceAllocationSymbolRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxOFDM_GetFrameResourceAllocationSubcarrierRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 arraySize,
   char attrVal[]
);

int32 __stdcall RFmxOFDM_SetFrameResourceAllocationSubcarrierRange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   char attrVal[]
);

int32 __stdcall RFmxOFDM_GetFrameResourceAllocationDataType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetFrameResourceAllocationDataType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameResourceAllocationModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetFrameResourceAllocationModulationType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetFrameResourceAllocationIQValues(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize,
   int32 *actualArraySize
);

int32 __stdcall RFmxOFDM_SetFrameResourceAllocationIQValues(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float32 attrVal[],
   int32 arraySize
);

int32 __stdcall RFmxOFDM_GetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetAutoLevelInitialReferenceLevel(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_GetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_SetLimitedConfigurationChange(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_GetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_SetResultFetchTimeout(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMeasurementEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetAveragingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetAveragingCount(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetEVMUnit(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetAcquisitionLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMeasurementOffset(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMaximumMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMaximumMeasurementLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetAutoSymbolTimeAdjustmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetAutoSymbolTimeAdjustmentEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetSymbolTimeAdjustment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetSymbolTimeAdjustment(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetSymbolClockOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetSymbolClockOffsetCorrectionEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetChannelEstimationSmoothingMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetChannelEstimationSmoothingMethod(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetChannelEstimationSmoothingWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetChannelEstimationSmoothingWindowLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetAmplitudeTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetAmplitudeTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetPhaseTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetTimeTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetTimeTrackingEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMulticarrierFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMulticarrierFilterType(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMulticarrierFilterWindowedSinc6dBBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMulticarrierFilterWindowedSinc6dBBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMulticarrierFilterWindowedSincAutoFilterLengthEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMulticarrierFilterWindowedSincAutoFilterLengthEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMulticarrierFilterWindowedSinc50dBBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMulticarrierFilterWindowedSinc50dBBandwidth(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetMulticarrierFilterWindowedSincFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetMulticarrierFilterWindowedSincFilterLength(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetAllTracesEnabled(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccSetNumberOfAnalysisThreads(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsCompositeRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsCompositeDataRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsCompositePilotRMSEVMMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsCompositePeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsCompositeDataPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsCompositePilotPeakEVMMaximum(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsNumberOfSymbolsUsed(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   int32 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsFrequencyErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

int32 __stdcall RFmxOFDM_ModAccGetResultsSymbolClockErrorMean(
   niRFmxInstrHandle instrumentHandle,
   char selectorString[],
   float64 *attrVal
);

#ifdef __cplusplus
}
#endif


#endif

